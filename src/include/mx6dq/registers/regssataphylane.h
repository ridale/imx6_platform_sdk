/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_SATAPHY_LANE0_REGISTERS_H__
#define __HW_SATAPHY_LANE0_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6DQ SATAPHY_LANE0 registers defined in this header file.
 *
 * - HW_SATAPHY_LANE0_TX_STAT - Transmit Input Status Register
 * - HW_SATAPHY_LANE0_RX_STAT - Receiver Input Status Register
 * - HW_SATAPHY_LANE0_OUT_STAT - Output Status Register
 * - HW_SATAPHY_LANE0_TX_OVRD - Transmit Input Override Register
 * - HW_SATAPHY_LANE0_RX_OVRD - Receive Input Override Register
 * - HW_SATAPHY_LANE0_OUT_OVRD - Output Override Register
 * - HW_SATAPHY_LANE0_DBG_CTL - Debug Control Register
 * - HW_SATAPHY_LANE0_PG_CTL - Pattern Generator Control Register
 * - HW_SATAPHY_LANE0_PM_CTL - Pattern Matcher Control Register
 * - HW_SATAPHY_LANE0_PM_ERR - Pattern Matcher Error Register
 * - HW_SATAPHY_LANE0_DPLL_PHASE - DPLL Phase Register
 * - HW_SATAPHY_LANE0_DPLL_FREQ - DPLL Frequency Register
 * - HW_SATAPHY_LANE0_SCOPE_CTL - Scope Control Register
 * - HW_SATAPHY_LANE0_RX_CTL - Receiver Control Register
 * - HW_SATAPHY_LANE0_RX_DBG - Receiver Debug Register
 * - HW_SATAPHY_LANE0_RX_ANA_CONTROL - Receive Analog Control Register
 * - HW_SATAPHY_LANE0_RX_ANA_ATB - Receive ATB Register
 * - HW_SATAPHY_LANE0_PLL_PRG2 - Rx PLL Programming 2 Register
 * - HW_SATAPHY_LANE0_PLL_PRG1 - Rx PLL Programming 1 Register
 * - HW_SATAPHY_LANE0_PLL_PRG3 - Rx PLL Measurement Register
 * - HW_SATAPHY_LANE0_TX_ANA_ATBSEL1 - Transmit ATB 1 Control Register
 * - HW_SATAPHY_LANE0_TX_ANA_ATBSEL2 - Transmit ATB 2 Control Register
 * - HW_SATAPHY_LANE0_TX_ANA_CONTROL - Transmit Analog Control Register
 *
 */

//! @name Module base addresses
//@{
#ifndef REGS_SATAPHY_LANE0_BASE
#define HW_SATAPHY_LANE0_INSTANCE_COUNT (0) //!< Number of instances of the SATAPHY_LANE0 module.
#define REGS_SATAPHY_LANE0_BASE (0x00000000) //!< Base address for SATAPHY_LANE0.
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
// HW_SATAPHY_LANE0_TX_STAT - Transmit Input Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_TX_STAT - Transmit Input Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x2001  Reset value: 16'b xxxx xxxx xxxx xxxx (depends on inputs)  This register
 * indicates the status of transmit control inputs.
 */
typedef union _hw_sataphy_lane0_tx_stat
{
    reg16_t U;
    struct _hw_sataphy_lane0_tx_stat_bitfields
    {
        unsigned short TX_CKO_EN : 1; //!< [0] tx_cko clock enable
        unsigned short TX_EN : 3; //!< [3:1] Transmit enable control
        unsigned short TX_CLK_ALIGN : 1; //!< [4] Command to align clocks
        unsigned short RESERVED0 : 1; //!< [5] Always reads as 0
        unsigned short TX_BOOST : 4; //!< [9:6] Boost amount control
        unsigned short TX_ATTEN : 3; //!< [12:10] Attenuation amount control
        unsigned short TX_EDGERATE : 2; //!< [14:13] Edge rate control
        unsigned short RESERVED1 : 1; //!< [15] Always reads as 1
    } B;
} hw_sataphy_lane0_tx_stat_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_TX_STAT register
 */
#define HW_SATAPHY_LANE0_TX_STAT_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2001)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_TX_STAT           (*(volatile hw_sataphy_lane0_tx_stat_t *) HW_SATAPHY_LANE0_TX_STAT_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_TX_STAT bitfields
 */

/* --- Register HW_SATAPHY_LANE0_TX_STAT, field TX_CKO_EN[0] (RO)
 *
 * tx_cko clock enable
 */

#define BP_SATAPHY_LANE0_TX_STAT_TX_CKO_EN      (0)      //!< Bit position for SATAPHY_LANE0_TX_STAT_TX_CKO_EN.
#define BM_SATAPHY_LANE0_TX_STAT_TX_CKO_EN      (0x00000001)  //!< Bit mask for SATAPHY_LANE0_TX_STAT_TX_CKO_EN.

//! @brief Get value of SATAPHY_LANE0_TX_STAT_TX_CKO_EN from a register value.
#define BG_SATAPHY_LANE0_TX_STAT_TX_CKO_EN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_STAT_TX_CKO_EN) >> BP_SATAPHY_LANE0_TX_STAT_TX_CKO_EN)

/* --- Register HW_SATAPHY_LANE0_TX_STAT, field TX_EN[3:1] (RO)
 *
 * Transmit enable control
 */

#define BP_SATAPHY_LANE0_TX_STAT_TX_EN      (1)      //!< Bit position for SATAPHY_LANE0_TX_STAT_TX_EN.
#define BM_SATAPHY_LANE0_TX_STAT_TX_EN      (0x0000000e)  //!< Bit mask for SATAPHY_LANE0_TX_STAT_TX_EN.

//! @brief Get value of SATAPHY_LANE0_TX_STAT_TX_EN from a register value.
#define BG_SATAPHY_LANE0_TX_STAT_TX_EN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_STAT_TX_EN) >> BP_SATAPHY_LANE0_TX_STAT_TX_EN)

/* --- Register HW_SATAPHY_LANE0_TX_STAT, field TX_CLK_ALIGN[4] (RO)
 *
 * Command to align clocks
 */

#define BP_SATAPHY_LANE0_TX_STAT_TX_CLK_ALIGN      (4)      //!< Bit position for SATAPHY_LANE0_TX_STAT_TX_CLK_ALIGN.
#define BM_SATAPHY_LANE0_TX_STAT_TX_CLK_ALIGN      (0x00000010)  //!< Bit mask for SATAPHY_LANE0_TX_STAT_TX_CLK_ALIGN.

//! @brief Get value of SATAPHY_LANE0_TX_STAT_TX_CLK_ALIGN from a register value.
#define BG_SATAPHY_LANE0_TX_STAT_TX_CLK_ALIGN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_STAT_TX_CLK_ALIGN) >> BP_SATAPHY_LANE0_TX_STAT_TX_CLK_ALIGN)

/* --- Register HW_SATAPHY_LANE0_TX_STAT, field TX_BOOST[9:6] (RO)
 *
 * Boost amount control
 */

#define BP_SATAPHY_LANE0_TX_STAT_TX_BOOST      (6)      //!< Bit position for SATAPHY_LANE0_TX_STAT_TX_BOOST.
#define BM_SATAPHY_LANE0_TX_STAT_TX_BOOST      (0x000003c0)  //!< Bit mask for SATAPHY_LANE0_TX_STAT_TX_BOOST.

//! @brief Get value of SATAPHY_LANE0_TX_STAT_TX_BOOST from a register value.
#define BG_SATAPHY_LANE0_TX_STAT_TX_BOOST(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_STAT_TX_BOOST) >> BP_SATAPHY_LANE0_TX_STAT_TX_BOOST)

/* --- Register HW_SATAPHY_LANE0_TX_STAT, field TX_ATTEN[12:10] (RO)
 *
 * Attenuation amount control
 */

#define BP_SATAPHY_LANE0_TX_STAT_TX_ATTEN      (10)      //!< Bit position for SATAPHY_LANE0_TX_STAT_TX_ATTEN.
#define BM_SATAPHY_LANE0_TX_STAT_TX_ATTEN      (0x00001c00)  //!< Bit mask for SATAPHY_LANE0_TX_STAT_TX_ATTEN.

//! @brief Get value of SATAPHY_LANE0_TX_STAT_TX_ATTEN from a register value.
#define BG_SATAPHY_LANE0_TX_STAT_TX_ATTEN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_STAT_TX_ATTEN) >> BP_SATAPHY_LANE0_TX_STAT_TX_ATTEN)

/* --- Register HW_SATAPHY_LANE0_TX_STAT, field TX_EDGERATE[14:13] (RO)
 *
 * Edge rate control
 */

#define BP_SATAPHY_LANE0_TX_STAT_TX_EDGERATE      (13)      //!< Bit position for SATAPHY_LANE0_TX_STAT_TX_EDGERATE.
#define BM_SATAPHY_LANE0_TX_STAT_TX_EDGERATE      (0x00006000)  //!< Bit mask for SATAPHY_LANE0_TX_STAT_TX_EDGERATE.

//! @brief Get value of SATAPHY_LANE0_TX_STAT_TX_EDGERATE from a register value.
#define BG_SATAPHY_LANE0_TX_STAT_TX_EDGERATE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_STAT_TX_EDGERATE) >> BP_SATAPHY_LANE0_TX_STAT_TX_EDGERATE)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_RX_STAT - Receiver Input Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_RX_STAT - Receiver Input Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x2002  Reset value: 16'b xxxx xxxx xxxx xxxx (depends on inputs)  This register
 * indicates the status of receiver control inputs.
 */
typedef union _hw_sataphy_lane0_rx_stat
{
    reg16_t U;
    struct _hw_sataphy_lane0_rx_stat_bitfields
    {
        unsigned short HALF_RATE : 1; //!< [0] Digital half-rate data control
        unsigned short RX_PLL_PWRON : 1; //!< [1] PLL power state control
        unsigned short RX_EN : 1; //!< [2] Receiver enable control
        unsigned short RX_ALIGN_EN : 1; //!< [3] Receiver alignment enable
        unsigned short RX_TERM_EN : 1; //!< [4] Receiver termination enable
        unsigned short RX_EQ_VAL : 3; //!< [7:5] Equalization amount control
        unsigned short RX_DPLL_MODE : 3; //!< [10:8] DPLL mode control
        unsigned short DPLL_RESET : 1; //!< [11] DPLL reset control
        unsigned short LOS_CTL : 2; //!< [13:12] LOS filtering mode control
        unsigned short RESERVED0 : 2; //!< [15:14] Always reads as 1
    } B;
} hw_sataphy_lane0_rx_stat_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_RX_STAT register
 */
#define HW_SATAPHY_LANE0_RX_STAT_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2002)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_RX_STAT           (*(volatile hw_sataphy_lane0_rx_stat_t *) HW_SATAPHY_LANE0_RX_STAT_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_RX_STAT bitfields
 */

/* --- Register HW_SATAPHY_LANE0_RX_STAT, field HALF_RATE[0] (RO)
 *
 * Digital half-rate data control
 */

#define BP_SATAPHY_LANE0_RX_STAT_HALF_RATE      (0)      //!< Bit position for SATAPHY_LANE0_RX_STAT_HALF_RATE.
#define BM_SATAPHY_LANE0_RX_STAT_HALF_RATE      (0x00000001)  //!< Bit mask for SATAPHY_LANE0_RX_STAT_HALF_RATE.

//! @brief Get value of SATAPHY_LANE0_RX_STAT_HALF_RATE from a register value.
#define BG_SATAPHY_LANE0_RX_STAT_HALF_RATE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_STAT_HALF_RATE) >> BP_SATAPHY_LANE0_RX_STAT_HALF_RATE)

/* --- Register HW_SATAPHY_LANE0_RX_STAT, field RX_PLL_PWRON[1] (RO)
 *
 * PLL power state control
 */

#define BP_SATAPHY_LANE0_RX_STAT_RX_PLL_PWRON      (1)      //!< Bit position for SATAPHY_LANE0_RX_STAT_RX_PLL_PWRON.
#define BM_SATAPHY_LANE0_RX_STAT_RX_PLL_PWRON      (0x00000002)  //!< Bit mask for SATAPHY_LANE0_RX_STAT_RX_PLL_PWRON.

//! @brief Get value of SATAPHY_LANE0_RX_STAT_RX_PLL_PWRON from a register value.
#define BG_SATAPHY_LANE0_RX_STAT_RX_PLL_PWRON(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_STAT_RX_PLL_PWRON) >> BP_SATAPHY_LANE0_RX_STAT_RX_PLL_PWRON)

/* --- Register HW_SATAPHY_LANE0_RX_STAT, field RX_EN[2] (RO)
 *
 * Receiver enable control
 */

#define BP_SATAPHY_LANE0_RX_STAT_RX_EN      (2)      //!< Bit position for SATAPHY_LANE0_RX_STAT_RX_EN.
#define BM_SATAPHY_LANE0_RX_STAT_RX_EN      (0x00000004)  //!< Bit mask for SATAPHY_LANE0_RX_STAT_RX_EN.

//! @brief Get value of SATAPHY_LANE0_RX_STAT_RX_EN from a register value.
#define BG_SATAPHY_LANE0_RX_STAT_RX_EN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_STAT_RX_EN) >> BP_SATAPHY_LANE0_RX_STAT_RX_EN)

/* --- Register HW_SATAPHY_LANE0_RX_STAT, field RX_ALIGN_EN[3] (RO)
 *
 * Receiver alignment enable
 */

#define BP_SATAPHY_LANE0_RX_STAT_RX_ALIGN_EN      (3)      //!< Bit position for SATAPHY_LANE0_RX_STAT_RX_ALIGN_EN.
#define BM_SATAPHY_LANE0_RX_STAT_RX_ALIGN_EN      (0x00000008)  //!< Bit mask for SATAPHY_LANE0_RX_STAT_RX_ALIGN_EN.

//! @brief Get value of SATAPHY_LANE0_RX_STAT_RX_ALIGN_EN from a register value.
#define BG_SATAPHY_LANE0_RX_STAT_RX_ALIGN_EN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_STAT_RX_ALIGN_EN) >> BP_SATAPHY_LANE0_RX_STAT_RX_ALIGN_EN)

/* --- Register HW_SATAPHY_LANE0_RX_STAT, field RX_TERM_EN[4] (RO)
 *
 * Receiver termination enable
 */

#define BP_SATAPHY_LANE0_RX_STAT_RX_TERM_EN      (4)      //!< Bit position for SATAPHY_LANE0_RX_STAT_RX_TERM_EN.
#define BM_SATAPHY_LANE0_RX_STAT_RX_TERM_EN      (0x00000010)  //!< Bit mask for SATAPHY_LANE0_RX_STAT_RX_TERM_EN.

//! @brief Get value of SATAPHY_LANE0_RX_STAT_RX_TERM_EN from a register value.
#define BG_SATAPHY_LANE0_RX_STAT_RX_TERM_EN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_STAT_RX_TERM_EN) >> BP_SATAPHY_LANE0_RX_STAT_RX_TERM_EN)

/* --- Register HW_SATAPHY_LANE0_RX_STAT, field RX_EQ_VAL[7:5] (RO)
 *
 * Equalization amount control
 */

#define BP_SATAPHY_LANE0_RX_STAT_RX_EQ_VAL      (5)      //!< Bit position for SATAPHY_LANE0_RX_STAT_RX_EQ_VAL.
#define BM_SATAPHY_LANE0_RX_STAT_RX_EQ_VAL      (0x000000e0)  //!< Bit mask for SATAPHY_LANE0_RX_STAT_RX_EQ_VAL.

//! @brief Get value of SATAPHY_LANE0_RX_STAT_RX_EQ_VAL from a register value.
#define BG_SATAPHY_LANE0_RX_STAT_RX_EQ_VAL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_STAT_RX_EQ_VAL) >> BP_SATAPHY_LANE0_RX_STAT_RX_EQ_VAL)

/* --- Register HW_SATAPHY_LANE0_RX_STAT, field RX_DPLL_MODE[10:8] (RO)
 *
 * DPLL mode control
 */

#define BP_SATAPHY_LANE0_RX_STAT_RX_DPLL_MODE      (8)      //!< Bit position for SATAPHY_LANE0_RX_STAT_RX_DPLL_MODE.
#define BM_SATAPHY_LANE0_RX_STAT_RX_DPLL_MODE      (0x00000700)  //!< Bit mask for SATAPHY_LANE0_RX_STAT_RX_DPLL_MODE.

//! @brief Get value of SATAPHY_LANE0_RX_STAT_RX_DPLL_MODE from a register value.
#define BG_SATAPHY_LANE0_RX_STAT_RX_DPLL_MODE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_STAT_RX_DPLL_MODE) >> BP_SATAPHY_LANE0_RX_STAT_RX_DPLL_MODE)

/* --- Register HW_SATAPHY_LANE0_RX_STAT, field DPLL_RESET[11] (RO)
 *
 * DPLL reset control
 */

#define BP_SATAPHY_LANE0_RX_STAT_DPLL_RESET      (11)      //!< Bit position for SATAPHY_LANE0_RX_STAT_DPLL_RESET.
#define BM_SATAPHY_LANE0_RX_STAT_DPLL_RESET      (0x00000800)  //!< Bit mask for SATAPHY_LANE0_RX_STAT_DPLL_RESET.

//! @brief Get value of SATAPHY_LANE0_RX_STAT_DPLL_RESET from a register value.
#define BG_SATAPHY_LANE0_RX_STAT_DPLL_RESET(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_STAT_DPLL_RESET) >> BP_SATAPHY_LANE0_RX_STAT_DPLL_RESET)

/* --- Register HW_SATAPHY_LANE0_RX_STAT, field LOS_CTL[13:12] (RO)
 *
 * LOS filtering mode control
 */

#define BP_SATAPHY_LANE0_RX_STAT_LOS_CTL      (12)      //!< Bit position for SATAPHY_LANE0_RX_STAT_LOS_CTL.
#define BM_SATAPHY_LANE0_RX_STAT_LOS_CTL      (0x00003000)  //!< Bit mask for SATAPHY_LANE0_RX_STAT_LOS_CTL.

//! @brief Get value of SATAPHY_LANE0_RX_STAT_LOS_CTL from a register value.
#define BG_SATAPHY_LANE0_RX_STAT_LOS_CTL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_STAT_LOS_CTL) >> BP_SATAPHY_LANE0_RX_STAT_LOS_CTL)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_OUT_STAT - Output Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_OUT_STAT - Output Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x2003  Reset value: 16'b xxxx xxxx xxxx xxxx (depends on inputs)  This register
 * indicates the status of output signals.
 */
typedef union _hw_sataphy_lane0_out_stat
{
    reg16_t U;
    struct _hw_sataphy_lane0_out_stat_bitfields
    {
        unsigned short RX_VALID : 1; //!< [0] Receiver valid output
        unsigned short RX_PLL_STATE : 1; //!< [1] Current state of Rx PLL
        unsigned short LOS : 1; //!< [2] Loss of signal output
        unsigned short TX_DONE : 1; //!< [3] Transmit operation is complete output
        unsigned short TX_RXPRES : 1; //!< [4] Transmit receiver detection result
        unsigned short RESERVED0 : 11; //!< [15:5] Always reads as 1
    } B;
} hw_sataphy_lane0_out_stat_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_OUT_STAT register
 */
#define HW_SATAPHY_LANE0_OUT_STAT_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2003)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_OUT_STAT           (*(volatile hw_sataphy_lane0_out_stat_t *) HW_SATAPHY_LANE0_OUT_STAT_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_OUT_STAT bitfields
 */

/* --- Register HW_SATAPHY_LANE0_OUT_STAT, field RX_VALID[0] (RO)
 *
 * Receiver valid output
 */

#define BP_SATAPHY_LANE0_OUT_STAT_RX_VALID      (0)      //!< Bit position for SATAPHY_LANE0_OUT_STAT_RX_VALID.
#define BM_SATAPHY_LANE0_OUT_STAT_RX_VALID      (0x00000001)  //!< Bit mask for SATAPHY_LANE0_OUT_STAT_RX_VALID.

//! @brief Get value of SATAPHY_LANE0_OUT_STAT_RX_VALID from a register value.
#define BG_SATAPHY_LANE0_OUT_STAT_RX_VALID(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_OUT_STAT_RX_VALID) >> BP_SATAPHY_LANE0_OUT_STAT_RX_VALID)

/* --- Register HW_SATAPHY_LANE0_OUT_STAT, field RX_PLL_STATE[1] (RO)
 *
 * Current state of Rx PLL
 */

#define BP_SATAPHY_LANE0_OUT_STAT_RX_PLL_STATE      (1)      //!< Bit position for SATAPHY_LANE0_OUT_STAT_RX_PLL_STATE.
#define BM_SATAPHY_LANE0_OUT_STAT_RX_PLL_STATE      (0x00000002)  //!< Bit mask for SATAPHY_LANE0_OUT_STAT_RX_PLL_STATE.

//! @brief Get value of SATAPHY_LANE0_OUT_STAT_RX_PLL_STATE from a register value.
#define BG_SATAPHY_LANE0_OUT_STAT_RX_PLL_STATE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_OUT_STAT_RX_PLL_STATE) >> BP_SATAPHY_LANE0_OUT_STAT_RX_PLL_STATE)

/* --- Register HW_SATAPHY_LANE0_OUT_STAT, field LOS[2] (RO)
 *
 * Loss of signal output
 */

#define BP_SATAPHY_LANE0_OUT_STAT_LOS      (2)      //!< Bit position for SATAPHY_LANE0_OUT_STAT_LOS.
#define BM_SATAPHY_LANE0_OUT_STAT_LOS      (0x00000004)  //!< Bit mask for SATAPHY_LANE0_OUT_STAT_LOS.

//! @brief Get value of SATAPHY_LANE0_OUT_STAT_LOS from a register value.
#define BG_SATAPHY_LANE0_OUT_STAT_LOS(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_OUT_STAT_LOS) >> BP_SATAPHY_LANE0_OUT_STAT_LOS)

/* --- Register HW_SATAPHY_LANE0_OUT_STAT, field TX_DONE[3] (RO)
 *
 * Transmit operation is complete output
 */

#define BP_SATAPHY_LANE0_OUT_STAT_TX_DONE      (3)      //!< Bit position for SATAPHY_LANE0_OUT_STAT_TX_DONE.
#define BM_SATAPHY_LANE0_OUT_STAT_TX_DONE      (0x00000008)  //!< Bit mask for SATAPHY_LANE0_OUT_STAT_TX_DONE.

//! @brief Get value of SATAPHY_LANE0_OUT_STAT_TX_DONE from a register value.
#define BG_SATAPHY_LANE0_OUT_STAT_TX_DONE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_OUT_STAT_TX_DONE) >> BP_SATAPHY_LANE0_OUT_STAT_TX_DONE)

/* --- Register HW_SATAPHY_LANE0_OUT_STAT, field TX_RXPRES[4] (RO)
 *
 * Transmit receiver detection result
 */

#define BP_SATAPHY_LANE0_OUT_STAT_TX_RXPRES      (4)      //!< Bit position for SATAPHY_LANE0_OUT_STAT_TX_RXPRES.
#define BM_SATAPHY_LANE0_OUT_STAT_TX_RXPRES      (0x00000010)  //!< Bit mask for SATAPHY_LANE0_OUT_STAT_TX_RXPRES.

//! @brief Get value of SATAPHY_LANE0_OUT_STAT_TX_RXPRES from a register value.
#define BG_SATAPHY_LANE0_OUT_STAT_TX_RXPRES(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_OUT_STAT_TX_RXPRES) >> BP_SATAPHY_LANE0_OUT_STAT_TX_RXPRES)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_TX_OVRD - Transmit Input Override Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_TX_OVRD - Transmit Input Override Register (RW)
 *
 * Reset value: 0x00000007
 *
 * Address: 0x2004  Reset value: 16'b 0000 0000 0000 0111  This register contains the override
 * transmitter control inputs.
 */
typedef union _hw_sataphy_lane0_tx_ovrd
{
    reg16_t U;
    struct _hw_sataphy_lane0_tx_ovrd_bitfields
    {
        unsigned short TX_CKO_EN : 1; //!< [0] tx_cko clock enable
        unsigned short TX_EN : 3; //!< [3:1] Transmit enable control
        unsigned short TX_CLK_ALIGN : 1; //!< [4] Command to align clocks
        unsigned short TX_DIS_ALIGN : 1; //!< [5] Disables clock alignment FSM
        unsigned short TX_BOOST : 4; //!< [9:6] Boost amount control
        unsigned short TX_ATTEN : 3; //!< [12:10] Attenuation amount control
        unsigned short TX_EDGERATE : 2; //!< [14:13] Edge rate control
        unsigned short OVRD : 1; //!< [15] Enables override of all bits in this register
    } B;
} hw_sataphy_lane0_tx_ovrd_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_TX_OVRD register
 */
#define HW_SATAPHY_LANE0_TX_OVRD_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2004)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_TX_OVRD           (*(volatile hw_sataphy_lane0_tx_ovrd_t *) HW_SATAPHY_LANE0_TX_OVRD_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_TX_OVRD bitfields
 */

/* --- Register HW_SATAPHY_LANE0_TX_OVRD, field TX_CKO_EN[0] (RW)
 *
 * tx_cko clock enable
 */

#define BP_SATAPHY_LANE0_TX_OVRD_TX_CKO_EN      (0)      //!< Bit position for SATAPHY_LANE0_TX_OVRD_TX_CKO_EN.
#define BM_SATAPHY_LANE0_TX_OVRD_TX_CKO_EN      (0x00000001)  //!< Bit mask for SATAPHY_LANE0_TX_OVRD_TX_CKO_EN.

//! @brief Get value of SATAPHY_LANE0_TX_OVRD_TX_CKO_EN from a register value.
#define BG_SATAPHY_LANE0_TX_OVRD_TX_CKO_EN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_OVRD_TX_CKO_EN) >> BP_SATAPHY_LANE0_TX_OVRD_TX_CKO_EN)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_OVRD_TX_CKO_EN.
#define BF_SATAPHY_LANE0_TX_OVRD_TX_CKO_EN(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_OVRD_TX_CKO_EN) & BM_SATAPHY_LANE0_TX_OVRD_TX_CKO_EN)

/* --- Register HW_SATAPHY_LANE0_TX_OVRD, field TX_EN[3:1] (RW)
 *
 * Transmit enable control
 */

#define BP_SATAPHY_LANE0_TX_OVRD_TX_EN      (1)      //!< Bit position for SATAPHY_LANE0_TX_OVRD_TX_EN.
#define BM_SATAPHY_LANE0_TX_OVRD_TX_EN      (0x0000000e)  //!< Bit mask for SATAPHY_LANE0_TX_OVRD_TX_EN.

//! @brief Get value of SATAPHY_LANE0_TX_OVRD_TX_EN from a register value.
#define BG_SATAPHY_LANE0_TX_OVRD_TX_EN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_OVRD_TX_EN) >> BP_SATAPHY_LANE0_TX_OVRD_TX_EN)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_OVRD_TX_EN.
#define BF_SATAPHY_LANE0_TX_OVRD_TX_EN(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_OVRD_TX_EN) & BM_SATAPHY_LANE0_TX_OVRD_TX_EN)

/* --- Register HW_SATAPHY_LANE0_TX_OVRD, field TX_CLK_ALIGN[4] (RW)
 *
 * Command to align clocks
 */

#define BP_SATAPHY_LANE0_TX_OVRD_TX_CLK_ALIGN      (4)      //!< Bit position for SATAPHY_LANE0_TX_OVRD_TX_CLK_ALIGN.
#define BM_SATAPHY_LANE0_TX_OVRD_TX_CLK_ALIGN      (0x00000010)  //!< Bit mask for SATAPHY_LANE0_TX_OVRD_TX_CLK_ALIGN.

//! @brief Get value of SATAPHY_LANE0_TX_OVRD_TX_CLK_ALIGN from a register value.
#define BG_SATAPHY_LANE0_TX_OVRD_TX_CLK_ALIGN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_OVRD_TX_CLK_ALIGN) >> BP_SATAPHY_LANE0_TX_OVRD_TX_CLK_ALIGN)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_OVRD_TX_CLK_ALIGN.
#define BF_SATAPHY_LANE0_TX_OVRD_TX_CLK_ALIGN(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_OVRD_TX_CLK_ALIGN) & BM_SATAPHY_LANE0_TX_OVRD_TX_CLK_ALIGN)

/* --- Register HW_SATAPHY_LANE0_TX_OVRD, field TX_DIS_ALIGN[5] (RW)
 *
 * Disables clock alignment FSM
 */

#define BP_SATAPHY_LANE0_TX_OVRD_TX_DIS_ALIGN      (5)      //!< Bit position for SATAPHY_LANE0_TX_OVRD_TX_DIS_ALIGN.
#define BM_SATAPHY_LANE0_TX_OVRD_TX_DIS_ALIGN      (0x00000020)  //!< Bit mask for SATAPHY_LANE0_TX_OVRD_TX_DIS_ALIGN.

//! @brief Get value of SATAPHY_LANE0_TX_OVRD_TX_DIS_ALIGN from a register value.
#define BG_SATAPHY_LANE0_TX_OVRD_TX_DIS_ALIGN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_OVRD_TX_DIS_ALIGN) >> BP_SATAPHY_LANE0_TX_OVRD_TX_DIS_ALIGN)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_OVRD_TX_DIS_ALIGN.
#define BF_SATAPHY_LANE0_TX_OVRD_TX_DIS_ALIGN(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_OVRD_TX_DIS_ALIGN) & BM_SATAPHY_LANE0_TX_OVRD_TX_DIS_ALIGN)

/* --- Register HW_SATAPHY_LANE0_TX_OVRD, field TX_BOOST[9:6] (RW)
 *
 * Boost amount control
 */

#define BP_SATAPHY_LANE0_TX_OVRD_TX_BOOST      (6)      //!< Bit position for SATAPHY_LANE0_TX_OVRD_TX_BOOST.
#define BM_SATAPHY_LANE0_TX_OVRD_TX_BOOST      (0x000003c0)  //!< Bit mask for SATAPHY_LANE0_TX_OVRD_TX_BOOST.

//! @brief Get value of SATAPHY_LANE0_TX_OVRD_TX_BOOST from a register value.
#define BG_SATAPHY_LANE0_TX_OVRD_TX_BOOST(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_OVRD_TX_BOOST) >> BP_SATAPHY_LANE0_TX_OVRD_TX_BOOST)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_OVRD_TX_BOOST.
#define BF_SATAPHY_LANE0_TX_OVRD_TX_BOOST(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_OVRD_TX_BOOST) & BM_SATAPHY_LANE0_TX_OVRD_TX_BOOST)

/* --- Register HW_SATAPHY_LANE0_TX_OVRD, field TX_ATTEN[12:10] (RW)
 *
 * Attenuation amount control
 */

#define BP_SATAPHY_LANE0_TX_OVRD_TX_ATTEN      (10)      //!< Bit position for SATAPHY_LANE0_TX_OVRD_TX_ATTEN.
#define BM_SATAPHY_LANE0_TX_OVRD_TX_ATTEN      (0x00001c00)  //!< Bit mask for SATAPHY_LANE0_TX_OVRD_TX_ATTEN.

//! @brief Get value of SATAPHY_LANE0_TX_OVRD_TX_ATTEN from a register value.
#define BG_SATAPHY_LANE0_TX_OVRD_TX_ATTEN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_OVRD_TX_ATTEN) >> BP_SATAPHY_LANE0_TX_OVRD_TX_ATTEN)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_OVRD_TX_ATTEN.
#define BF_SATAPHY_LANE0_TX_OVRD_TX_ATTEN(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_OVRD_TX_ATTEN) & BM_SATAPHY_LANE0_TX_OVRD_TX_ATTEN)

/* --- Register HW_SATAPHY_LANE0_TX_OVRD, field TX_EDGERATE[14:13] (RW)
 *
 * Edge rate control
 */

#define BP_SATAPHY_LANE0_TX_OVRD_TX_EDGERATE      (13)      //!< Bit position for SATAPHY_LANE0_TX_OVRD_TX_EDGERATE.
#define BM_SATAPHY_LANE0_TX_OVRD_TX_EDGERATE      (0x00006000)  //!< Bit mask for SATAPHY_LANE0_TX_OVRD_TX_EDGERATE.

//! @brief Get value of SATAPHY_LANE0_TX_OVRD_TX_EDGERATE from a register value.
#define BG_SATAPHY_LANE0_TX_OVRD_TX_EDGERATE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_OVRD_TX_EDGERATE) >> BP_SATAPHY_LANE0_TX_OVRD_TX_EDGERATE)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_OVRD_TX_EDGERATE.
#define BF_SATAPHY_LANE0_TX_OVRD_TX_EDGERATE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_OVRD_TX_EDGERATE) & BM_SATAPHY_LANE0_TX_OVRD_TX_EDGERATE)

/* --- Register HW_SATAPHY_LANE0_TX_OVRD, field OVRD[15] (RW)
 *
 * Enables override of all bits in this register
 */

#define BP_SATAPHY_LANE0_TX_OVRD_OVRD      (15)      //!< Bit position for SATAPHY_LANE0_TX_OVRD_OVRD.
#define BM_SATAPHY_LANE0_TX_OVRD_OVRD      (0x00008000)  //!< Bit mask for SATAPHY_LANE0_TX_OVRD_OVRD.

//! @brief Get value of SATAPHY_LANE0_TX_OVRD_OVRD from a register value.
#define BG_SATAPHY_LANE0_TX_OVRD_OVRD(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_OVRD_OVRD) >> BP_SATAPHY_LANE0_TX_OVRD_OVRD)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_OVRD_OVRD.
#define BF_SATAPHY_LANE0_TX_OVRD_OVRD(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_OVRD_OVRD) & BM_SATAPHY_LANE0_TX_OVRD_OVRD)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_RX_OVRD - Receive Input Override Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_RX_OVRD - Receive Input Override Register (RW)
 *
 * Reset value: 0x00001416
 *
 * Address: 0x2005  Reset value: 16'b x001 0100 0001 1110  This register contains the override of
 * receiver control inputs.
 */
typedef union _hw_sataphy_lane0_rx_ovrd
{
    reg16_t U;
    struct _hw_sataphy_lane0_rx_ovrd_bitfields
    {
        unsigned short HALF_RATE : 1; //!< [0] Digital half-rate data control
        unsigned short RX_PLL_PWRON : 1; //!< [1] PLL power state control
        unsigned short RX_EN : 1; //!< [2] Receiver enable control
        unsigned short RX_ALIGN_EN : 1; //!< [3] Receiver alignment enable
        unsigned short RX_TERM_EN : 1; //!< [4] Receiver termination enable
        unsigned short RX_EQ_VAL : 3; //!< [7:5] Equalization amount control
        unsigned short RX_DPLL_MODE : 3; //!< [10:8] DPLL mode control
        unsigned short DPLL_RESET : 1; //!< [11] DPLL reset control
        unsigned short LOS_CTL : 2; //!< [13:12] LOS filtering mode control
        unsigned short OVRD : 1; //!< [14] Enables override of all bits in this register
        unsigned short RESERVED0 : 1; //!< [15] Reserved
    } B;
} hw_sataphy_lane0_rx_ovrd_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_RX_OVRD register
 */
#define HW_SATAPHY_LANE0_RX_OVRD_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2005)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_RX_OVRD           (*(volatile hw_sataphy_lane0_rx_ovrd_t *) HW_SATAPHY_LANE0_RX_OVRD_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_RX_OVRD bitfields
 */

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field HALF_RATE[0] (RW)
 *
 * Digital half-rate data control
 */

#define BP_SATAPHY_LANE0_RX_OVRD_HALF_RATE      (0)      //!< Bit position for SATAPHY_LANE0_RX_OVRD_HALF_RATE.
#define BM_SATAPHY_LANE0_RX_OVRD_HALF_RATE      (0x00000001)  //!< Bit mask for SATAPHY_LANE0_RX_OVRD_HALF_RATE.

//! @brief Get value of SATAPHY_LANE0_RX_OVRD_HALF_RATE from a register value.
#define BG_SATAPHY_LANE0_RX_OVRD_HALF_RATE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_OVRD_HALF_RATE) >> BP_SATAPHY_LANE0_RX_OVRD_HALF_RATE)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_OVRD_HALF_RATE.
#define BF_SATAPHY_LANE0_RX_OVRD_HALF_RATE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_OVRD_HALF_RATE) & BM_SATAPHY_LANE0_RX_OVRD_HALF_RATE)

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field RX_PLL_PWRON[1] (RW)
 *
 * PLL power state control
 */

#define BP_SATAPHY_LANE0_RX_OVRD_RX_PLL_PWRON      (1)      //!< Bit position for SATAPHY_LANE0_RX_OVRD_RX_PLL_PWRON.
#define BM_SATAPHY_LANE0_RX_OVRD_RX_PLL_PWRON      (0x00000002)  //!< Bit mask for SATAPHY_LANE0_RX_OVRD_RX_PLL_PWRON.

//! @brief Get value of SATAPHY_LANE0_RX_OVRD_RX_PLL_PWRON from a register value.
#define BG_SATAPHY_LANE0_RX_OVRD_RX_PLL_PWRON(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_OVRD_RX_PLL_PWRON) >> BP_SATAPHY_LANE0_RX_OVRD_RX_PLL_PWRON)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_OVRD_RX_PLL_PWRON.
#define BF_SATAPHY_LANE0_RX_OVRD_RX_PLL_PWRON(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_OVRD_RX_PLL_PWRON) & BM_SATAPHY_LANE0_RX_OVRD_RX_PLL_PWRON)

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field RX_EN[2] (RW)
 *
 * Receiver enable control
 */

#define BP_SATAPHY_LANE0_RX_OVRD_RX_EN      (2)      //!< Bit position for SATAPHY_LANE0_RX_OVRD_RX_EN.
#define BM_SATAPHY_LANE0_RX_OVRD_RX_EN      (0x00000004)  //!< Bit mask for SATAPHY_LANE0_RX_OVRD_RX_EN.

//! @brief Get value of SATAPHY_LANE0_RX_OVRD_RX_EN from a register value.
#define BG_SATAPHY_LANE0_RX_OVRD_RX_EN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_OVRD_RX_EN) >> BP_SATAPHY_LANE0_RX_OVRD_RX_EN)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_OVRD_RX_EN.
#define BF_SATAPHY_LANE0_RX_OVRD_RX_EN(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_OVRD_RX_EN) & BM_SATAPHY_LANE0_RX_OVRD_RX_EN)

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field RX_ALIGN_EN[3] (RW)
 *
 * Receiver alignment enable
 */

#define BP_SATAPHY_LANE0_RX_OVRD_RX_ALIGN_EN      (3)      //!< Bit position for SATAPHY_LANE0_RX_OVRD_RX_ALIGN_EN.
#define BM_SATAPHY_LANE0_RX_OVRD_RX_ALIGN_EN      (0x00000008)  //!< Bit mask for SATAPHY_LANE0_RX_OVRD_RX_ALIGN_EN.

//! @brief Get value of SATAPHY_LANE0_RX_OVRD_RX_ALIGN_EN from a register value.
#define BG_SATAPHY_LANE0_RX_OVRD_RX_ALIGN_EN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_OVRD_RX_ALIGN_EN) >> BP_SATAPHY_LANE0_RX_OVRD_RX_ALIGN_EN)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_OVRD_RX_ALIGN_EN.
#define BF_SATAPHY_LANE0_RX_OVRD_RX_ALIGN_EN(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_OVRD_RX_ALIGN_EN) & BM_SATAPHY_LANE0_RX_OVRD_RX_ALIGN_EN)

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field RX_TERM_EN[4] (RW)
 *
 * Receiver termination enable
 */

#define BP_SATAPHY_LANE0_RX_OVRD_RX_TERM_EN      (4)      //!< Bit position for SATAPHY_LANE0_RX_OVRD_RX_TERM_EN.
#define BM_SATAPHY_LANE0_RX_OVRD_RX_TERM_EN      (0x00000010)  //!< Bit mask for SATAPHY_LANE0_RX_OVRD_RX_TERM_EN.

//! @brief Get value of SATAPHY_LANE0_RX_OVRD_RX_TERM_EN from a register value.
#define BG_SATAPHY_LANE0_RX_OVRD_RX_TERM_EN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_OVRD_RX_TERM_EN) >> BP_SATAPHY_LANE0_RX_OVRD_RX_TERM_EN)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_OVRD_RX_TERM_EN.
#define BF_SATAPHY_LANE0_RX_OVRD_RX_TERM_EN(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_OVRD_RX_TERM_EN) & BM_SATAPHY_LANE0_RX_OVRD_RX_TERM_EN)

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field RX_EQ_VAL[7:5] (RW)
 *
 * Equalization amount control
 */

#define BP_SATAPHY_LANE0_RX_OVRD_RX_EQ_VAL      (5)      //!< Bit position for SATAPHY_LANE0_RX_OVRD_RX_EQ_VAL.
#define BM_SATAPHY_LANE0_RX_OVRD_RX_EQ_VAL      (0x000000e0)  //!< Bit mask for SATAPHY_LANE0_RX_OVRD_RX_EQ_VAL.

//! @brief Get value of SATAPHY_LANE0_RX_OVRD_RX_EQ_VAL from a register value.
#define BG_SATAPHY_LANE0_RX_OVRD_RX_EQ_VAL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_OVRD_RX_EQ_VAL) >> BP_SATAPHY_LANE0_RX_OVRD_RX_EQ_VAL)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_OVRD_RX_EQ_VAL.
#define BF_SATAPHY_LANE0_RX_OVRD_RX_EQ_VAL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_OVRD_RX_EQ_VAL) & BM_SATAPHY_LANE0_RX_OVRD_RX_EQ_VAL)

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field RX_DPLL_MODE[10:8] (RW)
 *
 * DPLL mode control
 */

#define BP_SATAPHY_LANE0_RX_OVRD_RX_DPLL_MODE      (8)      //!< Bit position for SATAPHY_LANE0_RX_OVRD_RX_DPLL_MODE.
#define BM_SATAPHY_LANE0_RX_OVRD_RX_DPLL_MODE      (0x00000700)  //!< Bit mask for SATAPHY_LANE0_RX_OVRD_RX_DPLL_MODE.

//! @brief Get value of SATAPHY_LANE0_RX_OVRD_RX_DPLL_MODE from a register value.
#define BG_SATAPHY_LANE0_RX_OVRD_RX_DPLL_MODE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_OVRD_RX_DPLL_MODE) >> BP_SATAPHY_LANE0_RX_OVRD_RX_DPLL_MODE)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_OVRD_RX_DPLL_MODE.
#define BF_SATAPHY_LANE0_RX_OVRD_RX_DPLL_MODE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_OVRD_RX_DPLL_MODE) & BM_SATAPHY_LANE0_RX_OVRD_RX_DPLL_MODE)

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field DPLL_RESET[11] (RW)
 *
 * DPLL reset control
 */

#define BP_SATAPHY_LANE0_RX_OVRD_DPLL_RESET      (11)      //!< Bit position for SATAPHY_LANE0_RX_OVRD_DPLL_RESET.
#define BM_SATAPHY_LANE0_RX_OVRD_DPLL_RESET      (0x00000800)  //!< Bit mask for SATAPHY_LANE0_RX_OVRD_DPLL_RESET.

//! @brief Get value of SATAPHY_LANE0_RX_OVRD_DPLL_RESET from a register value.
#define BG_SATAPHY_LANE0_RX_OVRD_DPLL_RESET(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_OVRD_DPLL_RESET) >> BP_SATAPHY_LANE0_RX_OVRD_DPLL_RESET)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_OVRD_DPLL_RESET.
#define BF_SATAPHY_LANE0_RX_OVRD_DPLL_RESET(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_OVRD_DPLL_RESET) & BM_SATAPHY_LANE0_RX_OVRD_DPLL_RESET)

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field LOS_CTL[13:12] (RW)
 *
 * LOS filtering mode control
 */

#define BP_SATAPHY_LANE0_RX_OVRD_LOS_CTL      (12)      //!< Bit position for SATAPHY_LANE0_RX_OVRD_LOS_CTL.
#define BM_SATAPHY_LANE0_RX_OVRD_LOS_CTL      (0x00003000)  //!< Bit mask for SATAPHY_LANE0_RX_OVRD_LOS_CTL.

//! @brief Get value of SATAPHY_LANE0_RX_OVRD_LOS_CTL from a register value.
#define BG_SATAPHY_LANE0_RX_OVRD_LOS_CTL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_OVRD_LOS_CTL) >> BP_SATAPHY_LANE0_RX_OVRD_LOS_CTL)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_OVRD_LOS_CTL.
#define BF_SATAPHY_LANE0_RX_OVRD_LOS_CTL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_OVRD_LOS_CTL) & BM_SATAPHY_LANE0_RX_OVRD_LOS_CTL)

/* --- Register HW_SATAPHY_LANE0_RX_OVRD, field OVRD[14] (RW)
 *
 * Enables override of all bits in this register
 */

#define BP_SATAPHY_LANE0_RX_OVRD_OVRD      (14)      //!< Bit position for SATAPHY_LANE0_RX_OVRD_OVRD.
#define BM_SATAPHY_LANE0_RX_OVRD_OVRD      (0x00004000)  //!< Bit mask for SATAPHY_LANE0_RX_OVRD_OVRD.

//! @brief Get value of SATAPHY_LANE0_RX_OVRD_OVRD from a register value.
#define BG_SATAPHY_LANE0_RX_OVRD_OVRD(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_OVRD_OVRD) >> BP_SATAPHY_LANE0_RX_OVRD_OVRD)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_OVRD_OVRD.
#define BF_SATAPHY_LANE0_RX_OVRD_OVRD(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_OVRD_OVRD) & BM_SATAPHY_LANE0_RX_OVRD_OVRD)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_OUT_OVRD - Output Override Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_OUT_OVRD - Output Override Register (RW)
 *
 * Reset value: 0x00000011
 *
 * Address: 0x2006  Reset value: 16'b xxxx xxxx xx01 0001  This register contains the override of
 * output signals.
 */
typedef union _hw_sataphy_lane0_out_ovrd
{
    reg16_t U;
    struct _hw_sataphy_lane0_out_ovrd_bitfields
    {
        unsigned short RX_VALID : 1; //!< [0] Receiver valid output
        unsigned short RX_PLL_STATE : 1; //!< [1] Current state of Rx PLL
        unsigned short LOS : 1; //!< [2] Loss of signal output
        unsigned short TX_DONE : 1; //!< [3] Transmit operation is complete output
        unsigned short TX_RXPRES : 1; //!< [4] Transmit receiver detection result
        unsigned short OVRD : 1; //!< [5] Enables override of all bits in this register
        unsigned short RESERVED0 : 10; //!< [15:6] Reserved
    } B;
} hw_sataphy_lane0_out_ovrd_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_OUT_OVRD register
 */
#define HW_SATAPHY_LANE0_OUT_OVRD_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2006)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_OUT_OVRD           (*(volatile hw_sataphy_lane0_out_ovrd_t *) HW_SATAPHY_LANE0_OUT_OVRD_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_OUT_OVRD bitfields
 */

/* --- Register HW_SATAPHY_LANE0_OUT_OVRD, field RX_VALID[0] (RW)
 *
 * Receiver valid output
 */

#define BP_SATAPHY_LANE0_OUT_OVRD_RX_VALID      (0)      //!< Bit position for SATAPHY_LANE0_OUT_OVRD_RX_VALID.
#define BM_SATAPHY_LANE0_OUT_OVRD_RX_VALID      (0x00000001)  //!< Bit mask for SATAPHY_LANE0_OUT_OVRD_RX_VALID.

//! @brief Get value of SATAPHY_LANE0_OUT_OVRD_RX_VALID from a register value.
#define BG_SATAPHY_LANE0_OUT_OVRD_RX_VALID(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_OUT_OVRD_RX_VALID) >> BP_SATAPHY_LANE0_OUT_OVRD_RX_VALID)

//! @brief Format value for bitfield SATAPHY_LANE0_OUT_OVRD_RX_VALID.
#define BF_SATAPHY_LANE0_OUT_OVRD_RX_VALID(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_OUT_OVRD_RX_VALID) & BM_SATAPHY_LANE0_OUT_OVRD_RX_VALID)

/* --- Register HW_SATAPHY_LANE0_OUT_OVRD, field RX_PLL_STATE[1] (RW)
 *
 * Current state of Rx PLL
 */

#define BP_SATAPHY_LANE0_OUT_OVRD_RX_PLL_STATE      (1)      //!< Bit position for SATAPHY_LANE0_OUT_OVRD_RX_PLL_STATE.
#define BM_SATAPHY_LANE0_OUT_OVRD_RX_PLL_STATE      (0x00000002)  //!< Bit mask for SATAPHY_LANE0_OUT_OVRD_RX_PLL_STATE.

//! @brief Get value of SATAPHY_LANE0_OUT_OVRD_RX_PLL_STATE from a register value.
#define BG_SATAPHY_LANE0_OUT_OVRD_RX_PLL_STATE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_OUT_OVRD_RX_PLL_STATE) >> BP_SATAPHY_LANE0_OUT_OVRD_RX_PLL_STATE)

//! @brief Format value for bitfield SATAPHY_LANE0_OUT_OVRD_RX_PLL_STATE.
#define BF_SATAPHY_LANE0_OUT_OVRD_RX_PLL_STATE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_OUT_OVRD_RX_PLL_STATE) & BM_SATAPHY_LANE0_OUT_OVRD_RX_PLL_STATE)

/* --- Register HW_SATAPHY_LANE0_OUT_OVRD, field LOS[2] (RW)
 *
 * Loss of signal output
 */

#define BP_SATAPHY_LANE0_OUT_OVRD_LOS      (2)      //!< Bit position for SATAPHY_LANE0_OUT_OVRD_LOS.
#define BM_SATAPHY_LANE0_OUT_OVRD_LOS      (0x00000004)  //!< Bit mask for SATAPHY_LANE0_OUT_OVRD_LOS.

//! @brief Get value of SATAPHY_LANE0_OUT_OVRD_LOS from a register value.
#define BG_SATAPHY_LANE0_OUT_OVRD_LOS(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_OUT_OVRD_LOS) >> BP_SATAPHY_LANE0_OUT_OVRD_LOS)

//! @brief Format value for bitfield SATAPHY_LANE0_OUT_OVRD_LOS.
#define BF_SATAPHY_LANE0_OUT_OVRD_LOS(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_OUT_OVRD_LOS) & BM_SATAPHY_LANE0_OUT_OVRD_LOS)

/* --- Register HW_SATAPHY_LANE0_OUT_OVRD, field TX_DONE[3] (RW)
 *
 * Transmit operation is complete output
 */

#define BP_SATAPHY_LANE0_OUT_OVRD_TX_DONE      (3)      //!< Bit position for SATAPHY_LANE0_OUT_OVRD_TX_DONE.
#define BM_SATAPHY_LANE0_OUT_OVRD_TX_DONE      (0x00000008)  //!< Bit mask for SATAPHY_LANE0_OUT_OVRD_TX_DONE.

//! @brief Get value of SATAPHY_LANE0_OUT_OVRD_TX_DONE from a register value.
#define BG_SATAPHY_LANE0_OUT_OVRD_TX_DONE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_OUT_OVRD_TX_DONE) >> BP_SATAPHY_LANE0_OUT_OVRD_TX_DONE)

//! @brief Format value for bitfield SATAPHY_LANE0_OUT_OVRD_TX_DONE.
#define BF_SATAPHY_LANE0_OUT_OVRD_TX_DONE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_OUT_OVRD_TX_DONE) & BM_SATAPHY_LANE0_OUT_OVRD_TX_DONE)

/* --- Register HW_SATAPHY_LANE0_OUT_OVRD, field TX_RXPRES[4] (RW)
 *
 * Transmit receiver detection result
 */

#define BP_SATAPHY_LANE0_OUT_OVRD_TX_RXPRES      (4)      //!< Bit position for SATAPHY_LANE0_OUT_OVRD_TX_RXPRES.
#define BM_SATAPHY_LANE0_OUT_OVRD_TX_RXPRES      (0x00000010)  //!< Bit mask for SATAPHY_LANE0_OUT_OVRD_TX_RXPRES.

//! @brief Get value of SATAPHY_LANE0_OUT_OVRD_TX_RXPRES from a register value.
#define BG_SATAPHY_LANE0_OUT_OVRD_TX_RXPRES(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_OUT_OVRD_TX_RXPRES) >> BP_SATAPHY_LANE0_OUT_OVRD_TX_RXPRES)

//! @brief Format value for bitfield SATAPHY_LANE0_OUT_OVRD_TX_RXPRES.
#define BF_SATAPHY_LANE0_OUT_OVRD_TX_RXPRES(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_OUT_OVRD_TX_RXPRES) & BM_SATAPHY_LANE0_OUT_OVRD_TX_RXPRES)

/* --- Register HW_SATAPHY_LANE0_OUT_OVRD, field OVRD[5] (RW)
 *
 * Enables override of all bits in this register
 */

#define BP_SATAPHY_LANE0_OUT_OVRD_OVRD      (5)      //!< Bit position for SATAPHY_LANE0_OUT_OVRD_OVRD.
#define BM_SATAPHY_LANE0_OUT_OVRD_OVRD      (0x00000020)  //!< Bit mask for SATAPHY_LANE0_OUT_OVRD_OVRD.

//! @brief Get value of SATAPHY_LANE0_OUT_OVRD_OVRD from a register value.
#define BG_SATAPHY_LANE0_OUT_OVRD_OVRD(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_OUT_OVRD_OVRD) >> BP_SATAPHY_LANE0_OUT_OVRD_OVRD)

//! @brief Format value for bitfield SATAPHY_LANE0_OUT_OVRD_OVRD.
#define BF_SATAPHY_LANE0_OUT_OVRD_OVRD(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_OUT_OVRD_OVRD) & BM_SATAPHY_LANE0_OUT_OVRD_OVRD)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_DBG_CTL - Debug Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_DBG_CTL - Debug Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x2007  Reset value: 16'b x000 0000 0000 0000  This register contains debug controls.
 */
typedef union _hw_sataphy_lane0_dbg_ctl
{
    reg16_t U;
    struct _hw_sataphy_lane0_dbg_ctl_bitfields
    {
        unsigned short ZERO_TX_DATA : 1; //!< [0] Overrides all transmit data to zeros
        unsigned short ZERO_RX_DATA : 1; //!< [1] Overrides all receive data to zeros
        unsigned short INVERT_TX : 1; //!< [2] Inverts transmit data (post-LBERT)
        unsigned short INVERT_RX : 1; //!< [3] Inverts receive data (pre-LBERT)
        unsigned short DISABLE_RX_CK : 1; //!< [4] Disables rx_ck output
        unsigned short DTB_SEL0 : 5; //!< [9:5] All other bits: Disabled Selects wire to drive onto DTB bit 0:
        unsigned short DTB_SEL1 : 5; //!< [14:10] All other bits: Disabled Selects wire to drive onto DTB bit 1:
        unsigned short RESERVED0 : 1; //!< [15] Reserved
    } B;
} hw_sataphy_lane0_dbg_ctl_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_DBG_CTL register
 */
#define HW_SATAPHY_LANE0_DBG_CTL_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2007)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_DBG_CTL           (*(volatile hw_sataphy_lane0_dbg_ctl_t *) HW_SATAPHY_LANE0_DBG_CTL_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_DBG_CTL bitfields
 */

/* --- Register HW_SATAPHY_LANE0_DBG_CTL, field ZERO_TX_DATA[0] (RW)
 *
 * Overrides all transmit data to zeros
 */

#define BP_SATAPHY_LANE0_DBG_CTL_ZERO_TX_DATA      (0)      //!< Bit position for SATAPHY_LANE0_DBG_CTL_ZERO_TX_DATA.
#define BM_SATAPHY_LANE0_DBG_CTL_ZERO_TX_DATA      (0x00000001)  //!< Bit mask for SATAPHY_LANE0_DBG_CTL_ZERO_TX_DATA.

//! @brief Get value of SATAPHY_LANE0_DBG_CTL_ZERO_TX_DATA from a register value.
#define BG_SATAPHY_LANE0_DBG_CTL_ZERO_TX_DATA(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_DBG_CTL_ZERO_TX_DATA) >> BP_SATAPHY_LANE0_DBG_CTL_ZERO_TX_DATA)

//! @brief Format value for bitfield SATAPHY_LANE0_DBG_CTL_ZERO_TX_DATA.
#define BF_SATAPHY_LANE0_DBG_CTL_ZERO_TX_DATA(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_DBG_CTL_ZERO_TX_DATA) & BM_SATAPHY_LANE0_DBG_CTL_ZERO_TX_DATA)

/* --- Register HW_SATAPHY_LANE0_DBG_CTL, field ZERO_RX_DATA[1] (RW)
 *
 * Overrides all receive data to zeros
 */

#define BP_SATAPHY_LANE0_DBG_CTL_ZERO_RX_DATA      (1)      //!< Bit position for SATAPHY_LANE0_DBG_CTL_ZERO_RX_DATA.
#define BM_SATAPHY_LANE0_DBG_CTL_ZERO_RX_DATA      (0x00000002)  //!< Bit mask for SATAPHY_LANE0_DBG_CTL_ZERO_RX_DATA.

//! @brief Get value of SATAPHY_LANE0_DBG_CTL_ZERO_RX_DATA from a register value.
#define BG_SATAPHY_LANE0_DBG_CTL_ZERO_RX_DATA(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_DBG_CTL_ZERO_RX_DATA) >> BP_SATAPHY_LANE0_DBG_CTL_ZERO_RX_DATA)

//! @brief Format value for bitfield SATAPHY_LANE0_DBG_CTL_ZERO_RX_DATA.
#define BF_SATAPHY_LANE0_DBG_CTL_ZERO_RX_DATA(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_DBG_CTL_ZERO_RX_DATA) & BM_SATAPHY_LANE0_DBG_CTL_ZERO_RX_DATA)

/* --- Register HW_SATAPHY_LANE0_DBG_CTL, field INVERT_TX[2] (RW)
 *
 * Inverts transmit data (post-LBERT)
 */

#define BP_SATAPHY_LANE0_DBG_CTL_INVERT_TX      (2)      //!< Bit position for SATAPHY_LANE0_DBG_CTL_INVERT_TX.
#define BM_SATAPHY_LANE0_DBG_CTL_INVERT_TX      (0x00000004)  //!< Bit mask for SATAPHY_LANE0_DBG_CTL_INVERT_TX.

//! @brief Get value of SATAPHY_LANE0_DBG_CTL_INVERT_TX from a register value.
#define BG_SATAPHY_LANE0_DBG_CTL_INVERT_TX(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_DBG_CTL_INVERT_TX) >> BP_SATAPHY_LANE0_DBG_CTL_INVERT_TX)

//! @brief Format value for bitfield SATAPHY_LANE0_DBG_CTL_INVERT_TX.
#define BF_SATAPHY_LANE0_DBG_CTL_INVERT_TX(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_DBG_CTL_INVERT_TX) & BM_SATAPHY_LANE0_DBG_CTL_INVERT_TX)

/* --- Register HW_SATAPHY_LANE0_DBG_CTL, field INVERT_RX[3] (RW)
 *
 * Inverts receive data (pre-LBERT)
 */

#define BP_SATAPHY_LANE0_DBG_CTL_INVERT_RX      (3)      //!< Bit position for SATAPHY_LANE0_DBG_CTL_INVERT_RX.
#define BM_SATAPHY_LANE0_DBG_CTL_INVERT_RX      (0x00000008)  //!< Bit mask for SATAPHY_LANE0_DBG_CTL_INVERT_RX.

//! @brief Get value of SATAPHY_LANE0_DBG_CTL_INVERT_RX from a register value.
#define BG_SATAPHY_LANE0_DBG_CTL_INVERT_RX(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_DBG_CTL_INVERT_RX) >> BP_SATAPHY_LANE0_DBG_CTL_INVERT_RX)

//! @brief Format value for bitfield SATAPHY_LANE0_DBG_CTL_INVERT_RX.
#define BF_SATAPHY_LANE0_DBG_CTL_INVERT_RX(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_DBG_CTL_INVERT_RX) & BM_SATAPHY_LANE0_DBG_CTL_INVERT_RX)

/* --- Register HW_SATAPHY_LANE0_DBG_CTL, field DISABLE_RX_CK[4] (RW)
 *
 * Disables rx_ck output
 */

#define BP_SATAPHY_LANE0_DBG_CTL_DISABLE_RX_CK      (4)      //!< Bit position for SATAPHY_LANE0_DBG_CTL_DISABLE_RX_CK.
#define BM_SATAPHY_LANE0_DBG_CTL_DISABLE_RX_CK      (0x00000010)  //!< Bit mask for SATAPHY_LANE0_DBG_CTL_DISABLE_RX_CK.

//! @brief Get value of SATAPHY_LANE0_DBG_CTL_DISABLE_RX_CK from a register value.
#define BG_SATAPHY_LANE0_DBG_CTL_DISABLE_RX_CK(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_DBG_CTL_DISABLE_RX_CK) >> BP_SATAPHY_LANE0_DBG_CTL_DISABLE_RX_CK)

//! @brief Format value for bitfield SATAPHY_LANE0_DBG_CTL_DISABLE_RX_CK.
#define BF_SATAPHY_LANE0_DBG_CTL_DISABLE_RX_CK(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_DBG_CTL_DISABLE_RX_CK) & BM_SATAPHY_LANE0_DBG_CTL_DISABLE_RX_CK)

/* --- Register HW_SATAPHY_LANE0_DBG_CTL, field DTB_SEL0[9:5] (RW)
 *
 * All other bits: Disabled Selects wire to drive onto DTB bit 0:
 *
 * Values:
 * 00000 - Disabled
 * 00001 - half_rate
 * 00010 - tx_en[0]
 * 00011 - tx_en[1]
 * 00100 - tx_en[2]
 * 00101 - tx_clk_align
 * 00110 - n/a
 * 00111 - rx_pll_pwron
 * 01000 - rx_en
 * 01001 - dpll_reset
 * 01010 - rx_valid
 * 01011 - rx_pll_state
 * 01100 - los
 * 01101 - tx_done
 * 01110 - rx_ck (output to ASIC)
 * 01111 - ck_rx (PLL output)
 * 10000 - ck_los
 * 10001 - tx_ck (ASIC input)
 * 10010 - ck_tx_out (serializer output)
 * 10011 - pll_pwron (analog input)
 * 10100 - pll_reset
 * 10101 - ser_clk_kill
 * 10110 - LBERT pattern generator strobe
 * 10111 - rx_present_p (sampled)
 * 11000 - rx_present_m (sampled)
 * 11001 - acjt receiver o/p from rx_p
 * 11010 - acjt receiver o/p from rx_m
 */

#define BP_SATAPHY_LANE0_DBG_CTL_DTB_SEL0      (5)      //!< Bit position for SATAPHY_LANE0_DBG_CTL_DTB_SEL0.
#define BM_SATAPHY_LANE0_DBG_CTL_DTB_SEL0      (0x000003e0)  //!< Bit mask for SATAPHY_LANE0_DBG_CTL_DTB_SEL0.

//! @brief Get value of SATAPHY_LANE0_DBG_CTL_DTB_SEL0 from a register value.
#define BG_SATAPHY_LANE0_DBG_CTL_DTB_SEL0(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_DBG_CTL_DTB_SEL0) >> BP_SATAPHY_LANE0_DBG_CTL_DTB_SEL0)

//! @brief Format value for bitfield SATAPHY_LANE0_DBG_CTL_DTB_SEL0.
#define BF_SATAPHY_LANE0_DBG_CTL_DTB_SEL0(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_DBG_CTL_DTB_SEL0) & BM_SATAPHY_LANE0_DBG_CTL_DTB_SEL0)


/* --- Register HW_SATAPHY_LANE0_DBG_CTL, field DTB_SEL1[14:10] (RW)
 *
 * All other bits: Disabled Selects wire to drive onto DTB bit 1:
 *
 * Values:
 * 00000 - Disabled
 * 00001 - half_rate
 * 00010 - tx_en[0]
 * 00011 - tx_en[1]
 * 00100 - tx_en[2]
 * 00101 - tx_clk_align
 * 00110 - n/a
 * 00111 - rx_pll_pwron
 * 01000 - rx_en
 * 01001 - dpll_reset
 * 01010 - rx_valid
 * 01011 - rx_pll_state
 * 01100 - los
 * 01101 - tx_done
 * 01110 - rx_ck (output to ASIC)
 * 01111 - ck_rx (PLL output)
 * 10000 - ck_los
 * 10001 - tx_ck (ASIC input)
 * 10010 - ck_tx_out (serializer output)
 * 10011 - pll_pwron (analog input)
 * 10100 - pll_reset
 * 10101 - ser_clk_kill
 * 10110 - LBERT pg strobe
 * 10111 - rx_present_p (sampled)
 * 11000 - rx_present_m (sampled)
 * 11001 - acjt receiver o/p from rx_p
 * 11010 - acjt receiver o/p from rx_m
 */

#define BP_SATAPHY_LANE0_DBG_CTL_DTB_SEL1      (10)      //!< Bit position for SATAPHY_LANE0_DBG_CTL_DTB_SEL1.
#define BM_SATAPHY_LANE0_DBG_CTL_DTB_SEL1      (0x00007c00)  //!< Bit mask for SATAPHY_LANE0_DBG_CTL_DTB_SEL1.

//! @brief Get value of SATAPHY_LANE0_DBG_CTL_DTB_SEL1 from a register value.
#define BG_SATAPHY_LANE0_DBG_CTL_DTB_SEL1(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_DBG_CTL_DTB_SEL1) >> BP_SATAPHY_LANE0_DBG_CTL_DTB_SEL1)

//! @brief Format value for bitfield SATAPHY_LANE0_DBG_CTL_DTB_SEL1.
#define BF_SATAPHY_LANE0_DBG_CTL_DTB_SEL1(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_DBG_CTL_DTB_SEL1) & BM_SATAPHY_LANE0_DBG_CTL_DTB_SEL1)


//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_PG_CTL - Pattern Generator Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_PG_CTL - Pattern Generator Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x2010  Reset value: 16'b xx00 0000 0000 0000 0000  This register contains pattern
 * generator controls.
 */
typedef union _hw_sataphy_lane0_pg_ctl
{
    reg16_t U;
    struct _hw_sataphy_lane0_pg_ctl_bitfields
    {
        unsigned short MODE : 3; //!< [2:0] Selects a pattern to generate:
        unsigned short TRIGGER_ERR : 1; //!< [3] Inserts a single error into the LSB
        unsigned short PAT0 : 10; //!< [13:4] Pattern for modes 3-5
        unsigned short RESERVED0 : 2; //!< [15:14] Reserved
    } B;
} hw_sataphy_lane0_pg_ctl_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_PG_CTL register
 */
#define HW_SATAPHY_LANE0_PG_CTL_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2010)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_PG_CTL           (*(volatile hw_sataphy_lane0_pg_ctl_t *) HW_SATAPHY_LANE0_PG_CTL_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_PG_CTL bitfields
 */

/* --- Register HW_SATAPHY_LANE0_PG_CTL, field MODE[2:0] (RW)
 *
 * Selects a pattern to generate:
 *
 * Values:
 * 000 - Disabled
 * 001 - lfsr15. X^15 + X^14 + 1
 * 010 - lfsr7. X^7 + X^6 + 1
 * 011 - Fixed word (PAT0)3'b
 * 100 - DC balanced word (PAT0, ~PAT0)
 * 101 - Fixed pattern: (000, PAT0, 3ff, ~PAT0)
 * 110 - Reserved
 * 111 - Reserved
 */

#define BP_SATAPHY_LANE0_PG_CTL_MODE      (0)      //!< Bit position for SATAPHY_LANE0_PG_CTL_MODE.
#define BM_SATAPHY_LANE0_PG_CTL_MODE      (0x00000007)  //!< Bit mask for SATAPHY_LANE0_PG_CTL_MODE.

//! @brief Get value of SATAPHY_LANE0_PG_CTL_MODE from a register value.
#define BG_SATAPHY_LANE0_PG_CTL_MODE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PG_CTL_MODE) >> BP_SATAPHY_LANE0_PG_CTL_MODE)

//! @brief Format value for bitfield SATAPHY_LANE0_PG_CTL_MODE.
#define BF_SATAPHY_LANE0_PG_CTL_MODE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PG_CTL_MODE) & BM_SATAPHY_LANE0_PG_CTL_MODE)


/* --- Register HW_SATAPHY_LANE0_PG_CTL, field TRIGGER_ERR[3] (RW)
 *
 * Inserts a single error into the LSB
 */

#define BP_SATAPHY_LANE0_PG_CTL_TRIGGER_ERR      (3)      //!< Bit position for SATAPHY_LANE0_PG_CTL_TRIGGER_ERR.
#define BM_SATAPHY_LANE0_PG_CTL_TRIGGER_ERR      (0x00000008)  //!< Bit mask for SATAPHY_LANE0_PG_CTL_TRIGGER_ERR.

//! @brief Get value of SATAPHY_LANE0_PG_CTL_TRIGGER_ERR from a register value.
#define BG_SATAPHY_LANE0_PG_CTL_TRIGGER_ERR(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PG_CTL_TRIGGER_ERR) >> BP_SATAPHY_LANE0_PG_CTL_TRIGGER_ERR)

//! @brief Format value for bitfield SATAPHY_LANE0_PG_CTL_TRIGGER_ERR.
#define BF_SATAPHY_LANE0_PG_CTL_TRIGGER_ERR(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PG_CTL_TRIGGER_ERR) & BM_SATAPHY_LANE0_PG_CTL_TRIGGER_ERR)

/* --- Register HW_SATAPHY_LANE0_PG_CTL, field PAT0[13:4] (RW)
 *
 * Pattern for modes 3-5
 */

#define BP_SATAPHY_LANE0_PG_CTL_PAT0      (4)      //!< Bit position for SATAPHY_LANE0_PG_CTL_PAT0.
#define BM_SATAPHY_LANE0_PG_CTL_PAT0      (0x00003ff0)  //!< Bit mask for SATAPHY_LANE0_PG_CTL_PAT0.

//! @brief Get value of SATAPHY_LANE0_PG_CTL_PAT0 from a register value.
#define BG_SATAPHY_LANE0_PG_CTL_PAT0(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PG_CTL_PAT0) >> BP_SATAPHY_LANE0_PG_CTL_PAT0)

//! @brief Format value for bitfield SATAPHY_LANE0_PG_CTL_PAT0.
#define BF_SATAPHY_LANE0_PG_CTL_PAT0(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PG_CTL_PAT0) & BM_SATAPHY_LANE0_PG_CTL_PAT0)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_PM_CTL - Pattern Matcher Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_PM_CTL - Pattern Matcher Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x2018  Reset value: 16'b xxxx xxxx xxxx 0000  This register contains pattern matcher
 * controls.
 */
typedef union _hw_sataphy_lane0_pm_ctl
{
    reg16_t U;
    struct _hw_sataphy_lane0_pm_ctl_bitfields
    {
        unsigned short MODE : 3; //!< [2:0] All other bits: Reserved Pattern to match:
        unsigned short SYNC : 1; //!< [3] To enable checking, "Synchronize pattern matcher LFSR with incoming data" must be turned on, then turned off.
        unsigned short RESERVED0 : 12; //!< [15:4] Reserved
    } B;
} hw_sataphy_lane0_pm_ctl_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_PM_CTL register
 */
#define HW_SATAPHY_LANE0_PM_CTL_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2018)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_PM_CTL           (*(volatile hw_sataphy_lane0_pm_ctl_t *) HW_SATAPHY_LANE0_PM_CTL_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_PM_CTL bitfields
 */

/* --- Register HW_SATAPHY_LANE0_PM_CTL, field MODE[2:0] (RW)
 *
 * All other bits: Reserved Pattern to match:
 *
 * Values:
 * 000 - Disabled
 * 001 - lfsr15
 * 010 - lfsr7
 * 011 - d[n] = d[n-10]
 * 100 - d[n] = !d[n-10]
 */

#define BP_SATAPHY_LANE0_PM_CTL_MODE      (0)      //!< Bit position for SATAPHY_LANE0_PM_CTL_MODE.
#define BM_SATAPHY_LANE0_PM_CTL_MODE      (0x00000007)  //!< Bit mask for SATAPHY_LANE0_PM_CTL_MODE.

//! @brief Get value of SATAPHY_LANE0_PM_CTL_MODE from a register value.
#define BG_SATAPHY_LANE0_PM_CTL_MODE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PM_CTL_MODE) >> BP_SATAPHY_LANE0_PM_CTL_MODE)

//! @brief Format value for bitfield SATAPHY_LANE0_PM_CTL_MODE.
#define BF_SATAPHY_LANE0_PM_CTL_MODE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PM_CTL_MODE) & BM_SATAPHY_LANE0_PM_CTL_MODE)


/* --- Register HW_SATAPHY_LANE0_PM_CTL, field SYNC[3] (RW)
 *
 * To enable checking, "Synchronize pattern matcher LFSR with incoming data" must be turned on, then
 * turned off.
 */

#define BP_SATAPHY_LANE0_PM_CTL_SYNC      (3)      //!< Bit position for SATAPHY_LANE0_PM_CTL_SYNC.
#define BM_SATAPHY_LANE0_PM_CTL_SYNC      (0x00000008)  //!< Bit mask for SATAPHY_LANE0_PM_CTL_SYNC.

//! @brief Get value of SATAPHY_LANE0_PM_CTL_SYNC from a register value.
#define BG_SATAPHY_LANE0_PM_CTL_SYNC(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PM_CTL_SYNC) >> BP_SATAPHY_LANE0_PM_CTL_SYNC)

//! @brief Format value for bitfield SATAPHY_LANE0_PM_CTL_SYNC.
#define BF_SATAPHY_LANE0_PM_CTL_SYNC(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PM_CTL_SYNC) & BM_SATAPHY_LANE0_PM_CTL_SYNC)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_PM_ERR - Pattern Matcher Error Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_PM_ERR - Pattern Matcher Error Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x2019  Reset value: 16'b xxxx xxxx xxxx xxxx (a read resets the register)  This
 * register is the pattern match error counter. When the clock to the error counter is turned off,
 * reads and writes to the register are queued until the clock is turned back on.
 */
typedef union _hw_sataphy_lane0_pm_err
{
    reg16_t U;
    struct _hw_sataphy_lane0_pm_err_bitfields
    {
        unsigned short COUNT : 15; //!< [14:0] Current error count If the ov14 field is active, the count is multiplied by 128.
        unsigned short OV14 : 1; //!< [15] If this field is active, the count is multiplied by 128. If ov14 is set to 1 and count = 2^15 - 1, indicates overflow of counter.
    } B;
} hw_sataphy_lane0_pm_err_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_PM_ERR register
 */
#define HW_SATAPHY_LANE0_PM_ERR_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2019)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_PM_ERR           (*(volatile hw_sataphy_lane0_pm_err_t *) HW_SATAPHY_LANE0_PM_ERR_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_PM_ERR bitfields
 */

/* --- Register HW_SATAPHY_LANE0_PM_ERR, field COUNT[14:0] (RW)
 *
 * Current error count If the ov14 field is active, the count is multiplied by 128.
 */

#define BP_SATAPHY_LANE0_PM_ERR_COUNT      (0)      //!< Bit position for SATAPHY_LANE0_PM_ERR_COUNT.
#define BM_SATAPHY_LANE0_PM_ERR_COUNT      (0x00007fff)  //!< Bit mask for SATAPHY_LANE0_PM_ERR_COUNT.

//! @brief Get value of SATAPHY_LANE0_PM_ERR_COUNT from a register value.
#define BG_SATAPHY_LANE0_PM_ERR_COUNT(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PM_ERR_COUNT) >> BP_SATAPHY_LANE0_PM_ERR_COUNT)

//! @brief Format value for bitfield SATAPHY_LANE0_PM_ERR_COUNT.
#define BF_SATAPHY_LANE0_PM_ERR_COUNT(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PM_ERR_COUNT) & BM_SATAPHY_LANE0_PM_ERR_COUNT)

/* --- Register HW_SATAPHY_LANE0_PM_ERR, field OV14[15] (RW)
 *
 * If this field is active, the count is multiplied by 128. If ov14 is set to 1 and count = 2^15 -
 * 1, indicates overflow of counter.
 */

#define BP_SATAPHY_LANE0_PM_ERR_OV14      (15)      //!< Bit position for SATAPHY_LANE0_PM_ERR_OV14.
#define BM_SATAPHY_LANE0_PM_ERR_OV14      (0x00008000)  //!< Bit mask for SATAPHY_LANE0_PM_ERR_OV14.

//! @brief Get value of SATAPHY_LANE0_PM_ERR_OV14 from a register value.
#define BG_SATAPHY_LANE0_PM_ERR_OV14(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PM_ERR_OV14) >> BP_SATAPHY_LANE0_PM_ERR_OV14)

//! @brief Format value for bitfield SATAPHY_LANE0_PM_ERR_OV14.
#define BF_SATAPHY_LANE0_PM_ERR_OV14(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PM_ERR_OV14) & BM_SATAPHY_LANE0_PM_ERR_OV14)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_DPLL_PHASE - DPLL Phase Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_DPLL_PHASE - DPLL Phase Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x201A  Reset value: 16'b xxxx x000 0000 0000  This register contains the current phase
 * selector value.
 */
typedef union _hw_sataphy_lane0_dpll_phase
{
    reg16_t U;
    struct _hw_sataphy_lane0_dpll_phase_bitfields
    {
        unsigned short DTHR : 1; //!< [0] Bits below the useful resolution
        unsigned short VAL : 10; //!< [10:1] Phase is .UI/512 x VAL ps from zero reference
        unsigned short RESERVED0 : 5; //!< [15:11] Reserved
    } B;
} hw_sataphy_lane0_dpll_phase_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_DPLL_PHASE register
 */
#define HW_SATAPHY_LANE0_DPLL_PHASE_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x201a)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_DPLL_PHASE           (*(volatile hw_sataphy_lane0_dpll_phase_t *) HW_SATAPHY_LANE0_DPLL_PHASE_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_DPLL_PHASE bitfields
 */

/* --- Register HW_SATAPHY_LANE0_DPLL_PHASE, field DTHR[0] (RW)
 *
 * Bits below the useful resolution
 */

#define BP_SATAPHY_LANE0_DPLL_PHASE_DTHR      (0)      //!< Bit position for SATAPHY_LANE0_DPLL_PHASE_DTHR.
#define BM_SATAPHY_LANE0_DPLL_PHASE_DTHR      (0x00000001)  //!< Bit mask for SATAPHY_LANE0_DPLL_PHASE_DTHR.

//! @brief Get value of SATAPHY_LANE0_DPLL_PHASE_DTHR from a register value.
#define BG_SATAPHY_LANE0_DPLL_PHASE_DTHR(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_DPLL_PHASE_DTHR) >> BP_SATAPHY_LANE0_DPLL_PHASE_DTHR)

//! @brief Format value for bitfield SATAPHY_LANE0_DPLL_PHASE_DTHR.
#define BF_SATAPHY_LANE0_DPLL_PHASE_DTHR(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_DPLL_PHASE_DTHR) & BM_SATAPHY_LANE0_DPLL_PHASE_DTHR)

/* --- Register HW_SATAPHY_LANE0_DPLL_PHASE, field VAL[10:1] (RW)
 *
 * Phase is .UI/512 x VAL ps from zero reference
 */

#define BP_SATAPHY_LANE0_DPLL_PHASE_VAL      (1)      //!< Bit position for SATAPHY_LANE0_DPLL_PHASE_VAL.
#define BM_SATAPHY_LANE0_DPLL_PHASE_VAL      (0x000007fe)  //!< Bit mask for SATAPHY_LANE0_DPLL_PHASE_VAL.

//! @brief Get value of SATAPHY_LANE0_DPLL_PHASE_VAL from a register value.
#define BG_SATAPHY_LANE0_DPLL_PHASE_VAL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_DPLL_PHASE_VAL) >> BP_SATAPHY_LANE0_DPLL_PHASE_VAL)

//! @brief Format value for bitfield SATAPHY_LANE0_DPLL_PHASE_VAL.
#define BF_SATAPHY_LANE0_DPLL_PHASE_VAL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_DPLL_PHASE_VAL) & BM_SATAPHY_LANE0_DPLL_PHASE_VAL)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_DPLL_FREQ - DPLL Frequency Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_DPLL_FREQ - DPLL Frequency Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x201B  Reset value: 16'b xx00 0000 0000 0000  This register contains the current
 * frequency integrator value.
 */
typedef union _hw_sataphy_lane0_dpll_freq
{
    reg16_t U;
    struct _hw_sataphy_lane0_dpll_freq_bitfields
    {
        unsigned short DTHR : 1; //!< [0] Bits below the useful resolution
        unsigned short VAL : 13; //!< [13:1] Frequency is 1.526 x VAL ppm from the reference
        unsigned short RESERVED0 : 2; //!< [15:14] Reserved
    } B;
} hw_sataphy_lane0_dpll_freq_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_DPLL_FREQ register
 */
#define HW_SATAPHY_LANE0_DPLL_FREQ_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x201b)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_DPLL_FREQ           (*(volatile hw_sataphy_lane0_dpll_freq_t *) HW_SATAPHY_LANE0_DPLL_FREQ_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_DPLL_FREQ bitfields
 */

/* --- Register HW_SATAPHY_LANE0_DPLL_FREQ, field DTHR[0] (RW)
 *
 * Bits below the useful resolution
 */

#define BP_SATAPHY_LANE0_DPLL_FREQ_DTHR      (0)      //!< Bit position for SATAPHY_LANE0_DPLL_FREQ_DTHR.
#define BM_SATAPHY_LANE0_DPLL_FREQ_DTHR      (0x00000001)  //!< Bit mask for SATAPHY_LANE0_DPLL_FREQ_DTHR.

//! @brief Get value of SATAPHY_LANE0_DPLL_FREQ_DTHR from a register value.
#define BG_SATAPHY_LANE0_DPLL_FREQ_DTHR(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_DPLL_FREQ_DTHR) >> BP_SATAPHY_LANE0_DPLL_FREQ_DTHR)

//! @brief Format value for bitfield SATAPHY_LANE0_DPLL_FREQ_DTHR.
#define BF_SATAPHY_LANE0_DPLL_FREQ_DTHR(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_DPLL_FREQ_DTHR) & BM_SATAPHY_LANE0_DPLL_FREQ_DTHR)

/* --- Register HW_SATAPHY_LANE0_DPLL_FREQ, field VAL[13:1] (RW)
 *
 * Frequency is 1.526 x VAL ppm from the reference
 */

#define BP_SATAPHY_LANE0_DPLL_FREQ_VAL      (1)      //!< Bit position for SATAPHY_LANE0_DPLL_FREQ_VAL.
#define BM_SATAPHY_LANE0_DPLL_FREQ_VAL      (0x00003ffe)  //!< Bit mask for SATAPHY_LANE0_DPLL_FREQ_VAL.

//! @brief Get value of SATAPHY_LANE0_DPLL_FREQ_VAL from a register value.
#define BG_SATAPHY_LANE0_DPLL_FREQ_VAL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_DPLL_FREQ_VAL) >> BP_SATAPHY_LANE0_DPLL_FREQ_VAL)

//! @brief Format value for bitfield SATAPHY_LANE0_DPLL_FREQ_VAL.
#define BF_SATAPHY_LANE0_DPLL_FREQ_VAL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_DPLL_FREQ_VAL) & BM_SATAPHY_LANE0_DPLL_FREQ_VAL)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_SCOPE_CTL - Scope Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_SCOPE_CTL - Scope Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x201C  Reset value: 16'b x000 0000 0000 0000  This register contains control bits for
 * the per-transceiver scope portion.
 */
typedef union _hw_sataphy_lane0_scope_ctl
{
    reg16_t U;
    struct _hw_sataphy_lane0_scope_ctl_bitfields
    {
        unsigned short MODE : 2; //!< [1:0] Mode of counters:
        unsigned short DELAY : 9; //!< [10:2] Number of symbols to skip between samples
        unsigned short BASE : 4; //!< [14:11] The bit to be sampled when mode = 2'b01
        unsigned short RESERVED0 : 1; //!< [15] Reserved
    } B;
} hw_sataphy_lane0_scope_ctl_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_SCOPE_CTL register
 */
#define HW_SATAPHY_LANE0_SCOPE_CTL_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x201c)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_SCOPE_CTL           (*(volatile hw_sataphy_lane0_scope_ctl_t *) HW_SATAPHY_LANE0_SCOPE_CTL_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_SCOPE_CTL bitfields
 */

/* --- Register HW_SATAPHY_LANE0_SCOPE_CTL, field MODE[1:0] (RW)
 *
 * Mode of counters:
 *
 * Values:
 * 00 - Off
 * 01 - Sample every 10 bits (see base)
 * 10 - Sample every 11 + 10 x delay bits
 * 11 - Sample every 12 + 10 x delay bits
 */

#define BP_SATAPHY_LANE0_SCOPE_CTL_MODE      (0)      //!< Bit position for SATAPHY_LANE0_SCOPE_CTL_MODE.
#define BM_SATAPHY_LANE0_SCOPE_CTL_MODE      (0x00000003)  //!< Bit mask for SATAPHY_LANE0_SCOPE_CTL_MODE.

//! @brief Get value of SATAPHY_LANE0_SCOPE_CTL_MODE from a register value.
#define BG_SATAPHY_LANE0_SCOPE_CTL_MODE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_SCOPE_CTL_MODE) >> BP_SATAPHY_LANE0_SCOPE_CTL_MODE)

//! @brief Format value for bitfield SATAPHY_LANE0_SCOPE_CTL_MODE.
#define BF_SATAPHY_LANE0_SCOPE_CTL_MODE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_SCOPE_CTL_MODE) & BM_SATAPHY_LANE0_SCOPE_CTL_MODE)


/* --- Register HW_SATAPHY_LANE0_SCOPE_CTL, field DELAY[10:2] (RW)
 *
 * Number of symbols to skip between samples
 */

#define BP_SATAPHY_LANE0_SCOPE_CTL_DELAY      (2)      //!< Bit position for SATAPHY_LANE0_SCOPE_CTL_DELAY.
#define BM_SATAPHY_LANE0_SCOPE_CTL_DELAY      (0x000007fc)  //!< Bit mask for SATAPHY_LANE0_SCOPE_CTL_DELAY.

//! @brief Get value of SATAPHY_LANE0_SCOPE_CTL_DELAY from a register value.
#define BG_SATAPHY_LANE0_SCOPE_CTL_DELAY(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_SCOPE_CTL_DELAY) >> BP_SATAPHY_LANE0_SCOPE_CTL_DELAY)

//! @brief Format value for bitfield SATAPHY_LANE0_SCOPE_CTL_DELAY.
#define BF_SATAPHY_LANE0_SCOPE_CTL_DELAY(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_SCOPE_CTL_DELAY) & BM_SATAPHY_LANE0_SCOPE_CTL_DELAY)

/* --- Register HW_SATAPHY_LANE0_SCOPE_CTL, field BASE[14:11] (RW)
 *
 * The bit to be sampled when mode = 2'b01
 */

#define BP_SATAPHY_LANE0_SCOPE_CTL_BASE      (11)      //!< Bit position for SATAPHY_LANE0_SCOPE_CTL_BASE.
#define BM_SATAPHY_LANE0_SCOPE_CTL_BASE      (0x00007800)  //!< Bit mask for SATAPHY_LANE0_SCOPE_CTL_BASE.

//! @brief Get value of SATAPHY_LANE0_SCOPE_CTL_BASE from a register value.
#define BG_SATAPHY_LANE0_SCOPE_CTL_BASE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_SCOPE_CTL_BASE) >> BP_SATAPHY_LANE0_SCOPE_CTL_BASE)

//! @brief Format value for bitfield SATAPHY_LANE0_SCOPE_CTL_BASE.
#define BF_SATAPHY_LANE0_SCOPE_CTL_BASE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_SCOPE_CTL_BASE) & BM_SATAPHY_LANE0_SCOPE_CTL_BASE)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_RX_CTL - Receiver Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_RX_CTL - Receiver Control Register (RW)
 *
 * Reset value: 0x0000000f
 *
 * Address: 0x201D  Reset value: 16'b x000 0000 0000 1111  This register contains control bits for
 * the receiver in the recovered domain.
 */
typedef union _hw_sataphy_lane0_rx_ctl
{
    reg16_t U;
    struct _hw_sataphy_lane0_rx_ctl_bitfields
    {
        unsigned short PHDET_EN : 2; //!< [1:0] Enables phase detector Top bit is odd slicers, bottom is even.
        unsigned short PHDET_EDGE : 2; //!< [3:2] Edges to use for phase detection Top bit is rising edges, bottom is falling.
        unsigned short PHDET_POL : 1; //!< [4] Reverses polarity of phase error
        unsigned short OVRD_DPLL_GAIN : 1; //!< [5] Overrides phase update gain (PHUG) and frequency update gain (FRUG) values
        unsigned short PHUG_VALUE : 2; //!< [7:6] Overrides value for phase update gain (PHUG)
        unsigned short FRUG_VALUE : 2; //!< [9:8] Overrides value for frequency update gain (FRUG)
        unsigned short MODE_BP : 3; //!< [12:10] Sets BP 2:0 to longer timescale (for FTS patterns):
        unsigned short OVRD_SWITCH : 1; //!< [13] Overrides the value of the data/phase MUX
        unsigned short SWITCH_VAL : 1; //!< [14] Value to override the data/phase MUX
        unsigned short RESERVED0 : 1; //!< [15] Reserved
    } B;
} hw_sataphy_lane0_rx_ctl_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_RX_CTL register
 */
#define HW_SATAPHY_LANE0_RX_CTL_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x201d)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_RX_CTL           (*(volatile hw_sataphy_lane0_rx_ctl_t *) HW_SATAPHY_LANE0_RX_CTL_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_RX_CTL bitfields
 */

/* --- Register HW_SATAPHY_LANE0_RX_CTL, field PHDET_EN[1:0] (RW)
 *
 * Enables phase detector Top bit is odd slicers, bottom is even.
 */

#define BP_SATAPHY_LANE0_RX_CTL_PHDET_EN      (0)      //!< Bit position for SATAPHY_LANE0_RX_CTL_PHDET_EN.
#define BM_SATAPHY_LANE0_RX_CTL_PHDET_EN      (0x00000003)  //!< Bit mask for SATAPHY_LANE0_RX_CTL_PHDET_EN.

//! @brief Get value of SATAPHY_LANE0_RX_CTL_PHDET_EN from a register value.
#define BG_SATAPHY_LANE0_RX_CTL_PHDET_EN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_CTL_PHDET_EN) >> BP_SATAPHY_LANE0_RX_CTL_PHDET_EN)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_CTL_PHDET_EN.
#define BF_SATAPHY_LANE0_RX_CTL_PHDET_EN(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_CTL_PHDET_EN) & BM_SATAPHY_LANE0_RX_CTL_PHDET_EN)

/* --- Register HW_SATAPHY_LANE0_RX_CTL, field PHDET_EDGE[3:2] (RW)
 *
 * Edges to use for phase detection Top bit is rising edges, bottom is falling.
 */

#define BP_SATAPHY_LANE0_RX_CTL_PHDET_EDGE      (2)      //!< Bit position for SATAPHY_LANE0_RX_CTL_PHDET_EDGE.
#define BM_SATAPHY_LANE0_RX_CTL_PHDET_EDGE      (0x0000000c)  //!< Bit mask for SATAPHY_LANE0_RX_CTL_PHDET_EDGE.

//! @brief Get value of SATAPHY_LANE0_RX_CTL_PHDET_EDGE from a register value.
#define BG_SATAPHY_LANE0_RX_CTL_PHDET_EDGE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_CTL_PHDET_EDGE) >> BP_SATAPHY_LANE0_RX_CTL_PHDET_EDGE)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_CTL_PHDET_EDGE.
#define BF_SATAPHY_LANE0_RX_CTL_PHDET_EDGE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_CTL_PHDET_EDGE) & BM_SATAPHY_LANE0_RX_CTL_PHDET_EDGE)

/* --- Register HW_SATAPHY_LANE0_RX_CTL, field PHDET_POL[4] (RW)
 *
 * Reverses polarity of phase error
 */

#define BP_SATAPHY_LANE0_RX_CTL_PHDET_POL      (4)      //!< Bit position for SATAPHY_LANE0_RX_CTL_PHDET_POL.
#define BM_SATAPHY_LANE0_RX_CTL_PHDET_POL      (0x00000010)  //!< Bit mask for SATAPHY_LANE0_RX_CTL_PHDET_POL.

//! @brief Get value of SATAPHY_LANE0_RX_CTL_PHDET_POL from a register value.
#define BG_SATAPHY_LANE0_RX_CTL_PHDET_POL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_CTL_PHDET_POL) >> BP_SATAPHY_LANE0_RX_CTL_PHDET_POL)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_CTL_PHDET_POL.
#define BF_SATAPHY_LANE0_RX_CTL_PHDET_POL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_CTL_PHDET_POL) & BM_SATAPHY_LANE0_RX_CTL_PHDET_POL)

/* --- Register HW_SATAPHY_LANE0_RX_CTL, field OVRD_DPLL_GAIN[5] (RW)
 *
 * Overrides phase update gain (PHUG) and frequency update gain (FRUG) values
 */

#define BP_SATAPHY_LANE0_RX_CTL_OVRD_DPLL_GAIN      (5)      //!< Bit position for SATAPHY_LANE0_RX_CTL_OVRD_DPLL_GAIN.
#define BM_SATAPHY_LANE0_RX_CTL_OVRD_DPLL_GAIN      (0x00000020)  //!< Bit mask for SATAPHY_LANE0_RX_CTL_OVRD_DPLL_GAIN.

//! @brief Get value of SATAPHY_LANE0_RX_CTL_OVRD_DPLL_GAIN from a register value.
#define BG_SATAPHY_LANE0_RX_CTL_OVRD_DPLL_GAIN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_CTL_OVRD_DPLL_GAIN) >> BP_SATAPHY_LANE0_RX_CTL_OVRD_DPLL_GAIN)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_CTL_OVRD_DPLL_GAIN.
#define BF_SATAPHY_LANE0_RX_CTL_OVRD_DPLL_GAIN(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_CTL_OVRD_DPLL_GAIN) & BM_SATAPHY_LANE0_RX_CTL_OVRD_DPLL_GAIN)

/* --- Register HW_SATAPHY_LANE0_RX_CTL, field PHUG_VALUE[7:6] (RW)
 *
 * Overrides value for phase update gain (PHUG)
 */

#define BP_SATAPHY_LANE0_RX_CTL_PHUG_VALUE      (6)      //!< Bit position for SATAPHY_LANE0_RX_CTL_PHUG_VALUE.
#define BM_SATAPHY_LANE0_RX_CTL_PHUG_VALUE      (0x000000c0)  //!< Bit mask for SATAPHY_LANE0_RX_CTL_PHUG_VALUE.

//! @brief Get value of SATAPHY_LANE0_RX_CTL_PHUG_VALUE from a register value.
#define BG_SATAPHY_LANE0_RX_CTL_PHUG_VALUE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_CTL_PHUG_VALUE) >> BP_SATAPHY_LANE0_RX_CTL_PHUG_VALUE)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_CTL_PHUG_VALUE.
#define BF_SATAPHY_LANE0_RX_CTL_PHUG_VALUE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_CTL_PHUG_VALUE) & BM_SATAPHY_LANE0_RX_CTL_PHUG_VALUE)

/* --- Register HW_SATAPHY_LANE0_RX_CTL, field FRUG_VALUE[9:8] (RW)
 *
 * Overrides value for frequency update gain (FRUG)
 */

#define BP_SATAPHY_LANE0_RX_CTL_FRUG_VALUE      (8)      //!< Bit position for SATAPHY_LANE0_RX_CTL_FRUG_VALUE.
#define BM_SATAPHY_LANE0_RX_CTL_FRUG_VALUE      (0x00000300)  //!< Bit mask for SATAPHY_LANE0_RX_CTL_FRUG_VALUE.

//! @brief Get value of SATAPHY_LANE0_RX_CTL_FRUG_VALUE from a register value.
#define BG_SATAPHY_LANE0_RX_CTL_FRUG_VALUE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_CTL_FRUG_VALUE) >> BP_SATAPHY_LANE0_RX_CTL_FRUG_VALUE)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_CTL_FRUG_VALUE.
#define BF_SATAPHY_LANE0_RX_CTL_FRUG_VALUE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_CTL_FRUG_VALUE) & BM_SATAPHY_LANE0_RX_CTL_FRUG_VALUE)

/* --- Register HW_SATAPHY_LANE0_RX_CTL, field MODE_BP[12:10] (RW)
 *
 * Sets BP 2:0 to longer timescale (for FTS patterns):
 *
 * Values:
 * 10 - Starts phase update gain (PHUG) profile at 4/3 cycles
 * 11 - Starts frequency update gain (FRUG) profile at 46/42 additional cycles
 * 12 - Ends frequency update gain (FRUG) profile at 142/110 additional cycles
 */

#define BP_SATAPHY_LANE0_RX_CTL_MODE_BP      (10)      //!< Bit position for SATAPHY_LANE0_RX_CTL_MODE_BP.
#define BM_SATAPHY_LANE0_RX_CTL_MODE_BP      (0x00001c00)  //!< Bit mask for SATAPHY_LANE0_RX_CTL_MODE_BP.

//! @brief Get value of SATAPHY_LANE0_RX_CTL_MODE_BP from a register value.
#define BG_SATAPHY_LANE0_RX_CTL_MODE_BP(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_CTL_MODE_BP) >> BP_SATAPHY_LANE0_RX_CTL_MODE_BP)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_CTL_MODE_BP.
#define BF_SATAPHY_LANE0_RX_CTL_MODE_BP(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_CTL_MODE_BP) & BM_SATAPHY_LANE0_RX_CTL_MODE_BP)


/* --- Register HW_SATAPHY_LANE0_RX_CTL, field OVRD_SWITCH[13] (RW)
 *
 * Overrides the value of the data/phase MUX
 */

#define BP_SATAPHY_LANE0_RX_CTL_OVRD_SWITCH      (13)      //!< Bit position for SATAPHY_LANE0_RX_CTL_OVRD_SWITCH.
#define BM_SATAPHY_LANE0_RX_CTL_OVRD_SWITCH      (0x00002000)  //!< Bit mask for SATAPHY_LANE0_RX_CTL_OVRD_SWITCH.

//! @brief Get value of SATAPHY_LANE0_RX_CTL_OVRD_SWITCH from a register value.
#define BG_SATAPHY_LANE0_RX_CTL_OVRD_SWITCH(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_CTL_OVRD_SWITCH) >> BP_SATAPHY_LANE0_RX_CTL_OVRD_SWITCH)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_CTL_OVRD_SWITCH.
#define BF_SATAPHY_LANE0_RX_CTL_OVRD_SWITCH(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_CTL_OVRD_SWITCH) & BM_SATAPHY_LANE0_RX_CTL_OVRD_SWITCH)

/* --- Register HW_SATAPHY_LANE0_RX_CTL, field SWITCH_VAL[14] (RW)
 *
 * Value to override the data/phase MUX
 */

#define BP_SATAPHY_LANE0_RX_CTL_SWITCH_VAL      (14)      //!< Bit position for SATAPHY_LANE0_RX_CTL_SWITCH_VAL.
#define BM_SATAPHY_LANE0_RX_CTL_SWITCH_VAL      (0x00004000)  //!< Bit mask for SATAPHY_LANE0_RX_CTL_SWITCH_VAL.

//! @brief Get value of SATAPHY_LANE0_RX_CTL_SWITCH_VAL from a register value.
#define BG_SATAPHY_LANE0_RX_CTL_SWITCH_VAL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_CTL_SWITCH_VAL) >> BP_SATAPHY_LANE0_RX_CTL_SWITCH_VAL)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_CTL_SWITCH_VAL.
#define BF_SATAPHY_LANE0_RX_CTL_SWITCH_VAL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_CTL_SWITCH_VAL) & BM_SATAPHY_LANE0_RX_CTL_SWITCH_VAL)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_RX_DBG - Receiver Debug Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_RX_DBG - Receiver Debug Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x201E  Reset value: 16'b xxxx xxxx 0000 0000  This register contains control bits for
 * receiver debugging.
 */
typedef union _hw_sataphy_lane0_rx_dbg
{
    reg16_t U;
    struct _hw_sataphy_lane0_rx_dbg_bitfields
    {
        unsigned short DTB_SEL0 : 4; //!< [3:0] Selects wire to go on DTB bit 0
        unsigned short DTB_SEL1 : 4; //!< [7:4] Selects wire to go on DTB bit 1
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved
    } B;
} hw_sataphy_lane0_rx_dbg_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_RX_DBG register
 */
#define HW_SATAPHY_LANE0_RX_DBG_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x201e)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_RX_DBG           (*(volatile hw_sataphy_lane0_rx_dbg_t *) HW_SATAPHY_LANE0_RX_DBG_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_RX_DBG bitfields
 */

/* --- Register HW_SATAPHY_LANE0_RX_DBG, field DTB_SEL0[3:0] (RW)
 *
 * Selects wire to go on DTB bit 0
 *
 * Values:
 * 0000 - Disabled
 * 0001 - ana_los
 * 0010 - los_ref_pos
 * 0011 - los_ref_neg_l
 * 0100 - sata_los
 * 0101 - los_rck
 * 0110 - eios_idle
 * 0111 - pcie_los
 * 1000 - coast_dpll
 * 1001 - misalign
 * 1010 - realign
 * 1011 - com_detect
 * 1100 - idl_detect
 * 1101 - fts_detect
 * 1110 - fts_err
 * 1111 - bp_state[1]
 */

#define BP_SATAPHY_LANE0_RX_DBG_DTB_SEL0      (0)      //!< Bit position for SATAPHY_LANE0_RX_DBG_DTB_SEL0.
#define BM_SATAPHY_LANE0_RX_DBG_DTB_SEL0      (0x0000000f)  //!< Bit mask for SATAPHY_LANE0_RX_DBG_DTB_SEL0.

//! @brief Get value of SATAPHY_LANE0_RX_DBG_DTB_SEL0 from a register value.
#define BG_SATAPHY_LANE0_RX_DBG_DTB_SEL0(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_DBG_DTB_SEL0) >> BP_SATAPHY_LANE0_RX_DBG_DTB_SEL0)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_DBG_DTB_SEL0.
#define BF_SATAPHY_LANE0_RX_DBG_DTB_SEL0(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_DBG_DTB_SEL0) & BM_SATAPHY_LANE0_RX_DBG_DTB_SEL0)


/* --- Register HW_SATAPHY_LANE0_RX_DBG, field DTB_SEL1[7:4] (RW)
 *
 * Selects wire to go on DTB bit 1
 *
 * Values:
 * 0000 - Disabled
 * 0001 - ana_los
 * 0010 - los_ref_pos
 * 0011 - los_ref_neg_l
 * 0100 - sata_los
 * 0101 - los_rck
 * 0110 - eios_idle
 * 0111 - pcie_los
 * 1000 - coast_dpll
 * 1001 - misalign
 * 1010 - realign
 * 1011 - com_detect
 * 1100 - idl_detect
 * 1101 - fts_detect
 * 1110 - fts_err
 * 1111 - bp_state[1]
 */

#define BP_SATAPHY_LANE0_RX_DBG_DTB_SEL1      (4)      //!< Bit position for SATAPHY_LANE0_RX_DBG_DTB_SEL1.
#define BM_SATAPHY_LANE0_RX_DBG_DTB_SEL1      (0x000000f0)  //!< Bit mask for SATAPHY_LANE0_RX_DBG_DTB_SEL1.

//! @brief Get value of SATAPHY_LANE0_RX_DBG_DTB_SEL1 from a register value.
#define BG_SATAPHY_LANE0_RX_DBG_DTB_SEL1(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_DBG_DTB_SEL1) >> BP_SATAPHY_LANE0_RX_DBG_DTB_SEL1)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_DBG_DTB_SEL1.
#define BF_SATAPHY_LANE0_RX_DBG_DTB_SEL1(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_DBG_DTB_SEL1) & BM_SATAPHY_LANE0_RX_DBG_DTB_SEL1)


//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_RX_ANA_CONTROL - Receive Analog Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_RX_ANA_CONTROL - Receive Analog Control Register (RW)
 *
 * Reset value: 0x00000020
 *
 * Address: 0x203C  Reset value: 16'b xxxx xxxx xx10 0000  This register contains Rx control bits.
 */
typedef union _hw_sataphy_lane0_rx_ana_control
{
    reg16_t U;
    struct _hw_sataphy_lane0_rx_ana_control_bitfields
    {
        unsigned short ATB_EN : 1; //!< [0] ATB enable bit When this field is set to 1, internal atb_s_p,m = external atb_s_p,m.
        unsigned short MARGIN_EN : 1; //!< [1] 1 RWCr Margin enable bit When this field is set to 1, margining is enabled. When doing margining, ensure that you set atb_en so that atb_s_p/m are connected.
        unsigned short RCK625_EN : 1; //!< [2] rck625 enable bit When this field is set to 1, pll_alt_ref is driven by ck_i_p / 2.
        unsigned short RXLBE_EN : 1; //!< [3] Wafer level (external) loopback enable bit When this field is set to 1, the lane's output (Tx) is connected to the lane's input (Rx) through pass gates.
        unsigned short RXLBI_EN : 1; //!< [4] Digital serial (internal) loopback enable bit When this field is set to 1, an output from the serializer is connected to the first comparator stage.
        unsigned short RESERVED0 : 11; //!< [15:5] Reserved
    } B;
} hw_sataphy_lane0_rx_ana_control_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_RX_ANA_CONTROL register
 */
#define HW_SATAPHY_LANE0_RX_ANA_CONTROL_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2030)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_RX_ANA_CONTROL           (*(volatile hw_sataphy_lane0_rx_ana_control_t *) HW_SATAPHY_LANE0_RX_ANA_CONTROL_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_RX_ANA_CONTROL bitfields
 */

/* --- Register HW_SATAPHY_LANE0_RX_ANA_CONTROL, field ATB_EN[0] (RW)
 *
 * ATB enable bit When this field is set to 1, internal atb_s_p,m = external atb_s_p,m.
 */

#define BP_SATAPHY_LANE0_RX_ANA_CONTROL_ATB_EN      (0)      //!< Bit position for SATAPHY_LANE0_RX_ANA_CONTROL_ATB_EN.
#define BM_SATAPHY_LANE0_RX_ANA_CONTROL_ATB_EN      (0x00000001)  //!< Bit mask for SATAPHY_LANE0_RX_ANA_CONTROL_ATB_EN.

//! @brief Get value of SATAPHY_LANE0_RX_ANA_CONTROL_ATB_EN from a register value.
#define BG_SATAPHY_LANE0_RX_ANA_CONTROL_ATB_EN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_ATB_EN) >> BP_SATAPHY_LANE0_RX_ANA_CONTROL_ATB_EN)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_ANA_CONTROL_ATB_EN.
#define BF_SATAPHY_LANE0_RX_ANA_CONTROL_ATB_EN(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_ANA_CONTROL_ATB_EN) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_ATB_EN)

/* --- Register HW_SATAPHY_LANE0_RX_ANA_CONTROL, field MARGIN_EN[1] (RW)
 *
 * 1 RWCr Margin enable bit When this field is set to 1, margining is enabled. When doing margining,
 * ensure that you set atb_en so that atb_s_p/m are connected.
 */

#define BP_SATAPHY_LANE0_RX_ANA_CONTROL_MARGIN_EN      (1)      //!< Bit position for SATAPHY_LANE0_RX_ANA_CONTROL_MARGIN_EN.
#define BM_SATAPHY_LANE0_RX_ANA_CONTROL_MARGIN_EN      (0x00000002)  //!< Bit mask for SATAPHY_LANE0_RX_ANA_CONTROL_MARGIN_EN.

//! @brief Get value of SATAPHY_LANE0_RX_ANA_CONTROL_MARGIN_EN from a register value.
#define BG_SATAPHY_LANE0_RX_ANA_CONTROL_MARGIN_EN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_MARGIN_EN) >> BP_SATAPHY_LANE0_RX_ANA_CONTROL_MARGIN_EN)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_ANA_CONTROL_MARGIN_EN.
#define BF_SATAPHY_LANE0_RX_ANA_CONTROL_MARGIN_EN(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_ANA_CONTROL_MARGIN_EN) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_MARGIN_EN)

/* --- Register HW_SATAPHY_LANE0_RX_ANA_CONTROL, field RCK625_EN[2] (RW)
 *
 * rck625 enable bit When this field is set to 1, pll_alt_ref is driven by ck_i_p / 2.
 */

#define BP_SATAPHY_LANE0_RX_ANA_CONTROL_RCK625_EN      (2)      //!< Bit position for SATAPHY_LANE0_RX_ANA_CONTROL_RCK625_EN.
#define BM_SATAPHY_LANE0_RX_ANA_CONTROL_RCK625_EN      (0x00000004)  //!< Bit mask for SATAPHY_LANE0_RX_ANA_CONTROL_RCK625_EN.

//! @brief Get value of SATAPHY_LANE0_RX_ANA_CONTROL_RCK625_EN from a register value.
#define BG_SATAPHY_LANE0_RX_ANA_CONTROL_RCK625_EN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_RCK625_EN) >> BP_SATAPHY_LANE0_RX_ANA_CONTROL_RCK625_EN)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_ANA_CONTROL_RCK625_EN.
#define BF_SATAPHY_LANE0_RX_ANA_CONTROL_RCK625_EN(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_ANA_CONTROL_RCK625_EN) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_RCK625_EN)

/* --- Register HW_SATAPHY_LANE0_RX_ANA_CONTROL, field RXLBE_EN[3] (RW)
 *
 * Wafer level (external) loopback enable bit When this field is set to 1, the lane's output (Tx) is
 * connected to the lane's input (Rx) through pass gates.
 */

#define BP_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBE_EN      (3)      //!< Bit position for SATAPHY_LANE0_RX_ANA_CONTROL_RXLBE_EN.
#define BM_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBE_EN      (0x00000008)  //!< Bit mask for SATAPHY_LANE0_RX_ANA_CONTROL_RXLBE_EN.

//! @brief Get value of SATAPHY_LANE0_RX_ANA_CONTROL_RXLBE_EN from a register value.
#define BG_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBE_EN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBE_EN) >> BP_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBE_EN)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_ANA_CONTROL_RXLBE_EN.
#define BF_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBE_EN(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBE_EN) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBE_EN)

/* --- Register HW_SATAPHY_LANE0_RX_ANA_CONTROL, field RXLBI_EN[4] (RW)
 *
 * Digital serial (internal) loopback enable bit When this field is set to 1, an output from the
 * serializer is connected to the first comparator stage.
 */

#define BP_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBI_EN      (4)      //!< Bit position for SATAPHY_LANE0_RX_ANA_CONTROL_RXLBI_EN.
#define BM_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBI_EN      (0x00000010)  //!< Bit mask for SATAPHY_LANE0_RX_ANA_CONTROL_RXLBI_EN.

//! @brief Get value of SATAPHY_LANE0_RX_ANA_CONTROL_RXLBI_EN from a register value.
#define BG_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBI_EN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBI_EN) >> BP_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBI_EN)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_ANA_CONTROL_RXLBI_EN.
#define BF_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBI_EN(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBI_EN) & BM_SATAPHY_LANE0_RX_ANA_CONTROL_RXLBI_EN)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_RX_ANA_ATB - Receive ATB Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_RX_ANA_ATB - Receive ATB Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x2031  Reset value: 16'b xxxx xxxx xx00 0000  This register contains Rx ATB bits.
 */
typedef union _hw_sataphy_lane0_rx_ana_atb
{
    reg16_t U;
    struct _hw_sataphy_lane0_rx_ana_atb_bitfields
    {
        unsigned short FORCEP_RX_P : 1; //!< [0] Connects atb_f_p to rx_p Use for measuring Rx termination.
        unsigned short FORCEP_RX_M : 1; //!< [1] Connects atb_f_p to rx_m Use for measuring Rx termination.
        unsigned short SENSEP_RX_P : 1; //!< [2] Connects atb_s_p to rx_p Use for measuring Rx termination.
        unsigned short SENSEM_RX_M : 1; //!< [3] Connects atb_s_m to rx_m Use for measuring Rx termination.
        unsigned short SENSEM_VCM : 1; //!< [4] Connects atb_s_m to Rx vcm Use in margining.
        unsigned short SENSEM_VREF_LOS : 1; //!< [5] Connects atb_s_m to vref_los (vref_rx / 14)
        unsigned short RESERVED0 : 10; //!< [15:6] Reserved
    } B;
} hw_sataphy_lane0_rx_ana_atb_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_RX_ANA_ATB register
 */
#define HW_SATAPHY_LANE0_RX_ANA_ATB_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2031)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_RX_ANA_ATB           (*(volatile hw_sataphy_lane0_rx_ana_atb_t *) HW_SATAPHY_LANE0_RX_ANA_ATB_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_RX_ANA_ATB bitfields
 */

/* --- Register HW_SATAPHY_LANE0_RX_ANA_ATB, field FORCEP_RX_P[0] (RW)
 *
 * Connects atb_f_p to rx_p Use for measuring Rx termination.
 */

#define BP_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_P      (0)      //!< Bit position for SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_P.
#define BM_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_P      (0x00000001)  //!< Bit mask for SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_P.

//! @brief Get value of SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_P from a register value.
#define BG_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_P(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_P) >> BP_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_P)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_P.
#define BF_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_P(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_P) & BM_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_P)

/* --- Register HW_SATAPHY_LANE0_RX_ANA_ATB, field FORCEP_RX_M[1] (RW)
 *
 * Connects atb_f_p to rx_m Use for measuring Rx termination.
 */

#define BP_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_M      (1)      //!< Bit position for SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_M.
#define BM_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_M      (0x00000002)  //!< Bit mask for SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_M.

//! @brief Get value of SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_M from a register value.
#define BG_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_M(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_M) >> BP_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_M)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_M.
#define BF_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_M(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_M) & BM_SATAPHY_LANE0_RX_ANA_ATB_FORCEP_RX_M)

/* --- Register HW_SATAPHY_LANE0_RX_ANA_ATB, field SENSEP_RX_P[2] (RW)
 *
 * Connects atb_s_p to rx_p Use for measuring Rx termination.
 */

#define BP_SATAPHY_LANE0_RX_ANA_ATB_SENSEP_RX_P      (2)      //!< Bit position for SATAPHY_LANE0_RX_ANA_ATB_SENSEP_RX_P.
#define BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEP_RX_P      (0x00000004)  //!< Bit mask for SATAPHY_LANE0_RX_ANA_ATB_SENSEP_RX_P.

//! @brief Get value of SATAPHY_LANE0_RX_ANA_ATB_SENSEP_RX_P from a register value.
#define BG_SATAPHY_LANE0_RX_ANA_ATB_SENSEP_RX_P(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEP_RX_P) >> BP_SATAPHY_LANE0_RX_ANA_ATB_SENSEP_RX_P)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_ANA_ATB_SENSEP_RX_P.
#define BF_SATAPHY_LANE0_RX_ANA_ATB_SENSEP_RX_P(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_ANA_ATB_SENSEP_RX_P) & BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEP_RX_P)

/* --- Register HW_SATAPHY_LANE0_RX_ANA_ATB, field SENSEM_RX_M[3] (RW)
 *
 * Connects atb_s_m to rx_m Use for measuring Rx termination.
 */

#define BP_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_RX_M      (3)      //!< Bit position for SATAPHY_LANE0_RX_ANA_ATB_SENSEM_RX_M.
#define BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_RX_M      (0x00000008)  //!< Bit mask for SATAPHY_LANE0_RX_ANA_ATB_SENSEM_RX_M.

//! @brief Get value of SATAPHY_LANE0_RX_ANA_ATB_SENSEM_RX_M from a register value.
#define BG_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_RX_M(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_RX_M) >> BP_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_RX_M)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_ANA_ATB_SENSEM_RX_M.
#define BF_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_RX_M(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_RX_M) & BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_RX_M)

/* --- Register HW_SATAPHY_LANE0_RX_ANA_ATB, field SENSEM_VCM[4] (RW)
 *
 * Connects atb_s_m to Rx vcm Use in margining.
 */

#define BP_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VCM      (4)      //!< Bit position for SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VCM.
#define BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VCM      (0x00000010)  //!< Bit mask for SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VCM.

//! @brief Get value of SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VCM from a register value.
#define BG_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VCM(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VCM) >> BP_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VCM)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VCM.
#define BF_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VCM(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VCM) & BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VCM)

/* --- Register HW_SATAPHY_LANE0_RX_ANA_ATB, field SENSEM_VREF_LOS[5] (RW)
 *
 * Connects atb_s_m to vref_los (vref_rx / 14)
 */

#define BP_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VREF_LOS      (5)      //!< Bit position for SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VREF_LOS.
#define BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VREF_LOS      (0x00000020)  //!< Bit mask for SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VREF_LOS.

//! @brief Get value of SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VREF_LOS from a register value.
#define BG_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VREF_LOS(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VREF_LOS) >> BP_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VREF_LOS)

//! @brief Format value for bitfield SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VREF_LOS.
#define BF_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VREF_LOS(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VREF_LOS) & BM_SATAPHY_LANE0_RX_ANA_ATB_SENSEM_VREF_LOS)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_PLL_PRG2 - Rx PLL Programming 2 Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_PLL_PRG2 - Rx PLL Programming 2 Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x2032  Reset value: 16'b xxxx xxxx 0000 0000  This is an 8-bit programming register.
 */
typedef union _hw_sataphy_lane0_pll_prg2
{
    reg16_t U;
    struct _hw_sataphy_lane0_pll_prg2_bitfields
    {
        unsigned short ENABLE_TEST_PD : 1; //!< [0] Controls phase interpolator test mode:
        unsigned short RESET_LCL : 1; //!< [1] Resets PLL: Field is valid only when frc_reset is set to 1'b1.
        unsigned short FRC_RESET : 1; //!< [2] Enables override of default value of pll_pwron. Enables pwron_lcl to control PLL power-on.
        unsigned short PWRON_LCL : 1; //!< [3] Controls power to PLL: Field is valid only when frc_pwron is set to 1'b1.
        unsigned short FRC_PWRON : 1; //!< [4] Enables override of default value of pll_pwron. Enables pwron_lcl to control PLL power-on.
        unsigned short HCPL_LCL : 1; //!< [5] Forces coupling in VCO: Field is valid only when frc_hcpl is set to 1'b1.
        unsigned short FRC_HCPL : 1; //!< [6] Enables override of hcpl default value. Enables hcpl_lcl to control high-coupling mode.
        unsigned short ATB_SENSE_SEL : 1; //!< [7] Controls proportional charge pump current:
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved
    } B;
} hw_sataphy_lane0_pll_prg2_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_PLL_PRG2 register
 */
#define HW_SATAPHY_LANE0_PLL_PRG2_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2032)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_PLL_PRG2           (*(volatile hw_sataphy_lane0_pll_prg2_t *) HW_SATAPHY_LANE0_PLL_PRG2_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_PLL_PRG2 bitfields
 */

/* --- Register HW_SATAPHY_LANE0_PLL_PRG2, field ENABLE_TEST_PD[0] (RW)
 *
 * Controls phase interpolator test mode:
 *
 * Values:
 * 0 - Disables phase interpolator test mode.
 * 1 - Tests phase linearity of phase interpolator and VCO.
 */

#define BP_SATAPHY_LANE0_PLL_PRG2_ENABLE_TEST_PD      (0)      //!< Bit position for SATAPHY_LANE0_PLL_PRG2_ENABLE_TEST_PD.
#define BM_SATAPHY_LANE0_PLL_PRG2_ENABLE_TEST_PD      (0x00000001)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG2_ENABLE_TEST_PD.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG2_ENABLE_TEST_PD from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG2_ENABLE_TEST_PD(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG2_ENABLE_TEST_PD) >> BP_SATAPHY_LANE0_PLL_PRG2_ENABLE_TEST_PD)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG2_ENABLE_TEST_PD.
#define BF_SATAPHY_LANE0_PLL_PRG2_ENABLE_TEST_PD(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG2_ENABLE_TEST_PD) & BM_SATAPHY_LANE0_PLL_PRG2_ENABLE_TEST_PD)


/* --- Register HW_SATAPHY_LANE0_PLL_PRG2, field RESET_LCL[1] (RW)
 *
 * Resets PLL: Field is valid only when frc_reset is set to 1'b1.
 *
 * Values:
 * 0 - PLL is in normal mode.
 * 1 - PLL is held/placed in reset.
 */

#define BP_SATAPHY_LANE0_PLL_PRG2_RESET_LCL      (1)      //!< Bit position for SATAPHY_LANE0_PLL_PRG2_RESET_LCL.
#define BM_SATAPHY_LANE0_PLL_PRG2_RESET_LCL      (0x00000002)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG2_RESET_LCL.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG2_RESET_LCL from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG2_RESET_LCL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG2_RESET_LCL) >> BP_SATAPHY_LANE0_PLL_PRG2_RESET_LCL)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG2_RESET_LCL.
#define BF_SATAPHY_LANE0_PLL_PRG2_RESET_LCL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG2_RESET_LCL) & BM_SATAPHY_LANE0_PLL_PRG2_RESET_LCL)


/* --- Register HW_SATAPHY_LANE0_PLL_PRG2, field FRC_RESET[2] (RW)
 *
 * Enables override of default value of pll_pwron. Enables pwron_lcl to control PLL power-on.
 */

#define BP_SATAPHY_LANE0_PLL_PRG2_FRC_RESET      (2)      //!< Bit position for SATAPHY_LANE0_PLL_PRG2_FRC_RESET.
#define BM_SATAPHY_LANE0_PLL_PRG2_FRC_RESET      (0x00000004)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG2_FRC_RESET.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG2_FRC_RESET from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG2_FRC_RESET(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG2_FRC_RESET) >> BP_SATAPHY_LANE0_PLL_PRG2_FRC_RESET)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG2_FRC_RESET.
#define BF_SATAPHY_LANE0_PLL_PRG2_FRC_RESET(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG2_FRC_RESET) & BM_SATAPHY_LANE0_PLL_PRG2_FRC_RESET)

/* --- Register HW_SATAPHY_LANE0_PLL_PRG2, field PWRON_LCL[3] (RW)
 *
 * Controls power to PLL: Field is valid only when frc_pwron is set to 1'b1.
 *
 * Values:
 * 0 - Powers down PLL.
 * 1 - Supplies power to PLL.
 */

#define BP_SATAPHY_LANE0_PLL_PRG2_PWRON_LCL      (3)      //!< Bit position for SATAPHY_LANE0_PLL_PRG2_PWRON_LCL.
#define BM_SATAPHY_LANE0_PLL_PRG2_PWRON_LCL      (0x00000008)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG2_PWRON_LCL.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG2_PWRON_LCL from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG2_PWRON_LCL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG2_PWRON_LCL) >> BP_SATAPHY_LANE0_PLL_PRG2_PWRON_LCL)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG2_PWRON_LCL.
#define BF_SATAPHY_LANE0_PLL_PRG2_PWRON_LCL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG2_PWRON_LCL) & BM_SATAPHY_LANE0_PLL_PRG2_PWRON_LCL)


/* --- Register HW_SATAPHY_LANE0_PLL_PRG2, field FRC_PWRON[4] (RW)
 *
 * Enables override of default value of pll_pwron. Enables pwron_lcl to control PLL power-on.
 */

#define BP_SATAPHY_LANE0_PLL_PRG2_FRC_PWRON      (4)      //!< Bit position for SATAPHY_LANE0_PLL_PRG2_FRC_PWRON.
#define BM_SATAPHY_LANE0_PLL_PRG2_FRC_PWRON      (0x00000010)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG2_FRC_PWRON.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG2_FRC_PWRON from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG2_FRC_PWRON(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG2_FRC_PWRON) >> BP_SATAPHY_LANE0_PLL_PRG2_FRC_PWRON)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG2_FRC_PWRON.
#define BF_SATAPHY_LANE0_PLL_PRG2_FRC_PWRON(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG2_FRC_PWRON) & BM_SATAPHY_LANE0_PLL_PRG2_FRC_PWRON)

/* --- Register HW_SATAPHY_LANE0_PLL_PRG2, field HCPL_LCL[5] (RW)
 *
 * Forces coupling in VCO: Field is valid only when frc_hcpl is set to 1'b1.
 *
 * Values:
 * 0 - Forces coupling in VCO to minimum.
 * 1 - Forces coupling in VCO to maximum.
 */

#define BP_SATAPHY_LANE0_PLL_PRG2_HCPL_LCL      (5)      //!< Bit position for SATAPHY_LANE0_PLL_PRG2_HCPL_LCL.
#define BM_SATAPHY_LANE0_PLL_PRG2_HCPL_LCL      (0x00000020)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG2_HCPL_LCL.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG2_HCPL_LCL from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG2_HCPL_LCL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG2_HCPL_LCL) >> BP_SATAPHY_LANE0_PLL_PRG2_HCPL_LCL)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG2_HCPL_LCL.
#define BF_SATAPHY_LANE0_PLL_PRG2_HCPL_LCL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG2_HCPL_LCL) & BM_SATAPHY_LANE0_PLL_PRG2_HCPL_LCL)


/* --- Register HW_SATAPHY_LANE0_PLL_PRG2, field FRC_HCPL[6] (RW)
 *
 * Enables override of hcpl default value. Enables hcpl_lcl to control high-coupling mode.
 */

#define BP_SATAPHY_LANE0_PLL_PRG2_FRC_HCPL      (6)      //!< Bit position for SATAPHY_LANE0_PLL_PRG2_FRC_HCPL.
#define BM_SATAPHY_LANE0_PLL_PRG2_FRC_HCPL      (0x00000040)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG2_FRC_HCPL.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG2_FRC_HCPL from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG2_FRC_HCPL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG2_FRC_HCPL) >> BP_SATAPHY_LANE0_PLL_PRG2_FRC_HCPL)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG2_FRC_HCPL.
#define BF_SATAPHY_LANE0_PLL_PRG2_FRC_HCPL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG2_FRC_HCPL) & BM_SATAPHY_LANE0_PLL_PRG2_FRC_HCPL)

/* --- Register HW_SATAPHY_LANE0_PLL_PRG2, field ATB_SENSE_SEL[7] (RW)
 *
 * Controls proportional charge pump current:
 *
 * Values:
 * 0 - Disconnects PLL from analog test bus. No PLL signals can be viewed on the ATB.
 * 1 - Enables signals internal to PLL to connect to the analog test bus.
 */

#define BP_SATAPHY_LANE0_PLL_PRG2_ATB_SENSE_SEL      (7)      //!< Bit position for SATAPHY_LANE0_PLL_PRG2_ATB_SENSE_SEL.
#define BM_SATAPHY_LANE0_PLL_PRG2_ATB_SENSE_SEL      (0x00000080)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG2_ATB_SENSE_SEL.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG2_ATB_SENSE_SEL from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG2_ATB_SENSE_SEL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG2_ATB_SENSE_SEL) >> BP_SATAPHY_LANE0_PLL_PRG2_ATB_SENSE_SEL)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG2_ATB_SENSE_SEL.
#define BF_SATAPHY_LANE0_PLL_PRG2_ATB_SENSE_SEL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG2_ATB_SENSE_SEL) & BM_SATAPHY_LANE0_PLL_PRG2_ATB_SENSE_SEL)


//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_PLL_PRG1 - Rx PLL Programming 1 Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_PLL_PRG1 - Rx PLL Programming 1 Register (RW)
 *
 * Reset value: 0x000002a9
 *
 * Address: 0x2033  Reset value: 16'b xxxx xx10 1010 1001  This is a 10-bit programming register.
 */
typedef union _hw_sataphy_lane0_pll_prg1
{
    reg16_t U;
    struct _hw_sataphy_lane0_pll_prg1_bitfields
    {
        unsigned short RESERVED0 : 2; //!< [1:0] Reserved
        unsigned short INT_CNTRL : 3; //!< [4:2] Controls integral charge pump current Integral current = (n + 1) / 8 x full_scale Default value = 3'b010: 0.375 x full_scale
        unsigned short PROP_CNTRL : 3; //!< [7:5] Controls proportional charge pump current Proportional current = (n + 1) / 8 x full_scale Default value = 3'b101: 0.75 x full_scale
        unsigned short SEL_RXCK : 1; //!< [8] Uses recovered clock as reference to the PLL:
        unsigned short RESERVED1 : 7; //!< [15:9] Reserved
    } B;
} hw_sataphy_lane0_pll_prg1_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_PLL_PRG1 register
 */
#define HW_SATAPHY_LANE0_PLL_PRG1_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2033)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_PLL_PRG1           (*(volatile hw_sataphy_lane0_pll_prg1_t *) HW_SATAPHY_LANE0_PLL_PRG1_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_PLL_PRG1 bitfields
 */

/* --- Register HW_SATAPHY_LANE0_PLL_PRG1, field INT_CNTRL[4:2] (RW)
 *
 * Controls integral charge pump current Integral current = (n + 1) / 8 x full_scale Default value =
 * 3'b010: 0.375 x full_scale
 */

#define BP_SATAPHY_LANE0_PLL_PRG1_INT_CNTRL      (2)      //!< Bit position for SATAPHY_LANE0_PLL_PRG1_INT_CNTRL.
#define BM_SATAPHY_LANE0_PLL_PRG1_INT_CNTRL      (0x0000001c)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG1_INT_CNTRL.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG1_INT_CNTRL from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG1_INT_CNTRL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG1_INT_CNTRL) >> BP_SATAPHY_LANE0_PLL_PRG1_INT_CNTRL)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG1_INT_CNTRL.
#define BF_SATAPHY_LANE0_PLL_PRG1_INT_CNTRL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG1_INT_CNTRL) & BM_SATAPHY_LANE0_PLL_PRG1_INT_CNTRL)

/* --- Register HW_SATAPHY_LANE0_PLL_PRG1, field PROP_CNTRL[7:5] (RW)
 *
 * Controls proportional charge pump current Proportional current = (n + 1) / 8 x full_scale Default
 * value = 3'b101: 0.75 x full_scale
 */

#define BP_SATAPHY_LANE0_PLL_PRG1_PROP_CNTRL      (5)      //!< Bit position for SATAPHY_LANE0_PLL_PRG1_PROP_CNTRL.
#define BM_SATAPHY_LANE0_PLL_PRG1_PROP_CNTRL      (0x000000e0)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG1_PROP_CNTRL.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG1_PROP_CNTRL from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG1_PROP_CNTRL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG1_PROP_CNTRL) >> BP_SATAPHY_LANE0_PLL_PRG1_PROP_CNTRL)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG1_PROP_CNTRL.
#define BF_SATAPHY_LANE0_PLL_PRG1_PROP_CNTRL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG1_PROP_CNTRL) & BM_SATAPHY_LANE0_PLL_PRG1_PROP_CNTRL)

/* --- Register HW_SATAPHY_LANE0_PLL_PRG1, field SEL_RXCK[8] (RW)
 *
 * Uses recovered clock as reference to the PLL:
 *
 * Values:
 * 0 - Uses MPLL output as reference to the PLL
 * 1 - Uses recovered clock as reference to PLL
 */

#define BP_SATAPHY_LANE0_PLL_PRG1_SEL_RXCK      (8)      //!< Bit position for SATAPHY_LANE0_PLL_PRG1_SEL_RXCK.
#define BM_SATAPHY_LANE0_PLL_PRG1_SEL_RXCK      (0x00000100)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG1_SEL_RXCK.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG1_SEL_RXCK from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG1_SEL_RXCK(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG1_SEL_RXCK) >> BP_SATAPHY_LANE0_PLL_PRG1_SEL_RXCK)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG1_SEL_RXCK.
#define BF_SATAPHY_LANE0_PLL_PRG1_SEL_RXCK(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG1_SEL_RXCK) & BM_SATAPHY_LANE0_PLL_PRG1_SEL_RXCK)


//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_PLL_PRG3 - Rx PLL Measurement Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_PLL_PRG3 - Rx PLL Measurement Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x2034  Reset value: 16'b xxxx xx00 0000 0000  This is a 10-bit programming register.
 */
typedef union _hw_sataphy_lane0_pll_prg3
{
    reg16_t U;
    struct _hw_sataphy_lane0_pll_prg3_bitfields
    {
        unsigned short RESERVED0 : 1; //!< [0] Reserved
        unsigned short MEAS_CROWBAR : 1; //!< [1] Measures crowbar bias voltage on atb_sense_p; gd on atb_sense_m.
        unsigned short MEAS_1V : 1; //!< [2] Measures 1-V supply voltage on atb_sense_m. If meas_vp_cp is also set, atb_sense_p,m measures vpcp - vp.
        unsigned short MEAS_VP_CP : 1; //!< [3] Measures vp_cp voltage on atb_sense_p; gd on atb_sense_m. If meas_1v is also set, atb_sense_p,m measures vpcp - vp.
        unsigned short MEAS_VCO : 1; //!< [4] Measures VCO supply voltage on atb_sense_p; gd on atb_sense_m.
        unsigned short MEAS_STARTUP : 1; //!< [5] Measures startup voltage on atb_sense_p; gd on atb_sense_m.
        unsigned short MEAS_VP16 : 1; //!< [6] Measures vp16 on atb_sense_p; gd on atb_sense_m.
        unsigned short MEAS_VREF : 1; //!< [7] Measures vref on atb_sense_p; gd on atb_sense_m. If meas_vcntrl is also set, atb_sense_p,m measures vref - vcntrl.
        unsigned short MEAS_VCNTRL : 1; //!< [8] Measures vcntrl on atb_sense_m. If meas_vref is also set, atb_sense_p,m measures vref - vcntrl.
        unsigned short MEAS_BIAS : 1; //!< [9] Measures copy of bias current in oscillator on atb_force_m.
        unsigned short RESERVED1 : 6; //!< [15:10] Reserved
    } B;
} hw_sataphy_lane0_pll_prg3_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_PLL_PRG3 register
 */
#define HW_SATAPHY_LANE0_PLL_PRG3_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2034)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_PLL_PRG3           (*(volatile hw_sataphy_lane0_pll_prg3_t *) HW_SATAPHY_LANE0_PLL_PRG3_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_PLL_PRG3 bitfields
 */

/* --- Register HW_SATAPHY_LANE0_PLL_PRG3, field MEAS_CROWBAR[1] (RW)
 *
 * Measures crowbar bias voltage on atb_sense_p; gd on atb_sense_m.
 */

#define BP_SATAPHY_LANE0_PLL_PRG3_MEAS_CROWBAR      (1)      //!< Bit position for SATAPHY_LANE0_PLL_PRG3_MEAS_CROWBAR.
#define BM_SATAPHY_LANE0_PLL_PRG3_MEAS_CROWBAR      (0x00000002)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG3_MEAS_CROWBAR.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG3_MEAS_CROWBAR from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG3_MEAS_CROWBAR(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_CROWBAR) >> BP_SATAPHY_LANE0_PLL_PRG3_MEAS_CROWBAR)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG3_MEAS_CROWBAR.
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_CROWBAR(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG3_MEAS_CROWBAR) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_CROWBAR)

/* --- Register HW_SATAPHY_LANE0_PLL_PRG3, field MEAS_1V[2] (RW)
 *
 * Measures 1-V supply voltage on atb_sense_m. If meas_vp_cp is also set, atb_sense_p,m measures
 * vpcp - vp.
 */

#define BP_SATAPHY_LANE0_PLL_PRG3_MEAS_1V      (2)      //!< Bit position for SATAPHY_LANE0_PLL_PRG3_MEAS_1V.
#define BM_SATAPHY_LANE0_PLL_PRG3_MEAS_1V      (0x00000004)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG3_MEAS_1V.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG3_MEAS_1V from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG3_MEAS_1V(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_1V) >> BP_SATAPHY_LANE0_PLL_PRG3_MEAS_1V)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG3_MEAS_1V.
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_1V(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG3_MEAS_1V) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_1V)

/* --- Register HW_SATAPHY_LANE0_PLL_PRG3, field MEAS_VP_CP[3] (RW)
 *
 * Measures vp_cp voltage on atb_sense_p; gd on atb_sense_m. If meas_1v is also set, atb_sense_p,m
 * measures vpcp - vp.
 */

#define BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VP_CP      (3)      //!< Bit position for SATAPHY_LANE0_PLL_PRG3_MEAS_VP_CP.
#define BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VP_CP      (0x00000008)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG3_MEAS_VP_CP.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG3_MEAS_VP_CP from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG3_MEAS_VP_CP(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VP_CP) >> BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VP_CP)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG3_MEAS_VP_CP.
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_VP_CP(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VP_CP) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VP_CP)

/* --- Register HW_SATAPHY_LANE0_PLL_PRG3, field MEAS_VCO[4] (RW)
 *
 * Measures VCO supply voltage on atb_sense_p; gd on atb_sense_m.
 */

#define BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VCO      (4)      //!< Bit position for SATAPHY_LANE0_PLL_PRG3_MEAS_VCO.
#define BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VCO      (0x00000010)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG3_MEAS_VCO.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG3_MEAS_VCO from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG3_MEAS_VCO(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VCO) >> BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VCO)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG3_MEAS_VCO.
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_VCO(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VCO) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VCO)

/* --- Register HW_SATAPHY_LANE0_PLL_PRG3, field MEAS_STARTUP[5] (RW)
 *
 * Measures startup voltage on atb_sense_p; gd on atb_sense_m.
 */

#define BP_SATAPHY_LANE0_PLL_PRG3_MEAS_STARTUP      (5)      //!< Bit position for SATAPHY_LANE0_PLL_PRG3_MEAS_STARTUP.
#define BM_SATAPHY_LANE0_PLL_PRG3_MEAS_STARTUP      (0x00000020)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG3_MEAS_STARTUP.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG3_MEAS_STARTUP from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG3_MEAS_STARTUP(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_STARTUP) >> BP_SATAPHY_LANE0_PLL_PRG3_MEAS_STARTUP)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG3_MEAS_STARTUP.
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_STARTUP(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG3_MEAS_STARTUP) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_STARTUP)

/* --- Register HW_SATAPHY_LANE0_PLL_PRG3, field MEAS_VP16[6] (RW)
 *
 * Measures vp16 on atb_sense_p; gd on atb_sense_m.
 */

#define BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VP16      (6)      //!< Bit position for SATAPHY_LANE0_PLL_PRG3_MEAS_VP16.
#define BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VP16      (0x00000040)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG3_MEAS_VP16.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG3_MEAS_VP16 from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG3_MEAS_VP16(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VP16) >> BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VP16)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG3_MEAS_VP16.
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_VP16(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VP16) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VP16)

/* --- Register HW_SATAPHY_LANE0_PLL_PRG3, field MEAS_VREF[7] (RW)
 *
 * Measures vref on atb_sense_p; gd on atb_sense_m. If meas_vcntrl is also set, atb_sense_p,m
 * measures vref - vcntrl.
 */

#define BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VREF      (7)      //!< Bit position for SATAPHY_LANE0_PLL_PRG3_MEAS_VREF.
#define BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VREF      (0x00000080)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG3_MEAS_VREF.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG3_MEAS_VREF from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG3_MEAS_VREF(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VREF) >> BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VREF)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG3_MEAS_VREF.
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_VREF(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VREF) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VREF)

/* --- Register HW_SATAPHY_LANE0_PLL_PRG3, field MEAS_VCNTRL[8] (RW)
 *
 * Measures vcntrl on atb_sense_m. If meas_vref is also set, atb_sense_p,m measures vref - vcntrl.
 */

#define BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VCNTRL      (8)      //!< Bit position for SATAPHY_LANE0_PLL_PRG3_MEAS_VCNTRL.
#define BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VCNTRL      (0x00000100)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG3_MEAS_VCNTRL.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG3_MEAS_VCNTRL from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG3_MEAS_VCNTRL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VCNTRL) >> BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VCNTRL)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG3_MEAS_VCNTRL.
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_VCNTRL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG3_MEAS_VCNTRL) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_VCNTRL)

/* --- Register HW_SATAPHY_LANE0_PLL_PRG3, field MEAS_BIAS[9] (RW)
 *
 * Measures copy of bias current in oscillator on atb_force_m.
 */

#define BP_SATAPHY_LANE0_PLL_PRG3_MEAS_BIAS      (9)      //!< Bit position for SATAPHY_LANE0_PLL_PRG3_MEAS_BIAS.
#define BM_SATAPHY_LANE0_PLL_PRG3_MEAS_BIAS      (0x00000200)  //!< Bit mask for SATAPHY_LANE0_PLL_PRG3_MEAS_BIAS.

//! @brief Get value of SATAPHY_LANE0_PLL_PRG3_MEAS_BIAS from a register value.
#define BG_SATAPHY_LANE0_PLL_PRG3_MEAS_BIAS(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_BIAS) >> BP_SATAPHY_LANE0_PLL_PRG3_MEAS_BIAS)

//! @brief Format value for bitfield SATAPHY_LANE0_PLL_PRG3_MEAS_BIAS.
#define BF_SATAPHY_LANE0_PLL_PRG3_MEAS_BIAS(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_PLL_PRG3_MEAS_BIAS) & BM_SATAPHY_LANE0_PLL_PRG3_MEAS_BIAS)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_TX_ANA_ATBSEL1 - Transmit ATB 1 Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_TX_ANA_ATBSEL1 - Transmit ATB 1 Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x2035  Reset value: 16"b xxxx xxxx 0000 0000  This register contains Tx ATB control
 * bits.
 */
typedef union _hw_sataphy_lane0_tx_ana_atbsel1
{
    reg16_t U;
    struct _hw_sataphy_lane0_tx_ana_atbsel1_bitfields
    {
        unsigned short VGR_S_P : 1; //!< [0] Regulator gate voltage on ATB_S_P To validate this field, set lane0.tx_ana.atbsel2.atb_en.
        unsigned short VREF_S_P : 1; //!< [1] tx_vref voltage on ATB_S_P To validate this field, set lane0.tx_ana.atbsel2.atb_en.
        unsigned short VREG_S_M : 1; //!< [2] Regulator output voltage on ATB_S_M To validate this field, set lane0.tx_ana.atbsel2.atb_en.
        unsigned short TXP_F_P : 1; //!< [3] txp connected to ATB_F_P For termination resistance measurements.
        unsigned short TXP_S_P : 1; //!< [4] txp connected to ATB_S_P To validate this field, set lane0.tx_ana.atbsel2.atb_en.
        unsigned short TXM_F_P : 1; //!< [5] txm connected to ATB_S_P For termination resistance measurements.
        unsigned short TXM_S_M : 1; //!< [6] txm on ATB_S_M To validate this field, set lane0.tx_ana.atbsel2.atb_en.
        unsigned short VBPF_S_P : 1; //!< [7] vbpf in edge rate control circuit on ATB_S_P To validate this field, set lane0.tx_ana.atbsel2.atb_en.
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved
    } B;
} hw_sataphy_lane0_tx_ana_atbsel1_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_TX_ANA_ATBSEL1 register
 */
#define HW_SATAPHY_LANE0_TX_ANA_ATBSEL1_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2035)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_TX_ANA_ATBSEL1           (*(volatile hw_sataphy_lane0_tx_ana_atbsel1_t *) HW_SATAPHY_LANE0_TX_ANA_ATBSEL1_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_TX_ANA_ATBSEL1 bitfields
 */

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL1, field VGR_S_P[0] (RW)
 *
 * Regulator gate voltage on ATB_S_P To validate this field, set lane0.tx_ana.atbsel2.atb_en.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_VGR_S_P      (0)      //!< Bit position for SATAPHY_LANE0_TX_ANA_ATBSEL1_VGR_S_P.
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VGR_S_P      (0x00000001)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_ATBSEL1_VGR_S_P.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_ATBSEL1_VGR_S_P from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_ATBSEL1_VGR_S_P(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VGR_S_P) >> BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_VGR_S_P)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_ATBSEL1_VGR_S_P.
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_VGR_S_P(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_VGR_S_P) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VGR_S_P)

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL1, field VREF_S_P[1] (RW)
 *
 * tx_vref voltage on ATB_S_P To validate this field, set lane0.tx_ana.atbsel2.atb_en.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREF_S_P      (1)      //!< Bit position for SATAPHY_LANE0_TX_ANA_ATBSEL1_VREF_S_P.
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREF_S_P      (0x00000002)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_ATBSEL1_VREF_S_P.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_ATBSEL1_VREF_S_P from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREF_S_P(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREF_S_P) >> BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREF_S_P)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_ATBSEL1_VREF_S_P.
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREF_S_P(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREF_S_P) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREF_S_P)

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL1, field VREG_S_M[2] (RW)
 *
 * Regulator output voltage on ATB_S_M To validate this field, set lane0.tx_ana.atbsel2.atb_en.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREG_S_M      (2)      //!< Bit position for SATAPHY_LANE0_TX_ANA_ATBSEL1_VREG_S_M.
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREG_S_M      (0x00000004)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_ATBSEL1_VREG_S_M.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_ATBSEL1_VREG_S_M from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREG_S_M(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREG_S_M) >> BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREG_S_M)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_ATBSEL1_VREG_S_M.
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREG_S_M(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREG_S_M) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VREG_S_M)

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL1, field TXP_F_P[3] (RW)
 *
 * txp connected to ATB_F_P For termination resistance measurements.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_F_P      (3)      //!< Bit position for SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_F_P.
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_F_P      (0x00000008)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_F_P.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_F_P from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_F_P(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_F_P) >> BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_F_P)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_F_P.
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_F_P(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_F_P) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_F_P)

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL1, field TXP_S_P[4] (RW)
 *
 * txp connected to ATB_S_P To validate this field, set lane0.tx_ana.atbsel2.atb_en.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_S_P      (4)      //!< Bit position for SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_S_P.
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_S_P      (0x00000010)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_S_P.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_S_P from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_S_P(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_S_P) >> BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_S_P)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_S_P.
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_S_P(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_S_P) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXP_S_P)

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL1, field TXM_F_P[5] (RW)
 *
 * txm connected to ATB_S_P For termination resistance measurements.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_F_P      (5)      //!< Bit position for SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_F_P.
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_F_P      (0x00000020)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_F_P.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_F_P from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_F_P(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_F_P) >> BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_F_P)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_F_P.
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_F_P(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_F_P) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_F_P)

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL1, field TXM_S_M[6] (RW)
 *
 * txm on ATB_S_M To validate this field, set lane0.tx_ana.atbsel2.atb_en.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_S_M      (6)      //!< Bit position for SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_S_M.
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_S_M      (0x00000040)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_S_M.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_S_M from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_S_M(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_S_M) >> BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_S_M)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_S_M.
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_S_M(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_S_M) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_TXM_S_M)

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL1, field VBPF_S_P[7] (RW)
 *
 * vbpf in edge rate control circuit on ATB_S_P To validate this field, set
 * lane0.tx_ana.atbsel2.atb_en.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_VBPF_S_P      (7)      //!< Bit position for SATAPHY_LANE0_TX_ANA_ATBSEL1_VBPF_S_P.
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VBPF_S_P      (0x00000080)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_ATBSEL1_VBPF_S_P.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_ATBSEL1_VBPF_S_P from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_ATBSEL1_VBPF_S_P(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VBPF_S_P) >> BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_VBPF_S_P)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_ATBSEL1_VBPF_S_P.
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL1_VBPF_S_P(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_ATBSEL1_VBPF_S_P) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL1_VBPF_S_P)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_TX_ANA_ATBSEL2 - Transmit ATB 2 Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_TX_ANA_ATBSEL2 - Transmit ATB 2 Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x2036  Reset value: 16'b xxxx xxxx 0000 0000  This register contains Tx ATB control
 * bits.
 */
typedef union _hw_sataphy_lane0_tx_ana_atbsel2
{
    reg16_t U;
    struct _hw_sataphy_lane0_tx_ana_atbsel2_bitfields
    {
        unsigned short EN_TXILPBK : 1; //!< [0] Enables Tx internal loopback
        unsigned short ENLPBK : 1; //!< [1] Enables Tx external loopback Ensure that internal loopback is not on.
        unsigned short VBNF_S_M : 1; //!< [2] vbnf in edge rate control circuit on ATB_S_M To validate this field, set the atb_en field.
        unsigned short VBPS_S_P : 1; //!< [3] vbps in edge rate control circuit on ATB_S_M To validate this field, set the atb_en field.
        unsigned short VBNS_S_M : 1; //!< [4] vbps in edge rate control circuit on ATB_S_M To validate this field, set the atb_en field.
        unsigned short VCM_S_P : 1; //!< [5] Vcm replica on ATB_S_P To validate this field, set the atb_en field.
        unsigned short VREFRXD_S_M : 1; //!< [6] Reference voltage for RX_DETECT on ATB_S_M To validate this field, set the atb_en field.
        unsigned short ATB_EN : 1; //!< [7] RWCr 7 RWCr Connects internal and external ATB buses Required for all ATB measurements.
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved
    } B;
} hw_sataphy_lane0_tx_ana_atbsel2_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_TX_ANA_ATBSEL2 register
 */
#define HW_SATAPHY_LANE0_TX_ANA_ATBSEL2_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2036)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_TX_ANA_ATBSEL2           (*(volatile hw_sataphy_lane0_tx_ana_atbsel2_t *) HW_SATAPHY_LANE0_TX_ANA_ATBSEL2_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_TX_ANA_ATBSEL2 bitfields
 */

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL2, field EN_TXILPBK[0] (RW)
 *
 * Enables Tx internal loopback
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_EN_TXILPBK      (0)      //!< Bit position for SATAPHY_LANE0_TX_ANA_ATBSEL2_EN_TXILPBK.
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_EN_TXILPBK      (0x00000001)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_ATBSEL2_EN_TXILPBK.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_ATBSEL2_EN_TXILPBK from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_ATBSEL2_EN_TXILPBK(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_EN_TXILPBK) >> BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_EN_TXILPBK)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_ATBSEL2_EN_TXILPBK.
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_EN_TXILPBK(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_EN_TXILPBK) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_EN_TXILPBK)

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL2, field ENLPBK[1] (RW)
 *
 * Enables Tx external loopback Ensure that internal loopback is not on.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_ENLPBK      (1)      //!< Bit position for SATAPHY_LANE0_TX_ANA_ATBSEL2_ENLPBK.
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_ENLPBK      (0x00000002)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_ATBSEL2_ENLPBK.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_ATBSEL2_ENLPBK from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_ATBSEL2_ENLPBK(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_ENLPBK) >> BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_ENLPBK)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_ATBSEL2_ENLPBK.
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_ENLPBK(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_ENLPBK) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_ENLPBK)

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL2, field VBNF_S_M[2] (RW)
 *
 * vbnf in edge rate control circuit on ATB_S_M To validate this field, set the atb_en field.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNF_S_M      (2)      //!< Bit position for SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNF_S_M.
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNF_S_M      (0x00000004)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNF_S_M.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNF_S_M from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNF_S_M(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNF_S_M) >> BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNF_S_M)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNF_S_M.
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNF_S_M(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNF_S_M) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNF_S_M)

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL2, field VBPS_S_P[3] (RW)
 *
 * vbps in edge rate control circuit on ATB_S_M To validate this field, set the atb_en field.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBPS_S_P      (3)      //!< Bit position for SATAPHY_LANE0_TX_ANA_ATBSEL2_VBPS_S_P.
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBPS_S_P      (0x00000008)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_ATBSEL2_VBPS_S_P.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_ATBSEL2_VBPS_S_P from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBPS_S_P(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBPS_S_P) >> BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBPS_S_P)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_ATBSEL2_VBPS_S_P.
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBPS_S_P(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBPS_S_P) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBPS_S_P)

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL2, field VBNS_S_M[4] (RW)
 *
 * vbps in edge rate control circuit on ATB_S_M To validate this field, set the atb_en field.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNS_S_M      (4)      //!< Bit position for SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNS_S_M.
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNS_S_M      (0x00000010)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNS_S_M.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNS_S_M from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNS_S_M(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNS_S_M) >> BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNS_S_M)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNS_S_M.
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNS_S_M(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNS_S_M) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VBNS_S_M)

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL2, field VCM_S_P[5] (RW)
 *
 * Vcm replica on ATB_S_P To validate this field, set the atb_en field.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VCM_S_P      (5)      //!< Bit position for SATAPHY_LANE0_TX_ANA_ATBSEL2_VCM_S_P.
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VCM_S_P      (0x00000020)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_ATBSEL2_VCM_S_P.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_ATBSEL2_VCM_S_P from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_ATBSEL2_VCM_S_P(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VCM_S_P) >> BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VCM_S_P)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_ATBSEL2_VCM_S_P.
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_VCM_S_P(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VCM_S_P) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VCM_S_P)

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL2, field VREFRXD_S_M[6] (RW)
 *
 * Reference voltage for RX_DETECT on ATB_S_M To validate this field, set the atb_en field.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VREFRXD_S_M      (6)      //!< Bit position for SATAPHY_LANE0_TX_ANA_ATBSEL2_VREFRXD_S_M.
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VREFRXD_S_M      (0x00000040)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_ATBSEL2_VREFRXD_S_M.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_ATBSEL2_VREFRXD_S_M from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_ATBSEL2_VREFRXD_S_M(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VREFRXD_S_M) >> BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VREFRXD_S_M)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_ATBSEL2_VREFRXD_S_M.
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_VREFRXD_S_M(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_VREFRXD_S_M) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_VREFRXD_S_M)

/* --- Register HW_SATAPHY_LANE0_TX_ANA_ATBSEL2, field ATB_EN[7] (RW)
 *
 * RWCr 7 RWCr Connects internal and external ATB buses Required for all ATB measurements.
 */

#define BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_ATB_EN      (7)      //!< Bit position for SATAPHY_LANE0_TX_ANA_ATBSEL2_ATB_EN.
#define BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_ATB_EN      (0x00000080)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_ATBSEL2_ATB_EN.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_ATBSEL2_ATB_EN from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_ATBSEL2_ATB_EN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_ATB_EN) >> BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_ATB_EN)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_ATBSEL2_ATB_EN.
#define BF_SATAPHY_LANE0_TX_ANA_ATBSEL2_ATB_EN(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_ATBSEL2_ATB_EN) & BM_SATAPHY_LANE0_TX_ANA_ATBSEL2_ATB_EN)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_LANE0_TX_ANA_CONTROL - Transmit Analog Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_LANE0_TX_ANA_CONTROL - Transmit Analog Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x237  Reset value: 16"b xxxx xxxx 0000 0000  This register contains Tx power state
 * control bits.
 */
typedef union _hw_sataphy_lane0_tx_ana_control
{
    reg16_t U;
    struct _hw_sataphy_lane0_tx_ana_control_bitfields
    {
        unsigned short RESERVED0 : 1; //!< [0] Reserved
        unsigned short BCN_LCL : 1; //!< [1] Local beacon on/off control value To validate this field, set lane0.tx_ana.control.frc_beacon.
        unsigned short FRC_BEACON : 1; //!< [2] Forces beacon to local value (bcn_lcl) When this field is set to 1, BCN_LVL overrides input value.
        unsigned short DATAOVRD_LCL : 1; //!< [3] RWCr Local dataovrd control value To validate this field, set lane0.tx_ana.control.frc_do.
        unsigned short FRC_DO : 1; //!< [4] Forces dataovrd locally When set to 1, this field overrides the input data_ovrd value.
        unsigned short EN_LCL : 2; //!< [6:5] Locally forces tx_en[1:0]:
        unsigned short FRC_PWRST : 1; //!< [7] Locally forces power state When this field is set to 1, the tx_en[1:0] input is overridden by en_lcl.
        unsigned short RESERVED1 : 8; //!< [15:8] Reserved
    } B;
} hw_sataphy_lane0_tx_ana_control_t;
#endif

/*
 * constants & macros for entire SATAPHY_LANE0_TX_ANA_CONTROL register
 */
#define HW_SATAPHY_LANE0_TX_ANA_CONTROL_ADDR      (REGS_SATAPHY_LANE0_BASE + 0x2037)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_LANE0_TX_ANA_CONTROL           (*(volatile hw_sataphy_lane0_tx_ana_control_t *) HW_SATAPHY_LANE0_TX_ANA_CONTROL_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_LANE0_TX_ANA_CONTROL bitfields
 */

/* --- Register HW_SATAPHY_LANE0_TX_ANA_CONTROL, field BCN_LCL[1] (RW)
 *
 * Local beacon on/off control value To validate this field, set lane0.tx_ana.control.frc_beacon.
 */

#define BP_SATAPHY_LANE0_TX_ANA_CONTROL_BCN_LCL      (1)      //!< Bit position for SATAPHY_LANE0_TX_ANA_CONTROL_BCN_LCL.
#define BM_SATAPHY_LANE0_TX_ANA_CONTROL_BCN_LCL      (0x00000002)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_CONTROL_BCN_LCL.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_CONTROL_BCN_LCL from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_CONTROL_BCN_LCL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_BCN_LCL) >> BP_SATAPHY_LANE0_TX_ANA_CONTROL_BCN_LCL)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_CONTROL_BCN_LCL.
#define BF_SATAPHY_LANE0_TX_ANA_CONTROL_BCN_LCL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_CONTROL_BCN_LCL) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_BCN_LCL)

/* --- Register HW_SATAPHY_LANE0_TX_ANA_CONTROL, field FRC_BEACON[2] (RW)
 *
 * Forces beacon to local value (bcn_lcl) When this field is set to 1, BCN_LVL overrides input
 * value.
 */

#define BP_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_BEACON      (2)      //!< Bit position for SATAPHY_LANE0_TX_ANA_CONTROL_FRC_BEACON.
#define BM_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_BEACON      (0x00000004)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_CONTROL_FRC_BEACON.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_CONTROL_FRC_BEACON from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_BEACON(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_BEACON) >> BP_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_BEACON)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_CONTROL_FRC_BEACON.
#define BF_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_BEACON(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_BEACON) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_BEACON)

/* --- Register HW_SATAPHY_LANE0_TX_ANA_CONTROL, field DATAOVRD_LCL[3] (RW)
 *
 * RWCr Local dataovrd control value To validate this field, set lane0.tx_ana.control.frc_do.
 */

#define BP_SATAPHY_LANE0_TX_ANA_CONTROL_DATAOVRD_LCL      (3)      //!< Bit position for SATAPHY_LANE0_TX_ANA_CONTROL_DATAOVRD_LCL.
#define BM_SATAPHY_LANE0_TX_ANA_CONTROL_DATAOVRD_LCL      (0x00000008)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_CONTROL_DATAOVRD_LCL.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_CONTROL_DATAOVRD_LCL from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_CONTROL_DATAOVRD_LCL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_DATAOVRD_LCL) >> BP_SATAPHY_LANE0_TX_ANA_CONTROL_DATAOVRD_LCL)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_CONTROL_DATAOVRD_LCL.
#define BF_SATAPHY_LANE0_TX_ANA_CONTROL_DATAOVRD_LCL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_CONTROL_DATAOVRD_LCL) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_DATAOVRD_LCL)

/* --- Register HW_SATAPHY_LANE0_TX_ANA_CONTROL, field FRC_DO[4] (RW)
 *
 * Forces dataovrd locally When set to 1, this field overrides the input data_ovrd value.
 */

#define BP_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_DO      (4)      //!< Bit position for SATAPHY_LANE0_TX_ANA_CONTROL_FRC_DO.
#define BM_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_DO      (0x00000010)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_CONTROL_FRC_DO.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_CONTROL_FRC_DO from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_DO(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_DO) >> BP_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_DO)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_CONTROL_FRC_DO.
#define BF_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_DO(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_DO) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_DO)

/* --- Register HW_SATAPHY_LANE0_TX_ANA_CONTROL, field EN_LCL[6:5] (RW)
 *
 * Locally forces tx_en[1:0]:
 *
 * Values:
 * 00 - Power off
 * 01 - Tx idle (slow)
 * 10 - Transmit data
 * 11 - Tx idle (fast)
 */

#define BP_SATAPHY_LANE0_TX_ANA_CONTROL_EN_LCL      (5)      //!< Bit position for SATAPHY_LANE0_TX_ANA_CONTROL_EN_LCL.
#define BM_SATAPHY_LANE0_TX_ANA_CONTROL_EN_LCL      (0x00000060)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_CONTROL_EN_LCL.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_CONTROL_EN_LCL from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_CONTROL_EN_LCL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_EN_LCL) >> BP_SATAPHY_LANE0_TX_ANA_CONTROL_EN_LCL)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_CONTROL_EN_LCL.
#define BF_SATAPHY_LANE0_TX_ANA_CONTROL_EN_LCL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_CONTROL_EN_LCL) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_EN_LCL)


/* --- Register HW_SATAPHY_LANE0_TX_ANA_CONTROL, field FRC_PWRST[7] (RW)
 *
 * Locally forces power state When this field is set to 1, the tx_en[1:0] input is overridden by
 * en_lcl.
 */

#define BP_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_PWRST      (7)      //!< Bit position for SATAPHY_LANE0_TX_ANA_CONTROL_FRC_PWRST.
#define BM_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_PWRST      (0x00000080)  //!< Bit mask for SATAPHY_LANE0_TX_ANA_CONTROL_FRC_PWRST.

//! @brief Get value of SATAPHY_LANE0_TX_ANA_CONTROL_FRC_PWRST from a register value.
#define BG_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_PWRST(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_PWRST) >> BP_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_PWRST)

//! @brief Format value for bitfield SATAPHY_LANE0_TX_ANA_CONTROL_FRC_PWRST.
#define BF_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_PWRST(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_PWRST) & BM_SATAPHY_LANE0_TX_ANA_CONTROL_FRC_PWRST)



#endif // __HW_SATAPHY_LANE0_REGISTERS_H__
