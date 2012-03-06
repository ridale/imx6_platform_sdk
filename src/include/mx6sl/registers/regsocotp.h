/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _OCOTP_H
#define _OCOTP_H

#include "regs.h"

/*
 * i.MX6SL OCOTP registers defined in this header file.
 *
 * - HW_OCOTP_HW_OCOTP_CTRL - OTP Controller Control Register
 * - HW_OCOTP_HW_OCOTP_TIMING - OTP Controller Timing Register
 * - HW_OCOTP_HW_OCOTP_DATA - OTP Controller Write Data Register
 * - HW_OCOTP_HW_OCOTP_READ_CTRL - OTP Controller Write Data Register
 * - HW_OCOTP_HW_OCOTP_READ_FUSE_DATA - OTP Controller Read Data Register
 * - HW_OCOTP_HW_OCOTP_SW_STICKY - Sticky bit Register
 * - HW_OCOTP_HW_OCOTP_SCS - Software Controllable Signals Register
 * - HW_OCOTP_HW_OCOTP_CRC_ADDR - OTP Controller CRC test address
 * - HW_OCOTP_HW_OCOTP_CRC_VALUE - OTP Controller CRC Value Register
 * - HW_OCOTP_HW_OCOTP_UMC_TIMING - OTP Controller Timing Register
 * - HW_OCOTP_HW_OCOTP_VERSION - OTP Controller Version Register
 * - HW_OCOTP_HW_OCOTP_LOCK - Value of OTP Bank0 Word0 (Lock controls)
 * - HW_OCOTP_HW_OCOTP_CFG0 - Value of OTP Bank0 Word1 (Configuration and Manufacturing Info.)
 * - HW_OCOTP_HW_OCOTP_CFG1 - Value of OTP Bank0 Word2 (Configuration and Manufacturing Info.)
 * - HW_OCOTP_HW_OCOTP_CFG2 - Value of OTP Bank0 Word3 (Configuration and Manufacturing Info.)
 * - HW_OCOTP_HW_OCOTP_CFG3 - Value of OTP Bank0 Word4 (Configuration and Manufacturing Info.)
 * - HW_OCOTP_HW_OCOTP_CFG4 - Value of OTP Bank0 Word5 (Configuration and Manufacturing Info.)
 * - HW_OCOTP_HW_OCOTP_CFG5 - Value of OTP Bank0 Word6 (Configuration and Manufacturing Info.)
 * - HW_OCOTP_HW_OCOTP_CFG6 - Value of OTP Bank0 Word7 (Configuration and Manufacturing Info.)
 * - HW_OCOTP_HW_OCOTP_MEM0 - Value of OTP Bank1 Word0 (Memory Related Info.)
 * - HW_OCOTP_HW_OCOTP_MEM1 - Value of OTP Bank1 Word1 (Memory Related Info.)
 * - HW_OCOTP_HW_OCOTP_MEM2 - Value of OTP Bank1 Word2 (Memory Related Info.)
 * - HW_OCOTP_HW_OCOTP_MEM3 - Value of OTP Bank1 Word3 (Memory Related Info.)
 * - HW_OCOTP_HW_OCOTP_MEM4 - Value of OTP Bank1 Word4 (Memory Related Info.)
 * - HW_OCOTP_HW_OCOTP_ANA0 - Value of OTP Bank1 Word5 (Memory Related Info.)
 * - HW_OCOTP_HW_OCOTP_ANA1 - Value of OTP Bank1 Word6 (General Purpose Customer Defined Info.)
 * - HW_OCOTP_HW_OCOTP_ANA2 - Value of OTP Bank1 Word7 (General Purpose Customer Defined Info.)
 * - HW_OCOTP_HW_OCOTP_DCP0 - Shadow Register for OTP Bank2 Word0 (DCP and CRYPTO Key)
 * - HW_OCOTP_HW_OCOTP_DCP1 - Shadow Register for OTP Bank2 Word1 (DCP and CRYPTO Key)
 * - HW_OCOTP_HW_OCOTP_DCP2 - Shadow Register for OTP Bank2 Word2 (DCP and CRYPTO Key)
 * - HW_OCOTP_HW_OCOTP_DCP3 - Shadow Register for OTP Bank2 Word3 (DCP and CRYPTO Key)
 * - HW_OCOTP_HW_OCOTP_DCP4 - Shadow Register for OTP Bank2 Word4 (DCP Key)
 * - HW_OCOTP_HW_OCOTP_DCP5 - Shadow Register for OTP Bank2 Word5 (DCP Key)
 * - HW_OCOTP_HW_OCOTP_DCP6 - Shadow Register for OTP Bank2 Word6 (DCP Key)
 * - HW_OCOTP_HW_OCOTP_DCP7 - Shadow Register for OTP Bank2 Word7 (DCP Key)
 * - HW_OCOTP_HW_OCOTP_SRK0 - Shadow Register for OTP Bank3 Word0 (SRK Hash)
 * - HW_OCOTP_HW_OCOTP_SRK1 - Shadow Register for OTP Bank3 Word1 (SRK Hash)
 * - HW_OCOTP_HW_OCOTP_SRK2 - Shadow Register for OTP Bank3 Word2 (SRK Hash)
 * - HW_OCOTP_HW_OCOTP_SRK3 - Shadow Register for OTP Bank3 Word3 (SRK Hash)
 * - HW_OCOTP_HW_OCOTP_SRK4 - Shadow Register for OTP Bank3 Word4 (SRK Hash)
 * - HW_OCOTP_HW_OCOTP_SRK5 - Shadow Register for OTP Bank3 Word5 (SRK Hash)
 * - HW_OCOTP_HW_OCOTP_SRK6 - Shadow Register for OTP Bank3 Word6 (SRK Hash)
 * - HW_OCOTP_HW_OCOTP_SRK7 - Shadow Register for OTP Bank3 Word7 (SRK Hash)
 * - HW_OCOTP_HW_OCOTP_SJC_RESP0 - Value of OTP Bank4 Word0 (Secure JTAG Response Field)
 * - HW_OCOTP_HW_OCOTP_SJC_RESP1 - Value of OTP Bank4 Word1 (Secure JTAG Response Field)
 * - HW_OCOTP_HW_OCOTP_MAC0 - Value of OTP Bank4 Word2 (MAC Address)
 * - HW_OCOTP_HW_OCOTP_MAC1 - Value of OTP Bank4 Word3 (MAC Address)
 * - HW_OCOTP_HW_OCOTP_CRC0 - Value of OTP Bank4 Word4 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_CRC1 - Value of OTP Bank4 Word5 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_GP1 - Value of OTP Bank4 Word6 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_GP2 - Value of OTP Bank4 Word7 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_SW_GP0 - Value of OTP Bank5 Word0 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_SW_GP1 - Value of OTP Bank5 Word1 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_SW_GP2 - Value of OTP Bank5 Word2 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_SW_GP3 - Value of OTP Bank5 Word3 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_SW_GP4 - Value of OTP Bank5 Word4 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_MISC_CONF - Value of OTP Bank5 Word5 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_FIELD_RETURN - Value of OTP Bank5 Word6 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_SRK_REVOKE - Value of OTP Bank5 Word7 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_GP_LO0 - Value of OTP Bank6 Word0 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_GP_LO1 - Value of OTP Bank6 Word1 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_GP_LO2 - Value of OTP Bank6 Word2 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_GP_LO3 - Value of OTP Bank6 Word3 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_GP_LO4 - Value of OTP Bank6 Word4 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_GP_LO5 - Value of OTP Bank6 Word5 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_GP_LO6 - Value of OTP Bank6 Word6 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_GP_LO7 - Value of OTP Bank6 Word7 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_GP_HI0 - Value of OTP Bank7 Word0 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_GP_HI1 - Value of OTP Bank7 Word1 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_GP_HI2 - Value of OTP Bank7 Word2 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_GP_HI3 - Value of OTP Bank7 Word3 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_GP_HI4 - Value of OTP Bank7 Word4 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_GP_HI5 - Value of OTP Bank7 Word5 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_GP_HI6 - Value of OTP Bank7 Word6 (HW Capabilities)
 * - HW_OCOTP_HW_OCOTP_GP_HI7 - Value of OTP Bank7 Word7 (HW Capabilities)
 *
 * hw_ocotp_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_OCOTP_BASE
#define REGS_OCOTP_BASE (0x021bc000) //!< Base address for OCOTP.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_CTRL - OTP Controller Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The OCOTP Control and Status Register specifies the copy state, as well as the control required
 * for random access of the OTP memory  HW_OCOTP_CTRL: 0x000  HW_OCOTP_CTRL_SET: 0x004
 * HW_OCOTP_CTRL_CLR: 0x008  HW_OCOTP_CTRL_TOG: 0x00C  The OCOTP Control and Status Register
 * provides the necessary software interface for performing read and write operations to the On-Chip
 * OTP (One-Time Programmable ROM). The control fields such as WR_UNLOCK, ADDR and BUSY/ERROR may be
 * used in conjuction with the HW_OCOTP_DATA register to perform write operations. Read operations
 * to the On-Chip OTP are involving ADDR, BUSY/ERROR bit field and HW_OCOTP_READ_CTRL register. Read
 * value is saved in HW_OCOTP_READ_FUSE_DATA register.   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_ctrl
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_ctrl_bitfields
    {
        unsigned ADDR : 6; //!< [5:0] OTP write and read access address register. Specifies one of 64 word address locations (0x00 - 0x3f). If a valid access is accepted by the controller, the controller makes an internal copy of this value. This internal copy will not update until the access is complete.
        unsigned RESERVED0 : 2; //!< [7:6] Reserved
        unsigned BUSY : 1; //!< [8] OTP controller status bit. When active, no new write access or read access to OTP(including RELOAD_SHADOWS) can be performed. Cleared by controller when access complete. After reset (or after setting RELOAD_SHADOWS), this bit is set by the controller until the HW/SW and LOCK registers are successfully copied, after which time it is automatically cleared by the controller.
        unsigned ERROR : 1; //!< [9] Set by the controller when an access to a locked region(OTP or shadow register) is requested. Must be cleared before any further access can be performed. This bit can only be set by the controller. This bit is also set if the Pin interface is active and software requests an access to the OTP. In this instance, the ERROR bit cannot be cleared until the Pin interface access has completed. Reset this bit by writing a one to the SCT clear address space and not by a general write.
        unsigned RELOAD_SHADOWS : 1; //!< [10] Set to force re-loading the shadow registers (HW/SW capability and LOCK). This operation will automatically set BUSY. Once the shadow registers have been re-loaded, BUSY and RELOAD_SHADOWS are automatically cleared by the controller.
        unsigned CRC_TEST : 1; //!< [11] Set to calculate CRC according to start address and end address in CRC_ADDR register.And compare with CRC fuse word according CRC address in CRC_ADDR register to generate CRC_FAIL flag
        unsigned CRC_FAIL : 1; //!< [12] Set by controller when calculated CRC value is not equal to appointed CRC fuse word
        unsigned RESERVED1 : 3; //!< [15:13] Reserved
        unsigned WR_UNLOCK : 16; //!< [31:16] Write 0x3E77 to enable OTP write accesses. NOTE: This register must be unlocked on a write-by-write basis (a write is initiated when HW_OCOTP_DATA is written), so the UNLOCK bitfield must contain the correct key value during all writes to HW_OCOTP_DATA, otherwise a write shall not be initiated. This field is automatically cleared after a successful write completion (clearing of BUSY).
    } B;
} hw_ocotp_hw_ocotp_ctrl_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_CTRL register
 */
#define HW_OCOTP_HW_OCOTP_CTRL_ADDR      (REGS_OCOTP_BASE + 0x0)
#define HW_OCOTP_HW_OCOTP_CTRL_SET_ADDR  (HW_OCOTP_HW_OCOTP_CTRL_ADDR + 0x4)
#define HW_OCOTP_HW_OCOTP_CTRL_CLR_ADDR  (HW_OCOTP_HW_OCOTP_CTRL_ADDR + 0x8)
#define HW_OCOTP_HW_OCOTP_CTRL_TOG_ADDR  (HW_OCOTP_HW_OCOTP_CTRL_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_CTRL           (*(volatile hw_ocotp_hw_ocotp_ctrl_t *) HW_OCOTP_HW_OCOTP_CTRL_ADDR)
#define HW_OCOTP_HW_OCOTP_CTRL_RD()      (HW_OCOTP_HW_OCOTP_CTRL.U)
#define HW_OCOTP_HW_OCOTP_CTRL_WR(v)     (HW_OCOTP_HW_OCOTP_CTRL.U = (v))
#define HW_OCOTP_HW_OCOTP_CTRL_SET(v)    ((*(volatile reg32_t *) HW_OCOTP_HW_OCOTP_CTRL_SET_ADDR) = (v))
#define HW_OCOTP_HW_OCOTP_CTRL_CLR(v)    ((*(volatile reg32_t *) HW_OCOTP_HW_OCOTP_CTRL_CLR_ADDR) = (v))
#define HW_OCOTP_HW_OCOTP_CTRL_TOG(v)    ((*(volatile reg32_t *) HW_OCOTP_HW_OCOTP_CTRL_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_CTRL bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_CTRL, field ADDR[5:0] (RW)
 *
 * OTP write and read access address register. Specifies one of 64 word address locations (0x00 -
 * 0x3f). If a valid access is accepted by the controller, the controller makes an internal copy of
 * this value. This internal copy will not update until the access is complete.
 */

#define BP_OCOTP_HW_OCOTP_CTRL_ADDR      (0)      //!< Bit position for OCOTP_HW_OCOTP_CTRL_ADDR.
#define BM_OCOTP_HW_OCOTP_CTRL_ADDR      (0x0000003f)  //!< Bit mask for OCOTP_HW_OCOTP_CTRL_ADDR.

//! @brief Get value of OCOTP_HW_OCOTP_CTRL_ADDR from a register value.
#define BG_OCOTP_HW_OCOTP_CTRL_ADDR(r)   (((r) & BM_OCOTP_HW_OCOTP_CTRL_ADDR) >> BP_OCOTP_HW_OCOTP_CTRL_ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CTRL_ADDR.
#define BF_OCOTP_HW_OCOTP_CTRL_ADDR(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_CTRL_ADDR) & BM_OCOTP_HW_OCOTP_CTRL_ADDR)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CTRL_ADDR.
#define BF_OCOTP_HW_OCOTP_CTRL_ADDR(v)   (((v) << BP_OCOTP_HW_OCOTP_CTRL_ADDR) & BM_OCOTP_HW_OCOTP_CTRL_ADDR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_OCOTP_HW_OCOTP_CTRL_ADDR(v)   BF_CS1(OCOTP_HW_OCOTP_CTRL, ADDR, v)
#endif

/* --- Register HW_OCOTP_HW_OCOTP_CTRL, field BUSY[8] (RO)
 *
 * OTP controller status bit. When active, no new write access or read access to OTP(including
 * RELOAD_SHADOWS) can be performed. Cleared by controller when access complete. After reset (or
 * after setting RELOAD_SHADOWS), this bit is set by the controller until the HW/SW and LOCK
 * registers are successfully copied, after which time it is automatically cleared by the
 * controller.
 */

#define BP_OCOTP_HW_OCOTP_CTRL_BUSY      (8)      //!< Bit position for OCOTP_HW_OCOTP_CTRL_BUSY.
#define BM_OCOTP_HW_OCOTP_CTRL_BUSY      (0x00000100)  //!< Bit mask for OCOTP_HW_OCOTP_CTRL_BUSY.

//! @brief Get value of OCOTP_HW_OCOTP_CTRL_BUSY from a register value.
#define BG_OCOTP_HW_OCOTP_CTRL_BUSY(r)   (((r) & BM_OCOTP_HW_OCOTP_CTRL_BUSY) >> BP_OCOTP_HW_OCOTP_CTRL_BUSY)

/* --- Register HW_OCOTP_HW_OCOTP_CTRL, field ERROR[9] (RW)
 *
 * Set by the controller when an access to a locked region(OTP or shadow register) is requested.
 * Must be cleared before any further access can be performed. This bit can only be set by the
 * controller. This bit is also set if the Pin interface is active and software requests an access
 * to the OTP. In this instance, the ERROR bit cannot be cleared until the Pin interface access has
 * completed. Reset this bit by writing a one to the SCT clear address space and not by a general
 * write.
 */

#define BP_OCOTP_HW_OCOTP_CTRL_ERROR      (9)      //!< Bit position for OCOTP_HW_OCOTP_CTRL_ERROR.
#define BM_OCOTP_HW_OCOTP_CTRL_ERROR      (0x00000200)  //!< Bit mask for OCOTP_HW_OCOTP_CTRL_ERROR.

//! @brief Get value of OCOTP_HW_OCOTP_CTRL_ERROR from a register value.
#define BG_OCOTP_HW_OCOTP_CTRL_ERROR(r)   (((r) & BM_OCOTP_HW_OCOTP_CTRL_ERROR) >> BP_OCOTP_HW_OCOTP_CTRL_ERROR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CTRL_ERROR.
#define BF_OCOTP_HW_OCOTP_CTRL_ERROR(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_CTRL_ERROR) & BM_OCOTP_HW_OCOTP_CTRL_ERROR)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CTRL_ERROR.
#define BF_OCOTP_HW_OCOTP_CTRL_ERROR(v)   (((v) << BP_OCOTP_HW_OCOTP_CTRL_ERROR) & BM_OCOTP_HW_OCOTP_CTRL_ERROR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR field to a new value.
#define BW_OCOTP_HW_OCOTP_CTRL_ERROR(v)   BF_CS1(OCOTP_HW_OCOTP_CTRL, ERROR, v)
#endif

/* --- Register HW_OCOTP_HW_OCOTP_CTRL, field RELOAD_SHADOWS[10] (RW)
 *
 * Set to force re-loading the shadow registers (HW/SW capability and LOCK). This operation will
 * automatically set BUSY. Once the shadow registers have been re-loaded, BUSY and RELOAD_SHADOWS
 * are automatically cleared by the controller.
 */

#define BP_OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS      (10)      //!< Bit position for OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS.
#define BM_OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS      (0x00000400)  //!< Bit mask for OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS.

//! @brief Get value of OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS from a register value.
#define BG_OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS(r)   (((r) & BM_OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS) >> BP_OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS.
#define BF_OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS) & BM_OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS.
#define BF_OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS(v)   (((v) << BP_OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS) & BM_OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RELOAD_SHADOWS field to a new value.
#define BW_OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS(v)   BF_CS1(OCOTP_HW_OCOTP_CTRL, RELOAD_SHADOWS, v)
#endif

/* --- Register HW_OCOTP_HW_OCOTP_CTRL, field CRC_TEST[11] (RW)
 *
 * Set to calculate CRC according to start address and end address in CRC_ADDR register.And compare
 * with CRC fuse word according CRC address in CRC_ADDR register to generate CRC_FAIL flag
 */

#define BP_OCOTP_HW_OCOTP_CTRL_CRC_TEST      (11)      //!< Bit position for OCOTP_HW_OCOTP_CTRL_CRC_TEST.
#define BM_OCOTP_HW_OCOTP_CTRL_CRC_TEST      (0x00000800)  //!< Bit mask for OCOTP_HW_OCOTP_CTRL_CRC_TEST.

//! @brief Get value of OCOTP_HW_OCOTP_CTRL_CRC_TEST from a register value.
#define BG_OCOTP_HW_OCOTP_CTRL_CRC_TEST(r)   (((r) & BM_OCOTP_HW_OCOTP_CTRL_CRC_TEST) >> BP_OCOTP_HW_OCOTP_CTRL_CRC_TEST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CTRL_CRC_TEST.
#define BF_OCOTP_HW_OCOTP_CTRL_CRC_TEST(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_CTRL_CRC_TEST) & BM_OCOTP_HW_OCOTP_CTRL_CRC_TEST)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CTRL_CRC_TEST.
#define BF_OCOTP_HW_OCOTP_CTRL_CRC_TEST(v)   (((v) << BP_OCOTP_HW_OCOTP_CTRL_CRC_TEST) & BM_OCOTP_HW_OCOTP_CTRL_CRC_TEST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CRC_TEST field to a new value.
#define BW_OCOTP_HW_OCOTP_CTRL_CRC_TEST(v)   BF_CS1(OCOTP_HW_OCOTP_CTRL, CRC_TEST, v)
#endif

/* --- Register HW_OCOTP_HW_OCOTP_CTRL, field CRC_FAIL[12] (RW)
 *
 * Set by controller when calculated CRC value is not equal to appointed CRC fuse word
 */

#define BP_OCOTP_HW_OCOTP_CTRL_CRC_FAIL      (12)      //!< Bit position for OCOTP_HW_OCOTP_CTRL_CRC_FAIL.
#define BM_OCOTP_HW_OCOTP_CTRL_CRC_FAIL      (0x00001000)  //!< Bit mask for OCOTP_HW_OCOTP_CTRL_CRC_FAIL.

//! @brief Get value of OCOTP_HW_OCOTP_CTRL_CRC_FAIL from a register value.
#define BG_OCOTP_HW_OCOTP_CTRL_CRC_FAIL(r)   (((r) & BM_OCOTP_HW_OCOTP_CTRL_CRC_FAIL) >> BP_OCOTP_HW_OCOTP_CTRL_CRC_FAIL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CTRL_CRC_FAIL.
#define BF_OCOTP_HW_OCOTP_CTRL_CRC_FAIL(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_CTRL_CRC_FAIL) & BM_OCOTP_HW_OCOTP_CTRL_CRC_FAIL)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CTRL_CRC_FAIL.
#define BF_OCOTP_HW_OCOTP_CTRL_CRC_FAIL(v)   (((v) << BP_OCOTP_HW_OCOTP_CTRL_CRC_FAIL) & BM_OCOTP_HW_OCOTP_CTRL_CRC_FAIL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CRC_FAIL field to a new value.
#define BW_OCOTP_HW_OCOTP_CTRL_CRC_FAIL(v)   BF_CS1(OCOTP_HW_OCOTP_CTRL, CRC_FAIL, v)
#endif

/* --- Register HW_OCOTP_HW_OCOTP_CTRL, field WR_UNLOCK[31:16] (RW)
 *
 * Write 0x3E77 to enable OTP write accesses. NOTE: This register must be unlocked on a write-by-
 * write basis (a write is initiated when HW_OCOTP_DATA is written), so the UNLOCK bitfield must
 * contain the correct key value during all writes to HW_OCOTP_DATA, otherwise a write shall not be
 * initiated. This field is automatically cleared after a successful write completion (clearing of
 * BUSY).
 *
 * Values:
 * KEY = 0x3E77 - Key needed to unlock HW_OCOTP_DATA register.
 */

#define BP_OCOTP_HW_OCOTP_CTRL_WR_UNLOCK      (16)      //!< Bit position for OCOTP_HW_OCOTP_CTRL_WR_UNLOCK.
#define BM_OCOTP_HW_OCOTP_CTRL_WR_UNLOCK      (0xffff0000)  //!< Bit mask for OCOTP_HW_OCOTP_CTRL_WR_UNLOCK.

//! @brief Get value of OCOTP_HW_OCOTP_CTRL_WR_UNLOCK from a register value.
#define BG_OCOTP_HW_OCOTP_CTRL_WR_UNLOCK(r)   (((r) & BM_OCOTP_HW_OCOTP_CTRL_WR_UNLOCK) >> BP_OCOTP_HW_OCOTP_CTRL_WR_UNLOCK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CTRL_WR_UNLOCK.
#define BF_OCOTP_HW_OCOTP_CTRL_WR_UNLOCK(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_CTRL_WR_UNLOCK) & BM_OCOTP_HW_OCOTP_CTRL_WR_UNLOCK)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CTRL_WR_UNLOCK.
#define BF_OCOTP_HW_OCOTP_CTRL_WR_UNLOCK(v)   (((v) << BP_OCOTP_HW_OCOTP_CTRL_WR_UNLOCK) & BM_OCOTP_HW_OCOTP_CTRL_WR_UNLOCK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WR_UNLOCK field to a new value.
#define BW_OCOTP_HW_OCOTP_CTRL_WR_UNLOCK(v)   BF_CS1(OCOTP_HW_OCOTP_CTRL, WR_UNLOCK, v)
#endif

#define BV_OCOTP_HW_OCOTP_CTRL_WR_UNLOCK__KEY (0x3e77) //!< Key needed to unlock HW_OCOTP_DATA register.

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_TIMING - OTP Controller Timing Register (RW)
 *
 * Reset value: 0x01461299
 *
 * The OCOTP Data Register is used for OTP Programming  This register specifies timing parameters
 * for programming and reading the OCOTP fuse array.   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_timing
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_timing_bitfields
    {
        unsigned STROBE_PROG : 12; //!< [11:0] This count value specifies the strobe period in one time write OTP. Tpgm = ((STROBE_PROG+1)- 2*(RELAX+1)) /ipg_clk_freq. It is given in number of ipg_clk periods.
        unsigned RELAX : 4; //!< [15:12] This count value specifies the time to add to all default timing parameters other than the Tpgm and Trd. It is given in number of ipg_clk periods.
        unsigned STROBE_READ : 6; //!< [21:16] This count value specifies the strobe period in one time read OTP. Trd = ((STROBE_READ+1)- 2*(RELAX+1)) /ipg_clk_freq. It is given in number of ipg_clk periods.
        unsigned WAIT : 6; //!< [27:22] This count value specifies time interval between auto read and write access in one time program. It is given in number of ipg_clk periods.
        unsigned RESERVED0 : 4; //!< [31:28] These bits always read back zero.
    } B;
} hw_ocotp_hw_ocotp_timing_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_TIMING register
 */
#define HW_OCOTP_HW_OCOTP_TIMING_ADDR      (REGS_OCOTP_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_TIMING           (*(volatile hw_ocotp_hw_ocotp_timing_t *) HW_OCOTP_HW_OCOTP_TIMING_ADDR)
#define HW_OCOTP_HW_OCOTP_TIMING_RD()      (HW_OCOTP_HW_OCOTP_TIMING.U)
#define HW_OCOTP_HW_OCOTP_TIMING_WR(v)     (HW_OCOTP_HW_OCOTP_TIMING.U = (v))
#define HW_OCOTP_HW_OCOTP_TIMING_SET(v)    (HW_OCOTP_HW_OCOTP_TIMING_WR(HW_OCOTP_HW_OCOTP_TIMING_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_TIMING_CLR(v)    (HW_OCOTP_HW_OCOTP_TIMING_WR(HW_OCOTP_HW_OCOTP_TIMING_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_TIMING_TOG(v)    (HW_OCOTP_HW_OCOTP_TIMING_WR(HW_OCOTP_HW_OCOTP_TIMING_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_TIMING bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_TIMING, field STROBE_PROG[11:0] (RW)
 *
 * This count value specifies the strobe period in one time write OTP. Tpgm = ((STROBE_PROG+1)-
 * 2*(RELAX+1)) /ipg_clk_freq. It is given in number of ipg_clk periods.
 */

#define BP_OCOTP_HW_OCOTP_TIMING_STROBE_PROG      (0)      //!< Bit position for OCOTP_HW_OCOTP_TIMING_STROBE_PROG.
#define BM_OCOTP_HW_OCOTP_TIMING_STROBE_PROG      (0x00000fff)  //!< Bit mask for OCOTP_HW_OCOTP_TIMING_STROBE_PROG.

//! @brief Get value of OCOTP_HW_OCOTP_TIMING_STROBE_PROG from a register value.
#define BG_OCOTP_HW_OCOTP_TIMING_STROBE_PROG(r)   (((r) & BM_OCOTP_HW_OCOTP_TIMING_STROBE_PROG) >> BP_OCOTP_HW_OCOTP_TIMING_STROBE_PROG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_TIMING_STROBE_PROG.
#define BF_OCOTP_HW_OCOTP_TIMING_STROBE_PROG(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_TIMING_STROBE_PROG) & BM_OCOTP_HW_OCOTP_TIMING_STROBE_PROG)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_TIMING_STROBE_PROG.
#define BF_OCOTP_HW_OCOTP_TIMING_STROBE_PROG(v)   (((v) << BP_OCOTP_HW_OCOTP_TIMING_STROBE_PROG) & BM_OCOTP_HW_OCOTP_TIMING_STROBE_PROG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the STROBE_PROG field to a new value.
#define BW_OCOTP_HW_OCOTP_TIMING_STROBE_PROG(v)   (HW_OCOTP_HW_OCOTP_TIMING_WR((HW_OCOTP_HW_OCOTP_TIMING_RD() & ~BM_OCOTP_HW_OCOTP_TIMING_STROBE_PROG) | BF_OCOTP_HW_OCOTP_TIMING_STROBE_PROG(v)))
#endif

/* --- Register HW_OCOTP_HW_OCOTP_TIMING, field RELAX[15:12] (RW)
 *
 * This count value specifies the time to add to all default timing parameters other than the Tpgm
 * and Trd. It is given in number of ipg_clk periods.
 */

#define BP_OCOTP_HW_OCOTP_TIMING_RELAX      (12)      //!< Bit position for OCOTP_HW_OCOTP_TIMING_RELAX.
#define BM_OCOTP_HW_OCOTP_TIMING_RELAX      (0x0000f000)  //!< Bit mask for OCOTP_HW_OCOTP_TIMING_RELAX.

//! @brief Get value of OCOTP_HW_OCOTP_TIMING_RELAX from a register value.
#define BG_OCOTP_HW_OCOTP_TIMING_RELAX(r)   (((r) & BM_OCOTP_HW_OCOTP_TIMING_RELAX) >> BP_OCOTP_HW_OCOTP_TIMING_RELAX)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_TIMING_RELAX.
#define BF_OCOTP_HW_OCOTP_TIMING_RELAX(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_TIMING_RELAX) & BM_OCOTP_HW_OCOTP_TIMING_RELAX)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_TIMING_RELAX.
#define BF_OCOTP_HW_OCOTP_TIMING_RELAX(v)   (((v) << BP_OCOTP_HW_OCOTP_TIMING_RELAX) & BM_OCOTP_HW_OCOTP_TIMING_RELAX)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RELAX field to a new value.
#define BW_OCOTP_HW_OCOTP_TIMING_RELAX(v)   (HW_OCOTP_HW_OCOTP_TIMING_WR((HW_OCOTP_HW_OCOTP_TIMING_RD() & ~BM_OCOTP_HW_OCOTP_TIMING_RELAX) | BF_OCOTP_HW_OCOTP_TIMING_RELAX(v)))
#endif

/* --- Register HW_OCOTP_HW_OCOTP_TIMING, field STROBE_READ[21:16] (RW)
 *
 * This count value specifies the strobe period in one time read OTP. Trd = ((STROBE_READ+1)-
 * 2*(RELAX+1)) /ipg_clk_freq. It is given in number of ipg_clk periods.
 */

#define BP_OCOTP_HW_OCOTP_TIMING_STROBE_READ      (16)      //!< Bit position for OCOTP_HW_OCOTP_TIMING_STROBE_READ.
#define BM_OCOTP_HW_OCOTP_TIMING_STROBE_READ      (0x003f0000)  //!< Bit mask for OCOTP_HW_OCOTP_TIMING_STROBE_READ.

//! @brief Get value of OCOTP_HW_OCOTP_TIMING_STROBE_READ from a register value.
#define BG_OCOTP_HW_OCOTP_TIMING_STROBE_READ(r)   (((r) & BM_OCOTP_HW_OCOTP_TIMING_STROBE_READ) >> BP_OCOTP_HW_OCOTP_TIMING_STROBE_READ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_TIMING_STROBE_READ.
#define BF_OCOTP_HW_OCOTP_TIMING_STROBE_READ(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_TIMING_STROBE_READ) & BM_OCOTP_HW_OCOTP_TIMING_STROBE_READ)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_TIMING_STROBE_READ.
#define BF_OCOTP_HW_OCOTP_TIMING_STROBE_READ(v)   (((v) << BP_OCOTP_HW_OCOTP_TIMING_STROBE_READ) & BM_OCOTP_HW_OCOTP_TIMING_STROBE_READ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the STROBE_READ field to a new value.
#define BW_OCOTP_HW_OCOTP_TIMING_STROBE_READ(v)   (HW_OCOTP_HW_OCOTP_TIMING_WR((HW_OCOTP_HW_OCOTP_TIMING_RD() & ~BM_OCOTP_HW_OCOTP_TIMING_STROBE_READ) | BF_OCOTP_HW_OCOTP_TIMING_STROBE_READ(v)))
#endif

/* --- Register HW_OCOTP_HW_OCOTP_TIMING, field WAIT[27:22] (RW)
 *
 * This count value specifies time interval between auto read and write access in one time program.
 * It is given in number of ipg_clk periods.
 */

#define BP_OCOTP_HW_OCOTP_TIMING_WAIT      (22)      //!< Bit position for OCOTP_HW_OCOTP_TIMING_WAIT.
#define BM_OCOTP_HW_OCOTP_TIMING_WAIT      (0x0fc00000)  //!< Bit mask for OCOTP_HW_OCOTP_TIMING_WAIT.

//! @brief Get value of OCOTP_HW_OCOTP_TIMING_WAIT from a register value.
#define BG_OCOTP_HW_OCOTP_TIMING_WAIT(r)   (((r) & BM_OCOTP_HW_OCOTP_TIMING_WAIT) >> BP_OCOTP_HW_OCOTP_TIMING_WAIT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_TIMING_WAIT.
#define BF_OCOTP_HW_OCOTP_TIMING_WAIT(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_TIMING_WAIT) & BM_OCOTP_HW_OCOTP_TIMING_WAIT)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_TIMING_WAIT.
#define BF_OCOTP_HW_OCOTP_TIMING_WAIT(v)   (((v) << BP_OCOTP_HW_OCOTP_TIMING_WAIT) & BM_OCOTP_HW_OCOTP_TIMING_WAIT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WAIT field to a new value.
#define BW_OCOTP_HW_OCOTP_TIMING_WAIT(v)   (HW_OCOTP_HW_OCOTP_TIMING_WR((HW_OCOTP_HW_OCOTP_TIMING_RD() & ~BM_OCOTP_HW_OCOTP_TIMING_WAIT) | BF_OCOTP_HW_OCOTP_TIMING_WAIT(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_DATA - OTP Controller Write Data Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The OCOTP Data Register is used for OTP Programming  This register is used in conjuction with
 * HW_OCOTP_CTRL to perform one-time writes to the OTP. Please see the "Software Write Sequence"
 * section for operating details.   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_data
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_data_bitfields
    {
        unsigned DATA : 32; //!< [31:0] Used to initiate a write to OTP. Please see the "Software Write Sequence" section for operating details.
    } B;
} hw_ocotp_hw_ocotp_data_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_DATA register
 */
#define HW_OCOTP_HW_OCOTP_DATA_ADDR      (REGS_OCOTP_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_DATA           (*(volatile hw_ocotp_hw_ocotp_data_t *) HW_OCOTP_HW_OCOTP_DATA_ADDR)
#define HW_OCOTP_HW_OCOTP_DATA_RD()      (HW_OCOTP_HW_OCOTP_DATA.U)
#define HW_OCOTP_HW_OCOTP_DATA_WR(v)     (HW_OCOTP_HW_OCOTP_DATA.U = (v))
#define HW_OCOTP_HW_OCOTP_DATA_SET(v)    (HW_OCOTP_HW_OCOTP_DATA_WR(HW_OCOTP_HW_OCOTP_DATA_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_DATA_CLR(v)    (HW_OCOTP_HW_OCOTP_DATA_WR(HW_OCOTP_HW_OCOTP_DATA_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_DATA_TOG(v)    (HW_OCOTP_HW_OCOTP_DATA_WR(HW_OCOTP_HW_OCOTP_DATA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_DATA bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_DATA, field DATA[31:0] (RW)
 *
 * Used to initiate a write to OTP. Please see the "Software Write Sequence" section for operating
 * details.
 */

#define BP_OCOTP_HW_OCOTP_DATA_DATA      (0)      //!< Bit position for OCOTP_HW_OCOTP_DATA_DATA.
#define BM_OCOTP_HW_OCOTP_DATA_DATA      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_DATA_DATA.

//! @brief Get value of OCOTP_HW_OCOTP_DATA_DATA from a register value.
#define BG_OCOTP_HW_OCOTP_DATA_DATA(r)   (((r) & BM_OCOTP_HW_OCOTP_DATA_DATA) >> BP_OCOTP_HW_OCOTP_DATA_DATA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_DATA_DATA.
#define BF_OCOTP_HW_OCOTP_DATA_DATA(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_DATA_DATA) & BM_OCOTP_HW_OCOTP_DATA_DATA)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_DATA_DATA.
#define BF_OCOTP_HW_OCOTP_DATA_DATA(v)   (((v) << BP_OCOTP_HW_OCOTP_DATA_DATA) & BM_OCOTP_HW_OCOTP_DATA_DATA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA field to a new value.
#define BW_OCOTP_HW_OCOTP_DATA_DATA(v)   (HW_OCOTP_HW_OCOTP_DATA_WR((HW_OCOTP_HW_OCOTP_DATA_RD() & ~BM_OCOTP_HW_OCOTP_DATA_DATA) | BF_OCOTP_HW_OCOTP_DATA_DATA(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_READ_CTRL - OTP Controller Write Data Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The OCOTP Register is used for OTP Read  This register is used in conjuction with HW_OCOTP_CTRL
 * to perform one time read to the OTP. Please see the "Software read Sequence" section for
 * operating details.   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_read_ctrl
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_read_ctrl_bitfields
    {
        unsigned READ_FUSE : 1; //!< [0] Used to initiate a read to OTP. Please see the "Software read Sequence" section for operating details.
        unsigned RESERVED0 : 31; //!< [31:1] Reserved
    } B;
} hw_ocotp_hw_ocotp_read_ctrl_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_READ_CTRL register
 */
#define HW_OCOTP_HW_OCOTP_READ_CTRL_ADDR      (REGS_OCOTP_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_READ_CTRL           (*(volatile hw_ocotp_hw_ocotp_read_ctrl_t *) HW_OCOTP_HW_OCOTP_READ_CTRL_ADDR)
#define HW_OCOTP_HW_OCOTP_READ_CTRL_RD()      (HW_OCOTP_HW_OCOTP_READ_CTRL.U)
#define HW_OCOTP_HW_OCOTP_READ_CTRL_WR(v)     (HW_OCOTP_HW_OCOTP_READ_CTRL.U = (v))
#define HW_OCOTP_HW_OCOTP_READ_CTRL_SET(v)    (HW_OCOTP_HW_OCOTP_READ_CTRL_WR(HW_OCOTP_HW_OCOTP_READ_CTRL_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_READ_CTRL_CLR(v)    (HW_OCOTP_HW_OCOTP_READ_CTRL_WR(HW_OCOTP_HW_OCOTP_READ_CTRL_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_READ_CTRL_TOG(v)    (HW_OCOTP_HW_OCOTP_READ_CTRL_WR(HW_OCOTP_HW_OCOTP_READ_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_READ_CTRL bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_READ_CTRL, field READ_FUSE[0] (RW)
 *
 * Used to initiate a read to OTP. Please see the "Software read Sequence" section for operating
 * details.
 */

#define BP_OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE      (0)      //!< Bit position for OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE.
#define BM_OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE      (0x00000001)  //!< Bit mask for OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE.

//! @brief Get value of OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE from a register value.
#define BG_OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE(r)   (((r) & BM_OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE) >> BP_OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE.
#define BF_OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE) & BM_OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE.
#define BF_OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE(v)   (((v) << BP_OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE) & BM_OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the READ_FUSE field to a new value.
#define BW_OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE(v)   (HW_OCOTP_HW_OCOTP_READ_CTRL_WR((HW_OCOTP_HW_OCOTP_READ_CTRL_RD() & ~BM_OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE) | BF_OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_READ_FUSE_DATA - OTP Controller Read Data Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The OCOTP Data Register is used for OTP Read  The data read from OTP   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_read_fuse_data
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_read_fuse_data_bitfields
    {
        unsigned DATA : 32; //!< [31:0] The data read from OTP
    } B;
} hw_ocotp_hw_ocotp_read_fuse_data_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_READ_FUSE_DATA register
 */
#define HW_OCOTP_HW_OCOTP_READ_FUSE_DATA_ADDR      (REGS_OCOTP_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_READ_FUSE_DATA           (*(volatile hw_ocotp_hw_ocotp_read_fuse_data_t *) HW_OCOTP_HW_OCOTP_READ_FUSE_DATA_ADDR)
#define HW_OCOTP_HW_OCOTP_READ_FUSE_DATA_RD()      (HW_OCOTP_HW_OCOTP_READ_FUSE_DATA.U)
#define HW_OCOTP_HW_OCOTP_READ_FUSE_DATA_WR(v)     (HW_OCOTP_HW_OCOTP_READ_FUSE_DATA.U = (v))
#define HW_OCOTP_HW_OCOTP_READ_FUSE_DATA_SET(v)    (HW_OCOTP_HW_OCOTP_READ_FUSE_DATA_WR(HW_OCOTP_HW_OCOTP_READ_FUSE_DATA_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_READ_FUSE_DATA_CLR(v)    (HW_OCOTP_HW_OCOTP_READ_FUSE_DATA_WR(HW_OCOTP_HW_OCOTP_READ_FUSE_DATA_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_READ_FUSE_DATA_TOG(v)    (HW_OCOTP_HW_OCOTP_READ_FUSE_DATA_WR(HW_OCOTP_HW_OCOTP_READ_FUSE_DATA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_READ_FUSE_DATA bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_READ_FUSE_DATA, field DATA[31:0] (RW)
 *
 * The data read from OTP
 */

#define BP_OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA      (0)      //!< Bit position for OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA.
#define BM_OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA.

//! @brief Get value of OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA from a register value.
#define BG_OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA(r)   (((r) & BM_OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA) >> BP_OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA.
#define BF_OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA) & BM_OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA.
#define BF_OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA(v)   (((v) << BP_OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA) & BM_OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA field to a new value.
#define BW_OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA(v)   (HW_OCOTP_HW_OCOTP_READ_FUSE_DATA_WR((HW_OCOTP_HW_OCOTP_READ_FUSE_DATA_RD() & ~BM_OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA) | BF_OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_SW_STICKY - Sticky bit Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Some SW sticky bits .  Some sticky bits are used by SW to lock some fuse area , shadow registers
 * and other features.   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_sw_sticky
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_sw_sticky_bitfields
    {
        unsigned BLOCK_DTCP_KEY : 1; //!< [0] Shadow register read and OTP read lock for DTCP_KEY region. It is used to lock shadow register and OTP read for DTCP_KEY in conjuction with dtcp_disable and HDCP_KEY lock fuse bit. Once this bit is set, it is always high unless a POR is issued.
        unsigned SRK_REVOKE_LOCK : 1; //!< [1] Shadow register write and OTP write lock for SRK_REVOKE region. When set, the writing of this region's shadow register and OTP fuse word are blocked. Once this bit is set, it is always high unless a POR is issued.
        unsigned FIELD_RETURN_LOCK : 1; //!< [2] Shadow register write and OTP write lock for FIELD_RETURN region. When set, the writing of this region's shadow register and OTP fuse word are blocked.Once this bit is set, it is always high unless a POR is issued.
        unsigned BLOCK_ROM_PART : 1; //!< [3] Set by ARM during Boot after DTCP is initialized and before test mode entry, if ROM_PART_LOCK=1.* 0 (Default) - Secret part of Boot ROM is not hidden (subject to other conditions).* 1 - Secret part of Boot ROM is hidden.Once this bit is set, it is always high unless a POR is issued.
        unsigned JTAG_BLOCK_RELEASE : 1; //!< [4] Set by ARM during Boot after DTCP is initialized and before test mode entry. * 0 (Default) - JTAG is blocked (subject to other conditions).* 1 - JTAG block is released (subject to other controls). Once this bit is set, it is always high unless a POR is issued.
        unsigned RESERVED0 : 27; //!< [31:5] Reserved
    } B;
} hw_ocotp_hw_ocotp_sw_sticky_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_SW_STICKY register
 */
#define HW_OCOTP_HW_OCOTP_SW_STICKY_ADDR      (REGS_OCOTP_BASE + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_SW_STICKY           (*(volatile hw_ocotp_hw_ocotp_sw_sticky_t *) HW_OCOTP_HW_OCOTP_SW_STICKY_ADDR)
#define HW_OCOTP_HW_OCOTP_SW_STICKY_RD()      (HW_OCOTP_HW_OCOTP_SW_STICKY.U)
#define HW_OCOTP_HW_OCOTP_SW_STICKY_WR(v)     (HW_OCOTP_HW_OCOTP_SW_STICKY.U = (v))
#define HW_OCOTP_HW_OCOTP_SW_STICKY_SET(v)    (HW_OCOTP_HW_OCOTP_SW_STICKY_WR(HW_OCOTP_HW_OCOTP_SW_STICKY_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_SW_STICKY_CLR(v)    (HW_OCOTP_HW_OCOTP_SW_STICKY_WR(HW_OCOTP_HW_OCOTP_SW_STICKY_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_SW_STICKY_TOG(v)    (HW_OCOTP_HW_OCOTP_SW_STICKY_WR(HW_OCOTP_HW_OCOTP_SW_STICKY_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_SW_STICKY bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_SW_STICKY, field BLOCK_DTCP_KEY[0] (RW)
 *
 * Shadow register read and OTP read lock for DTCP_KEY region. It is used to lock shadow register
 * and OTP read for DTCP_KEY in conjuction with dtcp_disable and HDCP_KEY lock fuse bit. Once this
 * bit is set, it is always high unless a POR is issued.
 */

#define BP_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_DTCP_KEY      (0)      //!< Bit position for OCOTP_HW_OCOTP_SW_STICKY_BLOCK_DTCP_KEY.
#define BM_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_DTCP_KEY      (0x00000001)  //!< Bit mask for OCOTP_HW_OCOTP_SW_STICKY_BLOCK_DTCP_KEY.

//! @brief Get value of OCOTP_HW_OCOTP_SW_STICKY_BLOCK_DTCP_KEY from a register value.
#define BG_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_DTCP_KEY(r)   (((r) & BM_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_DTCP_KEY) >> BP_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_DTCP_KEY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_STICKY_BLOCK_DTCP_KEY.
#define BF_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_DTCP_KEY(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_DTCP_KEY) & BM_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_DTCP_KEY)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_STICKY_BLOCK_DTCP_KEY.
#define BF_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_DTCP_KEY(v)   (((v) << BP_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_DTCP_KEY) & BM_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_DTCP_KEY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BLOCK_DTCP_KEY field to a new value.
#define BW_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_DTCP_KEY(v)   (HW_OCOTP_HW_OCOTP_SW_STICKY_WR((HW_OCOTP_HW_OCOTP_SW_STICKY_RD() & ~BM_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_DTCP_KEY) | BF_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_DTCP_KEY(v)))
#endif

/* --- Register HW_OCOTP_HW_OCOTP_SW_STICKY, field SRK_REVOKE_LOCK[1] (RW)
 *
 * Shadow register write and OTP write lock for SRK_REVOKE region. When set, the writing of this
 * region's shadow register and OTP fuse word are blocked. Once this bit is set, it is always high
 * unless a POR is issued.
 */

#define BP_OCOTP_HW_OCOTP_SW_STICKY_SRK_REVOKE_LOCK      (1)      //!< Bit position for OCOTP_HW_OCOTP_SW_STICKY_SRK_REVOKE_LOCK.
#define BM_OCOTP_HW_OCOTP_SW_STICKY_SRK_REVOKE_LOCK      (0x00000002)  //!< Bit mask for OCOTP_HW_OCOTP_SW_STICKY_SRK_REVOKE_LOCK.

//! @brief Get value of OCOTP_HW_OCOTP_SW_STICKY_SRK_REVOKE_LOCK from a register value.
#define BG_OCOTP_HW_OCOTP_SW_STICKY_SRK_REVOKE_LOCK(r)   (((r) & BM_OCOTP_HW_OCOTP_SW_STICKY_SRK_REVOKE_LOCK) >> BP_OCOTP_HW_OCOTP_SW_STICKY_SRK_REVOKE_LOCK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_STICKY_SRK_REVOKE_LOCK.
#define BF_OCOTP_HW_OCOTP_SW_STICKY_SRK_REVOKE_LOCK(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SW_STICKY_SRK_REVOKE_LOCK) & BM_OCOTP_HW_OCOTP_SW_STICKY_SRK_REVOKE_LOCK)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_STICKY_SRK_REVOKE_LOCK.
#define BF_OCOTP_HW_OCOTP_SW_STICKY_SRK_REVOKE_LOCK(v)   (((v) << BP_OCOTP_HW_OCOTP_SW_STICKY_SRK_REVOKE_LOCK) & BM_OCOTP_HW_OCOTP_SW_STICKY_SRK_REVOKE_LOCK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SRK_REVOKE_LOCK field to a new value.
#define BW_OCOTP_HW_OCOTP_SW_STICKY_SRK_REVOKE_LOCK(v)   (HW_OCOTP_HW_OCOTP_SW_STICKY_WR((HW_OCOTP_HW_OCOTP_SW_STICKY_RD() & ~BM_OCOTP_HW_OCOTP_SW_STICKY_SRK_REVOKE_LOCK) | BF_OCOTP_HW_OCOTP_SW_STICKY_SRK_REVOKE_LOCK(v)))
#endif

/* --- Register HW_OCOTP_HW_OCOTP_SW_STICKY, field FIELD_RETURN_LOCK[2] (RW)
 *
 * Shadow register write and OTP write lock for FIELD_RETURN region. When set, the writing of this
 * region's shadow register and OTP fuse word are blocked.Once this bit is set, it is always high
 * unless a POR is issued.
 */

#define BP_OCOTP_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK      (2)      //!< Bit position for OCOTP_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK.
#define BM_OCOTP_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK      (0x00000004)  //!< Bit mask for OCOTP_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK.

//! @brief Get value of OCOTP_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK from a register value.
#define BG_OCOTP_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK(r)   (((r) & BM_OCOTP_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK) >> BP_OCOTP_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK.
#define BF_OCOTP_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK) & BM_OCOTP_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK.
#define BF_OCOTP_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK(v)   (((v) << BP_OCOTP_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK) & BM_OCOTP_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FIELD_RETURN_LOCK field to a new value.
#define BW_OCOTP_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK(v)   (HW_OCOTP_HW_OCOTP_SW_STICKY_WR((HW_OCOTP_HW_OCOTP_SW_STICKY_RD() & ~BM_OCOTP_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK) | BF_OCOTP_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK(v)))
#endif

/* --- Register HW_OCOTP_HW_OCOTP_SW_STICKY, field BLOCK_ROM_PART[3] (RW)
 *
 * Set by ARM during Boot after DTCP is initialized and before test mode entry, if ROM_PART_LOCK=1.*
 * 0 (Default) - Secret part of Boot ROM is not hidden (subject to other conditions).* 1 - Secret
 * part of Boot ROM is hidden.Once this bit is set, it is always high unless a POR is issued.
 */

#define BP_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_ROM_PART      (3)      //!< Bit position for OCOTP_HW_OCOTP_SW_STICKY_BLOCK_ROM_PART.
#define BM_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_ROM_PART      (0x00000008)  //!< Bit mask for OCOTP_HW_OCOTP_SW_STICKY_BLOCK_ROM_PART.

//! @brief Get value of OCOTP_HW_OCOTP_SW_STICKY_BLOCK_ROM_PART from a register value.
#define BG_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_ROM_PART(r)   (((r) & BM_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_ROM_PART) >> BP_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_ROM_PART)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_STICKY_BLOCK_ROM_PART.
#define BF_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_ROM_PART(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_ROM_PART) & BM_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_ROM_PART)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_STICKY_BLOCK_ROM_PART.
#define BF_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_ROM_PART(v)   (((v) << BP_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_ROM_PART) & BM_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_ROM_PART)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BLOCK_ROM_PART field to a new value.
#define BW_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_ROM_PART(v)   (HW_OCOTP_HW_OCOTP_SW_STICKY_WR((HW_OCOTP_HW_OCOTP_SW_STICKY_RD() & ~BM_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_ROM_PART) | BF_OCOTP_HW_OCOTP_SW_STICKY_BLOCK_ROM_PART(v)))
#endif

/* --- Register HW_OCOTP_HW_OCOTP_SW_STICKY, field JTAG_BLOCK_RELEASE[4] (RW)
 *
 * Set by ARM during Boot after DTCP is initialized and before test mode entry. * 0 (Default) - JTAG
 * is blocked (subject to other conditions).* 1 - JTAG block is released (subject to other
 * controls). Once this bit is set, it is always high unless a POR is issued.
 */

#define BP_OCOTP_HW_OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE      (4)      //!< Bit position for OCOTP_HW_OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE.
#define BM_OCOTP_HW_OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE      (0x00000010)  //!< Bit mask for OCOTP_HW_OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE.

//! @brief Get value of OCOTP_HW_OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE from a register value.
#define BG_OCOTP_HW_OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE(r)   (((r) & BM_OCOTP_HW_OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE) >> BP_OCOTP_HW_OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE.
#define BF_OCOTP_HW_OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE) & BM_OCOTP_HW_OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE.
#define BF_OCOTP_HW_OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE(v)   (((v) << BP_OCOTP_HW_OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE) & BM_OCOTP_HW_OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the JTAG_BLOCK_RELEASE field to a new value.
#define BW_OCOTP_HW_OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE(v)   (HW_OCOTP_HW_OCOTP_SW_STICKY_WR((HW_OCOTP_HW_OCOTP_SW_STICKY_RD() & ~BM_OCOTP_HW_OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE) | BF_OCOTP_HW_OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_SCS - Software Controllable Signals Register (RW)
 *
 * Reset value: 0x00000000
 *
 * HW_OCOTP_SCS: 0x060  HW_OCOTP_SCS_SET: 0x064  HW_OCOTP_SCS_CLR: 0x068  HW_OCOTP_SCS_TOG: 0x06C
 * This register holds volatile configuration values that can be set and locked by trusted software.
 * All values are returned to their defualt values after POR.   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_scs
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_scs_bitfields
    {
        unsigned HAB_JDE : 1; //!< [0] HAB JTAG Debug Enable. This bit is used by the HAB to enable JTAG debugging, assuming that a properlay signed command to do so is found and validated by the HAB. The HAB must lock the register before passing control to the OS whether or not JTAG debugging has been enabled. Once JTAG is enabled by this bit, it can not be disabled unless the system is reset by POR. 0: JTAG debugging is not enabled by the HAB (it may still be enabled by other mechanisms). 1: JTAG debugging is enabled by the HAB (though this signal may be gated off).
        unsigned SPARE : 30; //!< [30:1] Unallocated read/write bits for implementation specific software use.
        unsigned LOCK : 1; //!< [31] When set, all of the bits in this register are locked and can not be changed through SW programming. This bit is only reset after a POR is issued.
    } B;
} hw_ocotp_hw_ocotp_scs_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_SCS register
 */
#define HW_OCOTP_HW_OCOTP_SCS_ADDR      (REGS_OCOTP_BASE + 0x60)
#define HW_OCOTP_HW_OCOTP_SCS_SET_ADDR  (HW_OCOTP_HW_OCOTP_SCS_ADDR + 0x4)
#define HW_OCOTP_HW_OCOTP_SCS_CLR_ADDR  (HW_OCOTP_HW_OCOTP_SCS_ADDR + 0x8)
#define HW_OCOTP_HW_OCOTP_SCS_TOG_ADDR  (HW_OCOTP_HW_OCOTP_SCS_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_SCS           (*(volatile hw_ocotp_hw_ocotp_scs_t *) HW_OCOTP_HW_OCOTP_SCS_ADDR)
#define HW_OCOTP_HW_OCOTP_SCS_RD()      (HW_OCOTP_HW_OCOTP_SCS.U)
#define HW_OCOTP_HW_OCOTP_SCS_WR(v)     (HW_OCOTP_HW_OCOTP_SCS.U = (v))
#define HW_OCOTP_HW_OCOTP_SCS_SET(v)    ((*(volatile reg32_t *) HW_OCOTP_HW_OCOTP_SCS_SET_ADDR) = (v))
#define HW_OCOTP_HW_OCOTP_SCS_CLR(v)    ((*(volatile reg32_t *) HW_OCOTP_HW_OCOTP_SCS_CLR_ADDR) = (v))
#define HW_OCOTP_HW_OCOTP_SCS_TOG(v)    ((*(volatile reg32_t *) HW_OCOTP_HW_OCOTP_SCS_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_SCS bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_SCS, field HAB_JDE[0] (RW)
 *
 * HAB JTAG Debug Enable. This bit is used by the HAB to enable JTAG debugging, assuming that a
 * properlay signed command to do so is found and validated by the HAB. The HAB must lock the
 * register before passing control to the OS whether or not JTAG debugging has been enabled. Once
 * JTAG is enabled by this bit, it can not be disabled unless the system is reset by POR. 0: JTAG
 * debugging is not enabled by the HAB (it may still be enabled by other mechanisms). 1: JTAG
 * debugging is enabled by the HAB (though this signal may be gated off).
 */

#define BP_OCOTP_HW_OCOTP_SCS_HAB_JDE      (0)      //!< Bit position for OCOTP_HW_OCOTP_SCS_HAB_JDE.
#define BM_OCOTP_HW_OCOTP_SCS_HAB_JDE      (0x00000001)  //!< Bit mask for OCOTP_HW_OCOTP_SCS_HAB_JDE.

//! @brief Get value of OCOTP_HW_OCOTP_SCS_HAB_JDE from a register value.
#define BG_OCOTP_HW_OCOTP_SCS_HAB_JDE(r)   (((r) & BM_OCOTP_HW_OCOTP_SCS_HAB_JDE) >> BP_OCOTP_HW_OCOTP_SCS_HAB_JDE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SCS_HAB_JDE.
#define BF_OCOTP_HW_OCOTP_SCS_HAB_JDE(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SCS_HAB_JDE) & BM_OCOTP_HW_OCOTP_SCS_HAB_JDE)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SCS_HAB_JDE.
#define BF_OCOTP_HW_OCOTP_SCS_HAB_JDE(v)   (((v) << BP_OCOTP_HW_OCOTP_SCS_HAB_JDE) & BM_OCOTP_HW_OCOTP_SCS_HAB_JDE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HAB_JDE field to a new value.
#define BW_OCOTP_HW_OCOTP_SCS_HAB_JDE(v)   BF_CS1(OCOTP_HW_OCOTP_SCS, HAB_JDE, v)
#endif

/* --- Register HW_OCOTP_HW_OCOTP_SCS, field SPARE[30:1] (RW)
 *
 * Unallocated read/write bits for implementation specific software use.
 */

#define BP_OCOTP_HW_OCOTP_SCS_SPARE      (1)      //!< Bit position for OCOTP_HW_OCOTP_SCS_SPARE.
#define BM_OCOTP_HW_OCOTP_SCS_SPARE      (0x7ffffffe)  //!< Bit mask for OCOTP_HW_OCOTP_SCS_SPARE.

//! @brief Get value of OCOTP_HW_OCOTP_SCS_SPARE from a register value.
#define BG_OCOTP_HW_OCOTP_SCS_SPARE(r)   (((r) & BM_OCOTP_HW_OCOTP_SCS_SPARE) >> BP_OCOTP_HW_OCOTP_SCS_SPARE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SCS_SPARE.
#define BF_OCOTP_HW_OCOTP_SCS_SPARE(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SCS_SPARE) & BM_OCOTP_HW_OCOTP_SCS_SPARE)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SCS_SPARE.
#define BF_OCOTP_HW_OCOTP_SCS_SPARE(v)   (((v) << BP_OCOTP_HW_OCOTP_SCS_SPARE) & BM_OCOTP_HW_OCOTP_SCS_SPARE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SPARE field to a new value.
#define BW_OCOTP_HW_OCOTP_SCS_SPARE(v)   BF_CS1(OCOTP_HW_OCOTP_SCS, SPARE, v)
#endif

/* --- Register HW_OCOTP_HW_OCOTP_SCS, field LOCK[31] (RW)
 *
 * When set, all of the bits in this register are locked and can not be changed through SW
 * programming. This bit is only reset after a POR is issued.
 */

#define BP_OCOTP_HW_OCOTP_SCS_LOCK      (31)      //!< Bit position for OCOTP_HW_OCOTP_SCS_LOCK.
#define BM_OCOTP_HW_OCOTP_SCS_LOCK      (0x80000000)  //!< Bit mask for OCOTP_HW_OCOTP_SCS_LOCK.

//! @brief Get value of OCOTP_HW_OCOTP_SCS_LOCK from a register value.
#define BG_OCOTP_HW_OCOTP_SCS_LOCK(r)   (((r) & BM_OCOTP_HW_OCOTP_SCS_LOCK) >> BP_OCOTP_HW_OCOTP_SCS_LOCK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SCS_LOCK.
#define BF_OCOTP_HW_OCOTP_SCS_LOCK(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SCS_LOCK) & BM_OCOTP_HW_OCOTP_SCS_LOCK)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SCS_LOCK.
#define BF_OCOTP_HW_OCOTP_SCS_LOCK(v)   (((v) << BP_OCOTP_HW_OCOTP_SCS_LOCK) & BM_OCOTP_HW_OCOTP_SCS_LOCK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK field to a new value.
#define BW_OCOTP_HW_OCOTP_SCS_LOCK(v)   BF_CS1(OCOTP_HW_OCOTP_SCS, LOCK, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_CRC_ADDR - OTP Controller CRC test address (RW)
 *
 * Reset value: 0x00000000
 *
 * The OCOTP Data Register is used for OTP Read  The address for CRC calculation   EXAMPLE   Empty
 * Example.
 */
typedef union _hw_ocotp_hw_ocotp_crc_addr
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_crc_addr_bitfields
    {
        unsigned DATA_START_ADDR : 8; //!< [7:0] End address of fuse location for CRC calculation
        unsigned DATA_END_ADDR : 8; //!< [15:8] Start address of fuse location for CRC calculation
        unsigned CRC_ADDR : 3; //!< [18:16] Address of 32-bit CRC result for comparing
        unsigned RESERVED0 : 13; //!< [31:19] Reserved
    } B;
} hw_ocotp_hw_ocotp_crc_addr_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_CRC_ADDR register
 */
#define HW_OCOTP_HW_OCOTP_CRC_ADDR_ADDR      (REGS_OCOTP_BASE + 0x70)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_CRC_ADDR           (*(volatile hw_ocotp_hw_ocotp_crc_addr_t *) HW_OCOTP_HW_OCOTP_CRC_ADDR_ADDR)
#define HW_OCOTP_HW_OCOTP_CRC_ADDR_RD()      (HW_OCOTP_HW_OCOTP_CRC_ADDR.U)
#define HW_OCOTP_HW_OCOTP_CRC_ADDR_WR(v)     (HW_OCOTP_HW_OCOTP_CRC_ADDR.U = (v))
#define HW_OCOTP_HW_OCOTP_CRC_ADDR_SET(v)    (HW_OCOTP_HW_OCOTP_CRC_ADDR_WR(HW_OCOTP_HW_OCOTP_CRC_ADDR_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_CRC_ADDR_CLR(v)    (HW_OCOTP_HW_OCOTP_CRC_ADDR_WR(HW_OCOTP_HW_OCOTP_CRC_ADDR_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_CRC_ADDR_TOG(v)    (HW_OCOTP_HW_OCOTP_CRC_ADDR_WR(HW_OCOTP_HW_OCOTP_CRC_ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_CRC_ADDR bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_CRC_ADDR, field DATA_START_ADDR[7:0] (RW)
 *
 * End address of fuse location for CRC calculation
 */

#define BP_OCOTP_HW_OCOTP_CRC_ADDR_DATA_START_ADDR      (0)      //!< Bit position for OCOTP_HW_OCOTP_CRC_ADDR_DATA_START_ADDR.
#define BM_OCOTP_HW_OCOTP_CRC_ADDR_DATA_START_ADDR      (0x000000ff)  //!< Bit mask for OCOTP_HW_OCOTP_CRC_ADDR_DATA_START_ADDR.

//! @brief Get value of OCOTP_HW_OCOTP_CRC_ADDR_DATA_START_ADDR from a register value.
#define BG_OCOTP_HW_OCOTP_CRC_ADDR_DATA_START_ADDR(r)   (((r) & BM_OCOTP_HW_OCOTP_CRC_ADDR_DATA_START_ADDR) >> BP_OCOTP_HW_OCOTP_CRC_ADDR_DATA_START_ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CRC_ADDR_DATA_START_ADDR.
#define BF_OCOTP_HW_OCOTP_CRC_ADDR_DATA_START_ADDR(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_CRC_ADDR_DATA_START_ADDR) & BM_OCOTP_HW_OCOTP_CRC_ADDR_DATA_START_ADDR)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CRC_ADDR_DATA_START_ADDR.
#define BF_OCOTP_HW_OCOTP_CRC_ADDR_DATA_START_ADDR(v)   (((v) << BP_OCOTP_HW_OCOTP_CRC_ADDR_DATA_START_ADDR) & BM_OCOTP_HW_OCOTP_CRC_ADDR_DATA_START_ADDR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_START_ADDR field to a new value.
#define BW_OCOTP_HW_OCOTP_CRC_ADDR_DATA_START_ADDR(v)   (HW_OCOTP_HW_OCOTP_CRC_ADDR_WR((HW_OCOTP_HW_OCOTP_CRC_ADDR_RD() & ~BM_OCOTP_HW_OCOTP_CRC_ADDR_DATA_START_ADDR) | BF_OCOTP_HW_OCOTP_CRC_ADDR_DATA_START_ADDR(v)))
#endif

/* --- Register HW_OCOTP_HW_OCOTP_CRC_ADDR, field DATA_END_ADDR[15:8] (RW)
 *
 * Start address of fuse location for CRC calculation
 */

#define BP_OCOTP_HW_OCOTP_CRC_ADDR_DATA_END_ADDR      (8)      //!< Bit position for OCOTP_HW_OCOTP_CRC_ADDR_DATA_END_ADDR.
#define BM_OCOTP_HW_OCOTP_CRC_ADDR_DATA_END_ADDR      (0x0000ff00)  //!< Bit mask for OCOTP_HW_OCOTP_CRC_ADDR_DATA_END_ADDR.

//! @brief Get value of OCOTP_HW_OCOTP_CRC_ADDR_DATA_END_ADDR from a register value.
#define BG_OCOTP_HW_OCOTP_CRC_ADDR_DATA_END_ADDR(r)   (((r) & BM_OCOTP_HW_OCOTP_CRC_ADDR_DATA_END_ADDR) >> BP_OCOTP_HW_OCOTP_CRC_ADDR_DATA_END_ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CRC_ADDR_DATA_END_ADDR.
#define BF_OCOTP_HW_OCOTP_CRC_ADDR_DATA_END_ADDR(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_CRC_ADDR_DATA_END_ADDR) & BM_OCOTP_HW_OCOTP_CRC_ADDR_DATA_END_ADDR)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CRC_ADDR_DATA_END_ADDR.
#define BF_OCOTP_HW_OCOTP_CRC_ADDR_DATA_END_ADDR(v)   (((v) << BP_OCOTP_HW_OCOTP_CRC_ADDR_DATA_END_ADDR) & BM_OCOTP_HW_OCOTP_CRC_ADDR_DATA_END_ADDR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_END_ADDR field to a new value.
#define BW_OCOTP_HW_OCOTP_CRC_ADDR_DATA_END_ADDR(v)   (HW_OCOTP_HW_OCOTP_CRC_ADDR_WR((HW_OCOTP_HW_OCOTP_CRC_ADDR_RD() & ~BM_OCOTP_HW_OCOTP_CRC_ADDR_DATA_END_ADDR) | BF_OCOTP_HW_OCOTP_CRC_ADDR_DATA_END_ADDR(v)))
#endif

/* --- Register HW_OCOTP_HW_OCOTP_CRC_ADDR, field CRC_ADDR[18:16] (RW)
 *
 * Address of 32-bit CRC result for comparing
 */

#define BP_OCOTP_HW_OCOTP_CRC_ADDR_CRC_ADDR      (16)      //!< Bit position for OCOTP_HW_OCOTP_CRC_ADDR_CRC_ADDR.
#define BM_OCOTP_HW_OCOTP_CRC_ADDR_CRC_ADDR      (0x00070000)  //!< Bit mask for OCOTP_HW_OCOTP_CRC_ADDR_CRC_ADDR.

//! @brief Get value of OCOTP_HW_OCOTP_CRC_ADDR_CRC_ADDR from a register value.
#define BG_OCOTP_HW_OCOTP_CRC_ADDR_CRC_ADDR(r)   (((r) & BM_OCOTP_HW_OCOTP_CRC_ADDR_CRC_ADDR) >> BP_OCOTP_HW_OCOTP_CRC_ADDR_CRC_ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CRC_ADDR_CRC_ADDR.
#define BF_OCOTP_HW_OCOTP_CRC_ADDR_CRC_ADDR(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_CRC_ADDR_CRC_ADDR) & BM_OCOTP_HW_OCOTP_CRC_ADDR_CRC_ADDR)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CRC_ADDR_CRC_ADDR.
#define BF_OCOTP_HW_OCOTP_CRC_ADDR_CRC_ADDR(v)   (((v) << BP_OCOTP_HW_OCOTP_CRC_ADDR_CRC_ADDR) & BM_OCOTP_HW_OCOTP_CRC_ADDR_CRC_ADDR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CRC_ADDR field to a new value.
#define BW_OCOTP_HW_OCOTP_CRC_ADDR_CRC_ADDR(v)   (HW_OCOTP_HW_OCOTP_CRC_ADDR_WR((HW_OCOTP_HW_OCOTP_CRC_ADDR_RD() & ~BM_OCOTP_HW_OCOTP_CRC_ADDR_CRC_ADDR) | BF_OCOTP_HW_OCOTP_CRC_ADDR_CRC_ADDR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_CRC_VALUE - OTP Controller CRC Value Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The OCOTP Data Register is used for OTP Read  The crc32 value based on CRC_ADDR   EXAMPLE   Empty
 * Example.
 */
typedef union _hw_ocotp_hw_ocotp_crc_value
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_crc_value_bitfields
    {
        unsigned DATA : 32; //!< [31:0] The crc32 value based on CRC_ADDR
    } B;
} hw_ocotp_hw_ocotp_crc_value_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_CRC_VALUE register
 */
#define HW_OCOTP_HW_OCOTP_CRC_VALUE_ADDR      (REGS_OCOTP_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_CRC_VALUE           (*(volatile hw_ocotp_hw_ocotp_crc_value_t *) HW_OCOTP_HW_OCOTP_CRC_VALUE_ADDR)
#define HW_OCOTP_HW_OCOTP_CRC_VALUE_RD()      (HW_OCOTP_HW_OCOTP_CRC_VALUE.U)
#define HW_OCOTP_HW_OCOTP_CRC_VALUE_WR(v)     (HW_OCOTP_HW_OCOTP_CRC_VALUE.U = (v))
#define HW_OCOTP_HW_OCOTP_CRC_VALUE_SET(v)    (HW_OCOTP_HW_OCOTP_CRC_VALUE_WR(HW_OCOTP_HW_OCOTP_CRC_VALUE_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_CRC_VALUE_CLR(v)    (HW_OCOTP_HW_OCOTP_CRC_VALUE_WR(HW_OCOTP_HW_OCOTP_CRC_VALUE_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_CRC_VALUE_TOG(v)    (HW_OCOTP_HW_OCOTP_CRC_VALUE_WR(HW_OCOTP_HW_OCOTP_CRC_VALUE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_CRC_VALUE bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_CRC_VALUE, field DATA[31:0] (RW)
 *
 * The crc32 value based on CRC_ADDR
 */

#define BP_OCOTP_HW_OCOTP_CRC_VALUE_DATA      (0)      //!< Bit position for OCOTP_HW_OCOTP_CRC_VALUE_DATA.
#define BM_OCOTP_HW_OCOTP_CRC_VALUE_DATA      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_CRC_VALUE_DATA.

//! @brief Get value of OCOTP_HW_OCOTP_CRC_VALUE_DATA from a register value.
#define BG_OCOTP_HW_OCOTP_CRC_VALUE_DATA(r)   (((r) & BM_OCOTP_HW_OCOTP_CRC_VALUE_DATA) >> BP_OCOTP_HW_OCOTP_CRC_VALUE_DATA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CRC_VALUE_DATA.
#define BF_OCOTP_HW_OCOTP_CRC_VALUE_DATA(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_CRC_VALUE_DATA) & BM_OCOTP_HW_OCOTP_CRC_VALUE_DATA)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CRC_VALUE_DATA.
#define BF_OCOTP_HW_OCOTP_CRC_VALUE_DATA(v)   (((v) << BP_OCOTP_HW_OCOTP_CRC_VALUE_DATA) & BM_OCOTP_HW_OCOTP_CRC_VALUE_DATA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA field to a new value.
#define BW_OCOTP_HW_OCOTP_CRC_VALUE_DATA(v)   (HW_OCOTP_HW_OCOTP_CRC_VALUE_WR((HW_OCOTP_HW_OCOTP_CRC_VALUE_RD() & ~BM_OCOTP_HW_OCOTP_CRC_VALUE_DATA) | BF_OCOTP_HW_OCOTP_CRC_VALUE_DATA(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_UMC_TIMING - OTP Controller Timing Register (RW)
 *
 * Reset value: 0x00000042
 *
 * The OCOTP Data Register is used for OTP Programming  This register specifies timing parameters
 * for programming UMC OCOTP fuse array.   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_umc_timing
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_umc_timing_bitfields
    {
        unsigned STROBE_PROG_INT : 12; //!< [11:0] This count value specifies the strobe pulse interval in one time write OTP. Tpi = (STROBE_PROG+1) /ipg_clk_freq. It is given in number of ipg_clk periods.
        unsigned RESERVED0 : 20; //!< [31:12] These bits always read back zero.
    } B;
} hw_ocotp_hw_ocotp_umc_timing_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_UMC_TIMING register
 */
#define HW_OCOTP_HW_OCOTP_UMC_TIMING_ADDR      (REGS_OCOTP_BASE + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_UMC_TIMING           (*(volatile hw_ocotp_hw_ocotp_umc_timing_t *) HW_OCOTP_HW_OCOTP_UMC_TIMING_ADDR)
#define HW_OCOTP_HW_OCOTP_UMC_TIMING_RD()      (HW_OCOTP_HW_OCOTP_UMC_TIMING.U)
#define HW_OCOTP_HW_OCOTP_UMC_TIMING_WR(v)     (HW_OCOTP_HW_OCOTP_UMC_TIMING.U = (v))
#define HW_OCOTP_HW_OCOTP_UMC_TIMING_SET(v)    (HW_OCOTP_HW_OCOTP_UMC_TIMING_WR(HW_OCOTP_HW_OCOTP_UMC_TIMING_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_UMC_TIMING_CLR(v)    (HW_OCOTP_HW_OCOTP_UMC_TIMING_WR(HW_OCOTP_HW_OCOTP_UMC_TIMING_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_UMC_TIMING_TOG(v)    (HW_OCOTP_HW_OCOTP_UMC_TIMING_WR(HW_OCOTP_HW_OCOTP_UMC_TIMING_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_UMC_TIMING bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_UMC_TIMING, field STROBE_PROG_INT[11:0] (RW)
 *
 * This count value specifies the strobe pulse interval in one time write OTP. Tpi = (STROBE_PROG+1)
 * /ipg_clk_freq. It is given in number of ipg_clk periods.
 */

#define BP_OCOTP_HW_OCOTP_UMC_TIMING_STROBE_PROG_INT      (0)      //!< Bit position for OCOTP_HW_OCOTP_UMC_TIMING_STROBE_PROG_INT.
#define BM_OCOTP_HW_OCOTP_UMC_TIMING_STROBE_PROG_INT      (0x00000fff)  //!< Bit mask for OCOTP_HW_OCOTP_UMC_TIMING_STROBE_PROG_INT.

//! @brief Get value of OCOTP_HW_OCOTP_UMC_TIMING_STROBE_PROG_INT from a register value.
#define BG_OCOTP_HW_OCOTP_UMC_TIMING_STROBE_PROG_INT(r)   (((r) & BM_OCOTP_HW_OCOTP_UMC_TIMING_STROBE_PROG_INT) >> BP_OCOTP_HW_OCOTP_UMC_TIMING_STROBE_PROG_INT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_UMC_TIMING_STROBE_PROG_INT.
#define BF_OCOTP_HW_OCOTP_UMC_TIMING_STROBE_PROG_INT(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_UMC_TIMING_STROBE_PROG_INT) & BM_OCOTP_HW_OCOTP_UMC_TIMING_STROBE_PROG_INT)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_UMC_TIMING_STROBE_PROG_INT.
#define BF_OCOTP_HW_OCOTP_UMC_TIMING_STROBE_PROG_INT(v)   (((v) << BP_OCOTP_HW_OCOTP_UMC_TIMING_STROBE_PROG_INT) & BM_OCOTP_HW_OCOTP_UMC_TIMING_STROBE_PROG_INT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the STROBE_PROG_INT field to a new value.
#define BW_OCOTP_HW_OCOTP_UMC_TIMING_STROBE_PROG_INT(v)   (HW_OCOTP_HW_OCOTP_UMC_TIMING_WR((HW_OCOTP_HW_OCOTP_UMC_TIMING_RD() & ~BM_OCOTP_HW_OCOTP_UMC_TIMING_STROBE_PROG_INT) | BF_OCOTP_HW_OCOTP_UMC_TIMING_STROBE_PROG_INT(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_VERSION - OTP Controller Version Register (RW)
 *
 * Reset value: 0x03000000
 *
 * This register always returns a known read value for debug purposes it indicates the version of
 * the block.  This register indicates the RTL version in use.   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_version
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_version_bitfields
    {
        unsigned STEP : 16; //!< [15:0] Fixed read-only value reflecting the stepping of the RTL version.
        unsigned MINOR : 8; //!< [23:16] Fixed read-only value reflecting the MINOR field of the RTL version.
        unsigned MAJOR : 8; //!< [31:24] Fixed read-only value reflecting the MAJOR field of the RTL version.
    } B;
} hw_ocotp_hw_ocotp_version_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_VERSION register
 */
#define HW_OCOTP_HW_OCOTP_VERSION_ADDR      (REGS_OCOTP_BASE + 0xa0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_VERSION           (*(volatile hw_ocotp_hw_ocotp_version_t *) HW_OCOTP_HW_OCOTP_VERSION_ADDR)
#define HW_OCOTP_HW_OCOTP_VERSION_RD()      (HW_OCOTP_HW_OCOTP_VERSION.U)
#define HW_OCOTP_HW_OCOTP_VERSION_WR(v)     (HW_OCOTP_HW_OCOTP_VERSION.U = (v))
#define HW_OCOTP_HW_OCOTP_VERSION_SET(v)    (HW_OCOTP_HW_OCOTP_VERSION_WR(HW_OCOTP_HW_OCOTP_VERSION_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_VERSION_CLR(v)    (HW_OCOTP_HW_OCOTP_VERSION_WR(HW_OCOTP_HW_OCOTP_VERSION_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_VERSION_TOG(v)    (HW_OCOTP_HW_OCOTP_VERSION_WR(HW_OCOTP_HW_OCOTP_VERSION_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_VERSION bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_VERSION, field STEP[15:0] (RO)
 *
 * Fixed read-only value reflecting the stepping of the RTL version.
 */

#define BP_OCOTP_HW_OCOTP_VERSION_STEP      (0)      //!< Bit position for OCOTP_HW_OCOTP_VERSION_STEP.
#define BM_OCOTP_HW_OCOTP_VERSION_STEP      (0x0000ffff)  //!< Bit mask for OCOTP_HW_OCOTP_VERSION_STEP.

//! @brief Get value of OCOTP_HW_OCOTP_VERSION_STEP from a register value.
#define BG_OCOTP_HW_OCOTP_VERSION_STEP(r)   (((r) & BM_OCOTP_HW_OCOTP_VERSION_STEP) >> BP_OCOTP_HW_OCOTP_VERSION_STEP)

/* --- Register HW_OCOTP_HW_OCOTP_VERSION, field MINOR[23:16] (RO)
 *
 * Fixed read-only value reflecting the MINOR field of the RTL version.
 */

#define BP_OCOTP_HW_OCOTP_VERSION_MINOR      (16)      //!< Bit position for OCOTP_HW_OCOTP_VERSION_MINOR.
#define BM_OCOTP_HW_OCOTP_VERSION_MINOR      (0x00ff0000)  //!< Bit mask for OCOTP_HW_OCOTP_VERSION_MINOR.

//! @brief Get value of OCOTP_HW_OCOTP_VERSION_MINOR from a register value.
#define BG_OCOTP_HW_OCOTP_VERSION_MINOR(r)   (((r) & BM_OCOTP_HW_OCOTP_VERSION_MINOR) >> BP_OCOTP_HW_OCOTP_VERSION_MINOR)

/* --- Register HW_OCOTP_HW_OCOTP_VERSION, field MAJOR[31:24] (RO)
 *
 * Fixed read-only value reflecting the MAJOR field of the RTL version.
 */

#define BP_OCOTP_HW_OCOTP_VERSION_MAJOR      (24)      //!< Bit position for OCOTP_HW_OCOTP_VERSION_MAJOR.
#define BM_OCOTP_HW_OCOTP_VERSION_MAJOR      (0xff000000)  //!< Bit mask for OCOTP_HW_OCOTP_VERSION_MAJOR.

//! @brief Get value of OCOTP_HW_OCOTP_VERSION_MAJOR from a register value.
#define BG_OCOTP_HW_OCOTP_VERSION_MAJOR(r)   (((r) & BM_OCOTP_HW_OCOTP_VERSION_MAJOR) >> BP_OCOTP_HW_OCOTP_VERSION_MAJOR)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_LOCK - Value of OTP Bank0 Word0 (Lock controls) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 0, word 0 (ADDR = 0x00).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_lock
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_lock_bitfields
    {
        unsigned TESTER : 2; //!< [1:0] Status of shadow register and OTP write lock for tester region. When bit 1 is set, the writing of this region's shadow register is blocked. When bit 0 is set, the writing of this region's OTP fuse word is blocked.
        unsigned BOOT_CFG : 2; //!< [3:2] Status of shadow register and OTP write lock for boot_cfg region. When bit 1 is set, the writing of this region's shadow register is blocked. When bit 0 is set, the writing of this region's OTP fuse word is blocked.
        unsigned MEM_TRIM : 2; //!< [5:4] Status of shadow register and OTP write lock for mem_trim region. When bit 1 is set, the writing of this region's shadow register is blocked. When bit 0 is set, the writing of this region's OTP fuse word is blocked.
        unsigned SJC_RESP : 1; //!< [6] Status of shadow register read and write, OTP read and write lock for sjc_resp region. When set, the writing of this region's shadow register and OTP fuse word are blocked. The read of this region's shadow register and OTP fuse word are also blocked.
        unsigned RESERVED0 : 1; //!< [7] Reserved
        unsigned MAC_ADDR : 2; //!< [9:8] Status of shadow register and OTP write lock for mac_addr region. When bit 1 is set, the writing of this region's shadow register is blocked. When bit 0 is set, the writing of this region's OTP fuse word is blocked.
        unsigned GP1 : 2; //!< [11:10] Status of shadow register and OTP write lock for gp2 region. When bit 1 is set, the writing of this region's shadow register is blocked. When bit 0 is set, the writing of this region's OTP fuse word is blocked.
        unsigned GP2 : 2; //!< [13:12] Status of shadow register and OTP write lock for gp2 region. When bit 1 is set, the writing of this region's shadow register is blocked. When bit 0 is set, the writing of this region's OTP fuse word is blocked.
        unsigned SRK : 1; //!< [14] Status of shadow register and OTP write lock for srk region. When set, the writing of this region's shadow register and OTP fuse word are blocked.
        unsigned RESERVED1 : 1; //!< [15] Reserved
        unsigned SW_GP : 1; //!< [16] Status of shadow register lock for the region contained in the SW_GP registers. When set, the over-riding (writing) of this region's shadow bits is blocked. These shadow registers are always readable.
        unsigned DCP : 1; //!< [17] Status of shadow register read and write, OTP read and write lock for otpmk region. When set, the writing of this region's shadow register and OTP fuse word are blocked. The read of this region's shadow register and OTP fuse word are also blocked.
        unsigned ANALOG : 2; //!< [19:18] Status of shadow register and OTP write lock for analog region. When bit 1 is set, the writing of this region's shadow register is blocked. When bit 0 is set, the writing of this region's OTP fuse word is blocked.
        unsigned CRC_GP_LOCK : 2; //!< [21:20] Status of shadow register write and read, OTP program and read lock for CRC region. When bit 1 is set, the reading and writing of this region's OTP fuse and reading of shadow register are blocked.When bit 0 is set, the writing of this region's shadow register and OTP fuse are blocked.
        unsigned MISC_CONF : 1; //!< [22] Status of shadow register and OTP write lock for misc_conf region. When set, the writing of this region's shadow register and OTP fuse word are blocked.
        unsigned DTCP_DEV_CERT : 1; //!< [23] Status of shadow register and OTP write lock for dtcp_dev_cert region. When set, the writing of this region's shadow register and OTP fuse word are blocked.
        unsigned RESERVED2 : 1; //!< [24] Reserved
        unsigned PIN : 1; //!< [25] Status of Pin access lock bit. When set, pin access is disabled.
        unsigned GP_LO_LOCK : 2; //!< [27:26] Status of shadow register and OTP write lock for GP region. When bit 1 is set, the writing of this region's shadow register is blocked. When bit 0 is set, the writing of this region's OTP fuse word is blocked.
        unsigned GP_HI_LOCK : 2; //!< [29:28] Status of shadow register and OTP write lock for GP region. When bit 1 is set, the writing of this region's shadow register is blocked. When bit 0 is set, the writing of this region's OTP fuse word is blocked.
        unsigned UNALLOCATED : 2; //!< [31:30] Value of un-used portion of LOCK word
    } B;
} hw_ocotp_hw_ocotp_lock_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_LOCK register
 */
#define HW_OCOTP_HW_OCOTP_LOCK_ADDR      (REGS_OCOTP_BASE + 0x400)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_LOCK           (*(volatile hw_ocotp_hw_ocotp_lock_t *) HW_OCOTP_HW_OCOTP_LOCK_ADDR)
#define HW_OCOTP_HW_OCOTP_LOCK_RD()      (HW_OCOTP_HW_OCOTP_LOCK.U)
#define HW_OCOTP_HW_OCOTP_LOCK_WR(v)     (HW_OCOTP_HW_OCOTP_LOCK.U = (v))
#define HW_OCOTP_HW_OCOTP_LOCK_SET(v)    (HW_OCOTP_HW_OCOTP_LOCK_WR(HW_OCOTP_HW_OCOTP_LOCK_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_LOCK_CLR(v)    (HW_OCOTP_HW_OCOTP_LOCK_WR(HW_OCOTP_HW_OCOTP_LOCK_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_LOCK_TOG(v)    (HW_OCOTP_HW_OCOTP_LOCK_WR(HW_OCOTP_HW_OCOTP_LOCK_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_LOCK bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_LOCK, field TESTER[1:0] (RO)
 *
 * Status of shadow register and OTP write lock for tester region. When bit 1 is set, the writing of
 * this region's shadow register is blocked. When bit 0 is set, the writing of this region's OTP
 * fuse word is blocked.
 */

#define BP_OCOTP_HW_OCOTP_LOCK_TESTER      (0)      //!< Bit position for OCOTP_HW_OCOTP_LOCK_TESTER.
#define BM_OCOTP_HW_OCOTP_LOCK_TESTER      (0x00000003)  //!< Bit mask for OCOTP_HW_OCOTP_LOCK_TESTER.

//! @brief Get value of OCOTP_HW_OCOTP_LOCK_TESTER from a register value.
#define BG_OCOTP_HW_OCOTP_LOCK_TESTER(r)   (((r) & BM_OCOTP_HW_OCOTP_LOCK_TESTER) >> BP_OCOTP_HW_OCOTP_LOCK_TESTER)

/* --- Register HW_OCOTP_HW_OCOTP_LOCK, field BOOT_CFG[3:2] (RO)
 *
 * Status of shadow register and OTP write lock for boot_cfg region. When bit 1 is set, the writing
 * of this region's shadow register is blocked. When bit 0 is set, the writing of this region's OTP
 * fuse word is blocked.
 */

#define BP_OCOTP_HW_OCOTP_LOCK_BOOT_CFG      (2)      //!< Bit position for OCOTP_HW_OCOTP_LOCK_BOOT_CFG.
#define BM_OCOTP_HW_OCOTP_LOCK_BOOT_CFG      (0x0000000c)  //!< Bit mask for OCOTP_HW_OCOTP_LOCK_BOOT_CFG.

//! @brief Get value of OCOTP_HW_OCOTP_LOCK_BOOT_CFG from a register value.
#define BG_OCOTP_HW_OCOTP_LOCK_BOOT_CFG(r)   (((r) & BM_OCOTP_HW_OCOTP_LOCK_BOOT_CFG) >> BP_OCOTP_HW_OCOTP_LOCK_BOOT_CFG)

/* --- Register HW_OCOTP_HW_OCOTP_LOCK, field MEM_TRIM[5:4] (RO)
 *
 * Status of shadow register and OTP write lock for mem_trim region. When bit 1 is set, the writing
 * of this region's shadow register is blocked. When bit 0 is set, the writing of this region's OTP
 * fuse word is blocked.
 */

#define BP_OCOTP_HW_OCOTP_LOCK_MEM_TRIM      (4)      //!< Bit position for OCOTP_HW_OCOTP_LOCK_MEM_TRIM.
#define BM_OCOTP_HW_OCOTP_LOCK_MEM_TRIM      (0x00000030)  //!< Bit mask for OCOTP_HW_OCOTP_LOCK_MEM_TRIM.

//! @brief Get value of OCOTP_HW_OCOTP_LOCK_MEM_TRIM from a register value.
#define BG_OCOTP_HW_OCOTP_LOCK_MEM_TRIM(r)   (((r) & BM_OCOTP_HW_OCOTP_LOCK_MEM_TRIM) >> BP_OCOTP_HW_OCOTP_LOCK_MEM_TRIM)

/* --- Register HW_OCOTP_HW_OCOTP_LOCK, field SJC_RESP[6] (RO)
 *
 * Status of shadow register read and write, OTP read and write lock for sjc_resp region. When set,
 * the writing of this region's shadow register and OTP fuse word are blocked. The read of this
 * region's shadow register and OTP fuse word are also blocked.
 */

#define BP_OCOTP_HW_OCOTP_LOCK_SJC_RESP      (6)      //!< Bit position for OCOTP_HW_OCOTP_LOCK_SJC_RESP.
#define BM_OCOTP_HW_OCOTP_LOCK_SJC_RESP      (0x00000040)  //!< Bit mask for OCOTP_HW_OCOTP_LOCK_SJC_RESP.

//! @brief Get value of OCOTP_HW_OCOTP_LOCK_SJC_RESP from a register value.
#define BG_OCOTP_HW_OCOTP_LOCK_SJC_RESP(r)   (((r) & BM_OCOTP_HW_OCOTP_LOCK_SJC_RESP) >> BP_OCOTP_HW_OCOTP_LOCK_SJC_RESP)

/* --- Register HW_OCOTP_HW_OCOTP_LOCK, field MAC_ADDR[9:8] (RO)
 *
 * Status of shadow register and OTP write lock for mac_addr region. When bit 1 is set, the writing
 * of this region's shadow register is blocked. When bit 0 is set, the writing of this region's OTP
 * fuse word is blocked.
 */

#define BP_OCOTP_HW_OCOTP_LOCK_MAC_ADDR      (8)      //!< Bit position for OCOTP_HW_OCOTP_LOCK_MAC_ADDR.
#define BM_OCOTP_HW_OCOTP_LOCK_MAC_ADDR      (0x00000300)  //!< Bit mask for OCOTP_HW_OCOTP_LOCK_MAC_ADDR.

//! @brief Get value of OCOTP_HW_OCOTP_LOCK_MAC_ADDR from a register value.
#define BG_OCOTP_HW_OCOTP_LOCK_MAC_ADDR(r)   (((r) & BM_OCOTP_HW_OCOTP_LOCK_MAC_ADDR) >> BP_OCOTP_HW_OCOTP_LOCK_MAC_ADDR)

/* --- Register HW_OCOTP_HW_OCOTP_LOCK, field GP1[11:10] (RO)
 *
 * Status of shadow register and OTP write lock for gp2 region. When bit 1 is set, the writing of
 * this region's shadow register is blocked. When bit 0 is set, the writing of this region's OTP
 * fuse word is blocked.
 */

#define BP_OCOTP_HW_OCOTP_LOCK_GP1      (10)      //!< Bit position for OCOTP_HW_OCOTP_LOCK_GP1.
#define BM_OCOTP_HW_OCOTP_LOCK_GP1      (0x00000c00)  //!< Bit mask for OCOTP_HW_OCOTP_LOCK_GP1.

//! @brief Get value of OCOTP_HW_OCOTP_LOCK_GP1 from a register value.
#define BG_OCOTP_HW_OCOTP_LOCK_GP1(r)   (((r) & BM_OCOTP_HW_OCOTP_LOCK_GP1) >> BP_OCOTP_HW_OCOTP_LOCK_GP1)

/* --- Register HW_OCOTP_HW_OCOTP_LOCK, field GP2[13:12] (RO)
 *
 * Status of shadow register and OTP write lock for gp2 region. When bit 1 is set, the writing of
 * this region's shadow register is blocked. When bit 0 is set, the writing of this region's OTP
 * fuse word is blocked.
 */

#define BP_OCOTP_HW_OCOTP_LOCK_GP2      (12)      //!< Bit position for OCOTP_HW_OCOTP_LOCK_GP2.
#define BM_OCOTP_HW_OCOTP_LOCK_GP2      (0x00003000)  //!< Bit mask for OCOTP_HW_OCOTP_LOCK_GP2.

//! @brief Get value of OCOTP_HW_OCOTP_LOCK_GP2 from a register value.
#define BG_OCOTP_HW_OCOTP_LOCK_GP2(r)   (((r) & BM_OCOTP_HW_OCOTP_LOCK_GP2) >> BP_OCOTP_HW_OCOTP_LOCK_GP2)

/* --- Register HW_OCOTP_HW_OCOTP_LOCK, field SRK[14] (RO)
 *
 * Status of shadow register and OTP write lock for srk region. When set, the writing of this
 * region's shadow register and OTP fuse word are blocked.
 */

#define BP_OCOTP_HW_OCOTP_LOCK_SRK      (14)      //!< Bit position for OCOTP_HW_OCOTP_LOCK_SRK.
#define BM_OCOTP_HW_OCOTP_LOCK_SRK      (0x00004000)  //!< Bit mask for OCOTP_HW_OCOTP_LOCK_SRK.

//! @brief Get value of OCOTP_HW_OCOTP_LOCK_SRK from a register value.
#define BG_OCOTP_HW_OCOTP_LOCK_SRK(r)   (((r) & BM_OCOTP_HW_OCOTP_LOCK_SRK) >> BP_OCOTP_HW_OCOTP_LOCK_SRK)

/* --- Register HW_OCOTP_HW_OCOTP_LOCK, field SW_GP[16] (RO)
 *
 * Status of shadow register lock for the region contained in the SW_GP registers. When set, the
 * over-riding (writing) of this region's shadow bits is blocked. These shadow registers are always
 * readable.
 */

#define BP_OCOTP_HW_OCOTP_LOCK_SW_GP      (16)      //!< Bit position for OCOTP_HW_OCOTP_LOCK_SW_GP.
#define BM_OCOTP_HW_OCOTP_LOCK_SW_GP      (0x00010000)  //!< Bit mask for OCOTP_HW_OCOTP_LOCK_SW_GP.

//! @brief Get value of OCOTP_HW_OCOTP_LOCK_SW_GP from a register value.
#define BG_OCOTP_HW_OCOTP_LOCK_SW_GP(r)   (((r) & BM_OCOTP_HW_OCOTP_LOCK_SW_GP) >> BP_OCOTP_HW_OCOTP_LOCK_SW_GP)

/* --- Register HW_OCOTP_HW_OCOTP_LOCK, field DCP[17] (RO)
 *
 * Status of shadow register read and write, OTP read and write lock for otpmk region. When set, the
 * writing of this region's shadow register and OTP fuse word are blocked. The read of this region's
 * shadow register and OTP fuse word are also blocked.
 */

#define BP_OCOTP_HW_OCOTP_LOCK_DCP      (17)      //!< Bit position for OCOTP_HW_OCOTP_LOCK_DCP.
#define BM_OCOTP_HW_OCOTP_LOCK_DCP      (0x00020000)  //!< Bit mask for OCOTP_HW_OCOTP_LOCK_DCP.

//! @brief Get value of OCOTP_HW_OCOTP_LOCK_DCP from a register value.
#define BG_OCOTP_HW_OCOTP_LOCK_DCP(r)   (((r) & BM_OCOTP_HW_OCOTP_LOCK_DCP) >> BP_OCOTP_HW_OCOTP_LOCK_DCP)

/* --- Register HW_OCOTP_HW_OCOTP_LOCK, field ANALOG[19:18] (RO)
 *
 * Status of shadow register and OTP write lock for analog region. When bit 1 is set, the writing of
 * this region's shadow register is blocked. When bit 0 is set, the writing of this region's OTP
 * fuse word is blocked.
 */

#define BP_OCOTP_HW_OCOTP_LOCK_ANALOG      (18)      //!< Bit position for OCOTP_HW_OCOTP_LOCK_ANALOG.
#define BM_OCOTP_HW_OCOTP_LOCK_ANALOG      (0x000c0000)  //!< Bit mask for OCOTP_HW_OCOTP_LOCK_ANALOG.

//! @brief Get value of OCOTP_HW_OCOTP_LOCK_ANALOG from a register value.
#define BG_OCOTP_HW_OCOTP_LOCK_ANALOG(r)   (((r) & BM_OCOTP_HW_OCOTP_LOCK_ANALOG) >> BP_OCOTP_HW_OCOTP_LOCK_ANALOG)

/* --- Register HW_OCOTP_HW_OCOTP_LOCK, field CRC_GP_LOCK[21:20] (RO)
 *
 * Status of shadow register write and read, OTP program and read lock for CRC region. When bit 1 is
 * set, the reading and writing of this region's OTP fuse and reading of shadow register are
 * blocked.When bit 0 is set, the writing of this region's shadow register and OTP fuse are blocked.
 */

#define BP_OCOTP_HW_OCOTP_LOCK_CRC_GP_LOCK      (20)      //!< Bit position for OCOTP_HW_OCOTP_LOCK_CRC_GP_LOCK.
#define BM_OCOTP_HW_OCOTP_LOCK_CRC_GP_LOCK      (0x00300000)  //!< Bit mask for OCOTP_HW_OCOTP_LOCK_CRC_GP_LOCK.

//! @brief Get value of OCOTP_HW_OCOTP_LOCK_CRC_GP_LOCK from a register value.
#define BG_OCOTP_HW_OCOTP_LOCK_CRC_GP_LOCK(r)   (((r) & BM_OCOTP_HW_OCOTP_LOCK_CRC_GP_LOCK) >> BP_OCOTP_HW_OCOTP_LOCK_CRC_GP_LOCK)

/* --- Register HW_OCOTP_HW_OCOTP_LOCK, field MISC_CONF[22] (RO)
 *
 * Status of shadow register and OTP write lock for misc_conf region. When set, the writing of this
 * region's shadow register and OTP fuse word are blocked.
 */

#define BP_OCOTP_HW_OCOTP_LOCK_MISC_CONF      (22)      //!< Bit position for OCOTP_HW_OCOTP_LOCK_MISC_CONF.
#define BM_OCOTP_HW_OCOTP_LOCK_MISC_CONF      (0x00400000)  //!< Bit mask for OCOTP_HW_OCOTP_LOCK_MISC_CONF.

//! @brief Get value of OCOTP_HW_OCOTP_LOCK_MISC_CONF from a register value.
#define BG_OCOTP_HW_OCOTP_LOCK_MISC_CONF(r)   (((r) & BM_OCOTP_HW_OCOTP_LOCK_MISC_CONF) >> BP_OCOTP_HW_OCOTP_LOCK_MISC_CONF)

/* --- Register HW_OCOTP_HW_OCOTP_LOCK, field DTCP_DEV_CERT[23] (RO)
 *
 * Status of shadow register and OTP write lock for dtcp_dev_cert region. When set, the writing of
 * this region's shadow register and OTP fuse word are blocked.
 */

#define BP_OCOTP_HW_OCOTP_LOCK_DTCP_DEV_CERT      (23)      //!< Bit position for OCOTP_HW_OCOTP_LOCK_DTCP_DEV_CERT.
#define BM_OCOTP_HW_OCOTP_LOCK_DTCP_DEV_CERT      (0x00800000)  //!< Bit mask for OCOTP_HW_OCOTP_LOCK_DTCP_DEV_CERT.

//! @brief Get value of OCOTP_HW_OCOTP_LOCK_DTCP_DEV_CERT from a register value.
#define BG_OCOTP_HW_OCOTP_LOCK_DTCP_DEV_CERT(r)   (((r) & BM_OCOTP_HW_OCOTP_LOCK_DTCP_DEV_CERT) >> BP_OCOTP_HW_OCOTP_LOCK_DTCP_DEV_CERT)

/* --- Register HW_OCOTP_HW_OCOTP_LOCK, field PIN[25] (RO)
 *
 * Status of Pin access lock bit. When set, pin access is disabled.
 */

#define BP_OCOTP_HW_OCOTP_LOCK_PIN      (25)      //!< Bit position for OCOTP_HW_OCOTP_LOCK_PIN.
#define BM_OCOTP_HW_OCOTP_LOCK_PIN      (0x02000000)  //!< Bit mask for OCOTP_HW_OCOTP_LOCK_PIN.

//! @brief Get value of OCOTP_HW_OCOTP_LOCK_PIN from a register value.
#define BG_OCOTP_HW_OCOTP_LOCK_PIN(r)   (((r) & BM_OCOTP_HW_OCOTP_LOCK_PIN) >> BP_OCOTP_HW_OCOTP_LOCK_PIN)

/* --- Register HW_OCOTP_HW_OCOTP_LOCK, field GP_LO_LOCK[27:26] (RO)
 *
 * Status of shadow register and OTP write lock for GP region. When bit 1 is set, the writing of
 * this region's shadow register is blocked. When bit 0 is set, the writing of this region's OTP
 * fuse word is blocked.
 */

#define BP_OCOTP_HW_OCOTP_LOCK_GP_LO_LOCK      (26)      //!< Bit position for OCOTP_HW_OCOTP_LOCK_GP_LO_LOCK.
#define BM_OCOTP_HW_OCOTP_LOCK_GP_LO_LOCK      (0x0c000000)  //!< Bit mask for OCOTP_HW_OCOTP_LOCK_GP_LO_LOCK.

//! @brief Get value of OCOTP_HW_OCOTP_LOCK_GP_LO_LOCK from a register value.
#define BG_OCOTP_HW_OCOTP_LOCK_GP_LO_LOCK(r)   (((r) & BM_OCOTP_HW_OCOTP_LOCK_GP_LO_LOCK) >> BP_OCOTP_HW_OCOTP_LOCK_GP_LO_LOCK)

/* --- Register HW_OCOTP_HW_OCOTP_LOCK, field GP_HI_LOCK[29:28] (RO)
 *
 * Status of shadow register and OTP write lock for GP region. When bit 1 is set, the writing of
 * this region's shadow register is blocked. When bit 0 is set, the writing of this region's OTP
 * fuse word is blocked.
 */

#define BP_OCOTP_HW_OCOTP_LOCK_GP_HI_LOCK      (28)      //!< Bit position for OCOTP_HW_OCOTP_LOCK_GP_HI_LOCK.
#define BM_OCOTP_HW_OCOTP_LOCK_GP_HI_LOCK      (0x30000000)  //!< Bit mask for OCOTP_HW_OCOTP_LOCK_GP_HI_LOCK.

//! @brief Get value of OCOTP_HW_OCOTP_LOCK_GP_HI_LOCK from a register value.
#define BG_OCOTP_HW_OCOTP_LOCK_GP_HI_LOCK(r)   (((r) & BM_OCOTP_HW_OCOTP_LOCK_GP_HI_LOCK) >> BP_OCOTP_HW_OCOTP_LOCK_GP_HI_LOCK)

/* --- Register HW_OCOTP_HW_OCOTP_LOCK, field UNALLOCATED[31:30] (RO)
 *
 * Value of un-used portion of LOCK word
 */

#define BP_OCOTP_HW_OCOTP_LOCK_UNALLOCATED      (30)      //!< Bit position for OCOTP_HW_OCOTP_LOCK_UNALLOCATED.
#define BM_OCOTP_HW_OCOTP_LOCK_UNALLOCATED      (0xc0000000)  //!< Bit mask for OCOTP_HW_OCOTP_LOCK_UNALLOCATED.

//! @brief Get value of OCOTP_HW_OCOTP_LOCK_UNALLOCATED from a register value.
#define BG_OCOTP_HW_OCOTP_LOCK_UNALLOCATED(r)   (((r) & BM_OCOTP_HW_OCOTP_LOCK_UNALLOCATED) >> BP_OCOTP_HW_OCOTP_LOCK_UNALLOCATED)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_CFG0 - Value of OTP Bank0 Word1 (Configuration and Manufacturing Info.) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 0, word 1 (ADDR = 0x01).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_cfg0
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_cfg0_bitfields
    {
        unsigned BITS : 32; //!< [31:0] This register contains 32 bits of the Unique ID and SJC_CHALLENGE field. Reflects value of OTP Bank 0, word 1 (ADDR = 0x01). These bits become read-only after the HW_OCOTP_LOCK_TESTER[1] bit is set.
    } B;
} hw_ocotp_hw_ocotp_cfg0_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_CFG0 register
 */
#define HW_OCOTP_HW_OCOTP_CFG0_ADDR      (REGS_OCOTP_BASE + 0x410)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_CFG0           (*(volatile hw_ocotp_hw_ocotp_cfg0_t *) HW_OCOTP_HW_OCOTP_CFG0_ADDR)
#define HW_OCOTP_HW_OCOTP_CFG0_RD()      (HW_OCOTP_HW_OCOTP_CFG0.U)
#define HW_OCOTP_HW_OCOTP_CFG0_WR(v)     (HW_OCOTP_HW_OCOTP_CFG0.U = (v))
#define HW_OCOTP_HW_OCOTP_CFG0_SET(v)    (HW_OCOTP_HW_OCOTP_CFG0_WR(HW_OCOTP_HW_OCOTP_CFG0_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_CFG0_CLR(v)    (HW_OCOTP_HW_OCOTP_CFG0_WR(HW_OCOTP_HW_OCOTP_CFG0_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_CFG0_TOG(v)    (HW_OCOTP_HW_OCOTP_CFG0_WR(HW_OCOTP_HW_OCOTP_CFG0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_CFG0 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_CFG0, field BITS[31:0] (RW)
 *
 * This register contains 32 bits of the Unique ID and SJC_CHALLENGE field. Reflects value of OTP
 * Bank 0, word 1 (ADDR = 0x01). These bits become read-only after the HW_OCOTP_LOCK_TESTER[1] bit
 * is set.
 */

#define BP_OCOTP_HW_OCOTP_CFG0_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_CFG0_BITS.
#define BM_OCOTP_HW_OCOTP_CFG0_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_CFG0_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_CFG0_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_CFG0_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_CFG0_BITS) >> BP_OCOTP_HW_OCOTP_CFG0_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CFG0_BITS.
#define BF_OCOTP_HW_OCOTP_CFG0_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_CFG0_BITS) & BM_OCOTP_HW_OCOTP_CFG0_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CFG0_BITS.
#define BF_OCOTP_HW_OCOTP_CFG0_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_CFG0_BITS) & BM_OCOTP_HW_OCOTP_CFG0_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_CFG0_BITS(v)   (HW_OCOTP_HW_OCOTP_CFG0_WR((HW_OCOTP_HW_OCOTP_CFG0_RD() & ~BM_OCOTP_HW_OCOTP_CFG0_BITS) | BF_OCOTP_HW_OCOTP_CFG0_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_CFG1 - Value of OTP Bank0 Word2 (Configuration and Manufacturing Info.) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  shadowed memory mapped access to OTP Bank 0, word 2 (ADDR = 0x02).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_cfg1
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_cfg1_bitfields
    {
        unsigned BITS : 32; //!< [31:0] This register contains 32 bits of the Unique ID and SJC_CHALLENGE field. Reflects value of OTP Bank 0, word 2 (ADDR = 0x02). These bits become read-only after the HW_OCOTP_LOCK_TESTER[1] bit is set.
    } B;
} hw_ocotp_hw_ocotp_cfg1_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_CFG1 register
 */
#define HW_OCOTP_HW_OCOTP_CFG1_ADDR      (REGS_OCOTP_BASE + 0x420)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_CFG1           (*(volatile hw_ocotp_hw_ocotp_cfg1_t *) HW_OCOTP_HW_OCOTP_CFG1_ADDR)
#define HW_OCOTP_HW_OCOTP_CFG1_RD()      (HW_OCOTP_HW_OCOTP_CFG1.U)
#define HW_OCOTP_HW_OCOTP_CFG1_WR(v)     (HW_OCOTP_HW_OCOTP_CFG1.U = (v))
#define HW_OCOTP_HW_OCOTP_CFG1_SET(v)    (HW_OCOTP_HW_OCOTP_CFG1_WR(HW_OCOTP_HW_OCOTP_CFG1_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_CFG1_CLR(v)    (HW_OCOTP_HW_OCOTP_CFG1_WR(HW_OCOTP_HW_OCOTP_CFG1_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_CFG1_TOG(v)    (HW_OCOTP_HW_OCOTP_CFG1_WR(HW_OCOTP_HW_OCOTP_CFG1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_CFG1 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_CFG1, field BITS[31:0] (RW)
 *
 * This register contains 32 bits of the Unique ID and SJC_CHALLENGE field. Reflects value of OTP
 * Bank 0, word 2 (ADDR = 0x02). These bits become read-only after the HW_OCOTP_LOCK_TESTER[1] bit
 * is set.
 */

#define BP_OCOTP_HW_OCOTP_CFG1_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_CFG1_BITS.
#define BM_OCOTP_HW_OCOTP_CFG1_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_CFG1_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_CFG1_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_CFG1_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_CFG1_BITS) >> BP_OCOTP_HW_OCOTP_CFG1_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CFG1_BITS.
#define BF_OCOTP_HW_OCOTP_CFG1_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_CFG1_BITS) & BM_OCOTP_HW_OCOTP_CFG1_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CFG1_BITS.
#define BF_OCOTP_HW_OCOTP_CFG1_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_CFG1_BITS) & BM_OCOTP_HW_OCOTP_CFG1_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_CFG1_BITS(v)   (HW_OCOTP_HW_OCOTP_CFG1_WR((HW_OCOTP_HW_OCOTP_CFG1_RD() & ~BM_OCOTP_HW_OCOTP_CFG1_BITS) | BF_OCOTP_HW_OCOTP_CFG1_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_CFG2 - Value of OTP Bank0 Word3 (Configuration and Manufacturing Info.) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 0, word 3 (ADDR = 0x03).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_cfg2
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_cfg2_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 0, word 3 (ADDR = 0x03). These bits become read-only after the HW_OCOTP_LOCK_TESTER[1] bit is set.
    } B;
} hw_ocotp_hw_ocotp_cfg2_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_CFG2 register
 */
#define HW_OCOTP_HW_OCOTP_CFG2_ADDR      (REGS_OCOTP_BASE + 0x430)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_CFG2           (*(volatile hw_ocotp_hw_ocotp_cfg2_t *) HW_OCOTP_HW_OCOTP_CFG2_ADDR)
#define HW_OCOTP_HW_OCOTP_CFG2_RD()      (HW_OCOTP_HW_OCOTP_CFG2.U)
#define HW_OCOTP_HW_OCOTP_CFG2_WR(v)     (HW_OCOTP_HW_OCOTP_CFG2.U = (v))
#define HW_OCOTP_HW_OCOTP_CFG2_SET(v)    (HW_OCOTP_HW_OCOTP_CFG2_WR(HW_OCOTP_HW_OCOTP_CFG2_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_CFG2_CLR(v)    (HW_OCOTP_HW_OCOTP_CFG2_WR(HW_OCOTP_HW_OCOTP_CFG2_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_CFG2_TOG(v)    (HW_OCOTP_HW_OCOTP_CFG2_WR(HW_OCOTP_HW_OCOTP_CFG2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_CFG2 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_CFG2, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 0, word 3 (ADDR = 0x03). These bits become read-only after the
 * HW_OCOTP_LOCK_TESTER[1] bit is set.
 */

#define BP_OCOTP_HW_OCOTP_CFG2_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_CFG2_BITS.
#define BM_OCOTP_HW_OCOTP_CFG2_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_CFG2_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_CFG2_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_CFG2_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_CFG2_BITS) >> BP_OCOTP_HW_OCOTP_CFG2_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CFG2_BITS.
#define BF_OCOTP_HW_OCOTP_CFG2_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_CFG2_BITS) & BM_OCOTP_HW_OCOTP_CFG2_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CFG2_BITS.
#define BF_OCOTP_HW_OCOTP_CFG2_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_CFG2_BITS) & BM_OCOTP_HW_OCOTP_CFG2_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_CFG2_BITS(v)   (HW_OCOTP_HW_OCOTP_CFG2_WR((HW_OCOTP_HW_OCOTP_CFG2_RD() & ~BM_OCOTP_HW_OCOTP_CFG2_BITS) | BF_OCOTP_HW_OCOTP_CFG2_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_CFG3 - Value of OTP Bank0 Word4 (Configuration and Manufacturing Info.) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Non-shadowed memory mapped access to OTP Bank 0, word 4 (ADDR =
 * 0x04).   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_cfg3
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_cfg3_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 0, word 4 (ADDR = 0x04). These bits become read-only after the HW_OCOTP_LOCK_TESTER[1] bit is set.
    } B;
} hw_ocotp_hw_ocotp_cfg3_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_CFG3 register
 */
#define HW_OCOTP_HW_OCOTP_CFG3_ADDR      (REGS_OCOTP_BASE + 0x440)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_CFG3           (*(volatile hw_ocotp_hw_ocotp_cfg3_t *) HW_OCOTP_HW_OCOTP_CFG3_ADDR)
#define HW_OCOTP_HW_OCOTP_CFG3_RD()      (HW_OCOTP_HW_OCOTP_CFG3.U)
#define HW_OCOTP_HW_OCOTP_CFG3_WR(v)     (HW_OCOTP_HW_OCOTP_CFG3.U = (v))
#define HW_OCOTP_HW_OCOTP_CFG3_SET(v)    (HW_OCOTP_HW_OCOTP_CFG3_WR(HW_OCOTP_HW_OCOTP_CFG3_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_CFG3_CLR(v)    (HW_OCOTP_HW_OCOTP_CFG3_WR(HW_OCOTP_HW_OCOTP_CFG3_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_CFG3_TOG(v)    (HW_OCOTP_HW_OCOTP_CFG3_WR(HW_OCOTP_HW_OCOTP_CFG3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_CFG3 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_CFG3, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 0, word 4 (ADDR = 0x04). These bits become read-only after the
 * HW_OCOTP_LOCK_TESTER[1] bit is set.
 */

#define BP_OCOTP_HW_OCOTP_CFG3_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_CFG3_BITS.
#define BM_OCOTP_HW_OCOTP_CFG3_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_CFG3_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_CFG3_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_CFG3_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_CFG3_BITS) >> BP_OCOTP_HW_OCOTP_CFG3_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CFG3_BITS.
#define BF_OCOTP_HW_OCOTP_CFG3_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_CFG3_BITS) & BM_OCOTP_HW_OCOTP_CFG3_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CFG3_BITS.
#define BF_OCOTP_HW_OCOTP_CFG3_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_CFG3_BITS) & BM_OCOTP_HW_OCOTP_CFG3_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_CFG3_BITS(v)   (HW_OCOTP_HW_OCOTP_CFG3_WR((HW_OCOTP_HW_OCOTP_CFG3_RD() & ~BM_OCOTP_HW_OCOTP_CFG3_BITS) | BF_OCOTP_HW_OCOTP_CFG3_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_CFG4 - Value of OTP Bank0 Word5 (Configuration and Manufacturing Info.) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 0, word 5 (ADDR = 0x05).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_cfg4
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_cfg4_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 0, word 5 (ADDR = 0x05). These bits become read-only after the HW_OCOTP_LOCK_BOOT_CFG[1] bit is set.
    } B;
} hw_ocotp_hw_ocotp_cfg4_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_CFG4 register
 */
#define HW_OCOTP_HW_OCOTP_CFG4_ADDR      (REGS_OCOTP_BASE + 0x450)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_CFG4           (*(volatile hw_ocotp_hw_ocotp_cfg4_t *) HW_OCOTP_HW_OCOTP_CFG4_ADDR)
#define HW_OCOTP_HW_OCOTP_CFG4_RD()      (HW_OCOTP_HW_OCOTP_CFG4.U)
#define HW_OCOTP_HW_OCOTP_CFG4_WR(v)     (HW_OCOTP_HW_OCOTP_CFG4.U = (v))
#define HW_OCOTP_HW_OCOTP_CFG4_SET(v)    (HW_OCOTP_HW_OCOTP_CFG4_WR(HW_OCOTP_HW_OCOTP_CFG4_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_CFG4_CLR(v)    (HW_OCOTP_HW_OCOTP_CFG4_WR(HW_OCOTP_HW_OCOTP_CFG4_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_CFG4_TOG(v)    (HW_OCOTP_HW_OCOTP_CFG4_WR(HW_OCOTP_HW_OCOTP_CFG4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_CFG4 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_CFG4, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 0, word 5 (ADDR = 0x05). These bits become read-only after the
 * HW_OCOTP_LOCK_BOOT_CFG[1] bit is set.
 */

#define BP_OCOTP_HW_OCOTP_CFG4_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_CFG4_BITS.
#define BM_OCOTP_HW_OCOTP_CFG4_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_CFG4_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_CFG4_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_CFG4_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_CFG4_BITS) >> BP_OCOTP_HW_OCOTP_CFG4_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CFG4_BITS.
#define BF_OCOTP_HW_OCOTP_CFG4_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_CFG4_BITS) & BM_OCOTP_HW_OCOTP_CFG4_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CFG4_BITS.
#define BF_OCOTP_HW_OCOTP_CFG4_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_CFG4_BITS) & BM_OCOTP_HW_OCOTP_CFG4_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_CFG4_BITS(v)   (HW_OCOTP_HW_OCOTP_CFG4_WR((HW_OCOTP_HW_OCOTP_CFG4_RD() & ~BM_OCOTP_HW_OCOTP_CFG4_BITS) | BF_OCOTP_HW_OCOTP_CFG4_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_CFG5 - Value of OTP Bank0 Word6 (Configuration and Manufacturing Info.) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 0, word 6 (ADDR = 0x06).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_cfg5
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_cfg5_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 0, word 6 (ADDR = 0x06). These bits become read-only after the HW_OCOTP_LOCK_BOOT_CFG[1] bit is set.
    } B;
} hw_ocotp_hw_ocotp_cfg5_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_CFG5 register
 */
#define HW_OCOTP_HW_OCOTP_CFG5_ADDR      (REGS_OCOTP_BASE + 0x460)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_CFG5           (*(volatile hw_ocotp_hw_ocotp_cfg5_t *) HW_OCOTP_HW_OCOTP_CFG5_ADDR)
#define HW_OCOTP_HW_OCOTP_CFG5_RD()      (HW_OCOTP_HW_OCOTP_CFG5.U)
#define HW_OCOTP_HW_OCOTP_CFG5_WR(v)     (HW_OCOTP_HW_OCOTP_CFG5.U = (v))
#define HW_OCOTP_HW_OCOTP_CFG5_SET(v)    (HW_OCOTP_HW_OCOTP_CFG5_WR(HW_OCOTP_HW_OCOTP_CFG5_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_CFG5_CLR(v)    (HW_OCOTP_HW_OCOTP_CFG5_WR(HW_OCOTP_HW_OCOTP_CFG5_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_CFG5_TOG(v)    (HW_OCOTP_HW_OCOTP_CFG5_WR(HW_OCOTP_HW_OCOTP_CFG5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_CFG5 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_CFG5, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 0, word 6 (ADDR = 0x06). These bits become read-only after the
 * HW_OCOTP_LOCK_BOOT_CFG[1] bit is set.
 */

#define BP_OCOTP_HW_OCOTP_CFG5_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_CFG5_BITS.
#define BM_OCOTP_HW_OCOTP_CFG5_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_CFG5_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_CFG5_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_CFG5_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_CFG5_BITS) >> BP_OCOTP_HW_OCOTP_CFG5_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CFG5_BITS.
#define BF_OCOTP_HW_OCOTP_CFG5_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_CFG5_BITS) & BM_OCOTP_HW_OCOTP_CFG5_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CFG5_BITS.
#define BF_OCOTP_HW_OCOTP_CFG5_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_CFG5_BITS) & BM_OCOTP_HW_OCOTP_CFG5_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_CFG5_BITS(v)   (HW_OCOTP_HW_OCOTP_CFG5_WR((HW_OCOTP_HW_OCOTP_CFG5_RD() & ~BM_OCOTP_HW_OCOTP_CFG5_BITS) | BF_OCOTP_HW_OCOTP_CFG5_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_CFG6 - Value of OTP Bank0 Word7 (Configuration and Manufacturing Info.) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 0, word 7 (ADDR = 0x07).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_cfg6
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_cfg6_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 0, word 7 (ADDR = 0x07). These bits become read-only after the HW_OCOTP_LOCK_BOOT_CFG[1] bit is set.
    } B;
} hw_ocotp_hw_ocotp_cfg6_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_CFG6 register
 */
#define HW_OCOTP_HW_OCOTP_CFG6_ADDR      (REGS_OCOTP_BASE + 0x470)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_CFG6           (*(volatile hw_ocotp_hw_ocotp_cfg6_t *) HW_OCOTP_HW_OCOTP_CFG6_ADDR)
#define HW_OCOTP_HW_OCOTP_CFG6_RD()      (HW_OCOTP_HW_OCOTP_CFG6.U)
#define HW_OCOTP_HW_OCOTP_CFG6_WR(v)     (HW_OCOTP_HW_OCOTP_CFG6.U = (v))
#define HW_OCOTP_HW_OCOTP_CFG6_SET(v)    (HW_OCOTP_HW_OCOTP_CFG6_WR(HW_OCOTP_HW_OCOTP_CFG6_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_CFG6_CLR(v)    (HW_OCOTP_HW_OCOTP_CFG6_WR(HW_OCOTP_HW_OCOTP_CFG6_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_CFG6_TOG(v)    (HW_OCOTP_HW_OCOTP_CFG6_WR(HW_OCOTP_HW_OCOTP_CFG6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_CFG6 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_CFG6, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 0, word 7 (ADDR = 0x07). These bits become read-only after the
 * HW_OCOTP_LOCK_BOOT_CFG[1] bit is set.
 */

#define BP_OCOTP_HW_OCOTP_CFG6_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_CFG6_BITS.
#define BM_OCOTP_HW_OCOTP_CFG6_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_CFG6_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_CFG6_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_CFG6_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_CFG6_BITS) >> BP_OCOTP_HW_OCOTP_CFG6_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CFG6_BITS.
#define BF_OCOTP_HW_OCOTP_CFG6_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_CFG6_BITS) & BM_OCOTP_HW_OCOTP_CFG6_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CFG6_BITS.
#define BF_OCOTP_HW_OCOTP_CFG6_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_CFG6_BITS) & BM_OCOTP_HW_OCOTP_CFG6_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_CFG6_BITS(v)   (HW_OCOTP_HW_OCOTP_CFG6_WR((HW_OCOTP_HW_OCOTP_CFG6_RD() & ~BM_OCOTP_HW_OCOTP_CFG6_BITS) | BF_OCOTP_HW_OCOTP_CFG6_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_MEM0 - Value of OTP Bank1 Word0 (Memory Related Info.) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP bank 1, word 0 (ADDR = 0x08).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_mem0
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_mem0_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP bank 1, word 0 (ADDR = 0x08). These bits become read-only after the HW_OCOTP_LOCK_MEM_TRIM[1] bit is set.
    } B;
} hw_ocotp_hw_ocotp_mem0_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_MEM0 register
 */
#define HW_OCOTP_HW_OCOTP_MEM0_ADDR      (REGS_OCOTP_BASE + 0x480)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_MEM0           (*(volatile hw_ocotp_hw_ocotp_mem0_t *) HW_OCOTP_HW_OCOTP_MEM0_ADDR)
#define HW_OCOTP_HW_OCOTP_MEM0_RD()      (HW_OCOTP_HW_OCOTP_MEM0.U)
#define HW_OCOTP_HW_OCOTP_MEM0_WR(v)     (HW_OCOTP_HW_OCOTP_MEM0.U = (v))
#define HW_OCOTP_HW_OCOTP_MEM0_SET(v)    (HW_OCOTP_HW_OCOTP_MEM0_WR(HW_OCOTP_HW_OCOTP_MEM0_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_MEM0_CLR(v)    (HW_OCOTP_HW_OCOTP_MEM0_WR(HW_OCOTP_HW_OCOTP_MEM0_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_MEM0_TOG(v)    (HW_OCOTP_HW_OCOTP_MEM0_WR(HW_OCOTP_HW_OCOTP_MEM0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_MEM0 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_MEM0, field BITS[31:0] (RW)
 *
 * Reflects value of OTP bank 1, word 0 (ADDR = 0x08). These bits become read-only after the
 * HW_OCOTP_LOCK_MEM_TRIM[1] bit is set.
 */

#define BP_OCOTP_HW_OCOTP_MEM0_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_MEM0_BITS.
#define BM_OCOTP_HW_OCOTP_MEM0_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_MEM0_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_MEM0_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_MEM0_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_MEM0_BITS) >> BP_OCOTP_HW_OCOTP_MEM0_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_MEM0_BITS.
#define BF_OCOTP_HW_OCOTP_MEM0_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_MEM0_BITS) & BM_OCOTP_HW_OCOTP_MEM0_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_MEM0_BITS.
#define BF_OCOTP_HW_OCOTP_MEM0_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_MEM0_BITS) & BM_OCOTP_HW_OCOTP_MEM0_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_MEM0_BITS(v)   (HW_OCOTP_HW_OCOTP_MEM0_WR((HW_OCOTP_HW_OCOTP_MEM0_RD() & ~BM_OCOTP_HW_OCOTP_MEM0_BITS) | BF_OCOTP_HW_OCOTP_MEM0_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_MEM1 - Value of OTP Bank1 Word1 (Memory Related Info.) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP bank 1, word 1 (ADDR = 0x09).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_mem1
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_mem1_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP bank 1, word 1 (ADDR = 0x09). These bits become read-only after the HW_OCOTP_LOCK_MEM_TRIM[1] bit is set.
    } B;
} hw_ocotp_hw_ocotp_mem1_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_MEM1 register
 */
#define HW_OCOTP_HW_OCOTP_MEM1_ADDR      (REGS_OCOTP_BASE + 0x490)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_MEM1           (*(volatile hw_ocotp_hw_ocotp_mem1_t *) HW_OCOTP_HW_OCOTP_MEM1_ADDR)
#define HW_OCOTP_HW_OCOTP_MEM1_RD()      (HW_OCOTP_HW_OCOTP_MEM1.U)
#define HW_OCOTP_HW_OCOTP_MEM1_WR(v)     (HW_OCOTP_HW_OCOTP_MEM1.U = (v))
#define HW_OCOTP_HW_OCOTP_MEM1_SET(v)    (HW_OCOTP_HW_OCOTP_MEM1_WR(HW_OCOTP_HW_OCOTP_MEM1_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_MEM1_CLR(v)    (HW_OCOTP_HW_OCOTP_MEM1_WR(HW_OCOTP_HW_OCOTP_MEM1_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_MEM1_TOG(v)    (HW_OCOTP_HW_OCOTP_MEM1_WR(HW_OCOTP_HW_OCOTP_MEM1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_MEM1 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_MEM1, field BITS[31:0] (RW)
 *
 * Reflects value of OTP bank 1, word 1 (ADDR = 0x09). These bits become read-only after the
 * HW_OCOTP_LOCK_MEM_TRIM[1] bit is set.
 */

#define BP_OCOTP_HW_OCOTP_MEM1_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_MEM1_BITS.
#define BM_OCOTP_HW_OCOTP_MEM1_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_MEM1_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_MEM1_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_MEM1_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_MEM1_BITS) >> BP_OCOTP_HW_OCOTP_MEM1_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_MEM1_BITS.
#define BF_OCOTP_HW_OCOTP_MEM1_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_MEM1_BITS) & BM_OCOTP_HW_OCOTP_MEM1_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_MEM1_BITS.
#define BF_OCOTP_HW_OCOTP_MEM1_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_MEM1_BITS) & BM_OCOTP_HW_OCOTP_MEM1_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_MEM1_BITS(v)   (HW_OCOTP_HW_OCOTP_MEM1_WR((HW_OCOTP_HW_OCOTP_MEM1_RD() & ~BM_OCOTP_HW_OCOTP_MEM1_BITS) | BF_OCOTP_HW_OCOTP_MEM1_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_MEM2 - Value of OTP Bank1 Word2 (Memory Related Info.) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP bank 1, word 2 (ADDR = 0x0A).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_mem2
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_mem2_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP bank 1, word 2 (ADDR = 0x0A). These bits become read-only after the HW_OCOTP_LOCK_MEM_TRIM[1] bit is set.
    } B;
} hw_ocotp_hw_ocotp_mem2_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_MEM2 register
 */
#define HW_OCOTP_HW_OCOTP_MEM2_ADDR      (REGS_OCOTP_BASE + 0x4a0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_MEM2           (*(volatile hw_ocotp_hw_ocotp_mem2_t *) HW_OCOTP_HW_OCOTP_MEM2_ADDR)
#define HW_OCOTP_HW_OCOTP_MEM2_RD()      (HW_OCOTP_HW_OCOTP_MEM2.U)
#define HW_OCOTP_HW_OCOTP_MEM2_WR(v)     (HW_OCOTP_HW_OCOTP_MEM2.U = (v))
#define HW_OCOTP_HW_OCOTP_MEM2_SET(v)    (HW_OCOTP_HW_OCOTP_MEM2_WR(HW_OCOTP_HW_OCOTP_MEM2_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_MEM2_CLR(v)    (HW_OCOTP_HW_OCOTP_MEM2_WR(HW_OCOTP_HW_OCOTP_MEM2_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_MEM2_TOG(v)    (HW_OCOTP_HW_OCOTP_MEM2_WR(HW_OCOTP_HW_OCOTP_MEM2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_MEM2 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_MEM2, field BITS[31:0] (RW)
 *
 * Reflects value of OTP bank 1, word 2 (ADDR = 0x0A). These bits become read-only after the
 * HW_OCOTP_LOCK_MEM_TRIM[1] bit is set.
 */

#define BP_OCOTP_HW_OCOTP_MEM2_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_MEM2_BITS.
#define BM_OCOTP_HW_OCOTP_MEM2_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_MEM2_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_MEM2_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_MEM2_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_MEM2_BITS) >> BP_OCOTP_HW_OCOTP_MEM2_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_MEM2_BITS.
#define BF_OCOTP_HW_OCOTP_MEM2_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_MEM2_BITS) & BM_OCOTP_HW_OCOTP_MEM2_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_MEM2_BITS.
#define BF_OCOTP_HW_OCOTP_MEM2_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_MEM2_BITS) & BM_OCOTP_HW_OCOTP_MEM2_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_MEM2_BITS(v)   (HW_OCOTP_HW_OCOTP_MEM2_WR((HW_OCOTP_HW_OCOTP_MEM2_RD() & ~BM_OCOTP_HW_OCOTP_MEM2_BITS) | BF_OCOTP_HW_OCOTP_MEM2_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_MEM3 - Value of OTP Bank1 Word3 (Memory Related Info.) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP bank 1, word 3 (ADDR = 0x0B).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_mem3
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_mem3_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP bank 1, word 3 (ADDR = 0x0B). These bits become read-only after the HW_OCOTP_LOCK_MEM_TRIM[1] bit is set.
    } B;
} hw_ocotp_hw_ocotp_mem3_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_MEM3 register
 */
#define HW_OCOTP_HW_OCOTP_MEM3_ADDR      (REGS_OCOTP_BASE + 0x4b0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_MEM3           (*(volatile hw_ocotp_hw_ocotp_mem3_t *) HW_OCOTP_HW_OCOTP_MEM3_ADDR)
#define HW_OCOTP_HW_OCOTP_MEM3_RD()      (HW_OCOTP_HW_OCOTP_MEM3.U)
#define HW_OCOTP_HW_OCOTP_MEM3_WR(v)     (HW_OCOTP_HW_OCOTP_MEM3.U = (v))
#define HW_OCOTP_HW_OCOTP_MEM3_SET(v)    (HW_OCOTP_HW_OCOTP_MEM3_WR(HW_OCOTP_HW_OCOTP_MEM3_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_MEM3_CLR(v)    (HW_OCOTP_HW_OCOTP_MEM3_WR(HW_OCOTP_HW_OCOTP_MEM3_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_MEM3_TOG(v)    (HW_OCOTP_HW_OCOTP_MEM3_WR(HW_OCOTP_HW_OCOTP_MEM3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_MEM3 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_MEM3, field BITS[31:0] (RW)
 *
 * Reflects value of OTP bank 1, word 3 (ADDR = 0x0B). These bits become read-only after the
 * HW_OCOTP_LOCK_MEM_TRIM[1] bit is set.
 */

#define BP_OCOTP_HW_OCOTP_MEM3_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_MEM3_BITS.
#define BM_OCOTP_HW_OCOTP_MEM3_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_MEM3_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_MEM3_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_MEM3_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_MEM3_BITS) >> BP_OCOTP_HW_OCOTP_MEM3_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_MEM3_BITS.
#define BF_OCOTP_HW_OCOTP_MEM3_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_MEM3_BITS) & BM_OCOTP_HW_OCOTP_MEM3_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_MEM3_BITS.
#define BF_OCOTP_HW_OCOTP_MEM3_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_MEM3_BITS) & BM_OCOTP_HW_OCOTP_MEM3_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_MEM3_BITS(v)   (HW_OCOTP_HW_OCOTP_MEM3_WR((HW_OCOTP_HW_OCOTP_MEM3_RD() & ~BM_OCOTP_HW_OCOTP_MEM3_BITS) | BF_OCOTP_HW_OCOTP_MEM3_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_MEM4 - Value of OTP Bank1 Word4 (Memory Related Info.) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP bank 1, word 4 (ADDR = 0x0C).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_mem4
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_mem4_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP bank 1, word 4 (ADDR = 0x0C). These bits become read-only after the HW_OCOTP_LOCK_MEM_TRIM[1] bit is set.
    } B;
} hw_ocotp_hw_ocotp_mem4_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_MEM4 register
 */
#define HW_OCOTP_HW_OCOTP_MEM4_ADDR      (REGS_OCOTP_BASE + 0x4c0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_MEM4           (*(volatile hw_ocotp_hw_ocotp_mem4_t *) HW_OCOTP_HW_OCOTP_MEM4_ADDR)
#define HW_OCOTP_HW_OCOTP_MEM4_RD()      (HW_OCOTP_HW_OCOTP_MEM4.U)
#define HW_OCOTP_HW_OCOTP_MEM4_WR(v)     (HW_OCOTP_HW_OCOTP_MEM4.U = (v))
#define HW_OCOTP_HW_OCOTP_MEM4_SET(v)    (HW_OCOTP_HW_OCOTP_MEM4_WR(HW_OCOTP_HW_OCOTP_MEM4_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_MEM4_CLR(v)    (HW_OCOTP_HW_OCOTP_MEM4_WR(HW_OCOTP_HW_OCOTP_MEM4_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_MEM4_TOG(v)    (HW_OCOTP_HW_OCOTP_MEM4_WR(HW_OCOTP_HW_OCOTP_MEM4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_MEM4 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_MEM4, field BITS[31:0] (RW)
 *
 * Reflects value of OTP bank 1, word 4 (ADDR = 0x0C). These bits become read-only after the
 * HW_OCOTP_LOCK_MEM_TRIM[1] bit is set.
 */

#define BP_OCOTP_HW_OCOTP_MEM4_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_MEM4_BITS.
#define BM_OCOTP_HW_OCOTP_MEM4_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_MEM4_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_MEM4_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_MEM4_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_MEM4_BITS) >> BP_OCOTP_HW_OCOTP_MEM4_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_MEM4_BITS.
#define BF_OCOTP_HW_OCOTP_MEM4_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_MEM4_BITS) & BM_OCOTP_HW_OCOTP_MEM4_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_MEM4_BITS.
#define BF_OCOTP_HW_OCOTP_MEM4_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_MEM4_BITS) & BM_OCOTP_HW_OCOTP_MEM4_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_MEM4_BITS(v)   (HW_OCOTP_HW_OCOTP_MEM4_WR((HW_OCOTP_HW_OCOTP_MEM4_RD() & ~BM_OCOTP_HW_OCOTP_MEM4_BITS) | BF_OCOTP_HW_OCOTP_MEM4_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_ANA0 - Value of OTP Bank1 Word5 (Memory Related Info.) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP bank 1, word 5 (ADDR = 0x0D).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_ana0
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_ana0_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP bank 1, word 5 (ADDR = 0x0D). These bits become read-only after the HW_OCOTP_LOCK_ANALOG[1] bit is set.
    } B;
} hw_ocotp_hw_ocotp_ana0_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_ANA0 register
 */
#define HW_OCOTP_HW_OCOTP_ANA0_ADDR      (REGS_OCOTP_BASE + 0x4d0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_ANA0           (*(volatile hw_ocotp_hw_ocotp_ana0_t *) HW_OCOTP_HW_OCOTP_ANA0_ADDR)
#define HW_OCOTP_HW_OCOTP_ANA0_RD()      (HW_OCOTP_HW_OCOTP_ANA0.U)
#define HW_OCOTP_HW_OCOTP_ANA0_WR(v)     (HW_OCOTP_HW_OCOTP_ANA0.U = (v))
#define HW_OCOTP_HW_OCOTP_ANA0_SET(v)    (HW_OCOTP_HW_OCOTP_ANA0_WR(HW_OCOTP_HW_OCOTP_ANA0_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_ANA0_CLR(v)    (HW_OCOTP_HW_OCOTP_ANA0_WR(HW_OCOTP_HW_OCOTP_ANA0_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_ANA0_TOG(v)    (HW_OCOTP_HW_OCOTP_ANA0_WR(HW_OCOTP_HW_OCOTP_ANA0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_ANA0 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_ANA0, field BITS[31:0] (RW)
 *
 * Reflects value of OTP bank 1, word 5 (ADDR = 0x0D). These bits become read-only after the
 * HW_OCOTP_LOCK_ANALOG[1] bit is set.
 */

#define BP_OCOTP_HW_OCOTP_ANA0_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_ANA0_BITS.
#define BM_OCOTP_HW_OCOTP_ANA0_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_ANA0_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_ANA0_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_ANA0_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_ANA0_BITS) >> BP_OCOTP_HW_OCOTP_ANA0_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_ANA0_BITS.
#define BF_OCOTP_HW_OCOTP_ANA0_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_ANA0_BITS) & BM_OCOTP_HW_OCOTP_ANA0_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_ANA0_BITS.
#define BF_OCOTP_HW_OCOTP_ANA0_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_ANA0_BITS) & BM_OCOTP_HW_OCOTP_ANA0_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_ANA0_BITS(v)   (HW_OCOTP_HW_OCOTP_ANA0_WR((HW_OCOTP_HW_OCOTP_ANA0_RD() & ~BM_OCOTP_HW_OCOTP_ANA0_BITS) | BF_OCOTP_HW_OCOTP_ANA0_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_ANA1 - Value of OTP Bank1 Word6 (General Purpose Customer Defined Info.) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP bank 1, word 6 (ADDR = 0x0E).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_ana1
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_ana1_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP bank 1, word 6 (ADDR = 0x0E). These bits become read-only after the HW_OCOTP_LOCK_ANALOG[1] bit is set.
    } B;
} hw_ocotp_hw_ocotp_ana1_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_ANA1 register
 */
#define HW_OCOTP_HW_OCOTP_ANA1_ADDR      (REGS_OCOTP_BASE + 0x4e0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_ANA1           (*(volatile hw_ocotp_hw_ocotp_ana1_t *) HW_OCOTP_HW_OCOTP_ANA1_ADDR)
#define HW_OCOTP_HW_OCOTP_ANA1_RD()      (HW_OCOTP_HW_OCOTP_ANA1.U)
#define HW_OCOTP_HW_OCOTP_ANA1_WR(v)     (HW_OCOTP_HW_OCOTP_ANA1.U = (v))
#define HW_OCOTP_HW_OCOTP_ANA1_SET(v)    (HW_OCOTP_HW_OCOTP_ANA1_WR(HW_OCOTP_HW_OCOTP_ANA1_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_ANA1_CLR(v)    (HW_OCOTP_HW_OCOTP_ANA1_WR(HW_OCOTP_HW_OCOTP_ANA1_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_ANA1_TOG(v)    (HW_OCOTP_HW_OCOTP_ANA1_WR(HW_OCOTP_HW_OCOTP_ANA1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_ANA1 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_ANA1, field BITS[31:0] (RW)
 *
 * Reflects value of OTP bank 1, word 6 (ADDR = 0x0E). These bits become read-only after the
 * HW_OCOTP_LOCK_ANALOG[1] bit is set.
 */

#define BP_OCOTP_HW_OCOTP_ANA1_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_ANA1_BITS.
#define BM_OCOTP_HW_OCOTP_ANA1_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_ANA1_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_ANA1_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_ANA1_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_ANA1_BITS) >> BP_OCOTP_HW_OCOTP_ANA1_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_ANA1_BITS.
#define BF_OCOTP_HW_OCOTP_ANA1_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_ANA1_BITS) & BM_OCOTP_HW_OCOTP_ANA1_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_ANA1_BITS.
#define BF_OCOTP_HW_OCOTP_ANA1_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_ANA1_BITS) & BM_OCOTP_HW_OCOTP_ANA1_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_ANA1_BITS(v)   (HW_OCOTP_HW_OCOTP_ANA1_WR((HW_OCOTP_HW_OCOTP_ANA1_RD() & ~BM_OCOTP_HW_OCOTP_ANA1_BITS) | BF_OCOTP_HW_OCOTP_ANA1_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_ANA2 - Value of OTP Bank1 Word7 (General Purpose Customer Defined Info.) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP bank 1, word 7 (ADDR = 0x0F).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_ana2
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_ana2_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP bank 1, word 7 (ADDR = 0x0F). These bits become read-only after the HW_OCOTP_LOCK_ANALOG[1] bit is set.
    } B;
} hw_ocotp_hw_ocotp_ana2_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_ANA2 register
 */
#define HW_OCOTP_HW_OCOTP_ANA2_ADDR      (REGS_OCOTP_BASE + 0x4f0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_ANA2           (*(volatile hw_ocotp_hw_ocotp_ana2_t *) HW_OCOTP_HW_OCOTP_ANA2_ADDR)
#define HW_OCOTP_HW_OCOTP_ANA2_RD()      (HW_OCOTP_HW_OCOTP_ANA2.U)
#define HW_OCOTP_HW_OCOTP_ANA2_WR(v)     (HW_OCOTP_HW_OCOTP_ANA2.U = (v))
#define HW_OCOTP_HW_OCOTP_ANA2_SET(v)    (HW_OCOTP_HW_OCOTP_ANA2_WR(HW_OCOTP_HW_OCOTP_ANA2_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_ANA2_CLR(v)    (HW_OCOTP_HW_OCOTP_ANA2_WR(HW_OCOTP_HW_OCOTP_ANA2_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_ANA2_TOG(v)    (HW_OCOTP_HW_OCOTP_ANA2_WR(HW_OCOTP_HW_OCOTP_ANA2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_ANA2 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_ANA2, field BITS[31:0] (RW)
 *
 * Reflects value of OTP bank 1, word 7 (ADDR = 0x0F). These bits become read-only after the
 * HW_OCOTP_LOCK_ANALOG[1] bit is set.
 */

#define BP_OCOTP_HW_OCOTP_ANA2_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_ANA2_BITS.
#define BM_OCOTP_HW_OCOTP_ANA2_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_ANA2_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_ANA2_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_ANA2_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_ANA2_BITS) >> BP_OCOTP_HW_OCOTP_ANA2_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_ANA2_BITS.
#define BF_OCOTP_HW_OCOTP_ANA2_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_ANA2_BITS) & BM_OCOTP_HW_OCOTP_ANA2_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_ANA2_BITS.
#define BF_OCOTP_HW_OCOTP_ANA2_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_ANA2_BITS) & BM_OCOTP_HW_OCOTP_ANA2_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_ANA2_BITS(v)   (HW_OCOTP_HW_OCOTP_ANA2_WR((HW_OCOTP_HW_OCOTP_ANA2_RD() & ~BM_OCOTP_HW_OCOTP_ANA2_BITS) | BF_OCOTP_HW_OCOTP_ANA2_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_DCP0 - Shadow Register for OTP Bank2 Word0 (DCP and CRYPTO Key) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS].  Shadowed memory mapped access to OTP Bank 2, word 0 (ADDR =
 * 0x10).   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_dcp0
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_dcp0_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Shadow register for the DCP Key word0 (Copy of OTP Bank 2, word 0 (ADDR = 0x10)). These bits can be not read and wrotten after the HW_OCOTP_LOCK_DCP bit is set. If read, returns 0xBADA_BADA and sets HW_OCOTP_CTRL[ERROR].
    } B;
} hw_ocotp_hw_ocotp_dcp0_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_DCP0 register
 */
#define HW_OCOTP_HW_OCOTP_DCP0_ADDR      (REGS_OCOTP_BASE + 0x500)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_DCP0           (*(volatile hw_ocotp_hw_ocotp_dcp0_t *) HW_OCOTP_HW_OCOTP_DCP0_ADDR)
#define HW_OCOTP_HW_OCOTP_DCP0_RD()      (HW_OCOTP_HW_OCOTP_DCP0.U)
#define HW_OCOTP_HW_OCOTP_DCP0_WR(v)     (HW_OCOTP_HW_OCOTP_DCP0.U = (v))
#define HW_OCOTP_HW_OCOTP_DCP0_SET(v)    (HW_OCOTP_HW_OCOTP_DCP0_WR(HW_OCOTP_HW_OCOTP_DCP0_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_DCP0_CLR(v)    (HW_OCOTP_HW_OCOTP_DCP0_WR(HW_OCOTP_HW_OCOTP_DCP0_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_DCP0_TOG(v)    (HW_OCOTP_HW_OCOTP_DCP0_WR(HW_OCOTP_HW_OCOTP_DCP0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_DCP0 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_DCP0, field BITS[31:0] (RW)
 *
 * Shadow register for the DCP Key word0 (Copy of OTP Bank 2, word 0 (ADDR = 0x10)). These bits can
 * be not read and wrotten after the HW_OCOTP_LOCK_DCP bit is set. If read, returns 0xBADA_BADA and
 * sets HW_OCOTP_CTRL[ERROR].
 */

#define BP_OCOTP_HW_OCOTP_DCP0_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_DCP0_BITS.
#define BM_OCOTP_HW_OCOTP_DCP0_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_DCP0_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_DCP0_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_DCP0_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_DCP0_BITS) >> BP_OCOTP_HW_OCOTP_DCP0_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_DCP0_BITS.
#define BF_OCOTP_HW_OCOTP_DCP0_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_DCP0_BITS) & BM_OCOTP_HW_OCOTP_DCP0_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_DCP0_BITS.
#define BF_OCOTP_HW_OCOTP_DCP0_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_DCP0_BITS) & BM_OCOTP_HW_OCOTP_DCP0_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_DCP0_BITS(v)   (HW_OCOTP_HW_OCOTP_DCP0_WR((HW_OCOTP_HW_OCOTP_DCP0_RD() & ~BM_OCOTP_HW_OCOTP_DCP0_BITS) | BF_OCOTP_HW_OCOTP_DCP0_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_DCP1 - Shadow Register for OTP Bank2 Word1 (DCP and CRYPTO Key) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS].  Shadowed memory mapped access to OTP Bank 2, word 1 (ADDR =
 * 0x11).   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_dcp1
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_dcp1_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Shadow register for the DCP Key word1 (Copy of OTP Bank 2, word 1 (ADDR = 0x11)). These bits can be not read and wrotten after the HW_OCOTP_LOCK_DCP bit is set. If read, returns 0xBADA_BADA and sets HW_OCOTP_CTRL[ERROR].
    } B;
} hw_ocotp_hw_ocotp_dcp1_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_DCP1 register
 */
#define HW_OCOTP_HW_OCOTP_DCP1_ADDR      (REGS_OCOTP_BASE + 0x510)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_DCP1           (*(volatile hw_ocotp_hw_ocotp_dcp1_t *) HW_OCOTP_HW_OCOTP_DCP1_ADDR)
#define HW_OCOTP_HW_OCOTP_DCP1_RD()      (HW_OCOTP_HW_OCOTP_DCP1.U)
#define HW_OCOTP_HW_OCOTP_DCP1_WR(v)     (HW_OCOTP_HW_OCOTP_DCP1.U = (v))
#define HW_OCOTP_HW_OCOTP_DCP1_SET(v)    (HW_OCOTP_HW_OCOTP_DCP1_WR(HW_OCOTP_HW_OCOTP_DCP1_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_DCP1_CLR(v)    (HW_OCOTP_HW_OCOTP_DCP1_WR(HW_OCOTP_HW_OCOTP_DCP1_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_DCP1_TOG(v)    (HW_OCOTP_HW_OCOTP_DCP1_WR(HW_OCOTP_HW_OCOTP_DCP1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_DCP1 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_DCP1, field BITS[31:0] (RW)
 *
 * Shadow register for the DCP Key word1 (Copy of OTP Bank 2, word 1 (ADDR = 0x11)). These bits can
 * be not read and wrotten after the HW_OCOTP_LOCK_DCP bit is set. If read, returns 0xBADA_BADA and
 * sets HW_OCOTP_CTRL[ERROR].
 */

#define BP_OCOTP_HW_OCOTP_DCP1_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_DCP1_BITS.
#define BM_OCOTP_HW_OCOTP_DCP1_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_DCP1_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_DCP1_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_DCP1_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_DCP1_BITS) >> BP_OCOTP_HW_OCOTP_DCP1_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_DCP1_BITS.
#define BF_OCOTP_HW_OCOTP_DCP1_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_DCP1_BITS) & BM_OCOTP_HW_OCOTP_DCP1_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_DCP1_BITS.
#define BF_OCOTP_HW_OCOTP_DCP1_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_DCP1_BITS) & BM_OCOTP_HW_OCOTP_DCP1_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_DCP1_BITS(v)   (HW_OCOTP_HW_OCOTP_DCP1_WR((HW_OCOTP_HW_OCOTP_DCP1_RD() & ~BM_OCOTP_HW_OCOTP_DCP1_BITS) | BF_OCOTP_HW_OCOTP_DCP1_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_DCP2 - Shadow Register for OTP Bank2 Word2 (DCP and CRYPTO Key) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS].  Shadowed memory mapped access to OTP Bank 2, word 2 (ADDR =
 * 0x12).   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_dcp2
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_dcp2_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Shadow register for the DCP Key word2 (Copy of OTP Bank 2, word 2 (ADDR = 0x12)). These bits can be not read and wrotten after the HW_OCOTP_LOCK_DCP bit is set. If read, returns 0xBADA_BADA and sets HW_OCOTP_CTRL[ERROR].
    } B;
} hw_ocotp_hw_ocotp_dcp2_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_DCP2 register
 */
#define HW_OCOTP_HW_OCOTP_DCP2_ADDR      (REGS_OCOTP_BASE + 0x520)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_DCP2           (*(volatile hw_ocotp_hw_ocotp_dcp2_t *) HW_OCOTP_HW_OCOTP_DCP2_ADDR)
#define HW_OCOTP_HW_OCOTP_DCP2_RD()      (HW_OCOTP_HW_OCOTP_DCP2.U)
#define HW_OCOTP_HW_OCOTP_DCP2_WR(v)     (HW_OCOTP_HW_OCOTP_DCP2.U = (v))
#define HW_OCOTP_HW_OCOTP_DCP2_SET(v)    (HW_OCOTP_HW_OCOTP_DCP2_WR(HW_OCOTP_HW_OCOTP_DCP2_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_DCP2_CLR(v)    (HW_OCOTP_HW_OCOTP_DCP2_WR(HW_OCOTP_HW_OCOTP_DCP2_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_DCP2_TOG(v)    (HW_OCOTP_HW_OCOTP_DCP2_WR(HW_OCOTP_HW_OCOTP_DCP2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_DCP2 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_DCP2, field BITS[31:0] (RW)
 *
 * Shadow register for the DCP Key word2 (Copy of OTP Bank 2, word 2 (ADDR = 0x12)). These bits can
 * be not read and wrotten after the HW_OCOTP_LOCK_DCP bit is set. If read, returns 0xBADA_BADA and
 * sets HW_OCOTP_CTRL[ERROR].
 */

#define BP_OCOTP_HW_OCOTP_DCP2_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_DCP2_BITS.
#define BM_OCOTP_HW_OCOTP_DCP2_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_DCP2_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_DCP2_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_DCP2_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_DCP2_BITS) >> BP_OCOTP_HW_OCOTP_DCP2_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_DCP2_BITS.
#define BF_OCOTP_HW_OCOTP_DCP2_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_DCP2_BITS) & BM_OCOTP_HW_OCOTP_DCP2_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_DCP2_BITS.
#define BF_OCOTP_HW_OCOTP_DCP2_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_DCP2_BITS) & BM_OCOTP_HW_OCOTP_DCP2_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_DCP2_BITS(v)   (HW_OCOTP_HW_OCOTP_DCP2_WR((HW_OCOTP_HW_OCOTP_DCP2_RD() & ~BM_OCOTP_HW_OCOTP_DCP2_BITS) | BF_OCOTP_HW_OCOTP_DCP2_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_DCP3 - Shadow Register for OTP Bank2 Word3 (DCP and CRYPTO Key) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS].  Shadowed memory mapped access to OTP Bank 2, word 3 (ADDR =
 * 0x13).   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_dcp3
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_dcp3_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Shadow register for the DCP Key word3 (Copy of OTP Bank 2, word 3 (ADDR = 0x13)). These bits can be not read and wrotten after the HW_OCOTP_LOCK_DCP bit is set. If read, returns 0xBADA_BADA and sets HW_OCOTP_CTRL[ERROR].
    } B;
} hw_ocotp_hw_ocotp_dcp3_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_DCP3 register
 */
#define HW_OCOTP_HW_OCOTP_DCP3_ADDR      (REGS_OCOTP_BASE + 0x530)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_DCP3           (*(volatile hw_ocotp_hw_ocotp_dcp3_t *) HW_OCOTP_HW_OCOTP_DCP3_ADDR)
#define HW_OCOTP_HW_OCOTP_DCP3_RD()      (HW_OCOTP_HW_OCOTP_DCP3.U)
#define HW_OCOTP_HW_OCOTP_DCP3_WR(v)     (HW_OCOTP_HW_OCOTP_DCP3.U = (v))
#define HW_OCOTP_HW_OCOTP_DCP3_SET(v)    (HW_OCOTP_HW_OCOTP_DCP3_WR(HW_OCOTP_HW_OCOTP_DCP3_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_DCP3_CLR(v)    (HW_OCOTP_HW_OCOTP_DCP3_WR(HW_OCOTP_HW_OCOTP_DCP3_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_DCP3_TOG(v)    (HW_OCOTP_HW_OCOTP_DCP3_WR(HW_OCOTP_HW_OCOTP_DCP3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_DCP3 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_DCP3, field BITS[31:0] (RW)
 *
 * Shadow register for the DCP Key word3 (Copy of OTP Bank 2, word 3 (ADDR = 0x13)). These bits can
 * be not read and wrotten after the HW_OCOTP_LOCK_DCP bit is set. If read, returns 0xBADA_BADA and
 * sets HW_OCOTP_CTRL[ERROR].
 */

#define BP_OCOTP_HW_OCOTP_DCP3_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_DCP3_BITS.
#define BM_OCOTP_HW_OCOTP_DCP3_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_DCP3_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_DCP3_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_DCP3_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_DCP3_BITS) >> BP_OCOTP_HW_OCOTP_DCP3_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_DCP3_BITS.
#define BF_OCOTP_HW_OCOTP_DCP3_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_DCP3_BITS) & BM_OCOTP_HW_OCOTP_DCP3_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_DCP3_BITS.
#define BF_OCOTP_HW_OCOTP_DCP3_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_DCP3_BITS) & BM_OCOTP_HW_OCOTP_DCP3_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_DCP3_BITS(v)   (HW_OCOTP_HW_OCOTP_DCP3_WR((HW_OCOTP_HW_OCOTP_DCP3_RD() & ~BM_OCOTP_HW_OCOTP_DCP3_BITS) | BF_OCOTP_HW_OCOTP_DCP3_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_DCP4 - Shadow Register for OTP Bank2 Word4 (DCP Key) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS].  Shadowed memory mapped access to OTP Bank 2, word 4 (ADDR =
 * 0x14).   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_dcp4
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_dcp4_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Shadow register for the DCP Key word4 (Copy of OTP Bank 2, word 4 (ADDR = 0x14)). These bits can be not read and wrotten after the HW_OCOTP_LOCK_DCP bit is set. If read, returns 0xBADA_BADA and sets HW_OCOTP_CTRL[ERROR].
    } B;
} hw_ocotp_hw_ocotp_dcp4_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_DCP4 register
 */
#define HW_OCOTP_HW_OCOTP_DCP4_ADDR      (REGS_OCOTP_BASE + 0x540)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_DCP4           (*(volatile hw_ocotp_hw_ocotp_dcp4_t *) HW_OCOTP_HW_OCOTP_DCP4_ADDR)
#define HW_OCOTP_HW_OCOTP_DCP4_RD()      (HW_OCOTP_HW_OCOTP_DCP4.U)
#define HW_OCOTP_HW_OCOTP_DCP4_WR(v)     (HW_OCOTP_HW_OCOTP_DCP4.U = (v))
#define HW_OCOTP_HW_OCOTP_DCP4_SET(v)    (HW_OCOTP_HW_OCOTP_DCP4_WR(HW_OCOTP_HW_OCOTP_DCP4_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_DCP4_CLR(v)    (HW_OCOTP_HW_OCOTP_DCP4_WR(HW_OCOTP_HW_OCOTP_DCP4_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_DCP4_TOG(v)    (HW_OCOTP_HW_OCOTP_DCP4_WR(HW_OCOTP_HW_OCOTP_DCP4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_DCP4 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_DCP4, field BITS[31:0] (RW)
 *
 * Shadow register for the DCP Key word4 (Copy of OTP Bank 2, word 4 (ADDR = 0x14)). These bits can
 * be not read and wrotten after the HW_OCOTP_LOCK_DCP bit is set. If read, returns 0xBADA_BADA and
 * sets HW_OCOTP_CTRL[ERROR].
 */

#define BP_OCOTP_HW_OCOTP_DCP4_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_DCP4_BITS.
#define BM_OCOTP_HW_OCOTP_DCP4_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_DCP4_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_DCP4_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_DCP4_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_DCP4_BITS) >> BP_OCOTP_HW_OCOTP_DCP4_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_DCP4_BITS.
#define BF_OCOTP_HW_OCOTP_DCP4_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_DCP4_BITS) & BM_OCOTP_HW_OCOTP_DCP4_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_DCP4_BITS.
#define BF_OCOTP_HW_OCOTP_DCP4_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_DCP4_BITS) & BM_OCOTP_HW_OCOTP_DCP4_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_DCP4_BITS(v)   (HW_OCOTP_HW_OCOTP_DCP4_WR((HW_OCOTP_HW_OCOTP_DCP4_RD() & ~BM_OCOTP_HW_OCOTP_DCP4_BITS) | BF_OCOTP_HW_OCOTP_DCP4_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_DCP5 - Shadow Register for OTP Bank2 Word5 (DCP Key) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS].  Shadowed memory mapped access to OTP Bank 2, word 5 (ADDR =
 * 0x15).   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_dcp5
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_dcp5_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Shadow register for the DCP Key word5 (Copy of OTP Bank 2, word 5 (ADDR = 0x15)). These bits can be not read and wrotten after the HW_OCOTP_LOCK_DCP bit is set. If read, returns 0xBADA_BADA and sets HW_OCOTP_CTRL[ERROR].
    } B;
} hw_ocotp_hw_ocotp_dcp5_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_DCP5 register
 */
#define HW_OCOTP_HW_OCOTP_DCP5_ADDR      (REGS_OCOTP_BASE + 0x550)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_DCP5           (*(volatile hw_ocotp_hw_ocotp_dcp5_t *) HW_OCOTP_HW_OCOTP_DCP5_ADDR)
#define HW_OCOTP_HW_OCOTP_DCP5_RD()      (HW_OCOTP_HW_OCOTP_DCP5.U)
#define HW_OCOTP_HW_OCOTP_DCP5_WR(v)     (HW_OCOTP_HW_OCOTP_DCP5.U = (v))
#define HW_OCOTP_HW_OCOTP_DCP5_SET(v)    (HW_OCOTP_HW_OCOTP_DCP5_WR(HW_OCOTP_HW_OCOTP_DCP5_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_DCP5_CLR(v)    (HW_OCOTP_HW_OCOTP_DCP5_WR(HW_OCOTP_HW_OCOTP_DCP5_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_DCP5_TOG(v)    (HW_OCOTP_HW_OCOTP_DCP5_WR(HW_OCOTP_HW_OCOTP_DCP5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_DCP5 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_DCP5, field BITS[31:0] (RW)
 *
 * Shadow register for the DCP Key word5 (Copy of OTP Bank 2, word 5 (ADDR = 0x15)). These bits can
 * be not read and wrotten after the HW_OCOTP_LOCK_DCP bit is set. If read, returns 0xBADA_BADA and
 * sets HW_OCOTP_CTRL[ERROR].
 */

#define BP_OCOTP_HW_OCOTP_DCP5_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_DCP5_BITS.
#define BM_OCOTP_HW_OCOTP_DCP5_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_DCP5_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_DCP5_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_DCP5_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_DCP5_BITS) >> BP_OCOTP_HW_OCOTP_DCP5_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_DCP5_BITS.
#define BF_OCOTP_HW_OCOTP_DCP5_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_DCP5_BITS) & BM_OCOTP_HW_OCOTP_DCP5_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_DCP5_BITS.
#define BF_OCOTP_HW_OCOTP_DCP5_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_DCP5_BITS) & BM_OCOTP_HW_OCOTP_DCP5_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_DCP5_BITS(v)   (HW_OCOTP_HW_OCOTP_DCP5_WR((HW_OCOTP_HW_OCOTP_DCP5_RD() & ~BM_OCOTP_HW_OCOTP_DCP5_BITS) | BF_OCOTP_HW_OCOTP_DCP5_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_DCP6 - Shadow Register for OTP Bank2 Word6 (DCP Key) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS].  Shadowed memory mapped access to OTP Bank 2, word 6 (ADDR =
 * 0x16).   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_dcp6
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_dcp6_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Shadow register for the DCP Key word6 (Copy of OTP Bank 2, word 6 (ADDR = 0x16)). These bits can be not read and wrotten after the HW_OCOTP_LOCK_DCP bit is set. If read, returns 0xBADA_BADA and sets HW_OCOTP_CTRL[ERROR].
    } B;
} hw_ocotp_hw_ocotp_dcp6_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_DCP6 register
 */
#define HW_OCOTP_HW_OCOTP_DCP6_ADDR      (REGS_OCOTP_BASE + 0x560)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_DCP6           (*(volatile hw_ocotp_hw_ocotp_dcp6_t *) HW_OCOTP_HW_OCOTP_DCP6_ADDR)
#define HW_OCOTP_HW_OCOTP_DCP6_RD()      (HW_OCOTP_HW_OCOTP_DCP6.U)
#define HW_OCOTP_HW_OCOTP_DCP6_WR(v)     (HW_OCOTP_HW_OCOTP_DCP6.U = (v))
#define HW_OCOTP_HW_OCOTP_DCP6_SET(v)    (HW_OCOTP_HW_OCOTP_DCP6_WR(HW_OCOTP_HW_OCOTP_DCP6_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_DCP6_CLR(v)    (HW_OCOTP_HW_OCOTP_DCP6_WR(HW_OCOTP_HW_OCOTP_DCP6_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_DCP6_TOG(v)    (HW_OCOTP_HW_OCOTP_DCP6_WR(HW_OCOTP_HW_OCOTP_DCP6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_DCP6 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_DCP6, field BITS[31:0] (RW)
 *
 * Shadow register for the DCP Key word6 (Copy of OTP Bank 2, word 6 (ADDR = 0x16)). These bits can
 * be not read and wrotten after the HW_OCOTP_LOCK_DCP bit is set. If read, returns 0xBADA_BADA and
 * sets HW_OCOTP_CTRL[ERROR].
 */

#define BP_OCOTP_HW_OCOTP_DCP6_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_DCP6_BITS.
#define BM_OCOTP_HW_OCOTP_DCP6_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_DCP6_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_DCP6_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_DCP6_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_DCP6_BITS) >> BP_OCOTP_HW_OCOTP_DCP6_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_DCP6_BITS.
#define BF_OCOTP_HW_OCOTP_DCP6_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_DCP6_BITS) & BM_OCOTP_HW_OCOTP_DCP6_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_DCP6_BITS.
#define BF_OCOTP_HW_OCOTP_DCP6_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_DCP6_BITS) & BM_OCOTP_HW_OCOTP_DCP6_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_DCP6_BITS(v)   (HW_OCOTP_HW_OCOTP_DCP6_WR((HW_OCOTP_HW_OCOTP_DCP6_RD() & ~BM_OCOTP_HW_OCOTP_DCP6_BITS) | BF_OCOTP_HW_OCOTP_DCP6_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_DCP7 - Shadow Register for OTP Bank2 Word7 (DCP Key) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS].  Shadowed memory mapped access to OTP Bank 2, word 7 (ADDR =
 * 0x17).   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_dcp7
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_dcp7_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Shadow register for the DCP Key word7 (Copy of OTP Bank 2, word 7 (ADDR = 0x17)). These bits can be not read and wrotten after the HW_OCOTP_LOCK_DCP bit is set. If read, returns 0xBADA_BADA and sets HW_OCOTP_CTRL[ERROR].
    } B;
} hw_ocotp_hw_ocotp_dcp7_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_DCP7 register
 */
#define HW_OCOTP_HW_OCOTP_DCP7_ADDR      (REGS_OCOTP_BASE + 0x570)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_DCP7           (*(volatile hw_ocotp_hw_ocotp_dcp7_t *) HW_OCOTP_HW_OCOTP_DCP7_ADDR)
#define HW_OCOTP_HW_OCOTP_DCP7_RD()      (HW_OCOTP_HW_OCOTP_DCP7.U)
#define HW_OCOTP_HW_OCOTP_DCP7_WR(v)     (HW_OCOTP_HW_OCOTP_DCP7.U = (v))
#define HW_OCOTP_HW_OCOTP_DCP7_SET(v)    (HW_OCOTP_HW_OCOTP_DCP7_WR(HW_OCOTP_HW_OCOTP_DCP7_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_DCP7_CLR(v)    (HW_OCOTP_HW_OCOTP_DCP7_WR(HW_OCOTP_HW_OCOTP_DCP7_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_DCP7_TOG(v)    (HW_OCOTP_HW_OCOTP_DCP7_WR(HW_OCOTP_HW_OCOTP_DCP7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_DCP7 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_DCP7, field BITS[31:0] (RW)
 *
 * Shadow register for the DCP Key word7 (Copy of OTP Bank 2, word 7 (ADDR = 0x17)). These bits can
 * be not read and wrotten after the HW_OCOTP_LOCK_DCP bit is set. If read, returns 0xBADA_BADA and
 * sets HW_OCOTP_CTRL[ERROR].
 */

#define BP_OCOTP_HW_OCOTP_DCP7_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_DCP7_BITS.
#define BM_OCOTP_HW_OCOTP_DCP7_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_DCP7_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_DCP7_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_DCP7_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_DCP7_BITS) >> BP_OCOTP_HW_OCOTP_DCP7_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_DCP7_BITS.
#define BF_OCOTP_HW_OCOTP_DCP7_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_DCP7_BITS) & BM_OCOTP_HW_OCOTP_DCP7_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_DCP7_BITS.
#define BF_OCOTP_HW_OCOTP_DCP7_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_DCP7_BITS) & BM_OCOTP_HW_OCOTP_DCP7_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_DCP7_BITS(v)   (HW_OCOTP_HW_OCOTP_DCP7_WR((HW_OCOTP_HW_OCOTP_DCP7_RD() & ~BM_OCOTP_HW_OCOTP_DCP7_BITS) | BF_OCOTP_HW_OCOTP_DCP7_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_SRK0 - Shadow Register for OTP Bank3 Word0 (SRK Hash) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS].  Shadowed memory mapped access to OTP Bank 3, word 0 (ADDR =
 * 0x18).   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_srk0
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_srk0_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Shadow register for the hash of the Super Root Key word0 (Copy of OTP Bank 3, word 0 (ADDR = 0x1C)). These bits become read-only after the HW_OCOTP_LOCK_SRK bit is set.
    } B;
} hw_ocotp_hw_ocotp_srk0_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_SRK0 register
 */
#define HW_OCOTP_HW_OCOTP_SRK0_ADDR      (REGS_OCOTP_BASE + 0x580)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_SRK0           (*(volatile hw_ocotp_hw_ocotp_srk0_t *) HW_OCOTP_HW_OCOTP_SRK0_ADDR)
#define HW_OCOTP_HW_OCOTP_SRK0_RD()      (HW_OCOTP_HW_OCOTP_SRK0.U)
#define HW_OCOTP_HW_OCOTP_SRK0_WR(v)     (HW_OCOTP_HW_OCOTP_SRK0.U = (v))
#define HW_OCOTP_HW_OCOTP_SRK0_SET(v)    (HW_OCOTP_HW_OCOTP_SRK0_WR(HW_OCOTP_HW_OCOTP_SRK0_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_SRK0_CLR(v)    (HW_OCOTP_HW_OCOTP_SRK0_WR(HW_OCOTP_HW_OCOTP_SRK0_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_SRK0_TOG(v)    (HW_OCOTP_HW_OCOTP_SRK0_WR(HW_OCOTP_HW_OCOTP_SRK0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_SRK0 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_SRK0, field BITS[31:0] (RW)
 *
 * Shadow register for the hash of the Super Root Key word0 (Copy of OTP Bank 3, word 0 (ADDR =
 * 0x1C)). These bits become read-only after the HW_OCOTP_LOCK_SRK bit is set.
 */

#define BP_OCOTP_HW_OCOTP_SRK0_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_SRK0_BITS.
#define BM_OCOTP_HW_OCOTP_SRK0_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_SRK0_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_SRK0_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_SRK0_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_SRK0_BITS) >> BP_OCOTP_HW_OCOTP_SRK0_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SRK0_BITS.
#define BF_OCOTP_HW_OCOTP_SRK0_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SRK0_BITS) & BM_OCOTP_HW_OCOTP_SRK0_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SRK0_BITS.
#define BF_OCOTP_HW_OCOTP_SRK0_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_SRK0_BITS) & BM_OCOTP_HW_OCOTP_SRK0_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_SRK0_BITS(v)   (HW_OCOTP_HW_OCOTP_SRK0_WR((HW_OCOTP_HW_OCOTP_SRK0_RD() & ~BM_OCOTP_HW_OCOTP_SRK0_BITS) | BF_OCOTP_HW_OCOTP_SRK0_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_SRK1 - Shadow Register for OTP Bank3 Word1 (SRK Hash) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS].  Shadowed memory mapped access to OTP Bank 3, word 1 (ADDR =
 * 0x19).   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_srk1
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_srk1_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Shadow register for the hash of the Super Root Key word1 (Copy of OTP Bank 3, word 1 (ADDR = 0x1D)). These bits become read-only after the HW_OCOTP_LOCK_SRK bit is set.
    } B;
} hw_ocotp_hw_ocotp_srk1_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_SRK1 register
 */
#define HW_OCOTP_HW_OCOTP_SRK1_ADDR      (REGS_OCOTP_BASE + 0x590)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_SRK1           (*(volatile hw_ocotp_hw_ocotp_srk1_t *) HW_OCOTP_HW_OCOTP_SRK1_ADDR)
#define HW_OCOTP_HW_OCOTP_SRK1_RD()      (HW_OCOTP_HW_OCOTP_SRK1.U)
#define HW_OCOTP_HW_OCOTP_SRK1_WR(v)     (HW_OCOTP_HW_OCOTP_SRK1.U = (v))
#define HW_OCOTP_HW_OCOTP_SRK1_SET(v)    (HW_OCOTP_HW_OCOTP_SRK1_WR(HW_OCOTP_HW_OCOTP_SRK1_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_SRK1_CLR(v)    (HW_OCOTP_HW_OCOTP_SRK1_WR(HW_OCOTP_HW_OCOTP_SRK1_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_SRK1_TOG(v)    (HW_OCOTP_HW_OCOTP_SRK1_WR(HW_OCOTP_HW_OCOTP_SRK1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_SRK1 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_SRK1, field BITS[31:0] (RW)
 *
 * Shadow register for the hash of the Super Root Key word1 (Copy of OTP Bank 3, word 1 (ADDR =
 * 0x1D)). These bits become read-only after the HW_OCOTP_LOCK_SRK bit is set.
 */

#define BP_OCOTP_HW_OCOTP_SRK1_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_SRK1_BITS.
#define BM_OCOTP_HW_OCOTP_SRK1_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_SRK1_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_SRK1_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_SRK1_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_SRK1_BITS) >> BP_OCOTP_HW_OCOTP_SRK1_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SRK1_BITS.
#define BF_OCOTP_HW_OCOTP_SRK1_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SRK1_BITS) & BM_OCOTP_HW_OCOTP_SRK1_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SRK1_BITS.
#define BF_OCOTP_HW_OCOTP_SRK1_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_SRK1_BITS) & BM_OCOTP_HW_OCOTP_SRK1_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_SRK1_BITS(v)   (HW_OCOTP_HW_OCOTP_SRK1_WR((HW_OCOTP_HW_OCOTP_SRK1_RD() & ~BM_OCOTP_HW_OCOTP_SRK1_BITS) | BF_OCOTP_HW_OCOTP_SRK1_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_SRK2 - Shadow Register for OTP Bank3 Word2 (SRK Hash) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS].  Shadowed memory mapped access to OTP Bank 3, word 2 (ADDR =
 * 0x1A).   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_srk2
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_srk2_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Shadow register for the hash of the Super Root Key word2 (Copy of OTP Bank 3, word 2 (ADDR = 0x1E)). These bits become read-only after the HW_OCOTP_LOCK_SRK bit is set.
    } B;
} hw_ocotp_hw_ocotp_srk2_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_SRK2 register
 */
#define HW_OCOTP_HW_OCOTP_SRK2_ADDR      (REGS_OCOTP_BASE + 0x5a0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_SRK2           (*(volatile hw_ocotp_hw_ocotp_srk2_t *) HW_OCOTP_HW_OCOTP_SRK2_ADDR)
#define HW_OCOTP_HW_OCOTP_SRK2_RD()      (HW_OCOTP_HW_OCOTP_SRK2.U)
#define HW_OCOTP_HW_OCOTP_SRK2_WR(v)     (HW_OCOTP_HW_OCOTP_SRK2.U = (v))
#define HW_OCOTP_HW_OCOTP_SRK2_SET(v)    (HW_OCOTP_HW_OCOTP_SRK2_WR(HW_OCOTP_HW_OCOTP_SRK2_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_SRK2_CLR(v)    (HW_OCOTP_HW_OCOTP_SRK2_WR(HW_OCOTP_HW_OCOTP_SRK2_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_SRK2_TOG(v)    (HW_OCOTP_HW_OCOTP_SRK2_WR(HW_OCOTP_HW_OCOTP_SRK2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_SRK2 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_SRK2, field BITS[31:0] (RW)
 *
 * Shadow register for the hash of the Super Root Key word2 (Copy of OTP Bank 3, word 2 (ADDR =
 * 0x1E)). These bits become read-only after the HW_OCOTP_LOCK_SRK bit is set.
 */

#define BP_OCOTP_HW_OCOTP_SRK2_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_SRK2_BITS.
#define BM_OCOTP_HW_OCOTP_SRK2_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_SRK2_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_SRK2_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_SRK2_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_SRK2_BITS) >> BP_OCOTP_HW_OCOTP_SRK2_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SRK2_BITS.
#define BF_OCOTP_HW_OCOTP_SRK2_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SRK2_BITS) & BM_OCOTP_HW_OCOTP_SRK2_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SRK2_BITS.
#define BF_OCOTP_HW_OCOTP_SRK2_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_SRK2_BITS) & BM_OCOTP_HW_OCOTP_SRK2_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_SRK2_BITS(v)   (HW_OCOTP_HW_OCOTP_SRK2_WR((HW_OCOTP_HW_OCOTP_SRK2_RD() & ~BM_OCOTP_HW_OCOTP_SRK2_BITS) | BF_OCOTP_HW_OCOTP_SRK2_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_SRK3 - Shadow Register for OTP Bank3 Word3 (SRK Hash) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS].  Shadowed memory mapped access to OTP Bank 3, word 3 (ADDR =
 * 0x1B).   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_srk3
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_srk3_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Shadow register for the hash of the Super Root Key word3 (Copy of OTP Bank 3, word 3 (ADDR = 0x1F)). These bits become read-only after the HW_OCOTP_LOCK_SRK bit is set.
    } B;
} hw_ocotp_hw_ocotp_srk3_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_SRK3 register
 */
#define HW_OCOTP_HW_OCOTP_SRK3_ADDR      (REGS_OCOTP_BASE + 0x5b0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_SRK3           (*(volatile hw_ocotp_hw_ocotp_srk3_t *) HW_OCOTP_HW_OCOTP_SRK3_ADDR)
#define HW_OCOTP_HW_OCOTP_SRK3_RD()      (HW_OCOTP_HW_OCOTP_SRK3.U)
#define HW_OCOTP_HW_OCOTP_SRK3_WR(v)     (HW_OCOTP_HW_OCOTP_SRK3.U = (v))
#define HW_OCOTP_HW_OCOTP_SRK3_SET(v)    (HW_OCOTP_HW_OCOTP_SRK3_WR(HW_OCOTP_HW_OCOTP_SRK3_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_SRK3_CLR(v)    (HW_OCOTP_HW_OCOTP_SRK3_WR(HW_OCOTP_HW_OCOTP_SRK3_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_SRK3_TOG(v)    (HW_OCOTP_HW_OCOTP_SRK3_WR(HW_OCOTP_HW_OCOTP_SRK3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_SRK3 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_SRK3, field BITS[31:0] (RW)
 *
 * Shadow register for the hash of the Super Root Key word3 (Copy of OTP Bank 3, word 3 (ADDR =
 * 0x1F)). These bits become read-only after the HW_OCOTP_LOCK_SRK bit is set.
 */

#define BP_OCOTP_HW_OCOTP_SRK3_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_SRK3_BITS.
#define BM_OCOTP_HW_OCOTP_SRK3_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_SRK3_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_SRK3_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_SRK3_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_SRK3_BITS) >> BP_OCOTP_HW_OCOTP_SRK3_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SRK3_BITS.
#define BF_OCOTP_HW_OCOTP_SRK3_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SRK3_BITS) & BM_OCOTP_HW_OCOTP_SRK3_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SRK3_BITS.
#define BF_OCOTP_HW_OCOTP_SRK3_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_SRK3_BITS) & BM_OCOTP_HW_OCOTP_SRK3_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_SRK3_BITS(v)   (HW_OCOTP_HW_OCOTP_SRK3_WR((HW_OCOTP_HW_OCOTP_SRK3_RD() & ~BM_OCOTP_HW_OCOTP_SRK3_BITS) | BF_OCOTP_HW_OCOTP_SRK3_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_SRK4 - Shadow Register for OTP Bank3 Word4 (SRK Hash) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS].  Shadowed memory mapped access to OTP Bank 3, word 4 (ADDR =
 * 0x1C).   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_srk4
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_srk4_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Shadow register for the hash of the Super Root Key word4 (Copy of OTP Bank 3, word 4 (ADDR = 0x20)). These bits become read-only after the HW_OCOTP_LOCK_SRK bit is set.
    } B;
} hw_ocotp_hw_ocotp_srk4_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_SRK4 register
 */
#define HW_OCOTP_HW_OCOTP_SRK4_ADDR      (REGS_OCOTP_BASE + 0x5c0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_SRK4           (*(volatile hw_ocotp_hw_ocotp_srk4_t *) HW_OCOTP_HW_OCOTP_SRK4_ADDR)
#define HW_OCOTP_HW_OCOTP_SRK4_RD()      (HW_OCOTP_HW_OCOTP_SRK4.U)
#define HW_OCOTP_HW_OCOTP_SRK4_WR(v)     (HW_OCOTP_HW_OCOTP_SRK4.U = (v))
#define HW_OCOTP_HW_OCOTP_SRK4_SET(v)    (HW_OCOTP_HW_OCOTP_SRK4_WR(HW_OCOTP_HW_OCOTP_SRK4_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_SRK4_CLR(v)    (HW_OCOTP_HW_OCOTP_SRK4_WR(HW_OCOTP_HW_OCOTP_SRK4_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_SRK4_TOG(v)    (HW_OCOTP_HW_OCOTP_SRK4_WR(HW_OCOTP_HW_OCOTP_SRK4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_SRK4 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_SRK4, field BITS[31:0] (RW)
 *
 * Shadow register for the hash of the Super Root Key word4 (Copy of OTP Bank 3, word 4 (ADDR =
 * 0x20)). These bits become read-only after the HW_OCOTP_LOCK_SRK bit is set.
 */

#define BP_OCOTP_HW_OCOTP_SRK4_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_SRK4_BITS.
#define BM_OCOTP_HW_OCOTP_SRK4_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_SRK4_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_SRK4_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_SRK4_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_SRK4_BITS) >> BP_OCOTP_HW_OCOTP_SRK4_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SRK4_BITS.
#define BF_OCOTP_HW_OCOTP_SRK4_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SRK4_BITS) & BM_OCOTP_HW_OCOTP_SRK4_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SRK4_BITS.
#define BF_OCOTP_HW_OCOTP_SRK4_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_SRK4_BITS) & BM_OCOTP_HW_OCOTP_SRK4_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_SRK4_BITS(v)   (HW_OCOTP_HW_OCOTP_SRK4_WR((HW_OCOTP_HW_OCOTP_SRK4_RD() & ~BM_OCOTP_HW_OCOTP_SRK4_BITS) | BF_OCOTP_HW_OCOTP_SRK4_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_SRK5 - Shadow Register for OTP Bank3 Word5 (SRK Hash) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS].  Shadowed memory mapped access to OTP Bank 3, word 5 (ADDR =
 * 0x1D).   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_srk5
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_srk5_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Shadow register for the hash of the Super Root Key word5 (Copy of OTP Bank 3, word 5 (ADDR = 0x21)). These bits become read-only after the HW_OCOTP_LOCK_SRK bit is set.
    } B;
} hw_ocotp_hw_ocotp_srk5_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_SRK5 register
 */
#define HW_OCOTP_HW_OCOTP_SRK5_ADDR      (REGS_OCOTP_BASE + 0x5d0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_SRK5           (*(volatile hw_ocotp_hw_ocotp_srk5_t *) HW_OCOTP_HW_OCOTP_SRK5_ADDR)
#define HW_OCOTP_HW_OCOTP_SRK5_RD()      (HW_OCOTP_HW_OCOTP_SRK5.U)
#define HW_OCOTP_HW_OCOTP_SRK5_WR(v)     (HW_OCOTP_HW_OCOTP_SRK5.U = (v))
#define HW_OCOTP_HW_OCOTP_SRK5_SET(v)    (HW_OCOTP_HW_OCOTP_SRK5_WR(HW_OCOTP_HW_OCOTP_SRK5_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_SRK5_CLR(v)    (HW_OCOTP_HW_OCOTP_SRK5_WR(HW_OCOTP_HW_OCOTP_SRK5_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_SRK5_TOG(v)    (HW_OCOTP_HW_OCOTP_SRK5_WR(HW_OCOTP_HW_OCOTP_SRK5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_SRK5 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_SRK5, field BITS[31:0] (RW)
 *
 * Shadow register for the hash of the Super Root Key word5 (Copy of OTP Bank 3, word 5 (ADDR =
 * 0x21)). These bits become read-only after the HW_OCOTP_LOCK_SRK bit is set.
 */

#define BP_OCOTP_HW_OCOTP_SRK5_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_SRK5_BITS.
#define BM_OCOTP_HW_OCOTP_SRK5_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_SRK5_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_SRK5_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_SRK5_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_SRK5_BITS) >> BP_OCOTP_HW_OCOTP_SRK5_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SRK5_BITS.
#define BF_OCOTP_HW_OCOTP_SRK5_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SRK5_BITS) & BM_OCOTP_HW_OCOTP_SRK5_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SRK5_BITS.
#define BF_OCOTP_HW_OCOTP_SRK5_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_SRK5_BITS) & BM_OCOTP_HW_OCOTP_SRK5_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_SRK5_BITS(v)   (HW_OCOTP_HW_OCOTP_SRK5_WR((HW_OCOTP_HW_OCOTP_SRK5_RD() & ~BM_OCOTP_HW_OCOTP_SRK5_BITS) | BF_OCOTP_HW_OCOTP_SRK5_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_SRK6 - Shadow Register for OTP Bank3 Word6 (SRK Hash) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS].  Shadowed memory mapped access to OTP Bank 3, word 6 (ADDR =
 * 0x1E).   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_srk6
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_srk6_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Shadow register for the hash of the Super Root Key word6 (Copy of OTP Bank 3, word 6 (ADDR = 0x22)). These bits become read-only after the HW_OCOTP_LOCK_SRK bit is set.
    } B;
} hw_ocotp_hw_ocotp_srk6_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_SRK6 register
 */
#define HW_OCOTP_HW_OCOTP_SRK6_ADDR      (REGS_OCOTP_BASE + 0x5e0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_SRK6           (*(volatile hw_ocotp_hw_ocotp_srk6_t *) HW_OCOTP_HW_OCOTP_SRK6_ADDR)
#define HW_OCOTP_HW_OCOTP_SRK6_RD()      (HW_OCOTP_HW_OCOTP_SRK6.U)
#define HW_OCOTP_HW_OCOTP_SRK6_WR(v)     (HW_OCOTP_HW_OCOTP_SRK6.U = (v))
#define HW_OCOTP_HW_OCOTP_SRK6_SET(v)    (HW_OCOTP_HW_OCOTP_SRK6_WR(HW_OCOTP_HW_OCOTP_SRK6_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_SRK6_CLR(v)    (HW_OCOTP_HW_OCOTP_SRK6_WR(HW_OCOTP_HW_OCOTP_SRK6_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_SRK6_TOG(v)    (HW_OCOTP_HW_OCOTP_SRK6_WR(HW_OCOTP_HW_OCOTP_SRK6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_SRK6 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_SRK6, field BITS[31:0] (RW)
 *
 * Shadow register for the hash of the Super Root Key word6 (Copy of OTP Bank 3, word 6 (ADDR =
 * 0x22)). These bits become read-only after the HW_OCOTP_LOCK_SRK bit is set.
 */

#define BP_OCOTP_HW_OCOTP_SRK6_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_SRK6_BITS.
#define BM_OCOTP_HW_OCOTP_SRK6_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_SRK6_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_SRK6_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_SRK6_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_SRK6_BITS) >> BP_OCOTP_HW_OCOTP_SRK6_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SRK6_BITS.
#define BF_OCOTP_HW_OCOTP_SRK6_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SRK6_BITS) & BM_OCOTP_HW_OCOTP_SRK6_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SRK6_BITS.
#define BF_OCOTP_HW_OCOTP_SRK6_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_SRK6_BITS) & BM_OCOTP_HW_OCOTP_SRK6_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_SRK6_BITS(v)   (HW_OCOTP_HW_OCOTP_SRK6_WR((HW_OCOTP_HW_OCOTP_SRK6_RD() & ~BM_OCOTP_HW_OCOTP_SRK6_BITS) | BF_OCOTP_HW_OCOTP_SRK6_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_SRK7 - Shadow Register for OTP Bank3 Word7 (SRK Hash) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS].  Shadowed memory mapped access to OTP Bank 3, word 7 (ADDR =
 * 0x1F).   EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_srk7
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_srk7_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Shadow register for the hash of the Super Root Key word7 (Copy of OTP Bank 3, word 7 (ADDR = 0x23)). These bits become read-only after the HW_OCOTP_LOCK_SRK bit is set.
    } B;
} hw_ocotp_hw_ocotp_srk7_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_SRK7 register
 */
#define HW_OCOTP_HW_OCOTP_SRK7_ADDR      (REGS_OCOTP_BASE + 0x5f0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_SRK7           (*(volatile hw_ocotp_hw_ocotp_srk7_t *) HW_OCOTP_HW_OCOTP_SRK7_ADDR)
#define HW_OCOTP_HW_OCOTP_SRK7_RD()      (HW_OCOTP_HW_OCOTP_SRK7.U)
#define HW_OCOTP_HW_OCOTP_SRK7_WR(v)     (HW_OCOTP_HW_OCOTP_SRK7.U = (v))
#define HW_OCOTP_HW_OCOTP_SRK7_SET(v)    (HW_OCOTP_HW_OCOTP_SRK7_WR(HW_OCOTP_HW_OCOTP_SRK7_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_SRK7_CLR(v)    (HW_OCOTP_HW_OCOTP_SRK7_WR(HW_OCOTP_HW_OCOTP_SRK7_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_SRK7_TOG(v)    (HW_OCOTP_HW_OCOTP_SRK7_WR(HW_OCOTP_HW_OCOTP_SRK7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_SRK7 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_SRK7, field BITS[31:0] (RW)
 *
 * Shadow register for the hash of the Super Root Key word7 (Copy of OTP Bank 3, word 7 (ADDR =
 * 0x23)). These bits become read-only after the HW_OCOTP_LOCK_SRK bit is set.
 */

#define BP_OCOTP_HW_OCOTP_SRK7_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_SRK7_BITS.
#define BM_OCOTP_HW_OCOTP_SRK7_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_SRK7_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_SRK7_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_SRK7_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_SRK7_BITS) >> BP_OCOTP_HW_OCOTP_SRK7_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SRK7_BITS.
#define BF_OCOTP_HW_OCOTP_SRK7_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SRK7_BITS) & BM_OCOTP_HW_OCOTP_SRK7_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SRK7_BITS.
#define BF_OCOTP_HW_OCOTP_SRK7_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_SRK7_BITS) & BM_OCOTP_HW_OCOTP_SRK7_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_SRK7_BITS(v)   (HW_OCOTP_HW_OCOTP_SRK7_WR((HW_OCOTP_HW_OCOTP_SRK7_RD() & ~BM_OCOTP_HW_OCOTP_SRK7_BITS) | BF_OCOTP_HW_OCOTP_SRK7_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_SJC_RESP0 - Value of OTP Bank4 Word0 (Secure JTAG Response Field) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 4, word 0 (ADDR = 0x20).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_sjc_resp0
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_sjc_resp0_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Shadow register for the SJC_RESP Key word0 (Copy of OTP Bank 4, word 0 (ADDR = 0x20)). These bits can be not read and wrotten after the HW_OCOTP_LOCK_SJC_RESP bit is set. If read, returns 0xBADA_BADA and sets HW_OCOTP_CTRL[ERROR].
    } B;
} hw_ocotp_hw_ocotp_sjc_resp0_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_SJC_RESP0 register
 */
#define HW_OCOTP_HW_OCOTP_SJC_RESP0_ADDR      (REGS_OCOTP_BASE + 0x600)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_SJC_RESP0           (*(volatile hw_ocotp_hw_ocotp_sjc_resp0_t *) HW_OCOTP_HW_OCOTP_SJC_RESP0_ADDR)
#define HW_OCOTP_HW_OCOTP_SJC_RESP0_RD()      (HW_OCOTP_HW_OCOTP_SJC_RESP0.U)
#define HW_OCOTP_HW_OCOTP_SJC_RESP0_WR(v)     (HW_OCOTP_HW_OCOTP_SJC_RESP0.U = (v))
#define HW_OCOTP_HW_OCOTP_SJC_RESP0_SET(v)    (HW_OCOTP_HW_OCOTP_SJC_RESP0_WR(HW_OCOTP_HW_OCOTP_SJC_RESP0_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_SJC_RESP0_CLR(v)    (HW_OCOTP_HW_OCOTP_SJC_RESP0_WR(HW_OCOTP_HW_OCOTP_SJC_RESP0_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_SJC_RESP0_TOG(v)    (HW_OCOTP_HW_OCOTP_SJC_RESP0_WR(HW_OCOTP_HW_OCOTP_SJC_RESP0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_SJC_RESP0 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_SJC_RESP0, field BITS[31:0] (RW)
 *
 * Shadow register for the SJC_RESP Key word0 (Copy of OTP Bank 4, word 0 (ADDR = 0x20)). These bits
 * can be not read and wrotten after the HW_OCOTP_LOCK_SJC_RESP bit is set. If read, returns
 * 0xBADA_BADA and sets HW_OCOTP_CTRL[ERROR].
 */

#define BP_OCOTP_HW_OCOTP_SJC_RESP0_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_SJC_RESP0_BITS.
#define BM_OCOTP_HW_OCOTP_SJC_RESP0_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_SJC_RESP0_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_SJC_RESP0_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_SJC_RESP0_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_SJC_RESP0_BITS) >> BP_OCOTP_HW_OCOTP_SJC_RESP0_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SJC_RESP0_BITS.
#define BF_OCOTP_HW_OCOTP_SJC_RESP0_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SJC_RESP0_BITS) & BM_OCOTP_HW_OCOTP_SJC_RESP0_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SJC_RESP0_BITS.
#define BF_OCOTP_HW_OCOTP_SJC_RESP0_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_SJC_RESP0_BITS) & BM_OCOTP_HW_OCOTP_SJC_RESP0_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_SJC_RESP0_BITS(v)   (HW_OCOTP_HW_OCOTP_SJC_RESP0_WR((HW_OCOTP_HW_OCOTP_SJC_RESP0_RD() & ~BM_OCOTP_HW_OCOTP_SJC_RESP0_BITS) | BF_OCOTP_HW_OCOTP_SJC_RESP0_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_SJC_RESP1 - Value of OTP Bank4 Word1 (Secure JTAG Response Field) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 4, word 1 (ADDR = 0x21).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_sjc_resp1
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_sjc_resp1_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Shadow register for the SJC_RESP Key word1 (Copy of OTP Bank 4, word 1 (ADDR = 0x21)). These bits can be not read and wrotten after the HW_OCOTP_LOCK_SJC_RESP bit is set. If read, returns 0xBADA_BADA and sets HW_OCOTP_CTRL[ERROR].
    } B;
} hw_ocotp_hw_ocotp_sjc_resp1_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_SJC_RESP1 register
 */
#define HW_OCOTP_HW_OCOTP_SJC_RESP1_ADDR      (REGS_OCOTP_BASE + 0x610)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_SJC_RESP1           (*(volatile hw_ocotp_hw_ocotp_sjc_resp1_t *) HW_OCOTP_HW_OCOTP_SJC_RESP1_ADDR)
#define HW_OCOTP_HW_OCOTP_SJC_RESP1_RD()      (HW_OCOTP_HW_OCOTP_SJC_RESP1.U)
#define HW_OCOTP_HW_OCOTP_SJC_RESP1_WR(v)     (HW_OCOTP_HW_OCOTP_SJC_RESP1.U = (v))
#define HW_OCOTP_HW_OCOTP_SJC_RESP1_SET(v)    (HW_OCOTP_HW_OCOTP_SJC_RESP1_WR(HW_OCOTP_HW_OCOTP_SJC_RESP1_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_SJC_RESP1_CLR(v)    (HW_OCOTP_HW_OCOTP_SJC_RESP1_WR(HW_OCOTP_HW_OCOTP_SJC_RESP1_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_SJC_RESP1_TOG(v)    (HW_OCOTP_HW_OCOTP_SJC_RESP1_WR(HW_OCOTP_HW_OCOTP_SJC_RESP1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_SJC_RESP1 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_SJC_RESP1, field BITS[31:0] (RW)
 *
 * Shadow register for the SJC_RESP Key word1 (Copy of OTP Bank 4, word 1 (ADDR = 0x21)). These bits
 * can be not read and wrotten after the HW_OCOTP_LOCK_SJC_RESP bit is set. If read, returns
 * 0xBADA_BADA and sets HW_OCOTP_CTRL[ERROR].
 */

#define BP_OCOTP_HW_OCOTP_SJC_RESP1_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_SJC_RESP1_BITS.
#define BM_OCOTP_HW_OCOTP_SJC_RESP1_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_SJC_RESP1_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_SJC_RESP1_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_SJC_RESP1_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_SJC_RESP1_BITS) >> BP_OCOTP_HW_OCOTP_SJC_RESP1_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SJC_RESP1_BITS.
#define BF_OCOTP_HW_OCOTP_SJC_RESP1_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SJC_RESP1_BITS) & BM_OCOTP_HW_OCOTP_SJC_RESP1_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SJC_RESP1_BITS.
#define BF_OCOTP_HW_OCOTP_SJC_RESP1_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_SJC_RESP1_BITS) & BM_OCOTP_HW_OCOTP_SJC_RESP1_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_SJC_RESP1_BITS(v)   (HW_OCOTP_HW_OCOTP_SJC_RESP1_WR((HW_OCOTP_HW_OCOTP_SJC_RESP1_RD() & ~BM_OCOTP_HW_OCOTP_SJC_RESP1_BITS) | BF_OCOTP_HW_OCOTP_SJC_RESP1_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_MAC0 - Value of OTP Bank4 Word2 (MAC Address) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 4, word 2 (ADDR = 0x22).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_mac0
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_mac0_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 4, word 2 (ADDR = 0x22).
    } B;
} hw_ocotp_hw_ocotp_mac0_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_MAC0 register
 */
#define HW_OCOTP_HW_OCOTP_MAC0_ADDR      (REGS_OCOTP_BASE + 0x620)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_MAC0           (*(volatile hw_ocotp_hw_ocotp_mac0_t *) HW_OCOTP_HW_OCOTP_MAC0_ADDR)
#define HW_OCOTP_HW_OCOTP_MAC0_RD()      (HW_OCOTP_HW_OCOTP_MAC0.U)
#define HW_OCOTP_HW_OCOTP_MAC0_WR(v)     (HW_OCOTP_HW_OCOTP_MAC0.U = (v))
#define HW_OCOTP_HW_OCOTP_MAC0_SET(v)    (HW_OCOTP_HW_OCOTP_MAC0_WR(HW_OCOTP_HW_OCOTP_MAC0_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_MAC0_CLR(v)    (HW_OCOTP_HW_OCOTP_MAC0_WR(HW_OCOTP_HW_OCOTP_MAC0_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_MAC0_TOG(v)    (HW_OCOTP_HW_OCOTP_MAC0_WR(HW_OCOTP_HW_OCOTP_MAC0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_MAC0 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_MAC0, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 4, word 2 (ADDR = 0x22).
 */

#define BP_OCOTP_HW_OCOTP_MAC0_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_MAC0_BITS.
#define BM_OCOTP_HW_OCOTP_MAC0_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_MAC0_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_MAC0_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_MAC0_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_MAC0_BITS) >> BP_OCOTP_HW_OCOTP_MAC0_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_MAC0_BITS.
#define BF_OCOTP_HW_OCOTP_MAC0_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_MAC0_BITS) & BM_OCOTP_HW_OCOTP_MAC0_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_MAC0_BITS.
#define BF_OCOTP_HW_OCOTP_MAC0_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_MAC0_BITS) & BM_OCOTP_HW_OCOTP_MAC0_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_MAC0_BITS(v)   (HW_OCOTP_HW_OCOTP_MAC0_WR((HW_OCOTP_HW_OCOTP_MAC0_RD() & ~BM_OCOTP_HW_OCOTP_MAC0_BITS) | BF_OCOTP_HW_OCOTP_MAC0_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_MAC1 - Value of OTP Bank4 Word3 (MAC Address) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 4, word 3 (ADDR = 0x23).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_mac1
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_mac1_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 4, word 3 (ADDR = 0x23).
    } B;
} hw_ocotp_hw_ocotp_mac1_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_MAC1 register
 */
#define HW_OCOTP_HW_OCOTP_MAC1_ADDR      (REGS_OCOTP_BASE + 0x630)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_MAC1           (*(volatile hw_ocotp_hw_ocotp_mac1_t *) HW_OCOTP_HW_OCOTP_MAC1_ADDR)
#define HW_OCOTP_HW_OCOTP_MAC1_RD()      (HW_OCOTP_HW_OCOTP_MAC1.U)
#define HW_OCOTP_HW_OCOTP_MAC1_WR(v)     (HW_OCOTP_HW_OCOTP_MAC1.U = (v))
#define HW_OCOTP_HW_OCOTP_MAC1_SET(v)    (HW_OCOTP_HW_OCOTP_MAC1_WR(HW_OCOTP_HW_OCOTP_MAC1_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_MAC1_CLR(v)    (HW_OCOTP_HW_OCOTP_MAC1_WR(HW_OCOTP_HW_OCOTP_MAC1_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_MAC1_TOG(v)    (HW_OCOTP_HW_OCOTP_MAC1_WR(HW_OCOTP_HW_OCOTP_MAC1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_MAC1 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_MAC1, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 4, word 3 (ADDR = 0x23).
 */

#define BP_OCOTP_HW_OCOTP_MAC1_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_MAC1_BITS.
#define BM_OCOTP_HW_OCOTP_MAC1_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_MAC1_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_MAC1_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_MAC1_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_MAC1_BITS) >> BP_OCOTP_HW_OCOTP_MAC1_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_MAC1_BITS.
#define BF_OCOTP_HW_OCOTP_MAC1_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_MAC1_BITS) & BM_OCOTP_HW_OCOTP_MAC1_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_MAC1_BITS.
#define BF_OCOTP_HW_OCOTP_MAC1_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_MAC1_BITS) & BM_OCOTP_HW_OCOTP_MAC1_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_MAC1_BITS(v)   (HW_OCOTP_HW_OCOTP_MAC1_WR((HW_OCOTP_HW_OCOTP_MAC1_RD() & ~BM_OCOTP_HW_OCOTP_MAC1_BITS) | BF_OCOTP_HW_OCOTP_MAC1_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_CRC0 - Value of OTP Bank4 Word4 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 4, word 4 (ADDR = 0x24).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_crc0
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_crc0_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 4, word 4 (ADDR = 0x24).
    } B;
} hw_ocotp_hw_ocotp_crc0_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_CRC0 register
 */
#define HW_OCOTP_HW_OCOTP_CRC0_ADDR      (REGS_OCOTP_BASE + 0x640)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_CRC0           (*(volatile hw_ocotp_hw_ocotp_crc0_t *) HW_OCOTP_HW_OCOTP_CRC0_ADDR)
#define HW_OCOTP_HW_OCOTP_CRC0_RD()      (HW_OCOTP_HW_OCOTP_CRC0.U)
#define HW_OCOTP_HW_OCOTP_CRC0_WR(v)     (HW_OCOTP_HW_OCOTP_CRC0.U = (v))
#define HW_OCOTP_HW_OCOTP_CRC0_SET(v)    (HW_OCOTP_HW_OCOTP_CRC0_WR(HW_OCOTP_HW_OCOTP_CRC0_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_CRC0_CLR(v)    (HW_OCOTP_HW_OCOTP_CRC0_WR(HW_OCOTP_HW_OCOTP_CRC0_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_CRC0_TOG(v)    (HW_OCOTP_HW_OCOTP_CRC0_WR(HW_OCOTP_HW_OCOTP_CRC0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_CRC0 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_CRC0, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 4, word 4 (ADDR = 0x24).
 */

#define BP_OCOTP_HW_OCOTP_CRC0_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_CRC0_BITS.
#define BM_OCOTP_HW_OCOTP_CRC0_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_CRC0_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_CRC0_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_CRC0_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_CRC0_BITS) >> BP_OCOTP_HW_OCOTP_CRC0_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CRC0_BITS.
#define BF_OCOTP_HW_OCOTP_CRC0_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_CRC0_BITS) & BM_OCOTP_HW_OCOTP_CRC0_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CRC0_BITS.
#define BF_OCOTP_HW_OCOTP_CRC0_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_CRC0_BITS) & BM_OCOTP_HW_OCOTP_CRC0_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_CRC0_BITS(v)   (HW_OCOTP_HW_OCOTP_CRC0_WR((HW_OCOTP_HW_OCOTP_CRC0_RD() & ~BM_OCOTP_HW_OCOTP_CRC0_BITS) | BF_OCOTP_HW_OCOTP_CRC0_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_CRC1 - Value of OTP Bank4 Word5 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 4, word 5 (ADDR = 0x25).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_crc1
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_crc1_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 4, word 5 (ADDR = 0x25).
    } B;
} hw_ocotp_hw_ocotp_crc1_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_CRC1 register
 */
#define HW_OCOTP_HW_OCOTP_CRC1_ADDR      (REGS_OCOTP_BASE + 0x650)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_CRC1           (*(volatile hw_ocotp_hw_ocotp_crc1_t *) HW_OCOTP_HW_OCOTP_CRC1_ADDR)
#define HW_OCOTP_HW_OCOTP_CRC1_RD()      (HW_OCOTP_HW_OCOTP_CRC1.U)
#define HW_OCOTP_HW_OCOTP_CRC1_WR(v)     (HW_OCOTP_HW_OCOTP_CRC1.U = (v))
#define HW_OCOTP_HW_OCOTP_CRC1_SET(v)    (HW_OCOTP_HW_OCOTP_CRC1_WR(HW_OCOTP_HW_OCOTP_CRC1_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_CRC1_CLR(v)    (HW_OCOTP_HW_OCOTP_CRC1_WR(HW_OCOTP_HW_OCOTP_CRC1_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_CRC1_TOG(v)    (HW_OCOTP_HW_OCOTP_CRC1_WR(HW_OCOTP_HW_OCOTP_CRC1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_CRC1 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_CRC1, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 4, word 5 (ADDR = 0x25).
 */

#define BP_OCOTP_HW_OCOTP_CRC1_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_CRC1_BITS.
#define BM_OCOTP_HW_OCOTP_CRC1_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_CRC1_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_CRC1_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_CRC1_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_CRC1_BITS) >> BP_OCOTP_HW_OCOTP_CRC1_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CRC1_BITS.
#define BF_OCOTP_HW_OCOTP_CRC1_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_CRC1_BITS) & BM_OCOTP_HW_OCOTP_CRC1_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_CRC1_BITS.
#define BF_OCOTP_HW_OCOTP_CRC1_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_CRC1_BITS) & BM_OCOTP_HW_OCOTP_CRC1_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_CRC1_BITS(v)   (HW_OCOTP_HW_OCOTP_CRC1_WR((HW_OCOTP_HW_OCOTP_CRC1_RD() & ~BM_OCOTP_HW_OCOTP_CRC1_BITS) | BF_OCOTP_HW_OCOTP_CRC1_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_GP1 - Value of OTP Bank4 Word6 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 4, word 6 (ADDR = 0x26).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_gp1
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_gp1_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 4, word 6 (ADDR = 0x26).
    } B;
} hw_ocotp_hw_ocotp_gp1_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_GP1 register
 */
#define HW_OCOTP_HW_OCOTP_GP1_ADDR      (REGS_OCOTP_BASE + 0x660)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_GP1           (*(volatile hw_ocotp_hw_ocotp_gp1_t *) HW_OCOTP_HW_OCOTP_GP1_ADDR)
#define HW_OCOTP_HW_OCOTP_GP1_RD()      (HW_OCOTP_HW_OCOTP_GP1.U)
#define HW_OCOTP_HW_OCOTP_GP1_WR(v)     (HW_OCOTP_HW_OCOTP_GP1.U = (v))
#define HW_OCOTP_HW_OCOTP_GP1_SET(v)    (HW_OCOTP_HW_OCOTP_GP1_WR(HW_OCOTP_HW_OCOTP_GP1_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_GP1_CLR(v)    (HW_OCOTP_HW_OCOTP_GP1_WR(HW_OCOTP_HW_OCOTP_GP1_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_GP1_TOG(v)    (HW_OCOTP_HW_OCOTP_GP1_WR(HW_OCOTP_HW_OCOTP_GP1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_GP1 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_GP1, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 4, word 6 (ADDR = 0x26).
 */

#define BP_OCOTP_HW_OCOTP_GP1_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_GP1_BITS.
#define BM_OCOTP_HW_OCOTP_GP1_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_GP1_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_GP1_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_GP1_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_GP1_BITS) >> BP_OCOTP_HW_OCOTP_GP1_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP1_BITS.
#define BF_OCOTP_HW_OCOTP_GP1_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_GP1_BITS) & BM_OCOTP_HW_OCOTP_GP1_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP1_BITS.
#define BF_OCOTP_HW_OCOTP_GP1_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_GP1_BITS) & BM_OCOTP_HW_OCOTP_GP1_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_GP1_BITS(v)   (HW_OCOTP_HW_OCOTP_GP1_WR((HW_OCOTP_HW_OCOTP_GP1_RD() & ~BM_OCOTP_HW_OCOTP_GP1_BITS) | BF_OCOTP_HW_OCOTP_GP1_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_GP2 - Value of OTP Bank4 Word7 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 4, word 7 (ADDR = 0x27).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_gp2
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_gp2_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 4, word 7 (ADDR = 0x27).
    } B;
} hw_ocotp_hw_ocotp_gp2_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_GP2 register
 */
#define HW_OCOTP_HW_OCOTP_GP2_ADDR      (REGS_OCOTP_BASE + 0x670)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_GP2           (*(volatile hw_ocotp_hw_ocotp_gp2_t *) HW_OCOTP_HW_OCOTP_GP2_ADDR)
#define HW_OCOTP_HW_OCOTP_GP2_RD()      (HW_OCOTP_HW_OCOTP_GP2.U)
#define HW_OCOTP_HW_OCOTP_GP2_WR(v)     (HW_OCOTP_HW_OCOTP_GP2.U = (v))
#define HW_OCOTP_HW_OCOTP_GP2_SET(v)    (HW_OCOTP_HW_OCOTP_GP2_WR(HW_OCOTP_HW_OCOTP_GP2_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_GP2_CLR(v)    (HW_OCOTP_HW_OCOTP_GP2_WR(HW_OCOTP_HW_OCOTP_GP2_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_GP2_TOG(v)    (HW_OCOTP_HW_OCOTP_GP2_WR(HW_OCOTP_HW_OCOTP_GP2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_GP2 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_GP2, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 4, word 7 (ADDR = 0x27).
 */

#define BP_OCOTP_HW_OCOTP_GP2_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_GP2_BITS.
#define BM_OCOTP_HW_OCOTP_GP2_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_GP2_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_GP2_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_GP2_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_GP2_BITS) >> BP_OCOTP_HW_OCOTP_GP2_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP2_BITS.
#define BF_OCOTP_HW_OCOTP_GP2_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_GP2_BITS) & BM_OCOTP_HW_OCOTP_GP2_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP2_BITS.
#define BF_OCOTP_HW_OCOTP_GP2_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_GP2_BITS) & BM_OCOTP_HW_OCOTP_GP2_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_GP2_BITS(v)   (HW_OCOTP_HW_OCOTP_GP2_WR((HW_OCOTP_HW_OCOTP_GP2_RD() & ~BM_OCOTP_HW_OCOTP_GP2_BITS) | BF_OCOTP_HW_OCOTP_GP2_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_SW_GP0 - Value of OTP Bank5 Word0 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 5, word 0 (ADDR = 0x28).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_sw_gp0
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_sw_gp0_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 5, word 0 (ADDR = 0x28).
    } B;
} hw_ocotp_hw_ocotp_sw_gp0_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_SW_GP0 register
 */
#define HW_OCOTP_HW_OCOTP_SW_GP0_ADDR      (REGS_OCOTP_BASE + 0x680)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_SW_GP0           (*(volatile hw_ocotp_hw_ocotp_sw_gp0_t *) HW_OCOTP_HW_OCOTP_SW_GP0_ADDR)
#define HW_OCOTP_HW_OCOTP_SW_GP0_RD()      (HW_OCOTP_HW_OCOTP_SW_GP0.U)
#define HW_OCOTP_HW_OCOTP_SW_GP0_WR(v)     (HW_OCOTP_HW_OCOTP_SW_GP0.U = (v))
#define HW_OCOTP_HW_OCOTP_SW_GP0_SET(v)    (HW_OCOTP_HW_OCOTP_SW_GP0_WR(HW_OCOTP_HW_OCOTP_SW_GP0_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_SW_GP0_CLR(v)    (HW_OCOTP_HW_OCOTP_SW_GP0_WR(HW_OCOTP_HW_OCOTP_SW_GP0_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_SW_GP0_TOG(v)    (HW_OCOTP_HW_OCOTP_SW_GP0_WR(HW_OCOTP_HW_OCOTP_SW_GP0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_SW_GP0 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_SW_GP0, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 5, word 0 (ADDR = 0x28).
 */

#define BP_OCOTP_HW_OCOTP_SW_GP0_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_SW_GP0_BITS.
#define BM_OCOTP_HW_OCOTP_SW_GP0_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_SW_GP0_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_SW_GP0_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_SW_GP0_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_SW_GP0_BITS) >> BP_OCOTP_HW_OCOTP_SW_GP0_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_GP0_BITS.
#define BF_OCOTP_HW_OCOTP_SW_GP0_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SW_GP0_BITS) & BM_OCOTP_HW_OCOTP_SW_GP0_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_GP0_BITS.
#define BF_OCOTP_HW_OCOTP_SW_GP0_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_SW_GP0_BITS) & BM_OCOTP_HW_OCOTP_SW_GP0_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_SW_GP0_BITS(v)   (HW_OCOTP_HW_OCOTP_SW_GP0_WR((HW_OCOTP_HW_OCOTP_SW_GP0_RD() & ~BM_OCOTP_HW_OCOTP_SW_GP0_BITS) | BF_OCOTP_HW_OCOTP_SW_GP0_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_SW_GP1 - Value of OTP Bank5 Word1 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 5, word 1 (ADDR = 0x29).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_sw_gp1
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_sw_gp1_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 5, word 1 (ADDR = 0x29).
    } B;
} hw_ocotp_hw_ocotp_sw_gp1_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_SW_GP1 register
 */
#define HW_OCOTP_HW_OCOTP_SW_GP1_ADDR      (REGS_OCOTP_BASE + 0x690)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_SW_GP1           (*(volatile hw_ocotp_hw_ocotp_sw_gp1_t *) HW_OCOTP_HW_OCOTP_SW_GP1_ADDR)
#define HW_OCOTP_HW_OCOTP_SW_GP1_RD()      (HW_OCOTP_HW_OCOTP_SW_GP1.U)
#define HW_OCOTP_HW_OCOTP_SW_GP1_WR(v)     (HW_OCOTP_HW_OCOTP_SW_GP1.U = (v))
#define HW_OCOTP_HW_OCOTP_SW_GP1_SET(v)    (HW_OCOTP_HW_OCOTP_SW_GP1_WR(HW_OCOTP_HW_OCOTP_SW_GP1_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_SW_GP1_CLR(v)    (HW_OCOTP_HW_OCOTP_SW_GP1_WR(HW_OCOTP_HW_OCOTP_SW_GP1_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_SW_GP1_TOG(v)    (HW_OCOTP_HW_OCOTP_SW_GP1_WR(HW_OCOTP_HW_OCOTP_SW_GP1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_SW_GP1 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_SW_GP1, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 5, word 1 (ADDR = 0x29).
 */

#define BP_OCOTP_HW_OCOTP_SW_GP1_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_SW_GP1_BITS.
#define BM_OCOTP_HW_OCOTP_SW_GP1_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_SW_GP1_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_SW_GP1_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_SW_GP1_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_SW_GP1_BITS) >> BP_OCOTP_HW_OCOTP_SW_GP1_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_GP1_BITS.
#define BF_OCOTP_HW_OCOTP_SW_GP1_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SW_GP1_BITS) & BM_OCOTP_HW_OCOTP_SW_GP1_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_GP1_BITS.
#define BF_OCOTP_HW_OCOTP_SW_GP1_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_SW_GP1_BITS) & BM_OCOTP_HW_OCOTP_SW_GP1_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_SW_GP1_BITS(v)   (HW_OCOTP_HW_OCOTP_SW_GP1_WR((HW_OCOTP_HW_OCOTP_SW_GP1_RD() & ~BM_OCOTP_HW_OCOTP_SW_GP1_BITS) | BF_OCOTP_HW_OCOTP_SW_GP1_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_SW_GP2 - Value of OTP Bank5 Word2 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 5, word 2 (ADDR = 0x2a).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_sw_gp2
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_sw_gp2_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 5, word 2 (ADDR = 0x2a).
    } B;
} hw_ocotp_hw_ocotp_sw_gp2_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_SW_GP2 register
 */
#define HW_OCOTP_HW_OCOTP_SW_GP2_ADDR      (REGS_OCOTP_BASE + 0x6a0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_SW_GP2           (*(volatile hw_ocotp_hw_ocotp_sw_gp2_t *) HW_OCOTP_HW_OCOTP_SW_GP2_ADDR)
#define HW_OCOTP_HW_OCOTP_SW_GP2_RD()      (HW_OCOTP_HW_OCOTP_SW_GP2.U)
#define HW_OCOTP_HW_OCOTP_SW_GP2_WR(v)     (HW_OCOTP_HW_OCOTP_SW_GP2.U = (v))
#define HW_OCOTP_HW_OCOTP_SW_GP2_SET(v)    (HW_OCOTP_HW_OCOTP_SW_GP2_WR(HW_OCOTP_HW_OCOTP_SW_GP2_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_SW_GP2_CLR(v)    (HW_OCOTP_HW_OCOTP_SW_GP2_WR(HW_OCOTP_HW_OCOTP_SW_GP2_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_SW_GP2_TOG(v)    (HW_OCOTP_HW_OCOTP_SW_GP2_WR(HW_OCOTP_HW_OCOTP_SW_GP2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_SW_GP2 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_SW_GP2, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 5, word 2 (ADDR = 0x2a).
 */

#define BP_OCOTP_HW_OCOTP_SW_GP2_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_SW_GP2_BITS.
#define BM_OCOTP_HW_OCOTP_SW_GP2_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_SW_GP2_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_SW_GP2_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_SW_GP2_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_SW_GP2_BITS) >> BP_OCOTP_HW_OCOTP_SW_GP2_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_GP2_BITS.
#define BF_OCOTP_HW_OCOTP_SW_GP2_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SW_GP2_BITS) & BM_OCOTP_HW_OCOTP_SW_GP2_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_GP2_BITS.
#define BF_OCOTP_HW_OCOTP_SW_GP2_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_SW_GP2_BITS) & BM_OCOTP_HW_OCOTP_SW_GP2_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_SW_GP2_BITS(v)   (HW_OCOTP_HW_OCOTP_SW_GP2_WR((HW_OCOTP_HW_OCOTP_SW_GP2_RD() & ~BM_OCOTP_HW_OCOTP_SW_GP2_BITS) | BF_OCOTP_HW_OCOTP_SW_GP2_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_SW_GP3 - Value of OTP Bank5 Word3 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 5, word 3 (ADDR = 0x2b).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_sw_gp3
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_sw_gp3_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 5, word 3 (ADDR = 0x2b).
    } B;
} hw_ocotp_hw_ocotp_sw_gp3_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_SW_GP3 register
 */
#define HW_OCOTP_HW_OCOTP_SW_GP3_ADDR      (REGS_OCOTP_BASE + 0x6b0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_SW_GP3           (*(volatile hw_ocotp_hw_ocotp_sw_gp3_t *) HW_OCOTP_HW_OCOTP_SW_GP3_ADDR)
#define HW_OCOTP_HW_OCOTP_SW_GP3_RD()      (HW_OCOTP_HW_OCOTP_SW_GP3.U)
#define HW_OCOTP_HW_OCOTP_SW_GP3_WR(v)     (HW_OCOTP_HW_OCOTP_SW_GP3.U = (v))
#define HW_OCOTP_HW_OCOTP_SW_GP3_SET(v)    (HW_OCOTP_HW_OCOTP_SW_GP3_WR(HW_OCOTP_HW_OCOTP_SW_GP3_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_SW_GP3_CLR(v)    (HW_OCOTP_HW_OCOTP_SW_GP3_WR(HW_OCOTP_HW_OCOTP_SW_GP3_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_SW_GP3_TOG(v)    (HW_OCOTP_HW_OCOTP_SW_GP3_WR(HW_OCOTP_HW_OCOTP_SW_GP3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_SW_GP3 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_SW_GP3, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 5, word 3 (ADDR = 0x2b).
 */

#define BP_OCOTP_HW_OCOTP_SW_GP3_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_SW_GP3_BITS.
#define BM_OCOTP_HW_OCOTP_SW_GP3_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_SW_GP3_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_SW_GP3_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_SW_GP3_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_SW_GP3_BITS) >> BP_OCOTP_HW_OCOTP_SW_GP3_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_GP3_BITS.
#define BF_OCOTP_HW_OCOTP_SW_GP3_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SW_GP3_BITS) & BM_OCOTP_HW_OCOTP_SW_GP3_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_GP3_BITS.
#define BF_OCOTP_HW_OCOTP_SW_GP3_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_SW_GP3_BITS) & BM_OCOTP_HW_OCOTP_SW_GP3_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_SW_GP3_BITS(v)   (HW_OCOTP_HW_OCOTP_SW_GP3_WR((HW_OCOTP_HW_OCOTP_SW_GP3_RD() & ~BM_OCOTP_HW_OCOTP_SW_GP3_BITS) | BF_OCOTP_HW_OCOTP_SW_GP3_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_SW_GP4 - Value of OTP Bank5 Word4 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 5, word 4 (ADDR = 0x2c).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_sw_gp4
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_sw_gp4_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 5, word 4 (ADDR = 0x2c).
    } B;
} hw_ocotp_hw_ocotp_sw_gp4_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_SW_GP4 register
 */
#define HW_OCOTP_HW_OCOTP_SW_GP4_ADDR      (REGS_OCOTP_BASE + 0x6c0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_SW_GP4           (*(volatile hw_ocotp_hw_ocotp_sw_gp4_t *) HW_OCOTP_HW_OCOTP_SW_GP4_ADDR)
#define HW_OCOTP_HW_OCOTP_SW_GP4_RD()      (HW_OCOTP_HW_OCOTP_SW_GP4.U)
#define HW_OCOTP_HW_OCOTP_SW_GP4_WR(v)     (HW_OCOTP_HW_OCOTP_SW_GP4.U = (v))
#define HW_OCOTP_HW_OCOTP_SW_GP4_SET(v)    (HW_OCOTP_HW_OCOTP_SW_GP4_WR(HW_OCOTP_HW_OCOTP_SW_GP4_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_SW_GP4_CLR(v)    (HW_OCOTP_HW_OCOTP_SW_GP4_WR(HW_OCOTP_HW_OCOTP_SW_GP4_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_SW_GP4_TOG(v)    (HW_OCOTP_HW_OCOTP_SW_GP4_WR(HW_OCOTP_HW_OCOTP_SW_GP4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_SW_GP4 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_SW_GP4, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 5, word 4 (ADDR = 0x2c).
 */

#define BP_OCOTP_HW_OCOTP_SW_GP4_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_SW_GP4_BITS.
#define BM_OCOTP_HW_OCOTP_SW_GP4_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_SW_GP4_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_SW_GP4_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_SW_GP4_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_SW_GP4_BITS) >> BP_OCOTP_HW_OCOTP_SW_GP4_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_GP4_BITS.
#define BF_OCOTP_HW_OCOTP_SW_GP4_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SW_GP4_BITS) & BM_OCOTP_HW_OCOTP_SW_GP4_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SW_GP4_BITS.
#define BF_OCOTP_HW_OCOTP_SW_GP4_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_SW_GP4_BITS) & BM_OCOTP_HW_OCOTP_SW_GP4_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_SW_GP4_BITS(v)   (HW_OCOTP_HW_OCOTP_SW_GP4_WR((HW_OCOTP_HW_OCOTP_SW_GP4_RD() & ~BM_OCOTP_HW_OCOTP_SW_GP4_BITS) | BF_OCOTP_HW_OCOTP_SW_GP4_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_MISC_CONF - Value of OTP Bank5 Word5 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 5, word 5 (ADDR = 0x2d).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_misc_conf
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_misc_conf_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 5, word 5 (ADDR = 0x2d).
    } B;
} hw_ocotp_hw_ocotp_misc_conf_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_MISC_CONF register
 */
#define HW_OCOTP_HW_OCOTP_MISC_CONF_ADDR      (REGS_OCOTP_BASE + 0x6d0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_MISC_CONF           (*(volatile hw_ocotp_hw_ocotp_misc_conf_t *) HW_OCOTP_HW_OCOTP_MISC_CONF_ADDR)
#define HW_OCOTP_HW_OCOTP_MISC_CONF_RD()      (HW_OCOTP_HW_OCOTP_MISC_CONF.U)
#define HW_OCOTP_HW_OCOTP_MISC_CONF_WR(v)     (HW_OCOTP_HW_OCOTP_MISC_CONF.U = (v))
#define HW_OCOTP_HW_OCOTP_MISC_CONF_SET(v)    (HW_OCOTP_HW_OCOTP_MISC_CONF_WR(HW_OCOTP_HW_OCOTP_MISC_CONF_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_MISC_CONF_CLR(v)    (HW_OCOTP_HW_OCOTP_MISC_CONF_WR(HW_OCOTP_HW_OCOTP_MISC_CONF_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_MISC_CONF_TOG(v)    (HW_OCOTP_HW_OCOTP_MISC_CONF_WR(HW_OCOTP_HW_OCOTP_MISC_CONF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_MISC_CONF bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_MISC_CONF, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 5, word 5 (ADDR = 0x2d).
 */

#define BP_OCOTP_HW_OCOTP_MISC_CONF_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_MISC_CONF_BITS.
#define BM_OCOTP_HW_OCOTP_MISC_CONF_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_MISC_CONF_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_MISC_CONF_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_MISC_CONF_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_MISC_CONF_BITS) >> BP_OCOTP_HW_OCOTP_MISC_CONF_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_MISC_CONF_BITS.
#define BF_OCOTP_HW_OCOTP_MISC_CONF_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_MISC_CONF_BITS) & BM_OCOTP_HW_OCOTP_MISC_CONF_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_MISC_CONF_BITS.
#define BF_OCOTP_HW_OCOTP_MISC_CONF_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_MISC_CONF_BITS) & BM_OCOTP_HW_OCOTP_MISC_CONF_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_MISC_CONF_BITS(v)   (HW_OCOTP_HW_OCOTP_MISC_CONF_WR((HW_OCOTP_HW_OCOTP_MISC_CONF_RD() & ~BM_OCOTP_HW_OCOTP_MISC_CONF_BITS) | BF_OCOTP_HW_OCOTP_MISC_CONF_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_FIELD_RETURN - Value of OTP Bank5 Word6 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 5, word 6 (ADDR = 0x2e).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_field_return
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_field_return_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 5, word 6 (ADDR = 0x2e).
    } B;
} hw_ocotp_hw_ocotp_field_return_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_FIELD_RETURN register
 */
#define HW_OCOTP_HW_OCOTP_FIELD_RETURN_ADDR      (REGS_OCOTP_BASE + 0x6e0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_FIELD_RETURN           (*(volatile hw_ocotp_hw_ocotp_field_return_t *) HW_OCOTP_HW_OCOTP_FIELD_RETURN_ADDR)
#define HW_OCOTP_HW_OCOTP_FIELD_RETURN_RD()      (HW_OCOTP_HW_OCOTP_FIELD_RETURN.U)
#define HW_OCOTP_HW_OCOTP_FIELD_RETURN_WR(v)     (HW_OCOTP_HW_OCOTP_FIELD_RETURN.U = (v))
#define HW_OCOTP_HW_OCOTP_FIELD_RETURN_SET(v)    (HW_OCOTP_HW_OCOTP_FIELD_RETURN_WR(HW_OCOTP_HW_OCOTP_FIELD_RETURN_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_FIELD_RETURN_CLR(v)    (HW_OCOTP_HW_OCOTP_FIELD_RETURN_WR(HW_OCOTP_HW_OCOTP_FIELD_RETURN_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_FIELD_RETURN_TOG(v)    (HW_OCOTP_HW_OCOTP_FIELD_RETURN_WR(HW_OCOTP_HW_OCOTP_FIELD_RETURN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_FIELD_RETURN bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_FIELD_RETURN, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 5, word 6 (ADDR = 0x2e).
 */

#define BP_OCOTP_HW_OCOTP_FIELD_RETURN_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_FIELD_RETURN_BITS.
#define BM_OCOTP_HW_OCOTP_FIELD_RETURN_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_FIELD_RETURN_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_FIELD_RETURN_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_FIELD_RETURN_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_FIELD_RETURN_BITS) >> BP_OCOTP_HW_OCOTP_FIELD_RETURN_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_FIELD_RETURN_BITS.
#define BF_OCOTP_HW_OCOTP_FIELD_RETURN_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_FIELD_RETURN_BITS) & BM_OCOTP_HW_OCOTP_FIELD_RETURN_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_FIELD_RETURN_BITS.
#define BF_OCOTP_HW_OCOTP_FIELD_RETURN_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_FIELD_RETURN_BITS) & BM_OCOTP_HW_OCOTP_FIELD_RETURN_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_FIELD_RETURN_BITS(v)   (HW_OCOTP_HW_OCOTP_FIELD_RETURN_WR((HW_OCOTP_HW_OCOTP_FIELD_RETURN_RD() & ~BM_OCOTP_HW_OCOTP_FIELD_RETURN_BITS) | BF_OCOTP_HW_OCOTP_FIELD_RETURN_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_SRK_REVOKE - Value of OTP Bank5 Word7 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 5, word 7 (ADDR = 0x2f).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_srk_revoke
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_srk_revoke_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 5, word 7 (ADDR = 0x2f).
    } B;
} hw_ocotp_hw_ocotp_srk_revoke_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_SRK_REVOKE register
 */
#define HW_OCOTP_HW_OCOTP_SRK_REVOKE_ADDR      (REGS_OCOTP_BASE + 0x6f0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_SRK_REVOKE           (*(volatile hw_ocotp_hw_ocotp_srk_revoke_t *) HW_OCOTP_HW_OCOTP_SRK_REVOKE_ADDR)
#define HW_OCOTP_HW_OCOTP_SRK_REVOKE_RD()      (HW_OCOTP_HW_OCOTP_SRK_REVOKE.U)
#define HW_OCOTP_HW_OCOTP_SRK_REVOKE_WR(v)     (HW_OCOTP_HW_OCOTP_SRK_REVOKE.U = (v))
#define HW_OCOTP_HW_OCOTP_SRK_REVOKE_SET(v)    (HW_OCOTP_HW_OCOTP_SRK_REVOKE_WR(HW_OCOTP_HW_OCOTP_SRK_REVOKE_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_SRK_REVOKE_CLR(v)    (HW_OCOTP_HW_OCOTP_SRK_REVOKE_WR(HW_OCOTP_HW_OCOTP_SRK_REVOKE_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_SRK_REVOKE_TOG(v)    (HW_OCOTP_HW_OCOTP_SRK_REVOKE_WR(HW_OCOTP_HW_OCOTP_SRK_REVOKE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_SRK_REVOKE bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_SRK_REVOKE, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 5, word 7 (ADDR = 0x2f).
 */

#define BP_OCOTP_HW_OCOTP_SRK_REVOKE_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_SRK_REVOKE_BITS.
#define BM_OCOTP_HW_OCOTP_SRK_REVOKE_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_SRK_REVOKE_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_SRK_REVOKE_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_SRK_REVOKE_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_SRK_REVOKE_BITS) >> BP_OCOTP_HW_OCOTP_SRK_REVOKE_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SRK_REVOKE_BITS.
#define BF_OCOTP_HW_OCOTP_SRK_REVOKE_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_SRK_REVOKE_BITS) & BM_OCOTP_HW_OCOTP_SRK_REVOKE_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_SRK_REVOKE_BITS.
#define BF_OCOTP_HW_OCOTP_SRK_REVOKE_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_SRK_REVOKE_BITS) & BM_OCOTP_HW_OCOTP_SRK_REVOKE_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_SRK_REVOKE_BITS(v)   (HW_OCOTP_HW_OCOTP_SRK_REVOKE_WR((HW_OCOTP_HW_OCOTP_SRK_REVOKE_RD() & ~BM_OCOTP_HW_OCOTP_SRK_REVOKE_BITS) | BF_OCOTP_HW_OCOTP_SRK_REVOKE_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_GP_LO0 - Value of OTP Bank6 Word0 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 6, word 0 (ADDR = 0x30).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_gp_lo0
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_gp_lo0_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 6, word 0 (ADDR = 0x30).
    } B;
} hw_ocotp_hw_ocotp_gp_lo0_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_GP_LO0 register
 */
#define HW_OCOTP_HW_OCOTP_GP_LO0_ADDR      (REGS_OCOTP_BASE + 0x700)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_GP_LO0           (*(volatile hw_ocotp_hw_ocotp_gp_lo0_t *) HW_OCOTP_HW_OCOTP_GP_LO0_ADDR)
#define HW_OCOTP_HW_OCOTP_GP_LO0_RD()      (HW_OCOTP_HW_OCOTP_GP_LO0.U)
#define HW_OCOTP_HW_OCOTP_GP_LO0_WR(v)     (HW_OCOTP_HW_OCOTP_GP_LO0.U = (v))
#define HW_OCOTP_HW_OCOTP_GP_LO0_SET(v)    (HW_OCOTP_HW_OCOTP_GP_LO0_WR(HW_OCOTP_HW_OCOTP_GP_LO0_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_GP_LO0_CLR(v)    (HW_OCOTP_HW_OCOTP_GP_LO0_WR(HW_OCOTP_HW_OCOTP_GP_LO0_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_GP_LO0_TOG(v)    (HW_OCOTP_HW_OCOTP_GP_LO0_WR(HW_OCOTP_HW_OCOTP_GP_LO0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_GP_LO0 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_GP_LO0, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 6, word 0 (ADDR = 0x30).
 */

#define BP_OCOTP_HW_OCOTP_GP_LO0_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_GP_LO0_BITS.
#define BM_OCOTP_HW_OCOTP_GP_LO0_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_GP_LO0_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_GP_LO0_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_GP_LO0_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_GP_LO0_BITS) >> BP_OCOTP_HW_OCOTP_GP_LO0_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_LO0_BITS.
#define BF_OCOTP_HW_OCOTP_GP_LO0_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_GP_LO0_BITS) & BM_OCOTP_HW_OCOTP_GP_LO0_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_LO0_BITS.
#define BF_OCOTP_HW_OCOTP_GP_LO0_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_GP_LO0_BITS) & BM_OCOTP_HW_OCOTP_GP_LO0_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_GP_LO0_BITS(v)   (HW_OCOTP_HW_OCOTP_GP_LO0_WR((HW_OCOTP_HW_OCOTP_GP_LO0_RD() & ~BM_OCOTP_HW_OCOTP_GP_LO0_BITS) | BF_OCOTP_HW_OCOTP_GP_LO0_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_GP_LO1 - Value of OTP Bank6 Word1 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 6, word 1 (ADDR = 0x31).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_gp_lo1
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_gp_lo1_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 6, word 1 (ADDR = 0x31).
    } B;
} hw_ocotp_hw_ocotp_gp_lo1_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_GP_LO1 register
 */
#define HW_OCOTP_HW_OCOTP_GP_LO1_ADDR      (REGS_OCOTP_BASE + 0x710)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_GP_LO1           (*(volatile hw_ocotp_hw_ocotp_gp_lo1_t *) HW_OCOTP_HW_OCOTP_GP_LO1_ADDR)
#define HW_OCOTP_HW_OCOTP_GP_LO1_RD()      (HW_OCOTP_HW_OCOTP_GP_LO1.U)
#define HW_OCOTP_HW_OCOTP_GP_LO1_WR(v)     (HW_OCOTP_HW_OCOTP_GP_LO1.U = (v))
#define HW_OCOTP_HW_OCOTP_GP_LO1_SET(v)    (HW_OCOTP_HW_OCOTP_GP_LO1_WR(HW_OCOTP_HW_OCOTP_GP_LO1_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_GP_LO1_CLR(v)    (HW_OCOTP_HW_OCOTP_GP_LO1_WR(HW_OCOTP_HW_OCOTP_GP_LO1_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_GP_LO1_TOG(v)    (HW_OCOTP_HW_OCOTP_GP_LO1_WR(HW_OCOTP_HW_OCOTP_GP_LO1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_GP_LO1 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_GP_LO1, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 6, word 1 (ADDR = 0x31).
 */

#define BP_OCOTP_HW_OCOTP_GP_LO1_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_GP_LO1_BITS.
#define BM_OCOTP_HW_OCOTP_GP_LO1_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_GP_LO1_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_GP_LO1_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_GP_LO1_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_GP_LO1_BITS) >> BP_OCOTP_HW_OCOTP_GP_LO1_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_LO1_BITS.
#define BF_OCOTP_HW_OCOTP_GP_LO1_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_GP_LO1_BITS) & BM_OCOTP_HW_OCOTP_GP_LO1_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_LO1_BITS.
#define BF_OCOTP_HW_OCOTP_GP_LO1_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_GP_LO1_BITS) & BM_OCOTP_HW_OCOTP_GP_LO1_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_GP_LO1_BITS(v)   (HW_OCOTP_HW_OCOTP_GP_LO1_WR((HW_OCOTP_HW_OCOTP_GP_LO1_RD() & ~BM_OCOTP_HW_OCOTP_GP_LO1_BITS) | BF_OCOTP_HW_OCOTP_GP_LO1_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_GP_LO2 - Value of OTP Bank6 Word2 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 6, word 2 (ADDR = 0x32).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_gp_lo2
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_gp_lo2_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 6, word 2 (ADDR = 0x32).
    } B;
} hw_ocotp_hw_ocotp_gp_lo2_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_GP_LO2 register
 */
#define HW_OCOTP_HW_OCOTP_GP_LO2_ADDR      (REGS_OCOTP_BASE + 0x720)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_GP_LO2           (*(volatile hw_ocotp_hw_ocotp_gp_lo2_t *) HW_OCOTP_HW_OCOTP_GP_LO2_ADDR)
#define HW_OCOTP_HW_OCOTP_GP_LO2_RD()      (HW_OCOTP_HW_OCOTP_GP_LO2.U)
#define HW_OCOTP_HW_OCOTP_GP_LO2_WR(v)     (HW_OCOTP_HW_OCOTP_GP_LO2.U = (v))
#define HW_OCOTP_HW_OCOTP_GP_LO2_SET(v)    (HW_OCOTP_HW_OCOTP_GP_LO2_WR(HW_OCOTP_HW_OCOTP_GP_LO2_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_GP_LO2_CLR(v)    (HW_OCOTP_HW_OCOTP_GP_LO2_WR(HW_OCOTP_HW_OCOTP_GP_LO2_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_GP_LO2_TOG(v)    (HW_OCOTP_HW_OCOTP_GP_LO2_WR(HW_OCOTP_HW_OCOTP_GP_LO2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_GP_LO2 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_GP_LO2, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 6, word 2 (ADDR = 0x32).
 */

#define BP_OCOTP_HW_OCOTP_GP_LO2_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_GP_LO2_BITS.
#define BM_OCOTP_HW_OCOTP_GP_LO2_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_GP_LO2_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_GP_LO2_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_GP_LO2_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_GP_LO2_BITS) >> BP_OCOTP_HW_OCOTP_GP_LO2_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_LO2_BITS.
#define BF_OCOTP_HW_OCOTP_GP_LO2_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_GP_LO2_BITS) & BM_OCOTP_HW_OCOTP_GP_LO2_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_LO2_BITS.
#define BF_OCOTP_HW_OCOTP_GP_LO2_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_GP_LO2_BITS) & BM_OCOTP_HW_OCOTP_GP_LO2_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_GP_LO2_BITS(v)   (HW_OCOTP_HW_OCOTP_GP_LO2_WR((HW_OCOTP_HW_OCOTP_GP_LO2_RD() & ~BM_OCOTP_HW_OCOTP_GP_LO2_BITS) | BF_OCOTP_HW_OCOTP_GP_LO2_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_GP_LO3 - Value of OTP Bank6 Word3 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 6, word 3 (ADDR = 0x33).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_gp_lo3
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_gp_lo3_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 6, word 3 (ADDR = 0x33).
    } B;
} hw_ocotp_hw_ocotp_gp_lo3_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_GP_LO3 register
 */
#define HW_OCOTP_HW_OCOTP_GP_LO3_ADDR      (REGS_OCOTP_BASE + 0x730)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_GP_LO3           (*(volatile hw_ocotp_hw_ocotp_gp_lo3_t *) HW_OCOTP_HW_OCOTP_GP_LO3_ADDR)
#define HW_OCOTP_HW_OCOTP_GP_LO3_RD()      (HW_OCOTP_HW_OCOTP_GP_LO3.U)
#define HW_OCOTP_HW_OCOTP_GP_LO3_WR(v)     (HW_OCOTP_HW_OCOTP_GP_LO3.U = (v))
#define HW_OCOTP_HW_OCOTP_GP_LO3_SET(v)    (HW_OCOTP_HW_OCOTP_GP_LO3_WR(HW_OCOTP_HW_OCOTP_GP_LO3_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_GP_LO3_CLR(v)    (HW_OCOTP_HW_OCOTP_GP_LO3_WR(HW_OCOTP_HW_OCOTP_GP_LO3_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_GP_LO3_TOG(v)    (HW_OCOTP_HW_OCOTP_GP_LO3_WR(HW_OCOTP_HW_OCOTP_GP_LO3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_GP_LO3 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_GP_LO3, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 6, word 3 (ADDR = 0x33).
 */

#define BP_OCOTP_HW_OCOTP_GP_LO3_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_GP_LO3_BITS.
#define BM_OCOTP_HW_OCOTP_GP_LO3_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_GP_LO3_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_GP_LO3_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_GP_LO3_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_GP_LO3_BITS) >> BP_OCOTP_HW_OCOTP_GP_LO3_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_LO3_BITS.
#define BF_OCOTP_HW_OCOTP_GP_LO3_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_GP_LO3_BITS) & BM_OCOTP_HW_OCOTP_GP_LO3_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_LO3_BITS.
#define BF_OCOTP_HW_OCOTP_GP_LO3_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_GP_LO3_BITS) & BM_OCOTP_HW_OCOTP_GP_LO3_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_GP_LO3_BITS(v)   (HW_OCOTP_HW_OCOTP_GP_LO3_WR((HW_OCOTP_HW_OCOTP_GP_LO3_RD() & ~BM_OCOTP_HW_OCOTP_GP_LO3_BITS) | BF_OCOTP_HW_OCOTP_GP_LO3_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_GP_LO4 - Value of OTP Bank6 Word4 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 6, word 4 (ADDR = 0x34).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_gp_lo4
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_gp_lo4_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 6, word 4 (ADDR = 0x34).
    } B;
} hw_ocotp_hw_ocotp_gp_lo4_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_GP_LO4 register
 */
#define HW_OCOTP_HW_OCOTP_GP_LO4_ADDR      (REGS_OCOTP_BASE + 0x740)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_GP_LO4           (*(volatile hw_ocotp_hw_ocotp_gp_lo4_t *) HW_OCOTP_HW_OCOTP_GP_LO4_ADDR)
#define HW_OCOTP_HW_OCOTP_GP_LO4_RD()      (HW_OCOTP_HW_OCOTP_GP_LO4.U)
#define HW_OCOTP_HW_OCOTP_GP_LO4_WR(v)     (HW_OCOTP_HW_OCOTP_GP_LO4.U = (v))
#define HW_OCOTP_HW_OCOTP_GP_LO4_SET(v)    (HW_OCOTP_HW_OCOTP_GP_LO4_WR(HW_OCOTP_HW_OCOTP_GP_LO4_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_GP_LO4_CLR(v)    (HW_OCOTP_HW_OCOTP_GP_LO4_WR(HW_OCOTP_HW_OCOTP_GP_LO4_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_GP_LO4_TOG(v)    (HW_OCOTP_HW_OCOTP_GP_LO4_WR(HW_OCOTP_HW_OCOTP_GP_LO4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_GP_LO4 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_GP_LO4, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 6, word 4 (ADDR = 0x34).
 */

#define BP_OCOTP_HW_OCOTP_GP_LO4_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_GP_LO4_BITS.
#define BM_OCOTP_HW_OCOTP_GP_LO4_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_GP_LO4_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_GP_LO4_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_GP_LO4_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_GP_LO4_BITS) >> BP_OCOTP_HW_OCOTP_GP_LO4_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_LO4_BITS.
#define BF_OCOTP_HW_OCOTP_GP_LO4_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_GP_LO4_BITS) & BM_OCOTP_HW_OCOTP_GP_LO4_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_LO4_BITS.
#define BF_OCOTP_HW_OCOTP_GP_LO4_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_GP_LO4_BITS) & BM_OCOTP_HW_OCOTP_GP_LO4_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_GP_LO4_BITS(v)   (HW_OCOTP_HW_OCOTP_GP_LO4_WR((HW_OCOTP_HW_OCOTP_GP_LO4_RD() & ~BM_OCOTP_HW_OCOTP_GP_LO4_BITS) | BF_OCOTP_HW_OCOTP_GP_LO4_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_GP_LO5 - Value of OTP Bank6 Word5 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 6, word 5 (ADDR = 0x35).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_gp_lo5
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_gp_lo5_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 6, word 5 (ADDR = 0x35).
    } B;
} hw_ocotp_hw_ocotp_gp_lo5_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_GP_LO5 register
 */
#define HW_OCOTP_HW_OCOTP_GP_LO5_ADDR      (REGS_OCOTP_BASE + 0x750)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_GP_LO5           (*(volatile hw_ocotp_hw_ocotp_gp_lo5_t *) HW_OCOTP_HW_OCOTP_GP_LO5_ADDR)
#define HW_OCOTP_HW_OCOTP_GP_LO5_RD()      (HW_OCOTP_HW_OCOTP_GP_LO5.U)
#define HW_OCOTP_HW_OCOTP_GP_LO5_WR(v)     (HW_OCOTP_HW_OCOTP_GP_LO5.U = (v))
#define HW_OCOTP_HW_OCOTP_GP_LO5_SET(v)    (HW_OCOTP_HW_OCOTP_GP_LO5_WR(HW_OCOTP_HW_OCOTP_GP_LO5_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_GP_LO5_CLR(v)    (HW_OCOTP_HW_OCOTP_GP_LO5_WR(HW_OCOTP_HW_OCOTP_GP_LO5_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_GP_LO5_TOG(v)    (HW_OCOTP_HW_OCOTP_GP_LO5_WR(HW_OCOTP_HW_OCOTP_GP_LO5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_GP_LO5 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_GP_LO5, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 6, word 5 (ADDR = 0x35).
 */

#define BP_OCOTP_HW_OCOTP_GP_LO5_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_GP_LO5_BITS.
#define BM_OCOTP_HW_OCOTP_GP_LO5_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_GP_LO5_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_GP_LO5_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_GP_LO5_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_GP_LO5_BITS) >> BP_OCOTP_HW_OCOTP_GP_LO5_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_LO5_BITS.
#define BF_OCOTP_HW_OCOTP_GP_LO5_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_GP_LO5_BITS) & BM_OCOTP_HW_OCOTP_GP_LO5_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_LO5_BITS.
#define BF_OCOTP_HW_OCOTP_GP_LO5_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_GP_LO5_BITS) & BM_OCOTP_HW_OCOTP_GP_LO5_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_GP_LO5_BITS(v)   (HW_OCOTP_HW_OCOTP_GP_LO5_WR((HW_OCOTP_HW_OCOTP_GP_LO5_RD() & ~BM_OCOTP_HW_OCOTP_GP_LO5_BITS) | BF_OCOTP_HW_OCOTP_GP_LO5_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_GP_LO6 - Value of OTP Bank6 Word6 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 6, word 6 (ADDR = 0x36).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_gp_lo6
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_gp_lo6_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 6, word 6 (ADDR = 0x36).
    } B;
} hw_ocotp_hw_ocotp_gp_lo6_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_GP_LO6 register
 */
#define HW_OCOTP_HW_OCOTP_GP_LO6_ADDR      (REGS_OCOTP_BASE + 0x760)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_GP_LO6           (*(volatile hw_ocotp_hw_ocotp_gp_lo6_t *) HW_OCOTP_HW_OCOTP_GP_LO6_ADDR)
#define HW_OCOTP_HW_OCOTP_GP_LO6_RD()      (HW_OCOTP_HW_OCOTP_GP_LO6.U)
#define HW_OCOTP_HW_OCOTP_GP_LO6_WR(v)     (HW_OCOTP_HW_OCOTP_GP_LO6.U = (v))
#define HW_OCOTP_HW_OCOTP_GP_LO6_SET(v)    (HW_OCOTP_HW_OCOTP_GP_LO6_WR(HW_OCOTP_HW_OCOTP_GP_LO6_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_GP_LO6_CLR(v)    (HW_OCOTP_HW_OCOTP_GP_LO6_WR(HW_OCOTP_HW_OCOTP_GP_LO6_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_GP_LO6_TOG(v)    (HW_OCOTP_HW_OCOTP_GP_LO6_WR(HW_OCOTP_HW_OCOTP_GP_LO6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_GP_LO6 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_GP_LO6, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 6, word 6 (ADDR = 0x36).
 */

#define BP_OCOTP_HW_OCOTP_GP_LO6_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_GP_LO6_BITS.
#define BM_OCOTP_HW_OCOTP_GP_LO6_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_GP_LO6_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_GP_LO6_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_GP_LO6_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_GP_LO6_BITS) >> BP_OCOTP_HW_OCOTP_GP_LO6_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_LO6_BITS.
#define BF_OCOTP_HW_OCOTP_GP_LO6_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_GP_LO6_BITS) & BM_OCOTP_HW_OCOTP_GP_LO6_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_LO6_BITS.
#define BF_OCOTP_HW_OCOTP_GP_LO6_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_GP_LO6_BITS) & BM_OCOTP_HW_OCOTP_GP_LO6_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_GP_LO6_BITS(v)   (HW_OCOTP_HW_OCOTP_GP_LO6_WR((HW_OCOTP_HW_OCOTP_GP_LO6_RD() & ~BM_OCOTP_HW_OCOTP_GP_LO6_BITS) | BF_OCOTP_HW_OCOTP_GP_LO6_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_GP_LO7 - Value of OTP Bank6 Word7 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 6, word 7 (ADDR = 0x37).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_gp_lo7
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_gp_lo7_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 6, word 7 (ADDR = 0x37).
    } B;
} hw_ocotp_hw_ocotp_gp_lo7_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_GP_LO7 register
 */
#define HW_OCOTP_HW_OCOTP_GP_LO7_ADDR      (REGS_OCOTP_BASE + 0x770)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_GP_LO7           (*(volatile hw_ocotp_hw_ocotp_gp_lo7_t *) HW_OCOTP_HW_OCOTP_GP_LO7_ADDR)
#define HW_OCOTP_HW_OCOTP_GP_LO7_RD()      (HW_OCOTP_HW_OCOTP_GP_LO7.U)
#define HW_OCOTP_HW_OCOTP_GP_LO7_WR(v)     (HW_OCOTP_HW_OCOTP_GP_LO7.U = (v))
#define HW_OCOTP_HW_OCOTP_GP_LO7_SET(v)    (HW_OCOTP_HW_OCOTP_GP_LO7_WR(HW_OCOTP_HW_OCOTP_GP_LO7_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_GP_LO7_CLR(v)    (HW_OCOTP_HW_OCOTP_GP_LO7_WR(HW_OCOTP_HW_OCOTP_GP_LO7_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_GP_LO7_TOG(v)    (HW_OCOTP_HW_OCOTP_GP_LO7_WR(HW_OCOTP_HW_OCOTP_GP_LO7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_GP_LO7 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_GP_LO7, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 6, word 7 (ADDR = 0x37).
 */

#define BP_OCOTP_HW_OCOTP_GP_LO7_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_GP_LO7_BITS.
#define BM_OCOTP_HW_OCOTP_GP_LO7_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_GP_LO7_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_GP_LO7_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_GP_LO7_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_GP_LO7_BITS) >> BP_OCOTP_HW_OCOTP_GP_LO7_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_LO7_BITS.
#define BF_OCOTP_HW_OCOTP_GP_LO7_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_GP_LO7_BITS) & BM_OCOTP_HW_OCOTP_GP_LO7_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_LO7_BITS.
#define BF_OCOTP_HW_OCOTP_GP_LO7_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_GP_LO7_BITS) & BM_OCOTP_HW_OCOTP_GP_LO7_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_GP_LO7_BITS(v)   (HW_OCOTP_HW_OCOTP_GP_LO7_WR((HW_OCOTP_HW_OCOTP_GP_LO7_RD() & ~BM_OCOTP_HW_OCOTP_GP_LO7_BITS) | BF_OCOTP_HW_OCOTP_GP_LO7_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_GP_HI0 - Value of OTP Bank7 Word0 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 7, word 0 (ADDR = 0x38).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_gp_hi0
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_gp_hi0_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 7, word 0 (ADDR = 0x38).
    } B;
} hw_ocotp_hw_ocotp_gp_hi0_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_GP_HI0 register
 */
#define HW_OCOTP_HW_OCOTP_GP_HI0_ADDR      (REGS_OCOTP_BASE + 0x780)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_GP_HI0           (*(volatile hw_ocotp_hw_ocotp_gp_hi0_t *) HW_OCOTP_HW_OCOTP_GP_HI0_ADDR)
#define HW_OCOTP_HW_OCOTP_GP_HI0_RD()      (HW_OCOTP_HW_OCOTP_GP_HI0.U)
#define HW_OCOTP_HW_OCOTP_GP_HI0_WR(v)     (HW_OCOTP_HW_OCOTP_GP_HI0.U = (v))
#define HW_OCOTP_HW_OCOTP_GP_HI0_SET(v)    (HW_OCOTP_HW_OCOTP_GP_HI0_WR(HW_OCOTP_HW_OCOTP_GP_HI0_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_GP_HI0_CLR(v)    (HW_OCOTP_HW_OCOTP_GP_HI0_WR(HW_OCOTP_HW_OCOTP_GP_HI0_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_GP_HI0_TOG(v)    (HW_OCOTP_HW_OCOTP_GP_HI0_WR(HW_OCOTP_HW_OCOTP_GP_HI0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_GP_HI0 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_GP_HI0, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 7, word 0 (ADDR = 0x38).
 */

#define BP_OCOTP_HW_OCOTP_GP_HI0_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_GP_HI0_BITS.
#define BM_OCOTP_HW_OCOTP_GP_HI0_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_GP_HI0_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_GP_HI0_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_GP_HI0_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_GP_HI0_BITS) >> BP_OCOTP_HW_OCOTP_GP_HI0_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_HI0_BITS.
#define BF_OCOTP_HW_OCOTP_GP_HI0_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_GP_HI0_BITS) & BM_OCOTP_HW_OCOTP_GP_HI0_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_HI0_BITS.
#define BF_OCOTP_HW_OCOTP_GP_HI0_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_GP_HI0_BITS) & BM_OCOTP_HW_OCOTP_GP_HI0_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_GP_HI0_BITS(v)   (HW_OCOTP_HW_OCOTP_GP_HI0_WR((HW_OCOTP_HW_OCOTP_GP_HI0_RD() & ~BM_OCOTP_HW_OCOTP_GP_HI0_BITS) | BF_OCOTP_HW_OCOTP_GP_HI0_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_GP_HI1 - Value of OTP Bank7 Word1 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 7, word 1 (ADDR = 0x39).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_gp_hi1
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_gp_hi1_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 7, word 1 (ADDR = 0x39).
    } B;
} hw_ocotp_hw_ocotp_gp_hi1_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_GP_HI1 register
 */
#define HW_OCOTP_HW_OCOTP_GP_HI1_ADDR      (REGS_OCOTP_BASE + 0x790)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_GP_HI1           (*(volatile hw_ocotp_hw_ocotp_gp_hi1_t *) HW_OCOTP_HW_OCOTP_GP_HI1_ADDR)
#define HW_OCOTP_HW_OCOTP_GP_HI1_RD()      (HW_OCOTP_HW_OCOTP_GP_HI1.U)
#define HW_OCOTP_HW_OCOTP_GP_HI1_WR(v)     (HW_OCOTP_HW_OCOTP_GP_HI1.U = (v))
#define HW_OCOTP_HW_OCOTP_GP_HI1_SET(v)    (HW_OCOTP_HW_OCOTP_GP_HI1_WR(HW_OCOTP_HW_OCOTP_GP_HI1_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_GP_HI1_CLR(v)    (HW_OCOTP_HW_OCOTP_GP_HI1_WR(HW_OCOTP_HW_OCOTP_GP_HI1_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_GP_HI1_TOG(v)    (HW_OCOTP_HW_OCOTP_GP_HI1_WR(HW_OCOTP_HW_OCOTP_GP_HI1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_GP_HI1 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_GP_HI1, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 7, word 1 (ADDR = 0x39).
 */

#define BP_OCOTP_HW_OCOTP_GP_HI1_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_GP_HI1_BITS.
#define BM_OCOTP_HW_OCOTP_GP_HI1_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_GP_HI1_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_GP_HI1_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_GP_HI1_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_GP_HI1_BITS) >> BP_OCOTP_HW_OCOTP_GP_HI1_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_HI1_BITS.
#define BF_OCOTP_HW_OCOTP_GP_HI1_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_GP_HI1_BITS) & BM_OCOTP_HW_OCOTP_GP_HI1_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_HI1_BITS.
#define BF_OCOTP_HW_OCOTP_GP_HI1_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_GP_HI1_BITS) & BM_OCOTP_HW_OCOTP_GP_HI1_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_GP_HI1_BITS(v)   (HW_OCOTP_HW_OCOTP_GP_HI1_WR((HW_OCOTP_HW_OCOTP_GP_HI1_RD() & ~BM_OCOTP_HW_OCOTP_GP_HI1_BITS) | BF_OCOTP_HW_OCOTP_GP_HI1_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_GP_HI2 - Value of OTP Bank7 Word2 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 7, word 2 (ADDR = 0x3a).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_gp_hi2
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_gp_hi2_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 7, word 2 (ADDR = 0x3a).
    } B;
} hw_ocotp_hw_ocotp_gp_hi2_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_GP_HI2 register
 */
#define HW_OCOTP_HW_OCOTP_GP_HI2_ADDR      (REGS_OCOTP_BASE + 0x7a0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_GP_HI2           (*(volatile hw_ocotp_hw_ocotp_gp_hi2_t *) HW_OCOTP_HW_OCOTP_GP_HI2_ADDR)
#define HW_OCOTP_HW_OCOTP_GP_HI2_RD()      (HW_OCOTP_HW_OCOTP_GP_HI2.U)
#define HW_OCOTP_HW_OCOTP_GP_HI2_WR(v)     (HW_OCOTP_HW_OCOTP_GP_HI2.U = (v))
#define HW_OCOTP_HW_OCOTP_GP_HI2_SET(v)    (HW_OCOTP_HW_OCOTP_GP_HI2_WR(HW_OCOTP_HW_OCOTP_GP_HI2_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_GP_HI2_CLR(v)    (HW_OCOTP_HW_OCOTP_GP_HI2_WR(HW_OCOTP_HW_OCOTP_GP_HI2_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_GP_HI2_TOG(v)    (HW_OCOTP_HW_OCOTP_GP_HI2_WR(HW_OCOTP_HW_OCOTP_GP_HI2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_GP_HI2 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_GP_HI2, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 7, word 2 (ADDR = 0x3a).
 */

#define BP_OCOTP_HW_OCOTP_GP_HI2_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_GP_HI2_BITS.
#define BM_OCOTP_HW_OCOTP_GP_HI2_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_GP_HI2_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_GP_HI2_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_GP_HI2_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_GP_HI2_BITS) >> BP_OCOTP_HW_OCOTP_GP_HI2_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_HI2_BITS.
#define BF_OCOTP_HW_OCOTP_GP_HI2_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_GP_HI2_BITS) & BM_OCOTP_HW_OCOTP_GP_HI2_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_HI2_BITS.
#define BF_OCOTP_HW_OCOTP_GP_HI2_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_GP_HI2_BITS) & BM_OCOTP_HW_OCOTP_GP_HI2_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_GP_HI2_BITS(v)   (HW_OCOTP_HW_OCOTP_GP_HI2_WR((HW_OCOTP_HW_OCOTP_GP_HI2_RD() & ~BM_OCOTP_HW_OCOTP_GP_HI2_BITS) | BF_OCOTP_HW_OCOTP_GP_HI2_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_GP_HI3 - Value of OTP Bank7 Word3 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 7, word 3 (ADDR = 0x3b).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_gp_hi3
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_gp_hi3_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 7, word 3 (ADDR = 0x3b).
    } B;
} hw_ocotp_hw_ocotp_gp_hi3_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_GP_HI3 register
 */
#define HW_OCOTP_HW_OCOTP_GP_HI3_ADDR      (REGS_OCOTP_BASE + 0x7b0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_GP_HI3           (*(volatile hw_ocotp_hw_ocotp_gp_hi3_t *) HW_OCOTP_HW_OCOTP_GP_HI3_ADDR)
#define HW_OCOTP_HW_OCOTP_GP_HI3_RD()      (HW_OCOTP_HW_OCOTP_GP_HI3.U)
#define HW_OCOTP_HW_OCOTP_GP_HI3_WR(v)     (HW_OCOTP_HW_OCOTP_GP_HI3.U = (v))
#define HW_OCOTP_HW_OCOTP_GP_HI3_SET(v)    (HW_OCOTP_HW_OCOTP_GP_HI3_WR(HW_OCOTP_HW_OCOTP_GP_HI3_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_GP_HI3_CLR(v)    (HW_OCOTP_HW_OCOTP_GP_HI3_WR(HW_OCOTP_HW_OCOTP_GP_HI3_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_GP_HI3_TOG(v)    (HW_OCOTP_HW_OCOTP_GP_HI3_WR(HW_OCOTP_HW_OCOTP_GP_HI3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_GP_HI3 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_GP_HI3, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 7, word 3 (ADDR = 0x3b).
 */

#define BP_OCOTP_HW_OCOTP_GP_HI3_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_GP_HI3_BITS.
#define BM_OCOTP_HW_OCOTP_GP_HI3_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_GP_HI3_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_GP_HI3_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_GP_HI3_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_GP_HI3_BITS) >> BP_OCOTP_HW_OCOTP_GP_HI3_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_HI3_BITS.
#define BF_OCOTP_HW_OCOTP_GP_HI3_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_GP_HI3_BITS) & BM_OCOTP_HW_OCOTP_GP_HI3_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_HI3_BITS.
#define BF_OCOTP_HW_OCOTP_GP_HI3_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_GP_HI3_BITS) & BM_OCOTP_HW_OCOTP_GP_HI3_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_GP_HI3_BITS(v)   (HW_OCOTP_HW_OCOTP_GP_HI3_WR((HW_OCOTP_HW_OCOTP_GP_HI3_RD() & ~BM_OCOTP_HW_OCOTP_GP_HI3_BITS) | BF_OCOTP_HW_OCOTP_GP_HI3_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_GP_HI4 - Value of OTP Bank7 Word4 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 7, word 4 (ADDR = 0x3c).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_gp_hi4
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_gp_hi4_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 7, word 4 (ADDR = 0x3c).
    } B;
} hw_ocotp_hw_ocotp_gp_hi4_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_GP_HI4 register
 */
#define HW_OCOTP_HW_OCOTP_GP_HI4_ADDR      (REGS_OCOTP_BASE + 0x7c0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_GP_HI4           (*(volatile hw_ocotp_hw_ocotp_gp_hi4_t *) HW_OCOTP_HW_OCOTP_GP_HI4_ADDR)
#define HW_OCOTP_HW_OCOTP_GP_HI4_RD()      (HW_OCOTP_HW_OCOTP_GP_HI4.U)
#define HW_OCOTP_HW_OCOTP_GP_HI4_WR(v)     (HW_OCOTP_HW_OCOTP_GP_HI4.U = (v))
#define HW_OCOTP_HW_OCOTP_GP_HI4_SET(v)    (HW_OCOTP_HW_OCOTP_GP_HI4_WR(HW_OCOTP_HW_OCOTP_GP_HI4_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_GP_HI4_CLR(v)    (HW_OCOTP_HW_OCOTP_GP_HI4_WR(HW_OCOTP_HW_OCOTP_GP_HI4_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_GP_HI4_TOG(v)    (HW_OCOTP_HW_OCOTP_GP_HI4_WR(HW_OCOTP_HW_OCOTP_GP_HI4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_GP_HI4 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_GP_HI4, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 7, word 4 (ADDR = 0x3c).
 */

#define BP_OCOTP_HW_OCOTP_GP_HI4_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_GP_HI4_BITS.
#define BM_OCOTP_HW_OCOTP_GP_HI4_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_GP_HI4_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_GP_HI4_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_GP_HI4_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_GP_HI4_BITS) >> BP_OCOTP_HW_OCOTP_GP_HI4_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_HI4_BITS.
#define BF_OCOTP_HW_OCOTP_GP_HI4_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_GP_HI4_BITS) & BM_OCOTP_HW_OCOTP_GP_HI4_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_HI4_BITS.
#define BF_OCOTP_HW_OCOTP_GP_HI4_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_GP_HI4_BITS) & BM_OCOTP_HW_OCOTP_GP_HI4_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_GP_HI4_BITS(v)   (HW_OCOTP_HW_OCOTP_GP_HI4_WR((HW_OCOTP_HW_OCOTP_GP_HI4_RD() & ~BM_OCOTP_HW_OCOTP_GP_HI4_BITS) | BF_OCOTP_HW_OCOTP_GP_HI4_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_GP_HI5 - Value of OTP Bank7 Word5 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 7, word 5 (ADDR = 0x3d).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_gp_hi5
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_gp_hi5_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 7, word 5 (ADDR = 0x3d).
    } B;
} hw_ocotp_hw_ocotp_gp_hi5_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_GP_HI5 register
 */
#define HW_OCOTP_HW_OCOTP_GP_HI5_ADDR      (REGS_OCOTP_BASE + 0x7d0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_GP_HI5           (*(volatile hw_ocotp_hw_ocotp_gp_hi5_t *) HW_OCOTP_HW_OCOTP_GP_HI5_ADDR)
#define HW_OCOTP_HW_OCOTP_GP_HI5_RD()      (HW_OCOTP_HW_OCOTP_GP_HI5.U)
#define HW_OCOTP_HW_OCOTP_GP_HI5_WR(v)     (HW_OCOTP_HW_OCOTP_GP_HI5.U = (v))
#define HW_OCOTP_HW_OCOTP_GP_HI5_SET(v)    (HW_OCOTP_HW_OCOTP_GP_HI5_WR(HW_OCOTP_HW_OCOTP_GP_HI5_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_GP_HI5_CLR(v)    (HW_OCOTP_HW_OCOTP_GP_HI5_WR(HW_OCOTP_HW_OCOTP_GP_HI5_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_GP_HI5_TOG(v)    (HW_OCOTP_HW_OCOTP_GP_HI5_WR(HW_OCOTP_HW_OCOTP_GP_HI5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_GP_HI5 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_GP_HI5, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 7, word 5 (ADDR = 0x3d).
 */

#define BP_OCOTP_HW_OCOTP_GP_HI5_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_GP_HI5_BITS.
#define BM_OCOTP_HW_OCOTP_GP_HI5_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_GP_HI5_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_GP_HI5_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_GP_HI5_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_GP_HI5_BITS) >> BP_OCOTP_HW_OCOTP_GP_HI5_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_HI5_BITS.
#define BF_OCOTP_HW_OCOTP_GP_HI5_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_GP_HI5_BITS) & BM_OCOTP_HW_OCOTP_GP_HI5_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_HI5_BITS.
#define BF_OCOTP_HW_OCOTP_GP_HI5_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_GP_HI5_BITS) & BM_OCOTP_HW_OCOTP_GP_HI5_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_GP_HI5_BITS(v)   (HW_OCOTP_HW_OCOTP_GP_HI5_WR((HW_OCOTP_HW_OCOTP_GP_HI5_RD() & ~BM_OCOTP_HW_OCOTP_GP_HI5_BITS) | BF_OCOTP_HW_OCOTP_GP_HI5_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_GP_HI6 - Value of OTP Bank7 Word6 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 7, word 6 (ADDR = 0x3e).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_gp_hi6
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_gp_hi6_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 7, word 6 (ADDR = 0x3e).
    } B;
} hw_ocotp_hw_ocotp_gp_hi6_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_GP_HI6 register
 */
#define HW_OCOTP_HW_OCOTP_GP_HI6_ADDR      (REGS_OCOTP_BASE + 0x7e0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_GP_HI6           (*(volatile hw_ocotp_hw_ocotp_gp_hi6_t *) HW_OCOTP_HW_OCOTP_GP_HI6_ADDR)
#define HW_OCOTP_HW_OCOTP_GP_HI6_RD()      (HW_OCOTP_HW_OCOTP_GP_HI6.U)
#define HW_OCOTP_HW_OCOTP_GP_HI6_WR(v)     (HW_OCOTP_HW_OCOTP_GP_HI6.U = (v))
#define HW_OCOTP_HW_OCOTP_GP_HI6_SET(v)    (HW_OCOTP_HW_OCOTP_GP_HI6_WR(HW_OCOTP_HW_OCOTP_GP_HI6_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_GP_HI6_CLR(v)    (HW_OCOTP_HW_OCOTP_GP_HI6_WR(HW_OCOTP_HW_OCOTP_GP_HI6_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_GP_HI6_TOG(v)    (HW_OCOTP_HW_OCOTP_GP_HI6_WR(HW_OCOTP_HW_OCOTP_GP_HI6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_GP_HI6 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_GP_HI6, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 7, word 6 (ADDR = 0x3e).
 */

#define BP_OCOTP_HW_OCOTP_GP_HI6_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_GP_HI6_BITS.
#define BM_OCOTP_HW_OCOTP_GP_HI6_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_GP_HI6_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_GP_HI6_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_GP_HI6_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_GP_HI6_BITS) >> BP_OCOTP_HW_OCOTP_GP_HI6_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_HI6_BITS.
#define BF_OCOTP_HW_OCOTP_GP_HI6_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_GP_HI6_BITS) & BM_OCOTP_HW_OCOTP_GP_HI6_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_HI6_BITS.
#define BF_OCOTP_HW_OCOTP_GP_HI6_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_GP_HI6_BITS) & BM_OCOTP_HW_OCOTP_GP_HI6_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_GP_HI6_BITS(v)   (HW_OCOTP_HW_OCOTP_GP_HI6_WR((HW_OCOTP_HW_OCOTP_GP_HI6_RD() & ~BM_OCOTP_HW_OCOTP_GP_HI6_BITS) | BF_OCOTP_HW_OCOTP_GP_HI6_BITS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_OCOTP_HW_OCOTP_GP_HI7 - Value of OTP Bank7 Word7 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 7, word 7 (ADDR = 0x3f).
 * EXAMPLE   Empty Example.
 */
typedef union _hw_ocotp_hw_ocotp_gp_hi7
{
    reg32_t U;
    struct _hw_ocotp_hw_ocotp_gp_hi7_bitfields
    {
        unsigned BITS : 32; //!< [31:0] Reflects value of OTP Bank 7, word 7 (ADDR = 0x3f).
    } B;
} hw_ocotp_hw_ocotp_gp_hi7_t;
#endif

/*
 * constants & macros for entire OCOTP_HW_OCOTP_GP_HI7 register
 */
#define HW_OCOTP_HW_OCOTP_GP_HI7_ADDR      (REGS_OCOTP_BASE + 0x7f0)

#ifndef __LANGUAGE_ASM__
#define HW_OCOTP_HW_OCOTP_GP_HI7           (*(volatile hw_ocotp_hw_ocotp_gp_hi7_t *) HW_OCOTP_HW_OCOTP_GP_HI7_ADDR)
#define HW_OCOTP_HW_OCOTP_GP_HI7_RD()      (HW_OCOTP_HW_OCOTP_GP_HI7.U)
#define HW_OCOTP_HW_OCOTP_GP_HI7_WR(v)     (HW_OCOTP_HW_OCOTP_GP_HI7.U = (v))
#define HW_OCOTP_HW_OCOTP_GP_HI7_SET(v)    (HW_OCOTP_HW_OCOTP_GP_HI7_WR(HW_OCOTP_HW_OCOTP_GP_HI7_RD() |  (v)))
#define HW_OCOTP_HW_OCOTP_GP_HI7_CLR(v)    (HW_OCOTP_HW_OCOTP_GP_HI7_WR(HW_OCOTP_HW_OCOTP_GP_HI7_RD() & ~(v)))
#define HW_OCOTP_HW_OCOTP_GP_HI7_TOG(v)    (HW_OCOTP_HW_OCOTP_GP_HI7_WR(HW_OCOTP_HW_OCOTP_GP_HI7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual OCOTP_HW_OCOTP_GP_HI7 bitfields
 */

/* --- Register HW_OCOTP_HW_OCOTP_GP_HI7, field BITS[31:0] (RW)
 *
 * Reflects value of OTP Bank 7, word 7 (ADDR = 0x3f).
 */

#define BP_OCOTP_HW_OCOTP_GP_HI7_BITS      (0)      //!< Bit position for OCOTP_HW_OCOTP_GP_HI7_BITS.
#define BM_OCOTP_HW_OCOTP_GP_HI7_BITS      (0xffffffff)  //!< Bit mask for OCOTP_HW_OCOTP_GP_HI7_BITS.

//! @brief Get value of OCOTP_HW_OCOTP_GP_HI7_BITS from a register value.
#define BG_OCOTP_HW_OCOTP_GP_HI7_BITS(r)   (((r) & BM_OCOTP_HW_OCOTP_GP_HI7_BITS) >> BP_OCOTP_HW_OCOTP_GP_HI7_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_HI7_BITS.
#define BF_OCOTP_HW_OCOTP_GP_HI7_BITS(v)   ((((reg32_t) v) << BP_OCOTP_HW_OCOTP_GP_HI7_BITS) & BM_OCOTP_HW_OCOTP_GP_HI7_BITS)
#else
//! @brief Format value for bitfield OCOTP_HW_OCOTP_GP_HI7_BITS.
#define BF_OCOTP_HW_OCOTP_GP_HI7_BITS(v)   (((v) << BP_OCOTP_HW_OCOTP_GP_HI7_BITS) & BM_OCOTP_HW_OCOTP_GP_HI7_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BITS field to a new value.
#define BW_OCOTP_HW_OCOTP_GP_HI7_BITS(v)   (HW_OCOTP_HW_OCOTP_GP_HI7_WR((HW_OCOTP_HW_OCOTP_GP_HI7_RD() & ~BM_OCOTP_HW_OCOTP_GP_HI7_BITS) | BF_OCOTP_HW_OCOTP_GP_HI7_BITS(v)))
#endif


/*!
 * @brief All OCOTP module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_ocotp
{
    volatile hw_ocotp_hw_ocotp_ctrl_t HW_OCOTP_CTRL; //!< OTP Controller Control Register
    volatile reg32_t HW_OCOTP_CTRL_SET; //!< OTP Controller Control Register Set
    volatile reg32_t HW_OCOTP_CTRL_CLR; //!< OTP Controller Control Register Clear
    volatile reg32_t HW_OCOTP_CTRL_TOG; //!< OTP Controller Control Register Toggle
    volatile hw_ocotp_hw_ocotp_timing_t HW_OCOTP_TIMING; //!< OTP Controller Timing Register
    reg32_t _reserved0[3];
    volatile hw_ocotp_hw_ocotp_data_t HW_OCOTP_DATA; //!< OTP Controller Write Data Register
    reg32_t _reserved1[3];
    volatile hw_ocotp_hw_ocotp_read_ctrl_t HW_OCOTP_READ_CTRL; //!< OTP Controller Write Data Register
    reg32_t _reserved2[3];
    volatile hw_ocotp_hw_ocotp_read_fuse_data_t HW_OCOTP_READ_FUSE_DATA; //!< OTP Controller Read Data Register
    reg32_t _reserved3[3];
    volatile hw_ocotp_hw_ocotp_sw_sticky_t HW_OCOTP_SW_STICKY; //!< Sticky bit Register
    reg32_t _reserved4[3];
    volatile hw_ocotp_hw_ocotp_scs_t HW_OCOTP_SCS; //!< Software Controllable Signals Register
    volatile reg32_t HW_OCOTP_SCS_SET; //!< Software Controllable Signals Register Set
    volatile reg32_t HW_OCOTP_SCS_CLR; //!< Software Controllable Signals Register Clear
    volatile reg32_t HW_OCOTP_SCS_TOG; //!< Software Controllable Signals Register Toggle
    volatile hw_ocotp_hw_ocotp_crc_addr_t HW_OCOTP_CRC_ADDR; //!< OTP Controller CRC test address
    reg32_t _reserved5[3];
    volatile hw_ocotp_hw_ocotp_crc_value_t HW_OCOTP_CRC_VALUE; //!< OTP Controller CRC Value Register
    reg32_t _reserved6[3];
    volatile hw_ocotp_hw_ocotp_umc_timing_t HW_OCOTP_UMC_TIMING; //!< OTP Controller Timing Register
    reg32_t _reserved7[3];
    volatile hw_ocotp_hw_ocotp_version_t HW_OCOTP_VERSION; //!< OTP Controller Version Register
    reg32_t _reserved8[215];
    volatile hw_ocotp_hw_ocotp_lock_t HW_OCOTP_LOCK; //!< Value of OTP Bank0 Word0 (Lock controls)
    reg32_t _reserved9[3];
    volatile hw_ocotp_hw_ocotp_cfg0_t HW_OCOTP_CFG0; //!< Value of OTP Bank0 Word1 (Configuration and Manufacturing Info.)
    reg32_t _reserved10[3];
    volatile hw_ocotp_hw_ocotp_cfg1_t HW_OCOTP_CFG1; //!< Value of OTP Bank0 Word2 (Configuration and Manufacturing Info.)
    reg32_t _reserved11[3];
    volatile hw_ocotp_hw_ocotp_cfg2_t HW_OCOTP_CFG2; //!< Value of OTP Bank0 Word3 (Configuration and Manufacturing Info.)
    reg32_t _reserved12[3];
    volatile hw_ocotp_hw_ocotp_cfg3_t HW_OCOTP_CFG3; //!< Value of OTP Bank0 Word4 (Configuration and Manufacturing Info.)
    reg32_t _reserved13[3];
    volatile hw_ocotp_hw_ocotp_cfg4_t HW_OCOTP_CFG4; //!< Value of OTP Bank0 Word5 (Configuration and Manufacturing Info.)
    reg32_t _reserved14[3];
    volatile hw_ocotp_hw_ocotp_cfg5_t HW_OCOTP_CFG5; //!< Value of OTP Bank0 Word6 (Configuration and Manufacturing Info.)
    reg32_t _reserved15[3];
    volatile hw_ocotp_hw_ocotp_cfg6_t HW_OCOTP_CFG6; //!< Value of OTP Bank0 Word7 (Configuration and Manufacturing Info.)
    reg32_t _reserved16[3];
    volatile hw_ocotp_hw_ocotp_mem0_t HW_OCOTP_MEM0; //!< Value of OTP Bank1 Word0 (Memory Related Info.)
    reg32_t _reserved17[3];
    volatile hw_ocotp_hw_ocotp_mem1_t HW_OCOTP_MEM1; //!< Value of OTP Bank1 Word1 (Memory Related Info.)
    reg32_t _reserved18[3];
    volatile hw_ocotp_hw_ocotp_mem2_t HW_OCOTP_MEM2; //!< Value of OTP Bank1 Word2 (Memory Related Info.)
    reg32_t _reserved19[3];
    volatile hw_ocotp_hw_ocotp_mem3_t HW_OCOTP_MEM3; //!< Value of OTP Bank1 Word3 (Memory Related Info.)
    reg32_t _reserved20[3];
    volatile hw_ocotp_hw_ocotp_mem4_t HW_OCOTP_MEM4; //!< Value of OTP Bank1 Word4 (Memory Related Info.)
    reg32_t _reserved21[3];
    volatile hw_ocotp_hw_ocotp_ana0_t HW_OCOTP_ANA0; //!< Value of OTP Bank1 Word5 (Memory Related Info.)
    reg32_t _reserved22[3];
    volatile hw_ocotp_hw_ocotp_ana1_t HW_OCOTP_ANA1; //!< Value of OTP Bank1 Word6 (General Purpose Customer Defined Info.)
    reg32_t _reserved23[3];
    volatile hw_ocotp_hw_ocotp_ana2_t HW_OCOTP_ANA2; //!< Value of OTP Bank1 Word7 (General Purpose Customer Defined Info.)
    reg32_t _reserved24[3];
    volatile hw_ocotp_hw_ocotp_dcp0_t HW_OCOTP_DCP0; //!< Shadow Register for OTP Bank2 Word0 (DCP and CRYPTO Key)
    reg32_t _reserved25[3];
    volatile hw_ocotp_hw_ocotp_dcp1_t HW_OCOTP_DCP1; //!< Shadow Register for OTP Bank2 Word1 (DCP and CRYPTO Key)
    reg32_t _reserved26[3];
    volatile hw_ocotp_hw_ocotp_dcp2_t HW_OCOTP_DCP2; //!< Shadow Register for OTP Bank2 Word2 (DCP and CRYPTO Key)
    reg32_t _reserved27[3];
    volatile hw_ocotp_hw_ocotp_dcp3_t HW_OCOTP_DCP3; //!< Shadow Register for OTP Bank2 Word3 (DCP and CRYPTO Key)
    reg32_t _reserved28[3];
    volatile hw_ocotp_hw_ocotp_dcp4_t HW_OCOTP_DCP4; //!< Shadow Register for OTP Bank2 Word4 (DCP Key)
    reg32_t _reserved29[3];
    volatile hw_ocotp_hw_ocotp_dcp5_t HW_OCOTP_DCP5; //!< Shadow Register for OTP Bank2 Word5 (DCP Key)
    reg32_t _reserved30[3];
    volatile hw_ocotp_hw_ocotp_dcp6_t HW_OCOTP_DCP6; //!< Shadow Register for OTP Bank2 Word6 (DCP Key)
    reg32_t _reserved31[3];
    volatile hw_ocotp_hw_ocotp_dcp7_t HW_OCOTP_DCP7; //!< Shadow Register for OTP Bank2 Word7 (DCP Key)
    reg32_t _reserved32[3];
    volatile hw_ocotp_hw_ocotp_srk0_t HW_OCOTP_SRK0; //!< Shadow Register for OTP Bank3 Word0 (SRK Hash)
    reg32_t _reserved33[3];
    volatile hw_ocotp_hw_ocotp_srk1_t HW_OCOTP_SRK1; //!< Shadow Register for OTP Bank3 Word1 (SRK Hash)
    reg32_t _reserved34[3];
    volatile hw_ocotp_hw_ocotp_srk2_t HW_OCOTP_SRK2; //!< Shadow Register for OTP Bank3 Word2 (SRK Hash)
    reg32_t _reserved35[3];
    volatile hw_ocotp_hw_ocotp_srk3_t HW_OCOTP_SRK3; //!< Shadow Register for OTP Bank3 Word3 (SRK Hash)
    reg32_t _reserved36[3];
    volatile hw_ocotp_hw_ocotp_srk4_t HW_OCOTP_SRK4; //!< Shadow Register for OTP Bank3 Word4 (SRK Hash)
    reg32_t _reserved37[3];
    volatile hw_ocotp_hw_ocotp_srk5_t HW_OCOTP_SRK5; //!< Shadow Register for OTP Bank3 Word5 (SRK Hash)
    reg32_t _reserved38[3];
    volatile hw_ocotp_hw_ocotp_srk6_t HW_OCOTP_SRK6; //!< Shadow Register for OTP Bank3 Word6 (SRK Hash)
    reg32_t _reserved39[3];
    volatile hw_ocotp_hw_ocotp_srk7_t HW_OCOTP_SRK7; //!< Shadow Register for OTP Bank3 Word7 (SRK Hash)
    reg32_t _reserved40[3];
    volatile hw_ocotp_hw_ocotp_sjc_resp0_t HW_OCOTP_SJC_RESP0; //!< Value of OTP Bank4 Word0 (Secure JTAG Response Field)
    reg32_t _reserved41[3];
    volatile hw_ocotp_hw_ocotp_sjc_resp1_t HW_OCOTP_SJC_RESP1; //!< Value of OTP Bank4 Word1 (Secure JTAG Response Field)
    reg32_t _reserved42[3];
    volatile hw_ocotp_hw_ocotp_mac0_t HW_OCOTP_MAC0; //!< Value of OTP Bank4 Word2 (MAC Address)
    reg32_t _reserved43[3];
    volatile hw_ocotp_hw_ocotp_mac1_t HW_OCOTP_MAC1; //!< Value of OTP Bank4 Word3 (MAC Address)
    reg32_t _reserved44[3];
    volatile hw_ocotp_hw_ocotp_crc0_t HW_OCOTP_CRC0; //!< Value of OTP Bank4 Word4 (HW Capabilities)
    reg32_t _reserved45[3];
    volatile hw_ocotp_hw_ocotp_crc1_t HW_OCOTP_CRC1; //!< Value of OTP Bank4 Word5 (HW Capabilities)
    reg32_t _reserved46[3];
    volatile hw_ocotp_hw_ocotp_gp1_t HW_OCOTP_GP1; //!< Value of OTP Bank4 Word6 (HW Capabilities)
    reg32_t _reserved47[3];
    volatile hw_ocotp_hw_ocotp_gp2_t HW_OCOTP_GP2; //!< Value of OTP Bank4 Word7 (HW Capabilities)
    reg32_t _reserved48[3];
    volatile hw_ocotp_hw_ocotp_sw_gp0_t HW_OCOTP_SW_GP0; //!< Value of OTP Bank5 Word0 (HW Capabilities)
    reg32_t _reserved49[3];
    volatile hw_ocotp_hw_ocotp_sw_gp1_t HW_OCOTP_SW_GP1; //!< Value of OTP Bank5 Word1 (HW Capabilities)
    reg32_t _reserved50[3];
    volatile hw_ocotp_hw_ocotp_sw_gp2_t HW_OCOTP_SW_GP2; //!< Value of OTP Bank5 Word2 (HW Capabilities)
    reg32_t _reserved51[3];
    volatile hw_ocotp_hw_ocotp_sw_gp3_t HW_OCOTP_SW_GP3; //!< Value of OTP Bank5 Word3 (HW Capabilities)
    reg32_t _reserved52[3];
    volatile hw_ocotp_hw_ocotp_sw_gp4_t HW_OCOTP_SW_GP4; //!< Value of OTP Bank5 Word4 (HW Capabilities)
    reg32_t _reserved53[3];
    volatile hw_ocotp_hw_ocotp_misc_conf_t HW_OCOTP_MISC_CONF; //!< Value of OTP Bank5 Word5 (HW Capabilities)
    reg32_t _reserved54[3];
    volatile hw_ocotp_hw_ocotp_field_return_t HW_OCOTP_FIELD_RETURN; //!< Value of OTP Bank5 Word6 (HW Capabilities)
    reg32_t _reserved55[3];
    volatile hw_ocotp_hw_ocotp_srk_revoke_t HW_OCOTP_SRK_REVOKE; //!< Value of OTP Bank5 Word7 (HW Capabilities)
    reg32_t _reserved56[3];
    volatile hw_ocotp_hw_ocotp_gp_lo0_t HW_OCOTP_GP_LO0; //!< Value of OTP Bank6 Word0 (HW Capabilities)
    reg32_t _reserved57[3];
    volatile hw_ocotp_hw_ocotp_gp_lo1_t HW_OCOTP_GP_LO1; //!< Value of OTP Bank6 Word1 (HW Capabilities)
    reg32_t _reserved58[3];
    volatile hw_ocotp_hw_ocotp_gp_lo2_t HW_OCOTP_GP_LO2; //!< Value of OTP Bank6 Word2 (HW Capabilities)
    reg32_t _reserved59[3];
    volatile hw_ocotp_hw_ocotp_gp_lo3_t HW_OCOTP_GP_LO3; //!< Value of OTP Bank6 Word3 (HW Capabilities)
    reg32_t _reserved60[3];
    volatile hw_ocotp_hw_ocotp_gp_lo4_t HW_OCOTP_GP_LO4; //!< Value of OTP Bank6 Word4 (HW Capabilities)
    reg32_t _reserved61[3];
    volatile hw_ocotp_hw_ocotp_gp_lo5_t HW_OCOTP_GP_LO5; //!< Value of OTP Bank6 Word5 (HW Capabilities)
    reg32_t _reserved62[3];
    volatile hw_ocotp_hw_ocotp_gp_lo6_t HW_OCOTP_GP_LO6; //!< Value of OTP Bank6 Word6 (HW Capabilities)
    reg32_t _reserved63[3];
    volatile hw_ocotp_hw_ocotp_gp_lo7_t HW_OCOTP_GP_LO7; //!< Value of OTP Bank6 Word7 (HW Capabilities)
    reg32_t _reserved64[3];
    volatile hw_ocotp_hw_ocotp_gp_hi0_t HW_OCOTP_GP_HI0; //!< Value of OTP Bank7 Word0 (HW Capabilities)
    reg32_t _reserved65[3];
    volatile hw_ocotp_hw_ocotp_gp_hi1_t HW_OCOTP_GP_HI1; //!< Value of OTP Bank7 Word1 (HW Capabilities)
    reg32_t _reserved66[3];
    volatile hw_ocotp_hw_ocotp_gp_hi2_t HW_OCOTP_GP_HI2; //!< Value of OTP Bank7 Word2 (HW Capabilities)
    reg32_t _reserved67[3];
    volatile hw_ocotp_hw_ocotp_gp_hi3_t HW_OCOTP_GP_HI3; //!< Value of OTP Bank7 Word3 (HW Capabilities)
    reg32_t _reserved68[3];
    volatile hw_ocotp_hw_ocotp_gp_hi4_t HW_OCOTP_GP_HI4; //!< Value of OTP Bank7 Word4 (HW Capabilities)
    reg32_t _reserved69[3];
    volatile hw_ocotp_hw_ocotp_gp_hi5_t HW_OCOTP_GP_HI5; //!< Value of OTP Bank7 Word5 (HW Capabilities)
    reg32_t _reserved70[3];
    volatile hw_ocotp_hw_ocotp_gp_hi6_t HW_OCOTP_GP_HI6; //!< Value of OTP Bank7 Word6 (HW Capabilities)
    reg32_t _reserved71[3];
    volatile hw_ocotp_hw_ocotp_gp_hi7_t HW_OCOTP_GP_HI7; //!< Value of OTP Bank7 Word7 (HW Capabilities)
} hw_ocotp_t;
#pragma pack()
#endif

//! @brief Macro to access all OCOTP registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_OCOTP(0)</code>.
#define HW_OCOTP     (*(volatile hw_ocotp_t *) REGS_OCOTP_BASE)


#endif // _OCOTP_H