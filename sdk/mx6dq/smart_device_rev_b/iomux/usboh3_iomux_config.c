/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: usboh3_iomux_config.c

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

// Function to configure IOMUXC for usboh3 module.
void usboh3_iomux_config(void)
{
    // Config usboh3.USBH1_OC to pad EIM_D30(J20)
    // HW_IOMUXC_SW_MUX_CTL_PAD_EIM_D30_WR(0x00000006);
    // HW_IOMUXC_USBOH3_IPP_IND_UH1_OC_SELECT_INPUT_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_EIM_D30_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_D30(0x020E00CC)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_D30.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: EIM_D30.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_D[30] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DISP1_DAT[21] of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DI0_PIN11 of instance: ipu1.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: CSI0_D[3] of instance: ipu1.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: CTS of instance: uart3.
    //                NOTE: - Config Register IOMUXC_UART3_IPP_UART_RTS_B_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[30] of instance: gpio3.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: USBH1_OC of instance: usboh3.
    //                NOTE: - Config Register IOMUXC_USBOH3_IPP_IND_UH1_OC_SELECT_INPUT for mode ALT6.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HPROT[0] of instance: pl301_mx63per1.
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_D30_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_D30_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_D30_MUX_MODE(ALT6));
    // Pad EIM_D30 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_USBOH3_IPP_IND_UH1_OC_SELECT_INPUT(0x020E0948)
    //   DAISY [0] Reset: SEL_EIM_D30_ALT6
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: usboh3, In Pin: ipp_ind_uh1_oc
    //     SEL_EIM_D30_ALT6 (0) - Selecting Pad: EIM_D30 for Mode: ALT6.
    //     SEL_GPIO_3_ALT6 (1) - Selecting Pad: GPIO_3 for Mode: ALT6.
    HW_IOMUXC_USBOH3_IPP_IND_UH1_OC_SELECT_INPUT_WR(
            BF_IOMUXC_USBOH3_IPP_IND_UH1_OC_SELECT_INPUT_DAISY(SEL_EIM_D30_ALT6));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_D30(0x020E03E0)
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: EIM_D30.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_D30.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_D30.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_D30.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_D30.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_D30.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_D30.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: EIM_D30.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_EIM_D30_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D30_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D30_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D30_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D30_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D30_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D30_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D30_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D30_SRE(SRE_SLOW));

    // Config usboh3.USBOTG_OC to pad EIM_D21(H20)
    // HW_IOMUXC_SW_MUX_CTL_PAD_EIM_D21_WR(0x00000004);
    // HW_IOMUXC_USBOH3_IPP_IND_OTG_OC_SELECT_INPUT_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_EIM_D21_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_D21(0x020E00A4)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_D21.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: EIM_D21.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_D[21] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SCLK of instance: ecspi4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DI0_PIN17 of instance: ipu1.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: CSI1_D[11] of instance: ipu2.
    //                NOTE: - Config Register IOMUXC_IPU2_IPP_IND_SENS1_DATA_11_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: USBOTG_OC of instance: usboh3.
    //                NOTE: - Config Register IOMUXC_USBOH3_IPP_IND_OTG_OC_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[21] of instance: gpio3.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SCL of instance: i2c1.
    //                NOTE: - Config Register IOMUXC_I2C1_IPP_SCL_IN_SELECT_INPUT for mode ALT6.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: IN1 of instance: spdif.
    //                NOTE: - Config Register IOMUXC_SPDIF_SPDIF_IN1_SELECT_INPUT for mode ALT7.
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_D21_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_D21_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_D21_MUX_MODE(ALT4));
    // Pad EIM_D21 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_USBOH3_IPP_IND_OTG_OC_SELECT_INPUT(0x020E0944)
    //   DAISY [0] Reset: SEL_EIM_D21_ALT4
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: usboh3, In Pin: ipp_ind_otg_oc
    //     SEL_EIM_D21_ALT4 (0) - Selecting Pad: EIM_D21 for Mode: ALT4.
    //     SEL_KEY_COL4_ALT2 (1) - Selecting Pad: KEY_COL4 for Mode: ALT2.
    HW_IOMUXC_USBOH3_IPP_IND_OTG_OC_SELECT_INPUT_WR(
            BF_IOMUXC_USBOH3_IPP_IND_OTG_OC_SELECT_INPUT_DAISY(SEL_EIM_D21_ALT4));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_D21(0x020E03B8)
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: EIM_D21.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_D21.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_D21.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_D21.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_D21.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_D21.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_D21.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: EIM_D21.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_EIM_D21_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D21_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D21_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D21_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D21_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D21_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D21_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D21_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D21_SRE(SRE_SLOW));
}
