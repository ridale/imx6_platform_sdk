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

// File: i2c3_iomux_config.c

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

// Function to configure IOMUXC for i2c3 module.
void i2c3_iomux_config(void)
{
    // Config i2c3.SCL to pad GPIO_3(R7)
    // HW_IOMUXC_SW_MUX_CTL_PAD_GPIO_3_WR(0x00000012);
    // HW_IOMUXC_I2C3_IPP_SCL_IN_SELECT_INPUT_WR(0x00000001);
    // HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_3_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO_3(0x020E022C)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad GPIO_3.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: GPIO_3.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: HCKR of instance: esai.
    //                NOTE: - Config Register IOMUXC_ESAI_IPP_IND_HCKR_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: OBSRV_INT_OUT0 of instance: observe_mux.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: SCL of instance: i2c3.
    //                NOTE: - Config Register IOMUXC_I2C3_IPP_SCL_IN_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: ANATOP_24M_OUT of instance: anatop.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: CLKO2 of instance: ccm.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[3] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: USBH1_OC of instance: usboh3.
    //                NOTE: - Config Register IOMUXC_USBOH3_IPP_IND_UH1_OC_SELECT_INPUT for mode ALT6.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: MLBCLK of instance: mlb.
    //                NOTE: - Config Register IOMUXC_MLB_MLB_CLK_IN_SELECT_INPUT for mode ALT7.
    HW_IOMUXC_SW_MUX_CTL_PAD_GPIO_3_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO_3_SION(SION_ENABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO_3_MUX_MODE(ALT2));
    // Pad GPIO_3 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_I2C3_IPP_SCL_IN_SELECT_INPUT(0x020E08A8)
    //   DAISY [1:0] Reset: SEL_EIM_D17_ALT6
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: i2c3, In Pin: ipp_scl_in
    //     SEL_EIM_D17_ALT6 (0) - Selecting Pad: EIM_D17 for Mode: ALT6.
    //     SEL_GPIO_3_ALT2 (1) - Selecting Pad: GPIO_3 for Mode: ALT2.
    //     SEL_GPIO_5_ALT6 (2) - Selecting Pad: GPIO_5 for Mode: ALT6.
    HW_IOMUXC_I2C3_IPP_SCL_IN_SELECT_INPUT_WR(
            BF_IOMUXC_I2C3_IPP_SCL_IN_SELECT_INPUT_DAISY(SEL_GPIO_3_ALT2));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO_3(0x020E05FC)
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: GPIO_3.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: GPIO_3.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: GPIO_3.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: GPIO_3.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: GPIO_3.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: GPIO_3.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: GPIO_3.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: GPIO_3.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_3_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_3_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_3_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_3_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_3_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_3_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_3_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_3_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_3_SRE(SRE_SLOW));

    // Config i2c3.SDA to pad GPIO_6(T3)
    // HW_IOMUXC_SW_MUX_CTL_PAD_GPIO_6_WR(0x00000012);
    // HW_IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT_WR(0x00000001);
    // HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_6_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO_6(0x020E0230)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad GPIO_6.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: GPIO_6.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: SCKT of instance: esai.
    //                NOTE: - Config Register IOMUXC_ESAI_IPP_IND_SCKT_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: OBSRV_INT_OUT1 of instance: observe_mux.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: SDA of instance: i2c3.
    //                NOTE: - Config Register IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: CCM_OUT_0 of instance: ccm.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: CSU_INT_DEB of instance: csu.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[6] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: LCTL of instance: usdhc2.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: MLBSIG of instance: mlb.
    //                NOTE: - Config Register IOMUXC_MLB_MLB_SIG_IN_SELECT_INPUT for mode ALT7.
    HW_IOMUXC_SW_MUX_CTL_PAD_GPIO_6_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO_6_SION(SION_ENABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO_6_MUX_MODE(ALT2));
    // Pad GPIO_6 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT(0x020E08AC)
    //   DAISY [1:0] Reset: SEL_EIM_D18_ALT6
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: i2c3, In Pin: ipp_sda_in
    //     SEL_EIM_D18_ALT6 (0) - Selecting Pad: EIM_D18 for Mode: ALT6.
    //     SEL_GPIO_6_ALT2 (1) - Selecting Pad: GPIO_6 for Mode: ALT2.
    //     SEL_GPIO_16_ALT6 (2) - Selecting Pad: GPIO_16 for Mode: ALT6.
    HW_IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT_WR(
            BF_IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT_DAISY(SEL_GPIO_6_ALT2));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO_6(0x020E0600)
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: GPIO_6.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: GPIO_6.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: GPIO_6.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: GPIO_6.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: GPIO_6.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: GPIO_6.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: GPIO_6.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: GPIO_6.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_6_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_6_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_6_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_6_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_6_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_6_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_6_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_6_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_6_SRE(SRE_SLOW));
}
