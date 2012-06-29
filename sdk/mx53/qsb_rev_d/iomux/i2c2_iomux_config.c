/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: i2c2_iomux_config.c

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

// Function to configure IOMUXC for i2c2 module.
void i2c2_iomux_config(void)
{
    // Config i2c2.SCL to pad KEY_COL3(F6)
    // HW_IOMUXC_SW_MUX_CTL_PAD_KEY_COL3_WR(0x00000004);
    // HW_IOMUXC_I2C2_IPP_SCL_IN_SELECT_INPUT_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_KEY_COL3_WR(0x000001E4);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_KEY_COL3(0x53FA803C)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad KEY_COL3.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT1
    //                    Select 1 of 8 iomux modes to be used for pad: KEY_COL3.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: COL[3] of instance: kpp.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[12] of instance: gpio4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: H2_DP of instance: usboh3.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: IN1 of instance: spdif.
    //                NOTE: - Config Register IOMUXC_SPDIF_SPDIF_IN1_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: SCL of instance: i2c2.
    //                NOTE: - Config Register IOMUXC_I2C2_IPP_SCL_IN_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: SS3 of instance: ecspi1.
    //                NOTE: - Config Register IOMUXC_ECSPI1_IPP_IND_SS_B_3_SELECT_INPUT for mode ALT5.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: CRS of instance: fec.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: SIECLOCK of instance: usbphy1.
    HW_IOMUXC_SW_MUX_CTL_PAD_KEY_COL3_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_COL3_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_COL3_MUX_MODE(ALT4));
    // Pad KEY_COL3 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_I2C2_IPP_SCL_IN_SELECT_INPUT(0x53FA881C)
    //   DAISY [0] Reset: SEL_KEY_COL3_ALT4
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: i2c2, In Pin: ipp_scl_in
    //     SEL_KEY_COL3_ALT4 (0) - Selecting Pad: KEY_COL3 for Mode: ALT4.
    //     SEL_EIM_EB2_ALT5 (1) - Selecting Pad: EIM_EB2 for Mode: ALT5.
    HW_IOMUXC_I2C2_IPP_SCL_IN_SELECT_INPUT_WR(
            BF_IOMUXC_I2C2_IPP_SCL_IN_SELECT_INPUT_DAISY(SEL_KEY_COL3_ALT4));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_KEY_COL3(0x53FA8364)
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
    //             Select one out of next values for pad: KEY_COL3.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: KEY_COL3.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: KEY_COL3.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: KEY_COL3.
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: KEY_COL3.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: KEY_COL3.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_KEY_COL3_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL3_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL3_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL3_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL3_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL3_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL3_DSE(DSE_120OHM));

    // Config i2c2.SDA to pad KEY_ROW3(D4)
    // HW_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW3_WR(0x00000004);
    // HW_IOMUXC_I2C2_IPP_SDA_IN_SELECT_INPUT_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW3_WR(0x000001E4);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_KEY_ROW3(0x53FA8040)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad KEY_ROW3.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT1
    //                    Select 1 of 8 iomux modes to be used for pad: KEY_ROW3.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: ROW[3] of instance: kpp.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[13] of instance: gpio4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: H2_DM of instance: usboh3.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: ASRC_EXT_CLK of instance: ccm.
    //                NOTE: - Config Register IOMUXC_CCM_IPP_ASRC_EXT_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: SDA of instance: i2c2.
    //                NOTE: - Config Register IOMUXC_I2C2_IPP_SDA_IN_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: 32K_OUT of instance: osc32k.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: PLL4_BYP of instance: ccm.
    //                NOTE: - Config Register IOMUXC_CCM_PLL4_BYPASS_CLK_SELECT_INPUT for mode ALT6.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: LINESTATE[0] of instance: usbphy1.
    HW_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW3_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW3_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW3_MUX_MODE(ALT4));
    // Pad KEY_ROW3 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_I2C2_IPP_SDA_IN_SELECT_INPUT(0x53FA8820)
    //   DAISY [0] Reset: SEL_KEY_ROW3_ALT4
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: i2c2, In Pin: ipp_sda_in
    //     SEL_KEY_ROW3_ALT4 (0) - Selecting Pad: KEY_ROW3 for Mode: ALT4.
    //     SEL_EIM_D16_ALT5 (1) - Selecting Pad: EIM_D16 for Mode: ALT5.
    HW_IOMUXC_I2C2_IPP_SDA_IN_SELECT_INPUT_WR(
            BF_IOMUXC_I2C2_IPP_SDA_IN_SELECT_INPUT_DAISY(SEL_KEY_ROW3_ALT4));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_KEY_ROW3(0x53FA8368)
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
    //             Select one out of next values for pad: KEY_ROW3.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: KEY_ROW3.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: KEY_ROW3.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: KEY_ROW3.
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: KEY_ROW3.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: KEY_ROW3.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW3_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW3_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW3_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW3_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW3_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW3_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW3_DSE(DSE_120OHM));
}
