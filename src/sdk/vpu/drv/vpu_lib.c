/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*
 * Copyright (c) 2006, Chips & Media.  All rights reserved.
 */
/*
 * The code contained herein is licensed under the GNU Lesser General
 * Public License.  You may obtain a copy of the GNU Lesser General
 * Public License Version 2.1 or later at the following locations:
 *
 * http://www.opensource.org/licenses/lgpl-license.html
 * http://www.gnu.org/copyleft/lgpl.html
 */

/*!
 * @file vpu_lib.c
 *
 * @brief This file implements codec API funcitons for VPU
 *
 * @ingroup VPU
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vpu_reg.h"
#include "vpu_lib.h"
#include "vpu_util.h"
#include "vpu_io.h"
#include "vpu_debug.h"
#include "vpu_gdi.h"
#include "timer.h"

#define IMAGE_ENDIAN			0
#define STREAM_ENDIAN			0

unsigned int system_rev = 0x61 << 12;
extern const unsigned short bit_code[];

/* If a frame is started, pendingInst is set to the proper instance. */
static CodecInst **ppendingInst;

uint32_t virt_codeBuf;
uint32_t *virt_paraBuf;
uint32_t *virt_paraBuf2;

extern vpu_mem_desc bit_work_addr;
extern semaphore_t *vpu_semap;

static int decoded_pictype[32];

/*!
 * @brief
 * This functure indicate whether processing(encoding/decoding) a frame
 * is completed or not yet.
 *
 * @return
 * @li 0: VPU hardware is idle.
 * @li Non-zero value: VPU hardware is busy processing a frame.
 */
int vpu_IsBusy()
{
    int vpu_busy;

    ENTER_FUNC();

    vpu_busy = VpuReadReg(BIT_BUSY_FLAG);

    return vpu_busy != 0;
}

int vpu_WaitForInt(int timeout_in_ms)
{
    ENTER_FUNC();

    hal_delay_us(timeout_in_ms * 10);

    return 0;
}

/*!
 * @brief VPU initialization.
 * This function initializes VPU hardware and proper data structures/resources.
 * The user must call this function only once before using VPU codec.
 *
 * @param  cb  callback function if needed
 *
 * @return  This function always returns RETCODE_SUCCESS.
 */
RetCode vpu_Init(void *cb)
{
    int i, err;
    volatile uint32_t data;
    PhysicalAddress workBuffer, codeBuffer, paraBuffer;

    ENTER_FUNC();

    err = IOSystemInit(cb);
    if (err) {
        err_msg("IOSystemInit() failure.\n");
        return RETCODE_FAILURE;
    }

    if (!LockVpu(vpu_semap)) {
        err = IOSystemShutdown();
        return RETCODE_FAILURE_TIMEOUT;
    }
    codeBuffer = bit_work_addr.phy_addr;
    workBuffer = codeBuffer + CODE_BUF_SIZE;
    paraBuffer = workBuffer + WORK_BUF_SIZE + PARA_BUF2_SIZE;

    virt_codeBuf = (uint32_t) (bit_work_addr.virt_uaddr);
    virt_paraBuf = (uint32_t *) (virt_codeBuf + CODE_BUF_SIZE + WORK_BUF_SIZE + PARA_BUF2_SIZE);
    virt_paraBuf2 = (uint32_t *) (virt_codeBuf + CODE_BUF_SIZE + WORK_BUF_SIZE);

    ppendingInst = (CodecInst **) (&vpu_semap->pendingInst);

    if (!isVpuInitialized()) {
        if (DownloadBitCodeTable((uint32_t *) virt_codeBuf) != RETCODE_SUCCESS) {
            UnlockVpu(vpu_semap);
            return RETCODE_FAILURE;
        }

        VpuWriteReg(BIT_PARA_BUF_ADDR, paraBuffer);
        VpuWriteReg(BIT_CODE_BUF_ADDR, codeBuffer);
        if (cpu_is_mx6q())
            VpuWriteReg(BIT_WORK_BUF_ADDR, workBuffer);
        else
            VpuWriteReg(BIT_TEMP_BUF_ADDR, workBuffer);

        VpuWriteReg(BIT_BIT_STREAM_PARAM, 0);

        VpuWriteReg(BIT_CODE_RUN, 0);

        /* Download BIT Microcode to Program Memory */
        for (i = 0; i < 2048; ++i) {
            data = bit_code[i];
            VpuWriteReg(BIT_CODE_DOWN, (i << 16) | data);
        }

        data = STREAM_ENDIAN | STREAM_FULL_EMPTY_CHECK_DISABLE << BIT_BUF_CHECK_DIS;
        data |= BUF_PIC_FLUSH << BIT_BUF_PIC_FLUSH | BUF_PIC_RESET << BIT_BUF_PIC_RESET;
        VpuWriteReg(BIT_BIT_STREAM_CTRL, data);
        VpuWriteReg(BIT_FRAME_MEM_CTRL, IMAGE_ENDIAN);
        VpuWriteReg(BIT_INT_ENABLE, 8); /* PIC_RUN irq enable */

        if (cpu_is_mx5x())
            VpuWriteReg(BIT_AXI_SRAM_USE, 0);   /* init to not use SRAM */

        VpuWriteReg(BIT_BUSY_FLAG, 1);
        VpuWriteReg(BIT_CODE_RUN, 1);
        while (VpuReadReg(BIT_BUSY_FLAG)) ;
    }

    EXIT_FUNC();
    return RETCODE_SUCCESS;
}

void vpu_UnInit(void)
{
    IOSystemShutdown();
}

/*
 * This function resets the VPU instance specified by handle or index that
 * exists in the current thread. If handle is not NULL, the index will be
 * ignored and the instance of handle will be reset; otherwise, vpu will only
 * clean the instance record per index, not do real vpu reset.
 */
RetCode vpu_SWReset(DecHandle handle, int index)
{
    static unsigned int regBk[64];
    int i = 0;
    CodecInst *pCodecInst;
    RetCode ret;

    ENTER_FUNC();

    info_msg("vpu_SWReset");
    if (handle == NULL) {
        if (index < 0 || index >= MAX_NUM_INSTANCE)
            return RETCODE_FAILURE;

        /* Free instance info per index */
        pCodecInst = (CodecInst *) (&vpu_semap->codecInstPool[index]);
        if (pCodecInst == NULL)
            warn_msg("The instance is freed\n");
        else {
            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;
            FreeCodecInstance(pCodecInst);
            UnlockVpu(vpu_semap);
        }
        return RETCODE_SUCCESS;
    }

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS) {
        ret = CheckEncInstanceValidity(handle);
        if (ret != RETCODE_SUCCESS)
            return ret;
    }

    pCodecInst = handle;

    if (*ppendingInst && (pCodecInst != *ppendingInst))
        return RETCODE_FAILURE;
    else {
        /* Need to unlock VPU since mutex is locked when StartOneFrame */
        UnlockVpu(vpu_semap);
    }

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    for (i = 0; i < 64; i++)
        regBk[i] = VpuReadReg(BIT_CODE_BUF_ADDR + (i * 4));
    //IOSysSWReset();//removed by Ray
    for (i = 0; i < 64; i++)
        VpuWriteReg(BIT_CODE_BUF_ADDR + (i * 4), regBk[i]);
    VpuWriteReg(BIT_CODE_RUN, 0);

    uint32_t *p = (uint32_t *) virt_codeBuf;
    uint32_t data;
    uint16_t data_hi;
    uint16_t data_lo;
    for (i = 0; i < 2048; i += 4) {
        data = p[(i / 2) + 1];
        data_hi = (data >> 16) & 0xFFFF;
        data_lo = data & 0xFFFF;
        VpuWriteReg(BIT_CODE_DOWN, (i << 16) | data_hi);
        VpuWriteReg(BIT_CODE_DOWN, ((i + 1) << 16) | data_lo);

        data = p[i / 2];
        data_hi = (data >> 16) & 0xFFFF;
        data_lo = data & 0xFFFF;
        VpuWriteReg(BIT_CODE_DOWN, ((i + 2) << 16) | data_hi);
        VpuWriteReg(BIT_CODE_DOWN, ((i + 3) << 16) | data_lo);
    }

    VpuWriteReg(BIT_BUSY_FLAG, 1);
    VpuWriteReg(BIT_CODE_RUN, 1);
    while (vpu_IsBusy()) ;

    BitIssueCommand(0, 0, 0, VPU_WAKE);
    while (vpu_IsBusy()) ;

    /* The handle cannot be used after restore */
    UnlockVpu(vpu_semap);

    return RETCODE_SUCCESS;
}

/*!
 * @brief Get VPU Firmware Version.
 */
RetCode vpu_GetVersionInfo(vpu_versioninfo * verinfo)
{
    uint32_t ver;
    uint16_t pn, version;
    RetCode ret = RETCODE_SUCCESS;
    char productstr[18] = { 0 };

    ENTER_FUNC();

    if (!isVpuInitialized()) {
        return RETCODE_NOT_INITIALIZED;
    }

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    VpuWriteReg(RET_VER_NUM, 0);

    BitIssueCommand(0, 0, 0, FIRMWARE_GET);

    while (VpuReadReg(BIT_BUSY_FLAG)) ;

    ver = VpuReadReg(RET_VER_NUM);
    UnlockVpu(vpu_semap);

    if (ver == 0)
        return RETCODE_FAILURE;

    pn = (uint16_t) (ver >> 16);
    version = (uint16_t) ver;

    switch (pn) {
    case PRJ_TRISTAN:
    case PRJ_TRISTAN_REV:
        strcpy(productstr, "i.MX27");
        break;
    case PRJ_CODAHX_14:
        strcpy(productstr, "i.MX51");
        break;
    case PRJ_CODA7541:
        strcpy(productstr, "i.MX53");
        break;
    case PRJ_CODA_960:
        strcpy(productstr, "i.MX6Q");
        break;
    default:
        err_msg("Unknown VPU\n");
        ret = RETCODE_FAILURE;
        break;
    }

    if (verinfo != NULL) {
        verinfo->fw_major = (version >> 12) & 0x0f;
        verinfo->fw_minor = (version >> 8) & 0x0f;
        verinfo->fw_release = version & 0xff;

        verinfo->lib_major = (VPU_LIB_VERSION_CODE >> (12)) & 0x0f;
        verinfo->lib_minor = (VPU_LIB_VERSION_CODE >> (8)) & 0x0f;
        verinfo->lib_release = (VPU_LIB_VERSION_CODE) & 0xff;
        info_msg("Product Info: %s\n", productstr);
    }

    return ret;
}

/*!
 * @brief Decoder initialization
 *
 * @param pHandle [Output] Pointer to DecHandle type
 * @param pop [Input] Pointer to DecOpenParam type.
 *
 * @return
 * @li RETCODE_SUCCESS Success in acquisition of a decoder instance.
 * @li RETCODE_FAILURE Failed in acquisition of a decoder instance.
 * @li RETCODE_INVALID_PARAM pop is a null pointer or invalid.
 */
RetCode vpu_DecOpen(DecHandle * pHandle, DecOpenParam * pop)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    int instIdx;
    uint32_t val;
    RetCode ret;

    ENTER_FUNC();

    if (!isVpuInitialized()) {
        return RETCODE_NOT_INITIALIZED;
    }

    ret = CheckDecOpenParam(pop);
    if (ret != RETCODE_SUCCESS) {
        return ret;
    }

    ret = GetCodecInstance(&pCodecInst);
    if (ret == RETCODE_FAILURE) {
        *pHandle = 0;
        UnlockVpu(vpu_semap);
        return RETCODE_FAILURE;
    }

    *pHandle = pCodecInst;
    instIdx = pCodecInst->instIndex;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    pDecInfo->openParam = *pop;

    pCodecInst->contextBufMem.size = SIZE_CONTEXT_BUF;
    ret = IOGetMem(&pCodecInst->contextBufMem);
    if (ret) {
        err_msg("Unable to obtain physical mem\n");
        return RETCODE_FAILURE;
    }

    pDecInfo->openParam = *pop;

    switch (pop->bitstreamFormat) {
    case STD_MPEG4:
        pCodecInst->codecMode = MP4_DEC;
        pCodecInst->codecModeAux = MP4_AUX_MPEG4;
        break;
    case STD_AVC:
        pCodecInst->codecMode = AVC_DEC;
        break;
    case STD_VC1:
        pCodecInst->codecMode = VC1_DEC;
        break;
    case STD_MPEG2:
        pCodecInst->codecMode = MP2_DEC;
        break;
    case STD_DIV3:
        pCodecInst->codecMode = DV3_DEC;
        pCodecInst->codecModeAux = MP4_AUX_DIVX3;
        break;
    case STD_RV:
        pCodecInst->codecMode = RV_DEC;
        break;
    case STD_AVS:
        pCodecInst->codecMode = AVS_DEC;
        break;
    case STD_VP8:
        pCodecInst->codecMode = VPX_DEC;
        pCodecInst->codecModeAux = VPX_AUX_VP8;
        break;
    case STD_MJPG:
        pCodecInst->codecMode = MJPG_DEC;
        break;
    default:
        break;
    }

    pDecInfo->streamWrPtr = pop->bitstreamBuffer;
    pDecInfo->streamBufStartAddr = pop->bitstreamBuffer;
    pDecInfo->streamBufSize = pop->bitstreamBufferSize;
    pDecInfo->streamBufEndAddr = pop->bitstreamBuffer + pop->bitstreamBufferSize;
    pDecInfo->frameBufPool = 0;

    pDecInfo->rotationEnable = 0;
    pDecInfo->mirrorEnable = 0;
    pDecInfo->mirrorDirection = MIRDIR_NONE;
    pDecInfo->rotationAngle = 0;
    pDecInfo->rotatorOutputValid = 0;
    pDecInfo->rotatorStride = 0;
    pDecInfo->deringEnable = 0;

    pDecInfo->filePlayEnable = pop->filePlayEnable;
    if (pop->filePlayEnable == 1) {
        pDecInfo->picSrcSize = (pop->picWidth << BIT_PIC_WIDTH_OFFSET) | pop->picHeight;
    }
    pDecInfo->dynamicAllocEnable = pop->dynamicAllocEnable;

    pDecInfo->initialInfoObtained = 0;
    pDecInfo->vc1BframeDisplayValid = 0;

    pDecInfo->decReportFrameBufStat.enable = 0;
    pDecInfo->decReportMBInfo.enable = 0;
    pDecInfo->decReportMVInfo.enable = 0;
    pDecInfo->decReportUserData.enable = 0;
    pDecInfo->decReportUserData.size = 0;

    if (cpu_is_mx6q()) {
        pDecInfo->mapType = pop->mapType;
        pDecInfo->tiledLinearEnable = pop->tiled2LinearEnable;
        pDecInfo->cacheConfig.Bypass = 1;
        pDecInfo->jpgInfo.frameIdx = 0;
        SetTiledMapType(pDecInfo->mapType);
    }

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    pCodecInst->ctxRegs[CTX_BIT_RD_PTR] = pDecInfo->streamBufStartAddr;
    pCodecInst->ctxRegs[CTX_BIT_WR_PTR] = pDecInfo->streamWrPtr;
    pCodecInst->ctxRegs[CTX_BIT_FRM_DIS_FLG] = 0;
    pCodecInst->ctxRegs[CTX_BIT_STREAM_PARAM] = 0;

    LockVpuReg(vpu_semap);
    if (instIdx == VpuReadReg(BIT_RUN_INDEX)) {
        VpuWriteReg(BIT_RD_PTR, pDecInfo->streamBufStartAddr);
        VpuWriteReg(BIT_WR_PTR, pDecInfo->streamWrPtr);
        VpuWriteReg(BIT_FRM_DIS_FLG, 0);
    }
    UnlockVpuReg(vpu_semap);

    val = VpuReadReg(BIT_FRAME_MEM_CTRL);
    val &= ~(1 << 2 | 0x03 << 9);   /* clear the bit firstly */

    if (cpu_is_mx6q() && pDecInfo->mapType)
        val |= (pDecInfo->tiledLinearEnable << 11 | 0x03 << 9);

    pCodecInst->ctxRegs[CTX_BIT_FRAME_MEM_CTRL] = val | (pDecInfo->openParam.chromaInterleave << 2);

    UnlockVpu(vpu_semap);

    return RETCODE_SUCCESS;
}

/*!
 * @brief Decoder close function
 *
 * @param  handle [Input] The handle obtained from vpu_DecOpen().
 *
 * @return
 * @li RETCODE_SUCCESS Successful closing.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_FRAME_NOT_COMPLETE A frame has not been finished.
 */
RetCode vpu_DecClose(DecHandle handle)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    RetCode ret;

    ENTER_FUNC();

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    if (*ppendingInst == pCodecInst) {
        return RETCODE_FRAME_NOT_COMPLETE;
    }

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    if (pDecInfo->initialInfoObtained) {
        BitIssueCommandEx(pCodecInst, SEQ_END);
        while (VpuReadReg(BIT_BUSY_FLAG)) ;
    }

    /* Free memory allocated for data report functions */
    IOFreeMem(&pDecInfo->picParaBaseMem);
    IOFreeMem(&pDecInfo->userDataBufMem);
    IOFreeMem(&pCodecInst->contextBufMem);
    FreeCodecInstance(pCodecInst);
    UnlockVpu(vpu_semap);

    return RETCODE_SUCCESS;
}

RetCode vpu_DecSetEscSeqInit(DecHandle handle, int escape)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    RetCode ret;

    ENTER_FUNC();

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    if (escape == 0)
        pCodecInst->ctxRegs[CTX_BIT_STREAM_PARAM] &= ~0x01;
    else
        pCodecInst->ctxRegs[CTX_BIT_STREAM_PARAM] |= ~0x01;

    UnlockVpu(vpu_semap);

    return RETCODE_SUCCESS;
}

/*!
 * @brief Get header information of bitstream.
 *
 * @param handle [Input] The handle obtained from vpu_DecOpen().
 * @param info [Output] Pointer to DecInitialInfo data structure.
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_FAILURE There was an error in getting initial information.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_INVALID_PARAM info is an invalid pointer.
 * @li RETCODE_FRAME_NOT_COMPLETE A frame has not been finished.
 * @li RETCODE_WRONG_CALL_SEQUENCE Wrong calling sequence.
 */
RetCode vpu_DecGetInitialInfo(DecHandle handle, DecInitialInfo * info)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    uint32_t val, val2;
    SetIramParam iramParam;
    RetCode ret;

    ENTER_FUNC();

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS) {
        return ret;
    }

    if (info == 0) {
        return RETCODE_INVALID_PARAM;
    }

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    if (pDecInfo->initialInfoObtained) {
        return RETCODE_CALLED_BEFORE;
    }

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    if (DecBitstreamBufEmpty(handle)) {
        UnlockVpu(vpu_semap);
        return RETCODE_WRONG_CALL_SEQUENCE;
    }

    VpuWriteReg(CMD_DEC_SEQ_BB_START, pDecInfo->streamBufStartAddr);
    VpuWriteReg(CMD_DEC_SEQ_BB_SIZE, pDecInfo->streamBufSize / 1024);

    if (pDecInfo->filePlayEnable == 1) {
        VpuWriteReg(CMD_DEC_SEQ_START_BYTE, pDecInfo->openParam.streamStartByteOffset);
    }

    val = ((pDecInfo->dynamicAllocEnable << 3) & 0x8) |
        ((pDecInfo->filePlayEnable << 2) & 0x4) | ((pDecInfo->openParam.reorderEnable << 1) & 0x2);

    if (pCodecInst->codecMode == MJPG_DEC) {
        val |= 1 << 10;         /* force not interrupt mode */
        val |= pDecInfo->decReportUserData.enable << 5;
    }

    val |= (pDecInfo->openParam.mp4DeblkEnable & 0x1);

    VpuWriteReg(CMD_DEC_SEQ_OPTION, val);

    if (pCodecInst->codecMode == VC1_DEC) {
        if (cpu_is_mx6q())
            val = (pDecInfo->openParam.vc1AnnexL3MetaDisable << 3) & 0x08;
        else
            val = 0;
        VpuWriteReg(CMD_DEC_SEQ_VC1_STREAM_FMT, val);
    }

    if (pCodecInst->codecMode == MP4_DEC) {
        VpuWriteReg(CMD_DEC_SEQ_MP4_ASP_CLASS, pDecInfo->openParam.mp4Class);
    }

    if (pCodecInst->codecMode == AVC_DEC) {
        if (cpu_is_mx6q())
            VpuWriteReg(CMD_DEC_SEQ_X264_MV_EN, 0);
        VpuWriteReg(CMD_DEC_SEQ_PS_BB_START, pDecInfo->openParam.psSaveBuffer);
        VpuWriteReg(CMD_DEC_SEQ_PS_BB_SIZE, (pDecInfo->openParam.psSaveBufferSize / 1024));
    }

    VpuWriteReg(CMD_DEC_SEQ_SRC_SIZE, pDecInfo->picSrcSize);

    BitIssueCommandEx(pCodecInst, SEQ_INIT);
    while (VpuReadReg(BIT_BUSY_FLAG)) ;

    if (cpu_is_mx6q() && VpuReadReg(RET_DEC_SEQ_SUCCESS) & (1 << 31)) {
        UnlockVpu(vpu_semap);
        return RETCODE_MEMORY_ACCESS_VIOLATION;
    }

    if (!cpu_is_mx6q() && VpuReadReg(RET_DEC_SEQ_SUCCESS) == 0) {
        val = VpuReadReg(RET_DEC_SEQ_ERR_REASON);
        info->errorcode = val;

        UnlockVpu(vpu_semap);
        return RETCODE_FAILURE;
    }

    val = VpuReadReg(RET_DEC_SEQ_SRC_SIZE);
    info->picWidth = ((val >> 16) & 0xffff);
    info->picHeight = (val & 0xffff);

    if (pCodecInst->codecMode == MJPG_DEC) {
        if (info->picWidth < 16 || info->picHeight < 16) {
            UnlockVpu(vpu_semap);
            return RETCODE_FAILURE;
        }
    } else {
        if (info->picWidth < 64 || info->picHeight < 64) {
            UnlockVpu(vpu_semap);
            return RETCODE_FAILURE;
        }
    }

    if (cpu_is_mx6q()) {
        info->frameRateRes = VpuReadReg(RET_DEC_SEQ_FRATE_NR);
        info->frameRateDiv = VpuReadReg(RET_DEC_SEQ_FRATE_DR);
        info->bitRate = VpuReadReg(RET_DEC_SEQ_BIT_RATE);
    } else
        info->frameRateInfo = VpuReadReg(RET_DEC_SEQ_SRC_F_RATE);

    if (pCodecInst->codecMode == MP4_DEC) {
        val = VpuReadReg(RET_DEC_SEQ_INFO);
        info->mp4_shortVideoHeader = (val >> 2) & 1;
        info->mp4_dataPartitionEnable = val & 1;
        info->mp4_reversibleVlcEnable = info->mp4_dataPartitionEnable ? ((val >> 1) & 1) : 0;
        info->h263_annexJEnable = (val >> 3) & 1;
    } else if (pCodecInst->codecMode == VPX_DEC && pCodecInst->codecModeAux == VPX_AUX_VP8) {
        /* h_scale[31:30] v_scale[29:28] pic_width[27:14] pic_height[13:0] */
        val = VpuReadReg(RET_DEC_SEQ_VP8_SCALE_INFO);
        info->vp8ScaleInfo.hScaleFactor = (val >> 30) & 0x03;
        info->vp8ScaleInfo.vScaleFactor = (val >> 28) & 0x03;
        info->vp8ScaleInfo.picWidth = (val >> 14) & 0x3FFF;
        info->vp8ScaleInfo.picHeight = (val >> 0) & 0x3FFF;
    }

    info->minFrameBufferCount = VpuReadReg(RET_DEC_SEQ_FRAME_NEED);
    info->frameBufDelay = VpuReadReg(RET_DEC_SEQ_FRAME_DELAY);

    if (pCodecInst->codecMode == AVC_DEC) {
        val = VpuReadReg(RET_DEC_SEQ_CROP_LEFT_RIGHT);
        val2 = VpuReadReg(RET_DEC_SEQ_CROP_TOP_BOTTOM);
        if (val == 0 && val2 == 0) {
            info->picCropRect.left = 0;
            info->picCropRect.right = 0;
            info->picCropRect.top = 0;
            info->picCropRect.bottom = 0;
        } else {
            if (cpu_is_mx5x()) {
                info->picCropRect.left = ((val >> 16) & 0xFFFF);
                info->picCropRect.right = info->picWidth - ((val & 0xFFFF));
                info->picCropRect.top = ((val2 >> 16) & 0xFFFF);
                info->picCropRect.bottom = info->picHeight - ((val2 & 0xFFFF));

            } else {
                info->picCropRect.left = ((val >> 10) & 0x3FF) * 2;
                info->picCropRect.right = info->picWidth - ((val & 0x3FF) * 2);
                info->picCropRect.top = ((val2 >> 10) & 0x3FF) * 2;
                info->picCropRect.bottom = info->picHeight - ((val2 & 0x3FF) * 2);
            }
        }

        val = info->picWidth * info->picHeight;
        info->normalSliceSize = (val * 3 / 2) / 1024 / 4;
        info->worstSliceSize = ((val / 256) * 3200 / 8 + 512) / 1024;
    } else {
        info->picCropRect.left = 0;
        info->picCropRect.right = 0;
        info->picCropRect.top = 0;
        info->picCropRect.bottom = 0;
    }

    val = VpuReadReg(RET_DEC_SEQ_HEADER_REPORT);
    info->profile = (val >> 0) & 0xFF;
    info->level = (val >> 8) & 0xFF;
    info->interlace = (val >> 16) & 0x01;
    info->direct8x8Flag = (val >> 17) & 0x01;
    info->vc1_psf = (val >> 18) & 0x01;
    info->constraint_set_flag[0] = (val >> 19) & 0x01;
    info->constraint_set_flag[1] = (val >> 20) & 0x01;
    info->constraint_set_flag[2] = (val >> 21) & 0x01;
    info->constraint_set_flag[3] = (val >> 22) & 0x01;

    val = VpuReadReg(RET_DEC_SEQ_ASPECT);
    info->aspectRateInfo = val;

    info->reportBufSize.frameBufStatBufSize = SIZE_FRAME_BUF_STAT;
    info->reportBufSize.mbInfoBufSize = SIZE_MB_DATA;
    info->reportBufSize.mvInfoBufSize = SIZE_MV_DATA;

    info->streamInfoObtained = 1;

    /* Backup rd pointer to ctx */
    pCodecInst->ctxRegs[CTX_BIT_RD_PTR] = VpuReadReg(BIT_RD_PTR);
    pCodecInst->ctxRegs[CTX_BIT_STREAM_PARAM] = VpuReadReg(BIT_BIT_STREAM_PARAM);

    UnlockVpu(vpu_semap);

    pDecInfo->initialInfo = *info;
    pDecInfo->initialInfoObtained = 1;

    /* Set secondAXI IRAM */
    iramParam.width = (info->picWidth + 15) & ~15;
    iramParam.profile = info->profile;
    iramParam.codecMode = pCodecInst->codecMode;
    SetDecSecondAXIIRAM(&pDecInfo->secAxiUse, &iramParam);

    /* Enable 2-D cache */
    if (cpu_is_mx6q())
        SetMaverickCache(&pDecInfo->cacheConfig, pDecInfo->mapType,
                         pDecInfo->openParam.chromaInterleave);

    return RETCODE_SUCCESS;
}

/*!
 * @brief Register decoder frame buffers.
 *
 * @param handle [Input] The handle obtained from vpu_DecOpen().
 * @param bufArray [Input] Pointer to the first element of an array of FrameBuffer.
 * @param num [Input] Number of elements of the array.
 * @param stride [Input] Stride value of frame buffers being registered.
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_FRAME_NOT_COMPLETE A frame has not been finished.
 * @li RETCODE_WRONG_CALL_SEQUENCE Wrong calling sequence.
 * @li RETCODE_INVALID_FRAME_BUFFER Buffer is an invalid pointer.
 * @li RETCODE_INSUFFICIENT_FRAME_BUFFERS num is less than
 * the value requested by vpu_DecGetInitialInfo().
 * @li RETCODE_INVALID_STRIDE stride is less than the picture width.
 */
RetCode vpu_DecRegisterFrameBuffer(DecHandle handle,
                                   FrameBuffer * bufArray, int num, int stride,
                                   DecBufInfo * pBufInfo)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    int i;
    uint32_t val = 0, temp_baseAddr;
    RetCode ret;

    ENTER_FUNC();

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    if (pDecInfo->frameBufPool) {
        return RETCODE_CALLED_BEFORE;
    }

    if (!pDecInfo->initialInfoObtained) {
        return RETCODE_WRONG_CALL_SEQUENCE;
    }

    if (bufArray == 0) {
        return RETCODE_INVALID_FRAME_BUFFER;
    }

    if (num < pDecInfo->initialInfo.minFrameBufferCount) {
        return RETCODE_INSUFFICIENT_FRAME_BUFFERS;
    }

    if (stride < pDecInfo->initialInfo.picWidth || stride % 8 != 0) {
        return RETCODE_INVALID_STRIDE;
    }

    pDecInfo->frameBufPool = bufArray;
    pDecInfo->numFrameBuffers = num;
    pDecInfo->stride = stride;

    if (pDecInfo->openParam.bitstreamFormat == STD_MJPG)
        return RETCODE_SUCCESS;

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    for (i = 0; i < num; i += 2) {
        virt_paraBuf[i * 3] = bufArray[i].bufCb;
        virt_paraBuf[i * 3 + 1] = bufArray[i].bufY;
        virt_paraBuf[i * 3 + 3] = bufArray[i].bufCr;
        if (pDecInfo->openParam.bitstreamFormat == STD_AVC)
            virt_paraBuf[96 + i + 1] = bufArray[i].bufMvCol;
        if (i + 1 < num) {
            virt_paraBuf[i * 3 + 2] = bufArray[i + 1].bufY;
            virt_paraBuf[i * 3 + 4] = bufArray[i + 1].bufCr;
            virt_paraBuf[i * 3 + 5] = bufArray[i + 1].bufCb;
            if (pDecInfo->openParam.bitstreamFormat == STD_AVC)
                virt_paraBuf[96 + i] = bufArray[i + 1].bufMvCol;
        }
    }
    if (pDecInfo->openParam.bitstreamFormat == STD_VC1 ||
        pDecInfo->openParam.bitstreamFormat == STD_MPEG4 ||
        pDecInfo->openParam.bitstreamFormat == STD_RV)
        virt_paraBuf[97] = bufArray[0].bufMvCol;

    /* Tell the decoder how much frame buffers were allocated. */
    VpuWriteReg(CMD_SET_FRAME_BUF_NUM, num);
    VpuWriteReg(CMD_SET_FRAME_BUF_STRIDE, stride);

    VpuWriteReg(CMD_SET_FRAME_AXI_BIT_ADDR, pDecInfo->secAxiUse.bufBitUse);
    VpuWriteReg(CMD_SET_FRAME_AXI_IPACDC_ADDR, pDecInfo->secAxiUse.bufIpAcDcUse);
    VpuWriteReg(CMD_SET_FRAME_AXI_DBKY_ADDR, pDecInfo->secAxiUse.bufDbkYUse);
    VpuWriteReg(CMD_SET_FRAME_AXI_DBKC_ADDR, pDecInfo->secAxiUse.bufDbkCUse);
    VpuWriteReg(CMD_SET_FRAME_AXI_OVL_ADDR, pDecInfo->secAxiUse.bufOvlUse);

    if (cpu_is_mx6q())
        VpuWriteReg(CMD_SET_FRAME_AXI_BTP_ADDR, pDecInfo->secAxiUse.bufBtpUse);
    if (cpu_is_mx6q()) {
        /* Maverick Cache Configuration */
        val = (pDecInfo->cacheConfig.luma.cfg.PageSizeX << 28) |
            (pDecInfo->cacheConfig.luma.cfg.PageSizeY << 24) |
            (pDecInfo->cacheConfig.luma.cfg.CacheSizeX << 20) |
            (pDecInfo->cacheConfig.luma.cfg.CacheSizeY << 16) |
            (pDecInfo->cacheConfig.chroma.cfg.PageSizeX << 12) |
            (pDecInfo->cacheConfig.chroma.cfg.PageSizeY << 8) |
            (pDecInfo->cacheConfig.chroma.cfg.CacheSizeX << 4) |
            (pDecInfo->cacheConfig.chroma.cfg.CacheSizeY << 0);
        VpuWriteReg(CMD_SET_FRAME_CACHE_SIZE, val);

        val = (pDecInfo->cacheConfig.Bypass << 4) |
            (pDecInfo->cacheConfig.DualConf << 2) | (pDecInfo->cacheConfig.PageMerge << 0);
        val = val << 24;
        val |= (pDecInfo->cacheConfig.LumaBufferSize << 16) |
            (pDecInfo->cacheConfig.CbBufferSize << 8) | (pDecInfo->cacheConfig.CrBufferSize);
        VpuWriteReg(CMD_SET_FRAME_CACHE_CONFIG, val);
    }

    if (pCodecInst->codecMode == VPX_DEC && pCodecInst->codecModeAux == VPX_AUX_VP8) {
        VpuWriteReg(CMD_SET_FRAME_MB_BUF_BASE, pBufInfo->vp8MbDataBufInfo.bufferBase);
    }

    if (pCodecInst->codecMode == AVC_DEC) {
        if (cpu_is_mx5x()) {
            temp_baseAddr = VpuReadReg(BIT_TEMP_BUF_ADDR);
            VpuWriteReg(CMD_SET_FRAME_SLICE_BB_START, temp_baseAddr + 0x18300);
        } else {
            VpuWriteReg(CMD_SET_FRAME_SLICE_BB_START, pBufInfo->avcSliceBufInfo.bufferBase);
        }
        VpuWriteReg(CMD_SET_FRAME_SLICE_BB_SIZE, (pBufInfo->avcSliceBufInfo.bufferSize / 1024));
    }

    if (!cpu_is_mx6q())
        VpuWriteReg(CMD_SET_FRAME_MAX_DEC_SIZE,
                    (pBufInfo->maxDecFrmInfo.maxMbNum << 16 |
                     pBufInfo->maxDecFrmInfo.maxMbX << 8 | pBufInfo->maxDecFrmInfo.maxMbY));

    BitIssueCommandEx(pCodecInst, SET_FRAME_BUF);

    while (VpuReadReg(BIT_BUSY_FLAG)) ;

    if (cpu_is_mx6q() && VpuReadReg(RET_SET_FRAME_SUCCESS) & (1 << 31)) {
        UnlockVpu(vpu_semap);
        return RETCODE_MEMORY_ACCESS_VIOLATION;
    }

    UnlockVpu(vpu_semap);

    return RETCODE_SUCCESS;
}

/*!
 * @brief Get bitstream for decoder.
 *
 * @param handle [Input] The handle obtained from vpu_DecOpen().
 * @param bufAddr [Output] Bitstream buffer physical address.
 * @param size [Output] Bitstream size.
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_INVALID_PARAM buf or size is invalid.
 */
RetCode vpu_DecGetBitstreamBuffer(DecHandle handle,
                                  PhysicalAddress * paRdPtr,
                                  PhysicalAddress * paWrPtr, uint32_t * size)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    PhysicalAddress rdPtr;
    PhysicalAddress wrPtr;
    uint32_t room;
    RetCode ret;
    int instIndex;

    ENTER_FUNC();

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    if (paRdPtr == 0 || paWrPtr == 0 || size == 0) {
        return RETCODE_INVALID_PARAM;
    }

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    LockVpuReg(vpu_semap);
    /* Check current instance is in running or not, if not
       Get the pointer from back context regs */
    instIndex = VpuReadReg(BIT_RUN_INDEX);
    rdPtr = (pCodecInst->instIndex == instIndex) ?
        VpuReadReg(BIT_RD_PTR) : pCodecInst->ctxRegs[CTX_BIT_RD_PTR];
    UnlockVpuReg(vpu_semap);

    wrPtr = pDecInfo->streamWrPtr;

    if (wrPtr < rdPtr) {
        room = rdPtr - wrPtr - 1;
    } else {
        room = (pDecInfo->streamBufEndAddr - wrPtr) + (rdPtr - pDecInfo->streamBufStartAddr) - 1;
    }

    *paRdPtr = rdPtr;
    *paWrPtr = wrPtr;
    *size = room;

    return RETCODE_SUCCESS;
}

/*!
 * @brief Update the current bit stream position.
 *
 * @param handle [Input] The handle obtained from vpu_DecOpen().
 * @param size [Input] Size of bit stream you put.
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_INVALID_PARAM Invalid input parameters.
 */
RetCode vpu_DecUpdateBitstreamBuffer(DecHandle handle, uint32_t size)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    PhysicalAddress wrPtr;
    PhysicalAddress rdPtr;
    RetCode ret;
    int room = 0, val = 0, instIndex;

    ENTER_FUNC();

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;
    wrPtr = pDecInfo->streamWrPtr;

    LockVpuReg(vpu_semap);

    val = pCodecInst->ctxRegs[CTX_BIT_STREAM_PARAM];
    /* Set stream end flag if size == 0; otherwise, clear the flag */
    val = (size == 0) ? (val | 1 << 2) : (val & ~(1 << 2));
    /* Backup to context reg */
    pCodecInst->ctxRegs[CTX_BIT_STREAM_PARAM] = val;
    instIndex = VpuReadReg(BIT_RUN_INDEX);

    if (pCodecInst->instIndex == instIndex)
        VpuWriteReg(BIT_BIT_STREAM_PARAM, val); /* Write to vpu hardware */

    if (size == 0) {
        UnlockVpuReg(vpu_semap);
        return RETCODE_SUCCESS;
    }

    rdPtr = (pCodecInst->instIndex == instIndex) ?
        VpuReadReg(BIT_RD_PTR) : pCodecInst->ctxRegs[CTX_BIT_RD_PTR];
    if (wrPtr < rdPtr) {
        if (rdPtr <= wrPtr + size) {
            UnlockVpuReg(vpu_semap);
            return RETCODE_INVALID_PARAM;
        }
    }

    wrPtr += size;

    if (pDecInfo->filePlayEnable != 1) {
        if (wrPtr > pDecInfo->streamBufEndAddr) {
            room = wrPtr - pDecInfo->streamBufEndAddr;
            wrPtr = pDecInfo->streamBufStartAddr;
            wrPtr += room;
        }

        if (wrPtr == pDecInfo->streamBufEndAddr) {
            wrPtr = pDecInfo->streamBufStartAddr;
        }
    }

    pDecInfo->streamWrPtr = wrPtr;

    if (pCodecInst->instIndex == instIndex)
        VpuWriteReg(BIT_WR_PTR, wrPtr);
    pCodecInst->ctxRegs[CTX_BIT_WR_PTR] = wrPtr;
    UnlockVpuReg(vpu_semap);

    return RETCODE_SUCCESS;
}

/*!
 * @brief Start decoding one frame.
 *
 * @param handle [Input] The handle obtained from vpu_DecOpen().
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_FRAME_NOT_COMPLETE A frame has not been finished.
 * @li RETCODE_WRONG_CALL_SEQUENCE Wrong calling sequence.
 */
RetCode vpu_DecStartOneFrame(DecHandle handle, DecParam * param)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    DecParam *pDecParam;
    uint32_t rotMir;
    uint32_t val = 0;
    RetCode ret;

    ENTER_FUNC();

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;
    pDecParam = &pCodecInst->CodecParam.decParam;
    memcpy(pDecParam, param, sizeof(*pDecParam));

    /* This means frame buffers have not been registered. */
    if (pDecInfo->frameBufPool == 0) {
        return RETCODE_WRONG_CALL_SEQUENCE;
    }

    rotMir = 0;
    if (pDecInfo->rotationEnable) {
        rotMir |= 0x10;         /* Enable rotator */
        switch (pDecInfo->rotationAngle) {
        case 0:
            rotMir |= 0x0;
            break;

        case 90:
            rotMir |= 0x1;
            break;

        case 180:
            rotMir |= 0x2;
            break;

        case 270:
            rotMir |= 0x3;
            break;
        }
    }

    if (pDecInfo->mirrorEnable) {
        rotMir |= 0x10;         /* Enable mirror */
        switch (pDecInfo->mirrorDirection) {
        case MIRDIR_NONE:
            rotMir |= 0x0;
            break;

        case MIRDIR_VER:
            rotMir |= 0x4;
            break;

        case MIRDIR_HOR:
            rotMir |= 0x8;
            break;

        case MIRDIR_HOR_VER:
            rotMir |= 0xc;
            break;

        }
    }

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    if (cpu_is_mx6q() && pDecInfo->tiledLinearEnable) {
        rotMir |= 0x10;
    }

    if (!cpu_is_mx27() && pDecInfo->deringEnable) {
        rotMir |= 0x20;         /* Enable Dering Filter */
    }

    if ((rotMir & 0x30) ||      /* rotator or dering enabled */
        (!cpu_is_mx6q() && pCodecInst->codecMode == MJPG_DEC)) {
        if (cpu_is_mx6q())
            VpuWriteReg(CMD_DEC_PIC_ROT_INDEX, pDecInfo->rotatorOutput.myIndex);

        VpuWriteReg(CMD_DEC_PIC_ROT_ADDR_Y, pDecInfo->rotatorOutput.bufY);
        VpuWriteReg(CMD_DEC_PIC_ROT_ADDR_CB, pDecInfo->rotatorOutput.bufCb);
        VpuWriteReg(CMD_DEC_PIC_ROT_ADDR_CR, pDecInfo->rotatorOutput.bufCr);
        VpuWriteReg(CMD_DEC_PIC_ROT_STRIDE, pDecInfo->rotatorStride);
    }

    VpuWriteReg(CMD_DEC_PIC_ROT_MODE, rotMir);

    if (pDecInfo->decReportMBInfo.enable || pDecInfo->decReportMVInfo.enable ||
        pDecInfo->decReportFrameBufStat.enable) {
        if (!pDecInfo->picParaBaseMem.phy_addr) {
            pDecInfo->picParaBaseMem.size = DEC_ADDR_END_OF_RPT_BUF;
            ret = IOGetMem(&pDecInfo->picParaBaseMem);
            if (ret) {
                err_msg("Unable to obtain physical mem\n");
                UnlockVpu(vpu_semap);
                return RETCODE_FAILURE;
            }
        }

        VpuWriteReg(CMD_DEC_PIC_PARA_BASE_ADDR, pDecInfo->picParaBaseMem.phy_addr);

        uint32_t *virt_addr, phy_addr;

        virt_addr = (uint32_t *) pDecInfo->picParaBaseMem.virt_uaddr;
        phy_addr = pDecInfo->picParaBaseMem.phy_addr;
        /* Set frameStat buffer address */
        if (pDecInfo->decReportFrameBufStat.enable) {
            *virt_addr = phy_addr + ADDR_FRAME_BUF_STAT_BASE_OFFSET;
        }
        /* Set mbParam buffer address */
        if (pDecInfo->decReportMBInfo.enable) {
            *(virt_addr + 2) = phy_addr + ADDR_MB_BASE_OFFSET;
        }
        /* Set mvParam buffer address */
        if (pDecInfo->decReportMVInfo.enable) {
            *(virt_addr + 4) = phy_addr + ADDR_MV_BASE_OFFSET;
        }
    }
    if (pDecInfo->decReportUserData.enable && !pDecInfo->userDataBufMem.phy_addr) {
        pDecInfo->userDataBufMem.size = pDecInfo->decReportUserData.size;
        ret = IOGetMem(&pDecInfo->userDataBufMem);
        if (ret) {
            err_msg("Unable to obtain physical mem\n");
            UnlockVpu(vpu_semap);
            return RETCODE_FAILURE;
        }

        VpuWriteReg(CMD_DEC_PIC_USER_DATA_BASE_ADDR, pDecInfo->userDataBufMem.phy_addr);
        VpuWriteReg(CMD_DEC_PIC_USER_DATA_BUF_SIZE, pDecInfo->decReportUserData.size);
    }

    val = 0;

    val |= (1 << 10);           /* hardcode to use interrupt disable mode  */
    val |= (pDecInfo->decReportFrameBufStat.enable << 8);
    val |= (pDecInfo->decReportMBInfo.enable << 7);
    val |= (pDecInfo->decReportMVInfo.enable << 6);

    /* if iframeSearch is Enable, other bit is ignored. */
    if (param->iframeSearchEnable == 1) {
        val |= ((param->iframeSearchEnable & 0x1) << 2);
        pDecInfo->vc1BframeDisplayValid = 0;
    } else if (param->skipframeMode) {
        val |= (param->skipframeMode << 3);
        val |= (param->prescanMode << 1);
        val |= (param->prescanEnable);
    } else {
        val |= (pDecInfo->decReportUserData.enable << 5);
        val |= (param->prescanMode << 1);
        val |= (param->prescanEnable);
    }
    VpuWriteReg(CMD_DEC_PIC_OPTION, val);

    /* TODO may be removed after next mx51 release be aligned with mx37 */
    if (cpu_is_mx5x())
        VpuWriteReg(CMD_DEC_PIC_SKIP_NUM, param->skipframeNum);

    if (pDecInfo->filePlayEnable == 1) {
        VpuWriteReg(CMD_DEC_PIC_CHUNK_SIZE, param->chunkSize);
        if (pDecInfo->dynamicAllocEnable == 1) {
            VpuWriteReg(CMD_DEC_PIC_BB_START, param->picStreamBufferAddr);
        }

        VpuWriteReg(CMD_DEC_PIC_START_BYTE, param->picStartByteOffset);
    }

    if (cpu_is_mx6q()) {
        val = (pDecInfo->secAxiUse.useBitEnable |
               pDecInfo->secAxiUse.useIpEnable << 1 |
               pDecInfo->secAxiUse.useDbkEnable << 2 |
               pDecInfo->secAxiUse.useDbkEnable << 3 |
               pDecInfo->secAxiUse.useOvlEnable << 4 |
               pDecInfo->secAxiUse.useBtpEnable << 5 |
               pDecInfo->secAxiUse.useHostBitEnable << 8 |
               pDecInfo->secAxiUse.useHostIpEnable << 9 |
               pDecInfo->secAxiUse.useHostDbkEnable << 10 |
               pDecInfo->secAxiUse.useHostDbkEnable << 11 |
               pDecInfo->secAxiUse.useHostOvlEnable << 12 |
               pDecInfo->secAxiUse.useHostBtpEnable << 13);
    } else {
        val = (pDecInfo->secAxiUse.useBitEnable |
               pDecInfo->secAxiUse.useIpEnable << 1 |
               pDecInfo->secAxiUse.useDbkEnable << 2 |
               pDecInfo->secAxiUse.useOvlEnable << 3 |
               pDecInfo->secAxiUse.useHostBitEnable << 7 |
               pDecInfo->secAxiUse.useHostIpEnable << 8 |
               pDecInfo->secAxiUse.useHostDbkEnable << 9 |
               pDecInfo->secAxiUse.useHostOvlEnable << 10);
    }
    VpuWriteReg(BIT_AXI_SRAM_USE, val);

    BitIssueCommandEx(pCodecInst, PIC_RUN);

    *ppendingInst = pCodecInst;

    return RETCODE_SUCCESS;
}

/*!
 * @brief Get the information of output of decoding.
 *
 * @param handle [Input] The handle obtained from vpu_DecOpen().
 * @param info [Output] Pointer to DecOutputInfo data structure.
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_WRONG_CALL_SEQUENCE Wrong calling sequence.
 * @li RETCODE_INVALID_PARAM Info is an invalid pointer.
 */
RetCode vpu_DecGetOutputInfo(DecHandle handle, DecOutputInfo * info)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    RetCode ret;
    uint32_t val = 0;
    uint32_t val2 = 0;
    PhysicalAddress paraBuffer;

    ENTER_FUNC();

    paraBuffer = bit_work_addr.phy_addr + CODE_BUF_SIZE + WORK_BUF_SIZE + PARA_BUF2_SIZE;

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    if (info == 0) {
        return RETCODE_INVALID_PARAM;
    }

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    if (*ppendingInst == 0) {
        return RETCODE_WRONG_CALL_SEQUENCE;
    }

    if (pCodecInst != *ppendingInst) {
        return RETCODE_INVALID_HANDLE;
    }

    memset(info, 0, sizeof(DecOutputInfo));

    if (cpu_is_mx6q() && VpuReadReg(RET_DEC_PIC_SUCCESS) & (1 << 31)) {
        *ppendingInst = 0;
        UnlockVpu(vpu_semap);
        return RETCODE_MEMORY_ACCESS_VIOLATION;
    }

    val = VpuReadReg(RET_DEC_PIC_SUCCESS);
    info->decodingSuccess = (val & 0x01);
    if (pCodecInst->codecMode == AVC_DEC) {
        info->notSufficientPsBuffer = (val >> 3) & 0x1;
        info->notSufficientSliceBuffer = (val >> 2) & 0x1;
    } else if (pCodecInst->codecMode == MP4_DEC) {
        info->mp4PackedPBframe = ((val >> 16) & 0x01);
        /* Need to backup WR_PTR for mp4PackedPBframe */
        if (info->mp4PackedPBframe)
            pCodecInst->ctxRegs[CTX_BIT_WR_PTR] = VpuReadReg(BIT_WR_PTR);
    }

    val = VpuReadReg(RET_DEC_PIC_SIZE); /* decoding picture size */
    info->decPicHeight = val & 0xFFFF;
    info->decPicWidth = (val >> 16) & 0xFFFF;

    if (cpu_is_mx6q() && pCodecInst->codecMode == VC1_DEC) {
        val = VpuReadReg(RET_DEC_PIC_POST);
        info->hScaleFlag = val >> 1 & 1;
        info->vScaleFlag = val >> 2 & 1;

        if (info->hScaleFlag)
            info->decPicWidth = pDecInfo->initialInfo.picWidth / 2;
        if (info->vScaleFlag)
            info->decPicHeight = pDecInfo->initialInfo.picHeight / 2;
    }

    if (pCodecInst->codecMode == VPX_DEC && pCodecInst->codecModeAux == VPX_AUX_VP8) {
        /* VP8 specific header information */
        /* h_scale[31:30] v_scale[29:28] pic_width[27:14] pic_height[13:0] */
        val = VpuReadReg(RET_DEC_PIC_VP8_SCALE_INFO);
        info->vp8ScaleInfo.hScaleFactor = (val >> 30) & 0x03;
        info->vp8ScaleInfo.vScaleFactor = (val >> 28) & 0x03;
        info->vp8ScaleInfo.picWidth = (val >> 14) & 0x3FFF;
        info->vp8ScaleInfo.picHeight = (val >> 0) & 0x3FFF;
        /* ref_idx_gold[31:24], ref_idx_altr[23:16], ref_idx_last[15: 8], */
        /* version_number[3:1], show_frame[0] */
        val = VpuReadReg(RET_DEC_PIC_VP8_PIC_REPORT);
        info->vp8PicInfo.refIdxGold = (val >> 24) & 0x0FF;
        info->vp8PicInfo.refIdxAltr = (val >> 16) & 0x0FF;
        info->vp8PicInfo.refIdxLast = (val >> 8) & 0x0FF;
        info->vp8PicInfo.versionNumber = (val >> 1) & 0x07;
        info->vp8PicInfo.showFrame = (val >> 0) & 0x01;
    }

    /* frame crop information */
    if (pCodecInst->codecMode == AVC_DEC) {
        val = VpuReadReg(RET_DEC_PIC_CROP_LEFT_RIGHT);
        val2 = VpuReadReg(RET_DEC_PIC_CROP_TOP_BOTTOM);
        if (val == 0 && val2 == 0) {
            info->decPicCrop.left = 0;
            info->decPicCrop.right = 0;
            info->decPicCrop.top = 0;
            info->decPicCrop.bottom = 0;
        } else {
            info->decPicCrop.left = ((val >> 16) & 0xFFFF);
            info->decPicCrop.right = info->decPicWidth - ((val & 0xFFFF));
            info->decPicCrop.top = ((val2 >> 16) & 0xFFFF);
            info->decPicCrop.bottom = info->decPicHeight - ((val2 & 0xFFFF));
        }
    } else {
        info->decPicCrop.left = 0;
        info->decPicCrop.right = 0;
        info->decPicCrop.top = 0;
        info->decPicCrop.bottom = 0;
    }

    val = VpuReadReg(RET_DEC_PIC_TYPE);

    if (pCodecInst->codecMode == VC1_DEC && pDecInfo->initialInfo.profile == 2) /* VC1 AP propile */
        info->picType = val & 0x3f;
    else
        info->picType = val & 0x7;

    info->interlacedFrame = (val >> 16) & 0x1;

    info->h264Npf = (val >> 16) & 0x3;
    info->interlacedFrame = (val >> 18) & 0x1;
    info->pictureStructure = (val >> 19) & 0x0003;  /* MbAffFlag[17], FieldPicFlag[16] */
    info->topFieldFirst = (val >> 21) & 0x0001; /* TopFieldFirst[18] */
    info->repeatFirstField = (val >> 22) & 0x0001;
    if (pCodecInst->codecMode == VC1_DEC)
        info->vc1_repeatFrame = (val >> 23) & 0x0003;
    else
        info->progressiveFrame = (val >> 23) & 0x0003;
    info->fieldSequence = (val >> 25) & 0x0007;

    if (cpu_is_mx6q()) {
        info->frameRateRes = VpuReadReg(RET_DEC_PIC_FRATE_NR);
        info->frameRateDiv = VpuReadReg(RET_DEC_PIC_FRATE_DR);
        if (pCodecInst->codecMode == VPX_DEC)
            info->aspectRateInfo = 0;
        else
            info->aspectRateInfo = VpuReadReg(RET_DEC_PIC_ASPECT);
    }

    if (pDecInfo->decReportFrameBufStat.enable) {
        int size = 0, paraInfo = 0, address = 0;
        uint32_t tempBuf[2], virt_addr;

        virt_addr = pDecInfo->picParaBaseMem.virt_uaddr;
        memcpy((char *)tempBuf, (void *)virt_addr, 8);
        if (cpu_is_mx37()) {
            val = swab32(*tempBuf);
            address = swab32(*(tempBuf + 1));
        } else {
            val = *(tempBuf + 1);
            address = *tempBuf;
        }

        paraInfo = (val >> 24) & 0xFF;
        size = (val >> 0) & 0xFFFFFF;

        info->frameBufStat.enable = 1;
        if (paraInfo == PARA_TYPE_FRM_BUF_STATUS) {
            info->frameBufStat.size = size;
            info->frameBufStat.addr = pDecInfo->decReportFrameBufStat.addr;
            size = (size + 7) / 8 * 8;
            if (info->frameBufStat.size && info->frameBufStat.addr) {
                uint8_t *dst_addr, *src_addr;
                dst_addr = (uint8_t *) info->frameBufStat.addr;
                src_addr = (uint8_t *) (virt_addr + ADDR_FRAME_BUF_STAT_BASE_OFFSET);
                CopyBufferData(dst_addr, src_addr, size);
            }
        }
    }

    /* Mb Param */
    if (pDecInfo->decReportMBInfo.enable) {
        int size = 0, paraInfo = 0, address = 0;
        uint32_t tempBuf[2], virt_addr;

        virt_addr = pDecInfo->picParaBaseMem.virt_uaddr;

        memcpy((char *)tempBuf, (void *)(virt_addr + 8), 8);
        val = *(tempBuf + 1);
        address = *tempBuf;

        paraInfo = (val >> 24) & 0xFF;
        size = (val >> 0) & 0x00FFFF;

        info->mbInfo.enable = 1;
        if (paraInfo == PARA_TYPE_MB_PARA) {
            info->mbInfo.size = size;
            info->mbInfo.addr = pDecInfo->decReportMBInfo.addr;
            size = (size + 7) / 8 * 8;
            if (info->mbInfo.size && info->mbInfo.addr) {
                uint8_t *dst_addr, *src_addr;
                dst_addr = (uint8_t *) info->mbInfo.addr;
                src_addr = (uint8_t *) (virt_addr + ADDR_MB_BASE_OFFSET);
                CopyBufferData(dst_addr, src_addr, size);
            }
        } else {
            /* VPU does not write data */
            info->mbInfo.size = 0;
            info->mbInfo.addr = 0;
        }

    }

    /* Motion Vector */
    if (pDecInfo->decReportMVInfo.enable) {
        int size = 0, paraInfo = 0, address = 0, mvNumPerMb = 0;
        uint32_t tempBuf[2], virt_addr;

        virt_addr = pDecInfo->picParaBaseMem.virt_uaddr;
        memcpy((char *)tempBuf, (void *)(virt_addr + 16), 8);
        val = *(tempBuf + 1);
        address = *tempBuf;

        paraInfo = (val >> 24) & 0xFF;
        mvNumPerMb = (val >> 16) & 0xFF;
        size = (val >> 0) & 0xFFFF;
        info->mvInfo.enable = 1;
        if (paraInfo == PARA_TYPE_MV) {

            info->mvInfo.size = size;
            info->mvInfo.mvNumPerMb = mvNumPerMb;
            info->mvInfo.addr = pDecInfo->decReportMVInfo.addr;
            if (info->mvInfo.size && info->mvInfo.addr) {
                uint8_t *dst_addr, *src_addr;
                dst_addr = (uint8_t *) info->mvInfo.addr;
                src_addr = (uint8_t *) (virt_addr + ADDR_MV_BASE_OFFSET);
                size = (size + 7) / 8 * 8 * mvNumPerMb * 4;
                CopyBufferData(dst_addr, src_addr, size);
            }

        } else {
            /* VPU does not write data */
            info->mvInfo.mvNumPerMb = 0;
            info->mvInfo.addr = 0;
        }
    }

    /* User Data */
    if (pDecInfo->decReportUserData.enable) {
        int userDataNum = 0, userDataSize = 0;
        uint32_t tempBuf[2], virt_addr;

        virt_addr = pDecInfo->userDataBufMem.virt_uaddr;

        memcpy((char *)tempBuf, (void *)virt_addr, 8);

        val = *(tempBuf + 1);
        userDataNum = (val >> 16) & 0xFFFF;
        userDataSize = (val >> 0) & 0xFFFF;
        if (userDataNum == 0)
            userDataSize = 0;

        info->userData.userDataNum = userDataNum;
        info->userData.size = userDataSize;

        val = *tempBuf;
        if (userDataNum == 0)
            info->userData.userDataBufFull = 0;
        else
            info->userData.userDataBufFull = (val >> 16) & 0xFFFF;

        info->userData.enable = 1;
        if (userDataSize && pDecInfo->decReportUserData.addr) {
            int size = (userDataSize + 7) / 8 * 8 + USER_DATA_INFO_OFFSET;
            uint8_t *dst_addr, *src_addr;
            dst_addr = (uint8_t *) pDecInfo->decReportUserData.addr;
            src_addr = (uint8_t *) virt_addr;
            CopyBufferData(dst_addr, src_addr, size);
        }
    }

    info->numOfErrMBs = VpuReadReg(RET_DEC_PIC_ERR_MB);
    info->prescanresult = VpuReadReg(RET_DEC_PIC_OPTION);

    info->indexFrameDisplay = VpuReadReg(RET_DEC_PIC_FRAME_IDX);
    info->indexFrameDecoded = VpuReadReg(RET_DEC_PIC_CUR_IDX);
    info->NumDecFrameBuf = VpuReadReg(RET_DEC_PIC_FRAME_NEED);

    /* save decoded picType to this array */
    if (info->indexFrameDecoded >= 0)
        decoded_pictype[info->indexFrameDecoded] = info->picType;

    if (pCodecInst->codecMode == VC1_DEC && info->indexFrameDisplay != -3) {
        if (pDecInfo->vc1BframeDisplayValid == 0) {
            /* Check the pictype of displayed frame */
            if ((decoded_pictype[info->indexFrameDisplay] == 3
                 && pDecInfo->initialInfo.profile != 2)
                || ((decoded_pictype[info->indexFrameDisplay] >> 3) == 3
                    && pDecInfo->initialInfo.profile == 2)) {
                /* clear buffer for not displayed B frame */
                val = ~(1 << info->indexFrameDisplay);
                val &= VpuReadReg(BIT_FRM_DIS_FLG);
                VpuWriteReg(BIT_FRM_DIS_FLG, val);
                info->indexFrameDisplay = -3;
            } else {
                pDecInfo->vc1BframeDisplayValid = 1;
            }
        }
    }

    /* Backup context regs, no need to save BIT_WR_PTR
       and BIT_FRAME_MEM_CTRL since f/w doesn't update the registers */
    pCodecInst->ctxRegs[CTX_BIT_FRM_DIS_FLG] = VpuReadReg(BIT_FRM_DIS_FLG);
    pCodecInst->ctxRegs[CTX_BIT_RD_PTR] = VpuReadReg(BIT_RD_PTR);
    pCodecInst->ctxRegs[CTX_BIT_STREAM_PARAM] = VpuReadReg(BIT_BIT_STREAM_PARAM);

    if (pCodecInst->codecMode == VC1_DEC) {
        val = VpuReadReg(RET_DEC_PIC_POST);
        info->hScaleFlag = (val >> 1) & 1;
        info->vScaleFlag = (val >> 2) & 1;
        info->indexFrameRangemap = -1;
        if (val & 1)
            info->indexFrameRangemap = (val >> 3) & 31;

    }

    *ppendingInst = 0;
    UnlockVpu(vpu_semap);

    /* Workaround for multi-instances competition */
    hal_delay_us(10);

    return RETCODE_SUCCESS;
}

RetCode vpu_DecBitBufferFlush(DecHandle handle)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    RetCode ret;

    ENTER_FUNC();

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    /* This means frame buffers have not been registered. */
    if (pDecInfo->frameBufPool == 0) {
        return RETCODE_WRONG_CALL_SEQUENCE;
    }

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    BitIssueCommandEx(pCodecInst, DEC_BUF_FLUSH);

    while (VpuReadReg(BIT_BUSY_FLAG)) ;

    pDecInfo->streamWrPtr = pDecInfo->streamBufStartAddr;

    VpuWriteReg(BIT_WR_PTR, pDecInfo->streamBufStartAddr);
    /* Backup context reg */
    pCodecInst->ctxRegs[CTX_BIT_WR_PTR] = pDecInfo->streamBufStartAddr;

    UnlockVpu(vpu_semap);

    return RETCODE_SUCCESS;
}

RetCode vpu_DecClrDispFlag(DecHandle handle, int index)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    RetCode ret;
    int val;

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    /* This means frame buffers have not been registered. */
    if (pDecInfo->frameBufPool == 0) {
        return RETCODE_WRONG_CALL_SEQUENCE;
    }

    if ((index < 0) || (index > (pDecInfo->numFrameBuffers - 1)))
        return RETCODE_INVALID_PARAM;

    val = (~(1 << index) & pCodecInst->ctxRegs[CTX_BIT_FRM_DIS_FLG]);
    pCodecInst->ctxRegs[CTX_BIT_FRM_DIS_FLG] = val;

    return RETCODE_SUCCESS;
}

/*!
 * @brief Give command to the decoder.
 *
 * @param handle [Input] The handle obtained from vpu_DecOpen().
 * @param cmd [Intput] Command.
 * @param param [Intput/Output] param  for cmd.
 *
 * @return
 * @li RETCODE_INVALID_COMMANDcmd is not valid.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_FRAME_NOT_COMPLETE A frame has not been finished.
 */
RetCode vpu_DecGiveCommand(DecHandle handle, CodecCommand cmd, void *param)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    RetCode ret;

    ENTER_FUNC();

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    if (cpu_is_mx27() && (cmd == DEC_SET_DEBLOCK_OUTPUT)) {
        return RETCODE_NOT_SUPPORTED;
    }

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    switch (cmd) {
    case ENABLE_ROTATION:
        {
            if (!pDecInfo->rotatorOutputValid) {
                return RETCODE_ROTATOR_OUTPUT_NOT_SET;
            }
            if (pDecInfo->rotatorStride == 0) {
                return RETCODE_ROTATOR_STRIDE_NOT_SET;
            }
            pDecInfo->rotationEnable = 1;
            break;
        }

    case DISABLE_ROTATION:
        {
            pDecInfo->rotationEnable = 0;
            break;
        }

    case ENABLE_MIRRORING:
        {
            if (!pDecInfo->rotatorOutputValid) {
                return RETCODE_ROTATOR_OUTPUT_NOT_SET;
            }
            if (pDecInfo->rotatorStride == 0) {
                return RETCODE_ROTATOR_STRIDE_NOT_SET;
            }
            pDecInfo->mirrorEnable = 1;
            break;
        }

    case DISABLE_MIRRORING:
        {
            pDecInfo->mirrorEnable = 0;
            break;
        }

    case SET_MIRROR_DIRECTION:
        {
            MirrorDirection mirDir;

            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }
            mirDir = *(MirrorDirection *) param;
            if (mirDir < MIRDIR_NONE || mirDir > MIRDIR_HOR_VER) {
                return RETCODE_INVALID_PARAM;
            }
            pDecInfo->mirrorDirection = mirDir;
            break;
        }

    case SET_ROTATION_ANGLE:
        {
            int angle;
            int height, width;

            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }
            angle = *(int *)param;
            if (angle != 0 && angle != 90 && angle != 180 && angle != 270) {
                return RETCODE_INVALID_PARAM;
            }
            if (pDecInfo->rotatorStride != 0) {
                height = pDecInfo->initialInfo.picHeight;
                width = pDecInfo->initialInfo.picWidth;

                if (angle == 90 || angle == 270) {
                    if (height > pDecInfo->rotatorStride) {
                        return RETCODE_INVALID_PARAM;
                    }
                } else {
                    if (width > pDecInfo->rotatorStride) {
                        return RETCODE_INVALID_PARAM;
                    }
                }
            }

            pDecInfo->rotationAngle = angle;
            break;
        }

    case SET_ROTATOR_OUTPUT:
        {
            FrameBuffer *frame;

            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }
            frame = (FrameBuffer *) param;
            pDecInfo->rotatorOutput = *frame;
            pDecInfo->rotatorOutputValid = 1;
            break;
        }

    case SET_ROTATOR_STRIDE:
        {
            int stride;

            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }
            stride = *(int *)param;
            if (stride % 8 != 0 || stride == 0) {
                return RETCODE_INVALID_STRIDE;
            }
            if (pDecInfo->rotationAngle == 90 || pDecInfo->rotationAngle == 270) {
                if (pDecInfo->initialInfo.picHeight > stride) {
                    return RETCODE_INVALID_STRIDE;
                }
            } else {
                if (pDecInfo->initialInfo.picWidth > stride) {
                    return RETCODE_INVALID_STRIDE;
                }
            }

            pDecInfo->rotatorStride = stride;
            break;
        }

    case DEC_SET_SPS_RBSP:
        {
            if (pCodecInst->codecMode != AVC_DEC) {
                return RETCODE_INVALID_COMMAND;
            }
            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }

            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;

            SetParaSet(handle, 0, param);
            UnlockVpu(vpu_semap);
            break;
        }

    case DEC_SET_PPS_RBSP:
        {
            if (pCodecInst->codecMode != AVC_DEC) {
                return RETCODE_INVALID_COMMAND;
            }
            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }
            SetParaSet(handle, 1, param);
            break;
        }

    case DEC_SET_DEBLOCK_OUTPUT:
        {
            if (!cpu_is_mx5x()) {
                FrameBuffer *frame;
                if (param == 0) {
                    return RETCODE_INVALID_PARAM;
                }
                frame = (FrameBuffer *) param;
                pDecInfo->deBlockingFilterOutput = *frame;
                pDecInfo->deBlockingFilterOutputValid = 1;
            }
            break;
        }
    case ENABLE_DERING:
        {
            if (!pDecInfo->rotatorOutputValid) {
                return RETCODE_ROTATOR_OUTPUT_NOT_SET;
            }
            if (pDecInfo->rotatorStride == 0) {
                return RETCODE_ROTATOR_STRIDE_NOT_SET;
            }
            pDecInfo->deringEnable = 1;
            break;
        }

    case DISABLE_DERING:
        {
            pDecInfo->deringEnable = 0;
            break;
        }

    case SET_DBK_OFFSET:
        {
            DbkOffset dbkOffset;
            dbkOffset = *(DbkOffset *) param;

            pDecInfo->dbkOffset.DbkOffsetA = dbkOffset.DbkOffsetA;
            pDecInfo->dbkOffset.DbkOffsetB = dbkOffset.DbkOffsetB;

            pDecInfo->dbkOffset.DbkOffsetEnable = ((pDecInfo->dbkOffset.DbkOffsetA != 0)
                                                   && (pDecInfo->dbkOffset.DbkOffsetB != 0));
            break;
        }

    case DEC_SET_REPORT_BUFSTAT:
        {
            if (param == 0)
                return RETCODE_INVALID_PARAM;
            pDecInfo->decReportFrameBufStat = *(DecReportInfo *) param;

            if (pDecInfo->decReportFrameBufStat.enable && !pDecInfo->decReportFrameBufStat.addr)
                return RETCODE_REPORT_BUF_NOT_SET;
            break;
        }

    case DEC_SET_REPORT_MBINFO:
        {
            if (param == 0)
                return RETCODE_INVALID_PARAM;
            pDecInfo->decReportMBInfo = *(DecReportInfo *) param;

            if (pDecInfo->decReportMBInfo.enable && !pDecInfo->decReportMBInfo.addr)
                return RETCODE_REPORT_BUF_NOT_SET;
            break;
        }

    case DEC_SET_REPORT_MVINFO:
        {
            if (param == 0)
                return RETCODE_INVALID_PARAM;
            pDecInfo->decReportMVInfo = *(DecReportInfo *) param;
            if (pDecInfo->decReportMVInfo.enable && !pDecInfo->decReportMVInfo.addr)
                return RETCODE_REPORT_BUF_NOT_SET;
            break;
        }

    case DEC_SET_REPORT_USERDATA:
        {
            if (param == 0)
                return RETCODE_INVALID_PARAM;
            pDecInfo->decReportUserData = *(DecReportInfo *) param;
            if ((pDecInfo->decReportUserData.enable) && (!pDecInfo->decReportUserData.addr))
                return RETCODE_REPORT_BUF_NOT_SET;
            break;
        }

    default:
        return RETCODE_INVALID_COMMAND;
    }

    return RETCODE_SUCCESS;
}