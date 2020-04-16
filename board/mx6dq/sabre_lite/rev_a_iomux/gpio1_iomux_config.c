/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// File: gpio1_iomux_config.c

/* ------------------------------------------------------------------------------
 * <auto-generated>
 *     This code was generated by a tool.
 *     Runtime Version:3.4.0.3
 *
 *     Changes to this file may cause incorrect behavior and will be lost if
 *     the code is regenerated.
 * </auto-generated>
 * ------------------------------------------------------------------------------
*/

#include "iomux_config.h"
#include "registers/regsiomuxc.h"

// Function to configure IOMUXC for gpio1 module.
void gpio1_iomux_config(void)
{
    // Config gpio1.GPIO1_IO06 to pad GPIO06(T3)
    // J5 - Camera GP
    // HW_IOMUXC_SW_MUX_CTL_PAD_GPIO06_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_GPIO06_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO06(0x020E0230)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: esai signal: ESAI_TX_CLK
    //     ALT2 (2) - Select instance: i2c3 signal: I2C3_SDA
    //     ALT5 (5) - Select instance: gpio1 signal: GPIO1_IO06
    //     ALT6 (6) - Select instance: usdhc2 signal: SD2_LCTL
    //     ALT7 (7) - Select instance: mlb signal: MLB_SIG
    HW_IOMUXC_SW_MUX_CTL_PAD_GPIO06_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO06_SION_V(DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO06_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO06(0x020E0600)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SLOW
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_GPIO06_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO06_HYS_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO06_PUS_V(100K_OHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO06_PUE_V(PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO06_PKE_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO06_ODE_V(DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO06_SPEED_V(100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO06_DSE_V(40_OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO06_SRE_V(SLOW));

    // Config gpio1.GPIO1_IO07 to pad GPIO07(R3)
    // J7 - Display Connector GP
    // HW_IOMUXC_SW_MUX_CTL_PAD_GPIO07_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_GPIO07_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO07(0x020E0240)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: esai signal: ESAI_TX4_RX1
    //     ALT1 (1) - Select instance: ecspi5 signal: ECSPI5_RDY
    //     ALT2 (2) - Select instance: epit1 signal: EPIT1_OUT
    //     ALT3 (3) - Select instance: flexcan1 signal: FLEXCAN1_TX
    //     ALT4 (4) - Select instance: uart2 signal: UART2_TX_DATA
    //     ALT5 (5) - Select instance: gpio1 signal: GPIO1_IO07
    //     ALT6 (6) - Select instance: spdif signal: SPDIF_LOCK
    //     ALT7 (7) - Select instance: usb signal: USB_OTG_HOST_MODE
    HW_IOMUXC_SW_MUX_CTL_PAD_GPIO07_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO07_SION_V(DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO07_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO07(0x020E0610)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SLOW
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_GPIO07_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO07_HYS_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO07_PUS_V(100K_OHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO07_PUE_V(PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO07_PKE_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO07_ODE_V(DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO07_SPEED_V(100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO07_DSE_V(40_OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO07_SRE_V(SLOW));

    // Config gpio1.GPIO1_IO08 to pad GPIO08(R5)
    // J5 - Camera Reset
    // HW_IOMUXC_SW_MUX_CTL_PAD_GPIO08_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_GPIO08_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO08(0x020E0244)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: esai signal: ESAI_TX5_RX0
    //     ALT1 (1) - Select instance: xtalosc signal: XTALOSC_REF_CLK_32K
    //     ALT2 (2) - Select instance: epit2 signal: EPIT2_OUT
    //     ALT3 (3) - Select instance: flexcan1 signal: FLEXCAN1_RX
    //     ALT4 (4) - Select instance: uart2 signal: UART2_RX_DATA
    //     ALT5 (5) - Select instance: gpio1 signal: GPIO1_IO08
    //     ALT6 (6) - Select instance: spdif signal: SPDIF_SR_CLK
    //     ALT7 (7) - Select instance: usb signal: USB_OTG_PWR_CTL_WAKE
    HW_IOMUXC_SW_MUX_CTL_PAD_GPIO08_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO08_SION_V(DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO08_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO08(0x020E0614)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SLOW
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_GPIO08_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO08_HYS_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO08_PUS_V(100K_OHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO08_PUE_V(PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO08_PKE_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO08_ODE_V(DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO08_SPEED_V(100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO08_DSE_V(40_OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO08_SRE_V(SLOW));

    // Config gpio1.GPIO1_IO09 to pad GPIO09(T2)
    // J7 - Display connector GP
    // HW_IOMUXC_SW_MUX_CTL_PAD_GPIO09_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_GPIO09_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO09(0x020E0228)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: esai signal: ESAI_RX_FS
    //     ALT1 (1) - Select instance: wdog1 signal: WDOG1_B
    //     ALT2 (2) - Select instance: kpp signal: KEY_COL6
    //     ALT3 (3) - Select instance: ccm signal: CCM_REF_EN_B
    //     ALT4 (4) - Select instance: pwm1 signal: PWM1_OUT
    //     ALT5 (5) - Select instance: gpio1 signal: GPIO1_IO09
    //     ALT6 (6) - Select instance: usdhc1 signal: SD1_WP
    HW_IOMUXC_SW_MUX_CTL_PAD_GPIO09_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO09_SION_V(DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO09_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO09(0x020E05F8)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SLOW
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_GPIO09_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO09_HYS_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO09_PUS_V(100K_OHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO09_PUE_V(PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO09_PKE_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO09_ODE_V(DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO09_SPEED_V(100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO09_DSE_V(40_OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO09_SRE_V(SLOW));

    // Config gpio1.GPIO1_IO16 to pad SD1_DATA0(A21)
    // J5 - Camera GP
    // HW_IOMUXC_SW_MUX_CTL_PAD_SD1_DATA0_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD1_DATA0(0x020E0340)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: usdhc1 signal: SD1_DATA0
    //     ALT1 (1) - Select instance: ecspi5 signal: ECSPI5_MISO
    //     ALT3 (3) - Select instance: gpt signal: GPT_CAPTURE1
    //     ALT5 (5) - Select instance: gpio1 signal: GPIO1_IO16
    HW_IOMUXC_SW_MUX_CTL_PAD_SD1_DATA0_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_SD1_DATA0_SION_V(DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_SD1_DATA0_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0(0x020E0728)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SLOW
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0_HYS_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0_PUS_V(100K_OHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0_PUE_V(PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0_PKE_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0_ODE_V(DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0_SPEED_V(100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0_DSE_V(40_OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0_SRE_V(SLOW));

    // Config gpio1.GPIO1_IO23 to pad ENET_REF_CLK(V22)
    // GRMII interrupt
    // HW_IOMUXC_SW_MUX_CTL_PAD_ENET_REF_CLK_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_ENET_REF_CLK_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_ENET_REF_CLK(0x020E01D4)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT1 (1) - Select instance: enet signal: ENET_TX_CLK
    //     ALT2 (2) - Select instance: esai signal: ESAI_RX_FS
    //     ALT5 (5) - Select instance: gpio1 signal: GPIO1_IO23
    //     ALT6 (6) - Select instance: spdif signal: SPDIF_SR_CLK
    HW_IOMUXC_SW_MUX_CTL_PAD_ENET_REF_CLK_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_ENET_REF_CLK_SION_V(DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_ENET_REF_CLK_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_ENET_REF_CLK(0x020E04E8)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SLOW
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_ENET_REF_CLK_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_REF_CLK_HYS_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_REF_CLK_PUS_V(100K_OHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_REF_CLK_PUE_V(PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_REF_CLK_PKE_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_REF_CLK_ODE_V(DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_REF_CLK_SPEED_V(100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_REF_CLK_DSE_V(40_OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_REF_CLK_SRE_V(SLOW));

    // Config gpio1.GPIO1_IO24 to pad ENET_RX_ER(W23)
    // J9 - Microphone Detect
    // HW_IOMUXC_SW_MUX_CTL_PAD_ENET_RX_ER_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_ER_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_ENET_RX_ER(0x020E01D8)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: usb signal: USB_OTG_ID
    //     ALT1 (1) - Select instance: enet signal: ENET_RX_ER
    //     ALT2 (2) - Select instance: esai signal: ESAI_RX_HF_CLK
    //     ALT3 (3) - Select instance: spdif signal: SPDIF_IN
    //     ALT4 (4) - Select instance: enet signal: ENET_1588_EVENT2_OUT
    //     ALT5 (5) - Select instance: gpio1 signal: GPIO1_IO24
    HW_IOMUXC_SW_MUX_CTL_PAD_ENET_RX_ER_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_ENET_RX_ER_SION_V(DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_ENET_RX_ER_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_ENET_RX_ER(0x020E04EC)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SLOW
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_ER_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_ER_HYS_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_ER_PUS_V(100K_OHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_ER_PUE_V(PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_ER_PKE_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_ER_ODE_V(DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_ER_SPEED_V(100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_ER_DSE_V(40_OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_ER_SRE_V(SLOW));

    // Config gpio1.GPIO1_IO25 to pad ENET_CRS_DV(U21)
    // CAN1 STNDBY
    // HW_IOMUXC_SW_MUX_CTL_PAD_ENET_CRS_DV_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_ENET_CRS_DV_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_ENET_CRS_DV(0x020E01DC)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT1 (1) - Select instance: enet signal: ENET_RX_EN
    //     ALT2 (2) - Select instance: esai signal: ESAI_TX_CLK
    //     ALT3 (3) - Select instance: spdif signal: SPDIF_EXT_CLK
    //     ALT5 (5) - Select instance: gpio1 signal: GPIO1_IO25
    HW_IOMUXC_SW_MUX_CTL_PAD_ENET_CRS_DV_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_ENET_CRS_DV_SION_V(DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_ENET_CRS_DV_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_ENET_CRS_DV(0x020E04F0)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //                 NOTE: Read Only Field
    //                 The value of this field is fixed and cannot be changed.
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SLOW
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_ENET_CRS_DV_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_CRS_DV_HYS_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_CRS_DV_PUS_V(100K_OHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_CRS_DV_PUE_V(PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_CRS_DV_PKE_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_CRS_DV_ODE_V(DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_CRS_DV_DSE_V(40_OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_CRS_DV_SRE_V(SLOW));

    // Config gpio1.GPIO1_IO26 to pad ENET_RX_DATA1(W22)
    // CAN1 NERR
    // HW_IOMUXC_SW_MUX_CTL_PAD_ENET_RX_DATA1_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA1_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_ENET_RX_DATA1(0x020E01E0)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT0 (0) - Select instance: mlb signal: MLB_SIG
    //     ALT1 (1) - Select instance: enet signal: ENET_RX_DATA1
    //     ALT2 (2) - Select instance: esai signal: ESAI_TX_FS
    //     ALT4 (4) - Select instance: enet signal: ENET_1588_EVENT3_OUT
    //     ALT5 (5) - Select instance: gpio1 signal: GPIO1_IO26
    HW_IOMUXC_SW_MUX_CTL_PAD_ENET_RX_DATA1_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_ENET_RX_DATA1_SION_V(DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_ENET_RX_DATA1_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA1(0x020E04F4)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SLOW
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA1_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA1_HYS_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA1_PUS_V(100K_OHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA1_PUE_V(PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA1_PKE_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA1_ODE_V(DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA1_SPEED_V(100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA1_DSE_V(40_OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA1_SRE_V(SLOW));

    // Config gpio1.GPIO1_IO27 to pad ENET_RX_DATA0(W21)
    // CAN1 Enable
    // HW_IOMUXC_SW_MUX_CTL_PAD_ENET_RX_DATA0_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA0_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_ENET_RX_DATA0(0x020E01E4)
    //   SION [4] - Software Input On Field Reset: DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     ENABLED (1) - Force input path of pad.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select iomux modes to be used for pad.
    //     ALT1 (1) - Select instance: enet signal: ENET_RX_DATA0
    //     ALT2 (2) - Select instance: esai signal: ESAI_TX_HF_CLK
    //     ALT3 (3) - Select instance: spdif signal: SPDIF_OUT
    //     ALT5 (5) - Select instance: gpio1 signal: GPIO1_IO27
    HW_IOMUXC_SW_MUX_CTL_PAD_ENET_RX_DATA0_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_ENET_RX_DATA0_SION_V(DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_ENET_RX_DATA0_MUX_MODE_V(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA0(0x020E04F8)
    //   HYS [16] - Hysteresis Enable Field Reset: ENABLED
    //     DISABLED (0) - CMOS input
    //     ENABLED (1) - Schmitt trigger input
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: 100K_OHM_PU
    //     100K_OHM_PD (0) - 100K Ohm Pull Down
    //     47K_OHM_PU (1) - 47K Ohm Pull Up
    //     100K_OHM_PU (2) - 100K Ohm Pull Up
    //     22K_OHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PULL
    //     KEEP (0) - Keeper Enabled
    //     PULL (1) - Pull Enabled
    //   PKE [12] - Pull / Keep Enable Field Reset: ENABLED
    //     DISABLED (0) - Pull/Keeper Disabled
    //     ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: DISABLED
    //              Enables open drain of the pin.
    //     DISABLED (0) - Output is CMOS.
    //     ENABLED (1) - Output is Open Drain.
    //   SPEED [7:6] - Speed Field Reset: 100MHZ
    //                 NOTE: Read Only Field
    //                 The value of this field is fixed and cannot be changed.
    //     TBD (0) - TBD
    //     50MHZ (1) - Low (50 MHz)
    //     100MHZ (2) - Medium (100 MHz)
    //     200MHZ (3) - Maximum (200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: 40_OHM
    //     HIZ (0) - HI-Z
    //     240_OHM (1) - 240 Ohm
    //     120_OHM (2) - 120 Ohm
    //     80_OHM (3) - 80 Ohm
    //     60_OHM (4) - 60 Ohm
    //     48_OHM (5) - 48 Ohm
    //     40_OHM (6) - 40 Ohm
    //     34_OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SLOW
    //             Slew rate control.
    //     SLOW (0) - Slow Slew Rate
    //     FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA0_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA0_HYS_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA0_PUS_V(100K_OHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA0_PUE_V(PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA0_PKE_V(ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA0_ODE_V(DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA0_DSE_V(40_OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_ENET_RX_DATA0_SRE_V(SLOW));
}
