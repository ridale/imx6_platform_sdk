/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef _EPDC_REGS_H_
#define _EPDC_REGS_H_

#include <hardware.h>           // Hardware definitions

#if !defined(EPDC_BASE_ADDR)
#if defiend(CHIP_MX6SDL) || defiend(CHIP_MX6SL)
#define EPDC_BASE_ADDR 0x020F4000
#else
#error	EPDC is not supported on the platform!!!
#endif 
#endif

//*************************************
// Register addresses
//*************************************

#define EPDC_CTRL			(EPDC_BASE_ADDR + 0x000)
#define EPDC_CTRL_SET			(EPDC_BASE_ADDR + 0x004)
#define EPDC_CTRL_CLEAR			(EPDC_BASE_ADDR + 0x008)
#define EPDC_CTRL_TOGGLE		(EPDC_BASE_ADDR + 0x00C)
#define EPDC_WV_ADDR			(EPDC_BASE_ADDR + 0x020)
#define EPDC_WB_ADDR			(EPDC_BASE_ADDR + 0x030)
#define EPDC_RES			(EPDC_BASE_ADDR + 0x040)
#define EPDC_FORMAT			(EPDC_BASE_ADDR + 0x050)
#define EPDC_FORMAT_SET			(EPDC_BASE_ADDR + 0x054)
#define EPDC_FORMAT_CLEAR		(EPDC_BASE_ADDR + 0x058)
#define EPDC_FORMAT_TOGGLE		(EPDC_BASE_ADDR + 0x05C)
#define EPDC_FIFOCTRL			(EPDC_BASE_ADDR + 0x0A0)
#define EPDC_FIFOCTRL_SET		(EPDC_BASE_ADDR + 0x0A4)
#define EPDC_FIFOCTRL_CLEAR		(EPDC_BASE_ADDR + 0x0A8)
#define EPDC_FIFOCTRL_TOGGLE    	(EPDC_BASE_ADDR + 0x0AC)
#define EPDC_UPD_ADDR			(EPDC_BASE_ADDR + 0x100)
#define EPDC_UPD_CORD			(EPDC_BASE_ADDR + 0x120)
#define EPDC_UPD_SIZE			(EPDC_BASE_ADDR + 0x140)
#define EPDC_UPD_CTRL			(EPDC_BASE_ADDR + 0x160)
#define EPDC_UPD_FIXED			(EPDC_BASE_ADDR + 0x180)
#define EPDC_TEMP			(EPDC_BASE_ADDR + 0x1A0)
#define EPDC_TCE_CTRL			(EPDC_BASE_ADDR + 0x200)
#define EPDC_TCE_SDCFG			(EPDC_BASE_ADDR + 0x220)
#define EPDC_TCE_GDCFG			(EPDC_BASE_ADDR + 0x240)
#define EPDC_TCE_HSCAN1			(EPDC_BASE_ADDR + 0x260)
#define EPDC_TCE_HSCAN2			(EPDC_BASE_ADDR + 0x280)
#define EPDC_TCE_VSCAN			(EPDC_BASE_ADDR + 0x2A0)
#define EPDC_TCE_OE			(EPDC_BASE_ADDR + 0x2C0)
#define EPDC_TCE_POLARITY		(EPDC_BASE_ADDR + 0x2E0)
#define EPDC_TCE_TIMING1		(EPDC_BASE_ADDR + 0x300)
#define EPDC_TCE_TIMING2		(EPDC_BASE_ADDR + 0x310)
#define EPDC_TCE_TIMING3		(EPDC_BASE_ADDR + 0x320)
#define EPDC_IRQ_MASK			(EPDC_BASE_ADDR + 0x400)
#define EPDC_IRQ_MASK_SET		(EPDC_BASE_ADDR + 0x404)
#define EPDC_IRQ_MASK_CLEAR		(EPDC_BASE_ADDR + 0x408)
#define EPDC_IRQ_MASK_TOGGLE    	(EPDC_BASE_ADDR + 0x40C)
#define EPDC_IRQ			(EPDC_BASE_ADDR + 0x420)
#define EPDC_IRQ_SET			(EPDC_BASE_ADDR + 0x424)
#define EPDC_IRQ_CLEAR			(EPDC_BASE_ADDR + 0x428)
#define EPDC_IRQ_TOGGLE			(EPDC_BASE_ADDR + 0x42C)
#define EPDC_STATUS_LUTS		(EPDC_BASE_ADDR + 0x440)
#define EPDC_STATUS_LUTS_SET    	(EPDC_BASE_ADDR + 0x444)
#define EPDC_STATUS_LUTS_CLEAR   	(EPDC_BASE_ADDR + 0x448)
#define EPDC_STATUS_LUTS_TOGGLE  	(EPDC_BASE_ADDR + 0x44C)
#define EPDC_STATUS_NEXTLUT		(EPDC_BASE_ADDR + 0x460)
#define EPDC_STATUS_COL			(EPDC_BASE_ADDR + 0x480)
#define EPDC_STATUS			(EPDC_BASE_ADDR + 0x4A0)
#define EPDC_STATUS_SET			(EPDC_BASE_ADDR + 0x4A4)
#define EPDC_STATUS_CLEAR		(EPDC_BASE_ADDR + 0x4A8)
#define EPDC_STATUS_TOGGLE		(EPDC_BASE_ADDR + 0x4AC)
#define EPDC_DEBUG			(EPDC_BASE_ADDR + 0x500)
#define EPDC_DEBUG_LUT0			(EPDC_BASE_ADDR + 0x540)
#define EPDC_DEBUG_LUT1			(EPDC_BASE_ADDR + 0x550)
#define EPDC_DEBUG_LUT2			(EPDC_BASE_ADDR + 0x560)
#define EPDC_DEBUG_LUT3			(EPDC_BASE_ADDR + 0x570)
#define EPDC_DEBUG_LUT4			(EPDC_BASE_ADDR + 0x580)
#define EPDC_DEBUG_LUT5			(EPDC_BASE_ADDR + 0x590)
#define EPDC_DEBUG_LUT6			(EPDC_BASE_ADDR + 0x5A0)
#define EPDC_DEBUG_LUT7			(EPDC_BASE_ADDR + 0x5B0)
#define EPDC_DEBUG_LUT8			(EPDC_BASE_ADDR + 0x5C0)
#define EPDC_DEBUG_LUT9			(EPDC_BASE_ADDR + 0x5D0)
#define EPDC_DEBUG_LUT10		(EPDC_BASE_ADDR + 0x5E0)
#define EPDC_DEBUG_LUT11		(EPDC_BASE_ADDR + 0x5F0)
#define EPDC_DEBUG_LUT12		(EPDC_BASE_ADDR + 0x600)
#define EPDC_DEBUG_LUT13		(EPDC_BASE_ADDR + 0x610)
#define EPDC_DEBUG_LUT14		(EPDC_BASE_ADDR + 0x620)
#define EPDC_DEBUG_LUT15		(EPDC_BASE_ADDR + 0x630)
#define EPDC_GPIO			(EPDC_BASE_ADDR + 0x700)
#define EPDC_VERSION			(EPDC_BASE_ADDR + 0x7F0)
#define EPDC_PIGEON_0_0			(EPDC_BASE_ADDR + 0x800)
#define EPDC_PIGEON_0_1			(EPDC_BASE_ADDR + 0x810)
#define EPDC_PIGEON_0_2			(EPDC_BASE_ADDR + 0x820)
#define EPDC_PIGEON_1_0			(EPDC_BASE_ADDR + 0x840)
#define EPDC_PIGEON_1_1			(EPDC_BASE_ADDR + 0x850)
#define EPDC_PIGEON_1_2			(EPDC_BASE_ADDR + 0x860)
#define EPDC_PIGEON_2_0			(EPDC_BASE_ADDR + 0x880)
#define EPDC_PIGEON_2_1			(EPDC_BASE_ADDR + 0x890)
#define EPDC_PIGEON_2_2			(EPDC_BASE_ADDR + 0x8A0)
#define EPDC_PIGEON_3_0			(EPDC_BASE_ADDR + 0x8C0)
#define EPDC_PIGEON_3_1			(EPDC_BASE_ADDR + 0x8D0)
#define EPDC_PIGEON_3_2			(EPDC_BASE_ADDR + 0x8E0)
#define EPDC_PIGEON_4_0			(EPDC_BASE_ADDR + 0x900)
#define EPDC_PIGEON_4_1			(EPDC_BASE_ADDR + 0x910)
#define EPDC_PIGEON_4_2			(EPDC_BASE_ADDR + 0x920)
#define EPDC_PIGEON_5_0			(EPDC_BASE_ADDR + 0x940)
#define EPDC_PIGEON_5_1			(EPDC_BASE_ADDR + 0x950)
#define EPDC_PIGEON_5_2			(EPDC_BASE_ADDR + 0x960)
#define EPDC_PIGEON_6_0			(EPDC_BASE_ADDR + 0x980)
#define EPDC_PIGEON_6_1			(EPDC_BASE_ADDR + 0x990)
#define EPDC_PIGEON_6_2			(EPDC_BASE_ADDR + 0x9A0)
#define EPDC_PIGEON_7_0			(EPDC_BASE_ADDR + 0x9C0)
#define EPDC_PIGEON_7_1			(EPDC_BASE_ADDR + 0x9D0)
#define EPDC_PIGEON_7_2			(EPDC_BASE_ADDR + 0x9E0)
#define EPDC_PIGEON_8_0			(EPDC_BASE_ADDR + 0xA00)
#define EPDC_PIGEON_8_1			(EPDC_BASE_ADDR + 0xA10)
#define EPDC_PIGEON_8_2			(EPDC_BASE_ADDR + 0xA20)
#define EPDC_PIGEON_9_0			(EPDC_BASE_ADDR + 0xA40)
#define EPDC_PIGEON_9_1			(EPDC_BASE_ADDR + 0xA50)
#define EPDC_PIGEON_9_2			(EPDC_BASE_ADDR + 0xA60)
#define EPDC_PIGEON_10_0		(EPDC_BASE_ADDR + 0xA80)
#define EPDC_PIGEON_10_1		(EPDC_BASE_ADDR + 0xA90)
#define EPDC_PIGEON_10_2		(EPDC_BASE_ADDR + 0xAA0)
#define EPDC_PIGEON_11_0		(EPDC_BASE_ADDR + 0xAC0)
#define EPDC_PIGEON_11_1		(EPDC_BASE_ADDR + 0xAD0)
#define EPDC_PIGEON_11_2		(EPDC_BASE_ADDR + 0xAE0)
#define EPDC_PIGEON_12_0		(EPDC_BASE_ADDR + 0xB00)
#define EPDC_PIGEON_12_1		(EPDC_BASE_ADDR + 0xB10)
#define EPDC_PIGEON_12_2		(EPDC_BASE_ADDR + 0xB20)
#define EPDC_PIGEON_13_0		(EPDC_BASE_ADDR + 0xB40)
#define EPDC_PIGEON_13_1		(EPDC_BASE_ADDR + 0xB50)
#define EPDC_PIGEON_13_2		(EPDC_BASE_ADDR + 0xB60)
#define EPDC_PIGEON_14_0		(EPDC_BASE_ADDR + 0xB80)
#define EPDC_PIGEON_14_1		(EPDC_BASE_ADDR + 0xB90)
#define EPDC_PIGEON_14_2		(EPDC_BASE_ADDR + 0xBA0)
#define EPDC_PIGEON_15_0		(EPDC_BASE_ADDR + 0xBC0)
#define EPDC_PIGEON_15_1		(EPDC_BASE_ADDR + 0xBD0)
#define EPDC_PIGEON_15_2		(EPDC_BASE_ADDR + 0xBE0)
#define EPDC_PIGEON_16_0		(EPDC_BASE_ADDR + 0xC00)
#define EPDC_PIGEON_16_1		(EPDC_BASE_ADDR + 0xC10)
#define EPDC_PIGEON_16_2		(EPDC_BASE_ADDR + 0xC20)
/*
 * Register field definitions
 */

enum {
    /* EPDC_CTRL field values */
    EPDC_CTRL_SFTRST = 0x80000000,
    EPDC_CTRL_CLKGATE = 0x40000000,
    EPDC_CTRL_SRAM_POWERDOWN = 0x100,
    EPDC_CTRL_UPD_DATA_SWIZZLE_MASK = 0xC0,
    EPDC_CTRL_UPD_DATA_SWIZZLE_NO_SWAP = 0,
    EPDC_CTRL_UPD_DATA_SWIZZLE_ALL_BYTES_SWAP = 0x40,
    EPDC_CTRL_UPD_DATA_SWIZZLE_HWD_SWAP = 0x80,
    EPDC_CTRL_UPD_DATA_SWIZZLE_HWD_BYTE_SWAP = 0xC0,
    EPDC_CTRL_LUT_DATA_SWIZZLE_MASK = 0x30,
    EPDC_CTRL_LUT_DATA_SWIZZLE_NO_SWAP = 0,
    EPDC_CTRL_LUT_DATA_SWIZZLE_ALL_BYTES_SWAP = 0x10,
    EPDC_CTRL_LUT_DATA_SWIZZLE_HWD_SWAP = 0x20,
    EPDC_CTRL_LUT_DATA_SWIZZLE_HWD_BYTE_SWAP = 0x30,
    EPDC_CTRL_BURST_LEN_8_8 = 0x1,
    EPDC_CTRL_BURST_LEN_8_16 = 0,

    /* EPDC_RES field values */
    EPDC_RES_VERTICAL_MASK = 0x1FFF0000,
    EPDC_RES_VERTICAL_OFFSET = 16,
    EPDC_RES_HORIZONTAL_MASK = 0x1FFF,
    EPDC_RES_HORIZONTAL_OFFSET = 0,

    /* EPDC_FORMAT field values */
    EPDC_FORMAT_BUF_PIXEL_SCALE_ROUND = 0x1000000,
    EPDC_FORMAT_DEFAULT_TFT_PIXEL_MASK = 0xFF0000,
    EPDC_FORMAT_DEFAULT_TFT_PIXEL_OFFSET = 16,
    EPDC_FORMAT_BUF_PIXEL_FORMAT_P2N = 0x200,
    EPDC_FORMAT_BUF_PIXEL_FORMAT_P3N = 0x300,
    EPDC_FORMAT_BUF_PIXEL_FORMAT_P4N = 0x400,
    EPDC_FORMAT_BUF_PIXEL_FORMAT_P5N = 0x500,
    EPDC_FORMAT_TFT_PIXEL_FORMAT_2BIT = 0x0,
    EPDC_FORMAT_TFT_PIXEL_FORMAT_2BIT_VCOM = 0x1,
    EPDC_FORMAT_TFT_PIXEL_FORMAT_4BIT = 0x2,
    EPDC_FORMAT_TFT_PIXEL_FORMAT_4BIT_VCOM = 0x3,

    /* EPDC_FIFOCTRL field values */
    EPDC_FIFOCTRL_ENABLE_PRIORITY = 0x80000000,
    EPDC_FIFOCTRL_FIFO_INIT_LEVEL_MASK = 0xFF0000,
    EPDC_FIFOCTRL_FIFO_INIT_LEVEL_OFFSET = 16,
    EPDC_FIFOCTRL_FIFO_H_LEVEL_MASK = 0xFF00,
    EPDC_FIFOCTRL_FIFO_H_LEVEL_OFFSET = 8,
    EPDC_FIFOCTRL_FIFO_L_LEVEL_MASK = 0xFF,
    EPDC_FIFOCTRL_FIFO_L_LEVEL_OFFSET = 0,

    /* EPDC_UPD_CORD field values */
    EPDC_UPD_CORD_YCORD_MASK = 0x1FFF0000,
    EPDC_UPD_CORD_YCORD_OFFSET = 16,
    EPDC_UPD_CORD_XCORD_MASK = 0x1FFF,
    EPDC_UPD_CORD_XCORD_OFFSET = 0,

    /* EPDC_UPD_SIZE field values */
    EPDC_UPD_SIZE_HEIGHT_MASK = 0x1FFF0000,
    EPDC_UPD_SIZE_HEIGHT_OFFSET = 16,
    EPDC_UPD_SIZE_WIDTH_MASK = 0x1FFF,
    EPDC_UPD_SIZE_WIDTH_OFFSET = 0,

    /* EPDC_UPD_CTRL field values */
    EPDC_UPD_CTRL_USE_FIXED = 0x80000000,
    EPDC_UPD_CTRL_LUT_SEL_MASK = 0xF0000,
    EPDC_UPD_CTRL_LUT_SEL_OFFSET = 16,
    EPDC_UPD_CTRL_WAVEFORM_MODE_MASK = 0xFF00,
    EPDC_UPD_CTRL_WAVEFORM_MODE_OFFSET = 8,
    EPDC_UPD_CTRL_UPDATE_MODE_FULL = 0x1,

    /* EPDC_UPD_FIXED field values */
    EPDC_UPD_FIXED_FIXNP_EN = 0x80000000,
    EPDC_UPD_FIXED_FIXCP_EN = 0x40000000,
    EPDC_UPD_FIXED_FIXNP_MASK = 0xFF00,
    EPDC_UPD_FIXED_FIXNP_OFFSET = 8,
    EPDC_UPD_FIXED_FIXCP_MASK = 0xFF,
    EPDC_UPD_FIXED_FIXCP_OFFSET = 0,

    /* EPDC_TCE_CTRL field values */
    EPDC_TCE_CTRL_VSCAN_HOLDOFF_MASK = 0x1FF0000,
    EPDC_TCE_CTRL_VSCAN_HOLDOFF_OFFSET = 16,
    EPDC_TCE_CTRL_VCOM_VAL_MASK = 0xC00,
    EPDC_TCE_CTRL_VCOM_VAL_OFFSET = 10,
    EPDC_TCE_CTRL_VCOM_MODE_AUTO = 0x200,
    EPDC_TCE_CTRL_VCOM_MODE_MANUAL = 0x000,
    EPDC_TCE_CTRL_DDR_MODE_ENABLE = 0x100,
    EPDC_TCE_CTRL_LVDS_MODE_CE_ENABLE = 0x80,
    EPDC_TCE_CTRL_LVDS_MODE_ENABLE = 0x40,
    EPDC_TCE_CTRL_SCAN_DIR_1_UP = 0x20,
    EPDC_TCE_CTRL_SCAN_DIR_0_UP = 0x10,
    EPDC_TCE_CTRL_DUAL_SCAN_ENABLE = 0x8,
    EPDC_TCE_CTRL_SDDO_WIDTH_16BIT = 0x4,
    EPDC_TCE_CTRL_PIXELS_PER_SDCLK_2 = 1,
    EPDC_TCE_CTRL_PIXELS_PER_SDCLK_4 = 2,
    EPDC_TCE_CTRL_PIXELS_PER_SDCLK_8 = 3,

    /* EPDC_TCE_SDCFG field values */
    EPDC_TCE_SDCFG_SDCLK_HOLD = 0x200000,
    EPDC_TCE_SDCFG_SDSHR = 0x100000,
    EPDC_TCE_SDCFG_NUM_CE_MASK = 0xF0000,
    EPDC_TCE_SDCFG_NUM_CE_OFFSET = 16,
    EPDC_TCE_SDCFG_SDDO_REFORMAT_STANDARD = 0,
    EPDC_TCE_SDCFG_SDDO_REFORMAT_FLIP_PIXELS = 0x4000,
    EPDC_TCE_SDCFG_SDDO_INVERT_ENABLE = 0x2000,
    EPDC_TCE_SDCFG_PIXELS_PER_CE_MASK = 0x1FFF,
    EPDC_TCE_SDCFG_PIXELS_PER_CE_OFFSET = 0,

    /* EPDC_TCE_GDCFG field values */
    EPDC_TCE_SDCFG_GDRL = 0x10,
    EPDC_TCE_SDCFG_GDOE_MODE_DELAYED_GDCLK = 0x2,
    EPDC_TCE_SDCFG_GDSP_MODE_FRAME_SYNC = 0x1,
    EPDC_TCE_SDCFG_GDSP_MODE_ONE_LINE = 0x0,

    /* EPDC_TCE_HSCAN1 field values */
    EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH_MASK = 0xFFF0000,
    EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH_OFFSET = 16,
    EPDC_TCE_HSCAN1_LINE_SYNC_MASK = 0xFFF,
    EPDC_TCE_HSCAN1_LINE_SYNC_OFFSET = 0,

    /* EPDC_TCE_HSCAN2 field values */
    EPDC_TCE_HSCAN2_LINE_END_MASK = 0xFFF0000,
    EPDC_TCE_HSCAN2_LINE_END_OFFSET = 16,
    EPDC_TCE_HSCAN2_LINE_BEGIN_MASK = 0xFFF,
    EPDC_TCE_HSCAN2_LINE_BEGIN_OFFSET = 0,

    /* EPDC_TCE_VSCAN field values */
    EPDC_TCE_VSCAN_FRAME_END_MASK = 0xFF0000,
    EPDC_TCE_VSCAN_FRAME_END_OFFSET = 16,
    EPDC_TCE_VSCAN_FRAME_BEGIN_MASK = 0xFF00,
    EPDC_TCE_VSCAN_FRAME_BEGIN_OFFSET = 8,
    EPDC_TCE_VSCAN_FRAME_SYNC_MASK = 0xFF,
    EPDC_TCE_VSCAN_FRAME_SYNC_OFFSET = 0,

    /* EPDC_TCE_OE field values */
    EPDC_TCE_OE_SDOED_WIDTH_MASK = 0xFF000000,
    EPDC_TCE_OE_SDOED_WIDTH_OFFSET = 24,
    EPDC_TCE_OE_SDOED_DLY_MASK = 0xFF0000,
    EPDC_TCE_OE_SDOED_DLY_OFFSET = 16,
    EPDC_TCE_OE_SDOEZ_WIDTH_MASK = 0xFF00,
    EPDC_TCE_OE_SDOEZ_WIDTH_OFFSET = 8,
    EPDC_TCE_OE_SDOEZ_DLY_MASK = 0xFF,
    EPDC_TCE_OE_SDOEZ_DLY_OFFSET = 0,

    /* EPDC_TCE_POLARITY field values */
    EPDC_TCE_POLARITY_GDSP_POL_ACTIVE_HIGH = 0x10,
    EPDC_TCE_POLARITY_GDOE_POL_ACTIVE_HIGH = 0x8,
    EPDC_TCE_POLARITY_SDOE_POL_ACTIVE_HIGH = 0x4,
    EPDC_TCE_POLARITY_SDLE_POL_ACTIVE_HIGH = 0x2,
    EPDC_TCE_POLARITY_SDCE_POL_ACTIVE_HIGH = 0x1,

    /* EPDC_TCE_TIMING1 field values */
    EPDC_TCE_TIMING1_SDLE_SHIFT_NONE = 0x00,
    EPDC_TCE_TIMING1_SDLE_SHIFT_1 = 0x10,
    EPDC_TCE_TIMING1_SDLE_SHIFT_2 = 0x20,
    EPDC_TCE_TIMING1_SDLE_SHIFT_3 = 0x30,
    EPDC_TCE_TIMING1_SDCLK_INVERT = 0x8,
    EPDC_TCE_TIMING1_SDCLK_SHIFT_NONE = 0,
    EPDC_TCE_TIMING1_SDCLK_SHIFT_1CYCLE = 1,
    EPDC_TCE_TIMING1_SDCLK_SHIFT_2CYCLES = 2,
    EPDC_TCE_TIMING1_SDCLK_SHIFT_3CYCLES = 3,

    /* EPDC_TCE_TIMING2 field values */
    EPDC_TCE_TIMING2_GDCLK_HP_MASK = 0xFFFF0000,
    EPDC_TCE_TIMING2_GDCLK_HP_OFFSET = 16,
    EPDC_TCE_TIMING2_GDSP_OFFSET_MASK = 0xFFFF,
    EPDC_TCE_TIMING2_GDSP_OFFSET_OFFSET = 0,

    /* EPDC_TCE_TIMING3 field values */
    EPDC_TCE_TIMING3_GDOE_OFFSET_MASK = 0xFFFF0000,
    EPDC_TCE_TIMING3_GDOE_OFFSET_OFFSET = 16,
    EPDC_TCE_TIMING3_GDCLK_OFFSET_MASK = 0xFFFF,
    EPDC_TCE_TIMING3_GDCLK_OFFSET_OFFSET = 0,

    /* EPDC_IRQ_MASK/EPDC_IRQ field values */
    EPDC_IRQ_WB_CMPLT_IRQ = 0x10000,
    EPDC_IRQ_LUT_COL_IRQ = 0x20000,
    EPDC_IRQ_TCE_UNDERRUN_IRQ = 0x40000,
    EPDC_IRQ_FRAME_END_IRQ = 0x80000,
    EPDC_IRQ_BUS_ERROR_IRQ = 0x100000,
    EPDC_IRQ_TCE_IDLE_IRQ = 0x200000,

    /* EPDC_STATUS_NEXTLUT field values */
    EPDC_STATUS_NEXTLUT_NEXT_LUT_VALID = 0x100,
    EPDC_STATUS_NEXTLUT_NEXT_LUT_MASK = 0xF,
    EPDC_STATUS_NEXTLUT_NEXT_LUT_OFFSET = 0,

    /* EPDC_STATUS field values */
    EPDC_STATUS_LUTS_UNDERRUN = 0x4,
    EPDC_STATUS_LUTS_BUSY = 0x2,
    EPDC_STATUS_WB_BUSY = 0x1,

    /* EPDC_DEBUG field values */
    EPDC_DEBUG_UNDERRUN_RECOVER = 0x2,
    EPDC_DEBUG_COLLISION_OFF = 0x1,

    /* EPDC_GPIO field values */
    EPDC_GPIO_PWRCOM = 0x40,
    EPDC_GPIO_PWRCTRL_MASK = 0x3C,
    EPDC_GPIO_PWRCTRL_OFFSET = 2,
    EPDC_GPIO_BDR_MASK = 0x3,
    EPDC_GPIO_BDR_OFFSET = 0,
	
	/* EPDC_VERSION field values */
	EPDC_VERSION_MAJOR_MASK = 0xFF000000,
	EPDC_VERSION_MAJOR_OFFSET = 24,
	EPDC_VERSION_MINOR_MASK = 0xFF0000,
	EPDC_VERSION_MINOR_OFFSET = 16,
	EPDC_VERSION_STEP_MASK = 0xFFFF,
	EPDC_VERSION_STEP_OFFSET = 0,
};

#endif // _EPDC_REGS_H_