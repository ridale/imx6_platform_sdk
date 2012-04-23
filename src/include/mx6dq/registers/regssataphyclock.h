/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_SATAPHY_CLOCK_REGISTERS_H__
#define __HW_SATAPHY_CLOCK_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6DQ SATAPHY_CLOCK registers defined in this header file.
 *
 * - HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT - Creg Compare Upper Limit Register
 * - HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT - Creg Compare Lower Limit Register
 * - HW_SATAPHY_CLOCK_CRCMP_MASK - Creg Compare Mask Register
 * - HW_SATAPHY_CLOCK_CRCMP_CTL - Creg Compare Control Register
 * - HW_SATAPHY_CLOCK_CRCMP_STAT - Creg Compare Status Register
 * - HW_SATAPHY_CLOCK_SCOPE_SAMPLES - Scope Sample Count Register
 * - HW_SATAPHY_CLOCK_SCOPE_COUNT - Scope Count Result Register
 * - HW_SATAPHY_CLOCK_DAC_CTL - DAC Control Register
 * - HW_SATAPHY_CLOCK_RTUNE_CTL - Resistor Tuning Control Register
 * - HW_SATAPHY_CLOCK_ADC_OUT - ADC Output Register
 * - HW_SATAPHY_CLOCK_SS_PHASE - Spread Spectrum Phase Register
 * - HW_SATAPHY_CLOCK_CHIP_ID_HI - JTAG Chip ID (High Bits) Register
 * - HW_SATAPHY_CLOCK_CHIP_ID_LOW - JTAG Chip ID (Low Bits) Register
 * - HW_SATAPHY_CLOCK_FREQ_STAT - Frequency Status Register
 * - HW_SATAPHY_CLOCK_CTL_STAT - Control Status Register
 * - HW_SATAPHY_CLOCK_LVL_STAT - Level Status Register
 * - HW_SATAPHY_CLOCK_CREG_STAT - Creg Status Register
 * - HW_SATAPHY_CLOCK_FREW_OVRD - Frequency Override Register
 * - HW_SATAPHY_CLOCK_CTL_OVRD - Control Override Register
 * - HW_SATAPHY_CLOCK_LVL_OVRD - Level Override Register
 * - HW_SATAPHY_CLOCK_CREG_OVRD - Creg Override Register
 * - HW_SATAPHY_CLOCK_MPLL_CTL - MPLL Control Register
 * - HW_SATAPHY_CLOCK_MPLL_TEST - MPLL Test Register
 * - HW_SATAPHY_CLOCK_SS_FREQ - Spread Spectrum Frequency Register
 * - HW_SATAPHY_CLOCK_SEL_STAT - Clock Select Status Register
 * - HW_SATAPHY_CLOCK_SEL_OVRD - Clock Select Override Register
 * - HW_SATAPHY_CLOCK_RESET - Reset Register
 *
 */

//! @name Module base addresses
//@{
#ifndef REGS_SATAPHY_CLOCK_BASE
#define HW_SATAPHY_CLOCK_INSTANCE_COUNT (0) //!< Number of instances of the SATAPHY_CLOCK module.
#define REGS_SATAPHY_CLOCK_BASE (0x00000000) //!< Base address for SATAPHY_CLOCK.
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
// HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT - Creg Compare Upper Limit Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT - Creg Compare Upper Limit Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x0001  Reset value: 16'b 0000 0000 0000 0000  This register contains the less-than-
 * limit compare point.
 */
typedef union _hw_sataphy_clock_crcmp_lt_limit
{
    reg16_t U;
    struct _hw_sataphy_clock_crcmp_lt_limit_bitfields
    {
        unsigned short CRCMP_LT_LIMIT : 16; //!< [15:0] Less-than-limit compare point
    } B;
} hw_sataphy_clock_crcmp_lt_limit_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CRCMP_LT_LIMIT register
 */
#define HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x1)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT           (*(volatile hw_sataphy_clock_crcmp_lt_limit_t *) HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CRCMP_LT_LIMIT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CRCMP_LT_LIMIT, field CRCMP_LT_LIMIT[15:0] (RW)
 *
 * Less-than-limit compare point
 */

#define BP_SATAPHY_CLOCK_CRCMP_LT_LIMIT_CRCMP_LT_LIMIT      (0)      //!< Bit position for SATAPHY_CLOCK_CRCMP_LT_LIMIT_CRCMP_LT_LIMIT.
#define BM_SATAPHY_CLOCK_CRCMP_LT_LIMIT_CRCMP_LT_LIMIT      (0x0000ffff)  //!< Bit mask for SATAPHY_CLOCK_CRCMP_LT_LIMIT_CRCMP_LT_LIMIT.

//! @brief Get value of SATAPHY_CLOCK_CRCMP_LT_LIMIT_CRCMP_LT_LIMIT from a register value.
#define BG_SATAPHY_CLOCK_CRCMP_LT_LIMIT_CRCMP_LT_LIMIT(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CRCMP_LT_LIMIT_CRCMP_LT_LIMIT) >> BP_SATAPHY_CLOCK_CRCMP_LT_LIMIT_CRCMP_LT_LIMIT)

//! @brief Format value for bitfield SATAPHY_CLOCK_CRCMP_LT_LIMIT_CRCMP_LT_LIMIT.
#define BF_SATAPHY_CLOCK_CRCMP_LT_LIMIT_CRCMP_LT_LIMIT(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CRCMP_LT_LIMIT_CRCMP_LT_LIMIT) & BM_SATAPHY_CLOCK_CRCMP_LT_LIMIT_CRCMP_LT_LIMIT)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT - Creg Compare Lower Limit Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT - Creg Compare Lower Limit Register (RW)
 *
 * Reset value: 0x0000ffff
 *
 * Address: 0x0002  Reset value: 16'b 1111 1111 1111 1111  This register contains the greater-than-
 * limit compare point.
 */
typedef union _hw_sataphy_clock_crcmp_gt_limit
{
    reg16_t U;
    struct _hw_sataphy_clock_crcmp_gt_limit_bitfields
    {
        unsigned short CRCMP_GT_LIMIT : 16; //!< [15:0] Greater-than-limit compare point
    } B;
} hw_sataphy_clock_crcmp_gt_limit_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CRCMP_GT_LIMIT register
 */
#define HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x2)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT           (*(volatile hw_sataphy_clock_crcmp_gt_limit_t *) HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CRCMP_GT_LIMIT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CRCMP_GT_LIMIT, field CRCMP_GT_LIMIT[15:0] (RW)
 *
 * Greater-than-limit compare point
 */

#define BP_SATAPHY_CLOCK_CRCMP_GT_LIMIT_CRCMP_GT_LIMIT      (0)      //!< Bit position for SATAPHY_CLOCK_CRCMP_GT_LIMIT_CRCMP_GT_LIMIT.
#define BM_SATAPHY_CLOCK_CRCMP_GT_LIMIT_CRCMP_GT_LIMIT      (0x0000ffff)  //!< Bit mask for SATAPHY_CLOCK_CRCMP_GT_LIMIT_CRCMP_GT_LIMIT.

//! @brief Get value of SATAPHY_CLOCK_CRCMP_GT_LIMIT_CRCMP_GT_LIMIT from a register value.
#define BG_SATAPHY_CLOCK_CRCMP_GT_LIMIT_CRCMP_GT_LIMIT(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CRCMP_GT_LIMIT_CRCMP_GT_LIMIT) >> BP_SATAPHY_CLOCK_CRCMP_GT_LIMIT_CRCMP_GT_LIMIT)

//! @brief Format value for bitfield SATAPHY_CLOCK_CRCMP_GT_LIMIT_CRCMP_GT_LIMIT.
#define BF_SATAPHY_CLOCK_CRCMP_GT_LIMIT_CRCMP_GT_LIMIT(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CRCMP_GT_LIMIT_CRCMP_GT_LIMIT) & BM_SATAPHY_CLOCK_CRCMP_GT_LIMIT_CRCMP_GT_LIMIT)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_CRCMP_MASK - Creg Compare Mask Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CRCMP_MASK - Creg Compare Mask Register (RW)
 *
 * Reset value: 0x0000ffff
 *
 * Address: 0x0003  Reset value: 16'b 1111 1111 1111 1111  This register contains the
 * compare/scratch value mask.
 */
typedef union _hw_sataphy_clock_crcmp_mask
{
    reg16_t U;
    struct _hw_sataphy_clock_crcmp_mask_bitfields
    {
        unsigned short CRCMP_MASK : 16; //!< [15:0] Mask for comparisons
    } B;
} hw_sataphy_clock_crcmp_mask_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CRCMP_MASK register
 */
#define HW_SATAPHY_CLOCK_CRCMP_MASK_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x3)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CRCMP_MASK           (*(volatile hw_sataphy_clock_crcmp_mask_t *) HW_SATAPHY_CLOCK_CRCMP_MASK_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CRCMP_MASK bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CRCMP_MASK, field CRCMP_MASK[15:0] (RW)
 *
 * Mask for comparisons
 */

#define BP_SATAPHY_CLOCK_CRCMP_MASK_CRCMP_MASK      (0)      //!< Bit position for SATAPHY_CLOCK_CRCMP_MASK_CRCMP_MASK.
#define BM_SATAPHY_CLOCK_CRCMP_MASK_CRCMP_MASK      (0x0000ffff)  //!< Bit mask for SATAPHY_CLOCK_CRCMP_MASK_CRCMP_MASK.

//! @brief Get value of SATAPHY_CLOCK_CRCMP_MASK_CRCMP_MASK from a register value.
#define BG_SATAPHY_CLOCK_CRCMP_MASK_CRCMP_MASK(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CRCMP_MASK_CRCMP_MASK) >> BP_SATAPHY_CLOCK_CRCMP_MASK_CRCMP_MASK)

//! @brief Format value for bitfield SATAPHY_CLOCK_CRCMP_MASK_CRCMP_MASK.
#define BF_SATAPHY_CLOCK_CRCMP_MASK_CRCMP_MASK(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CRCMP_MASK_CRCMP_MASK) & BM_SATAPHY_CLOCK_CRCMP_MASK_CRCMP_MASK)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_CRCMP_CTL - Creg Compare Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CRCMP_CTL - Creg Compare Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x0004  Reset value: 16'b 0000 0000 0000 0000  This register contains the scratch space
 * control bits.
 */
typedef union _hw_sataphy_clock_crcmp_ctl
{
    reg16_t U;
    struct _hw_sataphy_clock_crcmp_ctl_bitfields
    {
        unsigned short HOLD_SCRATCH0 : 1; //!< [0] Scratch0 is not updated on register reads.
        unsigned short HOLD_SCRATCH1 : 1; //!< [1] Scratch1 is not updated on register reads.
        unsigned short RESERVED0 : 14; //!< [15:2] Reserved
    } B;
} hw_sataphy_clock_crcmp_ctl_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CRCMP_CTL register
 */
#define HW_SATAPHY_CLOCK_CRCMP_CTL_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CRCMP_CTL           (*(volatile hw_sataphy_clock_crcmp_ctl_t *) HW_SATAPHY_CLOCK_CRCMP_CTL_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CRCMP_CTL bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CRCMP_CTL, field HOLD_SCRATCH0[0] (RW)
 *
 * Scratch0 is not updated on register reads.
 */

#define BP_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH0      (0)      //!< Bit position for SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH0.
#define BM_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH0      (0x00000001)  //!< Bit mask for SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH0.

//! @brief Get value of SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH0 from a register value.
#define BG_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH0(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH0) >> BP_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH0)

//! @brief Format value for bitfield SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH0.
#define BF_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH0(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH0) & BM_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH0)

/* --- Register HW_SATAPHY_CLOCK_CRCMP_CTL, field HOLD_SCRATCH1[1] (RW)
 *
 * Scratch1 is not updated on register reads.
 */

#define BP_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH1      (1)      //!< Bit position for SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH1.
#define BM_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH1      (0x00000002)  //!< Bit mask for SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH1.

//! @brief Get value of SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH1 from a register value.
#define BG_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH1(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH1) >> BP_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH1)

//! @brief Format value for bitfield SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH1.
#define BF_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH1(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH1) & BM_SATAPHY_CLOCK_CRCMP_CTL_HOLD_SCRATCH1)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_CRCMP_STAT - Creg Compare Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CRCMP_STAT - Creg Compare Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x0005  Reset value: 16'b xxxx xxxx xxxx xxxx  This register contains the results of
 * scratch register comparisons to various limits.
 */
typedef union _hw_sataphy_clock_crcmp_stat
{
    reg16_t U;
    struct _hw_sataphy_clock_crcmp_stat_bitfields
    {
        unsigned short S0_LOW : 1; //!< [0] Masked Scratch0 is lower than CRCMP_LT_LIMIT
        unsigned short S0_HIGH : 1; //!< [1] Masked Scratch0 is higher than CRCMP_HT_LIMIT.
        unsigned short S1_S0_LOW : 1; //!< [2] Masked (Scratch1 - Scratch0) is lower than CRCMP_LT_LIMIT.
        unsigned short S1_S0_HIGH : 1; //!< [3] Masked (Scratch1 - Scratch0) is higher than CRCMP_HT_LIMIT.
        unsigned short S0_OUTSIDE : 1; //!< [4] Logical OR of S0_LOW and S0_HIGH Useful for determining if the value is near signed zero.
        unsigned short S1_S0_OUTSIDE : 1; //!< [5] Logical OR of S1_S0_LOW and S1_S0_HIGH Useful for determining if the difference is near signed zero.
        unsigned short RESERVED0 : 10; //!< [15:6] Reserved
    } B;
} hw_sataphy_clock_crcmp_stat_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CRCMP_STAT register
 */
#define HW_SATAPHY_CLOCK_CRCMP_STAT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x5)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CRCMP_STAT           (*(volatile hw_sataphy_clock_crcmp_stat_t *) HW_SATAPHY_CLOCK_CRCMP_STAT_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CRCMP_STAT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CRCMP_STAT, field S0_LOW[0] (RO)
 *
 * Masked Scratch0 is lower than CRCMP_LT_LIMIT
 */

#define BP_SATAPHY_CLOCK_CRCMP_STAT_S0_LOW      (0)      //!< Bit position for SATAPHY_CLOCK_CRCMP_STAT_S0_LOW.
#define BM_SATAPHY_CLOCK_CRCMP_STAT_S0_LOW      (0x00000001)  //!< Bit mask for SATAPHY_CLOCK_CRCMP_STAT_S0_LOW.

//! @brief Get value of SATAPHY_CLOCK_CRCMP_STAT_S0_LOW from a register value.
#define BG_SATAPHY_CLOCK_CRCMP_STAT_S0_LOW(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CRCMP_STAT_S0_LOW) >> BP_SATAPHY_CLOCK_CRCMP_STAT_S0_LOW)

/* --- Register HW_SATAPHY_CLOCK_CRCMP_STAT, field S0_HIGH[1] (RO)
 *
 * Masked Scratch0 is higher than CRCMP_HT_LIMIT.
 */

#define BP_SATAPHY_CLOCK_CRCMP_STAT_S0_HIGH      (1)      //!< Bit position for SATAPHY_CLOCK_CRCMP_STAT_S0_HIGH.
#define BM_SATAPHY_CLOCK_CRCMP_STAT_S0_HIGH      (0x00000002)  //!< Bit mask for SATAPHY_CLOCK_CRCMP_STAT_S0_HIGH.

//! @brief Get value of SATAPHY_CLOCK_CRCMP_STAT_S0_HIGH from a register value.
#define BG_SATAPHY_CLOCK_CRCMP_STAT_S0_HIGH(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CRCMP_STAT_S0_HIGH) >> BP_SATAPHY_CLOCK_CRCMP_STAT_S0_HIGH)

/* --- Register HW_SATAPHY_CLOCK_CRCMP_STAT, field S1_S0_LOW[2] (RO)
 *
 * Masked (Scratch1 - Scratch0) is lower than CRCMP_LT_LIMIT.
 */

#define BP_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_LOW      (2)      //!< Bit position for SATAPHY_CLOCK_CRCMP_STAT_S1_S0_LOW.
#define BM_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_LOW      (0x00000004)  //!< Bit mask for SATAPHY_CLOCK_CRCMP_STAT_S1_S0_LOW.

//! @brief Get value of SATAPHY_CLOCK_CRCMP_STAT_S1_S0_LOW from a register value.
#define BG_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_LOW(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_LOW) >> BP_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_LOW)

/* --- Register HW_SATAPHY_CLOCK_CRCMP_STAT, field S1_S0_HIGH[3] (RO)
 *
 * Masked (Scratch1 - Scratch0) is higher than CRCMP_HT_LIMIT.
 */

#define BP_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_HIGH      (3)      //!< Bit position for SATAPHY_CLOCK_CRCMP_STAT_S1_S0_HIGH.
#define BM_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_HIGH      (0x00000008)  //!< Bit mask for SATAPHY_CLOCK_CRCMP_STAT_S1_S0_HIGH.

//! @brief Get value of SATAPHY_CLOCK_CRCMP_STAT_S1_S0_HIGH from a register value.
#define BG_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_HIGH(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_HIGH) >> BP_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_HIGH)

/* --- Register HW_SATAPHY_CLOCK_CRCMP_STAT, field S0_OUTSIDE[4] (RO)
 *
 * Logical OR of S0_LOW and S0_HIGH Useful for determining if the value is near signed zero.
 */

#define BP_SATAPHY_CLOCK_CRCMP_STAT_S0_OUTSIDE      (4)      //!< Bit position for SATAPHY_CLOCK_CRCMP_STAT_S0_OUTSIDE.
#define BM_SATAPHY_CLOCK_CRCMP_STAT_S0_OUTSIDE      (0x00000010)  //!< Bit mask for SATAPHY_CLOCK_CRCMP_STAT_S0_OUTSIDE.

//! @brief Get value of SATAPHY_CLOCK_CRCMP_STAT_S0_OUTSIDE from a register value.
#define BG_SATAPHY_CLOCK_CRCMP_STAT_S0_OUTSIDE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CRCMP_STAT_S0_OUTSIDE) >> BP_SATAPHY_CLOCK_CRCMP_STAT_S0_OUTSIDE)

/* --- Register HW_SATAPHY_CLOCK_CRCMP_STAT, field S1_S0_OUTSIDE[5] (RO)
 *
 * Logical OR of S1_S0_LOW and S1_S0_HIGH Useful for determining if the difference is near signed
 * zero.
 */

#define BP_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_OUTSIDE      (5)      //!< Bit position for SATAPHY_CLOCK_CRCMP_STAT_S1_S0_OUTSIDE.
#define BM_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_OUTSIDE      (0x00000020)  //!< Bit mask for SATAPHY_CLOCK_CRCMP_STAT_S1_S0_OUTSIDE.

//! @brief Get value of SATAPHY_CLOCK_CRCMP_STAT_S1_S0_OUTSIDE from a register value.
#define BG_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_OUTSIDE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_OUTSIDE) >> BP_SATAPHY_CLOCK_CRCMP_STAT_S1_S0_OUTSIDE)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_SCOPE_SAMPLES - Scope Sample Count Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_SCOPE_SAMPLES - Scope Sample Count Register (RW)
 *
 * Reset value: 0x00000100
 *
 * Address: 0x0006  Reset value: 16'b 0000 0001 0000 0000  This register specifies the number of
 * samples to count.
 */
typedef union _hw_sataphy_clock_scope_samples
{
    reg16_t U;
    struct _hw_sataphy_clock_scope_samples_bitfields
    {
        unsigned short SCOPE_SAMPLES : 16; //!< [15:0] The number of samples to count
    } B;
} hw_sataphy_clock_scope_samples_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_SCOPE_SAMPLES register
 */
#define HW_SATAPHY_CLOCK_SCOPE_SAMPLES_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x6)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_SCOPE_SAMPLES           (*(volatile hw_sataphy_clock_scope_samples_t *) HW_SATAPHY_CLOCK_SCOPE_SAMPLES_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_SCOPE_SAMPLES bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_SCOPE_SAMPLES, field SCOPE_SAMPLES[15:0] (RW)
 *
 * The number of samples to count
 */

#define BP_SATAPHY_CLOCK_SCOPE_SAMPLES_SCOPE_SAMPLES      (0)      //!< Bit position for SATAPHY_CLOCK_SCOPE_SAMPLES_SCOPE_SAMPLES.
#define BM_SATAPHY_CLOCK_SCOPE_SAMPLES_SCOPE_SAMPLES      (0x0000ffff)  //!< Bit mask for SATAPHY_CLOCK_SCOPE_SAMPLES_SCOPE_SAMPLES.

//! @brief Get value of SATAPHY_CLOCK_SCOPE_SAMPLES_SCOPE_SAMPLES from a register value.
#define BG_SATAPHY_CLOCK_SCOPE_SAMPLES_SCOPE_SAMPLES(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_SCOPE_SAMPLES_SCOPE_SAMPLES) >> BP_SATAPHY_CLOCK_SCOPE_SAMPLES_SCOPE_SAMPLES)

//! @brief Format value for bitfield SATAPHY_CLOCK_SCOPE_SAMPLES_SCOPE_SAMPLES.
#define BF_SATAPHY_CLOCK_SCOPE_SAMPLES_SCOPE_SAMPLES(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_SCOPE_SAMPLES_SCOPE_SAMPLES) & BM_SATAPHY_CLOCK_SCOPE_SAMPLES_SCOPE_SAMPLES)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_SCOPE_COUNT - Scope Count Result Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_SCOPE_COUNT - Scope Count Result Register (RO)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x0007  Reset value: 16'b xxxx xxxx xxxx xxxx  This register provides the results of
 * scope counting. A write to this register starts the counting process. A value of FFFF indicates
 * that the count is still in progress.
 */
typedef union _hw_sataphy_clock_scope_count
{
    reg16_t U;
    struct _hw_sataphy_clock_scope_count_bitfields
    {
        unsigned short SCOPE_COUNT : 16; //!< [15:0] Results of scope counting
    } B;
} hw_sataphy_clock_scope_count_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_SCOPE_COUNT register
 */
#define HW_SATAPHY_CLOCK_SCOPE_COUNT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x7)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_SCOPE_COUNT           (*(volatile hw_sataphy_clock_scope_count_t *) HW_SATAPHY_CLOCK_SCOPE_COUNT_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_SCOPE_COUNT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_SCOPE_COUNT, field SCOPE_COUNT[15:0] (RO)
 *
 * Results of scope counting
 */

#define BP_SATAPHY_CLOCK_SCOPE_COUNT_SCOPE_COUNT      (0)      //!< Bit position for SATAPHY_CLOCK_SCOPE_COUNT_SCOPE_COUNT.
#define BM_SATAPHY_CLOCK_SCOPE_COUNT_SCOPE_COUNT      (0x0000ffff)  //!< Bit mask for SATAPHY_CLOCK_SCOPE_COUNT_SCOPE_COUNT.

//! @brief Get value of SATAPHY_CLOCK_SCOPE_COUNT_SCOPE_COUNT from a register value.
#define BG_SATAPHY_CLOCK_SCOPE_COUNT_SCOPE_COUNT(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_SCOPE_COUNT_SCOPE_COUNT) >> BP_SATAPHY_CLOCK_SCOPE_COUNT_SCOPE_COUNT)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_DAC_CTL - DAC Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_DAC_CTL - DAC Control Register (RW)
 *
 * Reset value: 0x000001ff
 *
 * Reset value: 16'b x000 0001 1111 1111  This register supports DAC values and controls.
 */
typedef union _hw_sataphy_clock_dac_ctl
{
    reg16_t U;
    struct _hw_sataphy_clock_dac_ctl_bitfields
    {
        unsigned short DAC_VAL : 10; //!< [9:0] Digital value to be used for DAC
        unsigned short OVRD_RTUNE_TX : 1; //!< [10] Writes DAC_VAL[5:0] to the Tx rtune bus
        unsigned short OVRD_RTUNE_RX : 1; //!< [11] Writes DAC_VAL[5:0] to the Rx rtune bus
        unsigned short DAC_MODE : 3; //!< [14:12] DAC output mode:
        unsigned short RESERVED0 : 1; //!< [15] Reserved
    } B;
} hw_sataphy_clock_dac_ctl_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_DAC_CTL register
 */
#define HW_SATAPHY_CLOCK_DAC_CTL_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_DAC_CTL           (*(volatile hw_sataphy_clock_dac_ctl_t *) HW_SATAPHY_CLOCK_DAC_CTL_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_DAC_CTL bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_DAC_CTL, field DAC_VAL[9:0] (RW)
 *
 * Digital value to be used for DAC
 */

#define BP_SATAPHY_CLOCK_DAC_CTL_DAC_VAL      (0)      //!< Bit position for SATAPHY_CLOCK_DAC_CTL_DAC_VAL.
#define BM_SATAPHY_CLOCK_DAC_CTL_DAC_VAL      (0x000003ff)  //!< Bit mask for SATAPHY_CLOCK_DAC_CTL_DAC_VAL.

//! @brief Get value of SATAPHY_CLOCK_DAC_CTL_DAC_VAL from a register value.
#define BG_SATAPHY_CLOCK_DAC_CTL_DAC_VAL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_DAC_CTL_DAC_VAL) >> BP_SATAPHY_CLOCK_DAC_CTL_DAC_VAL)

//! @brief Format value for bitfield SATAPHY_CLOCK_DAC_CTL_DAC_VAL.
#define BF_SATAPHY_CLOCK_DAC_CTL_DAC_VAL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_DAC_CTL_DAC_VAL) & BM_SATAPHY_CLOCK_DAC_CTL_DAC_VAL)

/* --- Register HW_SATAPHY_CLOCK_DAC_CTL, field OVRD_RTUNE_TX[10] (RW)
 *
 * Writes DAC_VAL[5:0] to the Tx rtune bus
 */

#define BP_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_TX      (10)      //!< Bit position for SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_TX.
#define BM_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_TX      (0x00000400)  //!< Bit mask for SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_TX.

//! @brief Get value of SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_TX from a register value.
#define BG_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_TX(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_TX) >> BP_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_TX)

//! @brief Format value for bitfield SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_TX.
#define BF_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_TX(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_TX) & BM_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_TX)

/* --- Register HW_SATAPHY_CLOCK_DAC_CTL, field OVRD_RTUNE_RX[11] (RW)
 *
 * Writes DAC_VAL[5:0] to the Rx rtune bus
 */

#define BP_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_RX      (11)      //!< Bit position for SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_RX.
#define BM_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_RX      (0x00000800)  //!< Bit mask for SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_RX.

//! @brief Get value of SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_RX from a register value.
#define BG_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_RX(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_RX) >> BP_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_RX)

//! @brief Format value for bitfield SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_RX.
#define BF_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_RX(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_RX) & BM_SATAPHY_CLOCK_DAC_CTL_OVRD_RTUNE_RX)

/* --- Register HW_SATAPHY_CLOCK_DAC_CTL, field DAC_MODE[14:12] (RW)
 *
 * DAC output mode:
 *
 * Values:
 * 000 - Powers down DAC
 * 001 - Reserved
 * 010 - High-range margining (VP25 x 418e-6 res)
 * 011 - Low-range margining (VP25 x 279e-6 res)
 * 100 - 100% range DAC, 0% offset
 * 101 - 36% range DAC, 0% offset
 * 110 - 36% range DAC, 33% offset
 * 111 - 36% range DAC, 66% offset
 */

#define BP_SATAPHY_CLOCK_DAC_CTL_DAC_MODE      (12)      //!< Bit position for SATAPHY_CLOCK_DAC_CTL_DAC_MODE.
#define BM_SATAPHY_CLOCK_DAC_CTL_DAC_MODE      (0x00007000)  //!< Bit mask for SATAPHY_CLOCK_DAC_CTL_DAC_MODE.

//! @brief Get value of SATAPHY_CLOCK_DAC_CTL_DAC_MODE from a register value.
#define BG_SATAPHY_CLOCK_DAC_CTL_DAC_MODE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_DAC_CTL_DAC_MODE) >> BP_SATAPHY_CLOCK_DAC_CTL_DAC_MODE)

//! @brief Format value for bitfield SATAPHY_CLOCK_DAC_CTL_DAC_MODE.
#define BF_SATAPHY_CLOCK_DAC_CTL_DAC_MODE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_DAC_CTL_DAC_MODE) & BM_SATAPHY_CLOCK_DAC_CTL_DAC_MODE)


//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_RTUNE_CTL - Resistor Tuning Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_RTUNE_CTL - Resistor Tuning Control Register (RW)
 *
 * Reset value: 0x00000020
 *
 * Reset value: 16'b xxxx x000 0010 0000  This register contains resistor tuning controls.
 */
typedef union _hw_sataphy_clock_rtune_ctl
{
    reg16_t U;
    struct _hw_sataphy_clock_rtune_ctl_bitfields
    {
        unsigned short MODE : 2; //!< [1:0] Resistor tune SAR mode:
        unsigned short FRC_PWRON : 1; //!< [2] Overrides internal power-on
        unsigned short PWRON_LCL : 1; //!< [3] Value of power-on to force
        unsigned short SEL_ATBP : 1; //!< [4] Selects atb_s_p for A/D measurement
        unsigned short RSC_X4 : 1; //!< [5] Sets x4 in rescal circuitry
        unsigned short DAC_CHOP : 1; //!< [6] Polarity of chop control for DAC
        unsigned short CMP_INVERT : 1; //!< [7] Inverts output of comparator (to reverse successive approximation register (SAR) feedback loop)
        unsigned short RTUNE_DIS : 1; //!< [8] Disables automatic resistor recalibrations
        unsigned short RTUNE_TRIG : 1; //!< [9] Triggers manual resistor calibration
        unsigned short ADC_TRIG : 1; //!< [10] Triggers ADC conversion
        unsigned short RESERVED0 : 5; //!< [15:11] Reserved
    } B;
} hw_sataphy_clock_rtune_ctl_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_RTUNE_CTL register
 */
#define HW_SATAPHY_CLOCK_RTUNE_CTL_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x9)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_RTUNE_CTL           (*(volatile hw_sataphy_clock_rtune_ctl_t *) HW_SATAPHY_CLOCK_RTUNE_CTL_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_RTUNE_CTL bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field MODE[1:0] (RW)
 *
 * Resistor tune SAR mode:
 *
 * Values:
 * 00 - Normal restune
 * 01 - ADC
 * 10 - Rx Resistor test
 * 11 - Tx Resistor test
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_MODE      (0)      //!< Bit position for SATAPHY_CLOCK_RTUNE_CTL_MODE.
#define BM_SATAPHY_CLOCK_RTUNE_CTL_MODE      (0x00000003)  //!< Bit mask for SATAPHY_CLOCK_RTUNE_CTL_MODE.

//! @brief Get value of SATAPHY_CLOCK_RTUNE_CTL_MODE from a register value.
#define BG_SATAPHY_CLOCK_RTUNE_CTL_MODE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_RTUNE_CTL_MODE) >> BP_SATAPHY_CLOCK_RTUNE_CTL_MODE)

//! @brief Format value for bitfield SATAPHY_CLOCK_RTUNE_CTL_MODE.
#define BF_SATAPHY_CLOCK_RTUNE_CTL_MODE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_RTUNE_CTL_MODE) & BM_SATAPHY_CLOCK_RTUNE_CTL_MODE)


/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field FRC_PWRON[2] (RW)
 *
 * Overrides internal power-on
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_FRC_PWRON      (2)      //!< Bit position for SATAPHY_CLOCK_RTUNE_CTL_FRC_PWRON.
#define BM_SATAPHY_CLOCK_RTUNE_CTL_FRC_PWRON      (0x00000004)  //!< Bit mask for SATAPHY_CLOCK_RTUNE_CTL_FRC_PWRON.

//! @brief Get value of SATAPHY_CLOCK_RTUNE_CTL_FRC_PWRON from a register value.
#define BG_SATAPHY_CLOCK_RTUNE_CTL_FRC_PWRON(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_RTUNE_CTL_FRC_PWRON) >> BP_SATAPHY_CLOCK_RTUNE_CTL_FRC_PWRON)

//! @brief Format value for bitfield SATAPHY_CLOCK_RTUNE_CTL_FRC_PWRON.
#define BF_SATAPHY_CLOCK_RTUNE_CTL_FRC_PWRON(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_RTUNE_CTL_FRC_PWRON) & BM_SATAPHY_CLOCK_RTUNE_CTL_FRC_PWRON)

/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field PWRON_LCL[3] (RW)
 *
 * Value of power-on to force
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_PWRON_LCL      (3)      //!< Bit position for SATAPHY_CLOCK_RTUNE_CTL_PWRON_LCL.
#define BM_SATAPHY_CLOCK_RTUNE_CTL_PWRON_LCL      (0x00000008)  //!< Bit mask for SATAPHY_CLOCK_RTUNE_CTL_PWRON_LCL.

//! @brief Get value of SATAPHY_CLOCK_RTUNE_CTL_PWRON_LCL from a register value.
#define BG_SATAPHY_CLOCK_RTUNE_CTL_PWRON_LCL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_RTUNE_CTL_PWRON_LCL) >> BP_SATAPHY_CLOCK_RTUNE_CTL_PWRON_LCL)

//! @brief Format value for bitfield SATAPHY_CLOCK_RTUNE_CTL_PWRON_LCL.
#define BF_SATAPHY_CLOCK_RTUNE_CTL_PWRON_LCL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_RTUNE_CTL_PWRON_LCL) & BM_SATAPHY_CLOCK_RTUNE_CTL_PWRON_LCL)

/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field SEL_ATBP[4] (RW)
 *
 * Selects atb_s_p for A/D measurement
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_SEL_ATBP      (4)      //!< Bit position for SATAPHY_CLOCK_RTUNE_CTL_SEL_ATBP.
#define BM_SATAPHY_CLOCK_RTUNE_CTL_SEL_ATBP      (0x00000010)  //!< Bit mask for SATAPHY_CLOCK_RTUNE_CTL_SEL_ATBP.

//! @brief Get value of SATAPHY_CLOCK_RTUNE_CTL_SEL_ATBP from a register value.
#define BG_SATAPHY_CLOCK_RTUNE_CTL_SEL_ATBP(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_RTUNE_CTL_SEL_ATBP) >> BP_SATAPHY_CLOCK_RTUNE_CTL_SEL_ATBP)

//! @brief Format value for bitfield SATAPHY_CLOCK_RTUNE_CTL_SEL_ATBP.
#define BF_SATAPHY_CLOCK_RTUNE_CTL_SEL_ATBP(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_RTUNE_CTL_SEL_ATBP) & BM_SATAPHY_CLOCK_RTUNE_CTL_SEL_ATBP)

/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field RSC_X4[5] (RW)
 *
 * Sets x4 in rescal circuitry
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_RSC_X4      (5)      //!< Bit position for SATAPHY_CLOCK_RTUNE_CTL_RSC_X4.
#define BM_SATAPHY_CLOCK_RTUNE_CTL_RSC_X4      (0x00000020)  //!< Bit mask for SATAPHY_CLOCK_RTUNE_CTL_RSC_X4.

//! @brief Get value of SATAPHY_CLOCK_RTUNE_CTL_RSC_X4 from a register value.
#define BG_SATAPHY_CLOCK_RTUNE_CTL_RSC_X4(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_RTUNE_CTL_RSC_X4) >> BP_SATAPHY_CLOCK_RTUNE_CTL_RSC_X4)

//! @brief Format value for bitfield SATAPHY_CLOCK_RTUNE_CTL_RSC_X4.
#define BF_SATAPHY_CLOCK_RTUNE_CTL_RSC_X4(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_RTUNE_CTL_RSC_X4) & BM_SATAPHY_CLOCK_RTUNE_CTL_RSC_X4)

/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field DAC_CHOP[6] (RW)
 *
 * Polarity of chop control for DAC
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_DAC_CHOP      (6)      //!< Bit position for SATAPHY_CLOCK_RTUNE_CTL_DAC_CHOP.
#define BM_SATAPHY_CLOCK_RTUNE_CTL_DAC_CHOP      (0x00000040)  //!< Bit mask for SATAPHY_CLOCK_RTUNE_CTL_DAC_CHOP.

//! @brief Get value of SATAPHY_CLOCK_RTUNE_CTL_DAC_CHOP from a register value.
#define BG_SATAPHY_CLOCK_RTUNE_CTL_DAC_CHOP(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_RTUNE_CTL_DAC_CHOP) >> BP_SATAPHY_CLOCK_RTUNE_CTL_DAC_CHOP)

//! @brief Format value for bitfield SATAPHY_CLOCK_RTUNE_CTL_DAC_CHOP.
#define BF_SATAPHY_CLOCK_RTUNE_CTL_DAC_CHOP(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_RTUNE_CTL_DAC_CHOP) & BM_SATAPHY_CLOCK_RTUNE_CTL_DAC_CHOP)

/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field CMP_INVERT[7] (RW)
 *
 * Inverts output of comparator (to reverse successive approximation register (SAR) feedback loop)
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_CMP_INVERT      (7)      //!< Bit position for SATAPHY_CLOCK_RTUNE_CTL_CMP_INVERT.
#define BM_SATAPHY_CLOCK_RTUNE_CTL_CMP_INVERT      (0x00000080)  //!< Bit mask for SATAPHY_CLOCK_RTUNE_CTL_CMP_INVERT.

//! @brief Get value of SATAPHY_CLOCK_RTUNE_CTL_CMP_INVERT from a register value.
#define BG_SATAPHY_CLOCK_RTUNE_CTL_CMP_INVERT(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_RTUNE_CTL_CMP_INVERT) >> BP_SATAPHY_CLOCK_RTUNE_CTL_CMP_INVERT)

//! @brief Format value for bitfield SATAPHY_CLOCK_RTUNE_CTL_CMP_INVERT.
#define BF_SATAPHY_CLOCK_RTUNE_CTL_CMP_INVERT(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_RTUNE_CTL_CMP_INVERT) & BM_SATAPHY_CLOCK_RTUNE_CTL_CMP_INVERT)

/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field RTUNE_DIS[8] (RW)
 *
 * Disables automatic resistor recalibrations
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_DIS      (8)      //!< Bit position for SATAPHY_CLOCK_RTUNE_CTL_RTUNE_DIS.
#define BM_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_DIS      (0x00000100)  //!< Bit mask for SATAPHY_CLOCK_RTUNE_CTL_RTUNE_DIS.

//! @brief Get value of SATAPHY_CLOCK_RTUNE_CTL_RTUNE_DIS from a register value.
#define BG_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_DIS(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_DIS) >> BP_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_DIS)

//! @brief Format value for bitfield SATAPHY_CLOCK_RTUNE_CTL_RTUNE_DIS.
#define BF_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_DIS(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_DIS) & BM_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_DIS)

/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field RTUNE_TRIG[9] (RW)
 *
 * Triggers manual resistor calibration
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_TRIG      (9)      //!< Bit position for SATAPHY_CLOCK_RTUNE_CTL_RTUNE_TRIG.
#define BM_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_TRIG      (0x00000200)  //!< Bit mask for SATAPHY_CLOCK_RTUNE_CTL_RTUNE_TRIG.

//! @brief Get value of SATAPHY_CLOCK_RTUNE_CTL_RTUNE_TRIG from a register value.
#define BG_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_TRIG(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_TRIG) >> BP_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_TRIG)

//! @brief Format value for bitfield SATAPHY_CLOCK_RTUNE_CTL_RTUNE_TRIG.
#define BF_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_TRIG(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_TRIG) & BM_SATAPHY_CLOCK_RTUNE_CTL_RTUNE_TRIG)

/* --- Register HW_SATAPHY_CLOCK_RTUNE_CTL, field ADC_TRIG[10] (RW)
 *
 * Triggers ADC conversion
 */

#define BP_SATAPHY_CLOCK_RTUNE_CTL_ADC_TRIG      (10)      //!< Bit position for SATAPHY_CLOCK_RTUNE_CTL_ADC_TRIG.
#define BM_SATAPHY_CLOCK_RTUNE_CTL_ADC_TRIG      (0x00000400)  //!< Bit mask for SATAPHY_CLOCK_RTUNE_CTL_ADC_TRIG.

//! @brief Get value of SATAPHY_CLOCK_RTUNE_CTL_ADC_TRIG from a register value.
#define BG_SATAPHY_CLOCK_RTUNE_CTL_ADC_TRIG(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_RTUNE_CTL_ADC_TRIG) >> BP_SATAPHY_CLOCK_RTUNE_CTL_ADC_TRIG)

//! @brief Format value for bitfield SATAPHY_CLOCK_RTUNE_CTL_ADC_TRIG.
#define BF_SATAPHY_CLOCK_RTUNE_CTL_ADC_TRIG(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_RTUNE_CTL_ADC_TRIG) & BM_SATAPHY_CLOCK_RTUNE_CTL_ADC_TRIG)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_ADC_OUT - ADC Output Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_ADC_OUT - ADC Output Register (RO)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x000A  Reset value: 16'b xxxx xxxx xxxx xxxx  This register contains the results of the
 * ADC process. A read from this register starts a new A/D conversion.
 */
typedef union _hw_sataphy_clock_adc_out
{
    reg16_t U;
    struct _hw_sataphy_clock_adc_out_bitfields
    {
        unsigned short VALUE : 10; //!< [9:0] A/D conversion result Based on RTUNE_CTL.MODE, this value is the result of either the last conversion (MODES 0 or 1) or the current Tx/Rx cal value (MODES 3/2).
        unsigned short FRESH : 1; //!< [10] Flag indicates that a new A/D conversion result is present.
        unsigned short RESERVED0 : 5; //!< [15:11] Reserved
    } B;
} hw_sataphy_clock_adc_out_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_ADC_OUT register
 */
#define HW_SATAPHY_CLOCK_ADC_OUT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0xa)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_ADC_OUT           (*(volatile hw_sataphy_clock_adc_out_t *) HW_SATAPHY_CLOCK_ADC_OUT_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_ADC_OUT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_ADC_OUT, field VALUE[9:0] (RO)
 *
 * A/D conversion result Based on RTUNE_CTL.MODE, this value is the result of either the last
 * conversion (MODES 0 or 1) or the current Tx/Rx cal value (MODES 3/2).
 */

#define BP_SATAPHY_CLOCK_ADC_OUT_VALUE      (0)      //!< Bit position for SATAPHY_CLOCK_ADC_OUT_VALUE.
#define BM_SATAPHY_CLOCK_ADC_OUT_VALUE      (0x000003ff)  //!< Bit mask for SATAPHY_CLOCK_ADC_OUT_VALUE.

//! @brief Get value of SATAPHY_CLOCK_ADC_OUT_VALUE from a register value.
#define BG_SATAPHY_CLOCK_ADC_OUT_VALUE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_ADC_OUT_VALUE) >> BP_SATAPHY_CLOCK_ADC_OUT_VALUE)

/* --- Register HW_SATAPHY_CLOCK_ADC_OUT, field FRESH[10] (RO)
 *
 * Flag indicates that a new A/D conversion result is present.
 */

#define BP_SATAPHY_CLOCK_ADC_OUT_FRESH      (10)      //!< Bit position for SATAPHY_CLOCK_ADC_OUT_FRESH.
#define BM_SATAPHY_CLOCK_ADC_OUT_FRESH      (0x00000400)  //!< Bit mask for SATAPHY_CLOCK_ADC_OUT_FRESH.

//! @brief Get value of SATAPHY_CLOCK_ADC_OUT_FRESH from a register value.
#define BG_SATAPHY_CLOCK_ADC_OUT_FRESH(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_ADC_OUT_FRESH) >> BP_SATAPHY_CLOCK_ADC_OUT_FRESH)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_SS_PHASE - Spread Spectrum Phase Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_SS_PHASE - Spread Spectrum Phase Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x000B  Reset value: 16'b xxx0 0000 0000 0000  This register contains the current MPLL
 * phase selector value.
 */
typedef union _hw_sataphy_clock_ss_phase
{
    reg16_t U;
    struct _hw_sataphy_clock_ss_phase_bitfields
    {
        unsigned short DTHR : 2; //!< [1:0] Bits below the useful resolution
        unsigned short VAL : 10; //!< [11:2] Phase value from zero reference
        unsigned short ZERO_FREQ : 1; //!< [12] Zero frequency register Must be set for PHASE writes to not be immediately overwritten.
        unsigned short RESERVED0 : 3; //!< [15:13] Reserved
    } B;
} hw_sataphy_clock_ss_phase_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_SS_PHASE register
 */
#define HW_SATAPHY_CLOCK_SS_PHASE_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0xb)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_SS_PHASE           (*(volatile hw_sataphy_clock_ss_phase_t *) HW_SATAPHY_CLOCK_SS_PHASE_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_SS_PHASE bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_SS_PHASE, field DTHR[1:0] (RW)
 *
 * Bits below the useful resolution
 */

#define BP_SATAPHY_CLOCK_SS_PHASE_DTHR      (0)      //!< Bit position for SATAPHY_CLOCK_SS_PHASE_DTHR.
#define BM_SATAPHY_CLOCK_SS_PHASE_DTHR      (0x00000003)  //!< Bit mask for SATAPHY_CLOCK_SS_PHASE_DTHR.

//! @brief Get value of SATAPHY_CLOCK_SS_PHASE_DTHR from a register value.
#define BG_SATAPHY_CLOCK_SS_PHASE_DTHR(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_SS_PHASE_DTHR) >> BP_SATAPHY_CLOCK_SS_PHASE_DTHR)

//! @brief Format value for bitfield SATAPHY_CLOCK_SS_PHASE_DTHR.
#define BF_SATAPHY_CLOCK_SS_PHASE_DTHR(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_SS_PHASE_DTHR) & BM_SATAPHY_CLOCK_SS_PHASE_DTHR)

/* --- Register HW_SATAPHY_CLOCK_SS_PHASE, field VAL[11:2] (RW)
 *
 * Phase value from zero reference
 */

#define BP_SATAPHY_CLOCK_SS_PHASE_VAL      (2)      //!< Bit position for SATAPHY_CLOCK_SS_PHASE_VAL.
#define BM_SATAPHY_CLOCK_SS_PHASE_VAL      (0x00000ffc)  //!< Bit mask for SATAPHY_CLOCK_SS_PHASE_VAL.

//! @brief Get value of SATAPHY_CLOCK_SS_PHASE_VAL from a register value.
#define BG_SATAPHY_CLOCK_SS_PHASE_VAL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_SS_PHASE_VAL) >> BP_SATAPHY_CLOCK_SS_PHASE_VAL)

//! @brief Format value for bitfield SATAPHY_CLOCK_SS_PHASE_VAL.
#define BF_SATAPHY_CLOCK_SS_PHASE_VAL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_SS_PHASE_VAL) & BM_SATAPHY_CLOCK_SS_PHASE_VAL)

/* --- Register HW_SATAPHY_CLOCK_SS_PHASE, field ZERO_FREQ[12] (RW)
 *
 * Zero frequency register Must be set for PHASE writes to not be immediately overwritten.
 */

#define BP_SATAPHY_CLOCK_SS_PHASE_ZERO_FREQ      (12)      //!< Bit position for SATAPHY_CLOCK_SS_PHASE_ZERO_FREQ.
#define BM_SATAPHY_CLOCK_SS_PHASE_ZERO_FREQ      (0x00001000)  //!< Bit mask for SATAPHY_CLOCK_SS_PHASE_ZERO_FREQ.

//! @brief Get value of SATAPHY_CLOCK_SS_PHASE_ZERO_FREQ from a register value.
#define BG_SATAPHY_CLOCK_SS_PHASE_ZERO_FREQ(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_SS_PHASE_ZERO_FREQ) >> BP_SATAPHY_CLOCK_SS_PHASE_ZERO_FREQ)

//! @brief Format value for bitfield SATAPHY_CLOCK_SS_PHASE_ZERO_FREQ.
#define BF_SATAPHY_CLOCK_SS_PHASE_ZERO_FREQ(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_SS_PHASE_ZERO_FREQ) & BM_SATAPHY_CLOCK_SS_PHASE_ZERO_FREQ)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_CHIP_ID_HI - JTAG Chip ID (High Bits) Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CHIP_ID_HI - JTAG Chip ID (High Bits) Register (RO)
 *
 * Reset value: 0x00000011
 *
 * Address: 0x000C  Reset value: See value for ID_VAL_HI in .  This register contains the internal
 * chip ID (high 16 bits) of the JTAG interface.
 */
typedef union _hw_sataphy_clock_chip_id_hi
{
    reg16_t U;
    struct _hw_sataphy_clock_chip_id_hi_bitfields
    {
        unsigned short CHIP_ID_HI : 16; //!< [15:0] Internal chip ID (high 16 bits)
    } B;
} hw_sataphy_clock_chip_id_hi_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CHIP_ID_HI register
 */
#define HW_SATAPHY_CLOCK_CHIP_ID_HI_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CHIP_ID_HI           (*(volatile hw_sataphy_clock_chip_id_hi_t *) HW_SATAPHY_CLOCK_CHIP_ID_HI_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CHIP_ID_HI bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CHIP_ID_HI, field CHIP_ID_HI[15:0] (RO)
 *
 * Internal chip ID (high 16 bits)
 */

#define BP_SATAPHY_CLOCK_CHIP_ID_HI_CHIP_ID_HI      (0)      //!< Bit position for SATAPHY_CLOCK_CHIP_ID_HI_CHIP_ID_HI.
#define BM_SATAPHY_CLOCK_CHIP_ID_HI_CHIP_ID_HI      (0x0000ffff)  //!< Bit mask for SATAPHY_CLOCK_CHIP_ID_HI_CHIP_ID_HI.

//! @brief Get value of SATAPHY_CLOCK_CHIP_ID_HI_CHIP_ID_HI from a register value.
#define BG_SATAPHY_CLOCK_CHIP_ID_HI_CHIP_ID_HI(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CHIP_ID_HI_CHIP_ID_HI) >> BP_SATAPHY_CLOCK_CHIP_ID_HI_CHIP_ID_HI)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_CHIP_ID_LOW - JTAG Chip ID (Low Bits) Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CHIP_ID_LOW - JTAG Chip ID (Low Bits) Register (RO)
 *
 * Reset value: 0x000074cd
 *
 * Address: 0x000D  Reset value: See value for ID_VAL_LO in .  This register contains the internal
 * chip ID (low 16 bits) of the JTAG interface.
 */
typedef union _hw_sataphy_clock_chip_id_low
{
    reg16_t U;
    struct _hw_sataphy_clock_chip_id_low_bitfields
    {
        unsigned short CHIP_ID_LO : 16; //!< [15:0] Internal chip ID (low 16 bits)
    } B;
} hw_sataphy_clock_chip_id_low_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CHIP_ID_LOW register
 */
#define HW_SATAPHY_CLOCK_CHIP_ID_LOW_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0xd)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CHIP_ID_LOW           (*(volatile hw_sataphy_clock_chip_id_low_t *) HW_SATAPHY_CLOCK_CHIP_ID_LOW_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CHIP_ID_LOW bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CHIP_ID_LOW, field CHIP_ID_LO[15:0] (RO)
 *
 * Internal chip ID (low 16 bits)
 */

#define BP_SATAPHY_CLOCK_CHIP_ID_LOW_CHIP_ID_LO      (0)      //!< Bit position for SATAPHY_CLOCK_CHIP_ID_LOW_CHIP_ID_LO.
#define BM_SATAPHY_CLOCK_CHIP_ID_LOW_CHIP_ID_LO      (0x0000ffff)  //!< Bit mask for SATAPHY_CLOCK_CHIP_ID_LOW_CHIP_ID_LO.

//! @brief Get value of SATAPHY_CLOCK_CHIP_ID_LOW_CHIP_ID_LO from a register value.
#define BG_SATAPHY_CLOCK_CHIP_ID_LOW_CHIP_ID_LO(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CHIP_ID_LOW_CHIP_ID_LO) >> BP_SATAPHY_CLOCK_CHIP_ID_LOW_CHIP_ID_LO)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_FREQ_STAT - Frequency Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_FREQ_STAT - Frequency Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x000E  Reset value: 16'b xxxx xxxx xxxx xxxx (depends on inputs)  This register
 * indicates the status of frequency control inputs.
 */
typedef union _hw_sataphy_clock_freq_stat
{
    reg16_t U;
    struct _hw_sataphy_clock_freq_stat_bitfields
    {
        unsigned short PROP_CTL : 3; //!< [2:0] Proportional charge pump control
        unsigned short INT_CTL : 3; //!< [5:3] Integral charge pump control
        unsigned short NCY5 : 2; //!< [7:6] Divide-by-5 control
        unsigned short NCY : 5; //!< [12:8] Divide-by-4 cycle control
        unsigned short PRESCALE : 2; //!< [14:13] Prescaler control
        unsigned short RESERVED0 : 1; //!< [15] Always reads as 1
    } B;
} hw_sataphy_clock_freq_stat_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_FREQ_STAT register
 */
#define HW_SATAPHY_CLOCK_FREQ_STAT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0xe)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_FREQ_STAT           (*(volatile hw_sataphy_clock_freq_stat_t *) HW_SATAPHY_CLOCK_FREQ_STAT_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_FREQ_STAT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_FREQ_STAT, field PROP_CTL[2:0] (RO)
 *
 * Proportional charge pump control
 */

#define BP_SATAPHY_CLOCK_FREQ_STAT_PROP_CTL      (0)      //!< Bit position for SATAPHY_CLOCK_FREQ_STAT_PROP_CTL.
#define BM_SATAPHY_CLOCK_FREQ_STAT_PROP_CTL      (0x00000007)  //!< Bit mask for SATAPHY_CLOCK_FREQ_STAT_PROP_CTL.

//! @brief Get value of SATAPHY_CLOCK_FREQ_STAT_PROP_CTL from a register value.
#define BG_SATAPHY_CLOCK_FREQ_STAT_PROP_CTL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_FREQ_STAT_PROP_CTL) >> BP_SATAPHY_CLOCK_FREQ_STAT_PROP_CTL)

/* --- Register HW_SATAPHY_CLOCK_FREQ_STAT, field INT_CTL[5:3] (RO)
 *
 * Integral charge pump control
 */

#define BP_SATAPHY_CLOCK_FREQ_STAT_INT_CTL      (3)      //!< Bit position for SATAPHY_CLOCK_FREQ_STAT_INT_CTL.
#define BM_SATAPHY_CLOCK_FREQ_STAT_INT_CTL      (0x00000038)  //!< Bit mask for SATAPHY_CLOCK_FREQ_STAT_INT_CTL.

//! @brief Get value of SATAPHY_CLOCK_FREQ_STAT_INT_CTL from a register value.
#define BG_SATAPHY_CLOCK_FREQ_STAT_INT_CTL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_FREQ_STAT_INT_CTL) >> BP_SATAPHY_CLOCK_FREQ_STAT_INT_CTL)

/* --- Register HW_SATAPHY_CLOCK_FREQ_STAT, field NCY5[7:6] (RO)
 *
 * Divide-by-5 control
 */

#define BP_SATAPHY_CLOCK_FREQ_STAT_NCY5      (6)      //!< Bit position for SATAPHY_CLOCK_FREQ_STAT_NCY5.
#define BM_SATAPHY_CLOCK_FREQ_STAT_NCY5      (0x000000c0)  //!< Bit mask for SATAPHY_CLOCK_FREQ_STAT_NCY5.

//! @brief Get value of SATAPHY_CLOCK_FREQ_STAT_NCY5 from a register value.
#define BG_SATAPHY_CLOCK_FREQ_STAT_NCY5(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_FREQ_STAT_NCY5) >> BP_SATAPHY_CLOCK_FREQ_STAT_NCY5)

/* --- Register HW_SATAPHY_CLOCK_FREQ_STAT, field NCY[12:8] (RO)
 *
 * Divide-by-4 cycle control
 */

#define BP_SATAPHY_CLOCK_FREQ_STAT_NCY      (8)      //!< Bit position for SATAPHY_CLOCK_FREQ_STAT_NCY.
#define BM_SATAPHY_CLOCK_FREQ_STAT_NCY      (0x00001f00)  //!< Bit mask for SATAPHY_CLOCK_FREQ_STAT_NCY.

//! @brief Get value of SATAPHY_CLOCK_FREQ_STAT_NCY from a register value.
#define BG_SATAPHY_CLOCK_FREQ_STAT_NCY(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_FREQ_STAT_NCY) >> BP_SATAPHY_CLOCK_FREQ_STAT_NCY)

/* --- Register HW_SATAPHY_CLOCK_FREQ_STAT, field PRESCALE[14:13] (RO)
 *
 * Prescaler control
 */

#define BP_SATAPHY_CLOCK_FREQ_STAT_PRESCALE      (13)      //!< Bit position for SATAPHY_CLOCK_FREQ_STAT_PRESCALE.
#define BM_SATAPHY_CLOCK_FREQ_STAT_PRESCALE      (0x00006000)  //!< Bit mask for SATAPHY_CLOCK_FREQ_STAT_PRESCALE.

//! @brief Get value of SATAPHY_CLOCK_FREQ_STAT_PRESCALE from a register value.
#define BG_SATAPHY_CLOCK_FREQ_STAT_PRESCALE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_FREQ_STAT_PRESCALE) >> BP_SATAPHY_CLOCK_FREQ_STAT_PRESCALE)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_CTL_STAT - Control Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CTL_STAT - Control Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x000F  Reset value: 16'b xxxx xxxx xxxx xxxx (depends on inputs)  This register
 * indicates the status of various control inputs.
 */
typedef union _hw_sataphy_clock_ctl_stat
{
    reg16_t U;
    struct _hw_sataphy_clock_ctl_stat_bitfields
    {
        unsigned short USE_REFCLK_ALT : 1; //!< [0] Alternate refclk is used
        unsigned short MPLL_CLK_OFF : 1; //!< [1] Reference clock is off
        unsigned short MPLL_PWRON : 1; //!< [2] MPLL power-on control
        unsigned short MPLL_SS_EN : 1; //!< [3] Spread spectrum enable
        unsigned short CKO_ALIVE_CON : 2; //!< [5:4] cko_alive MUX control
        unsigned short CKO_WORD_CON : 3; //!< [8:6] cko_word MUX control
        unsigned short RESERVED0 : 1; //!< [9] Reserved
        unsigned short RTUNE_DO_TUNE : 1; //!< [10] Manual resistor tune control
        unsigned short WIDE_XFACE : 1; //!< [11] Wide interface control
        unsigned short VPH_IS_3P3 : 1; //!< [12] High voltage supply is 3.3 V
        unsigned short VP_IS_1P2 : 1; //!< [13] Low voltage supply is 1.2 V
        unsigned short FAST_TECH : 1; //!< [14] Technology is fast
        unsigned short RESERVED1 : 1; //!< [15] Reserved
    } B;
} hw_sataphy_clock_ctl_stat_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CTL_STAT register
 */
#define HW_SATAPHY_CLOCK_CTL_STAT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0xf)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CTL_STAT           (*(volatile hw_sataphy_clock_ctl_stat_t *) HW_SATAPHY_CLOCK_CTL_STAT_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CTL_STAT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field USE_REFCLK_ALT[0] (RO)
 *
 * Alternate refclk is used
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_USE_REFCLK_ALT      (0)      //!< Bit position for SATAPHY_CLOCK_CTL_STAT_USE_REFCLK_ALT.
#define BM_SATAPHY_CLOCK_CTL_STAT_USE_REFCLK_ALT      (0x00000001)  //!< Bit mask for SATAPHY_CLOCK_CTL_STAT_USE_REFCLK_ALT.

//! @brief Get value of SATAPHY_CLOCK_CTL_STAT_USE_REFCLK_ALT from a register value.
#define BG_SATAPHY_CLOCK_CTL_STAT_USE_REFCLK_ALT(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_STAT_USE_REFCLK_ALT) >> BP_SATAPHY_CLOCK_CTL_STAT_USE_REFCLK_ALT)

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field MPLL_CLK_OFF[1] (RO)
 *
 * Reference clock is off
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_MPLL_CLK_OFF      (1)      //!< Bit position for SATAPHY_CLOCK_CTL_STAT_MPLL_CLK_OFF.
#define BM_SATAPHY_CLOCK_CTL_STAT_MPLL_CLK_OFF      (0x00000002)  //!< Bit mask for SATAPHY_CLOCK_CTL_STAT_MPLL_CLK_OFF.

//! @brief Get value of SATAPHY_CLOCK_CTL_STAT_MPLL_CLK_OFF from a register value.
#define BG_SATAPHY_CLOCK_CTL_STAT_MPLL_CLK_OFF(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_STAT_MPLL_CLK_OFF) >> BP_SATAPHY_CLOCK_CTL_STAT_MPLL_CLK_OFF)

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field MPLL_PWRON[2] (RO)
 *
 * MPLL power-on control
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_MPLL_PWRON      (2)      //!< Bit position for SATAPHY_CLOCK_CTL_STAT_MPLL_PWRON.
#define BM_SATAPHY_CLOCK_CTL_STAT_MPLL_PWRON      (0x00000004)  //!< Bit mask for SATAPHY_CLOCK_CTL_STAT_MPLL_PWRON.

//! @brief Get value of SATAPHY_CLOCK_CTL_STAT_MPLL_PWRON from a register value.
#define BG_SATAPHY_CLOCK_CTL_STAT_MPLL_PWRON(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_STAT_MPLL_PWRON) >> BP_SATAPHY_CLOCK_CTL_STAT_MPLL_PWRON)

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field MPLL_SS_EN[3] (RO)
 *
 * Spread spectrum enable
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_MPLL_SS_EN      (3)      //!< Bit position for SATAPHY_CLOCK_CTL_STAT_MPLL_SS_EN.
#define BM_SATAPHY_CLOCK_CTL_STAT_MPLL_SS_EN      (0x00000008)  //!< Bit mask for SATAPHY_CLOCK_CTL_STAT_MPLL_SS_EN.

//! @brief Get value of SATAPHY_CLOCK_CTL_STAT_MPLL_SS_EN from a register value.
#define BG_SATAPHY_CLOCK_CTL_STAT_MPLL_SS_EN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_STAT_MPLL_SS_EN) >> BP_SATAPHY_CLOCK_CTL_STAT_MPLL_SS_EN)

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field CKO_ALIVE_CON[5:4] (RO)
 *
 * cko_alive MUX control
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_CKO_ALIVE_CON      (4)      //!< Bit position for SATAPHY_CLOCK_CTL_STAT_CKO_ALIVE_CON.
#define BM_SATAPHY_CLOCK_CTL_STAT_CKO_ALIVE_CON      (0x00000030)  //!< Bit mask for SATAPHY_CLOCK_CTL_STAT_CKO_ALIVE_CON.

//! @brief Get value of SATAPHY_CLOCK_CTL_STAT_CKO_ALIVE_CON from a register value.
#define BG_SATAPHY_CLOCK_CTL_STAT_CKO_ALIVE_CON(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_STAT_CKO_ALIVE_CON) >> BP_SATAPHY_CLOCK_CTL_STAT_CKO_ALIVE_CON)

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field CKO_WORD_CON[8:6] (RO)
 *
 * cko_word MUX control
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_CKO_WORD_CON      (6)      //!< Bit position for SATAPHY_CLOCK_CTL_STAT_CKO_WORD_CON.
#define BM_SATAPHY_CLOCK_CTL_STAT_CKO_WORD_CON      (0x000001c0)  //!< Bit mask for SATAPHY_CLOCK_CTL_STAT_CKO_WORD_CON.

//! @brief Get value of SATAPHY_CLOCK_CTL_STAT_CKO_WORD_CON from a register value.
#define BG_SATAPHY_CLOCK_CTL_STAT_CKO_WORD_CON(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_STAT_CKO_WORD_CON) >> BP_SATAPHY_CLOCK_CTL_STAT_CKO_WORD_CON)

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field RTUNE_DO_TUNE[10] (RO)
 *
 * Manual resistor tune control
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_RTUNE_DO_TUNE      (10)      //!< Bit position for SATAPHY_CLOCK_CTL_STAT_RTUNE_DO_TUNE.
#define BM_SATAPHY_CLOCK_CTL_STAT_RTUNE_DO_TUNE      (0x00000400)  //!< Bit mask for SATAPHY_CLOCK_CTL_STAT_RTUNE_DO_TUNE.

//! @brief Get value of SATAPHY_CLOCK_CTL_STAT_RTUNE_DO_TUNE from a register value.
#define BG_SATAPHY_CLOCK_CTL_STAT_RTUNE_DO_TUNE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_STAT_RTUNE_DO_TUNE) >> BP_SATAPHY_CLOCK_CTL_STAT_RTUNE_DO_TUNE)

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field WIDE_XFACE[11] (RO)
 *
 * Wide interface control
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_WIDE_XFACE      (11)      //!< Bit position for SATAPHY_CLOCK_CTL_STAT_WIDE_XFACE.
#define BM_SATAPHY_CLOCK_CTL_STAT_WIDE_XFACE      (0x00000800)  //!< Bit mask for SATAPHY_CLOCK_CTL_STAT_WIDE_XFACE.

//! @brief Get value of SATAPHY_CLOCK_CTL_STAT_WIDE_XFACE from a register value.
#define BG_SATAPHY_CLOCK_CTL_STAT_WIDE_XFACE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_STAT_WIDE_XFACE) >> BP_SATAPHY_CLOCK_CTL_STAT_WIDE_XFACE)

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field VPH_IS_3P3[12] (RO)
 *
 * High voltage supply is 3.3 V
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_VPH_IS_3P3      (12)      //!< Bit position for SATAPHY_CLOCK_CTL_STAT_VPH_IS_3P3.
#define BM_SATAPHY_CLOCK_CTL_STAT_VPH_IS_3P3      (0x00001000)  //!< Bit mask for SATAPHY_CLOCK_CTL_STAT_VPH_IS_3P3.

//! @brief Get value of SATAPHY_CLOCK_CTL_STAT_VPH_IS_3P3 from a register value.
#define BG_SATAPHY_CLOCK_CTL_STAT_VPH_IS_3P3(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_STAT_VPH_IS_3P3) >> BP_SATAPHY_CLOCK_CTL_STAT_VPH_IS_3P3)

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field VP_IS_1P2[13] (RO)
 *
 * Low voltage supply is 1.2 V
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_VP_IS_1P2      (13)      //!< Bit position for SATAPHY_CLOCK_CTL_STAT_VP_IS_1P2.
#define BM_SATAPHY_CLOCK_CTL_STAT_VP_IS_1P2      (0x00002000)  //!< Bit mask for SATAPHY_CLOCK_CTL_STAT_VP_IS_1P2.

//! @brief Get value of SATAPHY_CLOCK_CTL_STAT_VP_IS_1P2 from a register value.
#define BG_SATAPHY_CLOCK_CTL_STAT_VP_IS_1P2(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_STAT_VP_IS_1P2) >> BP_SATAPHY_CLOCK_CTL_STAT_VP_IS_1P2)

/* --- Register HW_SATAPHY_CLOCK_CTL_STAT, field FAST_TECH[14] (RO)
 *
 * Technology is fast
 */

#define BP_SATAPHY_CLOCK_CTL_STAT_FAST_TECH      (14)      //!< Bit position for SATAPHY_CLOCK_CTL_STAT_FAST_TECH.
#define BM_SATAPHY_CLOCK_CTL_STAT_FAST_TECH      (0x00004000)  //!< Bit mask for SATAPHY_CLOCK_CTL_STAT_FAST_TECH.

//! @brief Get value of SATAPHY_CLOCK_CTL_STAT_FAST_TECH from a register value.
#define BG_SATAPHY_CLOCK_CTL_STAT_FAST_TECH(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_STAT_FAST_TECH) >> BP_SATAPHY_CLOCK_CTL_STAT_FAST_TECH)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_LVL_STAT - Level Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_LVL_STAT - Level Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * Reset value: 16'b xxxx xxxx xxxx xxxx (depends on inputs)  This register indicates the status of
 * level control inputs.
 */
typedef union _hw_sataphy_clock_lvl_stat
{
    reg16_t U;
    struct _hw_sataphy_clock_lvl_stat_bitfields
    {
        unsigned short ACJT_LVL : 5; //!< [4:0] ACJTAG comparator level
        unsigned short LOS_LVL : 5; //!< [9:5] Loss of Signal Detector level
        unsigned short TX_LVL : 5; //!< [14:10] Transmit level
        unsigned short RESERVED0 : 1; //!< [15] Reserved
    } B;
} hw_sataphy_clock_lvl_stat_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_LVL_STAT register
 */
#define HW_SATAPHY_CLOCK_LVL_STAT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_LVL_STAT           (*(volatile hw_sataphy_clock_lvl_stat_t *) HW_SATAPHY_CLOCK_LVL_STAT_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_LVL_STAT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_LVL_STAT, field ACJT_LVL[4:0] (RO)
 *
 * ACJTAG comparator level
 */

#define BP_SATAPHY_CLOCK_LVL_STAT_ACJT_LVL      (0)      //!< Bit position for SATAPHY_CLOCK_LVL_STAT_ACJT_LVL.
#define BM_SATAPHY_CLOCK_LVL_STAT_ACJT_LVL      (0x0000001f)  //!< Bit mask for SATAPHY_CLOCK_LVL_STAT_ACJT_LVL.

//! @brief Get value of SATAPHY_CLOCK_LVL_STAT_ACJT_LVL from a register value.
#define BG_SATAPHY_CLOCK_LVL_STAT_ACJT_LVL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_LVL_STAT_ACJT_LVL) >> BP_SATAPHY_CLOCK_LVL_STAT_ACJT_LVL)

/* --- Register HW_SATAPHY_CLOCK_LVL_STAT, field LOS_LVL[9:5] (RO)
 *
 * Loss of Signal Detector level
 */

#define BP_SATAPHY_CLOCK_LVL_STAT_LOS_LVL      (5)      //!< Bit position for SATAPHY_CLOCK_LVL_STAT_LOS_LVL.
#define BM_SATAPHY_CLOCK_LVL_STAT_LOS_LVL      (0x000003e0)  //!< Bit mask for SATAPHY_CLOCK_LVL_STAT_LOS_LVL.

//! @brief Get value of SATAPHY_CLOCK_LVL_STAT_LOS_LVL from a register value.
#define BG_SATAPHY_CLOCK_LVL_STAT_LOS_LVL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_LVL_STAT_LOS_LVL) >> BP_SATAPHY_CLOCK_LVL_STAT_LOS_LVL)

/* --- Register HW_SATAPHY_CLOCK_LVL_STAT, field TX_LVL[14:10] (RO)
 *
 * Transmit level
 */

#define BP_SATAPHY_CLOCK_LVL_STAT_TX_LVL      (10)      //!< Bit position for SATAPHY_CLOCK_LVL_STAT_TX_LVL.
#define BM_SATAPHY_CLOCK_LVL_STAT_TX_LVL      (0x00007c00)  //!< Bit mask for SATAPHY_CLOCK_LVL_STAT_TX_LVL.

//! @brief Get value of SATAPHY_CLOCK_LVL_STAT_TX_LVL from a register value.
#define BG_SATAPHY_CLOCK_LVL_STAT_TX_LVL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_LVL_STAT_TX_LVL) >> BP_SATAPHY_CLOCK_LVL_STAT_TX_LVL)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_CREG_STAT - Creg Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CREG_STAT - Creg Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x0011  Reset value: 16'b xxxx xxxx xxxx xxxx (depends on inputs)  This register
 * indicates the status of creg control I/O.
 */
typedef union _hw_sataphy_clock_creg_stat
{
    reg16_t U;
    struct _hw_sataphy_clock_creg_stat_bitfields
    {
        unsigned short CR_READ : 1; //!< [0] Read request
        unsigned short CR_WRITE : 1; //!< [1] Write request
        unsigned short CR_CAP_DATA : 1; //!< [2] Captures data request
        unsigned short CR_CAP_ADDR : 1; //!< [3] Captures address request
        unsigned short RESERVED0 : 1; //!< [4] Reserved
        unsigned short CR_ACK : 1; //!< [5] Creg request acknowledgement
        unsigned short POWER_GOOD : 1; //!< [6] Power good output
        unsigned short OP_DONE : 1; //!< [7] Operation is complete output
        unsigned short RESERVED1 : 8; //!< [15:8] Reserved
    } B;
} hw_sataphy_clock_creg_stat_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CREG_STAT register
 */
#define HW_SATAPHY_CLOCK_CREG_STAT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x11)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CREG_STAT           (*(volatile hw_sataphy_clock_creg_stat_t *) HW_SATAPHY_CLOCK_CREG_STAT_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CREG_STAT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CREG_STAT, field CR_READ[0] (RO)
 *
 * Read request
 */

#define BP_SATAPHY_CLOCK_CREG_STAT_CR_READ      (0)      //!< Bit position for SATAPHY_CLOCK_CREG_STAT_CR_READ.
#define BM_SATAPHY_CLOCK_CREG_STAT_CR_READ      (0x00000001)  //!< Bit mask for SATAPHY_CLOCK_CREG_STAT_CR_READ.

//! @brief Get value of SATAPHY_CLOCK_CREG_STAT_CR_READ from a register value.
#define BG_SATAPHY_CLOCK_CREG_STAT_CR_READ(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CREG_STAT_CR_READ) >> BP_SATAPHY_CLOCK_CREG_STAT_CR_READ)

/* --- Register HW_SATAPHY_CLOCK_CREG_STAT, field CR_WRITE[1] (RO)
 *
 * Write request
 */

#define BP_SATAPHY_CLOCK_CREG_STAT_CR_WRITE      (1)      //!< Bit position for SATAPHY_CLOCK_CREG_STAT_CR_WRITE.
#define BM_SATAPHY_CLOCK_CREG_STAT_CR_WRITE      (0x00000002)  //!< Bit mask for SATAPHY_CLOCK_CREG_STAT_CR_WRITE.

//! @brief Get value of SATAPHY_CLOCK_CREG_STAT_CR_WRITE from a register value.
#define BG_SATAPHY_CLOCK_CREG_STAT_CR_WRITE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CREG_STAT_CR_WRITE) >> BP_SATAPHY_CLOCK_CREG_STAT_CR_WRITE)

/* --- Register HW_SATAPHY_CLOCK_CREG_STAT, field CR_CAP_DATA[2] (RO)
 *
 * Captures data request
 */

#define BP_SATAPHY_CLOCK_CREG_STAT_CR_CAP_DATA      (2)      //!< Bit position for SATAPHY_CLOCK_CREG_STAT_CR_CAP_DATA.
#define BM_SATAPHY_CLOCK_CREG_STAT_CR_CAP_DATA      (0x00000004)  //!< Bit mask for SATAPHY_CLOCK_CREG_STAT_CR_CAP_DATA.

//! @brief Get value of SATAPHY_CLOCK_CREG_STAT_CR_CAP_DATA from a register value.
#define BG_SATAPHY_CLOCK_CREG_STAT_CR_CAP_DATA(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CREG_STAT_CR_CAP_DATA) >> BP_SATAPHY_CLOCK_CREG_STAT_CR_CAP_DATA)

/* --- Register HW_SATAPHY_CLOCK_CREG_STAT, field CR_CAP_ADDR[3] (RO)
 *
 * Captures address request
 */

#define BP_SATAPHY_CLOCK_CREG_STAT_CR_CAP_ADDR      (3)      //!< Bit position for SATAPHY_CLOCK_CREG_STAT_CR_CAP_ADDR.
#define BM_SATAPHY_CLOCK_CREG_STAT_CR_CAP_ADDR      (0x00000008)  //!< Bit mask for SATAPHY_CLOCK_CREG_STAT_CR_CAP_ADDR.

//! @brief Get value of SATAPHY_CLOCK_CREG_STAT_CR_CAP_ADDR from a register value.
#define BG_SATAPHY_CLOCK_CREG_STAT_CR_CAP_ADDR(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CREG_STAT_CR_CAP_ADDR) >> BP_SATAPHY_CLOCK_CREG_STAT_CR_CAP_ADDR)

/* --- Register HW_SATAPHY_CLOCK_CREG_STAT, field CR_ACK[5] (RO)
 *
 * Creg request acknowledgement
 */

#define BP_SATAPHY_CLOCK_CREG_STAT_CR_ACK      (5)      //!< Bit position for SATAPHY_CLOCK_CREG_STAT_CR_ACK.
#define BM_SATAPHY_CLOCK_CREG_STAT_CR_ACK      (0x00000020)  //!< Bit mask for SATAPHY_CLOCK_CREG_STAT_CR_ACK.

//! @brief Get value of SATAPHY_CLOCK_CREG_STAT_CR_ACK from a register value.
#define BG_SATAPHY_CLOCK_CREG_STAT_CR_ACK(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CREG_STAT_CR_ACK) >> BP_SATAPHY_CLOCK_CREG_STAT_CR_ACK)

/* --- Register HW_SATAPHY_CLOCK_CREG_STAT, field POWER_GOOD[6] (RO)
 *
 * Power good output
 */

#define BP_SATAPHY_CLOCK_CREG_STAT_POWER_GOOD      (6)      //!< Bit position for SATAPHY_CLOCK_CREG_STAT_POWER_GOOD.
#define BM_SATAPHY_CLOCK_CREG_STAT_POWER_GOOD      (0x00000040)  //!< Bit mask for SATAPHY_CLOCK_CREG_STAT_POWER_GOOD.

//! @brief Get value of SATAPHY_CLOCK_CREG_STAT_POWER_GOOD from a register value.
#define BG_SATAPHY_CLOCK_CREG_STAT_POWER_GOOD(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CREG_STAT_POWER_GOOD) >> BP_SATAPHY_CLOCK_CREG_STAT_POWER_GOOD)

/* --- Register HW_SATAPHY_CLOCK_CREG_STAT, field OP_DONE[7] (RO)
 *
 * Operation is complete output
 */

#define BP_SATAPHY_CLOCK_CREG_STAT_OP_DONE      (7)      //!< Bit position for SATAPHY_CLOCK_CREG_STAT_OP_DONE.
#define BM_SATAPHY_CLOCK_CREG_STAT_OP_DONE      (0x00000080)  //!< Bit mask for SATAPHY_CLOCK_CREG_STAT_OP_DONE.

//! @brief Get value of SATAPHY_CLOCK_CREG_STAT_OP_DONE from a register value.
#define BG_SATAPHY_CLOCK_CREG_STAT_OP_DONE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CREG_STAT_OP_DONE) >> BP_SATAPHY_CLOCK_CREG_STAT_OP_DONE)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_FREW_OVRD - Frequency Override Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_FREW_OVRD - Frequency Override Register (RW)
 *
 * Reset value: 0x00004547
 *
 * Reset value: 16'b 0100 0101 0100 0111  This register contains the override of frequency control
 * inputs.
 */
typedef union _hw_sataphy_clock_frew_ovrd
{
    reg16_t U;
    struct _hw_sataphy_clock_frew_ovrd_bitfields
    {
        unsigned short PROP_CTL : 3; //!< [2:0] Proportional charge pump control Proportional current = (n + 1) / 8 x full_scale
        unsigned short INT_CTL : 3; //!< [5:3] Integral charge pump control Integral current = (n + 1) / 8 x full_scale
        unsigned short NCY5 : 2; //!< [7:6] Divide-by-5 control MPLL Divider period = 4 x (NCY + 1) + NCY5. Valid only when NCY5 <=NCY
        unsigned short NCY : 5; //!< [12:8] Divide-by-4 cycle control MPLL Divider period = 4 x (NCY + 1) + NCY5. Valid only when NCY5 <=NCY.
        unsigned short PRESCALE : 2; //!< [14:13] Prescaler control:
        unsigned short OVRD : 1; //!< [15] Enables override of all bits in this register
    } B;
} hw_sataphy_clock_frew_ovrd_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_FREW_OVRD register
 */
#define HW_SATAPHY_CLOCK_FREW_OVRD_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x12)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_FREW_OVRD           (*(volatile hw_sataphy_clock_frew_ovrd_t *) HW_SATAPHY_CLOCK_FREW_OVRD_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_FREW_OVRD bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_FREW_OVRD, field PROP_CTL[2:0] (RW)
 *
 * Proportional charge pump control Proportional current = (n + 1) / 8 x full_scale
 */

#define BP_SATAPHY_CLOCK_FREW_OVRD_PROP_CTL      (0)      //!< Bit position for SATAPHY_CLOCK_FREW_OVRD_PROP_CTL.
#define BM_SATAPHY_CLOCK_FREW_OVRD_PROP_CTL      (0x00000007)  //!< Bit mask for SATAPHY_CLOCK_FREW_OVRD_PROP_CTL.

//! @brief Get value of SATAPHY_CLOCK_FREW_OVRD_PROP_CTL from a register value.
#define BG_SATAPHY_CLOCK_FREW_OVRD_PROP_CTL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_FREW_OVRD_PROP_CTL) >> BP_SATAPHY_CLOCK_FREW_OVRD_PROP_CTL)

//! @brief Format value for bitfield SATAPHY_CLOCK_FREW_OVRD_PROP_CTL.
#define BF_SATAPHY_CLOCK_FREW_OVRD_PROP_CTL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_FREW_OVRD_PROP_CTL) & BM_SATAPHY_CLOCK_FREW_OVRD_PROP_CTL)

/* --- Register HW_SATAPHY_CLOCK_FREW_OVRD, field INT_CTL[5:3] (RW)
 *
 * Integral charge pump control Integral current = (n + 1) / 8 x full_scale
 */

#define BP_SATAPHY_CLOCK_FREW_OVRD_INT_CTL      (3)      //!< Bit position for SATAPHY_CLOCK_FREW_OVRD_INT_CTL.
#define BM_SATAPHY_CLOCK_FREW_OVRD_INT_CTL      (0x00000038)  //!< Bit mask for SATAPHY_CLOCK_FREW_OVRD_INT_CTL.

//! @brief Get value of SATAPHY_CLOCK_FREW_OVRD_INT_CTL from a register value.
#define BG_SATAPHY_CLOCK_FREW_OVRD_INT_CTL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_FREW_OVRD_INT_CTL) >> BP_SATAPHY_CLOCK_FREW_OVRD_INT_CTL)

//! @brief Format value for bitfield SATAPHY_CLOCK_FREW_OVRD_INT_CTL.
#define BF_SATAPHY_CLOCK_FREW_OVRD_INT_CTL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_FREW_OVRD_INT_CTL) & BM_SATAPHY_CLOCK_FREW_OVRD_INT_CTL)

/* --- Register HW_SATAPHY_CLOCK_FREW_OVRD, field NCY5[7:6] (RW)
 *
 * Divide-by-5 control MPLL Divider period = 4 x (NCY + 1) + NCY5. Valid only when NCY5 <=NCY
 */

#define BP_SATAPHY_CLOCK_FREW_OVRD_NCY5      (6)      //!< Bit position for SATAPHY_CLOCK_FREW_OVRD_NCY5.
#define BM_SATAPHY_CLOCK_FREW_OVRD_NCY5      (0x000000c0)  //!< Bit mask for SATAPHY_CLOCK_FREW_OVRD_NCY5.

//! @brief Get value of SATAPHY_CLOCK_FREW_OVRD_NCY5 from a register value.
#define BG_SATAPHY_CLOCK_FREW_OVRD_NCY5(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_FREW_OVRD_NCY5) >> BP_SATAPHY_CLOCK_FREW_OVRD_NCY5)

//! @brief Format value for bitfield SATAPHY_CLOCK_FREW_OVRD_NCY5.
#define BF_SATAPHY_CLOCK_FREW_OVRD_NCY5(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_FREW_OVRD_NCY5) & BM_SATAPHY_CLOCK_FREW_OVRD_NCY5)

/* --- Register HW_SATAPHY_CLOCK_FREW_OVRD, field NCY[12:8] (RW)
 *
 * Divide-by-4 cycle control MPLL Divider period = 4 x (NCY + 1) + NCY5. Valid only when NCY5 <=NCY.
 */

#define BP_SATAPHY_CLOCK_FREW_OVRD_NCY      (8)      //!< Bit position for SATAPHY_CLOCK_FREW_OVRD_NCY.
#define BM_SATAPHY_CLOCK_FREW_OVRD_NCY      (0x00001f00)  //!< Bit mask for SATAPHY_CLOCK_FREW_OVRD_NCY.

//! @brief Get value of SATAPHY_CLOCK_FREW_OVRD_NCY from a register value.
#define BG_SATAPHY_CLOCK_FREW_OVRD_NCY(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_FREW_OVRD_NCY) >> BP_SATAPHY_CLOCK_FREW_OVRD_NCY)

//! @brief Format value for bitfield SATAPHY_CLOCK_FREW_OVRD_NCY.
#define BF_SATAPHY_CLOCK_FREW_OVRD_NCY(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_FREW_OVRD_NCY) & BM_SATAPHY_CLOCK_FREW_OVRD_NCY)

/* --- Register HW_SATAPHY_CLOCK_FREW_OVRD, field PRESCALE[14:13] (RW)
 *
 * Prescaler control:
 *
 * Values:
 * 00 - No scaling
 * 01 - Doubles refclk frequency
 * 10 - Halves refclk frequency
 * 11 - Reserved
 */

#define BP_SATAPHY_CLOCK_FREW_OVRD_PRESCALE      (13)      //!< Bit position for SATAPHY_CLOCK_FREW_OVRD_PRESCALE.
#define BM_SATAPHY_CLOCK_FREW_OVRD_PRESCALE      (0x00006000)  //!< Bit mask for SATAPHY_CLOCK_FREW_OVRD_PRESCALE.

//! @brief Get value of SATAPHY_CLOCK_FREW_OVRD_PRESCALE from a register value.
#define BG_SATAPHY_CLOCK_FREW_OVRD_PRESCALE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_FREW_OVRD_PRESCALE) >> BP_SATAPHY_CLOCK_FREW_OVRD_PRESCALE)

//! @brief Format value for bitfield SATAPHY_CLOCK_FREW_OVRD_PRESCALE.
#define BF_SATAPHY_CLOCK_FREW_OVRD_PRESCALE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_FREW_OVRD_PRESCALE) & BM_SATAPHY_CLOCK_FREW_OVRD_PRESCALE)


/* --- Register HW_SATAPHY_CLOCK_FREW_OVRD, field OVRD[15] (RW)
 *
 * Enables override of all bits in this register
 */

#define BP_SATAPHY_CLOCK_FREW_OVRD_OVRD      (15)      //!< Bit position for SATAPHY_CLOCK_FREW_OVRD_OVRD.
#define BM_SATAPHY_CLOCK_FREW_OVRD_OVRD      (0x00008000)  //!< Bit mask for SATAPHY_CLOCK_FREW_OVRD_OVRD.

//! @brief Get value of SATAPHY_CLOCK_FREW_OVRD_OVRD from a register value.
#define BG_SATAPHY_CLOCK_FREW_OVRD_OVRD(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_FREW_OVRD_OVRD) >> BP_SATAPHY_CLOCK_FREW_OVRD_OVRD)

//! @brief Format value for bitfield SATAPHY_CLOCK_FREW_OVRD_OVRD.
#define BF_SATAPHY_CLOCK_FREW_OVRD_OVRD(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_FREW_OVRD_OVRD) & BM_SATAPHY_CLOCK_FREW_OVRD_OVRD)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_CTL_OVRD - Control Override Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CTL_OVRD - Control Override Register (RW)
 *
 * Reset value: 0x00000854
 *
 * Reset value: 16'b 0000 1000 0101 0100  This register contains the override of various control
 * inputs.
 */
typedef union _hw_sataphy_clock_ctl_ovrd
{
    reg16_t U;
    struct _hw_sataphy_clock_ctl_ovrd_bitfields
    {
        unsigned short USE_REFCLK_ALT : 1; //!< [0] Uses alternate refclk
        unsigned short MPLL_CLK_OFF : 1; //!< [1] Reference clock is off
        unsigned short MPLL_PWRON : 1; //!< [2] MPLL power-on control
        unsigned short MPLL_SS_EN : 1; //!< [3] Spread spectrum enable
        unsigned short CKO_ALIVE_CON : 2; //!< [5:4] cko_alive mux control
        unsigned short CKO_WORD_CON : 3; //!< [8:6] cko_word mux control
        unsigned short OVRD_CLK : 1; //!< [9] Overrides clock controls (bits [8:0])
        unsigned short RTUNE_DO_TUNE : 1; //!< [10] Manual resistor tune control
        unsigned short WIDE_XFACE : 1; //!< [11] Wide interface control
        unsigned short VPH_IS_3P3 : 1; //!< [12] High-voltage supply is 3.3 V
        unsigned short VP_IS_1P2 : 1; //!< [13] Low-voltage supply is 1.2 V
        unsigned short FAST_TECH : 1; //!< [14] Technology is fast
        unsigned short OVRD_STATIC : 1; //!< [15] Overrides static controls (bits [14:10])
    } B;
} hw_sataphy_clock_ctl_ovrd_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CTL_OVRD register
 */
#define HW_SATAPHY_CLOCK_CTL_OVRD_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x13)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CTL_OVRD           (*(volatile hw_sataphy_clock_ctl_ovrd_t *) HW_SATAPHY_CLOCK_CTL_OVRD_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CTL_OVRD bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field USE_REFCLK_ALT[0] (RW)
 *
 * Uses alternate refclk
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_USE_REFCLK_ALT      (0)      //!< Bit position for SATAPHY_CLOCK_CTL_OVRD_USE_REFCLK_ALT.
#define BM_SATAPHY_CLOCK_CTL_OVRD_USE_REFCLK_ALT      (0x00000001)  //!< Bit mask for SATAPHY_CLOCK_CTL_OVRD_USE_REFCLK_ALT.

//! @brief Get value of SATAPHY_CLOCK_CTL_OVRD_USE_REFCLK_ALT from a register value.
#define BG_SATAPHY_CLOCK_CTL_OVRD_USE_REFCLK_ALT(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_OVRD_USE_REFCLK_ALT) >> BP_SATAPHY_CLOCK_CTL_OVRD_USE_REFCLK_ALT)

//! @brief Format value for bitfield SATAPHY_CLOCK_CTL_OVRD_USE_REFCLK_ALT.
#define BF_SATAPHY_CLOCK_CTL_OVRD_USE_REFCLK_ALT(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CTL_OVRD_USE_REFCLK_ALT) & BM_SATAPHY_CLOCK_CTL_OVRD_USE_REFCLK_ALT)

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field MPLL_CLK_OFF[1] (RW)
 *
 * Reference clock is off
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_MPLL_CLK_OFF      (1)      //!< Bit position for SATAPHY_CLOCK_CTL_OVRD_MPLL_CLK_OFF.
#define BM_SATAPHY_CLOCK_CTL_OVRD_MPLL_CLK_OFF      (0x00000002)  //!< Bit mask for SATAPHY_CLOCK_CTL_OVRD_MPLL_CLK_OFF.

//! @brief Get value of SATAPHY_CLOCK_CTL_OVRD_MPLL_CLK_OFF from a register value.
#define BG_SATAPHY_CLOCK_CTL_OVRD_MPLL_CLK_OFF(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_OVRD_MPLL_CLK_OFF) >> BP_SATAPHY_CLOCK_CTL_OVRD_MPLL_CLK_OFF)

//! @brief Format value for bitfield SATAPHY_CLOCK_CTL_OVRD_MPLL_CLK_OFF.
#define BF_SATAPHY_CLOCK_CTL_OVRD_MPLL_CLK_OFF(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CTL_OVRD_MPLL_CLK_OFF) & BM_SATAPHY_CLOCK_CTL_OVRD_MPLL_CLK_OFF)

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field MPLL_PWRON[2] (RW)
 *
 * MPLL power-on control
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_MPLL_PWRON      (2)      //!< Bit position for SATAPHY_CLOCK_CTL_OVRD_MPLL_PWRON.
#define BM_SATAPHY_CLOCK_CTL_OVRD_MPLL_PWRON      (0x00000004)  //!< Bit mask for SATAPHY_CLOCK_CTL_OVRD_MPLL_PWRON.

//! @brief Get value of SATAPHY_CLOCK_CTL_OVRD_MPLL_PWRON from a register value.
#define BG_SATAPHY_CLOCK_CTL_OVRD_MPLL_PWRON(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_OVRD_MPLL_PWRON) >> BP_SATAPHY_CLOCK_CTL_OVRD_MPLL_PWRON)

//! @brief Format value for bitfield SATAPHY_CLOCK_CTL_OVRD_MPLL_PWRON.
#define BF_SATAPHY_CLOCK_CTL_OVRD_MPLL_PWRON(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CTL_OVRD_MPLL_PWRON) & BM_SATAPHY_CLOCK_CTL_OVRD_MPLL_PWRON)

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field MPLL_SS_EN[3] (RW)
 *
 * Spread spectrum enable
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_MPLL_SS_EN      (3)      //!< Bit position for SATAPHY_CLOCK_CTL_OVRD_MPLL_SS_EN.
#define BM_SATAPHY_CLOCK_CTL_OVRD_MPLL_SS_EN      (0x00000008)  //!< Bit mask for SATAPHY_CLOCK_CTL_OVRD_MPLL_SS_EN.

//! @brief Get value of SATAPHY_CLOCK_CTL_OVRD_MPLL_SS_EN from a register value.
#define BG_SATAPHY_CLOCK_CTL_OVRD_MPLL_SS_EN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_OVRD_MPLL_SS_EN) >> BP_SATAPHY_CLOCK_CTL_OVRD_MPLL_SS_EN)

//! @brief Format value for bitfield SATAPHY_CLOCK_CTL_OVRD_MPLL_SS_EN.
#define BF_SATAPHY_CLOCK_CTL_OVRD_MPLL_SS_EN(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CTL_OVRD_MPLL_SS_EN) & BM_SATAPHY_CLOCK_CTL_OVRD_MPLL_SS_EN)

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field CKO_ALIVE_CON[5:4] (RW)
 *
 * cko_alive mux control
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_CKO_ALIVE_CON      (4)      //!< Bit position for SATAPHY_CLOCK_CTL_OVRD_CKO_ALIVE_CON.
#define BM_SATAPHY_CLOCK_CTL_OVRD_CKO_ALIVE_CON      (0x00000030)  //!< Bit mask for SATAPHY_CLOCK_CTL_OVRD_CKO_ALIVE_CON.

//! @brief Get value of SATAPHY_CLOCK_CTL_OVRD_CKO_ALIVE_CON from a register value.
#define BG_SATAPHY_CLOCK_CTL_OVRD_CKO_ALIVE_CON(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_OVRD_CKO_ALIVE_CON) >> BP_SATAPHY_CLOCK_CTL_OVRD_CKO_ALIVE_CON)

//! @brief Format value for bitfield SATAPHY_CLOCK_CTL_OVRD_CKO_ALIVE_CON.
#define BF_SATAPHY_CLOCK_CTL_OVRD_CKO_ALIVE_CON(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CTL_OVRD_CKO_ALIVE_CON) & BM_SATAPHY_CLOCK_CTL_OVRD_CKO_ALIVE_CON)

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field CKO_WORD_CON[8:6] (RW)
 *
 * cko_word mux control
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_CKO_WORD_CON      (6)      //!< Bit position for SATAPHY_CLOCK_CTL_OVRD_CKO_WORD_CON.
#define BM_SATAPHY_CLOCK_CTL_OVRD_CKO_WORD_CON      (0x000001c0)  //!< Bit mask for SATAPHY_CLOCK_CTL_OVRD_CKO_WORD_CON.

//! @brief Get value of SATAPHY_CLOCK_CTL_OVRD_CKO_WORD_CON from a register value.
#define BG_SATAPHY_CLOCK_CTL_OVRD_CKO_WORD_CON(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_OVRD_CKO_WORD_CON) >> BP_SATAPHY_CLOCK_CTL_OVRD_CKO_WORD_CON)

//! @brief Format value for bitfield SATAPHY_CLOCK_CTL_OVRD_CKO_WORD_CON.
#define BF_SATAPHY_CLOCK_CTL_OVRD_CKO_WORD_CON(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CTL_OVRD_CKO_WORD_CON) & BM_SATAPHY_CLOCK_CTL_OVRD_CKO_WORD_CON)

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field OVRD_CLK[9] (RW)
 *
 * Overrides clock controls (bits [8:0])
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_OVRD_CLK      (9)      //!< Bit position for SATAPHY_CLOCK_CTL_OVRD_OVRD_CLK.
#define BM_SATAPHY_CLOCK_CTL_OVRD_OVRD_CLK      (0x00000200)  //!< Bit mask for SATAPHY_CLOCK_CTL_OVRD_OVRD_CLK.

//! @brief Get value of SATAPHY_CLOCK_CTL_OVRD_OVRD_CLK from a register value.
#define BG_SATAPHY_CLOCK_CTL_OVRD_OVRD_CLK(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_OVRD_OVRD_CLK) >> BP_SATAPHY_CLOCK_CTL_OVRD_OVRD_CLK)

//! @brief Format value for bitfield SATAPHY_CLOCK_CTL_OVRD_OVRD_CLK.
#define BF_SATAPHY_CLOCK_CTL_OVRD_OVRD_CLK(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CTL_OVRD_OVRD_CLK) & BM_SATAPHY_CLOCK_CTL_OVRD_OVRD_CLK)

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field RTUNE_DO_TUNE[10] (RW)
 *
 * Manual resistor tune control
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_RTUNE_DO_TUNE      (10)      //!< Bit position for SATAPHY_CLOCK_CTL_OVRD_RTUNE_DO_TUNE.
#define BM_SATAPHY_CLOCK_CTL_OVRD_RTUNE_DO_TUNE      (0x00000400)  //!< Bit mask for SATAPHY_CLOCK_CTL_OVRD_RTUNE_DO_TUNE.

//! @brief Get value of SATAPHY_CLOCK_CTL_OVRD_RTUNE_DO_TUNE from a register value.
#define BG_SATAPHY_CLOCK_CTL_OVRD_RTUNE_DO_TUNE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_OVRD_RTUNE_DO_TUNE) >> BP_SATAPHY_CLOCK_CTL_OVRD_RTUNE_DO_TUNE)

//! @brief Format value for bitfield SATAPHY_CLOCK_CTL_OVRD_RTUNE_DO_TUNE.
#define BF_SATAPHY_CLOCK_CTL_OVRD_RTUNE_DO_TUNE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CTL_OVRD_RTUNE_DO_TUNE) & BM_SATAPHY_CLOCK_CTL_OVRD_RTUNE_DO_TUNE)

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field WIDE_XFACE[11] (RW)
 *
 * Wide interface control
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_WIDE_XFACE      (11)      //!< Bit position for SATAPHY_CLOCK_CTL_OVRD_WIDE_XFACE.
#define BM_SATAPHY_CLOCK_CTL_OVRD_WIDE_XFACE      (0x00000800)  //!< Bit mask for SATAPHY_CLOCK_CTL_OVRD_WIDE_XFACE.

//! @brief Get value of SATAPHY_CLOCK_CTL_OVRD_WIDE_XFACE from a register value.
#define BG_SATAPHY_CLOCK_CTL_OVRD_WIDE_XFACE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_OVRD_WIDE_XFACE) >> BP_SATAPHY_CLOCK_CTL_OVRD_WIDE_XFACE)

//! @brief Format value for bitfield SATAPHY_CLOCK_CTL_OVRD_WIDE_XFACE.
#define BF_SATAPHY_CLOCK_CTL_OVRD_WIDE_XFACE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CTL_OVRD_WIDE_XFACE) & BM_SATAPHY_CLOCK_CTL_OVRD_WIDE_XFACE)

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field VPH_IS_3P3[12] (RW)
 *
 * High-voltage supply is 3.3 V
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_VPH_IS_3P3      (12)      //!< Bit position for SATAPHY_CLOCK_CTL_OVRD_VPH_IS_3P3.
#define BM_SATAPHY_CLOCK_CTL_OVRD_VPH_IS_3P3      (0x00001000)  //!< Bit mask for SATAPHY_CLOCK_CTL_OVRD_VPH_IS_3P3.

//! @brief Get value of SATAPHY_CLOCK_CTL_OVRD_VPH_IS_3P3 from a register value.
#define BG_SATAPHY_CLOCK_CTL_OVRD_VPH_IS_3P3(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_OVRD_VPH_IS_3P3) >> BP_SATAPHY_CLOCK_CTL_OVRD_VPH_IS_3P3)

//! @brief Format value for bitfield SATAPHY_CLOCK_CTL_OVRD_VPH_IS_3P3.
#define BF_SATAPHY_CLOCK_CTL_OVRD_VPH_IS_3P3(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CTL_OVRD_VPH_IS_3P3) & BM_SATAPHY_CLOCK_CTL_OVRD_VPH_IS_3P3)

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field VP_IS_1P2[13] (RW)
 *
 * Low-voltage supply is 1.2 V
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_VP_IS_1P2      (13)      //!< Bit position for SATAPHY_CLOCK_CTL_OVRD_VP_IS_1P2.
#define BM_SATAPHY_CLOCK_CTL_OVRD_VP_IS_1P2      (0x00002000)  //!< Bit mask for SATAPHY_CLOCK_CTL_OVRD_VP_IS_1P2.

//! @brief Get value of SATAPHY_CLOCK_CTL_OVRD_VP_IS_1P2 from a register value.
#define BG_SATAPHY_CLOCK_CTL_OVRD_VP_IS_1P2(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_OVRD_VP_IS_1P2) >> BP_SATAPHY_CLOCK_CTL_OVRD_VP_IS_1P2)

//! @brief Format value for bitfield SATAPHY_CLOCK_CTL_OVRD_VP_IS_1P2.
#define BF_SATAPHY_CLOCK_CTL_OVRD_VP_IS_1P2(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CTL_OVRD_VP_IS_1P2) & BM_SATAPHY_CLOCK_CTL_OVRD_VP_IS_1P2)

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field FAST_TECH[14] (RW)
 *
 * Technology is fast
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_FAST_TECH      (14)      //!< Bit position for SATAPHY_CLOCK_CTL_OVRD_FAST_TECH.
#define BM_SATAPHY_CLOCK_CTL_OVRD_FAST_TECH      (0x00004000)  //!< Bit mask for SATAPHY_CLOCK_CTL_OVRD_FAST_TECH.

//! @brief Get value of SATAPHY_CLOCK_CTL_OVRD_FAST_TECH from a register value.
#define BG_SATAPHY_CLOCK_CTL_OVRD_FAST_TECH(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_OVRD_FAST_TECH) >> BP_SATAPHY_CLOCK_CTL_OVRD_FAST_TECH)

//! @brief Format value for bitfield SATAPHY_CLOCK_CTL_OVRD_FAST_TECH.
#define BF_SATAPHY_CLOCK_CTL_OVRD_FAST_TECH(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CTL_OVRD_FAST_TECH) & BM_SATAPHY_CLOCK_CTL_OVRD_FAST_TECH)

/* --- Register HW_SATAPHY_CLOCK_CTL_OVRD, field OVRD_STATIC[15] (RW)
 *
 * Overrides static controls (bits [14:10])
 */

#define BP_SATAPHY_CLOCK_CTL_OVRD_OVRD_STATIC      (15)      //!< Bit position for SATAPHY_CLOCK_CTL_OVRD_OVRD_STATIC.
#define BM_SATAPHY_CLOCK_CTL_OVRD_OVRD_STATIC      (0x00008000)  //!< Bit mask for SATAPHY_CLOCK_CTL_OVRD_OVRD_STATIC.

//! @brief Get value of SATAPHY_CLOCK_CTL_OVRD_OVRD_STATIC from a register value.
#define BG_SATAPHY_CLOCK_CTL_OVRD_OVRD_STATIC(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CTL_OVRD_OVRD_STATIC) >> BP_SATAPHY_CLOCK_CTL_OVRD_OVRD_STATIC)

//! @brief Format value for bitfield SATAPHY_CLOCK_CTL_OVRD_OVRD_STATIC.
#define BF_SATAPHY_CLOCK_CTL_OVRD_OVRD_STATIC(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CTL_OVRD_OVRD_STATIC) & BM_SATAPHY_CLOCK_CTL_OVRD_OVRD_STATIC)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_LVL_OVRD - Level Override Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_LVL_OVRD - Level Override Register (RW)
 *
 * Reset value: 0x00004210
 *
 * Address: 0x0014  Reset value: 16'b 0100 0010 0001 0000  This register contains the override of
 * level control inputs.
 */
typedef union _hw_sataphy_clock_lvl_ovrd
{
    reg16_t U;
    struct _hw_sataphy_clock_lvl_ovrd_bitfields
    {
        unsigned short ACJT_LVL : 5; //!< [4:0] ACJTAG comparator level
        unsigned short LOS_LVL : 5; //!< [9:5] Loss of Signal Detector
        unsigned short LEVEL_TX_LVL : 5; //!< [14:10] Transmit level
        unsigned short OVRD : 1; //!< [15] Overrides all level controls
    } B;
} hw_sataphy_clock_lvl_ovrd_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_LVL_OVRD register
 */
#define HW_SATAPHY_CLOCK_LVL_OVRD_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_LVL_OVRD           (*(volatile hw_sataphy_clock_lvl_ovrd_t *) HW_SATAPHY_CLOCK_LVL_OVRD_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_LVL_OVRD bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_LVL_OVRD, field ACJT_LVL[4:0] (RW)
 *
 * ACJTAG comparator level
 */

#define BP_SATAPHY_CLOCK_LVL_OVRD_ACJT_LVL      (0)      //!< Bit position for SATAPHY_CLOCK_LVL_OVRD_ACJT_LVL.
#define BM_SATAPHY_CLOCK_LVL_OVRD_ACJT_LVL      (0x0000001f)  //!< Bit mask for SATAPHY_CLOCK_LVL_OVRD_ACJT_LVL.

//! @brief Get value of SATAPHY_CLOCK_LVL_OVRD_ACJT_LVL from a register value.
#define BG_SATAPHY_CLOCK_LVL_OVRD_ACJT_LVL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_LVL_OVRD_ACJT_LVL) >> BP_SATAPHY_CLOCK_LVL_OVRD_ACJT_LVL)

//! @brief Format value for bitfield SATAPHY_CLOCK_LVL_OVRD_ACJT_LVL.
#define BF_SATAPHY_CLOCK_LVL_OVRD_ACJT_LVL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_LVL_OVRD_ACJT_LVL) & BM_SATAPHY_CLOCK_LVL_OVRD_ACJT_LVL)

/* --- Register HW_SATAPHY_CLOCK_LVL_OVRD, field LOS_LVL[9:5] (RW)
 *
 * Loss of Signal Detector
 */

#define BP_SATAPHY_CLOCK_LVL_OVRD_LOS_LVL      (5)      //!< Bit position for SATAPHY_CLOCK_LVL_OVRD_LOS_LVL.
#define BM_SATAPHY_CLOCK_LVL_OVRD_LOS_LVL      (0x000003e0)  //!< Bit mask for SATAPHY_CLOCK_LVL_OVRD_LOS_LVL.

//! @brief Get value of SATAPHY_CLOCK_LVL_OVRD_LOS_LVL from a register value.
#define BG_SATAPHY_CLOCK_LVL_OVRD_LOS_LVL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_LVL_OVRD_LOS_LVL) >> BP_SATAPHY_CLOCK_LVL_OVRD_LOS_LVL)

//! @brief Format value for bitfield SATAPHY_CLOCK_LVL_OVRD_LOS_LVL.
#define BF_SATAPHY_CLOCK_LVL_OVRD_LOS_LVL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_LVL_OVRD_LOS_LVL) & BM_SATAPHY_CLOCK_LVL_OVRD_LOS_LVL)

/* --- Register HW_SATAPHY_CLOCK_LVL_OVRD, field LEVEL_TX_LVL[14:10] (RW)
 *
 * Transmit level
 */

#define BP_SATAPHY_CLOCK_LVL_OVRD_LEVEL_TX_LVL      (10)      //!< Bit position for SATAPHY_CLOCK_LVL_OVRD_LEVEL_TX_LVL.
#define BM_SATAPHY_CLOCK_LVL_OVRD_LEVEL_TX_LVL      (0x00007c00)  //!< Bit mask for SATAPHY_CLOCK_LVL_OVRD_LEVEL_TX_LVL.

//! @brief Get value of SATAPHY_CLOCK_LVL_OVRD_LEVEL_TX_LVL from a register value.
#define BG_SATAPHY_CLOCK_LVL_OVRD_LEVEL_TX_LVL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_LVL_OVRD_LEVEL_TX_LVL) >> BP_SATAPHY_CLOCK_LVL_OVRD_LEVEL_TX_LVL)

//! @brief Format value for bitfield SATAPHY_CLOCK_LVL_OVRD_LEVEL_TX_LVL.
#define BF_SATAPHY_CLOCK_LVL_OVRD_LEVEL_TX_LVL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_LVL_OVRD_LEVEL_TX_LVL) & BM_SATAPHY_CLOCK_LVL_OVRD_LEVEL_TX_LVL)

/* --- Register HW_SATAPHY_CLOCK_LVL_OVRD, field OVRD[15] (RW)
 *
 * Overrides all level controls
 */

#define BP_SATAPHY_CLOCK_LVL_OVRD_OVRD      (15)      //!< Bit position for SATAPHY_CLOCK_LVL_OVRD_OVRD.
#define BM_SATAPHY_CLOCK_LVL_OVRD_OVRD      (0x00008000)  //!< Bit mask for SATAPHY_CLOCK_LVL_OVRD_OVRD.

//! @brief Get value of SATAPHY_CLOCK_LVL_OVRD_OVRD from a register value.
#define BG_SATAPHY_CLOCK_LVL_OVRD_OVRD(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_LVL_OVRD_OVRD) >> BP_SATAPHY_CLOCK_LVL_OVRD_OVRD)

//! @brief Format value for bitfield SATAPHY_CLOCK_LVL_OVRD_OVRD.
#define BF_SATAPHY_CLOCK_LVL_OVRD_OVRD(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_LVL_OVRD_OVRD) & BM_SATAPHY_CLOCK_LVL_OVRD_OVRD)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_CREG_OVRD - Creg Override Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_CREG_OVRD - Creg Override Register (RW)
 *
 * Reset value: 0x00000040
 *
 * Address: 0x0015 Reset value: 16'b xxxx xxx0 0100 0000 This register contains the override of creg
 * control I/O.
 */
typedef union _hw_sataphy_clock_creg_ovrd
{
    reg16_t U;
    struct _hw_sataphy_clock_creg_ovrd_bitfields
    {
        unsigned short CR_READ : 1; //!< [0] Reads request
        unsigned short CR_WRITE : 1; //!< [1] Writes request
        unsigned short CR_CAP_DATA : 1; //!< [2] Captures data request
        unsigned short CR_CAP_ADDR : 1; //!< [3] Captures address request
        unsigned short OVRD_IN : 1; //!< [4] Overrides inputs (bits [3:0])
        unsigned short CR_ACK : 1; //!< [5] Creg request acknowledgement
        unsigned short POWER_GOOD : 1; //!< [6] Power good output
        unsigned short OP_DONE : 1; //!< [7] Operation is complete output
        unsigned short OVRD_OUT : 1; //!< [8] Overrides outputs (bits [7:5])
        unsigned short RESERVED0 : 7; //!< [15:9] Reserved
    } B;
} hw_sataphy_clock_creg_ovrd_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_CREG_OVRD register
 */
#define HW_SATAPHY_CLOCK_CREG_OVRD_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x15)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_CREG_OVRD           (*(volatile hw_sataphy_clock_creg_ovrd_t *) HW_SATAPHY_CLOCK_CREG_OVRD_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_CREG_OVRD bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_CREG_OVRD, field CR_READ[0] (RW)
 *
 * Reads request
 */

#define BP_SATAPHY_CLOCK_CREG_OVRD_CR_READ      (0)      //!< Bit position for SATAPHY_CLOCK_CREG_OVRD_CR_READ.
#define BM_SATAPHY_CLOCK_CREG_OVRD_CR_READ      (0x00000001)  //!< Bit mask for SATAPHY_CLOCK_CREG_OVRD_CR_READ.

//! @brief Get value of SATAPHY_CLOCK_CREG_OVRD_CR_READ from a register value.
#define BG_SATAPHY_CLOCK_CREG_OVRD_CR_READ(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_READ) >> BP_SATAPHY_CLOCK_CREG_OVRD_CR_READ)

//! @brief Format value for bitfield SATAPHY_CLOCK_CREG_OVRD_CR_READ.
#define BF_SATAPHY_CLOCK_CREG_OVRD_CR_READ(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CREG_OVRD_CR_READ) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_READ)

/* --- Register HW_SATAPHY_CLOCK_CREG_OVRD, field CR_WRITE[1] (RW)
 *
 * Writes request
 */

#define BP_SATAPHY_CLOCK_CREG_OVRD_CR_WRITE      (1)      //!< Bit position for SATAPHY_CLOCK_CREG_OVRD_CR_WRITE.
#define BM_SATAPHY_CLOCK_CREG_OVRD_CR_WRITE      (0x00000002)  //!< Bit mask for SATAPHY_CLOCK_CREG_OVRD_CR_WRITE.

//! @brief Get value of SATAPHY_CLOCK_CREG_OVRD_CR_WRITE from a register value.
#define BG_SATAPHY_CLOCK_CREG_OVRD_CR_WRITE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_WRITE) >> BP_SATAPHY_CLOCK_CREG_OVRD_CR_WRITE)

//! @brief Format value for bitfield SATAPHY_CLOCK_CREG_OVRD_CR_WRITE.
#define BF_SATAPHY_CLOCK_CREG_OVRD_CR_WRITE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CREG_OVRD_CR_WRITE) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_WRITE)

/* --- Register HW_SATAPHY_CLOCK_CREG_OVRD, field CR_CAP_DATA[2] (RW)
 *
 * Captures data request
 */

#define BP_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_DATA      (2)      //!< Bit position for SATAPHY_CLOCK_CREG_OVRD_CR_CAP_DATA.
#define BM_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_DATA      (0x00000004)  //!< Bit mask for SATAPHY_CLOCK_CREG_OVRD_CR_CAP_DATA.

//! @brief Get value of SATAPHY_CLOCK_CREG_OVRD_CR_CAP_DATA from a register value.
#define BG_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_DATA(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_DATA) >> BP_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_DATA)

//! @brief Format value for bitfield SATAPHY_CLOCK_CREG_OVRD_CR_CAP_DATA.
#define BF_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_DATA(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_DATA) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_DATA)

/* --- Register HW_SATAPHY_CLOCK_CREG_OVRD, field CR_CAP_ADDR[3] (RW)
 *
 * Captures address request
 */

#define BP_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_ADDR      (3)      //!< Bit position for SATAPHY_CLOCK_CREG_OVRD_CR_CAP_ADDR.
#define BM_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_ADDR      (0x00000008)  //!< Bit mask for SATAPHY_CLOCK_CREG_OVRD_CR_CAP_ADDR.

//! @brief Get value of SATAPHY_CLOCK_CREG_OVRD_CR_CAP_ADDR from a register value.
#define BG_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_ADDR(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_ADDR) >> BP_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_ADDR)

//! @brief Format value for bitfield SATAPHY_CLOCK_CREG_OVRD_CR_CAP_ADDR.
#define BF_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_ADDR(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_ADDR) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_CAP_ADDR)

/* --- Register HW_SATAPHY_CLOCK_CREG_OVRD, field OVRD_IN[4] (RW)
 *
 * Overrides inputs (bits [3:0])
 */

#define BP_SATAPHY_CLOCK_CREG_OVRD_OVRD_IN      (4)      //!< Bit position for SATAPHY_CLOCK_CREG_OVRD_OVRD_IN.
#define BM_SATAPHY_CLOCK_CREG_OVRD_OVRD_IN      (0x00000010)  //!< Bit mask for SATAPHY_CLOCK_CREG_OVRD_OVRD_IN.

//! @brief Get value of SATAPHY_CLOCK_CREG_OVRD_OVRD_IN from a register value.
#define BG_SATAPHY_CLOCK_CREG_OVRD_OVRD_IN(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CREG_OVRD_OVRD_IN) >> BP_SATAPHY_CLOCK_CREG_OVRD_OVRD_IN)

//! @brief Format value for bitfield SATAPHY_CLOCK_CREG_OVRD_OVRD_IN.
#define BF_SATAPHY_CLOCK_CREG_OVRD_OVRD_IN(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CREG_OVRD_OVRD_IN) & BM_SATAPHY_CLOCK_CREG_OVRD_OVRD_IN)

/* --- Register HW_SATAPHY_CLOCK_CREG_OVRD, field CR_ACK[5] (RW)
 *
 * Creg request acknowledgement
 */

#define BP_SATAPHY_CLOCK_CREG_OVRD_CR_ACK      (5)      //!< Bit position for SATAPHY_CLOCK_CREG_OVRD_CR_ACK.
#define BM_SATAPHY_CLOCK_CREG_OVRD_CR_ACK      (0x00000020)  //!< Bit mask for SATAPHY_CLOCK_CREG_OVRD_CR_ACK.

//! @brief Get value of SATAPHY_CLOCK_CREG_OVRD_CR_ACK from a register value.
#define BG_SATAPHY_CLOCK_CREG_OVRD_CR_ACK(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_ACK) >> BP_SATAPHY_CLOCK_CREG_OVRD_CR_ACK)

//! @brief Format value for bitfield SATAPHY_CLOCK_CREG_OVRD_CR_ACK.
#define BF_SATAPHY_CLOCK_CREG_OVRD_CR_ACK(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CREG_OVRD_CR_ACK) & BM_SATAPHY_CLOCK_CREG_OVRD_CR_ACK)

/* --- Register HW_SATAPHY_CLOCK_CREG_OVRD, field POWER_GOOD[6] (RW)
 *
 * Power good output
 */

#define BP_SATAPHY_CLOCK_CREG_OVRD_POWER_GOOD      (6)      //!< Bit position for SATAPHY_CLOCK_CREG_OVRD_POWER_GOOD.
#define BM_SATAPHY_CLOCK_CREG_OVRD_POWER_GOOD      (0x00000040)  //!< Bit mask for SATAPHY_CLOCK_CREG_OVRD_POWER_GOOD.

//! @brief Get value of SATAPHY_CLOCK_CREG_OVRD_POWER_GOOD from a register value.
#define BG_SATAPHY_CLOCK_CREG_OVRD_POWER_GOOD(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CREG_OVRD_POWER_GOOD) >> BP_SATAPHY_CLOCK_CREG_OVRD_POWER_GOOD)

//! @brief Format value for bitfield SATAPHY_CLOCK_CREG_OVRD_POWER_GOOD.
#define BF_SATAPHY_CLOCK_CREG_OVRD_POWER_GOOD(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CREG_OVRD_POWER_GOOD) & BM_SATAPHY_CLOCK_CREG_OVRD_POWER_GOOD)

/* --- Register HW_SATAPHY_CLOCK_CREG_OVRD, field OP_DONE[7] (RW)
 *
 * Operation is complete output
 */

#define BP_SATAPHY_CLOCK_CREG_OVRD_OP_DONE      (7)      //!< Bit position for SATAPHY_CLOCK_CREG_OVRD_OP_DONE.
#define BM_SATAPHY_CLOCK_CREG_OVRD_OP_DONE      (0x00000080)  //!< Bit mask for SATAPHY_CLOCK_CREG_OVRD_OP_DONE.

//! @brief Get value of SATAPHY_CLOCK_CREG_OVRD_OP_DONE from a register value.
#define BG_SATAPHY_CLOCK_CREG_OVRD_OP_DONE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CREG_OVRD_OP_DONE) >> BP_SATAPHY_CLOCK_CREG_OVRD_OP_DONE)

//! @brief Format value for bitfield SATAPHY_CLOCK_CREG_OVRD_OP_DONE.
#define BF_SATAPHY_CLOCK_CREG_OVRD_OP_DONE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CREG_OVRD_OP_DONE) & BM_SATAPHY_CLOCK_CREG_OVRD_OP_DONE)

/* --- Register HW_SATAPHY_CLOCK_CREG_OVRD, field OVRD_OUT[8] (RW)
 *
 * Overrides outputs (bits [7:5])
 */

#define BP_SATAPHY_CLOCK_CREG_OVRD_OVRD_OUT      (8)      //!< Bit position for SATAPHY_CLOCK_CREG_OVRD_OVRD_OUT.
#define BM_SATAPHY_CLOCK_CREG_OVRD_OVRD_OUT      (0x00000100)  //!< Bit mask for SATAPHY_CLOCK_CREG_OVRD_OVRD_OUT.

//! @brief Get value of SATAPHY_CLOCK_CREG_OVRD_OVRD_OUT from a register value.
#define BG_SATAPHY_CLOCK_CREG_OVRD_OVRD_OUT(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_CREG_OVRD_OVRD_OUT) >> BP_SATAPHY_CLOCK_CREG_OVRD_OVRD_OUT)

//! @brief Format value for bitfield SATAPHY_CLOCK_CREG_OVRD_OVRD_OUT.
#define BF_SATAPHY_CLOCK_CREG_OVRD_OVRD_OUT(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_CREG_OVRD_OVRD_OUT) & BM_SATAPHY_CLOCK_CREG_OVRD_OVRD_OUT)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_MPLL_CTL - MPLL Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_MPLL_CTL - MPLL Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Reset value: 16'b xxxx xx00 0000 0000  This register contains MPLL controls.
 */
typedef union _hw_sataphy_clock_mpll_ctl
{
    reg16_t U;
    struct _hw_sataphy_clock_mpll_ctl_bitfields
    {
        unsigned short CLKDRV_ANA : 1; //!< [0] Value for analog clock drivers
        unsigned short CLKDRV_DIG : 1; //!< [1] Value for digital clock drivers
        unsigned short OVRD_CLKDRV : 1; //!< [2] Overrides clock driver controls
        unsigned short DIS_PARA_CREG : 1; //!< [3] Disables parallel creg interface
        unsigned short REFCLK_DELAY : 1; //!< [4] Delays refclk output of prescaler
        unsigned short DTB_SEL0 : 5; //!< [9:5] Selects wire to drive onto DTB bit 0: All other bits: Disabled
        unsigned short DTB_SEL1 : 5; //!< [14:10] Selects wire to drive onto DTB bit 1: All other bits: Disabled
        unsigned short RESERVED0 : 1; //!< [15] Reserved
    } B;
} hw_sataphy_clock_mpll_ctl_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_MPLL_CTL register
 */
#define HW_SATAPHY_CLOCK_MPLL_CTL_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x16)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_MPLL_CTL           (*(volatile hw_sataphy_clock_mpll_ctl_t *) HW_SATAPHY_CLOCK_MPLL_CTL_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_MPLL_CTL bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_MPLL_CTL, field CLKDRV_ANA[0] (RW)
 *
 * Value for analog clock drivers
 */

#define BP_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_ANA      (0)      //!< Bit position for SATAPHY_CLOCK_MPLL_CTL_CLKDRV_ANA.
#define BM_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_ANA      (0x00000001)  //!< Bit mask for SATAPHY_CLOCK_MPLL_CTL_CLKDRV_ANA.

//! @brief Get value of SATAPHY_CLOCK_MPLL_CTL_CLKDRV_ANA from a register value.
#define BG_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_ANA(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_ANA) >> BP_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_ANA)

//! @brief Format value for bitfield SATAPHY_CLOCK_MPLL_CTL_CLKDRV_ANA.
#define BF_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_ANA(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_ANA) & BM_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_ANA)

/* --- Register HW_SATAPHY_CLOCK_MPLL_CTL, field CLKDRV_DIG[1] (RW)
 *
 * Value for digital clock drivers
 */

#define BP_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_DIG      (1)      //!< Bit position for SATAPHY_CLOCK_MPLL_CTL_CLKDRV_DIG.
#define BM_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_DIG      (0x00000002)  //!< Bit mask for SATAPHY_CLOCK_MPLL_CTL_CLKDRV_DIG.

//! @brief Get value of SATAPHY_CLOCK_MPLL_CTL_CLKDRV_DIG from a register value.
#define BG_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_DIG(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_DIG) >> BP_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_DIG)

//! @brief Format value for bitfield SATAPHY_CLOCK_MPLL_CTL_CLKDRV_DIG.
#define BF_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_DIG(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_DIG) & BM_SATAPHY_CLOCK_MPLL_CTL_CLKDRV_DIG)

/* --- Register HW_SATAPHY_CLOCK_MPLL_CTL, field OVRD_CLKDRV[2] (RW)
 *
 * Overrides clock driver controls
 */

#define BP_SATAPHY_CLOCK_MPLL_CTL_OVRD_CLKDRV      (2)      //!< Bit position for SATAPHY_CLOCK_MPLL_CTL_OVRD_CLKDRV.
#define BM_SATAPHY_CLOCK_MPLL_CTL_OVRD_CLKDRV      (0x00000004)  //!< Bit mask for SATAPHY_CLOCK_MPLL_CTL_OVRD_CLKDRV.

//! @brief Get value of SATAPHY_CLOCK_MPLL_CTL_OVRD_CLKDRV from a register value.
#define BG_SATAPHY_CLOCK_MPLL_CTL_OVRD_CLKDRV(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_MPLL_CTL_OVRD_CLKDRV) >> BP_SATAPHY_CLOCK_MPLL_CTL_OVRD_CLKDRV)

//! @brief Format value for bitfield SATAPHY_CLOCK_MPLL_CTL_OVRD_CLKDRV.
#define BF_SATAPHY_CLOCK_MPLL_CTL_OVRD_CLKDRV(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_MPLL_CTL_OVRD_CLKDRV) & BM_SATAPHY_CLOCK_MPLL_CTL_OVRD_CLKDRV)

/* --- Register HW_SATAPHY_CLOCK_MPLL_CTL, field DIS_PARA_CREG[3] (RW)
 *
 * Disables parallel creg interface
 */

#define BP_SATAPHY_CLOCK_MPLL_CTL_DIS_PARA_CREG      (3)      //!< Bit position for SATAPHY_CLOCK_MPLL_CTL_DIS_PARA_CREG.
#define BM_SATAPHY_CLOCK_MPLL_CTL_DIS_PARA_CREG      (0x00000008)  //!< Bit mask for SATAPHY_CLOCK_MPLL_CTL_DIS_PARA_CREG.

//! @brief Get value of SATAPHY_CLOCK_MPLL_CTL_DIS_PARA_CREG from a register value.
#define BG_SATAPHY_CLOCK_MPLL_CTL_DIS_PARA_CREG(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_MPLL_CTL_DIS_PARA_CREG) >> BP_SATAPHY_CLOCK_MPLL_CTL_DIS_PARA_CREG)

//! @brief Format value for bitfield SATAPHY_CLOCK_MPLL_CTL_DIS_PARA_CREG.
#define BF_SATAPHY_CLOCK_MPLL_CTL_DIS_PARA_CREG(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_MPLL_CTL_DIS_PARA_CREG) & BM_SATAPHY_CLOCK_MPLL_CTL_DIS_PARA_CREG)

/* --- Register HW_SATAPHY_CLOCK_MPLL_CTL, field REFCLK_DELAY[4] (RW)
 *
 * Delays refclk output of prescaler
 */

#define BP_SATAPHY_CLOCK_MPLL_CTL_REFCLK_DELAY      (4)      //!< Bit position for SATAPHY_CLOCK_MPLL_CTL_REFCLK_DELAY.
#define BM_SATAPHY_CLOCK_MPLL_CTL_REFCLK_DELAY      (0x00000010)  //!< Bit mask for SATAPHY_CLOCK_MPLL_CTL_REFCLK_DELAY.

//! @brief Get value of SATAPHY_CLOCK_MPLL_CTL_REFCLK_DELAY from a register value.
#define BG_SATAPHY_CLOCK_MPLL_CTL_REFCLK_DELAY(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_MPLL_CTL_REFCLK_DELAY) >> BP_SATAPHY_CLOCK_MPLL_CTL_REFCLK_DELAY)

//! @brief Format value for bitfield SATAPHY_CLOCK_MPLL_CTL_REFCLK_DELAY.
#define BF_SATAPHY_CLOCK_MPLL_CTL_REFCLK_DELAY(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_MPLL_CTL_REFCLK_DELAY) & BM_SATAPHY_CLOCK_MPLL_CTL_REFCLK_DELAY)

/* --- Register HW_SATAPHY_CLOCK_MPLL_CTL, field DTB_SEL0[9:5] (RW)
 *
 * Selects wire to drive onto DTB bit 0: All other bits: Disabled
 *
 * Values:
 * 00000 - Disabled
 * 00001 - mpll_gear_shift
 * 00010 - mpll_reset
 * 00011 - mpll_pwron (at analog boundary)
 * 00100 - reset_n
 * 00101 - cr_ack
 * 00110 - power_good
 * 00111 - op_done
 * 01000 - cr_read
 * 01001 - cr_write
 * 01010 - cr_cap_data
 * 01011 - cr_cap_addr
 * 01100 - rtune_do_tune
 * 01101 - cko_alive_con[0]
 * 01110 - cko_alive_con[1]
 * 01111 - cko_word_con[0]
 * 10000 - cko_word_con[1]
 * 10001 - cko_word_con[2]
 * 10010 - mpll_pwron (ASIC control)
 * 10011 - mpll_ck_off
 */

#define BP_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL0      (5)      //!< Bit position for SATAPHY_CLOCK_MPLL_CTL_DTB_SEL0.
#define BM_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL0      (0x000003e0)  //!< Bit mask for SATAPHY_CLOCK_MPLL_CTL_DTB_SEL0.

//! @brief Get value of SATAPHY_CLOCK_MPLL_CTL_DTB_SEL0 from a register value.
#define BG_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL0(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL0) >> BP_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL0)

//! @brief Format value for bitfield SATAPHY_CLOCK_MPLL_CTL_DTB_SEL0.
#define BF_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL0(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL0) & BM_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL0)


/* --- Register HW_SATAPHY_CLOCK_MPLL_CTL, field DTB_SEL1[14:10] (RW)
 *
 * Selects wire to drive onto DTB bit 1: All other bits: Disabled
 *
 * Values:
 * 00000 - Disabled
 * 00001 - mpll_gear_shift
 * 00010 - mpll_reset
 * 00011 - mpll_pwron (at analog boundary)
 * 00100 - reset_n
 * 00101 - cr_ack
 * 00110 - power_good
 * 00111 - op_done
 * 01000 - cr_read
 * 01001 - cr_write
 * 01010 - cr_cap_data
 * 01011 - cr_cap_addr
 * 01100 - rtune_do_tune
 * 01101 - cko_alive_con[0]
 * 01110 - cko_alive_con[1]
 * 01111 - cko_word_con[0]
 * 10000 - cko_word_con[1]
 * 10001 - cko_word_con[2]
 * 10010 - mpll_pwron (ASIC control)
 * 10011 - mpll_ck_off
 */

#define BP_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL1      (10)      //!< Bit position for SATAPHY_CLOCK_MPLL_CTL_DTB_SEL1.
#define BM_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL1      (0x00007c00)  //!< Bit mask for SATAPHY_CLOCK_MPLL_CTL_DTB_SEL1.

//! @brief Get value of SATAPHY_CLOCK_MPLL_CTL_DTB_SEL1 from a register value.
#define BG_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL1(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL1) >> BP_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL1)

//! @brief Format value for bitfield SATAPHY_CLOCK_MPLL_CTL_DTB_SEL1.
#define BF_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL1(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL1) & BM_SATAPHY_CLOCK_MPLL_CTL_DTB_SEL1)


//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_MPLL_TEST - MPLL Test Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_MPLL_TEST - MPLL Test Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x0017  Reset value: 16'b 0000 0000 0000 0000  This register contains MPLL test
 * controls.
 */
typedef union _hw_sataphy_clock_mpll_test
{
    reg16_t U;
    struct _hw_sataphy_clock_mpll_test_bitfields
    {
        unsigned short ATB_SENSE : 1; //!< [0] Hooks up ATB sense lines
        unsigned short MEAS_GD : 1; //!< [1] Measures Ground For correct measurements, this field must be set when various meas_iv bits are set.
        unsigned short MEAS_IV : 11; //!< [12:2] Measures various MPLL controls: Bit 2: Measures dcc_vcntrl_p on atb_sense_p Bit 3: Measures dcc_vcntrl_m on atb_sense_m Bit 4: Measures 1-V supply voltage on atb_sense_m Bit 5: Measures vp_cp voltage on atb_sense_p; gd on atb_sense_m Bit 6: Measures VCO supply voltage on atb_sense_p; gd on atb_sense_m Bit 7: Measures clock tree supply voltage on atb_sense_p; gd on atb_sense_m Bit 8: Measures vp16 on atb_sense_p; gd on atb_sense_m Bit 9: Measures vref on atb_sense_p; gd on atb_sense_m Bit 10: Measures vcntrl on atb_sense_m Bit 11: Measures copy of bias current in oscillator on atb_force_m Bit 12: Enables phase linearity testing of phase interpolator and VCO
        unsigned short RESET_VAL : 1; //!< [13] Value to override for mpll_reset
        unsigned short GEARSHIFT_VAL : 1; //!< [14] Value to override for mpll_gearshift
        unsigned short OVRD_CTL : 1; //!< [15] Overrides MPLL reset and gearshift controls
    } B;
} hw_sataphy_clock_mpll_test_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_MPLL_TEST register
 */
#define HW_SATAPHY_CLOCK_MPLL_TEST_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x17)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_MPLL_TEST           (*(volatile hw_sataphy_clock_mpll_test_t *) HW_SATAPHY_CLOCK_MPLL_TEST_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_MPLL_TEST bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_MPLL_TEST, field ATB_SENSE[0] (RW)
 *
 * Hooks up ATB sense lines
 */

#define BP_SATAPHY_CLOCK_MPLL_TEST_ATB_SENSE      (0)      //!< Bit position for SATAPHY_CLOCK_MPLL_TEST_ATB_SENSE.
#define BM_SATAPHY_CLOCK_MPLL_TEST_ATB_SENSE      (0x00000001)  //!< Bit mask for SATAPHY_CLOCK_MPLL_TEST_ATB_SENSE.

//! @brief Get value of SATAPHY_CLOCK_MPLL_TEST_ATB_SENSE from a register value.
#define BG_SATAPHY_CLOCK_MPLL_TEST_ATB_SENSE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_MPLL_TEST_ATB_SENSE) >> BP_SATAPHY_CLOCK_MPLL_TEST_ATB_SENSE)

//! @brief Format value for bitfield SATAPHY_CLOCK_MPLL_TEST_ATB_SENSE.
#define BF_SATAPHY_CLOCK_MPLL_TEST_ATB_SENSE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_MPLL_TEST_ATB_SENSE) & BM_SATAPHY_CLOCK_MPLL_TEST_ATB_SENSE)

/* --- Register HW_SATAPHY_CLOCK_MPLL_TEST, field MEAS_GD[1] (RW)
 *
 * Measures Ground For correct measurements, this field must be set when various meas_iv bits are
 * set.
 */

#define BP_SATAPHY_CLOCK_MPLL_TEST_MEAS_GD      (1)      //!< Bit position for SATAPHY_CLOCK_MPLL_TEST_MEAS_GD.
#define BM_SATAPHY_CLOCK_MPLL_TEST_MEAS_GD      (0x00000002)  //!< Bit mask for SATAPHY_CLOCK_MPLL_TEST_MEAS_GD.

//! @brief Get value of SATAPHY_CLOCK_MPLL_TEST_MEAS_GD from a register value.
#define BG_SATAPHY_CLOCK_MPLL_TEST_MEAS_GD(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_MPLL_TEST_MEAS_GD) >> BP_SATAPHY_CLOCK_MPLL_TEST_MEAS_GD)

//! @brief Format value for bitfield SATAPHY_CLOCK_MPLL_TEST_MEAS_GD.
#define BF_SATAPHY_CLOCK_MPLL_TEST_MEAS_GD(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_MPLL_TEST_MEAS_GD) & BM_SATAPHY_CLOCK_MPLL_TEST_MEAS_GD)

/* --- Register HW_SATAPHY_CLOCK_MPLL_TEST, field MEAS_IV[12:2] (RW)
 *
 * Measures various MPLL controls: Bit 2: Measures dcc_vcntrl_p on atb_sense_p Bit 3: Measures
 * dcc_vcntrl_m on atb_sense_m Bit 4: Measures 1-V supply voltage on atb_sense_m Bit 5: Measures
 * vp_cp voltage on atb_sense_p; gd on atb_sense_m Bit 6: Measures VCO supply voltage on
 * atb_sense_p; gd on atb_sense_m Bit 7: Measures clock tree supply voltage on atb_sense_p; gd on
 * atb_sense_m Bit 8: Measures vp16 on atb_sense_p; gd on atb_sense_m Bit 9: Measures vref on
 * atb_sense_p; gd on atb_sense_m Bit 10: Measures vcntrl on atb_sense_m Bit 11: Measures copy of
 * bias current in oscillator on atb_force_m Bit 12: Enables phase linearity testing of phase
 * interpolator and VCO
 */

#define BP_SATAPHY_CLOCK_MPLL_TEST_MEAS_IV      (2)      //!< Bit position for SATAPHY_CLOCK_MPLL_TEST_MEAS_IV.
#define BM_SATAPHY_CLOCK_MPLL_TEST_MEAS_IV      (0x00001ffc)  //!< Bit mask for SATAPHY_CLOCK_MPLL_TEST_MEAS_IV.

//! @brief Get value of SATAPHY_CLOCK_MPLL_TEST_MEAS_IV from a register value.
#define BG_SATAPHY_CLOCK_MPLL_TEST_MEAS_IV(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_MPLL_TEST_MEAS_IV) >> BP_SATAPHY_CLOCK_MPLL_TEST_MEAS_IV)

//! @brief Format value for bitfield SATAPHY_CLOCK_MPLL_TEST_MEAS_IV.
#define BF_SATAPHY_CLOCK_MPLL_TEST_MEAS_IV(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_MPLL_TEST_MEAS_IV) & BM_SATAPHY_CLOCK_MPLL_TEST_MEAS_IV)

/* --- Register HW_SATAPHY_CLOCK_MPLL_TEST, field RESET_VAL[13] (RW)
 *
 * Value to override for mpll_reset
 */

#define BP_SATAPHY_CLOCK_MPLL_TEST_RESET_VAL      (13)      //!< Bit position for SATAPHY_CLOCK_MPLL_TEST_RESET_VAL.
#define BM_SATAPHY_CLOCK_MPLL_TEST_RESET_VAL      (0x00002000)  //!< Bit mask for SATAPHY_CLOCK_MPLL_TEST_RESET_VAL.

//! @brief Get value of SATAPHY_CLOCK_MPLL_TEST_RESET_VAL from a register value.
#define BG_SATAPHY_CLOCK_MPLL_TEST_RESET_VAL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_MPLL_TEST_RESET_VAL) >> BP_SATAPHY_CLOCK_MPLL_TEST_RESET_VAL)

//! @brief Format value for bitfield SATAPHY_CLOCK_MPLL_TEST_RESET_VAL.
#define BF_SATAPHY_CLOCK_MPLL_TEST_RESET_VAL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_MPLL_TEST_RESET_VAL) & BM_SATAPHY_CLOCK_MPLL_TEST_RESET_VAL)

/* --- Register HW_SATAPHY_CLOCK_MPLL_TEST, field GEARSHIFT_VAL[14] (RW)
 *
 * Value to override for mpll_gearshift
 */

#define BP_SATAPHY_CLOCK_MPLL_TEST_GEARSHIFT_VAL      (14)      //!< Bit position for SATAPHY_CLOCK_MPLL_TEST_GEARSHIFT_VAL.
#define BM_SATAPHY_CLOCK_MPLL_TEST_GEARSHIFT_VAL      (0x00004000)  //!< Bit mask for SATAPHY_CLOCK_MPLL_TEST_GEARSHIFT_VAL.

//! @brief Get value of SATAPHY_CLOCK_MPLL_TEST_GEARSHIFT_VAL from a register value.
#define BG_SATAPHY_CLOCK_MPLL_TEST_GEARSHIFT_VAL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_MPLL_TEST_GEARSHIFT_VAL) >> BP_SATAPHY_CLOCK_MPLL_TEST_GEARSHIFT_VAL)

//! @brief Format value for bitfield SATAPHY_CLOCK_MPLL_TEST_GEARSHIFT_VAL.
#define BF_SATAPHY_CLOCK_MPLL_TEST_GEARSHIFT_VAL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_MPLL_TEST_GEARSHIFT_VAL) & BM_SATAPHY_CLOCK_MPLL_TEST_GEARSHIFT_VAL)

/* --- Register HW_SATAPHY_CLOCK_MPLL_TEST, field OVRD_CTL[15] (RW)
 *
 * Overrides MPLL reset and gearshift controls
 */

#define BP_SATAPHY_CLOCK_MPLL_TEST_OVRD_CTL      (15)      //!< Bit position for SATAPHY_CLOCK_MPLL_TEST_OVRD_CTL.
#define BM_SATAPHY_CLOCK_MPLL_TEST_OVRD_CTL      (0x00008000)  //!< Bit mask for SATAPHY_CLOCK_MPLL_TEST_OVRD_CTL.

//! @brief Get value of SATAPHY_CLOCK_MPLL_TEST_OVRD_CTL from a register value.
#define BG_SATAPHY_CLOCK_MPLL_TEST_OVRD_CTL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_MPLL_TEST_OVRD_CTL) >> BP_SATAPHY_CLOCK_MPLL_TEST_OVRD_CTL)

//! @brief Format value for bitfield SATAPHY_CLOCK_MPLL_TEST_OVRD_CTL.
#define BF_SATAPHY_CLOCK_MPLL_TEST_OVRD_CTL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_MPLL_TEST_OVRD_CTL) & BM_SATAPHY_CLOCK_MPLL_TEST_OVRD_CTL)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_SS_FREQ - Spread Spectrum Frequency Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_SS_FREQ - Spread Spectrum Frequency Register (RW)
 *
 * Reset value: 0x0000332f
 *
 * Address: 0x0018  Reset value: 16'b x011 0011 0010 1111  This register contains the frequency
 * register override, peak frequency value, and frequency counter step values.
 */
typedef union _hw_sataphy_clock_ss_freq
{
    reg16_t U;
    struct _hw_sataphy_clock_ss_freq_bitfields
    {
        unsigned short FREQ_CNT_INIT : 7; //!< [6:0] Frequency counter step value. Note: This value is independent of the freq_pk value.
        unsigned short FREQ_PK : 7; //!< [13:7] Peak frequency value
        unsigned short FREQ_REG_OVRD : 1; //!< [14] Override control, indicating that overridden value is active
        unsigned short RESERVED0 : 1; //!< [15] Reserved
    } B;
} hw_sataphy_clock_ss_freq_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_SS_FREQ register
 */
#define HW_SATAPHY_CLOCK_SS_FREQ_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_SS_FREQ           (*(volatile hw_sataphy_clock_ss_freq_t *) HW_SATAPHY_CLOCK_SS_FREQ_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_SS_FREQ bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_SS_FREQ, field FREQ_CNT_INIT[6:0] (RW)
 *
 * Frequency counter step value. Note: This value is independent of the freq_pk value.
 */

#define BP_SATAPHY_CLOCK_SS_FREQ_FREQ_CNT_INIT      (0)      //!< Bit position for SATAPHY_CLOCK_SS_FREQ_FREQ_CNT_INIT.
#define BM_SATAPHY_CLOCK_SS_FREQ_FREQ_CNT_INIT      (0x0000007f)  //!< Bit mask for SATAPHY_CLOCK_SS_FREQ_FREQ_CNT_INIT.

//! @brief Get value of SATAPHY_CLOCK_SS_FREQ_FREQ_CNT_INIT from a register value.
#define BG_SATAPHY_CLOCK_SS_FREQ_FREQ_CNT_INIT(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_SS_FREQ_FREQ_CNT_INIT) >> BP_SATAPHY_CLOCK_SS_FREQ_FREQ_CNT_INIT)

//! @brief Format value for bitfield SATAPHY_CLOCK_SS_FREQ_FREQ_CNT_INIT.
#define BF_SATAPHY_CLOCK_SS_FREQ_FREQ_CNT_INIT(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_SS_FREQ_FREQ_CNT_INIT) & BM_SATAPHY_CLOCK_SS_FREQ_FREQ_CNT_INIT)

/* --- Register HW_SATAPHY_CLOCK_SS_FREQ, field FREQ_PK[13:7] (RW)
 *
 * Peak frequency value
 */

#define BP_SATAPHY_CLOCK_SS_FREQ_FREQ_PK      (7)      //!< Bit position for SATAPHY_CLOCK_SS_FREQ_FREQ_PK.
#define BM_SATAPHY_CLOCK_SS_FREQ_FREQ_PK      (0x00003f80)  //!< Bit mask for SATAPHY_CLOCK_SS_FREQ_FREQ_PK.

//! @brief Get value of SATAPHY_CLOCK_SS_FREQ_FREQ_PK from a register value.
#define BG_SATAPHY_CLOCK_SS_FREQ_FREQ_PK(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_SS_FREQ_FREQ_PK) >> BP_SATAPHY_CLOCK_SS_FREQ_FREQ_PK)

//! @brief Format value for bitfield SATAPHY_CLOCK_SS_FREQ_FREQ_PK.
#define BF_SATAPHY_CLOCK_SS_FREQ_FREQ_PK(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_SS_FREQ_FREQ_PK) & BM_SATAPHY_CLOCK_SS_FREQ_FREQ_PK)

/* --- Register HW_SATAPHY_CLOCK_SS_FREQ, field FREQ_REG_OVRD[14] (RW)
 *
 * Override control, indicating that overridden value is active
 */

#define BP_SATAPHY_CLOCK_SS_FREQ_FREQ_REG_OVRD      (14)      //!< Bit position for SATAPHY_CLOCK_SS_FREQ_FREQ_REG_OVRD.
#define BM_SATAPHY_CLOCK_SS_FREQ_FREQ_REG_OVRD      (0x00004000)  //!< Bit mask for SATAPHY_CLOCK_SS_FREQ_FREQ_REG_OVRD.

//! @brief Get value of SATAPHY_CLOCK_SS_FREQ_FREQ_REG_OVRD from a register value.
#define BG_SATAPHY_CLOCK_SS_FREQ_FREQ_REG_OVRD(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_SS_FREQ_FREQ_REG_OVRD) >> BP_SATAPHY_CLOCK_SS_FREQ_FREQ_REG_OVRD)

//! @brief Format value for bitfield SATAPHY_CLOCK_SS_FREQ_FREQ_REG_OVRD.
#define BF_SATAPHY_CLOCK_SS_FREQ_FREQ_REG_OVRD(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_SS_FREQ_FREQ_REG_OVRD) & BM_SATAPHY_CLOCK_SS_FREQ_FREQ_REG_OVRD)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_SEL_STAT - Clock Select Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_SEL_STAT - Clock Select Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x0019  Reset value: 16'bxxxx xxxx xxxx xxxx (depends on inputs)  This register
 * indicates the status of the ref_clk_sel and mpll_ss_sel inputs.
 */
typedef union _hw_sataphy_clock_sel_stat
{
    reg16_t U;
    struct _hw_sataphy_clock_sel_stat_bitfields
    {
        unsigned short MPLL_SS_SEL : 2; //!< [1:0] MPLL spread spectrum select input
        unsigned short REF_CLK_SEL : 8; //!< [9:2] Reference clock select input
        unsigned short RESERVED0 : 6; //!< [15:10] Reserved
    } B;
} hw_sataphy_clock_sel_stat_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_SEL_STAT register
 */
#define HW_SATAPHY_CLOCK_SEL_STAT_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x19)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_SEL_STAT           (*(volatile hw_sataphy_clock_sel_stat_t *) HW_SATAPHY_CLOCK_SEL_STAT_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_SEL_STAT bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_SEL_STAT, field MPLL_SS_SEL[1:0] (RO)
 *
 * MPLL spread spectrum select input
 */

#define BP_SATAPHY_CLOCK_SEL_STAT_MPLL_SS_SEL      (0)      //!< Bit position for SATAPHY_CLOCK_SEL_STAT_MPLL_SS_SEL.
#define BM_SATAPHY_CLOCK_SEL_STAT_MPLL_SS_SEL      (0x00000003)  //!< Bit mask for SATAPHY_CLOCK_SEL_STAT_MPLL_SS_SEL.

//! @brief Get value of SATAPHY_CLOCK_SEL_STAT_MPLL_SS_SEL from a register value.
#define BG_SATAPHY_CLOCK_SEL_STAT_MPLL_SS_SEL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_SEL_STAT_MPLL_SS_SEL) >> BP_SATAPHY_CLOCK_SEL_STAT_MPLL_SS_SEL)

/* --- Register HW_SATAPHY_CLOCK_SEL_STAT, field REF_CLK_SEL[9:2] (RO)
 *
 * Reference clock select input
 */

#define BP_SATAPHY_CLOCK_SEL_STAT_REF_CLK_SEL      (2)      //!< Bit position for SATAPHY_CLOCK_SEL_STAT_REF_CLK_SEL.
#define BM_SATAPHY_CLOCK_SEL_STAT_REF_CLK_SEL      (0x000003fc)  //!< Bit mask for SATAPHY_CLOCK_SEL_STAT_REF_CLK_SEL.

//! @brief Get value of SATAPHY_CLOCK_SEL_STAT_REF_CLK_SEL from a register value.
#define BG_SATAPHY_CLOCK_SEL_STAT_REF_CLK_SEL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_SEL_STAT_REF_CLK_SEL) >> BP_SATAPHY_CLOCK_SEL_STAT_REF_CLK_SEL)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_SEL_OVRD - Clock Select Override Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_SEL_OVRD - Clock Select Override Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x001A  Reset value: 16'b0000 0000 0000 0000  This register contains the clock select
 * override, the ref_clk_sel override value, and the mpll_ss_sel override value.
 */
typedef union _hw_sataphy_clock_sel_ovrd
{
    reg16_t U;
    struct _hw_sataphy_clock_sel_ovrd_bitfields
    {
        unsigned short MPLL_SS_SEL : 2; //!< [1:0] MPLL spread spectrum select
        unsigned short REF_CLK_SEL : 8; //!< [9:2] Reference clock select
        unsigned short CLK_SEL_OVRD : 1; //!< [10] Override control, indicating that the overridden value is active
        unsigned short RESERVED0 : 5; //!< [15:11] Reserved
    } B;
} hw_sataphy_clock_sel_ovrd_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_SEL_OVRD register
 */
#define HW_SATAPHY_CLOCK_SEL_OVRD_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x1a)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_SEL_OVRD           (*(volatile hw_sataphy_clock_sel_ovrd_t *) HW_SATAPHY_CLOCK_SEL_OVRD_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_SEL_OVRD bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_SEL_OVRD, field MPLL_SS_SEL[1:0] (RW)
 *
 * MPLL spread spectrum select
 */

#define BP_SATAPHY_CLOCK_SEL_OVRD_MPLL_SS_SEL      (0)      //!< Bit position for SATAPHY_CLOCK_SEL_OVRD_MPLL_SS_SEL.
#define BM_SATAPHY_CLOCK_SEL_OVRD_MPLL_SS_SEL      (0x00000003)  //!< Bit mask for SATAPHY_CLOCK_SEL_OVRD_MPLL_SS_SEL.

//! @brief Get value of SATAPHY_CLOCK_SEL_OVRD_MPLL_SS_SEL from a register value.
#define BG_SATAPHY_CLOCK_SEL_OVRD_MPLL_SS_SEL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_SEL_OVRD_MPLL_SS_SEL) >> BP_SATAPHY_CLOCK_SEL_OVRD_MPLL_SS_SEL)

//! @brief Format value for bitfield SATAPHY_CLOCK_SEL_OVRD_MPLL_SS_SEL.
#define BF_SATAPHY_CLOCK_SEL_OVRD_MPLL_SS_SEL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_SEL_OVRD_MPLL_SS_SEL) & BM_SATAPHY_CLOCK_SEL_OVRD_MPLL_SS_SEL)

/* --- Register HW_SATAPHY_CLOCK_SEL_OVRD, field REF_CLK_SEL[9:2] (RW)
 *
 * Reference clock select
 */

#define BP_SATAPHY_CLOCK_SEL_OVRD_REF_CLK_SEL      (2)      //!< Bit position for SATAPHY_CLOCK_SEL_OVRD_REF_CLK_SEL.
#define BM_SATAPHY_CLOCK_SEL_OVRD_REF_CLK_SEL      (0x000003fc)  //!< Bit mask for SATAPHY_CLOCK_SEL_OVRD_REF_CLK_SEL.

//! @brief Get value of SATAPHY_CLOCK_SEL_OVRD_REF_CLK_SEL from a register value.
#define BG_SATAPHY_CLOCK_SEL_OVRD_REF_CLK_SEL(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_SEL_OVRD_REF_CLK_SEL) >> BP_SATAPHY_CLOCK_SEL_OVRD_REF_CLK_SEL)

//! @brief Format value for bitfield SATAPHY_CLOCK_SEL_OVRD_REF_CLK_SEL.
#define BF_SATAPHY_CLOCK_SEL_OVRD_REF_CLK_SEL(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_SEL_OVRD_REF_CLK_SEL) & BM_SATAPHY_CLOCK_SEL_OVRD_REF_CLK_SEL)

/* --- Register HW_SATAPHY_CLOCK_SEL_OVRD, field CLK_SEL_OVRD[10] (RW)
 *
 * Override control, indicating that the overridden value is active
 */

#define BP_SATAPHY_CLOCK_SEL_OVRD_CLK_SEL_OVRD      (10)      //!< Bit position for SATAPHY_CLOCK_SEL_OVRD_CLK_SEL_OVRD.
#define BM_SATAPHY_CLOCK_SEL_OVRD_CLK_SEL_OVRD      (0x00000400)  //!< Bit mask for SATAPHY_CLOCK_SEL_OVRD_CLK_SEL_OVRD.

//! @brief Get value of SATAPHY_CLOCK_SEL_OVRD_CLK_SEL_OVRD from a register value.
#define BG_SATAPHY_CLOCK_SEL_OVRD_CLK_SEL_OVRD(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_SEL_OVRD_CLK_SEL_OVRD) >> BP_SATAPHY_CLOCK_SEL_OVRD_CLK_SEL_OVRD)

//! @brief Format value for bitfield SATAPHY_CLOCK_SEL_OVRD_CLK_SEL_OVRD.
#define BF_SATAPHY_CLOCK_SEL_OVRD_CLK_SEL_OVRD(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_SEL_OVRD_CLK_SEL_OVRD) & BM_SATAPHY_CLOCK_SEL_OVRD_CLK_SEL_OVRD)

//-------------------------------------------------------------------------------------------
// HW_SATAPHY_CLOCK_RESET - Reset Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATAPHY_CLOCK_RESET - Reset Register (WO)
 *
 * Reset value: 0x00000000
 *
 * Address: 0x7F3F  Reset value: 16'b xxxx xxxx xxxx xxx0  This register is a write-only register
 * (not a real register) that resets the SATA2 PHY.  Upon writing the PHY reset bit in the reset
 * register, the internal PHY reset is active immediately. Since the reset also affects the control
 * register state machine, there will not be an acknowledgement of the write; that is, cr_ack will
 * not be asserted.  Diagnostic code should treat the lack of an acknowledgment of the write as a
 * successful write; alternatively, it should treat the PHY acknowledging a write of the reset as a
 * write failure . This is the opposite expectation of all other registers, where the lack is a
 * failure and the acknowledge is successful.  It is sufficient to wait 20 ref_clock cycles in order
 * to determine that the acknowledgement has not occurred.
 */
typedef union _hw_sataphy_clock_reset
{
    reg16_t U;
    struct _hw_sataphy_clock_reset_bitfields
    {
        unsigned short RESET : 1; //!< [0] Writing a 1 to this field resets the SATA2 PHY.
        unsigned short RESERVED0 : 15; //!< [15:1] Reserved
    } B;
} hw_sataphy_clock_reset_t;
#endif

/*
 * constants & macros for entire SATAPHY_CLOCK_RESET register
 */
#define HW_SATAPHY_CLOCK_RESET_ADDR      (REGS_SATAPHY_CLOCK_BASE + 0x7f3f)

#ifndef __LANGUAGE_ASM__
#define HW_SATAPHY_CLOCK_RESET           (*(volatile hw_sataphy_clock_reset_t *) HW_SATAPHY_CLOCK_RESET_ADDR)
#endif

/*
 * constants & macros for individual SATAPHY_CLOCK_RESET bitfields
 */

/* --- Register HW_SATAPHY_CLOCK_RESET, field RESET[0] (WO)
 *
 * Writing a 1 to this field resets the SATA2 PHY.
 */

#define BP_SATAPHY_CLOCK_RESET_RESET      (0)      //!< Bit position for SATAPHY_CLOCK_RESET_RESET.
#define BM_SATAPHY_CLOCK_RESET_RESET      (0x00000001)  //!< Bit mask for SATAPHY_CLOCK_RESET_RESET.

//! @brief Get value of SATAPHY_CLOCK_RESET_RESET from a register value.
#define BG_SATAPHY_CLOCK_RESET_RESET(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_SATAPHY_CLOCK_RESET_RESET) >> BP_SATAPHY_CLOCK_RESET_RESET)

//! @brief Format value for bitfield SATAPHY_CLOCK_RESET_RESET.
#define BF_SATAPHY_CLOCK_RESET_RESET(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_SATAPHY_CLOCK_RESET_RESET) & BM_SATAPHY_CLOCK_RESET_RESET)



#endif // __HW_SATAPHY_CLOCK_REGISTERS_H__
