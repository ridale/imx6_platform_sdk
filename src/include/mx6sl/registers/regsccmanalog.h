/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_CCM_ANALOG_REGISTERS_H__
#define __HW_CCM_ANALOG_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6SL CCM_ANALOG registers defined in this header file.
 *
 * - HW_CCM_ANALOG_PLL_ARM - Analog ARM PLL control Register
 * - HW_CCM_ANALOG_PLL_USB1 - Analog USB1 480MHz PLL Control Register
 * - HW_CCM_ANALOG_PLL_USB2 - Analog USB2 480MHz PLL Control Register
 * - HW_CCM_ANALOG_PLL_SYS - Analog 528MHz System PLL Control Register
 * - HW_CCM_ANALOG_PLL_AUDIO - Analog Audio PLL control Register
 * - HW_CCM_ANALOG_PLL_AUDIO_NUM - Numerator of Audio PLL Fractional Loop Divider Register
 * - HW_CCM_ANALOG_PLL_AUDIO_DENOM - Denominator of Audio PLL Fractional Loop Divider Register
 * - HW_CCM_ANALOG_PLL_VIDEO - Analog Video PLL control Register
 * - HW_CCM_ANALOG_PLL_VIDEO_NUM - Numerator of Video PLL Fractional Loop Divider Register
 * - HW_CCM_ANALOG_PLL_VIDEO_DENOM - Denominator of Video PLL Fractional Loop Divider Register
 * - HW_CCM_ANALOG_PLL_ENET - Analog ENET PLL Control Register
 * - HW_CCM_ANALOG_PFD_480 - 480MHz Clock (from PLL_USB2) Phase Fractional Divider Control Register
 * - HW_CCM_ANALOG_PFD_528 - 528MHz Clock (From PLL_SYS) Phase Fractional Divider Control Register
 * - HW_CCM_ANALOG_MISC0 - Miscellaneous Control Register
 * - HW_CCM_ANALOG_MISC2 - Miscellaneous Control Register
 *
 * - hw_ccm_analog_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_CCM_ANALOG_BASE
#define HW_CCM_ANALOG_INSTANCE_COUNT (1) //!< Number of instances of the CCM_ANALOG module.
#define REGS_CCM_ANALOG_BASE (0x020c8000) //!< Base address for CCM_ANALOG.
#endif
//@}

// Typecast macro for C or asm. In C, the cast is applied, while in asm it is excluded. This is
// used to simplify macro definitions below.
#ifndef __REG_VALUE_TYPE
#ifndef __LANGUAGE_ASM__
#define __REG_VALUE_TYPE(v, t) ((t)(v))
#else
#define __REG_VALUE_TYPE(v, t) (v)
#endif
#endif


//-------------------------------------------------------------------------------------------
// HW_CCM_ANALOG_PLL_ARM - Analog ARM PLL control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_ARM - Analog ARM PLL control Register (RW)
 *
 * Reset value: 0x00013042
 *
 * The control register provides control for the system PLL.
 */
typedef union _hw_ccm_analog_pll_arm
{
    reg32_t U;
    struct _hw_ccm_analog_pll_arm_bitfields
    {
        unsigned DIV_SELECT : 7; //!< [6:0] This field controls the pll loop divider. Valid range for divider value: 54-108. Fout = Fin * div_select/2.0.
        unsigned HALF_LF : 1; //!< [7] Reserved by Freescale.
        unsigned DOUBLE_LF : 1; //!< [8] Reserved by Freescale.
        unsigned HALF_CP : 1; //!< [9] Reserved by Freescale.
        unsigned DOUBLE_CP : 1; //!< [10] Reserved by Freescale.
        unsigned HOLD_RING_OFF : 1; //!< [11] Analog debug bit.
        unsigned POWERDOWN : 1; //!< [12] Powers down the PLL.
        unsigned ENABLE : 1; //!< [13] Enable the clock output.
        unsigned BYPASS_CLK_SRC : 2; //!< [15:14] Determines the bypass source.
        unsigned BYPASS : 1; //!< [16] Bypass the pll.
        unsigned LVDS_SEL : 1; //!< [17] Analog Debug Bit
        unsigned LVDS_24MHZ_SEL : 1; //!< [18] Analog Debug Bit
        unsigned PLL_SEL : 1; //!< [19] Reserved
        unsigned RESERVED0 : 11; //!< [30:20] Always set to zero (0).
        unsigned LOCK : 1; //!< [31] 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_arm_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_ARM register
 */
#define HW_CCM_ANALOG_PLL_ARM_ADDR      (REGS_CCM_ANALOG_BASE + 0x0)
#define HW_CCM_ANALOG_PLL_ARM_SET_ADDR  (HW_CCM_ANALOG_PLL_ARM_ADDR + 0x4)
#define HW_CCM_ANALOG_PLL_ARM_CLR_ADDR  (HW_CCM_ANALOG_PLL_ARM_ADDR + 0x8)
#define HW_CCM_ANALOG_PLL_ARM_TOG_ADDR  (HW_CCM_ANALOG_PLL_ARM_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_ARM           (*(volatile hw_ccm_analog_pll_arm_t *) HW_CCM_ANALOG_PLL_ARM_ADDR)
#define HW_CCM_ANALOG_PLL_ARM_RD()      (HW_CCM_ANALOG_PLL_ARM.U)
#define HW_CCM_ANALOG_PLL_ARM_WR(v)     (HW_CCM_ANALOG_PLL_ARM.U = (v))
#define HW_CCM_ANALOG_PLL_ARM_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_ARM_SET_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_ARM_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_ARM_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_ARM_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_ARM_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_ARM bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_ARM, field DIV_SELECT[6:0] (RW)
 *
 * This field controls the pll loop divider. Valid range for divider value: 54-108. Fout = Fin *
 * div_select/2.0.
 */

#define BP_CCM_ANALOG_PLL_ARM_DIV_SELECT      (0)      //!< Bit position for CCM_ANALOG_PLL_ARM_DIV_SELECT.
#define BM_CCM_ANALOG_PLL_ARM_DIV_SELECT      (0x0000007f)  //!< Bit mask for CCM_ANALOG_PLL_ARM_DIV_SELECT.

//! @brief Get value of CCM_ANALOG_PLL_ARM_DIV_SELECT from a register value.
#define BG_CCM_ANALOG_PLL_ARM_DIV_SELECT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ARM_DIV_SELECT) >> BP_CCM_ANALOG_PLL_ARM_DIV_SELECT)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ARM_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_ARM_DIV_SELECT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ARM_DIV_SELECT) & BM_CCM_ANALOG_PLL_ARM_DIV_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_ARM_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_ARM, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ARM, field HALF_LF[7] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_ARM_HALF_LF      (7)      //!< Bit position for CCM_ANALOG_PLL_ARM_HALF_LF.
#define BM_CCM_ANALOG_PLL_ARM_HALF_LF      (0x00000080)  //!< Bit mask for CCM_ANALOG_PLL_ARM_HALF_LF.

//! @brief Get value of CCM_ANALOG_PLL_ARM_HALF_LF from a register value.
#define BG_CCM_ANALOG_PLL_ARM_HALF_LF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ARM_HALF_LF) >> BP_CCM_ANALOG_PLL_ARM_HALF_LF)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ARM_HALF_LF.
#define BF_CCM_ANALOG_PLL_ARM_HALF_LF(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ARM_HALF_LF) & BM_CCM_ANALOG_PLL_ARM_HALF_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_ARM_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_ARM, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ARM, field DOUBLE_LF[8] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_ARM_DOUBLE_LF      (8)      //!< Bit position for CCM_ANALOG_PLL_ARM_DOUBLE_LF.
#define BM_CCM_ANALOG_PLL_ARM_DOUBLE_LF      (0x00000100)  //!< Bit mask for CCM_ANALOG_PLL_ARM_DOUBLE_LF.

//! @brief Get value of CCM_ANALOG_PLL_ARM_DOUBLE_LF from a register value.
#define BG_CCM_ANALOG_PLL_ARM_DOUBLE_LF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ARM_DOUBLE_LF) >> BP_CCM_ANALOG_PLL_ARM_DOUBLE_LF)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ARM_DOUBLE_LF.
#define BF_CCM_ANALOG_PLL_ARM_DOUBLE_LF(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ARM_DOUBLE_LF) & BM_CCM_ANALOG_PLL_ARM_DOUBLE_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_ARM_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_ARM, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ARM, field HALF_CP[9] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_ARM_HALF_CP      (9)      //!< Bit position for CCM_ANALOG_PLL_ARM_HALF_CP.
#define BM_CCM_ANALOG_PLL_ARM_HALF_CP      (0x00000200)  //!< Bit mask for CCM_ANALOG_PLL_ARM_HALF_CP.

//! @brief Get value of CCM_ANALOG_PLL_ARM_HALF_CP from a register value.
#define BG_CCM_ANALOG_PLL_ARM_HALF_CP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ARM_HALF_CP) >> BP_CCM_ANALOG_PLL_ARM_HALF_CP)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ARM_HALF_CP.
#define BF_CCM_ANALOG_PLL_ARM_HALF_CP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ARM_HALF_CP) & BM_CCM_ANALOG_PLL_ARM_HALF_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_ARM_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_ARM, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ARM, field DOUBLE_CP[10] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_ARM_DOUBLE_CP      (10)      //!< Bit position for CCM_ANALOG_PLL_ARM_DOUBLE_CP.
#define BM_CCM_ANALOG_PLL_ARM_DOUBLE_CP      (0x00000400)  //!< Bit mask for CCM_ANALOG_PLL_ARM_DOUBLE_CP.

//! @brief Get value of CCM_ANALOG_PLL_ARM_DOUBLE_CP from a register value.
#define BG_CCM_ANALOG_PLL_ARM_DOUBLE_CP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ARM_DOUBLE_CP) >> BP_CCM_ANALOG_PLL_ARM_DOUBLE_CP)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ARM_DOUBLE_CP.
#define BF_CCM_ANALOG_PLL_ARM_DOUBLE_CP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ARM_DOUBLE_CP) & BM_CCM_ANALOG_PLL_ARM_DOUBLE_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_ARM_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_ARM, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ARM, field HOLD_RING_OFF[11] (RW)
 *
 * Analog debug bit.
 */

#define BP_CCM_ANALOG_PLL_ARM_HOLD_RING_OFF      (11)      //!< Bit position for CCM_ANALOG_PLL_ARM_HOLD_RING_OFF.
#define BM_CCM_ANALOG_PLL_ARM_HOLD_RING_OFF      (0x00000800)  //!< Bit mask for CCM_ANALOG_PLL_ARM_HOLD_RING_OFF.

//! @brief Get value of CCM_ANALOG_PLL_ARM_HOLD_RING_OFF from a register value.
#define BG_CCM_ANALOG_PLL_ARM_HOLD_RING_OFF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ARM_HOLD_RING_OFF) >> BP_CCM_ANALOG_PLL_ARM_HOLD_RING_OFF)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ARM_HOLD_RING_OFF.
#define BF_CCM_ANALOG_PLL_ARM_HOLD_RING_OFF(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ARM_HOLD_RING_OFF) & BM_CCM_ANALOG_PLL_ARM_HOLD_RING_OFF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_ARM_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_ARM, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ARM, field POWERDOWN[12] (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_ARM_POWERDOWN      (12)      //!< Bit position for CCM_ANALOG_PLL_ARM_POWERDOWN.
#define BM_CCM_ANALOG_PLL_ARM_POWERDOWN      (0x00001000)  //!< Bit mask for CCM_ANALOG_PLL_ARM_POWERDOWN.

//! @brief Get value of CCM_ANALOG_PLL_ARM_POWERDOWN from a register value.
#define BG_CCM_ANALOG_PLL_ARM_POWERDOWN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ARM_POWERDOWN) >> BP_CCM_ANALOG_PLL_ARM_POWERDOWN)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ARM_POWERDOWN.
#define BF_CCM_ANALOG_PLL_ARM_POWERDOWN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ARM_POWERDOWN) & BM_CCM_ANALOG_PLL_ARM_POWERDOWN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_ARM_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_ARM, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ARM, field ENABLE[13] (RW)
 *
 * Enable the clock output.
 */

#define BP_CCM_ANALOG_PLL_ARM_ENABLE      (13)      //!< Bit position for CCM_ANALOG_PLL_ARM_ENABLE.
#define BM_CCM_ANALOG_PLL_ARM_ENABLE      (0x00002000)  //!< Bit mask for CCM_ANALOG_PLL_ARM_ENABLE.

//! @brief Get value of CCM_ANALOG_PLL_ARM_ENABLE from a register value.
#define BG_CCM_ANALOG_PLL_ARM_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ARM_ENABLE) >> BP_CCM_ANALOG_PLL_ARM_ENABLE)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ARM_ENABLE.
#define BF_CCM_ANALOG_PLL_ARM_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ARM_ENABLE) & BM_CCM_ANALOG_PLL_ARM_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_ARM_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_ARM, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ARM, field BYPASS_CLK_SRC[15:14] (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * RESERVED = 0x2 - 
 * RESERVED = 0x3 - 
 */

#define BP_CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC      (14)      //!< Bit position for CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC.
#define BM_CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC      (0x0000c000)  //!< Bit mask for CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC.

//! @brief Get value of CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC from a register value.
#define BG_CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC) >> BP_CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC.
#define BF_CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC) & BM_CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_ARM, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC__OSC_24M (0x0) //!< Select the 24MHz oscillator as source.
#define BV_CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC__ANACLK_1 (0x1) //!< Select the Anaclk1/1b as source.
#define BV_CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC__RESERVED (0x2) //!< 
#define BV_CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC__RESERVED (0x3) //!< 

/* --- Register HW_CCM_ANALOG_PLL_ARM, field BYPASS[16] (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_ARM_BYPASS      (16)      //!< Bit position for CCM_ANALOG_PLL_ARM_BYPASS.
#define BM_CCM_ANALOG_PLL_ARM_BYPASS      (0x00010000)  //!< Bit mask for CCM_ANALOG_PLL_ARM_BYPASS.

//! @brief Get value of CCM_ANALOG_PLL_ARM_BYPASS from a register value.
#define BG_CCM_ANALOG_PLL_ARM_BYPASS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ARM_BYPASS) >> BP_CCM_ANALOG_PLL_ARM_BYPASS)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ARM_BYPASS.
#define BF_CCM_ANALOG_PLL_ARM_BYPASS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ARM_BYPASS) & BM_CCM_ANALOG_PLL_ARM_BYPASS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_ARM_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_ARM, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ARM, field LVDS_SEL[17] (RW)
 *
 * Analog Debug Bit
 */

#define BP_CCM_ANALOG_PLL_ARM_LVDS_SEL      (17)      //!< Bit position for CCM_ANALOG_PLL_ARM_LVDS_SEL.
#define BM_CCM_ANALOG_PLL_ARM_LVDS_SEL      (0x00020000)  //!< Bit mask for CCM_ANALOG_PLL_ARM_LVDS_SEL.

//! @brief Get value of CCM_ANALOG_PLL_ARM_LVDS_SEL from a register value.
#define BG_CCM_ANALOG_PLL_ARM_LVDS_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ARM_LVDS_SEL) >> BP_CCM_ANALOG_PLL_ARM_LVDS_SEL)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ARM_LVDS_SEL.
#define BF_CCM_ANALOG_PLL_ARM_LVDS_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ARM_LVDS_SEL) & BM_CCM_ANALOG_PLL_ARM_LVDS_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_ARM_LVDS_SEL(v)   BF_CS1(CCM_ANALOG_PLL_ARM, LVDS_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ARM, field LVDS_24MHZ_SEL[18] (RW)
 *
 * Analog Debug Bit
 */

#define BP_CCM_ANALOG_PLL_ARM_LVDS_24MHZ_SEL      (18)      //!< Bit position for CCM_ANALOG_PLL_ARM_LVDS_24MHZ_SEL.
#define BM_CCM_ANALOG_PLL_ARM_LVDS_24MHZ_SEL      (0x00040000)  //!< Bit mask for CCM_ANALOG_PLL_ARM_LVDS_24MHZ_SEL.

//! @brief Get value of CCM_ANALOG_PLL_ARM_LVDS_24MHZ_SEL from a register value.
#define BG_CCM_ANALOG_PLL_ARM_LVDS_24MHZ_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ARM_LVDS_24MHZ_SEL) >> BP_CCM_ANALOG_PLL_ARM_LVDS_24MHZ_SEL)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ARM_LVDS_24MHZ_SEL.
#define BF_CCM_ANALOG_PLL_ARM_LVDS_24MHZ_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ARM_LVDS_24MHZ_SEL) & BM_CCM_ANALOG_PLL_ARM_LVDS_24MHZ_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LVDS_24MHZ_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_ARM_LVDS_24MHZ_SEL(v)   BF_CS1(CCM_ANALOG_PLL_ARM, LVDS_24MHZ_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ARM, field PLL_SEL[19] (RW)
 *
 * Reserved
 */

#define BP_CCM_ANALOG_PLL_ARM_PLL_SEL      (19)      //!< Bit position for CCM_ANALOG_PLL_ARM_PLL_SEL.
#define BM_CCM_ANALOG_PLL_ARM_PLL_SEL      (0x00080000)  //!< Bit mask for CCM_ANALOG_PLL_ARM_PLL_SEL.

//! @brief Get value of CCM_ANALOG_PLL_ARM_PLL_SEL from a register value.
#define BG_CCM_ANALOG_PLL_ARM_PLL_SEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ARM_PLL_SEL) >> BP_CCM_ANALOG_PLL_ARM_PLL_SEL)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ARM_PLL_SEL.
#define BF_CCM_ANALOG_PLL_ARM_PLL_SEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ARM_PLL_SEL) & BM_CCM_ANALOG_PLL_ARM_PLL_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL_SEL field to a new value.
#define BW_CCM_ANALOG_PLL_ARM_PLL_SEL(v)   BF_CS1(CCM_ANALOG_PLL_ARM, PLL_SEL, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ARM, field LOCK[31] (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_ARM_LOCK      (31)      //!< Bit position for CCM_ANALOG_PLL_ARM_LOCK.
#define BM_CCM_ANALOG_PLL_ARM_LOCK      (0x80000000)  //!< Bit mask for CCM_ANALOG_PLL_ARM_LOCK.

//! @brief Get value of CCM_ANALOG_PLL_ARM_LOCK from a register value.
#define BG_CCM_ANALOG_PLL_ARM_LOCK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ARM_LOCK) >> BP_CCM_ANALOG_PLL_ARM_LOCK)

//-------------------------------------------------------------------------------------------
// HW_CCM_ANALOG_PLL_USB1 - Analog USB1 480MHz PLL Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_USB1 - Analog USB1 480MHz PLL Control Register (RW)
 *
 * Reset value: 0x00012000
 *
 * The control register provides control for USBPHY0 480MHz PLL.
 */
typedef union _hw_ccm_analog_pll_usb1
{
    reg32_t U;
    struct _hw_ccm_analog_pll_usb1_bitfields
    {
        unsigned DIV_SELECT : 2; //!< [1:0] This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
        unsigned RESERVED0 : 4; //!< [5:2] Always set to zero (0).
        unsigned EN_USB_CLKS : 1; //!< [6] Powers the 9-phase PLL outputs for USBPHYn. Additionally, the UTMI clock gate must be deasserted in the USBPHYn to enable USBn operation (clear CLKGATE bit in USBPHYn_CTRL). This bit will be set automatically when USBPHYn remote wakeup event occurs.
        unsigned RESERVED1 : 5; //!< [11:7] Always set to zero (0).
        unsigned POWER : 1; //!< [12] Powers up the PLL. This bit will be set automatically when USBPHY0 remote wakeup event happens.
        unsigned ENABLE : 1; //!< [13] Enable the PLL clock output.
        unsigned RESERVED2 : 17; //!< [30:14] Always set to zero (0).
        unsigned LOCK : 1; //!< [31] 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_usb1_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_USB1 register
 */
#define HW_CCM_ANALOG_PLL_USB1_ADDR      (REGS_CCM_ANALOG_BASE + 0x10)
#define HW_CCM_ANALOG_PLL_USB1_SET_ADDR  (HW_CCM_ANALOG_PLL_USB1_ADDR + 0x4)
#define HW_CCM_ANALOG_PLL_USB1_CLR_ADDR  (HW_CCM_ANALOG_PLL_USB1_ADDR + 0x8)
#define HW_CCM_ANALOG_PLL_USB1_TOG_ADDR  (HW_CCM_ANALOG_PLL_USB1_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_USB1           (*(volatile hw_ccm_analog_pll_usb1_t *) HW_CCM_ANALOG_PLL_USB1_ADDR)
#define HW_CCM_ANALOG_PLL_USB1_RD()      (HW_CCM_ANALOG_PLL_USB1.U)
#define HW_CCM_ANALOG_PLL_USB1_WR(v)     (HW_CCM_ANALOG_PLL_USB1.U = (v))
#define HW_CCM_ANALOG_PLL_USB1_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_USB1_SET_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_USB1_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_USB1_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_USB1_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_USB1_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_USB1 bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_USB1, field DIV_SELECT[1:0] (RW)
 *
 * This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
 */

#define BP_CCM_ANALOG_PLL_USB1_DIV_SELECT      (0)      //!< Bit position for CCM_ANALOG_PLL_USB1_DIV_SELECT.
#define BM_CCM_ANALOG_PLL_USB1_DIV_SELECT      (0x00000003)  //!< Bit mask for CCM_ANALOG_PLL_USB1_DIV_SELECT.

//! @brief Get value of CCM_ANALOG_PLL_USB1_DIV_SELECT from a register value.
#define BG_CCM_ANALOG_PLL_USB1_DIV_SELECT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_USB1_DIV_SELECT) >> BP_CCM_ANALOG_PLL_USB1_DIV_SELECT)

//! @brief Format value for bitfield CCM_ANALOG_PLL_USB1_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_USB1_DIV_SELECT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_USB1_DIV_SELECT) & BM_CCM_ANALOG_PLL_USB1_DIV_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_USB1_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_USB1, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_USB1, field EN_USB_CLKS[6] (RW)
 *
 * Powers the 9-phase PLL outputs for USBPHYn. Additionally, the UTMI clock gate must be deasserted
 * in the USBPHYn to enable USBn operation (clear CLKGATE bit in USBPHYn_CTRL). This bit will be set
 * automatically when USBPHYn remote wakeup event occurs.
 *
 * Values:
 * 0 - PLL outputs for USBPHYn off.
 * 1 - PLL outputs for USBPHYn on.
 */

#define BP_CCM_ANALOG_PLL_USB1_EN_USB_CLKS      (6)      //!< Bit position for CCM_ANALOG_PLL_USB1_EN_USB_CLKS.
#define BM_CCM_ANALOG_PLL_USB1_EN_USB_CLKS      (0x00000040)  //!< Bit mask for CCM_ANALOG_PLL_USB1_EN_USB_CLKS.

//! @brief Get value of CCM_ANALOG_PLL_USB1_EN_USB_CLKS from a register value.
#define BG_CCM_ANALOG_PLL_USB1_EN_USB_CLKS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_USB1_EN_USB_CLKS) >> BP_CCM_ANALOG_PLL_USB1_EN_USB_CLKS)

//! @brief Format value for bitfield CCM_ANALOG_PLL_USB1_EN_USB_CLKS.
#define BF_CCM_ANALOG_PLL_USB1_EN_USB_CLKS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_USB1_EN_USB_CLKS) & BM_CCM_ANALOG_PLL_USB1_EN_USB_CLKS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_USB_CLKS field to a new value.
#define BW_CCM_ANALOG_PLL_USB1_EN_USB_CLKS(v)   BF_CS1(CCM_ANALOG_PLL_USB1, EN_USB_CLKS, v)
#endif


/* --- Register HW_CCM_ANALOG_PLL_USB1, field POWER[12] (RW)
 *
 * Powers up the PLL. This bit will be set automatically when USBPHY0 remote wakeup event happens.
 */

#define BP_CCM_ANALOG_PLL_USB1_POWER      (12)      //!< Bit position for CCM_ANALOG_PLL_USB1_POWER.
#define BM_CCM_ANALOG_PLL_USB1_POWER      (0x00001000)  //!< Bit mask for CCM_ANALOG_PLL_USB1_POWER.

//! @brief Get value of CCM_ANALOG_PLL_USB1_POWER from a register value.
#define BG_CCM_ANALOG_PLL_USB1_POWER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_USB1_POWER) >> BP_CCM_ANALOG_PLL_USB1_POWER)

//! @brief Format value for bitfield CCM_ANALOG_PLL_USB1_POWER.
#define BF_CCM_ANALOG_PLL_USB1_POWER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_USB1_POWER) & BM_CCM_ANALOG_PLL_USB1_POWER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER field to a new value.
#define BW_CCM_ANALOG_PLL_USB1_POWER(v)   BF_CS1(CCM_ANALOG_PLL_USB1, POWER, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_USB1, field ENABLE[13] (RW)
 *
 * Enable the PLL clock output.
 */

#define BP_CCM_ANALOG_PLL_USB1_ENABLE      (13)      //!< Bit position for CCM_ANALOG_PLL_USB1_ENABLE.
#define BM_CCM_ANALOG_PLL_USB1_ENABLE      (0x00002000)  //!< Bit mask for CCM_ANALOG_PLL_USB1_ENABLE.

//! @brief Get value of CCM_ANALOG_PLL_USB1_ENABLE from a register value.
#define BG_CCM_ANALOG_PLL_USB1_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_USB1_ENABLE) >> BP_CCM_ANALOG_PLL_USB1_ENABLE)

//! @brief Format value for bitfield CCM_ANALOG_PLL_USB1_ENABLE.
#define BF_CCM_ANALOG_PLL_USB1_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_USB1_ENABLE) & BM_CCM_ANALOG_PLL_USB1_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_USB1_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_USB1, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_USB1, field LOCK[31] (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_USB1_LOCK      (31)      //!< Bit position for CCM_ANALOG_PLL_USB1_LOCK.
#define BM_CCM_ANALOG_PLL_USB1_LOCK      (0x80000000)  //!< Bit mask for CCM_ANALOG_PLL_USB1_LOCK.

//! @brief Get value of CCM_ANALOG_PLL_USB1_LOCK from a register value.
#define BG_CCM_ANALOG_PLL_USB1_LOCK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_USB1_LOCK) >> BP_CCM_ANALOG_PLL_USB1_LOCK)

//-------------------------------------------------------------------------------------------
// HW_CCM_ANALOG_PLL_USB2 - Analog USB2 480MHz PLL Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_USB2 - Analog USB2 480MHz PLL Control Register (RW)
 *
 * Reset value: 0x00012000
 *
 * The control register provides control for USBPHY1 480MHz PLL.
 */
typedef union _hw_ccm_analog_pll_usb2
{
    reg32_t U;
    struct _hw_ccm_analog_pll_usb2_bitfields
    {
        unsigned DIV_SELECT : 2; //!< [1:0] This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
        unsigned RESERVED0 : 4; //!< [5:2] Always set to zero (0).
        unsigned EN_USB_CLKS : 1; //!< [6] 0: 8-phase PLL outputs for USBPHY1 are powered down. If set to 1, 8-phase PLL outputs for USBPHY1 are powered up. Additionally, the utmi clock gate must be deasserted in the USBPHY1 to enable USB0 operation (clear CLKGATE bit in USBPHY1_CTRL).This bit will be set automatically when USBPHY1 remote wakeup event happens.
        unsigned RESERVED1 : 5; //!< [11:7] Always set to zero (0).
        unsigned POWER : 1; //!< [12] Powers up the PLL. This bit will be set automatically when USBPHY1 remote wakeup event happens.
        unsigned ENABLE : 1; //!< [13] Enable the PLL clock output.
        unsigned RESERVED2 : 17; //!< [30:14] Always set to zero (0).
        unsigned LOCK : 1; //!< [31] 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_usb2_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_USB2 register
 */
#define HW_CCM_ANALOG_PLL_USB2_ADDR      (REGS_CCM_ANALOG_BASE + 0x20)
#define HW_CCM_ANALOG_PLL_USB2_SET_ADDR  (HW_CCM_ANALOG_PLL_USB2_ADDR + 0x4)
#define HW_CCM_ANALOG_PLL_USB2_CLR_ADDR  (HW_CCM_ANALOG_PLL_USB2_ADDR + 0x8)
#define HW_CCM_ANALOG_PLL_USB2_TOG_ADDR  (HW_CCM_ANALOG_PLL_USB2_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_USB2           (*(volatile hw_ccm_analog_pll_usb2_t *) HW_CCM_ANALOG_PLL_USB2_ADDR)
#define HW_CCM_ANALOG_PLL_USB2_RD()      (HW_CCM_ANALOG_PLL_USB2.U)
#define HW_CCM_ANALOG_PLL_USB2_WR(v)     (HW_CCM_ANALOG_PLL_USB2.U = (v))
#define HW_CCM_ANALOG_PLL_USB2_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_USB2_SET_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_USB2_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_USB2_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_USB2_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_USB2_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_USB2 bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_USB2, field DIV_SELECT[1:0] (RW)
 *
 * This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
 */

#define BP_CCM_ANALOG_PLL_USB2_DIV_SELECT      (0)      //!< Bit position for CCM_ANALOG_PLL_USB2_DIV_SELECT.
#define BM_CCM_ANALOG_PLL_USB2_DIV_SELECT      (0x00000003)  //!< Bit mask for CCM_ANALOG_PLL_USB2_DIV_SELECT.

//! @brief Get value of CCM_ANALOG_PLL_USB2_DIV_SELECT from a register value.
#define BG_CCM_ANALOG_PLL_USB2_DIV_SELECT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_USB2_DIV_SELECT) >> BP_CCM_ANALOG_PLL_USB2_DIV_SELECT)

//! @brief Format value for bitfield CCM_ANALOG_PLL_USB2_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_USB2_DIV_SELECT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_USB2_DIV_SELECT) & BM_CCM_ANALOG_PLL_USB2_DIV_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_USB2_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_USB2, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_USB2, field EN_USB_CLKS[6] (RW)
 *
 * 0: 8-phase PLL outputs for USBPHY1 are powered down. If set to 1, 8-phase PLL outputs for USBPHY1
 * are powered up. Additionally, the utmi clock gate must be deasserted in the USBPHY1 to enable
 * USB0 operation (clear CLKGATE bit in USBPHY1_CTRL).This bit will be set automatically when
 * USBPHY1 remote wakeup event happens.
 */

#define BP_CCM_ANALOG_PLL_USB2_EN_USB_CLKS      (6)      //!< Bit position for CCM_ANALOG_PLL_USB2_EN_USB_CLKS.
#define BM_CCM_ANALOG_PLL_USB2_EN_USB_CLKS      (0x00000040)  //!< Bit mask for CCM_ANALOG_PLL_USB2_EN_USB_CLKS.

//! @brief Get value of CCM_ANALOG_PLL_USB2_EN_USB_CLKS from a register value.
#define BG_CCM_ANALOG_PLL_USB2_EN_USB_CLKS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_USB2_EN_USB_CLKS) >> BP_CCM_ANALOG_PLL_USB2_EN_USB_CLKS)

//! @brief Format value for bitfield CCM_ANALOG_PLL_USB2_EN_USB_CLKS.
#define BF_CCM_ANALOG_PLL_USB2_EN_USB_CLKS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_USB2_EN_USB_CLKS) & BM_CCM_ANALOG_PLL_USB2_EN_USB_CLKS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_USB_CLKS field to a new value.
#define BW_CCM_ANALOG_PLL_USB2_EN_USB_CLKS(v)   BF_CS1(CCM_ANALOG_PLL_USB2, EN_USB_CLKS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_USB2, field POWER[12] (RW)
 *
 * Powers up the PLL. This bit will be set automatically when USBPHY1 remote wakeup event happens.
 */

#define BP_CCM_ANALOG_PLL_USB2_POWER      (12)      //!< Bit position for CCM_ANALOG_PLL_USB2_POWER.
#define BM_CCM_ANALOG_PLL_USB2_POWER      (0x00001000)  //!< Bit mask for CCM_ANALOG_PLL_USB2_POWER.

//! @brief Get value of CCM_ANALOG_PLL_USB2_POWER from a register value.
#define BG_CCM_ANALOG_PLL_USB2_POWER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_USB2_POWER) >> BP_CCM_ANALOG_PLL_USB2_POWER)

//! @brief Format value for bitfield CCM_ANALOG_PLL_USB2_POWER.
#define BF_CCM_ANALOG_PLL_USB2_POWER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_USB2_POWER) & BM_CCM_ANALOG_PLL_USB2_POWER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER field to a new value.
#define BW_CCM_ANALOG_PLL_USB2_POWER(v)   BF_CS1(CCM_ANALOG_PLL_USB2, POWER, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_USB2, field ENABLE[13] (RW)
 *
 * Enable the PLL clock output.
 */

#define BP_CCM_ANALOG_PLL_USB2_ENABLE      (13)      //!< Bit position for CCM_ANALOG_PLL_USB2_ENABLE.
#define BM_CCM_ANALOG_PLL_USB2_ENABLE      (0x00002000)  //!< Bit mask for CCM_ANALOG_PLL_USB2_ENABLE.

//! @brief Get value of CCM_ANALOG_PLL_USB2_ENABLE from a register value.
#define BG_CCM_ANALOG_PLL_USB2_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_USB2_ENABLE) >> BP_CCM_ANALOG_PLL_USB2_ENABLE)

//! @brief Format value for bitfield CCM_ANALOG_PLL_USB2_ENABLE.
#define BF_CCM_ANALOG_PLL_USB2_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_USB2_ENABLE) & BM_CCM_ANALOG_PLL_USB2_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_USB2_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_USB2, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_USB2, field LOCK[31] (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_USB2_LOCK      (31)      //!< Bit position for CCM_ANALOG_PLL_USB2_LOCK.
#define BM_CCM_ANALOG_PLL_USB2_LOCK      (0x80000000)  //!< Bit mask for CCM_ANALOG_PLL_USB2_LOCK.

//! @brief Get value of CCM_ANALOG_PLL_USB2_LOCK from a register value.
#define BG_CCM_ANALOG_PLL_USB2_LOCK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_USB2_LOCK) >> BP_CCM_ANALOG_PLL_USB2_LOCK)

//-------------------------------------------------------------------------------------------
// HW_CCM_ANALOG_PLL_SYS - Analog 528MHz System PLL Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_SYS - Analog 528MHz System PLL Control Register (RW)
 *
 * Reset value: 0x00013001
 *
 * The control register provides control for the 528MHz PLL.
 */
typedef union _hw_ccm_analog_pll_sys
{
    reg32_t U;
    struct _hw_ccm_analog_pll_sys_bitfields
    {
        unsigned DIV_SELECT : 1; //!< [0] This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
        unsigned RESERVED0 : 6; //!< [6:1] Always set to zero (0).
        unsigned HALF_LF : 1; //!< [7] Reserved by Freescale
        unsigned DOUBLE_LF : 1; //!< [8] Reserved by Freescale
        unsigned HALF_CP : 1; //!< [9] Reserved by Freescale
        unsigned DOUBLE_CP : 1; //!< [10] Reserved by Freescale
        unsigned HOLD_RING_OFF : 1; //!< [11] Analog Debug bit.
        unsigned POWERDOWN : 1; //!< [12] Powers down the PLL.
        unsigned ENABLE : 1; //!< [13] Enable PLL output
        unsigned BYPASS_CLK_SRC : 2; //!< [15:14] Determines the bypass source.
        unsigned BYPASS : 1; //!< [16] Bypass the pll.
        unsigned RESERVED1 : 1; //!< [17] Reserved
        unsigned PFD_OFFSET_EN : 1; //!< [18] Enables an offset in the phase frequency detector.
        unsigned RESERVED2 : 12; //!< [30:19] Always set to zero (0).
        unsigned LOCK : 1; //!< [31] 1 - PLL is currently locked; 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_sys_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_SYS register
 */
#define HW_CCM_ANALOG_PLL_SYS_ADDR      (REGS_CCM_ANALOG_BASE + 0x30)
#define HW_CCM_ANALOG_PLL_SYS_SET_ADDR  (HW_CCM_ANALOG_PLL_SYS_ADDR + 0x4)
#define HW_CCM_ANALOG_PLL_SYS_CLR_ADDR  (HW_CCM_ANALOG_PLL_SYS_ADDR + 0x8)
#define HW_CCM_ANALOG_PLL_SYS_TOG_ADDR  (HW_CCM_ANALOG_PLL_SYS_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_SYS           (*(volatile hw_ccm_analog_pll_sys_t *) HW_CCM_ANALOG_PLL_SYS_ADDR)
#define HW_CCM_ANALOG_PLL_SYS_RD()      (HW_CCM_ANALOG_PLL_SYS.U)
#define HW_CCM_ANALOG_PLL_SYS_WR(v)     (HW_CCM_ANALOG_PLL_SYS.U = (v))
#define HW_CCM_ANALOG_PLL_SYS_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_SYS_SET_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_SYS_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_SYS_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_SYS_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_SYS_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_SYS bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_SYS, field DIV_SELECT[0] (RW)
 *
 * This field controls the pll loop divider. 0 - Fout=Fref*20; 1 - Fout=Fref*22.
 */

#define BP_CCM_ANALOG_PLL_SYS_DIV_SELECT      (0)      //!< Bit position for CCM_ANALOG_PLL_SYS_DIV_SELECT.
#define BM_CCM_ANALOG_PLL_SYS_DIV_SELECT      (0x00000001)  //!< Bit mask for CCM_ANALOG_PLL_SYS_DIV_SELECT.

//! @brief Get value of CCM_ANALOG_PLL_SYS_DIV_SELECT from a register value.
#define BG_CCM_ANALOG_PLL_SYS_DIV_SELECT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_SYS_DIV_SELECT) >> BP_CCM_ANALOG_PLL_SYS_DIV_SELECT)

//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_SYS_DIV_SELECT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_SYS_DIV_SELECT) & BM_CCM_ANALOG_PLL_SYS_DIV_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_SYS, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field HALF_LF[7] (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_SYS_HALF_LF      (7)      //!< Bit position for CCM_ANALOG_PLL_SYS_HALF_LF.
#define BM_CCM_ANALOG_PLL_SYS_HALF_LF      (0x00000080)  //!< Bit mask for CCM_ANALOG_PLL_SYS_HALF_LF.

//! @brief Get value of CCM_ANALOG_PLL_SYS_HALF_LF from a register value.
#define BG_CCM_ANALOG_PLL_SYS_HALF_LF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_SYS_HALF_LF) >> BP_CCM_ANALOG_PLL_SYS_HALF_LF)

//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_HALF_LF.
#define BF_CCM_ANALOG_PLL_SYS_HALF_LF(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_SYS_HALF_LF) & BM_CCM_ANALOG_PLL_SYS_HALF_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_SYS, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field DOUBLE_LF[8] (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_SYS_DOUBLE_LF      (8)      //!< Bit position for CCM_ANALOG_PLL_SYS_DOUBLE_LF.
#define BM_CCM_ANALOG_PLL_SYS_DOUBLE_LF      (0x00000100)  //!< Bit mask for CCM_ANALOG_PLL_SYS_DOUBLE_LF.

//! @brief Get value of CCM_ANALOG_PLL_SYS_DOUBLE_LF from a register value.
#define BG_CCM_ANALOG_PLL_SYS_DOUBLE_LF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_SYS_DOUBLE_LF) >> BP_CCM_ANALOG_PLL_SYS_DOUBLE_LF)

//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_DOUBLE_LF.
#define BF_CCM_ANALOG_PLL_SYS_DOUBLE_LF(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_SYS_DOUBLE_LF) & BM_CCM_ANALOG_PLL_SYS_DOUBLE_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_SYS, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field HALF_CP[9] (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_SYS_HALF_CP      (9)      //!< Bit position for CCM_ANALOG_PLL_SYS_HALF_CP.
#define BM_CCM_ANALOG_PLL_SYS_HALF_CP      (0x00000200)  //!< Bit mask for CCM_ANALOG_PLL_SYS_HALF_CP.

//! @brief Get value of CCM_ANALOG_PLL_SYS_HALF_CP from a register value.
#define BG_CCM_ANALOG_PLL_SYS_HALF_CP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_SYS_HALF_CP) >> BP_CCM_ANALOG_PLL_SYS_HALF_CP)

//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_HALF_CP.
#define BF_CCM_ANALOG_PLL_SYS_HALF_CP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_SYS_HALF_CP) & BM_CCM_ANALOG_PLL_SYS_HALF_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_SYS, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field DOUBLE_CP[10] (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_SYS_DOUBLE_CP      (10)      //!< Bit position for CCM_ANALOG_PLL_SYS_DOUBLE_CP.
#define BM_CCM_ANALOG_PLL_SYS_DOUBLE_CP      (0x00000400)  //!< Bit mask for CCM_ANALOG_PLL_SYS_DOUBLE_CP.

//! @brief Get value of CCM_ANALOG_PLL_SYS_DOUBLE_CP from a register value.
#define BG_CCM_ANALOG_PLL_SYS_DOUBLE_CP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_SYS_DOUBLE_CP) >> BP_CCM_ANALOG_PLL_SYS_DOUBLE_CP)

//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_DOUBLE_CP.
#define BF_CCM_ANALOG_PLL_SYS_DOUBLE_CP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_SYS_DOUBLE_CP) & BM_CCM_ANALOG_PLL_SYS_DOUBLE_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_SYS, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field HOLD_RING_OFF[11] (RW)
 *
 * Analog Debug bit.
 */

#define BP_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF      (11)      //!< Bit position for CCM_ANALOG_PLL_SYS_HOLD_RING_OFF.
#define BM_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF      (0x00000800)  //!< Bit mask for CCM_ANALOG_PLL_SYS_HOLD_RING_OFF.

//! @brief Get value of CCM_ANALOG_PLL_SYS_HOLD_RING_OFF from a register value.
#define BG_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF) >> BP_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF)

//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_HOLD_RING_OFF.
#define BF_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF) & BM_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_SYS, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field POWERDOWN[12] (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_SYS_POWERDOWN      (12)      //!< Bit position for CCM_ANALOG_PLL_SYS_POWERDOWN.
#define BM_CCM_ANALOG_PLL_SYS_POWERDOWN      (0x00001000)  //!< Bit mask for CCM_ANALOG_PLL_SYS_POWERDOWN.

//! @brief Get value of CCM_ANALOG_PLL_SYS_POWERDOWN from a register value.
#define BG_CCM_ANALOG_PLL_SYS_POWERDOWN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_SYS_POWERDOWN) >> BP_CCM_ANALOG_PLL_SYS_POWERDOWN)

//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_POWERDOWN.
#define BF_CCM_ANALOG_PLL_SYS_POWERDOWN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_SYS_POWERDOWN) & BM_CCM_ANALOG_PLL_SYS_POWERDOWN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_SYS, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field ENABLE[13] (RW)
 *
 * Enable PLL output
 */

#define BP_CCM_ANALOG_PLL_SYS_ENABLE      (13)      //!< Bit position for CCM_ANALOG_PLL_SYS_ENABLE.
#define BM_CCM_ANALOG_PLL_SYS_ENABLE      (0x00002000)  //!< Bit mask for CCM_ANALOG_PLL_SYS_ENABLE.

//! @brief Get value of CCM_ANALOG_PLL_SYS_ENABLE from a register value.
#define BG_CCM_ANALOG_PLL_SYS_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_SYS_ENABLE) >> BP_CCM_ANALOG_PLL_SYS_ENABLE)

//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_ENABLE.
#define BF_CCM_ANALOG_PLL_SYS_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_SYS_ENABLE) & BM_CCM_ANALOG_PLL_SYS_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_SYS, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field BYPASS_CLK_SRC[15:14] (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * GPANAIO = 0x2 - 
 * CHRG_DET_B = 0x3 - 
 */

#define BP_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC      (14)      //!< Bit position for CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC.
#define BM_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC      (0x0000c000)  //!< Bit mask for CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC.

//! @brief Get value of CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC from a register value.
#define BG_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC) >> BP_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC)

//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC.
#define BF_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC) & BM_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_SYS, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC__OSC_24M (0x0) //!< Select the 24MHz oscillator as source.
#define BV_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC__ANACLK_1 (0x1) //!< Select the Anaclk1/1b as source.
#define BV_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC__GPANAIO (0x2) //!< 
#define BV_CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC__CHRG_DET_B (0x3) //!< 

/* --- Register HW_CCM_ANALOG_PLL_SYS, field BYPASS[16] (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_SYS_BYPASS      (16)      //!< Bit position for CCM_ANALOG_PLL_SYS_BYPASS.
#define BM_CCM_ANALOG_PLL_SYS_BYPASS      (0x00010000)  //!< Bit mask for CCM_ANALOG_PLL_SYS_BYPASS.

//! @brief Get value of CCM_ANALOG_PLL_SYS_BYPASS from a register value.
#define BG_CCM_ANALOG_PLL_SYS_BYPASS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_SYS_BYPASS) >> BP_CCM_ANALOG_PLL_SYS_BYPASS)

//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_BYPASS.
#define BF_CCM_ANALOG_PLL_SYS_BYPASS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_SYS_BYPASS) & BM_CCM_ANALOG_PLL_SYS_BYPASS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_SYS, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field PFD_OFFSET_EN[18] (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_SYS_PFD_OFFSET_EN      (18)      //!< Bit position for CCM_ANALOG_PLL_SYS_PFD_OFFSET_EN.
#define BM_CCM_ANALOG_PLL_SYS_PFD_OFFSET_EN      (0x00040000)  //!< Bit mask for CCM_ANALOG_PLL_SYS_PFD_OFFSET_EN.

//! @brief Get value of CCM_ANALOG_PLL_SYS_PFD_OFFSET_EN from a register value.
#define BG_CCM_ANALOG_PLL_SYS_PFD_OFFSET_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_SYS_PFD_OFFSET_EN) >> BP_CCM_ANALOG_PLL_SYS_PFD_OFFSET_EN)

//! @brief Format value for bitfield CCM_ANALOG_PLL_SYS_PFD_OFFSET_EN.
#define BF_CCM_ANALOG_PLL_SYS_PFD_OFFSET_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_SYS_PFD_OFFSET_EN) & BM_CCM_ANALOG_PLL_SYS_PFD_OFFSET_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_SYS_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_SYS, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_SYS, field LOCK[31] (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_SYS_LOCK      (31)      //!< Bit position for CCM_ANALOG_PLL_SYS_LOCK.
#define BM_CCM_ANALOG_PLL_SYS_LOCK      (0x80000000)  //!< Bit mask for CCM_ANALOG_PLL_SYS_LOCK.

//! @brief Get value of CCM_ANALOG_PLL_SYS_LOCK from a register value.
#define BG_CCM_ANALOG_PLL_SYS_LOCK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_SYS_LOCK) >> BP_CCM_ANALOG_PLL_SYS_LOCK)

//-------------------------------------------------------------------------------------------
// HW_CCM_ANALOG_PLL_AUDIO - Analog Audio PLL control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_AUDIO - Analog Audio PLL control Register (RW)
 *
 * Reset value: 0x00011006
 *
 * The control register provides control for the audio PLL.
 */
typedef union _hw_ccm_analog_pll_audio
{
    reg32_t U;
    struct _hw_ccm_analog_pll_audio_bitfields
    {
        unsigned DIV_SELECT : 7; //!< [6:0] This field controls the pll loop divider. Valid range for DIV_SELECT divider value: 27~54.
        unsigned HALF_LF : 1; //!< [7] Reserved by Freescale.
        unsigned DOUBLE_LF : 1; //!< [8] Reserved by Freescale.
        unsigned HALF_CP : 1; //!< [9] Reserved by Freescale.
        unsigned DOUBLE_CP : 1; //!< [10] Reserved by Freescale.
        unsigned HOLD_RING_OFF : 1; //!< [11] Analog debug Bit
        unsigned POWERDOWN : 1; //!< [12] Powers down the PLL.
        unsigned ENABLE : 1; //!< [13] Enable PLL output
        unsigned BYPASS_CLK_SRC : 2; //!< [15:14] Determines the bypass source.
        unsigned BYPASS : 1; //!< [16] Bypass the pll.
        unsigned RESERVED0 : 1; //!< [17] Revsered
        unsigned PFD_OFFSET_EN : 1; //!< [18] Enables an offset in the phase frequency detector.
        unsigned POST_DIV_SELECT : 2; //!< [20:19] These bits implement a divider after the PLL, but before the enable and bypass mux.
        unsigned SSC_EN : 1; //!< [21] Reserved Bit
        unsigned RESERVED1 : 9; //!< [30:22] Always set to zero (0).
        unsigned LOCK : 1; //!< [31] 1 - PLL is currently locked. 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_audio_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_AUDIO register
 */
#define HW_CCM_ANALOG_PLL_AUDIO_ADDR      (REGS_CCM_ANALOG_BASE + 0x70)
#define HW_CCM_ANALOG_PLL_AUDIO_SET_ADDR  (HW_CCM_ANALOG_PLL_AUDIO_ADDR + 0x4)
#define HW_CCM_ANALOG_PLL_AUDIO_CLR_ADDR  (HW_CCM_ANALOG_PLL_AUDIO_ADDR + 0x8)
#define HW_CCM_ANALOG_PLL_AUDIO_TOG_ADDR  (HW_CCM_ANALOG_PLL_AUDIO_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_AUDIO           (*(volatile hw_ccm_analog_pll_audio_t *) HW_CCM_ANALOG_PLL_AUDIO_ADDR)
#define HW_CCM_ANALOG_PLL_AUDIO_RD()      (HW_CCM_ANALOG_PLL_AUDIO.U)
#define HW_CCM_ANALOG_PLL_AUDIO_WR(v)     (HW_CCM_ANALOG_PLL_AUDIO.U = (v))
#define HW_CCM_ANALOG_PLL_AUDIO_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_AUDIO_SET_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_AUDIO_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_AUDIO_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_AUDIO_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_AUDIO_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_AUDIO bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field DIV_SELECT[6:0] (RW)
 *
 * This field controls the pll loop divider. Valid range for DIV_SELECT divider value: 27~54.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_DIV_SELECT      (0)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_DIV_SELECT.
#define BM_CCM_ANALOG_PLL_AUDIO_DIV_SELECT      (0x0000007f)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_DIV_SELECT.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_DIV_SELECT from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_DIV_SELECT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_AUDIO_DIV_SELECT) >> BP_CCM_ANALOG_PLL_AUDIO_DIV_SELECT)

//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_AUDIO_DIV_SELECT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_AUDIO_DIV_SELECT) & BM_CCM_ANALOG_PLL_AUDIO_DIV_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field HALF_LF[7] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_HALF_LF      (7)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_HALF_LF.
#define BM_CCM_ANALOG_PLL_AUDIO_HALF_LF      (0x00000080)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_HALF_LF.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_HALF_LF from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_HALF_LF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_AUDIO_HALF_LF) >> BP_CCM_ANALOG_PLL_AUDIO_HALF_LF)

//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_HALF_LF.
#define BF_CCM_ANALOG_PLL_AUDIO_HALF_LF(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_AUDIO_HALF_LF) & BM_CCM_ANALOG_PLL_AUDIO_HALF_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field DOUBLE_LF[8] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF      (8)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_DOUBLE_LF.
#define BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF      (0x00000100)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_DOUBLE_LF.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_DOUBLE_LF from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF) >> BP_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF)

//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_DOUBLE_LF.
#define BF_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF) & BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field HALF_CP[9] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_HALF_CP      (9)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_HALF_CP.
#define BM_CCM_ANALOG_PLL_AUDIO_HALF_CP      (0x00000200)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_HALF_CP.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_HALF_CP from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_HALF_CP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_AUDIO_HALF_CP) >> BP_CCM_ANALOG_PLL_AUDIO_HALF_CP)

//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_HALF_CP.
#define BF_CCM_ANALOG_PLL_AUDIO_HALF_CP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_AUDIO_HALF_CP) & BM_CCM_ANALOG_PLL_AUDIO_HALF_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field DOUBLE_CP[10] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP      (10)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_DOUBLE_CP.
#define BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP      (0x00000400)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_DOUBLE_CP.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_DOUBLE_CP from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP) >> BP_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP)

//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_DOUBLE_CP.
#define BF_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP) & BM_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field HOLD_RING_OFF[11] (RW)
 *
 * Analog debug Bit
 */

#define BP_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF      (11)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF.
#define BM_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF      (0x00000800)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF) >> BP_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF)

//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF.
#define BF_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF) & BM_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field POWERDOWN[12] (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_POWERDOWN      (12)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_POWERDOWN.
#define BM_CCM_ANALOG_PLL_AUDIO_POWERDOWN      (0x00001000)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_POWERDOWN.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_POWERDOWN from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_POWERDOWN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_AUDIO_POWERDOWN) >> BP_CCM_ANALOG_PLL_AUDIO_POWERDOWN)

//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_POWERDOWN.
#define BF_CCM_ANALOG_PLL_AUDIO_POWERDOWN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_AUDIO_POWERDOWN) & BM_CCM_ANALOG_PLL_AUDIO_POWERDOWN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field ENABLE[13] (RW)
 *
 * Enable PLL output
 */

#define BP_CCM_ANALOG_PLL_AUDIO_ENABLE      (13)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_ENABLE.
#define BM_CCM_ANALOG_PLL_AUDIO_ENABLE      (0x00002000)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_ENABLE.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_ENABLE from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_AUDIO_ENABLE) >> BP_CCM_ANALOG_PLL_AUDIO_ENABLE)

//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_ENABLE.
#define BF_CCM_ANALOG_PLL_AUDIO_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_AUDIO_ENABLE) & BM_CCM_ANALOG_PLL_AUDIO_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field BYPASS_CLK_SRC[15:14] (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * RESERVED = 0x2 - 
 * RESERVED = 0x3 - 
 */

#define BP_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC      (14)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC.
#define BM_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC      (0x0000c000)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC) >> BP_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC)

//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC.
#define BF_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC) & BM_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC__OSC_24M (0x0) //!< Select the 24MHz oscillator as source.
#define BV_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC__ANACLK_1 (0x1) //!< Select the Anaclk1/1b as source.
#define BV_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC__RESERVED (0x2) //!< 
#define BV_CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC__RESERVED (0x3) //!< 

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field BYPASS[16] (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_BYPASS      (16)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_BYPASS.
#define BM_CCM_ANALOG_PLL_AUDIO_BYPASS      (0x00010000)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_BYPASS.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_BYPASS from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_BYPASS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_AUDIO_BYPASS) >> BP_CCM_ANALOG_PLL_AUDIO_BYPASS)

//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_BYPASS.
#define BF_CCM_ANALOG_PLL_AUDIO_BYPASS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_AUDIO_BYPASS) & BM_CCM_ANALOG_PLL_AUDIO_BYPASS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field PFD_OFFSET_EN[18] (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN      (18)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN.
#define BM_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN      (0x00040000)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN) >> BP_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN)

//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN.
#define BF_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN) & BM_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field POST_DIV_SELECT[20:19] (RW)
 *
 * These bits implement a divider after the PLL, but before the enable and bypass mux.
 *
 * Values:
 * 00 - Divide by 4.
 * 01 - Divide by 3.
 * 10 - Divide by 2.
 * 11 - Divide by 1.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT      (19)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT.
#define BM_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT      (0x00180000)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT) >> BP_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT)

//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT) & BM_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POST_DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, POST_DIV_SELECT, v)
#endif


/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field SSC_EN[21] (RW)
 *
 * Reserved Bit
 */

#define BP_CCM_ANALOG_PLL_AUDIO_SSC_EN      (21)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_SSC_EN.
#define BM_CCM_ANALOG_PLL_AUDIO_SSC_EN      (0x00200000)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_SSC_EN.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_SSC_EN from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_SSC_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_AUDIO_SSC_EN) >> BP_CCM_ANALOG_PLL_AUDIO_SSC_EN)

//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_SSC_EN.
#define BF_CCM_ANALOG_PLL_AUDIO_SSC_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_AUDIO_SSC_EN) & BM_CCM_ANALOG_PLL_AUDIO_SSC_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_EN field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_SSC_EN(v)   BF_CS1(CCM_ANALOG_PLL_AUDIO, SSC_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_AUDIO, field LOCK[31] (RO)
 *
 * 1 - PLL is currently locked. 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_LOCK      (31)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_LOCK.
#define BM_CCM_ANALOG_PLL_AUDIO_LOCK      (0x80000000)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_LOCK.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_LOCK from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_LOCK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_AUDIO_LOCK) >> BP_CCM_ANALOG_PLL_AUDIO_LOCK)

//-------------------------------------------------------------------------------------------
// HW_CCM_ANALOG_PLL_AUDIO_NUM - Numerator of Audio PLL Fractional Loop Divider Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_AUDIO_NUM - Numerator of Audio PLL Fractional Loop Divider Register (RW)
 *
 * Reset value: 0x05f5e100
 *
 * This register contains the numerator (A) of Audio PLL fractional loop divider.(Signed number),
 * absolute value should be less than denominator  Absolute value should be less than denominator
 */
typedef union _hw_ccm_analog_pll_audio_num
{
    reg32_t U;
    struct _hw_ccm_analog_pll_audio_num_bitfields
    {
        unsigned A : 30; //!< [29:0] 30 bit numerator of fractional loop divider.
        unsigned RESERVED0 : 2; //!< [31:30] Always set to zero (0).
    } B;
} hw_ccm_analog_pll_audio_num_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_AUDIO_NUM register
 */
#define HW_CCM_ANALOG_PLL_AUDIO_NUM_ADDR      (REGS_CCM_ANALOG_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_AUDIO_NUM           (*(volatile hw_ccm_analog_pll_audio_num_t *) HW_CCM_ANALOG_PLL_AUDIO_NUM_ADDR)
#define HW_CCM_ANALOG_PLL_AUDIO_NUM_RD()      (HW_CCM_ANALOG_PLL_AUDIO_NUM.U)
#define HW_CCM_ANALOG_PLL_AUDIO_NUM_WR(v)     (HW_CCM_ANALOG_PLL_AUDIO_NUM.U = (v))
#define HW_CCM_ANALOG_PLL_AUDIO_NUM_SET(v)    (HW_CCM_ANALOG_PLL_AUDIO_NUM_WR(HW_CCM_ANALOG_PLL_AUDIO_NUM_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_AUDIO_NUM_CLR(v)    (HW_CCM_ANALOG_PLL_AUDIO_NUM_WR(HW_CCM_ANALOG_PLL_AUDIO_NUM_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_AUDIO_NUM_TOG(v)    (HW_CCM_ANALOG_PLL_AUDIO_NUM_WR(HW_CCM_ANALOG_PLL_AUDIO_NUM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_AUDIO_NUM bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_NUM, field A[29:0] (RW)
 *
 * 30 bit numerator of fractional loop divider.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_NUM_A      (0)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_NUM_A.
#define BM_CCM_ANALOG_PLL_AUDIO_NUM_A      (0x3fffffff)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_NUM_A.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_NUM_A from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_NUM_A(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_AUDIO_NUM_A) >> BP_CCM_ANALOG_PLL_AUDIO_NUM_A)

//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_NUM_A.
#define BF_CCM_ANALOG_PLL_AUDIO_NUM_A(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_AUDIO_NUM_A) & BM_CCM_ANALOG_PLL_AUDIO_NUM_A)

#ifndef __LANGUAGE_ASM__
//! @brief Set the A field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_NUM_A(v)   (HW_CCM_ANALOG_PLL_AUDIO_NUM_WR((HW_CCM_ANALOG_PLL_AUDIO_NUM_RD() & ~BM_CCM_ANALOG_PLL_AUDIO_NUM_A) | BF_CCM_ANALOG_PLL_AUDIO_NUM_A(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_CCM_ANALOG_PLL_AUDIO_DENOM - Denominator of Audio PLL Fractional Loop Divider Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_AUDIO_DENOM - Denominator of Audio PLL Fractional Loop Divider Register (RW)
 *
 * Reset value: 0x2964619c
 *
 * This register contains the Denominator (B) of Audio PLL fractional loop divider.(unsigned number)
 */
typedef union _hw_ccm_analog_pll_audio_denom
{
    reg32_t U;
    struct _hw_ccm_analog_pll_audio_denom_bitfields
    {
        unsigned B : 30; //!< [29:0] 30 bit Denominator of fractional loop divider.
        unsigned RESERVED0 : 2; //!< [31:30] Always set to zero (0).
    } B;
} hw_ccm_analog_pll_audio_denom_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_AUDIO_DENOM register
 */
#define HW_CCM_ANALOG_PLL_AUDIO_DENOM_ADDR      (REGS_CCM_ANALOG_BASE + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_AUDIO_DENOM           (*(volatile hw_ccm_analog_pll_audio_denom_t *) HW_CCM_ANALOG_PLL_AUDIO_DENOM_ADDR)
#define HW_CCM_ANALOG_PLL_AUDIO_DENOM_RD()      (HW_CCM_ANALOG_PLL_AUDIO_DENOM.U)
#define HW_CCM_ANALOG_PLL_AUDIO_DENOM_WR(v)     (HW_CCM_ANALOG_PLL_AUDIO_DENOM.U = (v))
#define HW_CCM_ANALOG_PLL_AUDIO_DENOM_SET(v)    (HW_CCM_ANALOG_PLL_AUDIO_DENOM_WR(HW_CCM_ANALOG_PLL_AUDIO_DENOM_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_AUDIO_DENOM_CLR(v)    (HW_CCM_ANALOG_PLL_AUDIO_DENOM_WR(HW_CCM_ANALOG_PLL_AUDIO_DENOM_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_AUDIO_DENOM_TOG(v)    (HW_CCM_ANALOG_PLL_AUDIO_DENOM_WR(HW_CCM_ANALOG_PLL_AUDIO_DENOM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_AUDIO_DENOM bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_AUDIO_DENOM, field B[29:0] (RW)
 *
 * 30 bit Denominator of fractional loop divider.
 */

#define BP_CCM_ANALOG_PLL_AUDIO_DENOM_B      (0)      //!< Bit position for CCM_ANALOG_PLL_AUDIO_DENOM_B.
#define BM_CCM_ANALOG_PLL_AUDIO_DENOM_B      (0x3fffffff)  //!< Bit mask for CCM_ANALOG_PLL_AUDIO_DENOM_B.

//! @brief Get value of CCM_ANALOG_PLL_AUDIO_DENOM_B from a register value.
#define BG_CCM_ANALOG_PLL_AUDIO_DENOM_B(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_AUDIO_DENOM_B) >> BP_CCM_ANALOG_PLL_AUDIO_DENOM_B)

//! @brief Format value for bitfield CCM_ANALOG_PLL_AUDIO_DENOM_B.
#define BF_CCM_ANALOG_PLL_AUDIO_DENOM_B(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_AUDIO_DENOM_B) & BM_CCM_ANALOG_PLL_AUDIO_DENOM_B)

#ifndef __LANGUAGE_ASM__
//! @brief Set the B field to a new value.
#define BW_CCM_ANALOG_PLL_AUDIO_DENOM_B(v)   (HW_CCM_ANALOG_PLL_AUDIO_DENOM_WR((HW_CCM_ANALOG_PLL_AUDIO_DENOM_RD() & ~BM_CCM_ANALOG_PLL_AUDIO_DENOM_B) | BF_CCM_ANALOG_PLL_AUDIO_DENOM_B(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_CCM_ANALOG_PLL_VIDEO - Analog Video PLL control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_VIDEO - Analog Video PLL control Register (RW)
 *
 * Reset value: 0x0001100c
 *
 * The control register provides control for the Video PLL.
 */
typedef union _hw_ccm_analog_pll_video
{
    reg32_t U;
    struct _hw_ccm_analog_pll_video_bitfields
    {
        unsigned DIV_SELECT : 7; //!< [6:0] This field controls the pll loop divider. Valid range for DIV_SELECT divider value: 27~54.
        unsigned HALF_LF : 1; //!< [7] Reserved by Freescale.
        unsigned DOUBLE_LF : 1; //!< [8] Reserved by Freescale.
        unsigned HALF_CP : 1; //!< [9] Reserved by Freescale.
        unsigned DOUBLE_CP : 1; //!< [10] Reserved by Freescale.
        unsigned HOLD_RING_OFF : 1; //!< [11] Analog Debug bit.
        unsigned POWERDOWN : 1; //!< [12] Powers down the PLL.
        unsigned ENABLE : 1; //!< [13] Enalbe PLL output
        unsigned BYPASS_CLK_SRC : 2; //!< [15:14] Determines the bypass source.
        unsigned BYPASS : 1; //!< [16] Bypass the pll.
        unsigned RESERVED0 : 1; //!< [17] Reserved
        unsigned PFD_OFFSET_EN : 1; //!< [18] Enables an offset in the phase frequency detector.
        unsigned POST_DIV_SELECT : 2; //!< [20:19] These bits implement a divider after the PLL, but before the enable and bypass mux.
        unsigned SSC_EN : 1; //!< [21] Revserved BIt
        unsigned RESERVED1 : 9; //!< [30:22] Always set to zero (0).
        unsigned LOCK : 1; //!< [31] 1 - PLL is currently locked; 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_video_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_VIDEO register
 */
#define HW_CCM_ANALOG_PLL_VIDEO_ADDR      (REGS_CCM_ANALOG_BASE + 0xa0)
#define HW_CCM_ANALOG_PLL_VIDEO_SET_ADDR  (HW_CCM_ANALOG_PLL_VIDEO_ADDR + 0x4)
#define HW_CCM_ANALOG_PLL_VIDEO_CLR_ADDR  (HW_CCM_ANALOG_PLL_VIDEO_ADDR + 0x8)
#define HW_CCM_ANALOG_PLL_VIDEO_TOG_ADDR  (HW_CCM_ANALOG_PLL_VIDEO_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_VIDEO           (*(volatile hw_ccm_analog_pll_video_t *) HW_CCM_ANALOG_PLL_VIDEO_ADDR)
#define HW_CCM_ANALOG_PLL_VIDEO_RD()      (HW_CCM_ANALOG_PLL_VIDEO.U)
#define HW_CCM_ANALOG_PLL_VIDEO_WR(v)     (HW_CCM_ANALOG_PLL_VIDEO.U = (v))
#define HW_CCM_ANALOG_PLL_VIDEO_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_VIDEO_SET_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_VIDEO_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_VIDEO_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_VIDEO_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_VIDEO_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_VIDEO bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field DIV_SELECT[6:0] (RW)
 *
 * This field controls the pll loop divider. Valid range for DIV_SELECT divider value: 27~54.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_DIV_SELECT      (0)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_DIV_SELECT.
#define BM_CCM_ANALOG_PLL_VIDEO_DIV_SELECT      (0x0000007f)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_DIV_SELECT.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_DIV_SELECT from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_DIV_SELECT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_VIDEO_DIV_SELECT) >> BP_CCM_ANALOG_PLL_VIDEO_DIV_SELECT)

//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_VIDEO_DIV_SELECT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_VIDEO_DIV_SELECT) & BM_CCM_ANALOG_PLL_VIDEO_DIV_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field HALF_LF[7] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_HALF_LF      (7)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_HALF_LF.
#define BM_CCM_ANALOG_PLL_VIDEO_HALF_LF      (0x00000080)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_HALF_LF.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_HALF_LF from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_HALF_LF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_VIDEO_HALF_LF) >> BP_CCM_ANALOG_PLL_VIDEO_HALF_LF)

//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_HALF_LF.
#define BF_CCM_ANALOG_PLL_VIDEO_HALF_LF(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_VIDEO_HALF_LF) & BM_CCM_ANALOG_PLL_VIDEO_HALF_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field DOUBLE_LF[8] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF      (8)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_DOUBLE_LF.
#define BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF      (0x00000100)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_DOUBLE_LF.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_DOUBLE_LF from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF) >> BP_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF)

//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_DOUBLE_LF.
#define BF_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF) & BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field HALF_CP[9] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_HALF_CP      (9)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_HALF_CP.
#define BM_CCM_ANALOG_PLL_VIDEO_HALF_CP      (0x00000200)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_HALF_CP.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_HALF_CP from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_HALF_CP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_VIDEO_HALF_CP) >> BP_CCM_ANALOG_PLL_VIDEO_HALF_CP)

//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_HALF_CP.
#define BF_CCM_ANALOG_PLL_VIDEO_HALF_CP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_VIDEO_HALF_CP) & BM_CCM_ANALOG_PLL_VIDEO_HALF_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field DOUBLE_CP[10] (RW)
 *
 * Reserved by Freescale.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP      (10)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_DOUBLE_CP.
#define BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP      (0x00000400)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_DOUBLE_CP.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_DOUBLE_CP from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP) >> BP_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP)

//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_DOUBLE_CP.
#define BF_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP) & BM_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field HOLD_RING_OFF[11] (RW)
 *
 * Analog Debug bit.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF      (11)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF.
#define BM_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF      (0x00000800)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF) >> BP_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF)

//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF.
#define BF_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF) & BM_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field POWERDOWN[12] (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_POWERDOWN      (12)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_POWERDOWN.
#define BM_CCM_ANALOG_PLL_VIDEO_POWERDOWN      (0x00001000)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_POWERDOWN.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_POWERDOWN from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_POWERDOWN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_VIDEO_POWERDOWN) >> BP_CCM_ANALOG_PLL_VIDEO_POWERDOWN)

//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_POWERDOWN.
#define BF_CCM_ANALOG_PLL_VIDEO_POWERDOWN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_VIDEO_POWERDOWN) & BM_CCM_ANALOG_PLL_VIDEO_POWERDOWN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field ENABLE[13] (RW)
 *
 * Enalbe PLL output
 */

#define BP_CCM_ANALOG_PLL_VIDEO_ENABLE      (13)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_ENABLE.
#define BM_CCM_ANALOG_PLL_VIDEO_ENABLE      (0x00002000)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_ENABLE.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_ENABLE from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_VIDEO_ENABLE) >> BP_CCM_ANALOG_PLL_VIDEO_ENABLE)

//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_ENABLE.
#define BF_CCM_ANALOG_PLL_VIDEO_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_VIDEO_ENABLE) & BM_CCM_ANALOG_PLL_VIDEO_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field BYPASS_CLK_SRC[15:14] (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * RESERVED = 0x2 - 
 * RESERVED = 0x3 - 
 */

#define BP_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC      (14)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC.
#define BM_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC      (0x0000c000)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC) >> BP_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC)

//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC.
#define BF_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC) & BM_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC__OSC_24M (0x0) //!< Select the 24MHz oscillator as source.
#define BV_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC__ANACLK_1 (0x1) //!< Select the Anaclk1/1b as source.
#define BV_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC__RESERVED (0x2) //!< 
#define BV_CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC__RESERVED (0x3) //!< 

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field BYPASS[16] (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_BYPASS      (16)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_BYPASS.
#define BM_CCM_ANALOG_PLL_VIDEO_BYPASS      (0x00010000)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_BYPASS.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_BYPASS from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_BYPASS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_VIDEO_BYPASS) >> BP_CCM_ANALOG_PLL_VIDEO_BYPASS)

//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_BYPASS.
#define BF_CCM_ANALOG_PLL_VIDEO_BYPASS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_VIDEO_BYPASS) & BM_CCM_ANALOG_PLL_VIDEO_BYPASS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field PFD_OFFSET_EN[18] (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN      (18)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN.
#define BM_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN      (0x00040000)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN) >> BP_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN)

//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN.
#define BF_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN) & BM_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field POST_DIV_SELECT[20:19] (RW)
 *
 * These bits implement a divider after the PLL, but before the enable and bypass mux.
 *
 * Values:
 * 00 - Divide by 4.
 * 01 - Divide by 3.
 * 10 - Divide by 2.
 * 11 - Divide by 1.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT      (19)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT.
#define BM_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT      (0x00180000)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT) >> BP_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT)

//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT) & BM_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POST_DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, POST_DIV_SELECT, v)
#endif


/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field SSC_EN[21] (RW)
 *
 * Revserved BIt
 */

#define BP_CCM_ANALOG_PLL_VIDEO_SSC_EN      (21)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_SSC_EN.
#define BM_CCM_ANALOG_PLL_VIDEO_SSC_EN      (0x00200000)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_SSC_EN.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_SSC_EN from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_SSC_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_VIDEO_SSC_EN) >> BP_CCM_ANALOG_PLL_VIDEO_SSC_EN)

//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_SSC_EN.
#define BF_CCM_ANALOG_PLL_VIDEO_SSC_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_VIDEO_SSC_EN) & BM_CCM_ANALOG_PLL_VIDEO_SSC_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SSC_EN field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_SSC_EN(v)   BF_CS1(CCM_ANALOG_PLL_VIDEO, SSC_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_VIDEO, field LOCK[31] (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_LOCK      (31)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_LOCK.
#define BM_CCM_ANALOG_PLL_VIDEO_LOCK      (0x80000000)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_LOCK.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_LOCK from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_LOCK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_VIDEO_LOCK) >> BP_CCM_ANALOG_PLL_VIDEO_LOCK)

//-------------------------------------------------------------------------------------------
// HW_CCM_ANALOG_PLL_VIDEO_NUM - Numerator of Video PLL Fractional Loop Divider Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_VIDEO_NUM - Numerator of Video PLL Fractional Loop Divider Register (RW)
 *
 * Reset value: 0x05f5e100
 *
 * This register contains the numerator (A) of Video PLL fractional loop divider.(Signed number)
 * Absolute value should be less than denominator
 */
typedef union _hw_ccm_analog_pll_video_num
{
    reg32_t U;
    struct _hw_ccm_analog_pll_video_num_bitfields
    {
        unsigned A : 30; //!< [29:0] 30 bit numerator of fractional loop divider(Signed number), absolute value should be less than denominator
        unsigned RESERVED0 : 2; //!< [31:30] Always set to zero (0).
    } B;
} hw_ccm_analog_pll_video_num_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_VIDEO_NUM register
 */
#define HW_CCM_ANALOG_PLL_VIDEO_NUM_ADDR      (REGS_CCM_ANALOG_BASE + 0xb0)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_VIDEO_NUM           (*(volatile hw_ccm_analog_pll_video_num_t *) HW_CCM_ANALOG_PLL_VIDEO_NUM_ADDR)
#define HW_CCM_ANALOG_PLL_VIDEO_NUM_RD()      (HW_CCM_ANALOG_PLL_VIDEO_NUM.U)
#define HW_CCM_ANALOG_PLL_VIDEO_NUM_WR(v)     (HW_CCM_ANALOG_PLL_VIDEO_NUM.U = (v))
#define HW_CCM_ANALOG_PLL_VIDEO_NUM_SET(v)    (HW_CCM_ANALOG_PLL_VIDEO_NUM_WR(HW_CCM_ANALOG_PLL_VIDEO_NUM_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_VIDEO_NUM_CLR(v)    (HW_CCM_ANALOG_PLL_VIDEO_NUM_WR(HW_CCM_ANALOG_PLL_VIDEO_NUM_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_VIDEO_NUM_TOG(v)    (HW_CCM_ANALOG_PLL_VIDEO_NUM_WR(HW_CCM_ANALOG_PLL_VIDEO_NUM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_VIDEO_NUM bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_NUM, field A[29:0] (RW)
 *
 * 30 bit numerator of fractional loop divider(Signed number), absolute value should be less than
 * denominator
 */

#define BP_CCM_ANALOG_PLL_VIDEO_NUM_A      (0)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_NUM_A.
#define BM_CCM_ANALOG_PLL_VIDEO_NUM_A      (0x3fffffff)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_NUM_A.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_NUM_A from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_NUM_A(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_VIDEO_NUM_A) >> BP_CCM_ANALOG_PLL_VIDEO_NUM_A)

//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_NUM_A.
#define BF_CCM_ANALOG_PLL_VIDEO_NUM_A(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_VIDEO_NUM_A) & BM_CCM_ANALOG_PLL_VIDEO_NUM_A)

#ifndef __LANGUAGE_ASM__
//! @brief Set the A field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_NUM_A(v)   (HW_CCM_ANALOG_PLL_VIDEO_NUM_WR((HW_CCM_ANALOG_PLL_VIDEO_NUM_RD() & ~BM_CCM_ANALOG_PLL_VIDEO_NUM_A) | BF_CCM_ANALOG_PLL_VIDEO_NUM_A(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_CCM_ANALOG_PLL_VIDEO_DENOM - Denominator of Video PLL Fractional Loop Divider Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_VIDEO_DENOM - Denominator of Video PLL Fractional Loop Divider Register (RW)
 *
 * Reset value: 0x10a24447
 *
 * This register contains the Denominator (B) of Video PLL fractional loop divider.(Unsigned number)
 */
typedef union _hw_ccm_analog_pll_video_denom
{
    reg32_t U;
    struct _hw_ccm_analog_pll_video_denom_bitfields
    {
        unsigned B : 30; //!< [29:0] 30 bit Denominator of fractional loop divider.
        unsigned RESERVED0 : 2; //!< [31:30] Always set to zero (0).
    } B;
} hw_ccm_analog_pll_video_denom_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_VIDEO_DENOM register
 */
#define HW_CCM_ANALOG_PLL_VIDEO_DENOM_ADDR      (REGS_CCM_ANALOG_BASE + 0xc0)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_VIDEO_DENOM           (*(volatile hw_ccm_analog_pll_video_denom_t *) HW_CCM_ANALOG_PLL_VIDEO_DENOM_ADDR)
#define HW_CCM_ANALOG_PLL_VIDEO_DENOM_RD()      (HW_CCM_ANALOG_PLL_VIDEO_DENOM.U)
#define HW_CCM_ANALOG_PLL_VIDEO_DENOM_WR(v)     (HW_CCM_ANALOG_PLL_VIDEO_DENOM.U = (v))
#define HW_CCM_ANALOG_PLL_VIDEO_DENOM_SET(v)    (HW_CCM_ANALOG_PLL_VIDEO_DENOM_WR(HW_CCM_ANALOG_PLL_VIDEO_DENOM_RD() |  (v)))
#define HW_CCM_ANALOG_PLL_VIDEO_DENOM_CLR(v)    (HW_CCM_ANALOG_PLL_VIDEO_DENOM_WR(HW_CCM_ANALOG_PLL_VIDEO_DENOM_RD() & ~(v)))
#define HW_CCM_ANALOG_PLL_VIDEO_DENOM_TOG(v)    (HW_CCM_ANALOG_PLL_VIDEO_DENOM_WR(HW_CCM_ANALOG_PLL_VIDEO_DENOM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_VIDEO_DENOM bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_VIDEO_DENOM, field B[29:0] (RW)
 *
 * 30 bit Denominator of fractional loop divider.
 */

#define BP_CCM_ANALOG_PLL_VIDEO_DENOM_B      (0)      //!< Bit position for CCM_ANALOG_PLL_VIDEO_DENOM_B.
#define BM_CCM_ANALOG_PLL_VIDEO_DENOM_B      (0x3fffffff)  //!< Bit mask for CCM_ANALOG_PLL_VIDEO_DENOM_B.

//! @brief Get value of CCM_ANALOG_PLL_VIDEO_DENOM_B from a register value.
#define BG_CCM_ANALOG_PLL_VIDEO_DENOM_B(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_VIDEO_DENOM_B) >> BP_CCM_ANALOG_PLL_VIDEO_DENOM_B)

//! @brief Format value for bitfield CCM_ANALOG_PLL_VIDEO_DENOM_B.
#define BF_CCM_ANALOG_PLL_VIDEO_DENOM_B(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_VIDEO_DENOM_B) & BM_CCM_ANALOG_PLL_VIDEO_DENOM_B)

#ifndef __LANGUAGE_ASM__
//! @brief Set the B field to a new value.
#define BW_CCM_ANALOG_PLL_VIDEO_DENOM_B(v)   (HW_CCM_ANALOG_PLL_VIDEO_DENOM_WR((HW_CCM_ANALOG_PLL_VIDEO_DENOM_RD() & ~BM_CCM_ANALOG_PLL_VIDEO_DENOM_B) | BF_CCM_ANALOG_PLL_VIDEO_DENOM_B(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_CCM_ANALOG_PLL_ENET - Analog ENET PLL Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PLL_ENET - Analog ENET PLL Control Register (RW)
 *
 * Reset value: 0x00011001
 *
 * The control register provides control for the ENET PLL.
 */
typedef union _hw_ccm_analog_pll_enet
{
    reg32_t U;
    struct _hw_ccm_analog_pll_enet_bitfields
    {
        unsigned DIV_SELECT : 2; //!< [1:0] Controls the frequency of the ethernet reference clock.00 - 25MHz; 01 - 50MHz; 10 - 100MHz (not 50% duty cycle); 11 - 125MHz; Note: PCIe and SATA outputs are fixed at 125MHz and 100MHz respectively.
        unsigned RESERVED0 : 5; //!< [6:2] Always set to zero (0).
        unsigned HALF_LF : 1; //!< [7] Reserved by Freescale
        unsigned DOUBLE_LF : 1; //!< [8] Reserved by Freescale
        unsigned HALF_CP : 1; //!< [9] Reserved by Freescale
        unsigned DOUBLE_CP : 1; //!< [10] Reserved by Freescale
        unsigned HOLD_RING_OFF : 1; //!< [11] Analog debug bit
        unsigned POWERDOWN : 1; //!< [12] Powers down the PLL.
        unsigned ENABLE : 1; //!< [13] Enable the ethernet clock output.
        unsigned BYPASS_CLK_SRC : 2; //!< [15:14] Determines the bypass source.
        unsigned BYPASS : 1; //!< [16] Bypass the pll.
        unsigned RESERVED1 : 1; //!< [17] Reserved
        unsigned PFD_OFFSET_EN : 1; //!< [18] Enables an offset in the phase frequency detector.
        unsigned ENABLE_125M : 1; //!< [19] Enables an offset in the phase frequency detector.
        unsigned ENABLE_100M : 1; //!< [20] Enables an offset in the phase frequency detector.
        unsigned RESERVED2 : 10; //!< [30:21] Always set to zero (0).
        unsigned LOCK : 1; //!< [31] 1 - PLL is currently locked; 0 - PLL is not currently locked.
    } B;
} hw_ccm_analog_pll_enet_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PLL_ENET register
 */
#define HW_CCM_ANALOG_PLL_ENET_ADDR      (REGS_CCM_ANALOG_BASE + 0xe0)
#define HW_CCM_ANALOG_PLL_ENET_SET_ADDR  (HW_CCM_ANALOG_PLL_ENET_ADDR + 0x4)
#define HW_CCM_ANALOG_PLL_ENET_CLR_ADDR  (HW_CCM_ANALOG_PLL_ENET_ADDR + 0x8)
#define HW_CCM_ANALOG_PLL_ENET_TOG_ADDR  (HW_CCM_ANALOG_PLL_ENET_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PLL_ENET           (*(volatile hw_ccm_analog_pll_enet_t *) HW_CCM_ANALOG_PLL_ENET_ADDR)
#define HW_CCM_ANALOG_PLL_ENET_RD()      (HW_CCM_ANALOG_PLL_ENET.U)
#define HW_CCM_ANALOG_PLL_ENET_WR(v)     (HW_CCM_ANALOG_PLL_ENET.U = (v))
#define HW_CCM_ANALOG_PLL_ENET_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_ENET_SET_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_ENET_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_ENET_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_PLL_ENET_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PLL_ENET_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PLL_ENET bitfields
 */

/* --- Register HW_CCM_ANALOG_PLL_ENET, field DIV_SELECT[1:0] (RW)
 *
 * Controls the frequency of the ethernet reference clock.00 - 25MHz; 01 - 50MHz; 10 - 100MHz (not
 * 50% duty cycle); 11 - 125MHz; Note: PCIe and SATA outputs are fixed at 125MHz and 100MHz
 * respectively.
 */

#define BP_CCM_ANALOG_PLL_ENET_DIV_SELECT      (0)      //!< Bit position for CCM_ANALOG_PLL_ENET_DIV_SELECT.
#define BM_CCM_ANALOG_PLL_ENET_DIV_SELECT      (0x00000003)  //!< Bit mask for CCM_ANALOG_PLL_ENET_DIV_SELECT.

//! @brief Get value of CCM_ANALOG_PLL_ENET_DIV_SELECT from a register value.
#define BG_CCM_ANALOG_PLL_ENET_DIV_SELECT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ENET_DIV_SELECT) >> BP_CCM_ANALOG_PLL_ENET_DIV_SELECT)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_DIV_SELECT.
#define BF_CCM_ANALOG_PLL_ENET_DIV_SELECT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ENET_DIV_SELECT) & BM_CCM_ANALOG_PLL_ENET_DIV_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIV_SELECT field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_DIV_SELECT(v)   BF_CS1(CCM_ANALOG_PLL_ENET, DIV_SELECT, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field HALF_LF[7] (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_HALF_LF      (7)      //!< Bit position for CCM_ANALOG_PLL_ENET_HALF_LF.
#define BM_CCM_ANALOG_PLL_ENET_HALF_LF      (0x00000080)  //!< Bit mask for CCM_ANALOG_PLL_ENET_HALF_LF.

//! @brief Get value of CCM_ANALOG_PLL_ENET_HALF_LF from a register value.
#define BG_CCM_ANALOG_PLL_ENET_HALF_LF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ENET_HALF_LF) >> BP_CCM_ANALOG_PLL_ENET_HALF_LF)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_HALF_LF.
#define BF_CCM_ANALOG_PLL_ENET_HALF_LF(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ENET_HALF_LF) & BM_CCM_ANALOG_PLL_ENET_HALF_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LF field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_HALF_LF(v)   BF_CS1(CCM_ANALOG_PLL_ENET, HALF_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field DOUBLE_LF[8] (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_DOUBLE_LF      (8)      //!< Bit position for CCM_ANALOG_PLL_ENET_DOUBLE_LF.
#define BM_CCM_ANALOG_PLL_ENET_DOUBLE_LF      (0x00000100)  //!< Bit mask for CCM_ANALOG_PLL_ENET_DOUBLE_LF.

//! @brief Get value of CCM_ANALOG_PLL_ENET_DOUBLE_LF from a register value.
#define BG_CCM_ANALOG_PLL_ENET_DOUBLE_LF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ENET_DOUBLE_LF) >> BP_CCM_ANALOG_PLL_ENET_DOUBLE_LF)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_DOUBLE_LF.
#define BF_CCM_ANALOG_PLL_ENET_DOUBLE_LF(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ENET_DOUBLE_LF) & BM_CCM_ANALOG_PLL_ENET_DOUBLE_LF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_LF field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_DOUBLE_LF(v)   BF_CS1(CCM_ANALOG_PLL_ENET, DOUBLE_LF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field HALF_CP[9] (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_HALF_CP      (9)      //!< Bit position for CCM_ANALOG_PLL_ENET_HALF_CP.
#define BM_CCM_ANALOG_PLL_ENET_HALF_CP      (0x00000200)  //!< Bit mask for CCM_ANALOG_PLL_ENET_HALF_CP.

//! @brief Get value of CCM_ANALOG_PLL_ENET_HALF_CP from a register value.
#define BG_CCM_ANALOG_PLL_ENET_HALF_CP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ENET_HALF_CP) >> BP_CCM_ANALOG_PLL_ENET_HALF_CP)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_HALF_CP.
#define BF_CCM_ANALOG_PLL_ENET_HALF_CP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ENET_HALF_CP) & BM_CCM_ANALOG_PLL_ENET_HALF_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_CP field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_HALF_CP(v)   BF_CS1(CCM_ANALOG_PLL_ENET, HALF_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field DOUBLE_CP[10] (RW)
 *
 * Reserved by Freescale
 */

#define BP_CCM_ANALOG_PLL_ENET_DOUBLE_CP      (10)      //!< Bit position for CCM_ANALOG_PLL_ENET_DOUBLE_CP.
#define BM_CCM_ANALOG_PLL_ENET_DOUBLE_CP      (0x00000400)  //!< Bit mask for CCM_ANALOG_PLL_ENET_DOUBLE_CP.

//! @brief Get value of CCM_ANALOG_PLL_ENET_DOUBLE_CP from a register value.
#define BG_CCM_ANALOG_PLL_ENET_DOUBLE_CP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ENET_DOUBLE_CP) >> BP_CCM_ANALOG_PLL_ENET_DOUBLE_CP)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_DOUBLE_CP.
#define BF_CCM_ANALOG_PLL_ENET_DOUBLE_CP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ENET_DOUBLE_CP) & BM_CCM_ANALOG_PLL_ENET_DOUBLE_CP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOUBLE_CP field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_DOUBLE_CP(v)   BF_CS1(CCM_ANALOG_PLL_ENET, DOUBLE_CP, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field HOLD_RING_OFF[11] (RW)
 *
 * Analog debug bit
 */

#define BP_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF      (11)      //!< Bit position for CCM_ANALOG_PLL_ENET_HOLD_RING_OFF.
#define BM_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF      (0x00000800)  //!< Bit mask for CCM_ANALOG_PLL_ENET_HOLD_RING_OFF.

//! @brief Get value of CCM_ANALOG_PLL_ENET_HOLD_RING_OFF from a register value.
#define BG_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF) >> BP_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_HOLD_RING_OFF.
#define BF_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF) & BM_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLD_RING_OFF field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_HOLD_RING_OFF(v)   BF_CS1(CCM_ANALOG_PLL_ENET, HOLD_RING_OFF, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field POWERDOWN[12] (RW)
 *
 * Powers down the PLL.
 */

#define BP_CCM_ANALOG_PLL_ENET_POWERDOWN      (12)      //!< Bit position for CCM_ANALOG_PLL_ENET_POWERDOWN.
#define BM_CCM_ANALOG_PLL_ENET_POWERDOWN      (0x00001000)  //!< Bit mask for CCM_ANALOG_PLL_ENET_POWERDOWN.

//! @brief Get value of CCM_ANALOG_PLL_ENET_POWERDOWN from a register value.
#define BG_CCM_ANALOG_PLL_ENET_POWERDOWN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ENET_POWERDOWN) >> BP_CCM_ANALOG_PLL_ENET_POWERDOWN)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_POWERDOWN.
#define BF_CCM_ANALOG_PLL_ENET_POWERDOWN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ENET_POWERDOWN) & BM_CCM_ANALOG_PLL_ENET_POWERDOWN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWERDOWN field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_POWERDOWN(v)   BF_CS1(CCM_ANALOG_PLL_ENET, POWERDOWN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field ENABLE[13] (RW)
 *
 * Enable the ethernet clock output.
 */

#define BP_CCM_ANALOG_PLL_ENET_ENABLE      (13)      //!< Bit position for CCM_ANALOG_PLL_ENET_ENABLE.
#define BM_CCM_ANALOG_PLL_ENET_ENABLE      (0x00002000)  //!< Bit mask for CCM_ANALOG_PLL_ENET_ENABLE.

//! @brief Get value of CCM_ANALOG_PLL_ENET_ENABLE from a register value.
#define BG_CCM_ANALOG_PLL_ENET_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ENET_ENABLE) >> BP_CCM_ANALOG_PLL_ENET_ENABLE)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_ENABLE.
#define BF_CCM_ANALOG_PLL_ENET_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ENET_ENABLE) & BM_CCM_ANALOG_PLL_ENET_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_ENABLE(v)   BF_CS1(CCM_ANALOG_PLL_ENET, ENABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field BYPASS_CLK_SRC[15:14] (RW)
 *
 * Determines the bypass source.
 *
 * Values:
 * OSC_24M = 0x0 - Select the 24MHz oscillator as source.
 * ANACLK_1 = 0x1 - Select the Anaclk1/1b as source.
 * RESERVED = 0x2 - 
 * RESERVED = 0x3 - 
 */

#define BP_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC      (14)      //!< Bit position for CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC.
#define BM_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC      (0x0000c000)  //!< Bit mask for CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC.

//! @brief Get value of CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC from a register value.
#define BG_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC) >> BP_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC.
#define BF_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC) & BM_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_CLK_SRC field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC(v)   BF_CS1(CCM_ANALOG_PLL_ENET, BYPASS_CLK_SRC, v)
#endif

#define BV_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC__OSC_24M (0x0) //!< Select the 24MHz oscillator as source.
#define BV_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC__ANACLK_1 (0x1) //!< Select the Anaclk1/1b as source.
#define BV_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC__RESERVED (0x2) //!< 
#define BV_CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC__RESERVED (0x3) //!< 

/* --- Register HW_CCM_ANALOG_PLL_ENET, field BYPASS[16] (RW)
 *
 * Bypass the pll.
 */

#define BP_CCM_ANALOG_PLL_ENET_BYPASS      (16)      //!< Bit position for CCM_ANALOG_PLL_ENET_BYPASS.
#define BM_CCM_ANALOG_PLL_ENET_BYPASS      (0x00010000)  //!< Bit mask for CCM_ANALOG_PLL_ENET_BYPASS.

//! @brief Get value of CCM_ANALOG_PLL_ENET_BYPASS from a register value.
#define BG_CCM_ANALOG_PLL_ENET_BYPASS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ENET_BYPASS) >> BP_CCM_ANALOG_PLL_ENET_BYPASS)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_BYPASS.
#define BF_CCM_ANALOG_PLL_ENET_BYPASS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ENET_BYPASS) & BM_CCM_ANALOG_PLL_ENET_BYPASS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_BYPASS(v)   BF_CS1(CCM_ANALOG_PLL_ENET, BYPASS, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field PFD_OFFSET_EN[18] (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN      (18)      //!< Bit position for CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN.
#define BM_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN      (0x00040000)  //!< Bit mask for CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN.

//! @brief Get value of CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN from a register value.
#define BG_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN) >> BP_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN.
#define BF_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN) & BM_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD_OFFSET_EN field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_PFD_OFFSET_EN(v)   BF_CS1(CCM_ANALOG_PLL_ENET, PFD_OFFSET_EN, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field ENABLE_125M[19] (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_ENET_ENABLE_125M      (19)      //!< Bit position for CCM_ANALOG_PLL_ENET_ENABLE_125M.
#define BM_CCM_ANALOG_PLL_ENET_ENABLE_125M      (0x00080000)  //!< Bit mask for CCM_ANALOG_PLL_ENET_ENABLE_125M.

//! @brief Get value of CCM_ANALOG_PLL_ENET_ENABLE_125M from a register value.
#define BG_CCM_ANALOG_PLL_ENET_ENABLE_125M(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ENET_ENABLE_125M) >> BP_CCM_ANALOG_PLL_ENET_ENABLE_125M)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_ENABLE_125M.
#define BF_CCM_ANALOG_PLL_ENET_ENABLE_125M(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ENET_ENABLE_125M) & BM_CCM_ANALOG_PLL_ENET_ENABLE_125M)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_125M field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_ENABLE_125M(v)   BF_CS1(CCM_ANALOG_PLL_ENET, ENABLE_125M, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field ENABLE_100M[20] (RW)
 *
 * Enables an offset in the phase frequency detector.
 */

#define BP_CCM_ANALOG_PLL_ENET_ENABLE_100M      (20)      //!< Bit position for CCM_ANALOG_PLL_ENET_ENABLE_100M.
#define BM_CCM_ANALOG_PLL_ENET_ENABLE_100M      (0x00100000)  //!< Bit mask for CCM_ANALOG_PLL_ENET_ENABLE_100M.

//! @brief Get value of CCM_ANALOG_PLL_ENET_ENABLE_100M from a register value.
#define BG_CCM_ANALOG_PLL_ENET_ENABLE_100M(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ENET_ENABLE_100M) >> BP_CCM_ANALOG_PLL_ENET_ENABLE_100M)

//! @brief Format value for bitfield CCM_ANALOG_PLL_ENET_ENABLE_100M.
#define BF_CCM_ANALOG_PLL_ENET_ENABLE_100M(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PLL_ENET_ENABLE_100M) & BM_CCM_ANALOG_PLL_ENET_ENABLE_100M)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_100M field to a new value.
#define BW_CCM_ANALOG_PLL_ENET_ENABLE_100M(v)   BF_CS1(CCM_ANALOG_PLL_ENET, ENABLE_100M, v)
#endif

/* --- Register HW_CCM_ANALOG_PLL_ENET, field LOCK[31] (RO)
 *
 * 1 - PLL is currently locked; 0 - PLL is not currently locked.
 */

#define BP_CCM_ANALOG_PLL_ENET_LOCK      (31)      //!< Bit position for CCM_ANALOG_PLL_ENET_LOCK.
#define BM_CCM_ANALOG_PLL_ENET_LOCK      (0x80000000)  //!< Bit mask for CCM_ANALOG_PLL_ENET_LOCK.

//! @brief Get value of CCM_ANALOG_PLL_ENET_LOCK from a register value.
#define BG_CCM_ANALOG_PLL_ENET_LOCK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PLL_ENET_LOCK) >> BP_CCM_ANALOG_PLL_ENET_LOCK)

//-------------------------------------------------------------------------------------------
// HW_CCM_ANALOG_PFD_480 - 480MHz Clock (from PLL_USB2) Phase Fractional Divider Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PFD_480 - 480MHz Clock (from PLL_USB2) Phase Fractional Divider Control Register (RW)
 *
 * Reset value: 0x1311100c
 *
 * The PFD_480 control register provides control for PFD clock generation.  This register controls
 * the 4-phase fractional clock dividers. The fractional clock frequencies are a product of the
 * values in these registers.
 */
typedef union _hw_ccm_analog_pfd_480
{
    reg32_t U;
    struct _hw_ccm_analog_pfd_480_bitfields
    {
        unsigned PFD0_FRAC : 6; //!< [5:0] This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD0_FRAC where PFD0_FRAC is in the range 12-35.
        unsigned PFD0_STABLE : 1; //!< [6] This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD0_CLKGATE : 1; //!< [7] If set to 1, the IO fractional divider clock (reference ref_pfd0) is off (power savings). 0: ref_pfd0 fractional divider clock is enabled. Need to assert this bit before PLL is powered down
        unsigned PFD1_FRAC : 6; //!< [13:8] This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD1_FRAC where PFD1_FRAC is in the range 12-35.
        unsigned PFD1_STABLE : 1; //!< [14] This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD1_CLKGATE : 1; //!< [15] IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd1) is off (power savings). 0: ref_pfd1 fractional divider clock is enabled. Need to assert this bit before PLL is powered down
        unsigned PFD2_FRAC : 6; //!< [21:16] This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD2_FRAC where PFD2_FRAC is in the range 12-35.
        unsigned PFD2_STABLE : 1; //!< [22] This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD2_CLKGATE : 1; //!< [23] IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd2) is off (power savings). 0: ref_pfd2 fractional divider clock is enabled. Need to assert this bit before PLL is powered down
        unsigned PFD3_FRAC : 6; //!< [29:24] This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD3_FRAC where PFD3_FRAC is in the range 12-35.
        unsigned PFD3_STABLE : 1; //!< [30] This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD3_CLKGATE : 1; //!< [31] IO Clock Gate. If set to 1, the 3rd fractional divider clock (reference ref_pfd3) is off (power savings). 0: ref_pfd3 fractional divider clock is enabled. Need to assert this bit before PLL is powered down
    } B;
} hw_ccm_analog_pfd_480_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PFD_480 register
 */
#define HW_CCM_ANALOG_PFD_480_ADDR      (REGS_CCM_ANALOG_BASE + 0xf0)
#define HW_CCM_ANALOG_PFD_480_SET_ADDR  (HW_CCM_ANALOG_PFD_480_ADDR + 0x4)
#define HW_CCM_ANALOG_PFD_480_CLR_ADDR  (HW_CCM_ANALOG_PFD_480_ADDR + 0x8)
#define HW_CCM_ANALOG_PFD_480_TOG_ADDR  (HW_CCM_ANALOG_PFD_480_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PFD_480           (*(volatile hw_ccm_analog_pfd_480_t *) HW_CCM_ANALOG_PFD_480_ADDR)
#define HW_CCM_ANALOG_PFD_480_RD()      (HW_CCM_ANALOG_PFD_480.U)
#define HW_CCM_ANALOG_PFD_480_WR(v)     (HW_CCM_ANALOG_PFD_480.U = (v))
#define HW_CCM_ANALOG_PFD_480_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PFD_480_SET_ADDR) = (v))
#define HW_CCM_ANALOG_PFD_480_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PFD_480_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_PFD_480_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PFD_480_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PFD_480 bitfields
 */

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD0_FRAC[5:0] (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD0_FRAC where PFD0_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_PFD0_FRAC      (0)      //!< Bit position for CCM_ANALOG_PFD_480_PFD0_FRAC.
#define BM_CCM_ANALOG_PFD_480_PFD0_FRAC      (0x0000003f)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD0_FRAC.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD0_FRAC from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD0_FRAC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_480_PFD0_FRAC) >> BP_CCM_ANALOG_PFD_480_PFD0_FRAC)

//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD0_FRAC.
#define BF_CCM_ANALOG_PFD_480_PFD0_FRAC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PFD_480_PFD0_FRAC) & BM_CCM_ANALOG_PFD_480_PFD0_FRAC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD0_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD0_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD0_STABLE[6] (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_PFD0_STABLE      (6)      //!< Bit position for CCM_ANALOG_PFD_480_PFD0_STABLE.
#define BM_CCM_ANALOG_PFD_480_PFD0_STABLE      (0x00000040)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD0_STABLE.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD0_STABLE from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD0_STABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_480_PFD0_STABLE) >> BP_CCM_ANALOG_PFD_480_PFD0_STABLE)

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD0_CLKGATE[7] (RW)
 *
 * If set to 1, the IO fractional divider clock (reference ref_pfd0) is off (power savings). 0:
 * ref_pfd0 fractional divider clock is enabled. Need to assert this bit before PLL is powered down
 */

#define BP_CCM_ANALOG_PFD_480_PFD0_CLKGATE      (7)      //!< Bit position for CCM_ANALOG_PFD_480_PFD0_CLKGATE.
#define BM_CCM_ANALOG_PFD_480_PFD0_CLKGATE      (0x00000080)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD0_CLKGATE.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD0_CLKGATE from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD0_CLKGATE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_480_PFD0_CLKGATE) >> BP_CCM_ANALOG_PFD_480_PFD0_CLKGATE)

//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD0_CLKGATE.
#define BF_CCM_ANALOG_PFD_480_PFD0_CLKGATE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PFD_480_PFD0_CLKGATE) & BM_CCM_ANALOG_PFD_480_PFD0_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD0_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD0_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD1_FRAC[13:8] (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD1_FRAC where PFD1_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_PFD1_FRAC      (8)      //!< Bit position for CCM_ANALOG_PFD_480_PFD1_FRAC.
#define BM_CCM_ANALOG_PFD_480_PFD1_FRAC      (0x00003f00)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD1_FRAC.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD1_FRAC from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD1_FRAC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_480_PFD1_FRAC) >> BP_CCM_ANALOG_PFD_480_PFD1_FRAC)

//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD1_FRAC.
#define BF_CCM_ANALOG_PFD_480_PFD1_FRAC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PFD_480_PFD1_FRAC) & BM_CCM_ANALOG_PFD_480_PFD1_FRAC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD1_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD1_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD1_STABLE[14] (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_PFD1_STABLE      (14)      //!< Bit position for CCM_ANALOG_PFD_480_PFD1_STABLE.
#define BM_CCM_ANALOG_PFD_480_PFD1_STABLE      (0x00004000)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD1_STABLE.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD1_STABLE from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD1_STABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_480_PFD1_STABLE) >> BP_CCM_ANALOG_PFD_480_PFD1_STABLE)

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD1_CLKGATE[15] (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd1) is off (power
 * savings). 0: ref_pfd1 fractional divider clock is enabled. Need to assert this bit before PLL is
 * powered down
 */

#define BP_CCM_ANALOG_PFD_480_PFD1_CLKGATE      (15)      //!< Bit position for CCM_ANALOG_PFD_480_PFD1_CLKGATE.
#define BM_CCM_ANALOG_PFD_480_PFD1_CLKGATE      (0x00008000)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD1_CLKGATE.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD1_CLKGATE from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD1_CLKGATE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_480_PFD1_CLKGATE) >> BP_CCM_ANALOG_PFD_480_PFD1_CLKGATE)

//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD1_CLKGATE.
#define BF_CCM_ANALOG_PFD_480_PFD1_CLKGATE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PFD_480_PFD1_CLKGATE) & BM_CCM_ANALOG_PFD_480_PFD1_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD1_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD1_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD2_FRAC[21:16] (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD2_FRAC where PFD2_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_PFD2_FRAC      (16)      //!< Bit position for CCM_ANALOG_PFD_480_PFD2_FRAC.
#define BM_CCM_ANALOG_PFD_480_PFD2_FRAC      (0x003f0000)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD2_FRAC.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD2_FRAC from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD2_FRAC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_480_PFD2_FRAC) >> BP_CCM_ANALOG_PFD_480_PFD2_FRAC)

//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD2_FRAC.
#define BF_CCM_ANALOG_PFD_480_PFD2_FRAC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PFD_480_PFD2_FRAC) & BM_CCM_ANALOG_PFD_480_PFD2_FRAC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD2_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD2_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD2_STABLE[22] (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_PFD2_STABLE      (22)      //!< Bit position for CCM_ANALOG_PFD_480_PFD2_STABLE.
#define BM_CCM_ANALOG_PFD_480_PFD2_STABLE      (0x00400000)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD2_STABLE.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD2_STABLE from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD2_STABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_480_PFD2_STABLE) >> BP_CCM_ANALOG_PFD_480_PFD2_STABLE)

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD2_CLKGATE[23] (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd2) is off (power
 * savings). 0: ref_pfd2 fractional divider clock is enabled. Need to assert this bit before PLL is
 * powered down
 */

#define BP_CCM_ANALOG_PFD_480_PFD2_CLKGATE      (23)      //!< Bit position for CCM_ANALOG_PFD_480_PFD2_CLKGATE.
#define BM_CCM_ANALOG_PFD_480_PFD2_CLKGATE      (0x00800000)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD2_CLKGATE.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD2_CLKGATE from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD2_CLKGATE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_480_PFD2_CLKGATE) >> BP_CCM_ANALOG_PFD_480_PFD2_CLKGATE)

//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD2_CLKGATE.
#define BF_CCM_ANALOG_PFD_480_PFD2_CLKGATE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PFD_480_PFD2_CLKGATE) & BM_CCM_ANALOG_PFD_480_PFD2_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD2_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD2_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD3_FRAC[29:24] (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD3_FRAC where PFD3_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_480_PFD3_FRAC      (24)      //!< Bit position for CCM_ANALOG_PFD_480_PFD3_FRAC.
#define BM_CCM_ANALOG_PFD_480_PFD3_FRAC      (0x3f000000)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD3_FRAC.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD3_FRAC from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD3_FRAC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_480_PFD3_FRAC) >> BP_CCM_ANALOG_PFD_480_PFD3_FRAC)

//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD3_FRAC.
#define BF_CCM_ANALOG_PFD_480_PFD3_FRAC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PFD_480_PFD3_FRAC) & BM_CCM_ANALOG_PFD_480_PFD3_FRAC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD3_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD3_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD3_STABLE[30] (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_480_PFD3_STABLE      (30)      //!< Bit position for CCM_ANALOG_PFD_480_PFD3_STABLE.
#define BM_CCM_ANALOG_PFD_480_PFD3_STABLE      (0x40000000)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD3_STABLE.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD3_STABLE from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD3_STABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_480_PFD3_STABLE) >> BP_CCM_ANALOG_PFD_480_PFD3_STABLE)

/* --- Register HW_CCM_ANALOG_PFD_480, field PFD3_CLKGATE[31] (RW)
 *
 * IO Clock Gate. If set to 1, the 3rd fractional divider clock (reference ref_pfd3) is off (power
 * savings). 0: ref_pfd3 fractional divider clock is enabled. Need to assert this bit before PLL is
 * powered down
 */

#define BP_CCM_ANALOG_PFD_480_PFD3_CLKGATE      (31)      //!< Bit position for CCM_ANALOG_PFD_480_PFD3_CLKGATE.
#define BM_CCM_ANALOG_PFD_480_PFD3_CLKGATE      (0x80000000)  //!< Bit mask for CCM_ANALOG_PFD_480_PFD3_CLKGATE.

//! @brief Get value of CCM_ANALOG_PFD_480_PFD3_CLKGATE from a register value.
#define BG_CCM_ANALOG_PFD_480_PFD3_CLKGATE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_480_PFD3_CLKGATE) >> BP_CCM_ANALOG_PFD_480_PFD3_CLKGATE)

//! @brief Format value for bitfield CCM_ANALOG_PFD_480_PFD3_CLKGATE.
#define BF_CCM_ANALOG_PFD_480_PFD3_CLKGATE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PFD_480_PFD3_CLKGATE) & BM_CCM_ANALOG_PFD_480_PFD3_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_480_PFD3_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_480, PFD3_CLKGATE, v)
#endif

//-------------------------------------------------------------------------------------------
// HW_CCM_ANALOG_PFD_528 - 528MHz Clock (From PLL_SYS) Phase Fractional Divider Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_PFD_528 - 528MHz Clock (From PLL_SYS) Phase Fractional Divider Control Register (RW)
 *
 * Reset value: 0x1018101b
 *
 * The PFD_528 control register provides control for PFD clock generation.  This register controls
 * the 4-phase fractional clock dividers. The fractional clock frequencies are a product of the
 * values in these registers.
 */
typedef union _hw_ccm_analog_pfd_528
{
    reg32_t U;
    struct _hw_ccm_analog_pfd_528_bitfields
    {
        unsigned PFD0_FRAC : 6; //!< [5:0] This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD0_FRAC where PFD0_FRAC is in the range 12-35.
        unsigned PFD0_STABLE : 1; //!< [6] This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD0_CLKGATE : 1; //!< [7] If set to 1, the IO fractional divider clock (reference ref_pfd0) is off (power savings). 0: ref_pfd0 fractional divider clock is enabled. Need to assert this bit before PLL powered down
        unsigned PFD1_FRAC : 6; //!< [13:8] This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD1_FRAC where PFD1_FRAC is in the range 12-35.
        unsigned PFD1_STABLE : 1; //!< [14] This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD1_CLKGATE : 1; //!< [15] IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd1) is off (power savings). 0: ref_pfd1 fractional divider clock is enabled. Need to assert this bit before PLL powered down
        unsigned PFD2_FRAC : 6; //!< [21:16] This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD2_FRAC where PFD2_FRAC is in the range 12-35.
        unsigned PFD2_STABLE : 1; //!< [22] This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD2_CLKGATE : 1; //!< [23] IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd2) is off (power savings). 0: ref_pfd2 fractional divider clock is enabled. Need to assert this bit before PLL powered down
        unsigned PFD3_FRAC : 6; //!< [29:24] This field controls the fractional divide value. The resulting frequency shall be 480*18/PFD3_FRAC where PFD3_FRAC is in the range 12-35.
        unsigned PFD3_STABLE : 1; //!< [30] This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should become stable quickly enough that this field will never need to be used by either device driver or application code. The value inverts when the new programmed fractional divide value has taken effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock output is stable. Note that the value will not invert when the fractional divider is taken out of or placed into clock-gated state.
        unsigned PFD3_CLKGATE : 1; //!< [31] IO Clock Gate. If set to 1, the 3rd fractional divider clock (reference ref_pfd3) is off (power savings). 0: ref_pfd3 fractional divider clock is enabled. Need to assert this bit before PLL powered down
    } B;
} hw_ccm_analog_pfd_528_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_PFD_528 register
 */
#define HW_CCM_ANALOG_PFD_528_ADDR      (REGS_CCM_ANALOG_BASE + 0x100)
#define HW_CCM_ANALOG_PFD_528_SET_ADDR  (HW_CCM_ANALOG_PFD_528_ADDR + 0x4)
#define HW_CCM_ANALOG_PFD_528_CLR_ADDR  (HW_CCM_ANALOG_PFD_528_ADDR + 0x8)
#define HW_CCM_ANALOG_PFD_528_TOG_ADDR  (HW_CCM_ANALOG_PFD_528_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_PFD_528           (*(volatile hw_ccm_analog_pfd_528_t *) HW_CCM_ANALOG_PFD_528_ADDR)
#define HW_CCM_ANALOG_PFD_528_RD()      (HW_CCM_ANALOG_PFD_528.U)
#define HW_CCM_ANALOG_PFD_528_WR(v)     (HW_CCM_ANALOG_PFD_528.U = (v))
#define HW_CCM_ANALOG_PFD_528_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PFD_528_SET_ADDR) = (v))
#define HW_CCM_ANALOG_PFD_528_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PFD_528_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_PFD_528_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_PFD_528_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_PFD_528 bitfields
 */

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD0_FRAC[5:0] (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD0_FRAC where PFD0_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_PFD0_FRAC      (0)      //!< Bit position for CCM_ANALOG_PFD_528_PFD0_FRAC.
#define BM_CCM_ANALOG_PFD_528_PFD0_FRAC      (0x0000003f)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD0_FRAC.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD0_FRAC from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD0_FRAC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_528_PFD0_FRAC) >> BP_CCM_ANALOG_PFD_528_PFD0_FRAC)

//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD0_FRAC.
#define BF_CCM_ANALOG_PFD_528_PFD0_FRAC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PFD_528_PFD0_FRAC) & BM_CCM_ANALOG_PFD_528_PFD0_FRAC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD0_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD0_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD0_STABLE[6] (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_PFD0_STABLE      (6)      //!< Bit position for CCM_ANALOG_PFD_528_PFD0_STABLE.
#define BM_CCM_ANALOG_PFD_528_PFD0_STABLE      (0x00000040)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD0_STABLE.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD0_STABLE from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD0_STABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_528_PFD0_STABLE) >> BP_CCM_ANALOG_PFD_528_PFD0_STABLE)

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD0_CLKGATE[7] (RW)
 *
 * If set to 1, the IO fractional divider clock (reference ref_pfd0) is off (power savings). 0:
 * ref_pfd0 fractional divider clock is enabled. Need to assert this bit before PLL powered down
 */

#define BP_CCM_ANALOG_PFD_528_PFD0_CLKGATE      (7)      //!< Bit position for CCM_ANALOG_PFD_528_PFD0_CLKGATE.
#define BM_CCM_ANALOG_PFD_528_PFD0_CLKGATE      (0x00000080)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD0_CLKGATE.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD0_CLKGATE from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD0_CLKGATE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_528_PFD0_CLKGATE) >> BP_CCM_ANALOG_PFD_528_PFD0_CLKGATE)

//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD0_CLKGATE.
#define BF_CCM_ANALOG_PFD_528_PFD0_CLKGATE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PFD_528_PFD0_CLKGATE) & BM_CCM_ANALOG_PFD_528_PFD0_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD0_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD0_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD0_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD1_FRAC[13:8] (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD1_FRAC where PFD1_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_PFD1_FRAC      (8)      //!< Bit position for CCM_ANALOG_PFD_528_PFD1_FRAC.
#define BM_CCM_ANALOG_PFD_528_PFD1_FRAC      (0x00003f00)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD1_FRAC.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD1_FRAC from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD1_FRAC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_528_PFD1_FRAC) >> BP_CCM_ANALOG_PFD_528_PFD1_FRAC)

//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD1_FRAC.
#define BF_CCM_ANALOG_PFD_528_PFD1_FRAC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PFD_528_PFD1_FRAC) & BM_CCM_ANALOG_PFD_528_PFD1_FRAC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD1_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD1_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD1_STABLE[14] (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_PFD1_STABLE      (14)      //!< Bit position for CCM_ANALOG_PFD_528_PFD1_STABLE.
#define BM_CCM_ANALOG_PFD_528_PFD1_STABLE      (0x00004000)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD1_STABLE.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD1_STABLE from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD1_STABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_528_PFD1_STABLE) >> BP_CCM_ANALOG_PFD_528_PFD1_STABLE)

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD1_CLKGATE[15] (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd1) is off (power
 * savings). 0: ref_pfd1 fractional divider clock is enabled. Need to assert this bit before PLL
 * powered down
 */

#define BP_CCM_ANALOG_PFD_528_PFD1_CLKGATE      (15)      //!< Bit position for CCM_ANALOG_PFD_528_PFD1_CLKGATE.
#define BM_CCM_ANALOG_PFD_528_PFD1_CLKGATE      (0x00008000)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD1_CLKGATE.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD1_CLKGATE from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD1_CLKGATE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_528_PFD1_CLKGATE) >> BP_CCM_ANALOG_PFD_528_PFD1_CLKGATE)

//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD1_CLKGATE.
#define BF_CCM_ANALOG_PFD_528_PFD1_CLKGATE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PFD_528_PFD1_CLKGATE) & BM_CCM_ANALOG_PFD_528_PFD1_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD1_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD1_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD1_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD2_FRAC[21:16] (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD2_FRAC where PFD2_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_PFD2_FRAC      (16)      //!< Bit position for CCM_ANALOG_PFD_528_PFD2_FRAC.
#define BM_CCM_ANALOG_PFD_528_PFD2_FRAC      (0x003f0000)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD2_FRAC.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD2_FRAC from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD2_FRAC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_528_PFD2_FRAC) >> BP_CCM_ANALOG_PFD_528_PFD2_FRAC)

//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD2_FRAC.
#define BF_CCM_ANALOG_PFD_528_PFD2_FRAC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PFD_528_PFD2_FRAC) & BM_CCM_ANALOG_PFD_528_PFD2_FRAC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD2_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD2_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD2_STABLE[22] (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_PFD2_STABLE      (22)      //!< Bit position for CCM_ANALOG_PFD_528_PFD2_STABLE.
#define BM_CCM_ANALOG_PFD_528_PFD2_STABLE      (0x00400000)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD2_STABLE.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD2_STABLE from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD2_STABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_528_PFD2_STABLE) >> BP_CCM_ANALOG_PFD_528_PFD2_STABLE)

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD2_CLKGATE[23] (RW)
 *
 * IO Clock Gate. If set to 1, the IO fractional divider clock (reference ref_pfd2) is off (power
 * savings). 0: ref_pfd2 fractional divider clock is enabled. Need to assert this bit before PLL
 * powered down
 */

#define BP_CCM_ANALOG_PFD_528_PFD2_CLKGATE      (23)      //!< Bit position for CCM_ANALOG_PFD_528_PFD2_CLKGATE.
#define BM_CCM_ANALOG_PFD_528_PFD2_CLKGATE      (0x00800000)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD2_CLKGATE.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD2_CLKGATE from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD2_CLKGATE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_528_PFD2_CLKGATE) >> BP_CCM_ANALOG_PFD_528_PFD2_CLKGATE)

//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD2_CLKGATE.
#define BF_CCM_ANALOG_PFD_528_PFD2_CLKGATE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PFD_528_PFD2_CLKGATE) & BM_CCM_ANALOG_PFD_528_PFD2_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD2_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD2_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD2_CLKGATE, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD3_FRAC[29:24] (RW)
 *
 * This field controls the fractional divide value. The resulting frequency shall be
 * 480*18/PFD3_FRAC where PFD3_FRAC is in the range 12-35.
 */

#define BP_CCM_ANALOG_PFD_528_PFD3_FRAC      (24)      //!< Bit position for CCM_ANALOG_PFD_528_PFD3_FRAC.
#define BM_CCM_ANALOG_PFD_528_PFD3_FRAC      (0x3f000000)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD3_FRAC.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD3_FRAC from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD3_FRAC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_528_PFD3_FRAC) >> BP_CCM_ANALOG_PFD_528_PFD3_FRAC)

//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD3_FRAC.
#define BF_CCM_ANALOG_PFD_528_PFD3_FRAC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PFD_528_PFD3_FRAC) & BM_CCM_ANALOG_PFD_528_PFD3_FRAC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_FRAC field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD3_FRAC(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD3_FRAC, v)
#endif

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD3_STABLE[30] (RO)
 *
 * This read-only bitfield is for DIAGNOSTIC PURPOSES ONLY since the fractional divider should
 * become stable quickly enough that this field will never need to be used by either device driver
 * or application code. The value inverts when the new programmed fractional divide value has taken
 * effect. Read this bit, program the new value, and when this bit inverts, the phase divider clock
 * output is stable. Note that the value will not invert when the fractional divider is taken out of
 * or placed into clock-gated state.
 */

#define BP_CCM_ANALOG_PFD_528_PFD3_STABLE      (30)      //!< Bit position for CCM_ANALOG_PFD_528_PFD3_STABLE.
#define BM_CCM_ANALOG_PFD_528_PFD3_STABLE      (0x40000000)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD3_STABLE.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD3_STABLE from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD3_STABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_528_PFD3_STABLE) >> BP_CCM_ANALOG_PFD_528_PFD3_STABLE)

/* --- Register HW_CCM_ANALOG_PFD_528, field PFD3_CLKGATE[31] (RW)
 *
 * IO Clock Gate. If set to 1, the 3rd fractional divider clock (reference ref_pfd3) is off (power
 * savings). 0: ref_pfd3 fractional divider clock is enabled. Need to assert this bit before PLL
 * powered down
 */

#define BP_CCM_ANALOG_PFD_528_PFD3_CLKGATE      (31)      //!< Bit position for CCM_ANALOG_PFD_528_PFD3_CLKGATE.
#define BM_CCM_ANALOG_PFD_528_PFD3_CLKGATE      (0x80000000)  //!< Bit mask for CCM_ANALOG_PFD_528_PFD3_CLKGATE.

//! @brief Get value of CCM_ANALOG_PFD_528_PFD3_CLKGATE from a register value.
#define BG_CCM_ANALOG_PFD_528_PFD3_CLKGATE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_PFD_528_PFD3_CLKGATE) >> BP_CCM_ANALOG_PFD_528_PFD3_CLKGATE)

//! @brief Format value for bitfield CCM_ANALOG_PFD_528_PFD3_CLKGATE.
#define BF_CCM_ANALOG_PFD_528_PFD3_CLKGATE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_PFD_528_PFD3_CLKGATE) & BM_CCM_ANALOG_PFD_528_PFD3_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PFD3_CLKGATE field to a new value.
#define BW_CCM_ANALOG_PFD_528_PFD3_CLKGATE(v)   BF_CS1(CCM_ANALOG_PFD_528, PFD3_CLKGATE, v)
#endif

//-------------------------------------------------------------------------------------------
// HW_CCM_ANALOG_MISC0 - Miscellaneous Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_MISC0 - Miscellaneous Control Register (RW)
 *
 * Reset value: 0x02000000
 *
 * This register defines the control for miscellaneous CCM Analog blocks.
 */
typedef union _hw_ccm_analog_misc0
{
    reg32_t U;
    struct _hw_ccm_analog_misc0_bitfields
    {
        unsigned RESERVED0 : 11; //!< [10:0] 
        unsigned STOP_MODE_CONFIG : 2; //!< [12:11] Configure the analog behavior in stop mode. 0 - all analog except rtc powered down on stop mode assertion. XtalOsc=on, RCOsc=off
        unsigned RESERVED1 : 19; //!< [31:13] 
    } B;
} hw_ccm_analog_misc0_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_MISC0 register
 */
#define HW_CCM_ANALOG_MISC0_ADDR      (REGS_CCM_ANALOG_BASE + 0x150)
#define HW_CCM_ANALOG_MISC0_SET_ADDR  (HW_CCM_ANALOG_MISC0_ADDR + 0x4)
#define HW_CCM_ANALOG_MISC0_CLR_ADDR  (HW_CCM_ANALOG_MISC0_ADDR + 0x8)
#define HW_CCM_ANALOG_MISC0_TOG_ADDR  (HW_CCM_ANALOG_MISC0_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_MISC0           (*(volatile hw_ccm_analog_misc0_t *) HW_CCM_ANALOG_MISC0_ADDR)
#define HW_CCM_ANALOG_MISC0_RD()      (HW_CCM_ANALOG_MISC0.U)
#define HW_CCM_ANALOG_MISC0_WR(v)     (HW_CCM_ANALOG_MISC0.U = (v))
#define HW_CCM_ANALOG_MISC0_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_MISC0_SET_ADDR) = (v))
#define HW_CCM_ANALOG_MISC0_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_MISC0_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_MISC0_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_MISC0_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_MISC0 bitfields
 */

/* --- Register HW_CCM_ANALOG_MISC0, field STOP_MODE_CONFIG[12:11] (RW)
 *
 * Configure the analog behavior in stop mode. 0 - all analog except rtc powered down on stop mode
 * assertion. XtalOsc=on, RCOsc=off
 */

#define BP_CCM_ANALOG_MISC0_STOP_MODE_CONFIG      (11)      //!< Bit position for CCM_ANALOG_MISC0_STOP_MODE_CONFIG.
#define BM_CCM_ANALOG_MISC0_STOP_MODE_CONFIG      (0x00001800)  //!< Bit mask for CCM_ANALOG_MISC0_STOP_MODE_CONFIG.

//! @brief Get value of CCM_ANALOG_MISC0_STOP_MODE_CONFIG from a register value.
#define BG_CCM_ANALOG_MISC0_STOP_MODE_CONFIG(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_MISC0_STOP_MODE_CONFIG) >> BP_CCM_ANALOG_MISC0_STOP_MODE_CONFIG)

//! @brief Format value for bitfield CCM_ANALOG_MISC0_STOP_MODE_CONFIG.
#define BF_CCM_ANALOG_MISC0_STOP_MODE_CONFIG(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_MISC0_STOP_MODE_CONFIG) & BM_CCM_ANALOG_MISC0_STOP_MODE_CONFIG)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STOP_MODE_CONFIG field to a new value.
#define BW_CCM_ANALOG_MISC0_STOP_MODE_CONFIG(v)   BF_CS1(CCM_ANALOG_MISC0, STOP_MODE_CONFIG, v)
#endif

//-------------------------------------------------------------------------------------------
// HW_CCM_ANALOG_MISC2 - Miscellaneous Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CCM_ANALOG_MISC2 - Miscellaneous Control Register (RW)
 *
 * Reset value: 0x00272727
 *
 * This register defines the control for miscellaneous CCM Analog blocks.
 */
typedef union _hw_ccm_analog_misc2
{
    reg32_t U;
    struct _hw_ccm_analog_misc2_bitfields
    {
        unsigned RESERVED0 : 7; //!< [6:0] 
        unsigned PLL3_DISABLE : 1; //!< [7] Default value of "0". Should be set to "1" to turn off the USB-PLL(PLL3) in run mode
        unsigned RESERVED1 : 7; //!< [14:8] 
        unsigned AUDIO_DIV_LSB : 1; //!< [15] LSB of Post-divider for Audio PLL: 0x0=div-by-1(default), 0x1=div-by-2, 0x2=div-by-1, 0x3=div-by-4. The output clock of the video PLL should be gated prior to changing this divider to prevent glitches.
        unsigned RESERVED2 : 7; //!< [22:16] 
        unsigned AUDIO_DIV_MSB : 1; //!< [23] MSB of Post-divider for Audio PLL: 0x0=div-by-1(default), 0x1=div-by-2, 0x2=div-by-1, 0x3=div-by-4. The output clock of the video PLL should be gated prior to changing this divider to prevent glitches.
        unsigned RESERVED3 : 6; //!< [29:24] 
        unsigned VIDEO_DIV : 2; //!< [31:30] Post-divider for video: 0x0=div-by-1(default), 0x1=div-by-2, 0x2=div-by-1, 0x3=div-by-4. The output clock of the video PLL should be gated prior to changing this divider to prevent glitches.
    } B;
} hw_ccm_analog_misc2_t;
#endif

/*
 * constants & macros for entire CCM_ANALOG_MISC2 register
 */
#define HW_CCM_ANALOG_MISC2_ADDR      (REGS_CCM_ANALOG_BASE + 0x170)
#define HW_CCM_ANALOG_MISC2_SET_ADDR  (HW_CCM_ANALOG_MISC2_ADDR + 0x4)
#define HW_CCM_ANALOG_MISC2_CLR_ADDR  (HW_CCM_ANALOG_MISC2_ADDR + 0x8)
#define HW_CCM_ANALOG_MISC2_TOG_ADDR  (HW_CCM_ANALOG_MISC2_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_CCM_ANALOG_MISC2           (*(volatile hw_ccm_analog_misc2_t *) HW_CCM_ANALOG_MISC2_ADDR)
#define HW_CCM_ANALOG_MISC2_RD()      (HW_CCM_ANALOG_MISC2.U)
#define HW_CCM_ANALOG_MISC2_WR(v)     (HW_CCM_ANALOG_MISC2.U = (v))
#define HW_CCM_ANALOG_MISC2_SET(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_MISC2_SET_ADDR) = (v))
#define HW_CCM_ANALOG_MISC2_CLR(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_MISC2_CLR_ADDR) = (v))
#define HW_CCM_ANALOG_MISC2_TOG(v)    ((*(volatile reg32_t *) HW_CCM_ANALOG_MISC2_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual CCM_ANALOG_MISC2 bitfields
 */

/* --- Register HW_CCM_ANALOG_MISC2, field PLL3_DISABLE[7] (RW)
 *
 * Default value of "0". Should be set to "1" to turn off the USB-PLL(PLL3) in run mode
 */

#define BP_CCM_ANALOG_MISC2_PLL3_DISABLE      (7)      //!< Bit position for CCM_ANALOG_MISC2_PLL3_DISABLE.
#define BM_CCM_ANALOG_MISC2_PLL3_DISABLE      (0x00000080)  //!< Bit mask for CCM_ANALOG_MISC2_PLL3_DISABLE.

//! @brief Get value of CCM_ANALOG_MISC2_PLL3_DISABLE from a register value.
#define BG_CCM_ANALOG_MISC2_PLL3_DISABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_MISC2_PLL3_DISABLE) >> BP_CCM_ANALOG_MISC2_PLL3_DISABLE)

//! @brief Format value for bitfield CCM_ANALOG_MISC2_PLL3_DISABLE.
#define BF_CCM_ANALOG_MISC2_PLL3_DISABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_MISC2_PLL3_DISABLE) & BM_CCM_ANALOG_MISC2_PLL3_DISABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLL3_DISABLE field to a new value.
#define BW_CCM_ANALOG_MISC2_PLL3_DISABLE(v)   BF_CS1(CCM_ANALOG_MISC2, PLL3_DISABLE, v)
#endif

/* --- Register HW_CCM_ANALOG_MISC2, field AUDIO_DIV_LSB[15] (RW)
 *
 * LSB of Post-divider for Audio PLL: 0x0=div-by-1(default), 0x1=div-by-2, 0x2=div-by-1, 0x3=div-
 * by-4. The output clock of the video PLL should be gated prior to changing this divider to prevent
 * glitches.
 */

#define BP_CCM_ANALOG_MISC2_AUDIO_DIV_LSB      (15)      //!< Bit position for CCM_ANALOG_MISC2_AUDIO_DIV_LSB.
#define BM_CCM_ANALOG_MISC2_AUDIO_DIV_LSB      (0x00008000)  //!< Bit mask for CCM_ANALOG_MISC2_AUDIO_DIV_LSB.

//! @brief Get value of CCM_ANALOG_MISC2_AUDIO_DIV_LSB from a register value.
#define BG_CCM_ANALOG_MISC2_AUDIO_DIV_LSB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_MISC2_AUDIO_DIV_LSB) >> BP_CCM_ANALOG_MISC2_AUDIO_DIV_LSB)

//! @brief Format value for bitfield CCM_ANALOG_MISC2_AUDIO_DIV_LSB.
#define BF_CCM_ANALOG_MISC2_AUDIO_DIV_LSB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_MISC2_AUDIO_DIV_LSB) & BM_CCM_ANALOG_MISC2_AUDIO_DIV_LSB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDIO_DIV_LSB field to a new value.
#define BW_CCM_ANALOG_MISC2_AUDIO_DIV_LSB(v)   BF_CS1(CCM_ANALOG_MISC2, AUDIO_DIV_LSB, v)
#endif

/* --- Register HW_CCM_ANALOG_MISC2, field AUDIO_DIV_MSB[23] (RW)
 *
 * MSB of Post-divider for Audio PLL: 0x0=div-by-1(default), 0x1=div-by-2, 0x2=div-by-1, 0x3=div-
 * by-4. The output clock of the video PLL should be gated prior to changing this divider to prevent
 * glitches.
 */

#define BP_CCM_ANALOG_MISC2_AUDIO_DIV_MSB      (23)      //!< Bit position for CCM_ANALOG_MISC2_AUDIO_DIV_MSB.
#define BM_CCM_ANALOG_MISC2_AUDIO_DIV_MSB      (0x00800000)  //!< Bit mask for CCM_ANALOG_MISC2_AUDIO_DIV_MSB.

//! @brief Get value of CCM_ANALOG_MISC2_AUDIO_DIV_MSB from a register value.
#define BG_CCM_ANALOG_MISC2_AUDIO_DIV_MSB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_MISC2_AUDIO_DIV_MSB) >> BP_CCM_ANALOG_MISC2_AUDIO_DIV_MSB)

//! @brief Format value for bitfield CCM_ANALOG_MISC2_AUDIO_DIV_MSB.
#define BF_CCM_ANALOG_MISC2_AUDIO_DIV_MSB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_MISC2_AUDIO_DIV_MSB) & BM_CCM_ANALOG_MISC2_AUDIO_DIV_MSB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AUDIO_DIV_MSB field to a new value.
#define BW_CCM_ANALOG_MISC2_AUDIO_DIV_MSB(v)   BF_CS1(CCM_ANALOG_MISC2, AUDIO_DIV_MSB, v)
#endif

/* --- Register HW_CCM_ANALOG_MISC2, field VIDEO_DIV[31:30] (RW)
 *
 * Post-divider for video: 0x0=div-by-1(default), 0x1=div-by-2, 0x2=div-by-1, 0x3=div-by-4. The
 * output clock of the video PLL should be gated prior to changing this divider to prevent glitches.
 */

#define BP_CCM_ANALOG_MISC2_VIDEO_DIV      (30)      //!< Bit position for CCM_ANALOG_MISC2_VIDEO_DIV.
#define BM_CCM_ANALOG_MISC2_VIDEO_DIV      (0xc0000000)  //!< Bit mask for CCM_ANALOG_MISC2_VIDEO_DIV.

//! @brief Get value of CCM_ANALOG_MISC2_VIDEO_DIV from a register value.
#define BG_CCM_ANALOG_MISC2_VIDEO_DIV(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_CCM_ANALOG_MISC2_VIDEO_DIV) >> BP_CCM_ANALOG_MISC2_VIDEO_DIV)

//! @brief Format value for bitfield CCM_ANALOG_MISC2_VIDEO_DIV.
#define BF_CCM_ANALOG_MISC2_VIDEO_DIV(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_CCM_ANALOG_MISC2_VIDEO_DIV) & BM_CCM_ANALOG_MISC2_VIDEO_DIV)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VIDEO_DIV field to a new value.
#define BW_CCM_ANALOG_MISC2_VIDEO_DIV(v)   BF_CS1(CCM_ANALOG_MISC2, VIDEO_DIV, v)
#endif


/*!
 * @brief All CCM_ANALOG module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_ccm_analog
{
    volatile hw_ccm_analog_pll_arm_t PLL_ARM; //!< Analog ARM PLL control Register
    volatile reg32_t PLL_ARM_SET; //!< Analog ARM PLL control Register Set
    volatile reg32_t PLL_ARM_CLR; //!< Analog ARM PLL control Register Clear
    volatile reg32_t PLL_ARM_TOG; //!< Analog ARM PLL control Register Toggle
    volatile hw_ccm_analog_pll_usb1_t PLL_USB1; //!< Analog USB1 480MHz PLL Control Register
    volatile reg32_t PLL_USB1_SET; //!< Analog USB1 480MHz PLL Control Register Set
    volatile reg32_t PLL_USB1_CLR; //!< Analog USB1 480MHz PLL Control Register Clear
    volatile reg32_t PLL_USB1_TOG; //!< Analog USB1 480MHz PLL Control Register Toggle
    volatile hw_ccm_analog_pll_usb2_t PLL_USB2; //!< Analog USB2 480MHz PLL Control Register
    volatile reg32_t PLL_USB2_SET; //!< Analog USB2 480MHz PLL Control Register Set
    volatile reg32_t PLL_USB2_CLR; //!< Analog USB2 480MHz PLL Control Register Clear
    volatile reg32_t PLL_USB2_TOG; //!< Analog USB2 480MHz PLL Control Register Toggle
    volatile hw_ccm_analog_pll_sys_t PLL_SYS; //!< Analog 528MHz System PLL Control Register
    volatile reg32_t PLL_SYS_SET; //!< Analog 528MHz System PLL Control Register Set
    volatile reg32_t PLL_SYS_CLR; //!< Analog 528MHz System PLL Control Register Clear
    volatile reg32_t PLL_SYS_TOG; //!< Analog 528MHz System PLL Control Register Toggle
    reg32_t _reserved0[12];
    volatile hw_ccm_analog_pll_audio_t PLL_AUDIO; //!< Analog Audio PLL control Register
    volatile reg32_t PLL_AUDIO_SET; //!< Analog Audio PLL control Register Set
    volatile reg32_t PLL_AUDIO_CLR; //!< Analog Audio PLL control Register Clear
    volatile reg32_t PLL_AUDIO_TOG; //!< Analog Audio PLL control Register Toggle
    volatile hw_ccm_analog_pll_audio_num_t PLL_AUDIO_NUM; //!< Numerator of Audio PLL Fractional Loop Divider Register
    reg32_t _reserved1[3];
    volatile hw_ccm_analog_pll_audio_denom_t PLL_AUDIO_DENOM; //!< Denominator of Audio PLL Fractional Loop Divider Register
    reg32_t _reserved2[3];
    volatile hw_ccm_analog_pll_video_t PLL_VIDEO; //!< Analog Video PLL control Register
    volatile reg32_t PLL_VIDEO_SET; //!< Analog Video PLL control Register Set
    volatile reg32_t PLL_VIDEO_CLR; //!< Analog Video PLL control Register Clear
    volatile reg32_t PLL_VIDEO_TOG; //!< Analog Video PLL control Register Toggle
    volatile hw_ccm_analog_pll_video_num_t PLL_VIDEO_NUM; //!< Numerator of Video PLL Fractional Loop Divider Register
    reg32_t _reserved3[3];
    volatile hw_ccm_analog_pll_video_denom_t PLL_VIDEO_DENOM; //!< Denominator of Video PLL Fractional Loop Divider Register
    reg32_t _reserved4[7];
    volatile hw_ccm_analog_pll_enet_t PLL_ENET; //!< Analog ENET PLL Control Register
    volatile reg32_t PLL_ENET_SET; //!< Analog ENET PLL Control Register Set
    volatile reg32_t PLL_ENET_CLR; //!< Analog ENET PLL Control Register Clear
    volatile reg32_t PLL_ENET_TOG; //!< Analog ENET PLL Control Register Toggle
    volatile hw_ccm_analog_pfd_480_t PFD_480; //!< 480MHz Clock (from PLL_USB2) Phase Fractional Divider Control Register
    volatile reg32_t PFD_480_SET; //!< 480MHz Clock (from PLL_USB2) Phase Fractional Divider Control Register Set
    volatile reg32_t PFD_480_CLR; //!< 480MHz Clock (from PLL_USB2) Phase Fractional Divider Control Register Clear
    volatile reg32_t PFD_480_TOG; //!< 480MHz Clock (from PLL_USB2) Phase Fractional Divider Control Register Toggle
    volatile hw_ccm_analog_pfd_528_t PFD_528; //!< 528MHz Clock (From PLL_SYS) Phase Fractional Divider Control Register
    volatile reg32_t PFD_528_SET; //!< 528MHz Clock (From PLL_SYS) Phase Fractional Divider Control Register Set
    volatile reg32_t PFD_528_CLR; //!< 528MHz Clock (From PLL_SYS) Phase Fractional Divider Control Register Clear
    volatile reg32_t PFD_528_TOG; //!< 528MHz Clock (From PLL_SYS) Phase Fractional Divider Control Register Toggle
    reg32_t _reserved5[16];
    volatile hw_ccm_analog_misc0_t MISC0; //!< Miscellaneous Control Register
    volatile reg32_t MISC0_SET; //!< Miscellaneous Control Register Set
    volatile reg32_t MISC0_CLR; //!< Miscellaneous Control Register Clear
    volatile reg32_t MISC0_TOG; //!< Miscellaneous Control Register Toggle
    reg32_t _reserved6[4];
    volatile hw_ccm_analog_misc2_t MISC2; //!< Miscellaneous Control Register
    volatile reg32_t MISC2_SET; //!< Miscellaneous Control Register Set
    volatile reg32_t MISC2_CLR; //!< Miscellaneous Control Register Clear
    volatile reg32_t MISC2_TOG; //!< Miscellaneous Control Register Toggle
} hw_ccm_analog_t;
#pragma pack()

//! @brief Macro to access all CCM_ANALOG registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_CCM_ANALOG(0)</code>.
#define HW_CCM_ANALOG     (*(volatile hw_ccm_analog_t *) REGS_CCM_ANALOG_BASE)

#endif


#endif // __HW_CCM_ANALOG_REGISTERS_H__
