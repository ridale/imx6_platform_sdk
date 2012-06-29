/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: spdif_iomux_config.c

/* ------------------------------------------------------------------------------
 * <auto-generated>
 *     This code was generated by a tool.
 *     Runtime Version:3.3.2.1
 *
 *     Changes to this file may cause incorrect behavior and will be lost if
 *     the code is regenerated.
 * </auto-generated>
 * ------------------------------------------------------------------------------
*/

#include "iomux_config.h"
#include "iomux_define.h"
#include "registers/regsiomuxc.h"

// Function to configure IOMUXC for spdif module.
void spdif_iomux_config(void)
{
    // Config spdif.OUT1 to pad GPIO_17(A3)
    // HW_IOMUXC_SW_MUX_CTL_PAD_GPIO_17_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_17_WR(0x000001C4);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO_17(0x53FA8340)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad GPIO_17.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT1
    //                    Select 1 of 8 iomux modes to be used for pad: GPIO_17.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: TX0 of instance: esai1.
    //                NOTE: - Config Register IOMUXC_ESAI1_IPP_IND_SDO0_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[12] of instance: gpio7.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: SDMA_EXT_EVENT[0] of instance: sdma.
    //                NOTE: - Config Register IOMUXC_SDMA_EVENTS_14_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: PMIC_RDY of instance: gpc.
    //                NOTE: - Config Register IOMUXC_GPC_PMIC_RDY_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: CE_RTC_FSV_TRIG of instance: rtc.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: OUT1 of instance: spdif.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SNOOP2 of instance: ipu.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: JTAG_ACT of instance: sjc.
    HW_IOMUXC_SW_MUX_CTL_PAD_GPIO_17_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO_17_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO_17_MUX_MODE(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO_17(0x53FA86D0)
    //   HVE [13] - Low / High Output Voltage Field Reset: HVE_RES0
    //              Read Only Field
    //     HVE_RES0 (0) - Reserved
    //   TEST_TS [12] - Test TS Field Reset: TEST_TS_DISABLED
    //                  Read Only Field
    //     TEST_TS_DISABLED (0) - Disabled
    //   DSE_TEST [11] - DSE Test Field Reset: DSE_TEST_NORMAL
    //                   Read Only Field
    //     DSE_TEST_NORMAL (0) - Normal
    //   HYS [8] - Hysteresis Enable Field Reset: HYS_ENABLED
    //             Select one out of next values for pad: GPIO_17.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: GPIO_17.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: GPIO_17.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_360KOHM_PD
    //               Select one out of next values for pad: GPIO_17.
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: GPIO_17.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: GPIO_17.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_17_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_17_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_17_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_17_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_17_PUS(PUS_360KOHM_PD) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_17_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_17_DSE(DSE_120OHM));
}
