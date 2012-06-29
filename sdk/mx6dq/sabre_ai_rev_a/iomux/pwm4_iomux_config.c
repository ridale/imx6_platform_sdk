/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: pwm4_iomux_config.c

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

// Function to configure IOMUXC for pwm4 module.
void pwm4_iomux_config(void)
{
    // Config pwm4.PWMO to pad SD4_DAT2(F17)
    // HW_IOMUXC_SW_MUX_CTL_PAD_SD4_DAT2_WR(0x00000002);
    // HW_IOMUXC_SW_PAD_CTL_PAD_SD4_DAT2_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD4_DAT2(0x020E0324)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD4_DAT2.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: SD4_DAT2.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: D10 of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DAT2 of instance: usdhc4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: PWMO of instance: pwm4.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH2_DFD_OUT[26] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH3_DFD_OUT[26] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[10] of instance: gpio2.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: IPU_DIAG_BUS[10] of instance: ipu1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: IPU_DIAG_BUS[10] of instance: ipu2.
    HW_IOMUXC_SW_MUX_CTL_PAD_SD4_DAT2_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_SD4_DAT2_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_SD4_DAT2_MUX_MODE(ALT2));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD4_DAT2(0x020E070C)
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD4_DAT2.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD4_DAT2.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD4_DAT2.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD4_DAT2.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD4_DAT2.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD4_DAT2.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD4_DAT2.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD4_DAT2.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_SD4_DAT2_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_SD4_DAT2_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD4_DAT2_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD4_DAT2_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD4_DAT2_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD4_DAT2_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD4_DAT2_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD4_DAT2_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD4_DAT2_SRE(SRE_SLOW));
}
