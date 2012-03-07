/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _VDOA_H
#define _VDOA_H

#include "regs.h"

/*
 * i.MX6SDL VDOA registers defined in this header file.
 *
 * - HW_VDOA_VDOAC - VDOA Control Register
 * - HW_VDOA_VDOASRR - VDOA Start and Reset
 * - HW_VDOA_VDOAIE - VDOA Interrupt Enable Register
 * - HW_VDOA_VDOAIST - VDOA Interrupt Status Register
 * - HW_VDOA_VDOAFP - VDOA Frame Parameters Register
 * - HW_VDOA_VDOAIEBA00 - VDOA IPU External Buffer 0 Frame 0 Address Register
 * - HW_VDOA_VDOAIEBA01 - VDOA IPU External Buffer 0 Frame 1 Address Register
 * - HW_VDOA_VDOAIEBA02 - VDOA IPU External Buffer 0 Frame 2 Address Register
 * - HW_VDOA_VDOAIEBA10 - VDOA IPU External Buffer 1 Frame 0 Address Register
 * - HW_VDOA_VDOAIEBA11 - VDOA IPU External Buffer 1 Frame 1 Address Register
 * - HW_VDOA_VDOAIEBA12 - VDOA IPU External Buffer 1 Frame 2 Address Register
 * - HW_VDOA_VDOASL - VDOA IPU Stride Line Register
 * - HW_VDOA_VDOAIUBO - VDOA IPU U (Chroma) Buffer Offset Register
 * - HW_VDOA_VDOAVEBA0 - VDOA VPU External Buffer 0 Address Register
 * - HW_VDOA_VDOAVEBA1 - VDOA VPU External Buffer 1 Address Register
 * - HW_VDOA_VDOAVEBA2 - VDOA VPU External Buffer 2 Address Register
 * - HW_VDOA_VDOAVUBO - VDOA VPU U (Chroma) Buffer Offset Register
 * - HW_VDOA_VDOASR - VDOA Status Register
 *
 * hw_vdoa_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_VDOA_BASE
#define REGS_VDOA_BASE (0x021e4000) //!< Base address for VDOA.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VDOA_VDOAC - VDOA Control Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_vdoa_vdoac
{
    reg32_t U;
    struct _hw_vdoa_vdoac_bitfields
    {
        unsigned BNDM : 2; //!< [1:0] BNDM Band Size
        unsigned NF : 1; //!< [2] Number of frames - Determines whether to transfer 1 frame or three frames
        unsigned SYNC : 1; //!< [3] SYNC MODE - defines whether the VDOA will transfer a full frame (or 2 frames) continuously or will transfer a band at a time and wait for IPU signal to continue
        unsigned SO : 1; //!< [4] Scan Order
        unsigned PFS : 1; //!< [5] Pixel Format Select - Pixel format of data written to / read from IPU. Note Data from VPU is always assumed to have partial interleaved 4:2:0 format
        unsigned ISEL : 1; //!< [6] IPU SELECT - determines in sync mode which of the two sets of hand shake pins is used
        unsigned RESERVED0 : 25; //!< [31:7] Reserved
    } B;
} hw_vdoa_vdoac_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAC register
 */
#define HW_VDOA_VDOAC_ADDR      (REGS_VDOA_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAC           (*(volatile hw_vdoa_vdoac_t *) HW_VDOA_VDOAC_ADDR)
#define HW_VDOA_VDOAC_RD()      (HW_VDOA_VDOAC.U)
#define HW_VDOA_VDOAC_WR(v)     (HW_VDOA_VDOAC.U = (v))
#define HW_VDOA_VDOAC_SET(v)    (HW_VDOA_VDOAC_WR(HW_VDOA_VDOAC_RD() |  (v)))
#define HW_VDOA_VDOAC_CLR(v)    (HW_VDOA_VDOAC_WR(HW_VDOA_VDOAC_RD() & ~(v)))
#define HW_VDOA_VDOAC_TOG(v)    (HW_VDOA_VDOAC_WR(HW_VDOA_VDOAC_RD() ^  (v)))
#endif

/*
 * constants & macros for individual VDOA_VDOAC bitfields
 */

/* --- Register HW_VDOA_VDOAC, field BNDM[1:0] (RW)
 *
 * BNDM Band Size
 *
 * Values:
 * BAND_HEIGHT_8 = 00 - Band height = 8 lines.- Supported only for interlaced scan (SO=1)
 * BAND_HEIGHT_16 = 01 - Band height = 16 lines.
 * BAND_HEIGHT_32 = 10 - Band height = 32 lines.
 * 11 - reserved
 */

#define BP_VDOA_VDOAC_BNDM      (0)      //!< Bit position for VDOA_VDOAC_BNDM.
#define BM_VDOA_VDOAC_BNDM      (0x00000003)  //!< Bit mask for VDOA_VDOAC_BNDM.

//! @brief Get value of VDOA_VDOAC_BNDM from a register value.
#define BG_VDOA_VDOAC_BNDM(r)   (((r) & BM_VDOA_VDOAC_BNDM) >> BP_VDOA_VDOAC_BNDM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAC_BNDM.
#define BF_VDOA_VDOAC_BNDM(v)   ((((reg32_t) v) << BP_VDOA_VDOAC_BNDM) & BM_VDOA_VDOAC_BNDM)
#else
//! @brief Format value for bitfield VDOA_VDOAC_BNDM.
#define BF_VDOA_VDOAC_BNDM(v)   (((v) << BP_VDOA_VDOAC_BNDM) & BM_VDOA_VDOAC_BNDM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BNDM field to a new value.
#define BW_VDOA_VDOAC_BNDM(v)   (HW_VDOA_VDOAC_WR((HW_VDOA_VDOAC_RD() & ~BM_VDOA_VDOAC_BNDM) | BF_VDOA_VDOAC_BNDM(v)))
#endif

#define BV_VDOA_VDOAC_BNDM__BAND_HEIGHT_8 (0x0) //!< Band height = 8 lines.- Supported only for interlaced scan (SO=1)
#define BV_VDOA_VDOAC_BNDM__BAND_HEIGHT_16 (0x1) //!< Band height = 16 lines.
#define BV_VDOA_VDOAC_BNDM__BAND_HEIGHT_32 (0x2) //!< Band height = 32 lines.

/* --- Register HW_VDOA_VDOAC, field NF[2] (RW)
 *
 * Number of frames - Determines whether to transfer 1 frame or three frames
 *
 * Values:
 * 1_FRAME = 0 - One frame (default)
 * 3_FRAMES = 1 - Three frames
 */

#define BP_VDOA_VDOAC_NF      (2)      //!< Bit position for VDOA_VDOAC_NF.
#define BM_VDOA_VDOAC_NF      (0x00000004)  //!< Bit mask for VDOA_VDOAC_NF.

//! @brief Get value of VDOA_VDOAC_NF from a register value.
#define BG_VDOA_VDOAC_NF(r)   (((r) & BM_VDOA_VDOAC_NF) >> BP_VDOA_VDOAC_NF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAC_NF.
#define BF_VDOA_VDOAC_NF(v)   ((((reg32_t) v) << BP_VDOA_VDOAC_NF) & BM_VDOA_VDOAC_NF)
#else
//! @brief Format value for bitfield VDOA_VDOAC_NF.
#define BF_VDOA_VDOAC_NF(v)   (((v) << BP_VDOA_VDOAC_NF) & BM_VDOA_VDOAC_NF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the NF field to a new value.
#define BW_VDOA_VDOAC_NF(v)   (HW_VDOA_VDOAC_WR((HW_VDOA_VDOAC_RD() & ~BM_VDOA_VDOAC_NF) | BF_VDOA_VDOAC_NF(v)))
#endif

#define BV_VDOA_VDOAC_NF__1_FRAME (0x0) //!< One frame (default)
#define BV_VDOA_VDOAC_NF__3_FRAMES (0x1) //!< Three frames

/* --- Register HW_VDOA_VDOAC, field SYNC[3] (RW)
 *
 * SYNC MODE - defines whether the VDOA will transfer a full frame (or 2 frames) continuously or
 * will transfer a band at a time and wait for IPU signal to continue
 *
 * Values:
 * NO_SYNC_MODE = 0 - None SYNC mode (default)
 * SYNC_MODE = 1 - Sync mode
 */

#define BP_VDOA_VDOAC_SYNC      (3)      //!< Bit position for VDOA_VDOAC_SYNC.
#define BM_VDOA_VDOAC_SYNC      (0x00000008)  //!< Bit mask for VDOA_VDOAC_SYNC.

//! @brief Get value of VDOA_VDOAC_SYNC from a register value.
#define BG_VDOA_VDOAC_SYNC(r)   (((r) & BM_VDOA_VDOAC_SYNC) >> BP_VDOA_VDOAC_SYNC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAC_SYNC.
#define BF_VDOA_VDOAC_SYNC(v)   ((((reg32_t) v) << BP_VDOA_VDOAC_SYNC) & BM_VDOA_VDOAC_SYNC)
#else
//! @brief Format value for bitfield VDOA_VDOAC_SYNC.
#define BF_VDOA_VDOAC_SYNC(v)   (((v) << BP_VDOA_VDOAC_SYNC) & BM_VDOA_VDOAC_SYNC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYNC field to a new value.
#define BW_VDOA_VDOAC_SYNC(v)   (HW_VDOA_VDOAC_WR((HW_VDOA_VDOAC_RD() & ~BM_VDOA_VDOAC_SYNC) | BF_VDOA_VDOAC_SYNC(v)))
#endif

#define BV_VDOA_VDOAC_SYNC__NO_SYNC_MODE (0x0) //!< None SYNC mode (default)
#define BV_VDOA_VDOAC_SYNC__SYNC_MODE (0x1) //!< Sync mode

/* --- Register HW_VDOA_VDOAC, field SO[4] (RW)
 *
 * Scan Order
 *
 * Values:
 * PROGRESSIVE = 0 - Scan order is progressive
 * INTERLACED = 1 - Scan order is interlaced
 */

#define BP_VDOA_VDOAC_SO      (4)      //!< Bit position for VDOA_VDOAC_SO.
#define BM_VDOA_VDOAC_SO      (0x00000010)  //!< Bit mask for VDOA_VDOAC_SO.

//! @brief Get value of VDOA_VDOAC_SO from a register value.
#define BG_VDOA_VDOAC_SO(r)   (((r) & BM_VDOA_VDOAC_SO) >> BP_VDOA_VDOAC_SO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAC_SO.
#define BF_VDOA_VDOAC_SO(v)   ((((reg32_t) v) << BP_VDOA_VDOAC_SO) & BM_VDOA_VDOAC_SO)
#else
//! @brief Format value for bitfield VDOA_VDOAC_SO.
#define BF_VDOA_VDOAC_SO(v)   (((v) << BP_VDOA_VDOAC_SO) & BM_VDOA_VDOAC_SO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SO field to a new value.
#define BW_VDOA_VDOAC_SO(v)   (HW_VDOA_VDOAC_WR((HW_VDOA_VDOAC_RD() & ~BM_VDOA_VDOAC_SO) | BF_VDOA_VDOAC_SO(v)))
#endif

#define BV_VDOA_VDOAC_SO__PROGRESSIVE (0x0) //!< Scan order is progressive
#define BV_VDOA_VDOAC_SO__INTERLACED (0x1) //!< Scan order is interlaced

/* --- Register HW_VDOA_VDOAC, field PFS[5] (RW)
 *
 * Pixel Format Select - Pixel format of data written to / read from IPU. Note Data from VPU is
 * always assumed to have partial interleaved 4:2:0 format
 *
 * Values:
 * 4_2_0 = 0 - partialy interleaved 4:2:0
 * 4_2_2 = 1 - interleaved 4:2:2 Y1U1Y2V1
 */

#define BP_VDOA_VDOAC_PFS      (5)      //!< Bit position for VDOA_VDOAC_PFS.
#define BM_VDOA_VDOAC_PFS      (0x00000020)  //!< Bit mask for VDOA_VDOAC_PFS.

//! @brief Get value of VDOA_VDOAC_PFS from a register value.
#define BG_VDOA_VDOAC_PFS(r)   (((r) & BM_VDOA_VDOAC_PFS) >> BP_VDOA_VDOAC_PFS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAC_PFS.
#define BF_VDOA_VDOAC_PFS(v)   ((((reg32_t) v) << BP_VDOA_VDOAC_PFS) & BM_VDOA_VDOAC_PFS)
#else
//! @brief Format value for bitfield VDOA_VDOAC_PFS.
#define BF_VDOA_VDOAC_PFS(v)   (((v) << BP_VDOA_VDOAC_PFS) & BM_VDOA_VDOAC_PFS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFS field to a new value.
#define BW_VDOA_VDOAC_PFS(v)   (HW_VDOA_VDOAC_WR((HW_VDOA_VDOAC_RD() & ~BM_VDOA_VDOAC_PFS) | BF_VDOA_VDOAC_PFS(v)))
#endif

#define BV_VDOA_VDOAC_PFS__4_2_0 (0x0) //!< partialy interleaved 4:2:0
#define BV_VDOA_VDOAC_PFS__4_2_2 (0x1) //!< interleaved 4:2:2 Y1U1Y2V1

/* --- Register HW_VDOA_VDOAC, field ISEL[6] (RW)
 *
 * IPU SELECT - determines in sync mode which of the two sets of hand shake pins is used
 *
 * Values:
 * VDOA_BUF_RDY_AND_IPU_BUF_EOB_0 = 0 - Use vdoa_buf_rdy[0] and ipu_buf_eob[0]
 * VDOA_BUF_RDY_AND_IPU_BUF_EOB_1 = 1 - Use vdoa_buf_rdy[1] and ipu_buf_eob[1]
 */

#define BP_VDOA_VDOAC_ISEL      (6)      //!< Bit position for VDOA_VDOAC_ISEL.
#define BM_VDOA_VDOAC_ISEL      (0x00000040)  //!< Bit mask for VDOA_VDOAC_ISEL.

//! @brief Get value of VDOA_VDOAC_ISEL from a register value.
#define BG_VDOA_VDOAC_ISEL(r)   (((r) & BM_VDOA_VDOAC_ISEL) >> BP_VDOA_VDOAC_ISEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAC_ISEL.
#define BF_VDOA_VDOAC_ISEL(v)   ((((reg32_t) v) << BP_VDOA_VDOAC_ISEL) & BM_VDOA_VDOAC_ISEL)
#else
//! @brief Format value for bitfield VDOA_VDOAC_ISEL.
#define BF_VDOA_VDOAC_ISEL(v)   (((v) << BP_VDOA_VDOAC_ISEL) & BM_VDOA_VDOAC_ISEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ISEL field to a new value.
#define BW_VDOA_VDOAC_ISEL(v)   (HW_VDOA_VDOAC_WR((HW_VDOA_VDOAC_RD() & ~BM_VDOA_VDOAC_ISEL) | BF_VDOA_VDOAC_ISEL(v)))
#endif

#define BV_VDOA_VDOAC_ISEL__VDOA_BUF_RDY_AND_IPU_BUF_EOB_0 (0x0) //!< Use vdoa_buf_rdy[0] and ipu_buf_eob[0]
#define BV_VDOA_VDOAC_ISEL__VDOA_BUF_RDY_AND_IPU_BUF_EOB_1 (0x1) //!< Use vdoa_buf_rdy[1] and ipu_buf_eob[1]

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VDOA_VDOASRR - VDOA Start and Reset (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_vdoa_vdoasrr
{
    reg32_t U;
    struct _hw_vdoa_vdoasrr_bitfields
    {
        unsigned SWRST : 1; //!< [0] Software reset - Finish outstanding AXI transfer and reset all internal registers the configuration registers are mnot cleared
        unsigned START : 1; //!< [1] Start Transfer - Strat a VDOA data transfer according to all parameters. Note: During run this bit is read only In IDLE -
        unsigned RESERVED0 : 30; //!< [31:2] Reserved
    } B;
} hw_vdoa_vdoasrr_t;
#endif

/*
 * constants & macros for entire VDOA_VDOASRR register
 */
#define HW_VDOA_VDOASRR_ADDR      (REGS_VDOA_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOASRR           (*(volatile hw_vdoa_vdoasrr_t *) HW_VDOA_VDOASRR_ADDR)
#define HW_VDOA_VDOASRR_RD()      (HW_VDOA_VDOASRR.U)
#define HW_VDOA_VDOASRR_WR(v)     (HW_VDOA_VDOASRR.U = (v))
#define HW_VDOA_VDOASRR_SET(v)    (HW_VDOA_VDOASRR_WR(HW_VDOA_VDOASRR_RD() |  (v)))
#define HW_VDOA_VDOASRR_CLR(v)    (HW_VDOA_VDOASRR_WR(HW_VDOA_VDOASRR_RD() & ~(v)))
#define HW_VDOA_VDOASRR_TOG(v)    (HW_VDOA_VDOASRR_WR(HW_VDOA_VDOASRR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual VDOA_VDOASRR bitfields
 */

/* --- Register HW_VDOA_VDOASRR, field SWRST[0] (RW)
 *
 * Software reset - Finish outstanding AXI transfer and reset all internal registers the
 * configuration registers are mnot cleared
 */

#define BP_VDOA_VDOASRR_SWRST      (0)      //!< Bit position for VDOA_VDOASRR_SWRST.
#define BM_VDOA_VDOASRR_SWRST      (0x00000001)  //!< Bit mask for VDOA_VDOASRR_SWRST.

//! @brief Get value of VDOA_VDOASRR_SWRST from a register value.
#define BG_VDOA_VDOASRR_SWRST(r)   (((r) & BM_VDOA_VDOASRR_SWRST) >> BP_VDOA_VDOASRR_SWRST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOASRR_SWRST.
#define BF_VDOA_VDOASRR_SWRST(v)   ((((reg32_t) v) << BP_VDOA_VDOASRR_SWRST) & BM_VDOA_VDOASRR_SWRST)
#else
//! @brief Format value for bitfield VDOA_VDOASRR_SWRST.
#define BF_VDOA_VDOASRR_SWRST(v)   (((v) << BP_VDOA_VDOASRR_SWRST) & BM_VDOA_VDOASRR_SWRST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SWRST field to a new value.
#define BW_VDOA_VDOASRR_SWRST(v)   (HW_VDOA_VDOASRR_WR((HW_VDOA_VDOASRR_RD() & ~BM_VDOA_VDOASRR_SWRST) | BF_VDOA_VDOASRR_SWRST(v)))
#endif

/* --- Register HW_VDOA_VDOASRR, field START[1] (RW)
 *
 * Start Transfer - Strat a VDOA data transfer according to all parameters. Note: During run this
 * bit is read only In IDLE -
 *
 * Values:
 * 0 - Ignored
 * START_TRANSFER = 1 - Start a new transfer All registers we copied internally so any write to them will take place only in
 *     next transfer (double buffer)
 */

#define BP_VDOA_VDOASRR_START      (1)      //!< Bit position for VDOA_VDOASRR_START.
#define BM_VDOA_VDOASRR_START      (0x00000002)  //!< Bit mask for VDOA_VDOASRR_START.

//! @brief Get value of VDOA_VDOASRR_START from a register value.
#define BG_VDOA_VDOASRR_START(r)   (((r) & BM_VDOA_VDOASRR_START) >> BP_VDOA_VDOASRR_START)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOASRR_START.
#define BF_VDOA_VDOASRR_START(v)   ((((reg32_t) v) << BP_VDOA_VDOASRR_START) & BM_VDOA_VDOASRR_START)
#else
//! @brief Format value for bitfield VDOA_VDOASRR_START.
#define BF_VDOA_VDOASRR_START(v)   (((v) << BP_VDOA_VDOASRR_START) & BM_VDOA_VDOASRR_START)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the START field to a new value.
#define BW_VDOA_VDOASRR_START(v)   (HW_VDOA_VDOASRR_WR((HW_VDOA_VDOASRR_RD() & ~BM_VDOA_VDOASRR_START) | BF_VDOA_VDOASRR_START(v)))
#endif

#define BV_VDOA_VDOASRR_START__START_TRANSFER (0x1) //!< Start a new transfer All registers we copied internally so any write to them will take place only in next transfer (double buffer)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VDOA_VDOAIE - VDOA Interrupt Enable Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_vdoa_vdoaie
{
    reg32_t U;
    struct _hw_vdoa_vdoaie_bitfields
    {
        unsigned EIEOT : 1; //!< [0] EIEOT - Enable Interrupt End Of Transfer- Enables Interrupt on end of transfer
        unsigned EITERR : 1; //!< [1] EITERR - Enable Interrupt Transfer access Error - Enables Interrupt on AXI access Error
        unsigned RESERVED0 : 30; //!< [31:2] Reserved
    } B;
} hw_vdoa_vdoaie_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAIE register
 */
#define HW_VDOA_VDOAIE_ADDR      (REGS_VDOA_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAIE           (*(volatile hw_vdoa_vdoaie_t *) HW_VDOA_VDOAIE_ADDR)
#define HW_VDOA_VDOAIE_RD()      (HW_VDOA_VDOAIE.U)
#define HW_VDOA_VDOAIE_WR(v)     (HW_VDOA_VDOAIE.U = (v))
#define HW_VDOA_VDOAIE_SET(v)    (HW_VDOA_VDOAIE_WR(HW_VDOA_VDOAIE_RD() |  (v)))
#define HW_VDOA_VDOAIE_CLR(v)    (HW_VDOA_VDOAIE_WR(HW_VDOA_VDOAIE_RD() & ~(v)))
#define HW_VDOA_VDOAIE_TOG(v)    (HW_VDOA_VDOAIE_WR(HW_VDOA_VDOAIE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual VDOA_VDOAIE bitfields
 */

/* --- Register HW_VDOA_VDOAIE, field EIEOT[0] (RW)
 *
 * EIEOT - Enable Interrupt End Of Transfer- Enables Interrupt on end of transfer
 *
 * Values:
 * IRQ_DISABLED = 0 - interrupt disable (default)
 * IRQ_ENABLED = 1 - Interrupt Enabled
 */

#define BP_VDOA_VDOAIE_EIEOT      (0)      //!< Bit position for VDOA_VDOAIE_EIEOT.
#define BM_VDOA_VDOAIE_EIEOT      (0x00000001)  //!< Bit mask for VDOA_VDOAIE_EIEOT.

//! @brief Get value of VDOA_VDOAIE_EIEOT from a register value.
#define BG_VDOA_VDOAIE_EIEOT(r)   (((r) & BM_VDOA_VDOAIE_EIEOT) >> BP_VDOA_VDOAIE_EIEOT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAIE_EIEOT.
#define BF_VDOA_VDOAIE_EIEOT(v)   ((((reg32_t) v) << BP_VDOA_VDOAIE_EIEOT) & BM_VDOA_VDOAIE_EIEOT)
#else
//! @brief Format value for bitfield VDOA_VDOAIE_EIEOT.
#define BF_VDOA_VDOAIE_EIEOT(v)   (((v) << BP_VDOA_VDOAIE_EIEOT) & BM_VDOA_VDOAIE_EIEOT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EIEOT field to a new value.
#define BW_VDOA_VDOAIE_EIEOT(v)   (HW_VDOA_VDOAIE_WR((HW_VDOA_VDOAIE_RD() & ~BM_VDOA_VDOAIE_EIEOT) | BF_VDOA_VDOAIE_EIEOT(v)))
#endif

#define BV_VDOA_VDOAIE_EIEOT__IRQ_DISABLED (0x0) //!< interrupt disable (default)
#define BV_VDOA_VDOAIE_EIEOT__IRQ_ENABLED (0x1) //!< Interrupt Enabled

/* --- Register HW_VDOA_VDOAIE, field EITERR[1] (RW)
 *
 * EITERR - Enable Interrupt Transfer access Error - Enables Interrupt on AXI access Error
 *
 * Values:
 * IRQ_DISABLED = 0 - interrupt disable (default)
 * IRQ_ENABLED = 1 - Interrupt Enabled
 */

#define BP_VDOA_VDOAIE_EITERR      (1)      //!< Bit position for VDOA_VDOAIE_EITERR.
#define BM_VDOA_VDOAIE_EITERR      (0x00000002)  //!< Bit mask for VDOA_VDOAIE_EITERR.

//! @brief Get value of VDOA_VDOAIE_EITERR from a register value.
#define BG_VDOA_VDOAIE_EITERR(r)   (((r) & BM_VDOA_VDOAIE_EITERR) >> BP_VDOA_VDOAIE_EITERR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAIE_EITERR.
#define BF_VDOA_VDOAIE_EITERR(v)   ((((reg32_t) v) << BP_VDOA_VDOAIE_EITERR) & BM_VDOA_VDOAIE_EITERR)
#else
//! @brief Format value for bitfield VDOA_VDOAIE_EITERR.
#define BF_VDOA_VDOAIE_EITERR(v)   (((v) << BP_VDOA_VDOAIE_EITERR) & BM_VDOA_VDOAIE_EITERR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EITERR field to a new value.
#define BW_VDOA_VDOAIE_EITERR(v)   (HW_VDOA_VDOAIE_WR((HW_VDOA_VDOAIE_RD() & ~BM_VDOA_VDOAIE_EITERR) | BF_VDOA_VDOAIE_EITERR(v)))
#endif

#define BV_VDOA_VDOAIE_EITERR__IRQ_DISABLED (0x0) //!< interrupt disable (default)
#define BV_VDOA_VDOAIE_EITERR__IRQ_ENABLED (0x1) //!< Interrupt Enabled

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VDOA_VDOAIST - VDOA Interrupt Status Register (W1C)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_vdoa_vdoaist
{
    reg32_t U;
    struct _hw_vdoa_vdoaist_bitfields
    {
        unsigned EOT : 1; //!< [0] End Of transfer - Transfer was completed if EIEOT is set an interrupt will be generated
        unsigned TERR : 1; //!< [1] Axi Access had an access error see ERRW bit in 0XBASE_0044 (VDOASR) for type of access (read write) if EITERR is set an interrupt will be generated
        unsigned RESERVED0 : 30; //!< [31:2] Reserved
    } B;
} hw_vdoa_vdoaist_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAIST register
 */
#define HW_VDOA_VDOAIST_ADDR      (REGS_VDOA_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAIST           (*(volatile hw_vdoa_vdoaist_t *) HW_VDOA_VDOAIST_ADDR)
#define HW_VDOA_VDOAIST_RD()      (HW_VDOA_VDOAIST.U)
#define HW_VDOA_VDOAIST_WR(v)     (HW_VDOA_VDOAIST.U = (v))
#define HW_VDOA_VDOAIST_SET(v)    (HW_VDOA_VDOAIST_WR(HW_VDOA_VDOAIST_RD() |  (v)))
#define HW_VDOA_VDOAIST_CLR(v)    (HW_VDOA_VDOAIST_WR(HW_VDOA_VDOAIST_RD() & ~(v)))
#define HW_VDOA_VDOAIST_TOG(v)    (HW_VDOA_VDOAIST_WR(HW_VDOA_VDOAIST_RD() ^  (v)))
#endif

/*
 * constants & macros for individual VDOA_VDOAIST bitfields
 */

/* --- Register HW_VDOA_VDOAIST, field EOT[0] (W1C)
 *
 * End Of transfer - Transfer was completed if EIEOT is set an interrupt will be generated
 */

#define BP_VDOA_VDOAIST_EOT      (0)      //!< Bit position for VDOA_VDOAIST_EOT.
#define BM_VDOA_VDOAIST_EOT      (0x00000001)  //!< Bit mask for VDOA_VDOAIST_EOT.

//! @brief Get value of VDOA_VDOAIST_EOT from a register value.
#define BG_VDOA_VDOAIST_EOT(r)   (((r) & BM_VDOA_VDOAIST_EOT) >> BP_VDOA_VDOAIST_EOT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAIST_EOT.
#define BF_VDOA_VDOAIST_EOT(v)   ((((reg32_t) v) << BP_VDOA_VDOAIST_EOT) & BM_VDOA_VDOAIST_EOT)
#else
//! @brief Format value for bitfield VDOA_VDOAIST_EOT.
#define BF_VDOA_VDOAIST_EOT(v)   (((v) << BP_VDOA_VDOAIST_EOT) & BM_VDOA_VDOAIST_EOT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EOT field to a new value.
#define BW_VDOA_VDOAIST_EOT(v)   (HW_VDOA_VDOAIST_WR((HW_VDOA_VDOAIST_RD() & ~BM_VDOA_VDOAIST_EOT) | BF_VDOA_VDOAIST_EOT(v)))
#endif

/* --- Register HW_VDOA_VDOAIST, field TERR[1] (W1C)
 *
 * Axi Access had an access error see ERRW bit in 0XBASE_0044 (VDOASR) for type of access (read
 * write) if EITERR is set an interrupt will be generated
 */

#define BP_VDOA_VDOAIST_TERR      (1)      //!< Bit position for VDOA_VDOAIST_TERR.
#define BM_VDOA_VDOAIST_TERR      (0x00000002)  //!< Bit mask for VDOA_VDOAIST_TERR.

//! @brief Get value of VDOA_VDOAIST_TERR from a register value.
#define BG_VDOA_VDOAIST_TERR(r)   (((r) & BM_VDOA_VDOAIST_TERR) >> BP_VDOA_VDOAIST_TERR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAIST_TERR.
#define BF_VDOA_VDOAIST_TERR(v)   ((((reg32_t) v) << BP_VDOA_VDOAIST_TERR) & BM_VDOA_VDOAIST_TERR)
#else
//! @brief Format value for bitfield VDOA_VDOAIST_TERR.
#define BF_VDOA_VDOAIST_TERR(v)   (((v) << BP_VDOA_VDOAIST_TERR) & BM_VDOA_VDOAIST_TERR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TERR field to a new value.
#define BW_VDOA_VDOAIST_TERR(v)   (HW_VDOA_VDOAIST_WR((HW_VDOA_VDOAIST_RD() & ~BM_VDOA_VDOAIST_TERR) | BF_VDOA_VDOAIST_TERR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VDOA_VDOAFP - VDOA Frame Parameters Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_vdoa_vdoafp
{
    reg32_t U;
    struct _hw_vdoa_vdoafp_bitfields
    {
        unsigned FW : 14; //!< [13:0] Number of pixels in one row, of the frame. Note the3 LSB are RO and will always be 0 (multiply of 8)
        unsigned RESERVED0 : 2; //!< [15:14] Reserved
        unsigned FH : 13; //!< [28:16] Number of pixels in one column, of the frame. Note the 3 LSB are RO and will always be 0 (multiply of 8)
        unsigned RESERVED1 : 3; //!< [31:29] reserved
    } B;
} hw_vdoa_vdoafp_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAFP register
 */
#define HW_VDOA_VDOAFP_ADDR      (REGS_VDOA_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAFP           (*(volatile hw_vdoa_vdoafp_t *) HW_VDOA_VDOAFP_ADDR)
#define HW_VDOA_VDOAFP_RD()      (HW_VDOA_VDOAFP.U)
#define HW_VDOA_VDOAFP_WR(v)     (HW_VDOA_VDOAFP.U = (v))
#define HW_VDOA_VDOAFP_SET(v)    (HW_VDOA_VDOAFP_WR(HW_VDOA_VDOAFP_RD() |  (v)))
#define HW_VDOA_VDOAFP_CLR(v)    (HW_VDOA_VDOAFP_WR(HW_VDOA_VDOAFP_RD() & ~(v)))
#define HW_VDOA_VDOAFP_TOG(v)    (HW_VDOA_VDOAFP_WR(HW_VDOA_VDOAFP_RD() ^  (v)))
#endif

/*
 * constants & macros for individual VDOA_VDOAFP bitfields
 */

/* --- Register HW_VDOA_VDOAFP, field FW[13:0] (RW)
 *
 * Number of pixels in one row, of the frame. Note the3 LSB are RO and will always be 0 (multiply of
 * 8)
 */

#define BP_VDOA_VDOAFP_FW      (0)      //!< Bit position for VDOA_VDOAFP_FW.
#define BM_VDOA_VDOAFP_FW      (0x00003fff)  //!< Bit mask for VDOA_VDOAFP_FW.

//! @brief Get value of VDOA_VDOAFP_FW from a register value.
#define BG_VDOA_VDOAFP_FW(r)   (((r) & BM_VDOA_VDOAFP_FW) >> BP_VDOA_VDOAFP_FW)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAFP_FW.
#define BF_VDOA_VDOAFP_FW(v)   ((((reg32_t) v) << BP_VDOA_VDOAFP_FW) & BM_VDOA_VDOAFP_FW)
#else
//! @brief Format value for bitfield VDOA_VDOAFP_FW.
#define BF_VDOA_VDOAFP_FW(v)   (((v) << BP_VDOA_VDOAFP_FW) & BM_VDOA_VDOAFP_FW)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FW field to a new value.
#define BW_VDOA_VDOAFP_FW(v)   (HW_VDOA_VDOAFP_WR((HW_VDOA_VDOAFP_RD() & ~BM_VDOA_VDOAFP_FW) | BF_VDOA_VDOAFP_FW(v)))
#endif

/* --- Register HW_VDOA_VDOAFP, field FH[28:16] (RW)
 *
 * Number of pixels in one column, of the frame. Note the 3 LSB are RO and will always be 0
 * (multiply of 8)
 */

#define BP_VDOA_VDOAFP_FH      (16)      //!< Bit position for VDOA_VDOAFP_FH.
#define BM_VDOA_VDOAFP_FH      (0x1fff0000)  //!< Bit mask for VDOA_VDOAFP_FH.

//! @brief Get value of VDOA_VDOAFP_FH from a register value.
#define BG_VDOA_VDOAFP_FH(r)   (((r) & BM_VDOA_VDOAFP_FH) >> BP_VDOA_VDOAFP_FH)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAFP_FH.
#define BF_VDOA_VDOAFP_FH(v)   ((((reg32_t) v) << BP_VDOA_VDOAFP_FH) & BM_VDOA_VDOAFP_FH)
#else
//! @brief Format value for bitfield VDOA_VDOAFP_FH.
#define BF_VDOA_VDOAFP_FH(v)   (((v) << BP_VDOA_VDOAFP_FH) & BM_VDOA_VDOAFP_FH)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FH field to a new value.
#define BW_VDOA_VDOAFP_FH(v)   (HW_VDOA_VDOAFP_WR((HW_VDOA_VDOAFP_RD() & ~BM_VDOA_VDOAFP_FH) | BF_VDOA_VDOAFP_FH(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VDOA_VDOAIEBA00 - VDOA IPU External Buffer 0 Frame 0 Address Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_vdoa_vdoaieba00
{
    reg32_t U;
    struct _hw_vdoa_vdoaieba00_bitfields
    {
        unsigned IEBA00 : 32; //!< [31:0] External Address of Frame 0 output (IPU) buffer 0 - Note that the 3 LSB are always 0 (aligned to 8 address) Used for all transfer types
    } B;
} hw_vdoa_vdoaieba00_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAIEBA00 register
 */
#define HW_VDOA_VDOAIEBA00_ADDR      (REGS_VDOA_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAIEBA00           (*(volatile hw_vdoa_vdoaieba00_t *) HW_VDOA_VDOAIEBA00_ADDR)
#define HW_VDOA_VDOAIEBA00_RD()      (HW_VDOA_VDOAIEBA00.U)
#define HW_VDOA_VDOAIEBA00_WR(v)     (HW_VDOA_VDOAIEBA00.U = (v))
#define HW_VDOA_VDOAIEBA00_SET(v)    (HW_VDOA_VDOAIEBA00_WR(HW_VDOA_VDOAIEBA00_RD() |  (v)))
#define HW_VDOA_VDOAIEBA00_CLR(v)    (HW_VDOA_VDOAIEBA00_WR(HW_VDOA_VDOAIEBA00_RD() & ~(v)))
#define HW_VDOA_VDOAIEBA00_TOG(v)    (HW_VDOA_VDOAIEBA00_WR(HW_VDOA_VDOAIEBA00_RD() ^  (v)))
#endif

/*
 * constants & macros for individual VDOA_VDOAIEBA00 bitfields
 */

/* --- Register HW_VDOA_VDOAIEBA00, field IEBA00[31:0] (RW)
 *
 * External Address of Frame 0 output (IPU) buffer 0 - Note that the 3 LSB are always 0 (aligned to
 * 8 address) Used for all transfer types
 */

#define BP_VDOA_VDOAIEBA00_IEBA00      (0)      //!< Bit position for VDOA_VDOAIEBA00_IEBA00.
#define BM_VDOA_VDOAIEBA00_IEBA00      (0xffffffff)  //!< Bit mask for VDOA_VDOAIEBA00_IEBA00.

//! @brief Get value of VDOA_VDOAIEBA00_IEBA00 from a register value.
#define BG_VDOA_VDOAIEBA00_IEBA00(r)   (((r) & BM_VDOA_VDOAIEBA00_IEBA00) >> BP_VDOA_VDOAIEBA00_IEBA00)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAIEBA00_IEBA00.
#define BF_VDOA_VDOAIEBA00_IEBA00(v)   ((((reg32_t) v) << BP_VDOA_VDOAIEBA00_IEBA00) & BM_VDOA_VDOAIEBA00_IEBA00)
#else
//! @brief Format value for bitfield VDOA_VDOAIEBA00_IEBA00.
#define BF_VDOA_VDOAIEBA00_IEBA00(v)   (((v) << BP_VDOA_VDOAIEBA00_IEBA00) & BM_VDOA_VDOAIEBA00_IEBA00)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IEBA00 field to a new value.
#define BW_VDOA_VDOAIEBA00_IEBA00(v)   (HW_VDOA_VDOAIEBA00_WR((HW_VDOA_VDOAIEBA00_RD() & ~BM_VDOA_VDOAIEBA00_IEBA00) | BF_VDOA_VDOAIEBA00_IEBA00(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VDOA_VDOAIEBA01 - VDOA IPU External Buffer 0 Frame 1 Address Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_vdoa_vdoaieba01
{
    reg32_t U;
    struct _hw_vdoa_vdoaieba01_bitfields
    {
        unsigned IEBA01 : 32; //!< [31:0] External Address of Frame 1 output (IPU) buffer 0 - Note that the 3 LSB are always 0 (aligned to 8 address) Used when transfering 3 frames (NF=1) only
    } B;
} hw_vdoa_vdoaieba01_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAIEBA01 register
 */
#define HW_VDOA_VDOAIEBA01_ADDR      (REGS_VDOA_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAIEBA01           (*(volatile hw_vdoa_vdoaieba01_t *) HW_VDOA_VDOAIEBA01_ADDR)
#define HW_VDOA_VDOAIEBA01_RD()      (HW_VDOA_VDOAIEBA01.U)
#define HW_VDOA_VDOAIEBA01_WR(v)     (HW_VDOA_VDOAIEBA01.U = (v))
#define HW_VDOA_VDOAIEBA01_SET(v)    (HW_VDOA_VDOAIEBA01_WR(HW_VDOA_VDOAIEBA01_RD() |  (v)))
#define HW_VDOA_VDOAIEBA01_CLR(v)    (HW_VDOA_VDOAIEBA01_WR(HW_VDOA_VDOAIEBA01_RD() & ~(v)))
#define HW_VDOA_VDOAIEBA01_TOG(v)    (HW_VDOA_VDOAIEBA01_WR(HW_VDOA_VDOAIEBA01_RD() ^  (v)))
#endif

/*
 * constants & macros for individual VDOA_VDOAIEBA01 bitfields
 */

/* --- Register HW_VDOA_VDOAIEBA01, field IEBA01[31:0] (RW)
 *
 * External Address of Frame 1 output (IPU) buffer 0 - Note that the 3 LSB are always 0 (aligned to
 * 8 address) Used when transfering 3 frames (NF=1) only
 */

#define BP_VDOA_VDOAIEBA01_IEBA01      (0)      //!< Bit position for VDOA_VDOAIEBA01_IEBA01.
#define BM_VDOA_VDOAIEBA01_IEBA01      (0xffffffff)  //!< Bit mask for VDOA_VDOAIEBA01_IEBA01.

//! @brief Get value of VDOA_VDOAIEBA01_IEBA01 from a register value.
#define BG_VDOA_VDOAIEBA01_IEBA01(r)   (((r) & BM_VDOA_VDOAIEBA01_IEBA01) >> BP_VDOA_VDOAIEBA01_IEBA01)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAIEBA01_IEBA01.
#define BF_VDOA_VDOAIEBA01_IEBA01(v)   ((((reg32_t) v) << BP_VDOA_VDOAIEBA01_IEBA01) & BM_VDOA_VDOAIEBA01_IEBA01)
#else
//! @brief Format value for bitfield VDOA_VDOAIEBA01_IEBA01.
#define BF_VDOA_VDOAIEBA01_IEBA01(v)   (((v) << BP_VDOA_VDOAIEBA01_IEBA01) & BM_VDOA_VDOAIEBA01_IEBA01)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IEBA01 field to a new value.
#define BW_VDOA_VDOAIEBA01_IEBA01(v)   (HW_VDOA_VDOAIEBA01_WR((HW_VDOA_VDOAIEBA01_RD() & ~BM_VDOA_VDOAIEBA01_IEBA01) | BF_VDOA_VDOAIEBA01_IEBA01(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VDOA_VDOAIEBA02 - VDOA IPU External Buffer 0 Frame 2 Address Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_vdoa_vdoaieba02
{
    reg32_t U;
    struct _hw_vdoa_vdoaieba02_bitfields
    {
        unsigned IEBA02 : 32; //!< [31:0] External Address of Frame 2 output (IPU) buffer 0 - Note that the 3 LSB are always 0 (aligned to 8 address) Used when transfering 3 frames (NF=1) only
    } B;
} hw_vdoa_vdoaieba02_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAIEBA02 register
 */
#define HW_VDOA_VDOAIEBA02_ADDR      (REGS_VDOA_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAIEBA02           (*(volatile hw_vdoa_vdoaieba02_t *) HW_VDOA_VDOAIEBA02_ADDR)
#define HW_VDOA_VDOAIEBA02_RD()      (HW_VDOA_VDOAIEBA02.U)
#define HW_VDOA_VDOAIEBA02_WR(v)     (HW_VDOA_VDOAIEBA02.U = (v))
#define HW_VDOA_VDOAIEBA02_SET(v)    (HW_VDOA_VDOAIEBA02_WR(HW_VDOA_VDOAIEBA02_RD() |  (v)))
#define HW_VDOA_VDOAIEBA02_CLR(v)    (HW_VDOA_VDOAIEBA02_WR(HW_VDOA_VDOAIEBA02_RD() & ~(v)))
#define HW_VDOA_VDOAIEBA02_TOG(v)    (HW_VDOA_VDOAIEBA02_WR(HW_VDOA_VDOAIEBA02_RD() ^  (v)))
#endif

/*
 * constants & macros for individual VDOA_VDOAIEBA02 bitfields
 */

/* --- Register HW_VDOA_VDOAIEBA02, field IEBA02[31:0] (RW)
 *
 * External Address of Frame 2 output (IPU) buffer 0 - Note that the 3 LSB are always 0 (aligned to
 * 8 address) Used when transfering 3 frames (NF=1) only
 */

#define BP_VDOA_VDOAIEBA02_IEBA02      (0)      //!< Bit position for VDOA_VDOAIEBA02_IEBA02.
#define BM_VDOA_VDOAIEBA02_IEBA02      (0xffffffff)  //!< Bit mask for VDOA_VDOAIEBA02_IEBA02.

//! @brief Get value of VDOA_VDOAIEBA02_IEBA02 from a register value.
#define BG_VDOA_VDOAIEBA02_IEBA02(r)   (((r) & BM_VDOA_VDOAIEBA02_IEBA02) >> BP_VDOA_VDOAIEBA02_IEBA02)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAIEBA02_IEBA02.
#define BF_VDOA_VDOAIEBA02_IEBA02(v)   ((((reg32_t) v) << BP_VDOA_VDOAIEBA02_IEBA02) & BM_VDOA_VDOAIEBA02_IEBA02)
#else
//! @brief Format value for bitfield VDOA_VDOAIEBA02_IEBA02.
#define BF_VDOA_VDOAIEBA02_IEBA02(v)   (((v) << BP_VDOA_VDOAIEBA02_IEBA02) & BM_VDOA_VDOAIEBA02_IEBA02)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IEBA02 field to a new value.
#define BW_VDOA_VDOAIEBA02_IEBA02(v)   (HW_VDOA_VDOAIEBA02_WR((HW_VDOA_VDOAIEBA02_RD() & ~BM_VDOA_VDOAIEBA02_IEBA02) | BF_VDOA_VDOAIEBA02_IEBA02(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VDOA_VDOAIEBA10 - VDOA IPU External Buffer 1 Frame 0 Address Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_vdoa_vdoaieba10
{
    reg32_t U;
    struct _hw_vdoa_vdoaieba10_bitfields
    {
        unsigned IEBA10 : 32; //!< [31:0] External Address of Frame 0 output (IPU) buffer 1 - Note that the 3 LSB are always 0 (aligned to 8 address) Used in sync mode (SYNC=1) only
    } B;
} hw_vdoa_vdoaieba10_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAIEBA10 register
 */
#define HW_VDOA_VDOAIEBA10_ADDR      (REGS_VDOA_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAIEBA10           (*(volatile hw_vdoa_vdoaieba10_t *) HW_VDOA_VDOAIEBA10_ADDR)
#define HW_VDOA_VDOAIEBA10_RD()      (HW_VDOA_VDOAIEBA10.U)
#define HW_VDOA_VDOAIEBA10_WR(v)     (HW_VDOA_VDOAIEBA10.U = (v))
#define HW_VDOA_VDOAIEBA10_SET(v)    (HW_VDOA_VDOAIEBA10_WR(HW_VDOA_VDOAIEBA10_RD() |  (v)))
#define HW_VDOA_VDOAIEBA10_CLR(v)    (HW_VDOA_VDOAIEBA10_WR(HW_VDOA_VDOAIEBA10_RD() & ~(v)))
#define HW_VDOA_VDOAIEBA10_TOG(v)    (HW_VDOA_VDOAIEBA10_WR(HW_VDOA_VDOAIEBA10_RD() ^  (v)))
#endif

/*
 * constants & macros for individual VDOA_VDOAIEBA10 bitfields
 */

/* --- Register HW_VDOA_VDOAIEBA10, field IEBA10[31:0] (RW)
 *
 * External Address of Frame 0 output (IPU) buffer 1 - Note that the 3 LSB are always 0 (aligned to
 * 8 address) Used in sync mode (SYNC=1) only
 */

#define BP_VDOA_VDOAIEBA10_IEBA10      (0)      //!< Bit position for VDOA_VDOAIEBA10_IEBA10.
#define BM_VDOA_VDOAIEBA10_IEBA10      (0xffffffff)  //!< Bit mask for VDOA_VDOAIEBA10_IEBA10.

//! @brief Get value of VDOA_VDOAIEBA10_IEBA10 from a register value.
#define BG_VDOA_VDOAIEBA10_IEBA10(r)   (((r) & BM_VDOA_VDOAIEBA10_IEBA10) >> BP_VDOA_VDOAIEBA10_IEBA10)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAIEBA10_IEBA10.
#define BF_VDOA_VDOAIEBA10_IEBA10(v)   ((((reg32_t) v) << BP_VDOA_VDOAIEBA10_IEBA10) & BM_VDOA_VDOAIEBA10_IEBA10)
#else
//! @brief Format value for bitfield VDOA_VDOAIEBA10_IEBA10.
#define BF_VDOA_VDOAIEBA10_IEBA10(v)   (((v) << BP_VDOA_VDOAIEBA10_IEBA10) & BM_VDOA_VDOAIEBA10_IEBA10)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IEBA10 field to a new value.
#define BW_VDOA_VDOAIEBA10_IEBA10(v)   (HW_VDOA_VDOAIEBA10_WR((HW_VDOA_VDOAIEBA10_RD() & ~BM_VDOA_VDOAIEBA10_IEBA10) | BF_VDOA_VDOAIEBA10_IEBA10(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VDOA_VDOAIEBA11 - VDOA IPU External Buffer 1 Frame 1 Address Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_vdoa_vdoaieba11
{
    reg32_t U;
    struct _hw_vdoa_vdoaieba11_bitfields
    {
        unsigned IEBA11 : 32; //!< [31:0] External Address of Frame 1 output (IPU) buffer 1 - Note that the 3 LSB are always 0 (aligned to 8 address) This register is used only in sync mode (SYNC=1), 3 frames transfer (NF=1)
    } B;
} hw_vdoa_vdoaieba11_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAIEBA11 register
 */
#define HW_VDOA_VDOAIEBA11_ADDR      (REGS_VDOA_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAIEBA11           (*(volatile hw_vdoa_vdoaieba11_t *) HW_VDOA_VDOAIEBA11_ADDR)
#define HW_VDOA_VDOAIEBA11_RD()      (HW_VDOA_VDOAIEBA11.U)
#define HW_VDOA_VDOAIEBA11_WR(v)     (HW_VDOA_VDOAIEBA11.U = (v))
#define HW_VDOA_VDOAIEBA11_SET(v)    (HW_VDOA_VDOAIEBA11_WR(HW_VDOA_VDOAIEBA11_RD() |  (v)))
#define HW_VDOA_VDOAIEBA11_CLR(v)    (HW_VDOA_VDOAIEBA11_WR(HW_VDOA_VDOAIEBA11_RD() & ~(v)))
#define HW_VDOA_VDOAIEBA11_TOG(v)    (HW_VDOA_VDOAIEBA11_WR(HW_VDOA_VDOAIEBA11_RD() ^  (v)))
#endif

/*
 * constants & macros for individual VDOA_VDOAIEBA11 bitfields
 */

/* --- Register HW_VDOA_VDOAIEBA11, field IEBA11[31:0] (RW)
 *
 * External Address of Frame 1 output (IPU) buffer 1 - Note that the 3 LSB are always 0 (aligned to
 * 8 address) This register is used only in sync mode (SYNC=1), 3 frames transfer (NF=1)
 */

#define BP_VDOA_VDOAIEBA11_IEBA11      (0)      //!< Bit position for VDOA_VDOAIEBA11_IEBA11.
#define BM_VDOA_VDOAIEBA11_IEBA11      (0xffffffff)  //!< Bit mask for VDOA_VDOAIEBA11_IEBA11.

//! @brief Get value of VDOA_VDOAIEBA11_IEBA11 from a register value.
#define BG_VDOA_VDOAIEBA11_IEBA11(r)   (((r) & BM_VDOA_VDOAIEBA11_IEBA11) >> BP_VDOA_VDOAIEBA11_IEBA11)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAIEBA11_IEBA11.
#define BF_VDOA_VDOAIEBA11_IEBA11(v)   ((((reg32_t) v) << BP_VDOA_VDOAIEBA11_IEBA11) & BM_VDOA_VDOAIEBA11_IEBA11)
#else
//! @brief Format value for bitfield VDOA_VDOAIEBA11_IEBA11.
#define BF_VDOA_VDOAIEBA11_IEBA11(v)   (((v) << BP_VDOA_VDOAIEBA11_IEBA11) & BM_VDOA_VDOAIEBA11_IEBA11)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IEBA11 field to a new value.
#define BW_VDOA_VDOAIEBA11_IEBA11(v)   (HW_VDOA_VDOAIEBA11_WR((HW_VDOA_VDOAIEBA11_RD() & ~BM_VDOA_VDOAIEBA11_IEBA11) | BF_VDOA_VDOAIEBA11_IEBA11(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VDOA_VDOAIEBA12 - VDOA IPU External Buffer 1 Frame 2 Address Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_vdoa_vdoaieba12
{
    reg32_t U;
    struct _hw_vdoa_vdoaieba12_bitfields
    {
        unsigned IEBA12 : 32; //!< [31:0] External Address of Frame 2 output (IPU) buffer 1 - Note that the 3 LSB are always 0 (aligned to 8 address) This register is used only in sync mode (SYNC=1), 3 frames transfer (NF=1)
    } B;
} hw_vdoa_vdoaieba12_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAIEBA12 register
 */
#define HW_VDOA_VDOAIEBA12_ADDR      (REGS_VDOA_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAIEBA12           (*(volatile hw_vdoa_vdoaieba12_t *) HW_VDOA_VDOAIEBA12_ADDR)
#define HW_VDOA_VDOAIEBA12_RD()      (HW_VDOA_VDOAIEBA12.U)
#define HW_VDOA_VDOAIEBA12_WR(v)     (HW_VDOA_VDOAIEBA12.U = (v))
#define HW_VDOA_VDOAIEBA12_SET(v)    (HW_VDOA_VDOAIEBA12_WR(HW_VDOA_VDOAIEBA12_RD() |  (v)))
#define HW_VDOA_VDOAIEBA12_CLR(v)    (HW_VDOA_VDOAIEBA12_WR(HW_VDOA_VDOAIEBA12_RD() & ~(v)))
#define HW_VDOA_VDOAIEBA12_TOG(v)    (HW_VDOA_VDOAIEBA12_WR(HW_VDOA_VDOAIEBA12_RD() ^  (v)))
#endif

/*
 * constants & macros for individual VDOA_VDOAIEBA12 bitfields
 */

/* --- Register HW_VDOA_VDOAIEBA12, field IEBA12[31:0] (RW)
 *
 * External Address of Frame 2 output (IPU) buffer 1 - Note that the 3 LSB are always 0 (aligned to
 * 8 address) This register is used only in sync mode (SYNC=1), 3 frames transfer (NF=1)
 */

#define BP_VDOA_VDOAIEBA12_IEBA12      (0)      //!< Bit position for VDOA_VDOAIEBA12_IEBA12.
#define BM_VDOA_VDOAIEBA12_IEBA12      (0xffffffff)  //!< Bit mask for VDOA_VDOAIEBA12_IEBA12.

//! @brief Get value of VDOA_VDOAIEBA12_IEBA12 from a register value.
#define BG_VDOA_VDOAIEBA12_IEBA12(r)   (((r) & BM_VDOA_VDOAIEBA12_IEBA12) >> BP_VDOA_VDOAIEBA12_IEBA12)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAIEBA12_IEBA12.
#define BF_VDOA_VDOAIEBA12_IEBA12(v)   ((((reg32_t) v) << BP_VDOA_VDOAIEBA12_IEBA12) & BM_VDOA_VDOAIEBA12_IEBA12)
#else
//! @brief Format value for bitfield VDOA_VDOAIEBA12_IEBA12.
#define BF_VDOA_VDOAIEBA12_IEBA12(v)   (((v) << BP_VDOA_VDOAIEBA12_IEBA12) & BM_VDOA_VDOAIEBA12_IEBA12)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IEBA12 field to a new value.
#define BW_VDOA_VDOAIEBA12_IEBA12(v)   (HW_VDOA_VDOAIEBA12_WR((HW_VDOA_VDOAIEBA12_RD() & ~BM_VDOA_VDOAIEBA12_IEBA12) | BF_VDOA_VDOAIEBA12_IEBA12(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VDOA_VDOASL - VDOA IPU Stride Line Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_vdoa_vdoasl
{
    reg32_t U;
    struct _hw_vdoa_vdoasl_bitfields
    {
        unsigned ISLY : 15; //!< [14:0] IPU Stride Line - Address vertical scaling factor in bytes for memory access. Also number of maximum bytes in the "Y" component row according to memory limitations. - Note for 4:2:2 format ISLY will be doubled since each pixel takes two bytes
        unsigned RESERVED0 : 1; //!< [15] Reserved
        unsigned VSLY : 14; //!< [29:16] VPU Stride Line - Address vertical scaling factor in bytes for memory access. Also number of maximum bytes in the "Y" component row according to memory limitations.
        unsigned RESERVED1 : 2; //!< [31:30] Reserved
    } B;
} hw_vdoa_vdoasl_t;
#endif

/*
 * constants & macros for entire VDOA_VDOASL register
 */
#define HW_VDOA_VDOASL_ADDR      (REGS_VDOA_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOASL           (*(volatile hw_vdoa_vdoasl_t *) HW_VDOA_VDOASL_ADDR)
#define HW_VDOA_VDOASL_RD()      (HW_VDOA_VDOASL.U)
#define HW_VDOA_VDOASL_WR(v)     (HW_VDOA_VDOASL.U = (v))
#define HW_VDOA_VDOASL_SET(v)    (HW_VDOA_VDOASL_WR(HW_VDOA_VDOASL_RD() |  (v)))
#define HW_VDOA_VDOASL_CLR(v)    (HW_VDOA_VDOASL_WR(HW_VDOA_VDOASL_RD() & ~(v)))
#define HW_VDOA_VDOASL_TOG(v)    (HW_VDOA_VDOASL_WR(HW_VDOA_VDOASL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual VDOA_VDOASL bitfields
 */

/* --- Register HW_VDOA_VDOASL, field ISLY[14:0] (RW)
 *
 * IPU Stride Line - Address vertical scaling factor in bytes for memory access. Also number of
 * maximum bytes in the "Y" component row according to memory limitations. - Note for 4:2:2 format
 * ISLY will be doubled since each pixel takes two bytes
 */

#define BP_VDOA_VDOASL_ISLY      (0)      //!< Bit position for VDOA_VDOASL_ISLY.
#define BM_VDOA_VDOASL_ISLY      (0x00007fff)  //!< Bit mask for VDOA_VDOASL_ISLY.

//! @brief Get value of VDOA_VDOASL_ISLY from a register value.
#define BG_VDOA_VDOASL_ISLY(r)   (((r) & BM_VDOA_VDOASL_ISLY) >> BP_VDOA_VDOASL_ISLY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOASL_ISLY.
#define BF_VDOA_VDOASL_ISLY(v)   ((((reg32_t) v) << BP_VDOA_VDOASL_ISLY) & BM_VDOA_VDOASL_ISLY)
#else
//! @brief Format value for bitfield VDOA_VDOASL_ISLY.
#define BF_VDOA_VDOASL_ISLY(v)   (((v) << BP_VDOA_VDOASL_ISLY) & BM_VDOA_VDOASL_ISLY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ISLY field to a new value.
#define BW_VDOA_VDOASL_ISLY(v)   (HW_VDOA_VDOASL_WR((HW_VDOA_VDOASL_RD() & ~BM_VDOA_VDOASL_ISLY) | BF_VDOA_VDOASL_ISLY(v)))
#endif

/* --- Register HW_VDOA_VDOASL, field VSLY[29:16] (RW)
 *
 * VPU Stride Line - Address vertical scaling factor in bytes for memory access. Also number of
 * maximum bytes in the "Y" component row according to memory limitations.
 */

#define BP_VDOA_VDOASL_VSLY      (16)      //!< Bit position for VDOA_VDOASL_VSLY.
#define BM_VDOA_VDOASL_VSLY      (0x3fff0000)  //!< Bit mask for VDOA_VDOASL_VSLY.

//! @brief Get value of VDOA_VDOASL_VSLY from a register value.
#define BG_VDOA_VDOASL_VSLY(r)   (((r) & BM_VDOA_VDOASL_VSLY) >> BP_VDOA_VDOASL_VSLY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOASL_VSLY.
#define BF_VDOA_VDOASL_VSLY(v)   ((((reg32_t) v) << BP_VDOA_VDOASL_VSLY) & BM_VDOA_VDOASL_VSLY)
#else
//! @brief Format value for bitfield VDOA_VDOASL_VSLY.
#define BF_VDOA_VDOASL_VSLY(v)   (((v) << BP_VDOA_VDOASL_VSLY) & BM_VDOA_VDOASL_VSLY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VSLY field to a new value.
#define BW_VDOA_VDOASL_VSLY(v)   (HW_VDOA_VDOASL_WR((HW_VDOA_VDOASL_RD() & ~BM_VDOA_VDOASL_VSLY) | BF_VDOA_VDOASL_VSLY(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VDOA_VDOAIUBO - VDOA IPU U (Chroma) Buffer Offset Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_vdoa_vdoaiubo
{
    reg32_t U;
    struct _hw_vdoa_vdoaiubo_bitfields
    {
        unsigned IUBO : 27; //!< [26:0] The offset of Chroma (UV) Buffer for all IPU output frames i.e Buffer Chroma address will be VDOAIEBAnm+VDOAIUBO - Note that the 3 LSB are always 0 (aligned to 8 address) used only for PFL = 4:2:0
        unsigned RESERVED0 : 5; //!< [31:27] Reserved
    } B;
} hw_vdoa_vdoaiubo_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAIUBO register
 */
#define HW_VDOA_VDOAIUBO_ADDR      (REGS_VDOA_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAIUBO           (*(volatile hw_vdoa_vdoaiubo_t *) HW_VDOA_VDOAIUBO_ADDR)
#define HW_VDOA_VDOAIUBO_RD()      (HW_VDOA_VDOAIUBO.U)
#define HW_VDOA_VDOAIUBO_WR(v)     (HW_VDOA_VDOAIUBO.U = (v))
#define HW_VDOA_VDOAIUBO_SET(v)    (HW_VDOA_VDOAIUBO_WR(HW_VDOA_VDOAIUBO_RD() |  (v)))
#define HW_VDOA_VDOAIUBO_CLR(v)    (HW_VDOA_VDOAIUBO_WR(HW_VDOA_VDOAIUBO_RD() & ~(v)))
#define HW_VDOA_VDOAIUBO_TOG(v)    (HW_VDOA_VDOAIUBO_WR(HW_VDOA_VDOAIUBO_RD() ^  (v)))
#endif

/*
 * constants & macros for individual VDOA_VDOAIUBO bitfields
 */

/* --- Register HW_VDOA_VDOAIUBO, field IUBO[26:0] (RW)
 *
 * The offset of Chroma (UV) Buffer for all IPU output frames i.e Buffer Chroma address will be
 * VDOAIEBAnm+VDOAIUBO - Note that the 3 LSB are always 0 (aligned to 8 address) used only for PFL =
 * 4:2:0
 */

#define BP_VDOA_VDOAIUBO_IUBO      (0)      //!< Bit position for VDOA_VDOAIUBO_IUBO.
#define BM_VDOA_VDOAIUBO_IUBO      (0x07ffffff)  //!< Bit mask for VDOA_VDOAIUBO_IUBO.

//! @brief Get value of VDOA_VDOAIUBO_IUBO from a register value.
#define BG_VDOA_VDOAIUBO_IUBO(r)   (((r) & BM_VDOA_VDOAIUBO_IUBO) >> BP_VDOA_VDOAIUBO_IUBO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAIUBO_IUBO.
#define BF_VDOA_VDOAIUBO_IUBO(v)   ((((reg32_t) v) << BP_VDOA_VDOAIUBO_IUBO) & BM_VDOA_VDOAIUBO_IUBO)
#else
//! @brief Format value for bitfield VDOA_VDOAIUBO_IUBO.
#define BF_VDOA_VDOAIUBO_IUBO(v)   (((v) << BP_VDOA_VDOAIUBO_IUBO) & BM_VDOA_VDOAIUBO_IUBO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IUBO field to a new value.
#define BW_VDOA_VDOAIUBO_IUBO(v)   (HW_VDOA_VDOAIUBO_WR((HW_VDOA_VDOAIUBO_RD() & ~BM_VDOA_VDOAIUBO_IUBO) | BF_VDOA_VDOAIUBO_IUBO(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VDOA_VDOAVEBA0 - VDOA VPU External Buffer 0 Address Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_vdoa_vdoaveba0
{
    reg32_t U;
    struct _hw_vdoa_vdoaveba0_bitfields
    {
        unsigned VEBA0 : 32; //!< [31:0] Address of Frame 0 VPU buffers - Note that the 3 LSB are always 0 (aligned to 8 address) Used for all transfers
    } B;
} hw_vdoa_vdoaveba0_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAVEBA0 register
 */
#define HW_VDOA_VDOAVEBA0_ADDR      (REGS_VDOA_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAVEBA0           (*(volatile hw_vdoa_vdoaveba0_t *) HW_VDOA_VDOAVEBA0_ADDR)
#define HW_VDOA_VDOAVEBA0_RD()      (HW_VDOA_VDOAVEBA0.U)
#define HW_VDOA_VDOAVEBA0_WR(v)     (HW_VDOA_VDOAVEBA0.U = (v))
#define HW_VDOA_VDOAVEBA0_SET(v)    (HW_VDOA_VDOAVEBA0_WR(HW_VDOA_VDOAVEBA0_RD() |  (v)))
#define HW_VDOA_VDOAVEBA0_CLR(v)    (HW_VDOA_VDOAVEBA0_WR(HW_VDOA_VDOAVEBA0_RD() & ~(v)))
#define HW_VDOA_VDOAVEBA0_TOG(v)    (HW_VDOA_VDOAVEBA0_WR(HW_VDOA_VDOAVEBA0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual VDOA_VDOAVEBA0 bitfields
 */

/* --- Register HW_VDOA_VDOAVEBA0, field VEBA0[31:0] (RW)
 *
 * Address of Frame 0 VPU buffers - Note that the 3 LSB are always 0 (aligned to 8 address) Used for
 * all transfers
 */

#define BP_VDOA_VDOAVEBA0_VEBA0      (0)      //!< Bit position for VDOA_VDOAVEBA0_VEBA0.
#define BM_VDOA_VDOAVEBA0_VEBA0      (0xffffffff)  //!< Bit mask for VDOA_VDOAVEBA0_VEBA0.

//! @brief Get value of VDOA_VDOAVEBA0_VEBA0 from a register value.
#define BG_VDOA_VDOAVEBA0_VEBA0(r)   (((r) & BM_VDOA_VDOAVEBA0_VEBA0) >> BP_VDOA_VDOAVEBA0_VEBA0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAVEBA0_VEBA0.
#define BF_VDOA_VDOAVEBA0_VEBA0(v)   ((((reg32_t) v) << BP_VDOA_VDOAVEBA0_VEBA0) & BM_VDOA_VDOAVEBA0_VEBA0)
#else
//! @brief Format value for bitfield VDOA_VDOAVEBA0_VEBA0.
#define BF_VDOA_VDOAVEBA0_VEBA0(v)   (((v) << BP_VDOA_VDOAVEBA0_VEBA0) & BM_VDOA_VDOAVEBA0_VEBA0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VEBA0 field to a new value.
#define BW_VDOA_VDOAVEBA0_VEBA0(v)   (HW_VDOA_VDOAVEBA0_WR((HW_VDOA_VDOAVEBA0_RD() & ~BM_VDOA_VDOAVEBA0_VEBA0) | BF_VDOA_VDOAVEBA0_VEBA0(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VDOA_VDOAVEBA1 - VDOA VPU External Buffer 1 Address Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_vdoa_vdoaveba1
{
    reg32_t U;
    struct _hw_vdoa_vdoaveba1_bitfields
    {
        unsigned VEBA1 : 32; //!< [31:0] Address of Frame 1 VPU buffers - Note that the 3 LSB are always 0 (aligned to 8 address) Used when transfering three frame (NF=1) only
    } B;
} hw_vdoa_vdoaveba1_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAVEBA1 register
 */
#define HW_VDOA_VDOAVEBA1_ADDR      (REGS_VDOA_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAVEBA1           (*(volatile hw_vdoa_vdoaveba1_t *) HW_VDOA_VDOAVEBA1_ADDR)
#define HW_VDOA_VDOAVEBA1_RD()      (HW_VDOA_VDOAVEBA1.U)
#define HW_VDOA_VDOAVEBA1_WR(v)     (HW_VDOA_VDOAVEBA1.U = (v))
#define HW_VDOA_VDOAVEBA1_SET(v)    (HW_VDOA_VDOAVEBA1_WR(HW_VDOA_VDOAVEBA1_RD() |  (v)))
#define HW_VDOA_VDOAVEBA1_CLR(v)    (HW_VDOA_VDOAVEBA1_WR(HW_VDOA_VDOAVEBA1_RD() & ~(v)))
#define HW_VDOA_VDOAVEBA1_TOG(v)    (HW_VDOA_VDOAVEBA1_WR(HW_VDOA_VDOAVEBA1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual VDOA_VDOAVEBA1 bitfields
 */

/* --- Register HW_VDOA_VDOAVEBA1, field VEBA1[31:0] (RW)
 *
 * Address of Frame 1 VPU buffers - Note that the 3 LSB are always 0 (aligned to 8 address) Used
 * when transfering three frame (NF=1) only
 */

#define BP_VDOA_VDOAVEBA1_VEBA1      (0)      //!< Bit position for VDOA_VDOAVEBA1_VEBA1.
#define BM_VDOA_VDOAVEBA1_VEBA1      (0xffffffff)  //!< Bit mask for VDOA_VDOAVEBA1_VEBA1.

//! @brief Get value of VDOA_VDOAVEBA1_VEBA1 from a register value.
#define BG_VDOA_VDOAVEBA1_VEBA1(r)   (((r) & BM_VDOA_VDOAVEBA1_VEBA1) >> BP_VDOA_VDOAVEBA1_VEBA1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAVEBA1_VEBA1.
#define BF_VDOA_VDOAVEBA1_VEBA1(v)   ((((reg32_t) v) << BP_VDOA_VDOAVEBA1_VEBA1) & BM_VDOA_VDOAVEBA1_VEBA1)
#else
//! @brief Format value for bitfield VDOA_VDOAVEBA1_VEBA1.
#define BF_VDOA_VDOAVEBA1_VEBA1(v)   (((v) << BP_VDOA_VDOAVEBA1_VEBA1) & BM_VDOA_VDOAVEBA1_VEBA1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VEBA1 field to a new value.
#define BW_VDOA_VDOAVEBA1_VEBA1(v)   (HW_VDOA_VDOAVEBA1_WR((HW_VDOA_VDOAVEBA1_RD() & ~BM_VDOA_VDOAVEBA1_VEBA1) | BF_VDOA_VDOAVEBA1_VEBA1(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VDOA_VDOAVEBA2 - VDOA VPU External Buffer 2 Address Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_vdoa_vdoaveba2
{
    reg32_t U;
    struct _hw_vdoa_vdoaveba2_bitfields
    {
        unsigned VEBA2 : 32; //!< [31:0] Address of Frame 2 VPU buffers - Note that the 3 LSB are always 0 (aligned to 8 address) Used when transfering three frame (NF=1) only
    } B;
} hw_vdoa_vdoaveba2_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAVEBA2 register
 */
#define HW_VDOA_VDOAVEBA2_ADDR      (REGS_VDOA_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAVEBA2           (*(volatile hw_vdoa_vdoaveba2_t *) HW_VDOA_VDOAVEBA2_ADDR)
#define HW_VDOA_VDOAVEBA2_RD()      (HW_VDOA_VDOAVEBA2.U)
#define HW_VDOA_VDOAVEBA2_WR(v)     (HW_VDOA_VDOAVEBA2.U = (v))
#define HW_VDOA_VDOAVEBA2_SET(v)    (HW_VDOA_VDOAVEBA2_WR(HW_VDOA_VDOAVEBA2_RD() |  (v)))
#define HW_VDOA_VDOAVEBA2_CLR(v)    (HW_VDOA_VDOAVEBA2_WR(HW_VDOA_VDOAVEBA2_RD() & ~(v)))
#define HW_VDOA_VDOAVEBA2_TOG(v)    (HW_VDOA_VDOAVEBA2_WR(HW_VDOA_VDOAVEBA2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual VDOA_VDOAVEBA2 bitfields
 */

/* --- Register HW_VDOA_VDOAVEBA2, field VEBA2[31:0] (RW)
 *
 * Address of Frame 2 VPU buffers - Note that the 3 LSB are always 0 (aligned to 8 address) Used
 * when transfering three frame (NF=1) only
 */

#define BP_VDOA_VDOAVEBA2_VEBA2      (0)      //!< Bit position for VDOA_VDOAVEBA2_VEBA2.
#define BM_VDOA_VDOAVEBA2_VEBA2      (0xffffffff)  //!< Bit mask for VDOA_VDOAVEBA2_VEBA2.

//! @brief Get value of VDOA_VDOAVEBA2_VEBA2 from a register value.
#define BG_VDOA_VDOAVEBA2_VEBA2(r)   (((r) & BM_VDOA_VDOAVEBA2_VEBA2) >> BP_VDOA_VDOAVEBA2_VEBA2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAVEBA2_VEBA2.
#define BF_VDOA_VDOAVEBA2_VEBA2(v)   ((((reg32_t) v) << BP_VDOA_VDOAVEBA2_VEBA2) & BM_VDOA_VDOAVEBA2_VEBA2)
#else
//! @brief Format value for bitfield VDOA_VDOAVEBA2_VEBA2.
#define BF_VDOA_VDOAVEBA2_VEBA2(v)   (((v) << BP_VDOA_VDOAVEBA2_VEBA2) & BM_VDOA_VDOAVEBA2_VEBA2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VEBA2 field to a new value.
#define BW_VDOA_VDOAVEBA2_VEBA2(v)   (HW_VDOA_VDOAVEBA2_WR((HW_VDOA_VDOAVEBA2_RD() & ~BM_VDOA_VDOAVEBA2_VEBA2) | BF_VDOA_VDOAVEBA2_VEBA2(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VDOA_VDOAVUBO - VDOA VPU U (Chroma) Buffer Offset Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_vdoa_vdoavubo
{
    reg32_t U;
    struct _hw_vdoa_vdoavubo_bitfields
    {
        unsigned VUBO : 27; //!< [26:0] The offset of Chroma (UV) Buffer for all VPU input frames i.e Chroma Buffer address will be VDOAVEBAm+VDOAVUBO - Note that the 3 LSB are always 0 (aligned to 8 address)
        unsigned RESERVED0 : 5; //!< [31:27] Reserved
    } B;
} hw_vdoa_vdoavubo_t;
#endif

/*
 * constants & macros for entire VDOA_VDOAVUBO register
 */
#define HW_VDOA_VDOAVUBO_ADDR      (REGS_VDOA_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOAVUBO           (*(volatile hw_vdoa_vdoavubo_t *) HW_VDOA_VDOAVUBO_ADDR)
#define HW_VDOA_VDOAVUBO_RD()      (HW_VDOA_VDOAVUBO.U)
#define HW_VDOA_VDOAVUBO_WR(v)     (HW_VDOA_VDOAVUBO.U = (v))
#define HW_VDOA_VDOAVUBO_SET(v)    (HW_VDOA_VDOAVUBO_WR(HW_VDOA_VDOAVUBO_RD() |  (v)))
#define HW_VDOA_VDOAVUBO_CLR(v)    (HW_VDOA_VDOAVUBO_WR(HW_VDOA_VDOAVUBO_RD() & ~(v)))
#define HW_VDOA_VDOAVUBO_TOG(v)    (HW_VDOA_VDOAVUBO_WR(HW_VDOA_VDOAVUBO_RD() ^  (v)))
#endif

/*
 * constants & macros for individual VDOA_VDOAVUBO bitfields
 */

/* --- Register HW_VDOA_VDOAVUBO, field VUBO[26:0] (RW)
 *
 * The offset of Chroma (UV) Buffer for all VPU input frames i.e Chroma Buffer address will be
 * VDOAVEBAm+VDOAVUBO - Note that the 3 LSB are always 0 (aligned to 8 address)
 */

#define BP_VDOA_VDOAVUBO_VUBO      (0)      //!< Bit position for VDOA_VDOAVUBO_VUBO.
#define BM_VDOA_VDOAVUBO_VUBO      (0x07ffffff)  //!< Bit mask for VDOA_VDOAVUBO_VUBO.

//! @brief Get value of VDOA_VDOAVUBO_VUBO from a register value.
#define BG_VDOA_VDOAVUBO_VUBO(r)   (((r) & BM_VDOA_VDOAVUBO_VUBO) >> BP_VDOA_VDOAVUBO_VUBO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield VDOA_VDOAVUBO_VUBO.
#define BF_VDOA_VDOAVUBO_VUBO(v)   ((((reg32_t) v) << BP_VDOA_VDOAVUBO_VUBO) & BM_VDOA_VDOAVUBO_VUBO)
#else
//! @brief Format value for bitfield VDOA_VDOAVUBO_VUBO.
#define BF_VDOA_VDOAVUBO_VUBO(v)   (((v) << BP_VDOA_VDOAVUBO_VUBO) & BM_VDOA_VDOAVUBO_VUBO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VUBO field to a new value.
#define BW_VDOA_VDOAVUBO_VUBO(v)   (HW_VDOA_VDOAVUBO_WR((HW_VDOA_VDOAVUBO_RD() & ~BM_VDOA_VDOAVUBO_VUBO) | BF_VDOA_VDOAVUBO_VUBO(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VDOA_VDOASR - VDOA Status Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_vdoa_vdoasr
{
    reg32_t U;
    struct _hw_vdoa_vdoasr_bitfields
    {
        unsigned CURRENT_BUFFER : 1; //!< [0] Current Buffer - for Double buffer shows the number of buffer currently transferred
        unsigned CURRENT_FRAME : 2; //!< [2:1] Current Frame - When working on 3 frames the number of frame currently transferred
        unsigned EOB : 1; //!< [3] End of Band- Indicates that the VDOA has finished transferring a band in SYNC mode and is waiting to IPU to continue
        unsigned ERRW : 1; //!< [4] Error Write - Indicates that the last access that failed was a read or a write.This field is valid only when TERR bit is set in VDOA Interrupt Status Register - VDOAIST
        unsigned RESERVED0 : 27; //!< [31:5] Reserved
    } B;
} hw_vdoa_vdoasr_t;
#endif

/*
 * constants & macros for entire VDOA_VDOASR register
 */
#define HW_VDOA_VDOASR_ADDR      (REGS_VDOA_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_VDOA_VDOASR           (*(volatile hw_vdoa_vdoasr_t *) HW_VDOA_VDOASR_ADDR)
#define HW_VDOA_VDOASR_RD()      (HW_VDOA_VDOASR.U)
#endif

/*
 * constants & macros for individual VDOA_VDOASR bitfields
 */

/* --- Register HW_VDOA_VDOASR, field CURRENT_BUFFER[0] (RO)
 *
 * Current Buffer - for Double buffer shows the number of buffer currently transferred
 */

#define BP_VDOA_VDOASR_CURRENT_BUFFER      (0)      //!< Bit position for VDOA_VDOASR_CURRENT_BUFFER.
#define BM_VDOA_VDOASR_CURRENT_BUFFER      (0x00000001)  //!< Bit mask for VDOA_VDOASR_CURRENT_BUFFER.

//! @brief Get value of VDOA_VDOASR_CURRENT_BUFFER from a register value.
#define BG_VDOA_VDOASR_CURRENT_BUFFER(r)   (((r) & BM_VDOA_VDOASR_CURRENT_BUFFER) >> BP_VDOA_VDOASR_CURRENT_BUFFER)

/* --- Register HW_VDOA_VDOASR, field CURRENT_FRAME[2:1] (RO)
 *
 * Current Frame - When working on 3 frames the number of frame currently transferred
 */

#define BP_VDOA_VDOASR_CURRENT_FRAME      (1)      //!< Bit position for VDOA_VDOASR_CURRENT_FRAME.
#define BM_VDOA_VDOASR_CURRENT_FRAME      (0x00000006)  //!< Bit mask for VDOA_VDOASR_CURRENT_FRAME.

//! @brief Get value of VDOA_VDOASR_CURRENT_FRAME from a register value.
#define BG_VDOA_VDOASR_CURRENT_FRAME(r)   (((r) & BM_VDOA_VDOASR_CURRENT_FRAME) >> BP_VDOA_VDOASR_CURRENT_FRAME)

/* --- Register HW_VDOA_VDOASR, field EOB[3] (RO)
 *
 * End of Band- Indicates that the VDOA has finished transferring a band in SYNC mode and is waiting
 * to IPU to continue
 */

#define BP_VDOA_VDOASR_EOB      (3)      //!< Bit position for VDOA_VDOASR_EOB.
#define BM_VDOA_VDOASR_EOB      (0x00000008)  //!< Bit mask for VDOA_VDOASR_EOB.

//! @brief Get value of VDOA_VDOASR_EOB from a register value.
#define BG_VDOA_VDOASR_EOB(r)   (((r) & BM_VDOA_VDOASR_EOB) >> BP_VDOA_VDOASR_EOB)

/* --- Register HW_VDOA_VDOASR, field ERRW[4] (RO)
 *
 * Error Write - Indicates that the last access that failed was a read or a write.This field is
 * valid only when TERR bit is set in VDOA Interrupt Status Register - VDOAIST
 *
 * Values:
 * READ_ERROR = 0 - Read Error
 * WRITE_ERROR = 1 - Write Error
 */

#define BP_VDOA_VDOASR_ERRW      (4)      //!< Bit position for VDOA_VDOASR_ERRW.
#define BM_VDOA_VDOASR_ERRW      (0x00000010)  //!< Bit mask for VDOA_VDOASR_ERRW.

//! @brief Get value of VDOA_VDOASR_ERRW from a register value.
#define BG_VDOA_VDOASR_ERRW(r)   (((r) & BM_VDOA_VDOASR_ERRW) >> BP_VDOA_VDOASR_ERRW)

#define BV_VDOA_VDOASR_ERRW__READ_ERROR (0x0) //!< Read Error
#define BV_VDOA_VDOASR_ERRW__WRITE_ERROR (0x1) //!< Write Error


/*!
 * @brief All VDOA module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_vdoa
{
    volatile hw_vdoa_vdoac_t VDOAC; //!< VDOA Control Register
    volatile hw_vdoa_vdoasrr_t VDOASRR; //!< VDOA Start and Reset
    volatile hw_vdoa_vdoaie_t VDOAIE; //!< VDOA Interrupt Enable Register
    volatile hw_vdoa_vdoaist_t VDOAIST; //!< VDOA Interrupt Status Register
    volatile hw_vdoa_vdoafp_t VDOAFP; //!< VDOA Frame Parameters Register
    volatile hw_vdoa_vdoaieba00_t VDOAIEBA00; //!< VDOA IPU External Buffer 0 Frame 0 Address Register
    volatile hw_vdoa_vdoaieba01_t VDOAIEBA01; //!< VDOA IPU External Buffer 0 Frame 1 Address Register
    volatile hw_vdoa_vdoaieba02_t VDOAIEBA02; //!< VDOA IPU External Buffer 0 Frame 2 Address Register
    volatile hw_vdoa_vdoaieba10_t VDOAIEBA10; //!< VDOA IPU External Buffer 1 Frame 0 Address Register
    volatile hw_vdoa_vdoaieba11_t VDOAIEBA11; //!< VDOA IPU External Buffer 1 Frame 1 Address Register
    volatile hw_vdoa_vdoaieba12_t VDOAIEBA12; //!< VDOA IPU External Buffer 1 Frame 2 Address Register
    volatile hw_vdoa_vdoasl_t VDOASL; //!< VDOA IPU Stride Line Register
    volatile hw_vdoa_vdoaiubo_t VDOAIUBO; //!< VDOA IPU U (Chroma) Buffer Offset Register
    volatile hw_vdoa_vdoaveba0_t VDOAVEBA0; //!< VDOA VPU External Buffer 0 Address Register
    volatile hw_vdoa_vdoaveba1_t VDOAVEBA1; //!< VDOA VPU External Buffer 1 Address Register
    volatile hw_vdoa_vdoaveba2_t VDOAVEBA2; //!< VDOA VPU External Buffer 2 Address Register
    volatile hw_vdoa_vdoavubo_t VDOAVUBO; //!< VDOA VPU U (Chroma) Buffer Offset Register
    volatile hw_vdoa_vdoasr_t VDOASR; //!< VDOA Status Register
} hw_vdoa_t;
#pragma pack()
#endif

//! @brief Macro to access all VDOA registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_VDOA(0)</code>.
#define HW_VDOA     (*(volatile hw_vdoa_t *) REGS_VDOA_BASE)


#endif // _VDOA_H
