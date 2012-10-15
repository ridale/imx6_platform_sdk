/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "sdk.h"
#include "registers/regsccm.h"
#include "registers/regsccmanalog.h"
#include "registers/regspmu.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/*!
 * SATA power on
 */
void sata_power_on(void)
{
    //enable SATA_3V3 and SATA_5V with MX7310 U19 CTRL_0
#ifdef BOARD_SMART_DEVICE
    //AUX_5V_EN
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0, ALT5);
    gpio_set_direction(GPIO_PORT6, 10, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT6, 10, GPIO_HIGH_LEVEL);
#else
    //enable SATA_3V3 and SATA_5V with MX7310 CTRL_0
    max7310_set_gpio_output(1, 0, GPIO_HIGH_LEVEL);
//     sata_phy_clk_sel = CCM_PLL_ENET;
#endif
}

/*!
 * SATA power off
 */
void sata_power_off(void)
{
    //disable SATA_3V3 and SATA_5V with MX7310 U19 CTRL_0
    max7310_set_gpio_output(1, 0, GPIO_LOW_LEVEL);
}

// The external 100 MHz clock is used by SATA, which is only present on the mx6dq.
void enable_extrn_100mhz_clk(uint32_t enable)
{
    if (enable) {
        // Disable SATA clock gating used as external reference
        HW_CCM_ANALOG_PLL_ENET_SET(BM_CCM_ANALOG_PLL_ENET_ENABLE_100M);

        // Select SATA clock source and switch to output buffer.
        HW_PMU_MISC1_CLR(BM_PMU_MISC1_LVDSCLK1_IBEN);
        HW_PMU_MISC1.B.LVDS1_CLK_SEL = BV_PMU_MISC1_LVDS1_CLK_SEL__SATA_REF;
        HW_PMU_MISC1_SET(BM_PMU_MISC1_LVDSCLK1_OBEN);
    }
}

/*!
 * @brief SATA related clocks enable function
 */
void sata_clock_enable(void)
{
    // Set SATA timings     0x05932046
    reg32_write(0x020E0034, 0x05932044);
    hal_delay_us(1000);

    // Enable SATA PLL
    reg32_write(0x020E0034, 0x05932046);
    hal_delay_us(1000);

    //enable SATA_CLK in CCGR5
    clock_gating_config(SATA_BASE_ADDR, CLOCK_ON);

    //enable ENET_PLL (PLL8). done in freq_populate()
    //enale SATA_CLK in the ENET_PLL register
    HW_CCM_ANALOG_PLL_ENET_SET(BM_CCM_ANALOG_PLL_ENET_ENABLE_100M);

    //config ENET PLL div_select for SATA - 100MHz
    HW_CCM_ANALOG_PLL_ENET.B.DIV_SELECT = 0x2;  // 0b10-100MHz
}

/*!
 * @brief SATA related clocks dis function
 */
void sata_clock_disable(void)
{
    //disable SATA_CLK in CCGR5.
    clock_gating_config(SATA_BASE_ADDR, CLOCK_OFF);

    //disable ENET_PLL (PLL8)
    HW_CCM_ANALOG_PLL_ENET_CLR(BM_CCM_ANALOG_PLL_ENET_ENABLE_100M);
}

/*!
 * @brief SATA related function to get the PHY source clock
 */
void sata_get_phy_src_clk(sata_phy_ref_clk_t * phy_ref_clk)
{
    *phy_ref_clk = CCM_PLL_ENET;
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
