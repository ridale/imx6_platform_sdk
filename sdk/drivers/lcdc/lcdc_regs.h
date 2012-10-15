/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef _LCDC_REGS_H_
#define _LCDC_REGS_H_

#include "sdk.h"           // Hardware definitions
#define 	LCDIF_CSC_ENABLE		1
#define 	LCDIF_CSC_DISABLE		0

#define 	HW_LCDIF_CTRL 				(ELCDIF_BASE_ADDR + 0x000)
#define 	HW_LCDIF_CTRL_SET 			(ELCDIF_BASE_ADDR + 0x004)
#define 	HW_LCDIF_CTRL_CLR 			(ELCDIF_BASE_ADDR + 0x008)
#define 	HW_LCDIF_CTRL_TOG 			(ELCDIF_BASE_ADDR + 0x00C)
#define 	HW_LCDIF_CTRL1 				(ELCDIF_BASE_ADDR + 0x010)
#define 	HW_LCDIF_CTRL1_SET 			(ELCDIF_BASE_ADDR + 0x014)
#define 	HW_LCDIF_CTRL1_CLR 			(ELCDIF_BASE_ADDR + 0x018)
#define 	HW_LCDIF_CTRL1_TOG 			(ELCDIF_BASE_ADDR + 0x01C)
#define 	HW_LCDIF_CTRL2 				(ELCDIF_BASE_ADDR + 0x020)
#define 	HW_LCDIF_CTRL2_SET 			(ELCDIF_BASE_ADDR + 0x024)
#define 	HW_LCDIF_CTRL2_CLR 			(ELCDIF_BASE_ADDR + 0x028)
#define 	HW_LCDIF_CTRL2_TOG 			(ELCDIF_BASE_ADDR + 0x02C)
#define 	HW_LCDIF_TRANSFER_COUNT 	(ELCDIF_BASE_ADDR + 0x030)
#define 	HW_LCDIF_CUR_BUF 			(ELCDIF_BASE_ADDR + 0x040)
#define 	HW_LCDIF_NEXT_BUF 			(ELCDIF_BASE_ADDR + 0x050)
#define 	HW_LCDIF_TIMING 			(ELCDIF_BASE_ADDR + 0x060)
#define 	HW_LCDIF_VDCTRL0 			(ELCDIF_BASE_ADDR + 0x070)
#define 	HW_LCDIF_VDCTRL0_SET 		(ELCDIF_BASE_ADDR + 0x074)
#define 	HW_LCDIF_VDCTRL0_CLR 		(ELCDIF_BASE_ADDR + 0x078)
#define 	HW_LCDIF_VDCTRL0_TOG 		(ELCDIF_BASE_ADDR + 0x07C)
#define 	HW_LCDIF_VDCTRL1 			(ELCDIF_BASE_ADDR + 0x080)
#define 	HW_LCDIF_VDCTRL2 			(ELCDIF_BASE_ADDR + 0x090)
#define 	HW_LCDIF_VDCTRL3 			(ELCDIF_BASE_ADDR + 0x0a0)
#define 	HW_LCDIF_VDCTRL4 			(ELCDIF_BASE_ADDR + 0x0b0)
#define 	HW_LCDIF_DVICTRL0 			(ELCDIF_BASE_ADDR + 0x0c0)
#define 	HW_LCDIF_DVICTRL1 			(ELCDIF_BASE_ADDR + 0x0d0)
#define 	HW_LCDIF_DVICTRL2 			(ELCDIF_BASE_ADDR + 0x0e0)
#define 	HW_LCDIF_DVICTRL3 			(ELCDIF_BASE_ADDR + 0x0f0)
#define 	HW_LCDIF_DVICTRL4 			(ELCDIF_BASE_ADDR + 0x100)
#define 	HW_LCDIF_CSC_COEFF0 		(ELCDIF_BASE_ADDR + 0x110)
#define 	HW_LCDIF_CSC_COEFF1 		(ELCDIF_BASE_ADDR + 0x120)
#define 	HW_LCDIF_CSC_COEFF2 		(ELCDIF_BASE_ADDR + 0x130)
#define 	HW_LCDIF_CSC_COEFF3 		(ELCDIF_BASE_ADDR + 0x140)
#define 	HW_LCDIF_CSC_COEFF4 		(ELCDIF_BASE_ADDR + 0x150)
#define 	HW_LCDIF_CSC_OFFSET 		(ELCDIF_BASE_ADDR + 0x160)
#define 	HW_LCDIF_CSC_LIMIT 			(ELCDIF_BASE_ADDR + 0x170)
#define 	HW_LCDIF_DATA 				(ELCDIF_BASE_ADDR + 0x180)
#define 	HW_LCDIF_BM_ERROR_STAT 		(ELCDIF_BASE_ADDR + 0x190)
#define 	HW_LCDIF_CRC_STAT 			(ELCDIF_BASE_ADDR + 0x1a0)
#define 	HW_LCDIF_STAT 				(ELCDIF_BASE_ADDR + 0x1b0)
#define 	HW_LCDIF_VERSION 			(ELCDIF_BASE_ADDR + 0x1c0)
#define 	HW_LCDIF_DEBUG0 			(ELCDIF_BASE_ADDR + 0x1d0)
#define 	HW_LCDIF_DEBUG1 			(ELCDIF_BASE_ADDR + 0x1e0)
#define 	HW_LCDIF_DEBUG2 			(ELCDIF_BASE_ADDR + 0x1f0)

#endif
