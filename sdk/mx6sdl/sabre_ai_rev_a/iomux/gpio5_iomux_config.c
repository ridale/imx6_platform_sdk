/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: gpio5_iomux_config.c

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

// Function to configure IOMUXC for gpio5 module.
void gpio5_iomux_config(void)
{
    // Config gpio5.GPIO[14] to pad DISP0_DAT20(U22)
    // HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT20_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT20_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT20(0x020E00E4)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad DISP0_DAT20.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: DISP0_DAT20.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DISP0_DAT[20] of instance: ipu1.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DAT[20] of instance: lcdif.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: SCLK of instance: ecspi1.
    //                NOTE: - Config IOMUXC_ECSPI1_IPP_CSPI_CLK_IN_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: AUD4_TXC of instance: audmux.
    //                NOTE: - Config IOMUXC_AUDMUX_P4_INPUT_TXCLK_AMX_SELECT_INPUT for mode ALT3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[14] of instance: gpio5.
    HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT20_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT20_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT20_MUX_MODE(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT20(0x020E03F8)
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: DISP0_DAT20.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: DISP0_DAT20.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: DISP0_DAT20.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: DISP0_DAT20.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: DISP0_DAT20.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: DISP0_DAT20.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: DISP0_DAT20.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: DISP0_DAT20.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT20_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT20_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT20_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT20_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT20_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT20_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT20_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT20_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT20_SRE(SRE_SLOW));

    // Config gpio5.GPIO[15] to pad DISP0_DAT21(T20)
    // HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT21_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT21_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT21(0x020E00E8)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad DISP0_DAT21.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: DISP0_DAT21.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DISP0_DAT[21] of instance: ipu1.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DAT[21] of instance: lcdif.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: MOSI of instance: ecspi1.
    //                NOTE: - Config IOMUXC_ECSPI1_IPP_IND_MOSI_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: AUD4_TXD of instance: audmux.
    //                NOTE: - Config IOMUXC_AUDMUX_P4_INPUT_DB_AMX_SELECT_INPUT for mode ALT3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[15] of instance: gpio5.
    HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT21_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT21_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT21_MUX_MODE(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT21(0x020E03FC)
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: DISP0_DAT21.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: DISP0_DAT21.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: DISP0_DAT21.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: DISP0_DAT21.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: DISP0_DAT21.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: DISP0_DAT21.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: DISP0_DAT21.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: DISP0_DAT21.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT21_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT21_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT21_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT21_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT21_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT21_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT21_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT21_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT21_SRE(SRE_SLOW));

    // Config gpio5.GPIO[16] to pad DISP0_DAT22(V24)
    // HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT22_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT22_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT22(0x020E00EC)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad DISP0_DAT22.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: DISP0_DAT22.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DISP0_DAT[22] of instance: ipu1.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DAT[22] of instance: lcdif.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: MISO of instance: ecspi1.
    //                NOTE: - Config IOMUXC_ECSPI1_IPP_IND_MISO_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: AUD4_TXFS of instance: audmux.
    //                NOTE: - Config IOMUXC_AUDMUX_P4_INPUT_TXFS_AMX_SELECT_INPUT for mode ALT3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[16] of instance: gpio5.
    HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT22_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT22_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT22_MUX_MODE(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT22(0x020E0400)
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: DISP0_DAT22.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: DISP0_DAT22.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: DISP0_DAT22.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: DISP0_DAT22.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: DISP0_DAT22.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: DISP0_DAT22.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: DISP0_DAT22.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: DISP0_DAT22.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT22_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT22_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT22_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT22_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT22_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT22_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT22_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT22_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT22_SRE(SRE_SLOW));

    // Config gpio5.GPIO[17] to pad DISP0_DAT23(W24)
    // HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT23_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT23_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT23(0x020E00F0)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad DISP0_DAT23.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: DISP0_DAT23.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DISP0_DAT[23] of instance: ipu1.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DAT[23] of instance: lcdif.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: SS0 of instance: ecspi1.
    //                NOTE: - Config IOMUXC_ECSPI1_IPP_IND_SS_B_0_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: AUD4_RXD of instance: audmux.
    //                NOTE: - Config IOMUXC_AUDMUX_P4_INPUT_DA_AMX_SELECT_INPUT for mode ALT3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[17] of instance: gpio5.
    HW_IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT23_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT23_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT23_MUX_MODE(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT23(0x020E0404)
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: DISP0_DAT23.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: DISP0_DAT23.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: DISP0_DAT23.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: DISP0_DAT23.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: DISP0_DAT23.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: DISP0_DAT23.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: DISP0_DAT23.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: DISP0_DAT23.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT23_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT23_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT23_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT23_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT23_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT23_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT23_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT23_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DISP0_DAT23_SRE(SRE_SLOW));

    // Config gpio5.GPIO[20] to pad CSI0_DATA_EN(P3)
    // HW_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA_EN_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA_EN(0x020E008C)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad CSI0_DATA_EN.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 7 iomux modes to be used for pad: CSI0_DATA_EN.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CSI0_DATA_EN of instance: ipu1.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: WEIM_D[0] of instance: weim.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[20] of instance: gpio5.
    HW_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA_EN_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA_EN_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_CSI0_DATA_EN_MUX_MODE(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN(0x020E03A0)
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: CSI0_DATA_EN.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: CSI0_DATA_EN.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: CSI0_DATA_EN.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: CSI0_DATA_EN.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: CSI0_DATA_EN.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: CSI0_DATA_EN.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: CSI0_DATA_EN.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: CSI0_DATA_EN.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_CSI0_DATA_EN_SRE(SRE_SLOW));
}
