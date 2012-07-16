/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_ROMC_REGISTERS_H__
#define __HW_ROMC_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6SL ROMC registers defined in this header file.
 *
 * - HW_ROMC_ROMPATCH0D - ROMC Data Registers
 * - HW_ROMC_ROMPATCH1D - ROMC Data Registers
 * - HW_ROMC_ROMPATCH2D - ROMC Data Registers
 * - HW_ROMC_ROMPATCH3D - ROMC Data Registers
 * - HW_ROMC_ROMPATCH4D - ROMC Data Registers
 * - HW_ROMC_ROMPATCH5D - ROMC Data Registers
 * - HW_ROMC_ROMPATCH6D - ROMC Data Registers
 * - HW_ROMC_ROMPATCH7D - ROMC Data Registers
 * - HW_ROMC_ROMPATCHCNTL - ROMC Control Register
 * - HW_ROMC_ROMPATCHENH - ROMC Enable Register High
 * - HW_ROMC_ROMPATCHENL - ROMC Enable Register Low
 * - HW_ROMC_ROMPATCH0A - ROMC Address Registers
 * - HW_ROMC_ROMPATCH1A - ROMC Address Registers
 * - HW_ROMC_ROMPATCH2A - ROMC Address Registers
 * - HW_ROMC_ROMPATCH3A - ROMC Address Registers
 * - HW_ROMC_ROMPATCH4A - ROMC Address Registers
 * - HW_ROMC_ROMPATCH5A - ROMC Address Registers
 * - HW_ROMC_ROMPATCH6A - ROMC Address Registers
 * - HW_ROMC_ROMPATCH7A - ROMC Address Registers
 * - HW_ROMC_ROMPATCH8A - ROMC Address Registers
 * - HW_ROMC_ROMPATCH9A - ROMC Address Registers
 * - HW_ROMC_ROMPATCH10A - ROMC Address Registers
 * - HW_ROMC_ROMPATCH11A - ROMC Address Registers
 * - HW_ROMC_ROMPATCH12A - ROMC Address Registers
 * - HW_ROMC_ROMPATCH13A - ROMC Address Registers
 * - HW_ROMC_ROMPATCH14A - ROMC Address Registers
 * - HW_ROMC_ROMPATCH15A - ROMC Address Registers
 * - HW_ROMC_ROMPATCHSR - ROMC Status Register
 *
 * - hw_romc_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_ROMC_BASE
#define HW_ROMC_INSTANCE_COUNT (1) //!< Number of instances of the ROMC module.
#define REGS_ROMC_BASE (0x021ac000) //!< Base address for ROMC.
#endif
//@}


//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH0D - ROMC Data Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH0D - ROMC Data Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC data registers (ROMC_ROMPATCHD7 through ROMC_ROMPATCHD0) store the data to use for the 8
 * 1-word data fix events. Each register is associated with an address comparator (7 through 0).
 * When a data fixing event occurs, the value in the data register corresponding to the comparator
 * that has the address match is put on the romc_hrdata[31:0] bus until romc_hready is asserted by
 * the ROM controller to terminate the access. A MUX external to the ROMC will select this data over
 * that of romc_hrdata[31:0] in returning read data to the ARM core. The selection is done with the
 * control bus rompatch_romc_hrdata_ovr[1:0] with both bits asserted by the ROMC.  If more than one
 * address comparators match, the highest-numbered one takes precedence, and the value in
 * corresponding data register is used for the patching event.
 */
typedef union _hw_romc_rompatch0d
{
    reg32_t U;
    struct _hw_romc_rompatch0d_bitfields
    {
        unsigned DATAX : 32; //!< [31:0] Data Fix Registers - Stores the data used for 1-word data fix operations.
    } B;
} hw_romc_rompatch0d_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH0D register
 */
#define HW_ROMC_ROMPATCH0D_ADDR      (REGS_ROMC_BASE + 0xd4)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH0D           (*(volatile hw_romc_rompatch0d_t *) HW_ROMC_ROMPATCH0D_ADDR)
#define HW_ROMC_ROMPATCH0D_RD()      (HW_ROMC_ROMPATCH0D.U)
#define HW_ROMC_ROMPATCH0D_WR(v)     (HW_ROMC_ROMPATCH0D.U = (v))
#define HW_ROMC_ROMPATCH0D_SET(v)    (HW_ROMC_ROMPATCH0D_WR(HW_ROMC_ROMPATCH0D_RD() |  (v)))
#define HW_ROMC_ROMPATCH0D_CLR(v)    (HW_ROMC_ROMPATCH0D_WR(HW_ROMC_ROMPATCH0D_RD() & ~(v)))
#define HW_ROMC_ROMPATCH0D_TOG(v)    (HW_ROMC_ROMPATCH0D_WR(HW_ROMC_ROMPATCH0D_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH0D bitfields
 */

/* --- Register HW_ROMC_ROMPATCH0D, field DATAX[31:0] (RW)
 *
 * Data Fix Registers - Stores the data used for 1-word data fix operations. The values stored
 * within these registers do not affect the writes to the memory system. They are selected over the
 * read data from ROM when a data fix event occurs. If any part of the 1-word data fix is read, then
 * the entire word is replaced. Therefore, a byte or half-word read will cause the ROMC to replace
 * the entire word. The word is word address aligned.
 */

#define BP_ROMC_ROMPATCH0D_DATAX      (0)      //!< Bit position for ROMC_ROMPATCH0D_DATAX.
#define BM_ROMC_ROMPATCH0D_DATAX      (0xffffffff)  //!< Bit mask for ROMC_ROMPATCH0D_DATAX.

//! @brief Get value of ROMC_ROMPATCH0D_DATAX from a register value.
#define BG_ROMC_ROMPATCH0D_DATAX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH0D_DATAX) >> BP_ROMC_ROMPATCH0D_DATAX)

//! @brief Format value for bitfield ROMC_ROMPATCH0D_DATAX.
#define BF_ROMC_ROMPATCH0D_DATAX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH0D_DATAX) & BM_ROMC_ROMPATCH0D_DATAX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAX field to a new value.
#define BW_ROMC_ROMPATCH0D_DATAX(v)   (HW_ROMC_ROMPATCH0D_WR((HW_ROMC_ROMPATCH0D_RD() & ~BM_ROMC_ROMPATCH0D_DATAX) | BF_ROMC_ROMPATCH0D_DATAX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH1D - ROMC Data Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH1D - ROMC Data Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC data registers (ROMC_ROMPATCHD7 through ROMC_ROMPATCHD0) store the data to use for the 8
 * 1-word data fix events. Each register is associated with an address comparator (7 through 0).
 * When a data fixing event occurs, the value in the data register corresponding to the comparator
 * that has the address match is put on the romc_hrdata[31:0] bus until romc_hready is asserted by
 * the ROM controller to terminate the access. A MUX external to the ROMC will select this data over
 * that of romc_hrdata[31:0] in returning read data to the ARM core. The selection is done with the
 * control bus rompatch_romc_hrdata_ovr[1:0] with both bits asserted by the ROMC.  If more than one
 * address comparators match, the highest-numbered one takes precedence, and the value in
 * corresponding data register is used for the patching event.
 */
typedef union _hw_romc_rompatch1d
{
    reg32_t U;
    struct _hw_romc_rompatch1d_bitfields
    {
        unsigned DATAX : 32; //!< [31:0] Data Fix Registers - Stores the data used for 1-word data fix operations.
    } B;
} hw_romc_rompatch1d_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH1D register
 */
#define HW_ROMC_ROMPATCH1D_ADDR      (REGS_ROMC_BASE + 0xd8)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH1D           (*(volatile hw_romc_rompatch1d_t *) HW_ROMC_ROMPATCH1D_ADDR)
#define HW_ROMC_ROMPATCH1D_RD()      (HW_ROMC_ROMPATCH1D.U)
#define HW_ROMC_ROMPATCH1D_WR(v)     (HW_ROMC_ROMPATCH1D.U = (v))
#define HW_ROMC_ROMPATCH1D_SET(v)    (HW_ROMC_ROMPATCH1D_WR(HW_ROMC_ROMPATCH1D_RD() |  (v)))
#define HW_ROMC_ROMPATCH1D_CLR(v)    (HW_ROMC_ROMPATCH1D_WR(HW_ROMC_ROMPATCH1D_RD() & ~(v)))
#define HW_ROMC_ROMPATCH1D_TOG(v)    (HW_ROMC_ROMPATCH1D_WR(HW_ROMC_ROMPATCH1D_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH1D bitfields
 */

/* --- Register HW_ROMC_ROMPATCH1D, field DATAX[31:0] (RW)
 *
 * Data Fix Registers - Stores the data used for 1-word data fix operations. The values stored
 * within these registers do not affect the writes to the memory system. They are selected over the
 * read data from ROM when a data fix event occurs. If any part of the 1-word data fix is read, then
 * the entire word is replaced. Therefore, a byte or half-word read will cause the ROMC to replace
 * the entire word. The word is word address aligned.
 */

#define BP_ROMC_ROMPATCH1D_DATAX      (0)      //!< Bit position for ROMC_ROMPATCH1D_DATAX.
#define BM_ROMC_ROMPATCH1D_DATAX      (0xffffffff)  //!< Bit mask for ROMC_ROMPATCH1D_DATAX.

//! @brief Get value of ROMC_ROMPATCH1D_DATAX from a register value.
#define BG_ROMC_ROMPATCH1D_DATAX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH1D_DATAX) >> BP_ROMC_ROMPATCH1D_DATAX)

//! @brief Format value for bitfield ROMC_ROMPATCH1D_DATAX.
#define BF_ROMC_ROMPATCH1D_DATAX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH1D_DATAX) & BM_ROMC_ROMPATCH1D_DATAX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAX field to a new value.
#define BW_ROMC_ROMPATCH1D_DATAX(v)   (HW_ROMC_ROMPATCH1D_WR((HW_ROMC_ROMPATCH1D_RD() & ~BM_ROMC_ROMPATCH1D_DATAX) | BF_ROMC_ROMPATCH1D_DATAX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH2D - ROMC Data Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH2D - ROMC Data Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC data registers (ROMC_ROMPATCHD7 through ROMC_ROMPATCHD0) store the data to use for the 8
 * 1-word data fix events. Each register is associated with an address comparator (7 through 0).
 * When a data fixing event occurs, the value in the data register corresponding to the comparator
 * that has the address match is put on the romc_hrdata[31:0] bus until romc_hready is asserted by
 * the ROM controller to terminate the access. A MUX external to the ROMC will select this data over
 * that of romc_hrdata[31:0] in returning read data to the ARM core. The selection is done with the
 * control bus rompatch_romc_hrdata_ovr[1:0] with both bits asserted by the ROMC.  If more than one
 * address comparators match, the highest-numbered one takes precedence, and the value in
 * corresponding data register is used for the patching event.
 */
typedef union _hw_romc_rompatch2d
{
    reg32_t U;
    struct _hw_romc_rompatch2d_bitfields
    {
        unsigned DATAX : 32; //!< [31:0] Data Fix Registers - Stores the data used for 1-word data fix operations.
    } B;
} hw_romc_rompatch2d_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH2D register
 */
#define HW_ROMC_ROMPATCH2D_ADDR      (REGS_ROMC_BASE + 0xdc)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH2D           (*(volatile hw_romc_rompatch2d_t *) HW_ROMC_ROMPATCH2D_ADDR)
#define HW_ROMC_ROMPATCH2D_RD()      (HW_ROMC_ROMPATCH2D.U)
#define HW_ROMC_ROMPATCH2D_WR(v)     (HW_ROMC_ROMPATCH2D.U = (v))
#define HW_ROMC_ROMPATCH2D_SET(v)    (HW_ROMC_ROMPATCH2D_WR(HW_ROMC_ROMPATCH2D_RD() |  (v)))
#define HW_ROMC_ROMPATCH2D_CLR(v)    (HW_ROMC_ROMPATCH2D_WR(HW_ROMC_ROMPATCH2D_RD() & ~(v)))
#define HW_ROMC_ROMPATCH2D_TOG(v)    (HW_ROMC_ROMPATCH2D_WR(HW_ROMC_ROMPATCH2D_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH2D bitfields
 */

/* --- Register HW_ROMC_ROMPATCH2D, field DATAX[31:0] (RW)
 *
 * Data Fix Registers - Stores the data used for 1-word data fix operations. The values stored
 * within these registers do not affect the writes to the memory system. They are selected over the
 * read data from ROM when a data fix event occurs. If any part of the 1-word data fix is read, then
 * the entire word is replaced. Therefore, a byte or half-word read will cause the ROMC to replace
 * the entire word. The word is word address aligned.
 */

#define BP_ROMC_ROMPATCH2D_DATAX      (0)      //!< Bit position for ROMC_ROMPATCH2D_DATAX.
#define BM_ROMC_ROMPATCH2D_DATAX      (0xffffffff)  //!< Bit mask for ROMC_ROMPATCH2D_DATAX.

//! @brief Get value of ROMC_ROMPATCH2D_DATAX from a register value.
#define BG_ROMC_ROMPATCH2D_DATAX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH2D_DATAX) >> BP_ROMC_ROMPATCH2D_DATAX)

//! @brief Format value for bitfield ROMC_ROMPATCH2D_DATAX.
#define BF_ROMC_ROMPATCH2D_DATAX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH2D_DATAX) & BM_ROMC_ROMPATCH2D_DATAX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAX field to a new value.
#define BW_ROMC_ROMPATCH2D_DATAX(v)   (HW_ROMC_ROMPATCH2D_WR((HW_ROMC_ROMPATCH2D_RD() & ~BM_ROMC_ROMPATCH2D_DATAX) | BF_ROMC_ROMPATCH2D_DATAX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH3D - ROMC Data Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH3D - ROMC Data Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC data registers (ROMC_ROMPATCHD7 through ROMC_ROMPATCHD0) store the data to use for the 8
 * 1-word data fix events. Each register is associated with an address comparator (7 through 0).
 * When a data fixing event occurs, the value in the data register corresponding to the comparator
 * that has the address match is put on the romc_hrdata[31:0] bus until romc_hready is asserted by
 * the ROM controller to terminate the access. A MUX external to the ROMC will select this data over
 * that of romc_hrdata[31:0] in returning read data to the ARM core. The selection is done with the
 * control bus rompatch_romc_hrdata_ovr[1:0] with both bits asserted by the ROMC.  If more than one
 * address comparators match, the highest-numbered one takes precedence, and the value in
 * corresponding data register is used for the patching event.
 */
typedef union _hw_romc_rompatch3d
{
    reg32_t U;
    struct _hw_romc_rompatch3d_bitfields
    {
        unsigned DATAX : 32; //!< [31:0] Data Fix Registers - Stores the data used for 1-word data fix operations.
    } B;
} hw_romc_rompatch3d_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH3D register
 */
#define HW_ROMC_ROMPATCH3D_ADDR      (REGS_ROMC_BASE + 0xe0)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH3D           (*(volatile hw_romc_rompatch3d_t *) HW_ROMC_ROMPATCH3D_ADDR)
#define HW_ROMC_ROMPATCH3D_RD()      (HW_ROMC_ROMPATCH3D.U)
#define HW_ROMC_ROMPATCH3D_WR(v)     (HW_ROMC_ROMPATCH3D.U = (v))
#define HW_ROMC_ROMPATCH3D_SET(v)    (HW_ROMC_ROMPATCH3D_WR(HW_ROMC_ROMPATCH3D_RD() |  (v)))
#define HW_ROMC_ROMPATCH3D_CLR(v)    (HW_ROMC_ROMPATCH3D_WR(HW_ROMC_ROMPATCH3D_RD() & ~(v)))
#define HW_ROMC_ROMPATCH3D_TOG(v)    (HW_ROMC_ROMPATCH3D_WR(HW_ROMC_ROMPATCH3D_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH3D bitfields
 */

/* --- Register HW_ROMC_ROMPATCH3D, field DATAX[31:0] (RW)
 *
 * Data Fix Registers - Stores the data used for 1-word data fix operations. The values stored
 * within these registers do not affect the writes to the memory system. They are selected over the
 * read data from ROM when a data fix event occurs. If any part of the 1-word data fix is read, then
 * the entire word is replaced. Therefore, a byte or half-word read will cause the ROMC to replace
 * the entire word. The word is word address aligned.
 */

#define BP_ROMC_ROMPATCH3D_DATAX      (0)      //!< Bit position for ROMC_ROMPATCH3D_DATAX.
#define BM_ROMC_ROMPATCH3D_DATAX      (0xffffffff)  //!< Bit mask for ROMC_ROMPATCH3D_DATAX.

//! @brief Get value of ROMC_ROMPATCH3D_DATAX from a register value.
#define BG_ROMC_ROMPATCH3D_DATAX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH3D_DATAX) >> BP_ROMC_ROMPATCH3D_DATAX)

//! @brief Format value for bitfield ROMC_ROMPATCH3D_DATAX.
#define BF_ROMC_ROMPATCH3D_DATAX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH3D_DATAX) & BM_ROMC_ROMPATCH3D_DATAX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAX field to a new value.
#define BW_ROMC_ROMPATCH3D_DATAX(v)   (HW_ROMC_ROMPATCH3D_WR((HW_ROMC_ROMPATCH3D_RD() & ~BM_ROMC_ROMPATCH3D_DATAX) | BF_ROMC_ROMPATCH3D_DATAX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH4D - ROMC Data Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH4D - ROMC Data Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC data registers (ROMC_ROMPATCHD7 through ROMC_ROMPATCHD0) store the data to use for the 8
 * 1-word data fix events. Each register is associated with an address comparator (7 through 0).
 * When a data fixing event occurs, the value in the data register corresponding to the comparator
 * that has the address match is put on the romc_hrdata[31:0] bus until romc_hready is asserted by
 * the ROM controller to terminate the access. A MUX external to the ROMC will select this data over
 * that of romc_hrdata[31:0] in returning read data to the ARM core. The selection is done with the
 * control bus rompatch_romc_hrdata_ovr[1:0] with both bits asserted by the ROMC.  If more than one
 * address comparators match, the highest-numbered one takes precedence, and the value in
 * corresponding data register is used for the patching event.
 */
typedef union _hw_romc_rompatch4d
{
    reg32_t U;
    struct _hw_romc_rompatch4d_bitfields
    {
        unsigned DATAX : 32; //!< [31:0] Data Fix Registers - Stores the data used for 1-word data fix operations.
    } B;
} hw_romc_rompatch4d_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH4D register
 */
#define HW_ROMC_ROMPATCH4D_ADDR      (REGS_ROMC_BASE + 0xe4)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH4D           (*(volatile hw_romc_rompatch4d_t *) HW_ROMC_ROMPATCH4D_ADDR)
#define HW_ROMC_ROMPATCH4D_RD()      (HW_ROMC_ROMPATCH4D.U)
#define HW_ROMC_ROMPATCH4D_WR(v)     (HW_ROMC_ROMPATCH4D.U = (v))
#define HW_ROMC_ROMPATCH4D_SET(v)    (HW_ROMC_ROMPATCH4D_WR(HW_ROMC_ROMPATCH4D_RD() |  (v)))
#define HW_ROMC_ROMPATCH4D_CLR(v)    (HW_ROMC_ROMPATCH4D_WR(HW_ROMC_ROMPATCH4D_RD() & ~(v)))
#define HW_ROMC_ROMPATCH4D_TOG(v)    (HW_ROMC_ROMPATCH4D_WR(HW_ROMC_ROMPATCH4D_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH4D bitfields
 */

/* --- Register HW_ROMC_ROMPATCH4D, field DATAX[31:0] (RW)
 *
 * Data Fix Registers - Stores the data used for 1-word data fix operations. The values stored
 * within these registers do not affect the writes to the memory system. They are selected over the
 * read data from ROM when a data fix event occurs. If any part of the 1-word data fix is read, then
 * the entire word is replaced. Therefore, a byte or half-word read will cause the ROMC to replace
 * the entire word. The word is word address aligned.
 */

#define BP_ROMC_ROMPATCH4D_DATAX      (0)      //!< Bit position for ROMC_ROMPATCH4D_DATAX.
#define BM_ROMC_ROMPATCH4D_DATAX      (0xffffffff)  //!< Bit mask for ROMC_ROMPATCH4D_DATAX.

//! @brief Get value of ROMC_ROMPATCH4D_DATAX from a register value.
#define BG_ROMC_ROMPATCH4D_DATAX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH4D_DATAX) >> BP_ROMC_ROMPATCH4D_DATAX)

//! @brief Format value for bitfield ROMC_ROMPATCH4D_DATAX.
#define BF_ROMC_ROMPATCH4D_DATAX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH4D_DATAX) & BM_ROMC_ROMPATCH4D_DATAX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAX field to a new value.
#define BW_ROMC_ROMPATCH4D_DATAX(v)   (HW_ROMC_ROMPATCH4D_WR((HW_ROMC_ROMPATCH4D_RD() & ~BM_ROMC_ROMPATCH4D_DATAX) | BF_ROMC_ROMPATCH4D_DATAX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH5D - ROMC Data Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH5D - ROMC Data Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC data registers (ROMC_ROMPATCHD7 through ROMC_ROMPATCHD0) store the data to use for the 8
 * 1-word data fix events. Each register is associated with an address comparator (7 through 0).
 * When a data fixing event occurs, the value in the data register corresponding to the comparator
 * that has the address match is put on the romc_hrdata[31:0] bus until romc_hready is asserted by
 * the ROM controller to terminate the access. A MUX external to the ROMC will select this data over
 * that of romc_hrdata[31:0] in returning read data to the ARM core. The selection is done with the
 * control bus rompatch_romc_hrdata_ovr[1:0] with both bits asserted by the ROMC.  If more than one
 * address comparators match, the highest-numbered one takes precedence, and the value in
 * corresponding data register is used for the patching event.
 */
typedef union _hw_romc_rompatch5d
{
    reg32_t U;
    struct _hw_romc_rompatch5d_bitfields
    {
        unsigned DATAX : 32; //!< [31:0] Data Fix Registers - Stores the data used for 1-word data fix operations.
    } B;
} hw_romc_rompatch5d_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH5D register
 */
#define HW_ROMC_ROMPATCH5D_ADDR      (REGS_ROMC_BASE + 0xe8)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH5D           (*(volatile hw_romc_rompatch5d_t *) HW_ROMC_ROMPATCH5D_ADDR)
#define HW_ROMC_ROMPATCH5D_RD()      (HW_ROMC_ROMPATCH5D.U)
#define HW_ROMC_ROMPATCH5D_WR(v)     (HW_ROMC_ROMPATCH5D.U = (v))
#define HW_ROMC_ROMPATCH5D_SET(v)    (HW_ROMC_ROMPATCH5D_WR(HW_ROMC_ROMPATCH5D_RD() |  (v)))
#define HW_ROMC_ROMPATCH5D_CLR(v)    (HW_ROMC_ROMPATCH5D_WR(HW_ROMC_ROMPATCH5D_RD() & ~(v)))
#define HW_ROMC_ROMPATCH5D_TOG(v)    (HW_ROMC_ROMPATCH5D_WR(HW_ROMC_ROMPATCH5D_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH5D bitfields
 */

/* --- Register HW_ROMC_ROMPATCH5D, field DATAX[31:0] (RW)
 *
 * Data Fix Registers - Stores the data used for 1-word data fix operations. The values stored
 * within these registers do not affect the writes to the memory system. They are selected over the
 * read data from ROM when a data fix event occurs. If any part of the 1-word data fix is read, then
 * the entire word is replaced. Therefore, a byte or half-word read will cause the ROMC to replace
 * the entire word. The word is word address aligned.
 */

#define BP_ROMC_ROMPATCH5D_DATAX      (0)      //!< Bit position for ROMC_ROMPATCH5D_DATAX.
#define BM_ROMC_ROMPATCH5D_DATAX      (0xffffffff)  //!< Bit mask for ROMC_ROMPATCH5D_DATAX.

//! @brief Get value of ROMC_ROMPATCH5D_DATAX from a register value.
#define BG_ROMC_ROMPATCH5D_DATAX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH5D_DATAX) >> BP_ROMC_ROMPATCH5D_DATAX)

//! @brief Format value for bitfield ROMC_ROMPATCH5D_DATAX.
#define BF_ROMC_ROMPATCH5D_DATAX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH5D_DATAX) & BM_ROMC_ROMPATCH5D_DATAX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAX field to a new value.
#define BW_ROMC_ROMPATCH5D_DATAX(v)   (HW_ROMC_ROMPATCH5D_WR((HW_ROMC_ROMPATCH5D_RD() & ~BM_ROMC_ROMPATCH5D_DATAX) | BF_ROMC_ROMPATCH5D_DATAX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH6D - ROMC Data Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH6D - ROMC Data Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC data registers (ROMC_ROMPATCHD7 through ROMC_ROMPATCHD0) store the data to use for the 8
 * 1-word data fix events. Each register is associated with an address comparator (7 through 0).
 * When a data fixing event occurs, the value in the data register corresponding to the comparator
 * that has the address match is put on the romc_hrdata[31:0] bus until romc_hready is asserted by
 * the ROM controller to terminate the access. A MUX external to the ROMC will select this data over
 * that of romc_hrdata[31:0] in returning read data to the ARM core. The selection is done with the
 * control bus rompatch_romc_hrdata_ovr[1:0] with both bits asserted by the ROMC.  If more than one
 * address comparators match, the highest-numbered one takes precedence, and the value in
 * corresponding data register is used for the patching event.
 */
typedef union _hw_romc_rompatch6d
{
    reg32_t U;
    struct _hw_romc_rompatch6d_bitfields
    {
        unsigned DATAX : 32; //!< [31:0] Data Fix Registers - Stores the data used for 1-word data fix operations.
    } B;
} hw_romc_rompatch6d_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH6D register
 */
#define HW_ROMC_ROMPATCH6D_ADDR      (REGS_ROMC_BASE + 0xec)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH6D           (*(volatile hw_romc_rompatch6d_t *) HW_ROMC_ROMPATCH6D_ADDR)
#define HW_ROMC_ROMPATCH6D_RD()      (HW_ROMC_ROMPATCH6D.U)
#define HW_ROMC_ROMPATCH6D_WR(v)     (HW_ROMC_ROMPATCH6D.U = (v))
#define HW_ROMC_ROMPATCH6D_SET(v)    (HW_ROMC_ROMPATCH6D_WR(HW_ROMC_ROMPATCH6D_RD() |  (v)))
#define HW_ROMC_ROMPATCH6D_CLR(v)    (HW_ROMC_ROMPATCH6D_WR(HW_ROMC_ROMPATCH6D_RD() & ~(v)))
#define HW_ROMC_ROMPATCH6D_TOG(v)    (HW_ROMC_ROMPATCH6D_WR(HW_ROMC_ROMPATCH6D_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH6D bitfields
 */

/* --- Register HW_ROMC_ROMPATCH6D, field DATAX[31:0] (RW)
 *
 * Data Fix Registers - Stores the data used for 1-word data fix operations. The values stored
 * within these registers do not affect the writes to the memory system. They are selected over the
 * read data from ROM when a data fix event occurs. If any part of the 1-word data fix is read, then
 * the entire word is replaced. Therefore, a byte or half-word read will cause the ROMC to replace
 * the entire word. The word is word address aligned.
 */

#define BP_ROMC_ROMPATCH6D_DATAX      (0)      //!< Bit position for ROMC_ROMPATCH6D_DATAX.
#define BM_ROMC_ROMPATCH6D_DATAX      (0xffffffff)  //!< Bit mask for ROMC_ROMPATCH6D_DATAX.

//! @brief Get value of ROMC_ROMPATCH6D_DATAX from a register value.
#define BG_ROMC_ROMPATCH6D_DATAX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH6D_DATAX) >> BP_ROMC_ROMPATCH6D_DATAX)

//! @brief Format value for bitfield ROMC_ROMPATCH6D_DATAX.
#define BF_ROMC_ROMPATCH6D_DATAX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH6D_DATAX) & BM_ROMC_ROMPATCH6D_DATAX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAX field to a new value.
#define BW_ROMC_ROMPATCH6D_DATAX(v)   (HW_ROMC_ROMPATCH6D_WR((HW_ROMC_ROMPATCH6D_RD() & ~BM_ROMC_ROMPATCH6D_DATAX) | BF_ROMC_ROMPATCH6D_DATAX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH7D - ROMC Data Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH7D - ROMC Data Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC data registers (ROMC_ROMPATCHD7 through ROMC_ROMPATCHD0) store the data to use for the 8
 * 1-word data fix events. Each register is associated with an address comparator (7 through 0).
 * When a data fixing event occurs, the value in the data register corresponding to the comparator
 * that has the address match is put on the romc_hrdata[31:0] bus until romc_hready is asserted by
 * the ROM controller to terminate the access. A MUX external to the ROMC will select this data over
 * that of romc_hrdata[31:0] in returning read data to the ARM core. The selection is done with the
 * control bus rompatch_romc_hrdata_ovr[1:0] with both bits asserted by the ROMC.  If more than one
 * address comparators match, the highest-numbered one takes precedence, and the value in
 * corresponding data register is used for the patching event.
 */
typedef union _hw_romc_rompatch7d
{
    reg32_t U;
    struct _hw_romc_rompatch7d_bitfields
    {
        unsigned DATAX : 32; //!< [31:0] Data Fix Registers - Stores the data used for 1-word data fix operations.
    } B;
} hw_romc_rompatch7d_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH7D register
 */
#define HW_ROMC_ROMPATCH7D_ADDR      (REGS_ROMC_BASE + 0xf0)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH7D           (*(volatile hw_romc_rompatch7d_t *) HW_ROMC_ROMPATCH7D_ADDR)
#define HW_ROMC_ROMPATCH7D_RD()      (HW_ROMC_ROMPATCH7D.U)
#define HW_ROMC_ROMPATCH7D_WR(v)     (HW_ROMC_ROMPATCH7D.U = (v))
#define HW_ROMC_ROMPATCH7D_SET(v)    (HW_ROMC_ROMPATCH7D_WR(HW_ROMC_ROMPATCH7D_RD() |  (v)))
#define HW_ROMC_ROMPATCH7D_CLR(v)    (HW_ROMC_ROMPATCH7D_WR(HW_ROMC_ROMPATCH7D_RD() & ~(v)))
#define HW_ROMC_ROMPATCH7D_TOG(v)    (HW_ROMC_ROMPATCH7D_WR(HW_ROMC_ROMPATCH7D_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH7D bitfields
 */

/* --- Register HW_ROMC_ROMPATCH7D, field DATAX[31:0] (RW)
 *
 * Data Fix Registers - Stores the data used for 1-word data fix operations. The values stored
 * within these registers do not affect the writes to the memory system. They are selected over the
 * read data from ROM when a data fix event occurs. If any part of the 1-word data fix is read, then
 * the entire word is replaced. Therefore, a byte or half-word read will cause the ROMC to replace
 * the entire word. The word is word address aligned.
 */

#define BP_ROMC_ROMPATCH7D_DATAX      (0)      //!< Bit position for ROMC_ROMPATCH7D_DATAX.
#define BM_ROMC_ROMPATCH7D_DATAX      (0xffffffff)  //!< Bit mask for ROMC_ROMPATCH7D_DATAX.

//! @brief Get value of ROMC_ROMPATCH7D_DATAX from a register value.
#define BG_ROMC_ROMPATCH7D_DATAX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH7D_DATAX) >> BP_ROMC_ROMPATCH7D_DATAX)

//! @brief Format value for bitfield ROMC_ROMPATCH7D_DATAX.
#define BF_ROMC_ROMPATCH7D_DATAX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH7D_DATAX) & BM_ROMC_ROMPATCH7D_DATAX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAX field to a new value.
#define BW_ROMC_ROMPATCH7D_DATAX(v)   (HW_ROMC_ROMPATCH7D_WR((HW_ROMC_ROMPATCH7D_RD() & ~BM_ROMC_ROMPATCH7D_DATAX) | BF_ROMC_ROMPATCH7D_DATAX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCHCNTL - ROMC Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHCNTL - ROMC Control Register (RW)
 *
 * Reset value: 0x08400000
 *
 * The ROMC control register (ROMC_ROMPATCHCNTL) contains the block disable bit and the data fix
 * enable bits. The block disable bit provides a means to disable the ROMC data fix and opcode
 * patching functions, even when the address comparators are enabled. The External Boot feature is
 * not affected by this bit. The eight data fix enable bits (0 through 7), when set, assign the
 * associated address comparators to data fix operations  Bits 27 and 22 always read as 1s.
 */
typedef union _hw_romc_rompatchcntl
{
    reg32_t U;
    struct _hw_romc_rompatchcntl_bitfields
    {
        unsigned DATAFIX : 8; //!< [7:0] Data Fix Enable - Controls the use of the first 8 address comparators for 1-word data fix or for code patch routine.
        unsigned RESERVED0 : 21; //!< [28:8] Reserved
        unsigned DIS : 1; //!< [29] ROMC Disable -- This bit, when set, disables all ROMC operations.
        unsigned RESERVED1 : 2; //!< [31:30] Reserved
    } B;
} hw_romc_rompatchcntl_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHCNTL register
 */
#define HW_ROMC_ROMPATCHCNTL_ADDR      (REGS_ROMC_BASE + 0xf4)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHCNTL           (*(volatile hw_romc_rompatchcntl_t *) HW_ROMC_ROMPATCHCNTL_ADDR)
#define HW_ROMC_ROMPATCHCNTL_RD()      (HW_ROMC_ROMPATCHCNTL.U)
#define HW_ROMC_ROMPATCHCNTL_WR(v)     (HW_ROMC_ROMPATCHCNTL.U = (v))
#define HW_ROMC_ROMPATCHCNTL_SET(v)    (HW_ROMC_ROMPATCHCNTL_WR(HW_ROMC_ROMPATCHCNTL_RD() |  (v)))
#define HW_ROMC_ROMPATCHCNTL_CLR(v)    (HW_ROMC_ROMPATCHCNTL_WR(HW_ROMC_ROMPATCHCNTL_RD() & ~(v)))
#define HW_ROMC_ROMPATCHCNTL_TOG(v)    (HW_ROMC_ROMPATCHCNTL_WR(HW_ROMC_ROMPATCHCNTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHCNTL bitfields
 */

/* --- Register HW_ROMC_ROMPATCHCNTL, field DATAFIX[7:0] (RW)
 *
 * Data Fix Enable - Controls the use of the first 8 address comparators for 1-word data fix or for
 * code patch routine.
 *
 * Values:
 * 0 - Address comparator triggers a opcode patch
 * 1 - Address comparator triggers a data fix
 */

#define BP_ROMC_ROMPATCHCNTL_DATAFIX      (0)      //!< Bit position for ROMC_ROMPATCHCNTL_DATAFIX.
#define BM_ROMC_ROMPATCHCNTL_DATAFIX      (0x000000ff)  //!< Bit mask for ROMC_ROMPATCHCNTL_DATAFIX.

//! @brief Get value of ROMC_ROMPATCHCNTL_DATAFIX from a register value.
#define BG_ROMC_ROMPATCHCNTL_DATAFIX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCHCNTL_DATAFIX) >> BP_ROMC_ROMPATCHCNTL_DATAFIX)

//! @brief Format value for bitfield ROMC_ROMPATCHCNTL_DATAFIX.
#define BF_ROMC_ROMPATCHCNTL_DATAFIX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCHCNTL_DATAFIX) & BM_ROMC_ROMPATCHCNTL_DATAFIX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAFIX field to a new value.
#define BW_ROMC_ROMPATCHCNTL_DATAFIX(v)   (HW_ROMC_ROMPATCHCNTL_WR((HW_ROMC_ROMPATCHCNTL_RD() & ~BM_ROMC_ROMPATCHCNTL_DATAFIX) | BF_ROMC_ROMPATCHCNTL_DATAFIX(v)))
#endif


/* --- Register HW_ROMC_ROMPATCHCNTL, field DIS[29] (RW)
 *
 * ROMC Disable -- This bit, when set, disables all ROMC operations. This bit is used to enable
 * secure operations.
 *
 * Values:
 * 0 - Does not affect any ROMC functions (default)
 * 1 - Disable all ROMC functions: data fixing, and opcode patching
 */

#define BP_ROMC_ROMPATCHCNTL_DIS      (29)      //!< Bit position for ROMC_ROMPATCHCNTL_DIS.
#define BM_ROMC_ROMPATCHCNTL_DIS      (0x20000000)  //!< Bit mask for ROMC_ROMPATCHCNTL_DIS.

//! @brief Get value of ROMC_ROMPATCHCNTL_DIS from a register value.
#define BG_ROMC_ROMPATCHCNTL_DIS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCHCNTL_DIS) >> BP_ROMC_ROMPATCHCNTL_DIS)

//! @brief Format value for bitfield ROMC_ROMPATCHCNTL_DIS.
#define BF_ROMC_ROMPATCHCNTL_DIS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCHCNTL_DIS) & BM_ROMC_ROMPATCHCNTL_DIS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIS field to a new value.
#define BW_ROMC_ROMPATCHCNTL_DIS(v)   (HW_ROMC_ROMPATCHCNTL_WR((HW_ROMC_ROMPATCHCNTL_RD() & ~BM_ROMC_ROMPATCHCNTL_DIS) | BF_ROMC_ROMPATCHCNTL_DIS(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCHENH - ROMC Enable Register High
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHENH - ROMC Enable Register High (RO)
 *
 * Reset value: 0x00000000
 *
 * The ROMC enable register high (ROMC_ROMPATCHENH) and ROMC enable register low (ROMC_ROMPATCHENL)
 * control whether or not the associated address comparator can trigger a opcode patch or data fix
 * event. This implementation of the ROMC only has 16 comparators, therefore ROMC_ROMPATCHENH and
 * the upper half of ROMC_OMPATCHENL are read-only. ROMC_ROMPATCHENL[15:0] are associated with
 * comparators 15 through 0. ROMC_ROMPATCHENLH[31:0] would have been associated with comparators 63
 * through 32.
 */
typedef union _hw_romc_rompatchenh
{
    reg32_t U;
    struct _hw_romc_rompatchenh_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Reserved
    } B;
} hw_romc_rompatchenh_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHENH register
 */
#define HW_ROMC_ROMPATCHENH_ADDR      (REGS_ROMC_BASE + 0xf8)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHENH           (*(volatile hw_romc_rompatchenh_t *) HW_ROMC_ROMPATCHENH_ADDR)
#define HW_ROMC_ROMPATCHENH_RD()      (HW_ROMC_ROMPATCHENH.U)
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHENH bitfields
 */

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCHENL - ROMC Enable Register Low
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHENL - ROMC Enable Register Low (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC enable register high (ROMC_ROMPATCHENH) and ROMC enable register low (ROMC_ROMPATCHENL)
 * control whether or not the associated address comparator can trigger a opcode patch or data fix
 * event. This implementation of the ROMC only has 16 comparators, therefore ROMC_ROMPATCHENH and
 * the upper half of ROMC_ROMPATCHENL are read-only. ROMC_ROMPATCHENL[15:0] are associated with
 * comparators 15 through 0. ROMC_ROMPATCHENLH[31:0] would have been associated with comparators 63
 * through 32.
 */
typedef union _hw_romc_rompatchenl
{
    reg32_t U;
    struct _hw_romc_rompatchenl_bitfields
    {
        unsigned ENABLE : 16; //!< [15:0] Enable Address Comparator - This bit enables the corresponding address comparator to trigger an event.
        unsigned RESERVED0 : 16; //!< [31:16] 
    } B;
} hw_romc_rompatchenl_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHENL register
 */
#define HW_ROMC_ROMPATCHENL_ADDR      (REGS_ROMC_BASE + 0xfc)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHENL           (*(volatile hw_romc_rompatchenl_t *) HW_ROMC_ROMPATCHENL_ADDR)
#define HW_ROMC_ROMPATCHENL_RD()      (HW_ROMC_ROMPATCHENL.U)
#define HW_ROMC_ROMPATCHENL_WR(v)     (HW_ROMC_ROMPATCHENL.U = (v))
#define HW_ROMC_ROMPATCHENL_SET(v)    (HW_ROMC_ROMPATCHENL_WR(HW_ROMC_ROMPATCHENL_RD() |  (v)))
#define HW_ROMC_ROMPATCHENL_CLR(v)    (HW_ROMC_ROMPATCHENL_WR(HW_ROMC_ROMPATCHENL_RD() & ~(v)))
#define HW_ROMC_ROMPATCHENL_TOG(v)    (HW_ROMC_ROMPATCHENL_WR(HW_ROMC_ROMPATCHENL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHENL bitfields
 */

/* --- Register HW_ROMC_ROMPATCHENL, field ENABLE[15:0] (RW)
 *
 * Enable Address Comparator - This bit enables the corresponding address comparator to trigger an
 * event.
 *
 * Values:
 * 0 - Address comparator disabled
 * 1 - Address comparator enabled, ROMC will trigger a opcode patch or data fix event upon matching of the
 *     associated address
 */

#define BP_ROMC_ROMPATCHENL_ENABLE      (0)      //!< Bit position for ROMC_ROMPATCHENL_ENABLE.
#define BM_ROMC_ROMPATCHENL_ENABLE      (0x0000ffff)  //!< Bit mask for ROMC_ROMPATCHENL_ENABLE.

//! @brief Get value of ROMC_ROMPATCHENL_ENABLE from a register value.
#define BG_ROMC_ROMPATCHENL_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCHENL_ENABLE) >> BP_ROMC_ROMPATCHENL_ENABLE)

//! @brief Format value for bitfield ROMC_ROMPATCHENL_ENABLE.
#define BF_ROMC_ROMPATCHENL_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCHENL_ENABLE) & BM_ROMC_ROMPATCHENL_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_ROMC_ROMPATCHENL_ENABLE(v)   (HW_ROMC_ROMPATCHENL_WR((HW_ROMC_ROMPATCHENL_RD() & ~BM_ROMC_ROMPATCHENL_ENABLE) | BF_ROMC_ROMPATCHENL_ENABLE(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH0A - ROMC Address Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH0A - ROMC Address Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC address registers (ROMC_ROMPATCHA0 through ROMC_ROMPATCHA15) store the memory addresses
 * where opcode patching begins and data fixing occurs. The address registers ROMC_ROMPATCHA0
 * through ROMC_ROMPATCHA15 are each 21 bits wide and dedicated to one 4 Mbyte memory space. Bits 21
 * through 2 are address bits, to be compared with romc_haddr[21:2] for a match; bit 1 is also an
 * address bit used for half word selection. Bit 0 is the mode bit (set to 1 for THUMB mode). 1-word
 * data fixing can only be used on the first 8 of the address comparators. ROMC_ROMPATCHA0 through
 * ROMC_ROMPATCHA15 are associated each with address comparators 0 through 15.
 */
typedef union _hw_romc_rompatch0a
{
    reg32_t U;
    struct _hw_romc_rompatch0a_bitfields
    {
        unsigned THUMBX : 1; //!< [0] THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM opcode patch.
        unsigned ADDRX : 22; //!< [22:1] Address Comparator Registers - Indicates the memory address to be watched.
        unsigned RESERVED0 : 9; //!< [31:23] Reserved
    } B;
} hw_romc_rompatch0a_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH0A register
 */
#define HW_ROMC_ROMPATCH0A_ADDR      (REGS_ROMC_BASE + 0x100)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH0A           (*(volatile hw_romc_rompatch0a_t *) HW_ROMC_ROMPATCH0A_ADDR)
#define HW_ROMC_ROMPATCH0A_RD()      (HW_ROMC_ROMPATCH0A.U)
#define HW_ROMC_ROMPATCH0A_WR(v)     (HW_ROMC_ROMPATCH0A.U = (v))
#define HW_ROMC_ROMPATCH0A_SET(v)    (HW_ROMC_ROMPATCH0A_WR(HW_ROMC_ROMPATCH0A_RD() |  (v)))
#define HW_ROMC_ROMPATCH0A_CLR(v)    (HW_ROMC_ROMPATCH0A_WR(HW_ROMC_ROMPATCH0A_RD() & ~(v)))
#define HW_ROMC_ROMPATCH0A_TOG(v)    (HW_ROMC_ROMPATCH0A_WR(HW_ROMC_ROMPATCH0A_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH0A bitfields
 */

/* --- Register HW_ROMC_ROMPATCH0A, field THUMBX[0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCH0A_THUMBX      (0)      //!< Bit position for ROMC_ROMPATCH0A_THUMBX.
#define BM_ROMC_ROMPATCH0A_THUMBX      (0x00000001)  //!< Bit mask for ROMC_ROMPATCH0A_THUMBX.

//! @brief Get value of ROMC_ROMPATCH0A_THUMBX from a register value.
#define BG_ROMC_ROMPATCH0A_THUMBX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH0A_THUMBX) >> BP_ROMC_ROMPATCH0A_THUMBX)

//! @brief Format value for bitfield ROMC_ROMPATCH0A_THUMBX.
#define BF_ROMC_ROMPATCH0A_THUMBX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH0A_THUMBX) & BM_ROMC_ROMPATCH0A_THUMBX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCH0A_THUMBX(v)   (HW_ROMC_ROMPATCH0A_WR((HW_ROMC_ROMPATCH0A_RD() & ~BM_ROMC_ROMPATCH0A_THUMBX) | BF_ROMC_ROMPATCH0A_THUMBX(v)))
#endif


/* --- Register HW_ROMC_ROMPATCH0A, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCH0A_ADDRX      (1)      //!< Bit position for ROMC_ROMPATCH0A_ADDRX.
#define BM_ROMC_ROMPATCH0A_ADDRX      (0x007ffffe)  //!< Bit mask for ROMC_ROMPATCH0A_ADDRX.

//! @brief Get value of ROMC_ROMPATCH0A_ADDRX from a register value.
#define BG_ROMC_ROMPATCH0A_ADDRX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH0A_ADDRX) >> BP_ROMC_ROMPATCH0A_ADDRX)

//! @brief Format value for bitfield ROMC_ROMPATCH0A_ADDRX.
#define BF_ROMC_ROMPATCH0A_ADDRX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH0A_ADDRX) & BM_ROMC_ROMPATCH0A_ADDRX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCH0A_ADDRX(v)   (HW_ROMC_ROMPATCH0A_WR((HW_ROMC_ROMPATCH0A_RD() & ~BM_ROMC_ROMPATCH0A_ADDRX) | BF_ROMC_ROMPATCH0A_ADDRX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH1A - ROMC Address Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH1A - ROMC Address Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC address registers (ROMC_ROMPATCHA0 through ROMC_ROMPATCHA15) store the memory addresses
 * where opcode patching begins and data fixing occurs. The address registers ROMC_ROMPATCHA0
 * through ROMC_ROMPATCHA15 are each 21 bits wide and dedicated to one 4 Mbyte memory space. Bits 21
 * through 2 are address bits, to be compared with romc_haddr[21:2] for a match; bit 1 is also an
 * address bit used for half word selection. Bit 0 is the mode bit (set to 1 for THUMB mode). 1-word
 * data fixing can only be used on the first 8 of the address comparators. ROMC_ROMPATCHA0 through
 * ROMC_ROMPATCHA15 are associated each with address comparators 0 through 15.
 */
typedef union _hw_romc_rompatch1a
{
    reg32_t U;
    struct _hw_romc_rompatch1a_bitfields
    {
        unsigned THUMBX : 1; //!< [0] THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM opcode patch.
        unsigned ADDRX : 22; //!< [22:1] Address Comparator Registers - Indicates the memory address to be watched.
        unsigned RESERVED0 : 9; //!< [31:23] Reserved
    } B;
} hw_romc_rompatch1a_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH1A register
 */
#define HW_ROMC_ROMPATCH1A_ADDR      (REGS_ROMC_BASE + 0x104)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH1A           (*(volatile hw_romc_rompatch1a_t *) HW_ROMC_ROMPATCH1A_ADDR)
#define HW_ROMC_ROMPATCH1A_RD()      (HW_ROMC_ROMPATCH1A.U)
#define HW_ROMC_ROMPATCH1A_WR(v)     (HW_ROMC_ROMPATCH1A.U = (v))
#define HW_ROMC_ROMPATCH1A_SET(v)    (HW_ROMC_ROMPATCH1A_WR(HW_ROMC_ROMPATCH1A_RD() |  (v)))
#define HW_ROMC_ROMPATCH1A_CLR(v)    (HW_ROMC_ROMPATCH1A_WR(HW_ROMC_ROMPATCH1A_RD() & ~(v)))
#define HW_ROMC_ROMPATCH1A_TOG(v)    (HW_ROMC_ROMPATCH1A_WR(HW_ROMC_ROMPATCH1A_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH1A bitfields
 */

/* --- Register HW_ROMC_ROMPATCH1A, field THUMBX[0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCH1A_THUMBX      (0)      //!< Bit position for ROMC_ROMPATCH1A_THUMBX.
#define BM_ROMC_ROMPATCH1A_THUMBX      (0x00000001)  //!< Bit mask for ROMC_ROMPATCH1A_THUMBX.

//! @brief Get value of ROMC_ROMPATCH1A_THUMBX from a register value.
#define BG_ROMC_ROMPATCH1A_THUMBX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH1A_THUMBX) >> BP_ROMC_ROMPATCH1A_THUMBX)

//! @brief Format value for bitfield ROMC_ROMPATCH1A_THUMBX.
#define BF_ROMC_ROMPATCH1A_THUMBX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH1A_THUMBX) & BM_ROMC_ROMPATCH1A_THUMBX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCH1A_THUMBX(v)   (HW_ROMC_ROMPATCH1A_WR((HW_ROMC_ROMPATCH1A_RD() & ~BM_ROMC_ROMPATCH1A_THUMBX) | BF_ROMC_ROMPATCH1A_THUMBX(v)))
#endif


/* --- Register HW_ROMC_ROMPATCH1A, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCH1A_ADDRX      (1)      //!< Bit position for ROMC_ROMPATCH1A_ADDRX.
#define BM_ROMC_ROMPATCH1A_ADDRX      (0x007ffffe)  //!< Bit mask for ROMC_ROMPATCH1A_ADDRX.

//! @brief Get value of ROMC_ROMPATCH1A_ADDRX from a register value.
#define BG_ROMC_ROMPATCH1A_ADDRX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH1A_ADDRX) >> BP_ROMC_ROMPATCH1A_ADDRX)

//! @brief Format value for bitfield ROMC_ROMPATCH1A_ADDRX.
#define BF_ROMC_ROMPATCH1A_ADDRX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH1A_ADDRX) & BM_ROMC_ROMPATCH1A_ADDRX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCH1A_ADDRX(v)   (HW_ROMC_ROMPATCH1A_WR((HW_ROMC_ROMPATCH1A_RD() & ~BM_ROMC_ROMPATCH1A_ADDRX) | BF_ROMC_ROMPATCH1A_ADDRX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH2A - ROMC Address Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH2A - ROMC Address Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC address registers (ROMC_ROMPATCHA0 through ROMC_ROMPATCHA15) store the memory addresses
 * where opcode patching begins and data fixing occurs. The address registers ROMC_ROMPATCHA0
 * through ROMC_ROMPATCHA15 are each 21 bits wide and dedicated to one 4 Mbyte memory space. Bits 21
 * through 2 are address bits, to be compared with romc_haddr[21:2] for a match; bit 1 is also an
 * address bit used for half word selection. Bit 0 is the mode bit (set to 1 for THUMB mode). 1-word
 * data fixing can only be used on the first 8 of the address comparators. ROMC_ROMPATCHA0 through
 * ROMC_ROMPATCHA15 are associated each with address comparators 0 through 15.
 */
typedef union _hw_romc_rompatch2a
{
    reg32_t U;
    struct _hw_romc_rompatch2a_bitfields
    {
        unsigned THUMBX : 1; //!< [0] THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM opcode patch.
        unsigned ADDRX : 22; //!< [22:1] Address Comparator Registers - Indicates the memory address to be watched.
        unsigned RESERVED0 : 9; //!< [31:23] Reserved
    } B;
} hw_romc_rompatch2a_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH2A register
 */
#define HW_ROMC_ROMPATCH2A_ADDR      (REGS_ROMC_BASE + 0x108)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH2A           (*(volatile hw_romc_rompatch2a_t *) HW_ROMC_ROMPATCH2A_ADDR)
#define HW_ROMC_ROMPATCH2A_RD()      (HW_ROMC_ROMPATCH2A.U)
#define HW_ROMC_ROMPATCH2A_WR(v)     (HW_ROMC_ROMPATCH2A.U = (v))
#define HW_ROMC_ROMPATCH2A_SET(v)    (HW_ROMC_ROMPATCH2A_WR(HW_ROMC_ROMPATCH2A_RD() |  (v)))
#define HW_ROMC_ROMPATCH2A_CLR(v)    (HW_ROMC_ROMPATCH2A_WR(HW_ROMC_ROMPATCH2A_RD() & ~(v)))
#define HW_ROMC_ROMPATCH2A_TOG(v)    (HW_ROMC_ROMPATCH2A_WR(HW_ROMC_ROMPATCH2A_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH2A bitfields
 */

/* --- Register HW_ROMC_ROMPATCH2A, field THUMBX[0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCH2A_THUMBX      (0)      //!< Bit position for ROMC_ROMPATCH2A_THUMBX.
#define BM_ROMC_ROMPATCH2A_THUMBX      (0x00000001)  //!< Bit mask for ROMC_ROMPATCH2A_THUMBX.

//! @brief Get value of ROMC_ROMPATCH2A_THUMBX from a register value.
#define BG_ROMC_ROMPATCH2A_THUMBX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH2A_THUMBX) >> BP_ROMC_ROMPATCH2A_THUMBX)

//! @brief Format value for bitfield ROMC_ROMPATCH2A_THUMBX.
#define BF_ROMC_ROMPATCH2A_THUMBX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH2A_THUMBX) & BM_ROMC_ROMPATCH2A_THUMBX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCH2A_THUMBX(v)   (HW_ROMC_ROMPATCH2A_WR((HW_ROMC_ROMPATCH2A_RD() & ~BM_ROMC_ROMPATCH2A_THUMBX) | BF_ROMC_ROMPATCH2A_THUMBX(v)))
#endif


/* --- Register HW_ROMC_ROMPATCH2A, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCH2A_ADDRX      (1)      //!< Bit position for ROMC_ROMPATCH2A_ADDRX.
#define BM_ROMC_ROMPATCH2A_ADDRX      (0x007ffffe)  //!< Bit mask for ROMC_ROMPATCH2A_ADDRX.

//! @brief Get value of ROMC_ROMPATCH2A_ADDRX from a register value.
#define BG_ROMC_ROMPATCH2A_ADDRX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH2A_ADDRX) >> BP_ROMC_ROMPATCH2A_ADDRX)

//! @brief Format value for bitfield ROMC_ROMPATCH2A_ADDRX.
#define BF_ROMC_ROMPATCH2A_ADDRX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH2A_ADDRX) & BM_ROMC_ROMPATCH2A_ADDRX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCH2A_ADDRX(v)   (HW_ROMC_ROMPATCH2A_WR((HW_ROMC_ROMPATCH2A_RD() & ~BM_ROMC_ROMPATCH2A_ADDRX) | BF_ROMC_ROMPATCH2A_ADDRX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH3A - ROMC Address Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH3A - ROMC Address Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC address registers (ROMC_ROMPATCHA0 through ROMC_ROMPATCHA15) store the memory addresses
 * where opcode patching begins and data fixing occurs. The address registers ROMC_ROMPATCHA0
 * through ROMC_ROMPATCHA15 are each 21 bits wide and dedicated to one 4 Mbyte memory space. Bits 21
 * through 2 are address bits, to be compared with romc_haddr[21:2] for a match; bit 1 is also an
 * address bit used for half word selection. Bit 0 is the mode bit (set to 1 for THUMB mode). 1-word
 * data fixing can only be used on the first 8 of the address comparators. ROMC_ROMPATCHA0 through
 * ROMC_ROMPATCHA15 are associated each with address comparators 0 through 15.
 */
typedef union _hw_romc_rompatch3a
{
    reg32_t U;
    struct _hw_romc_rompatch3a_bitfields
    {
        unsigned THUMBX : 1; //!< [0] THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM opcode patch.
        unsigned ADDRX : 22; //!< [22:1] Address Comparator Registers - Indicates the memory address to be watched.
        unsigned RESERVED0 : 9; //!< [31:23] Reserved
    } B;
} hw_romc_rompatch3a_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH3A register
 */
#define HW_ROMC_ROMPATCH3A_ADDR      (REGS_ROMC_BASE + 0x10c)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH3A           (*(volatile hw_romc_rompatch3a_t *) HW_ROMC_ROMPATCH3A_ADDR)
#define HW_ROMC_ROMPATCH3A_RD()      (HW_ROMC_ROMPATCH3A.U)
#define HW_ROMC_ROMPATCH3A_WR(v)     (HW_ROMC_ROMPATCH3A.U = (v))
#define HW_ROMC_ROMPATCH3A_SET(v)    (HW_ROMC_ROMPATCH3A_WR(HW_ROMC_ROMPATCH3A_RD() |  (v)))
#define HW_ROMC_ROMPATCH3A_CLR(v)    (HW_ROMC_ROMPATCH3A_WR(HW_ROMC_ROMPATCH3A_RD() & ~(v)))
#define HW_ROMC_ROMPATCH3A_TOG(v)    (HW_ROMC_ROMPATCH3A_WR(HW_ROMC_ROMPATCH3A_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH3A bitfields
 */

/* --- Register HW_ROMC_ROMPATCH3A, field THUMBX[0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCH3A_THUMBX      (0)      //!< Bit position for ROMC_ROMPATCH3A_THUMBX.
#define BM_ROMC_ROMPATCH3A_THUMBX      (0x00000001)  //!< Bit mask for ROMC_ROMPATCH3A_THUMBX.

//! @brief Get value of ROMC_ROMPATCH3A_THUMBX from a register value.
#define BG_ROMC_ROMPATCH3A_THUMBX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH3A_THUMBX) >> BP_ROMC_ROMPATCH3A_THUMBX)

//! @brief Format value for bitfield ROMC_ROMPATCH3A_THUMBX.
#define BF_ROMC_ROMPATCH3A_THUMBX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH3A_THUMBX) & BM_ROMC_ROMPATCH3A_THUMBX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCH3A_THUMBX(v)   (HW_ROMC_ROMPATCH3A_WR((HW_ROMC_ROMPATCH3A_RD() & ~BM_ROMC_ROMPATCH3A_THUMBX) | BF_ROMC_ROMPATCH3A_THUMBX(v)))
#endif


/* --- Register HW_ROMC_ROMPATCH3A, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCH3A_ADDRX      (1)      //!< Bit position for ROMC_ROMPATCH3A_ADDRX.
#define BM_ROMC_ROMPATCH3A_ADDRX      (0x007ffffe)  //!< Bit mask for ROMC_ROMPATCH3A_ADDRX.

//! @brief Get value of ROMC_ROMPATCH3A_ADDRX from a register value.
#define BG_ROMC_ROMPATCH3A_ADDRX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH3A_ADDRX) >> BP_ROMC_ROMPATCH3A_ADDRX)

//! @brief Format value for bitfield ROMC_ROMPATCH3A_ADDRX.
#define BF_ROMC_ROMPATCH3A_ADDRX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH3A_ADDRX) & BM_ROMC_ROMPATCH3A_ADDRX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCH3A_ADDRX(v)   (HW_ROMC_ROMPATCH3A_WR((HW_ROMC_ROMPATCH3A_RD() & ~BM_ROMC_ROMPATCH3A_ADDRX) | BF_ROMC_ROMPATCH3A_ADDRX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH4A - ROMC Address Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH4A - ROMC Address Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC address registers (ROMC_ROMPATCHA0 through ROMC_ROMPATCHA15) store the memory addresses
 * where opcode patching begins and data fixing occurs. The address registers ROMC_ROMPATCHA0
 * through ROMC_ROMPATCHA15 are each 21 bits wide and dedicated to one 4 Mbyte memory space. Bits 21
 * through 2 are address bits, to be compared with romc_haddr[21:2] for a match; bit 1 is also an
 * address bit used for half word selection. Bit 0 is the mode bit (set to 1 for THUMB mode). 1-word
 * data fixing can only be used on the first 8 of the address comparators. ROMC_ROMPATCHA0 through
 * ROMC_ROMPATCHA15 are associated each with address comparators 0 through 15.
 */
typedef union _hw_romc_rompatch4a
{
    reg32_t U;
    struct _hw_romc_rompatch4a_bitfields
    {
        unsigned THUMBX : 1; //!< [0] THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM opcode patch.
        unsigned ADDRX : 22; //!< [22:1] Address Comparator Registers - Indicates the memory address to be watched.
        unsigned RESERVED0 : 9; //!< [31:23] Reserved
    } B;
} hw_romc_rompatch4a_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH4A register
 */
#define HW_ROMC_ROMPATCH4A_ADDR      (REGS_ROMC_BASE + 0x110)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH4A           (*(volatile hw_romc_rompatch4a_t *) HW_ROMC_ROMPATCH4A_ADDR)
#define HW_ROMC_ROMPATCH4A_RD()      (HW_ROMC_ROMPATCH4A.U)
#define HW_ROMC_ROMPATCH4A_WR(v)     (HW_ROMC_ROMPATCH4A.U = (v))
#define HW_ROMC_ROMPATCH4A_SET(v)    (HW_ROMC_ROMPATCH4A_WR(HW_ROMC_ROMPATCH4A_RD() |  (v)))
#define HW_ROMC_ROMPATCH4A_CLR(v)    (HW_ROMC_ROMPATCH4A_WR(HW_ROMC_ROMPATCH4A_RD() & ~(v)))
#define HW_ROMC_ROMPATCH4A_TOG(v)    (HW_ROMC_ROMPATCH4A_WR(HW_ROMC_ROMPATCH4A_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH4A bitfields
 */

/* --- Register HW_ROMC_ROMPATCH4A, field THUMBX[0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCH4A_THUMBX      (0)      //!< Bit position for ROMC_ROMPATCH4A_THUMBX.
#define BM_ROMC_ROMPATCH4A_THUMBX      (0x00000001)  //!< Bit mask for ROMC_ROMPATCH4A_THUMBX.

//! @brief Get value of ROMC_ROMPATCH4A_THUMBX from a register value.
#define BG_ROMC_ROMPATCH4A_THUMBX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH4A_THUMBX) >> BP_ROMC_ROMPATCH4A_THUMBX)

//! @brief Format value for bitfield ROMC_ROMPATCH4A_THUMBX.
#define BF_ROMC_ROMPATCH4A_THUMBX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH4A_THUMBX) & BM_ROMC_ROMPATCH4A_THUMBX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCH4A_THUMBX(v)   (HW_ROMC_ROMPATCH4A_WR((HW_ROMC_ROMPATCH4A_RD() & ~BM_ROMC_ROMPATCH4A_THUMBX) | BF_ROMC_ROMPATCH4A_THUMBX(v)))
#endif


/* --- Register HW_ROMC_ROMPATCH4A, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCH4A_ADDRX      (1)      //!< Bit position for ROMC_ROMPATCH4A_ADDRX.
#define BM_ROMC_ROMPATCH4A_ADDRX      (0x007ffffe)  //!< Bit mask for ROMC_ROMPATCH4A_ADDRX.

//! @brief Get value of ROMC_ROMPATCH4A_ADDRX from a register value.
#define BG_ROMC_ROMPATCH4A_ADDRX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH4A_ADDRX) >> BP_ROMC_ROMPATCH4A_ADDRX)

//! @brief Format value for bitfield ROMC_ROMPATCH4A_ADDRX.
#define BF_ROMC_ROMPATCH4A_ADDRX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH4A_ADDRX) & BM_ROMC_ROMPATCH4A_ADDRX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCH4A_ADDRX(v)   (HW_ROMC_ROMPATCH4A_WR((HW_ROMC_ROMPATCH4A_RD() & ~BM_ROMC_ROMPATCH4A_ADDRX) | BF_ROMC_ROMPATCH4A_ADDRX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH5A - ROMC Address Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH5A - ROMC Address Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC address registers (ROMC_ROMPATCHA0 through ROMC_ROMPATCHA15) store the memory addresses
 * where opcode patching begins and data fixing occurs. The address registers ROMC_ROMPATCHA0
 * through ROMC_ROMPATCHA15 are each 21 bits wide and dedicated to one 4 Mbyte memory space. Bits 21
 * through 2 are address bits, to be compared with romc_haddr[21:2] for a match; bit 1 is also an
 * address bit used for half word selection. Bit 0 is the mode bit (set to 1 for THUMB mode). 1-word
 * data fixing can only be used on the first 8 of the address comparators. ROMC_ROMPATCHA0 through
 * ROMC_ROMPATCHA15 are associated each with address comparators 0 through 15.
 */
typedef union _hw_romc_rompatch5a
{
    reg32_t U;
    struct _hw_romc_rompatch5a_bitfields
    {
        unsigned THUMBX : 1; //!< [0] THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM opcode patch.
        unsigned ADDRX : 22; //!< [22:1] Address Comparator Registers - Indicates the memory address to be watched.
        unsigned RESERVED0 : 9; //!< [31:23] Reserved
    } B;
} hw_romc_rompatch5a_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH5A register
 */
#define HW_ROMC_ROMPATCH5A_ADDR      (REGS_ROMC_BASE + 0x114)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH5A           (*(volatile hw_romc_rompatch5a_t *) HW_ROMC_ROMPATCH5A_ADDR)
#define HW_ROMC_ROMPATCH5A_RD()      (HW_ROMC_ROMPATCH5A.U)
#define HW_ROMC_ROMPATCH5A_WR(v)     (HW_ROMC_ROMPATCH5A.U = (v))
#define HW_ROMC_ROMPATCH5A_SET(v)    (HW_ROMC_ROMPATCH5A_WR(HW_ROMC_ROMPATCH5A_RD() |  (v)))
#define HW_ROMC_ROMPATCH5A_CLR(v)    (HW_ROMC_ROMPATCH5A_WR(HW_ROMC_ROMPATCH5A_RD() & ~(v)))
#define HW_ROMC_ROMPATCH5A_TOG(v)    (HW_ROMC_ROMPATCH5A_WR(HW_ROMC_ROMPATCH5A_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH5A bitfields
 */

/* --- Register HW_ROMC_ROMPATCH5A, field THUMBX[0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCH5A_THUMBX      (0)      //!< Bit position for ROMC_ROMPATCH5A_THUMBX.
#define BM_ROMC_ROMPATCH5A_THUMBX      (0x00000001)  //!< Bit mask for ROMC_ROMPATCH5A_THUMBX.

//! @brief Get value of ROMC_ROMPATCH5A_THUMBX from a register value.
#define BG_ROMC_ROMPATCH5A_THUMBX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH5A_THUMBX) >> BP_ROMC_ROMPATCH5A_THUMBX)

//! @brief Format value for bitfield ROMC_ROMPATCH5A_THUMBX.
#define BF_ROMC_ROMPATCH5A_THUMBX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH5A_THUMBX) & BM_ROMC_ROMPATCH5A_THUMBX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCH5A_THUMBX(v)   (HW_ROMC_ROMPATCH5A_WR((HW_ROMC_ROMPATCH5A_RD() & ~BM_ROMC_ROMPATCH5A_THUMBX) | BF_ROMC_ROMPATCH5A_THUMBX(v)))
#endif


/* --- Register HW_ROMC_ROMPATCH5A, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCH5A_ADDRX      (1)      //!< Bit position for ROMC_ROMPATCH5A_ADDRX.
#define BM_ROMC_ROMPATCH5A_ADDRX      (0x007ffffe)  //!< Bit mask for ROMC_ROMPATCH5A_ADDRX.

//! @brief Get value of ROMC_ROMPATCH5A_ADDRX from a register value.
#define BG_ROMC_ROMPATCH5A_ADDRX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH5A_ADDRX) >> BP_ROMC_ROMPATCH5A_ADDRX)

//! @brief Format value for bitfield ROMC_ROMPATCH5A_ADDRX.
#define BF_ROMC_ROMPATCH5A_ADDRX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH5A_ADDRX) & BM_ROMC_ROMPATCH5A_ADDRX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCH5A_ADDRX(v)   (HW_ROMC_ROMPATCH5A_WR((HW_ROMC_ROMPATCH5A_RD() & ~BM_ROMC_ROMPATCH5A_ADDRX) | BF_ROMC_ROMPATCH5A_ADDRX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH6A - ROMC Address Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH6A - ROMC Address Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC address registers (ROMC_ROMPATCHA0 through ROMC_ROMPATCHA15) store the memory addresses
 * where opcode patching begins and data fixing occurs. The address registers ROMC_ROMPATCHA0
 * through ROMC_ROMPATCHA15 are each 21 bits wide and dedicated to one 4 Mbyte memory space. Bits 21
 * through 2 are address bits, to be compared with romc_haddr[21:2] for a match; bit 1 is also an
 * address bit used for half word selection. Bit 0 is the mode bit (set to 1 for THUMB mode). 1-word
 * data fixing can only be used on the first 8 of the address comparators. ROMC_ROMPATCHA0 through
 * ROMC_ROMPATCHA15 are associated each with address comparators 0 through 15.
 */
typedef union _hw_romc_rompatch6a
{
    reg32_t U;
    struct _hw_romc_rompatch6a_bitfields
    {
        unsigned THUMBX : 1; //!< [0] THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM opcode patch.
        unsigned ADDRX : 22; //!< [22:1] Address Comparator Registers - Indicates the memory address to be watched.
        unsigned RESERVED0 : 9; //!< [31:23] Reserved
    } B;
} hw_romc_rompatch6a_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH6A register
 */
#define HW_ROMC_ROMPATCH6A_ADDR      (REGS_ROMC_BASE + 0x118)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH6A           (*(volatile hw_romc_rompatch6a_t *) HW_ROMC_ROMPATCH6A_ADDR)
#define HW_ROMC_ROMPATCH6A_RD()      (HW_ROMC_ROMPATCH6A.U)
#define HW_ROMC_ROMPATCH6A_WR(v)     (HW_ROMC_ROMPATCH6A.U = (v))
#define HW_ROMC_ROMPATCH6A_SET(v)    (HW_ROMC_ROMPATCH6A_WR(HW_ROMC_ROMPATCH6A_RD() |  (v)))
#define HW_ROMC_ROMPATCH6A_CLR(v)    (HW_ROMC_ROMPATCH6A_WR(HW_ROMC_ROMPATCH6A_RD() & ~(v)))
#define HW_ROMC_ROMPATCH6A_TOG(v)    (HW_ROMC_ROMPATCH6A_WR(HW_ROMC_ROMPATCH6A_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH6A bitfields
 */

/* --- Register HW_ROMC_ROMPATCH6A, field THUMBX[0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCH6A_THUMBX      (0)      //!< Bit position for ROMC_ROMPATCH6A_THUMBX.
#define BM_ROMC_ROMPATCH6A_THUMBX      (0x00000001)  //!< Bit mask for ROMC_ROMPATCH6A_THUMBX.

//! @brief Get value of ROMC_ROMPATCH6A_THUMBX from a register value.
#define BG_ROMC_ROMPATCH6A_THUMBX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH6A_THUMBX) >> BP_ROMC_ROMPATCH6A_THUMBX)

//! @brief Format value for bitfield ROMC_ROMPATCH6A_THUMBX.
#define BF_ROMC_ROMPATCH6A_THUMBX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH6A_THUMBX) & BM_ROMC_ROMPATCH6A_THUMBX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCH6A_THUMBX(v)   (HW_ROMC_ROMPATCH6A_WR((HW_ROMC_ROMPATCH6A_RD() & ~BM_ROMC_ROMPATCH6A_THUMBX) | BF_ROMC_ROMPATCH6A_THUMBX(v)))
#endif


/* --- Register HW_ROMC_ROMPATCH6A, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCH6A_ADDRX      (1)      //!< Bit position for ROMC_ROMPATCH6A_ADDRX.
#define BM_ROMC_ROMPATCH6A_ADDRX      (0x007ffffe)  //!< Bit mask for ROMC_ROMPATCH6A_ADDRX.

//! @brief Get value of ROMC_ROMPATCH6A_ADDRX from a register value.
#define BG_ROMC_ROMPATCH6A_ADDRX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH6A_ADDRX) >> BP_ROMC_ROMPATCH6A_ADDRX)

//! @brief Format value for bitfield ROMC_ROMPATCH6A_ADDRX.
#define BF_ROMC_ROMPATCH6A_ADDRX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH6A_ADDRX) & BM_ROMC_ROMPATCH6A_ADDRX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCH6A_ADDRX(v)   (HW_ROMC_ROMPATCH6A_WR((HW_ROMC_ROMPATCH6A_RD() & ~BM_ROMC_ROMPATCH6A_ADDRX) | BF_ROMC_ROMPATCH6A_ADDRX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH7A - ROMC Address Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH7A - ROMC Address Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC address registers (ROMC_ROMPATCHA0 through ROMC_ROMPATCHA15) store the memory addresses
 * where opcode patching begins and data fixing occurs. The address registers ROMC_ROMPATCHA0
 * through ROMC_ROMPATCHA15 are each 21 bits wide and dedicated to one 4 Mbyte memory space. Bits 21
 * through 2 are address bits, to be compared with romc_haddr[21:2] for a match; bit 1 is also an
 * address bit used for half word selection. Bit 0 is the mode bit (set to 1 for THUMB mode). 1-word
 * data fixing can only be used on the first 8 of the address comparators. ROMC_ROMPATCHA0 through
 * ROMC_ROMPATCHA15 are associated each with address comparators 0 through 15.
 */
typedef union _hw_romc_rompatch7a
{
    reg32_t U;
    struct _hw_romc_rompatch7a_bitfields
    {
        unsigned THUMBX : 1; //!< [0] THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM opcode patch.
        unsigned ADDRX : 22; //!< [22:1] Address Comparator Registers - Indicates the memory address to be watched.
        unsigned RESERVED0 : 9; //!< [31:23] Reserved
    } B;
} hw_romc_rompatch7a_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH7A register
 */
#define HW_ROMC_ROMPATCH7A_ADDR      (REGS_ROMC_BASE + 0x11c)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH7A           (*(volatile hw_romc_rompatch7a_t *) HW_ROMC_ROMPATCH7A_ADDR)
#define HW_ROMC_ROMPATCH7A_RD()      (HW_ROMC_ROMPATCH7A.U)
#define HW_ROMC_ROMPATCH7A_WR(v)     (HW_ROMC_ROMPATCH7A.U = (v))
#define HW_ROMC_ROMPATCH7A_SET(v)    (HW_ROMC_ROMPATCH7A_WR(HW_ROMC_ROMPATCH7A_RD() |  (v)))
#define HW_ROMC_ROMPATCH7A_CLR(v)    (HW_ROMC_ROMPATCH7A_WR(HW_ROMC_ROMPATCH7A_RD() & ~(v)))
#define HW_ROMC_ROMPATCH7A_TOG(v)    (HW_ROMC_ROMPATCH7A_WR(HW_ROMC_ROMPATCH7A_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH7A bitfields
 */

/* --- Register HW_ROMC_ROMPATCH7A, field THUMBX[0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCH7A_THUMBX      (0)      //!< Bit position for ROMC_ROMPATCH7A_THUMBX.
#define BM_ROMC_ROMPATCH7A_THUMBX      (0x00000001)  //!< Bit mask for ROMC_ROMPATCH7A_THUMBX.

//! @brief Get value of ROMC_ROMPATCH7A_THUMBX from a register value.
#define BG_ROMC_ROMPATCH7A_THUMBX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH7A_THUMBX) >> BP_ROMC_ROMPATCH7A_THUMBX)

//! @brief Format value for bitfield ROMC_ROMPATCH7A_THUMBX.
#define BF_ROMC_ROMPATCH7A_THUMBX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH7A_THUMBX) & BM_ROMC_ROMPATCH7A_THUMBX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCH7A_THUMBX(v)   (HW_ROMC_ROMPATCH7A_WR((HW_ROMC_ROMPATCH7A_RD() & ~BM_ROMC_ROMPATCH7A_THUMBX) | BF_ROMC_ROMPATCH7A_THUMBX(v)))
#endif


/* --- Register HW_ROMC_ROMPATCH7A, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCH7A_ADDRX      (1)      //!< Bit position for ROMC_ROMPATCH7A_ADDRX.
#define BM_ROMC_ROMPATCH7A_ADDRX      (0x007ffffe)  //!< Bit mask for ROMC_ROMPATCH7A_ADDRX.

//! @brief Get value of ROMC_ROMPATCH7A_ADDRX from a register value.
#define BG_ROMC_ROMPATCH7A_ADDRX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH7A_ADDRX) >> BP_ROMC_ROMPATCH7A_ADDRX)

//! @brief Format value for bitfield ROMC_ROMPATCH7A_ADDRX.
#define BF_ROMC_ROMPATCH7A_ADDRX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH7A_ADDRX) & BM_ROMC_ROMPATCH7A_ADDRX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCH7A_ADDRX(v)   (HW_ROMC_ROMPATCH7A_WR((HW_ROMC_ROMPATCH7A_RD() & ~BM_ROMC_ROMPATCH7A_ADDRX) | BF_ROMC_ROMPATCH7A_ADDRX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH8A - ROMC Address Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH8A - ROMC Address Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC address registers (ROMC_ROMPATCHA0 through ROMC_ROMPATCHA15) store the memory addresses
 * where opcode patching begins and data fixing occurs. The address registers ROMC_ROMPATCHA0
 * through ROMC_ROMPATCHA15 are each 21 bits wide and dedicated to one 4 Mbyte memory space. Bits 21
 * through 2 are address bits, to be compared with romc_haddr[21:2] for a match; bit 1 is also an
 * address bit used for half word selection. Bit 0 is the mode bit (set to 1 for THUMB mode). 1-word
 * data fixing can only be used on the first 8 of the address comparators. ROMC_ROMPATCHA0 through
 * ROMC_ROMPATCHA15 are associated each with address comparators 0 through 15.
 */
typedef union _hw_romc_rompatch8a
{
    reg32_t U;
    struct _hw_romc_rompatch8a_bitfields
    {
        unsigned THUMBX : 1; //!< [0] THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM opcode patch.
        unsigned ADDRX : 22; //!< [22:1] Address Comparator Registers - Indicates the memory address to be watched.
        unsigned RESERVED0 : 9; //!< [31:23] Reserved
    } B;
} hw_romc_rompatch8a_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH8A register
 */
#define HW_ROMC_ROMPATCH8A_ADDR      (REGS_ROMC_BASE + 0x120)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH8A           (*(volatile hw_romc_rompatch8a_t *) HW_ROMC_ROMPATCH8A_ADDR)
#define HW_ROMC_ROMPATCH8A_RD()      (HW_ROMC_ROMPATCH8A.U)
#define HW_ROMC_ROMPATCH8A_WR(v)     (HW_ROMC_ROMPATCH8A.U = (v))
#define HW_ROMC_ROMPATCH8A_SET(v)    (HW_ROMC_ROMPATCH8A_WR(HW_ROMC_ROMPATCH8A_RD() |  (v)))
#define HW_ROMC_ROMPATCH8A_CLR(v)    (HW_ROMC_ROMPATCH8A_WR(HW_ROMC_ROMPATCH8A_RD() & ~(v)))
#define HW_ROMC_ROMPATCH8A_TOG(v)    (HW_ROMC_ROMPATCH8A_WR(HW_ROMC_ROMPATCH8A_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH8A bitfields
 */

/* --- Register HW_ROMC_ROMPATCH8A, field THUMBX[0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCH8A_THUMBX      (0)      //!< Bit position for ROMC_ROMPATCH8A_THUMBX.
#define BM_ROMC_ROMPATCH8A_THUMBX      (0x00000001)  //!< Bit mask for ROMC_ROMPATCH8A_THUMBX.

//! @brief Get value of ROMC_ROMPATCH8A_THUMBX from a register value.
#define BG_ROMC_ROMPATCH8A_THUMBX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH8A_THUMBX) >> BP_ROMC_ROMPATCH8A_THUMBX)

//! @brief Format value for bitfield ROMC_ROMPATCH8A_THUMBX.
#define BF_ROMC_ROMPATCH8A_THUMBX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH8A_THUMBX) & BM_ROMC_ROMPATCH8A_THUMBX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCH8A_THUMBX(v)   (HW_ROMC_ROMPATCH8A_WR((HW_ROMC_ROMPATCH8A_RD() & ~BM_ROMC_ROMPATCH8A_THUMBX) | BF_ROMC_ROMPATCH8A_THUMBX(v)))
#endif


/* --- Register HW_ROMC_ROMPATCH8A, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCH8A_ADDRX      (1)      //!< Bit position for ROMC_ROMPATCH8A_ADDRX.
#define BM_ROMC_ROMPATCH8A_ADDRX      (0x007ffffe)  //!< Bit mask for ROMC_ROMPATCH8A_ADDRX.

//! @brief Get value of ROMC_ROMPATCH8A_ADDRX from a register value.
#define BG_ROMC_ROMPATCH8A_ADDRX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH8A_ADDRX) >> BP_ROMC_ROMPATCH8A_ADDRX)

//! @brief Format value for bitfield ROMC_ROMPATCH8A_ADDRX.
#define BF_ROMC_ROMPATCH8A_ADDRX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH8A_ADDRX) & BM_ROMC_ROMPATCH8A_ADDRX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCH8A_ADDRX(v)   (HW_ROMC_ROMPATCH8A_WR((HW_ROMC_ROMPATCH8A_RD() & ~BM_ROMC_ROMPATCH8A_ADDRX) | BF_ROMC_ROMPATCH8A_ADDRX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH9A - ROMC Address Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH9A - ROMC Address Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC address registers (ROMC_ROMPATCHA0 through ROMC_ROMPATCHA15) store the memory addresses
 * where opcode patching begins and data fixing occurs. The address registers ROMC_ROMPATCHA0
 * through ROMC_ROMPATCHA15 are each 21 bits wide and dedicated to one 4 Mbyte memory space. Bits 21
 * through 2 are address bits, to be compared with romc_haddr[21:2] for a match; bit 1 is also an
 * address bit used for half word selection. Bit 0 is the mode bit (set to 1 for THUMB mode). 1-word
 * data fixing can only be used on the first 8 of the address comparators. ROMC_ROMPATCHA0 through
 * ROMC_ROMPATCHA15 are associated each with address comparators 0 through 15.
 */
typedef union _hw_romc_rompatch9a
{
    reg32_t U;
    struct _hw_romc_rompatch9a_bitfields
    {
        unsigned THUMBX : 1; //!< [0] THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM opcode patch.
        unsigned ADDRX : 22; //!< [22:1] Address Comparator Registers - Indicates the memory address to be watched.
        unsigned RESERVED0 : 9; //!< [31:23] Reserved
    } B;
} hw_romc_rompatch9a_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH9A register
 */
#define HW_ROMC_ROMPATCH9A_ADDR      (REGS_ROMC_BASE + 0x124)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH9A           (*(volatile hw_romc_rompatch9a_t *) HW_ROMC_ROMPATCH9A_ADDR)
#define HW_ROMC_ROMPATCH9A_RD()      (HW_ROMC_ROMPATCH9A.U)
#define HW_ROMC_ROMPATCH9A_WR(v)     (HW_ROMC_ROMPATCH9A.U = (v))
#define HW_ROMC_ROMPATCH9A_SET(v)    (HW_ROMC_ROMPATCH9A_WR(HW_ROMC_ROMPATCH9A_RD() |  (v)))
#define HW_ROMC_ROMPATCH9A_CLR(v)    (HW_ROMC_ROMPATCH9A_WR(HW_ROMC_ROMPATCH9A_RD() & ~(v)))
#define HW_ROMC_ROMPATCH9A_TOG(v)    (HW_ROMC_ROMPATCH9A_WR(HW_ROMC_ROMPATCH9A_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH9A bitfields
 */

/* --- Register HW_ROMC_ROMPATCH9A, field THUMBX[0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCH9A_THUMBX      (0)      //!< Bit position for ROMC_ROMPATCH9A_THUMBX.
#define BM_ROMC_ROMPATCH9A_THUMBX      (0x00000001)  //!< Bit mask for ROMC_ROMPATCH9A_THUMBX.

//! @brief Get value of ROMC_ROMPATCH9A_THUMBX from a register value.
#define BG_ROMC_ROMPATCH9A_THUMBX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH9A_THUMBX) >> BP_ROMC_ROMPATCH9A_THUMBX)

//! @brief Format value for bitfield ROMC_ROMPATCH9A_THUMBX.
#define BF_ROMC_ROMPATCH9A_THUMBX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH9A_THUMBX) & BM_ROMC_ROMPATCH9A_THUMBX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCH9A_THUMBX(v)   (HW_ROMC_ROMPATCH9A_WR((HW_ROMC_ROMPATCH9A_RD() & ~BM_ROMC_ROMPATCH9A_THUMBX) | BF_ROMC_ROMPATCH9A_THUMBX(v)))
#endif


/* --- Register HW_ROMC_ROMPATCH9A, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCH9A_ADDRX      (1)      //!< Bit position for ROMC_ROMPATCH9A_ADDRX.
#define BM_ROMC_ROMPATCH9A_ADDRX      (0x007ffffe)  //!< Bit mask for ROMC_ROMPATCH9A_ADDRX.

//! @brief Get value of ROMC_ROMPATCH9A_ADDRX from a register value.
#define BG_ROMC_ROMPATCH9A_ADDRX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH9A_ADDRX) >> BP_ROMC_ROMPATCH9A_ADDRX)

//! @brief Format value for bitfield ROMC_ROMPATCH9A_ADDRX.
#define BF_ROMC_ROMPATCH9A_ADDRX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH9A_ADDRX) & BM_ROMC_ROMPATCH9A_ADDRX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCH9A_ADDRX(v)   (HW_ROMC_ROMPATCH9A_WR((HW_ROMC_ROMPATCH9A_RD() & ~BM_ROMC_ROMPATCH9A_ADDRX) | BF_ROMC_ROMPATCH9A_ADDRX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH10A - ROMC Address Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH10A - ROMC Address Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC address registers (ROMC_ROMPATCHA0 through ROMC_ROMPATCHA15) store the memory addresses
 * where opcode patching begins and data fixing occurs. The address registers ROMC_ROMPATCHA0
 * through ROMC_ROMPATCHA15 are each 21 bits wide and dedicated to one 4 Mbyte memory space. Bits 21
 * through 2 are address bits, to be compared with romc_haddr[21:2] for a match; bit 1 is also an
 * address bit used for half word selection. Bit 0 is the mode bit (set to 1 for THUMB mode). 1-word
 * data fixing can only be used on the first 8 of the address comparators. ROMC_ROMPATCHA0 through
 * ROMC_ROMPATCHA15 are associated each with address comparators 0 through 15.
 */
typedef union _hw_romc_rompatch10a
{
    reg32_t U;
    struct _hw_romc_rompatch10a_bitfields
    {
        unsigned THUMBX : 1; //!< [0] THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM opcode patch.
        unsigned ADDRX : 22; //!< [22:1] Address Comparator Registers - Indicates the memory address to be watched.
        unsigned RESERVED0 : 9; //!< [31:23] Reserved
    } B;
} hw_romc_rompatch10a_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH10A register
 */
#define HW_ROMC_ROMPATCH10A_ADDR      (REGS_ROMC_BASE + 0x128)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH10A           (*(volatile hw_romc_rompatch10a_t *) HW_ROMC_ROMPATCH10A_ADDR)
#define HW_ROMC_ROMPATCH10A_RD()      (HW_ROMC_ROMPATCH10A.U)
#define HW_ROMC_ROMPATCH10A_WR(v)     (HW_ROMC_ROMPATCH10A.U = (v))
#define HW_ROMC_ROMPATCH10A_SET(v)    (HW_ROMC_ROMPATCH10A_WR(HW_ROMC_ROMPATCH10A_RD() |  (v)))
#define HW_ROMC_ROMPATCH10A_CLR(v)    (HW_ROMC_ROMPATCH10A_WR(HW_ROMC_ROMPATCH10A_RD() & ~(v)))
#define HW_ROMC_ROMPATCH10A_TOG(v)    (HW_ROMC_ROMPATCH10A_WR(HW_ROMC_ROMPATCH10A_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH10A bitfields
 */

/* --- Register HW_ROMC_ROMPATCH10A, field THUMBX[0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCH10A_THUMBX      (0)      //!< Bit position for ROMC_ROMPATCH10A_THUMBX.
#define BM_ROMC_ROMPATCH10A_THUMBX      (0x00000001)  //!< Bit mask for ROMC_ROMPATCH10A_THUMBX.

//! @brief Get value of ROMC_ROMPATCH10A_THUMBX from a register value.
#define BG_ROMC_ROMPATCH10A_THUMBX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH10A_THUMBX) >> BP_ROMC_ROMPATCH10A_THUMBX)

//! @brief Format value for bitfield ROMC_ROMPATCH10A_THUMBX.
#define BF_ROMC_ROMPATCH10A_THUMBX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH10A_THUMBX) & BM_ROMC_ROMPATCH10A_THUMBX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCH10A_THUMBX(v)   (HW_ROMC_ROMPATCH10A_WR((HW_ROMC_ROMPATCH10A_RD() & ~BM_ROMC_ROMPATCH10A_THUMBX) | BF_ROMC_ROMPATCH10A_THUMBX(v)))
#endif


/* --- Register HW_ROMC_ROMPATCH10A, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCH10A_ADDRX      (1)      //!< Bit position for ROMC_ROMPATCH10A_ADDRX.
#define BM_ROMC_ROMPATCH10A_ADDRX      (0x007ffffe)  //!< Bit mask for ROMC_ROMPATCH10A_ADDRX.

//! @brief Get value of ROMC_ROMPATCH10A_ADDRX from a register value.
#define BG_ROMC_ROMPATCH10A_ADDRX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH10A_ADDRX) >> BP_ROMC_ROMPATCH10A_ADDRX)

//! @brief Format value for bitfield ROMC_ROMPATCH10A_ADDRX.
#define BF_ROMC_ROMPATCH10A_ADDRX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH10A_ADDRX) & BM_ROMC_ROMPATCH10A_ADDRX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCH10A_ADDRX(v)   (HW_ROMC_ROMPATCH10A_WR((HW_ROMC_ROMPATCH10A_RD() & ~BM_ROMC_ROMPATCH10A_ADDRX) | BF_ROMC_ROMPATCH10A_ADDRX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH11A - ROMC Address Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH11A - ROMC Address Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC address registers (ROMC_ROMPATCHA0 through ROMC_ROMPATCHA15) store the memory addresses
 * where opcode patching begins and data fixing occurs. The address registers ROMC_ROMPATCHA0
 * through ROMC_ROMPATCHA15 are each 21 bits wide and dedicated to one 4 Mbyte memory space. Bits 21
 * through 2 are address bits, to be compared with romc_haddr[21:2] for a match; bit 1 is also an
 * address bit used for half word selection. Bit 0 is the mode bit (set to 1 for THUMB mode). 1-word
 * data fixing can only be used on the first 8 of the address comparators. ROMC_ROMPATCHA0 through
 * ROMC_ROMPATCHA15 are associated each with address comparators 0 through 15.
 */
typedef union _hw_romc_rompatch11a
{
    reg32_t U;
    struct _hw_romc_rompatch11a_bitfields
    {
        unsigned THUMBX : 1; //!< [0] THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM opcode patch.
        unsigned ADDRX : 22; //!< [22:1] Address Comparator Registers - Indicates the memory address to be watched.
        unsigned RESERVED0 : 9; //!< [31:23] Reserved
    } B;
} hw_romc_rompatch11a_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH11A register
 */
#define HW_ROMC_ROMPATCH11A_ADDR      (REGS_ROMC_BASE + 0x12c)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH11A           (*(volatile hw_romc_rompatch11a_t *) HW_ROMC_ROMPATCH11A_ADDR)
#define HW_ROMC_ROMPATCH11A_RD()      (HW_ROMC_ROMPATCH11A.U)
#define HW_ROMC_ROMPATCH11A_WR(v)     (HW_ROMC_ROMPATCH11A.U = (v))
#define HW_ROMC_ROMPATCH11A_SET(v)    (HW_ROMC_ROMPATCH11A_WR(HW_ROMC_ROMPATCH11A_RD() |  (v)))
#define HW_ROMC_ROMPATCH11A_CLR(v)    (HW_ROMC_ROMPATCH11A_WR(HW_ROMC_ROMPATCH11A_RD() & ~(v)))
#define HW_ROMC_ROMPATCH11A_TOG(v)    (HW_ROMC_ROMPATCH11A_WR(HW_ROMC_ROMPATCH11A_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH11A bitfields
 */

/* --- Register HW_ROMC_ROMPATCH11A, field THUMBX[0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCH11A_THUMBX      (0)      //!< Bit position for ROMC_ROMPATCH11A_THUMBX.
#define BM_ROMC_ROMPATCH11A_THUMBX      (0x00000001)  //!< Bit mask for ROMC_ROMPATCH11A_THUMBX.

//! @brief Get value of ROMC_ROMPATCH11A_THUMBX from a register value.
#define BG_ROMC_ROMPATCH11A_THUMBX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH11A_THUMBX) >> BP_ROMC_ROMPATCH11A_THUMBX)

//! @brief Format value for bitfield ROMC_ROMPATCH11A_THUMBX.
#define BF_ROMC_ROMPATCH11A_THUMBX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH11A_THUMBX) & BM_ROMC_ROMPATCH11A_THUMBX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCH11A_THUMBX(v)   (HW_ROMC_ROMPATCH11A_WR((HW_ROMC_ROMPATCH11A_RD() & ~BM_ROMC_ROMPATCH11A_THUMBX) | BF_ROMC_ROMPATCH11A_THUMBX(v)))
#endif


/* --- Register HW_ROMC_ROMPATCH11A, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCH11A_ADDRX      (1)      //!< Bit position for ROMC_ROMPATCH11A_ADDRX.
#define BM_ROMC_ROMPATCH11A_ADDRX      (0x007ffffe)  //!< Bit mask for ROMC_ROMPATCH11A_ADDRX.

//! @brief Get value of ROMC_ROMPATCH11A_ADDRX from a register value.
#define BG_ROMC_ROMPATCH11A_ADDRX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH11A_ADDRX) >> BP_ROMC_ROMPATCH11A_ADDRX)

//! @brief Format value for bitfield ROMC_ROMPATCH11A_ADDRX.
#define BF_ROMC_ROMPATCH11A_ADDRX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH11A_ADDRX) & BM_ROMC_ROMPATCH11A_ADDRX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCH11A_ADDRX(v)   (HW_ROMC_ROMPATCH11A_WR((HW_ROMC_ROMPATCH11A_RD() & ~BM_ROMC_ROMPATCH11A_ADDRX) | BF_ROMC_ROMPATCH11A_ADDRX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH12A - ROMC Address Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH12A - ROMC Address Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC address registers (ROMC_ROMPATCHA0 through ROMC_ROMPATCHA15) store the memory addresses
 * where opcode patching begins and data fixing occurs. The address registers ROMC_ROMPATCHA0
 * through ROMC_ROMPATCHA15 are each 21 bits wide and dedicated to one 4 Mbyte memory space. Bits 21
 * through 2 are address bits, to be compared with romc_haddr[21:2] for a match; bit 1 is also an
 * address bit used for half word selection. Bit 0 is the mode bit (set to 1 for THUMB mode). 1-word
 * data fixing can only be used on the first 8 of the address comparators. ROMC_ROMPATCHA0 through
 * ROMC_ROMPATCHA15 are associated each with address comparators 0 through 15.
 */
typedef union _hw_romc_rompatch12a
{
    reg32_t U;
    struct _hw_romc_rompatch12a_bitfields
    {
        unsigned THUMBX : 1; //!< [0] THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM opcode patch.
        unsigned ADDRX : 22; //!< [22:1] Address Comparator Registers - Indicates the memory address to be watched.
        unsigned RESERVED0 : 9; //!< [31:23] Reserved
    } B;
} hw_romc_rompatch12a_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH12A register
 */
#define HW_ROMC_ROMPATCH12A_ADDR      (REGS_ROMC_BASE + 0x130)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH12A           (*(volatile hw_romc_rompatch12a_t *) HW_ROMC_ROMPATCH12A_ADDR)
#define HW_ROMC_ROMPATCH12A_RD()      (HW_ROMC_ROMPATCH12A.U)
#define HW_ROMC_ROMPATCH12A_WR(v)     (HW_ROMC_ROMPATCH12A.U = (v))
#define HW_ROMC_ROMPATCH12A_SET(v)    (HW_ROMC_ROMPATCH12A_WR(HW_ROMC_ROMPATCH12A_RD() |  (v)))
#define HW_ROMC_ROMPATCH12A_CLR(v)    (HW_ROMC_ROMPATCH12A_WR(HW_ROMC_ROMPATCH12A_RD() & ~(v)))
#define HW_ROMC_ROMPATCH12A_TOG(v)    (HW_ROMC_ROMPATCH12A_WR(HW_ROMC_ROMPATCH12A_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH12A bitfields
 */

/* --- Register HW_ROMC_ROMPATCH12A, field THUMBX[0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCH12A_THUMBX      (0)      //!< Bit position for ROMC_ROMPATCH12A_THUMBX.
#define BM_ROMC_ROMPATCH12A_THUMBX      (0x00000001)  //!< Bit mask for ROMC_ROMPATCH12A_THUMBX.

//! @brief Get value of ROMC_ROMPATCH12A_THUMBX from a register value.
#define BG_ROMC_ROMPATCH12A_THUMBX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH12A_THUMBX) >> BP_ROMC_ROMPATCH12A_THUMBX)

//! @brief Format value for bitfield ROMC_ROMPATCH12A_THUMBX.
#define BF_ROMC_ROMPATCH12A_THUMBX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH12A_THUMBX) & BM_ROMC_ROMPATCH12A_THUMBX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCH12A_THUMBX(v)   (HW_ROMC_ROMPATCH12A_WR((HW_ROMC_ROMPATCH12A_RD() & ~BM_ROMC_ROMPATCH12A_THUMBX) | BF_ROMC_ROMPATCH12A_THUMBX(v)))
#endif


/* --- Register HW_ROMC_ROMPATCH12A, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCH12A_ADDRX      (1)      //!< Bit position for ROMC_ROMPATCH12A_ADDRX.
#define BM_ROMC_ROMPATCH12A_ADDRX      (0x007ffffe)  //!< Bit mask for ROMC_ROMPATCH12A_ADDRX.

//! @brief Get value of ROMC_ROMPATCH12A_ADDRX from a register value.
#define BG_ROMC_ROMPATCH12A_ADDRX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH12A_ADDRX) >> BP_ROMC_ROMPATCH12A_ADDRX)

//! @brief Format value for bitfield ROMC_ROMPATCH12A_ADDRX.
#define BF_ROMC_ROMPATCH12A_ADDRX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH12A_ADDRX) & BM_ROMC_ROMPATCH12A_ADDRX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCH12A_ADDRX(v)   (HW_ROMC_ROMPATCH12A_WR((HW_ROMC_ROMPATCH12A_RD() & ~BM_ROMC_ROMPATCH12A_ADDRX) | BF_ROMC_ROMPATCH12A_ADDRX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH13A - ROMC Address Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH13A - ROMC Address Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC address registers (ROMC_ROMPATCHA0 through ROMC_ROMPATCHA15) store the memory addresses
 * where opcode patching begins and data fixing occurs. The address registers ROMC_ROMPATCHA0
 * through ROMC_ROMPATCHA15 are each 21 bits wide and dedicated to one 4 Mbyte memory space. Bits 21
 * through 2 are address bits, to be compared with romc_haddr[21:2] for a match; bit 1 is also an
 * address bit used for half word selection. Bit 0 is the mode bit (set to 1 for THUMB mode). 1-word
 * data fixing can only be used on the first 8 of the address comparators. ROMC_ROMPATCHA0 through
 * ROMC_ROMPATCHA15 are associated each with address comparators 0 through 15.
 */
typedef union _hw_romc_rompatch13a
{
    reg32_t U;
    struct _hw_romc_rompatch13a_bitfields
    {
        unsigned THUMBX : 1; //!< [0] THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM opcode patch.
        unsigned ADDRX : 22; //!< [22:1] Address Comparator Registers - Indicates the memory address to be watched.
        unsigned RESERVED0 : 9; //!< [31:23] Reserved
    } B;
} hw_romc_rompatch13a_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH13A register
 */
#define HW_ROMC_ROMPATCH13A_ADDR      (REGS_ROMC_BASE + 0x134)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH13A           (*(volatile hw_romc_rompatch13a_t *) HW_ROMC_ROMPATCH13A_ADDR)
#define HW_ROMC_ROMPATCH13A_RD()      (HW_ROMC_ROMPATCH13A.U)
#define HW_ROMC_ROMPATCH13A_WR(v)     (HW_ROMC_ROMPATCH13A.U = (v))
#define HW_ROMC_ROMPATCH13A_SET(v)    (HW_ROMC_ROMPATCH13A_WR(HW_ROMC_ROMPATCH13A_RD() |  (v)))
#define HW_ROMC_ROMPATCH13A_CLR(v)    (HW_ROMC_ROMPATCH13A_WR(HW_ROMC_ROMPATCH13A_RD() & ~(v)))
#define HW_ROMC_ROMPATCH13A_TOG(v)    (HW_ROMC_ROMPATCH13A_WR(HW_ROMC_ROMPATCH13A_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH13A bitfields
 */

/* --- Register HW_ROMC_ROMPATCH13A, field THUMBX[0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCH13A_THUMBX      (0)      //!< Bit position for ROMC_ROMPATCH13A_THUMBX.
#define BM_ROMC_ROMPATCH13A_THUMBX      (0x00000001)  //!< Bit mask for ROMC_ROMPATCH13A_THUMBX.

//! @brief Get value of ROMC_ROMPATCH13A_THUMBX from a register value.
#define BG_ROMC_ROMPATCH13A_THUMBX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH13A_THUMBX) >> BP_ROMC_ROMPATCH13A_THUMBX)

//! @brief Format value for bitfield ROMC_ROMPATCH13A_THUMBX.
#define BF_ROMC_ROMPATCH13A_THUMBX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH13A_THUMBX) & BM_ROMC_ROMPATCH13A_THUMBX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCH13A_THUMBX(v)   (HW_ROMC_ROMPATCH13A_WR((HW_ROMC_ROMPATCH13A_RD() & ~BM_ROMC_ROMPATCH13A_THUMBX) | BF_ROMC_ROMPATCH13A_THUMBX(v)))
#endif


/* --- Register HW_ROMC_ROMPATCH13A, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCH13A_ADDRX      (1)      //!< Bit position for ROMC_ROMPATCH13A_ADDRX.
#define BM_ROMC_ROMPATCH13A_ADDRX      (0x007ffffe)  //!< Bit mask for ROMC_ROMPATCH13A_ADDRX.

//! @brief Get value of ROMC_ROMPATCH13A_ADDRX from a register value.
#define BG_ROMC_ROMPATCH13A_ADDRX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH13A_ADDRX) >> BP_ROMC_ROMPATCH13A_ADDRX)

//! @brief Format value for bitfield ROMC_ROMPATCH13A_ADDRX.
#define BF_ROMC_ROMPATCH13A_ADDRX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH13A_ADDRX) & BM_ROMC_ROMPATCH13A_ADDRX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCH13A_ADDRX(v)   (HW_ROMC_ROMPATCH13A_WR((HW_ROMC_ROMPATCH13A_RD() & ~BM_ROMC_ROMPATCH13A_ADDRX) | BF_ROMC_ROMPATCH13A_ADDRX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH14A - ROMC Address Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH14A - ROMC Address Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC address registers (ROMC_ROMPATCHA0 through ROMC_ROMPATCHA15) store the memory addresses
 * where opcode patching begins and data fixing occurs. The address registers ROMC_ROMPATCHA0
 * through ROMC_ROMPATCHA15 are each 21 bits wide and dedicated to one 4 Mbyte memory space. Bits 21
 * through 2 are address bits, to be compared with romc_haddr[21:2] for a match; bit 1 is also an
 * address bit used for half word selection. Bit 0 is the mode bit (set to 1 for THUMB mode). 1-word
 * data fixing can only be used on the first 8 of the address comparators. ROMC_ROMPATCHA0 through
 * ROMC_ROMPATCHA15 are associated each with address comparators 0 through 15.
 */
typedef union _hw_romc_rompatch14a
{
    reg32_t U;
    struct _hw_romc_rompatch14a_bitfields
    {
        unsigned THUMBX : 1; //!< [0] THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM opcode patch.
        unsigned ADDRX : 22; //!< [22:1] Address Comparator Registers - Indicates the memory address to be watched.
        unsigned RESERVED0 : 9; //!< [31:23] Reserved
    } B;
} hw_romc_rompatch14a_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH14A register
 */
#define HW_ROMC_ROMPATCH14A_ADDR      (REGS_ROMC_BASE + 0x138)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH14A           (*(volatile hw_romc_rompatch14a_t *) HW_ROMC_ROMPATCH14A_ADDR)
#define HW_ROMC_ROMPATCH14A_RD()      (HW_ROMC_ROMPATCH14A.U)
#define HW_ROMC_ROMPATCH14A_WR(v)     (HW_ROMC_ROMPATCH14A.U = (v))
#define HW_ROMC_ROMPATCH14A_SET(v)    (HW_ROMC_ROMPATCH14A_WR(HW_ROMC_ROMPATCH14A_RD() |  (v)))
#define HW_ROMC_ROMPATCH14A_CLR(v)    (HW_ROMC_ROMPATCH14A_WR(HW_ROMC_ROMPATCH14A_RD() & ~(v)))
#define HW_ROMC_ROMPATCH14A_TOG(v)    (HW_ROMC_ROMPATCH14A_WR(HW_ROMC_ROMPATCH14A_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH14A bitfields
 */

/* --- Register HW_ROMC_ROMPATCH14A, field THUMBX[0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCH14A_THUMBX      (0)      //!< Bit position for ROMC_ROMPATCH14A_THUMBX.
#define BM_ROMC_ROMPATCH14A_THUMBX      (0x00000001)  //!< Bit mask for ROMC_ROMPATCH14A_THUMBX.

//! @brief Get value of ROMC_ROMPATCH14A_THUMBX from a register value.
#define BG_ROMC_ROMPATCH14A_THUMBX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH14A_THUMBX) >> BP_ROMC_ROMPATCH14A_THUMBX)

//! @brief Format value for bitfield ROMC_ROMPATCH14A_THUMBX.
#define BF_ROMC_ROMPATCH14A_THUMBX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH14A_THUMBX) & BM_ROMC_ROMPATCH14A_THUMBX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCH14A_THUMBX(v)   (HW_ROMC_ROMPATCH14A_WR((HW_ROMC_ROMPATCH14A_RD() & ~BM_ROMC_ROMPATCH14A_THUMBX) | BF_ROMC_ROMPATCH14A_THUMBX(v)))
#endif


/* --- Register HW_ROMC_ROMPATCH14A, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCH14A_ADDRX      (1)      //!< Bit position for ROMC_ROMPATCH14A_ADDRX.
#define BM_ROMC_ROMPATCH14A_ADDRX      (0x007ffffe)  //!< Bit mask for ROMC_ROMPATCH14A_ADDRX.

//! @brief Get value of ROMC_ROMPATCH14A_ADDRX from a register value.
#define BG_ROMC_ROMPATCH14A_ADDRX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH14A_ADDRX) >> BP_ROMC_ROMPATCH14A_ADDRX)

//! @brief Format value for bitfield ROMC_ROMPATCH14A_ADDRX.
#define BF_ROMC_ROMPATCH14A_ADDRX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH14A_ADDRX) & BM_ROMC_ROMPATCH14A_ADDRX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCH14A_ADDRX(v)   (HW_ROMC_ROMPATCH14A_WR((HW_ROMC_ROMPATCH14A_RD() & ~BM_ROMC_ROMPATCH14A_ADDRX) | BF_ROMC_ROMPATCH14A_ADDRX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCH15A - ROMC Address Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCH15A - ROMC Address Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * The ROMC address registers (ROMC_ROMPATCHA0 through ROMC_ROMPATCHA15) store the memory addresses
 * where opcode patching begins and data fixing occurs. The address registers ROMC_ROMPATCHA0
 * through ROMC_ROMPATCHA15 are each 21 bits wide and dedicated to one 4 Mbyte memory space. Bits 21
 * through 2 are address bits, to be compared with romc_haddr[21:2] for a match; bit 1 is also an
 * address bit used for half word selection. Bit 0 is the mode bit (set to 1 for THUMB mode). 1-word
 * data fixing can only be used on the first 8 of the address comparators. ROMC_ROMPATCHA0 through
 * ROMC_ROMPATCHA15 are associated each with address comparators 0 through 15.
 */
typedef union _hw_romc_rompatch15a
{
    reg32_t U;
    struct _hw_romc_rompatch15a_bitfields
    {
        unsigned THUMBX : 1; //!< [0] THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM opcode patch.
        unsigned ADDRX : 22; //!< [22:1] Address Comparator Registers - Indicates the memory address to be watched.
        unsigned RESERVED0 : 9; //!< [31:23] Reserved
    } B;
} hw_romc_rompatch15a_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCH15A register
 */
#define HW_ROMC_ROMPATCH15A_ADDR      (REGS_ROMC_BASE + 0x13c)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCH15A           (*(volatile hw_romc_rompatch15a_t *) HW_ROMC_ROMPATCH15A_ADDR)
#define HW_ROMC_ROMPATCH15A_RD()      (HW_ROMC_ROMPATCH15A.U)
#define HW_ROMC_ROMPATCH15A_WR(v)     (HW_ROMC_ROMPATCH15A.U = (v))
#define HW_ROMC_ROMPATCH15A_SET(v)    (HW_ROMC_ROMPATCH15A_WR(HW_ROMC_ROMPATCH15A_RD() |  (v)))
#define HW_ROMC_ROMPATCH15A_CLR(v)    (HW_ROMC_ROMPATCH15A_WR(HW_ROMC_ROMPATCH15A_RD() & ~(v)))
#define HW_ROMC_ROMPATCH15A_TOG(v)    (HW_ROMC_ROMPATCH15A_WR(HW_ROMC_ROMPATCH15A_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCH15A bitfields
 */

/* --- Register HW_ROMC_ROMPATCH15A, field THUMBX[0] (RW)
 *
 * THUMB Comparator Select - Indicates that this address will trigger a THUMB opcode patch or an ARM
 * opcode patch. If this watchpoint is selected to be a data fix, then this bit is ignored as all
 * data fixes are 1-word data fixes.
 *
 * Values:
 * 0 - ARM patch
 * 1 - THUMB patch (ignore if data fix)
 */

#define BP_ROMC_ROMPATCH15A_THUMBX      (0)      //!< Bit position for ROMC_ROMPATCH15A_THUMBX.
#define BM_ROMC_ROMPATCH15A_THUMBX      (0x00000001)  //!< Bit mask for ROMC_ROMPATCH15A_THUMBX.

//! @brief Get value of ROMC_ROMPATCH15A_THUMBX from a register value.
#define BG_ROMC_ROMPATCH15A_THUMBX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH15A_THUMBX) >> BP_ROMC_ROMPATCH15A_THUMBX)

//! @brief Format value for bitfield ROMC_ROMPATCH15A_THUMBX.
#define BF_ROMC_ROMPATCH15A_THUMBX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH15A_THUMBX) & BM_ROMC_ROMPATCH15A_THUMBX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the THUMBX field to a new value.
#define BW_ROMC_ROMPATCH15A_THUMBX(v)   (HW_ROMC_ROMPATCH15A_WR((HW_ROMC_ROMPATCH15A_RD() & ~BM_ROMC_ROMPATCH15A_THUMBX) | BF_ROMC_ROMPATCH15A_THUMBX(v)))
#endif


/* --- Register HW_ROMC_ROMPATCH15A, field ADDRX[22:1] (RW)
 *
 * Address Comparator Registers - Indicates the memory address to be watched. All 16 registers can
 * be used for code patch address comparison. Only the first 8 registers can be used for a 1-word
 * data fix address comparison. Bit 1 is ignored if data fix. Only used in code patch
 */

#define BP_ROMC_ROMPATCH15A_ADDRX      (1)      //!< Bit position for ROMC_ROMPATCH15A_ADDRX.
#define BM_ROMC_ROMPATCH15A_ADDRX      (0x007ffffe)  //!< Bit mask for ROMC_ROMPATCH15A_ADDRX.

//! @brief Get value of ROMC_ROMPATCH15A_ADDRX from a register value.
#define BG_ROMC_ROMPATCH15A_ADDRX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCH15A_ADDRX) >> BP_ROMC_ROMPATCH15A_ADDRX)

//! @brief Format value for bitfield ROMC_ROMPATCH15A_ADDRX.
#define BF_ROMC_ROMPATCH15A_ADDRX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCH15A_ADDRX) & BM_ROMC_ROMPATCH15A_ADDRX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDRX field to a new value.
#define BW_ROMC_ROMPATCH15A_ADDRX(v)   (HW_ROMC_ROMPATCH15A_WR((HW_ROMC_ROMPATCH15A_RD() & ~BM_ROMC_ROMPATCH15A_ADDRX) | BF_ROMC_ROMPATCH15A_ADDRX(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ROMC_ROMPATCHSR - ROMC Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ROMC_ROMPATCHSR - ROMC Status Register (W1C)
 *
 * Reset value: 0x00000000
 *
 * The ROMC status register (ROMC_ROMPATCHSR) indicates the current state of the ROMC and the source
 * number of the most recent address comparator event.
 */
typedef union _hw_romc_rompatchsr
{
    reg32_t U;
    struct _hw_romc_rompatchsr_bitfields
    {
        unsigned SOURCE : 6; //!< [5:0] ROMC Source Number - Binary encoding of the number of the address comparator which has an address match in the most recent patch event on ROMC AHB.
        unsigned RESERVED0 : 11; //!< [16:6] Reserved
        unsigned SW : 1; //!< [17] ROMC AHB Multiple Address Comparator matches Indicator - Indicates that multiple address comparator matches occurred.
        unsigned RESERVED1 : 14; //!< [31:18] Reserved
    } B;
} hw_romc_rompatchsr_t;
#endif

/*
 * constants & macros for entire ROMC_ROMPATCHSR register
 */
#define HW_ROMC_ROMPATCHSR_ADDR      (REGS_ROMC_BASE + 0x208)

#ifndef __LANGUAGE_ASM__
#define HW_ROMC_ROMPATCHSR           (*(volatile hw_romc_rompatchsr_t *) HW_ROMC_ROMPATCHSR_ADDR)
#define HW_ROMC_ROMPATCHSR_RD()      (HW_ROMC_ROMPATCHSR.U)
#define HW_ROMC_ROMPATCHSR_WR(v)     (HW_ROMC_ROMPATCHSR.U = (v))
#define HW_ROMC_ROMPATCHSR_SET(v)    (HW_ROMC_ROMPATCHSR_WR(HW_ROMC_ROMPATCHSR_RD() |  (v)))
#define HW_ROMC_ROMPATCHSR_CLR(v)    (HW_ROMC_ROMPATCHSR_WR(HW_ROMC_ROMPATCHSR_RD() & ~(v)))
#define HW_ROMC_ROMPATCHSR_TOG(v)    (HW_ROMC_ROMPATCHSR_WR(HW_ROMC_ROMPATCHSR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ROMC_ROMPATCHSR bitfields
 */

/* --- Register HW_ROMC_ROMPATCHSR, field SOURCE[5:0] (RO)
 *
 * ROMC Source Number - Binary encoding of the number of the address comparator which has an address
 * match in the most recent patch event on ROMC AHB. If multiple matches occurred, the highest
 * priority source number is used.
 *
 * Values:
 * 0 - Address Comparator 0 matched
 * 1 - Address Comparator 1 matched
 * 15 - Address Comparator 15 matched
 */

#define BP_ROMC_ROMPATCHSR_SOURCE      (0)      //!< Bit position for ROMC_ROMPATCHSR_SOURCE.
#define BM_ROMC_ROMPATCHSR_SOURCE      (0x0000003f)  //!< Bit mask for ROMC_ROMPATCHSR_SOURCE.

//! @brief Get value of ROMC_ROMPATCHSR_SOURCE from a register value.
#define BG_ROMC_ROMPATCHSR_SOURCE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCHSR_SOURCE) >> BP_ROMC_ROMPATCHSR_SOURCE)


/* --- Register HW_ROMC_ROMPATCHSR, field SW[17] (W1C)
 *
 * ROMC AHB Multiple Address Comparator matches Indicator - Indicates that multiple address
 * comparator matches occurred. Writing a 1 to this bit will clear this it.
 *
 * Values:
 * 0 - no event or comparator collisions
 * 1 - a collision has occurred
 */

#define BP_ROMC_ROMPATCHSR_SW      (17)      //!< Bit position for ROMC_ROMPATCHSR_SW.
#define BM_ROMC_ROMPATCHSR_SW      (0x00020000)  //!< Bit mask for ROMC_ROMPATCHSR_SW.

//! @brief Get value of ROMC_ROMPATCHSR_SW from a register value.
#define BG_ROMC_ROMPATCHSR_SW(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ROMC_ROMPATCHSR_SW) >> BP_ROMC_ROMPATCHSR_SW)

//! @brief Format value for bitfield ROMC_ROMPATCHSR_SW.
#define BF_ROMC_ROMPATCHSR_SW(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ROMC_ROMPATCHSR_SW) & BM_ROMC_ROMPATCHSR_SW)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SW field to a new value.
#define BW_ROMC_ROMPATCHSR_SW(v)   (HW_ROMC_ROMPATCHSR_WR((HW_ROMC_ROMPATCHSR_RD() & ~BM_ROMC_ROMPATCHSR_SW) | BF_ROMC_ROMPATCHSR_SW(v)))
#endif



/*!
 * @brief All ROMC module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_romc
{
    reg32_t _reserved0[53];
    volatile hw_romc_rompatch0d_t ROMPATCH0D; //!< ROMC Data Registers
    volatile hw_romc_rompatch1d_t ROMPATCH1D; //!< ROMC Data Registers
    volatile hw_romc_rompatch2d_t ROMPATCH2D; //!< ROMC Data Registers
    volatile hw_romc_rompatch3d_t ROMPATCH3D; //!< ROMC Data Registers
    volatile hw_romc_rompatch4d_t ROMPATCH4D; //!< ROMC Data Registers
    volatile hw_romc_rompatch5d_t ROMPATCH5D; //!< ROMC Data Registers
    volatile hw_romc_rompatch6d_t ROMPATCH6D; //!< ROMC Data Registers
    volatile hw_romc_rompatch7d_t ROMPATCH7D; //!< ROMC Data Registers
    volatile hw_romc_rompatchcntl_t ROMPATCHCNTL; //!< ROMC Control Register
    volatile hw_romc_rompatchenh_t ROMPATCHENH; //!< ROMC Enable Register High
    volatile hw_romc_rompatchenl_t ROMPATCHENL; //!< ROMC Enable Register Low
    volatile hw_romc_rompatch0a_t ROMPATCH0A; //!< ROMC Address Registers
    volatile hw_romc_rompatch1a_t ROMPATCH1A; //!< ROMC Address Registers
    volatile hw_romc_rompatch2a_t ROMPATCH2A; //!< ROMC Address Registers
    volatile hw_romc_rompatch3a_t ROMPATCH3A; //!< ROMC Address Registers
    volatile hw_romc_rompatch4a_t ROMPATCH4A; //!< ROMC Address Registers
    volatile hw_romc_rompatch5a_t ROMPATCH5A; //!< ROMC Address Registers
    volatile hw_romc_rompatch6a_t ROMPATCH6A; //!< ROMC Address Registers
    volatile hw_romc_rompatch7a_t ROMPATCH7A; //!< ROMC Address Registers
    volatile hw_romc_rompatch8a_t ROMPATCH8A; //!< ROMC Address Registers
    volatile hw_romc_rompatch9a_t ROMPATCH9A; //!< ROMC Address Registers
    volatile hw_romc_rompatch10a_t ROMPATCH10A; //!< ROMC Address Registers
    volatile hw_romc_rompatch11a_t ROMPATCH11A; //!< ROMC Address Registers
    volatile hw_romc_rompatch12a_t ROMPATCH12A; //!< ROMC Address Registers
    volatile hw_romc_rompatch13a_t ROMPATCH13A; //!< ROMC Address Registers
    volatile hw_romc_rompatch14a_t ROMPATCH14A; //!< ROMC Address Registers
    volatile hw_romc_rompatch15a_t ROMPATCH15A; //!< ROMC Address Registers
    reg32_t _reserved1[50];
    volatile hw_romc_rompatchsr_t ROMPATCHSR; //!< ROMC Status Register
} hw_romc_t;
#pragma pack()

//! @brief Macro to access all ROMC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_ROMC(0)</code>.
#define HW_ROMC     (*(volatile hw_romc_t *) REGS_ROMC_BASE)

#endif


#endif // __HW_ROMC_REGISTERS_H__