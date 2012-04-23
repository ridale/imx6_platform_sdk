/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_ASRC_REGISTERS_H__
#define __HW_ASRC_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6DQ ASRC registers defined in this header file.
 *
 * - HW_ASRC_ASRCTR - ASRC Control Register
 * - HW_ASRC_ASRIER - ASRC Interrupt Enable Register
 * - HW_ASRC_ASRCNCR - ASRC Channel Number Configuration Register
 * - HW_ASRC_ASRCFG - ASRC Filter Configuration Status Register
 * - HW_ASRC_ASRCSR - ASRC Clock Source Register
 * - HW_ASRC_ASRCDR1 - ASRC Clock Divider Register 1
 * - HW_ASRC_ASRCDR2 - ASRC Clock Divider Register 2
 * - HW_ASRC_ASRSTR - ASRC Status Register
 * - HW_ASRC_ASRPMN1 - ASRC Parameter Register n
 * - HW_ASRC_ASRPMN2 - ASRC Parameter Register n
 * - HW_ASRC_ASRPMN3 - ASRC Parameter Register n
 * - HW_ASRC_ASRPMN4 - ASRC Parameter Register n
 * - HW_ASRC_ASRPMN5 - ASRC Parameter Register n
 * - HW_ASRC_ASRTFR1 - ASRC ASRC Task Queue FIFO Register 1
 * - HW_ASRC_ASRCCR - ASRC Channel Counter Register
 * - HW_ASRC_ASRDIA - ASRC Data Input Register for Pair
 * - HW_ASRC_ASRDOA - ASRC Data Output Register for Pair
 * - HW_ASRC_ASRDIB - ASRC Data Input Register for Pair
 * - HW_ASRC_ASRDOB - ASRC Data Output Register for Pair
 * - HW_ASRC_ASRDIC - ASRC Data Input Register for Pair
 * - HW_ASRC_ASRDOC - ASRC Data Output Register for Pair
 * - HW_ASRC_ASRIDRHA - ASRC Ideal Ratio for Pair A-High Part
 * - HW_ASRC_ASRIDRLA - ASRC Ideal Ratio for Pair A -Low Part
 * - HW_ASRC_ASRIDRHB - ASRC Ideal Ratio for Pair B-High Part
 * - HW_ASRC_ASRIDRLB - ASRC Ideal Ratio for Pair B-Low Part
 * - HW_ASRC_ASRIDRHC - ASRC Ideal Ratio for Pair C-High Part
 * - HW_ASRC_ASRIDRLC - ASRC Ideal Ratio for Pair C-Low Part
 * - HW_ASRC_ASR76K - ASRC 76kHz Period in terms of ASRC processing clock
 * - HW_ASRC_ASR56K - ASRC 56kHz Period in terms of ASRC processing clock
 * - HW_ASRC_ASRMCRA - ASRC Misc Control Register for Pair A
 * - HW_ASRC_ASRFSTA - ASRC FIFO Status Register for Pair A
 * - HW_ASRC_ASRMCRB - ASRC Misc Control Register for Pair B
 * - HW_ASRC_ASRFSTB - ASRC FIFO Status Register for Pair B
 * - HW_ASRC_ASRMCRC - ASRC Misc Control Register for Pair C
 * - HW_ASRC_ASRFSTC - ASRC FIFO Status Register for Pair C
 * - HW_ASRC_ASRMCR1A - ASRC Misc Control Register 1 for Pair X
 * - HW_ASRC_ASRMCR1B - ASRC Misc Control Register 1 for Pair X
 * - HW_ASRC_ASRMCR1C - ASRC Misc Control Register 1 for Pair X
 *
 * - hw_asrc_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_ASRC_BASE
#define HW_ASRC_INSTANCE_COUNT (1) //!< Number of instances of the ASRC module.
#define REGS_ASRC_BASE (0x02034000) //!< Base address for ASRC.
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
// HW_ASRC_ASRCTR - ASRC Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRCTR - ASRC Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The ASRC control register (ASRCTR) is a 24-bit read/write register that controls the ASRC
 * operations.
 */
typedef union _hw_asrc_asrctr
{
    reg32_t U;
    struct _hw_asrc_asrctr_bitfields
    {
        unsigned ASRCEN : 1; //!< [0] ASRC Enable Enable the operation of ASRC.
        unsigned ASREA : 1; //!< [1] ASRC Enable A Enable the operation of the conversion A of ASRC. When ASREA is cleared, operation of conversion A is disabled.
        unsigned ASREB : 1; //!< [2] ASRC Enable B Enable the operation of the conversion B of ASRC. When ASREB is cleared, operation of conversion B is disabled.
        unsigned ASREC : 1; //!< [3] ASRC Enable C Enable the operation of the conversion C of ASRC. When ASREC is cleared, operation of conversion C is disabled.
        unsigned SRST : 1; //!< [4] Software Reset This bit is self-clear bit. Once it is been written as 1, it will generate a software reset signal inside ASRC. After 9 cycles of the ASRC processing clock, this reset process will stop, and this bit will be cleared automatically.
        unsigned RESERVED0 : 8; //!< [12:5] Reserved. Should be written as zero for compatibility.
        unsigned IDRA : 1; //!< [13] Use Ideal Ratio for Pair A When USRA=0, this bit has no usage. When USRA=1 and IDRA=0, ASRC internal measured ratio will be used. When USRA=1 and IDRA=1, the idea ratio from the interface register ASRIDRHA, ASRIDRLA will be used. It is suggested to manually set ASRCFG:POSTMODA, ASRCFG:PREMODA according to in this case.
        unsigned USRA : 1; //!< [14] Use Ratio for Pair A Use ratio as the input to ASRC. This bit is used in conjunction with IDRA control bit.
        unsigned IDRB : 1; //!< [15] Use Ideal Ratio for Pair B When USRB=0, this bit has no usage. When USRB=1 and IDRB=0, ASRC internal measured ratio will be used. When USRB=1 and IDRB=1, the idea ratio from the interface register ASRIDRHB, ASRIDRLB will be used.It is suggested to manually set ASRCFG:POSTMODB, ASRCFG:PREMODB according to in this case.
        unsigned USRB : 1; //!< [16] Use Ratio for Pair B Use ratio as the input to ASRC. This bit is used in conjunction with IDRB control bit.
        unsigned IDRC : 1; //!< [17] Use Ideal Ratio for Pair C When USRC=0, this bit has no usage. When USRC=1 and IDRC=0, ASRC internal measured ratio will be used. When USRC=1 and IDRC=1, the idea ratio from the interface register ASRIDRHC, ASRIDRLC will be used. It is suggested to manually set ASRCFG:POSTMODC, ASRCFG:PREMODC according to in this case.
        unsigned USRC : 1; //!< [18] Use Ratio for Pair C Use ratio as the input to ASRC. This bit is used in conjunction with IDRC control bit.
        unsigned RESERVED1 : 1; //!< [19] Reserved. Should be written as zero for compatibility.
        unsigned ATSA : 1; //!< [20] ASRC Pair A Automatic Selection For Processing Options When this bit is 1, pair A will automatic update its pre-processing and post-processing options (ASRCFG: PREMODA, ASRCFG:POSTMODA , ASRCFG:HFA see ASRC Misc Control Register 1 for Pair C ) based on the frequencies it detected. To use this option, the two parameter registers(ASR76K and ASR56K) should be set correctly (see ASRC Misc Control Register 1 for Pair C and ASRC Misc Control Register 1 for Pair C ). When this bit is 0, the user is responsible for choosing the proper processing options for pair A. This bit should be disabled when {USRA, IDRA}={1,1}.
        unsigned ATSB : 1; //!< [21] ASRC Pair B Automatic Selection For Processing Options When this bit is 1, pair B will automatic update its pre-processing and post-processing options (ASRCFG: PREMODB, ASRCFG:POSTMODB , ASRCFG:HFB see ASRC Misc Control Register 1 for Pair C ) based on the frequencies it detected. To use this option, the two parameter registers(ASR76K and ASR56K) should be set correctly (see ASRC Misc Control Register 1 for Pair C and ASRC Misc Control Register 1 for Pair C ). When this bit is 0, the user is responsible for choosing the proper processing options for pair B. This bit should be disabled when {USRB, IDRB}={1,1}.
        unsigned ATSC : 1; //!< [22] ASRC Pair C Automatic Selection For Processing Options When this bit is 1, pair C will automatic update its pre-processing and post-processing options (ASRCFG: PREMODC, ASRCFG:POSTMODC , ASRCFG:HFC see ASRC Misc Control Register 1 for Pair C ) based on the frequencies it detected. To use this option, the two parameter registers(ASR76K and ASR56K) should be set correctly (see ASRC Misc Control Register 1 for Pair C and ASRC Misc Control Register 1 for Pair C ). When this bit is 0, the user is responsible for choosing the proper processing options for pair C. This bit should be disabled when {USRC, IDRC}={1,1}.
        unsigned RESERVED2 : 1; //!< [23] Reserved. Should be written as zero for compatibility.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrctr_t;
#endif

/*
 * constants & macros for entire ASRC_ASRCTR register
 */
#define HW_ASRC_ASRCTR_ADDR      (REGS_ASRC_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRCTR           (*(volatile hw_asrc_asrctr_t *) HW_ASRC_ASRCTR_ADDR)
#define HW_ASRC_ASRCTR_RD()      (HW_ASRC_ASRCTR.U)
#define HW_ASRC_ASRCTR_WR(v)     (HW_ASRC_ASRCTR.U = (v))
#define HW_ASRC_ASRCTR_SET(v)    (HW_ASRC_ASRCTR_WR(HW_ASRC_ASRCTR_RD() |  (v)))
#define HW_ASRC_ASRCTR_CLR(v)    (HW_ASRC_ASRCTR_WR(HW_ASRC_ASRCTR_RD() & ~(v)))
#define HW_ASRC_ASRCTR_TOG(v)    (HW_ASRC_ASRCTR_WR(HW_ASRC_ASRCTR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRCTR bitfields
 */

/* --- Register HW_ASRC_ASRCTR, field ASRCEN[0] (RW)
 *
 * ASRC Enable Enable the operation of ASRC.
 */

#define BP_ASRC_ASRCTR_ASRCEN      (0)      //!< Bit position for ASRC_ASRCTR_ASRCEN.
#define BM_ASRC_ASRCTR_ASRCEN      (0x00000001)  //!< Bit mask for ASRC_ASRCTR_ASRCEN.

//! @brief Get value of ASRC_ASRCTR_ASRCEN from a register value.
#define BG_ASRC_ASRCTR_ASRCEN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCTR_ASRCEN) >> BP_ASRC_ASRCTR_ASRCEN)

//! @brief Format value for bitfield ASRC_ASRCTR_ASRCEN.
#define BF_ASRC_ASRCTR_ASRCEN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCTR_ASRCEN) & BM_ASRC_ASRCTR_ASRCEN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ASRCEN field to a new value.
#define BW_ASRC_ASRCTR_ASRCEN(v)   (HW_ASRC_ASRCTR_WR((HW_ASRC_ASRCTR_RD() & ~BM_ASRC_ASRCTR_ASRCEN) | BF_ASRC_ASRCTR_ASRCEN(v)))
#endif

/* --- Register HW_ASRC_ASRCTR, field ASREA[1] (RW)
 *
 * ASRC Enable A Enable the operation of the conversion A of ASRC. When ASREA is cleared, operation
 * of conversion A is disabled.
 */

#define BP_ASRC_ASRCTR_ASREA      (1)      //!< Bit position for ASRC_ASRCTR_ASREA.
#define BM_ASRC_ASRCTR_ASREA      (0x00000002)  //!< Bit mask for ASRC_ASRCTR_ASREA.

//! @brief Get value of ASRC_ASRCTR_ASREA from a register value.
#define BG_ASRC_ASRCTR_ASREA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCTR_ASREA) >> BP_ASRC_ASRCTR_ASREA)

//! @brief Format value for bitfield ASRC_ASRCTR_ASREA.
#define BF_ASRC_ASRCTR_ASREA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCTR_ASREA) & BM_ASRC_ASRCTR_ASREA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ASREA field to a new value.
#define BW_ASRC_ASRCTR_ASREA(v)   (HW_ASRC_ASRCTR_WR((HW_ASRC_ASRCTR_RD() & ~BM_ASRC_ASRCTR_ASREA) | BF_ASRC_ASRCTR_ASREA(v)))
#endif

/* --- Register HW_ASRC_ASRCTR, field ASREB[2] (RW)
 *
 * ASRC Enable B Enable the operation of the conversion B of ASRC. When ASREB is cleared, operation
 * of conversion B is disabled.
 */

#define BP_ASRC_ASRCTR_ASREB      (2)      //!< Bit position for ASRC_ASRCTR_ASREB.
#define BM_ASRC_ASRCTR_ASREB      (0x00000004)  //!< Bit mask for ASRC_ASRCTR_ASREB.

//! @brief Get value of ASRC_ASRCTR_ASREB from a register value.
#define BG_ASRC_ASRCTR_ASREB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCTR_ASREB) >> BP_ASRC_ASRCTR_ASREB)

//! @brief Format value for bitfield ASRC_ASRCTR_ASREB.
#define BF_ASRC_ASRCTR_ASREB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCTR_ASREB) & BM_ASRC_ASRCTR_ASREB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ASREB field to a new value.
#define BW_ASRC_ASRCTR_ASREB(v)   (HW_ASRC_ASRCTR_WR((HW_ASRC_ASRCTR_RD() & ~BM_ASRC_ASRCTR_ASREB) | BF_ASRC_ASRCTR_ASREB(v)))
#endif

/* --- Register HW_ASRC_ASRCTR, field ASREC[3] (RW)
 *
 * ASRC Enable C Enable the operation of the conversion C of ASRC. When ASREC is cleared, operation
 * of conversion C is disabled.
 */

#define BP_ASRC_ASRCTR_ASREC      (3)      //!< Bit position for ASRC_ASRCTR_ASREC.
#define BM_ASRC_ASRCTR_ASREC      (0x00000008)  //!< Bit mask for ASRC_ASRCTR_ASREC.

//! @brief Get value of ASRC_ASRCTR_ASREC from a register value.
#define BG_ASRC_ASRCTR_ASREC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCTR_ASREC) >> BP_ASRC_ASRCTR_ASREC)

//! @brief Format value for bitfield ASRC_ASRCTR_ASREC.
#define BF_ASRC_ASRCTR_ASREC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCTR_ASREC) & BM_ASRC_ASRCTR_ASREC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ASREC field to a new value.
#define BW_ASRC_ASRCTR_ASREC(v)   (HW_ASRC_ASRCTR_WR((HW_ASRC_ASRCTR_RD() & ~BM_ASRC_ASRCTR_ASREC) | BF_ASRC_ASRCTR_ASREC(v)))
#endif

/* --- Register HW_ASRC_ASRCTR, field SRST[4] (WO)
 *
 * Software Reset This bit is self-clear bit. Once it is been written as 1, it will generate a
 * software reset signal inside ASRC. After 9 cycles of the ASRC processing clock, this reset
 * process will stop, and this bit will be cleared automatically.
 */

#define BP_ASRC_ASRCTR_SRST      (4)      //!< Bit position for ASRC_ASRCTR_SRST.
#define BM_ASRC_ASRCTR_SRST      (0x00000010)  //!< Bit mask for ASRC_ASRCTR_SRST.

//! @brief Get value of ASRC_ASRCTR_SRST from a register value.
#define BG_ASRC_ASRCTR_SRST(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCTR_SRST) >> BP_ASRC_ASRCTR_SRST)

//! @brief Format value for bitfield ASRC_ASRCTR_SRST.
#define BF_ASRC_ASRCTR_SRST(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCTR_SRST) & BM_ASRC_ASRCTR_SRST)

/* --- Register HW_ASRC_ASRCTR, field IDRA[13] (RW)
 *
 * Use Ideal Ratio for Pair A When USRA=0, this bit has no usage. When USRA=1 and IDRA=0, ASRC
 * internal measured ratio will be used. When USRA=1 and IDRA=1, the idea ratio from the interface
 * register ASRIDRHA, ASRIDRLA will be used. It is suggested to manually set ASRCFG:POSTMODA,
 * ASRCFG:PREMODA according to in this case.
 */

#define BP_ASRC_ASRCTR_IDRA      (13)      //!< Bit position for ASRC_ASRCTR_IDRA.
#define BM_ASRC_ASRCTR_IDRA      (0x00002000)  //!< Bit mask for ASRC_ASRCTR_IDRA.

//! @brief Get value of ASRC_ASRCTR_IDRA from a register value.
#define BG_ASRC_ASRCTR_IDRA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCTR_IDRA) >> BP_ASRC_ASRCTR_IDRA)

//! @brief Format value for bitfield ASRC_ASRCTR_IDRA.
#define BF_ASRC_ASRCTR_IDRA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCTR_IDRA) & BM_ASRC_ASRCTR_IDRA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IDRA field to a new value.
#define BW_ASRC_ASRCTR_IDRA(v)   (HW_ASRC_ASRCTR_WR((HW_ASRC_ASRCTR_RD() & ~BM_ASRC_ASRCTR_IDRA) | BF_ASRC_ASRCTR_IDRA(v)))
#endif

/* --- Register HW_ASRC_ASRCTR, field USRA[14] (RW)
 *
 * Use Ratio for Pair A Use ratio as the input to ASRC. This bit is used in conjunction with IDRA
 * control bit.
 */

#define BP_ASRC_ASRCTR_USRA      (14)      //!< Bit position for ASRC_ASRCTR_USRA.
#define BM_ASRC_ASRCTR_USRA      (0x00004000)  //!< Bit mask for ASRC_ASRCTR_USRA.

//! @brief Get value of ASRC_ASRCTR_USRA from a register value.
#define BG_ASRC_ASRCTR_USRA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCTR_USRA) >> BP_ASRC_ASRCTR_USRA)

//! @brief Format value for bitfield ASRC_ASRCTR_USRA.
#define BF_ASRC_ASRCTR_USRA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCTR_USRA) & BM_ASRC_ASRCTR_USRA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the USRA field to a new value.
#define BW_ASRC_ASRCTR_USRA(v)   (HW_ASRC_ASRCTR_WR((HW_ASRC_ASRCTR_RD() & ~BM_ASRC_ASRCTR_USRA) | BF_ASRC_ASRCTR_USRA(v)))
#endif

/* --- Register HW_ASRC_ASRCTR, field IDRB[15] (RW)
 *
 * Use Ideal Ratio for Pair B When USRB=0, this bit has no usage. When USRB=1 and IDRB=0, ASRC
 * internal measured ratio will be used. When USRB=1 and IDRB=1, the idea ratio from the interface
 * register ASRIDRHB, ASRIDRLB will be used.It is suggested to manually set ASRCFG:POSTMODB,
 * ASRCFG:PREMODB according to in this case.
 */

#define BP_ASRC_ASRCTR_IDRB      (15)      //!< Bit position for ASRC_ASRCTR_IDRB.
#define BM_ASRC_ASRCTR_IDRB      (0x00008000)  //!< Bit mask for ASRC_ASRCTR_IDRB.

//! @brief Get value of ASRC_ASRCTR_IDRB from a register value.
#define BG_ASRC_ASRCTR_IDRB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCTR_IDRB) >> BP_ASRC_ASRCTR_IDRB)

//! @brief Format value for bitfield ASRC_ASRCTR_IDRB.
#define BF_ASRC_ASRCTR_IDRB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCTR_IDRB) & BM_ASRC_ASRCTR_IDRB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IDRB field to a new value.
#define BW_ASRC_ASRCTR_IDRB(v)   (HW_ASRC_ASRCTR_WR((HW_ASRC_ASRCTR_RD() & ~BM_ASRC_ASRCTR_IDRB) | BF_ASRC_ASRCTR_IDRB(v)))
#endif

/* --- Register HW_ASRC_ASRCTR, field USRB[16] (RW)
 *
 * Use Ratio for Pair B Use ratio as the input to ASRC. This bit is used in conjunction with IDRB
 * control bit.
 */

#define BP_ASRC_ASRCTR_USRB      (16)      //!< Bit position for ASRC_ASRCTR_USRB.
#define BM_ASRC_ASRCTR_USRB      (0x00010000)  //!< Bit mask for ASRC_ASRCTR_USRB.

//! @brief Get value of ASRC_ASRCTR_USRB from a register value.
#define BG_ASRC_ASRCTR_USRB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCTR_USRB) >> BP_ASRC_ASRCTR_USRB)

//! @brief Format value for bitfield ASRC_ASRCTR_USRB.
#define BF_ASRC_ASRCTR_USRB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCTR_USRB) & BM_ASRC_ASRCTR_USRB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the USRB field to a new value.
#define BW_ASRC_ASRCTR_USRB(v)   (HW_ASRC_ASRCTR_WR((HW_ASRC_ASRCTR_RD() & ~BM_ASRC_ASRCTR_USRB) | BF_ASRC_ASRCTR_USRB(v)))
#endif

/* --- Register HW_ASRC_ASRCTR, field IDRC[17] (RW)
 *
 * Use Ideal Ratio for Pair C When USRC=0, this bit has no usage. When USRC=1 and IDRC=0, ASRC
 * internal measured ratio will be used. When USRC=1 and IDRC=1, the idea ratio from the interface
 * register ASRIDRHC, ASRIDRLC will be used. It is suggested to manually set ASRCFG:POSTMODC,
 * ASRCFG:PREMODC according to in this case.
 */

#define BP_ASRC_ASRCTR_IDRC      (17)      //!< Bit position for ASRC_ASRCTR_IDRC.
#define BM_ASRC_ASRCTR_IDRC      (0x00020000)  //!< Bit mask for ASRC_ASRCTR_IDRC.

//! @brief Get value of ASRC_ASRCTR_IDRC from a register value.
#define BG_ASRC_ASRCTR_IDRC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCTR_IDRC) >> BP_ASRC_ASRCTR_IDRC)

//! @brief Format value for bitfield ASRC_ASRCTR_IDRC.
#define BF_ASRC_ASRCTR_IDRC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCTR_IDRC) & BM_ASRC_ASRCTR_IDRC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IDRC field to a new value.
#define BW_ASRC_ASRCTR_IDRC(v)   (HW_ASRC_ASRCTR_WR((HW_ASRC_ASRCTR_RD() & ~BM_ASRC_ASRCTR_IDRC) | BF_ASRC_ASRCTR_IDRC(v)))
#endif

/* --- Register HW_ASRC_ASRCTR, field USRC[18] (RW)
 *
 * Use Ratio for Pair C Use ratio as the input to ASRC. This bit is used in conjunction with IDRC
 * control bit.
 */

#define BP_ASRC_ASRCTR_USRC      (18)      //!< Bit position for ASRC_ASRCTR_USRC.
#define BM_ASRC_ASRCTR_USRC      (0x00040000)  //!< Bit mask for ASRC_ASRCTR_USRC.

//! @brief Get value of ASRC_ASRCTR_USRC from a register value.
#define BG_ASRC_ASRCTR_USRC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCTR_USRC) >> BP_ASRC_ASRCTR_USRC)

//! @brief Format value for bitfield ASRC_ASRCTR_USRC.
#define BF_ASRC_ASRCTR_USRC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCTR_USRC) & BM_ASRC_ASRCTR_USRC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the USRC field to a new value.
#define BW_ASRC_ASRCTR_USRC(v)   (HW_ASRC_ASRCTR_WR((HW_ASRC_ASRCTR_RD() & ~BM_ASRC_ASRCTR_USRC) | BF_ASRC_ASRCTR_USRC(v)))
#endif

/* --- Register HW_ASRC_ASRCTR, field ATSA[20] (RW)
 *
 * ASRC Pair A Automatic Selection For Processing Options When this bit is 1, pair A will automatic
 * update its pre-processing and post-processing options (ASRCFG: PREMODA, ASRCFG:POSTMODA ,
 * ASRCFG:HFA see ASRC Misc Control Register 1 for Pair C ) based on the frequencies it detected. To
 * use this option, the two parameter registers(ASR76K and ASR56K) should be set correctly (see ASRC
 * Misc Control Register 1 for Pair C and ASRC Misc Control Register 1 for Pair C ). When this bit
 * is 0, the user is responsible for choosing the proper processing options for pair A. This bit
 * should be disabled when {USRA, IDRA}={1,1}.
 */

#define BP_ASRC_ASRCTR_ATSA      (20)      //!< Bit position for ASRC_ASRCTR_ATSA.
#define BM_ASRC_ASRCTR_ATSA      (0x00100000)  //!< Bit mask for ASRC_ASRCTR_ATSA.

//! @brief Get value of ASRC_ASRCTR_ATSA from a register value.
#define BG_ASRC_ASRCTR_ATSA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCTR_ATSA) >> BP_ASRC_ASRCTR_ATSA)

//! @brief Format value for bitfield ASRC_ASRCTR_ATSA.
#define BF_ASRC_ASRCTR_ATSA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCTR_ATSA) & BM_ASRC_ASRCTR_ATSA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATSA field to a new value.
#define BW_ASRC_ASRCTR_ATSA(v)   (HW_ASRC_ASRCTR_WR((HW_ASRC_ASRCTR_RD() & ~BM_ASRC_ASRCTR_ATSA) | BF_ASRC_ASRCTR_ATSA(v)))
#endif

/* --- Register HW_ASRC_ASRCTR, field ATSB[21] (RW)
 *
 * ASRC Pair B Automatic Selection For Processing Options When this bit is 1, pair B will automatic
 * update its pre-processing and post-processing options (ASRCFG: PREMODB, ASRCFG:POSTMODB ,
 * ASRCFG:HFB see ASRC Misc Control Register 1 for Pair C ) based on the frequencies it detected. To
 * use this option, the two parameter registers(ASR76K and ASR56K) should be set correctly (see ASRC
 * Misc Control Register 1 for Pair C and ASRC Misc Control Register 1 for Pair C ). When this bit
 * is 0, the user is responsible for choosing the proper processing options for pair B. This bit
 * should be disabled when {USRB, IDRB}={1,1}.
 */

#define BP_ASRC_ASRCTR_ATSB      (21)      //!< Bit position for ASRC_ASRCTR_ATSB.
#define BM_ASRC_ASRCTR_ATSB      (0x00200000)  //!< Bit mask for ASRC_ASRCTR_ATSB.

//! @brief Get value of ASRC_ASRCTR_ATSB from a register value.
#define BG_ASRC_ASRCTR_ATSB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCTR_ATSB) >> BP_ASRC_ASRCTR_ATSB)

//! @brief Format value for bitfield ASRC_ASRCTR_ATSB.
#define BF_ASRC_ASRCTR_ATSB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCTR_ATSB) & BM_ASRC_ASRCTR_ATSB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATSB field to a new value.
#define BW_ASRC_ASRCTR_ATSB(v)   (HW_ASRC_ASRCTR_WR((HW_ASRC_ASRCTR_RD() & ~BM_ASRC_ASRCTR_ATSB) | BF_ASRC_ASRCTR_ATSB(v)))
#endif

/* --- Register HW_ASRC_ASRCTR, field ATSC[22] (RW)
 *
 * ASRC Pair C Automatic Selection For Processing Options When this bit is 1, pair C will automatic
 * update its pre-processing and post-processing options (ASRCFG: PREMODC, ASRCFG:POSTMODC ,
 * ASRCFG:HFC see ASRC Misc Control Register 1 for Pair C ) based on the frequencies it detected. To
 * use this option, the two parameter registers(ASR76K and ASR56K) should be set correctly (see ASRC
 * Misc Control Register 1 for Pair C and ASRC Misc Control Register 1 for Pair C ). When this bit
 * is 0, the user is responsible for choosing the proper processing options for pair C. This bit
 * should be disabled when {USRC, IDRC}={1,1}.
 */

#define BP_ASRC_ASRCTR_ATSC      (22)      //!< Bit position for ASRC_ASRCTR_ATSC.
#define BM_ASRC_ASRCTR_ATSC      (0x00400000)  //!< Bit mask for ASRC_ASRCTR_ATSC.

//! @brief Get value of ASRC_ASRCTR_ATSC from a register value.
#define BG_ASRC_ASRCTR_ATSC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCTR_ATSC) >> BP_ASRC_ASRCTR_ATSC)

//! @brief Format value for bitfield ASRC_ASRCTR_ATSC.
#define BF_ASRC_ASRCTR_ATSC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCTR_ATSC) & BM_ASRC_ASRCTR_ATSC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATSC field to a new value.
#define BW_ASRC_ASRCTR_ATSC(v)   (HW_ASRC_ASRCTR_WR((HW_ASRC_ASRCTR_RD() & ~BM_ASRC_ASRCTR_ATSC) | BF_ASRC_ASRCTR_ATSC(v)))
#endif

/* --- Register HW_ASRC_ASRCTR, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRCTR_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRCTR_UNIMPLEMENTED.
#define BM_ASRC_ASRCTR_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRCTR_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRCTR_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRCTR_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCTR_UNIMPLEMENTED) >> BP_ASRC_ASRCTR_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRIER - ASRC Interrupt Enable Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRIER - ASRC Interrupt Enable Register (RW)
 *
 * Reset value: 0x00000000
 *
 * These 8 bits combined with corresponding 8 LSBs in ASRSTR register can generate interrupt
 * requests.
 */
typedef union _hw_asrc_asrier
{
    reg32_t U;
    struct _hw_asrc_asrier_bitfields
    {
        unsigned ADIEA : 1; //!< [0] Data Input A Interrupt Enable Enables the data input A Interrupt.
        unsigned ADIEB : 1; //!< [1] Data Input B Interrupt Enable Enables the data input B interrupt.
        unsigned ADIEC : 1; //!< [2] Data Input C Interrupt Enable Enables the data input C interrupt.
        unsigned ADOEA : 1; //!< [3] Data Output A Interrupt Enable Enables the data output A interrupt.
        unsigned ADOEB : 1; //!< [4] Data Output B Interrupt Enable Enables the data output B interrupt.
        unsigned ADOEC : 1; //!< [5] Data Output C Interrupt Enable Enables the data output C interrupt.
        unsigned AOLIE : 1; //!< [6] Overload Interrupt Enable Enables the overload interrupt.
        unsigned AFPWE : 1; //!< [7] FP in Wait State Interrupt Enable Enables the FP in wait state interrupt.
        unsigned RESERVED0 : 16; //!< [23:8] Reserved. Should be written as zero for compatibility.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrier_t;
#endif

/*
 * constants & macros for entire ASRC_ASRIER register
 */
#define HW_ASRC_ASRIER_ADDR      (REGS_ASRC_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRIER           (*(volatile hw_asrc_asrier_t *) HW_ASRC_ASRIER_ADDR)
#define HW_ASRC_ASRIER_RD()      (HW_ASRC_ASRIER.U)
#define HW_ASRC_ASRIER_WR(v)     (HW_ASRC_ASRIER.U = (v))
#define HW_ASRC_ASRIER_SET(v)    (HW_ASRC_ASRIER_WR(HW_ASRC_ASRIER_RD() |  (v)))
#define HW_ASRC_ASRIER_CLR(v)    (HW_ASRC_ASRIER_WR(HW_ASRC_ASRIER_RD() & ~(v)))
#define HW_ASRC_ASRIER_TOG(v)    (HW_ASRC_ASRIER_WR(HW_ASRC_ASRIER_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRIER bitfields
 */

/* --- Register HW_ASRC_ASRIER, field ADIEA[0] (RW)
 *
 * Data Input A Interrupt Enable Enables the data input A Interrupt.
 *
 * Values:
 * 0 - interrupt disabled
 * 1 - interrupt enabled
 */

#define BP_ASRC_ASRIER_ADIEA      (0)      //!< Bit position for ASRC_ASRIER_ADIEA.
#define BM_ASRC_ASRIER_ADIEA      (0x00000001)  //!< Bit mask for ASRC_ASRIER_ADIEA.

//! @brief Get value of ASRC_ASRIER_ADIEA from a register value.
#define BG_ASRC_ASRIER_ADIEA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIER_ADIEA) >> BP_ASRC_ASRIER_ADIEA)

//! @brief Format value for bitfield ASRC_ASRIER_ADIEA.
#define BF_ASRC_ASRIER_ADIEA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRIER_ADIEA) & BM_ASRC_ASRIER_ADIEA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADIEA field to a new value.
#define BW_ASRC_ASRIER_ADIEA(v)   (HW_ASRC_ASRIER_WR((HW_ASRC_ASRIER_RD() & ~BM_ASRC_ASRIER_ADIEA) | BF_ASRC_ASRIER_ADIEA(v)))
#endif


/* --- Register HW_ASRC_ASRIER, field ADIEB[1] (RW)
 *
 * Data Input B Interrupt Enable Enables the data input B interrupt.
 *
 * Values:
 * 0 - interrupt disabled
 * 1 - interrupt enabled
 */

#define BP_ASRC_ASRIER_ADIEB      (1)      //!< Bit position for ASRC_ASRIER_ADIEB.
#define BM_ASRC_ASRIER_ADIEB      (0x00000002)  //!< Bit mask for ASRC_ASRIER_ADIEB.

//! @brief Get value of ASRC_ASRIER_ADIEB from a register value.
#define BG_ASRC_ASRIER_ADIEB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIER_ADIEB) >> BP_ASRC_ASRIER_ADIEB)

//! @brief Format value for bitfield ASRC_ASRIER_ADIEB.
#define BF_ASRC_ASRIER_ADIEB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRIER_ADIEB) & BM_ASRC_ASRIER_ADIEB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADIEB field to a new value.
#define BW_ASRC_ASRIER_ADIEB(v)   (HW_ASRC_ASRIER_WR((HW_ASRC_ASRIER_RD() & ~BM_ASRC_ASRIER_ADIEB) | BF_ASRC_ASRIER_ADIEB(v)))
#endif


/* --- Register HW_ASRC_ASRIER, field ADIEC[2] (RW)
 *
 * Data Input C Interrupt Enable Enables the data input C interrupt.
 *
 * Values:
 * 0 - interrupt disabled
 * 1 - interrupt enabled
 */

#define BP_ASRC_ASRIER_ADIEC      (2)      //!< Bit position for ASRC_ASRIER_ADIEC.
#define BM_ASRC_ASRIER_ADIEC      (0x00000004)  //!< Bit mask for ASRC_ASRIER_ADIEC.

//! @brief Get value of ASRC_ASRIER_ADIEC from a register value.
#define BG_ASRC_ASRIER_ADIEC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIER_ADIEC) >> BP_ASRC_ASRIER_ADIEC)

//! @brief Format value for bitfield ASRC_ASRIER_ADIEC.
#define BF_ASRC_ASRIER_ADIEC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRIER_ADIEC) & BM_ASRC_ASRIER_ADIEC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADIEC field to a new value.
#define BW_ASRC_ASRIER_ADIEC(v)   (HW_ASRC_ASRIER_WR((HW_ASRC_ASRIER_RD() & ~BM_ASRC_ASRIER_ADIEC) | BF_ASRC_ASRIER_ADIEC(v)))
#endif


/* --- Register HW_ASRC_ASRIER, field ADOEA[3] (RW)
 *
 * Data Output A Interrupt Enable Enables the data output A interrupt.
 *
 * Values:
 * 0 - interrupt disabled
 * 1 - interrupt enabled
 */

#define BP_ASRC_ASRIER_ADOEA      (3)      //!< Bit position for ASRC_ASRIER_ADOEA.
#define BM_ASRC_ASRIER_ADOEA      (0x00000008)  //!< Bit mask for ASRC_ASRIER_ADOEA.

//! @brief Get value of ASRC_ASRIER_ADOEA from a register value.
#define BG_ASRC_ASRIER_ADOEA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIER_ADOEA) >> BP_ASRC_ASRIER_ADOEA)

//! @brief Format value for bitfield ASRC_ASRIER_ADOEA.
#define BF_ASRC_ASRIER_ADOEA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRIER_ADOEA) & BM_ASRC_ASRIER_ADOEA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADOEA field to a new value.
#define BW_ASRC_ASRIER_ADOEA(v)   (HW_ASRC_ASRIER_WR((HW_ASRC_ASRIER_RD() & ~BM_ASRC_ASRIER_ADOEA) | BF_ASRC_ASRIER_ADOEA(v)))
#endif


/* --- Register HW_ASRC_ASRIER, field ADOEB[4] (RW)
 *
 * Data Output B Interrupt Enable Enables the data output B interrupt.
 *
 * Values:
 * 0 - interrupt disabled
 * 1 - interrupt enabled
 */

#define BP_ASRC_ASRIER_ADOEB      (4)      //!< Bit position for ASRC_ASRIER_ADOEB.
#define BM_ASRC_ASRIER_ADOEB      (0x00000010)  //!< Bit mask for ASRC_ASRIER_ADOEB.

//! @brief Get value of ASRC_ASRIER_ADOEB from a register value.
#define BG_ASRC_ASRIER_ADOEB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIER_ADOEB) >> BP_ASRC_ASRIER_ADOEB)

//! @brief Format value for bitfield ASRC_ASRIER_ADOEB.
#define BF_ASRC_ASRIER_ADOEB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRIER_ADOEB) & BM_ASRC_ASRIER_ADOEB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADOEB field to a new value.
#define BW_ASRC_ASRIER_ADOEB(v)   (HW_ASRC_ASRIER_WR((HW_ASRC_ASRIER_RD() & ~BM_ASRC_ASRIER_ADOEB) | BF_ASRC_ASRIER_ADOEB(v)))
#endif


/* --- Register HW_ASRC_ASRIER, field ADOEC[5] (RW)
 *
 * Data Output C Interrupt Enable Enables the data output C interrupt.
 *
 * Values:
 * 0 - interrupt disabled
 * 1 - interrupt enabled
 */

#define BP_ASRC_ASRIER_ADOEC      (5)      //!< Bit position for ASRC_ASRIER_ADOEC.
#define BM_ASRC_ASRIER_ADOEC      (0x00000020)  //!< Bit mask for ASRC_ASRIER_ADOEC.

//! @brief Get value of ASRC_ASRIER_ADOEC from a register value.
#define BG_ASRC_ASRIER_ADOEC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIER_ADOEC) >> BP_ASRC_ASRIER_ADOEC)

//! @brief Format value for bitfield ASRC_ASRIER_ADOEC.
#define BF_ASRC_ASRIER_ADOEC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRIER_ADOEC) & BM_ASRC_ASRIER_ADOEC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADOEC field to a new value.
#define BW_ASRC_ASRIER_ADOEC(v)   (HW_ASRC_ASRIER_WR((HW_ASRC_ASRIER_RD() & ~BM_ASRC_ASRIER_ADOEC) | BF_ASRC_ASRIER_ADOEC(v)))
#endif


/* --- Register HW_ASRC_ASRIER, field AOLIE[6] (RW)
 *
 * Overload Interrupt Enable Enables the overload interrupt.
 *
 * Values:
 * 0 - interrupt disabled
 * 1 - interrupt enabled
 */

#define BP_ASRC_ASRIER_AOLIE      (6)      //!< Bit position for ASRC_ASRIER_AOLIE.
#define BM_ASRC_ASRIER_AOLIE      (0x00000040)  //!< Bit mask for ASRC_ASRIER_AOLIE.

//! @brief Get value of ASRC_ASRIER_AOLIE from a register value.
#define BG_ASRC_ASRIER_AOLIE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIER_AOLIE) >> BP_ASRC_ASRIER_AOLIE)

//! @brief Format value for bitfield ASRC_ASRIER_AOLIE.
#define BF_ASRC_ASRIER_AOLIE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRIER_AOLIE) & BM_ASRC_ASRIER_AOLIE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AOLIE field to a new value.
#define BW_ASRC_ASRIER_AOLIE(v)   (HW_ASRC_ASRIER_WR((HW_ASRC_ASRIER_RD() & ~BM_ASRC_ASRIER_AOLIE) | BF_ASRC_ASRIER_AOLIE(v)))
#endif


/* --- Register HW_ASRC_ASRIER, field AFPWE[7] (RW)
 *
 * FP in Wait State Interrupt Enable Enables the FP in wait state interrupt.
 *
 * Values:
 * 0 - interrupt disabled
 * 1 - interrupt enabled
 */

#define BP_ASRC_ASRIER_AFPWE      (7)      //!< Bit position for ASRC_ASRIER_AFPWE.
#define BM_ASRC_ASRIER_AFPWE      (0x00000080)  //!< Bit mask for ASRC_ASRIER_AFPWE.

//! @brief Get value of ASRC_ASRIER_AFPWE from a register value.
#define BG_ASRC_ASRIER_AFPWE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIER_AFPWE) >> BP_ASRC_ASRIER_AFPWE)

//! @brief Format value for bitfield ASRC_ASRIER_AFPWE.
#define BF_ASRC_ASRIER_AFPWE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRIER_AFPWE) & BM_ASRC_ASRIER_AFPWE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AFPWE field to a new value.
#define BW_ASRC_ASRIER_AFPWE(v)   (HW_ASRC_ASRIER_WR((HW_ASRC_ASRIER_RD() & ~BM_ASRC_ASRIER_AFPWE) | BF_ASRC_ASRIER_AFPWE(v)))
#endif


/* --- Register HW_ASRC_ASRIER, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRIER_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRIER_UNIMPLEMENTED.
#define BM_ASRC_ASRIER_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRIER_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRIER_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRIER_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIER_UNIMPLEMENTED) >> BP_ASRC_ASRIER_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRCNCR - ASRC Channel Number Configuration Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRCNCR - ASRC Channel Number Configuration Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The ASRC channel number configuration register (ASRCNCR) is a 24-bit read/write register that
 * sets the number of channels used by each ASRC conversion pair.  There are 10 channels available
 * for distribution among 3 conversion pairs, they are ordered as 0,1,...,9. The bottom [0, ANCA-1]
 * channels are used for pair A, the top [10-ANCC, 9] channels are used for pair C, and the [ANCA,
 * ANCA+ANCB-1] channels are allocated for pair B. In case that ANCA=0, then the [0, ANCB-1]
 * channels are assigned for pair B.
 */
typedef union _hw_asrc_asrcncr
{
    reg32_t U;
    struct _hw_asrc_asrcncr_bitfields
    {
        unsigned ANCA : 3; //!< [2:0] Number of A Channels
        unsigned ANCB : 3; //!< [5:3] Number of B Channels
        unsigned ANCC : 3; //!< [8:6] Number of C Channels ANCC+ANCB+ANCA<=10. Hardware is not checking the constraint. Programmer should take the responsibility to ensure the constraint is satisfied.
        unsigned RESERVED0 : 15; //!< [23:9] Reserved. Should be written as zero for compatibility.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrcncr_t;
#endif

/*
 * constants & macros for entire ASRC_ASRCNCR register
 */
#define HW_ASRC_ASRCNCR_ADDR      (REGS_ASRC_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRCNCR           (*(volatile hw_asrc_asrcncr_t *) HW_ASRC_ASRCNCR_ADDR)
#define HW_ASRC_ASRCNCR_RD()      (HW_ASRC_ASRCNCR.U)
#define HW_ASRC_ASRCNCR_WR(v)     (HW_ASRC_ASRCNCR.U = (v))
#define HW_ASRC_ASRCNCR_SET(v)    (HW_ASRC_ASRCNCR_WR(HW_ASRC_ASRCNCR_RD() |  (v)))
#define HW_ASRC_ASRCNCR_CLR(v)    (HW_ASRC_ASRCNCR_WR(HW_ASRC_ASRCNCR_RD() & ~(v)))
#define HW_ASRC_ASRCNCR_TOG(v)    (HW_ASRC_ASRCNCR_WR(HW_ASRC_ASRCNCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRCNCR bitfields
 */

/* --- Register HW_ASRC_ASRCNCR, field ANCA[2:0] (RW)
 *
 * Number of A Channels
 *
 * Values:
 * 0000 - 0 channels in A (Pair A is disabled)
 * 0001 - 1 channel in A
 * 0010 - 2 channels in A
 * 0011 - 3 channels in A
 * 0100 - 4 channels in A
 * 0101 - 5 channels in A
 * 0110 - 6 channels in A
 * 0111 - 7 channels in A
 * 1000 - 8 channels in A
 * 1001 - 9 channels in A
 * 1010 - 10 channels in A
 * 1011-1111 - Should not be used.
 */

#define BP_ASRC_ASRCNCR_ANCA      (0)      //!< Bit position for ASRC_ASRCNCR_ANCA.
#define BM_ASRC_ASRCNCR_ANCA      (0x00000007)  //!< Bit mask for ASRC_ASRCNCR_ANCA.

//! @brief Get value of ASRC_ASRCNCR_ANCA from a register value.
#define BG_ASRC_ASRCNCR_ANCA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCNCR_ANCA) >> BP_ASRC_ASRCNCR_ANCA)

//! @brief Format value for bitfield ASRC_ASRCNCR_ANCA.
#define BF_ASRC_ASRCNCR_ANCA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCNCR_ANCA) & BM_ASRC_ASRCNCR_ANCA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ANCA field to a new value.
#define BW_ASRC_ASRCNCR_ANCA(v)   (HW_ASRC_ASRCNCR_WR((HW_ASRC_ASRCNCR_RD() & ~BM_ASRC_ASRCNCR_ANCA) | BF_ASRC_ASRCNCR_ANCA(v)))
#endif


/* --- Register HW_ASRC_ASRCNCR, field ANCB[5:3] (RW)
 *
 * Number of B Channels
 *
 * Values:
 * 0000 - 0 channels in B (Pair B is disabled)
 * 0001 - 1 channel in B
 * 0010 - 2 channels in B
 * 0011 - 3 channels in B
 * 0100 - 4 channels in B
 * 0101 - 5 channels in B
 * 0110 - 6 channels in B
 * 0111 - 7 channels in B
 * 1000 - 8 channels in B
 * 1001 - 9 channels in B
 * 1010 - 10 channels in B
 * 1011-1111 - Should not be used.
 */

#define BP_ASRC_ASRCNCR_ANCB      (3)      //!< Bit position for ASRC_ASRCNCR_ANCB.
#define BM_ASRC_ASRCNCR_ANCB      (0x00000038)  //!< Bit mask for ASRC_ASRCNCR_ANCB.

//! @brief Get value of ASRC_ASRCNCR_ANCB from a register value.
#define BG_ASRC_ASRCNCR_ANCB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCNCR_ANCB) >> BP_ASRC_ASRCNCR_ANCB)

//! @brief Format value for bitfield ASRC_ASRCNCR_ANCB.
#define BF_ASRC_ASRCNCR_ANCB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCNCR_ANCB) & BM_ASRC_ASRCNCR_ANCB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ANCB field to a new value.
#define BW_ASRC_ASRCNCR_ANCB(v)   (HW_ASRC_ASRCNCR_WR((HW_ASRC_ASRCNCR_RD() & ~BM_ASRC_ASRCNCR_ANCB) | BF_ASRC_ASRCNCR_ANCB(v)))
#endif


/* --- Register HW_ASRC_ASRCNCR, field ANCC[8:6] (RW)
 *
 * Number of C Channels ANCC+ANCB+ANCA<=10. Hardware is not checking the constraint. Programmer
 * should take the responsibility to ensure the constraint is satisfied.
 *
 * Values:
 * 0000 - 0 channels in C (Pair C is disabled)
 * 0001 - 1 channel in C
 * 0010 - 2 channels in C
 * 0011 - 3 channels in C
 * 0100 - 4 channels in C
 * 0101 - 5 channels in C
 * 0110 - 6 channels in C
 * 0111 - 7 channels in C
 * 1000 - 8 channels in C
 * 1001 - 9 channels in C
 * 1010 - 10 channels in C
 * 1011-1111 - Should not be used.
 */

#define BP_ASRC_ASRCNCR_ANCC      (6)      //!< Bit position for ASRC_ASRCNCR_ANCC.
#define BM_ASRC_ASRCNCR_ANCC      (0x000001c0)  //!< Bit mask for ASRC_ASRCNCR_ANCC.

//! @brief Get value of ASRC_ASRCNCR_ANCC from a register value.
#define BG_ASRC_ASRCNCR_ANCC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCNCR_ANCC) >> BP_ASRC_ASRCNCR_ANCC)

//! @brief Format value for bitfield ASRC_ASRCNCR_ANCC.
#define BF_ASRC_ASRCNCR_ANCC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCNCR_ANCC) & BM_ASRC_ASRCNCR_ANCC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ANCC field to a new value.
#define BW_ASRC_ASRCNCR_ANCC(v)   (HW_ASRC_ASRCNCR_WR((HW_ASRC_ASRCNCR_RD() & ~BM_ASRC_ASRCNCR_ANCC) | BF_ASRC_ASRCNCR_ANCC(v)))
#endif


/* --- Register HW_ASRC_ASRCNCR, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRCNCR_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRCNCR_UNIMPLEMENTED.
#define BM_ASRC_ASRCNCR_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRCNCR_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRCNCR_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRCNCR_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCNCR_UNIMPLEMENTED) >> BP_ASRC_ASRCNCR_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRCFG - ASRC Filter Configuration Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRCFG - ASRC Filter Configuration Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The ASRC configuration status register (ASRCFG) is a 24-bit read/write register that sets and/or
 * automatically senses the ASRC operations.
 */
typedef union _hw_asrc_asrcfg
{
    reg32_t U;
    struct _hw_asrc_asrcfg_bitfields
    {
        unsigned RESERVED0 : 6; //!< [5:0] Reserved. Should be written as zero for compatibility.
        unsigned PREMODA : 2; //!< [7:6] Pre-Processing Configuration for Conversion Pair A These bits will be read/write by user if ASRCTR:ATSA=0, and can also be automatically updated by the ASRC internal logic if ASRCTR:ATSA=1 (see ASRC Misc Control Register 1 for Pair C ). These bits set the selection of the pre-processing configuration.
        unsigned POSTMODA : 2; //!< [9:8] Post-Processing Configuration for Conversion Pair A These bits will be read/write by user if ASRCTR:ATSA=0, and can also be automatically updated by the ASRC internal logic if ASRCTR:ATSA=1 (see ASRC Misc Control Register 1 for Pair C ). These bits set the selection of the post-processing configuration.
        unsigned PREMODB : 2; //!< [11:10] Pre-Processing Configuration for Conversion Pair B These bits will be read/write by user if ASRCTR:ATSB=0, and can also be automatically updated by the ASRC internal logic if ASRCTR:ATSB=1 (see ASRC Misc Control Register 1 for Pair C ). These bits set the selection of the pre-processing configuration.
        unsigned POSTMODB : 2; //!< [13:12] Post-Processing Configuration for Conversion Pair B These bits will be read/write by user if ASRCTR:ATSB=0, and can also be automatically updated by the ASRC internal logic if ASRCTR:ATSB=1 (see ASRC Misc Control Register 1 for Pair C ). These bits set the selection of the post-processing configuration.
        unsigned PREMODC : 2; //!< [15:14] Pre-Processing Configuration for Conversion Pair C These bits will be read/write by user if ASRCTR:ATSC=0, and can also be automatically updated by the ASRC internal logic if ASRCTR:ATSC=1 (see ASRC Misc Control Register 1 for Pair C ). These bits set the selection of the pre-processing configuration.
        unsigned POSTMODC : 2; //!< [17:16] Post-Processing Configuration for Conversion Pair C These bits will be read/write by user if ASRCTR:ATSC=0, and can also be automatically updated by the ASRC internal logic if ASRCTR:ATSC=1 (see ASRC Misc Control Register 1 for Pair C ). These bits set the selection of the post-processing configuration.
        unsigned NDPRA : 1; //!< [18] Not Use Default Parameters for RAM-stored Parameters For Conversion Pair A
        unsigned NDPRB : 1; //!< [19] Not Use Default Parameters for RAM-stored Parameters For Conversion Pair B
        unsigned NDPRC : 1; //!< [20] Not Use Default Parameters for RAM-stored Parameters For Conversion Pair C
        unsigned INIRQA : 1; //!< [21] Initialization for Conversion Pair A is served When this bit is 1, it means the initialization for conversion pair A is served. This bit is cleared by disabling the ASRC conversion pair (ASRCTR:ASREA=0 or ASRCTR:ASRCEN=0).
        unsigned INIRQB : 1; //!< [22] Initialization for Conversion Pair B is served When this bit is 1, it means the initialization for conversion pair B is served. This bit is cleared by disabling the ASRC conversion pair (ASRCTR:ASREB=0 or ASRCTR:ASRCEN=0).
        unsigned INIRQC : 1; //!< [23] Initialization for Conversion Pair C is served When this bit is 1, it means the initialization for conversion pair C is served. This bit is cleared by disabling the ASRC conversion pair (ASRCTR:ASREC=0 or ASRCTR:ASRCEN=0).
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrcfg_t;
#endif

/*
 * constants & macros for entire ASRC_ASRCFG register
 */
#define HW_ASRC_ASRCFG_ADDR      (REGS_ASRC_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRCFG           (*(volatile hw_asrc_asrcfg_t *) HW_ASRC_ASRCFG_ADDR)
#define HW_ASRC_ASRCFG_RD()      (HW_ASRC_ASRCFG.U)
#define HW_ASRC_ASRCFG_WR(v)     (HW_ASRC_ASRCFG.U = (v))
#define HW_ASRC_ASRCFG_SET(v)    (HW_ASRC_ASRCFG_WR(HW_ASRC_ASRCFG_RD() |  (v)))
#define HW_ASRC_ASRCFG_CLR(v)    (HW_ASRC_ASRCFG_WR(HW_ASRC_ASRCFG_RD() & ~(v)))
#define HW_ASRC_ASRCFG_TOG(v)    (HW_ASRC_ASRCFG_WR(HW_ASRC_ASRCFG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRCFG bitfields
 */

/* --- Register HW_ASRC_ASRCFG, field PREMODA[7:6] (RW)
 *
 * Pre-Processing Configuration for Conversion Pair A These bits will be read/write by user if
 * ASRCTR:ATSA=0, and can also be automatically updated by the ASRC internal logic if ASRCTR:ATSA=1
 * (see ASRC Misc Control Register 1 for Pair C ). These bits set the selection of the pre-
 * processing configuration.
 *
 * Values:
 * 00 - Select Upsampling-by-2 as defined in
 * 01 - Select Direct-Connection as defined in
 * 10 - Select Downsampling-by-2 as defined in
 * 11 - Select passthrough mode. In this case, POSTMODA[1-0] ,HFA[1:0] have no use.
 */

#define BP_ASRC_ASRCFG_PREMODA      (6)      //!< Bit position for ASRC_ASRCFG_PREMODA.
#define BM_ASRC_ASRCFG_PREMODA      (0x000000c0)  //!< Bit mask for ASRC_ASRCFG_PREMODA.

//! @brief Get value of ASRC_ASRCFG_PREMODA from a register value.
#define BG_ASRC_ASRCFG_PREMODA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCFG_PREMODA) >> BP_ASRC_ASRCFG_PREMODA)

//! @brief Format value for bitfield ASRC_ASRCFG_PREMODA.
#define BF_ASRC_ASRCFG_PREMODA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCFG_PREMODA) & BM_ASRC_ASRCFG_PREMODA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PREMODA field to a new value.
#define BW_ASRC_ASRCFG_PREMODA(v)   (HW_ASRC_ASRCFG_WR((HW_ASRC_ASRCFG_RD() & ~BM_ASRC_ASRCFG_PREMODA) | BF_ASRC_ASRCFG_PREMODA(v)))
#endif


/* --- Register HW_ASRC_ASRCFG, field POSTMODA[9:8] (RW)
 *
 * Post-Processing Configuration for Conversion Pair A These bits will be read/write by user if
 * ASRCTR:ATSA=0, and can also be automatically updated by the ASRC internal logic if ASRCTR:ATSA=1
 * (see ASRC Misc Control Register 1 for Pair C ). These bits set the selection of the post-
 * processing configuration.
 *
 * Values:
 * 00 - Select Upsampling-by-2 as defined in
 * 01 - Select Direct-Connection as defined in
 * 10 - Select Downsampling-by-2 as defined in
 */

#define BP_ASRC_ASRCFG_POSTMODA      (8)      //!< Bit position for ASRC_ASRCFG_POSTMODA.
#define BM_ASRC_ASRCFG_POSTMODA      (0x00000300)  //!< Bit mask for ASRC_ASRCFG_POSTMODA.

//! @brief Get value of ASRC_ASRCFG_POSTMODA from a register value.
#define BG_ASRC_ASRCFG_POSTMODA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCFG_POSTMODA) >> BP_ASRC_ASRCFG_POSTMODA)

//! @brief Format value for bitfield ASRC_ASRCFG_POSTMODA.
#define BF_ASRC_ASRCFG_POSTMODA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCFG_POSTMODA) & BM_ASRC_ASRCFG_POSTMODA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POSTMODA field to a new value.
#define BW_ASRC_ASRCFG_POSTMODA(v)   (HW_ASRC_ASRCFG_WR((HW_ASRC_ASRCFG_RD() & ~BM_ASRC_ASRCFG_POSTMODA) | BF_ASRC_ASRCFG_POSTMODA(v)))
#endif


/* --- Register HW_ASRC_ASRCFG, field PREMODB[11:10] (RW)
 *
 * Pre-Processing Configuration for Conversion Pair B These bits will be read/write by user if
 * ASRCTR:ATSB=0, and can also be automatically updated by the ASRC internal logic if ASRCTR:ATSB=1
 * (see ASRC Misc Control Register 1 for Pair C ). These bits set the selection of the pre-
 * processing configuration.
 *
 * Values:
 * 00 - Select Upsampling-by-2 as defined in
 * 01 - Select Direct-Connection as defined in
 * 10 - Select Downsampling-by-2 as defined in
 * 11 - Select passthrough mode. In this case, POSTMODB[1-0] ,HFB[1:0] have no use.
 */

#define BP_ASRC_ASRCFG_PREMODB      (10)      //!< Bit position for ASRC_ASRCFG_PREMODB.
#define BM_ASRC_ASRCFG_PREMODB      (0x00000c00)  //!< Bit mask for ASRC_ASRCFG_PREMODB.

//! @brief Get value of ASRC_ASRCFG_PREMODB from a register value.
#define BG_ASRC_ASRCFG_PREMODB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCFG_PREMODB) >> BP_ASRC_ASRCFG_PREMODB)

//! @brief Format value for bitfield ASRC_ASRCFG_PREMODB.
#define BF_ASRC_ASRCFG_PREMODB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCFG_PREMODB) & BM_ASRC_ASRCFG_PREMODB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PREMODB field to a new value.
#define BW_ASRC_ASRCFG_PREMODB(v)   (HW_ASRC_ASRCFG_WR((HW_ASRC_ASRCFG_RD() & ~BM_ASRC_ASRCFG_PREMODB) | BF_ASRC_ASRCFG_PREMODB(v)))
#endif


/* --- Register HW_ASRC_ASRCFG, field POSTMODB[13:12] (RW)
 *
 * Post-Processing Configuration for Conversion Pair B These bits will be read/write by user if
 * ASRCTR:ATSB=0, and can also be automatically updated by the ASRC internal logic if ASRCTR:ATSB=1
 * (see ASRC Misc Control Register 1 for Pair C ). These bits set the selection of the post-
 * processing configuration.
 *
 * Values:
 * 00 - Select Upsampling-by-2 as defined in
 * 01 - Select Direct-Connection as defined in
 * 10 - Select Downsampling-by-2 as defined in
 */

#define BP_ASRC_ASRCFG_POSTMODB      (12)      //!< Bit position for ASRC_ASRCFG_POSTMODB.
#define BM_ASRC_ASRCFG_POSTMODB      (0x00003000)  //!< Bit mask for ASRC_ASRCFG_POSTMODB.

//! @brief Get value of ASRC_ASRCFG_POSTMODB from a register value.
#define BG_ASRC_ASRCFG_POSTMODB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCFG_POSTMODB) >> BP_ASRC_ASRCFG_POSTMODB)

//! @brief Format value for bitfield ASRC_ASRCFG_POSTMODB.
#define BF_ASRC_ASRCFG_POSTMODB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCFG_POSTMODB) & BM_ASRC_ASRCFG_POSTMODB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POSTMODB field to a new value.
#define BW_ASRC_ASRCFG_POSTMODB(v)   (HW_ASRC_ASRCFG_WR((HW_ASRC_ASRCFG_RD() & ~BM_ASRC_ASRCFG_POSTMODB) | BF_ASRC_ASRCFG_POSTMODB(v)))
#endif


/* --- Register HW_ASRC_ASRCFG, field PREMODC[15:14] (RW)
 *
 * Pre-Processing Configuration for Conversion Pair C These bits will be read/write by user if
 * ASRCTR:ATSC=0, and can also be automatically updated by the ASRC internal logic if ASRCTR:ATSC=1
 * (see ASRC Misc Control Register 1 for Pair C ). These bits set the selection of the pre-
 * processing configuration.
 *
 * Values:
 * 00 - Select Upsampling-by-2 as defined in
 * 01 - Select Direct-Connection as defined in
 * 10 - Select Downsampling-by-2 as defined in
 * 11 - Select passthrough mode. In this case, POSTMODC[1-0] ,HFC[1:0] have no use.
 */

#define BP_ASRC_ASRCFG_PREMODC      (14)      //!< Bit position for ASRC_ASRCFG_PREMODC.
#define BM_ASRC_ASRCFG_PREMODC      (0x0000c000)  //!< Bit mask for ASRC_ASRCFG_PREMODC.

//! @brief Get value of ASRC_ASRCFG_PREMODC from a register value.
#define BG_ASRC_ASRCFG_PREMODC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCFG_PREMODC) >> BP_ASRC_ASRCFG_PREMODC)

//! @brief Format value for bitfield ASRC_ASRCFG_PREMODC.
#define BF_ASRC_ASRCFG_PREMODC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCFG_PREMODC) & BM_ASRC_ASRCFG_PREMODC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PREMODC field to a new value.
#define BW_ASRC_ASRCFG_PREMODC(v)   (HW_ASRC_ASRCFG_WR((HW_ASRC_ASRCFG_RD() & ~BM_ASRC_ASRCFG_PREMODC) | BF_ASRC_ASRCFG_PREMODC(v)))
#endif


/* --- Register HW_ASRC_ASRCFG, field POSTMODC[17:16] (RW)
 *
 * Post-Processing Configuration for Conversion Pair C These bits will be read/write by user if
 * ASRCTR:ATSC=0, and can also be automatically updated by the ASRC internal logic if ASRCTR:ATSC=1
 * (see ASRC Misc Control Register 1 for Pair C ). These bits set the selection of the post-
 * processing configuration.
 *
 * Values:
 * 00 - Select Upsampling-by-2 as defined in Signal Processing Flow.
 * 01 - Select Direct-Connection as defined in Signal Processing Flow.
 * 10 - Select Downsampling-by-2 as defined in Signal Processing Flow.
 */

#define BP_ASRC_ASRCFG_POSTMODC      (16)      //!< Bit position for ASRC_ASRCFG_POSTMODC.
#define BM_ASRC_ASRCFG_POSTMODC      (0x00030000)  //!< Bit mask for ASRC_ASRCFG_POSTMODC.

//! @brief Get value of ASRC_ASRCFG_POSTMODC from a register value.
#define BG_ASRC_ASRCFG_POSTMODC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCFG_POSTMODC) >> BP_ASRC_ASRCFG_POSTMODC)

//! @brief Format value for bitfield ASRC_ASRCFG_POSTMODC.
#define BF_ASRC_ASRCFG_POSTMODC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCFG_POSTMODC) & BM_ASRC_ASRCFG_POSTMODC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POSTMODC field to a new value.
#define BW_ASRC_ASRCFG_POSTMODC(v)   (HW_ASRC_ASRCFG_WR((HW_ASRC_ASRCFG_RD() & ~BM_ASRC_ASRCFG_POSTMODC) | BF_ASRC_ASRCFG_POSTMODC(v)))
#endif


/* --- Register HW_ASRC_ASRCFG, field NDPRA[18] (RW)
 *
 * Not Use Default Parameters for RAM-stored Parameters For Conversion Pair A
 *
 * Values:
 * 0 - Use default parameters for RAM-stored parameters. Override any parameters already in RAM.
 * 1 - Don't use default parameters for RAM-stored parameters. Use the parameters already stored in RAM.
 */

#define BP_ASRC_ASRCFG_NDPRA      (18)      //!< Bit position for ASRC_ASRCFG_NDPRA.
#define BM_ASRC_ASRCFG_NDPRA      (0x00040000)  //!< Bit mask for ASRC_ASRCFG_NDPRA.

//! @brief Get value of ASRC_ASRCFG_NDPRA from a register value.
#define BG_ASRC_ASRCFG_NDPRA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCFG_NDPRA) >> BP_ASRC_ASRCFG_NDPRA)

//! @brief Format value for bitfield ASRC_ASRCFG_NDPRA.
#define BF_ASRC_ASRCFG_NDPRA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCFG_NDPRA) & BM_ASRC_ASRCFG_NDPRA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the NDPRA field to a new value.
#define BW_ASRC_ASRCFG_NDPRA(v)   (HW_ASRC_ASRCFG_WR((HW_ASRC_ASRCFG_RD() & ~BM_ASRC_ASRCFG_NDPRA) | BF_ASRC_ASRCFG_NDPRA(v)))
#endif


/* --- Register HW_ASRC_ASRCFG, field NDPRB[19] (RW)
 *
 * Not Use Default Parameters for RAM-stored Parameters For Conversion Pair B
 *
 * Values:
 * 0 - Use default parameters for RAM-stored parameters. Override any parameters already in RAM.
 * 1 - Don't use default parameters for RAM-stored parameter. Use the parameters already stored in RAM.
 */

#define BP_ASRC_ASRCFG_NDPRB      (19)      //!< Bit position for ASRC_ASRCFG_NDPRB.
#define BM_ASRC_ASRCFG_NDPRB      (0x00080000)  //!< Bit mask for ASRC_ASRCFG_NDPRB.

//! @brief Get value of ASRC_ASRCFG_NDPRB from a register value.
#define BG_ASRC_ASRCFG_NDPRB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCFG_NDPRB) >> BP_ASRC_ASRCFG_NDPRB)

//! @brief Format value for bitfield ASRC_ASRCFG_NDPRB.
#define BF_ASRC_ASRCFG_NDPRB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCFG_NDPRB) & BM_ASRC_ASRCFG_NDPRB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the NDPRB field to a new value.
#define BW_ASRC_ASRCFG_NDPRB(v)   (HW_ASRC_ASRCFG_WR((HW_ASRC_ASRCFG_RD() & ~BM_ASRC_ASRCFG_NDPRB) | BF_ASRC_ASRCFG_NDPRB(v)))
#endif


/* --- Register HW_ASRC_ASRCFG, field NDPRC[20] (RW)
 *
 * Not Use Default Parameters for RAM-stored Parameters For Conversion Pair C
 *
 * Values:
 * 0 - Use default parameters for RAM-stored parameters. Override any parameters already in RAM.
 * 1 - Don't use default parameters for RAM-stored parameters. Use the parameters already stored in RAM.
 */

#define BP_ASRC_ASRCFG_NDPRC      (20)      //!< Bit position for ASRC_ASRCFG_NDPRC.
#define BM_ASRC_ASRCFG_NDPRC      (0x00100000)  //!< Bit mask for ASRC_ASRCFG_NDPRC.

//! @brief Get value of ASRC_ASRCFG_NDPRC from a register value.
#define BG_ASRC_ASRCFG_NDPRC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCFG_NDPRC) >> BP_ASRC_ASRCFG_NDPRC)

//! @brief Format value for bitfield ASRC_ASRCFG_NDPRC.
#define BF_ASRC_ASRCFG_NDPRC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCFG_NDPRC) & BM_ASRC_ASRCFG_NDPRC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the NDPRC field to a new value.
#define BW_ASRC_ASRCFG_NDPRC(v)   (HW_ASRC_ASRCFG_WR((HW_ASRC_ASRCFG_RD() & ~BM_ASRC_ASRCFG_NDPRC) | BF_ASRC_ASRCFG_NDPRC(v)))
#endif


/* --- Register HW_ASRC_ASRCFG, field INIRQA[21] (RO)
 *
 * Initialization for Conversion Pair A is served When this bit is 1, it means the initialization
 * for conversion pair A is served. This bit is cleared by disabling the ASRC conversion pair
 * (ASRCTR:ASREA=0 or ASRCTR:ASRCEN=0).
 */

#define BP_ASRC_ASRCFG_INIRQA      (21)      //!< Bit position for ASRC_ASRCFG_INIRQA.
#define BM_ASRC_ASRCFG_INIRQA      (0x00200000)  //!< Bit mask for ASRC_ASRCFG_INIRQA.

//! @brief Get value of ASRC_ASRCFG_INIRQA from a register value.
#define BG_ASRC_ASRCFG_INIRQA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCFG_INIRQA) >> BP_ASRC_ASRCFG_INIRQA)

/* --- Register HW_ASRC_ASRCFG, field INIRQB[22] (RO)
 *
 * Initialization for Conversion Pair B is served When this bit is 1, it means the initialization
 * for conversion pair B is served. This bit is cleared by disabling the ASRC conversion pair
 * (ASRCTR:ASREB=0 or ASRCTR:ASRCEN=0).
 */

#define BP_ASRC_ASRCFG_INIRQB      (22)      //!< Bit position for ASRC_ASRCFG_INIRQB.
#define BM_ASRC_ASRCFG_INIRQB      (0x00400000)  //!< Bit mask for ASRC_ASRCFG_INIRQB.

//! @brief Get value of ASRC_ASRCFG_INIRQB from a register value.
#define BG_ASRC_ASRCFG_INIRQB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCFG_INIRQB) >> BP_ASRC_ASRCFG_INIRQB)

/* --- Register HW_ASRC_ASRCFG, field INIRQC[23] (RO)
 *
 * Initialization for Conversion Pair C is served When this bit is 1, it means the initialization
 * for conversion pair C is served. This bit is cleared by disabling the ASRC conversion pair
 * (ASRCTR:ASREC=0 or ASRCTR:ASRCEN=0).
 */

#define BP_ASRC_ASRCFG_INIRQC      (23)      //!< Bit position for ASRC_ASRCFG_INIRQC.
#define BM_ASRC_ASRCFG_INIRQC      (0x00800000)  //!< Bit mask for ASRC_ASRCFG_INIRQC.

//! @brief Get value of ASRC_ASRCFG_INIRQC from a register value.
#define BG_ASRC_ASRCFG_INIRQC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCFG_INIRQC) >> BP_ASRC_ASRCFG_INIRQC)

/* --- Register HW_ASRC_ASRCFG, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRCFG_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRCFG_UNIMPLEMENTED.
#define BM_ASRC_ASRCFG_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRCFG_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRCFG_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRCFG_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCFG_UNIMPLEMENTED) >> BP_ASRC_ASRCFG_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRCSR - ASRC Clock Source Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRCSR - ASRC Clock Source Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The ASRC clock source register (ASRCSR) is a 24-bit read/write register that controls the sources
 * of the input and output clocks of the ASRC.  The clock connections are shown in ASRC Misc Control
 * Register 1 for Pair C , also shown in :   Bit Clock Definitions       Bit Clk Name  Definitions
 * 0  ESAI RX clock    1  SSI-1 RX clock    2  SSI-2 RX clock    3  SSI-3 RX clock    4  SPDIF RX
 * clock    5  MLB Bit clock    6  bit clock 6 should connect to one of the three pads:
 * KEY_ROW3,GPIO_0,GPIO_18, which is configured by register
 * IOMUXC_IOMUXC_ASRC_ASRCK_CLOCK_6_SELECT_INPUT    7  tied to zero    8  ESAI TX clock    9  SSI-1
 * TX clock    a  SSI-2 TX clock    b  SSI-3 TX clock    c  SPDIF TX clock    d  bit clock d is
 * configured by spdif1_clk_pred and spdif1_clk_podf in CCM_CDCDR, but it is better to describe it
 * also in CCM spec.
 */
typedef union _hw_asrc_asrcsr
{
    reg32_t U;
    struct _hw_asrc_asrcsr_bitfields
    {
        unsigned AICSA : 4; //!< [3:0] Input Clock Source A
        unsigned AICSB : 4; //!< [7:4] Input Clock Source B
        unsigned AICSC : 4; //!< [11:8] Input Clock Source C
        unsigned AOCSA : 4; //!< [15:12] Output Clock Source A
        unsigned AOCSB : 4; //!< [19:16] Output Clock Source B
        unsigned AOCSC : 4; //!< [23:20] Output Clock Source C
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrcsr_t;
#endif

/*
 * constants & macros for entire ASRC_ASRCSR register
 */
#define HW_ASRC_ASRCSR_ADDR      (REGS_ASRC_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRCSR           (*(volatile hw_asrc_asrcsr_t *) HW_ASRC_ASRCSR_ADDR)
#define HW_ASRC_ASRCSR_RD()      (HW_ASRC_ASRCSR.U)
#define HW_ASRC_ASRCSR_WR(v)     (HW_ASRC_ASRCSR.U = (v))
#define HW_ASRC_ASRCSR_SET(v)    (HW_ASRC_ASRCSR_WR(HW_ASRC_ASRCSR_RD() |  (v)))
#define HW_ASRC_ASRCSR_CLR(v)    (HW_ASRC_ASRCSR_WR(HW_ASRC_ASRCSR_RD() & ~(v)))
#define HW_ASRC_ASRCSR_TOG(v)    (HW_ASRC_ASRCSR_WR(HW_ASRC_ASRCSR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRCSR bitfields
 */

/* --- Register HW_ASRC_ASRCSR, field AICSA[3:0] (RW)
 *
 * Input Clock Source A
 *
 * Values:
 * 0000 - bit clock 0
 * 0001 - bit clock 1
 * 0010 - bit clock 2
 * 0011 - bit clock 3
 * 0100 - bit clock 4
 * 0101 - bit clock 5
 * 0110 - bit clock 6
 * 0111 - bit clock 7
 * 1000 - bit clock 8
 * 1001 - bit clock 9
 * 1010 - bit clock A
 * 1011 - bit clock B
 * 1100 - bit clock C
 * 1101 - bit clock D
 * 1111 - clock disabled, connected to zero
 * any other value - bit clock 0
 */

#define BP_ASRC_ASRCSR_AICSA      (0)      //!< Bit position for ASRC_ASRCSR_AICSA.
#define BM_ASRC_ASRCSR_AICSA      (0x0000000f)  //!< Bit mask for ASRC_ASRCSR_AICSA.

//! @brief Get value of ASRC_ASRCSR_AICSA from a register value.
#define BG_ASRC_ASRCSR_AICSA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCSR_AICSA) >> BP_ASRC_ASRCSR_AICSA)

//! @brief Format value for bitfield ASRC_ASRCSR_AICSA.
#define BF_ASRC_ASRCSR_AICSA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCSR_AICSA) & BM_ASRC_ASRCSR_AICSA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AICSA field to a new value.
#define BW_ASRC_ASRCSR_AICSA(v)   (HW_ASRC_ASRCSR_WR((HW_ASRC_ASRCSR_RD() & ~BM_ASRC_ASRCSR_AICSA) | BF_ASRC_ASRCSR_AICSA(v)))
#endif


/* --- Register HW_ASRC_ASRCSR, field AICSB[7:4] (RW)
 *
 * Input Clock Source B
 *
 * Values:
 * 0000 - bit clock 0
 * 0001 - bit clock 1
 * 0010 - bit clock 2
 * 0011 - bit clock 3
 * 0100 - bit clock 4
 * 0101 - bit clock 5
 * 0110 - bit clock 6
 * 0111 - bit clock 7
 * 1000 - bit clock 8
 * 1001 - bit clock 9
 * 1010 - bit clock A
 * 1011 - bit clock B
 * 1100 - bit clock C
 * 1101 - bit clock D
 * 1111 - clock disabled, connected to zero
 * any other value - bit clock 0
 */

#define BP_ASRC_ASRCSR_AICSB      (4)      //!< Bit position for ASRC_ASRCSR_AICSB.
#define BM_ASRC_ASRCSR_AICSB      (0x000000f0)  //!< Bit mask for ASRC_ASRCSR_AICSB.

//! @brief Get value of ASRC_ASRCSR_AICSB from a register value.
#define BG_ASRC_ASRCSR_AICSB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCSR_AICSB) >> BP_ASRC_ASRCSR_AICSB)

//! @brief Format value for bitfield ASRC_ASRCSR_AICSB.
#define BF_ASRC_ASRCSR_AICSB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCSR_AICSB) & BM_ASRC_ASRCSR_AICSB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AICSB field to a new value.
#define BW_ASRC_ASRCSR_AICSB(v)   (HW_ASRC_ASRCSR_WR((HW_ASRC_ASRCSR_RD() & ~BM_ASRC_ASRCSR_AICSB) | BF_ASRC_ASRCSR_AICSB(v)))
#endif


/* --- Register HW_ASRC_ASRCSR, field AICSC[11:8] (RW)
 *
 * Input Clock Source C
 *
 * Values:
 * 0000 - bit clock 0
 * 0001 - bit clock 1
 * 0010 - bit clock 2
 * 0011 - bit clock 3
 * 0100 - bit clock 4
 * 0101 - bit clock 5
 * 0110 - bit clock 6
 * 0111 - bit clock 7
 * 1000 - bit clock 8
 * 1001 - bit clock 9
 * 1010 - bit clock A
 * 1011 - bit clock B
 * 1100 - bit clock C
 * 1101 - bit clock D
 * 1111 - clock disabled, connected to zero
 * any other value - bit clock 0
 */

#define BP_ASRC_ASRCSR_AICSC      (8)      //!< Bit position for ASRC_ASRCSR_AICSC.
#define BM_ASRC_ASRCSR_AICSC      (0x00000f00)  //!< Bit mask for ASRC_ASRCSR_AICSC.

//! @brief Get value of ASRC_ASRCSR_AICSC from a register value.
#define BG_ASRC_ASRCSR_AICSC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCSR_AICSC) >> BP_ASRC_ASRCSR_AICSC)

//! @brief Format value for bitfield ASRC_ASRCSR_AICSC.
#define BF_ASRC_ASRCSR_AICSC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCSR_AICSC) & BM_ASRC_ASRCSR_AICSC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AICSC field to a new value.
#define BW_ASRC_ASRCSR_AICSC(v)   (HW_ASRC_ASRCSR_WR((HW_ASRC_ASRCSR_RD() & ~BM_ASRC_ASRCSR_AICSC) | BF_ASRC_ASRCSR_AICSC(v)))
#endif


/* --- Register HW_ASRC_ASRCSR, field AOCSA[15:12] (RW)
 *
 * Output Clock Source A
 *
 * Values:
 * 0000 - bit clock 0
 * 0001 - bit clock 1
 * 0010 - bit clock 2
 * 0011 - bit clock 3
 * 0100 - bit clock 4
 * 0101 - bit clock 5
 * 0110 - bit clock 6
 * 0111 - bit clock 7
 * 1000 - bit clock 8
 * 1001 - bit clock 9
 * 1010 - bit clock A
 * 1011 - bit clock B
 * 1100 - bit clock C
 * 1101 - bit clock D
 * 1111 - clock disabled, connected to zero
 * any other value - bit clock 0
 */

#define BP_ASRC_ASRCSR_AOCSA      (12)      //!< Bit position for ASRC_ASRCSR_AOCSA.
#define BM_ASRC_ASRCSR_AOCSA      (0x0000f000)  //!< Bit mask for ASRC_ASRCSR_AOCSA.

//! @brief Get value of ASRC_ASRCSR_AOCSA from a register value.
#define BG_ASRC_ASRCSR_AOCSA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCSR_AOCSA) >> BP_ASRC_ASRCSR_AOCSA)

//! @brief Format value for bitfield ASRC_ASRCSR_AOCSA.
#define BF_ASRC_ASRCSR_AOCSA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCSR_AOCSA) & BM_ASRC_ASRCSR_AOCSA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AOCSA field to a new value.
#define BW_ASRC_ASRCSR_AOCSA(v)   (HW_ASRC_ASRCSR_WR((HW_ASRC_ASRCSR_RD() & ~BM_ASRC_ASRCSR_AOCSA) | BF_ASRC_ASRCSR_AOCSA(v)))
#endif


/* --- Register HW_ASRC_ASRCSR, field AOCSB[19:16] (RW)
 *
 * Output Clock Source B
 *
 * Values:
 * 0000 - bit clock 0
 * 0001 - bit clock 1
 * 0010 - bit clock 2
 * 0011 - bit clock 3
 * 0100 - bit clock 4
 * 0101 - bit clock 5
 * 0110 - bit clock 6
 * 0111 - bit clock 7
 * 1000 - bit clock 8
 * 1001 - bit clock 9
 * 1010 - bit clock A
 * 1011 - bit clock B
 * 1100 - bit clock C
 * 1101 - bit clock D
 * 1111 - clock disabled, connected to zero
 * any other value - bit clock 0
 */

#define BP_ASRC_ASRCSR_AOCSB      (16)      //!< Bit position for ASRC_ASRCSR_AOCSB.
#define BM_ASRC_ASRCSR_AOCSB      (0x000f0000)  //!< Bit mask for ASRC_ASRCSR_AOCSB.

//! @brief Get value of ASRC_ASRCSR_AOCSB from a register value.
#define BG_ASRC_ASRCSR_AOCSB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCSR_AOCSB) >> BP_ASRC_ASRCSR_AOCSB)

//! @brief Format value for bitfield ASRC_ASRCSR_AOCSB.
#define BF_ASRC_ASRCSR_AOCSB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCSR_AOCSB) & BM_ASRC_ASRCSR_AOCSB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AOCSB field to a new value.
#define BW_ASRC_ASRCSR_AOCSB(v)   (HW_ASRC_ASRCSR_WR((HW_ASRC_ASRCSR_RD() & ~BM_ASRC_ASRCSR_AOCSB) | BF_ASRC_ASRCSR_AOCSB(v)))
#endif


/* --- Register HW_ASRC_ASRCSR, field AOCSC[23:20] (RW)
 *
 * Output Clock Source C
 *
 * Values:
 * 0000 - bit clock 0
 * 0001 - bit clock 1
 * 0010 - bit clock 2
 * 0011 - bit clock 3
 * 0100 - bit clock 4
 * 0101 - bit clock 5
 * 0110 - bit clock 6
 * 0111 - bit clock 7
 * 1000 - bit clock 8
 * 1001 - bit clock 9
 * 1010 - bit clock A
 * 1011 - bit clock B
 * 1100 - bit clock C
 * 1101 - bit clock D
 * 1111 - clock disabled, connected to zero
 * any other value - bit clock 0
 */

#define BP_ASRC_ASRCSR_AOCSC      (20)      //!< Bit position for ASRC_ASRCSR_AOCSC.
#define BM_ASRC_ASRCSR_AOCSC      (0x00f00000)  //!< Bit mask for ASRC_ASRCSR_AOCSC.

//! @brief Get value of ASRC_ASRCSR_AOCSC from a register value.
#define BG_ASRC_ASRCSR_AOCSC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCSR_AOCSC) >> BP_ASRC_ASRCSR_AOCSC)

//! @brief Format value for bitfield ASRC_ASRCSR_AOCSC.
#define BF_ASRC_ASRCSR_AOCSC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCSR_AOCSC) & BM_ASRC_ASRCSR_AOCSC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AOCSC field to a new value.
#define BW_ASRC_ASRCSR_AOCSC(v)   (HW_ASRC_ASRCSR_WR((HW_ASRC_ASRCSR_RD() & ~BM_ASRC_ASRCSR_AOCSC) | BF_ASRC_ASRCSR_AOCSC(v)))
#endif


/* --- Register HW_ASRC_ASRCSR, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRCSR_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRCSR_UNIMPLEMENTED.
#define BM_ASRC_ASRCSR_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRCSR_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRCSR_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRCSR_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCSR_UNIMPLEMENTED) >> BP_ASRC_ASRCSR_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRCDR1 - ASRC Clock Divider Register 1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRCDR1 - ASRC Clock Divider Register 1 (RW)
 *
 * Reset value: 0x00000000
 *
 * The ASRC clock divider register (ASRCDR1) is a two 24-bit read/write register that controls the
 * division factors of the ASRC input and output clock sources.
 */
typedef union _hw_asrc_asrcdr1
{
    reg32_t U;
    struct _hw_asrc_asrcdr1_bitfields
    {
        unsigned AICPA : 3; //!< [2:0] Input Clock Prescaler A Specify the prescaling factor of the input prescaler A. The prescaling ratio may be any power of 2 from 1 to 128.
        unsigned AICDA : 3; //!< [5:3] Input Clock Divider A Specify the divide ratio of the input clock divider A. The divide ratio may range from 1 to 8 (AICDA[2:0] = 000 to 111).
        unsigned AICPB : 3; //!< [8:6] Input Clock Prescaler B Specify the prescaling factor of the input prescaler B. The prescaling ratio may be any power of 2 from 1 to 128.
        unsigned AICDB : 3; //!< [11:9] Input Clock Divider B Specify the divide ratio of the input clock divider B. The divide ratio may range from 1 to 8 (AICDB[2:0] = 000 to 111).
        unsigned AOCPA : 3; //!< [14:12] Output Clock Prescaler A Specify the prescaling factor of the output prescaler A. The prescaling ratio may be any power of 2 from 1 to 128.
        unsigned AOCDA : 3; //!< [17:15] Output Clock Divider A Specify the divide ratio of the output clock divider A. The divide ratio may range from 1 to 8 (AOCDA[2:0] = 000 to 111).
        unsigned AOCPB : 3; //!< [20:18] Output Clock Prescaler B Specify the prescaling factor of the output prescaler B. The prescaling ratio may be any power of 2 from 1 to 128.
        unsigned AOCDB : 3; //!< [23:21] Output Clock Divider B Specify the divide ratio of the output clock divider B. The divide ratio may range from 1 to 8 (AOCDB[2:0] = 000 to 111).
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrcdr1_t;
#endif

/*
 * constants & macros for entire ASRC_ASRCDR1 register
 */
#define HW_ASRC_ASRCDR1_ADDR      (REGS_ASRC_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRCDR1           (*(volatile hw_asrc_asrcdr1_t *) HW_ASRC_ASRCDR1_ADDR)
#define HW_ASRC_ASRCDR1_RD()      (HW_ASRC_ASRCDR1.U)
#define HW_ASRC_ASRCDR1_WR(v)     (HW_ASRC_ASRCDR1.U = (v))
#define HW_ASRC_ASRCDR1_SET(v)    (HW_ASRC_ASRCDR1_WR(HW_ASRC_ASRCDR1_RD() |  (v)))
#define HW_ASRC_ASRCDR1_CLR(v)    (HW_ASRC_ASRCDR1_WR(HW_ASRC_ASRCDR1_RD() & ~(v)))
#define HW_ASRC_ASRCDR1_TOG(v)    (HW_ASRC_ASRCDR1_WR(HW_ASRC_ASRCDR1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRCDR1 bitfields
 */

/* --- Register HW_ASRC_ASRCDR1, field AICPA[2:0] (RW)
 *
 * Input Clock Prescaler A Specify the prescaling factor of the input prescaler A. The prescaling
 * ratio may be any power of 2 from 1 to 128.
 */

#define BP_ASRC_ASRCDR1_AICPA      (0)      //!< Bit position for ASRC_ASRCDR1_AICPA.
#define BM_ASRC_ASRCDR1_AICPA      (0x00000007)  //!< Bit mask for ASRC_ASRCDR1_AICPA.

//! @brief Get value of ASRC_ASRCDR1_AICPA from a register value.
#define BG_ASRC_ASRCDR1_AICPA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCDR1_AICPA) >> BP_ASRC_ASRCDR1_AICPA)

//! @brief Format value for bitfield ASRC_ASRCDR1_AICPA.
#define BF_ASRC_ASRCDR1_AICPA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCDR1_AICPA) & BM_ASRC_ASRCDR1_AICPA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AICPA field to a new value.
#define BW_ASRC_ASRCDR1_AICPA(v)   (HW_ASRC_ASRCDR1_WR((HW_ASRC_ASRCDR1_RD() & ~BM_ASRC_ASRCDR1_AICPA) | BF_ASRC_ASRCDR1_AICPA(v)))
#endif

/* --- Register HW_ASRC_ASRCDR1, field AICDA[5:3] (RW)
 *
 * Input Clock Divider A Specify the divide ratio of the input clock divider A. The divide ratio may
 * range from 1 to 8 (AICDA[2:0] = 000 to 111).
 */

#define BP_ASRC_ASRCDR1_AICDA      (3)      //!< Bit position for ASRC_ASRCDR1_AICDA.
#define BM_ASRC_ASRCDR1_AICDA      (0x00000038)  //!< Bit mask for ASRC_ASRCDR1_AICDA.

//! @brief Get value of ASRC_ASRCDR1_AICDA from a register value.
#define BG_ASRC_ASRCDR1_AICDA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCDR1_AICDA) >> BP_ASRC_ASRCDR1_AICDA)

//! @brief Format value for bitfield ASRC_ASRCDR1_AICDA.
#define BF_ASRC_ASRCDR1_AICDA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCDR1_AICDA) & BM_ASRC_ASRCDR1_AICDA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AICDA field to a new value.
#define BW_ASRC_ASRCDR1_AICDA(v)   (HW_ASRC_ASRCDR1_WR((HW_ASRC_ASRCDR1_RD() & ~BM_ASRC_ASRCDR1_AICDA) | BF_ASRC_ASRCDR1_AICDA(v)))
#endif

/* --- Register HW_ASRC_ASRCDR1, field AICPB[8:6] (RW)
 *
 * Input Clock Prescaler B Specify the prescaling factor of the input prescaler B. The prescaling
 * ratio may be any power of 2 from 1 to 128.
 */

#define BP_ASRC_ASRCDR1_AICPB      (6)      //!< Bit position for ASRC_ASRCDR1_AICPB.
#define BM_ASRC_ASRCDR1_AICPB      (0x000001c0)  //!< Bit mask for ASRC_ASRCDR1_AICPB.

//! @brief Get value of ASRC_ASRCDR1_AICPB from a register value.
#define BG_ASRC_ASRCDR1_AICPB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCDR1_AICPB) >> BP_ASRC_ASRCDR1_AICPB)

//! @brief Format value for bitfield ASRC_ASRCDR1_AICPB.
#define BF_ASRC_ASRCDR1_AICPB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCDR1_AICPB) & BM_ASRC_ASRCDR1_AICPB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AICPB field to a new value.
#define BW_ASRC_ASRCDR1_AICPB(v)   (HW_ASRC_ASRCDR1_WR((HW_ASRC_ASRCDR1_RD() & ~BM_ASRC_ASRCDR1_AICPB) | BF_ASRC_ASRCDR1_AICPB(v)))
#endif

/* --- Register HW_ASRC_ASRCDR1, field AICDB[11:9] (RW)
 *
 * Input Clock Divider B Specify the divide ratio of the input clock divider B. The divide ratio may
 * range from 1 to 8 (AICDB[2:0] = 000 to 111).
 */

#define BP_ASRC_ASRCDR1_AICDB      (9)      //!< Bit position for ASRC_ASRCDR1_AICDB.
#define BM_ASRC_ASRCDR1_AICDB      (0x00000e00)  //!< Bit mask for ASRC_ASRCDR1_AICDB.

//! @brief Get value of ASRC_ASRCDR1_AICDB from a register value.
#define BG_ASRC_ASRCDR1_AICDB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCDR1_AICDB) >> BP_ASRC_ASRCDR1_AICDB)

//! @brief Format value for bitfield ASRC_ASRCDR1_AICDB.
#define BF_ASRC_ASRCDR1_AICDB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCDR1_AICDB) & BM_ASRC_ASRCDR1_AICDB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AICDB field to a new value.
#define BW_ASRC_ASRCDR1_AICDB(v)   (HW_ASRC_ASRCDR1_WR((HW_ASRC_ASRCDR1_RD() & ~BM_ASRC_ASRCDR1_AICDB) | BF_ASRC_ASRCDR1_AICDB(v)))
#endif

/* --- Register HW_ASRC_ASRCDR1, field AOCPA[14:12] (RW)
 *
 * Output Clock Prescaler A Specify the prescaling factor of the output prescaler A. The prescaling
 * ratio may be any power of 2 from 1 to 128.
 */

#define BP_ASRC_ASRCDR1_AOCPA      (12)      //!< Bit position for ASRC_ASRCDR1_AOCPA.
#define BM_ASRC_ASRCDR1_AOCPA      (0x00007000)  //!< Bit mask for ASRC_ASRCDR1_AOCPA.

//! @brief Get value of ASRC_ASRCDR1_AOCPA from a register value.
#define BG_ASRC_ASRCDR1_AOCPA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCDR1_AOCPA) >> BP_ASRC_ASRCDR1_AOCPA)

//! @brief Format value for bitfield ASRC_ASRCDR1_AOCPA.
#define BF_ASRC_ASRCDR1_AOCPA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCDR1_AOCPA) & BM_ASRC_ASRCDR1_AOCPA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AOCPA field to a new value.
#define BW_ASRC_ASRCDR1_AOCPA(v)   (HW_ASRC_ASRCDR1_WR((HW_ASRC_ASRCDR1_RD() & ~BM_ASRC_ASRCDR1_AOCPA) | BF_ASRC_ASRCDR1_AOCPA(v)))
#endif

/* --- Register HW_ASRC_ASRCDR1, field AOCDA[17:15] (RW)
 *
 * Output Clock Divider A Specify the divide ratio of the output clock divider A. The divide ratio
 * may range from 1 to 8 (AOCDA[2:0] = 000 to 111).
 */

#define BP_ASRC_ASRCDR1_AOCDA      (15)      //!< Bit position for ASRC_ASRCDR1_AOCDA.
#define BM_ASRC_ASRCDR1_AOCDA      (0x00038000)  //!< Bit mask for ASRC_ASRCDR1_AOCDA.

//! @brief Get value of ASRC_ASRCDR1_AOCDA from a register value.
#define BG_ASRC_ASRCDR1_AOCDA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCDR1_AOCDA) >> BP_ASRC_ASRCDR1_AOCDA)

//! @brief Format value for bitfield ASRC_ASRCDR1_AOCDA.
#define BF_ASRC_ASRCDR1_AOCDA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCDR1_AOCDA) & BM_ASRC_ASRCDR1_AOCDA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AOCDA field to a new value.
#define BW_ASRC_ASRCDR1_AOCDA(v)   (HW_ASRC_ASRCDR1_WR((HW_ASRC_ASRCDR1_RD() & ~BM_ASRC_ASRCDR1_AOCDA) | BF_ASRC_ASRCDR1_AOCDA(v)))
#endif

/* --- Register HW_ASRC_ASRCDR1, field AOCPB[20:18] (RW)
 *
 * Output Clock Prescaler B Specify the prescaling factor of the output prescaler B. The prescaling
 * ratio may be any power of 2 from 1 to 128.
 */

#define BP_ASRC_ASRCDR1_AOCPB      (18)      //!< Bit position for ASRC_ASRCDR1_AOCPB.
#define BM_ASRC_ASRCDR1_AOCPB      (0x001c0000)  //!< Bit mask for ASRC_ASRCDR1_AOCPB.

//! @brief Get value of ASRC_ASRCDR1_AOCPB from a register value.
#define BG_ASRC_ASRCDR1_AOCPB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCDR1_AOCPB) >> BP_ASRC_ASRCDR1_AOCPB)

//! @brief Format value for bitfield ASRC_ASRCDR1_AOCPB.
#define BF_ASRC_ASRCDR1_AOCPB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCDR1_AOCPB) & BM_ASRC_ASRCDR1_AOCPB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AOCPB field to a new value.
#define BW_ASRC_ASRCDR1_AOCPB(v)   (HW_ASRC_ASRCDR1_WR((HW_ASRC_ASRCDR1_RD() & ~BM_ASRC_ASRCDR1_AOCPB) | BF_ASRC_ASRCDR1_AOCPB(v)))
#endif

/* --- Register HW_ASRC_ASRCDR1, field AOCDB[23:21] (RW)
 *
 * Output Clock Divider B Specify the divide ratio of the output clock divider B. The divide ratio
 * may range from 1 to 8 (AOCDB[2:0] = 000 to 111).
 */

#define BP_ASRC_ASRCDR1_AOCDB      (21)      //!< Bit position for ASRC_ASRCDR1_AOCDB.
#define BM_ASRC_ASRCDR1_AOCDB      (0x00e00000)  //!< Bit mask for ASRC_ASRCDR1_AOCDB.

//! @brief Get value of ASRC_ASRCDR1_AOCDB from a register value.
#define BG_ASRC_ASRCDR1_AOCDB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCDR1_AOCDB) >> BP_ASRC_ASRCDR1_AOCDB)

//! @brief Format value for bitfield ASRC_ASRCDR1_AOCDB.
#define BF_ASRC_ASRCDR1_AOCDB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCDR1_AOCDB) & BM_ASRC_ASRCDR1_AOCDB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AOCDB field to a new value.
#define BW_ASRC_ASRCDR1_AOCDB(v)   (HW_ASRC_ASRCDR1_WR((HW_ASRC_ASRCDR1_RD() & ~BM_ASRC_ASRCDR1_AOCDB) | BF_ASRC_ASRCDR1_AOCDB(v)))
#endif

/* --- Register HW_ASRC_ASRCDR1, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRCDR1_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRCDR1_UNIMPLEMENTED.
#define BM_ASRC_ASRCDR1_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRCDR1_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRCDR1_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRCDR1_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCDR1_UNIMPLEMENTED) >> BP_ASRC_ASRCDR1_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRCDR2 - ASRC Clock Divider Register 2
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRCDR2 - ASRC Clock Divider Register 2 (RW)
 *
 * Reset value: 0x00000000
 *
 * The ASRC clock divider register (ASRCDR2) is a two 24-bit read/write register that controls the
 * division factors of the ASRC input and output clock sources.
 */
typedef union _hw_asrc_asrcdr2
{
    reg32_t U;
    struct _hw_asrc_asrcdr2_bitfields
    {
        unsigned AICPC : 3; //!< [2:0] Input Clock Prescaler C Specify the prescaling factor of the input prescaler C. The prescaling ratio may be any power of 2 from 1 to 128.
        unsigned AICDC : 3; //!< [5:3] Input Clock Divider C Specify the divide ratio of the input clock divider C. The divide ratio may range from 1 to 8 (AICDC[2:0] = 000 to 111).
        unsigned AOCPC : 3; //!< [8:6] Output Clock Prescaler C Specify the prescaling factor of the output prescaler C. The prescaling ratio may be any power of 2 from 1 to 128.
        unsigned AOCDC : 3; //!< [11:9] Output Clock Divider C Specify the divide ratio of the output clock divider C. The divide ratio may range from 1 to 8 (AOCDC[2:0] = 000 to 111).
        unsigned RESERVED0 : 12; //!< [23:12] Reserved. Should be written as zero for compatibility.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrcdr2_t;
#endif

/*
 * constants & macros for entire ASRC_ASRCDR2 register
 */
#define HW_ASRC_ASRCDR2_ADDR      (REGS_ASRC_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRCDR2           (*(volatile hw_asrc_asrcdr2_t *) HW_ASRC_ASRCDR2_ADDR)
#define HW_ASRC_ASRCDR2_RD()      (HW_ASRC_ASRCDR2.U)
#define HW_ASRC_ASRCDR2_WR(v)     (HW_ASRC_ASRCDR2.U = (v))
#define HW_ASRC_ASRCDR2_SET(v)    (HW_ASRC_ASRCDR2_WR(HW_ASRC_ASRCDR2_RD() |  (v)))
#define HW_ASRC_ASRCDR2_CLR(v)    (HW_ASRC_ASRCDR2_WR(HW_ASRC_ASRCDR2_RD() & ~(v)))
#define HW_ASRC_ASRCDR2_TOG(v)    (HW_ASRC_ASRCDR2_WR(HW_ASRC_ASRCDR2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRCDR2 bitfields
 */

/* --- Register HW_ASRC_ASRCDR2, field AICPC[2:0] (RW)
 *
 * Input Clock Prescaler C Specify the prescaling factor of the input prescaler C. The prescaling
 * ratio may be any power of 2 from 1 to 128.
 */

#define BP_ASRC_ASRCDR2_AICPC      (0)      //!< Bit position for ASRC_ASRCDR2_AICPC.
#define BM_ASRC_ASRCDR2_AICPC      (0x00000007)  //!< Bit mask for ASRC_ASRCDR2_AICPC.

//! @brief Get value of ASRC_ASRCDR2_AICPC from a register value.
#define BG_ASRC_ASRCDR2_AICPC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCDR2_AICPC) >> BP_ASRC_ASRCDR2_AICPC)

//! @brief Format value for bitfield ASRC_ASRCDR2_AICPC.
#define BF_ASRC_ASRCDR2_AICPC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCDR2_AICPC) & BM_ASRC_ASRCDR2_AICPC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AICPC field to a new value.
#define BW_ASRC_ASRCDR2_AICPC(v)   (HW_ASRC_ASRCDR2_WR((HW_ASRC_ASRCDR2_RD() & ~BM_ASRC_ASRCDR2_AICPC) | BF_ASRC_ASRCDR2_AICPC(v)))
#endif

/* --- Register HW_ASRC_ASRCDR2, field AICDC[5:3] (RW)
 *
 * Input Clock Divider C Specify the divide ratio of the input clock divider C. The divide ratio may
 * range from 1 to 8 (AICDC[2:0] = 000 to 111).
 */

#define BP_ASRC_ASRCDR2_AICDC      (3)      //!< Bit position for ASRC_ASRCDR2_AICDC.
#define BM_ASRC_ASRCDR2_AICDC      (0x00000038)  //!< Bit mask for ASRC_ASRCDR2_AICDC.

//! @brief Get value of ASRC_ASRCDR2_AICDC from a register value.
#define BG_ASRC_ASRCDR2_AICDC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCDR2_AICDC) >> BP_ASRC_ASRCDR2_AICDC)

//! @brief Format value for bitfield ASRC_ASRCDR2_AICDC.
#define BF_ASRC_ASRCDR2_AICDC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCDR2_AICDC) & BM_ASRC_ASRCDR2_AICDC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AICDC field to a new value.
#define BW_ASRC_ASRCDR2_AICDC(v)   (HW_ASRC_ASRCDR2_WR((HW_ASRC_ASRCDR2_RD() & ~BM_ASRC_ASRCDR2_AICDC) | BF_ASRC_ASRCDR2_AICDC(v)))
#endif

/* --- Register HW_ASRC_ASRCDR2, field AOCPC[8:6] (RW)
 *
 * Output Clock Prescaler C Specify the prescaling factor of the output prescaler C. The prescaling
 * ratio may be any power of 2 from 1 to 128.
 */

#define BP_ASRC_ASRCDR2_AOCPC      (6)      //!< Bit position for ASRC_ASRCDR2_AOCPC.
#define BM_ASRC_ASRCDR2_AOCPC      (0x000001c0)  //!< Bit mask for ASRC_ASRCDR2_AOCPC.

//! @brief Get value of ASRC_ASRCDR2_AOCPC from a register value.
#define BG_ASRC_ASRCDR2_AOCPC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCDR2_AOCPC) >> BP_ASRC_ASRCDR2_AOCPC)

//! @brief Format value for bitfield ASRC_ASRCDR2_AOCPC.
#define BF_ASRC_ASRCDR2_AOCPC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCDR2_AOCPC) & BM_ASRC_ASRCDR2_AOCPC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AOCPC field to a new value.
#define BW_ASRC_ASRCDR2_AOCPC(v)   (HW_ASRC_ASRCDR2_WR((HW_ASRC_ASRCDR2_RD() & ~BM_ASRC_ASRCDR2_AOCPC) | BF_ASRC_ASRCDR2_AOCPC(v)))
#endif

/* --- Register HW_ASRC_ASRCDR2, field AOCDC[11:9] (RW)
 *
 * Output Clock Divider C Specify the divide ratio of the output clock divider C. The divide ratio
 * may range from 1 to 8 (AOCDC[2:0] = 000 to 111).
 */

#define BP_ASRC_ASRCDR2_AOCDC      (9)      //!< Bit position for ASRC_ASRCDR2_AOCDC.
#define BM_ASRC_ASRCDR2_AOCDC      (0x00000e00)  //!< Bit mask for ASRC_ASRCDR2_AOCDC.

//! @brief Get value of ASRC_ASRCDR2_AOCDC from a register value.
#define BG_ASRC_ASRCDR2_AOCDC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCDR2_AOCDC) >> BP_ASRC_ASRCDR2_AOCDC)

//! @brief Format value for bitfield ASRC_ASRCDR2_AOCDC.
#define BF_ASRC_ASRCDR2_AOCDC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCDR2_AOCDC) & BM_ASRC_ASRCDR2_AOCDC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AOCDC field to a new value.
#define BW_ASRC_ASRCDR2_AOCDC(v)   (HW_ASRC_ASRCDR2_WR((HW_ASRC_ASRCDR2_RD() & ~BM_ASRC_ASRCDR2_AOCDC) | BF_ASRC_ASRCDR2_AOCDC(v)))
#endif

/* --- Register HW_ASRC_ASRCDR2, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRCDR2_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRCDR2_UNIMPLEMENTED.
#define BM_ASRC_ASRCDR2_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRCDR2_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRCDR2_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRCDR2_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCDR2_UNIMPLEMENTED) >> BP_ASRC_ASRCDR2_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRSTR - ASRC Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRSTR - ASRC Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * The ASRC status register (ASRSTR) is a 24-bit read-write register used by the processor core to
 * examine the status of the ASRC block and clear the overload interrupt request and AOLE flag bit.
 * Read the status register will return the current state of ASRC.
 */
typedef union _hw_asrc_asrstr
{
    reg32_t U;
    struct _hw_asrc_asrstr_bitfields
    {
        unsigned AIDEA : 1; //!< [0] Number of data in Input Data Buffer A is less than threshold When set, this bit indicates that number of data still available in ASRDIRA is less than threshold and the processor can write data to ASRDIRA. When AIDEA is set, the ASRC generates data input A interrupt request to the processor, if enabled (that is, ASRCTR:ADIEA = 1). A DMA request is always generated when the AIDEA bit is set, but a DMA transfer takes place only if a DMA channel is active and triggered by this event.
        unsigned AIDEB : 1; //!< [1] Number of data in Input Data Buffer B is less than threshold When set, this bit indicates that number of data still available in ASRDIRB is less than threshold and the processor can write data to ASRDIRB. When AIDEB is set, the ASRC generates data input B interrupt request to the processor, if enabled (that is, ASRCTR:ADIEB = 1). A DMA request is always generated when the AIDEB bit is set, but a DMA transfer takes place only if a DMA channel is active and triggered by this event.
        unsigned AIDEC : 1; //!< [2] Number of data in Input Data Buffer C is less than threshold When set, this bit indicates that number of data still available in ASRDIRC is less than threshold and the processor can write data to ASRDIRC. When AIDEC is set, the ASRC generates data input C interrupt request to the processor, if enabled (that is, ASRCTR:ADIEC = 1). A DMA request is always generated when the AIDEC bit is set, but a DMA transfer takes place only if a DMA channel is active and triggered by this event.
        unsigned AODFA : 1; //!< [3] Number of data in Output Data Buffer A is greater than threshold When set, this bit indicates that number of data already existing in ASRDORA is greater than threshold and the processor can read data from ASRDORA. When AODFA is set, the ASRC generates data output A interrupt request to the processor, if enabled (that is, ASRCTR:ADOEA = 1). A DMA request is always generated when the AODFA bit is set, but a DMA transfer takes place only if a DMA channel is active and triggered by this event.
        unsigned AODFB : 1; //!< [4] Number of data in Output Data Buffer B is greater than threshold When set, this bit indicates that number of data already existing in ASRDORB is greater than threshold and the processor can read data from ASRDORB. When AODFB is set, the ASRC generates data output B interrupt request to the processor, if enabled (that is, ASRCTR:ADOEB = 1). A DMA request is always generated when the AODFB bit is set, but a DMA transfer takes place only if a DMA channel is active and triggered by this event.
        unsigned AODFC : 1; //!< [5] Number of data in Output Data Buffer C is greater than threshold When set, this bit indicates that number of data already existing in ASRDORC is greater than threshold and the processor can read data from ASRDORC. When AODFC is set, the ASRC generates data output C interrupt request to the processor, if enabled (that is, ASRCTR:ADOEC = 1). A DMA request is always generated when the AODFC bit is set, but a DMA transfer takes place only if a DMA channel is active and triggered by this event.
        unsigned AOLE : 1; //!< [6] Overload Error Flag When set, this bit indicates that the task rate is too high for the ASRC to handle. The reasons for overload may be: - too high input clock frequency, - too high output clock frequency, - incorrect selection of the pre-filter, - low ASRC processing clock, - too many channels, - underrun, - or any combination of the reasons above. Since the ASRC uses the same hardware resources to perform various tasks, the real reason for the overload is not straight forward, and it should be carefully analyzed by the programmer. If ASRCTR:AOLIE=1, an interrupt will be proposed when this bit is set. Write any value with this bit set as one into the status register will clear this bit and the interrupt request proposed by this bit.
        unsigned FPWT : 1; //!< [7] FP is in wait states This bit is for debug only. When set, this bit indicates that ASRC is in wait states. When clear, this bit indicates that ASRC is not in wait states. If ASRCTR:AFPWE=1 and ASRCTR:ASDBG=1, an interrupt will be proposed when this bit is set.
        unsigned AIDUA : 1; //!< [8] Input Data Buffer A has underflowed When set, this bit indicates that input data buffer A has underflowed. When clear, this bit indicates that input data buffer A has not underflowed.
        unsigned AIDUB : 1; //!< [9] Input Data Buffer B has underflowed When set, this bit indicates that input data buffer B has underflowed. When clear, this bit indicates that input data buffer B has not underflowed.
        unsigned AIDUC : 1; //!< [10] Input Data Buffer C has underflowed When set, this bit indicates that input data buffer C has underflowed. When clear, this bit indicates that input data buffer C has not underflowed.
        unsigned AODOA : 1; //!< [11] Output Data Buffer A has overflowed When set, this bit indicates that output data buffer A has overflowed. When clear, this bit indicates that output data buffer A has not overflowed
        unsigned AODOB : 1; //!< [12] Output Data Buffer B has overflowed When set, this bit indicates that output data buffer B has overflowed. When clear, this bit indicates that output data buffer B has not overflowed
        unsigned AODOC : 1; //!< [13] Output Data Buffer C has overflowed When set, this bit indicates that output data buffer C has overflowed. When clear, this bit indicates that output data buffer C has not overflowed
        unsigned AIOLA : 1; //!< [14] Pair A Input Task Overload When set, this bit indicates that pair A input task is oveloaded. This may help to check the reason why overload interrupt happens. The bit is cleared when writing ASRCTR:AOLIE as 1.
        unsigned AIOLB : 1; //!< [15] Pair B Input Task Overload When set, this bit indicates that pair B input task is oveloaded. This may help to check the reason why overload interrupt happens. The bit is cleared when writing ASRCTR:AOLIE as 1.
        unsigned AIOLC : 1; //!< [16] Pair C Input Task Overload When set, this bit indicates that pair C input task is oveloaded. This may help to check the reason why overload interrupt happens. The bit is cleared when writing ASRCTR:AOLIE as 1.
        unsigned AOOLA : 1; //!< [17] Pair A Output Task Overload When set, this bit indicates that pair A output task is oveloaded. This may help to check the reason why overload interrupt happens. The bit is cleared when writing ASRCTR:AOLIE as 1.
        unsigned AOOLB : 1; //!< [18] Pair B Output Task Overload When set, this bit indicates that pair B output task is oveloaded. This may help to check the reason why overload interrupt happens. The bit is cleared when writing ASRCTR:AOLIE as 1.
        unsigned AOOLC : 1; //!< [19] Pair C Output Task Overload When set, this bit indicates that pair C output task is oveloaded. This may help to check the reason why overload interrupt happens. The bit is cleared when writing ASRCTR:AOLIE as 1.
        unsigned ATQOL : 1; //!< [20] Task Queue FIFO overload When set, this bit indicates that task queue FIFO logic is oveloaded. This may help to check the reason why overload interrupt happens. The bit is cleared when writing ASRCTR:AOLIE as 1.
        unsigned DSLCNT : 1; //!< [21] DSL Counter Input to FIFO ready When set, this bit indicates that new DSL counter information is stored in the internal ASRC FIFO. When clear, this bit indicates that new DSL counter information is in the process of storage into the internal ASRC FIFO. When ASRIER:AFPWE=1, the rising edge of this signal will propose an interrupt request. Writing any value with this bit set will clear the interrupt request proposed by the rising edge of this bit.
        unsigned RESERVED0 : 2; //!< [23:22] Reserved. Should be written as zero for compatibility.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrstr_t;
#endif

/*
 * constants & macros for entire ASRC_ASRSTR register
 */
#define HW_ASRC_ASRSTR_ADDR      (REGS_ASRC_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRSTR           (*(volatile hw_asrc_asrstr_t *) HW_ASRC_ASRSTR_ADDR)
#define HW_ASRC_ASRSTR_RD()      (HW_ASRC_ASRSTR.U)
#endif

/*
 * constants & macros for individual ASRC_ASRSTR bitfields
 */

/* --- Register HW_ASRC_ASRSTR, field AIDEA[0] (RO)
 *
 * Number of data in Input Data Buffer A is less than threshold When set, this bit indicates that
 * number of data still available in ASRDIRA is less than threshold and the processor can write data
 * to ASRDIRA. When AIDEA is set, the ASRC generates data input A interrupt request to the
 * processor, if enabled (that is, ASRCTR:ADIEA = 1). A DMA request is always generated when the
 * AIDEA bit is set, but a DMA transfer takes place only if a DMA channel is active and triggered by
 * this event.
 */

#define BP_ASRC_ASRSTR_AIDEA      (0)      //!< Bit position for ASRC_ASRSTR_AIDEA.
#define BM_ASRC_ASRSTR_AIDEA      (0x00000001)  //!< Bit mask for ASRC_ASRSTR_AIDEA.

//! @brief Get value of ASRC_ASRSTR_AIDEA from a register value.
#define BG_ASRC_ASRSTR_AIDEA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_AIDEA) >> BP_ASRC_ASRSTR_AIDEA)

/* --- Register HW_ASRC_ASRSTR, field AIDEB[1] (RO)
 *
 * Number of data in Input Data Buffer B is less than threshold When set, this bit indicates that
 * number of data still available in ASRDIRB is less than threshold and the processor can write data
 * to ASRDIRB. When AIDEB is set, the ASRC generates data input B interrupt request to the
 * processor, if enabled (that is, ASRCTR:ADIEB = 1). A DMA request is always generated when the
 * AIDEB bit is set, but a DMA transfer takes place only if a DMA channel is active and triggered by
 * this event.
 */

#define BP_ASRC_ASRSTR_AIDEB      (1)      //!< Bit position for ASRC_ASRSTR_AIDEB.
#define BM_ASRC_ASRSTR_AIDEB      (0x00000002)  //!< Bit mask for ASRC_ASRSTR_AIDEB.

//! @brief Get value of ASRC_ASRSTR_AIDEB from a register value.
#define BG_ASRC_ASRSTR_AIDEB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_AIDEB) >> BP_ASRC_ASRSTR_AIDEB)

/* --- Register HW_ASRC_ASRSTR, field AIDEC[2] (RO)
 *
 * Number of data in Input Data Buffer C is less than threshold When set, this bit indicates that
 * number of data still available in ASRDIRC is less than threshold and the processor can write data
 * to ASRDIRC. When AIDEC is set, the ASRC generates data input C interrupt request to the
 * processor, if enabled (that is, ASRCTR:ADIEC = 1). A DMA request is always generated when the
 * AIDEC bit is set, but a DMA transfer takes place only if a DMA channel is active and triggered by
 * this event.
 */

#define BP_ASRC_ASRSTR_AIDEC      (2)      //!< Bit position for ASRC_ASRSTR_AIDEC.
#define BM_ASRC_ASRSTR_AIDEC      (0x00000004)  //!< Bit mask for ASRC_ASRSTR_AIDEC.

//! @brief Get value of ASRC_ASRSTR_AIDEC from a register value.
#define BG_ASRC_ASRSTR_AIDEC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_AIDEC) >> BP_ASRC_ASRSTR_AIDEC)

/* --- Register HW_ASRC_ASRSTR, field AODFA[3] (RO)
 *
 * Number of data in Output Data Buffer A is greater than threshold When set, this bit indicates
 * that number of data already existing in ASRDORA is greater than threshold and the processor can
 * read data from ASRDORA. When AODFA is set, the ASRC generates data output A interrupt request to
 * the processor, if enabled (that is, ASRCTR:ADOEA = 1). A DMA request is always generated when the
 * AODFA bit is set, but a DMA transfer takes place only if a DMA channel is active and triggered by
 * this event.
 */

#define BP_ASRC_ASRSTR_AODFA      (3)      //!< Bit position for ASRC_ASRSTR_AODFA.
#define BM_ASRC_ASRSTR_AODFA      (0x00000008)  //!< Bit mask for ASRC_ASRSTR_AODFA.

//! @brief Get value of ASRC_ASRSTR_AODFA from a register value.
#define BG_ASRC_ASRSTR_AODFA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_AODFA) >> BP_ASRC_ASRSTR_AODFA)

/* --- Register HW_ASRC_ASRSTR, field AODFB[4] (RO)
 *
 * Number of data in Output Data Buffer B is greater than threshold When set, this bit indicates
 * that number of data already existing in ASRDORB is greater than threshold and the processor can
 * read data from ASRDORB. When AODFB is set, the ASRC generates data output B interrupt request to
 * the processor, if enabled (that is, ASRCTR:ADOEB = 1). A DMA request is always generated when the
 * AODFB bit is set, but a DMA transfer takes place only if a DMA channel is active and triggered by
 * this event.
 */

#define BP_ASRC_ASRSTR_AODFB      (4)      //!< Bit position for ASRC_ASRSTR_AODFB.
#define BM_ASRC_ASRSTR_AODFB      (0x00000010)  //!< Bit mask for ASRC_ASRSTR_AODFB.

//! @brief Get value of ASRC_ASRSTR_AODFB from a register value.
#define BG_ASRC_ASRSTR_AODFB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_AODFB) >> BP_ASRC_ASRSTR_AODFB)

/* --- Register HW_ASRC_ASRSTR, field AODFC[5] (RO)
 *
 * Number of data in Output Data Buffer C is greater than threshold When set, this bit indicates
 * that number of data already existing in ASRDORC is greater than threshold and the processor can
 * read data from ASRDORC. When AODFC is set, the ASRC generates data output C interrupt request to
 * the processor, if enabled (that is, ASRCTR:ADOEC = 1). A DMA request is always generated when the
 * AODFC bit is set, but a DMA transfer takes place only if a DMA channel is active and triggered by
 * this event.
 */

#define BP_ASRC_ASRSTR_AODFC      (5)      //!< Bit position for ASRC_ASRSTR_AODFC.
#define BM_ASRC_ASRSTR_AODFC      (0x00000020)  //!< Bit mask for ASRC_ASRSTR_AODFC.

//! @brief Get value of ASRC_ASRSTR_AODFC from a register value.
#define BG_ASRC_ASRSTR_AODFC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_AODFC) >> BP_ASRC_ASRSTR_AODFC)

/* --- Register HW_ASRC_ASRSTR, field AOLE[6] (RO)
 *
 * Overload Error Flag When set, this bit indicates that the task rate is too high for the ASRC to
 * handle. The reasons for overload may be: - too high input clock frequency, - too high output
 * clock frequency, - incorrect selection of the pre-filter, - low ASRC processing clock, - too many
 * channels, - underrun, - or any combination of the reasons above. Since the ASRC uses the same
 * hardware resources to perform various tasks, the real reason for the overload is not straight
 * forward, and it should be carefully analyzed by the programmer. If ASRCTR:AOLIE=1, an interrupt
 * will be proposed when this bit is set. Write any value with this bit set as one into the status
 * register will clear this bit and the interrupt request proposed by this bit.
 */

#define BP_ASRC_ASRSTR_AOLE      (6)      //!< Bit position for ASRC_ASRSTR_AOLE.
#define BM_ASRC_ASRSTR_AOLE      (0x00000040)  //!< Bit mask for ASRC_ASRSTR_AOLE.

//! @brief Get value of ASRC_ASRSTR_AOLE from a register value.
#define BG_ASRC_ASRSTR_AOLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_AOLE) >> BP_ASRC_ASRSTR_AOLE)

/* --- Register HW_ASRC_ASRSTR, field FPWT[7] (RO)
 *
 * FP is in wait states This bit is for debug only. When set, this bit indicates that ASRC is in
 * wait states. When clear, this bit indicates that ASRC is not in wait states. If ASRCTR:AFPWE=1
 * and ASRCTR:ASDBG=1, an interrupt will be proposed when this bit is set.
 */

#define BP_ASRC_ASRSTR_FPWT      (7)      //!< Bit position for ASRC_ASRSTR_FPWT.
#define BM_ASRC_ASRSTR_FPWT      (0x00000080)  //!< Bit mask for ASRC_ASRSTR_FPWT.

//! @brief Get value of ASRC_ASRSTR_FPWT from a register value.
#define BG_ASRC_ASRSTR_FPWT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_FPWT) >> BP_ASRC_ASRSTR_FPWT)

/* --- Register HW_ASRC_ASRSTR, field AIDUA[8] (RO)
 *
 * Input Data Buffer A has underflowed When set, this bit indicates that input data buffer A has
 * underflowed. When clear, this bit indicates that input data buffer A has not underflowed.
 */

#define BP_ASRC_ASRSTR_AIDUA      (8)      //!< Bit position for ASRC_ASRSTR_AIDUA.
#define BM_ASRC_ASRSTR_AIDUA      (0x00000100)  //!< Bit mask for ASRC_ASRSTR_AIDUA.

//! @brief Get value of ASRC_ASRSTR_AIDUA from a register value.
#define BG_ASRC_ASRSTR_AIDUA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_AIDUA) >> BP_ASRC_ASRSTR_AIDUA)

/* --- Register HW_ASRC_ASRSTR, field AIDUB[9] (RO)
 *
 * Input Data Buffer B has underflowed When set, this bit indicates that input data buffer B has
 * underflowed. When clear, this bit indicates that input data buffer B has not underflowed.
 */

#define BP_ASRC_ASRSTR_AIDUB      (9)      //!< Bit position for ASRC_ASRSTR_AIDUB.
#define BM_ASRC_ASRSTR_AIDUB      (0x00000200)  //!< Bit mask for ASRC_ASRSTR_AIDUB.

//! @brief Get value of ASRC_ASRSTR_AIDUB from a register value.
#define BG_ASRC_ASRSTR_AIDUB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_AIDUB) >> BP_ASRC_ASRSTR_AIDUB)

/* --- Register HW_ASRC_ASRSTR, field AIDUC[10] (RO)
 *
 * Input Data Buffer C has underflowed When set, this bit indicates that input data buffer C has
 * underflowed. When clear, this bit indicates that input data buffer C has not underflowed.
 */

#define BP_ASRC_ASRSTR_AIDUC      (10)      //!< Bit position for ASRC_ASRSTR_AIDUC.
#define BM_ASRC_ASRSTR_AIDUC      (0x00000400)  //!< Bit mask for ASRC_ASRSTR_AIDUC.

//! @brief Get value of ASRC_ASRSTR_AIDUC from a register value.
#define BG_ASRC_ASRSTR_AIDUC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_AIDUC) >> BP_ASRC_ASRSTR_AIDUC)

/* --- Register HW_ASRC_ASRSTR, field AODOA[11] (RO)
 *
 * Output Data Buffer A has overflowed When set, this bit indicates that output data buffer A has
 * overflowed. When clear, this bit indicates that output data buffer A has not overflowed
 */

#define BP_ASRC_ASRSTR_AODOA      (11)      //!< Bit position for ASRC_ASRSTR_AODOA.
#define BM_ASRC_ASRSTR_AODOA      (0x00000800)  //!< Bit mask for ASRC_ASRSTR_AODOA.

//! @brief Get value of ASRC_ASRSTR_AODOA from a register value.
#define BG_ASRC_ASRSTR_AODOA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_AODOA) >> BP_ASRC_ASRSTR_AODOA)

/* --- Register HW_ASRC_ASRSTR, field AODOB[12] (RO)
 *
 * Output Data Buffer B has overflowed When set, this bit indicates that output data buffer B has
 * overflowed. When clear, this bit indicates that output data buffer B has not overflowed
 */

#define BP_ASRC_ASRSTR_AODOB      (12)      //!< Bit position for ASRC_ASRSTR_AODOB.
#define BM_ASRC_ASRSTR_AODOB      (0x00001000)  //!< Bit mask for ASRC_ASRSTR_AODOB.

//! @brief Get value of ASRC_ASRSTR_AODOB from a register value.
#define BG_ASRC_ASRSTR_AODOB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_AODOB) >> BP_ASRC_ASRSTR_AODOB)

/* --- Register HW_ASRC_ASRSTR, field AODOC[13] (RO)
 *
 * Output Data Buffer C has overflowed When set, this bit indicates that output data buffer C has
 * overflowed. When clear, this bit indicates that output data buffer C has not overflowed
 */

#define BP_ASRC_ASRSTR_AODOC      (13)      //!< Bit position for ASRC_ASRSTR_AODOC.
#define BM_ASRC_ASRSTR_AODOC      (0x00002000)  //!< Bit mask for ASRC_ASRSTR_AODOC.

//! @brief Get value of ASRC_ASRSTR_AODOC from a register value.
#define BG_ASRC_ASRSTR_AODOC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_AODOC) >> BP_ASRC_ASRSTR_AODOC)

/* --- Register HW_ASRC_ASRSTR, field AIOLA[14] (RO)
 *
 * Pair A Input Task Overload When set, this bit indicates that pair A input task is oveloaded. This
 * may help to check the reason why overload interrupt happens. The bit is cleared when writing
 * ASRCTR:AOLIE as 1.
 */

#define BP_ASRC_ASRSTR_AIOLA      (14)      //!< Bit position for ASRC_ASRSTR_AIOLA.
#define BM_ASRC_ASRSTR_AIOLA      (0x00004000)  //!< Bit mask for ASRC_ASRSTR_AIOLA.

//! @brief Get value of ASRC_ASRSTR_AIOLA from a register value.
#define BG_ASRC_ASRSTR_AIOLA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_AIOLA) >> BP_ASRC_ASRSTR_AIOLA)

/* --- Register HW_ASRC_ASRSTR, field AIOLB[15] (RO)
 *
 * Pair B Input Task Overload When set, this bit indicates that pair B input task is oveloaded. This
 * may help to check the reason why overload interrupt happens. The bit is cleared when writing
 * ASRCTR:AOLIE as 1.
 */

#define BP_ASRC_ASRSTR_AIOLB      (15)      //!< Bit position for ASRC_ASRSTR_AIOLB.
#define BM_ASRC_ASRSTR_AIOLB      (0x00008000)  //!< Bit mask for ASRC_ASRSTR_AIOLB.

//! @brief Get value of ASRC_ASRSTR_AIOLB from a register value.
#define BG_ASRC_ASRSTR_AIOLB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_AIOLB) >> BP_ASRC_ASRSTR_AIOLB)

/* --- Register HW_ASRC_ASRSTR, field AIOLC[16] (RO)
 *
 * Pair C Input Task Overload When set, this bit indicates that pair C input task is oveloaded. This
 * may help to check the reason why overload interrupt happens. The bit is cleared when writing
 * ASRCTR:AOLIE as 1.
 */

#define BP_ASRC_ASRSTR_AIOLC      (16)      //!< Bit position for ASRC_ASRSTR_AIOLC.
#define BM_ASRC_ASRSTR_AIOLC      (0x00010000)  //!< Bit mask for ASRC_ASRSTR_AIOLC.

//! @brief Get value of ASRC_ASRSTR_AIOLC from a register value.
#define BG_ASRC_ASRSTR_AIOLC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_AIOLC) >> BP_ASRC_ASRSTR_AIOLC)

/* --- Register HW_ASRC_ASRSTR, field AOOLA[17] (RO)
 *
 * Pair A Output Task Overload When set, this bit indicates that pair A output task is oveloaded.
 * This may help to check the reason why overload interrupt happens. The bit is cleared when writing
 * ASRCTR:AOLIE as 1.
 */

#define BP_ASRC_ASRSTR_AOOLA      (17)      //!< Bit position for ASRC_ASRSTR_AOOLA.
#define BM_ASRC_ASRSTR_AOOLA      (0x00020000)  //!< Bit mask for ASRC_ASRSTR_AOOLA.

//! @brief Get value of ASRC_ASRSTR_AOOLA from a register value.
#define BG_ASRC_ASRSTR_AOOLA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_AOOLA) >> BP_ASRC_ASRSTR_AOOLA)

/* --- Register HW_ASRC_ASRSTR, field AOOLB[18] (RO)
 *
 * Pair B Output Task Overload When set, this bit indicates that pair B output task is oveloaded.
 * This may help to check the reason why overload interrupt happens. The bit is cleared when writing
 * ASRCTR:AOLIE as 1.
 */

#define BP_ASRC_ASRSTR_AOOLB      (18)      //!< Bit position for ASRC_ASRSTR_AOOLB.
#define BM_ASRC_ASRSTR_AOOLB      (0x00040000)  //!< Bit mask for ASRC_ASRSTR_AOOLB.

//! @brief Get value of ASRC_ASRSTR_AOOLB from a register value.
#define BG_ASRC_ASRSTR_AOOLB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_AOOLB) >> BP_ASRC_ASRSTR_AOOLB)

/* --- Register HW_ASRC_ASRSTR, field AOOLC[19] (RO)
 *
 * Pair C Output Task Overload When set, this bit indicates that pair C output task is oveloaded.
 * This may help to check the reason why overload interrupt happens. The bit is cleared when writing
 * ASRCTR:AOLIE as 1.
 */

#define BP_ASRC_ASRSTR_AOOLC      (19)      //!< Bit position for ASRC_ASRSTR_AOOLC.
#define BM_ASRC_ASRSTR_AOOLC      (0x00080000)  //!< Bit mask for ASRC_ASRSTR_AOOLC.

//! @brief Get value of ASRC_ASRSTR_AOOLC from a register value.
#define BG_ASRC_ASRSTR_AOOLC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_AOOLC) >> BP_ASRC_ASRSTR_AOOLC)

/* --- Register HW_ASRC_ASRSTR, field ATQOL[20] (RO)
 *
 * Task Queue FIFO overload When set, this bit indicates that task queue FIFO logic is oveloaded.
 * This may help to check the reason why overload interrupt happens. The bit is cleared when writing
 * ASRCTR:AOLIE as 1.
 */

#define BP_ASRC_ASRSTR_ATQOL      (20)      //!< Bit position for ASRC_ASRSTR_ATQOL.
#define BM_ASRC_ASRSTR_ATQOL      (0x00100000)  //!< Bit mask for ASRC_ASRSTR_ATQOL.

//! @brief Get value of ASRC_ASRSTR_ATQOL from a register value.
#define BG_ASRC_ASRSTR_ATQOL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_ATQOL) >> BP_ASRC_ASRSTR_ATQOL)

/* --- Register HW_ASRC_ASRSTR, field DSLCNT[21] (RO)
 *
 * DSL Counter Input to FIFO ready When set, this bit indicates that new DSL counter information is
 * stored in the internal ASRC FIFO. When clear, this bit indicates that new DSL counter information
 * is in the process of storage into the internal ASRC FIFO. When ASRIER:AFPWE=1, the rising edge of
 * this signal will propose an interrupt request. Writing any value with this bit set will clear the
 * interrupt request proposed by the rising edge of this bit.
 */

#define BP_ASRC_ASRSTR_DSLCNT      (21)      //!< Bit position for ASRC_ASRSTR_DSLCNT.
#define BM_ASRC_ASRSTR_DSLCNT      (0x00200000)  //!< Bit mask for ASRC_ASRSTR_DSLCNT.

//! @brief Get value of ASRC_ASRSTR_DSLCNT from a register value.
#define BG_ASRC_ASRSTR_DSLCNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_DSLCNT) >> BP_ASRC_ASRSTR_DSLCNT)

/* --- Register HW_ASRC_ASRSTR, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRSTR_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRSTR_UNIMPLEMENTED.
#define BM_ASRC_ASRSTR_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRSTR_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRSTR_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRSTR_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRSTR_UNIMPLEMENTED) >> BP_ASRC_ASRSTR_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRPMN1 - ASRC Parameter Register n
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRPMN1 - ASRC Parameter Register n (RW)
 *
 * Reset value: 0x00000000
 *
 * Parameter registers determine the performance of ASRC.  The parameter registers must be
 * initialized by software before ASRC is enabled. Recommended values are given in ASRC Misc Control
 * Register 1 for Pair C below,   ASRC Parameter Registers (ASRPM1~ASRPM5)          Register  Offset
 * Access  Reset Value  Recommend Value      asrcpm1  0x40  R/W  0x00_0000  0x7fffff    asrcpm2
 * 0x44  R/W  0x00_0000  0x255555    asrcpm3  0x48  R/W  0x00_0000  0xff7280    asrcpm4  0x4C  R/W
 * 0x00_0000  0xff7280    asrcpm5  0x50  R/W  0x00_0000  0xff7280
 */
typedef union _hw_asrc_asrpmn1
{
    reg32_t U;
    struct _hw_asrc_asrpmn1_bitfields
    {
        unsigned PARAMETER_VALUE : 24; //!< [23:0] See recommended values table.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrpmn1_t;
#endif

/*
 * constants & macros for entire ASRC_ASRPMN1 register
 */
#define HW_ASRC_ASRPMN1_ADDR      (REGS_ASRC_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRPMN1           (*(volatile hw_asrc_asrpmn1_t *) HW_ASRC_ASRPMN1_ADDR)
#define HW_ASRC_ASRPMN1_RD()      (HW_ASRC_ASRPMN1.U)
#define HW_ASRC_ASRPMN1_WR(v)     (HW_ASRC_ASRPMN1.U = (v))
#define HW_ASRC_ASRPMN1_SET(v)    (HW_ASRC_ASRPMN1_WR(HW_ASRC_ASRPMN1_RD() |  (v)))
#define HW_ASRC_ASRPMN1_CLR(v)    (HW_ASRC_ASRPMN1_WR(HW_ASRC_ASRPMN1_RD() & ~(v)))
#define HW_ASRC_ASRPMN1_TOG(v)    (HW_ASRC_ASRPMN1_WR(HW_ASRC_ASRPMN1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRPMN1 bitfields
 */

/* --- Register HW_ASRC_ASRPMN1, field PARAMETER_VALUE[23:0] (RW)
 *
 * See recommended values table.
 */

#define BP_ASRC_ASRPMN1_PARAMETER_VALUE      (0)      //!< Bit position for ASRC_ASRPMN1_PARAMETER_VALUE.
#define BM_ASRC_ASRPMN1_PARAMETER_VALUE      (0x00ffffff)  //!< Bit mask for ASRC_ASRPMN1_PARAMETER_VALUE.

//! @brief Get value of ASRC_ASRPMN1_PARAMETER_VALUE from a register value.
#define BG_ASRC_ASRPMN1_PARAMETER_VALUE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRPMN1_PARAMETER_VALUE) >> BP_ASRC_ASRPMN1_PARAMETER_VALUE)

//! @brief Format value for bitfield ASRC_ASRPMN1_PARAMETER_VALUE.
#define BF_ASRC_ASRPMN1_PARAMETER_VALUE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRPMN1_PARAMETER_VALUE) & BM_ASRC_ASRPMN1_PARAMETER_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PARAMETER_VALUE field to a new value.
#define BW_ASRC_ASRPMN1_PARAMETER_VALUE(v)   (HW_ASRC_ASRPMN1_WR((HW_ASRC_ASRPMN1_RD() & ~BM_ASRC_ASRPMN1_PARAMETER_VALUE) | BF_ASRC_ASRPMN1_PARAMETER_VALUE(v)))
#endif

/* --- Register HW_ASRC_ASRPMN1, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRPMN1_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRPMN1_UNIMPLEMENTED.
#define BM_ASRC_ASRPMN1_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRPMN1_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRPMN1_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRPMN1_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRPMN1_UNIMPLEMENTED) >> BP_ASRC_ASRPMN1_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRPMN2 - ASRC Parameter Register n
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRPMN2 - ASRC Parameter Register n (RW)
 *
 * Reset value: 0x00000000
 *
 * Parameter registers determine the performance of ASRC.  The parameter registers must be
 * initialized by software before ASRC is enabled. Recommended values are given in ASRC Misc Control
 * Register 1 for Pair C below,   ASRC Parameter Registers (ASRPM1~ASRPM5)          Register  Offset
 * Access  Reset Value  Recommend Value      asrcpm1  0x40  R/W  0x00_0000  0x7fffff    asrcpm2
 * 0x44  R/W  0x00_0000  0x255555    asrcpm3  0x48  R/W  0x00_0000  0xff7280    asrcpm4  0x4C  R/W
 * 0x00_0000  0xff7280    asrcpm5  0x50  R/W  0x00_0000  0xff7280
 */
typedef union _hw_asrc_asrpmn2
{
    reg32_t U;
    struct _hw_asrc_asrpmn2_bitfields
    {
        unsigned PARAMETER_VALUE : 24; //!< [23:0] See recommended values table.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrpmn2_t;
#endif

/*
 * constants & macros for entire ASRC_ASRPMN2 register
 */
#define HW_ASRC_ASRPMN2_ADDR      (REGS_ASRC_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRPMN2           (*(volatile hw_asrc_asrpmn2_t *) HW_ASRC_ASRPMN2_ADDR)
#define HW_ASRC_ASRPMN2_RD()      (HW_ASRC_ASRPMN2.U)
#define HW_ASRC_ASRPMN2_WR(v)     (HW_ASRC_ASRPMN2.U = (v))
#define HW_ASRC_ASRPMN2_SET(v)    (HW_ASRC_ASRPMN2_WR(HW_ASRC_ASRPMN2_RD() |  (v)))
#define HW_ASRC_ASRPMN2_CLR(v)    (HW_ASRC_ASRPMN2_WR(HW_ASRC_ASRPMN2_RD() & ~(v)))
#define HW_ASRC_ASRPMN2_TOG(v)    (HW_ASRC_ASRPMN2_WR(HW_ASRC_ASRPMN2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRPMN2 bitfields
 */

/* --- Register HW_ASRC_ASRPMN2, field PARAMETER_VALUE[23:0] (RW)
 *
 * See recommended values table.
 */

#define BP_ASRC_ASRPMN2_PARAMETER_VALUE      (0)      //!< Bit position for ASRC_ASRPMN2_PARAMETER_VALUE.
#define BM_ASRC_ASRPMN2_PARAMETER_VALUE      (0x00ffffff)  //!< Bit mask for ASRC_ASRPMN2_PARAMETER_VALUE.

//! @brief Get value of ASRC_ASRPMN2_PARAMETER_VALUE from a register value.
#define BG_ASRC_ASRPMN2_PARAMETER_VALUE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRPMN2_PARAMETER_VALUE) >> BP_ASRC_ASRPMN2_PARAMETER_VALUE)

//! @brief Format value for bitfield ASRC_ASRPMN2_PARAMETER_VALUE.
#define BF_ASRC_ASRPMN2_PARAMETER_VALUE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRPMN2_PARAMETER_VALUE) & BM_ASRC_ASRPMN2_PARAMETER_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PARAMETER_VALUE field to a new value.
#define BW_ASRC_ASRPMN2_PARAMETER_VALUE(v)   (HW_ASRC_ASRPMN2_WR((HW_ASRC_ASRPMN2_RD() & ~BM_ASRC_ASRPMN2_PARAMETER_VALUE) | BF_ASRC_ASRPMN2_PARAMETER_VALUE(v)))
#endif

/* --- Register HW_ASRC_ASRPMN2, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRPMN2_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRPMN2_UNIMPLEMENTED.
#define BM_ASRC_ASRPMN2_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRPMN2_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRPMN2_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRPMN2_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRPMN2_UNIMPLEMENTED) >> BP_ASRC_ASRPMN2_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRPMN3 - ASRC Parameter Register n
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRPMN3 - ASRC Parameter Register n (RW)
 *
 * Reset value: 0x00000000
 *
 * Parameter registers determine the performance of ASRC.  The parameter registers must be
 * initialized by software before ASRC is enabled. Recommended values are given in ASRC Misc Control
 * Register 1 for Pair C below,   ASRC Parameter Registers (ASRPM1~ASRPM5)          Register  Offset
 * Access  Reset Value  Recommend Value      asrcpm1  0x40  R/W  0x00_0000  0x7fffff    asrcpm2
 * 0x44  R/W  0x00_0000  0x255555    asrcpm3  0x48  R/W  0x00_0000  0xff7280    asrcpm4  0x4C  R/W
 * 0x00_0000  0xff7280    asrcpm5  0x50  R/W  0x00_0000  0xff7280
 */
typedef union _hw_asrc_asrpmn3
{
    reg32_t U;
    struct _hw_asrc_asrpmn3_bitfields
    {
        unsigned PARAMETER_VALUE : 24; //!< [23:0] See recommended values table.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrpmn3_t;
#endif

/*
 * constants & macros for entire ASRC_ASRPMN3 register
 */
#define HW_ASRC_ASRPMN3_ADDR      (REGS_ASRC_BASE + 0x48)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRPMN3           (*(volatile hw_asrc_asrpmn3_t *) HW_ASRC_ASRPMN3_ADDR)
#define HW_ASRC_ASRPMN3_RD()      (HW_ASRC_ASRPMN3.U)
#define HW_ASRC_ASRPMN3_WR(v)     (HW_ASRC_ASRPMN3.U = (v))
#define HW_ASRC_ASRPMN3_SET(v)    (HW_ASRC_ASRPMN3_WR(HW_ASRC_ASRPMN3_RD() |  (v)))
#define HW_ASRC_ASRPMN3_CLR(v)    (HW_ASRC_ASRPMN3_WR(HW_ASRC_ASRPMN3_RD() & ~(v)))
#define HW_ASRC_ASRPMN3_TOG(v)    (HW_ASRC_ASRPMN3_WR(HW_ASRC_ASRPMN3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRPMN3 bitfields
 */

/* --- Register HW_ASRC_ASRPMN3, field PARAMETER_VALUE[23:0] (RW)
 *
 * See recommended values table.
 */

#define BP_ASRC_ASRPMN3_PARAMETER_VALUE      (0)      //!< Bit position for ASRC_ASRPMN3_PARAMETER_VALUE.
#define BM_ASRC_ASRPMN3_PARAMETER_VALUE      (0x00ffffff)  //!< Bit mask for ASRC_ASRPMN3_PARAMETER_VALUE.

//! @brief Get value of ASRC_ASRPMN3_PARAMETER_VALUE from a register value.
#define BG_ASRC_ASRPMN3_PARAMETER_VALUE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRPMN3_PARAMETER_VALUE) >> BP_ASRC_ASRPMN3_PARAMETER_VALUE)

//! @brief Format value for bitfield ASRC_ASRPMN3_PARAMETER_VALUE.
#define BF_ASRC_ASRPMN3_PARAMETER_VALUE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRPMN3_PARAMETER_VALUE) & BM_ASRC_ASRPMN3_PARAMETER_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PARAMETER_VALUE field to a new value.
#define BW_ASRC_ASRPMN3_PARAMETER_VALUE(v)   (HW_ASRC_ASRPMN3_WR((HW_ASRC_ASRPMN3_RD() & ~BM_ASRC_ASRPMN3_PARAMETER_VALUE) | BF_ASRC_ASRPMN3_PARAMETER_VALUE(v)))
#endif

/* --- Register HW_ASRC_ASRPMN3, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRPMN3_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRPMN3_UNIMPLEMENTED.
#define BM_ASRC_ASRPMN3_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRPMN3_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRPMN3_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRPMN3_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRPMN3_UNIMPLEMENTED) >> BP_ASRC_ASRPMN3_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRPMN4 - ASRC Parameter Register n
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRPMN4 - ASRC Parameter Register n (RW)
 *
 * Reset value: 0x00000000
 *
 * Parameter registers determine the performance of ASRC.  The parameter registers must be
 * initialized by software before ASRC is enabled. Recommended values are given in ASRC Misc Control
 * Register 1 for Pair C below,   ASRC Parameter Registers (ASRPM1~ASRPM5)          Register  Offset
 * Access  Reset Value  Recommend Value      asrcpm1  0x40  R/W  0x00_0000  0x7fffff    asrcpm2
 * 0x44  R/W  0x00_0000  0x255555    asrcpm3  0x48  R/W  0x00_0000  0xff7280    asrcpm4  0x4C  R/W
 * 0x00_0000  0xff7280    asrcpm5  0x50  R/W  0x00_0000  0xff7280
 */
typedef union _hw_asrc_asrpmn4
{
    reg32_t U;
    struct _hw_asrc_asrpmn4_bitfields
    {
        unsigned PARAMETER_VALUE : 24; //!< [23:0] See recommended values table.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrpmn4_t;
#endif

/*
 * constants & macros for entire ASRC_ASRPMN4 register
 */
#define HW_ASRC_ASRPMN4_ADDR      (REGS_ASRC_BASE + 0x4c)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRPMN4           (*(volatile hw_asrc_asrpmn4_t *) HW_ASRC_ASRPMN4_ADDR)
#define HW_ASRC_ASRPMN4_RD()      (HW_ASRC_ASRPMN4.U)
#define HW_ASRC_ASRPMN4_WR(v)     (HW_ASRC_ASRPMN4.U = (v))
#define HW_ASRC_ASRPMN4_SET(v)    (HW_ASRC_ASRPMN4_WR(HW_ASRC_ASRPMN4_RD() |  (v)))
#define HW_ASRC_ASRPMN4_CLR(v)    (HW_ASRC_ASRPMN4_WR(HW_ASRC_ASRPMN4_RD() & ~(v)))
#define HW_ASRC_ASRPMN4_TOG(v)    (HW_ASRC_ASRPMN4_WR(HW_ASRC_ASRPMN4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRPMN4 bitfields
 */

/* --- Register HW_ASRC_ASRPMN4, field PARAMETER_VALUE[23:0] (RW)
 *
 * See recommended values table.
 */

#define BP_ASRC_ASRPMN4_PARAMETER_VALUE      (0)      //!< Bit position for ASRC_ASRPMN4_PARAMETER_VALUE.
#define BM_ASRC_ASRPMN4_PARAMETER_VALUE      (0x00ffffff)  //!< Bit mask for ASRC_ASRPMN4_PARAMETER_VALUE.

//! @brief Get value of ASRC_ASRPMN4_PARAMETER_VALUE from a register value.
#define BG_ASRC_ASRPMN4_PARAMETER_VALUE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRPMN4_PARAMETER_VALUE) >> BP_ASRC_ASRPMN4_PARAMETER_VALUE)

//! @brief Format value for bitfield ASRC_ASRPMN4_PARAMETER_VALUE.
#define BF_ASRC_ASRPMN4_PARAMETER_VALUE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRPMN4_PARAMETER_VALUE) & BM_ASRC_ASRPMN4_PARAMETER_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PARAMETER_VALUE field to a new value.
#define BW_ASRC_ASRPMN4_PARAMETER_VALUE(v)   (HW_ASRC_ASRPMN4_WR((HW_ASRC_ASRPMN4_RD() & ~BM_ASRC_ASRPMN4_PARAMETER_VALUE) | BF_ASRC_ASRPMN4_PARAMETER_VALUE(v)))
#endif

/* --- Register HW_ASRC_ASRPMN4, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRPMN4_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRPMN4_UNIMPLEMENTED.
#define BM_ASRC_ASRPMN4_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRPMN4_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRPMN4_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRPMN4_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRPMN4_UNIMPLEMENTED) >> BP_ASRC_ASRPMN4_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRPMN5 - ASRC Parameter Register n
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRPMN5 - ASRC Parameter Register n (RW)
 *
 * Reset value: 0x00000000
 *
 * Parameter registers determine the performance of ASRC.  The parameter registers must be
 * initialized by software before ASRC is enabled. Recommended values are given in ASRC Misc Control
 * Register 1 for Pair C below,   ASRC Parameter Registers (ASRPM1~ASRPM5)          Register  Offset
 * Access  Reset Value  Recommend Value      asrcpm1  0x40  R/W  0x00_0000  0x7fffff    asrcpm2
 * 0x44  R/W  0x00_0000  0x255555    asrcpm3  0x48  R/W  0x00_0000  0xff7280    asrcpm4  0x4C  R/W
 * 0x00_0000  0xff7280    asrcpm5  0x50  R/W  0x00_0000  0xff7280
 */
typedef union _hw_asrc_asrpmn5
{
    reg32_t U;
    struct _hw_asrc_asrpmn5_bitfields
    {
        unsigned PARAMETER_VALUE : 24; //!< [23:0] See recommended values table.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrpmn5_t;
#endif

/*
 * constants & macros for entire ASRC_ASRPMN5 register
 */
#define HW_ASRC_ASRPMN5_ADDR      (REGS_ASRC_BASE + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRPMN5           (*(volatile hw_asrc_asrpmn5_t *) HW_ASRC_ASRPMN5_ADDR)
#define HW_ASRC_ASRPMN5_RD()      (HW_ASRC_ASRPMN5.U)
#define HW_ASRC_ASRPMN5_WR(v)     (HW_ASRC_ASRPMN5.U = (v))
#define HW_ASRC_ASRPMN5_SET(v)    (HW_ASRC_ASRPMN5_WR(HW_ASRC_ASRPMN5_RD() |  (v)))
#define HW_ASRC_ASRPMN5_CLR(v)    (HW_ASRC_ASRPMN5_WR(HW_ASRC_ASRPMN5_RD() & ~(v)))
#define HW_ASRC_ASRPMN5_TOG(v)    (HW_ASRC_ASRPMN5_WR(HW_ASRC_ASRPMN5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRPMN5 bitfields
 */

/* --- Register HW_ASRC_ASRPMN5, field PARAMETER_VALUE[23:0] (RW)
 *
 * See recommended values table.
 */

#define BP_ASRC_ASRPMN5_PARAMETER_VALUE      (0)      //!< Bit position for ASRC_ASRPMN5_PARAMETER_VALUE.
#define BM_ASRC_ASRPMN5_PARAMETER_VALUE      (0x00ffffff)  //!< Bit mask for ASRC_ASRPMN5_PARAMETER_VALUE.

//! @brief Get value of ASRC_ASRPMN5_PARAMETER_VALUE from a register value.
#define BG_ASRC_ASRPMN5_PARAMETER_VALUE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRPMN5_PARAMETER_VALUE) >> BP_ASRC_ASRPMN5_PARAMETER_VALUE)

//! @brief Format value for bitfield ASRC_ASRPMN5_PARAMETER_VALUE.
#define BF_ASRC_ASRPMN5_PARAMETER_VALUE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRPMN5_PARAMETER_VALUE) & BM_ASRC_ASRPMN5_PARAMETER_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PARAMETER_VALUE field to a new value.
#define BW_ASRC_ASRPMN5_PARAMETER_VALUE(v)   (HW_ASRC_ASRPMN5_WR((HW_ASRC_ASRPMN5_RD() & ~BM_ASRC_ASRPMN5_PARAMETER_VALUE) | BF_ASRC_ASRPMN5_PARAMETER_VALUE(v)))
#endif

/* --- Register HW_ASRC_ASRPMN5, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRPMN5_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRPMN5_UNIMPLEMENTED.
#define BM_ASRC_ASRPMN5_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRPMN5_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRPMN5_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRPMN5_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRPMN5_UNIMPLEMENTED) >> BP_ASRC_ASRPMN5_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRTFR1 - ASRC ASRC Task Queue FIFO Register 1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRTFR1 - ASRC ASRC Task Queue FIFO Register 1 (RW)
 *
 * Reset value: 0x00000000
 *
 * These registers define and show The register defines and shows the parameters for ASRC inner task
 * queue FIFOs.
 */
typedef union _hw_asrc_asrtfr1
{
    reg32_t U;
    struct _hw_asrc_asrtfr1_bitfields
    {
        unsigned RESERVED0 : 6; //!< [5:0] Reserved. Should be written as zero for compatibility.
        unsigned TF_BASE : 7; //!< [12:6] Base address for task queue FIFO. Set to 0x7C.
        unsigned TF_FILL : 7; //!< [19:13] Current number of entries in task queue FIFO.
        unsigned RESERVED1 : 4; //!< [23:20] Reserved. Should be written as zero for compatibility.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrtfr1_t;
#endif

/*
 * constants & macros for entire ASRC_ASRTFR1 register
 */
#define HW_ASRC_ASRTFR1_ADDR      (REGS_ASRC_BASE + 0x54)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRTFR1           (*(volatile hw_asrc_asrtfr1_t *) HW_ASRC_ASRTFR1_ADDR)
#define HW_ASRC_ASRTFR1_RD()      (HW_ASRC_ASRTFR1.U)
#define HW_ASRC_ASRTFR1_WR(v)     (HW_ASRC_ASRTFR1.U = (v))
#define HW_ASRC_ASRTFR1_SET(v)    (HW_ASRC_ASRTFR1_WR(HW_ASRC_ASRTFR1_RD() |  (v)))
#define HW_ASRC_ASRTFR1_CLR(v)    (HW_ASRC_ASRTFR1_WR(HW_ASRC_ASRTFR1_RD() & ~(v)))
#define HW_ASRC_ASRTFR1_TOG(v)    (HW_ASRC_ASRTFR1_WR(HW_ASRC_ASRTFR1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRTFR1 bitfields
 */

/* --- Register HW_ASRC_ASRTFR1, field TF_BASE[12:6] (RW)
 *
 * Base address for task queue FIFO. Set to 0x7C.
 */

#define BP_ASRC_ASRTFR1_TF_BASE      (6)      //!< Bit position for ASRC_ASRTFR1_TF_BASE.
#define BM_ASRC_ASRTFR1_TF_BASE      (0x00001fc0)  //!< Bit mask for ASRC_ASRTFR1_TF_BASE.

//! @brief Get value of ASRC_ASRTFR1_TF_BASE from a register value.
#define BG_ASRC_ASRTFR1_TF_BASE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRTFR1_TF_BASE) >> BP_ASRC_ASRTFR1_TF_BASE)

//! @brief Format value for bitfield ASRC_ASRTFR1_TF_BASE.
#define BF_ASRC_ASRTFR1_TF_BASE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRTFR1_TF_BASE) & BM_ASRC_ASRTFR1_TF_BASE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TF_BASE field to a new value.
#define BW_ASRC_ASRTFR1_TF_BASE(v)   (HW_ASRC_ASRTFR1_WR((HW_ASRC_ASRTFR1_RD() & ~BM_ASRC_ASRTFR1_TF_BASE) | BF_ASRC_ASRTFR1_TF_BASE(v)))
#endif

/* --- Register HW_ASRC_ASRTFR1, field TF_FILL[19:13] (RO)
 *
 * Current number of entries in task queue FIFO.
 */

#define BP_ASRC_ASRTFR1_TF_FILL      (13)      //!< Bit position for ASRC_ASRTFR1_TF_FILL.
#define BM_ASRC_ASRTFR1_TF_FILL      (0x000fe000)  //!< Bit mask for ASRC_ASRTFR1_TF_FILL.

//! @brief Get value of ASRC_ASRTFR1_TF_FILL from a register value.
#define BG_ASRC_ASRTFR1_TF_FILL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRTFR1_TF_FILL) >> BP_ASRC_ASRTFR1_TF_FILL)

/* --- Register HW_ASRC_ASRTFR1, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRTFR1_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRTFR1_UNIMPLEMENTED.
#define BM_ASRC_ASRTFR1_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRTFR1_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRTFR1_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRTFR1_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRTFR1_UNIMPLEMENTED) >> BP_ASRC_ASRTFR1_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRCCR - ASRC Channel Counter Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRCCR - ASRC Channel Counter Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The ASRC channel counter register (ASRCCR) is a 24-bit read/write register that sets and reflects
 * the current specific input/output FIFO being accessed through shared peripheral bus for each ASRC
 * conversion pair.
 */
typedef union _hw_asrc_asrccr
{
    reg32_t U;
    struct _hw_asrc_asrccr_bitfields
    {
        unsigned ACIA : 4; //!< [3:0] The channel counter for Pair A's input FIFO These bits stand for the current channel being accessed through shared peripheral bus for Pair A's input FIFO's usage. The value can be any value between [0, ANCA-1]
        unsigned ACIB : 4; //!< [7:4] The channel counter for Pair B's input FIFO These bits stand for the current channel being accessed through shared peripheral bus for Pair B's input FIFO's usage. The value can be any value between [0, ANCB-1]
        unsigned ACIC : 4; //!< [11:8] The channel counter for Pair C's input FIFO These bits stand for the current channel being accessed through shared peripheral bus for Pair C's input FIFO's usage. The value can be any value between [0, ANCC-1]
        unsigned ACOA : 4; //!< [15:12] The channel counter for Pair A's output FIFO These bits stand for the current channel being accessed through shared peripheral bus for Pair A's output FIFO's usage. The value can be any value between [0, ANCA-1]
        unsigned ACOB : 4; //!< [19:16] The channel counter for Pair B's output FIFO These bits stand for the current channel being accessed through shared peripheral bus for Pair B's output FIFO's usage. The value can be any value between [0, ANCB-1]
        unsigned ACOC : 4; //!< [23:20] The channel counter for Pair C's output FIFO These bits stand for the current channel being accessed through shared peripheral bus for Pair C's output FIFO's usage. The value can be any value between [0, ANCC-1]
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrccr_t;
#endif

/*
 * constants & macros for entire ASRC_ASRCCR register
 */
#define HW_ASRC_ASRCCR_ADDR      (REGS_ASRC_BASE + 0x5c)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRCCR           (*(volatile hw_asrc_asrccr_t *) HW_ASRC_ASRCCR_ADDR)
#define HW_ASRC_ASRCCR_RD()      (HW_ASRC_ASRCCR.U)
#define HW_ASRC_ASRCCR_WR(v)     (HW_ASRC_ASRCCR.U = (v))
#define HW_ASRC_ASRCCR_SET(v)    (HW_ASRC_ASRCCR_WR(HW_ASRC_ASRCCR_RD() |  (v)))
#define HW_ASRC_ASRCCR_CLR(v)    (HW_ASRC_ASRCCR_WR(HW_ASRC_ASRCCR_RD() & ~(v)))
#define HW_ASRC_ASRCCR_TOG(v)    (HW_ASRC_ASRCCR_WR(HW_ASRC_ASRCCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRCCR bitfields
 */

/* --- Register HW_ASRC_ASRCCR, field ACIA[3:0] (RW)
 *
 * The channel counter for Pair A's input FIFO These bits stand for the current channel being
 * accessed through shared peripheral bus for Pair A's input FIFO's usage. The value can be any
 * value between [0, ANCA-1]
 */

#define BP_ASRC_ASRCCR_ACIA      (0)      //!< Bit position for ASRC_ASRCCR_ACIA.
#define BM_ASRC_ASRCCR_ACIA      (0x0000000f)  //!< Bit mask for ASRC_ASRCCR_ACIA.

//! @brief Get value of ASRC_ASRCCR_ACIA from a register value.
#define BG_ASRC_ASRCCR_ACIA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCCR_ACIA) >> BP_ASRC_ASRCCR_ACIA)

//! @brief Format value for bitfield ASRC_ASRCCR_ACIA.
#define BF_ASRC_ASRCCR_ACIA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCCR_ACIA) & BM_ASRC_ASRCCR_ACIA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ACIA field to a new value.
#define BW_ASRC_ASRCCR_ACIA(v)   (HW_ASRC_ASRCCR_WR((HW_ASRC_ASRCCR_RD() & ~BM_ASRC_ASRCCR_ACIA) | BF_ASRC_ASRCCR_ACIA(v)))
#endif

/* --- Register HW_ASRC_ASRCCR, field ACIB[7:4] (RW)
 *
 * The channel counter for Pair B's input FIFO These bits stand for the current channel being
 * accessed through shared peripheral bus for Pair B's input FIFO's usage. The value can be any
 * value between [0, ANCB-1]
 */

#define BP_ASRC_ASRCCR_ACIB      (4)      //!< Bit position for ASRC_ASRCCR_ACIB.
#define BM_ASRC_ASRCCR_ACIB      (0x000000f0)  //!< Bit mask for ASRC_ASRCCR_ACIB.

//! @brief Get value of ASRC_ASRCCR_ACIB from a register value.
#define BG_ASRC_ASRCCR_ACIB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCCR_ACIB) >> BP_ASRC_ASRCCR_ACIB)

//! @brief Format value for bitfield ASRC_ASRCCR_ACIB.
#define BF_ASRC_ASRCCR_ACIB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCCR_ACIB) & BM_ASRC_ASRCCR_ACIB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ACIB field to a new value.
#define BW_ASRC_ASRCCR_ACIB(v)   (HW_ASRC_ASRCCR_WR((HW_ASRC_ASRCCR_RD() & ~BM_ASRC_ASRCCR_ACIB) | BF_ASRC_ASRCCR_ACIB(v)))
#endif

/* --- Register HW_ASRC_ASRCCR, field ACIC[11:8] (RW)
 *
 * The channel counter for Pair C's input FIFO These bits stand for the current channel being
 * accessed through shared peripheral bus for Pair C's input FIFO's usage. The value can be any
 * value between [0, ANCC-1]
 */

#define BP_ASRC_ASRCCR_ACIC      (8)      //!< Bit position for ASRC_ASRCCR_ACIC.
#define BM_ASRC_ASRCCR_ACIC      (0x00000f00)  //!< Bit mask for ASRC_ASRCCR_ACIC.

//! @brief Get value of ASRC_ASRCCR_ACIC from a register value.
#define BG_ASRC_ASRCCR_ACIC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCCR_ACIC) >> BP_ASRC_ASRCCR_ACIC)

//! @brief Format value for bitfield ASRC_ASRCCR_ACIC.
#define BF_ASRC_ASRCCR_ACIC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCCR_ACIC) & BM_ASRC_ASRCCR_ACIC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ACIC field to a new value.
#define BW_ASRC_ASRCCR_ACIC(v)   (HW_ASRC_ASRCCR_WR((HW_ASRC_ASRCCR_RD() & ~BM_ASRC_ASRCCR_ACIC) | BF_ASRC_ASRCCR_ACIC(v)))
#endif

/* --- Register HW_ASRC_ASRCCR, field ACOA[15:12] (RW)
 *
 * The channel counter for Pair A's output FIFO These bits stand for the current channel being
 * accessed through shared peripheral bus for Pair A's output FIFO's usage. The value can be any
 * value between [0, ANCA-1]
 */

#define BP_ASRC_ASRCCR_ACOA      (12)      //!< Bit position for ASRC_ASRCCR_ACOA.
#define BM_ASRC_ASRCCR_ACOA      (0x0000f000)  //!< Bit mask for ASRC_ASRCCR_ACOA.

//! @brief Get value of ASRC_ASRCCR_ACOA from a register value.
#define BG_ASRC_ASRCCR_ACOA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCCR_ACOA) >> BP_ASRC_ASRCCR_ACOA)

//! @brief Format value for bitfield ASRC_ASRCCR_ACOA.
#define BF_ASRC_ASRCCR_ACOA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCCR_ACOA) & BM_ASRC_ASRCCR_ACOA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ACOA field to a new value.
#define BW_ASRC_ASRCCR_ACOA(v)   (HW_ASRC_ASRCCR_WR((HW_ASRC_ASRCCR_RD() & ~BM_ASRC_ASRCCR_ACOA) | BF_ASRC_ASRCCR_ACOA(v)))
#endif

/* --- Register HW_ASRC_ASRCCR, field ACOB[19:16] (RW)
 *
 * The channel counter for Pair B's output FIFO These bits stand for the current channel being
 * accessed through shared peripheral bus for Pair B's output FIFO's usage. The value can be any
 * value between [0, ANCB-1]
 */

#define BP_ASRC_ASRCCR_ACOB      (16)      //!< Bit position for ASRC_ASRCCR_ACOB.
#define BM_ASRC_ASRCCR_ACOB      (0x000f0000)  //!< Bit mask for ASRC_ASRCCR_ACOB.

//! @brief Get value of ASRC_ASRCCR_ACOB from a register value.
#define BG_ASRC_ASRCCR_ACOB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCCR_ACOB) >> BP_ASRC_ASRCCR_ACOB)

//! @brief Format value for bitfield ASRC_ASRCCR_ACOB.
#define BF_ASRC_ASRCCR_ACOB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCCR_ACOB) & BM_ASRC_ASRCCR_ACOB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ACOB field to a new value.
#define BW_ASRC_ASRCCR_ACOB(v)   (HW_ASRC_ASRCCR_WR((HW_ASRC_ASRCCR_RD() & ~BM_ASRC_ASRCCR_ACOB) | BF_ASRC_ASRCCR_ACOB(v)))
#endif

/* --- Register HW_ASRC_ASRCCR, field ACOC[23:20] (RW)
 *
 * The channel counter for Pair C's output FIFO These bits stand for the current channel being
 * accessed through shared peripheral bus for Pair C's output FIFO's usage. The value can be any
 * value between [0, ANCC-1]
 */

#define BP_ASRC_ASRCCR_ACOC      (20)      //!< Bit position for ASRC_ASRCCR_ACOC.
#define BM_ASRC_ASRCCR_ACOC      (0x00f00000)  //!< Bit mask for ASRC_ASRCCR_ACOC.

//! @brief Get value of ASRC_ASRCCR_ACOC from a register value.
#define BG_ASRC_ASRCCR_ACOC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCCR_ACOC) >> BP_ASRC_ASRCCR_ACOC)

//! @brief Format value for bitfield ASRC_ASRCCR_ACOC.
#define BF_ASRC_ASRCCR_ACOC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRCCR_ACOC) & BM_ASRC_ASRCCR_ACOC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ACOC field to a new value.
#define BW_ASRC_ASRCCR_ACOC(v)   (HW_ASRC_ASRCCR_WR((HW_ASRC_ASRCCR_RD() & ~BM_ASRC_ASRCCR_ACOC) | BF_ASRC_ASRCCR_ACOC(v)))
#endif

/* --- Register HW_ASRC_ASRCCR, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRCCR_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRCCR_UNIMPLEMENTED.
#define BM_ASRC_ASRCCR_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRCCR_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRCCR_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRCCR_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRCCR_UNIMPLEMENTED) >> BP_ASRC_ASRCCR_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRDIA - ASRC Data Input Register for Pair
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRDIA - ASRC Data Input Register for Pair (WO)
 *
 * Reset value: 0x00000000
 *
 * These registers are the interface registers for the audio data input of pair A,B,C respectively.
 * They are backed by FIFOs.  The usage of these registers is shown in "xref to 56898: Heading5:
 * 1.2.3.2.1 Data Input Modes"
 */
typedef union _hw_asrc_asrdia
{
    reg32_t U;
    struct _hw_asrc_asrdia_bitfields
    {
        unsigned DATA : 24; //!< [23:0] Audio data input
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrdia_t;
#endif

/*
 * constants & macros for entire ASRC_ASRDIA register
 */
#define HW_ASRC_ASRDIA_ADDR      (REGS_ASRC_BASE + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRDIA           (*(volatile hw_asrc_asrdia_t *) HW_ASRC_ASRDIA_ADDR)
#define HW_ASRC_ASRDIA_WR(v)     (HW_ASRC_ASRDIA.U = (v))
#endif

/*
 * constants & macros for individual ASRC_ASRDIA bitfields
 */

/* --- Register HW_ASRC_ASRDIA, field DATA[23:0] (WO)
 *
 * Audio data input
 */

#define BP_ASRC_ASRDIA_DATA      (0)      //!< Bit position for ASRC_ASRDIA_DATA.
#define BM_ASRC_ASRDIA_DATA      (0x00ffffff)  //!< Bit mask for ASRC_ASRDIA_DATA.

//! @brief Get value of ASRC_ASRDIA_DATA from a register value.
#define BG_ASRC_ASRDIA_DATA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRDIA_DATA) >> BP_ASRC_ASRDIA_DATA)

//! @brief Format value for bitfield ASRC_ASRDIA_DATA.
#define BF_ASRC_ASRDIA_DATA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRDIA_DATA) & BM_ASRC_ASRDIA_DATA)

/* --- Register HW_ASRC_ASRDIA, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRDIA_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRDIA_UNIMPLEMENTED.
#define BM_ASRC_ASRDIA_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRDIA_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRDIA_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRDIA_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRDIA_UNIMPLEMENTED) >> BP_ASRC_ASRDIA_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRDOA - ASRC Data Output Register for Pair
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRDOA - ASRC Data Output Register for Pair (RO)
 *
 * Reset value: 0x00000000
 *
 * These registers are the interface registers for the audio data output of pair A,B,C respectively.
 * They are backed by FIFOs.  The usage of these registers is shown in xref to "Data Output modes."
 */
typedef union _hw_asrc_asrdoa
{
    reg32_t U;
    struct _hw_asrc_asrdoa_bitfields
    {
        unsigned DATA : 24; //!< [23:0] Audio data output
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrdoa_t;
#endif

/*
 * constants & macros for entire ASRC_ASRDOA register
 */
#define HW_ASRC_ASRDOA_ADDR      (REGS_ASRC_BASE + 0x64)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRDOA           (*(volatile hw_asrc_asrdoa_t *) HW_ASRC_ASRDOA_ADDR)
#define HW_ASRC_ASRDOA_RD()      (HW_ASRC_ASRDOA.U)
#endif

/*
 * constants & macros for individual ASRC_ASRDOA bitfields
 */

/* --- Register HW_ASRC_ASRDOA, field DATA[23:0] (RO)
 *
 * Audio data output
 */

#define BP_ASRC_ASRDOA_DATA      (0)      //!< Bit position for ASRC_ASRDOA_DATA.
#define BM_ASRC_ASRDOA_DATA      (0x00ffffff)  //!< Bit mask for ASRC_ASRDOA_DATA.

//! @brief Get value of ASRC_ASRDOA_DATA from a register value.
#define BG_ASRC_ASRDOA_DATA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRDOA_DATA) >> BP_ASRC_ASRDOA_DATA)

/* --- Register HW_ASRC_ASRDOA, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRDOA_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRDOA_UNIMPLEMENTED.
#define BM_ASRC_ASRDOA_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRDOA_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRDOA_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRDOA_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRDOA_UNIMPLEMENTED) >> BP_ASRC_ASRDOA_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRDIB - ASRC Data Input Register for Pair
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRDIB - ASRC Data Input Register for Pair (WO)
 *
 * Reset value: 0x00000000
 *
 * These registers are the interface registers for the audio data input of pair A,B,C respectively.
 * They are backed by FIFOs.  The usage of these registers is shown in "xref to 56898: Heading5:
 * 1.2.3.2.1 Data Input Modes"
 */
typedef union _hw_asrc_asrdib
{
    reg32_t U;
    struct _hw_asrc_asrdib_bitfields
    {
        unsigned DATA : 24; //!< [23:0] Audio data input
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrdib_t;
#endif

/*
 * constants & macros for entire ASRC_ASRDIB register
 */
#define HW_ASRC_ASRDIB_ADDR      (REGS_ASRC_BASE + 0x68)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRDIB           (*(volatile hw_asrc_asrdib_t *) HW_ASRC_ASRDIB_ADDR)
#define HW_ASRC_ASRDIB_WR(v)     (HW_ASRC_ASRDIB.U = (v))
#endif

/*
 * constants & macros for individual ASRC_ASRDIB bitfields
 */

/* --- Register HW_ASRC_ASRDIB, field DATA[23:0] (WO)
 *
 * Audio data input
 */

#define BP_ASRC_ASRDIB_DATA      (0)      //!< Bit position for ASRC_ASRDIB_DATA.
#define BM_ASRC_ASRDIB_DATA      (0x00ffffff)  //!< Bit mask for ASRC_ASRDIB_DATA.

//! @brief Get value of ASRC_ASRDIB_DATA from a register value.
#define BG_ASRC_ASRDIB_DATA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRDIB_DATA) >> BP_ASRC_ASRDIB_DATA)

//! @brief Format value for bitfield ASRC_ASRDIB_DATA.
#define BF_ASRC_ASRDIB_DATA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRDIB_DATA) & BM_ASRC_ASRDIB_DATA)

/* --- Register HW_ASRC_ASRDIB, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRDIB_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRDIB_UNIMPLEMENTED.
#define BM_ASRC_ASRDIB_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRDIB_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRDIB_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRDIB_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRDIB_UNIMPLEMENTED) >> BP_ASRC_ASRDIB_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRDOB - ASRC Data Output Register for Pair
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRDOB - ASRC Data Output Register for Pair (RO)
 *
 * Reset value: 0x00000000
 *
 * These registers are the interface registers for the audio data output of pair A,B,C respectively.
 * They are backed by FIFOs.  The usage of these registers is shown in xref to "Data Output modes."
 */
typedef union _hw_asrc_asrdob
{
    reg32_t U;
    struct _hw_asrc_asrdob_bitfields
    {
        unsigned DATA : 24; //!< [23:0] Audio data output
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrdob_t;
#endif

/*
 * constants & macros for entire ASRC_ASRDOB register
 */
#define HW_ASRC_ASRDOB_ADDR      (REGS_ASRC_BASE + 0x6c)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRDOB           (*(volatile hw_asrc_asrdob_t *) HW_ASRC_ASRDOB_ADDR)
#define HW_ASRC_ASRDOB_RD()      (HW_ASRC_ASRDOB.U)
#endif

/*
 * constants & macros for individual ASRC_ASRDOB bitfields
 */

/* --- Register HW_ASRC_ASRDOB, field DATA[23:0] (RO)
 *
 * Audio data output
 */

#define BP_ASRC_ASRDOB_DATA      (0)      //!< Bit position for ASRC_ASRDOB_DATA.
#define BM_ASRC_ASRDOB_DATA      (0x00ffffff)  //!< Bit mask for ASRC_ASRDOB_DATA.

//! @brief Get value of ASRC_ASRDOB_DATA from a register value.
#define BG_ASRC_ASRDOB_DATA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRDOB_DATA) >> BP_ASRC_ASRDOB_DATA)

/* --- Register HW_ASRC_ASRDOB, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRDOB_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRDOB_UNIMPLEMENTED.
#define BM_ASRC_ASRDOB_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRDOB_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRDOB_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRDOB_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRDOB_UNIMPLEMENTED) >> BP_ASRC_ASRDOB_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRDIC - ASRC Data Input Register for Pair
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRDIC - ASRC Data Input Register for Pair (WO)
 *
 * Reset value: 0x00000000
 *
 * These registers are the interface registers for the audio data input of pair A,B,C respectively.
 * They are backed by FIFOs.  The usage of these registers is shown in "xref to 56898: Heading5:
 * 1.2.3.2.1 Data Input Modes"
 */
typedef union _hw_asrc_asrdic
{
    reg32_t U;
    struct _hw_asrc_asrdic_bitfields
    {
        unsigned DATA : 24; //!< [23:0] Audio data input
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrdic_t;
#endif

/*
 * constants & macros for entire ASRC_ASRDIC register
 */
#define HW_ASRC_ASRDIC_ADDR      (REGS_ASRC_BASE + 0x70)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRDIC           (*(volatile hw_asrc_asrdic_t *) HW_ASRC_ASRDIC_ADDR)
#define HW_ASRC_ASRDIC_WR(v)     (HW_ASRC_ASRDIC.U = (v))
#endif

/*
 * constants & macros for individual ASRC_ASRDIC bitfields
 */

/* --- Register HW_ASRC_ASRDIC, field DATA[23:0] (WO)
 *
 * Audio data input
 */

#define BP_ASRC_ASRDIC_DATA      (0)      //!< Bit position for ASRC_ASRDIC_DATA.
#define BM_ASRC_ASRDIC_DATA      (0x00ffffff)  //!< Bit mask for ASRC_ASRDIC_DATA.

//! @brief Get value of ASRC_ASRDIC_DATA from a register value.
#define BG_ASRC_ASRDIC_DATA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRDIC_DATA) >> BP_ASRC_ASRDIC_DATA)

//! @brief Format value for bitfield ASRC_ASRDIC_DATA.
#define BF_ASRC_ASRDIC_DATA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRDIC_DATA) & BM_ASRC_ASRDIC_DATA)

/* --- Register HW_ASRC_ASRDIC, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRDIC_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRDIC_UNIMPLEMENTED.
#define BM_ASRC_ASRDIC_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRDIC_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRDIC_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRDIC_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRDIC_UNIMPLEMENTED) >> BP_ASRC_ASRDIC_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRDOC - ASRC Data Output Register for Pair
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRDOC - ASRC Data Output Register for Pair (RO)
 *
 * Reset value: 0x00000000
 *
 * These registers are the interface registers for the audio data output of pair A,B,C respectively.
 * They are backed by FIFOs.  The usage of these registers is shown in xref to "Data Output modes."
 */
typedef union _hw_asrc_asrdoc
{
    reg32_t U;
    struct _hw_asrc_asrdoc_bitfields
    {
        unsigned DATA : 24; //!< [23:0] Audio data output
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrdoc_t;
#endif

/*
 * constants & macros for entire ASRC_ASRDOC register
 */
#define HW_ASRC_ASRDOC_ADDR      (REGS_ASRC_BASE + 0x74)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRDOC           (*(volatile hw_asrc_asrdoc_t *) HW_ASRC_ASRDOC_ADDR)
#define HW_ASRC_ASRDOC_RD()      (HW_ASRC_ASRDOC.U)
#endif

/*
 * constants & macros for individual ASRC_ASRDOC bitfields
 */

/* --- Register HW_ASRC_ASRDOC, field DATA[23:0] (RO)
 *
 * Audio data output
 */

#define BP_ASRC_ASRDOC_DATA      (0)      //!< Bit position for ASRC_ASRDOC_DATA.
#define BM_ASRC_ASRDOC_DATA      (0x00ffffff)  //!< Bit mask for ASRC_ASRDOC_DATA.

//! @brief Get value of ASRC_ASRDOC_DATA from a register value.
#define BG_ASRC_ASRDOC_DATA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRDOC_DATA) >> BP_ASRC_ASRDOC_DATA)

/* --- Register HW_ASRC_ASRDOC, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRDOC_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRDOC_UNIMPLEMENTED.
#define BM_ASRC_ASRDOC_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRDOC_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRDOC_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRDOC_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRDOC_UNIMPLEMENTED) >> BP_ASRC_ASRDOC_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRIDRHA - ASRC Ideal Ratio for Pair A-High Part
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRIDRHA - ASRC Ideal Ratio for Pair A-High Part (RW)
 *
 * Reset value: 0x00000000
 *
 * The ideal ratio registers (ASRIDRHA, ASRIDRLA) hold the ratio value IDRATIOA. IDRATIOA = Fs inA
 * /Fs outA = Ts outA /Ts inA is a 32-bit fixed point value with 26 fractional bits. This value is
 * only useful when ASRCTR:{USRA, IDRA}=2'b11.
 */
typedef union _hw_asrc_asridrha
{
    reg32_t U;
    struct _hw_asrc_asridrha_bitfields
    {
        unsigned IDRATIOA : 8; //!< [7:0] IDRATIOA[31:24]. High part of ideal ratio value for pair A
        unsigned RESERVED0 : 16; //!< [23:8] Reserved
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asridrha_t;
#endif

/*
 * constants & macros for entire ASRC_ASRIDRHA register
 */
#define HW_ASRC_ASRIDRHA_ADDR      (REGS_ASRC_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRIDRHA           (*(volatile hw_asrc_asridrha_t *) HW_ASRC_ASRIDRHA_ADDR)
#define HW_ASRC_ASRIDRHA_RD()      (HW_ASRC_ASRIDRHA.U)
#define HW_ASRC_ASRIDRHA_WR(v)     (HW_ASRC_ASRIDRHA.U = (v))
#define HW_ASRC_ASRIDRHA_SET(v)    (HW_ASRC_ASRIDRHA_WR(HW_ASRC_ASRIDRHA_RD() |  (v)))
#define HW_ASRC_ASRIDRHA_CLR(v)    (HW_ASRC_ASRIDRHA_WR(HW_ASRC_ASRIDRHA_RD() & ~(v)))
#define HW_ASRC_ASRIDRHA_TOG(v)    (HW_ASRC_ASRIDRHA_WR(HW_ASRC_ASRIDRHA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRIDRHA bitfields
 */

/* --- Register HW_ASRC_ASRIDRHA, field IDRATIOA[7:0] (RW)
 *
 * IDRATIOA[31:24]. High part of ideal ratio value for pair A
 */

#define BP_ASRC_ASRIDRHA_IDRATIOA      (0)      //!< Bit position for ASRC_ASRIDRHA_IDRATIOA.
#define BM_ASRC_ASRIDRHA_IDRATIOA      (0x000000ff)  //!< Bit mask for ASRC_ASRIDRHA_IDRATIOA.

//! @brief Get value of ASRC_ASRIDRHA_IDRATIOA from a register value.
#define BG_ASRC_ASRIDRHA_IDRATIOA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIDRHA_IDRATIOA) >> BP_ASRC_ASRIDRHA_IDRATIOA)

//! @brief Format value for bitfield ASRC_ASRIDRHA_IDRATIOA.
#define BF_ASRC_ASRIDRHA_IDRATIOA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRIDRHA_IDRATIOA) & BM_ASRC_ASRIDRHA_IDRATIOA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IDRATIOA field to a new value.
#define BW_ASRC_ASRIDRHA_IDRATIOA(v)   (HW_ASRC_ASRIDRHA_WR((HW_ASRC_ASRIDRHA_RD() & ~BM_ASRC_ASRIDRHA_IDRATIOA) | BF_ASRC_ASRIDRHA_IDRATIOA(v)))
#endif

/* --- Register HW_ASRC_ASRIDRHA, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRIDRHA_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRIDRHA_UNIMPLEMENTED.
#define BM_ASRC_ASRIDRHA_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRIDRHA_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRIDRHA_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRIDRHA_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIDRHA_UNIMPLEMENTED) >> BP_ASRC_ASRIDRHA_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRIDRLA - ASRC Ideal Ratio for Pair A -Low Part
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRIDRLA - ASRC Ideal Ratio for Pair A -Low Part (RW)
 *
 * Reset value: 0x00000000
 *
 * The ideal ratio registers (ASRIDRHA, ASRIDRLA) hold the ratio value IDRATIOA. IDRATIOA = Fs inA
 * /Fs outA = Ts outA /Ts inA is a 32-bit fixed point value with 26 fractional bits. This value is
 * only useful when ASRCTR:{USRA, IDRA}=2'b11.
 */
typedef union _hw_asrc_asridrla
{
    reg32_t U;
    struct _hw_asrc_asridrla_bitfields
    {
        unsigned IDRATIOA : 24; //!< [23:0] IDRATIOA[23:0]. Low part of ideal ratio value for pair A
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asridrla_t;
#endif

/*
 * constants & macros for entire ASRC_ASRIDRLA register
 */
#define HW_ASRC_ASRIDRLA_ADDR      (REGS_ASRC_BASE + 0x84)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRIDRLA           (*(volatile hw_asrc_asridrla_t *) HW_ASRC_ASRIDRLA_ADDR)
#define HW_ASRC_ASRIDRLA_RD()      (HW_ASRC_ASRIDRLA.U)
#define HW_ASRC_ASRIDRLA_WR(v)     (HW_ASRC_ASRIDRLA.U = (v))
#define HW_ASRC_ASRIDRLA_SET(v)    (HW_ASRC_ASRIDRLA_WR(HW_ASRC_ASRIDRLA_RD() |  (v)))
#define HW_ASRC_ASRIDRLA_CLR(v)    (HW_ASRC_ASRIDRLA_WR(HW_ASRC_ASRIDRLA_RD() & ~(v)))
#define HW_ASRC_ASRIDRLA_TOG(v)    (HW_ASRC_ASRIDRLA_WR(HW_ASRC_ASRIDRLA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRIDRLA bitfields
 */

/* --- Register HW_ASRC_ASRIDRLA, field IDRATIOA[23:0] (RW)
 *
 * IDRATIOA[23:0]. Low part of ideal ratio value for pair A
 */

#define BP_ASRC_ASRIDRLA_IDRATIOA      (0)      //!< Bit position for ASRC_ASRIDRLA_IDRATIOA.
#define BM_ASRC_ASRIDRLA_IDRATIOA      (0x00ffffff)  //!< Bit mask for ASRC_ASRIDRLA_IDRATIOA.

//! @brief Get value of ASRC_ASRIDRLA_IDRATIOA from a register value.
#define BG_ASRC_ASRIDRLA_IDRATIOA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIDRLA_IDRATIOA) >> BP_ASRC_ASRIDRLA_IDRATIOA)

//! @brief Format value for bitfield ASRC_ASRIDRLA_IDRATIOA.
#define BF_ASRC_ASRIDRLA_IDRATIOA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRIDRLA_IDRATIOA) & BM_ASRC_ASRIDRLA_IDRATIOA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IDRATIOA field to a new value.
#define BW_ASRC_ASRIDRLA_IDRATIOA(v)   (HW_ASRC_ASRIDRLA_WR((HW_ASRC_ASRIDRLA_RD() & ~BM_ASRC_ASRIDRLA_IDRATIOA) | BF_ASRC_ASRIDRLA_IDRATIOA(v)))
#endif

/* --- Register HW_ASRC_ASRIDRLA, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRIDRLA_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRIDRLA_UNIMPLEMENTED.
#define BM_ASRC_ASRIDRLA_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRIDRLA_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRIDRLA_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRIDRLA_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIDRLA_UNIMPLEMENTED) >> BP_ASRC_ASRIDRLA_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRIDRHB - ASRC Ideal Ratio for Pair B-High Part
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRIDRHB - ASRC Ideal Ratio for Pair B-High Part (RW)
 *
 * Reset value: 0x00000000
 *
 * The ideal ratio registers (ASRIDRHB, ASRIDRLB) hold the ratio value IDRATIOB. IDRATIOB = Fs inB
 * /Fs outB = Ts outB /Ts inB is a 32-bit fixed point value with 26 fractional bits. This value is
 * only useful when ASRCTR:{USRB, IDRB}=2'b11.
 */
typedef union _hw_asrc_asridrhb
{
    reg32_t U;
    struct _hw_asrc_asridrhb_bitfields
    {
        unsigned IDRATIOB : 8; //!< [7:0] IDRATIOB[31:24]. High part of ideal ratio value for pair B.
        unsigned RESERVED0 : 16; //!< [23:8] Reserved
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asridrhb_t;
#endif

/*
 * constants & macros for entire ASRC_ASRIDRHB register
 */
#define HW_ASRC_ASRIDRHB_ADDR      (REGS_ASRC_BASE + 0x88)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRIDRHB           (*(volatile hw_asrc_asridrhb_t *) HW_ASRC_ASRIDRHB_ADDR)
#define HW_ASRC_ASRIDRHB_RD()      (HW_ASRC_ASRIDRHB.U)
#define HW_ASRC_ASRIDRHB_WR(v)     (HW_ASRC_ASRIDRHB.U = (v))
#define HW_ASRC_ASRIDRHB_SET(v)    (HW_ASRC_ASRIDRHB_WR(HW_ASRC_ASRIDRHB_RD() |  (v)))
#define HW_ASRC_ASRIDRHB_CLR(v)    (HW_ASRC_ASRIDRHB_WR(HW_ASRC_ASRIDRHB_RD() & ~(v)))
#define HW_ASRC_ASRIDRHB_TOG(v)    (HW_ASRC_ASRIDRHB_WR(HW_ASRC_ASRIDRHB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRIDRHB bitfields
 */

/* --- Register HW_ASRC_ASRIDRHB, field IDRATIOB[7:0] (RW)
 *
 * IDRATIOB[31:24]. High part of ideal ratio value for pair B.
 */

#define BP_ASRC_ASRIDRHB_IDRATIOB      (0)      //!< Bit position for ASRC_ASRIDRHB_IDRATIOB.
#define BM_ASRC_ASRIDRHB_IDRATIOB      (0x000000ff)  //!< Bit mask for ASRC_ASRIDRHB_IDRATIOB.

//! @brief Get value of ASRC_ASRIDRHB_IDRATIOB from a register value.
#define BG_ASRC_ASRIDRHB_IDRATIOB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIDRHB_IDRATIOB) >> BP_ASRC_ASRIDRHB_IDRATIOB)

//! @brief Format value for bitfield ASRC_ASRIDRHB_IDRATIOB.
#define BF_ASRC_ASRIDRHB_IDRATIOB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRIDRHB_IDRATIOB) & BM_ASRC_ASRIDRHB_IDRATIOB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IDRATIOB field to a new value.
#define BW_ASRC_ASRIDRHB_IDRATIOB(v)   (HW_ASRC_ASRIDRHB_WR((HW_ASRC_ASRIDRHB_RD() & ~BM_ASRC_ASRIDRHB_IDRATIOB) | BF_ASRC_ASRIDRHB_IDRATIOB(v)))
#endif

/* --- Register HW_ASRC_ASRIDRHB, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRIDRHB_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRIDRHB_UNIMPLEMENTED.
#define BM_ASRC_ASRIDRHB_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRIDRHB_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRIDRHB_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRIDRHB_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIDRHB_UNIMPLEMENTED) >> BP_ASRC_ASRIDRHB_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRIDRLB - ASRC Ideal Ratio for Pair B-Low Part
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRIDRLB - ASRC Ideal Ratio for Pair B-Low Part (RW)
 *
 * Reset value: 0x00000000
 *
 * The ideal ratio registers (ASRIDRHB, ASRIDRLB) hold the ratio value IDRATIOB. IDRATIOB = Fs inB
 * /Fs outB = Ts outB /Ts inB is a 32-bit fixed point value with 26 fractional bits. This value is
 * only useful when ASRCTR:{USRB, IDRB}=2'b11.
 */
typedef union _hw_asrc_asridrlb
{
    reg32_t U;
    struct _hw_asrc_asridrlb_bitfields
    {
        unsigned IDRATIOB : 24; //!< [23:0] IDRATIOB[23:0]. Low part of ideal ratio value for pair B.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asridrlb_t;
#endif

/*
 * constants & macros for entire ASRC_ASRIDRLB register
 */
#define HW_ASRC_ASRIDRLB_ADDR      (REGS_ASRC_BASE + 0x8c)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRIDRLB           (*(volatile hw_asrc_asridrlb_t *) HW_ASRC_ASRIDRLB_ADDR)
#define HW_ASRC_ASRIDRLB_RD()      (HW_ASRC_ASRIDRLB.U)
#define HW_ASRC_ASRIDRLB_WR(v)     (HW_ASRC_ASRIDRLB.U = (v))
#define HW_ASRC_ASRIDRLB_SET(v)    (HW_ASRC_ASRIDRLB_WR(HW_ASRC_ASRIDRLB_RD() |  (v)))
#define HW_ASRC_ASRIDRLB_CLR(v)    (HW_ASRC_ASRIDRLB_WR(HW_ASRC_ASRIDRLB_RD() & ~(v)))
#define HW_ASRC_ASRIDRLB_TOG(v)    (HW_ASRC_ASRIDRLB_WR(HW_ASRC_ASRIDRLB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRIDRLB bitfields
 */

/* --- Register HW_ASRC_ASRIDRLB, field IDRATIOB[23:0] (RW)
 *
 * IDRATIOB[23:0]. Low part of ideal ratio value for pair B.
 */

#define BP_ASRC_ASRIDRLB_IDRATIOB      (0)      //!< Bit position for ASRC_ASRIDRLB_IDRATIOB.
#define BM_ASRC_ASRIDRLB_IDRATIOB      (0x00ffffff)  //!< Bit mask for ASRC_ASRIDRLB_IDRATIOB.

//! @brief Get value of ASRC_ASRIDRLB_IDRATIOB from a register value.
#define BG_ASRC_ASRIDRLB_IDRATIOB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIDRLB_IDRATIOB) >> BP_ASRC_ASRIDRLB_IDRATIOB)

//! @brief Format value for bitfield ASRC_ASRIDRLB_IDRATIOB.
#define BF_ASRC_ASRIDRLB_IDRATIOB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRIDRLB_IDRATIOB) & BM_ASRC_ASRIDRLB_IDRATIOB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IDRATIOB field to a new value.
#define BW_ASRC_ASRIDRLB_IDRATIOB(v)   (HW_ASRC_ASRIDRLB_WR((HW_ASRC_ASRIDRLB_RD() & ~BM_ASRC_ASRIDRLB_IDRATIOB) | BF_ASRC_ASRIDRLB_IDRATIOB(v)))
#endif

/* --- Register HW_ASRC_ASRIDRLB, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRIDRLB_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRIDRLB_UNIMPLEMENTED.
#define BM_ASRC_ASRIDRLB_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRIDRLB_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRIDRLB_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRIDRLB_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIDRLB_UNIMPLEMENTED) >> BP_ASRC_ASRIDRLB_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRIDRHC - ASRC Ideal Ratio for Pair C-High Part
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRIDRHC - ASRC Ideal Ratio for Pair C-High Part (RW)
 *
 * Reset value: 0x00000000
 *
 * The ideal ratio registers (ASRIDRHC, ASRIDRLC) hold the ratio value IDRATIOC. IDRATIOC = Fs inC
 * /Fs outC = Ts outC /Ts inC is a 32-bit fixed point value with 26 fractional bits. This value is
 * only useful when ASRCTR:{USRC, IDRC}=2'b11.
 */
typedef union _hw_asrc_asridrhc
{
    reg32_t U;
    struct _hw_asrc_asridrhc_bitfields
    {
        unsigned IDRATIOC : 8; //!< [7:0] IDRATIOC[31:24]. High part of ideal ratio value for pair C.
        unsigned RESERVED0 : 16; //!< [23:8] Reserved
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asridrhc_t;
#endif

/*
 * constants & macros for entire ASRC_ASRIDRHC register
 */
#define HW_ASRC_ASRIDRHC_ADDR      (REGS_ASRC_BASE + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRIDRHC           (*(volatile hw_asrc_asridrhc_t *) HW_ASRC_ASRIDRHC_ADDR)
#define HW_ASRC_ASRIDRHC_RD()      (HW_ASRC_ASRIDRHC.U)
#define HW_ASRC_ASRIDRHC_WR(v)     (HW_ASRC_ASRIDRHC.U = (v))
#define HW_ASRC_ASRIDRHC_SET(v)    (HW_ASRC_ASRIDRHC_WR(HW_ASRC_ASRIDRHC_RD() |  (v)))
#define HW_ASRC_ASRIDRHC_CLR(v)    (HW_ASRC_ASRIDRHC_WR(HW_ASRC_ASRIDRHC_RD() & ~(v)))
#define HW_ASRC_ASRIDRHC_TOG(v)    (HW_ASRC_ASRIDRHC_WR(HW_ASRC_ASRIDRHC_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRIDRHC bitfields
 */

/* --- Register HW_ASRC_ASRIDRHC, field IDRATIOC[7:0] (RW)
 *
 * IDRATIOC[31:24]. High part of ideal ratio value for pair C.
 */

#define BP_ASRC_ASRIDRHC_IDRATIOC      (0)      //!< Bit position for ASRC_ASRIDRHC_IDRATIOC.
#define BM_ASRC_ASRIDRHC_IDRATIOC      (0x000000ff)  //!< Bit mask for ASRC_ASRIDRHC_IDRATIOC.

//! @brief Get value of ASRC_ASRIDRHC_IDRATIOC from a register value.
#define BG_ASRC_ASRIDRHC_IDRATIOC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIDRHC_IDRATIOC) >> BP_ASRC_ASRIDRHC_IDRATIOC)

//! @brief Format value for bitfield ASRC_ASRIDRHC_IDRATIOC.
#define BF_ASRC_ASRIDRHC_IDRATIOC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRIDRHC_IDRATIOC) & BM_ASRC_ASRIDRHC_IDRATIOC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IDRATIOC field to a new value.
#define BW_ASRC_ASRIDRHC_IDRATIOC(v)   (HW_ASRC_ASRIDRHC_WR((HW_ASRC_ASRIDRHC_RD() & ~BM_ASRC_ASRIDRHC_IDRATIOC) | BF_ASRC_ASRIDRHC_IDRATIOC(v)))
#endif

/* --- Register HW_ASRC_ASRIDRHC, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRIDRHC_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRIDRHC_UNIMPLEMENTED.
#define BM_ASRC_ASRIDRHC_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRIDRHC_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRIDRHC_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRIDRHC_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIDRHC_UNIMPLEMENTED) >> BP_ASRC_ASRIDRHC_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRIDRLC - ASRC Ideal Ratio for Pair C-Low Part
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRIDRLC - ASRC Ideal Ratio for Pair C-Low Part (RW)
 *
 * Reset value: 0x00000000
 *
 * The ideal ratio registers (ASRIDRHC, ASRIDRLC) hold the ratio value IDRATIOC. IDRATIOC = Fs inC
 * /Fs outC = Ts outC /Ts inC is a 32-bit fixed point value with 26 fractional bits. This value is
 * only useful when ASRCTR:{USRC, IDRC}=2'b11.
 */
typedef union _hw_asrc_asridrlc
{
    reg32_t U;
    struct _hw_asrc_asridrlc_bitfields
    {
        unsigned IDRATIOC : 24; //!< [23:0] IDRATIOC[23:0]. Low part of ideal ratio value for pair C.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asridrlc_t;
#endif

/*
 * constants & macros for entire ASRC_ASRIDRLC register
 */
#define HW_ASRC_ASRIDRLC_ADDR      (REGS_ASRC_BASE + 0x94)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRIDRLC           (*(volatile hw_asrc_asridrlc_t *) HW_ASRC_ASRIDRLC_ADDR)
#define HW_ASRC_ASRIDRLC_RD()      (HW_ASRC_ASRIDRLC.U)
#define HW_ASRC_ASRIDRLC_WR(v)     (HW_ASRC_ASRIDRLC.U = (v))
#define HW_ASRC_ASRIDRLC_SET(v)    (HW_ASRC_ASRIDRLC_WR(HW_ASRC_ASRIDRLC_RD() |  (v)))
#define HW_ASRC_ASRIDRLC_CLR(v)    (HW_ASRC_ASRIDRLC_WR(HW_ASRC_ASRIDRLC_RD() & ~(v)))
#define HW_ASRC_ASRIDRLC_TOG(v)    (HW_ASRC_ASRIDRLC_WR(HW_ASRC_ASRIDRLC_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRIDRLC bitfields
 */

/* --- Register HW_ASRC_ASRIDRLC, field IDRATIOC[23:0] (RW)
 *
 * IDRATIOC[23:0]. Low part of ideal ratio value for pair C.
 */

#define BP_ASRC_ASRIDRLC_IDRATIOC      (0)      //!< Bit position for ASRC_ASRIDRLC_IDRATIOC.
#define BM_ASRC_ASRIDRLC_IDRATIOC      (0x00ffffff)  //!< Bit mask for ASRC_ASRIDRLC_IDRATIOC.

//! @brief Get value of ASRC_ASRIDRLC_IDRATIOC from a register value.
#define BG_ASRC_ASRIDRLC_IDRATIOC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIDRLC_IDRATIOC) >> BP_ASRC_ASRIDRLC_IDRATIOC)

//! @brief Format value for bitfield ASRC_ASRIDRLC_IDRATIOC.
#define BF_ASRC_ASRIDRLC_IDRATIOC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRIDRLC_IDRATIOC) & BM_ASRC_ASRIDRLC_IDRATIOC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IDRATIOC field to a new value.
#define BW_ASRC_ASRIDRLC_IDRATIOC(v)   (HW_ASRC_ASRIDRLC_WR((HW_ASRC_ASRIDRLC_RD() & ~BM_ASRC_ASRIDRLC_IDRATIOC) | BF_ASRC_ASRIDRLC_IDRATIOC(v)))
#endif

/* --- Register HW_ASRC_ASRIDRLC, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRIDRLC_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRIDRLC_UNIMPLEMENTED.
#define BM_ASRC_ASRIDRLC_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRIDRLC_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRIDRLC_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRIDRLC_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRIDRLC_UNIMPLEMENTED) >> BP_ASRC_ASRIDRLC_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASR76K - ASRC 76kHz Period in terms of ASRC processing clock
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASR76K - ASRC 76kHz Period in terms of ASRC processing clock (RW)
 *
 * Reset value: 0x00000a47
 *
 * The register (ASR76K) holds the period of the 76kHz sampling clock in terms of the ASRC
 * processing clock with frequency Fs ASRC . ASR76K = Fs ASRC /Fs 76k . Reset value is 0x0A47 which
 * assumes that Fs ASRC =200MHz. This register is used to help the ASRC internal logic to decide the
 * pre-processing and the post-processing options automatically (see ASRC Misc Control Register 1
 * for Pair C and ASRC Misc Control Register 1 for Pair C ). In a system when Fs ASRC =133MHz, the
 * value should be assigned explicitly as 0x06D6 in user application code.
 */
typedef union _hw_asrc_asr76k
{
    reg32_t U;
    struct _hw_asrc_asr76k_bitfields
    {
        unsigned ASR76K : 17; //!< [16:0] Value for the period of the 76kHz sampling clock.
        unsigned RESERVED0 : 7; //!< [23:17] Reserved
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asr76k_t;
#endif

/*
 * constants & macros for entire ASRC_ASR76K register
 */
#define HW_ASRC_ASR76K_ADDR      (REGS_ASRC_BASE + 0x98)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASR76K           (*(volatile hw_asrc_asr76k_t *) HW_ASRC_ASR76K_ADDR)
#define HW_ASRC_ASR76K_RD()      (HW_ASRC_ASR76K.U)
#define HW_ASRC_ASR76K_WR(v)     (HW_ASRC_ASR76K.U = (v))
#define HW_ASRC_ASR76K_SET(v)    (HW_ASRC_ASR76K_WR(HW_ASRC_ASR76K_RD() |  (v)))
#define HW_ASRC_ASR76K_CLR(v)    (HW_ASRC_ASR76K_WR(HW_ASRC_ASR76K_RD() & ~(v)))
#define HW_ASRC_ASR76K_TOG(v)    (HW_ASRC_ASR76K_WR(HW_ASRC_ASR76K_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASR76K bitfields
 */

/* --- Register HW_ASRC_ASR76K, field ASR76K[16:0] (RW)
 *
 * Value for the period of the 76kHz sampling clock.
 */

#define BP_ASRC_ASR76K_ASR76K      (0)      //!< Bit position for ASRC_ASR76K_ASR76K.
#define BM_ASRC_ASR76K_ASR76K      (0x0001ffff)  //!< Bit mask for ASRC_ASR76K_ASR76K.

//! @brief Get value of ASRC_ASR76K_ASR76K from a register value.
#define BG_ASRC_ASR76K_ASR76K(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASR76K_ASR76K) >> BP_ASRC_ASR76K_ASR76K)

//! @brief Format value for bitfield ASRC_ASR76K_ASR76K.
#define BF_ASRC_ASR76K_ASR76K(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASR76K_ASR76K) & BM_ASRC_ASR76K_ASR76K)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ASR76K field to a new value.
#define BW_ASRC_ASR76K_ASR76K(v)   (HW_ASRC_ASR76K_WR((HW_ASRC_ASR76K_RD() & ~BM_ASRC_ASR76K_ASR76K) | BF_ASRC_ASR76K_ASR76K(v)))
#endif

/* --- Register HW_ASRC_ASR76K, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASR76K_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASR76K_UNIMPLEMENTED.
#define BM_ASRC_ASR76K_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASR76K_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASR76K_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASR76K_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASR76K_UNIMPLEMENTED) >> BP_ASRC_ASR76K_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASR56K - ASRC 56kHz Period in terms of ASRC processing clock
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASR56K - ASRC 56kHz Period in terms of ASRC processing clock (RW)
 *
 * Reset value: 0x00000df3
 *
 * The register (ASR56K) holds the period of the 56kHz sampling clock in terms of the ASRC
 * processing clock with frequency Fs ASRC . ASR56K = Fs ASRC /Fs 56k . Reset value is 0x0DF3 which
 * assumes that Fs ASRC =200MHz. This register is used to help the ASRC internal logic to decide the
 * pre-processing and the post-processing options automatically (see ASRC Misc Control Register 1
 * for Pair C and ASRC Misc Control Register 1 for Pair C ). In a system when Fs ASRC =133MHz, the
 * value should be assigned explicitly as 0x0947 in user application code.
 */
typedef union _hw_asrc_asr56k
{
    reg32_t U;
    struct _hw_asrc_asr56k_bitfields
    {
        unsigned ASR56K : 17; //!< [16:0] Value for the period of the 56kHz sampling clock
        unsigned RESERVED0 : 7; //!< [23:17] Reserved
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asr56k_t;
#endif

/*
 * constants & macros for entire ASRC_ASR56K register
 */
#define HW_ASRC_ASR56K_ADDR      (REGS_ASRC_BASE + 0x9c)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASR56K           (*(volatile hw_asrc_asr56k_t *) HW_ASRC_ASR56K_ADDR)
#define HW_ASRC_ASR56K_RD()      (HW_ASRC_ASR56K.U)
#define HW_ASRC_ASR56K_WR(v)     (HW_ASRC_ASR56K.U = (v))
#define HW_ASRC_ASR56K_SET(v)    (HW_ASRC_ASR56K_WR(HW_ASRC_ASR56K_RD() |  (v)))
#define HW_ASRC_ASR56K_CLR(v)    (HW_ASRC_ASR56K_WR(HW_ASRC_ASR56K_RD() & ~(v)))
#define HW_ASRC_ASR56K_TOG(v)    (HW_ASRC_ASR56K_WR(HW_ASRC_ASR56K_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASR56K bitfields
 */

/* --- Register HW_ASRC_ASR56K, field ASR56K[16:0] (RW)
 *
 * Value for the period of the 56kHz sampling clock
 */

#define BP_ASRC_ASR56K_ASR56K      (0)      //!< Bit position for ASRC_ASR56K_ASR56K.
#define BM_ASRC_ASR56K_ASR56K      (0x0001ffff)  //!< Bit mask for ASRC_ASR56K_ASR56K.

//! @brief Get value of ASRC_ASR56K_ASR56K from a register value.
#define BG_ASRC_ASR56K_ASR56K(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASR56K_ASR56K) >> BP_ASRC_ASR56K_ASR56K)

//! @brief Format value for bitfield ASRC_ASR56K_ASR56K.
#define BF_ASRC_ASR56K_ASR56K(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASR56K_ASR56K) & BM_ASRC_ASR56K_ASR56K)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ASR56K field to a new value.
#define BW_ASRC_ASR56K_ASR56K(v)   (HW_ASRC_ASR56K_WR((HW_ASRC_ASR56K_RD() & ~BM_ASRC_ASR56K_ASR56K) | BF_ASRC_ASR56K_ASR56K(v)))
#endif

/* --- Register HW_ASRC_ASR56K, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASR56K_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASR56K_UNIMPLEMENTED.
#define BM_ASRC_ASR56K_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASR56K_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASR56K_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASR56K_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASR56K_UNIMPLEMENTED) >> BP_ASRC_ASR56K_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRMCRA - ASRC Misc Control Register for Pair A
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRMCRA - ASRC Misc Control Register for Pair A (RW)
 *
 * Reset value: 0x00000000
 *
 * The register (ASRMCRA) is used to control Pair A internal logic.
 */
typedef union _hw_asrc_asrmcra
{
    reg32_t U;
    struct _hw_asrc_asrmcra_bitfields
    {
        unsigned INFIFO_THRESHOLDA : 6; //!< [5:0] The threshold for Pair A's input FIFO per channel These bits stand for the threshold for Pair A's input FIFO per channel. Possible range is [0,63]. When the value is n, it means that: when the number of input FIFO fillings of the pair is less than n samples per channel, the input data needed flag is set; when the number of input FIFO fillings of the pair is greater than or equal to n samples per channel, the input data needed flag is automatically cleared.
        unsigned RESERVED0 : 4; //!< [9:6] Reserved. Should be written as zero for future compatibility.
        unsigned RSYNOFA : 1; //!< [10] Re-sync Output FIFO Channel Counter If bit set, force ASRCCR:ACOA=0. If bit clear, untouch ASRCCR:ACOA.
        unsigned RSYNIFA : 1; //!< [11] Re-sync Input FIFO Channel Counter If bit set, force ASRCCR:ACIA=0. If bit clear, untouch ASRCCR:ACIA.
        unsigned OUTFIFO_THRESHOLDA : 6; //!< [17:12] The threshold for Pair A's output FIFO per channel These bits stand for the threshold for Pair A's output FIFO per channel. Possible range is [0,63]. When the value is n, it means that: when the number of output FIFO fillings of the pair is greater than n samples per channel, the output data ready flag is set; when the number of output FIFO fillings of the pair is less than or equal to n samples per channel, the output data ready flag is automatically cleared.
        unsigned RESERVED1 : 2; //!< [19:18] Reserved. Should be written as zero for future compatibility.
        unsigned BYPASSPOLYA : 1; //!< [20] Bypass Polyphase Filtering for Pair A This bit will determine whether the polyphase filtering part of Pair A conversion will be bypassed.
        unsigned BUFSTALLA : 1; //!< [21] Stall Pair A conversion in case of Buffer Near Empty/Full Condition This bit will determine whether the near empty/full FIFO condition will stall the rate conversion for pair A. This option can only work when external ratio is used. Near empty condition is the condition when input FIFO has less than 4 useful samples per channel. Near full condition is the condition when the output FIFO has less than 4 vacant sample words to fill per channel.
        unsigned EXTTHRSHA : 1; //!< [22] Use external thresholds for FIFO control of Pair A This bit will determine whether the FIFO thresholds externally defined in this register is used to control ASRC internal FIFO logic for pair A.
        unsigned ZEROBUFA : 1; //!< [23] Initialize buf of Pair A when pair A is enabled. Always clear option. This bit is used to control whether the buffer is to be zeroized when pair A is enabled.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrmcra_t;
#endif

/*
 * constants & macros for entire ASRC_ASRMCRA register
 */
#define HW_ASRC_ASRMCRA_ADDR      (REGS_ASRC_BASE + 0xa0)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRMCRA           (*(volatile hw_asrc_asrmcra_t *) HW_ASRC_ASRMCRA_ADDR)
#define HW_ASRC_ASRMCRA_RD()      (HW_ASRC_ASRMCRA.U)
#define HW_ASRC_ASRMCRA_WR(v)     (HW_ASRC_ASRMCRA.U = (v))
#define HW_ASRC_ASRMCRA_SET(v)    (HW_ASRC_ASRMCRA_WR(HW_ASRC_ASRMCRA_RD() |  (v)))
#define HW_ASRC_ASRMCRA_CLR(v)    (HW_ASRC_ASRMCRA_WR(HW_ASRC_ASRMCRA_RD() & ~(v)))
#define HW_ASRC_ASRMCRA_TOG(v)    (HW_ASRC_ASRMCRA_WR(HW_ASRC_ASRMCRA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRMCRA bitfields
 */

/* --- Register HW_ASRC_ASRMCRA, field INFIFO_THRESHOLDA[5:0] (RW)
 *
 * The threshold for Pair A's input FIFO per channel These bits stand for the threshold for Pair A's
 * input FIFO per channel. Possible range is [0,63]. When the value is n, it means that: when the
 * number of input FIFO fillings of the pair is less than n samples per channel, the input data
 * needed flag is set; when the number of input FIFO fillings of the pair is greater than or equal
 * to n samples per channel, the input data needed flag is automatically cleared.
 */

#define BP_ASRC_ASRMCRA_INFIFO_THRESHOLDA      (0)      //!< Bit position for ASRC_ASRMCRA_INFIFO_THRESHOLDA.
#define BM_ASRC_ASRMCRA_INFIFO_THRESHOLDA      (0x0000003f)  //!< Bit mask for ASRC_ASRMCRA_INFIFO_THRESHOLDA.

//! @brief Get value of ASRC_ASRMCRA_INFIFO_THRESHOLDA from a register value.
#define BG_ASRC_ASRMCRA_INFIFO_THRESHOLDA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRA_INFIFO_THRESHOLDA) >> BP_ASRC_ASRMCRA_INFIFO_THRESHOLDA)

//! @brief Format value for bitfield ASRC_ASRMCRA_INFIFO_THRESHOLDA.
#define BF_ASRC_ASRMCRA_INFIFO_THRESHOLDA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRA_INFIFO_THRESHOLDA) & BM_ASRC_ASRMCRA_INFIFO_THRESHOLDA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INFIFO_THRESHOLDA field to a new value.
#define BW_ASRC_ASRMCRA_INFIFO_THRESHOLDA(v)   (HW_ASRC_ASRMCRA_WR((HW_ASRC_ASRMCRA_RD() & ~BM_ASRC_ASRMCRA_INFIFO_THRESHOLDA) | BF_ASRC_ASRMCRA_INFIFO_THRESHOLDA(v)))
#endif

/* --- Register HW_ASRC_ASRMCRA, field RSYNOFA[10] (RW)
 *
 * Re-sync Output FIFO Channel Counter If bit set, force ASRCCR:ACOA=0. If bit clear, untouch
 * ASRCCR:ACOA.
 */

#define BP_ASRC_ASRMCRA_RSYNOFA      (10)      //!< Bit position for ASRC_ASRMCRA_RSYNOFA.
#define BM_ASRC_ASRMCRA_RSYNOFA      (0x00000400)  //!< Bit mask for ASRC_ASRMCRA_RSYNOFA.

//! @brief Get value of ASRC_ASRMCRA_RSYNOFA from a register value.
#define BG_ASRC_ASRMCRA_RSYNOFA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRA_RSYNOFA) >> BP_ASRC_ASRMCRA_RSYNOFA)

//! @brief Format value for bitfield ASRC_ASRMCRA_RSYNOFA.
#define BF_ASRC_ASRMCRA_RSYNOFA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRA_RSYNOFA) & BM_ASRC_ASRMCRA_RSYNOFA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RSYNOFA field to a new value.
#define BW_ASRC_ASRMCRA_RSYNOFA(v)   (HW_ASRC_ASRMCRA_WR((HW_ASRC_ASRMCRA_RD() & ~BM_ASRC_ASRMCRA_RSYNOFA) | BF_ASRC_ASRMCRA_RSYNOFA(v)))
#endif

/* --- Register HW_ASRC_ASRMCRA, field RSYNIFA[11] (RW)
 *
 * Re-sync Input FIFO Channel Counter If bit set, force ASRCCR:ACIA=0. If bit clear, untouch
 * ASRCCR:ACIA.
 */

#define BP_ASRC_ASRMCRA_RSYNIFA      (11)      //!< Bit position for ASRC_ASRMCRA_RSYNIFA.
#define BM_ASRC_ASRMCRA_RSYNIFA      (0x00000800)  //!< Bit mask for ASRC_ASRMCRA_RSYNIFA.

//! @brief Get value of ASRC_ASRMCRA_RSYNIFA from a register value.
#define BG_ASRC_ASRMCRA_RSYNIFA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRA_RSYNIFA) >> BP_ASRC_ASRMCRA_RSYNIFA)

//! @brief Format value for bitfield ASRC_ASRMCRA_RSYNIFA.
#define BF_ASRC_ASRMCRA_RSYNIFA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRA_RSYNIFA) & BM_ASRC_ASRMCRA_RSYNIFA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RSYNIFA field to a new value.
#define BW_ASRC_ASRMCRA_RSYNIFA(v)   (HW_ASRC_ASRMCRA_WR((HW_ASRC_ASRMCRA_RD() & ~BM_ASRC_ASRMCRA_RSYNIFA) | BF_ASRC_ASRMCRA_RSYNIFA(v)))
#endif

/* --- Register HW_ASRC_ASRMCRA, field OUTFIFO_THRESHOLDA[17:12] (RW)
 *
 * The threshold for Pair A's output FIFO per channel These bits stand for the threshold for Pair
 * A's output FIFO per channel. Possible range is [0,63]. When the value is n, it means that: when
 * the number of output FIFO fillings of the pair is greater than n samples per channel, the output
 * data ready flag is set; when the number of output FIFO fillings of the pair is less than or equal
 * to n samples per channel, the output data ready flag is automatically cleared.
 */

#define BP_ASRC_ASRMCRA_OUTFIFO_THRESHOLDA      (12)      //!< Bit position for ASRC_ASRMCRA_OUTFIFO_THRESHOLDA.
#define BM_ASRC_ASRMCRA_OUTFIFO_THRESHOLDA      (0x0003f000)  //!< Bit mask for ASRC_ASRMCRA_OUTFIFO_THRESHOLDA.

//! @brief Get value of ASRC_ASRMCRA_OUTFIFO_THRESHOLDA from a register value.
#define BG_ASRC_ASRMCRA_OUTFIFO_THRESHOLDA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRA_OUTFIFO_THRESHOLDA) >> BP_ASRC_ASRMCRA_OUTFIFO_THRESHOLDA)

//! @brief Format value for bitfield ASRC_ASRMCRA_OUTFIFO_THRESHOLDA.
#define BF_ASRC_ASRMCRA_OUTFIFO_THRESHOLDA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRA_OUTFIFO_THRESHOLDA) & BM_ASRC_ASRMCRA_OUTFIFO_THRESHOLDA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OUTFIFO_THRESHOLDA field to a new value.
#define BW_ASRC_ASRMCRA_OUTFIFO_THRESHOLDA(v)   (HW_ASRC_ASRMCRA_WR((HW_ASRC_ASRMCRA_RD() & ~BM_ASRC_ASRMCRA_OUTFIFO_THRESHOLDA) | BF_ASRC_ASRMCRA_OUTFIFO_THRESHOLDA(v)))
#endif

/* --- Register HW_ASRC_ASRMCRA, field BYPASSPOLYA[20] (RW)
 *
 * Bypass Polyphase Filtering for Pair A This bit will determine whether the polyphase filtering
 * part of Pair A conversion will be bypassed.
 *
 * Values:
 * 0 - Don't bypass polyphase filtering.
 * 1 - Bypass polyphase filtering.
 */

#define BP_ASRC_ASRMCRA_BYPASSPOLYA      (20)      //!< Bit position for ASRC_ASRMCRA_BYPASSPOLYA.
#define BM_ASRC_ASRMCRA_BYPASSPOLYA      (0x00100000)  //!< Bit mask for ASRC_ASRMCRA_BYPASSPOLYA.

//! @brief Get value of ASRC_ASRMCRA_BYPASSPOLYA from a register value.
#define BG_ASRC_ASRMCRA_BYPASSPOLYA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRA_BYPASSPOLYA) >> BP_ASRC_ASRMCRA_BYPASSPOLYA)

//! @brief Format value for bitfield ASRC_ASRMCRA_BYPASSPOLYA.
#define BF_ASRC_ASRMCRA_BYPASSPOLYA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRA_BYPASSPOLYA) & BM_ASRC_ASRMCRA_BYPASSPOLYA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASSPOLYA field to a new value.
#define BW_ASRC_ASRMCRA_BYPASSPOLYA(v)   (HW_ASRC_ASRMCRA_WR((HW_ASRC_ASRMCRA_RD() & ~BM_ASRC_ASRMCRA_BYPASSPOLYA) | BF_ASRC_ASRMCRA_BYPASSPOLYA(v)))
#endif


/* --- Register HW_ASRC_ASRMCRA, field BUFSTALLA[21] (RW)
 *
 * Stall Pair A conversion in case of Buffer Near Empty/Full Condition This bit will determine
 * whether the near empty/full FIFO condition will stall the rate conversion for pair A. This option
 * can only work when external ratio is used. Near empty condition is the condition when input FIFO
 * has less than 4 useful samples per channel. Near full condition is the condition when the output
 * FIFO has less than 4 vacant sample words to fill per channel.
 *
 * Values:
 * 0 - Don't stall Pair A conversion even in case of near empty/full FIFO conditions.
 * 1 - Stall Pair A conversion in case of near empty/full FIFO conditions.
 */

#define BP_ASRC_ASRMCRA_BUFSTALLA      (21)      //!< Bit position for ASRC_ASRMCRA_BUFSTALLA.
#define BM_ASRC_ASRMCRA_BUFSTALLA      (0x00200000)  //!< Bit mask for ASRC_ASRMCRA_BUFSTALLA.

//! @brief Get value of ASRC_ASRMCRA_BUFSTALLA from a register value.
#define BG_ASRC_ASRMCRA_BUFSTALLA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRA_BUFSTALLA) >> BP_ASRC_ASRMCRA_BUFSTALLA)

//! @brief Format value for bitfield ASRC_ASRMCRA_BUFSTALLA.
#define BF_ASRC_ASRMCRA_BUFSTALLA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRA_BUFSTALLA) & BM_ASRC_ASRMCRA_BUFSTALLA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BUFSTALLA field to a new value.
#define BW_ASRC_ASRMCRA_BUFSTALLA(v)   (HW_ASRC_ASRMCRA_WR((HW_ASRC_ASRMCRA_RD() & ~BM_ASRC_ASRMCRA_BUFSTALLA) | BF_ASRC_ASRMCRA_BUFSTALLA(v)))
#endif


/* --- Register HW_ASRC_ASRMCRA, field EXTTHRSHA[22] (RW)
 *
 * Use external thresholds for FIFO control of Pair A This bit will determine whether the FIFO
 * thresholds externally defined in this register is used to control ASRC internal FIFO logic for
 * pair A.
 *
 * Values:
 * 0 - Use default thresholds.
 * 1 - Use external defined thresholds.
 */

#define BP_ASRC_ASRMCRA_EXTTHRSHA      (22)      //!< Bit position for ASRC_ASRMCRA_EXTTHRSHA.
#define BM_ASRC_ASRMCRA_EXTTHRSHA      (0x00400000)  //!< Bit mask for ASRC_ASRMCRA_EXTTHRSHA.

//! @brief Get value of ASRC_ASRMCRA_EXTTHRSHA from a register value.
#define BG_ASRC_ASRMCRA_EXTTHRSHA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRA_EXTTHRSHA) >> BP_ASRC_ASRMCRA_EXTTHRSHA)

//! @brief Format value for bitfield ASRC_ASRMCRA_EXTTHRSHA.
#define BF_ASRC_ASRMCRA_EXTTHRSHA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRA_EXTTHRSHA) & BM_ASRC_ASRMCRA_EXTTHRSHA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EXTTHRSHA field to a new value.
#define BW_ASRC_ASRMCRA_EXTTHRSHA(v)   (HW_ASRC_ASRMCRA_WR((HW_ASRC_ASRMCRA_RD() & ~BM_ASRC_ASRMCRA_EXTTHRSHA) | BF_ASRC_ASRMCRA_EXTTHRSHA(v)))
#endif


/* --- Register HW_ASRC_ASRMCRA, field ZEROBUFA[23] (RW)
 *
 * Initialize buf of Pair A when pair A is enabled. Always clear option. This bit is used to control
 * whether the buffer is to be zeroized when pair A is enabled.
 *
 * Values:
 * 0 - Zeroize the buffer
 * 1 - Don't zeroize the buffer
 */

#define BP_ASRC_ASRMCRA_ZEROBUFA      (23)      //!< Bit position for ASRC_ASRMCRA_ZEROBUFA.
#define BM_ASRC_ASRMCRA_ZEROBUFA      (0x00800000)  //!< Bit mask for ASRC_ASRMCRA_ZEROBUFA.

//! @brief Get value of ASRC_ASRMCRA_ZEROBUFA from a register value.
#define BG_ASRC_ASRMCRA_ZEROBUFA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRA_ZEROBUFA) >> BP_ASRC_ASRMCRA_ZEROBUFA)

//! @brief Format value for bitfield ASRC_ASRMCRA_ZEROBUFA.
#define BF_ASRC_ASRMCRA_ZEROBUFA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRA_ZEROBUFA) & BM_ASRC_ASRMCRA_ZEROBUFA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ZEROBUFA field to a new value.
#define BW_ASRC_ASRMCRA_ZEROBUFA(v)   (HW_ASRC_ASRMCRA_WR((HW_ASRC_ASRMCRA_RD() & ~BM_ASRC_ASRMCRA_ZEROBUFA) | BF_ASRC_ASRMCRA_ZEROBUFA(v)))
#endif


/* --- Register HW_ASRC_ASRMCRA, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRMCRA_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRMCRA_UNIMPLEMENTED.
#define BM_ASRC_ASRMCRA_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRMCRA_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRMCRA_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRMCRA_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRA_UNIMPLEMENTED) >> BP_ASRC_ASRMCRA_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRFSTA - ASRC FIFO Status Register for Pair A
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRFSTA - ASRC FIFO Status Register for Pair A (RO)
 *
 * Reset value: 0x00000000
 *
 * The register (ASRFSTA) is used to show Pair A internal FIFO conditions.
 */
typedef union _hw_asrc_asrfsta
{
    reg32_t U;
    struct _hw_asrc_asrfsta_bitfields
    {
        unsigned INFIFO_FILLA : 7; //!< [6:0] The fillings for Pair A's input FIFO per channel These bits stand for the fillings for Pair A's input FIFO per channel. Possible range is [0,64].
        unsigned RESERVED0 : 4; //!< [10:7] Reserved. Should be written as zero for future compatibility.
        unsigned IAEA : 1; //!< [11] Input FIFO is near Empty for Pair A This bit is to indicate whether the input FIFO of Pair A is near empty.
        unsigned OUTFIFO_FILLA : 7; //!< [18:12] The fillings for Pair A's output FIFO per channel These bits stand for the fillings for Pair A's output FIFO per channel. Possible range is [0,64].
        unsigned RESERVED1 : 4; //!< [22:19] Reserved. Should be written as zero for future compatibility.
        unsigned OAFA : 1; //!< [23] Output FIFO is near Full for Pair A This bit is to indicate whether the output FIFO of Pair A is near full.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrfsta_t;
#endif

/*
 * constants & macros for entire ASRC_ASRFSTA register
 */
#define HW_ASRC_ASRFSTA_ADDR      (REGS_ASRC_BASE + 0xa4)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRFSTA           (*(volatile hw_asrc_asrfsta_t *) HW_ASRC_ASRFSTA_ADDR)
#define HW_ASRC_ASRFSTA_RD()      (HW_ASRC_ASRFSTA.U)
#endif

/*
 * constants & macros for individual ASRC_ASRFSTA bitfields
 */

/* --- Register HW_ASRC_ASRFSTA, field INFIFO_FILLA[6:0] (RO)
 *
 * The fillings for Pair A's input FIFO per channel These bits stand for the fillings for Pair A's
 * input FIFO per channel. Possible range is [0,64].
 */

#define BP_ASRC_ASRFSTA_INFIFO_FILLA      (0)      //!< Bit position for ASRC_ASRFSTA_INFIFO_FILLA.
#define BM_ASRC_ASRFSTA_INFIFO_FILLA      (0x0000007f)  //!< Bit mask for ASRC_ASRFSTA_INFIFO_FILLA.

//! @brief Get value of ASRC_ASRFSTA_INFIFO_FILLA from a register value.
#define BG_ASRC_ASRFSTA_INFIFO_FILLA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRFSTA_INFIFO_FILLA) >> BP_ASRC_ASRFSTA_INFIFO_FILLA)

/* --- Register HW_ASRC_ASRFSTA, field IAEA[11] (RO)
 *
 * Input FIFO is near Empty for Pair A This bit is to indicate whether the input FIFO of Pair A is
 * near empty.
 */

#define BP_ASRC_ASRFSTA_IAEA      (11)      //!< Bit position for ASRC_ASRFSTA_IAEA.
#define BM_ASRC_ASRFSTA_IAEA      (0x00000800)  //!< Bit mask for ASRC_ASRFSTA_IAEA.

//! @brief Get value of ASRC_ASRFSTA_IAEA from a register value.
#define BG_ASRC_ASRFSTA_IAEA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRFSTA_IAEA) >> BP_ASRC_ASRFSTA_IAEA)

/* --- Register HW_ASRC_ASRFSTA, field OUTFIFO_FILLA[18:12] (RO)
 *
 * The fillings for Pair A's output FIFO per channel These bits stand for the fillings for Pair A's
 * output FIFO per channel. Possible range is [0,64].
 */

#define BP_ASRC_ASRFSTA_OUTFIFO_FILLA      (12)      //!< Bit position for ASRC_ASRFSTA_OUTFIFO_FILLA.
#define BM_ASRC_ASRFSTA_OUTFIFO_FILLA      (0x0007f000)  //!< Bit mask for ASRC_ASRFSTA_OUTFIFO_FILLA.

//! @brief Get value of ASRC_ASRFSTA_OUTFIFO_FILLA from a register value.
#define BG_ASRC_ASRFSTA_OUTFIFO_FILLA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRFSTA_OUTFIFO_FILLA) >> BP_ASRC_ASRFSTA_OUTFIFO_FILLA)

/* --- Register HW_ASRC_ASRFSTA, field OAFA[23] (RO)
 *
 * Output FIFO is near Full for Pair A This bit is to indicate whether the output FIFO of Pair A is
 * near full.
 */

#define BP_ASRC_ASRFSTA_OAFA      (23)      //!< Bit position for ASRC_ASRFSTA_OAFA.
#define BM_ASRC_ASRFSTA_OAFA      (0x00800000)  //!< Bit mask for ASRC_ASRFSTA_OAFA.

//! @brief Get value of ASRC_ASRFSTA_OAFA from a register value.
#define BG_ASRC_ASRFSTA_OAFA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRFSTA_OAFA) >> BP_ASRC_ASRFSTA_OAFA)

/* --- Register HW_ASRC_ASRFSTA, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRFSTA_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRFSTA_UNIMPLEMENTED.
#define BM_ASRC_ASRFSTA_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRFSTA_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRFSTA_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRFSTA_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRFSTA_UNIMPLEMENTED) >> BP_ASRC_ASRFSTA_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRMCRB - ASRC Misc Control Register for Pair B
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRMCRB - ASRC Misc Control Register for Pair B (RW)
 *
 * Reset value: 0x00000000
 *
 * The register (ASRMCRB) is used to control Pair B internal logic.
 */
typedef union _hw_asrc_asrmcrb
{
    reg32_t U;
    struct _hw_asrc_asrmcrb_bitfields
    {
        unsigned INFIFO_THRESHOLDB : 6; //!< [5:0] The threshold for Pair B's input FIFO per channel These bits stand for the threshold for Pair B's input FIFO per channel. Possible range is [0,63]. When the value is n, it means that: when the number of input FIFO fillings of the pair is less than n samples per channel, the input data needed flag is set; when the number of input FIFO fillings of the pair is greater than or equal to n samples per channel, the input data needed flag is automatically cleared.
        unsigned RESERVED0 : 4; //!< [9:6] Reserved. Should be written as zero for future compatibility.
        unsigned RSYNOFB : 1; //!< [10] Re-sync Output FIFO Channel Counter If bit set, force ASRCCR:ACOB=0. If bit clear, untouch ASRCCR:ACOB.
        unsigned RSYNIFB : 1; //!< [11] Re-sync Input FIFO Channel Counter If bit set, force ASRCCR:ACIB=0. If bit clear, untouch ASRCCR:ACIB.
        unsigned OUTFIFO_THRESHOLDB : 6; //!< [17:12] The threshold for Pair B's output FIFO per channel These bits stand for the threshold for Pair B's output FIFO per channel. Possible range is [0,63]. When the value is n, it means that: when the number of output FIFO fillings of the pair is greater than n samples per channel, the output data ready flag is set; when the number of output FIFO fillings of the pair is less than or equal to n samples per channel, the output data ready flag is automatically cleared.
        unsigned RESERVED1 : 2; //!< [19:18] Reserved. Should be written as zero for future compatibility.
        unsigned BYPASSPOLYB : 1; //!< [20] Bypass Polyphase Filtering for Pair B This bit will determine whether the polyphase filtering part of Pair B conversion will be bypassed.
        unsigned BUFSTALLB : 1; //!< [21] Stall Pair B conversion in case of Buffer Near Empty/Full Condition This bit will determine whether the near empty/full FIFO condition will stall the rate conversion for pair B. This option can only work when external ratio is used. Near empty condition is the condition when input FIFO has less than 4 useful samples per channel. Near full condition is the condition when the output FIFO has less than 4 vacant sample words to fill per channel.
        unsigned EXTTHRSHB : 1; //!< [22] Use external thresholds for FIFO control of Pair B This bit will determine whether the FIFO thresholds externally defined in this register is used to control ASRC internal FIFO logic for pair B.
        unsigned ZEROBUFB : 1; //!< [23] Initialize buf of Pair B when pair B is enabled This bit is used to control whether the buffer is to be zeroized when pair B is enabled.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrmcrb_t;
#endif

/*
 * constants & macros for entire ASRC_ASRMCRB register
 */
#define HW_ASRC_ASRMCRB_ADDR      (REGS_ASRC_BASE + 0xa8)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRMCRB           (*(volatile hw_asrc_asrmcrb_t *) HW_ASRC_ASRMCRB_ADDR)
#define HW_ASRC_ASRMCRB_RD()      (HW_ASRC_ASRMCRB.U)
#define HW_ASRC_ASRMCRB_WR(v)     (HW_ASRC_ASRMCRB.U = (v))
#define HW_ASRC_ASRMCRB_SET(v)    (HW_ASRC_ASRMCRB_WR(HW_ASRC_ASRMCRB_RD() |  (v)))
#define HW_ASRC_ASRMCRB_CLR(v)    (HW_ASRC_ASRMCRB_WR(HW_ASRC_ASRMCRB_RD() & ~(v)))
#define HW_ASRC_ASRMCRB_TOG(v)    (HW_ASRC_ASRMCRB_WR(HW_ASRC_ASRMCRB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRMCRB bitfields
 */

/* --- Register HW_ASRC_ASRMCRB, field INFIFO_THRESHOLDB[5:0] (RW)
 *
 * The threshold for Pair B's input FIFO per channel These bits stand for the threshold for Pair B's
 * input FIFO per channel. Possible range is [0,63]. When the value is n, it means that: when the
 * number of input FIFO fillings of the pair is less than n samples per channel, the input data
 * needed flag is set; when the number of input FIFO fillings of the pair is greater than or equal
 * to n samples per channel, the input data needed flag is automatically cleared.
 */

#define BP_ASRC_ASRMCRB_INFIFO_THRESHOLDB      (0)      //!< Bit position for ASRC_ASRMCRB_INFIFO_THRESHOLDB.
#define BM_ASRC_ASRMCRB_INFIFO_THRESHOLDB      (0x0000003f)  //!< Bit mask for ASRC_ASRMCRB_INFIFO_THRESHOLDB.

//! @brief Get value of ASRC_ASRMCRB_INFIFO_THRESHOLDB from a register value.
#define BG_ASRC_ASRMCRB_INFIFO_THRESHOLDB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRB_INFIFO_THRESHOLDB) >> BP_ASRC_ASRMCRB_INFIFO_THRESHOLDB)

//! @brief Format value for bitfield ASRC_ASRMCRB_INFIFO_THRESHOLDB.
#define BF_ASRC_ASRMCRB_INFIFO_THRESHOLDB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRB_INFIFO_THRESHOLDB) & BM_ASRC_ASRMCRB_INFIFO_THRESHOLDB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INFIFO_THRESHOLDB field to a new value.
#define BW_ASRC_ASRMCRB_INFIFO_THRESHOLDB(v)   (HW_ASRC_ASRMCRB_WR((HW_ASRC_ASRMCRB_RD() & ~BM_ASRC_ASRMCRB_INFIFO_THRESHOLDB) | BF_ASRC_ASRMCRB_INFIFO_THRESHOLDB(v)))
#endif

/* --- Register HW_ASRC_ASRMCRB, field RSYNOFB[10] (RW)
 *
 * Re-sync Output FIFO Channel Counter If bit set, force ASRCCR:ACOB=0. If bit clear, untouch
 * ASRCCR:ACOB.
 */

#define BP_ASRC_ASRMCRB_RSYNOFB      (10)      //!< Bit position for ASRC_ASRMCRB_RSYNOFB.
#define BM_ASRC_ASRMCRB_RSYNOFB      (0x00000400)  //!< Bit mask for ASRC_ASRMCRB_RSYNOFB.

//! @brief Get value of ASRC_ASRMCRB_RSYNOFB from a register value.
#define BG_ASRC_ASRMCRB_RSYNOFB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRB_RSYNOFB) >> BP_ASRC_ASRMCRB_RSYNOFB)

//! @brief Format value for bitfield ASRC_ASRMCRB_RSYNOFB.
#define BF_ASRC_ASRMCRB_RSYNOFB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRB_RSYNOFB) & BM_ASRC_ASRMCRB_RSYNOFB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RSYNOFB field to a new value.
#define BW_ASRC_ASRMCRB_RSYNOFB(v)   (HW_ASRC_ASRMCRB_WR((HW_ASRC_ASRMCRB_RD() & ~BM_ASRC_ASRMCRB_RSYNOFB) | BF_ASRC_ASRMCRB_RSYNOFB(v)))
#endif

/* --- Register HW_ASRC_ASRMCRB, field RSYNIFB[11] (RW)
 *
 * Re-sync Input FIFO Channel Counter If bit set, force ASRCCR:ACIB=0. If bit clear, untouch
 * ASRCCR:ACIB.
 */

#define BP_ASRC_ASRMCRB_RSYNIFB      (11)      //!< Bit position for ASRC_ASRMCRB_RSYNIFB.
#define BM_ASRC_ASRMCRB_RSYNIFB      (0x00000800)  //!< Bit mask for ASRC_ASRMCRB_RSYNIFB.

//! @brief Get value of ASRC_ASRMCRB_RSYNIFB from a register value.
#define BG_ASRC_ASRMCRB_RSYNIFB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRB_RSYNIFB) >> BP_ASRC_ASRMCRB_RSYNIFB)

//! @brief Format value for bitfield ASRC_ASRMCRB_RSYNIFB.
#define BF_ASRC_ASRMCRB_RSYNIFB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRB_RSYNIFB) & BM_ASRC_ASRMCRB_RSYNIFB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RSYNIFB field to a new value.
#define BW_ASRC_ASRMCRB_RSYNIFB(v)   (HW_ASRC_ASRMCRB_WR((HW_ASRC_ASRMCRB_RD() & ~BM_ASRC_ASRMCRB_RSYNIFB) | BF_ASRC_ASRMCRB_RSYNIFB(v)))
#endif

/* --- Register HW_ASRC_ASRMCRB, field OUTFIFO_THRESHOLDB[17:12] (RW)
 *
 * The threshold for Pair B's output FIFO per channel These bits stand for the threshold for Pair
 * B's output FIFO per channel. Possible range is [0,63]. When the value is n, it means that: when
 * the number of output FIFO fillings of the pair is greater than n samples per channel, the output
 * data ready flag is set; when the number of output FIFO fillings of the pair is less than or equal
 * to n samples per channel, the output data ready flag is automatically cleared.
 */

#define BP_ASRC_ASRMCRB_OUTFIFO_THRESHOLDB      (12)      //!< Bit position for ASRC_ASRMCRB_OUTFIFO_THRESHOLDB.
#define BM_ASRC_ASRMCRB_OUTFIFO_THRESHOLDB      (0x0003f000)  //!< Bit mask for ASRC_ASRMCRB_OUTFIFO_THRESHOLDB.

//! @brief Get value of ASRC_ASRMCRB_OUTFIFO_THRESHOLDB from a register value.
#define BG_ASRC_ASRMCRB_OUTFIFO_THRESHOLDB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRB_OUTFIFO_THRESHOLDB) >> BP_ASRC_ASRMCRB_OUTFIFO_THRESHOLDB)

//! @brief Format value for bitfield ASRC_ASRMCRB_OUTFIFO_THRESHOLDB.
#define BF_ASRC_ASRMCRB_OUTFIFO_THRESHOLDB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRB_OUTFIFO_THRESHOLDB) & BM_ASRC_ASRMCRB_OUTFIFO_THRESHOLDB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OUTFIFO_THRESHOLDB field to a new value.
#define BW_ASRC_ASRMCRB_OUTFIFO_THRESHOLDB(v)   (HW_ASRC_ASRMCRB_WR((HW_ASRC_ASRMCRB_RD() & ~BM_ASRC_ASRMCRB_OUTFIFO_THRESHOLDB) | BF_ASRC_ASRMCRB_OUTFIFO_THRESHOLDB(v)))
#endif

/* --- Register HW_ASRC_ASRMCRB, field BYPASSPOLYB[20] (RW)
 *
 * Bypass Polyphase Filtering for Pair B This bit will determine whether the polyphase filtering
 * part of Pair B conversion will be bypassed.
 *
 * Values:
 * 0 - Don't bypass polyphase filtering.
 * 1 - Bypass polyphase filtering.
 */

#define BP_ASRC_ASRMCRB_BYPASSPOLYB      (20)      //!< Bit position for ASRC_ASRMCRB_BYPASSPOLYB.
#define BM_ASRC_ASRMCRB_BYPASSPOLYB      (0x00100000)  //!< Bit mask for ASRC_ASRMCRB_BYPASSPOLYB.

//! @brief Get value of ASRC_ASRMCRB_BYPASSPOLYB from a register value.
#define BG_ASRC_ASRMCRB_BYPASSPOLYB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRB_BYPASSPOLYB) >> BP_ASRC_ASRMCRB_BYPASSPOLYB)

//! @brief Format value for bitfield ASRC_ASRMCRB_BYPASSPOLYB.
#define BF_ASRC_ASRMCRB_BYPASSPOLYB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRB_BYPASSPOLYB) & BM_ASRC_ASRMCRB_BYPASSPOLYB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASSPOLYB field to a new value.
#define BW_ASRC_ASRMCRB_BYPASSPOLYB(v)   (HW_ASRC_ASRMCRB_WR((HW_ASRC_ASRMCRB_RD() & ~BM_ASRC_ASRMCRB_BYPASSPOLYB) | BF_ASRC_ASRMCRB_BYPASSPOLYB(v)))
#endif


/* --- Register HW_ASRC_ASRMCRB, field BUFSTALLB[21] (RW)
 *
 * Stall Pair B conversion in case of Buffer Near Empty/Full Condition This bit will determine
 * whether the near empty/full FIFO condition will stall the rate conversion for pair B. This option
 * can only work when external ratio is used. Near empty condition is the condition when input FIFO
 * has less than 4 useful samples per channel. Near full condition is the condition when the output
 * FIFO has less than 4 vacant sample words to fill per channel.
 *
 * Values:
 * 0 - Don't stall Pair B conversion even in case of near empty/full FIFO conditions.
 * 1 - Stall Pair B conversion in case of near empty/full FIFO conditions.
 */

#define BP_ASRC_ASRMCRB_BUFSTALLB      (21)      //!< Bit position for ASRC_ASRMCRB_BUFSTALLB.
#define BM_ASRC_ASRMCRB_BUFSTALLB      (0x00200000)  //!< Bit mask for ASRC_ASRMCRB_BUFSTALLB.

//! @brief Get value of ASRC_ASRMCRB_BUFSTALLB from a register value.
#define BG_ASRC_ASRMCRB_BUFSTALLB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRB_BUFSTALLB) >> BP_ASRC_ASRMCRB_BUFSTALLB)

//! @brief Format value for bitfield ASRC_ASRMCRB_BUFSTALLB.
#define BF_ASRC_ASRMCRB_BUFSTALLB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRB_BUFSTALLB) & BM_ASRC_ASRMCRB_BUFSTALLB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BUFSTALLB field to a new value.
#define BW_ASRC_ASRMCRB_BUFSTALLB(v)   (HW_ASRC_ASRMCRB_WR((HW_ASRC_ASRMCRB_RD() & ~BM_ASRC_ASRMCRB_BUFSTALLB) | BF_ASRC_ASRMCRB_BUFSTALLB(v)))
#endif


/* --- Register HW_ASRC_ASRMCRB, field EXTTHRSHB[22] (RW)
 *
 * Use external thresholds for FIFO control of Pair B This bit will determine whether the FIFO
 * thresholds externally defined in this register is used to control ASRC internal FIFO logic for
 * pair B.
 *
 * Values:
 * 0 - Use default thresholds.
 * 1 - Use external defined thresholds.
 */

#define BP_ASRC_ASRMCRB_EXTTHRSHB      (22)      //!< Bit position for ASRC_ASRMCRB_EXTTHRSHB.
#define BM_ASRC_ASRMCRB_EXTTHRSHB      (0x00400000)  //!< Bit mask for ASRC_ASRMCRB_EXTTHRSHB.

//! @brief Get value of ASRC_ASRMCRB_EXTTHRSHB from a register value.
#define BG_ASRC_ASRMCRB_EXTTHRSHB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRB_EXTTHRSHB) >> BP_ASRC_ASRMCRB_EXTTHRSHB)

//! @brief Format value for bitfield ASRC_ASRMCRB_EXTTHRSHB.
#define BF_ASRC_ASRMCRB_EXTTHRSHB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRB_EXTTHRSHB) & BM_ASRC_ASRMCRB_EXTTHRSHB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EXTTHRSHB field to a new value.
#define BW_ASRC_ASRMCRB_EXTTHRSHB(v)   (HW_ASRC_ASRMCRB_WR((HW_ASRC_ASRMCRB_RD() & ~BM_ASRC_ASRMCRB_EXTTHRSHB) | BF_ASRC_ASRMCRB_EXTTHRSHB(v)))
#endif


/* --- Register HW_ASRC_ASRMCRB, field ZEROBUFB[23] (RW)
 *
 * Initialize buf of Pair B when pair B is enabled This bit is used to control whether the buffer is
 * to be zeroized when pair B is enabled.
 *
 * Values:
 * 0 - Zeroize the buffer
 * 1 - Don't zeroize the buffer
 */

#define BP_ASRC_ASRMCRB_ZEROBUFB      (23)      //!< Bit position for ASRC_ASRMCRB_ZEROBUFB.
#define BM_ASRC_ASRMCRB_ZEROBUFB      (0x00800000)  //!< Bit mask for ASRC_ASRMCRB_ZEROBUFB.

//! @brief Get value of ASRC_ASRMCRB_ZEROBUFB from a register value.
#define BG_ASRC_ASRMCRB_ZEROBUFB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRB_ZEROBUFB) >> BP_ASRC_ASRMCRB_ZEROBUFB)

//! @brief Format value for bitfield ASRC_ASRMCRB_ZEROBUFB.
#define BF_ASRC_ASRMCRB_ZEROBUFB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRB_ZEROBUFB) & BM_ASRC_ASRMCRB_ZEROBUFB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ZEROBUFB field to a new value.
#define BW_ASRC_ASRMCRB_ZEROBUFB(v)   (HW_ASRC_ASRMCRB_WR((HW_ASRC_ASRMCRB_RD() & ~BM_ASRC_ASRMCRB_ZEROBUFB) | BF_ASRC_ASRMCRB_ZEROBUFB(v)))
#endif


/* --- Register HW_ASRC_ASRMCRB, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRMCRB_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRMCRB_UNIMPLEMENTED.
#define BM_ASRC_ASRMCRB_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRMCRB_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRMCRB_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRMCRB_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRB_UNIMPLEMENTED) >> BP_ASRC_ASRMCRB_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRFSTB - ASRC FIFO Status Register for Pair B
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRFSTB - ASRC FIFO Status Register for Pair B (RO)
 *
 * Reset value: 0x00000000
 *
 * The register (ASRFSTB) is used to show Pair B internal FIFO conditions.
 */
typedef union _hw_asrc_asrfstb
{
    reg32_t U;
    struct _hw_asrc_asrfstb_bitfields
    {
        unsigned INFIFO_FILLB : 7; //!< [6:0] The fillings for Pair B's input FIFO per channel These bits stand for the fillings for Pair B's input FIFO per channel. Possible range is [0,64].
        unsigned RESERVED0 : 4; //!< [10:7] Reserved. Should be written as zero for future compatibility.
        unsigned IAEB : 1; //!< [11] Input FIFO is near Empty for Pair B This bit is to indicate whether the input FIFO of Pair B is near empty.
        unsigned OUTFIFO_FILLB : 7; //!< [18:12] The fillings for Pair B's output FIFO per channel These bits stand for the fillings for Pair B's output FIFO per channel. Possible range is [0,64].
        unsigned RESERVED1 : 4; //!< [22:19] Reserved. Should be written as zero for future compatibility.
        unsigned OAFB : 1; //!< [23] Output FIFO is near Full for Pair B This bit is to indicate whether the output FIFO of Pair B is near full.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrfstb_t;
#endif

/*
 * constants & macros for entire ASRC_ASRFSTB register
 */
#define HW_ASRC_ASRFSTB_ADDR      (REGS_ASRC_BASE + 0xac)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRFSTB           (*(volatile hw_asrc_asrfstb_t *) HW_ASRC_ASRFSTB_ADDR)
#define HW_ASRC_ASRFSTB_RD()      (HW_ASRC_ASRFSTB.U)
#endif

/*
 * constants & macros for individual ASRC_ASRFSTB bitfields
 */

/* --- Register HW_ASRC_ASRFSTB, field INFIFO_FILLB[6:0] (RO)
 *
 * The fillings for Pair B's input FIFO per channel These bits stand for the fillings for Pair B's
 * input FIFO per channel. Possible range is [0,64].
 */

#define BP_ASRC_ASRFSTB_INFIFO_FILLB      (0)      //!< Bit position for ASRC_ASRFSTB_INFIFO_FILLB.
#define BM_ASRC_ASRFSTB_INFIFO_FILLB      (0x0000007f)  //!< Bit mask for ASRC_ASRFSTB_INFIFO_FILLB.

//! @brief Get value of ASRC_ASRFSTB_INFIFO_FILLB from a register value.
#define BG_ASRC_ASRFSTB_INFIFO_FILLB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRFSTB_INFIFO_FILLB) >> BP_ASRC_ASRFSTB_INFIFO_FILLB)

/* --- Register HW_ASRC_ASRFSTB, field IAEB[11] (RO)
 *
 * Input FIFO is near Empty for Pair B This bit is to indicate whether the input FIFO of Pair B is
 * near empty.
 */

#define BP_ASRC_ASRFSTB_IAEB      (11)      //!< Bit position for ASRC_ASRFSTB_IAEB.
#define BM_ASRC_ASRFSTB_IAEB      (0x00000800)  //!< Bit mask for ASRC_ASRFSTB_IAEB.

//! @brief Get value of ASRC_ASRFSTB_IAEB from a register value.
#define BG_ASRC_ASRFSTB_IAEB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRFSTB_IAEB) >> BP_ASRC_ASRFSTB_IAEB)

/* --- Register HW_ASRC_ASRFSTB, field OUTFIFO_FILLB[18:12] (RO)
 *
 * The fillings for Pair B's output FIFO per channel These bits stand for the fillings for Pair B's
 * output FIFO per channel. Possible range is [0,64].
 */

#define BP_ASRC_ASRFSTB_OUTFIFO_FILLB      (12)      //!< Bit position for ASRC_ASRFSTB_OUTFIFO_FILLB.
#define BM_ASRC_ASRFSTB_OUTFIFO_FILLB      (0x0007f000)  //!< Bit mask for ASRC_ASRFSTB_OUTFIFO_FILLB.

//! @brief Get value of ASRC_ASRFSTB_OUTFIFO_FILLB from a register value.
#define BG_ASRC_ASRFSTB_OUTFIFO_FILLB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRFSTB_OUTFIFO_FILLB) >> BP_ASRC_ASRFSTB_OUTFIFO_FILLB)

/* --- Register HW_ASRC_ASRFSTB, field OAFB[23] (RO)
 *
 * Output FIFO is near Full for Pair B This bit is to indicate whether the output FIFO of Pair B is
 * near full.
 */

#define BP_ASRC_ASRFSTB_OAFB      (23)      //!< Bit position for ASRC_ASRFSTB_OAFB.
#define BM_ASRC_ASRFSTB_OAFB      (0x00800000)  //!< Bit mask for ASRC_ASRFSTB_OAFB.

//! @brief Get value of ASRC_ASRFSTB_OAFB from a register value.
#define BG_ASRC_ASRFSTB_OAFB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRFSTB_OAFB) >> BP_ASRC_ASRFSTB_OAFB)

/* --- Register HW_ASRC_ASRFSTB, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRFSTB_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRFSTB_UNIMPLEMENTED.
#define BM_ASRC_ASRFSTB_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRFSTB_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRFSTB_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRFSTB_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRFSTB_UNIMPLEMENTED) >> BP_ASRC_ASRFSTB_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRMCRC - ASRC Misc Control Register for Pair C
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRMCRC - ASRC Misc Control Register for Pair C (RW)
 *
 * Reset value: 0x00000000
 *
 * The register (ASRMCRC) is used to control Pair C internal logic.
 */
typedef union _hw_asrc_asrmcrc
{
    reg32_t U;
    struct _hw_asrc_asrmcrc_bitfields
    {
        unsigned INFIFO_THRESHOLDC : 6; //!< [5:0] The threshold for Pair C's input FIFO per channel These bits stand for the threshold for Pair C's input FIFO per channel. Possible range is [0,63]. When the value is n, it means that: when the number of input FIFO fillings of the pair is less than n samples per channel, the input data needed flag is set; when the number of input FIFO fillings of the pair is greater than or equal to n samples per channel, the input data needed flag is automatically cleared.
        unsigned RESERVED0 : 4; //!< [9:6] Reserved. Should be written as zero for future compatibility.
        unsigned RSYNOFC : 1; //!< [10] Re-sync Output FIFO Channel Counter If bit set, force ASRCCR:ACOC=0. If bit clear, untouch ASRCCR:ACOC.
        unsigned RSYNIFC : 1; //!< [11] Re-sync Input FIFO Channel Counter If bit set, force ASRCCR:ACIC=0. If bit clear, untouch ASRCCR:ACIC.
        unsigned OUTFIFO_THRESHOLDC : 6; //!< [17:12] The threshold for Pair C's output FIFO per channel These bits stand for the threshold for Pair C's output FIFO per channel. Possible range is [0,63]. When the value is n, it means that: when the number of output FIFO fillings of the pair is greater than n samples per channel, the output data ready flag is set; when the number of output FIFO fillings of the pair is less than or equal to n samples per channel, the output data ready flag is automatically cleared.
        unsigned RESERVED1 : 2; //!< [19:18] Reserved. Should be written as zero for future compatibility.
        unsigned BYPASSPOLYC : 1; //!< [20] Bypass Polyphase Filtering for Pair C This bit will determine whether the polyphase filtering part of Pair C conversion will be bypassed.
        unsigned BUFSTALLC : 1; //!< [21] Stall Pair C conversion in case of Buffer Near Empty/Full Condition This bit will determine whether the near empty/full FIFO condition will stall the rate conversion for pair C. This option can only work when external ratio is used. Near empty condition is the condition when input FIFO has less than 4 useful samples per channel. Near full condition is the condition when the output FIFO has less than 4 vacant sample words to fill per channel.
        unsigned EXTTHRSHC : 1; //!< [22] Use external thresholds for FIFO control of Pair C This bit will determine whether the FIFO thresholds externally defined in this register is used to control ASRC internal FIFO logic for pair C.
        unsigned ZEROBUFC : 1; //!< [23] Initialize buf of Pair C when pair C is enabled This bit is used to control whether the buffer is to be zeroized when pair C is enabled.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrmcrc_t;
#endif

/*
 * constants & macros for entire ASRC_ASRMCRC register
 */
#define HW_ASRC_ASRMCRC_ADDR      (REGS_ASRC_BASE + 0xb0)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRMCRC           (*(volatile hw_asrc_asrmcrc_t *) HW_ASRC_ASRMCRC_ADDR)
#define HW_ASRC_ASRMCRC_RD()      (HW_ASRC_ASRMCRC.U)
#define HW_ASRC_ASRMCRC_WR(v)     (HW_ASRC_ASRMCRC.U = (v))
#define HW_ASRC_ASRMCRC_SET(v)    (HW_ASRC_ASRMCRC_WR(HW_ASRC_ASRMCRC_RD() |  (v)))
#define HW_ASRC_ASRMCRC_CLR(v)    (HW_ASRC_ASRMCRC_WR(HW_ASRC_ASRMCRC_RD() & ~(v)))
#define HW_ASRC_ASRMCRC_TOG(v)    (HW_ASRC_ASRMCRC_WR(HW_ASRC_ASRMCRC_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRMCRC bitfields
 */

/* --- Register HW_ASRC_ASRMCRC, field INFIFO_THRESHOLDC[5:0] (RW)
 *
 * The threshold for Pair C's input FIFO per channel These bits stand for the threshold for Pair C's
 * input FIFO per channel. Possible range is [0,63]. When the value is n, it means that: when the
 * number of input FIFO fillings of the pair is less than n samples per channel, the input data
 * needed flag is set; when the number of input FIFO fillings of the pair is greater than or equal
 * to n samples per channel, the input data needed flag is automatically cleared.
 */

#define BP_ASRC_ASRMCRC_INFIFO_THRESHOLDC      (0)      //!< Bit position for ASRC_ASRMCRC_INFIFO_THRESHOLDC.
#define BM_ASRC_ASRMCRC_INFIFO_THRESHOLDC      (0x0000003f)  //!< Bit mask for ASRC_ASRMCRC_INFIFO_THRESHOLDC.

//! @brief Get value of ASRC_ASRMCRC_INFIFO_THRESHOLDC from a register value.
#define BG_ASRC_ASRMCRC_INFIFO_THRESHOLDC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRC_INFIFO_THRESHOLDC) >> BP_ASRC_ASRMCRC_INFIFO_THRESHOLDC)

//! @brief Format value for bitfield ASRC_ASRMCRC_INFIFO_THRESHOLDC.
#define BF_ASRC_ASRMCRC_INFIFO_THRESHOLDC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRC_INFIFO_THRESHOLDC) & BM_ASRC_ASRMCRC_INFIFO_THRESHOLDC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INFIFO_THRESHOLDC field to a new value.
#define BW_ASRC_ASRMCRC_INFIFO_THRESHOLDC(v)   (HW_ASRC_ASRMCRC_WR((HW_ASRC_ASRMCRC_RD() & ~BM_ASRC_ASRMCRC_INFIFO_THRESHOLDC) | BF_ASRC_ASRMCRC_INFIFO_THRESHOLDC(v)))
#endif

/* --- Register HW_ASRC_ASRMCRC, field RSYNOFC[10] (RW)
 *
 * Re-sync Output FIFO Channel Counter If bit set, force ASRCCR:ACOC=0. If bit clear, untouch
 * ASRCCR:ACOC.
 */

#define BP_ASRC_ASRMCRC_RSYNOFC      (10)      //!< Bit position for ASRC_ASRMCRC_RSYNOFC.
#define BM_ASRC_ASRMCRC_RSYNOFC      (0x00000400)  //!< Bit mask for ASRC_ASRMCRC_RSYNOFC.

//! @brief Get value of ASRC_ASRMCRC_RSYNOFC from a register value.
#define BG_ASRC_ASRMCRC_RSYNOFC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRC_RSYNOFC) >> BP_ASRC_ASRMCRC_RSYNOFC)

//! @brief Format value for bitfield ASRC_ASRMCRC_RSYNOFC.
#define BF_ASRC_ASRMCRC_RSYNOFC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRC_RSYNOFC) & BM_ASRC_ASRMCRC_RSYNOFC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RSYNOFC field to a new value.
#define BW_ASRC_ASRMCRC_RSYNOFC(v)   (HW_ASRC_ASRMCRC_WR((HW_ASRC_ASRMCRC_RD() & ~BM_ASRC_ASRMCRC_RSYNOFC) | BF_ASRC_ASRMCRC_RSYNOFC(v)))
#endif

/* --- Register HW_ASRC_ASRMCRC, field RSYNIFC[11] (RW)
 *
 * Re-sync Input FIFO Channel Counter If bit set, force ASRCCR:ACIC=0. If bit clear, untouch
 * ASRCCR:ACIC.
 */

#define BP_ASRC_ASRMCRC_RSYNIFC      (11)      //!< Bit position for ASRC_ASRMCRC_RSYNIFC.
#define BM_ASRC_ASRMCRC_RSYNIFC      (0x00000800)  //!< Bit mask for ASRC_ASRMCRC_RSYNIFC.

//! @brief Get value of ASRC_ASRMCRC_RSYNIFC from a register value.
#define BG_ASRC_ASRMCRC_RSYNIFC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRC_RSYNIFC) >> BP_ASRC_ASRMCRC_RSYNIFC)

//! @brief Format value for bitfield ASRC_ASRMCRC_RSYNIFC.
#define BF_ASRC_ASRMCRC_RSYNIFC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRC_RSYNIFC) & BM_ASRC_ASRMCRC_RSYNIFC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RSYNIFC field to a new value.
#define BW_ASRC_ASRMCRC_RSYNIFC(v)   (HW_ASRC_ASRMCRC_WR((HW_ASRC_ASRMCRC_RD() & ~BM_ASRC_ASRMCRC_RSYNIFC) | BF_ASRC_ASRMCRC_RSYNIFC(v)))
#endif

/* --- Register HW_ASRC_ASRMCRC, field OUTFIFO_THRESHOLDC[17:12] (RW)
 *
 * The threshold for Pair C's output FIFO per channel These bits stand for the threshold for Pair
 * C's output FIFO per channel. Possible range is [0,63]. When the value is n, it means that: when
 * the number of output FIFO fillings of the pair is greater than n samples per channel, the output
 * data ready flag is set; when the number of output FIFO fillings of the pair is less than or equal
 * to n samples per channel, the output data ready flag is automatically cleared.
 */

#define BP_ASRC_ASRMCRC_OUTFIFO_THRESHOLDC      (12)      //!< Bit position for ASRC_ASRMCRC_OUTFIFO_THRESHOLDC.
#define BM_ASRC_ASRMCRC_OUTFIFO_THRESHOLDC      (0x0003f000)  //!< Bit mask for ASRC_ASRMCRC_OUTFIFO_THRESHOLDC.

//! @brief Get value of ASRC_ASRMCRC_OUTFIFO_THRESHOLDC from a register value.
#define BG_ASRC_ASRMCRC_OUTFIFO_THRESHOLDC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRC_OUTFIFO_THRESHOLDC) >> BP_ASRC_ASRMCRC_OUTFIFO_THRESHOLDC)

//! @brief Format value for bitfield ASRC_ASRMCRC_OUTFIFO_THRESHOLDC.
#define BF_ASRC_ASRMCRC_OUTFIFO_THRESHOLDC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRC_OUTFIFO_THRESHOLDC) & BM_ASRC_ASRMCRC_OUTFIFO_THRESHOLDC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OUTFIFO_THRESHOLDC field to a new value.
#define BW_ASRC_ASRMCRC_OUTFIFO_THRESHOLDC(v)   (HW_ASRC_ASRMCRC_WR((HW_ASRC_ASRMCRC_RD() & ~BM_ASRC_ASRMCRC_OUTFIFO_THRESHOLDC) | BF_ASRC_ASRMCRC_OUTFIFO_THRESHOLDC(v)))
#endif

/* --- Register HW_ASRC_ASRMCRC, field BYPASSPOLYC[20] (RW)
 *
 * Bypass Polyphase Filtering for Pair C This bit will determine whether the polyphase filtering
 * part of Pair C conversion will be bypassed.
 *
 * Values:
 * 0 - Don't bypass polyphase filtering.
 * 1 - Bypass polyphase filtering.
 */

#define BP_ASRC_ASRMCRC_BYPASSPOLYC      (20)      //!< Bit position for ASRC_ASRMCRC_BYPASSPOLYC.
#define BM_ASRC_ASRMCRC_BYPASSPOLYC      (0x00100000)  //!< Bit mask for ASRC_ASRMCRC_BYPASSPOLYC.

//! @brief Get value of ASRC_ASRMCRC_BYPASSPOLYC from a register value.
#define BG_ASRC_ASRMCRC_BYPASSPOLYC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRC_BYPASSPOLYC) >> BP_ASRC_ASRMCRC_BYPASSPOLYC)

//! @brief Format value for bitfield ASRC_ASRMCRC_BYPASSPOLYC.
#define BF_ASRC_ASRMCRC_BYPASSPOLYC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRC_BYPASSPOLYC) & BM_ASRC_ASRMCRC_BYPASSPOLYC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASSPOLYC field to a new value.
#define BW_ASRC_ASRMCRC_BYPASSPOLYC(v)   (HW_ASRC_ASRMCRC_WR((HW_ASRC_ASRMCRC_RD() & ~BM_ASRC_ASRMCRC_BYPASSPOLYC) | BF_ASRC_ASRMCRC_BYPASSPOLYC(v)))
#endif


/* --- Register HW_ASRC_ASRMCRC, field BUFSTALLC[21] (RW)
 *
 * Stall Pair C conversion in case of Buffer Near Empty/Full Condition This bit will determine
 * whether the near empty/full FIFO condition will stall the rate conversion for pair C. This option
 * can only work when external ratio is used. Near empty condition is the condition when input FIFO
 * has less than 4 useful samples per channel. Near full condition is the condition when the output
 * FIFO has less than 4 vacant sample words to fill per channel.
 *
 * Values:
 * 0 - Don't stall Pair C conversion even in case of near empty/full FIFO conditions.
 * 1 - Stall Pair C conversion in case of near empty/full FIFO conditions.
 */

#define BP_ASRC_ASRMCRC_BUFSTALLC      (21)      //!< Bit position for ASRC_ASRMCRC_BUFSTALLC.
#define BM_ASRC_ASRMCRC_BUFSTALLC      (0x00200000)  //!< Bit mask for ASRC_ASRMCRC_BUFSTALLC.

//! @brief Get value of ASRC_ASRMCRC_BUFSTALLC from a register value.
#define BG_ASRC_ASRMCRC_BUFSTALLC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRC_BUFSTALLC) >> BP_ASRC_ASRMCRC_BUFSTALLC)

//! @brief Format value for bitfield ASRC_ASRMCRC_BUFSTALLC.
#define BF_ASRC_ASRMCRC_BUFSTALLC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRC_BUFSTALLC) & BM_ASRC_ASRMCRC_BUFSTALLC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BUFSTALLC field to a new value.
#define BW_ASRC_ASRMCRC_BUFSTALLC(v)   (HW_ASRC_ASRMCRC_WR((HW_ASRC_ASRMCRC_RD() & ~BM_ASRC_ASRMCRC_BUFSTALLC) | BF_ASRC_ASRMCRC_BUFSTALLC(v)))
#endif


/* --- Register HW_ASRC_ASRMCRC, field EXTTHRSHC[22] (RW)
 *
 * Use external thresholds for FIFO control of Pair C This bit will determine whether the FIFO
 * thresholds externally defined in this register is used to control ASRC internal FIFO logic for
 * pair C.
 *
 * Values:
 * 0 - Use default thresholds.
 * 1 - Use external defined thresholds.
 */

#define BP_ASRC_ASRMCRC_EXTTHRSHC      (22)      //!< Bit position for ASRC_ASRMCRC_EXTTHRSHC.
#define BM_ASRC_ASRMCRC_EXTTHRSHC      (0x00400000)  //!< Bit mask for ASRC_ASRMCRC_EXTTHRSHC.

//! @brief Get value of ASRC_ASRMCRC_EXTTHRSHC from a register value.
#define BG_ASRC_ASRMCRC_EXTTHRSHC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRC_EXTTHRSHC) >> BP_ASRC_ASRMCRC_EXTTHRSHC)

//! @brief Format value for bitfield ASRC_ASRMCRC_EXTTHRSHC.
#define BF_ASRC_ASRMCRC_EXTTHRSHC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRC_EXTTHRSHC) & BM_ASRC_ASRMCRC_EXTTHRSHC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EXTTHRSHC field to a new value.
#define BW_ASRC_ASRMCRC_EXTTHRSHC(v)   (HW_ASRC_ASRMCRC_WR((HW_ASRC_ASRMCRC_RD() & ~BM_ASRC_ASRMCRC_EXTTHRSHC) | BF_ASRC_ASRMCRC_EXTTHRSHC(v)))
#endif


/* --- Register HW_ASRC_ASRMCRC, field ZEROBUFC[23] (RW)
 *
 * Initialize buf of Pair C when pair C is enabled This bit is used to control whether the buffer is
 * to be zeroized when pair C is enabled.
 *
 * Values:
 * 0 - Zeroize the buffer
 * 1 - Don't zeroize the buffer
 */

#define BP_ASRC_ASRMCRC_ZEROBUFC      (23)      //!< Bit position for ASRC_ASRMCRC_ZEROBUFC.
#define BM_ASRC_ASRMCRC_ZEROBUFC      (0x00800000)  //!< Bit mask for ASRC_ASRMCRC_ZEROBUFC.

//! @brief Get value of ASRC_ASRMCRC_ZEROBUFC from a register value.
#define BG_ASRC_ASRMCRC_ZEROBUFC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRC_ZEROBUFC) >> BP_ASRC_ASRMCRC_ZEROBUFC)

//! @brief Format value for bitfield ASRC_ASRMCRC_ZEROBUFC.
#define BF_ASRC_ASRMCRC_ZEROBUFC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCRC_ZEROBUFC) & BM_ASRC_ASRMCRC_ZEROBUFC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ZEROBUFC field to a new value.
#define BW_ASRC_ASRMCRC_ZEROBUFC(v)   (HW_ASRC_ASRMCRC_WR((HW_ASRC_ASRMCRC_RD() & ~BM_ASRC_ASRMCRC_ZEROBUFC) | BF_ASRC_ASRMCRC_ZEROBUFC(v)))
#endif


/* --- Register HW_ASRC_ASRMCRC, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRMCRC_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRMCRC_UNIMPLEMENTED.
#define BM_ASRC_ASRMCRC_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRMCRC_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRMCRC_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRMCRC_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCRC_UNIMPLEMENTED) >> BP_ASRC_ASRMCRC_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRFSTC - ASRC FIFO Status Register for Pair C
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRFSTC - ASRC FIFO Status Register for Pair C (RO)
 *
 * Reset value: 0x00000000
 *
 * The register (ASRFSTC) is used to show Pair C internal FIFO conditions.
 */
typedef union _hw_asrc_asrfstc
{
    reg32_t U;
    struct _hw_asrc_asrfstc_bitfields
    {
        unsigned INFIFO_FILLC : 7; //!< [6:0] The fillings for Pair C's input FIFO per channel These bits stand for the fillings for Pair C's input FIFO per channel. Possible range is [0,64].
        unsigned RESERVED0 : 4; //!< [10:7] Reserved. Should be written as zero for future compatibility.
        unsigned IAEC : 1; //!< [11] Input FIFO is near Empty for Pair C This bit is to indicate whether the input FIFO of Pair C is near empty.
        unsigned OUTFIFO_FILLC : 7; //!< [18:12] The fillings for Pair C's output FIFO per channel These bits stand for the fillings for Pair C's output FIFO per channel. Possible range is [0,64].
        unsigned RESERVED1 : 4; //!< [22:19] Reserved. Should be written as zero for future compatibility.
        unsigned OAFC : 1; //!< [23] Output FIFO is near Full for Pair C This bit is to indicate whether the output FIFO of Pair C is near full.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrfstc_t;
#endif

/*
 * constants & macros for entire ASRC_ASRFSTC register
 */
#define HW_ASRC_ASRFSTC_ADDR      (REGS_ASRC_BASE + 0xb4)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRFSTC           (*(volatile hw_asrc_asrfstc_t *) HW_ASRC_ASRFSTC_ADDR)
#define HW_ASRC_ASRFSTC_RD()      (HW_ASRC_ASRFSTC.U)
#endif

/*
 * constants & macros for individual ASRC_ASRFSTC bitfields
 */

/* --- Register HW_ASRC_ASRFSTC, field INFIFO_FILLC[6:0] (RO)
 *
 * The fillings for Pair C's input FIFO per channel These bits stand for the fillings for Pair C's
 * input FIFO per channel. Possible range is [0,64].
 */

#define BP_ASRC_ASRFSTC_INFIFO_FILLC      (0)      //!< Bit position for ASRC_ASRFSTC_INFIFO_FILLC.
#define BM_ASRC_ASRFSTC_INFIFO_FILLC      (0x0000007f)  //!< Bit mask for ASRC_ASRFSTC_INFIFO_FILLC.

//! @brief Get value of ASRC_ASRFSTC_INFIFO_FILLC from a register value.
#define BG_ASRC_ASRFSTC_INFIFO_FILLC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRFSTC_INFIFO_FILLC) >> BP_ASRC_ASRFSTC_INFIFO_FILLC)

/* --- Register HW_ASRC_ASRFSTC, field IAEC[11] (RO)
 *
 * Input FIFO is near Empty for Pair C This bit is to indicate whether the input FIFO of Pair C is
 * near empty.
 */

#define BP_ASRC_ASRFSTC_IAEC      (11)      //!< Bit position for ASRC_ASRFSTC_IAEC.
#define BM_ASRC_ASRFSTC_IAEC      (0x00000800)  //!< Bit mask for ASRC_ASRFSTC_IAEC.

//! @brief Get value of ASRC_ASRFSTC_IAEC from a register value.
#define BG_ASRC_ASRFSTC_IAEC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRFSTC_IAEC) >> BP_ASRC_ASRFSTC_IAEC)

/* --- Register HW_ASRC_ASRFSTC, field OUTFIFO_FILLC[18:12] (RO)
 *
 * The fillings for Pair C's output FIFO per channel These bits stand for the fillings for Pair C's
 * output FIFO per channel. Possible range is [0,64].
 */

#define BP_ASRC_ASRFSTC_OUTFIFO_FILLC      (12)      //!< Bit position for ASRC_ASRFSTC_OUTFIFO_FILLC.
#define BM_ASRC_ASRFSTC_OUTFIFO_FILLC      (0x0007f000)  //!< Bit mask for ASRC_ASRFSTC_OUTFIFO_FILLC.

//! @brief Get value of ASRC_ASRFSTC_OUTFIFO_FILLC from a register value.
#define BG_ASRC_ASRFSTC_OUTFIFO_FILLC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRFSTC_OUTFIFO_FILLC) >> BP_ASRC_ASRFSTC_OUTFIFO_FILLC)

/* --- Register HW_ASRC_ASRFSTC, field OAFC[23] (RO)
 *
 * Output FIFO is near Full for Pair C This bit is to indicate whether the output FIFO of Pair C is
 * near full.
 */

#define BP_ASRC_ASRFSTC_OAFC      (23)      //!< Bit position for ASRC_ASRFSTC_OAFC.
#define BM_ASRC_ASRFSTC_OAFC      (0x00800000)  //!< Bit mask for ASRC_ASRFSTC_OAFC.

//! @brief Get value of ASRC_ASRFSTC_OAFC from a register value.
#define BG_ASRC_ASRFSTC_OAFC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRFSTC_OAFC) >> BP_ASRC_ASRFSTC_OAFC)

/* --- Register HW_ASRC_ASRFSTC, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRFSTC_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRFSTC_UNIMPLEMENTED.
#define BM_ASRC_ASRFSTC_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRFSTC_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRFSTC_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRFSTC_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRFSTC_UNIMPLEMENTED) >> BP_ASRC_ASRFSTC_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRMCR1A - ASRC Misc Control Register 1 for Pair X
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRMCR1A - ASRC Misc Control Register 1 for Pair X (RW)
 *
 * Reset value: 0x00000000
 *
 * The register (ASRMCR1A) is used to control Pair x internal logic (for data alignment etc.).  The
 * bit assignment for all the input data formats is the same as that supported by the SSI.
 */
typedef union _hw_asrc_asrmcr1a
{
    reg32_t U;
    struct _hw_asrc_asrmcr1a_bitfields
    {
        unsigned OW16 : 1; //!< [0] Bit Width Option of the output FIFO This bit will determine the bit width option of the output FIFO.
        unsigned OSGN : 1; //!< [1] Sign Extension Option of the output FIFO This bit will determine the sign extension option of the output FIFO.
        unsigned OMSB : 1; //!< [2] Data Alignment of the output FIFO This bit will determine the data alignment of the output FIFO.
        unsigned RESERVED0 : 5; //!< [7:3] Reserved. Should be written as zero for future compatibility.
        unsigned IMSB : 1; //!< [8] Data Alignment of the input FIFO This bit will determine the data alignment of the input FIFO.
        unsigned IWD : 3; //!< [11:9] Data Width of the input FIFO These three bits will determine the bitwidth for the audio data into ASRC All other settings not shown are reserved. 3'b000 24-bit audio data. 3'b001 16-bit audio data. 3'b010 8-bit audio data.
        unsigned RESERVED1 : 12; //!< [23:12] Reserved. Should be written as zero for future compatibility.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrmcr1a_t;
#endif

/*
 * constants & macros for entire ASRC_ASRMCR1A register
 */
#define HW_ASRC_ASRMCR1A_ADDR      (REGS_ASRC_BASE + 0xc0)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRMCR1A           (*(volatile hw_asrc_asrmcr1a_t *) HW_ASRC_ASRMCR1A_ADDR)
#define HW_ASRC_ASRMCR1A_RD()      (HW_ASRC_ASRMCR1A.U)
#define HW_ASRC_ASRMCR1A_WR(v)     (HW_ASRC_ASRMCR1A.U = (v))
#define HW_ASRC_ASRMCR1A_SET(v)    (HW_ASRC_ASRMCR1A_WR(HW_ASRC_ASRMCR1A_RD() |  (v)))
#define HW_ASRC_ASRMCR1A_CLR(v)    (HW_ASRC_ASRMCR1A_WR(HW_ASRC_ASRMCR1A_RD() & ~(v)))
#define HW_ASRC_ASRMCR1A_TOG(v)    (HW_ASRC_ASRMCR1A_WR(HW_ASRC_ASRMCR1A_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRMCR1A bitfields
 */

/* --- Register HW_ASRC_ASRMCR1A, field OW16[0] (RW)
 *
 * Bit Width Option of the output FIFO This bit will determine the bit width option of the output
 * FIFO.
 *
 * Values:
 * 0 - 24-bit output data.
 * 1 - 16-bit output data
 */

#define BP_ASRC_ASRMCR1A_OW16      (0)      //!< Bit position for ASRC_ASRMCR1A_OW16.
#define BM_ASRC_ASRMCR1A_OW16      (0x00000001)  //!< Bit mask for ASRC_ASRMCR1A_OW16.

//! @brief Get value of ASRC_ASRMCR1A_OW16 from a register value.
#define BG_ASRC_ASRMCR1A_OW16(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCR1A_OW16) >> BP_ASRC_ASRMCR1A_OW16)

//! @brief Format value for bitfield ASRC_ASRMCR1A_OW16.
#define BF_ASRC_ASRMCR1A_OW16(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCR1A_OW16) & BM_ASRC_ASRMCR1A_OW16)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OW16 field to a new value.
#define BW_ASRC_ASRMCR1A_OW16(v)   (HW_ASRC_ASRMCR1A_WR((HW_ASRC_ASRMCR1A_RD() & ~BM_ASRC_ASRMCR1A_OW16) | BF_ASRC_ASRMCR1A_OW16(v)))
#endif


/* --- Register HW_ASRC_ASRMCR1A, field OSGN[1] (RW)
 *
 * Sign Extension Option of the output FIFO This bit will determine the sign extension option of the
 * output FIFO.
 *
 * Values:
 * 0 - No sign extension.
 * 1 - Sign extension.
 */

#define BP_ASRC_ASRMCR1A_OSGN      (1)      //!< Bit position for ASRC_ASRMCR1A_OSGN.
#define BM_ASRC_ASRMCR1A_OSGN      (0x00000002)  //!< Bit mask for ASRC_ASRMCR1A_OSGN.

//! @brief Get value of ASRC_ASRMCR1A_OSGN from a register value.
#define BG_ASRC_ASRMCR1A_OSGN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCR1A_OSGN) >> BP_ASRC_ASRMCR1A_OSGN)

//! @brief Format value for bitfield ASRC_ASRMCR1A_OSGN.
#define BF_ASRC_ASRMCR1A_OSGN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCR1A_OSGN) & BM_ASRC_ASRMCR1A_OSGN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OSGN field to a new value.
#define BW_ASRC_ASRMCR1A_OSGN(v)   (HW_ASRC_ASRMCR1A_WR((HW_ASRC_ASRMCR1A_RD() & ~BM_ASRC_ASRMCR1A_OSGN) | BF_ASRC_ASRMCR1A_OSGN(v)))
#endif


/* --- Register HW_ASRC_ASRMCR1A, field OMSB[2] (RW)
 *
 * Data Alignment of the output FIFO This bit will determine the data alignment of the output FIFO.
 *
 * Values:
 * 0 - LSB aligned.
 * 1 - MSB aligned.
 */

#define BP_ASRC_ASRMCR1A_OMSB      (2)      //!< Bit position for ASRC_ASRMCR1A_OMSB.
#define BM_ASRC_ASRMCR1A_OMSB      (0x00000004)  //!< Bit mask for ASRC_ASRMCR1A_OMSB.

//! @brief Get value of ASRC_ASRMCR1A_OMSB from a register value.
#define BG_ASRC_ASRMCR1A_OMSB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCR1A_OMSB) >> BP_ASRC_ASRMCR1A_OMSB)

//! @brief Format value for bitfield ASRC_ASRMCR1A_OMSB.
#define BF_ASRC_ASRMCR1A_OMSB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCR1A_OMSB) & BM_ASRC_ASRMCR1A_OMSB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OMSB field to a new value.
#define BW_ASRC_ASRMCR1A_OMSB(v)   (HW_ASRC_ASRMCR1A_WR((HW_ASRC_ASRMCR1A_RD() & ~BM_ASRC_ASRMCR1A_OMSB) | BF_ASRC_ASRMCR1A_OMSB(v)))
#endif


/* --- Register HW_ASRC_ASRMCR1A, field IMSB[8] (RW)
 *
 * Data Alignment of the input FIFO This bit will determine the data alignment of the input FIFO.
 *
 * Values:
 * 0 - LSB aligned.
 * 1 - MSB aligned.
 */

#define BP_ASRC_ASRMCR1A_IMSB      (8)      //!< Bit position for ASRC_ASRMCR1A_IMSB.
#define BM_ASRC_ASRMCR1A_IMSB      (0x00000100)  //!< Bit mask for ASRC_ASRMCR1A_IMSB.

//! @brief Get value of ASRC_ASRMCR1A_IMSB from a register value.
#define BG_ASRC_ASRMCR1A_IMSB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCR1A_IMSB) >> BP_ASRC_ASRMCR1A_IMSB)

//! @brief Format value for bitfield ASRC_ASRMCR1A_IMSB.
#define BF_ASRC_ASRMCR1A_IMSB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCR1A_IMSB) & BM_ASRC_ASRMCR1A_IMSB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IMSB field to a new value.
#define BW_ASRC_ASRMCR1A_IMSB(v)   (HW_ASRC_ASRMCR1A_WR((HW_ASRC_ASRMCR1A_RD() & ~BM_ASRC_ASRMCR1A_IMSB) | BF_ASRC_ASRMCR1A_IMSB(v)))
#endif


/* --- Register HW_ASRC_ASRMCR1A, field IWD[11:9] (RW)
 *
 * Data Width of the input FIFO These three bits will determine the bitwidth for the audio data into
 * ASRC All other settings not shown are reserved. 3'b000 24-bit audio data. 3'b001 16-bit audio
 * data. 3'b010 8-bit audio data.
 */

#define BP_ASRC_ASRMCR1A_IWD      (9)      //!< Bit position for ASRC_ASRMCR1A_IWD.
#define BM_ASRC_ASRMCR1A_IWD      (0x00000e00)  //!< Bit mask for ASRC_ASRMCR1A_IWD.

//! @brief Get value of ASRC_ASRMCR1A_IWD from a register value.
#define BG_ASRC_ASRMCR1A_IWD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCR1A_IWD) >> BP_ASRC_ASRMCR1A_IWD)

//! @brief Format value for bitfield ASRC_ASRMCR1A_IWD.
#define BF_ASRC_ASRMCR1A_IWD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCR1A_IWD) & BM_ASRC_ASRMCR1A_IWD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IWD field to a new value.
#define BW_ASRC_ASRMCR1A_IWD(v)   (HW_ASRC_ASRMCR1A_WR((HW_ASRC_ASRMCR1A_RD() & ~BM_ASRC_ASRMCR1A_IWD) | BF_ASRC_ASRMCR1A_IWD(v)))
#endif

/* --- Register HW_ASRC_ASRMCR1A, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRMCR1A_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRMCR1A_UNIMPLEMENTED.
#define BM_ASRC_ASRMCR1A_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRMCR1A_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRMCR1A_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRMCR1A_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCR1A_UNIMPLEMENTED) >> BP_ASRC_ASRMCR1A_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRMCR1B - ASRC Misc Control Register 1 for Pair X
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRMCR1B - ASRC Misc Control Register 1 for Pair X (RW)
 *
 * Reset value: 0x00000000
 *
 * The register (ASRMCR1A) is used to control Pair x internal logic (for data alignment etc.).  The
 * bit assignment for all the input data formats is the same as that supported by the SSI.
 */
typedef union _hw_asrc_asrmcr1b
{
    reg32_t U;
    struct _hw_asrc_asrmcr1b_bitfields
    {
        unsigned OW16 : 1; //!< [0] Bit Width Option of the output FIFO This bit will determine the bit width option of the output FIFO.
        unsigned OSGN : 1; //!< [1] Sign Extension Option of the output FIFO This bit will determine the sign extension option of the output FIFO.
        unsigned OMSB : 1; //!< [2] Data Alignment of the output FIFO This bit will determine the data alignment of the output FIFO.
        unsigned RESERVED0 : 5; //!< [7:3] Reserved. Should be written as zero for future compatibility.
        unsigned IMSB : 1; //!< [8] Data Alignment of the input FIFO This bit will determine the data alignment of the input FIFO.
        unsigned IWD : 3; //!< [11:9] Data Width of the input FIFO These three bits will determine the bitwidth for the audio data into ASRC All other settings not shown are reserved. 3'b000 24-bit audio data. 3'b001 16-bit audio data. 3'b010 8-bit audio data.
        unsigned RESERVED1 : 12; //!< [23:12] Reserved. Should be written as zero for future compatibility.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrmcr1b_t;
#endif

/*
 * constants & macros for entire ASRC_ASRMCR1B register
 */
#define HW_ASRC_ASRMCR1B_ADDR      (REGS_ASRC_BASE + 0xc4)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRMCR1B           (*(volatile hw_asrc_asrmcr1b_t *) HW_ASRC_ASRMCR1B_ADDR)
#define HW_ASRC_ASRMCR1B_RD()      (HW_ASRC_ASRMCR1B.U)
#define HW_ASRC_ASRMCR1B_WR(v)     (HW_ASRC_ASRMCR1B.U = (v))
#define HW_ASRC_ASRMCR1B_SET(v)    (HW_ASRC_ASRMCR1B_WR(HW_ASRC_ASRMCR1B_RD() |  (v)))
#define HW_ASRC_ASRMCR1B_CLR(v)    (HW_ASRC_ASRMCR1B_WR(HW_ASRC_ASRMCR1B_RD() & ~(v)))
#define HW_ASRC_ASRMCR1B_TOG(v)    (HW_ASRC_ASRMCR1B_WR(HW_ASRC_ASRMCR1B_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRMCR1B bitfields
 */

/* --- Register HW_ASRC_ASRMCR1B, field OW16[0] (RW)
 *
 * Bit Width Option of the output FIFO This bit will determine the bit width option of the output
 * FIFO.
 *
 * Values:
 * 0 - 24-bit output data.
 * 1 - 16-bit output data
 */

#define BP_ASRC_ASRMCR1B_OW16      (0)      //!< Bit position for ASRC_ASRMCR1B_OW16.
#define BM_ASRC_ASRMCR1B_OW16      (0x00000001)  //!< Bit mask for ASRC_ASRMCR1B_OW16.

//! @brief Get value of ASRC_ASRMCR1B_OW16 from a register value.
#define BG_ASRC_ASRMCR1B_OW16(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCR1B_OW16) >> BP_ASRC_ASRMCR1B_OW16)

//! @brief Format value for bitfield ASRC_ASRMCR1B_OW16.
#define BF_ASRC_ASRMCR1B_OW16(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCR1B_OW16) & BM_ASRC_ASRMCR1B_OW16)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OW16 field to a new value.
#define BW_ASRC_ASRMCR1B_OW16(v)   (HW_ASRC_ASRMCR1B_WR((HW_ASRC_ASRMCR1B_RD() & ~BM_ASRC_ASRMCR1B_OW16) | BF_ASRC_ASRMCR1B_OW16(v)))
#endif


/* --- Register HW_ASRC_ASRMCR1B, field OSGN[1] (RW)
 *
 * Sign Extension Option of the output FIFO This bit will determine the sign extension option of the
 * output FIFO.
 *
 * Values:
 * 0 - No sign extension.
 * 1 - Sign extension.
 */

#define BP_ASRC_ASRMCR1B_OSGN      (1)      //!< Bit position for ASRC_ASRMCR1B_OSGN.
#define BM_ASRC_ASRMCR1B_OSGN      (0x00000002)  //!< Bit mask for ASRC_ASRMCR1B_OSGN.

//! @brief Get value of ASRC_ASRMCR1B_OSGN from a register value.
#define BG_ASRC_ASRMCR1B_OSGN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCR1B_OSGN) >> BP_ASRC_ASRMCR1B_OSGN)

//! @brief Format value for bitfield ASRC_ASRMCR1B_OSGN.
#define BF_ASRC_ASRMCR1B_OSGN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCR1B_OSGN) & BM_ASRC_ASRMCR1B_OSGN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OSGN field to a new value.
#define BW_ASRC_ASRMCR1B_OSGN(v)   (HW_ASRC_ASRMCR1B_WR((HW_ASRC_ASRMCR1B_RD() & ~BM_ASRC_ASRMCR1B_OSGN) | BF_ASRC_ASRMCR1B_OSGN(v)))
#endif


/* --- Register HW_ASRC_ASRMCR1B, field OMSB[2] (RW)
 *
 * Data Alignment of the output FIFO This bit will determine the data alignment of the output FIFO.
 *
 * Values:
 * 0 - LSB aligned.
 * 1 - MSB aligned.
 */

#define BP_ASRC_ASRMCR1B_OMSB      (2)      //!< Bit position for ASRC_ASRMCR1B_OMSB.
#define BM_ASRC_ASRMCR1B_OMSB      (0x00000004)  //!< Bit mask for ASRC_ASRMCR1B_OMSB.

//! @brief Get value of ASRC_ASRMCR1B_OMSB from a register value.
#define BG_ASRC_ASRMCR1B_OMSB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCR1B_OMSB) >> BP_ASRC_ASRMCR1B_OMSB)

//! @brief Format value for bitfield ASRC_ASRMCR1B_OMSB.
#define BF_ASRC_ASRMCR1B_OMSB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCR1B_OMSB) & BM_ASRC_ASRMCR1B_OMSB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OMSB field to a new value.
#define BW_ASRC_ASRMCR1B_OMSB(v)   (HW_ASRC_ASRMCR1B_WR((HW_ASRC_ASRMCR1B_RD() & ~BM_ASRC_ASRMCR1B_OMSB) | BF_ASRC_ASRMCR1B_OMSB(v)))
#endif


/* --- Register HW_ASRC_ASRMCR1B, field IMSB[8] (RW)
 *
 * Data Alignment of the input FIFO This bit will determine the data alignment of the input FIFO.
 *
 * Values:
 * 0 - LSB aligned.
 * 1 - MSB aligned.
 */

#define BP_ASRC_ASRMCR1B_IMSB      (8)      //!< Bit position for ASRC_ASRMCR1B_IMSB.
#define BM_ASRC_ASRMCR1B_IMSB      (0x00000100)  //!< Bit mask for ASRC_ASRMCR1B_IMSB.

//! @brief Get value of ASRC_ASRMCR1B_IMSB from a register value.
#define BG_ASRC_ASRMCR1B_IMSB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCR1B_IMSB) >> BP_ASRC_ASRMCR1B_IMSB)

//! @brief Format value for bitfield ASRC_ASRMCR1B_IMSB.
#define BF_ASRC_ASRMCR1B_IMSB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCR1B_IMSB) & BM_ASRC_ASRMCR1B_IMSB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IMSB field to a new value.
#define BW_ASRC_ASRMCR1B_IMSB(v)   (HW_ASRC_ASRMCR1B_WR((HW_ASRC_ASRMCR1B_RD() & ~BM_ASRC_ASRMCR1B_IMSB) | BF_ASRC_ASRMCR1B_IMSB(v)))
#endif


/* --- Register HW_ASRC_ASRMCR1B, field IWD[11:9] (RW)
 *
 * Data Width of the input FIFO These three bits will determine the bitwidth for the audio data into
 * ASRC All other settings not shown are reserved. 3'b000 24-bit audio data. 3'b001 16-bit audio
 * data. 3'b010 8-bit audio data.
 */

#define BP_ASRC_ASRMCR1B_IWD      (9)      //!< Bit position for ASRC_ASRMCR1B_IWD.
#define BM_ASRC_ASRMCR1B_IWD      (0x00000e00)  //!< Bit mask for ASRC_ASRMCR1B_IWD.

//! @brief Get value of ASRC_ASRMCR1B_IWD from a register value.
#define BG_ASRC_ASRMCR1B_IWD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCR1B_IWD) >> BP_ASRC_ASRMCR1B_IWD)

//! @brief Format value for bitfield ASRC_ASRMCR1B_IWD.
#define BF_ASRC_ASRMCR1B_IWD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCR1B_IWD) & BM_ASRC_ASRMCR1B_IWD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IWD field to a new value.
#define BW_ASRC_ASRMCR1B_IWD(v)   (HW_ASRC_ASRMCR1B_WR((HW_ASRC_ASRMCR1B_RD() & ~BM_ASRC_ASRMCR1B_IWD) | BF_ASRC_ASRMCR1B_IWD(v)))
#endif

/* --- Register HW_ASRC_ASRMCR1B, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRMCR1B_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRMCR1B_UNIMPLEMENTED.
#define BM_ASRC_ASRMCR1B_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRMCR1B_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRMCR1B_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRMCR1B_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCR1B_UNIMPLEMENTED) >> BP_ASRC_ASRMCR1B_UNIMPLEMENTED)

//-------------------------------------------------------------------------------------------
// HW_ASRC_ASRMCR1C - ASRC Misc Control Register 1 for Pair X
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ASRC_ASRMCR1C - ASRC Misc Control Register 1 for Pair X (RW)
 *
 * Reset value: 0x00000000
 *
 * The register (ASRMCR1A) is used to control Pair x internal logic (for data alignment etc.).  The
 * bit assignment for all the input data formats is the same as that supported by the SSI.
 */
typedef union _hw_asrc_asrmcr1c
{
    reg32_t U;
    struct _hw_asrc_asrmcr1c_bitfields
    {
        unsigned OW16 : 1; //!< [0] Bit Width Option of the output FIFO This bit will determine the bit width option of the output FIFO.
        unsigned OSGN : 1; //!< [1] Sign Extension Option of the output FIFO This bit will determine the sign extension option of the output FIFO.
        unsigned OMSB : 1; //!< [2] Data Alignment of the output FIFO This bit will determine the data alignment of the output FIFO.
        unsigned RESERVED0 : 5; //!< [7:3] Reserved. Should be written as zero for future compatibility.
        unsigned IMSB : 1; //!< [8] Data Alignment of the input FIFO This bit will determine the data alignment of the input FIFO.
        unsigned IWD : 3; //!< [11:9] Data Width of the input FIFO These three bits will determine the bitwidth for the audio data into ASRC All other settings not shown are reserved. 3'b000 24-bit audio data. 3'b001 16-bit audio data. 3'b010 8-bit audio data.
        unsigned RESERVED1 : 12; //!< [23:12] Reserved. Should be written as zero for future compatibility.
        unsigned UNIMPLEMENTED : 8; //!< [31:24] 
    } B;
} hw_asrc_asrmcr1c_t;
#endif

/*
 * constants & macros for entire ASRC_ASRMCR1C register
 */
#define HW_ASRC_ASRMCR1C_ADDR      (REGS_ASRC_BASE + 0xc8)

#ifndef __LANGUAGE_ASM__
#define HW_ASRC_ASRMCR1C           (*(volatile hw_asrc_asrmcr1c_t *) HW_ASRC_ASRMCR1C_ADDR)
#define HW_ASRC_ASRMCR1C_RD()      (HW_ASRC_ASRMCR1C.U)
#define HW_ASRC_ASRMCR1C_WR(v)     (HW_ASRC_ASRMCR1C.U = (v))
#define HW_ASRC_ASRMCR1C_SET(v)    (HW_ASRC_ASRMCR1C_WR(HW_ASRC_ASRMCR1C_RD() |  (v)))
#define HW_ASRC_ASRMCR1C_CLR(v)    (HW_ASRC_ASRMCR1C_WR(HW_ASRC_ASRMCR1C_RD() & ~(v)))
#define HW_ASRC_ASRMCR1C_TOG(v)    (HW_ASRC_ASRMCR1C_WR(HW_ASRC_ASRMCR1C_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ASRC_ASRMCR1C bitfields
 */

/* --- Register HW_ASRC_ASRMCR1C, field OW16[0] (RW)
 *
 * Bit Width Option of the output FIFO This bit will determine the bit width option of the output
 * FIFO.
 *
 * Values:
 * 0 - 24-bit output data.
 * 1 - 16-bit output data
 */

#define BP_ASRC_ASRMCR1C_OW16      (0)      //!< Bit position for ASRC_ASRMCR1C_OW16.
#define BM_ASRC_ASRMCR1C_OW16      (0x00000001)  //!< Bit mask for ASRC_ASRMCR1C_OW16.

//! @brief Get value of ASRC_ASRMCR1C_OW16 from a register value.
#define BG_ASRC_ASRMCR1C_OW16(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCR1C_OW16) >> BP_ASRC_ASRMCR1C_OW16)

//! @brief Format value for bitfield ASRC_ASRMCR1C_OW16.
#define BF_ASRC_ASRMCR1C_OW16(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCR1C_OW16) & BM_ASRC_ASRMCR1C_OW16)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OW16 field to a new value.
#define BW_ASRC_ASRMCR1C_OW16(v)   (HW_ASRC_ASRMCR1C_WR((HW_ASRC_ASRMCR1C_RD() & ~BM_ASRC_ASRMCR1C_OW16) | BF_ASRC_ASRMCR1C_OW16(v)))
#endif


/* --- Register HW_ASRC_ASRMCR1C, field OSGN[1] (RW)
 *
 * Sign Extension Option of the output FIFO This bit will determine the sign extension option of the
 * output FIFO.
 *
 * Values:
 * 0 - No sign extension.
 * 1 - Sign extension.
 */

#define BP_ASRC_ASRMCR1C_OSGN      (1)      //!< Bit position for ASRC_ASRMCR1C_OSGN.
#define BM_ASRC_ASRMCR1C_OSGN      (0x00000002)  //!< Bit mask for ASRC_ASRMCR1C_OSGN.

//! @brief Get value of ASRC_ASRMCR1C_OSGN from a register value.
#define BG_ASRC_ASRMCR1C_OSGN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCR1C_OSGN) >> BP_ASRC_ASRMCR1C_OSGN)

//! @brief Format value for bitfield ASRC_ASRMCR1C_OSGN.
#define BF_ASRC_ASRMCR1C_OSGN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCR1C_OSGN) & BM_ASRC_ASRMCR1C_OSGN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OSGN field to a new value.
#define BW_ASRC_ASRMCR1C_OSGN(v)   (HW_ASRC_ASRMCR1C_WR((HW_ASRC_ASRMCR1C_RD() & ~BM_ASRC_ASRMCR1C_OSGN) | BF_ASRC_ASRMCR1C_OSGN(v)))
#endif


/* --- Register HW_ASRC_ASRMCR1C, field OMSB[2] (RW)
 *
 * Data Alignment of the output FIFO This bit will determine the data alignment of the output FIFO.
 *
 * Values:
 * 0 - LSB aligned.
 * 1 - MSB aligned.
 */

#define BP_ASRC_ASRMCR1C_OMSB      (2)      //!< Bit position for ASRC_ASRMCR1C_OMSB.
#define BM_ASRC_ASRMCR1C_OMSB      (0x00000004)  //!< Bit mask for ASRC_ASRMCR1C_OMSB.

//! @brief Get value of ASRC_ASRMCR1C_OMSB from a register value.
#define BG_ASRC_ASRMCR1C_OMSB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCR1C_OMSB) >> BP_ASRC_ASRMCR1C_OMSB)

//! @brief Format value for bitfield ASRC_ASRMCR1C_OMSB.
#define BF_ASRC_ASRMCR1C_OMSB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCR1C_OMSB) & BM_ASRC_ASRMCR1C_OMSB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OMSB field to a new value.
#define BW_ASRC_ASRMCR1C_OMSB(v)   (HW_ASRC_ASRMCR1C_WR((HW_ASRC_ASRMCR1C_RD() & ~BM_ASRC_ASRMCR1C_OMSB) | BF_ASRC_ASRMCR1C_OMSB(v)))
#endif


/* --- Register HW_ASRC_ASRMCR1C, field IMSB[8] (RW)
 *
 * Data Alignment of the input FIFO This bit will determine the data alignment of the input FIFO.
 *
 * Values:
 * 0 - LSB aligned.
 * 1 - MSB aligned.
 */

#define BP_ASRC_ASRMCR1C_IMSB      (8)      //!< Bit position for ASRC_ASRMCR1C_IMSB.
#define BM_ASRC_ASRMCR1C_IMSB      (0x00000100)  //!< Bit mask for ASRC_ASRMCR1C_IMSB.

//! @brief Get value of ASRC_ASRMCR1C_IMSB from a register value.
#define BG_ASRC_ASRMCR1C_IMSB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCR1C_IMSB) >> BP_ASRC_ASRMCR1C_IMSB)

//! @brief Format value for bitfield ASRC_ASRMCR1C_IMSB.
#define BF_ASRC_ASRMCR1C_IMSB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCR1C_IMSB) & BM_ASRC_ASRMCR1C_IMSB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IMSB field to a new value.
#define BW_ASRC_ASRMCR1C_IMSB(v)   (HW_ASRC_ASRMCR1C_WR((HW_ASRC_ASRMCR1C_RD() & ~BM_ASRC_ASRMCR1C_IMSB) | BF_ASRC_ASRMCR1C_IMSB(v)))
#endif


/* --- Register HW_ASRC_ASRMCR1C, field IWD[11:9] (RW)
 *
 * Data Width of the input FIFO These three bits will determine the bitwidth for the audio data into
 * ASRC All other settings not shown are reserved. 3'b000 24-bit audio data. 3'b001 16-bit audio
 * data. 3'b010 8-bit audio data.
 */

#define BP_ASRC_ASRMCR1C_IWD      (9)      //!< Bit position for ASRC_ASRMCR1C_IWD.
#define BM_ASRC_ASRMCR1C_IWD      (0x00000e00)  //!< Bit mask for ASRC_ASRMCR1C_IWD.

//! @brief Get value of ASRC_ASRMCR1C_IWD from a register value.
#define BG_ASRC_ASRMCR1C_IWD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCR1C_IWD) >> BP_ASRC_ASRMCR1C_IWD)

//! @brief Format value for bitfield ASRC_ASRMCR1C_IWD.
#define BF_ASRC_ASRMCR1C_IWD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ASRC_ASRMCR1C_IWD) & BM_ASRC_ASRMCR1C_IWD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IWD field to a new value.
#define BW_ASRC_ASRMCR1C_IWD(v)   (HW_ASRC_ASRMCR1C_WR((HW_ASRC_ASRMCR1C_RD() & ~BM_ASRC_ASRMCR1C_IWD) | BF_ASRC_ASRMCR1C_IWD(v)))
#endif

/* --- Register HW_ASRC_ASRMCR1C, field UNIMPLEMENTED[31:24] (RU)
 *

 */

#define BP_ASRC_ASRMCR1C_UNIMPLEMENTED      (24)      //!< Bit position for ASRC_ASRMCR1C_UNIMPLEMENTED.
#define BM_ASRC_ASRMCR1C_UNIMPLEMENTED      (0xff000000)  //!< Bit mask for ASRC_ASRMCR1C_UNIMPLEMENTED.

//! @brief Get value of ASRC_ASRMCR1C_UNIMPLEMENTED from a register value.
#define BG_ASRC_ASRMCR1C_UNIMPLEMENTED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ASRC_ASRMCR1C_UNIMPLEMENTED) >> BP_ASRC_ASRMCR1C_UNIMPLEMENTED)


/*!
 * @brief All ASRC module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_asrc
{
    volatile hw_asrc_asrctr_t ASRCTR; //!< ASRC Control Register
    volatile hw_asrc_asrier_t ASRIER; //!< ASRC Interrupt Enable Register
    reg32_t _reserved0;
    volatile hw_asrc_asrcncr_t ASRCNCR; //!< ASRC Channel Number Configuration Register
    volatile hw_asrc_asrcfg_t ASRCFG; //!< ASRC Filter Configuration Status Register
    volatile hw_asrc_asrcsr_t ASRCSR; //!< ASRC Clock Source Register
    volatile hw_asrc_asrcdr1_t ASRCDR1; //!< ASRC Clock Divider Register 1
    volatile hw_asrc_asrcdr2_t ASRCDR2; //!< ASRC Clock Divider Register 2
    volatile hw_asrc_asrstr_t ASRSTR; //!< ASRC Status Register
    reg32_t _reserved1[7];
    volatile hw_asrc_asrpmn1_t ASRPMN1; //!< ASRC Parameter Register n
    volatile hw_asrc_asrpmn2_t ASRPMN2; //!< ASRC Parameter Register n
    volatile hw_asrc_asrpmn3_t ASRPMN3; //!< ASRC Parameter Register n
    volatile hw_asrc_asrpmn4_t ASRPMN4; //!< ASRC Parameter Register n
    volatile hw_asrc_asrpmn5_t ASRPMN5; //!< ASRC Parameter Register n
    volatile hw_asrc_asrtfr1_t ASRTFR1; //!< ASRC ASRC Task Queue FIFO Register 1
    reg32_t _reserved2;
    volatile hw_asrc_asrccr_t ASRCCR; //!< ASRC Channel Counter Register
    volatile hw_asrc_asrdia_t ASRDIA; //!< ASRC Data Input Register for Pair
    volatile hw_asrc_asrdoa_t ASRDOA; //!< ASRC Data Output Register for Pair
    volatile hw_asrc_asrdib_t ASRDIB; //!< ASRC Data Input Register for Pair
    volatile hw_asrc_asrdob_t ASRDOB; //!< ASRC Data Output Register for Pair
    volatile hw_asrc_asrdic_t ASRDIC; //!< ASRC Data Input Register for Pair
    volatile hw_asrc_asrdoc_t ASRDOC; //!< ASRC Data Output Register for Pair
    reg32_t _reserved3[2];
    volatile hw_asrc_asridrha_t ASRIDRHA; //!< ASRC Ideal Ratio for Pair A-High Part
    volatile hw_asrc_asridrla_t ASRIDRLA; //!< ASRC Ideal Ratio for Pair A -Low Part
    volatile hw_asrc_asridrhb_t ASRIDRHB; //!< ASRC Ideal Ratio for Pair B-High Part
    volatile hw_asrc_asridrlb_t ASRIDRLB; //!< ASRC Ideal Ratio for Pair B-Low Part
    volatile hw_asrc_asridrhc_t ASRIDRHC; //!< ASRC Ideal Ratio for Pair C-High Part
    volatile hw_asrc_asridrlc_t ASRIDRLC; //!< ASRC Ideal Ratio for Pair C-Low Part
    volatile hw_asrc_asr76k_t ASR76K; //!< ASRC 76kHz Period in terms of ASRC processing clock
    volatile hw_asrc_asr56k_t ASR56K; //!< ASRC 56kHz Period in terms of ASRC processing clock
    volatile hw_asrc_asrmcra_t ASRMCRA; //!< ASRC Misc Control Register for Pair A
    volatile hw_asrc_asrfsta_t ASRFSTA; //!< ASRC FIFO Status Register for Pair A
    volatile hw_asrc_asrmcrb_t ASRMCRB; //!< ASRC Misc Control Register for Pair B
    volatile hw_asrc_asrfstb_t ASRFSTB; //!< ASRC FIFO Status Register for Pair B
    volatile hw_asrc_asrmcrc_t ASRMCRC; //!< ASRC Misc Control Register for Pair C
    volatile hw_asrc_asrfstc_t ASRFSTC; //!< ASRC FIFO Status Register for Pair C
    reg32_t _reserved4[2];
    volatile hw_asrc_asrmcr1a_t ASRMCR1A; //!< ASRC Misc Control Register 1 for Pair X
    volatile hw_asrc_asrmcr1b_t ASRMCR1B; //!< ASRC Misc Control Register 1 for Pair X
    volatile hw_asrc_asrmcr1c_t ASRMCR1C; //!< ASRC Misc Control Register 1 for Pair X
} hw_asrc_t;
#pragma pack()

//! @brief Macro to access all ASRC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_ASRC(0)</code>.
#define HW_ASRC     (*(volatile hw_asrc_t *) REGS_ASRC_BASE)

#endif


#endif // __HW_ASRC_REGISTERS_H__
