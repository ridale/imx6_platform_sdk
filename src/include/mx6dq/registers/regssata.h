/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_SATA_REGISTERS_H__
#define __HW_SATA_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6DQ SATA registers defined in this header file.
 *
 * - HW_SATA_CAP - HBA Capabilites Register
 * - HW_SATA_GHC - Global HBA Control Register
 * - HW_SATA_IS - Interrupt Status Register
 * - HW_SATA_PI - Ports Implemented Register
 * - HW_SATA_VS - AHCl Version Register
 * - HW_SATA_CCC_CTL - Command Completion Coalescing Control
 * - HW_SATA_CCC_PORTS - Command Completion Coalescing Ports
 * - HW_SATA_CAP2 - HBA Capabilities Extended Register
 * - HW_SATA_BISTAFR - BIST Activate FIS Register
 * - HW_SATA_BISTCR - BIST Control Register
 * - HW_SATA_BISTFCTR - BIST FIS Count Register
 * - HW_SATA_BISTSR - BIST Status Register
 * - HW_SATA_OOBR - OOB Register
 * - HW_SATA_GPCR - General Purpose Control Register
 * - HW_SATA_GPSR - General Purpose Status Register
 * - HW_SATA_TIMER1MS - Timer 1-ms Register
 * - HW_SATA_GPARAM1R - Global Parameter 1 Register
 * - HW_SATA_GPARAM2R - Global Parameter 1 Register
 * - HW_SATA_PPARAMR - Port Parameter Register
 * - HW_SATA_TESTR - Test Register
 * - HW_SATA_VERSIONR - Version Register
 * - HW_SATA_P0CLB - Port0 Command List Base Address Register
 * - HW_SATA_P0FB - Port0 FIS Base Address Register
 * - HW_SATA_P0IS - Port0 Interrupt Status Register
 * - HW_SATA_P0IE - Port0 Interrupt Enable Register
 * - HW_SATA_P0CMD - Port0 Command Register
 * - HW_SATA_P0TFD - Port0 Task File Data Register
 * - HW_SATA_P0SIG - Port0 Signature Register
 * - HW_SATA_P0SSTS - Port0 Serial ATA Status Register
 * - HW_SATA_P0SCTL - Port0 Serial ATA Control {SControl} Register
 * - HW_SATA_P0SERR - Port0 Serial ATA Error Register
 * - HW_SATA_P0SACT - Port0 Serial ATA Active Register
 * - HW_SATA_P0CI - Port0 Command Issue Register
 * - HW_SATA_P0SNTF - Port0 Serial ATA Notification Register
 * - HW_SATA_P0DMACR - Port0 DMA Control Register
 * - HW_SATA_P0PHYCR - Port0 PHY Control Register
 * - HW_SATA_P0PHYSR - Port0 PHY Status Register
 *
 * - hw_sata_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_SATA_BASE
#define HW_SATA_INSTANCE_COUNT (1) //!< Number of instances of the SATA module.
#define REGS_SATA_BASE (0x02200000) //!< Base address for SATA.
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
// HW_SATA_CAP - HBA Capabilites Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_CAP - HBA Capabilites Register (RO)
 *
 * Reset value: 0x00000000
 *
 * This register indicates basic capabilities of the SATA block to the software.
 */
typedef union _hw_sata_cap
{
    reg32_t U;
    struct _hw_sata_cap_bitfields
    {
        unsigned NP : 5; //!< [4:0] Number of Ports. 0's based value indicating the number of Ports supported by the SATA block: The options for this field are: • 0x00: 1 Port • 0x01: 2 Ports • 0x02: 3 Ports Reset Value: 0x00 Configurable: AHSATA_NUM_PORTS-1
        unsigned SXS : 1; //!< [5] Supports External SATA. The options for this field are: 1 Indicates that the SATA block has one or more Ports that has a signal only connector (power is not part of that connector) that is externally accessible. When this bit is set to 1, the software can refer to the SATA_P # 0 CMD[ESP] bit to determine whether a specific Port has its signal connector externally accessible. 0 Indicates that the SATA block has no Ports that have a signal only connector externally accessible. Reset Value: Configurable
        unsigned EMS : 1; //!< [6] Enclosure Management Support. SATA block does not support enclosure management.
        unsigned CCCS : 1; //!< [7] Command Completion Coalescing Support. SATA block supports command completion coalescing.
        unsigned NCS : 5; //!< [12:8] Number of Command Slots. SATA block supports 32 command slots per Port.
        unsigned PSC : 1; //!< [13] Partial State Capable. SATA block supports transitions to the interface PARTIAL power management state.
        unsigned SSC : 1; //!< [14] Slumber State Capable. SATA block supports transitions to the interface SLUMBER power management state.
        unsigned PMD : 1; //!< [15] PIO Multiple DRQ Block. SATA block supports multiple DRQ block data transfers for the PIO command protocol.
        unsigned RESERVED0 : 1; //!< [16] Reserved.
        unsigned SMP : 1; //!< [17] Supports Port Multiplier. SATA block supports command-based switching Port Multiplier on any of its Ports.
        unsigned SAM : 1; //!< [18] Supports AHCI Mode Only. SATA block supports AHCI mode only and does not support legacy, task-file based register interface.
        unsigned RESERVED1 : 1; //!< [19] Reserved. Returns 0 on read.
        unsigned ISS : 4; //!< [23:20] Interface Speed Support. Reserved. Returns 0x2 on read.
        unsigned SCLO : 1; //!< [24] Supports Command List Override. SATA block supports the SATA_P # 0 CMD[CLO] bit functionality for Port Multiplier devices' enumeration.
        unsigned SAL : 1; //!< [25] Supports Activity LED. SATA block supports activity indication using signal p # 0 _act_led.
        unsigned SALP : 1; //!< [26] Supports Aggressive Link Power Management. SATA block supports auto-generating (Port-initiated) Link Layer requests to the PARTIAL or SLUMBER power management states when there are no commands to process.
        unsigned SSS : 1; //!< [27] Supports Staggered Spin-up. This bit is set by the system firmware/BIOS to indicate platform support for staggered devices' spin-up. SATA block supports this feature through the SATA_P # 0 CMD[SUD] bit functionality.
        unsigned SMPS : 1; //!< [28] Supports Mechanical Presence Switch. This bit is set by the system firmware/BIOS when the platform supports mechanical presence switch for hot plug operation. Dependencies: This field is implemented only when parameter (Macro configuration parm) DEV_MP_SWITCH==Include. When this field is not implemented, this field is reserved, and reads 1'b0.
        unsigned SSNTF : 1; //!< [29] Supports SNotification Register. SATA block supports SATA_P # 0 SNTF (SNotification) register and its associated functionality.
        unsigned SNCQ : 1; //!< [30] Supports Native Command Queuing. SATA block supports SATA native command queueing by handling DMA Setup FIS natively.
        unsigned S64A : 1; //!< [31] Supports 64-bit Addressing SATA block supports 64-bit addressable data structures by utilizing PFFBU and P#CLBU registers. Reset Value: Configurable.
    } B;
} hw_sata_cap_t;
#endif

/*
 * constants & macros for entire SATA_CAP register
 */
#define HW_SATA_CAP_ADDR      (REGS_SATA_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_CAP           (*(volatile hw_sata_cap_t *) HW_SATA_CAP_ADDR)
#define HW_SATA_CAP_RD()      (HW_SATA_CAP.U)
#endif

/*
 * constants & macros for individual SATA_CAP bitfields
 */

/* --- Register HW_SATA_CAP, field NP[4:0] (RO)
 *
 * Number of Ports. 0's based value indicating the number of Ports supported by the SATA block: The
 * options for this field are: • 0x00: 1 Port • 0x01: 2 Ports • 0x02: 3 Ports Reset Value: 0x00
 * Configurable: AHSATA_NUM_PORTS-1
 */

#define BP_SATA_CAP_NP      (0)      //!< Bit position for SATA_CAP_NP.
#define BM_SATA_CAP_NP      (0x0000001f)  //!< Bit mask for SATA_CAP_NP.

//! @brief Get value of SATA_CAP_NP from a register value.
#define BG_SATA_CAP_NP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP_NP) >> BP_SATA_CAP_NP)

/* --- Register HW_SATA_CAP, field SXS[5] (RO)
 *
 * Supports External SATA. The options for this field are: 1 Indicates that the SATA block has one
 * or more Ports that has a signal only connector (power is not part of that connector) that is
 * externally accessible. When this bit is set to 1, the software can refer to the SATA_P # 0
 * CMD[ESP] bit to determine whether a specific Port has its signal connector externally accessible.
 * 0 Indicates that the SATA block has no Ports that have a signal only connector externally
 * accessible. Reset Value: Configurable
 *
 * Values:
 * 0 - when all of the SATA_P #  0 CMD[ESP]=0
 * 1 - when any of the SATA_P #  0 CMD[ESP]=1
 */

#define BP_SATA_CAP_SXS      (5)      //!< Bit position for SATA_CAP_SXS.
#define BM_SATA_CAP_SXS      (0x00000020)  //!< Bit mask for SATA_CAP_SXS.

//! @brief Get value of SATA_CAP_SXS from a register value.
#define BG_SATA_CAP_SXS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP_SXS) >> BP_SATA_CAP_SXS)


/* --- Register HW_SATA_CAP, field EMS[6] (RO)
 *
 * Enclosure Management Support. SATA block does not support enclosure management.
 */

#define BP_SATA_CAP_EMS      (6)      //!< Bit position for SATA_CAP_EMS.
#define BM_SATA_CAP_EMS      (0x00000040)  //!< Bit mask for SATA_CAP_EMS.

//! @brief Get value of SATA_CAP_EMS from a register value.
#define BG_SATA_CAP_EMS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP_EMS) >> BP_SATA_CAP_EMS)

/* --- Register HW_SATA_CAP, field CCCS[7] (RO)
 *
 * Command Completion Coalescing Support. SATA block supports command completion coalescing.
 */

#define BP_SATA_CAP_CCCS      (7)      //!< Bit position for SATA_CAP_CCCS.
#define BM_SATA_CAP_CCCS      (0x00000080)  //!< Bit mask for SATA_CAP_CCCS.

//! @brief Get value of SATA_CAP_CCCS from a register value.
#define BG_SATA_CAP_CCCS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP_CCCS) >> BP_SATA_CAP_CCCS)

/* --- Register HW_SATA_CAP, field NCS[12:8] (RO)
 *
 * Number of Command Slots. SATA block supports 32 command slots per Port.
 */

#define BP_SATA_CAP_NCS      (8)      //!< Bit position for SATA_CAP_NCS.
#define BM_SATA_CAP_NCS      (0x00001f00)  //!< Bit mask for SATA_CAP_NCS.

//! @brief Get value of SATA_CAP_NCS from a register value.
#define BG_SATA_CAP_NCS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP_NCS) >> BP_SATA_CAP_NCS)

/* --- Register HW_SATA_CAP, field PSC[13] (RO)
 *
 * Partial State Capable. SATA block supports transitions to the interface PARTIAL power management
 * state.
 */

#define BP_SATA_CAP_PSC      (13)      //!< Bit position for SATA_CAP_PSC.
#define BM_SATA_CAP_PSC      (0x00002000)  //!< Bit mask for SATA_CAP_PSC.

//! @brief Get value of SATA_CAP_PSC from a register value.
#define BG_SATA_CAP_PSC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP_PSC) >> BP_SATA_CAP_PSC)

/* --- Register HW_SATA_CAP, field SSC[14] (RO)
 *
 * Slumber State Capable. SATA block supports transitions to the interface SLUMBER power management
 * state.
 */

#define BP_SATA_CAP_SSC      (14)      //!< Bit position for SATA_CAP_SSC.
#define BM_SATA_CAP_SSC      (0x00004000)  //!< Bit mask for SATA_CAP_SSC.

//! @brief Get value of SATA_CAP_SSC from a register value.
#define BG_SATA_CAP_SSC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP_SSC) >> BP_SATA_CAP_SSC)

/* --- Register HW_SATA_CAP, field PMD[15] (RO)
 *
 * PIO Multiple DRQ Block. SATA block supports multiple DRQ block data transfers for the PIO command
 * protocol.
 */

#define BP_SATA_CAP_PMD      (15)      //!< Bit position for SATA_CAP_PMD.
#define BM_SATA_CAP_PMD      (0x00008000)  //!< Bit mask for SATA_CAP_PMD.

//! @brief Get value of SATA_CAP_PMD from a register value.
#define BG_SATA_CAP_PMD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP_PMD) >> BP_SATA_CAP_PMD)

/* --- Register HW_SATA_CAP, field SMP[17] (RO)
 *
 * Supports Port Multiplier. SATA block supports command-based switching Port Multiplier on any of
 * its Ports.
 */

#define BP_SATA_CAP_SMP      (17)      //!< Bit position for SATA_CAP_SMP.
#define BM_SATA_CAP_SMP      (0x00020000)  //!< Bit mask for SATA_CAP_SMP.

//! @brief Get value of SATA_CAP_SMP from a register value.
#define BG_SATA_CAP_SMP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP_SMP) >> BP_SATA_CAP_SMP)

/* --- Register HW_SATA_CAP, field SAM[18] (RO)
 *
 * Supports AHCI Mode Only. SATA block supports AHCI mode only and does not support legacy, task-
 * file based register interface.
 */

#define BP_SATA_CAP_SAM      (18)      //!< Bit position for SATA_CAP_SAM.
#define BM_SATA_CAP_SAM      (0x00040000)  //!< Bit mask for SATA_CAP_SAM.

//! @brief Get value of SATA_CAP_SAM from a register value.
#define BG_SATA_CAP_SAM(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP_SAM) >> BP_SATA_CAP_SAM)

/* --- Register HW_SATA_CAP, field ISS[23:20] (RU)
 *
 * Interface Speed Support. Reserved. Returns 0x2 on read.
 */

#define BP_SATA_CAP_ISS      (20)      //!< Bit position for SATA_CAP_ISS.
#define BM_SATA_CAP_ISS      (0x00f00000)  //!< Bit mask for SATA_CAP_ISS.

//! @brief Get value of SATA_CAP_ISS from a register value.
#define BG_SATA_CAP_ISS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP_ISS) >> BP_SATA_CAP_ISS)

/* --- Register HW_SATA_CAP, field SCLO[24] (RO)
 *
 * Supports Command List Override. SATA block supports the SATA_P # 0 CMD[CLO] bit functionality for
 * Port Multiplier devices' enumeration.
 */

#define BP_SATA_CAP_SCLO      (24)      //!< Bit position for SATA_CAP_SCLO.
#define BM_SATA_CAP_SCLO      (0x01000000)  //!< Bit mask for SATA_CAP_SCLO.

//! @brief Get value of SATA_CAP_SCLO from a register value.
#define BG_SATA_CAP_SCLO(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP_SCLO) >> BP_SATA_CAP_SCLO)

/* --- Register HW_SATA_CAP, field SAL[25] (RO)
 *
 * Supports Activity LED. SATA block supports activity indication using signal p # 0 _act_led.
 */

#define BP_SATA_CAP_SAL      (25)      //!< Bit position for SATA_CAP_SAL.
#define BM_SATA_CAP_SAL      (0x02000000)  //!< Bit mask for SATA_CAP_SAL.

//! @brief Get value of SATA_CAP_SAL from a register value.
#define BG_SATA_CAP_SAL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP_SAL) >> BP_SATA_CAP_SAL)

/* --- Register HW_SATA_CAP, field SALP[26] (RO)
 *
 * Supports Aggressive Link Power Management. SATA block supports auto-generating (Port-initiated)
 * Link Layer requests to the PARTIAL or SLUMBER power management states when there are no commands
 * to process.
 */

#define BP_SATA_CAP_SALP      (26)      //!< Bit position for SATA_CAP_SALP.
#define BM_SATA_CAP_SALP      (0x04000000)  //!< Bit mask for SATA_CAP_SALP.

//! @brief Get value of SATA_CAP_SALP from a register value.
#define BG_SATA_CAP_SALP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP_SALP) >> BP_SATA_CAP_SALP)

/* --- Register HW_SATA_CAP, field SSS[27] (RO)
 *
 * Supports Staggered Spin-up. This bit is set by the system firmware/BIOS to indicate platform
 * support for staggered devices' spin-up. SATA block supports this feature through the SATA_P # 0
 * CMD[SUD] bit functionality.
 */

#define BP_SATA_CAP_SSS      (27)      //!< Bit position for SATA_CAP_SSS.
#define BM_SATA_CAP_SSS      (0x08000000)  //!< Bit mask for SATA_CAP_SSS.

//! @brief Get value of SATA_CAP_SSS from a register value.
#define BG_SATA_CAP_SSS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP_SSS) >> BP_SATA_CAP_SSS)

/* --- Register HW_SATA_CAP, field SMPS[28] (RO)
 *
 * Supports Mechanical Presence Switch. This bit is set by the system firmware/BIOS when the
 * platform supports mechanical presence switch for hot plug operation. Dependencies: This field is
 * implemented only when parameter (Macro configuration parm) DEV_MP_SWITCH==Include. When this
 * field is not implemented, this field is reserved, and reads 1'b0.
 */

#define BP_SATA_CAP_SMPS      (28)      //!< Bit position for SATA_CAP_SMPS.
#define BM_SATA_CAP_SMPS      (0x10000000)  //!< Bit mask for SATA_CAP_SMPS.

//! @brief Get value of SATA_CAP_SMPS from a register value.
#define BG_SATA_CAP_SMPS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP_SMPS) >> BP_SATA_CAP_SMPS)

/* --- Register HW_SATA_CAP, field SSNTF[29] (RO)
 *
 * Supports SNotification Register. SATA block supports SATA_P # 0 SNTF (SNotification) register and
 * its associated functionality.
 */

#define BP_SATA_CAP_SSNTF      (29)      //!< Bit position for SATA_CAP_SSNTF.
#define BM_SATA_CAP_SSNTF      (0x20000000)  //!< Bit mask for SATA_CAP_SSNTF.

//! @brief Get value of SATA_CAP_SSNTF from a register value.
#define BG_SATA_CAP_SSNTF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP_SSNTF) >> BP_SATA_CAP_SSNTF)

/* --- Register HW_SATA_CAP, field SNCQ[30] (RO)
 *
 * Supports Native Command Queuing. SATA block supports SATA native command queueing by handling DMA
 * Setup FIS natively.
 */

#define BP_SATA_CAP_SNCQ      (30)      //!< Bit position for SATA_CAP_SNCQ.
#define BM_SATA_CAP_SNCQ      (0x40000000)  //!< Bit mask for SATA_CAP_SNCQ.

//! @brief Get value of SATA_CAP_SNCQ from a register value.
#define BG_SATA_CAP_SNCQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP_SNCQ) >> BP_SATA_CAP_SNCQ)

/* --- Register HW_SATA_CAP, field S64A[31] (RO)
 *
 * Supports 64-bit Addressing SATA block supports 64-bit addressable data structures by utilizing
 * PFFBU and P#CLBU registers. Reset Value: Configurable.
 *
 * Values:
 * 0 - when M_HADDR_WIDTH=32
 * 1 - when M_HADDR_WIDTH=64
 */

#define BP_SATA_CAP_S64A      (31)      //!< Bit position for SATA_CAP_S64A.
#define BM_SATA_CAP_S64A      (0x80000000)  //!< Bit mask for SATA_CAP_S64A.

//! @brief Get value of SATA_CAP_S64A from a register value.
#define BG_SATA_CAP_S64A(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP_S64A) >> BP_SATA_CAP_S64A)


//-------------------------------------------------------------------------------------------
// HW_SATA_GHC - Global HBA Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_GHC - Global HBA Control Register (RW)
 *
 * Reset value: 0x80000000
 *
 * This register controls various global actions of the SATA block.
 */
typedef union _hw_sata_ghc
{
    reg32_t U;
    struct _hw_sata_ghc_bitfields
    {
        unsigned HR : 1; //!< [0] HBA Reset. When set by the software, this bit causes an internal Global reset of the SATA block. All state machines that relate to data transfers and queueing return to an idle state, and all the Ports are re-initialized by sending COMRESET When staggered spin-up is not supported. When staggered spin-up is supported, then the software must spin-up each Port after this reset has completed. See for details. The SATA block clears this bit when the reset action is done. A software write of 0 has no effect.
        unsigned IE : 1; //!< [1] Interrupt Enable. This global bit enables interrupts from the SATA block. When cleared, all interrupt sources from all the Ports are disabled (masked). When set, interrupts are enabled and any SATA block interrupt event causes intrq output assertion. This field is reset on Global reset (SATA_GHC[HR]=1).
        unsigned RESERVED0 : 29; //!< [30:2] Reserved
        unsigned AE : 1; //!< [31] AHCI Enable. This bit is always set since SATA block supports only AHCI mode as indicated by the SATA_CAP[SAM]=1.
    } B;
} hw_sata_ghc_t;
#endif

/*
 * constants & macros for entire SATA_GHC register
 */
#define HW_SATA_GHC_ADDR      (REGS_SATA_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_GHC           (*(volatile hw_sata_ghc_t *) HW_SATA_GHC_ADDR)
#define HW_SATA_GHC_RD()      (HW_SATA_GHC.U)
#define HW_SATA_GHC_WR(v)     (HW_SATA_GHC.U = (v))
#define HW_SATA_GHC_SET(v)    (HW_SATA_GHC_WR(HW_SATA_GHC_RD() |  (v)))
#define HW_SATA_GHC_CLR(v)    (HW_SATA_GHC_WR(HW_SATA_GHC_RD() & ~(v)))
#define HW_SATA_GHC_TOG(v)    (HW_SATA_GHC_WR(HW_SATA_GHC_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_GHC bitfields
 */

/* --- Register HW_SATA_GHC, field HR[0] (WO)
 *
 * HBA Reset. When set by the software, this bit causes an internal Global reset of the SATA block.
 * All state machines that relate to data transfers and queueing return to an idle state, and all
 * the Ports are re-initialized by sending COMRESET When staggered spin-up is not supported. When
 * staggered spin-up is supported, then the software must spin-up each Port after this reset has
 * completed. See for details. The SATA block clears this bit when the reset action is done. A
 * software write of 0 has no effect.
 */

#define BP_SATA_GHC_HR      (0)      //!< Bit position for SATA_GHC_HR.
#define BM_SATA_GHC_HR      (0x00000001)  //!< Bit mask for SATA_GHC_HR.

//! @brief Get value of SATA_GHC_HR from a register value.
#define BG_SATA_GHC_HR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GHC_HR) >> BP_SATA_GHC_HR)

//! @brief Format value for bitfield SATA_GHC_HR.
#define BF_SATA_GHC_HR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_GHC_HR) & BM_SATA_GHC_HR)

/* --- Register HW_SATA_GHC, field IE[1] (RW)
 *
 * Interrupt Enable. This global bit enables interrupts from the SATA block. When cleared, all
 * interrupt sources from all the Ports are disabled (masked). When set, interrupts are enabled and
 * any SATA block interrupt event causes intrq output assertion. This field is reset on Global reset
 * (SATA_GHC[HR]=1).
 */

#define BP_SATA_GHC_IE      (1)      //!< Bit position for SATA_GHC_IE.
#define BM_SATA_GHC_IE      (0x00000002)  //!< Bit mask for SATA_GHC_IE.

//! @brief Get value of SATA_GHC_IE from a register value.
#define BG_SATA_GHC_IE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GHC_IE) >> BP_SATA_GHC_IE)

//! @brief Format value for bitfield SATA_GHC_IE.
#define BF_SATA_GHC_IE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_GHC_IE) & BM_SATA_GHC_IE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IE field to a new value.
#define BW_SATA_GHC_IE(v)   (HW_SATA_GHC_WR((HW_SATA_GHC_RD() & ~BM_SATA_GHC_IE) | BF_SATA_GHC_IE(v)))
#endif

/* --- Register HW_SATA_GHC, field AE[31] (RW)
 *
 * AHCI Enable. This bit is always set since SATA block supports only AHCI mode as indicated by the
 * SATA_CAP[SAM]=1.
 */

#define BP_SATA_GHC_AE      (31)      //!< Bit position for SATA_GHC_AE.
#define BM_SATA_GHC_AE      (0x80000000)  //!< Bit mask for SATA_GHC_AE.

//! @brief Get value of SATA_GHC_AE from a register value.
#define BG_SATA_GHC_AE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GHC_AE) >> BP_SATA_GHC_AE)

//! @brief Format value for bitfield SATA_GHC_AE.
#define BF_SATA_GHC_AE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_GHC_AE) & BM_SATA_GHC_AE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AE field to a new value.
#define BW_SATA_GHC_AE(v)   (HW_SATA_GHC_WR((HW_SATA_GHC_RD() & ~BM_SATA_GHC_AE) | BF_SATA_GHC_AE(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_SATA_IS - Interrupt Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_IS - Interrupt Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register indicates which of the Ports within the SATA block have an interrupt pending and
 * require service. This register is reset on Global reset (SATA_GHC[HR]=1).   Size: 32 bits
 * Address offset: 0x08  Read/write access: Read/Write One to Clear  Reset: 0x0000_00000
 */
typedef union _hw_sata_is
{
    reg32_t U;
    struct _hw_sata_is_bitfields
    {
        unsigned IPS : 2; //!< [1:0] Interrupt Pending Status. np-1-0 np = AHSATA_NUM_PORTS. When bit 1is set, this bit indicates that the corresponding Port 0 has an interrupt pending. Software can use this information to determine which Ports require service after an interrupt. The bits of this field are set by the Ports that have interrupt events pending in the P#IS bits and enabled by the P#IE (see "Interrupts" on page 73). Set bits are cleared by the software writing 1 to all bits to clear. This bit is set when the Port has an interrupt event pending and the interrupt source is enabled (see the definition of the SATA_P # 0 IE register). Bit 0 of the IPS field is not used.
        unsigned RESERVED0 : 30; //!< [31:2] Reserved. 31- np +1 np = AHSATA_NUM_PORTS
    } B;
} hw_sata_is_t;
#endif

/*
 * constants & macros for entire SATA_IS register
 */
#define HW_SATA_IS_ADDR      (REGS_SATA_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_IS           (*(volatile hw_sata_is_t *) HW_SATA_IS_ADDR)
#define HW_SATA_IS_RD()      (HW_SATA_IS.U)
#define HW_SATA_IS_WR(v)     (HW_SATA_IS.U = (v))
#define HW_SATA_IS_SET(v)    (HW_SATA_IS_WR(HW_SATA_IS_RD() |  (v)))
#define HW_SATA_IS_CLR(v)    (HW_SATA_IS_WR(HW_SATA_IS_RD() & ~(v)))
#define HW_SATA_IS_TOG(v)    (HW_SATA_IS_WR(HW_SATA_IS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_IS bitfields
 */

/* --- Register HW_SATA_IS, field IPS[1:0] (W1C)
 *
 * Interrupt Pending Status. np-1-0 np = AHSATA_NUM_PORTS. When bit 1is set, this bit indicates that
 * the corresponding Port 0 has an interrupt pending. Software can use this information to determine
 * which Ports require service after an interrupt. The bits of this field are set by the Ports that
 * have interrupt events pending in the P#IS bits and enabled by the P#IE (see "Interrupts" on page
 * 73). Set bits are cleared by the software writing 1 to all bits to clear. This bit is set when
 * the Port has an interrupt event pending and the interrupt source is enabled (see the definition
 * of the SATA_P # 0 IE register). Bit 0 of the IPS field is not used.
 */

#define BP_SATA_IS_IPS      (0)      //!< Bit position for SATA_IS_IPS.
#define BM_SATA_IS_IPS      (0x00000003)  //!< Bit mask for SATA_IS_IPS.

//! @brief Get value of SATA_IS_IPS from a register value.
#define BG_SATA_IS_IPS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_IS_IPS) >> BP_SATA_IS_IPS)

//! @brief Format value for bitfield SATA_IS_IPS.
#define BF_SATA_IS_IPS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_IS_IPS) & BM_SATA_IS_IPS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPS field to a new value.
#define BW_SATA_IS_IPS(v)   (HW_SATA_IS_WR((HW_SATA_IS_RD() & ~BM_SATA_IS_IPS) | BF_SATA_IS_IPS(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_SATA_PI - Ports Implemented Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_PI - Ports Implemented Register (RO)
 *
 * Reset value: 0x00000000
 *
 * This register indicates which Ports are exposed by the SATA block and are available for the
 * software to use. It is loaded by the BIOS. For example, when the SATA block supports 8 Ports as
 * indicated in the SATA_CAP[NP], only Ports 1, 3, 5, and 7 could be available, while Ports 0, 2, 4,
 * and 6 being unavailable.  The contents of this register are relevant to the SATA_CCC_PORTS
 * (Command Completion Coalescing Ports) register.
 */
typedef union _hw_sata_pi
{
    reg32_t U;
    struct _hw_sata_pi_bitfields
    {
        unsigned PI : 1; //!< [0] Ports Implemented. BIOS must set this bit to 1 np-1-0. np = AHSATA_NUM_PORTS. This register is bit significant. The maximum number of bits that can be set to 1 is CAP.NP+1. At least one bit must be set to 1.
        unsigned RESERVED0 : 31; //!< [31:1] Reserved. 31-1np np = AHSATA_NUM_PORTS.
    } B;
} hw_sata_pi_t;
#endif

/*
 * constants & macros for entire SATA_PI register
 */
#define HW_SATA_PI_ADDR      (REGS_SATA_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_PI           (*(volatile hw_sata_pi_t *) HW_SATA_PI_ADDR)
#define HW_SATA_PI_RD()      (HW_SATA_PI.U)
#endif

/*
 * constants & macros for individual SATA_PI bitfields
 */

/* --- Register HW_SATA_PI, field PI[0] (RO)
 *
 * Ports Implemented. BIOS must set this bit to 1 np-1-0. np = AHSATA_NUM_PORTS. This register is
 * bit significant. The maximum number of bits that can be set to 1 is CAP.NP+1. At least one bit
 * must be set to 1.
 */

#define BP_SATA_PI_PI      (0)      //!< Bit position for SATA_PI_PI.
#define BM_SATA_PI_PI      (0x00000001)  //!< Bit mask for SATA_PI_PI.

//! @brief Get value of SATA_PI_PI from a register value.
#define BG_SATA_PI_PI(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_PI_PI) >> BP_SATA_PI_PI)

//-------------------------------------------------------------------------------------------
// HW_SATA_VS - AHCl Version Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_VS - AHCl Version Register (RO)
 *
 * Reset value: 0x00010300
 *
 * This register indicates the major and minor version of the AHCI specification that the SATA block
 * implementation supports. The SATA block supports version 1.30.  The SATA block core currently
 * complies fully with AHCI version 1.10 , and complies with AHCI version 1.3, except with respect
 * to FIS-based switching. FIS-based switching is not currently supported.
 */
typedef union _hw_sata_vs
{
    reg32_t U;
    struct _hw_sata_vs_bitfields
    {
        unsigned MNR : 16; //!< [15:0] Minor Version Number. Indicates that the minor AHCI version is 30.
        unsigned MJR : 16; //!< [31:16] Major Version Number. Indicates that the major AHCI version is 1.
    } B;
} hw_sata_vs_t;
#endif

/*
 * constants & macros for entire SATA_VS register
 */
#define HW_SATA_VS_ADDR      (REGS_SATA_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_VS           (*(volatile hw_sata_vs_t *) HW_SATA_VS_ADDR)
#define HW_SATA_VS_RD()      (HW_SATA_VS.U)
#endif

/*
 * constants & macros for individual SATA_VS bitfields
 */

/* --- Register HW_SATA_VS, field MNR[15:0] (RO)
 *
 * Minor Version Number. Indicates that the minor AHCI version is 30.
 */

#define BP_SATA_VS_MNR      (0)      //!< Bit position for SATA_VS_MNR.
#define BM_SATA_VS_MNR      (0x0000ffff)  //!< Bit mask for SATA_VS_MNR.

//! @brief Get value of SATA_VS_MNR from a register value.
#define BG_SATA_VS_MNR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_VS_MNR) >> BP_SATA_VS_MNR)

/* --- Register HW_SATA_VS, field MJR[31:16] (RO)
 *
 * Major Version Number. Indicates that the major AHCI version is 1.
 */

#define BP_SATA_VS_MJR      (16)      //!< Bit position for SATA_VS_MJR.
#define BM_SATA_VS_MJR      (0xffff0000)  //!< Bit mask for SATA_VS_MJR.

//! @brief Get value of SATA_VS_MJR from a register value.
#define BG_SATA_VS_MJR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_VS_MJR) >> BP_SATA_VS_MJR)

//-------------------------------------------------------------------------------------------
// HW_SATA_CCC_CTL - Command Completion Coalescing Control
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_CCC_CTL - Command Completion Coalescing Control (RW)
 *
 * Reset value: 0x00000000
 *
 * This register is used to configure the command completion coalescing (CCC) feature for the SATA
 * block core. It is reset on Global reset.
 */
typedef union _hw_sata_ccc_ctl
{
    reg32_t U;
    struct _hw_sata_ccc_ctl_bitfields
    {
        unsigned EN : 1; //!< [0] Enable. When field SATA_CCC_CTL[EN]==1, the software can not change the fields SATA_CCC_CTL[TV] and SATA_CCC_CTL[CC]. The options for this field are:
        unsigned RESERVED0 : 2; //!< [2:1] Reserved.
        unsigned INT : 5; //!< [7:3] Interrupt. Set this field to 0x01. This field specifies the interrupt used by the CCC feature, using the number of Ports configured for the core. For example, when AHSATA_NUM_PORTS==6 then This field SATA_CCC_CTL.INT==6. When a CCC interrupt occurs, the field SATA_IS.IPS[INT] is set to 1. Reset Value: Configurable: AHSATA_NUM_PORTS.
        unsigned CC : 8; //!< [15:8] Command Completions. This field specifies the number of command completions that are necessary to cause a CCC interrupt. The value 0x00 for this field disables CCC interrupts being generated based on the number of commands completed. In this case, CCC interrupts are only generated based on the timer. Software loads this value prior to enabling CCC: Field access is: • RW when SATA_CCC_CTL[EN]==0 • RO when SATA_CCC_CTL[EN]==1
        unsigned TV : 16; //!< [31:16] Time-out Value. This field specifies the CCC time-out value in 1ms intervals. The software loads this value prior to enabling CCC. The options for this field are: • RW when SATA_CCC_CTL[EN]==0. • RO when SATA_CCC_CTL[EN]==1. A time-out value of 0x0000 is reserved and should not be used.
    } B;
} hw_sata_ccc_ctl_t;
#endif

/*
 * constants & macros for entire SATA_CCC_CTL register
 */
#define HW_SATA_CCC_CTL_ADDR      (REGS_SATA_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_CCC_CTL           (*(volatile hw_sata_ccc_ctl_t *) HW_SATA_CCC_CTL_ADDR)
#define HW_SATA_CCC_CTL_RD()      (HW_SATA_CCC_CTL.U)
#define HW_SATA_CCC_CTL_WR(v)     (HW_SATA_CCC_CTL.U = (v))
#define HW_SATA_CCC_CTL_SET(v)    (HW_SATA_CCC_CTL_WR(HW_SATA_CCC_CTL_RD() |  (v)))
#define HW_SATA_CCC_CTL_CLR(v)    (HW_SATA_CCC_CTL_WR(HW_SATA_CCC_CTL_RD() & ~(v)))
#define HW_SATA_CCC_CTL_TOG(v)    (HW_SATA_CCC_CTL_WR(HW_SATA_CCC_CTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_CCC_CTL bitfields
 */

/* --- Register HW_SATA_CCC_CTL, field EN[0] (RW)
 *
 * Enable. When field SATA_CCC_CTL[EN]==1, the software can not change the fields SATA_CCC_CTL[TV]
 * and SATA_CCC_CTL[CC]. The options for this field are:
 *
 * Values:
 * 0 - CCC feature is disabled and no CCC interrupts are generated.
 * 1 - CCC feature is enabled and CCC interrupts may be generated based on the time-out or command
 *     completion conditions.
 */

#define BP_SATA_CCC_CTL_EN      (0)      //!< Bit position for SATA_CCC_CTL_EN.
#define BM_SATA_CCC_CTL_EN      (0x00000001)  //!< Bit mask for SATA_CCC_CTL_EN.

//! @brief Get value of SATA_CCC_CTL_EN from a register value.
#define BG_SATA_CCC_CTL_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CCC_CTL_EN) >> BP_SATA_CCC_CTL_EN)

//! @brief Format value for bitfield SATA_CCC_CTL_EN.
#define BF_SATA_CCC_CTL_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_CCC_CTL_EN) & BM_SATA_CCC_CTL_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_SATA_CCC_CTL_EN(v)   (HW_SATA_CCC_CTL_WR((HW_SATA_CCC_CTL_RD() & ~BM_SATA_CCC_CTL_EN) | BF_SATA_CCC_CTL_EN(v)))
#endif


/* --- Register HW_SATA_CCC_CTL, field INT[7:3] (RW)
 *
 * Interrupt. Set this field to 0x01. This field specifies the interrupt used by the CCC feature,
 * using the number of Ports configured for the core. For example, when AHSATA_NUM_PORTS==6 then
 * This field SATA_CCC_CTL.INT==6. When a CCC interrupt occurs, the field SATA_IS.IPS[INT] is set to
 * 1. Reset Value: Configurable: AHSATA_NUM_PORTS.
 */

#define BP_SATA_CCC_CTL_INT      (3)      //!< Bit position for SATA_CCC_CTL_INT.
#define BM_SATA_CCC_CTL_INT      (0x000000f8)  //!< Bit mask for SATA_CCC_CTL_INT.

//! @brief Get value of SATA_CCC_CTL_INT from a register value.
#define BG_SATA_CCC_CTL_INT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CCC_CTL_INT) >> BP_SATA_CCC_CTL_INT)

//! @brief Format value for bitfield SATA_CCC_CTL_INT.
#define BF_SATA_CCC_CTL_INT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_CCC_CTL_INT) & BM_SATA_CCC_CTL_INT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INT field to a new value.
#define BW_SATA_CCC_CTL_INT(v)   (HW_SATA_CCC_CTL_WR((HW_SATA_CCC_CTL_RD() & ~BM_SATA_CCC_CTL_INT) | BF_SATA_CCC_CTL_INT(v)))
#endif

/* --- Register HW_SATA_CCC_CTL, field CC[15:8] (RW)
 *
 * Command Completions. This field specifies the number of command completions that are necessary to
 * cause a CCC interrupt. The value 0x00 for this field disables CCC interrupts being generated
 * based on the number of commands completed. In this case, CCC interrupts are only generated based
 * on the timer. Software loads this value prior to enabling CCC: Field access is: • RW when
 * SATA_CCC_CTL[EN]==0 • RO when SATA_CCC_CTL[EN]==1
 */

#define BP_SATA_CCC_CTL_CC      (8)      //!< Bit position for SATA_CCC_CTL_CC.
#define BM_SATA_CCC_CTL_CC      (0x0000ff00)  //!< Bit mask for SATA_CCC_CTL_CC.

//! @brief Get value of SATA_CCC_CTL_CC from a register value.
#define BG_SATA_CCC_CTL_CC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CCC_CTL_CC) >> BP_SATA_CCC_CTL_CC)

//! @brief Format value for bitfield SATA_CCC_CTL_CC.
#define BF_SATA_CCC_CTL_CC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_CCC_CTL_CC) & BM_SATA_CCC_CTL_CC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CC field to a new value.
#define BW_SATA_CCC_CTL_CC(v)   (HW_SATA_CCC_CTL_WR((HW_SATA_CCC_CTL_RD() & ~BM_SATA_CCC_CTL_CC) | BF_SATA_CCC_CTL_CC(v)))
#endif

/* --- Register HW_SATA_CCC_CTL, field TV[31:16] (RW)
 *
 * Time-out Value. This field specifies the CCC time-out value in 1ms intervals. The software loads
 * this value prior to enabling CCC. The options for this field are: • RW when SATA_CCC_CTL[EN]==0.
 * • RO when SATA_CCC_CTL[EN]==1. A time-out value of 0x0000 is reserved and should not be used.
 */

#define BP_SATA_CCC_CTL_TV      (16)      //!< Bit position for SATA_CCC_CTL_TV.
#define BM_SATA_CCC_CTL_TV      (0xffff0000)  //!< Bit mask for SATA_CCC_CTL_TV.

//! @brief Get value of SATA_CCC_CTL_TV from a register value.
#define BG_SATA_CCC_CTL_TV(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CCC_CTL_TV) >> BP_SATA_CCC_CTL_TV)

//! @brief Format value for bitfield SATA_CCC_CTL_TV.
#define BF_SATA_CCC_CTL_TV(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_CCC_CTL_TV) & BM_SATA_CCC_CTL_TV)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TV field to a new value.
#define BW_SATA_CCC_CTL_TV(v)   (HW_SATA_CCC_CTL_WR((HW_SATA_CCC_CTL_RD() & ~BM_SATA_CCC_CTL_TV) | BF_SATA_CCC_CTL_TV(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_SATA_CCC_PORTS - Command Completion Coalescing Ports
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_CCC_PORTS - Command Completion Coalescing Ports (RW)
 *
 * Reset value: 0x00000000
 *
 * This register specifies the Ports that are coalesced as part of the command completion coalescing
 * (CCC) feature when SATA_CCC_CTL[EN]==1. It is reset on Global reset.
 */
typedef union _hw_sata_ccc_ports
{
    reg32_t U;
    struct _hw_sata_ccc_ports_bitfields
    {
        unsigned PRT : 32; //!< [31:0] Ports. This field is bit significant. Each bit corresponds to a particular Port, where bit 0 corresponds to Port0. Bits set in this register must have the corresponding bit set in the SATA_PI (Ports Implemented Register). The options for this field are:
    } B;
} hw_sata_ccc_ports_t;
#endif

/*
 * constants & macros for entire SATA_CCC_PORTS register
 */
#define HW_SATA_CCC_PORTS_ADDR      (REGS_SATA_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_CCC_PORTS           (*(volatile hw_sata_ccc_ports_t *) HW_SATA_CCC_PORTS_ADDR)
#define HW_SATA_CCC_PORTS_RD()      (HW_SATA_CCC_PORTS.U)
#define HW_SATA_CCC_PORTS_WR(v)     (HW_SATA_CCC_PORTS.U = (v))
#define HW_SATA_CCC_PORTS_SET(v)    (HW_SATA_CCC_PORTS_WR(HW_SATA_CCC_PORTS_RD() |  (v)))
#define HW_SATA_CCC_PORTS_CLR(v)    (HW_SATA_CCC_PORTS_WR(HW_SATA_CCC_PORTS_RD() & ~(v)))
#define HW_SATA_CCC_PORTS_TOG(v)    (HW_SATA_CCC_PORTS_WR(HW_SATA_CCC_PORTS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_CCC_PORTS bitfields
 */

/* --- Register HW_SATA_CCC_PORTS, field PRT[31:0] (RW)
 *
 * Ports. This field is bit significant. Each bit corresponds to a particular Port, where bit 0
 * corresponds to Port0. Bits set in this register must have the corresponding bit set in the
 * SATA_PI (Ports Implemented Register). The options for this field are:
 *
 * Values:
 * 0 - the corresponding Port is not part of the CCC feature.
 * 1 - the corresponding Port is part of the CCC feature.
 */

#define BP_SATA_CCC_PORTS_PRT      (0)      //!< Bit position for SATA_CCC_PORTS_PRT.
#define BM_SATA_CCC_PORTS_PRT      (0xffffffff)  //!< Bit mask for SATA_CCC_PORTS_PRT.

//! @brief Get value of SATA_CCC_PORTS_PRT from a register value.
#define BG_SATA_CCC_PORTS_PRT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CCC_PORTS_PRT) >> BP_SATA_CCC_PORTS_PRT)

//! @brief Format value for bitfield SATA_CCC_PORTS_PRT.
#define BF_SATA_CCC_PORTS_PRT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_CCC_PORTS_PRT) & BM_SATA_CCC_PORTS_PRT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PRT field to a new value.
#define BW_SATA_CCC_PORTS_PRT(v)   (HW_SATA_CCC_PORTS_WR((HW_SATA_CCC_PORTS_RD() & ~BM_SATA_CCC_PORTS_PRT) | BF_SATA_CCC_PORTS_PRT(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_SATA_CAP2 - HBA Capabilities Extended Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_CAP2 - HBA Capabilities Extended Register (RO)
 *
 * Reset value: 0x00000004
 *
 * This register indicates capabilites of the SATA block core to the software.
 */
typedef union _hw_sata_cap2
{
    reg32_t U;
    struct _hw_sata_cap2_bitfields
    {
        unsigned RESERVED0 : 2; //!< [1:0] Reserved.
        unsigned APST : 1; //!< [2] Automatic Partial to Slumber Transitions. SATA block supports automatic Partial to Slumber transitions.
        unsigned RESERVED1 : 29; //!< [31:3] Reserved
    } B;
} hw_sata_cap2_t;
#endif

/*
 * constants & macros for entire SATA_CAP2 register
 */
#define HW_SATA_CAP2_ADDR      (REGS_SATA_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_CAP2           (*(volatile hw_sata_cap2_t *) HW_SATA_CAP2_ADDR)
#define HW_SATA_CAP2_RD()      (HW_SATA_CAP2.U)
#endif

/*
 * constants & macros for individual SATA_CAP2 bitfields
 */

/* --- Register HW_SATA_CAP2, field APST[2] (RO)
 *
 * Automatic Partial to Slumber Transitions. SATA block supports automatic Partial to Slumber
 * transitions.
 */

#define BP_SATA_CAP2_APST      (2)      //!< Bit position for SATA_CAP2_APST.
#define BM_SATA_CAP2_APST      (0x00000004)  //!< Bit mask for SATA_CAP2_APST.

//! @brief Get value of SATA_CAP2_APST from a register value.
#define BG_SATA_CAP2_APST(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_CAP2_APST) >> BP_SATA_CAP2_APST)

//-------------------------------------------------------------------------------------------
// HW_SATA_BISTAFR - BIST Activate FIS Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_BISTAFR - BIST Activate FIS Register (RO)
 *
 * Reset value: 0x00000000
 *
 * This register contains the pattern definition (bits [23:16] of the first DWORD) and data pattern
 * (bits [7:0] of the second DWORD) fields of the received BIST Activate FIS. These fields define
 * the SATA block loopback responder mode requested by the device. It is updated every time a new
 * BIST Activate FIS is received from the device. Reset on Global or Port reset.
 */
typedef union _hw_sata_bistafr
{
    reg32_t U;
    struct _hw_sata_bistafr_bitfields
    {
        unsigned PD : 8; //!< [7:0] Pattern Definition Indicates the pattern definition field of the received BIST Activate FIS - bits [23:16] of the first DWORD. It is used to put the SATA block in one of the following BIST modes: For far-end transmit only modes SATA_BISTAFR[NCP] field contains the required data pattern.
        unsigned NCP : 8; //!< [15:8] Least significant byte of the received BIST Activate FIS second DWORD (bits [7:0]). This value defines the required pattern for far-end transmit only mode (SATA_BISTAFR[PD]=0x80 or 0xA0): When none of these values is decoded, the simultaneous switching pattern is transmitted by default.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved.
    } B;
} hw_sata_bistafr_t;
#endif

/*
 * constants & macros for entire SATA_BISTAFR register
 */
#define HW_SATA_BISTAFR_ADDR      (REGS_SATA_BASE + 0xa0)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_BISTAFR           (*(volatile hw_sata_bistafr_t *) HW_SATA_BISTAFR_ADDR)
#define HW_SATA_BISTAFR_RD()      (HW_SATA_BISTAFR.U)
#endif

/*
 * constants & macros for individual SATA_BISTAFR bitfields
 */

/* --- Register HW_SATA_BISTAFR, field PD[7:0] (RO)
 *
 * Pattern Definition Indicates the pattern definition field of the received BIST Activate FIS -
 * bits [23:16] of the first DWORD. It is used to put the SATA block in one of the following BIST
 * modes: For far-end transmit only modes SATA_BISTAFR[NCP] field contains the required data
 * pattern.
 *
 * Values:
 * 0x08 - Far-end analog (when PHY supports this mode)
 * 0x10 - Far-end retimed
 * 0x80 - Far-end transmit only
 * 0xA0 - Far-end transmit only with scrambler bypassed
 * All other values - should not be used by the device, otherwise, the FIS is negatively acknowledged with R_ERRp.
 */

#define BP_SATA_BISTAFR_PD      (0)      //!< Bit position for SATA_BISTAFR_PD.
#define BM_SATA_BISTAFR_PD      (0x000000ff)  //!< Bit mask for SATA_BISTAFR_PD.

//! @brief Get value of SATA_BISTAFR_PD from a register value.
#define BG_SATA_BISTAFR_PD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_BISTAFR_PD) >> BP_SATA_BISTAFR_PD)


/* --- Register HW_SATA_BISTAFR, field NCP[15:8] (RO)
 *
 * Least significant byte of the received BIST Activate FIS second DWORD (bits [7:0]). This value
 * defines the required pattern for far-end transmit only mode (SATA_BISTAFR[PD]=0x80 or 0xA0): When
 * none of these values is decoded, the simultaneous switching pattern is transmitted by default.
 *
 * Values:
 * 0x4A - High frequency test pattern (HFTP)
 * 0x78 - Mid frequency test pattern (MFTP)
 * 0x7E - Low frequency test pattern (LFTP)
 * 0x7F - Simultaneous switching outputs pattern (SSOP)
 * 0x8B - Lone Bit pattern (LBP)
 * 0xAB - Low frequency spectral component pattern (LFSCP)
 * 0xB5 - High transition density pattern (HTDP)
 * 0xF1 - Low transition density pattern (LTDP)
 */

#define BP_SATA_BISTAFR_NCP      (8)      //!< Bit position for SATA_BISTAFR_NCP.
#define BM_SATA_BISTAFR_NCP      (0x0000ff00)  //!< Bit mask for SATA_BISTAFR_NCP.

//! @brief Get value of SATA_BISTAFR_NCP from a register value.
#define BG_SATA_BISTAFR_NCP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_BISTAFR_NCP) >> BP_SATA_BISTAFR_NCP)


//-------------------------------------------------------------------------------------------
// HW_SATA_BISTCR - BIST Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_BISTCR - BIST Control Register (RW)
 *
 * Reset value: 0x00000700
 *
 * This register is used in BIST initiator modes. It is loaded by the host software prior to sending
 * BIST Activate FIS to the device (via TXBISTPD write). It is reset on a Global or Port reset.
 */
typedef union _hw_sata_bistcr
{
    reg32_t U;
    struct _hw_sata_bistcr_bitfields
    {
        unsigned PATTERN : 4; //!< [3:0] This field defines one of the following SATA compliant patterns for far-end retimed/ far-end analog/ near-end analog initiator modes, or non-compliant patterns for transmit-only responder mode when initiated by the software writing to the SATA_BISTCR[TXO] bit. If the value is none of the listed below, Composite pattern (COMP) is transmitted by default.
        unsigned PV : 1; //!< [4] Pattern Version This bit is used to select either short or long version of the SSOP, HTDP, LTDP, LFSCP, COMP patterns. The options for this field are:
        unsigned FLIP : 1; //!< [5] Flip Disparity This bit is used to change disparity of the current test pattern to the opposite every time its state is changed by the software.
        unsigned ERREN : 1; //!< [6] Error Enable. This bit is used to allow or filter (disable) [ internal errors outside the FIS boundary to set corresponding SATA_P # 0 SERR bits. The options for this field are:
        unsigned RESERVED0 : 1; //!< [7] Reserved.
        unsigned LLC : 3; //!< [10:8] Link Layer Control This field controls the Port Link Layer functions: scrambler, descrambler, and repeat primitive drop. Note the different meanings for normal and BIST modes of operation: • Bit8-SCRAM The options for this field are: 0 Scrambler disabled in normal mode, enabled in BIST mode 1 Scrambler enabled in normal mode, disabled in BIST mode • Bit9-DESCRAM The options for this field are: 0 Descrambler disabled in normal mode, enabled in BIST mode 1 Descrambler enabled in normal mode, disabled in BIST mode • Bit10-RPD The options for this field are: 0 Repeat primitive drop function disabled in normal mode, NA in BIST mode. 1 Repeat primitive drop function enabled in normal mode, NA in BIST mode. The SCRAM bit is cleared (enabled) by the Port when the Port enters a responder far-end transmit BIST mode with scrambling enabled (SATA_BISTAFR[PD]=0x80). In normal mode, the functions scrambler, descrambler, or RPD can be changed only during Port reset (SATA_P # 0 SCTL[DET]=0x1)
        unsigned RESERVED1 : 1; //!< [11] Reserved.
        unsigned SDFE : 1; //!< [12] Signal Detect Feature Enable Reset: PHY_INTERFACE_TYPE 1: Link layer feature to handle unstable/absent phy_sig_det signal is enabled 0: Link layer feature to handle unstable/absent phy_sig_det signal is disabled. This bit is set on power-up or asynchronous reset if PHY_INTERFACE_TYPE = Synopsys_SATA_II (1) or PHY_INTERFACE_TYPE = Synopsys_SATA_6G (2), otherwise, the bit is cleared until it is set via programming. It is not affected by a Global reset or COMRESET. For special handling in systems where phy_sig_det may not be present or stable after OOB signalling and during normal operation , see . For these systems, phy_rx_data_vld must not be tied high and must go low when no data is detected on the wires.
        unsigned RESERVED2 : 1; //!< [13] Reserved.
        unsigned QPHYINIT : 1; //!< [14] When set, this bit enables quick PHY initialization feature. The Link does not require any ALIGNs to transition from OOB to normal operation. For more details, see This bit is available only when TX_OOB_MODE = Exclude (0) and ALIGN_MODE = Aligned (1), otherwise it is reserved.
        unsigned RESERVED3 : 1; //!< [15] Reserved.
        unsigned NEALB : 1; //!< [16] Near-End Analog Loopback This mode should be initiated either in the PARTIAL or SLUMBER power mode, or with the device disconnected from the Port PHY (Link NOCOMM state). BIST Activate FIS is not sent to the device in this mode. This bit places the Port PHY into near-end analog loopback mode. This field is one-shot type and reads returns 0:
        unsigned CNTCLR : 1; //!< [17] Counter Clear This bit clears BIST error count registers. This field is one-shot type and reads returns 0.
        unsigned TXO : 1; //!< [18] Transmit Only. This bit is used to initiate transmission of one of the non-compliant patterns defined by the SATA_BISTCR[PATTERN] value when the device is disconnected.
        unsigned RESERVED4 : 1; //!< [19] Reserved.
        unsigned FERLB : 1; //!< [20] Far-end Retimed Loopback. When set, this bit is used to put the SATA block Link into Far-end Retimed mode, without the BIST Activate FIS, regardless whether the device is connected or disconnected (Link in NOCOMM state). This field is one-shot type and reads returns 0.
        unsigned RESERVED5 : 11; //!< [31:21] Reserved.
    } B;
} hw_sata_bistcr_t;
#endif

/*
 * constants & macros for entire SATA_BISTCR register
 */
#define HW_SATA_BISTCR_ADDR      (REGS_SATA_BASE + 0xa4)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_BISTCR           (*(volatile hw_sata_bistcr_t *) HW_SATA_BISTCR_ADDR)
#define HW_SATA_BISTCR_RD()      (HW_SATA_BISTCR.U)
#define HW_SATA_BISTCR_WR(v)     (HW_SATA_BISTCR.U = (v))
#define HW_SATA_BISTCR_SET(v)    (HW_SATA_BISTCR_WR(HW_SATA_BISTCR_RD() |  (v)))
#define HW_SATA_BISTCR_CLR(v)    (HW_SATA_BISTCR_WR(HW_SATA_BISTCR_RD() & ~(v)))
#define HW_SATA_BISTCR_TOG(v)    (HW_SATA_BISTCR_WR(HW_SATA_BISTCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_BISTCR bitfields
 */

/* --- Register HW_SATA_BISTCR, field PATTERN[3:0] (RW)
 *
 * This field defines one of the following SATA compliant patterns for far-end retimed/ far-end
 * analog/ near-end analog initiator modes, or non-compliant patterns for transmit-only responder
 * mode when initiated by the software writing to the SATA_BISTCR[TXO] bit. If the value is none of
 * the listed below, Composite pattern (COMP) is transmitted by default.
 *
 * Values:
 * 0000b - Simultaneous switching outputs pattern (SSOP)
 * 0001b - High transition density pattern (HTDP)
 * 0010b - Low transition density pattern (LTDP)
 * 0011b - Low frequency spectral component pattern (LFSCP)
 * 0100b - Composite pattern (COMP)
 * 0101b - Lone bit pattern (LBP)
 * 0110b - Mid frequency test pattern (MFTP)
 * 0111b - High frequency test pattern (HFTP)
 * All other values - Reserved and should not be used.
 * 1000b - Low frequency test pattern (LFTP)
 */

#define BP_SATA_BISTCR_PATTERN      (0)      //!< Bit position for SATA_BISTCR_PATTERN.
#define BM_SATA_BISTCR_PATTERN      (0x0000000f)  //!< Bit mask for SATA_BISTCR_PATTERN.

//! @brief Get value of SATA_BISTCR_PATTERN from a register value.
#define BG_SATA_BISTCR_PATTERN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_BISTCR_PATTERN) >> BP_SATA_BISTCR_PATTERN)

//! @brief Format value for bitfield SATA_BISTCR_PATTERN.
#define BF_SATA_BISTCR_PATTERN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_BISTCR_PATTERN) & BM_SATA_BISTCR_PATTERN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PATTERN field to a new value.
#define BW_SATA_BISTCR_PATTERN(v)   (HW_SATA_BISTCR_WR((HW_SATA_BISTCR_RD() & ~BM_SATA_BISTCR_PATTERN) | BF_SATA_BISTCR_PATTERN(v)))
#endif


/* --- Register HW_SATA_BISTCR, field PV[4] (RW)
 *
 * Pattern Version This bit is used to select either short or long version of the SSOP, HTDP, LTDP,
 * LFSCP, COMP patterns. The options for this field are:
 *
 * Values:
 * 0 - Short pattern version
 * 1 - Long pattern version
 */

#define BP_SATA_BISTCR_PV      (4)      //!< Bit position for SATA_BISTCR_PV.
#define BM_SATA_BISTCR_PV      (0x00000010)  //!< Bit mask for SATA_BISTCR_PV.

//! @brief Get value of SATA_BISTCR_PV from a register value.
#define BG_SATA_BISTCR_PV(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_BISTCR_PV) >> BP_SATA_BISTCR_PV)

//! @brief Format value for bitfield SATA_BISTCR_PV.
#define BF_SATA_BISTCR_PV(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_BISTCR_PV) & BM_SATA_BISTCR_PV)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PV field to a new value.
#define BW_SATA_BISTCR_PV(v)   (HW_SATA_BISTCR_WR((HW_SATA_BISTCR_RD() & ~BM_SATA_BISTCR_PV) | BF_SATA_BISTCR_PV(v)))
#endif


/* --- Register HW_SATA_BISTCR, field FLIP[5] (RW)
 *
 * Flip Disparity This bit is used to change disparity of the current test pattern to the opposite
 * every time its state is changed by the software.
 */

#define BP_SATA_BISTCR_FLIP      (5)      //!< Bit position for SATA_BISTCR_FLIP.
#define BM_SATA_BISTCR_FLIP      (0x00000020)  //!< Bit mask for SATA_BISTCR_FLIP.

//! @brief Get value of SATA_BISTCR_FLIP from a register value.
#define BG_SATA_BISTCR_FLIP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_BISTCR_FLIP) >> BP_SATA_BISTCR_FLIP)

//! @brief Format value for bitfield SATA_BISTCR_FLIP.
#define BF_SATA_BISTCR_FLIP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_BISTCR_FLIP) & BM_SATA_BISTCR_FLIP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FLIP field to a new value.
#define BW_SATA_BISTCR_FLIP(v)   (HW_SATA_BISTCR_WR((HW_SATA_BISTCR_RD() & ~BM_SATA_BISTCR_FLIP) | BF_SATA_BISTCR_FLIP(v)))
#endif

/* --- Register HW_SATA_BISTCR, field ERREN[6] (RW)
 *
 * Error Enable. This bit is used to allow or filter (disable) [ internal errors outside the FIS
 * boundary to set corresponding SATA_P # 0 SERR bits. The options for this field are:
 *
 * Values:
 * 0 - Filter errors outside the FIS, allow errors inside the FIS;
 * 1 - Allow errors outside or inside the FIS.
 */

#define BP_SATA_BISTCR_ERREN      (6)      //!< Bit position for SATA_BISTCR_ERREN.
#define BM_SATA_BISTCR_ERREN      (0x00000040)  //!< Bit mask for SATA_BISTCR_ERREN.

//! @brief Get value of SATA_BISTCR_ERREN from a register value.
#define BG_SATA_BISTCR_ERREN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_BISTCR_ERREN) >> BP_SATA_BISTCR_ERREN)

//! @brief Format value for bitfield SATA_BISTCR_ERREN.
#define BF_SATA_BISTCR_ERREN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_BISTCR_ERREN) & BM_SATA_BISTCR_ERREN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ERREN field to a new value.
#define BW_SATA_BISTCR_ERREN(v)   (HW_SATA_BISTCR_WR((HW_SATA_BISTCR_RD() & ~BM_SATA_BISTCR_ERREN) | BF_SATA_BISTCR_ERREN(v)))
#endif


/* --- Register HW_SATA_BISTCR, field LLC[10:8] (RW)
 *
 * Link Layer Control This field controls the Port Link Layer functions: scrambler, descrambler, and
 * repeat primitive drop. Note the different meanings for normal and BIST modes of operation: •
 * Bit8-SCRAM The options for this field are: 0 Scrambler disabled in normal mode, enabled in BIST
 * mode 1 Scrambler enabled in normal mode, disabled in BIST mode • Bit9-DESCRAM The options for
 * this field are: 0 Descrambler disabled in normal mode, enabled in BIST mode 1 Descrambler enabled
 * in normal mode, disabled in BIST mode • Bit10-RPD The options for this field are: 0 Repeat
 * primitive drop function disabled in normal mode, NA in BIST mode. 1 Repeat primitive drop
 * function enabled in normal mode, NA in BIST mode. The SCRAM bit is cleared (enabled) by the Port
 * when the Port enters a responder far-end transmit BIST mode with scrambling enabled
 * (SATA_BISTAFR[PD]=0x80). In normal mode, the functions scrambler, descrambler, or RPD can be
 * changed only during Port reset (SATA_P # 0 SCTL[DET]=0x1)
 */

#define BP_SATA_BISTCR_LLC      (8)      //!< Bit position for SATA_BISTCR_LLC.
#define BM_SATA_BISTCR_LLC      (0x00000700)  //!< Bit mask for SATA_BISTCR_LLC.

//! @brief Get value of SATA_BISTCR_LLC from a register value.
#define BG_SATA_BISTCR_LLC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_BISTCR_LLC) >> BP_SATA_BISTCR_LLC)

//! @brief Format value for bitfield SATA_BISTCR_LLC.
#define BF_SATA_BISTCR_LLC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_BISTCR_LLC) & BM_SATA_BISTCR_LLC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LLC field to a new value.
#define BW_SATA_BISTCR_LLC(v)   (HW_SATA_BISTCR_WR((HW_SATA_BISTCR_RD() & ~BM_SATA_BISTCR_LLC) | BF_SATA_BISTCR_LLC(v)))
#endif

/* --- Register HW_SATA_BISTCR, field SDFE[12] (RW)
 *
 * Signal Detect Feature Enable Reset: PHY_INTERFACE_TYPE 1: Link layer feature to handle
 * unstable/absent phy_sig_det signal is enabled 0: Link layer feature to handle unstable/absent
 * phy_sig_det signal is disabled. This bit is set on power-up or asynchronous reset if
 * PHY_INTERFACE_TYPE = Synopsys_SATA_II (1) or PHY_INTERFACE_TYPE = Synopsys_SATA_6G (2),
 * otherwise, the bit is cleared until it is set via programming. It is not affected by a Global
 * reset or COMRESET. For special handling in systems where phy_sig_det may not be present or stable
 * after OOB signalling and during normal operation , see . For these systems, phy_rx_data_vld must
 * not be tied high and must go low when no data is detected on the wires.
 */

#define BP_SATA_BISTCR_SDFE      (12)      //!< Bit position for SATA_BISTCR_SDFE.
#define BM_SATA_BISTCR_SDFE      (0x00001000)  //!< Bit mask for SATA_BISTCR_SDFE.

//! @brief Get value of SATA_BISTCR_SDFE from a register value.
#define BG_SATA_BISTCR_SDFE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_BISTCR_SDFE) >> BP_SATA_BISTCR_SDFE)

//! @brief Format value for bitfield SATA_BISTCR_SDFE.
#define BF_SATA_BISTCR_SDFE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_BISTCR_SDFE) & BM_SATA_BISTCR_SDFE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SDFE field to a new value.
#define BW_SATA_BISTCR_SDFE(v)   (HW_SATA_BISTCR_WR((HW_SATA_BISTCR_RD() & ~BM_SATA_BISTCR_SDFE) | BF_SATA_BISTCR_SDFE(v)))
#endif

/* --- Register HW_SATA_BISTCR, field QPHYINIT[14] (RW)
 *
 * When set, this bit enables quick PHY initialization feature. The Link does not require any ALIGNs
 * to transition from OOB to normal operation. For more details, see This bit is available only when
 * TX_OOB_MODE = Exclude (0) and ALIGN_MODE = Aligned (1), otherwise it is reserved.
 */

#define BP_SATA_BISTCR_QPHYINIT      (14)      //!< Bit position for SATA_BISTCR_QPHYINIT.
#define BM_SATA_BISTCR_QPHYINIT      (0x00004000)  //!< Bit mask for SATA_BISTCR_QPHYINIT.

//! @brief Get value of SATA_BISTCR_QPHYINIT from a register value.
#define BG_SATA_BISTCR_QPHYINIT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_BISTCR_QPHYINIT) >> BP_SATA_BISTCR_QPHYINIT)

//! @brief Format value for bitfield SATA_BISTCR_QPHYINIT.
#define BF_SATA_BISTCR_QPHYINIT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_BISTCR_QPHYINIT) & BM_SATA_BISTCR_QPHYINIT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the QPHYINIT field to a new value.
#define BW_SATA_BISTCR_QPHYINIT(v)   (HW_SATA_BISTCR_WR((HW_SATA_BISTCR_RD() & ~BM_SATA_BISTCR_QPHYINIT) | BF_SATA_BISTCR_QPHYINIT(v)))
#endif

/* --- Register HW_SATA_BISTCR, field NEALB[16] (WO)
 *
 * Near-End Analog Loopback This mode should be initiated either in the PARTIAL or SLUMBER power
 * mode, or with the device disconnected from the Port PHY (Link NOCOMM state). BIST Activate FIS is
 * not sent to the device in this mode. This bit places the Port PHY into near-end analog loopback
 * mode. This field is one-shot type and reads returns 0:
 *
 * Values:
 * 1 - Near-end analog loopback request. SATA_BISTCR[PATTERN] field contains the appropriate pattern.
 */

#define BP_SATA_BISTCR_NEALB      (16)      //!< Bit position for SATA_BISTCR_NEALB.
#define BM_SATA_BISTCR_NEALB      (0x00010000)  //!< Bit mask for SATA_BISTCR_NEALB.

//! @brief Get value of SATA_BISTCR_NEALB from a register value.
#define BG_SATA_BISTCR_NEALB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_BISTCR_NEALB) >> BP_SATA_BISTCR_NEALB)

//! @brief Format value for bitfield SATA_BISTCR_NEALB.
#define BF_SATA_BISTCR_NEALB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_BISTCR_NEALB) & BM_SATA_BISTCR_NEALB)


/* --- Register HW_SATA_BISTCR, field CNTCLR[17] (WO)
 *
 * Counter Clear This bit clears BIST error count registers. This field is one-shot type and reads
 * returns 0.
 *
 * Values:
 * 1 - Clear SATA_BISTFCTR, and SATA_BISTSR , and SATA_BISTDECR registers.
 */

#define BP_SATA_BISTCR_CNTCLR      (17)      //!< Bit position for SATA_BISTCR_CNTCLR.
#define BM_SATA_BISTCR_CNTCLR      (0x00020000)  //!< Bit mask for SATA_BISTCR_CNTCLR.

//! @brief Get value of SATA_BISTCR_CNTCLR from a register value.
#define BG_SATA_BISTCR_CNTCLR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_BISTCR_CNTCLR) >> BP_SATA_BISTCR_CNTCLR)

//! @brief Format value for bitfield SATA_BISTCR_CNTCLR.
#define BF_SATA_BISTCR_CNTCLR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_BISTCR_CNTCLR) & BM_SATA_BISTCR_CNTCLR)


/* --- Register HW_SATA_BISTCR, field TXO[18] (RW)
 *
 * Transmit Only. This bit is used to initiate transmission of one of the non-compliant patterns
 * defined by the SATA_BISTCR[PATTERN] value when the device is disconnected.
 */

#define BP_SATA_BISTCR_TXO      (18)      //!< Bit position for SATA_BISTCR_TXO.
#define BM_SATA_BISTCR_TXO      (0x00040000)  //!< Bit mask for SATA_BISTCR_TXO.

//! @brief Get value of SATA_BISTCR_TXO from a register value.
#define BG_SATA_BISTCR_TXO(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_BISTCR_TXO) >> BP_SATA_BISTCR_TXO)

//! @brief Format value for bitfield SATA_BISTCR_TXO.
#define BF_SATA_BISTCR_TXO(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_BISTCR_TXO) & BM_SATA_BISTCR_TXO)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXO field to a new value.
#define BW_SATA_BISTCR_TXO(v)   (HW_SATA_BISTCR_WR((HW_SATA_BISTCR_RD() & ~BM_SATA_BISTCR_TXO) | BF_SATA_BISTCR_TXO(v)))
#endif

/* --- Register HW_SATA_BISTCR, field FERLB[20] (WO)
 *
 * Far-end Retimed Loopback. When set, this bit is used to put the SATA block Link into Far-end
 * Retimed mode, without the BIST Activate FIS, regardless whether the device is connected or
 * disconnected (Link in NOCOMM state). This field is one-shot type and reads returns 0.
 */

#define BP_SATA_BISTCR_FERLB      (20)      //!< Bit position for SATA_BISTCR_FERLB.
#define BM_SATA_BISTCR_FERLB      (0x00100000)  //!< Bit mask for SATA_BISTCR_FERLB.

//! @brief Get value of SATA_BISTCR_FERLB from a register value.
#define BG_SATA_BISTCR_FERLB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_BISTCR_FERLB) >> BP_SATA_BISTCR_FERLB)

//! @brief Format value for bitfield SATA_BISTCR_FERLB.
#define BF_SATA_BISTCR_FERLB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_BISTCR_FERLB) & BM_SATA_BISTCR_FERLB)

//-------------------------------------------------------------------------------------------
// HW_SATA_BISTFCTR - BIST FIS Count Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_BISTFCTR - BIST FIS Count Register (RO)
 *
 * Reset value: 0x00000000
 *
 * This register contains the received BIST FIS count in the loopback initiator far-end retimed,
 * far-end analog and near-end analog modes. It is updated each time a new BIST FIS is received. It
 * is reset by Global reset, Port reset (COMRESET) or by setting the SATA_BISTCR[CNTCLR] bit. This
 * register does not roll over and freezes when the FFFF_FFFFh value is reached. It takes
 * approximately 65 hours of continuous BIST operation to reach this value.
 */
typedef union _hw_sata_bistfctr
{
    reg32_t U;
    struct _hw_sata_bistfctr_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Received BIST FIS Count
    } B;
} hw_sata_bistfctr_t;
#endif

/*
 * constants & macros for entire SATA_BISTFCTR register
 */
#define HW_SATA_BISTFCTR_ADDR      (REGS_SATA_BASE + 0xa8)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_BISTFCTR           (*(volatile hw_sata_bistfctr_t *) HW_SATA_BISTFCTR_ADDR)
#define HW_SATA_BISTFCTR_RD()      (HW_SATA_BISTFCTR.U)
#endif

/*
 * constants & macros for individual SATA_BISTFCTR bitfields
 */

//-------------------------------------------------------------------------------------------
// HW_SATA_BISTSR - BIST Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_BISTSR - BIST Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * This register contains errors detected in the received BIST FIS in the loopback initiator far-end
 * retimed, far- end analog and near-end analog modes. It is updated each time a new BIST FIS is
 * received. It is reset by Global reset, Port reset (COMRESET) or by setting the
 * SATA_BISTCR[CNTCLR] bit.
 */
typedef union _hw_sata_bistsr
{
    reg32_t U;
    struct _hw_sata_bistsr_bitfields
    {
        unsigned FRAMERR : 16; //!< [15:0] Frame Error. This field contains the frame error count. It is accumulated (new value is added to the old value) each time a new BIST frame with a CRC error is received. The FRAMERR value does not roll over and freezes at FFFFh.
        unsigned BRSTERR : 8; //!< [23:16] Burst Error. This field contains the burst error count. It is accumulated each time a burst error condition is detected: DWORD error is detected in the received frame and 1.5 seconds (27,000 frames) passed since the previous burst error was detected. The BRSTERR value does not roll over and freezes at FFh. This field is updated when parameter (Macro configuration parm) BIST_MODE=DWORD.
        unsigned RESERVED0 : 8; //!< [31:24] Reserved.
    } B;
} hw_sata_bistsr_t;
#endif

/*
 * constants & macros for entire SATA_BISTSR register
 */
#define HW_SATA_BISTSR_ADDR      (REGS_SATA_BASE + 0xac)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_BISTSR           (*(volatile hw_sata_bistsr_t *) HW_SATA_BISTSR_ADDR)
#define HW_SATA_BISTSR_RD()      (HW_SATA_BISTSR.U)
#endif

/*
 * constants & macros for individual SATA_BISTSR bitfields
 */

/* --- Register HW_SATA_BISTSR, field FRAMERR[15:0] (RO)
 *
 * Frame Error. This field contains the frame error count. It is accumulated (new value is added to
 * the old value) each time a new BIST frame with a CRC error is received. The FRAMERR value does
 * not roll over and freezes at FFFFh.
 */

#define BP_SATA_BISTSR_FRAMERR      (0)      //!< Bit position for SATA_BISTSR_FRAMERR.
#define BM_SATA_BISTSR_FRAMERR      (0x0000ffff)  //!< Bit mask for SATA_BISTSR_FRAMERR.

//! @brief Get value of SATA_BISTSR_FRAMERR from a register value.
#define BG_SATA_BISTSR_FRAMERR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_BISTSR_FRAMERR) >> BP_SATA_BISTSR_FRAMERR)

/* --- Register HW_SATA_BISTSR, field BRSTERR[23:16] (RO)
 *
 * Burst Error. This field contains the burst error count. It is accumulated each time a burst error
 * condition is detected: DWORD error is detected in the received frame and 1.5 seconds (27,000
 * frames) passed since the previous burst error was detected. The BRSTERR value does not roll over
 * and freezes at FFh. This field is updated when parameter (Macro configuration parm)
 * BIST_MODE=DWORD.
 */

#define BP_SATA_BISTSR_BRSTERR      (16)      //!< Bit position for SATA_BISTSR_BRSTERR.
#define BM_SATA_BISTSR_BRSTERR      (0x00ff0000)  //!< Bit mask for SATA_BISTSR_BRSTERR.

//! @brief Get value of SATA_BISTSR_BRSTERR from a register value.
#define BG_SATA_BISTSR_BRSTERR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_BISTSR_BRSTERR) >> BP_SATA_BISTSR_BRSTERR)

//-------------------------------------------------------------------------------------------
// HW_SATA_OOBR - OOB Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_OOBR - OOB Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register controls the Link layer OOB detection counters. The default values, MIN_COMWAKE,
 * MAX_COMWAKE, MIN_COMINIT and MAX_COMINIT are calculated based on the RXOOB_CLK  RXOOB_CLK_FREQ
 * parameter and loaded on power-up or asynchronous SATA block reset.   The resulting default OOB
 * spacing ranges are shown in Table 3-1. To change these ranges, the new values must be
 * recalculated based on formulas in and and loaded into the link as follows:    Set SATA_OOBR bit
 * 31 to enable other SATA_OOBR fields  Write new values to the corresponding SATA_OOBR fields
 * Generate PORT Reset (COMRESET)   Dependencies: Present only when RXOOB_CLK_MODE==Include
 */
typedef union _hw_sata_oobr
{
    reg32_t U;
    struct _hw_sata_oobr_bitfields
    {
        unsigned CIMAX : 8; //!< [7:0] COMINIT Maximum Value This field is RW when WE=1 and RO when WE=0.
        unsigned CIMIN : 8; //!< [15:8] COMINIT Minimum Value This field is RW when WE=1 and RO when WE=0.
        unsigned CWMAX : 8; //!< [23:16] COMWAKE Maximum Value This field is RW when WE=1 and RO when WE=0.
        unsigned CWMIN : 7; //!< [30:24] COMWAKE Minimum Value This field is RW when WE=1 and RO when WE=0.
        unsigned WE : 1; //!< [31] Write Enable This bit is cleared when COMRESET is detected. The options for this field are:
    } B;
} hw_sata_oobr_t;
#endif

/*
 * constants & macros for entire SATA_OOBR register
 */
#define HW_SATA_OOBR_ADDR      (REGS_SATA_BASE + 0xbc)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_OOBR           (*(volatile hw_sata_oobr_t *) HW_SATA_OOBR_ADDR)
#define HW_SATA_OOBR_RD()      (HW_SATA_OOBR.U)
#define HW_SATA_OOBR_WR(v)     (HW_SATA_OOBR.U = (v))
#define HW_SATA_OOBR_SET(v)    (HW_SATA_OOBR_WR(HW_SATA_OOBR_RD() |  (v)))
#define HW_SATA_OOBR_CLR(v)    (HW_SATA_OOBR_WR(HW_SATA_OOBR_RD() & ~(v)))
#define HW_SATA_OOBR_TOG(v)    (HW_SATA_OOBR_WR(HW_SATA_OOBR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_OOBR bitfields
 */

/* --- Register HW_SATA_OOBR, field CIMAX[7:0] (RW)
 *
 * COMINIT Maximum Value This field is RW when WE=1 and RO when WE=0.
 */

#define BP_SATA_OOBR_CIMAX      (0)      //!< Bit position for SATA_OOBR_CIMAX.
#define BM_SATA_OOBR_CIMAX      (0x000000ff)  //!< Bit mask for SATA_OOBR_CIMAX.

//! @brief Get value of SATA_OOBR_CIMAX from a register value.
#define BG_SATA_OOBR_CIMAX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_OOBR_CIMAX) >> BP_SATA_OOBR_CIMAX)

//! @brief Format value for bitfield SATA_OOBR_CIMAX.
#define BF_SATA_OOBR_CIMAX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_OOBR_CIMAX) & BM_SATA_OOBR_CIMAX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CIMAX field to a new value.
#define BW_SATA_OOBR_CIMAX(v)   (HW_SATA_OOBR_WR((HW_SATA_OOBR_RD() & ~BM_SATA_OOBR_CIMAX) | BF_SATA_OOBR_CIMAX(v)))
#endif

/* --- Register HW_SATA_OOBR, field CIMIN[15:8] (RW)
 *
 * COMINIT Minimum Value This field is RW when WE=1 and RO when WE=0.
 */

#define BP_SATA_OOBR_CIMIN      (8)      //!< Bit position for SATA_OOBR_CIMIN.
#define BM_SATA_OOBR_CIMIN      (0x0000ff00)  //!< Bit mask for SATA_OOBR_CIMIN.

//! @brief Get value of SATA_OOBR_CIMIN from a register value.
#define BG_SATA_OOBR_CIMIN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_OOBR_CIMIN) >> BP_SATA_OOBR_CIMIN)

//! @brief Format value for bitfield SATA_OOBR_CIMIN.
#define BF_SATA_OOBR_CIMIN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_OOBR_CIMIN) & BM_SATA_OOBR_CIMIN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CIMIN field to a new value.
#define BW_SATA_OOBR_CIMIN(v)   (HW_SATA_OOBR_WR((HW_SATA_OOBR_RD() & ~BM_SATA_OOBR_CIMIN) | BF_SATA_OOBR_CIMIN(v)))
#endif

/* --- Register HW_SATA_OOBR, field CWMAX[23:16] (RW)
 *
 * COMWAKE Maximum Value This field is RW when WE=1 and RO when WE=0.
 */

#define BP_SATA_OOBR_CWMAX      (16)      //!< Bit position for SATA_OOBR_CWMAX.
#define BM_SATA_OOBR_CWMAX      (0x00ff0000)  //!< Bit mask for SATA_OOBR_CWMAX.

//! @brief Get value of SATA_OOBR_CWMAX from a register value.
#define BG_SATA_OOBR_CWMAX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_OOBR_CWMAX) >> BP_SATA_OOBR_CWMAX)

//! @brief Format value for bitfield SATA_OOBR_CWMAX.
#define BF_SATA_OOBR_CWMAX(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_OOBR_CWMAX) & BM_SATA_OOBR_CWMAX)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CWMAX field to a new value.
#define BW_SATA_OOBR_CWMAX(v)   (HW_SATA_OOBR_WR((HW_SATA_OOBR_RD() & ~BM_SATA_OOBR_CWMAX) | BF_SATA_OOBR_CWMAX(v)))
#endif

/* --- Register HW_SATA_OOBR, field CWMIN[30:24] (RW)
 *
 * COMWAKE Minimum Value This field is RW when WE=1 and RO when WE=0.
 */

#define BP_SATA_OOBR_CWMIN      (24)      //!< Bit position for SATA_OOBR_CWMIN.
#define BM_SATA_OOBR_CWMIN      (0x7f000000)  //!< Bit mask for SATA_OOBR_CWMIN.

//! @brief Get value of SATA_OOBR_CWMIN from a register value.
#define BG_SATA_OOBR_CWMIN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_OOBR_CWMIN) >> BP_SATA_OOBR_CWMIN)

//! @brief Format value for bitfield SATA_OOBR_CWMIN.
#define BF_SATA_OOBR_CWMIN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_OOBR_CWMIN) & BM_SATA_OOBR_CWMIN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CWMIN field to a new value.
#define BW_SATA_OOBR_CWMIN(v)   (HW_SATA_OOBR_WR((HW_SATA_OOBR_RD() & ~BM_SATA_OOBR_CWMIN) | BF_SATA_OOBR_CWMIN(v)))
#endif

/* --- Register HW_SATA_OOBR, field WE[31] (RW)
 *
 * Write Enable This bit is cleared when COMRESET is detected. The options for this field are:
 *
 * Values:
 * 0 - SATA_OOBR bits [30:0] are read-only
 * 1 - SATA_OOBR bits [30:0] can be written
 */

#define BP_SATA_OOBR_WE      (31)      //!< Bit position for SATA_OOBR_WE.
#define BM_SATA_OOBR_WE      (0x80000000)  //!< Bit mask for SATA_OOBR_WE.

//! @brief Get value of SATA_OOBR_WE from a register value.
#define BG_SATA_OOBR_WE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_OOBR_WE) >> BP_SATA_OOBR_WE)

//! @brief Format value for bitfield SATA_OOBR_WE.
#define BF_SATA_OOBR_WE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_OOBR_WE) & BM_SATA_OOBR_WE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WE field to a new value.
#define BW_SATA_OOBR_WE(v)   (HW_SATA_OOBR_WR((HW_SATA_OOBR_RD() & ~BM_SATA_OOBR_WE) | BF_SATA_OOBR_WE(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_SATA_GPCR - General Purpose Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_GPCR - General Purpose Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This 32-bit register is used for general purpose control. This register only exists when GP_CTRL
 * parameter is set to “Include” otherwise this location is reserved.  The bits of this register are
 * connected to the corresponding bits of the gp_ctrl output. Resets on power-up (system reset) only
 * to the GP_CTRL_DEF value.
 */
typedef union _hw_sata_gpcr
{
    reg32_t U;
    struct _hw_sata_gpcr_bitfields
    {
        unsigned GP_CONTROL : 32; //!< [31:0] General Purpose Control. Present only when GP_CTRL=Include(1). Reset Value: Configurable parameter GP_CTRL_DEF
    } B;
} hw_sata_gpcr_t;
#endif

/*
 * constants & macros for entire SATA_GPCR register
 */
#define HW_SATA_GPCR_ADDR      (REGS_SATA_BASE + 0xd0)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_GPCR           (*(volatile hw_sata_gpcr_t *) HW_SATA_GPCR_ADDR)
#define HW_SATA_GPCR_RD()      (HW_SATA_GPCR.U)
#define HW_SATA_GPCR_WR(v)     (HW_SATA_GPCR.U = (v))
#define HW_SATA_GPCR_SET(v)    (HW_SATA_GPCR_WR(HW_SATA_GPCR_RD() |  (v)))
#define HW_SATA_GPCR_CLR(v)    (HW_SATA_GPCR_WR(HW_SATA_GPCR_RD() & ~(v)))
#define HW_SATA_GPCR_TOG(v)    (HW_SATA_GPCR_WR(HW_SATA_GPCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_GPCR bitfields
 */

/* --- Register HW_SATA_GPCR, field GP_CONTROL[31:0] (RW)
 *
 * General Purpose Control. Present only when GP_CTRL=Include(1). Reset Value: Configurable
 * parameter GP_CTRL_DEF
 */

#define BP_SATA_GPCR_GP_CONTROL      (0)      //!< Bit position for SATA_GPCR_GP_CONTROL.
#define BM_SATA_GPCR_GP_CONTROL      (0xffffffff)  //!< Bit mask for SATA_GPCR_GP_CONTROL.

//! @brief Get value of SATA_GPCR_GP_CONTROL from a register value.
#define BG_SATA_GPCR_GP_CONTROL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPCR_GP_CONTROL) >> BP_SATA_GPCR_GP_CONTROL)

//! @brief Format value for bitfield SATA_GPCR_GP_CONTROL.
#define BF_SATA_GPCR_GP_CONTROL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_GPCR_GP_CONTROL) & BM_SATA_GPCR_GP_CONTROL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the GP_CONTROL field to a new value.
#define BW_SATA_GPCR_GP_CONTROL(v)   (HW_SATA_GPCR_WR((HW_SATA_GPCR_RD() & ~BM_SATA_GPCR_GP_CONTROL) | BF_SATA_GPCR_GP_CONTROL(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_SATA_GPSR - General Purpose Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_GPSR - General Purpose Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This 32-bit register is used to monitor the general purpose status. This register only exists
 * when GP_STAT parameter is set to “Include”, otherwise, this location is reserved.  The bits of
 * this register reflect the state of the corresponding bits of the gp_status input. Signals
 * connected to the gp_status input can be asynchronous to any of the DWC_ahsata clocks, however
 * they must not change faster than five hclk/aclk periods, otherwise the GPSR register may never be
 * updated with the intermediate changing values.
 */
typedef union _hw_sata_gpsr
{
    reg32_t U;
    struct _hw_sata_gpsr_bitfields
    {
        unsigned GP_STATUS : 32; //!< [31:0] General Purpose Status. Present only when GP_STAT=Include(1)
    } B;
} hw_sata_gpsr_t;
#endif

/*
 * constants & macros for entire SATA_GPSR register
 */
#define HW_SATA_GPSR_ADDR      (REGS_SATA_BASE + 0xd4)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_GPSR           (*(volatile hw_sata_gpsr_t *) HW_SATA_GPSR_ADDR)
#define HW_SATA_GPSR_RD()      (HW_SATA_GPSR.U)
#define HW_SATA_GPSR_WR(v)     (HW_SATA_GPSR.U = (v))
#define HW_SATA_GPSR_SET(v)    (HW_SATA_GPSR_WR(HW_SATA_GPSR_RD() |  (v)))
#define HW_SATA_GPSR_CLR(v)    (HW_SATA_GPSR_WR(HW_SATA_GPSR_RD() & ~(v)))
#define HW_SATA_GPSR_TOG(v)    (HW_SATA_GPSR_WR(HW_SATA_GPSR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_GPSR bitfields
 */

/* --- Register HW_SATA_GPSR, field GP_STATUS[31:0] (RW)
 *
 * General Purpose Status. Present only when GP_STAT=Include(1)
 */

#define BP_SATA_GPSR_GP_STATUS      (0)      //!< Bit position for SATA_GPSR_GP_STATUS.
#define BM_SATA_GPSR_GP_STATUS      (0xffffffff)  //!< Bit mask for SATA_GPSR_GP_STATUS.

//! @brief Get value of SATA_GPSR_GP_STATUS from a register value.
#define BG_SATA_GPSR_GP_STATUS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPSR_GP_STATUS) >> BP_SATA_GPSR_GP_STATUS)

//! @brief Format value for bitfield SATA_GPSR_GP_STATUS.
#define BF_SATA_GPSR_GP_STATUS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_GPSR_GP_STATUS) & BM_SATA_GPSR_GP_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the GP_STATUS field to a new value.
#define BW_SATA_GPSR_GP_STATUS(v)   (HW_SATA_GPSR_WR((HW_SATA_GPSR_RD() & ~BM_SATA_GPSR_GP_STATUS) | BF_SATA_GPSR_GP_STATUS(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_SATA_TIMER1MS - Timer 1-ms Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_TIMER1MS - Timer 1-ms Register (RW)
 *
 * Reset value: 0x000186a0
 *
 * This register is used to generate a 1-ms tick for the command completion coalescing (CCC) logic,
 * based on the AHB bus clock frequency. The Software must initialize this register with the
 * required value after power up before using the CCC feature. This register is reset to 100,000
 * (TIMV value for 100-MHz hclk) on power up and is not affected by Global reset.
 */
typedef union _hw_sata_timer1ms
{
    reg32_t U;
    struct _hw_sata_timer1ms_bitfields
    {
        unsigned TIMV : 20; //!< [19:0] 1ms Timer Value This field contains the following value for the internal timer to generate 1-ms tick: Fhclk*1000 where Fhclk = AHB clock frequency in MHz The options for this field are: • RW when SATA_CCC_CTL[EN]==0 • RO when SATA_CCC_CTL[EN]==1.
        unsigned RESERVED0 : 12; //!< [31:20] Reserved.
    } B;
} hw_sata_timer1ms_t;
#endif

/*
 * constants & macros for entire SATA_TIMER1MS register
 */
#define HW_SATA_TIMER1MS_ADDR      (REGS_SATA_BASE + 0xe0)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_TIMER1MS           (*(volatile hw_sata_timer1ms_t *) HW_SATA_TIMER1MS_ADDR)
#define HW_SATA_TIMER1MS_RD()      (HW_SATA_TIMER1MS.U)
#define HW_SATA_TIMER1MS_WR(v)     (HW_SATA_TIMER1MS.U = (v))
#define HW_SATA_TIMER1MS_SET(v)    (HW_SATA_TIMER1MS_WR(HW_SATA_TIMER1MS_RD() |  (v)))
#define HW_SATA_TIMER1MS_CLR(v)    (HW_SATA_TIMER1MS_WR(HW_SATA_TIMER1MS_RD() & ~(v)))
#define HW_SATA_TIMER1MS_TOG(v)    (HW_SATA_TIMER1MS_WR(HW_SATA_TIMER1MS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_TIMER1MS bitfields
 */

/* --- Register HW_SATA_TIMER1MS, field TIMV[19:0] (RW)
 *
 * 1ms Timer Value This field contains the following value for the internal timer to generate 1-ms
 * tick: Fhclk*1000 where Fhclk = AHB clock frequency in MHz The options for this field are: • RW
 * when SATA_CCC_CTL[EN]==0 • RO when SATA_CCC_CTL[EN]==1.
 */

#define BP_SATA_TIMER1MS_TIMV      (0)      //!< Bit position for SATA_TIMER1MS_TIMV.
#define BM_SATA_TIMER1MS_TIMV      (0x000fffff)  //!< Bit mask for SATA_TIMER1MS_TIMV.

//! @brief Get value of SATA_TIMER1MS_TIMV from a register value.
#define BG_SATA_TIMER1MS_TIMV(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_TIMER1MS_TIMV) >> BP_SATA_TIMER1MS_TIMV)

//! @brief Format value for bitfield SATA_TIMER1MS_TIMV.
#define BF_SATA_TIMER1MS_TIMV(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_TIMER1MS_TIMV) & BM_SATA_TIMER1MS_TIMV)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TIMV field to a new value.
#define BW_SATA_TIMER1MS_TIMV(v)   (HW_SATA_TIMER1MS_WR((HW_SATA_TIMER1MS_RD() & ~BM_SATA_TIMER1MS_TIMV) | BF_SATA_TIMER1MS_TIMV(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_SATA_GPARAM1R - Global Parameter 1 Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_GPARAM1R - Global Parameter 1 Register (RO)
 *
 * Reset value: 0xd8000000
 *
 * This read-only register contains encoded information about the SATA block global configuration
 * parameters' settings.
 */
typedef union _hw_sata_gparam1r
{
    reg32_t U;
    struct _hw_sata_gparam1r_bitfields
    {
        unsigned RESERVED0 : 6; //!< [5:0] Reserved.
        unsigned M_HADDR : 1; //!< [6] AHB Master Address Bus Width This value is derived from the M_HADDR_WIDTH parameter: The options for this field are:
        unsigned S_HADDR : 1; //!< [7] AHB Slave Address Bus Width This value is derived from the S_HADDR_WIDTH parameter: The options for this field are:
        unsigned AHB_ENDIAN : 2; //!< [9:8] AHB Bus Endianness This value is derived from the AHB_ENDIANNESS parameter: The options for this field are:
        unsigned RETURN_ERR : 1; //!< [10] AHB Error Response This value is derived from the RETURN_ERR_RESP parameter: The options for this field are:
        unsigned RESERVED1 : 2; //!< [12:11] Reserved. Returns 1.
        unsigned BIST_M : 1; //!< [13] BIST Loopback Checking Depth This value is derived from the BIST_MODE parameter. The options for this field are:
        unsigned RESERVED2 : 1; //!< [14] Reserved. Returns 0.
        unsigned PHY_STAT : 6; //!< [20:15] PHY Status Width 0x20 (32) PHY Status Width is 32 bits. This value reflects the PHY_STAT_W parameter.
        unsigned PHY_CTRL : 6; //!< [26:21] PHY Control Width 0x20 (32) PHY Control Width is 32 bits. This value reflects the PHY_CTRL_W parameter.
        unsigned PHY_RST : 1; //!< [27] PHY Reset Mode This value is derived from the PHY_RST_MODE parameter. The options for this field are:
        unsigned PHY_DATA : 2; //!< [29:28] PHY Data Width This value is derived from the PHY_DATA_WIDTH parameter: The options for this field are: • 0x0: 1 0x1: PHY DATA WIDTH = 2 • 0x2: 4 Other values are reserved.
        unsigned RX_BUFFER : 1; //!< [30] Rx Data Buffer This value is derived from the RX_BUFFER_MODE parameter:
        unsigned ALIGN_M : 1; //!< [31] Rx Data Alignment This value is derived from the ALIGN_MODE parameter. The options for this field are:
    } B;
} hw_sata_gparam1r_t;
#endif

/*
 * constants & macros for entire SATA_GPARAM1R register
 */
#define HW_SATA_GPARAM1R_ADDR      (REGS_SATA_BASE + 0xe8)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_GPARAM1R           (*(volatile hw_sata_gparam1r_t *) HW_SATA_GPARAM1R_ADDR)
#define HW_SATA_GPARAM1R_RD()      (HW_SATA_GPARAM1R.U)
#endif

/*
 * constants & macros for individual SATA_GPARAM1R bitfields
 */

/* --- Register HW_SATA_GPARAM1R, field M_HADDR[6] (RO)
 *
 * AHB Master Address Bus Width This value is derived from the M_HADDR_WIDTH parameter: The options
 * for this field are:
 *
 * Values:
 * 0 - 32 bits
 */

#define BP_SATA_GPARAM1R_M_HADDR      (6)      //!< Bit position for SATA_GPARAM1R_M_HADDR.
#define BM_SATA_GPARAM1R_M_HADDR      (0x00000040)  //!< Bit mask for SATA_GPARAM1R_M_HADDR.

//! @brief Get value of SATA_GPARAM1R_M_HADDR from a register value.
#define BG_SATA_GPARAM1R_M_HADDR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPARAM1R_M_HADDR) >> BP_SATA_GPARAM1R_M_HADDR)


/* --- Register HW_SATA_GPARAM1R, field S_HADDR[7] (RO)
 *
 * AHB Slave Address Bus Width This value is derived from the S_HADDR_WIDTH parameter: The options
 * for this field are:
 *
 * Values:
 * 0 - 32 bits
 */

#define BP_SATA_GPARAM1R_S_HADDR      (7)      //!< Bit position for SATA_GPARAM1R_S_HADDR.
#define BM_SATA_GPARAM1R_S_HADDR      (0x00000080)  //!< Bit mask for SATA_GPARAM1R_S_HADDR.

//! @brief Get value of SATA_GPARAM1R_S_HADDR from a register value.
#define BG_SATA_GPARAM1R_S_HADDR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPARAM1R_S_HADDR) >> BP_SATA_GPARAM1R_S_HADDR)


/* --- Register HW_SATA_GPARAM1R, field AHB_ENDIAN[9:8] (RO)
 *
 * AHB Bus Endianness This value is derived from the AHB_ENDIANNESS parameter: The options for this
 * field are:
 *
 * Values:
 * 0 - Little Endian
 */

#define BP_SATA_GPARAM1R_AHB_ENDIAN      (8)      //!< Bit position for SATA_GPARAM1R_AHB_ENDIAN.
#define BM_SATA_GPARAM1R_AHB_ENDIAN      (0x00000300)  //!< Bit mask for SATA_GPARAM1R_AHB_ENDIAN.

//! @brief Get value of SATA_GPARAM1R_AHB_ENDIAN from a register value.
#define BG_SATA_GPARAM1R_AHB_ENDIAN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPARAM1R_AHB_ENDIAN) >> BP_SATA_GPARAM1R_AHB_ENDIAN)


/* --- Register HW_SATA_GPARAM1R, field RETURN_ERR[10] (RO)
 *
 * AHB Error Response This value is derived from the RETURN_ERR_RESP parameter: The options for this
 * field are:
 *
 * Values:
 * 1 - True
 */

#define BP_SATA_GPARAM1R_RETURN_ERR      (10)      //!< Bit position for SATA_GPARAM1R_RETURN_ERR.
#define BM_SATA_GPARAM1R_RETURN_ERR      (0x00000400)  //!< Bit mask for SATA_GPARAM1R_RETURN_ERR.

//! @brief Get value of SATA_GPARAM1R_RETURN_ERR from a register value.
#define BG_SATA_GPARAM1R_RETURN_ERR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPARAM1R_RETURN_ERR) >> BP_SATA_GPARAM1R_RETURN_ERR)


/* --- Register HW_SATA_GPARAM1R, field BIST_M[13] (RO)
 *
 * BIST Loopback Checking Depth This value is derived from the BIST_MODE parameter. The options for
 * this field are:
 *
 * Values:
 * 0 - FIS
 */

#define BP_SATA_GPARAM1R_BIST_M      (13)      //!< Bit position for SATA_GPARAM1R_BIST_M.
#define BM_SATA_GPARAM1R_BIST_M      (0x00002000)  //!< Bit mask for SATA_GPARAM1R_BIST_M.

//! @brief Get value of SATA_GPARAM1R_BIST_M from a register value.
#define BG_SATA_GPARAM1R_BIST_M(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPARAM1R_BIST_M) >> BP_SATA_GPARAM1R_BIST_M)


/* --- Register HW_SATA_GPARAM1R, field PHY_STAT[20:15] (RO)
 *
 * PHY Status Width 0x20 (32) PHY Status Width is 32 bits. This value reflects the PHY_STAT_W
 * parameter.
 */

#define BP_SATA_GPARAM1R_PHY_STAT      (15)      //!< Bit position for SATA_GPARAM1R_PHY_STAT.
#define BM_SATA_GPARAM1R_PHY_STAT      (0x001f8000)  //!< Bit mask for SATA_GPARAM1R_PHY_STAT.

//! @brief Get value of SATA_GPARAM1R_PHY_STAT from a register value.
#define BG_SATA_GPARAM1R_PHY_STAT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPARAM1R_PHY_STAT) >> BP_SATA_GPARAM1R_PHY_STAT)

/* --- Register HW_SATA_GPARAM1R, field PHY_CTRL[26:21] (RO)
 *
 * PHY Control Width 0x20 (32) PHY Control Width is 32 bits. This value reflects the PHY_CTRL_W
 * parameter.
 */

#define BP_SATA_GPARAM1R_PHY_CTRL      (21)      //!< Bit position for SATA_GPARAM1R_PHY_CTRL.
#define BM_SATA_GPARAM1R_PHY_CTRL      (0x07e00000)  //!< Bit mask for SATA_GPARAM1R_PHY_CTRL.

//! @brief Get value of SATA_GPARAM1R_PHY_CTRL from a register value.
#define BG_SATA_GPARAM1R_PHY_CTRL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPARAM1R_PHY_CTRL) >> BP_SATA_GPARAM1R_PHY_CTRL)

/* --- Register HW_SATA_GPARAM1R, field PHY_RST[27] (RO)
 *
 * PHY Reset Mode This value is derived from the PHY_RST_MODE parameter. The options for this field
 * are:
 *
 * Values:
 * 0 - Low
 */

#define BP_SATA_GPARAM1R_PHY_RST      (27)      //!< Bit position for SATA_GPARAM1R_PHY_RST.
#define BM_SATA_GPARAM1R_PHY_RST      (0x08000000)  //!< Bit mask for SATA_GPARAM1R_PHY_RST.

//! @brief Get value of SATA_GPARAM1R_PHY_RST from a register value.
#define BG_SATA_GPARAM1R_PHY_RST(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPARAM1R_PHY_RST) >> BP_SATA_GPARAM1R_PHY_RST)


/* --- Register HW_SATA_GPARAM1R, field PHY_DATA[29:28] (RO)
 *
 * PHY Data Width This value is derived from the PHY_DATA_WIDTH parameter: The options for this
 * field are: • 0x0: 1 0x1: PHY DATA WIDTH = 2 • 0x2: 4 Other values are reserved.
 */

#define BP_SATA_GPARAM1R_PHY_DATA      (28)      //!< Bit position for SATA_GPARAM1R_PHY_DATA.
#define BM_SATA_GPARAM1R_PHY_DATA      (0x30000000)  //!< Bit mask for SATA_GPARAM1R_PHY_DATA.

//! @brief Get value of SATA_GPARAM1R_PHY_DATA from a register value.
#define BG_SATA_GPARAM1R_PHY_DATA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPARAM1R_PHY_DATA) >> BP_SATA_GPARAM1R_PHY_DATA)

/* --- Register HW_SATA_GPARAM1R, field RX_BUFFER[30] (RO)
 *
 * Rx Data Buffer This value is derived from the RX_BUFFER_MODE parameter:
 *
 * Values:
 * 1 - Include
 */

#define BP_SATA_GPARAM1R_RX_BUFFER      (30)      //!< Bit position for SATA_GPARAM1R_RX_BUFFER.
#define BM_SATA_GPARAM1R_RX_BUFFER      (0x40000000)  //!< Bit mask for SATA_GPARAM1R_RX_BUFFER.

//! @brief Get value of SATA_GPARAM1R_RX_BUFFER from a register value.
#define BG_SATA_GPARAM1R_RX_BUFFER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPARAM1R_RX_BUFFER) >> BP_SATA_GPARAM1R_RX_BUFFER)


/* --- Register HW_SATA_GPARAM1R, field ALIGN_M[31] (RO)
 *
 * Rx Data Alignment This value is derived from the ALIGN_MODE parameter. The options for this field
 * are:
 *
 * Values:
 * 0 - Misaligned
 */

#define BP_SATA_GPARAM1R_ALIGN_M      (31)      //!< Bit position for SATA_GPARAM1R_ALIGN_M.
#define BM_SATA_GPARAM1R_ALIGN_M      (0x80000000)  //!< Bit mask for SATA_GPARAM1R_ALIGN_M.

//! @brief Get value of SATA_GPARAM1R_ALIGN_M from a register value.
#define BG_SATA_GPARAM1R_ALIGN_M(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPARAM1R_ALIGN_M) >> BP_SATA_GPARAM1R_ALIGN_M)


//-------------------------------------------------------------------------------------------
// HW_SATA_GPARAM2R - Global Parameter 1 Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_GPARAM2R - Global Parameter 1 Register (RO)
 *
 * Reset value: 0x00000e1e
 *
 * This read-only register contains encoded information about the SATA block global configuration
 * parameters' settings.
 */
typedef union _hw_sata_gparam2r
{
    reg32_t U;
    struct _hw_sata_gparam2r_bitfields
    {
        unsigned RXOOB_CLK : 9; //!< [8:0] Rx OOB Clock Frequency This field returns 0x32 (50 decimal) The Rx OOB clock frequency is 50 MHz. This value reflects the hexadecimal value of the RXOOB_CLK_FREQ parameter .
        unsigned TX_OOB_M : 1; //!< [9] Tx OOB Mode This value is derived from the TX_OOB_MODE parameter: The options for this field are:
        unsigned RX_OOB_M : 1; //!< [10] Rx OOB Mode This value is derived from the RX_OOB_MODE parameter: The options for this field are:
        unsigned RXOOB_CLK_M : 1; //!< [11] Rx OOB Clock Mode This value is derived from the RXOOB_CLK_MODE parameter, The options for this field are:
        unsigned ENCODE_M : 1; //!< [12] 8b/10b Encoding/Decoding This value is derived from the ENCODE_MODE parameter. The options for this field are:
        unsigned DEV_MP : 1; //!< [13] Mechanical Presence Switch This value is derived from the DEV_MP_SWITCH parameter. The options for this field are:
        unsigned DEV_CP : 1; //!< [14] Cold Presence Detect This value is derived from the DEV_CP_DET parameter. The options for this field are:
        unsigned RESERVED0 : 17; //!< [31:15] Reserved
    } B;
} hw_sata_gparam2r_t;
#endif

/*
 * constants & macros for entire SATA_GPARAM2R register
 */
#define HW_SATA_GPARAM2R_ADDR      (REGS_SATA_BASE + 0xec)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_GPARAM2R           (*(volatile hw_sata_gparam2r_t *) HW_SATA_GPARAM2R_ADDR)
#define HW_SATA_GPARAM2R_RD()      (HW_SATA_GPARAM2R.U)
#endif

/*
 * constants & macros for individual SATA_GPARAM2R bitfields
 */

/* --- Register HW_SATA_GPARAM2R, field RXOOB_CLK[8:0] (RO)
 *
 * Rx OOB Clock Frequency This field returns 0x32 (50 decimal) The Rx OOB clock frequency is 50 MHz.
 * This value reflects the hexadecimal value of the RXOOB_CLK_FREQ parameter .
 */

#define BP_SATA_GPARAM2R_RXOOB_CLK      (0)      //!< Bit position for SATA_GPARAM2R_RXOOB_CLK.
#define BM_SATA_GPARAM2R_RXOOB_CLK      (0x000001ff)  //!< Bit mask for SATA_GPARAM2R_RXOOB_CLK.

//! @brief Get value of SATA_GPARAM2R_RXOOB_CLK from a register value.
#define BG_SATA_GPARAM2R_RXOOB_CLK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPARAM2R_RXOOB_CLK) >> BP_SATA_GPARAM2R_RXOOB_CLK)

/* --- Register HW_SATA_GPARAM2R, field TX_OOB_M[9] (RO)
 *
 * Tx OOB Mode This value is derived from the TX_OOB_MODE parameter: The options for this field are:
 *
 * Values:
 * 1 - Tx OOB signalling is supported
 */

#define BP_SATA_GPARAM2R_TX_OOB_M      (9)      //!< Bit position for SATA_GPARAM2R_TX_OOB_M.
#define BM_SATA_GPARAM2R_TX_OOB_M      (0x00000200)  //!< Bit mask for SATA_GPARAM2R_TX_OOB_M.

//! @brief Get value of SATA_GPARAM2R_TX_OOB_M from a register value.
#define BG_SATA_GPARAM2R_TX_OOB_M(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPARAM2R_TX_OOB_M) >> BP_SATA_GPARAM2R_TX_OOB_M)


/* --- Register HW_SATA_GPARAM2R, field RX_OOB_M[10] (RO)
 *
 * Rx OOB Mode This value is derived from the RX_OOB_MODE parameter: The options for this field are:
 *
 * Values:
 * 1 - Rx OOB signalling is supported
 */

#define BP_SATA_GPARAM2R_RX_OOB_M      (10)      //!< Bit position for SATA_GPARAM2R_RX_OOB_M.
#define BM_SATA_GPARAM2R_RX_OOB_M      (0x00000400)  //!< Bit mask for SATA_GPARAM2R_RX_OOB_M.

//! @brief Get value of SATA_GPARAM2R_RX_OOB_M from a register value.
#define BG_SATA_GPARAM2R_RX_OOB_M(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPARAM2R_RX_OOB_M) >> BP_SATA_GPARAM2R_RX_OOB_M)


/* --- Register HW_SATA_GPARAM2R, field RXOOB_CLK_M[11] (RO)
 *
 * Rx OOB Clock Mode This value is derived from the RXOOB_CLK_MODE parameter, The options for this
 * field are:
 *
 * Values:
 * 1 - separate clock
 */

#define BP_SATA_GPARAM2R_RXOOB_CLK_M      (11)      //!< Bit position for SATA_GPARAM2R_RXOOB_CLK_M.
#define BM_SATA_GPARAM2R_RXOOB_CLK_M      (0x00000800)  //!< Bit mask for SATA_GPARAM2R_RXOOB_CLK_M.

//! @brief Get value of SATA_GPARAM2R_RXOOB_CLK_M from a register value.
#define BG_SATA_GPARAM2R_RXOOB_CLK_M(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPARAM2R_RXOOB_CLK_M) >> BP_SATA_GPARAM2R_RXOOB_CLK_M)


/* --- Register HW_SATA_GPARAM2R, field ENCODE_M[12] (RO)
 *
 * 8b/10b Encoding/Decoding This value is derived from the ENCODE_MODE parameter. The options for
 * this field are:
 *
 * Values:
 * 1 - 8b/10b encoding/decoding is supported
 */

#define BP_SATA_GPARAM2R_ENCODE_M      (12)      //!< Bit position for SATA_GPARAM2R_ENCODE_M.
#define BM_SATA_GPARAM2R_ENCODE_M      (0x00001000)  //!< Bit mask for SATA_GPARAM2R_ENCODE_M.

//! @brief Get value of SATA_GPARAM2R_ENCODE_M from a register value.
#define BG_SATA_GPARAM2R_ENCODE_M(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPARAM2R_ENCODE_M) >> BP_SATA_GPARAM2R_ENCODE_M)


/* --- Register HW_SATA_GPARAM2R, field DEV_MP[13] (RO)
 *
 * Mechanical Presence Switch This value is derived from the DEV_MP_SWITCH parameter. The options
 * for this field are:
 *
 * Values:
 * 0 - Mechanical presence switch is not supported
 */

#define BP_SATA_GPARAM2R_DEV_MP      (13)      //!< Bit position for SATA_GPARAM2R_DEV_MP.
#define BM_SATA_GPARAM2R_DEV_MP      (0x00002000)  //!< Bit mask for SATA_GPARAM2R_DEV_MP.

//! @brief Get value of SATA_GPARAM2R_DEV_MP from a register value.
#define BG_SATA_GPARAM2R_DEV_MP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPARAM2R_DEV_MP) >> BP_SATA_GPARAM2R_DEV_MP)


/* --- Register HW_SATA_GPARAM2R, field DEV_CP[14] (RO)
 *
 * Cold Presence Detect This value is derived from the DEV_CP_DET parameter. The options for this
 * field are:
 *
 * Values:
 * 0 - cold presence detect is not supported
 */

#define BP_SATA_GPARAM2R_DEV_CP      (14)      //!< Bit position for SATA_GPARAM2R_DEV_CP.
#define BM_SATA_GPARAM2R_DEV_CP      (0x00004000)  //!< Bit mask for SATA_GPARAM2R_DEV_CP.

//! @brief Get value of SATA_GPARAM2R_DEV_CP from a register value.
#define BG_SATA_GPARAM2R_DEV_CP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_GPARAM2R_DEV_CP) >> BP_SATA_GPARAM2R_DEV_CP)


//-------------------------------------------------------------------------------------------
// HW_SATA_PPARAMR - Port Parameter Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_PPARAMR - Port Parameter Register (RO)
 *
 * Reset value: 0x00000022
 *
 * This read-only register contains encoded information about the selected Port configuration
 * parameters' settings. The Port is selected by the SATA_TESTR[PSEL] field.
 */
typedef union _hw_sata_pparamr
{
    reg32_t U;
    struct _hw_sata_pparamr_bitfields
    {
        unsigned RXFIFO_DEPTH : 3; //!< [2:0] Rx FIFO Depth 0x4 Rx FIFO Depth set to 512 DWORDs This value is derived from the P#_RXFIFO_DEPTH parameter: The options for this field are:
        unsigned TXFIFO_DEPTH : 3; //!< [5:3] Tx FIFO Depth 0x4 Tx FIFO Depth set to 512 DWORDs This value is derived from the P#_TXFIFO_DEPTH parameter: The options for this field are:
        unsigned RX_MEM_S : 1; //!< [6] Rx FIFO Memory Type This value is derived from the P#_RX_MEM_SELECT parameter: The options for this field are:
        unsigned RX_MEM_M : 1; //!< [7] Rx FIFO Memory Read Port Type This value is derived from the P#_RX_MEM_MODE parameter: The options for this field are:
        unsigned TX_MEM_S : 1; //!< [8] Tx FIFO Memory Type This value is derived from the P#_TX_MEM_SELECT parameter: The options for this field are:
        unsigned TX_MEM_M : 1; //!< [9] Tx FIFO Memory Read Port Type This value is derived from the P#_TX_MEM_MODE parameter: The options for this field are:
        unsigned TX_MEM_S1 : 1; //!< [10] TX FIFO Memory This value is derived from the P0_TX_MEM_SELECT parameter. The options for this field are:
        unsigned TX_MEM_M1 : 1; //!< [11] TX FIFO Memory Read Port Type This value is derived from the P0_TX_MEM_MODE parameter. The options for this field are:
        unsigned RESERVED0 : 20; //!< [31:12] Reserved
    } B;
} hw_sata_pparamr_t;
#endif

/*
 * constants & macros for entire SATA_PPARAMR register
 */
#define HW_SATA_PPARAMR_ADDR      (REGS_SATA_BASE + 0xf0)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_PPARAMR           (*(volatile hw_sata_pparamr_t *) HW_SATA_PPARAMR_ADDR)
#define HW_SATA_PPARAMR_RD()      (HW_SATA_PPARAMR.U)
#endif

/*
 * constants & macros for individual SATA_PPARAMR bitfields
 */

/* --- Register HW_SATA_PPARAMR, field RXFIFO_DEPTH[2:0] (RO)
 *
 * Rx FIFO Depth 0x4 Rx FIFO Depth set to 512 DWORDs This value is derived from the P#_RXFIFO_DEPTH
 * parameter: The options for this field are:
 */

#define BP_SATA_PPARAMR_RXFIFO_DEPTH      (0)      //!< Bit position for SATA_PPARAMR_RXFIFO_DEPTH.
#define BM_SATA_PPARAMR_RXFIFO_DEPTH      (0x00000007)  //!< Bit mask for SATA_PPARAMR_RXFIFO_DEPTH.

//! @brief Get value of SATA_PPARAMR_RXFIFO_DEPTH from a register value.
#define BG_SATA_PPARAMR_RXFIFO_DEPTH(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_PPARAMR_RXFIFO_DEPTH) >> BP_SATA_PPARAMR_RXFIFO_DEPTH)

/* --- Register HW_SATA_PPARAMR, field TXFIFO_DEPTH[5:3] (RO)
 *
 * Tx FIFO Depth 0x4 Tx FIFO Depth set to 512 DWORDs This value is derived from the P#_TXFIFO_DEPTH
 * parameter: The options for this field are:
 */

#define BP_SATA_PPARAMR_TXFIFO_DEPTH      (3)      //!< Bit position for SATA_PPARAMR_TXFIFO_DEPTH.
#define BM_SATA_PPARAMR_TXFIFO_DEPTH      (0x00000038)  //!< Bit mask for SATA_PPARAMR_TXFIFO_DEPTH.

//! @brief Get value of SATA_PPARAMR_TXFIFO_DEPTH from a register value.
#define BG_SATA_PPARAMR_TXFIFO_DEPTH(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_PPARAMR_TXFIFO_DEPTH) >> BP_SATA_PPARAMR_TXFIFO_DEPTH)

/* --- Register HW_SATA_PPARAMR, field RX_MEM_S[6] (RO)
 *
 * Rx FIFO Memory Type This value is derived from the P#_RX_MEM_SELECT parameter: The options for
 * this field are:
 *
 * Values:
 * 0 - External
 */

#define BP_SATA_PPARAMR_RX_MEM_S      (6)      //!< Bit position for SATA_PPARAMR_RX_MEM_S.
#define BM_SATA_PPARAMR_RX_MEM_S      (0x00000040)  //!< Bit mask for SATA_PPARAMR_RX_MEM_S.

//! @brief Get value of SATA_PPARAMR_RX_MEM_S from a register value.
#define BG_SATA_PPARAMR_RX_MEM_S(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_PPARAMR_RX_MEM_S) >> BP_SATA_PPARAMR_RX_MEM_S)


/* --- Register HW_SATA_PPARAMR, field RX_MEM_M[7] (RO)
 *
 * Rx FIFO Memory Read Port Type This value is derived from the P#_RX_MEM_MODE parameter: The
 * options for this field are:
 *
 * Values:
 * 1 - Sync
 */

#define BP_SATA_PPARAMR_RX_MEM_M      (7)      //!< Bit position for SATA_PPARAMR_RX_MEM_M.
#define BM_SATA_PPARAMR_RX_MEM_M      (0x00000080)  //!< Bit mask for SATA_PPARAMR_RX_MEM_M.

//! @brief Get value of SATA_PPARAMR_RX_MEM_M from a register value.
#define BG_SATA_PPARAMR_RX_MEM_M(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_PPARAMR_RX_MEM_M) >> BP_SATA_PPARAMR_RX_MEM_M)


/* --- Register HW_SATA_PPARAMR, field TX_MEM_S[8] (RO)
 *
 * Tx FIFO Memory Type This value is derived from the P#_TX_MEM_SELECT parameter: The options for
 * this field are:
 *
 * Values:
 * 0 - External
 */

#define BP_SATA_PPARAMR_TX_MEM_S      (8)      //!< Bit position for SATA_PPARAMR_TX_MEM_S.
#define BM_SATA_PPARAMR_TX_MEM_S      (0x00000100)  //!< Bit mask for SATA_PPARAMR_TX_MEM_S.

//! @brief Get value of SATA_PPARAMR_TX_MEM_S from a register value.
#define BG_SATA_PPARAMR_TX_MEM_S(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_PPARAMR_TX_MEM_S) >> BP_SATA_PPARAMR_TX_MEM_S)


/* --- Register HW_SATA_PPARAMR, field TX_MEM_M[9] (RO)
 *
 * Tx FIFO Memory Read Port Type This value is derived from the P#_TX_MEM_MODE parameter: The
 * options for this field are:
 *
 * Values:
 * 1 - Sync
 */

#define BP_SATA_PPARAMR_TX_MEM_M      (9)      //!< Bit position for SATA_PPARAMR_TX_MEM_M.
#define BM_SATA_PPARAMR_TX_MEM_M      (0x00000200)  //!< Bit mask for SATA_PPARAMR_TX_MEM_M.

//! @brief Get value of SATA_PPARAMR_TX_MEM_M from a register value.
#define BG_SATA_PPARAMR_TX_MEM_M(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_PPARAMR_TX_MEM_M) >> BP_SATA_PPARAMR_TX_MEM_M)


/* --- Register HW_SATA_PPARAMR, field TX_MEM_S1[10] (RU)
 *
 * TX FIFO Memory This value is derived from the P0_TX_MEM_SELECT parameter. The options for this
 * field are:
 *
 * Values:
 * 0 - External
 * 1 - Internal
 */

#define BP_SATA_PPARAMR_TX_MEM_S1      (10)      //!< Bit position for SATA_PPARAMR_TX_MEM_S1.
#define BM_SATA_PPARAMR_TX_MEM_S1      (0x00000400)  //!< Bit mask for SATA_PPARAMR_TX_MEM_S1.

//! @brief Get value of SATA_PPARAMR_TX_MEM_S1 from a register value.
#define BG_SATA_PPARAMR_TX_MEM_S1(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_PPARAMR_TX_MEM_S1) >> BP_SATA_PPARAMR_TX_MEM_S1)


/* --- Register HW_SATA_PPARAMR, field TX_MEM_M1[11] (RU)
 *
 * TX FIFO Memory Read Port Type This value is derived from the P0_TX_MEM_MODE parameter. The
 * options for this field are:
 *
 * Values:
 * 0 - Async
 * 1 - Sync
 */

#define BP_SATA_PPARAMR_TX_MEM_M1      (11)      //!< Bit position for SATA_PPARAMR_TX_MEM_M1.
#define BM_SATA_PPARAMR_TX_MEM_M1      (0x00000800)  //!< Bit mask for SATA_PPARAMR_TX_MEM_M1.

//! @brief Get value of SATA_PPARAMR_TX_MEM_M1 from a register value.
#define BG_SATA_PPARAMR_TX_MEM_M1(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_PPARAMR_TX_MEM_M1) >> BP_SATA_PPARAMR_TX_MEM_M1)


//-------------------------------------------------------------------------------------------
// HW_SATA_TESTR - Test Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_TESTR - Test Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register is used to put the SATA block slave interface into a test mode and to select a Port
 * for BIST operation.
 */
typedef union _hw_sata_testr
{
    reg32_t U;
    struct _hw_sata_testr_bitfields
    {
        unsigned TEST_IF : 1; //!< [0] TEST_IF: Test Interface Normal operation is disabled. The following registers can be accessed in this mode: - SATA_GHC register IE bit - SATA_BISTAFR register NCP and PD bits become read-write - SATA_BISTCR register LLC, ERREN, FLIP, PV, PATTERN - SATA_BISTFCTR, SATA_BISTSR , SATA_BISTDECR become read-write - SATA_P # 0 CLB /CLBU , SATA_P # 0 FB /FBU registers - SATA_P # 0 IS register RW1C and UFS bits become read-write - SATA_P # 0 IE register - SATA_P # 0 CMD register ASP, ALPE, DLAE, ATAPI, PMA bits - SATA_P # 0 TFD, SATA_P # 0 SIG registers become read-write - SATA_P # 0 SCTL register - SATA_P # 0 SERR register RW1C bits become read-write bits - SATA_P # 0 SACT, SATA_P # 0 CI, SATA_P # 0 SNTF registers become read-write - SATA_P # 0 DMACR register - SATA_P # 0 PHYCR register - SATA_P # 0 PHYSR register becomes read-write Notes: • Interrupt is asserted when any of the SATA_IS register bits is set after setting the corresponding SATA_P # 0 IS and SATA_P # 0 IE registers and SATA_GHC[IE]=1. • SATA_CAP[SMPS], SATA_CAP[SSS], SATA_PI, SATA_P # 0 CMD[ESP], SATA_P # 0 CMD[CPD], SATA_P # 0 CMD[MPSP], and SATA_P # 0 CMD[HPCP] register bits are HwInit type and can not be used in Test mode. They are written once after power-on reset and become read-only. • Global SATA block reset must be issued (SATA_GHC[HR]=1) after TEST_WHEN bit is cleared following the Test mode operation. This bit is used to put the SATA block slave interface into the test mode: The options for this field are:
        unsigned RESERVED0 : 15; //!< [15:1] Reserved
        unsigned PSEL : 3; //!< [18:16] Port Select This field is used to select a Port for BIST operation: The options for this field are:
        unsigned RESERVED1 : 13; //!< [31:19] Reserved
    } B;
} hw_sata_testr_t;
#endif

/*
 * constants & macros for entire SATA_TESTR register
 */
#define HW_SATA_TESTR_ADDR      (REGS_SATA_BASE + 0xf4)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_TESTR           (*(volatile hw_sata_testr_t *) HW_SATA_TESTR_ADDR)
#define HW_SATA_TESTR_RD()      (HW_SATA_TESTR.U)
#define HW_SATA_TESTR_WR(v)     (HW_SATA_TESTR.U = (v))
#define HW_SATA_TESTR_SET(v)    (HW_SATA_TESTR_WR(HW_SATA_TESTR_RD() |  (v)))
#define HW_SATA_TESTR_CLR(v)    (HW_SATA_TESTR_WR(HW_SATA_TESTR_RD() & ~(v)))
#define HW_SATA_TESTR_TOG(v)    (HW_SATA_TESTR_WR(HW_SATA_TESTR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_TESTR bitfields
 */

/* --- Register HW_SATA_TESTR, field TEST_IF[0] (RW)
 *
 * TEST_IF: Test Interface Normal operation is disabled. The following registers can be accessed in
 * this mode: - SATA_GHC register IE bit - SATA_BISTAFR register NCP and PD bits become read-write -
 * SATA_BISTCR register LLC, ERREN, FLIP, PV, PATTERN - SATA_BISTFCTR, SATA_BISTSR , SATA_BISTDECR
 * become read-write - SATA_P # 0 CLB /CLBU , SATA_P # 0 FB /FBU registers - SATA_P # 0 IS register
 * RW1C and UFS bits become read-write - SATA_P # 0 IE register - SATA_P # 0 CMD register ASP, ALPE,
 * DLAE, ATAPI, PMA bits - SATA_P # 0 TFD, SATA_P # 0 SIG registers become read-write - SATA_P # 0
 * SCTL register - SATA_P # 0 SERR register RW1C bits become read-write bits - SATA_P # 0 SACT,
 * SATA_P # 0 CI, SATA_P # 0 SNTF registers become read-write - SATA_P # 0 DMACR register - SATA_P #
 * 0 PHYCR register - SATA_P # 0 PHYSR register becomes read-write Notes: • Interrupt is asserted
 * when any of the SATA_IS register bits is set after setting the corresponding SATA_P # 0 IS and
 * SATA_P # 0 IE registers and SATA_GHC[IE]=1. • SATA_CAP[SMPS], SATA_CAP[SSS], SATA_PI, SATA_P # 0
 * CMD[ESP], SATA_P # 0 CMD[CPD], SATA_P # 0 CMD[MPSP], and SATA_P # 0 CMD[HPCP] register bits are
 * HwInit type and can not be used in Test mode. They are written once after power-on reset and
 * become read-only. • Global SATA block reset must be issued (SATA_GHC[HR]=1) after TEST_WHEN bit
 * is cleared following the Test mode operation. This bit is used to put the SATA block slave
 * interface into the test mode: The options for this field are:
 *
 * Values:
 * 0 - Normal mode: the read back value of some registers is a function of the SATA block state and does
 *     not match the value written.
 * 1 - Test mode: the read back value of the registers matches the value written.
 */

#define BP_SATA_TESTR_TEST_IF      (0)      //!< Bit position for SATA_TESTR_TEST_IF.
#define BM_SATA_TESTR_TEST_IF      (0x00000001)  //!< Bit mask for SATA_TESTR_TEST_IF.

//! @brief Get value of SATA_TESTR_TEST_IF from a register value.
#define BG_SATA_TESTR_TEST_IF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_TESTR_TEST_IF) >> BP_SATA_TESTR_TEST_IF)

//! @brief Format value for bitfield SATA_TESTR_TEST_IF.
#define BF_SATA_TESTR_TEST_IF(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_TESTR_TEST_IF) & BM_SATA_TESTR_TEST_IF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TEST_IF field to a new value.
#define BW_SATA_TESTR_TEST_IF(v)   (HW_SATA_TESTR_WR((HW_SATA_TESTR_RD() & ~BM_SATA_TESTR_TEST_IF) | BF_SATA_TESTR_TEST_IF(v)))
#endif


/* --- Register HW_SATA_TESTR, field PSEL[18:16] (RW)
 *
 * Port Select This field is used to select a Port for BIST operation: The options for this field
 * are:
 *
 * Values:
 * 0x0 - Port0 is selected
 * 0x0 - Port1 is selected
 * 0x0 - Port2 is selected
 * 0x0 - Port3 is selected
 * 0x0 - Port4 is selected
 * 0x0 - Port5 is selected
 * 0x0 - Port6 is selected
 * 0x0 - Port7 is selected
 */

#define BP_SATA_TESTR_PSEL      (16)      //!< Bit position for SATA_TESTR_PSEL.
#define BM_SATA_TESTR_PSEL      (0x00070000)  //!< Bit mask for SATA_TESTR_PSEL.

//! @brief Get value of SATA_TESTR_PSEL from a register value.
#define BG_SATA_TESTR_PSEL(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_TESTR_PSEL) >> BP_SATA_TESTR_PSEL)

//! @brief Format value for bitfield SATA_TESTR_PSEL.
#define BF_SATA_TESTR_PSEL(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_TESTR_PSEL) & BM_SATA_TESTR_PSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PSEL field to a new value.
#define BW_SATA_TESTR_PSEL(v)   (HW_SATA_TESTR_WR((HW_SATA_TESTR_RD() & ~BM_SATA_TESTR_PSEL) | BF_SATA_TESTR_PSEL(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_SATA_VERSIONR - Version Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_VERSIONR - Version Register (RO)
 *
 * Reset value: 0x3330302a
 *
 * This 32-bit read-only register contains a hard-coded ASCII string that represents the version
 * level of the SATA block. This register contains the ASCII string "300*" (hexadecimal 0x3330302A).
 * This 32-bit read-only register contains a hard-coded component version value set by the
 * AHSATA_VERSION_NUM parameter. The value represents an ASCII code of the version number. For
 * example, version 1.24* is coded as 0x3132_342A.
 */
typedef union _hw_sata_versionr
{
    reg32_t U;
    struct _hw_sata_versionr_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] SATA block hard-coded hexadecimal version value encoded in ASCII. Parameter AHSATA_VERSION_NUM
    } B;
} hw_sata_versionr_t;
#endif

/*
 * constants & macros for entire SATA_VERSIONR register
 */
#define HW_SATA_VERSIONR_ADDR      (REGS_SATA_BASE + 0xf8)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_VERSIONR           (*(volatile hw_sata_versionr_t *) HW_SATA_VERSIONR_ADDR)
#define HW_SATA_VERSIONR_RD()      (HW_SATA_VERSIONR.U)
#endif

/*
 * constants & macros for individual SATA_VERSIONR bitfields
 */

//-------------------------------------------------------------------------------------------
// HW_SATA_P0CLB - Port0 Command List Base Address Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_P0CLB - Port0 Command List Base Address Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The algorithm for the software to determine the offset is:   Port offset = 0x100 + (PI Asserted
 * Bit Position * 0x80)    Size: 32 bits  Address offset: for # = 0 to 7:   P0CLB: 0x100  P1CLB:
 * 0x180  P2CLB: 0x200  P3CLB: 0x280  P4CLB: 0x300  P5CLB: 0x380  P6CLB: 0x400  P7CLB: 0x480
 * Read/write access: Read/write  Reset: 0x0000_0000
 */
typedef union _hw_sata_p0clb
{
    reg32_t U;
    struct _hw_sata_p0clb_bitfields
    {
        unsigned RESERVED0 : 10; //!< [9:0] Reserved.
        unsigned CLB : 22; //!< [31:10] Command List Base Address Indicates the 32-bit base physical address for the command list for this Port. This base is used when fetching commands to execute. The structure pointed to by this address range is 1 KB in length. This address must be 1-KB-aligned as indicated by bits [9:0] being read only.
    } B;
} hw_sata_p0clb_t;
#endif

/*
 * constants & macros for entire SATA_P0CLB register
 */
#define HW_SATA_P0CLB_ADDR      (REGS_SATA_BASE + 0x100)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0CLB           (*(volatile hw_sata_p0clb_t *) HW_SATA_P0CLB_ADDR)
#define HW_SATA_P0CLB_RD()      (HW_SATA_P0CLB.U)
#define HW_SATA_P0CLB_WR(v)     (HW_SATA_P0CLB.U = (v))
#define HW_SATA_P0CLB_SET(v)    (HW_SATA_P0CLB_WR(HW_SATA_P0CLB_RD() |  (v)))
#define HW_SATA_P0CLB_CLR(v)    (HW_SATA_P0CLB_WR(HW_SATA_P0CLB_RD() & ~(v)))
#define HW_SATA_P0CLB_TOG(v)    (HW_SATA_P0CLB_WR(HW_SATA_P0CLB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_P0CLB bitfields
 */

/* --- Register HW_SATA_P0CLB, field CLB[31:10] (RW)
 *
 * Command List Base Address Indicates the 32-bit base physical address for the command list for
 * this Port. This base is used when fetching commands to execute. The structure pointed to by this
 * address range is 1 KB in length. This address must be 1-KB-aligned as indicated by bits [9:0]
 * being read only.
 */

#define BP_SATA_P0CLB_CLB      (10)      //!< Bit position for SATA_P0CLB_CLB.
#define BM_SATA_P0CLB_CLB      (0xfffffc00)  //!< Bit mask for SATA_P0CLB_CLB.

//! @brief Get value of SATA_P0CLB_CLB from a register value.
#define BG_SATA_P0CLB_CLB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CLB_CLB) >> BP_SATA_P0CLB_CLB)

//! @brief Format value for bitfield SATA_P0CLB_CLB.
#define BF_SATA_P0CLB_CLB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CLB_CLB) & BM_SATA_P0CLB_CLB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLB field to a new value.
#define BW_SATA_P0CLB_CLB(v)   (HW_SATA_P0CLB_WR((HW_SATA_P0CLB_RD() & ~BM_SATA_P0CLB_CLB) | BF_SATA_P0CLB_CLB(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_SATA_P0FB - Port0 FIS Base Address Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_P0FB - Port0 FIS Base Address Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Size: 32 bits  Address offset: for # = 0 to 7:   P0FB: 0x108  P1FB: 0x188  P2FB: 0x208  P3FB:
 * 0x288  P4FB: 0x308  P5FB: 0x388  P6FB: 0x408  P7FB: 0x488    Read/write access: Read/write
 * Reset: 0x0000_0000
 */
typedef union _hw_sata_p0fb
{
    reg32_t U;
    struct _hw_sata_p0fb_bitfields
    {
        unsigned RESERVED0 : 8; //!< [7:0] Reserved.
        unsigned FB : 24; //!< [31:8] FIS Base Address. Indicates the 32-bit base physical address for received FISes. The structure pointed to by this address range is 256 bytes in length. This address must be 256byte-aligned as indicated by bits [7:0] being read only. Reset: 0x000000
    } B;
} hw_sata_p0fb_t;
#endif

/*
 * constants & macros for entire SATA_P0FB register
 */
#define HW_SATA_P0FB_ADDR      (REGS_SATA_BASE + 0x108)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0FB           (*(volatile hw_sata_p0fb_t *) HW_SATA_P0FB_ADDR)
#define HW_SATA_P0FB_RD()      (HW_SATA_P0FB.U)
#define HW_SATA_P0FB_WR(v)     (HW_SATA_P0FB.U = (v))
#define HW_SATA_P0FB_SET(v)    (HW_SATA_P0FB_WR(HW_SATA_P0FB_RD() |  (v)))
#define HW_SATA_P0FB_CLR(v)    (HW_SATA_P0FB_WR(HW_SATA_P0FB_RD() & ~(v)))
#define HW_SATA_P0FB_TOG(v)    (HW_SATA_P0FB_WR(HW_SATA_P0FB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_P0FB bitfields
 */

/* --- Register HW_SATA_P0FB, field FB[31:8] (RW)
 *
 * FIS Base Address. Indicates the 32-bit base physical address for received FISes. The structure
 * pointed to by this address range is 256 bytes in length. This address must be 256byte-aligned as
 * indicated by bits [7:0] being read only. Reset: 0x000000
 */

#define BP_SATA_P0FB_FB      (8)      //!< Bit position for SATA_P0FB_FB.
#define BM_SATA_P0FB_FB      (0xffffff00)  //!< Bit mask for SATA_P0FB_FB.

//! @brief Get value of SATA_P0FB_FB from a register value.
#define BG_SATA_P0FB_FB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0FB_FB) >> BP_SATA_P0FB_FB)

//! @brief Format value for bitfield SATA_P0FB_FB.
#define BF_SATA_P0FB_FB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0FB_FB) & BM_SATA_P0FB_FB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FB field to a new value.
#define BW_SATA_P0FB_FB(v)   (HW_SATA_P0FB_WR((HW_SATA_P0FB_RD() & ~BM_SATA_P0FB_FB) | BF_SATA_P0FB_FB(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_SATA_P0IS - Port0 Interrupt Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_P0IS - Port0 Interrupt Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register is used to generate SATA block interrupt when any of the bits are set. Bits in this
 * register are set by some internal conditions, and cleared by the software writing ones in the
 * positions it wants to clear. This register is reset on Global SATA block reset.   Size: 32 bits
 * Address offset: for # = 0 to 7:   SATA_P0IS: 0x110  P1IS: 0x190  P2IS: 0x210  P3IS: 0x290  P4IS:
 * 0x310  P5IS: 0x390  P6IS: 0x410  P7IS: 0x490    Read/write access: Read-only/Write One to Clear
 * Reset: 0x0000_0000
 */
typedef union _hw_sata_p0is
{
    reg32_t U;
    struct _hw_sata_p0is_bitfields
    {
        unsigned DHRS : 1; //!< [0] Device to Host Register FIS Interrupt A D2H Register FIS has been received with the 'I' bit set, and has been copied into system memory.
        unsigned PSS : 1; //!< [1] PIO Setup FIS Interrupt. A PIO Setup FIS has been received with the 'I' bit set, it has been copied into system memory, and the data related to that FIS has been transferred. This bit is set even when the data transfer resulted in an error.
        unsigned DSS : 1; //!< [2] DMA Setup FIS Interrupt A DMA Setup FIS has been received with the 'I' bit set and has been copied into system memory.
        unsigned SDBS : 1; //!< [3] Set Device Bits Interrupt. A Set Device Bits FIS has been received with the 'I' bit set and has been copied into system memory.
        unsigned UFS : 1; //!< [4] Unknown FIS Interrupt. When set to 1, indicates that an unknown FIS was received and has been copied into system memory. This bit is cleared to 0 by the software clearing the SATA_P # 0 SERR[DIAG_F] bit to 0. The UFS bit does not directly reflect the SATA_P # 0 SERR[DIAG_F] bit. SATA_P # 0 SERR[DIAG_F] bit is set immediately when an unknown FIS is detected, whereas the UFS bit is set when that FIS is posted to memory. The software should wait to act on an unknown FIS until the UFS bit is set to 1 or the two bits may become out of sync.
        unsigned DPS : 1; //!< [5] Descriptor Processed A PRD with the I bit set has transferred all of its data. This is an opportunistic interrupt and must not be used to definitively indicate the end of a transfer. Two PRD interrupts could happen close in time together such that the second interrupt is missed when the first PRD interrupt is being cleared.
        unsigned PCS : 1; //!< [6] Port Connect Change Status This bit is cleared only when SATA_P # 0 SERR[DIAG_X] is cleared. This bit reflects the state of the SATA_P # 0 SERR[DIAG_X] bit:
        unsigned RESERVED0 : 15; //!< [21:7] Reserved. Returns 0 on read.
        unsigned PRCS : 1; //!< [22] PHY Ready Change Status This bit reflects the state of the SATA_P # 0 SERR[DIAG_N] bit. When set to 1, indicates the internal p # 0 _phy_ready signal changed state. To clear this bit, the software must clear the SATA_P # 0 SERR[DIAG_N] bit to 0.
        unsigned IPMS : 1; //!< [23] Incorrect Port Multiplier Status. Indicates that the HBA received a FIS from a device whose Port Multiplier field did not match what was expected. This bit may be set during enumeration of devices on a Port Multiplier due to the normal Port Multiplier enumeration process. The software must use the IPMS bit only after enumeration is complete on the Port Multiplier.
        unsigned OFS : 1; //!< [24] Overflow Status This bit is set when command list overflow is detected during read or write operation when the software builds command table that has fever total bytes than the transaction given to the device. Port DMA transitions to a fatal state until the software clears SATA_P # 0 CMD[ST] bit or resets the interface by way of Port or Global reset.
        unsigned RESERVED1 : 1; //!< [25] Reserved
        unsigned INFS : 1; //!< [26] Interface Non-fatal Error Status This bit is set when any of the following conditions is detected: • One or more of the following errors are detected during non-data FIS transfer - 10B to 8B Decode Error (SATA_P # 0 SERR[DIAG_B]) - Protocol (SATA_P # 0 SERR[ERR_P]) - CRC (SATA_P # 0 SERR[DIAG_C]), - Handshake (SATA_P # 0 SERR[DIAG_H]) - PHY Not Ready (SATA_P # 0 SERR[ERR_C]); • Command list underflow during read operation (i.e. DMA read) when the software builds command table that has more total bytes than the transaction given to the device.
        unsigned IFS : 1; //!< [27] Interface Fatal Error Status This bit is set when any of the following conditions is detected: • SYNC escape is received from the device during H2D Register or Data FIS transmission; • One or more of the following errors are detected during Data FIS transfer: - 10B to 8B Decode Error (SATA_P # 0 SERR[DIAG_B]) - Protocol (SATA_P # 0 SERR[ERR_P]) - CRC (SATA_P # 0 SERR[DIAG_C]) - Handshake (SATA_P # 0 SERR[DIAG_H]) - PHY Not Ready (SATA_P # 0 SERR[ERR_C]) • Unknown FIS is received with good CRC, but the length exceeds 64 bytes; • PRD table byte count is zero. Port DMA transitions to a fatal state until the software clears SATA_P # 0 CMD[ST] bit or resets the interface by way of Port or Global reset.
        unsigned HBDS : 1; //!< [28] Host Bus Data Error Status. This bit is always cleared to 0.
        unsigned HBFS : 1; //!< [29] Host Bus Fatal Error Status. This bit is set when SATA block AHB Master detects an ERROR response from the slave.
        unsigned TFES : 1; //!< [30] Task File Error Status. This bit is set whenever the SATA_P # 0 TFD[STS] register is updated by the device and the error bit (bit 0) is set.
        unsigned RESERVED2 : 1; //!< [31] Reserved. Returns 0 on read.
    } B;
} hw_sata_p0is_t;
#endif

/*
 * constants & macros for entire SATA_P0IS register
 */
#define HW_SATA_P0IS_ADDR      (REGS_SATA_BASE + 0x110)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0IS           (*(volatile hw_sata_p0is_t *) HW_SATA_P0IS_ADDR)
#define HW_SATA_P0IS_RD()      (HW_SATA_P0IS.U)
#define HW_SATA_P0IS_WR(v)     (HW_SATA_P0IS.U = (v))
#define HW_SATA_P0IS_SET(v)    (HW_SATA_P0IS_WR(HW_SATA_P0IS_RD() |  (v)))
#define HW_SATA_P0IS_CLR(v)    (HW_SATA_P0IS_WR(HW_SATA_P0IS_RD() & ~(v)))
#define HW_SATA_P0IS_TOG(v)    (HW_SATA_P0IS_WR(HW_SATA_P0IS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_P0IS bitfields
 */

/* --- Register HW_SATA_P0IS, field DHRS[0] (RO)
 *
 * Device to Host Register FIS Interrupt A D2H Register FIS has been received with the 'I' bit set,
 * and has been copied into system memory.
 */

#define BP_SATA_P0IS_DHRS      (0)      //!< Bit position for SATA_P0IS_DHRS.
#define BM_SATA_P0IS_DHRS      (0x00000001)  //!< Bit mask for SATA_P0IS_DHRS.

//! @brief Get value of SATA_P0IS_DHRS from a register value.
#define BG_SATA_P0IS_DHRS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IS_DHRS) >> BP_SATA_P0IS_DHRS)

/* --- Register HW_SATA_P0IS, field PSS[1] (RO)
 *
 * PIO Setup FIS Interrupt. A PIO Setup FIS has been received with the 'I' bit set, it has been
 * copied into system memory, and the data related to that FIS has been transferred. This bit is set
 * even when the data transfer resulted in an error.
 */

#define BP_SATA_P0IS_PSS      (1)      //!< Bit position for SATA_P0IS_PSS.
#define BM_SATA_P0IS_PSS      (0x00000002)  //!< Bit mask for SATA_P0IS_PSS.

//! @brief Get value of SATA_P0IS_PSS from a register value.
#define BG_SATA_P0IS_PSS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IS_PSS) >> BP_SATA_P0IS_PSS)

/* --- Register HW_SATA_P0IS, field DSS[2] (RO)
 *
 * DMA Setup FIS Interrupt A DMA Setup FIS has been received with the 'I' bit set and has been
 * copied into system memory.
 */

#define BP_SATA_P0IS_DSS      (2)      //!< Bit position for SATA_P0IS_DSS.
#define BM_SATA_P0IS_DSS      (0x00000004)  //!< Bit mask for SATA_P0IS_DSS.

//! @brief Get value of SATA_P0IS_DSS from a register value.
#define BG_SATA_P0IS_DSS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IS_DSS) >> BP_SATA_P0IS_DSS)

/* --- Register HW_SATA_P0IS, field SDBS[3] (RO)
 *
 * Set Device Bits Interrupt. A Set Device Bits FIS has been received with the 'I' bit set and has
 * been copied into system memory.
 */

#define BP_SATA_P0IS_SDBS      (3)      //!< Bit position for SATA_P0IS_SDBS.
#define BM_SATA_P0IS_SDBS      (0x00000008)  //!< Bit mask for SATA_P0IS_SDBS.

//! @brief Get value of SATA_P0IS_SDBS from a register value.
#define BG_SATA_P0IS_SDBS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IS_SDBS) >> BP_SATA_P0IS_SDBS)

/* --- Register HW_SATA_P0IS, field UFS[4] (RO)
 *
 * Unknown FIS Interrupt. When set to 1, indicates that an unknown FIS was received and has been
 * copied into system memory. This bit is cleared to 0 by the software clearing the SATA_P # 0
 * SERR[DIAG_F] bit to 0. The UFS bit does not directly reflect the SATA_P # 0 SERR[DIAG_F] bit.
 * SATA_P # 0 SERR[DIAG_F] bit is set immediately when an unknown FIS is detected, whereas the UFS
 * bit is set when that FIS is posted to memory. The software should wait to act on an unknown FIS
 * until the UFS bit is set to 1 or the two bits may become out of sync.
 */

#define BP_SATA_P0IS_UFS      (4)      //!< Bit position for SATA_P0IS_UFS.
#define BM_SATA_P0IS_UFS      (0x00000010)  //!< Bit mask for SATA_P0IS_UFS.

//! @brief Get value of SATA_P0IS_UFS from a register value.
#define BG_SATA_P0IS_UFS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IS_UFS) >> BP_SATA_P0IS_UFS)

/* --- Register HW_SATA_P0IS, field DPS[5] (RO)
 *
 * Descriptor Processed A PRD with the I bit set has transferred all of its data. This is an
 * opportunistic interrupt and must not be used to definitively indicate the end of a transfer. Two
 * PRD interrupts could happen close in time together such that the second interrupt is missed when
 * the first PRD interrupt is being cleared.
 */

#define BP_SATA_P0IS_DPS      (5)      //!< Bit position for SATA_P0IS_DPS.
#define BM_SATA_P0IS_DPS      (0x00000020)  //!< Bit mask for SATA_P0IS_DPS.

//! @brief Get value of SATA_P0IS_DPS from a register value.
#define BG_SATA_P0IS_DPS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IS_DPS) >> BP_SATA_P0IS_DPS)

/* --- Register HW_SATA_P0IS, field PCS[6] (RO)
 *
 * Port Connect Change Status This bit is cleared only when SATA_P # 0 SERR[DIAG_X] is cleared. This
 * bit reflects the state of the SATA_P # 0 SERR[DIAG_X] bit:
 *
 * Values:
 * 0 - No change in Current Connect Status.
 * 1 - Change in Current Connect Status;
 */

#define BP_SATA_P0IS_PCS      (6)      //!< Bit position for SATA_P0IS_PCS.
#define BM_SATA_P0IS_PCS      (0x00000040)  //!< Bit mask for SATA_P0IS_PCS.

//! @brief Get value of SATA_P0IS_PCS from a register value.
#define BG_SATA_P0IS_PCS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IS_PCS) >> BP_SATA_P0IS_PCS)


/* --- Register HW_SATA_P0IS, field PRCS[22] (RO)
 *
 * PHY Ready Change Status This bit reflects the state of the SATA_P # 0 SERR[DIAG_N] bit. When set
 * to 1, indicates the internal p # 0 _phy_ready signal changed state. To clear this bit, the
 * software must clear the SATA_P # 0 SERR[DIAG_N] bit to 0.
 */

#define BP_SATA_P0IS_PRCS      (22)      //!< Bit position for SATA_P0IS_PRCS.
#define BM_SATA_P0IS_PRCS      (0x00400000)  //!< Bit mask for SATA_P0IS_PRCS.

//! @brief Get value of SATA_P0IS_PRCS from a register value.
#define BG_SATA_P0IS_PRCS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IS_PRCS) >> BP_SATA_P0IS_PRCS)

/* --- Register HW_SATA_P0IS, field IPMS[23] (RO)
 *
 * Incorrect Port Multiplier Status. Indicates that the HBA received a FIS from a device whose Port
 * Multiplier field did not match what was expected. This bit may be set during enumeration of
 * devices on a Port Multiplier due to the normal Port Multiplier enumeration process. The software
 * must use the IPMS bit only after enumeration is complete on the Port Multiplier.
 */

#define BP_SATA_P0IS_IPMS      (23)      //!< Bit position for SATA_P0IS_IPMS.
#define BM_SATA_P0IS_IPMS      (0x00800000)  //!< Bit mask for SATA_P0IS_IPMS.

//! @brief Get value of SATA_P0IS_IPMS from a register value.
#define BG_SATA_P0IS_IPMS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IS_IPMS) >> BP_SATA_P0IS_IPMS)

/* --- Register HW_SATA_P0IS, field OFS[24] (RO)
 *
 * Overflow Status This bit is set when command list overflow is detected during read or write
 * operation when the software builds command table that has fever total bytes than the transaction
 * given to the device. Port DMA transitions to a fatal state until the software clears SATA_P # 0
 * CMD[ST] bit or resets the interface by way of Port or Global reset.
 */

#define BP_SATA_P0IS_OFS      (24)      //!< Bit position for SATA_P0IS_OFS.
#define BM_SATA_P0IS_OFS      (0x01000000)  //!< Bit mask for SATA_P0IS_OFS.

//! @brief Get value of SATA_P0IS_OFS from a register value.
#define BG_SATA_P0IS_OFS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IS_OFS) >> BP_SATA_P0IS_OFS)

/* --- Register HW_SATA_P0IS, field INFS[26] (RO)
 *
 * Interface Non-fatal Error Status This bit is set when any of the following conditions is
 * detected: • One or more of the following errors are detected during non-data FIS transfer - 10B
 * to 8B Decode Error (SATA_P # 0 SERR[DIAG_B]) - Protocol (SATA_P # 0 SERR[ERR_P]) - CRC (SATA_P #
 * 0 SERR[DIAG_C]), - Handshake (SATA_P # 0 SERR[DIAG_H]) - PHY Not Ready (SATA_P # 0 SERR[ERR_C]);
 * • Command list underflow during read operation (i.e. DMA read) when the software builds command
 * table that has more total bytes than the transaction given to the device.
 */

#define BP_SATA_P0IS_INFS      (26)      //!< Bit position for SATA_P0IS_INFS.
#define BM_SATA_P0IS_INFS      (0x04000000)  //!< Bit mask for SATA_P0IS_INFS.

//! @brief Get value of SATA_P0IS_INFS from a register value.
#define BG_SATA_P0IS_INFS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IS_INFS) >> BP_SATA_P0IS_INFS)

/* --- Register HW_SATA_P0IS, field IFS[27] (RO)
 *
 * Interface Fatal Error Status This bit is set when any of the following conditions is detected: •
 * SYNC escape is received from the device during H2D Register or Data FIS transmission; • One or
 * more of the following errors are detected during Data FIS transfer: - 10B to 8B Decode Error
 * (SATA_P # 0 SERR[DIAG_B]) - Protocol (SATA_P # 0 SERR[ERR_P]) - CRC (SATA_P # 0 SERR[DIAG_C]) -
 * Handshake (SATA_P # 0 SERR[DIAG_H]) - PHY Not Ready (SATA_P # 0 SERR[ERR_C]) • Unknown FIS is
 * received with good CRC, but the length exceeds 64 bytes; • PRD table byte count is zero. Port DMA
 * transitions to a fatal state until the software clears SATA_P # 0 CMD[ST] bit or resets the
 * interface by way of Port or Global reset.
 */

#define BP_SATA_P0IS_IFS      (27)      //!< Bit position for SATA_P0IS_IFS.
#define BM_SATA_P0IS_IFS      (0x08000000)  //!< Bit mask for SATA_P0IS_IFS.

//! @brief Get value of SATA_P0IS_IFS from a register value.
#define BG_SATA_P0IS_IFS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IS_IFS) >> BP_SATA_P0IS_IFS)

/* --- Register HW_SATA_P0IS, field HBDS[28] (RO)
 *
 * Host Bus Data Error Status. This bit is always cleared to 0.
 */

#define BP_SATA_P0IS_HBDS      (28)      //!< Bit position for SATA_P0IS_HBDS.
#define BM_SATA_P0IS_HBDS      (0x10000000)  //!< Bit mask for SATA_P0IS_HBDS.

//! @brief Get value of SATA_P0IS_HBDS from a register value.
#define BG_SATA_P0IS_HBDS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IS_HBDS) >> BP_SATA_P0IS_HBDS)

/* --- Register HW_SATA_P0IS, field HBFS[29] (RO)
 *
 * Host Bus Fatal Error Status. This bit is set when SATA block AHB Master detects an ERROR response
 * from the slave.
 */

#define BP_SATA_P0IS_HBFS      (29)      //!< Bit position for SATA_P0IS_HBFS.
#define BM_SATA_P0IS_HBFS      (0x20000000)  //!< Bit mask for SATA_P0IS_HBFS.

//! @brief Get value of SATA_P0IS_HBFS from a register value.
#define BG_SATA_P0IS_HBFS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IS_HBFS) >> BP_SATA_P0IS_HBFS)

/* --- Register HW_SATA_P0IS, field TFES[30] (RO)
 *
 * Task File Error Status. This bit is set whenever the SATA_P # 0 TFD[STS] register is updated by
 * the device and the error bit (bit 0) is set.
 */

#define BP_SATA_P0IS_TFES      (30)      //!< Bit position for SATA_P0IS_TFES.
#define BM_SATA_P0IS_TFES      (0x40000000)  //!< Bit mask for SATA_P0IS_TFES.

//! @brief Get value of SATA_P0IS_TFES from a register value.
#define BG_SATA_P0IS_TFES(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IS_TFES) >> BP_SATA_P0IS_TFES)

//-------------------------------------------------------------------------------------------
// HW_SATA_P0IE - Port0 Interrupt Enable Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_P0IE - Port0 Interrupt Enable Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register enables and disables the reporting of the corresponding interrupt to the software.
 * When a bit is set (1), and the corresponding interrupt condition is active, then the SATA block
 * intrq output is asserted. Interrupt sources that are disabled (0) are still reflected in the
 * status registers. This register is symmetrical with the SATA_P #  0 IS register. This register is
 * reset on Global SATA block reset.   Size: 32 bits  Address offset: for # = 0 to 7:   P0IE: 0x114
 * P0IE: 0x194  P0IE: 0x214  P0IE: 0x294  P0IE: 0x314  P0IE: 0x394  P0IE: 0x414  P0IE: 0x494
 * Read/write access: Read/write  Reset: 0x0000_0000
 */
typedef union _hw_sata_p0ie
{
    reg32_t U;
    struct _hw_sata_p0ie_bitfields
    {
        unsigned DHRE : 1; //!< [0] Device to Host Register FIS Interrupt Dependencies: when the following conditions are true, the intrq output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[DHRS]=1
        unsigned PSE : 1; //!< [1] PIO Setup FIS Interrupt Enable Dependencies: when the following conditions are true, the intrq output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[PSS]=1
        unsigned DSE : 1; //!< [2] DMA Setup FIS Interrupt Enable Dependencies: when the following conditions are true, the intrq output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[DSS]=1
        unsigned SDBE : 1; //!< [3] Set Device Bits FIS Interrupt Enable Dependencies: when the following conditions are true, the intrq output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[SDBS]=1
        unsigned UFE : 1; //!< [4] Unknown FIS Interrupt Enable Dependencies: when the following conditions are true, the intrq output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[UFS]=1
        unsigned DPE : 1; //!< [5] Descriptor Processed Interrupt Enable Dependencies: when the following conditions are true, the intrq output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[DPS]=1
        unsigned PCE : 1; //!< [6] Port Change Interrupt Enable Dependencies: when the following conditions are true, the intrq output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[PCS]=1
        unsigned RESERVED0 : 15; //!< [21:7] Reserved.
        unsigned PRCE : 1; //!< [22] PHY Ready Change Enable Dependencies: when the following conditions are true, the intrq output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[PRCS]=1
        unsigned IPME : 1; //!< [23] Incorrect Port Multiplier Enable Dependencies: when the following conditions are true, the intrq output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[IPMS]=1
        unsigned OFE : 1; //!< [24] Overflow Enable Dependencies: when the following conditions are true, the intrq output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[OFS]=1
        unsigned RESERVED1 : 1; //!< [25] Reserved
        unsigned INFE : 1; //!< [26] Interface Non-Fatal Error Enable Dependencies: when the following conditions are true, the intrq output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[INFS]=1
        unsigned IFE : 1; //!< [27] Dependencies: when the following conditions are true, the intrq output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[IFS]=1
        unsigned HBDE : 1; //!< [28] Host Bus Data Error Enable Dependencies: when the following conditions are true, the intrq output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[HBDS]=1
        unsigned HBFE : 1; //!< [29] Host Bus Fatal Error Enable Dependencies: when the following conditions are true, the intrq output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[HBFS]=1
        unsigned TFEE : 1; //!< [30] Task File Error Enable Dependencies: when the following conditions are true, the intrq output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[TFES]=1
        unsigned CPDE : 1; //!< [31] Cold Port Detect Enable Read-only. Returns 0. The options for this field are: • When DEV_CP_DET=Include, this bit is read/write. • When DEV_CP_DET=Exclude, this bit is read-only 0. Dependencies: when the following conditions are true, the intrq output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • P#IS[CPDS]=1
    } B;
} hw_sata_p0ie_t;
#endif

/*
 * constants & macros for entire SATA_P0IE register
 */
#define HW_SATA_P0IE_ADDR      (REGS_SATA_BASE + 0x114)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0IE           (*(volatile hw_sata_p0ie_t *) HW_SATA_P0IE_ADDR)
#define HW_SATA_P0IE_RD()      (HW_SATA_P0IE.U)
#define HW_SATA_P0IE_WR(v)     (HW_SATA_P0IE.U = (v))
#define HW_SATA_P0IE_SET(v)    (HW_SATA_P0IE_WR(HW_SATA_P0IE_RD() |  (v)))
#define HW_SATA_P0IE_CLR(v)    (HW_SATA_P0IE_WR(HW_SATA_P0IE_RD() & ~(v)))
#define HW_SATA_P0IE_TOG(v)    (HW_SATA_P0IE_WR(HW_SATA_P0IE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_P0IE bitfields
 */

/* --- Register HW_SATA_P0IE, field DHRE[0] (RW)
 *
 * Device to Host Register FIS Interrupt Dependencies: when the following conditions are true, the
 * intrq output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[DHRS]=1
 */

#define BP_SATA_P0IE_DHRE      (0)      //!< Bit position for SATA_P0IE_DHRE.
#define BM_SATA_P0IE_DHRE      (0x00000001)  //!< Bit mask for SATA_P0IE_DHRE.

//! @brief Get value of SATA_P0IE_DHRE from a register value.
#define BG_SATA_P0IE_DHRE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IE_DHRE) >> BP_SATA_P0IE_DHRE)

//! @brief Format value for bitfield SATA_P0IE_DHRE.
#define BF_SATA_P0IE_DHRE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0IE_DHRE) & BM_SATA_P0IE_DHRE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DHRE field to a new value.
#define BW_SATA_P0IE_DHRE(v)   (HW_SATA_P0IE_WR((HW_SATA_P0IE_RD() & ~BM_SATA_P0IE_DHRE) | BF_SATA_P0IE_DHRE(v)))
#endif

/* --- Register HW_SATA_P0IE, field PSE[1] (RW)
 *
 * PIO Setup FIS Interrupt Enable Dependencies: when the following conditions are true, the intrq
 * output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[PSS]=1
 */

#define BP_SATA_P0IE_PSE      (1)      //!< Bit position for SATA_P0IE_PSE.
#define BM_SATA_P0IE_PSE      (0x00000002)  //!< Bit mask for SATA_P0IE_PSE.

//! @brief Get value of SATA_P0IE_PSE from a register value.
#define BG_SATA_P0IE_PSE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IE_PSE) >> BP_SATA_P0IE_PSE)

//! @brief Format value for bitfield SATA_P0IE_PSE.
#define BF_SATA_P0IE_PSE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0IE_PSE) & BM_SATA_P0IE_PSE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PSE field to a new value.
#define BW_SATA_P0IE_PSE(v)   (HW_SATA_P0IE_WR((HW_SATA_P0IE_RD() & ~BM_SATA_P0IE_PSE) | BF_SATA_P0IE_PSE(v)))
#endif

/* --- Register HW_SATA_P0IE, field DSE[2] (RW)
 *
 * DMA Setup FIS Interrupt Enable Dependencies: when the following conditions are true, the intrq
 * output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[DSS]=1
 */

#define BP_SATA_P0IE_DSE      (2)      //!< Bit position for SATA_P0IE_DSE.
#define BM_SATA_P0IE_DSE      (0x00000004)  //!< Bit mask for SATA_P0IE_DSE.

//! @brief Get value of SATA_P0IE_DSE from a register value.
#define BG_SATA_P0IE_DSE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IE_DSE) >> BP_SATA_P0IE_DSE)

//! @brief Format value for bitfield SATA_P0IE_DSE.
#define BF_SATA_P0IE_DSE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0IE_DSE) & BM_SATA_P0IE_DSE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DSE field to a new value.
#define BW_SATA_P0IE_DSE(v)   (HW_SATA_P0IE_WR((HW_SATA_P0IE_RD() & ~BM_SATA_P0IE_DSE) | BF_SATA_P0IE_DSE(v)))
#endif

/* --- Register HW_SATA_P0IE, field SDBE[3] (RW)
 *
 * Set Device Bits FIS Interrupt Enable Dependencies: when the following conditions are true, the
 * intrq output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[SDBS]=1
 */

#define BP_SATA_P0IE_SDBE      (3)      //!< Bit position for SATA_P0IE_SDBE.
#define BM_SATA_P0IE_SDBE      (0x00000008)  //!< Bit mask for SATA_P0IE_SDBE.

//! @brief Get value of SATA_P0IE_SDBE from a register value.
#define BG_SATA_P0IE_SDBE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IE_SDBE) >> BP_SATA_P0IE_SDBE)

//! @brief Format value for bitfield SATA_P0IE_SDBE.
#define BF_SATA_P0IE_SDBE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0IE_SDBE) & BM_SATA_P0IE_SDBE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SDBE field to a new value.
#define BW_SATA_P0IE_SDBE(v)   (HW_SATA_P0IE_WR((HW_SATA_P0IE_RD() & ~BM_SATA_P0IE_SDBE) | BF_SATA_P0IE_SDBE(v)))
#endif

/* --- Register HW_SATA_P0IE, field UFE[4] (RW)
 *
 * Unknown FIS Interrupt Enable Dependencies: when the following conditions are true, the intrq
 * output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[UFS]=1
 */

#define BP_SATA_P0IE_UFE      (4)      //!< Bit position for SATA_P0IE_UFE.
#define BM_SATA_P0IE_UFE      (0x00000010)  //!< Bit mask for SATA_P0IE_UFE.

//! @brief Get value of SATA_P0IE_UFE from a register value.
#define BG_SATA_P0IE_UFE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IE_UFE) >> BP_SATA_P0IE_UFE)

//! @brief Format value for bitfield SATA_P0IE_UFE.
#define BF_SATA_P0IE_UFE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0IE_UFE) & BM_SATA_P0IE_UFE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the UFE field to a new value.
#define BW_SATA_P0IE_UFE(v)   (HW_SATA_P0IE_WR((HW_SATA_P0IE_RD() & ~BM_SATA_P0IE_UFE) | BF_SATA_P0IE_UFE(v)))
#endif

/* --- Register HW_SATA_P0IE, field DPE[5] (RW)
 *
 * Descriptor Processed Interrupt Enable Dependencies: when the following conditions are true, the
 * intrq output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[DPS]=1
 */

#define BP_SATA_P0IE_DPE      (5)      //!< Bit position for SATA_P0IE_DPE.
#define BM_SATA_P0IE_DPE      (0x00000020)  //!< Bit mask for SATA_P0IE_DPE.

//! @brief Get value of SATA_P0IE_DPE from a register value.
#define BG_SATA_P0IE_DPE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IE_DPE) >> BP_SATA_P0IE_DPE)

//! @brief Format value for bitfield SATA_P0IE_DPE.
#define BF_SATA_P0IE_DPE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0IE_DPE) & BM_SATA_P0IE_DPE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DPE field to a new value.
#define BW_SATA_P0IE_DPE(v)   (HW_SATA_P0IE_WR((HW_SATA_P0IE_RD() & ~BM_SATA_P0IE_DPE) | BF_SATA_P0IE_DPE(v)))
#endif

/* --- Register HW_SATA_P0IE, field PCE[6] (RW)
 *
 * Port Change Interrupt Enable Dependencies: when the following conditions are true, the intrq
 * output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[PCS]=1
 */

#define BP_SATA_P0IE_PCE      (6)      //!< Bit position for SATA_P0IE_PCE.
#define BM_SATA_P0IE_PCE      (0x00000040)  //!< Bit mask for SATA_P0IE_PCE.

//! @brief Get value of SATA_P0IE_PCE from a register value.
#define BG_SATA_P0IE_PCE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IE_PCE) >> BP_SATA_P0IE_PCE)

//! @brief Format value for bitfield SATA_P0IE_PCE.
#define BF_SATA_P0IE_PCE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0IE_PCE) & BM_SATA_P0IE_PCE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PCE field to a new value.
#define BW_SATA_P0IE_PCE(v)   (HW_SATA_P0IE_WR((HW_SATA_P0IE_RD() & ~BM_SATA_P0IE_PCE) | BF_SATA_P0IE_PCE(v)))
#endif

/* --- Register HW_SATA_P0IE, field PRCE[22] (RW)
 *
 * PHY Ready Change Enable Dependencies: when the following conditions are true, the intrq output
 * signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[PRCS]=1
 */

#define BP_SATA_P0IE_PRCE      (22)      //!< Bit position for SATA_P0IE_PRCE.
#define BM_SATA_P0IE_PRCE      (0x00400000)  //!< Bit mask for SATA_P0IE_PRCE.

//! @brief Get value of SATA_P0IE_PRCE from a register value.
#define BG_SATA_P0IE_PRCE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IE_PRCE) >> BP_SATA_P0IE_PRCE)

//! @brief Format value for bitfield SATA_P0IE_PRCE.
#define BF_SATA_P0IE_PRCE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0IE_PRCE) & BM_SATA_P0IE_PRCE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PRCE field to a new value.
#define BW_SATA_P0IE_PRCE(v)   (HW_SATA_P0IE_WR((HW_SATA_P0IE_RD() & ~BM_SATA_P0IE_PRCE) | BF_SATA_P0IE_PRCE(v)))
#endif

/* --- Register HW_SATA_P0IE, field IPME[23] (RW)
 *
 * Incorrect Port Multiplier Enable Dependencies: when the following conditions are true, the intrq
 * output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[IPMS]=1
 */

#define BP_SATA_P0IE_IPME      (23)      //!< Bit position for SATA_P0IE_IPME.
#define BM_SATA_P0IE_IPME      (0x00800000)  //!< Bit mask for SATA_P0IE_IPME.

//! @brief Get value of SATA_P0IE_IPME from a register value.
#define BG_SATA_P0IE_IPME(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IE_IPME) >> BP_SATA_P0IE_IPME)

//! @brief Format value for bitfield SATA_P0IE_IPME.
#define BF_SATA_P0IE_IPME(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0IE_IPME) & BM_SATA_P0IE_IPME)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPME field to a new value.
#define BW_SATA_P0IE_IPME(v)   (HW_SATA_P0IE_WR((HW_SATA_P0IE_RD() & ~BM_SATA_P0IE_IPME) | BF_SATA_P0IE_IPME(v)))
#endif

/* --- Register HW_SATA_P0IE, field OFE[24] (RW)
 *
 * Overflow Enable Dependencies: when the following conditions are true, the intrq output signal is
 * asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[OFS]=1
 */

#define BP_SATA_P0IE_OFE      (24)      //!< Bit position for SATA_P0IE_OFE.
#define BM_SATA_P0IE_OFE      (0x01000000)  //!< Bit mask for SATA_P0IE_OFE.

//! @brief Get value of SATA_P0IE_OFE from a register value.
#define BG_SATA_P0IE_OFE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IE_OFE) >> BP_SATA_P0IE_OFE)

//! @brief Format value for bitfield SATA_P0IE_OFE.
#define BF_SATA_P0IE_OFE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0IE_OFE) & BM_SATA_P0IE_OFE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFE field to a new value.
#define BW_SATA_P0IE_OFE(v)   (HW_SATA_P0IE_WR((HW_SATA_P0IE_RD() & ~BM_SATA_P0IE_OFE) | BF_SATA_P0IE_OFE(v)))
#endif

/* --- Register HW_SATA_P0IE, field INFE[26] (RW)
 *
 * Interface Non-Fatal Error Enable Dependencies: when the following conditions are true, the intrq
 * output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[INFS]=1
 */

#define BP_SATA_P0IE_INFE      (26)      //!< Bit position for SATA_P0IE_INFE.
#define BM_SATA_P0IE_INFE      (0x04000000)  //!< Bit mask for SATA_P0IE_INFE.

//! @brief Get value of SATA_P0IE_INFE from a register value.
#define BG_SATA_P0IE_INFE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IE_INFE) >> BP_SATA_P0IE_INFE)

//! @brief Format value for bitfield SATA_P0IE_INFE.
#define BF_SATA_P0IE_INFE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0IE_INFE) & BM_SATA_P0IE_INFE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the INFE field to a new value.
#define BW_SATA_P0IE_INFE(v)   (HW_SATA_P0IE_WR((HW_SATA_P0IE_RD() & ~BM_SATA_P0IE_INFE) | BF_SATA_P0IE_INFE(v)))
#endif

/* --- Register HW_SATA_P0IE, field IFE[27] (RW)
 *
 * Dependencies: when the following conditions are true, the intrq output signal is asserted: • This
 * bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[IFS]=1
 */

#define BP_SATA_P0IE_IFE      (27)      //!< Bit position for SATA_P0IE_IFE.
#define BM_SATA_P0IE_IFE      (0x08000000)  //!< Bit mask for SATA_P0IE_IFE.

//! @brief Get value of SATA_P0IE_IFE from a register value.
#define BG_SATA_P0IE_IFE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IE_IFE) >> BP_SATA_P0IE_IFE)

//! @brief Format value for bitfield SATA_P0IE_IFE.
#define BF_SATA_P0IE_IFE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0IE_IFE) & BM_SATA_P0IE_IFE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IFE field to a new value.
#define BW_SATA_P0IE_IFE(v)   (HW_SATA_P0IE_WR((HW_SATA_P0IE_RD() & ~BM_SATA_P0IE_IFE) | BF_SATA_P0IE_IFE(v)))
#endif

/* --- Register HW_SATA_P0IE, field HBDE[28] (RW)
 *
 * Host Bus Data Error Enable Dependencies: when the following conditions are true, the intrq output
 * signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[HBDS]=1
 */

#define BP_SATA_P0IE_HBDE      (28)      //!< Bit position for SATA_P0IE_HBDE.
#define BM_SATA_P0IE_HBDE      (0x10000000)  //!< Bit mask for SATA_P0IE_HBDE.

//! @brief Get value of SATA_P0IE_HBDE from a register value.
#define BG_SATA_P0IE_HBDE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IE_HBDE) >> BP_SATA_P0IE_HBDE)

//! @brief Format value for bitfield SATA_P0IE_HBDE.
#define BF_SATA_P0IE_HBDE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0IE_HBDE) & BM_SATA_P0IE_HBDE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HBDE field to a new value.
#define BW_SATA_P0IE_HBDE(v)   (HW_SATA_P0IE_WR((HW_SATA_P0IE_RD() & ~BM_SATA_P0IE_HBDE) | BF_SATA_P0IE_HBDE(v)))
#endif

/* --- Register HW_SATA_P0IE, field HBFE[29] (RW)
 *
 * Host Bus Fatal Error Enable Dependencies: when the following conditions are true, the intrq
 * output signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[HBFS]=1
 */

#define BP_SATA_P0IE_HBFE      (29)      //!< Bit position for SATA_P0IE_HBFE.
#define BM_SATA_P0IE_HBFE      (0x20000000)  //!< Bit mask for SATA_P0IE_HBFE.

//! @brief Get value of SATA_P0IE_HBFE from a register value.
#define BG_SATA_P0IE_HBFE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IE_HBFE) >> BP_SATA_P0IE_HBFE)

//! @brief Format value for bitfield SATA_P0IE_HBFE.
#define BF_SATA_P0IE_HBFE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0IE_HBFE) & BM_SATA_P0IE_HBFE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HBFE field to a new value.
#define BW_SATA_P0IE_HBFE(v)   (HW_SATA_P0IE_WR((HW_SATA_P0IE_RD() & ~BM_SATA_P0IE_HBFE) | BF_SATA_P0IE_HBFE(v)))
#endif

/* --- Register HW_SATA_P0IE, field TFEE[30] (RW)
 *
 * Task File Error Enable Dependencies: when the following conditions are true, the intrq output
 * signal is asserted: • This bit=1 • SATA_GHC[IE]=1 • SATA_P # 0 IS[TFES]=1
 */

#define BP_SATA_P0IE_TFEE      (30)      //!< Bit position for SATA_P0IE_TFEE.
#define BM_SATA_P0IE_TFEE      (0x40000000)  //!< Bit mask for SATA_P0IE_TFEE.

//! @brief Get value of SATA_P0IE_TFEE from a register value.
#define BG_SATA_P0IE_TFEE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IE_TFEE) >> BP_SATA_P0IE_TFEE)

//! @brief Format value for bitfield SATA_P0IE_TFEE.
#define BF_SATA_P0IE_TFEE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0IE_TFEE) & BM_SATA_P0IE_TFEE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFEE field to a new value.
#define BW_SATA_P0IE_TFEE(v)   (HW_SATA_P0IE_WR((HW_SATA_P0IE_RD() & ~BM_SATA_P0IE_TFEE) | BF_SATA_P0IE_TFEE(v)))
#endif

/* --- Register HW_SATA_P0IE, field CPDE[31] (RW)
 *
 * Cold Port Detect Enable Read-only. Returns 0. The options for this field are: • When
 * DEV_CP_DET=Include, this bit is read/write. • When DEV_CP_DET=Exclude, this bit is read-only 0.
 * Dependencies: when the following conditions are true, the intrq output signal is asserted: • This
 * bit=1 • SATA_GHC[IE]=1 • P#IS[CPDS]=1
 */

#define BP_SATA_P0IE_CPDE      (31)      //!< Bit position for SATA_P0IE_CPDE.
#define BM_SATA_P0IE_CPDE      (0x80000000)  //!< Bit mask for SATA_P0IE_CPDE.

//! @brief Get value of SATA_P0IE_CPDE from a register value.
#define BG_SATA_P0IE_CPDE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0IE_CPDE) >> BP_SATA_P0IE_CPDE)

//! @brief Format value for bitfield SATA_P0IE_CPDE.
#define BF_SATA_P0IE_CPDE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0IE_CPDE) & BM_SATA_P0IE_CPDE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CPDE field to a new value.
#define BW_SATA_P0IE_CPDE(v)   (HW_SATA_P0IE_WR((HW_SATA_P0IE_RD() & ~BM_SATA_P0IE_CPDE) | BF_SATA_P0IE_CPDE(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_SATA_P0CMD - Port0 Command Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_P0CMD - Port0 Command Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register contains bits controlling various Port functions. All RW bits are reset on Global
 * reset.   Size: 32 bits  Address offset: for # = 0 to 7:  P0CMD: 0x118  P1CMD: 0x198  P2CMD: 0x218
 * P3CMD: 0x298  P4CMD: 0x318  P5CMD: 0x398  P6CMD: 0x418  P7CMD: 0x498    Read/write access: (See
 * table below)  Reset: 0x0000_0000
 */
typedef union _hw_sata_p0cmd
{
    reg32_t U;
    struct _hw_sata_p0cmd_bitfields
    {
        unsigned ST : 1; //!< [0] Start When set to 1, the Port processes the command list. When cleared, the Port does not process the command list. Whenever this bit is changed from a 0 to a 1, the Port starts processing the command list at entry'0. Whenever this bit is changed from a 1 to a 0, the SATA_P # 0 CI register is cleared by the Port upon transition into an idle state. Refer to AHCI specification, section 10.3.1, for important restrictions on when this bit can be set to 1. Note: SATA_P # 0 SERR register must be cleared prior to setting ST bit to 1.
        unsigned SUD : 1; //!< [1] Spin-Up Device This bit is read/write when staggered spin-up is supported as indicated by the SATA_CAP[SSS]=1. This bit is read-only 1 when staggered spin-up is not supported and SATA_CAP[SSS]=0. On an edge detect from 0 to 1, the Port starts a COMRESET initialization sequence to the device. Clearing this bit causes no action on the interface. Note: The SUD bit is read-only 0 on power-up until SATA_CAP[SSS] bit is written with the required value.
        unsigned POD : 1; //!< [2] Power On Device This bit is read/write when cold presence detection is supported on this Port as indicated by SATA_P # 0 CMD[CPD]=1. This bit is read-only 1 when cold presence detection is not supported and SATA_P # 0 CMD[CPD]=0. When set, the Port asserts the p # 0 _cp_pod output pin so that it may be used to provide power to a cold-presence detectable Port.
        unsigned CLO : 1; //!< [3] Command List Override Setting this bit to 1 causes the SATA_P # 0 TFD[STS] field BSY bit and the SATA_P # 0 TFD[STS] field DRQ bit to be cleared. This allows a software reset to be transmitted to the device regardless of whether the BSY and DRQ bits are still set in the SATA_P # 0 TFD[STS] field. This bit is cleared to 0 when SATA_P # 0 TFD[STS] BSY bit and SATA_P # 0 TFD[STS] DRQ bit have been cleared. A write to this register with a value of '0' has no effect. This bit should only be set to 1 immediately prior to setting SATA_P # 0 CMD[ST] bit to 1 from a previous value of 0. Setting this bit to 1 at any other time is not supported and results in indeterminate behavior.
        unsigned FRE : 1; //!< [4] FIS Receive Enable When set to 1, the Port may post received FISes into the FIS receive area pointed to by SATA_P # 0 FB (and P#FBU when M_HADDR_WIDTH=64) . When cleared, received FISes are not accepted by the Port, except for the first D2H register FIS after the initialization sequence, and no FISes are posted to the FIS receive area. The software must not set this bit until SATA_P # 0 FB (P#FBU) has been programmed with a valid pointer to the FIS receive area When the software wishes to move the base, this bit must first be cleared, and the software must wait for the SATA_P # 0 CMD[FR] bit to be cleared.
        unsigned RESERVED0 : 3; //!< [7:5] Reserved.
        unsigned CCS : 5; //!< [12:8] Current Command Slot This field is set to the command slot value value of the command that is currently being issued by the Port. • When SATA_P # 0 CMD[ST] transitions from 1 to 0, this field is recleared to 0x00. • After SATA_P # 0 CMD[ST] transitions from 0 to 1, the highest priority slot to issue from next is command slot 0. After the first command has been issued, the highest priority slot to issue from next is SATA_P # 0 CMD[CCS]+1.For example, after the Port has issued its first command, when CCS=0x00 and SATA_P # 0 CI is cleared to 0x3, the next command issued is from command slot 1. This field is valid only when SATA_P # 0 CMD[ST] is set to 1.
        unsigned MPSS : 1; //!< [13] Mechanical Presence Switch State The software must use this bit only when both SATA_CAP[SMPS] and SATA_P # 0 CMD[MPSP] are set. This bit reports the state of a mechanical presence switch attached to this Port as indicated by the p # 0 _mp_switch input state (assuming SATA_CAP[SMPS]=1 and SATA_P # 0 CMD[MPSP]=1). The options for this field are: When SATA_CAP[SMPS]=0 then this bit is cleared to 0.
        unsigned FR : 1; //!< [14] FIS Receive Running When set to '1', the FIS Receive DMA engine for the Port is running. See AHCI specification section 10.3.2 for details on when this bit is set and cleared by the Port.
        unsigned CR : 1; //!< [15] Command List Running When this bit is set to '1', the command list DMA engine for this Port is running. See AHCI state machine in AHCI specification section 5.3.2 (this is a reference to an external document) for details on when this bit is set and cleared by the Port.
        unsigned CPS : 1; //!< [16] Cold Presence State This bit reports whether a device is currently detected on this Port as indicated by the p # 0 _cp_det input state (assuming SATA_P # 0 CMD[CPD]=1). The options for this field are:
        unsigned PMA : 1; //!< [17] Port Multiplier Attached The software is responsible for detecting whether a Port Multiplier is present; the SATA block Port does not auto-detect the presence of a Port Multiplier. The options for this field are:
        unsigned HPCP : 1; //!< [18] Hot Plug Capable Port The HPCP bit is mutually exclusive with SATA_P # 0 CMD[ESP]. The options for this field are:
        unsigned RESERVED1 : 2; //!< [20:19] Reserved.
        unsigned ESP : 1; //!< [21] External SATA Port When set to 1, indicates that this Port's signal only connector is externally accessible. When set to 1, SATA_CAP[SXS] is also set to 1. When cleared to 0, indicates that this Port's signal only connector is not externally accessible. Note: The ESP bit is mutually exclusive with SATA_P # 0 CMD[HPCP]
        unsigned RESERVED2 : 1; //!< [22] Reserved
        unsigned APSTE : 1; //!< [23] Device is ATAPI This bit is used by the Port to control whether to assert p # 0 _act_led output when commands are active (see " ) . The options for this field are:
        unsigned ATAPI : 1; //!< [24] ATAPI Device is ATAPI This bit is used by the Port to control whether to assert p # 0 _act_led output when commands are active (see " ) . The options for this field are:
        unsigned DLAE : 1; //!< [25] Drive LED on ATAPI Enable When set to 1, SATA_P # 0 CMD[ATAPI]=1, and commands are active, the Port asserts p # 0 _act_led output (see " ) .
        unsigned ALPE : 1; //!< [26] Aggressive Link Power Management Enable When set to 1, the Port aggressively enters a lower link power state (PARTIAL or SLUMBER) based on the setting of the SATA_P # 0 CMD[ASP] bit. When cleared to 0, aggressive power management state transition is disabled.
        unsigned ASP : 1; //!< [27] Aggressive Slumber/ Partial The options for this field are: • When set to 1, and SATA_P # 0 CMD[ALPE]=1, the Port aggressively enters the SLUMBER state when one of the following conditions is true: - The Port clears the SATA_P # 0 CI and the SATA_P # 0 SACT register is cleared. - The Port clears the SATA_P # 0 SACT register and SATA_P # 0 CI is cleared. • When cleared to 0, and SATA_P # 0 CMD[ALPE]=1, the Port aggressively enters the PARTIAL state when one of the following conditions is true: - The Port clears the SATA_P # 0 CI register and the SATA_P # 0 SACT register is cleared. - The Port clears the SATA_P # 0 SACT register and SATA_P # 0 CI is cleared.
        unsigned ICC : 4; //!< [31:28] Interface Communication Control This field is used to control power management states of the interface. When the Link layer is currently in the L_IDLE state, writes to this field cause the Port to initiate a transition to the interface power management state requested. When the Link layer is not currently in the L_IDLE state, writes to this field have no effect. • 0xF-0x7: Reserved • 0x6: Slumber. This causes the Port to request a transition of the interface to the Slumber state. The SATA device can reject the request and the interface remains in its current state. • 0x5-0x3: Reserved • 0x2: Partial. This causes the Port to request a transition of the interface to the Partial state. The SATA device can reject the request and the interface remains in its current state. • 0x1: Active. This causes the Port to request a transition of the interface into the active state. • 0x0: No-Op/ Idle. This value indicates to the software that the Port # 0 is ready to accept a new interface control command, although the transition to the previously selected state may not yet have occurred. When the software writes a non-reserved value other than No-Op (0x0), the Port performs the action and update this field back to Idle (0x0). When the software writes to this field to change the state to a state the link is already in (i.e., interface is in the active state and a request is made to go to the active state), the Port takes no action and returns this field to Idle. When the interface is in a low power state and the software wants to transition to a different low power state, the software must first bring the link to active and then initiate the transition to the desired low power state.
    } B;
} hw_sata_p0cmd_t;
#endif

/*
 * constants & macros for entire SATA_P0CMD register
 */
#define HW_SATA_P0CMD_ADDR      (REGS_SATA_BASE + 0x118)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0CMD           (*(volatile hw_sata_p0cmd_t *) HW_SATA_P0CMD_ADDR)
#define HW_SATA_P0CMD_RD()      (HW_SATA_P0CMD.U)
#define HW_SATA_P0CMD_WR(v)     (HW_SATA_P0CMD.U = (v))
#define HW_SATA_P0CMD_SET(v)    (HW_SATA_P0CMD_WR(HW_SATA_P0CMD_RD() |  (v)))
#define HW_SATA_P0CMD_CLR(v)    (HW_SATA_P0CMD_WR(HW_SATA_P0CMD_RD() & ~(v)))
#define HW_SATA_P0CMD_TOG(v)    (HW_SATA_P0CMD_WR(HW_SATA_P0CMD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_P0CMD bitfields
 */

/* --- Register HW_SATA_P0CMD, field ST[0] (RW)
 *
 * Start When set to 1, the Port processes the command list. When cleared, the Port does not process
 * the command list. Whenever this bit is changed from a 0 to a 1, the Port starts processing the
 * command list at entry'0. Whenever this bit is changed from a 1 to a 0, the SATA_P # 0 CI register
 * is cleared by the Port upon transition into an idle state. Refer to AHCI specification, section
 * 10.3.1, for important restrictions on when this bit can be set to 1. Note: SATA_P # 0 SERR
 * register must be cleared prior to setting ST bit to 1.
 */

#define BP_SATA_P0CMD_ST      (0)      //!< Bit position for SATA_P0CMD_ST.
#define BM_SATA_P0CMD_ST      (0x00000001)  //!< Bit mask for SATA_P0CMD_ST.

//! @brief Get value of SATA_P0CMD_ST from a register value.
#define BG_SATA_P0CMD_ST(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CMD_ST) >> BP_SATA_P0CMD_ST)

//! @brief Format value for bitfield SATA_P0CMD_ST.
#define BF_SATA_P0CMD_ST(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CMD_ST) & BM_SATA_P0CMD_ST)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ST field to a new value.
#define BW_SATA_P0CMD_ST(v)   (HW_SATA_P0CMD_WR((HW_SATA_P0CMD_RD() & ~BM_SATA_P0CMD_ST) | BF_SATA_P0CMD_ST(v)))
#endif

/* --- Register HW_SATA_P0CMD, field SUD[1] (RW)
 *
 * Spin-Up Device This bit is read/write when staggered spin-up is supported as indicated by the
 * SATA_CAP[SSS]=1. This bit is read-only 1 when staggered spin-up is not supported and
 * SATA_CAP[SSS]=0. On an edge detect from 0 to 1, the Port starts a COMRESET initialization
 * sequence to the device. Clearing this bit causes no action on the interface. Note: The SUD bit is
 * read-only 0 on power-up until SATA_CAP[SSS] bit is written with the required value.
 */

#define BP_SATA_P0CMD_SUD      (1)      //!< Bit position for SATA_P0CMD_SUD.
#define BM_SATA_P0CMD_SUD      (0x00000002)  //!< Bit mask for SATA_P0CMD_SUD.

//! @brief Get value of SATA_P0CMD_SUD from a register value.
#define BG_SATA_P0CMD_SUD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CMD_SUD) >> BP_SATA_P0CMD_SUD)

//! @brief Format value for bitfield SATA_P0CMD_SUD.
#define BF_SATA_P0CMD_SUD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CMD_SUD) & BM_SATA_P0CMD_SUD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SUD field to a new value.
#define BW_SATA_P0CMD_SUD(v)   (HW_SATA_P0CMD_WR((HW_SATA_P0CMD_RD() & ~BM_SATA_P0CMD_SUD) | BF_SATA_P0CMD_SUD(v)))
#endif

/* --- Register HW_SATA_P0CMD, field POD[2] (RW)
 *
 * Power On Device This bit is read/write when cold presence detection is supported on this Port as
 * indicated by SATA_P # 0 CMD[CPD]=1. This bit is read-only 1 when cold presence detection is not
 * supported and SATA_P # 0 CMD[CPD]=0. When set, the Port asserts the p # 0 _cp_pod output pin so
 * that it may be used to provide power to a cold-presence detectable Port.
 */

#define BP_SATA_P0CMD_POD      (2)      //!< Bit position for SATA_P0CMD_POD.
#define BM_SATA_P0CMD_POD      (0x00000004)  //!< Bit mask for SATA_P0CMD_POD.

//! @brief Get value of SATA_P0CMD_POD from a register value.
#define BG_SATA_P0CMD_POD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CMD_POD) >> BP_SATA_P0CMD_POD)

//! @brief Format value for bitfield SATA_P0CMD_POD.
#define BF_SATA_P0CMD_POD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CMD_POD) & BM_SATA_P0CMD_POD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POD field to a new value.
#define BW_SATA_P0CMD_POD(v)   (HW_SATA_P0CMD_WR((HW_SATA_P0CMD_RD() & ~BM_SATA_P0CMD_POD) | BF_SATA_P0CMD_POD(v)))
#endif

/* --- Register HW_SATA_P0CMD, field CLO[3] (RW)
 *
 * Command List Override Setting this bit to 1 causes the SATA_P # 0 TFD[STS] field BSY bit and the
 * SATA_P # 0 TFD[STS] field DRQ bit to be cleared. This allows a software reset to be transmitted
 * to the device regardless of whether the BSY and DRQ bits are still set in the SATA_P # 0 TFD[STS]
 * field. This bit is cleared to 0 when SATA_P # 0 TFD[STS] BSY bit and SATA_P # 0 TFD[STS] DRQ bit
 * have been cleared. A write to this register with a value of '0' has no effect. This bit should
 * only be set to 1 immediately prior to setting SATA_P # 0 CMD[ST] bit to 1 from a previous value
 * of 0. Setting this bit to 1 at any other time is not supported and results in indeterminate
 * behavior.
 */

#define BP_SATA_P0CMD_CLO      (3)      //!< Bit position for SATA_P0CMD_CLO.
#define BM_SATA_P0CMD_CLO      (0x00000008)  //!< Bit mask for SATA_P0CMD_CLO.

//! @brief Get value of SATA_P0CMD_CLO from a register value.
#define BG_SATA_P0CMD_CLO(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CMD_CLO) >> BP_SATA_P0CMD_CLO)

//! @brief Format value for bitfield SATA_P0CMD_CLO.
#define BF_SATA_P0CMD_CLO(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CMD_CLO) & BM_SATA_P0CMD_CLO)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLO field to a new value.
#define BW_SATA_P0CMD_CLO(v)   (HW_SATA_P0CMD_WR((HW_SATA_P0CMD_RD() & ~BM_SATA_P0CMD_CLO) | BF_SATA_P0CMD_CLO(v)))
#endif

/* --- Register HW_SATA_P0CMD, field FRE[4] (RW)
 *
 * FIS Receive Enable When set to 1, the Port may post received FISes into the FIS receive area
 * pointed to by SATA_P # 0 FB (and P#FBU when M_HADDR_WIDTH=64) . When cleared, received FISes are
 * not accepted by the Port, except for the first D2H register FIS after the initialization
 * sequence, and no FISes are posted to the FIS receive area. The software must not set this bit
 * until SATA_P # 0 FB (P#FBU) has been programmed with a valid pointer to the FIS receive area When
 * the software wishes to move the base, this bit must first be cleared, and the software must wait
 * for the SATA_P # 0 CMD[FR] bit to be cleared.
 */

#define BP_SATA_P0CMD_FRE      (4)      //!< Bit position for SATA_P0CMD_FRE.
#define BM_SATA_P0CMD_FRE      (0x00000010)  //!< Bit mask for SATA_P0CMD_FRE.

//! @brief Get value of SATA_P0CMD_FRE from a register value.
#define BG_SATA_P0CMD_FRE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CMD_FRE) >> BP_SATA_P0CMD_FRE)

//! @brief Format value for bitfield SATA_P0CMD_FRE.
#define BF_SATA_P0CMD_FRE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CMD_FRE) & BM_SATA_P0CMD_FRE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FRE field to a new value.
#define BW_SATA_P0CMD_FRE(v)   (HW_SATA_P0CMD_WR((HW_SATA_P0CMD_RD() & ~BM_SATA_P0CMD_FRE) | BF_SATA_P0CMD_FRE(v)))
#endif

/* --- Register HW_SATA_P0CMD, field CCS[12:8] (RW)
 *
 * Current Command Slot This field is set to the command slot value value of the command that is
 * currently being issued by the Port. • When SATA_P # 0 CMD[ST] transitions from 1 to 0, this field
 * is recleared to 0x00. • After SATA_P # 0 CMD[ST] transitions from 0 to 1, the highest priority
 * slot to issue from next is command slot 0. After the first command has been issued, the highest
 * priority slot to issue from next is SATA_P # 0 CMD[CCS]+1.For example, after the Port has issued
 * its first command, when CCS=0x00 and SATA_P # 0 CI is cleared to 0x3, the next command issued is
 * from command slot 1. This field is valid only when SATA_P # 0 CMD[ST] is set to 1.
 */

#define BP_SATA_P0CMD_CCS      (8)      //!< Bit position for SATA_P0CMD_CCS.
#define BM_SATA_P0CMD_CCS      (0x00001f00)  //!< Bit mask for SATA_P0CMD_CCS.

//! @brief Get value of SATA_P0CMD_CCS from a register value.
#define BG_SATA_P0CMD_CCS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CMD_CCS) >> BP_SATA_P0CMD_CCS)

//! @brief Format value for bitfield SATA_P0CMD_CCS.
#define BF_SATA_P0CMD_CCS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CMD_CCS) & BM_SATA_P0CMD_CCS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CCS field to a new value.
#define BW_SATA_P0CMD_CCS(v)   (HW_SATA_P0CMD_WR((HW_SATA_P0CMD_RD() & ~BM_SATA_P0CMD_CCS) | BF_SATA_P0CMD_CCS(v)))
#endif

/* --- Register HW_SATA_P0CMD, field MPSS[13] (RW)
 *
 * Mechanical Presence Switch State The software must use this bit only when both SATA_CAP[SMPS] and
 * SATA_P # 0 CMD[MPSP] are set. This bit reports the state of a mechanical presence switch attached
 * to this Port as indicated by the p # 0 _mp_switch input state (assuming SATA_CAP[SMPS]=1 and
 * SATA_P # 0 CMD[MPSP]=1). The options for this field are: When SATA_CAP[SMPS]=0 then this bit is
 * cleared to 0.
 *
 * Values:
 * 0 - Switch is closed
 * 1 - Switch is open
 */

#define BP_SATA_P0CMD_MPSS      (13)      //!< Bit position for SATA_P0CMD_MPSS.
#define BM_SATA_P0CMD_MPSS      (0x00002000)  //!< Bit mask for SATA_P0CMD_MPSS.

//! @brief Get value of SATA_P0CMD_MPSS from a register value.
#define BG_SATA_P0CMD_MPSS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CMD_MPSS) >> BP_SATA_P0CMD_MPSS)

//! @brief Format value for bitfield SATA_P0CMD_MPSS.
#define BF_SATA_P0CMD_MPSS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CMD_MPSS) & BM_SATA_P0CMD_MPSS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPSS field to a new value.
#define BW_SATA_P0CMD_MPSS(v)   (HW_SATA_P0CMD_WR((HW_SATA_P0CMD_RD() & ~BM_SATA_P0CMD_MPSS) | BF_SATA_P0CMD_MPSS(v)))
#endif


/* --- Register HW_SATA_P0CMD, field FR[14] (RW)
 *
 * FIS Receive Running When set to '1', the FIS Receive DMA engine for the Port is running. See AHCI
 * specification section 10.3.2 for details on when this bit is set and cleared by the Port.
 */

#define BP_SATA_P0CMD_FR      (14)      //!< Bit position for SATA_P0CMD_FR.
#define BM_SATA_P0CMD_FR      (0x00004000)  //!< Bit mask for SATA_P0CMD_FR.

//! @brief Get value of SATA_P0CMD_FR from a register value.
#define BG_SATA_P0CMD_FR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CMD_FR) >> BP_SATA_P0CMD_FR)

//! @brief Format value for bitfield SATA_P0CMD_FR.
#define BF_SATA_P0CMD_FR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CMD_FR) & BM_SATA_P0CMD_FR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FR field to a new value.
#define BW_SATA_P0CMD_FR(v)   (HW_SATA_P0CMD_WR((HW_SATA_P0CMD_RD() & ~BM_SATA_P0CMD_FR) | BF_SATA_P0CMD_FR(v)))
#endif

/* --- Register HW_SATA_P0CMD, field CR[15] (RW)
 *
 * Command List Running When this bit is set to '1', the command list DMA engine for this Port is
 * running. See AHCI state machine in AHCI specification section 5.3.2 (this is a reference to an
 * external document) for details on when this bit is set and cleared by the Port.
 */

#define BP_SATA_P0CMD_CR      (15)      //!< Bit position for SATA_P0CMD_CR.
#define BM_SATA_P0CMD_CR      (0x00008000)  //!< Bit mask for SATA_P0CMD_CR.

//! @brief Get value of SATA_P0CMD_CR from a register value.
#define BG_SATA_P0CMD_CR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CMD_CR) >> BP_SATA_P0CMD_CR)

//! @brief Format value for bitfield SATA_P0CMD_CR.
#define BF_SATA_P0CMD_CR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CMD_CR) & BM_SATA_P0CMD_CR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CR field to a new value.
#define BW_SATA_P0CMD_CR(v)   (HW_SATA_P0CMD_WR((HW_SATA_P0CMD_RD() & ~BM_SATA_P0CMD_CR) | BF_SATA_P0CMD_CR(v)))
#endif

/* --- Register HW_SATA_P0CMD, field CPS[16] (RW)
 *
 * Cold Presence State This bit reports whether a device is currently detected on this Port as
 * indicated by the p # 0 _cp_det input state (assuming SATA_P # 0 CMD[CPD]=1). The options for this
 * field are:
 *
 * Values:
 * 0 - no device attached to this Port
 * 1 - device is attached to this Port
 */

#define BP_SATA_P0CMD_CPS      (16)      //!< Bit position for SATA_P0CMD_CPS.
#define BM_SATA_P0CMD_CPS      (0x00010000)  //!< Bit mask for SATA_P0CMD_CPS.

//! @brief Get value of SATA_P0CMD_CPS from a register value.
#define BG_SATA_P0CMD_CPS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CMD_CPS) >> BP_SATA_P0CMD_CPS)

//! @brief Format value for bitfield SATA_P0CMD_CPS.
#define BF_SATA_P0CMD_CPS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CMD_CPS) & BM_SATA_P0CMD_CPS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CPS field to a new value.
#define BW_SATA_P0CMD_CPS(v)   (HW_SATA_P0CMD_WR((HW_SATA_P0CMD_RD() & ~BM_SATA_P0CMD_CPS) | BF_SATA_P0CMD_CPS(v)))
#endif


/* --- Register HW_SATA_P0CMD, field PMA[17] (RW)
 *
 * Port Multiplier Attached The software is responsible for detecting whether a Port Multiplier is
 * present; the SATA block Port does not auto-detect the presence of a Port Multiplier. The options
 * for this field are:
 *
 * Values:
 * 0 - A Port Multiplier is not attached to this Port.
 * 1 - A Port Multiplier is attached to this Port.
 */

#define BP_SATA_P0CMD_PMA      (17)      //!< Bit position for SATA_P0CMD_PMA.
#define BM_SATA_P0CMD_PMA      (0x00020000)  //!< Bit mask for SATA_P0CMD_PMA.

//! @brief Get value of SATA_P0CMD_PMA from a register value.
#define BG_SATA_P0CMD_PMA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CMD_PMA) >> BP_SATA_P0CMD_PMA)

//! @brief Format value for bitfield SATA_P0CMD_PMA.
#define BF_SATA_P0CMD_PMA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CMD_PMA) & BM_SATA_P0CMD_PMA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PMA field to a new value.
#define BW_SATA_P0CMD_PMA(v)   (HW_SATA_P0CMD_WR((HW_SATA_P0CMD_RD() & ~BM_SATA_P0CMD_PMA) | BF_SATA_P0CMD_PMA(v)))
#endif


/* --- Register HW_SATA_P0CMD, field HPCP[18] (RW)
 *
 * Hot Plug Capable Port The HPCP bit is mutually exclusive with SATA_P # 0 CMD[ESP]. The options
 * for this field are:
 *
 * Values:
 * 0 - Indicates that this Port's signal and power connectors are not externally accessible.
 * 1 - Indicates that this Port's signal and power connectors are externally accessible via a joint signal-
 *     power connector for blindmate device hot plug.
 */

#define BP_SATA_P0CMD_HPCP      (18)      //!< Bit position for SATA_P0CMD_HPCP.
#define BM_SATA_P0CMD_HPCP      (0x00040000)  //!< Bit mask for SATA_P0CMD_HPCP.

//! @brief Get value of SATA_P0CMD_HPCP from a register value.
#define BG_SATA_P0CMD_HPCP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CMD_HPCP) >> BP_SATA_P0CMD_HPCP)

//! @brief Format value for bitfield SATA_P0CMD_HPCP.
#define BF_SATA_P0CMD_HPCP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CMD_HPCP) & BM_SATA_P0CMD_HPCP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HPCP field to a new value.
#define BW_SATA_P0CMD_HPCP(v)   (HW_SATA_P0CMD_WR((HW_SATA_P0CMD_RD() & ~BM_SATA_P0CMD_HPCP) | BF_SATA_P0CMD_HPCP(v)))
#endif


/* --- Register HW_SATA_P0CMD, field ESP[21] (RW)
 *
 * External SATA Port When set to 1, indicates that this Port's signal only connector is externally
 * accessible. When set to 1, SATA_CAP[SXS] is also set to 1. When cleared to 0, indicates that this
 * Port's signal only connector is not externally accessible. Note: The ESP bit is mutually
 * exclusive with SATA_P # 0 CMD[HPCP]
 */

#define BP_SATA_P0CMD_ESP      (21)      //!< Bit position for SATA_P0CMD_ESP.
#define BM_SATA_P0CMD_ESP      (0x00200000)  //!< Bit mask for SATA_P0CMD_ESP.

//! @brief Get value of SATA_P0CMD_ESP from a register value.
#define BG_SATA_P0CMD_ESP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CMD_ESP) >> BP_SATA_P0CMD_ESP)

//! @brief Format value for bitfield SATA_P0CMD_ESP.
#define BF_SATA_P0CMD_ESP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CMD_ESP) & BM_SATA_P0CMD_ESP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ESP field to a new value.
#define BW_SATA_P0CMD_ESP(v)   (HW_SATA_P0CMD_WR((HW_SATA_P0CMD_RD() & ~BM_SATA_P0CMD_ESP) | BF_SATA_P0CMD_ESP(v)))
#endif

/* --- Register HW_SATA_P0CMD, field APSTE[23] (RW)
 *
 * Device is ATAPI This bit is used by the Port to control whether to assert p # 0 _act_led output
 * when commands are active (see " ) . The options for this field are:
 *
 * Values:
 * 0 - non-ATAPI device
 * 1 - ATAPI device
 */

#define BP_SATA_P0CMD_APSTE      (23)      //!< Bit position for SATA_P0CMD_APSTE.
#define BM_SATA_P0CMD_APSTE      (0x00800000)  //!< Bit mask for SATA_P0CMD_APSTE.

//! @brief Get value of SATA_P0CMD_APSTE from a register value.
#define BG_SATA_P0CMD_APSTE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CMD_APSTE) >> BP_SATA_P0CMD_APSTE)

//! @brief Format value for bitfield SATA_P0CMD_APSTE.
#define BF_SATA_P0CMD_APSTE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CMD_APSTE) & BM_SATA_P0CMD_APSTE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the APSTE field to a new value.
#define BW_SATA_P0CMD_APSTE(v)   (HW_SATA_P0CMD_WR((HW_SATA_P0CMD_RD() & ~BM_SATA_P0CMD_APSTE) | BF_SATA_P0CMD_APSTE(v)))
#endif


/* --- Register HW_SATA_P0CMD, field ATAPI[24] (RW)
 *
 * ATAPI Device is ATAPI This bit is used by the Port to control whether to assert p # 0 _act_led
 * output when commands are active (see " ) . The options for this field are:
 *
 * Values:
 * 0 - non-ATAPI device
 * 1 - ATAPI device
 */

#define BP_SATA_P0CMD_ATAPI      (24)      //!< Bit position for SATA_P0CMD_ATAPI.
#define BM_SATA_P0CMD_ATAPI      (0x01000000)  //!< Bit mask for SATA_P0CMD_ATAPI.

//! @brief Get value of SATA_P0CMD_ATAPI from a register value.
#define BG_SATA_P0CMD_ATAPI(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CMD_ATAPI) >> BP_SATA_P0CMD_ATAPI)

//! @brief Format value for bitfield SATA_P0CMD_ATAPI.
#define BF_SATA_P0CMD_ATAPI(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CMD_ATAPI) & BM_SATA_P0CMD_ATAPI)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATAPI field to a new value.
#define BW_SATA_P0CMD_ATAPI(v)   (HW_SATA_P0CMD_WR((HW_SATA_P0CMD_RD() & ~BM_SATA_P0CMD_ATAPI) | BF_SATA_P0CMD_ATAPI(v)))
#endif


/* --- Register HW_SATA_P0CMD, field DLAE[25] (RW)
 *
 * Drive LED on ATAPI Enable When set to 1, SATA_P # 0 CMD[ATAPI]=1, and commands are active, the
 * Port asserts p # 0 _act_led output (see " ) .
 */

#define BP_SATA_P0CMD_DLAE      (25)      //!< Bit position for SATA_P0CMD_DLAE.
#define BM_SATA_P0CMD_DLAE      (0x02000000)  //!< Bit mask for SATA_P0CMD_DLAE.

//! @brief Get value of SATA_P0CMD_DLAE from a register value.
#define BG_SATA_P0CMD_DLAE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CMD_DLAE) >> BP_SATA_P0CMD_DLAE)

//! @brief Format value for bitfield SATA_P0CMD_DLAE.
#define BF_SATA_P0CMD_DLAE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CMD_DLAE) & BM_SATA_P0CMD_DLAE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DLAE field to a new value.
#define BW_SATA_P0CMD_DLAE(v)   (HW_SATA_P0CMD_WR((HW_SATA_P0CMD_RD() & ~BM_SATA_P0CMD_DLAE) | BF_SATA_P0CMD_DLAE(v)))
#endif

/* --- Register HW_SATA_P0CMD, field ALPE[26] (RW)
 *
 * Aggressive Link Power Management Enable When set to 1, the Port aggressively enters a lower link
 * power state (PARTIAL or SLUMBER) based on the setting of the SATA_P # 0 CMD[ASP] bit. When
 * cleared to 0, aggressive power management state transition is disabled.
 */

#define BP_SATA_P0CMD_ALPE      (26)      //!< Bit position for SATA_P0CMD_ALPE.
#define BM_SATA_P0CMD_ALPE      (0x04000000)  //!< Bit mask for SATA_P0CMD_ALPE.

//! @brief Get value of SATA_P0CMD_ALPE from a register value.
#define BG_SATA_P0CMD_ALPE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CMD_ALPE) >> BP_SATA_P0CMD_ALPE)

//! @brief Format value for bitfield SATA_P0CMD_ALPE.
#define BF_SATA_P0CMD_ALPE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CMD_ALPE) & BM_SATA_P0CMD_ALPE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ALPE field to a new value.
#define BW_SATA_P0CMD_ALPE(v)   (HW_SATA_P0CMD_WR((HW_SATA_P0CMD_RD() & ~BM_SATA_P0CMD_ALPE) | BF_SATA_P0CMD_ALPE(v)))
#endif

/* --- Register HW_SATA_P0CMD, field ASP[27] (RW)
 *
 * Aggressive Slumber/ Partial The options for this field are: • When set to 1, and SATA_P # 0
 * CMD[ALPE]=1, the Port aggressively enters the SLUMBER state when one of the following conditions
 * is true: - The Port clears the SATA_P # 0 CI and the SATA_P # 0 SACT register is cleared. - The
 * Port clears the SATA_P # 0 SACT register and SATA_P # 0 CI is cleared. • When cleared to 0, and
 * SATA_P # 0 CMD[ALPE]=1, the Port aggressively enters the PARTIAL state when one of the following
 * conditions is true: - The Port clears the SATA_P # 0 CI register and the SATA_P # 0 SACT register
 * is cleared. - The Port clears the SATA_P # 0 SACT register and SATA_P # 0 CI is cleared.
 */

#define BP_SATA_P0CMD_ASP      (27)      //!< Bit position for SATA_P0CMD_ASP.
#define BM_SATA_P0CMD_ASP      (0x08000000)  //!< Bit mask for SATA_P0CMD_ASP.

//! @brief Get value of SATA_P0CMD_ASP from a register value.
#define BG_SATA_P0CMD_ASP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CMD_ASP) >> BP_SATA_P0CMD_ASP)

//! @brief Format value for bitfield SATA_P0CMD_ASP.
#define BF_SATA_P0CMD_ASP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CMD_ASP) & BM_SATA_P0CMD_ASP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ASP field to a new value.
#define BW_SATA_P0CMD_ASP(v)   (HW_SATA_P0CMD_WR((HW_SATA_P0CMD_RD() & ~BM_SATA_P0CMD_ASP) | BF_SATA_P0CMD_ASP(v)))
#endif

/* --- Register HW_SATA_P0CMD, field ICC[31:28] (RW)
 *
 * Interface Communication Control This field is used to control power management states of the
 * interface. When the Link layer is currently in the L_IDLE state, writes to this field cause the
 * Port to initiate a transition to the interface power management state requested. When the Link
 * layer is not currently in the L_IDLE state, writes to this field have no effect. • 0xF-0x7:
 * Reserved • 0x6: Slumber. This causes the Port to request a transition of the interface to the
 * Slumber state. The SATA device can reject the request and the interface remains in its current
 * state. • 0x5-0x3: Reserved • 0x2: Partial. This causes the Port to request a transition of the
 * interface to the Partial state. The SATA device can reject the request and the interface remains
 * in its current state. • 0x1: Active. This causes the Port to request a transition of the
 * interface into the active state. • 0x0: No-Op/ Idle. This value indicates to the software that
 * the Port # 0 is ready to accept a new interface control command, although the transition to the
 * previously selected state may not yet have occurred. When the software writes a non-reserved
 * value other than No-Op (0x0), the Port performs the action and update this field back to Idle
 * (0x0). When the software writes to this field to change the state to a state the link is already
 * in (i.e., interface is in the active state and a request is made to go to the active state), the
 * Port takes no action and returns this field to Idle. When the interface is in a low power state
 * and the software wants to transition to a different low power state, the software must first
 * bring the link to active and then initiate the transition to the desired low power state.
 */

#define BP_SATA_P0CMD_ICC      (28)      //!< Bit position for SATA_P0CMD_ICC.
#define BM_SATA_P0CMD_ICC      (0xf0000000)  //!< Bit mask for SATA_P0CMD_ICC.

//! @brief Get value of SATA_P0CMD_ICC from a register value.
#define BG_SATA_P0CMD_ICC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CMD_ICC) >> BP_SATA_P0CMD_ICC)

//! @brief Format value for bitfield SATA_P0CMD_ICC.
#define BF_SATA_P0CMD_ICC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CMD_ICC) & BM_SATA_P0CMD_ICC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ICC field to a new value.
#define BW_SATA_P0CMD_ICC(v)   (HW_SATA_P0CMD_WR((HW_SATA_P0CMD_RD() & ~BM_SATA_P0CMD_ICC) | BF_SATA_P0CMD_ICC(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_SATA_P0TFD - Port0 Task File Data Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_P0TFD - Port0 Task File Data Register (RO)
 *
 * Reset value: 0x0000007f
 *
 * This register contains Error and Status registers updated every time a new Register FIS, PIO
 * Setup FIS, or Set Device Bits FIS is received from the device. Reset on Global or Port reset
 * (COMRESET).   Size: 32 bits  Address offset: for # = 0 to 7:   P0TFD: 0x120  P1TFD: 0x1A0  P2TFD:
 * 0x220  P3TFD: 0x2A0  P4TFD: 0x320  P5TFD: 0x3A0  P6TFD: 0x420  P7TFD: 0x4A0    Read/write access:
 * Read-only  Reset: 0x0000_007F
 */
typedef union _hw_sata_p0tfd
{
    reg32_t U;
    struct _hw_sata_p0tfd_bitfields
    {
        unsigned STS : 8; //!< [7:0] Status This field contains the latest copy of the task file status register. The bits that affect SATA block operation are: • Bit [7] BSY - Indicates the interface is busy • Bits [6:4] cs - Command specific • Bit [3] DRQ - Indicates a data transfer is requested • Bits [2:1] cs - Command specific • Bit [0] ERR - Indicates an error during the transfer The Port updates the entire 8-bit field, not just the bits noted above.
        unsigned ERR : 8; //!< [15:8] Error This field contains the latest copy of the task file error register.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
    } B;
} hw_sata_p0tfd_t;
#endif

/*
 * constants & macros for entire SATA_P0TFD register
 */
#define HW_SATA_P0TFD_ADDR      (REGS_SATA_BASE + 0x120)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0TFD           (*(volatile hw_sata_p0tfd_t *) HW_SATA_P0TFD_ADDR)
#define HW_SATA_P0TFD_RD()      (HW_SATA_P0TFD.U)
#endif

/*
 * constants & macros for individual SATA_P0TFD bitfields
 */

/* --- Register HW_SATA_P0TFD, field STS[7:0] (RO)
 *
 * Status This field contains the latest copy of the task file status register. The bits that affect
 * SATA block operation are: • Bit [7] BSY - Indicates the interface is busy • Bits [6:4] cs -
 * Command specific • Bit [3] DRQ - Indicates a data transfer is requested • Bits [2:1] cs - Command
 * specific • Bit [0] ERR - Indicates an error during the transfer The Port updates the entire 8-bit
 * field, not just the bits noted above.
 */

#define BP_SATA_P0TFD_STS      (0)      //!< Bit position for SATA_P0TFD_STS.
#define BM_SATA_P0TFD_STS      (0x000000ff)  //!< Bit mask for SATA_P0TFD_STS.

//! @brief Get value of SATA_P0TFD_STS from a register value.
#define BG_SATA_P0TFD_STS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0TFD_STS) >> BP_SATA_P0TFD_STS)

/* --- Register HW_SATA_P0TFD, field ERR[15:8] (RO)
 *
 * Error This field contains the latest copy of the task file error register.
 */

#define BP_SATA_P0TFD_ERR      (8)      //!< Bit position for SATA_P0TFD_ERR.
#define BM_SATA_P0TFD_ERR      (0x0000ff00)  //!< Bit mask for SATA_P0TFD_ERR.

//! @brief Get value of SATA_P0TFD_ERR from a register value.
#define BG_SATA_P0TFD_ERR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0TFD_ERR) >> BP_SATA_P0TFD_ERR)

//-------------------------------------------------------------------------------------------
// HW_SATA_P0SIG - Port0 Signature Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_P0SIG - Port0 Signature Register (RO)
 *
 * Reset value: 0xffffffff
 *
 * Size: 32 bits  Address offset: for # = 0 to 7:  P0SIG: 0x124  P1SIG: 0x1A4  P2SIG: 0x224  P3SIG:
 * 0x2A4  P4SIG: 0x324  P5SIG: 0x3A4  P6SIG: 0x424  P7SIG: 0x4A4    Read/write access: Read-only
 * Reset: 0xFFFF_FFFF
 */
typedef union _hw_sata_p0sig
{
    reg32_t U;
    struct _hw_sata_p0sig_bitfields
    {
        unsigned SIG : 32; //!< [31:0] Signature This field contains the signature received from a device on the first D2H Register FIS. The bit order as follows: • Bits [31:24] - LBA High (Cylinder High) Register • Bits [23:16] - LBA Mid (Cylinder Low) Register • Bits [15:8] - LBA Low (Sector Number) Register • Bits [7:0] - Sector Count Register This field is updated once after a reset sequence. Reset on Global or Port reset.
    } B;
} hw_sata_p0sig_t;
#endif

/*
 * constants & macros for entire SATA_P0SIG register
 */
#define HW_SATA_P0SIG_ADDR      (REGS_SATA_BASE + 0x124)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0SIG           (*(volatile hw_sata_p0sig_t *) HW_SATA_P0SIG_ADDR)
#define HW_SATA_P0SIG_RD()      (HW_SATA_P0SIG.U)
#endif

/*
 * constants & macros for individual SATA_P0SIG bitfields
 */

/* --- Register HW_SATA_P0SIG, field SIG[31:0] (RO)
 *
 * Signature This field contains the signature received from a device on the first D2H Register FIS.
 * The bit order as follows: • Bits [31:24] - LBA High (Cylinder High) Register • Bits [23:16] - LBA
 * Mid (Cylinder Low) Register • Bits [15:8] - LBA Low (Sector Number) Register • Bits [7:0] -
 * Sector Count Register This field is updated once after a reset sequence. Reset on Global or Port
 * reset.
 */

#define BP_SATA_P0SIG_SIG      (0)      //!< Bit position for SATA_P0SIG_SIG.
#define BM_SATA_P0SIG_SIG      (0xffffffff)  //!< Bit mask for SATA_P0SIG_SIG.

//! @brief Get value of SATA_P0SIG_SIG from a register value.
#define BG_SATA_P0SIG_SIG(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SIG_SIG) >> BP_SATA_P0SIG_SIG)

//-------------------------------------------------------------------------------------------
// HW_SATA_P0SSTS - Port0 Serial ATA Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_P0SSTS - Port0 Serial ATA Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * This 32-bit register conveys the current state of the interface and host. The Port updates it
 * continuously and asynchronously. When the Port transmits a COMRESET to the device, this register
 * is updated to its reset values (i.e., Global reset, Port reset, or COMINIT from the device
 * Size: 32 bits  Address offset: 0x128  for # = 0 to 7:  P0SSTS: 0x128  P1SSTS: 0x1A8  P2SSTS:
 * 0x228  P3SSTS: 0x2A8  P4SSTS: 0x328  P5SSTS: 0x3A8  P6SSTS: 0x428  P7SSTS: 0x4A8    Read/write
 * access: Read-only  Reset: 0x0000_0000
 */
typedef union _hw_sata_p0ssts
{
    reg32_t U;
    struct _hw_sata_p0ssts_bitfields
    {
        unsigned DET : 4; //!< [3:0] Indicates the interface device detection and PHY state. The options for this field are: 0x0: No device detected and PHY communication not established 0x1: Device presence detected but PHY communication not established (COMINIT is detected) 0x3: Device presence detected and PHY communication established (“PHY Ready” is detected) 0x4: PHY in offline mode as a result of the interface being disabled or running in a BIST loopback mode. All other values reserved.
        unsigned SPD : 4; //!< [7:4] Current Interface Speed Indicates the negotiated interface communication speed. The options for this field are:
        unsigned IPM : 4; //!< [11:8] Interface Power Management Indicates the current interface state. The options for this field are:
        unsigned RESERVED0 : 20; //!< [31:12] Reserved
    } B;
} hw_sata_p0ssts_t;
#endif

/*
 * constants & macros for entire SATA_P0SSTS register
 */
#define HW_SATA_P0SSTS_ADDR      (REGS_SATA_BASE + 0x128)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0SSTS           (*(volatile hw_sata_p0ssts_t *) HW_SATA_P0SSTS_ADDR)
#define HW_SATA_P0SSTS_RD()      (HW_SATA_P0SSTS.U)
#endif

/*
 * constants & macros for individual SATA_P0SSTS bitfields
 */

/* --- Register HW_SATA_P0SSTS, field DET[3:0] (RU)
 *
 * Indicates the interface device detection and PHY state. The options for this field are: 0x0: No
 * device detected and PHY communication not established 0x1: Device presence detected but PHY
 * communication not established (COMINIT is detected) 0x3: Device presence detected and PHY
 * communication established (“PHY Ready” is detected) 0x4: PHY in offline mode as a result of the
 * interface being disabled or running in a BIST loopback mode. All other values reserved.
 */

#define BP_SATA_P0SSTS_DET      (0)      //!< Bit position for SATA_P0SSTS_DET.
#define BM_SATA_P0SSTS_DET      (0x0000000f)  //!< Bit mask for SATA_P0SSTS_DET.

//! @brief Get value of SATA_P0SSTS_DET from a register value.
#define BG_SATA_P0SSTS_DET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SSTS_DET) >> BP_SATA_P0SSTS_DET)

/* --- Register HW_SATA_P0SSTS, field SPD[7:4] (RO)
 *
 * Current Interface Speed Indicates the negotiated interface communication speed. The options for
 * this field are:
 *
 * Values:
 * 0x0 - Device not present or communication not established
 * 0x1 - 1.5 Gb/s communication rate negotiated
 * 0x2 - 3.0 Gb/s communication rate negotiated
 * All other values - Reserved and should not be used
 */

#define BP_SATA_P0SSTS_SPD      (4)      //!< Bit position for SATA_P0SSTS_SPD.
#define BM_SATA_P0SSTS_SPD      (0x000000f0)  //!< Bit mask for SATA_P0SSTS_SPD.

//! @brief Get value of SATA_P0SSTS_SPD from a register value.
#define BG_SATA_P0SSTS_SPD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SSTS_SPD) >> BP_SATA_P0SSTS_SPD)


/* --- Register HW_SATA_P0SSTS, field IPM[11:8] (RO)
 *
 * Interface Power Management Indicates the current interface state. The options for this field are:
 *
 * Values:
 * 0x0 - Device not present or communication not established
 * 0x1 - Interface in active state
 * 0x2 - Interface in Partial power management state
 * 0x6 - Interface in Slumber power management state
 * All other values - Reserved
 */

#define BP_SATA_P0SSTS_IPM      (8)      //!< Bit position for SATA_P0SSTS_IPM.
#define BM_SATA_P0SSTS_IPM      (0x00000f00)  //!< Bit mask for SATA_P0SSTS_IPM.

//! @brief Get value of SATA_P0SSTS_IPM from a register value.
#define BG_SATA_P0SSTS_IPM(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SSTS_IPM) >> BP_SATA_P0SSTS_IPM)


//-------------------------------------------------------------------------------------------
// HW_SATA_P0SCTL - Port0 Serial ATA Control {SControl} Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_P0SCTL - Port0 Serial ATA Control {SControl} Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This 32-bit read-write register is used by the software to control SATA interface capabilities.
 * Writes to this register result in an action being taken by the Port PHY interface. Reads from the
 * register return the last value written to it. Reset on Global reset.  These bits are static and
 * should not be changed frequently due to the clock crossing between the Transport and Link Layers.
 * The software must wait for at least seven periods of the slower clock (clk_asic #  0 or hclk)
 * before changing this register   Size: 32 bits  Address offset: for # = 0 to 7:   P0SCTL: 0x12C
 * P1SCTL: 0x1AC  P2SCTL: 0x22C  P3SCTL: 0x2AC  P4SCTL: 0x32C  P5SCTL: 0x3AC  P6SCTL: 0x42C  P7SCTL:
 * 0x4AC    Read/write access: Read/Write  Reset: 0x0000_0000
 */
typedef union _hw_sata_p0sctl
{
    reg32_t U;
    struct _hw_sata_p0sctl_bitfields
    {
        unsigned DET : 4; //!< [3:0] Device Detection Initialization Controls the Port's device detection and interface initialization. The options for this field are: This field may only be modified when SATA_P # 0 CMD[ST] is 0. Changing this field while the SATA_P # 0 CMD[ST]=1 results in undefined behavior. When SATA_P # 0 CMD[ST] is set to 1, this field should have a value of 0x0.
        unsigned SPD : 4; //!< [7:4] Speed Allowed This field indicates the highest allowable speed of the Port PHY interface. The options for this field are: When the host software must change this field value, the host must also reset the Port (SATA_P # 0 SCTL[DET] = 0x1) at the same time to ensure proper speed negotiation.
        unsigned IPM : 4; //!< [11:8] Interface Power Management Transitions Allowed This field indicates which power states the Port PHY interface is allowed to transition to. When an interface power management state is disabled, the Port does not initiate that state and any request from the device to enter that state is rejected via PMNAKp The options for this field are:
        unsigned RESERVED0 : 20; //!< [31:12] Reserved
    } B;
} hw_sata_p0sctl_t;
#endif

/*
 * constants & macros for entire SATA_P0SCTL register
 */
#define HW_SATA_P0SCTL_ADDR      (REGS_SATA_BASE + 0x12c)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0SCTL           (*(volatile hw_sata_p0sctl_t *) HW_SATA_P0SCTL_ADDR)
#define HW_SATA_P0SCTL_RD()      (HW_SATA_P0SCTL.U)
#define HW_SATA_P0SCTL_WR(v)     (HW_SATA_P0SCTL.U = (v))
#define HW_SATA_P0SCTL_SET(v)    (HW_SATA_P0SCTL_WR(HW_SATA_P0SCTL_RD() |  (v)))
#define HW_SATA_P0SCTL_CLR(v)    (HW_SATA_P0SCTL_WR(HW_SATA_P0SCTL_RD() & ~(v)))
#define HW_SATA_P0SCTL_TOG(v)    (HW_SATA_P0SCTL_WR(HW_SATA_P0SCTL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_P0SCTL bitfields
 */

/* --- Register HW_SATA_P0SCTL, field DET[3:0] (RW)
 *
 * Device Detection Initialization Controls the Port's device detection and interface
 * initialization. The options for this field are: This field may only be modified when SATA_P # 0
 * CMD[ST] is 0. Changing this field while the SATA_P # 0 CMD[ST]=1 results in undefined behavior.
 * When SATA_P # 0 CMD[ST] is set to 1, this field should have a value of 0x0.
 *
 * Values:
 * 0x0 - No device detection or initialization action requested
 * 0x1 - Perform interface initialization sequence to establish communication. This results in the interface
 *     being reset and communication re initialized.
 * 0x4 - Disable the Serial ATA interface and put the Port PHY in offline mode. All other values reserved.
 */

#define BP_SATA_P0SCTL_DET      (0)      //!< Bit position for SATA_P0SCTL_DET.
#define BM_SATA_P0SCTL_DET      (0x0000000f)  //!< Bit mask for SATA_P0SCTL_DET.

//! @brief Get value of SATA_P0SCTL_DET from a register value.
#define BG_SATA_P0SCTL_DET(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SCTL_DET) >> BP_SATA_P0SCTL_DET)

//! @brief Format value for bitfield SATA_P0SCTL_DET.
#define BF_SATA_P0SCTL_DET(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0SCTL_DET) & BM_SATA_P0SCTL_DET)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DET field to a new value.
#define BW_SATA_P0SCTL_DET(v)   (HW_SATA_P0SCTL_WR((HW_SATA_P0SCTL_RD() & ~BM_SATA_P0SCTL_DET) | BF_SATA_P0SCTL_DET(v)))
#endif


/* --- Register HW_SATA_P0SCTL, field SPD[7:4] (RW)
 *
 * Speed Allowed This field indicates the highest allowable speed of the Port PHY interface. The
 * options for this field are: When the host software must change this field value, the host must
 * also reset the Port (SATA_P # 0 SCTL[DET] = 0x1) at the same time to ensure proper speed
 * negotiation.
 *
 * Values:
 * 0x0 - No speed negotiation restrictions
 * 0x1 - Limit speed negotiation to SATA 1.5 Gb/s communication rate
 * 0x2 - Limit speed negotiation to SATA 3.0 Gb/s communication rate
 * All other values - Reserved and should not be used.
 */

#define BP_SATA_P0SCTL_SPD      (4)      //!< Bit position for SATA_P0SCTL_SPD.
#define BM_SATA_P0SCTL_SPD      (0x000000f0)  //!< Bit mask for SATA_P0SCTL_SPD.

//! @brief Get value of SATA_P0SCTL_SPD from a register value.
#define BG_SATA_P0SCTL_SPD(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SCTL_SPD) >> BP_SATA_P0SCTL_SPD)

//! @brief Format value for bitfield SATA_P0SCTL_SPD.
#define BF_SATA_P0SCTL_SPD(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0SCTL_SPD) & BM_SATA_P0SCTL_SPD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SPD field to a new value.
#define BW_SATA_P0SCTL_SPD(v)   (HW_SATA_P0SCTL_WR((HW_SATA_P0SCTL_RD() & ~BM_SATA_P0SCTL_SPD) | BF_SATA_P0SCTL_SPD(v)))
#endif


/* --- Register HW_SATA_P0SCTL, field IPM[11:8] (RW)
 *
 * Interface Power Management Transitions Allowed This field indicates which power states the Port
 * PHY interface is allowed to transition to. When an interface power management state is disabled,
 * the Port does not initiate that state and any request from the device to enter that state is
 * rejected via PMNAKp The options for this field are:
 *
 * Values:
 * 0x0 - No interface power management state restrictions
 * 0x1 - Transitions to the Partial state disabled
 * 0x2 - Transitions to the Slumber state disabled
 * 0x3 - Transitions to both Partial and Slumber states disabled
 * All other values. - Reserved and should not be used
 */

#define BP_SATA_P0SCTL_IPM      (8)      //!< Bit position for SATA_P0SCTL_IPM.
#define BM_SATA_P0SCTL_IPM      (0x00000f00)  //!< Bit mask for SATA_P0SCTL_IPM.

//! @brief Get value of SATA_P0SCTL_IPM from a register value.
#define BG_SATA_P0SCTL_IPM(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SCTL_IPM) >> BP_SATA_P0SCTL_IPM)

//! @brief Format value for bitfield SATA_P0SCTL_IPM.
#define BF_SATA_P0SCTL_IPM(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0SCTL_IPM) & BM_SATA_P0SCTL_IPM)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPM field to a new value.
#define BW_SATA_P0SCTL_IPM(v)   (HW_SATA_P0SCTL_WR((HW_SATA_P0SCTL_RD() & ~BM_SATA_P0SCTL_IPM) | BF_SATA_P0SCTL_IPM(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_SATA_P0SERR - Port0 Serial ATA Error Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_P0SERR - Port0 Serial ATA Error Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This 32-bit register represents all the detected interface errors accumulated since the last time
 * it was cleared. The set bits in the SError register indicate that the corresponding error
 * condition became true one or more times since the last time the bit was cleared. The set bits in
 * this register are explicitly cleared by a write operation to the register, Global reset, or Port
 * reset (COMRESET). The value written to clear the set error bits should have ones encoded in the
 * bit positions corresponding to the bits that are to be cleared. All bits in the following table
 * have a reset value of 0.
 */
typedef union _hw_sata_p0serr
{
    reg32_t U;
    struct _hw_sata_p0serr_bitfields
    {
        unsigned ERR_I : 1; //!< [0] This bit is set when any of the following SATA_P # 0 SERR register bits is set during non- Data FIS transfer: • DIAG_C (CRC) • DIAG_H (Handshake) • ERR_C ("PHY Ready" negation)
        unsigned ERR_M : 1; //!< [1] Recovered Communication Error This bit is set to 1 when PHY Ready condition is detected after interface initialization, but not after transition from Partial or Slumber power management state to active state.
        unsigned RESERVED0 : 6; //!< [7:2] Reserved
        unsigned ERR_T : 1; //!< [8] Non-Recovered Transient Data Integrity Error This bit is set when any of the following SATA_P # 0 SERR register bits is set during Data FIS transfer: ERR_P (Protocol) • DIAG_C (CRC) • DIAG_H (Handshake) • ERR_C ("PHY Ready" negation)
        unsigned ERR_C : 1; //!< [9] Non-Recovered Persistent Communication Error This bit is set to 1 when PHY Ready signal is negated due to the loss of communication with the device or problems with interface, but not after transition from active to Partial or Slumber power management state.
        unsigned ERR_P : 1; //!< [10] Protocol Error This bit is set to 1 when any of the following conditions are detected. • Transport state transition error (DIAG_T) • Link sequence error (DIAG_S) • RxFIFO overflow • Link bad end error (WTRM instead of EOF is received).
        unsigned ERR_E : 1; //!< [11] Internal Error This bit is set to 1 when one or more AHB bus ERROR responses are detected on the master interface.
        unsigned RESERVED1 : 4; //!< [15:12] Reserved
        unsigned DIAG_N : 1; //!< [16] PHY Ready Change This bit indicates that the PHY Ready signal changed state. This bit is reflected in the SATA_P # 0 IS[PRCS] bit.
        unsigned DIAG_I : 1; //!< [17] PHY Internal Error This bit is set when the PHY detects some internal error as indicated by the assertion of the p # 0 _phy_rx_err input. The setting of this bit is controlled by the SATA_BISTCR[ERREN] bit: when ERREN==0 (default), only errors occurring inside the received FIS cause DIAG_I bit to be set; when ERREN==1, any error inside or outside the FIS causes the DIAG_I bit to be set.
        unsigned DIAG_W : 1; //!< [18] Comm Wake This bit is set when PHY COMWAKE signal is detected.
        unsigned DIAG_B : 1; //!< [19] 10B to 8B Decode Error This bit indicates errors were detected by 10b8b decoder. This bit indicates that one or more CRC errors were detected by the Link layer during FIS reception. This bit is set only when an error is detected on the received FIS data dword. This bit is not set when an error is detected on the primitive, regardless whether it is inside or outside the FIS.
        unsigned DIAG_D : 1; //!< [20] Disparity Error This bit is always cleared to 0 since it is not used by the AHCI specification.
        unsigned DIAG_C : 1; //!< [21] CRC Error
        unsigned DIAG_H : 1; //!< [22] Handshake Error This bit indicates that one or more R_ERRp was received in response to frame transmission. Such errors may be the result of a CRC error detected by the device, a disparity or 8b/10b decoding error, or other error condition leading to a negative handshake on a transmitted frame.
        unsigned DIAG_S : 1; //!< [23] Link Sequence Error This bit indicates that one or more Link state machine error conditions was encountered. One of the conditions that cause this bit to be set is device doing SYNC escape during FIS transmission.
        unsigned DIAG_T : 1; //!< [24] Transport State Transition Error This bit indicates that a Transport Layer protocol violation was detected since the last time this bit was cleared. See for details.
        unsigned DIAG_F : 1; //!< [25] Unknown FIS Type This bit indicates that one or more FISes were received by the Transport layer with good CRC, but had a type field that was not recognized/known and the length was less than or equal to 64bytes. When the Unknown FIS length exceeds 64 bytes, the DIAG_F bit is not set and the DIAG_T bit is set instead.
        unsigned DIAG_X : 1; //!< [26] Exchanged This bit is set to 1 when PHY COMINIT signal is detected. This bit is reflected in the SATA_P # 0 IS[PCS] bit.
        unsigned RESERVED2 : 5; //!< [31:27] Reserved
    } B;
} hw_sata_p0serr_t;
#endif

/*
 * constants & macros for entire SATA_P0SERR register
 */
#define HW_SATA_P0SERR_ADDR      (REGS_SATA_BASE + 0x130)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0SERR           (*(volatile hw_sata_p0serr_t *) HW_SATA_P0SERR_ADDR)
#define HW_SATA_P0SERR_RD()      (HW_SATA_P0SERR.U)
#define HW_SATA_P0SERR_WR(v)     (HW_SATA_P0SERR.U = (v))
#define HW_SATA_P0SERR_SET(v)    (HW_SATA_P0SERR_WR(HW_SATA_P0SERR_RD() |  (v)))
#define HW_SATA_P0SERR_CLR(v)    (HW_SATA_P0SERR_WR(HW_SATA_P0SERR_RD() & ~(v)))
#define HW_SATA_P0SERR_TOG(v)    (HW_SATA_P0SERR_WR(HW_SATA_P0SERR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_P0SERR bitfields
 */

/* --- Register HW_SATA_P0SERR, field ERR_I[0] (RO)
 *
 * This bit is set when any of the following SATA_P # 0 SERR register bits is set during non- Data
 * FIS transfer: • DIAG_C (CRC) • DIAG_H (Handshake) • ERR_C ("PHY Ready" negation)
 */

#define BP_SATA_P0SERR_ERR_I      (0)      //!< Bit position for SATA_P0SERR_ERR_I.
#define BM_SATA_P0SERR_ERR_I      (0x00000001)  //!< Bit mask for SATA_P0SERR_ERR_I.

//! @brief Get value of SATA_P0SERR_ERR_I from a register value.
#define BG_SATA_P0SERR_ERR_I(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SERR_ERR_I) >> BP_SATA_P0SERR_ERR_I)

/* --- Register HW_SATA_P0SERR, field ERR_M[1] (RO)
 *
 * Recovered Communication Error This bit is set to 1 when PHY Ready condition is detected after
 * interface initialization, but not after transition from Partial or Slumber power management state
 * to active state.
 */

#define BP_SATA_P0SERR_ERR_M      (1)      //!< Bit position for SATA_P0SERR_ERR_M.
#define BM_SATA_P0SERR_ERR_M      (0x00000002)  //!< Bit mask for SATA_P0SERR_ERR_M.

//! @brief Get value of SATA_P0SERR_ERR_M from a register value.
#define BG_SATA_P0SERR_ERR_M(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SERR_ERR_M) >> BP_SATA_P0SERR_ERR_M)

/* --- Register HW_SATA_P0SERR, field ERR_T[8] (RO)
 *
 * Non-Recovered Transient Data Integrity Error This bit is set when any of the following SATA_P # 0
 * SERR register bits is set during Data FIS transfer: ERR_P (Protocol) • DIAG_C (CRC) • DIAG_H
 * (Handshake) • ERR_C ("PHY Ready" negation)
 */

#define BP_SATA_P0SERR_ERR_T      (8)      //!< Bit position for SATA_P0SERR_ERR_T.
#define BM_SATA_P0SERR_ERR_T      (0x00000100)  //!< Bit mask for SATA_P0SERR_ERR_T.

//! @brief Get value of SATA_P0SERR_ERR_T from a register value.
#define BG_SATA_P0SERR_ERR_T(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SERR_ERR_T) >> BP_SATA_P0SERR_ERR_T)

/* --- Register HW_SATA_P0SERR, field ERR_C[9] (RO)
 *
 * Non-Recovered Persistent Communication Error This bit is set to 1 when PHY Ready signal is
 * negated due to the loss of communication with the device or problems with interface, but not
 * after transition from active to Partial or Slumber power management state.
 */

#define BP_SATA_P0SERR_ERR_C      (9)      //!< Bit position for SATA_P0SERR_ERR_C.
#define BM_SATA_P0SERR_ERR_C      (0x00000200)  //!< Bit mask for SATA_P0SERR_ERR_C.

//! @brief Get value of SATA_P0SERR_ERR_C from a register value.
#define BG_SATA_P0SERR_ERR_C(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SERR_ERR_C) >> BP_SATA_P0SERR_ERR_C)

/* --- Register HW_SATA_P0SERR, field ERR_P[10] (RO)
 *
 * Protocol Error This bit is set to 1 when any of the following conditions are detected. •
 * Transport state transition error (DIAG_T) • Link sequence error (DIAG_S) • RxFIFO overflow • Link
 * bad end error (WTRM instead of EOF is received).
 */

#define BP_SATA_P0SERR_ERR_P      (10)      //!< Bit position for SATA_P0SERR_ERR_P.
#define BM_SATA_P0SERR_ERR_P      (0x00000400)  //!< Bit mask for SATA_P0SERR_ERR_P.

//! @brief Get value of SATA_P0SERR_ERR_P from a register value.
#define BG_SATA_P0SERR_ERR_P(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SERR_ERR_P) >> BP_SATA_P0SERR_ERR_P)

/* --- Register HW_SATA_P0SERR, field ERR_E[11] (RO)
 *
 * Internal Error This bit is set to 1 when one or more AHB bus ERROR responses are detected on the
 * master interface.
 */

#define BP_SATA_P0SERR_ERR_E      (11)      //!< Bit position for SATA_P0SERR_ERR_E.
#define BM_SATA_P0SERR_ERR_E      (0x00000800)  //!< Bit mask for SATA_P0SERR_ERR_E.

//! @brief Get value of SATA_P0SERR_ERR_E from a register value.
#define BG_SATA_P0SERR_ERR_E(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SERR_ERR_E) >> BP_SATA_P0SERR_ERR_E)

/* --- Register HW_SATA_P0SERR, field DIAG_N[16] (RO)
 *
 * PHY Ready Change This bit indicates that the PHY Ready signal changed state. This bit is
 * reflected in the SATA_P # 0 IS[PRCS] bit.
 */

#define BP_SATA_P0SERR_DIAG_N      (16)      //!< Bit position for SATA_P0SERR_DIAG_N.
#define BM_SATA_P0SERR_DIAG_N      (0x00010000)  //!< Bit mask for SATA_P0SERR_DIAG_N.

//! @brief Get value of SATA_P0SERR_DIAG_N from a register value.
#define BG_SATA_P0SERR_DIAG_N(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SERR_DIAG_N) >> BP_SATA_P0SERR_DIAG_N)

/* --- Register HW_SATA_P0SERR, field DIAG_I[17] (RO)
 *
 * PHY Internal Error This bit is set when the PHY detects some internal error as indicated by the
 * assertion of the p # 0 _phy_rx_err input. The setting of this bit is controlled by the
 * SATA_BISTCR[ERREN] bit: when ERREN==0 (default), only errors occurring inside the received FIS
 * cause DIAG_I bit to be set; when ERREN==1, any error inside or outside the FIS causes the DIAG_I
 * bit to be set.
 */

#define BP_SATA_P0SERR_DIAG_I      (17)      //!< Bit position for SATA_P0SERR_DIAG_I.
#define BM_SATA_P0SERR_DIAG_I      (0x00020000)  //!< Bit mask for SATA_P0SERR_DIAG_I.

//! @brief Get value of SATA_P0SERR_DIAG_I from a register value.
#define BG_SATA_P0SERR_DIAG_I(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SERR_DIAG_I) >> BP_SATA_P0SERR_DIAG_I)

/* --- Register HW_SATA_P0SERR, field DIAG_W[18] (RO)
 *
 * Comm Wake This bit is set when PHY COMWAKE signal is detected.
 */

#define BP_SATA_P0SERR_DIAG_W      (18)      //!< Bit position for SATA_P0SERR_DIAG_W.
#define BM_SATA_P0SERR_DIAG_W      (0x00040000)  //!< Bit mask for SATA_P0SERR_DIAG_W.

//! @brief Get value of SATA_P0SERR_DIAG_W from a register value.
#define BG_SATA_P0SERR_DIAG_W(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SERR_DIAG_W) >> BP_SATA_P0SERR_DIAG_W)

/* --- Register HW_SATA_P0SERR, field DIAG_B[19] (RO)
 *
 * 10B to 8B Decode Error This bit indicates errors were detected by 10b8b decoder. This bit
 * indicates that one or more CRC errors were detected by the Link layer during FIS reception. This
 * bit is set only when an error is detected on the received FIS data dword. This bit is not set
 * when an error is detected on the primitive, regardless whether it is inside or outside the FIS.
 */

#define BP_SATA_P0SERR_DIAG_B      (19)      //!< Bit position for SATA_P0SERR_DIAG_B.
#define BM_SATA_P0SERR_DIAG_B      (0x00080000)  //!< Bit mask for SATA_P0SERR_DIAG_B.

//! @brief Get value of SATA_P0SERR_DIAG_B from a register value.
#define BG_SATA_P0SERR_DIAG_B(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SERR_DIAG_B) >> BP_SATA_P0SERR_DIAG_B)

/* --- Register HW_SATA_P0SERR, field DIAG_D[20] (RO)
 *
 * Disparity Error This bit is always cleared to 0 since it is not used by the AHCI specification.
 */

#define BP_SATA_P0SERR_DIAG_D      (20)      //!< Bit position for SATA_P0SERR_DIAG_D.
#define BM_SATA_P0SERR_DIAG_D      (0x00100000)  //!< Bit mask for SATA_P0SERR_DIAG_D.

//! @brief Get value of SATA_P0SERR_DIAG_D from a register value.
#define BG_SATA_P0SERR_DIAG_D(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SERR_DIAG_D) >> BP_SATA_P0SERR_DIAG_D)

/* --- Register HW_SATA_P0SERR, field DIAG_C[21] (RO)
 *
 * CRC Error
 */

#define BP_SATA_P0SERR_DIAG_C      (21)      //!< Bit position for SATA_P0SERR_DIAG_C.
#define BM_SATA_P0SERR_DIAG_C      (0x00200000)  //!< Bit mask for SATA_P0SERR_DIAG_C.

//! @brief Get value of SATA_P0SERR_DIAG_C from a register value.
#define BG_SATA_P0SERR_DIAG_C(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SERR_DIAG_C) >> BP_SATA_P0SERR_DIAG_C)

/* --- Register HW_SATA_P0SERR, field DIAG_H[22] (RO)
 *
 * Handshake Error This bit indicates that one or more R_ERRp was received in response to frame
 * transmission. Such errors may be the result of a CRC error detected by the device, a disparity or
 * 8b/10b decoding error, or other error condition leading to a negative handshake on a transmitted
 * frame.
 */

#define BP_SATA_P0SERR_DIAG_H      (22)      //!< Bit position for SATA_P0SERR_DIAG_H.
#define BM_SATA_P0SERR_DIAG_H      (0x00400000)  //!< Bit mask for SATA_P0SERR_DIAG_H.

//! @brief Get value of SATA_P0SERR_DIAG_H from a register value.
#define BG_SATA_P0SERR_DIAG_H(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SERR_DIAG_H) >> BP_SATA_P0SERR_DIAG_H)

/* --- Register HW_SATA_P0SERR, field DIAG_S[23] (RO)
 *
 * Link Sequence Error This bit indicates that one or more Link state machine error conditions was
 * encountered. One of the conditions that cause this bit to be set is device doing SYNC escape
 * during FIS transmission.
 */

#define BP_SATA_P0SERR_DIAG_S      (23)      //!< Bit position for SATA_P0SERR_DIAG_S.
#define BM_SATA_P0SERR_DIAG_S      (0x00800000)  //!< Bit mask for SATA_P0SERR_DIAG_S.

//! @brief Get value of SATA_P0SERR_DIAG_S from a register value.
#define BG_SATA_P0SERR_DIAG_S(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SERR_DIAG_S) >> BP_SATA_P0SERR_DIAG_S)

/* --- Register HW_SATA_P0SERR, field DIAG_T[24] (RO)
 *
 * Transport State Transition Error This bit indicates that a Transport Layer protocol violation was
 * detected since the last time this bit was cleared. See for details.
 */

#define BP_SATA_P0SERR_DIAG_T      (24)      //!< Bit position for SATA_P0SERR_DIAG_T.
#define BM_SATA_P0SERR_DIAG_T      (0x01000000)  //!< Bit mask for SATA_P0SERR_DIAG_T.

//! @brief Get value of SATA_P0SERR_DIAG_T from a register value.
#define BG_SATA_P0SERR_DIAG_T(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SERR_DIAG_T) >> BP_SATA_P0SERR_DIAG_T)

/* --- Register HW_SATA_P0SERR, field DIAG_F[25] (RO)
 *
 * Unknown FIS Type This bit indicates that one or more FISes were received by the Transport layer
 * with good CRC, but had a type field that was not recognized/known and the length was less than or
 * equal to 64bytes. When the Unknown FIS length exceeds 64 bytes, the DIAG_F bit is not set and the
 * DIAG_T bit is set instead.
 */

#define BP_SATA_P0SERR_DIAG_F      (25)      //!< Bit position for SATA_P0SERR_DIAG_F.
#define BM_SATA_P0SERR_DIAG_F      (0x02000000)  //!< Bit mask for SATA_P0SERR_DIAG_F.

//! @brief Get value of SATA_P0SERR_DIAG_F from a register value.
#define BG_SATA_P0SERR_DIAG_F(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SERR_DIAG_F) >> BP_SATA_P0SERR_DIAG_F)

/* --- Register HW_SATA_P0SERR, field DIAG_X[26] (RO)
 *
 * Exchanged This bit is set to 1 when PHY COMINIT signal is detected. This bit is reflected in the
 * SATA_P # 0 IS[PCS] bit.
 */

#define BP_SATA_P0SERR_DIAG_X      (26)      //!< Bit position for SATA_P0SERR_DIAG_X.
#define BM_SATA_P0SERR_DIAG_X      (0x04000000)  //!< Bit mask for SATA_P0SERR_DIAG_X.

//! @brief Get value of SATA_P0SERR_DIAG_X from a register value.
#define BG_SATA_P0SERR_DIAG_X(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SERR_DIAG_X) >> BP_SATA_P0SERR_DIAG_X)

//-------------------------------------------------------------------------------------------
// HW_SATA_P0SACT - Port0 Serial ATA Active Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_P0SACT - Port0 Serial ATA Active Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sata_p0sact
{
    reg32_t U;
    struct _hw_sata_p0sact_bitfields
    {
        unsigned DS : 32; //!< [31:0] Device Status This field is bit significant. Each bit corresponds to the TAG and command slot of a native queued command, where bit 0 corresponds to TAG 0 and command slot 0. Software sets this field prior to issuing a native queued command for a particular command slot. Prior to writing SATA_P # 0 CI[TAG] to 1, the software sets DS[TAG] to 1 to indicate that a command with that TAG is outstanding. This field is cleared to 0 when: • The software writes SATA_P # 0 CMD[ST from a 1 to a 0 . • The device sends a Set Device Bits FIS to the Port. The Port clears bits in this field that are set in the SActive field of the Set Device Bits FIS. The Port clears only bits that correspond to native queued commands that have completed successfully. This field is not cleared by the following: • Port reset (COMRESET). • Software reset. Software must write this field only when SATA_P # 0 CMD[ST] bit is set to 1.
    } B;
} hw_sata_p0sact_t;
#endif

/*
 * constants & macros for entire SATA_P0SACT register
 */
#define HW_SATA_P0SACT_ADDR      (REGS_SATA_BASE + 0x134)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0SACT           (*(volatile hw_sata_p0sact_t *) HW_SATA_P0SACT_ADDR)
#define HW_SATA_P0SACT_RD()      (HW_SATA_P0SACT.U)
#define HW_SATA_P0SACT_WR(v)     (HW_SATA_P0SACT.U = (v))
#define HW_SATA_P0SACT_SET(v)    (HW_SATA_P0SACT_WR(HW_SATA_P0SACT_RD() |  (v)))
#define HW_SATA_P0SACT_CLR(v)    (HW_SATA_P0SACT_WR(HW_SATA_P0SACT_RD() & ~(v)))
#define HW_SATA_P0SACT_TOG(v)    (HW_SATA_P0SACT_WR(HW_SATA_P0SACT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_P0SACT bitfields
 */

/* --- Register HW_SATA_P0SACT, field DS[31:0] (RW)
 *
 * Device Status This field is bit significant. Each bit corresponds to the TAG and command slot of
 * a native queued command, where bit 0 corresponds to TAG 0 and command slot 0. Software sets this
 * field prior to issuing a native queued command for a particular command slot. Prior to writing
 * SATA_P # 0 CI[TAG] to 1, the software sets DS[TAG] to 1 to indicate that a command with that TAG
 * is outstanding. This field is cleared to 0 when: • The software writes SATA_P # 0 CMD[ST from a 1
 * to a 0 . • The device sends a Set Device Bits FIS to the Port. The Port clears bits in this field
 * that are set in the SActive field of the Set Device Bits FIS. The Port clears only bits that
 * correspond to native queued commands that have completed successfully. This field is not cleared
 * by the following: • Port reset (COMRESET). • Software reset. Software must write this field only
 * when SATA_P # 0 CMD[ST] bit is set to 1.
 */

#define BP_SATA_P0SACT_DS      (0)      //!< Bit position for SATA_P0SACT_DS.
#define BM_SATA_P0SACT_DS      (0xffffffff)  //!< Bit mask for SATA_P0SACT_DS.

//! @brief Get value of SATA_P0SACT_DS from a register value.
#define BG_SATA_P0SACT_DS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SACT_DS) >> BP_SATA_P0SACT_DS)

//! @brief Format value for bitfield SATA_P0SACT_DS.
#define BF_SATA_P0SACT_DS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0SACT_DS) & BM_SATA_P0SACT_DS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DS field to a new value.
#define BW_SATA_P0SACT_DS(v)   (HW_SATA_P0SACT_WR((HW_SATA_P0SACT_RD() & ~BM_SATA_P0SACT_DS) | BF_SATA_P0SACT_DS(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_SATA_P0CI - Port0 Command Issue Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_P0CI - Port0 Command Issue Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sata_p0ci
{
    reg32_t U;
    struct _hw_sata_p0ci_bitfields
    {
        unsigned CI : 32; //!< [31:0] Command Issued This field is bit significant. Each bit corresponds to a command slot, where bit 0 corresponds to command slot 0. This field is set by the software to indicate to the Port that a command has been built in system memory for a command slot and may be sent to the device. When the Port receives a FIS which clears the BSY, DRQ, and ERR bits for the command, it clears the corresponding bit in this register for that command slot. Bits in this field can only be set to 1 by the software when SATA_P # 0 CMD[ST] is set to 1. This field is reset when SATA_P # 0 CMD[ST] is written from a 1 to a 0 by the software.
    } B;
} hw_sata_p0ci_t;
#endif

/*
 * constants & macros for entire SATA_P0CI register
 */
#define HW_SATA_P0CI_ADDR      (REGS_SATA_BASE + 0x138)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0CI           (*(volatile hw_sata_p0ci_t *) HW_SATA_P0CI_ADDR)
#define HW_SATA_P0CI_RD()      (HW_SATA_P0CI.U)
#define HW_SATA_P0CI_WR(v)     (HW_SATA_P0CI.U = (v))
#define HW_SATA_P0CI_SET(v)    (HW_SATA_P0CI_WR(HW_SATA_P0CI_RD() |  (v)))
#define HW_SATA_P0CI_CLR(v)    (HW_SATA_P0CI_WR(HW_SATA_P0CI_RD() & ~(v)))
#define HW_SATA_P0CI_TOG(v)    (HW_SATA_P0CI_WR(HW_SATA_P0CI_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_P0CI bitfields
 */

/* --- Register HW_SATA_P0CI, field CI[31:0] (RW)
 *
 * Command Issued This field is bit significant. Each bit corresponds to a command slot, where bit 0
 * corresponds to command slot 0. This field is set by the software to indicate to the Port that a
 * command has been built in system memory for a command slot and may be sent to the device. When
 * the Port receives a FIS which clears the BSY, DRQ, and ERR bits for the command, it clears the
 * corresponding bit in this register for that command slot. Bits in this field can only be set to 1
 * by the software when SATA_P # 0 CMD[ST] is set to 1. This field is reset when SATA_P # 0 CMD[ST]
 * is written from a 1 to a 0 by the software.
 */

#define BP_SATA_P0CI_CI      (0)      //!< Bit position for SATA_P0CI_CI.
#define BM_SATA_P0CI_CI      (0xffffffff)  //!< Bit mask for SATA_P0CI_CI.

//! @brief Get value of SATA_P0CI_CI from a register value.
#define BG_SATA_P0CI_CI(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0CI_CI) >> BP_SATA_P0CI_CI)

//! @brief Format value for bitfield SATA_P0CI_CI.
#define BF_SATA_P0CI_CI(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0CI_CI) & BM_SATA_P0CI_CI)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CI field to a new value.
#define BW_SATA_P0CI_CI(v)   (HW_SATA_P0CI_WR((HW_SATA_P0CI_RD() & ~BM_SATA_P0CI_CI) | BF_SATA_P0CI_CI(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_SATA_P0SNTF - Port0 Serial ATA Notification Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_P0SNTF - Port0 Serial ATA Notification Register (W1C)
 *
 * Reset value: 0x00000000
 *
 * This register is used to determine when asynchronous notification events have occurred for
 * directly connected devices and devices connected to a Port Multiplier.   Size: 32 bits  Address
 * offset: for # = 0 to 7:  P0SNTF: 0x13C  P1SNTF: 0x1BC  P2SNTF: 0x23C  P3SNTF: 0x2BC  P4SNTF:
 * 0x33C  P5SNTF: 0x3BC  P6SNTF: 0x43C  P7SNTF: 0x4BC    Read/write access: Read/Write One to Clear
 * Reset: 0x0000_0000
 */
typedef union _hw_sata_p0sntf
{
    reg32_t U;
    struct _hw_sata_p0sntf_bitfields
    {
        unsigned PMN : 16; //!< [15:0] PM Notify This field indicates whether a particular device with the corresponding PM Port number issued a Set Device Bits FIS to the SATA block Port with the Notification bit set: • PM Port 0h sets bit 0, • PM Port 1h sets bit 1, ... • PM Port Fh sets bit 15. Individual bits are cleared by the software writing 1s to the corresponding bit positions. This field is reset on Global reset, but it is not reset by Port reset (COMRESET) or software reset.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
    } B;
} hw_sata_p0sntf_t;
#endif

/*
 * constants & macros for entire SATA_P0SNTF register
 */
#define HW_SATA_P0SNTF_ADDR      (REGS_SATA_BASE + 0x13c)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0SNTF           (*(volatile hw_sata_p0sntf_t *) HW_SATA_P0SNTF_ADDR)
#define HW_SATA_P0SNTF_RD()      (HW_SATA_P0SNTF.U)
#define HW_SATA_P0SNTF_WR(v)     (HW_SATA_P0SNTF.U = (v))
#define HW_SATA_P0SNTF_SET(v)    (HW_SATA_P0SNTF_WR(HW_SATA_P0SNTF_RD() |  (v)))
#define HW_SATA_P0SNTF_CLR(v)    (HW_SATA_P0SNTF_WR(HW_SATA_P0SNTF_RD() & ~(v)))
#define HW_SATA_P0SNTF_TOG(v)    (HW_SATA_P0SNTF_WR(HW_SATA_P0SNTF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_P0SNTF bitfields
 */

/* --- Register HW_SATA_P0SNTF, field PMN[15:0] (W1C)
 *
 * PM Notify This field indicates whether a particular device with the corresponding PM Port number
 * issued a Set Device Bits FIS to the SATA block Port with the Notification bit set: • PM Port 0h
 * sets bit 0, • PM Port 1h sets bit 1, ... • PM Port Fh sets bit 15. Individual bits are cleared by
 * the software writing 1s to the corresponding bit positions. This field is reset on Global reset,
 * but it is not reset by Port reset (COMRESET) or software reset.
 */

#define BP_SATA_P0SNTF_PMN      (0)      //!< Bit position for SATA_P0SNTF_PMN.
#define BM_SATA_P0SNTF_PMN      (0x0000ffff)  //!< Bit mask for SATA_P0SNTF_PMN.

//! @brief Get value of SATA_P0SNTF_PMN from a register value.
#define BG_SATA_P0SNTF_PMN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0SNTF_PMN) >> BP_SATA_P0SNTF_PMN)

//! @brief Format value for bitfield SATA_P0SNTF_PMN.
#define BF_SATA_P0SNTF_PMN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0SNTF_PMN) & BM_SATA_P0SNTF_PMN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PMN field to a new value.
#define BW_SATA_P0SNTF_PMN(v)   (HW_SATA_P0SNTF_WR((HW_SATA_P0SNTF_RD() & ~BM_SATA_P0SNTF_PMN) | BF_SATA_P0SNTF_PMN(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_SATA_P0DMACR - Port0 DMA Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_P0DMACR - Port0 DMA Control Register (RW)
 *
 * Reset value: 0x00000044
 *
 * This register contains bits for controlling the Port DMA engine. The software can change the
 * fields of this register only when SATA_P 0  # CMD[ST]=0. Power-up (system reset), Global reset,
 * or Port reset (COMRESET) reset this register to the default value.   Size: 32 bits  Address
 * offset: for # = 0 to 7:  P0DMACR: 0x170  P1DMACR: 0x1F0  P2DMACR: 0x270  P3DMACR: 0x2F0  P4DMACR:
 * 0x370  P5DMACR: 0x3F0  P6DMACR: 0x470  P7DMACR: 0x4F0    Read/write access: Read/Write or Read-
 * only  Reset: 0x0000_0044
 */
typedef union _hw_sata_p0dmacr
{
    reg32_t U;
    struct _hw_sata_p0dmacr_bitfields
    {
        unsigned TXTS : 4; //!< [3:0] Transmit Transaction Size This field defines the DMA transaction size in DWORDs for transmit (system bus read, device write) operation. The options for this field are: This field is read-write when SATA_P 0 # CMD[ST]=0 and read-only when SATA_P 0 # CMD[ST]=1. The maximum value of this field is determined by the TxFIFO depth set by the P#_TXFIFO_DEPTH parameter. When the software attempts to write a value exceeding this value, the maximum value would be set instead.
        unsigned RXTS : 4; //!< [7:4] Receive Transaction Size This field defines the Port DMA transaction size in DWORDs for receive (system bus write, device read) operation. This field is read-write when SATA_P 0 # CMD[ST]=0 and read-only when SATA_P 0 # CMD[ST]=1. The maximum value of this field is determined by the RxFIFO depth set by the P#_RXFIFO_DEPTH parameter. When the software attempts to write a value exceeding this value, the maximum value would be set instead.
        unsigned RESERVED0 : 8; //!< [15:8] Reserved.
        unsigned RESERVED1 : 16; //!< [31:16] Reserved
    } B;
} hw_sata_p0dmacr_t;
#endif

/*
 * constants & macros for entire SATA_P0DMACR register
 */
#define HW_SATA_P0DMACR_ADDR      (REGS_SATA_BASE + 0x170)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0DMACR           (*(volatile hw_sata_p0dmacr_t *) HW_SATA_P0DMACR_ADDR)
#define HW_SATA_P0DMACR_RD()      (HW_SATA_P0DMACR.U)
#define HW_SATA_P0DMACR_WR(v)     (HW_SATA_P0DMACR.U = (v))
#define HW_SATA_P0DMACR_SET(v)    (HW_SATA_P0DMACR_WR(HW_SATA_P0DMACR_RD() |  (v)))
#define HW_SATA_P0DMACR_CLR(v)    (HW_SATA_P0DMACR_WR(HW_SATA_P0DMACR_RD() & ~(v)))
#define HW_SATA_P0DMACR_TOG(v)    (HW_SATA_P0DMACR_WR(HW_SATA_P0DMACR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_P0DMACR bitfields
 */

/* --- Register HW_SATA_P0DMACR, field TXTS[3:0] (RW)
 *
 * Transmit Transaction Size This field defines the DMA transaction size in DWORDs for transmit
 * (system bus read, device write) operation. The options for this field are: This field is read-
 * write when SATA_P 0 # CMD[ST]=0 and read-only when SATA_P 0 # CMD[ST]=1. The maximum value of
 * this field is determined by the TxFIFO depth set by the P#_TXFIFO_DEPTH parameter. When the
 * software attempts to write a value exceeding this value, the maximum value would be set instead.
 *
 * Values:
 * 0x0 - 1 DWORD
 * 0x1 - 2 DWORD
 * 0x2 - 4 DWORD
 * 0x3 - 8 DWORD
 * 0x4 - 16 DWORDs (maximum value when P#_ TXFIFO_DEPTH=32)
 * 0x5 - 32 DWORDs (maximum value when P#_ TXFIFO_DEPTH=64)
 * 0x6 - 64 DWORDs (maximum value when P#_ TXFIFO_DEPTH=128)
 * 0x7 - 128 DWORDs (maximum value when P#_ TXFIFO_DEPTH=256)
 * 0x8 - 256 DWORDs (maximum value when P#_ TXFIFO_DEPTH=512)
 * 0x9 - 512 DWORDs (maximum value when P#_ TXFIFO_DEPTH=1024)
 * 0xA - 1024 DWORDs (maximum value when P#_ TXFIFO_DEPTH=2048) All other values are reserved and should not
 *     be used.
 */

#define BP_SATA_P0DMACR_TXTS      (0)      //!< Bit position for SATA_P0DMACR_TXTS.
#define BM_SATA_P0DMACR_TXTS      (0x0000000f)  //!< Bit mask for SATA_P0DMACR_TXTS.

//! @brief Get value of SATA_P0DMACR_TXTS from a register value.
#define BG_SATA_P0DMACR_TXTS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0DMACR_TXTS) >> BP_SATA_P0DMACR_TXTS)

//! @brief Format value for bitfield SATA_P0DMACR_TXTS.
#define BF_SATA_P0DMACR_TXTS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0DMACR_TXTS) & BM_SATA_P0DMACR_TXTS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXTS field to a new value.
#define BW_SATA_P0DMACR_TXTS(v)   (HW_SATA_P0DMACR_WR((HW_SATA_P0DMACR_RD() & ~BM_SATA_P0DMACR_TXTS) | BF_SATA_P0DMACR_TXTS(v)))
#endif


/* --- Register HW_SATA_P0DMACR, field RXTS[7:4] (RW)
 *
 * Receive Transaction Size This field defines the Port DMA transaction size in DWORDs for receive
 * (system bus write, device read) operation. This field is read-write when SATA_P 0 # CMD[ST]=0 and
 * read-only when SATA_P 0 # CMD[ST]=1. The maximum value of this field is determined by the RxFIFO
 * depth set by the P#_RXFIFO_DEPTH parameter. When the software attempts to write a value exceeding
 * this value, the maximum value would be set instead.
 *
 * Values:
 * 0x0 - 1 DWORD
 * 0x1 - 2 DWORD
 * 0x2 - 4 DWORD
 * 0x3 - 8 DWORD
 * 0x4 - 16 DWORDs (maximum value when P#_ RXFIFO_DEPTH=64)
 * 0x5 - 32 DWORD
 * 0x6 - 64 DWORDs (maximum value when P#_ RXFIFO_DEPTH=128)
 * 0x7 - 128 DWORDs (maximum value when P#_ RXFIFO_DEPTH=256)
 * 0x8 - 256 DWORDs (maximum value when P#_ RXFIFO_DEPTH=512)
 * 0x9 - 12 DWORDs (maximum value when P#_ RXFIFO_DEPTH=1024)
 * 0xA - 1024 DWORDs (maximum value when P#_ RXFIFO_DEPTH=2048) All other values are reserved and should not
 *     be used.
 */

#define BP_SATA_P0DMACR_RXTS      (4)      //!< Bit position for SATA_P0DMACR_RXTS.
#define BM_SATA_P0DMACR_RXTS      (0x000000f0)  //!< Bit mask for SATA_P0DMACR_RXTS.

//! @brief Get value of SATA_P0DMACR_RXTS from a register value.
#define BG_SATA_P0DMACR_RXTS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0DMACR_RXTS) >> BP_SATA_P0DMACR_RXTS)

//! @brief Format value for bitfield SATA_P0DMACR_RXTS.
#define BF_SATA_P0DMACR_RXTS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0DMACR_RXTS) & BM_SATA_P0DMACR_RXTS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXTS field to a new value.
#define BW_SATA_P0DMACR_RXTS(v)   (HW_SATA_P0DMACR_WR((HW_SATA_P0DMACR_RD() & ~BM_SATA_P0DMACR_RXTS) | BF_SATA_P0DMACR_RXTS(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_SATA_P0PHYCR - Port0 PHY Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_P0PHYCR - Port0 PHY Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register is used for Port PHY control. This register only exists when PHY_CTRL_W parameter
 * is set to a non-zero value, otherwise this location is reserved. The width is set by the
 * PHY_CTRL_W parameter (valid range: 0 to 32). When PHY_CTRL_W < 32, the remaining bits are
 * reserved: reads return zeros, writes have no effect.   Bits of this register are connected to the
 * corresponding bits of the p 0  # _phy_ctrl output Port. Resets on power- up (system reset) only
 * to the PHY_CTRL_DEF value.   The SATA_P #  0 PHYCR register supports only 32-bit write access
 * (s_hsize = 3'b010).    Size: 32 bits  Address offset: for # = 0 to 7:  P0PHYCR: 0x178  P1PHYCR:
 * 0x1F8  P2PHYCR: 0x278  P3PHYCR: 0x2F8  P4PHYCR: 0x378  P5PHYCR: 0x3F8  P6PHYCR: 0x478  P7PHYCR:
 * 0x4F8    Read/write access: Read/Write  Reset: 0x0000_0000 PHY_CTRL_DEF
 */
typedef union _hw_sata_p0phycr
{
    reg32_t U;
    struct _hw_sata_p0phycr_bitfields
    {
        unsigned CR_DATA_IN : 16; //!< [15:0] CR Address and Write Data Input Bus. Supplies and captures address and write data.
        unsigned CR_CAP_ADDR : 1; //!< [16] CR Capture Address. Captures phy_cr_data_in[15:0] into the Address register.
        unsigned CR_CAP_DATA : 1; //!< [17] CR Capture Data. Captures phy_cr_data_in[15:0] into the Write Data register.
        unsigned CR_WRITE : 1; //!< [18] CR Write. Writes the Write Data register to the referenced Address register.
        unsigned CR_READ : 1; //!< [19] CR Read. Reads from the referenced Address register.
        unsigned TEST_PDDQ : 1; //!< [20] Test IDDQ
        unsigned RESERVED0 : 11; //!< [31:21] Reserved
    } B;
} hw_sata_p0phycr_t;
#endif

/*
 * constants & macros for entire SATA_P0PHYCR register
 */
#define HW_SATA_P0PHYCR_ADDR      (REGS_SATA_BASE + 0x178)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0PHYCR           (*(volatile hw_sata_p0phycr_t *) HW_SATA_P0PHYCR_ADDR)
#define HW_SATA_P0PHYCR_RD()      (HW_SATA_P0PHYCR.U)
#define HW_SATA_P0PHYCR_WR(v)     (HW_SATA_P0PHYCR.U = (v))
#define HW_SATA_P0PHYCR_SET(v)    (HW_SATA_P0PHYCR_WR(HW_SATA_P0PHYCR_RD() |  (v)))
#define HW_SATA_P0PHYCR_CLR(v)    (HW_SATA_P0PHYCR_WR(HW_SATA_P0PHYCR_RD() & ~(v)))
#define HW_SATA_P0PHYCR_TOG(v)    (HW_SATA_P0PHYCR_WR(HW_SATA_P0PHYCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SATA_P0PHYCR bitfields
 */

/* --- Register HW_SATA_P0PHYCR, field CR_DATA_IN[15:0] (RW)
 *
 * CR Address and Write Data Input Bus. Supplies and captures address and write data.
 */

#define BP_SATA_P0PHYCR_CR_DATA_IN      (0)      //!< Bit position for SATA_P0PHYCR_CR_DATA_IN.
#define BM_SATA_P0PHYCR_CR_DATA_IN      (0x0000ffff)  //!< Bit mask for SATA_P0PHYCR_CR_DATA_IN.

//! @brief Get value of SATA_P0PHYCR_CR_DATA_IN from a register value.
#define BG_SATA_P0PHYCR_CR_DATA_IN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0PHYCR_CR_DATA_IN) >> BP_SATA_P0PHYCR_CR_DATA_IN)

//! @brief Format value for bitfield SATA_P0PHYCR_CR_DATA_IN.
#define BF_SATA_P0PHYCR_CR_DATA_IN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0PHYCR_CR_DATA_IN) & BM_SATA_P0PHYCR_CR_DATA_IN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CR_DATA_IN field to a new value.
#define BW_SATA_P0PHYCR_CR_DATA_IN(v)   (HW_SATA_P0PHYCR_WR((HW_SATA_P0PHYCR_RD() & ~BM_SATA_P0PHYCR_CR_DATA_IN) | BF_SATA_P0PHYCR_CR_DATA_IN(v)))
#endif

/* --- Register HW_SATA_P0PHYCR, field CR_CAP_ADDR[16] (RW)
 *
 * CR Capture Address. Captures phy_cr_data_in[15:0] into the Address register.
 */

#define BP_SATA_P0PHYCR_CR_CAP_ADDR      (16)      //!< Bit position for SATA_P0PHYCR_CR_CAP_ADDR.
#define BM_SATA_P0PHYCR_CR_CAP_ADDR      (0x00010000)  //!< Bit mask for SATA_P0PHYCR_CR_CAP_ADDR.

//! @brief Get value of SATA_P0PHYCR_CR_CAP_ADDR from a register value.
#define BG_SATA_P0PHYCR_CR_CAP_ADDR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0PHYCR_CR_CAP_ADDR) >> BP_SATA_P0PHYCR_CR_CAP_ADDR)

//! @brief Format value for bitfield SATA_P0PHYCR_CR_CAP_ADDR.
#define BF_SATA_P0PHYCR_CR_CAP_ADDR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0PHYCR_CR_CAP_ADDR) & BM_SATA_P0PHYCR_CR_CAP_ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CR_CAP_ADDR field to a new value.
#define BW_SATA_P0PHYCR_CR_CAP_ADDR(v)   (HW_SATA_P0PHYCR_WR((HW_SATA_P0PHYCR_RD() & ~BM_SATA_P0PHYCR_CR_CAP_ADDR) | BF_SATA_P0PHYCR_CR_CAP_ADDR(v)))
#endif

/* --- Register HW_SATA_P0PHYCR, field CR_CAP_DATA[17] (RW)
 *
 * CR Capture Data. Captures phy_cr_data_in[15:0] into the Write Data register.
 */

#define BP_SATA_P0PHYCR_CR_CAP_DATA      (17)      //!< Bit position for SATA_P0PHYCR_CR_CAP_DATA.
#define BM_SATA_P0PHYCR_CR_CAP_DATA      (0x00020000)  //!< Bit mask for SATA_P0PHYCR_CR_CAP_DATA.

//! @brief Get value of SATA_P0PHYCR_CR_CAP_DATA from a register value.
#define BG_SATA_P0PHYCR_CR_CAP_DATA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0PHYCR_CR_CAP_DATA) >> BP_SATA_P0PHYCR_CR_CAP_DATA)

//! @brief Format value for bitfield SATA_P0PHYCR_CR_CAP_DATA.
#define BF_SATA_P0PHYCR_CR_CAP_DATA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0PHYCR_CR_CAP_DATA) & BM_SATA_P0PHYCR_CR_CAP_DATA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CR_CAP_DATA field to a new value.
#define BW_SATA_P0PHYCR_CR_CAP_DATA(v)   (HW_SATA_P0PHYCR_WR((HW_SATA_P0PHYCR_RD() & ~BM_SATA_P0PHYCR_CR_CAP_DATA) | BF_SATA_P0PHYCR_CR_CAP_DATA(v)))
#endif

/* --- Register HW_SATA_P0PHYCR, field CR_WRITE[18] (RW)
 *
 * CR Write. Writes the Write Data register to the referenced Address register.
 */

#define BP_SATA_P0PHYCR_CR_WRITE      (18)      //!< Bit position for SATA_P0PHYCR_CR_WRITE.
#define BM_SATA_P0PHYCR_CR_WRITE      (0x00040000)  //!< Bit mask for SATA_P0PHYCR_CR_WRITE.

//! @brief Get value of SATA_P0PHYCR_CR_WRITE from a register value.
#define BG_SATA_P0PHYCR_CR_WRITE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0PHYCR_CR_WRITE) >> BP_SATA_P0PHYCR_CR_WRITE)

//! @brief Format value for bitfield SATA_P0PHYCR_CR_WRITE.
#define BF_SATA_P0PHYCR_CR_WRITE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0PHYCR_CR_WRITE) & BM_SATA_P0PHYCR_CR_WRITE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CR_WRITE field to a new value.
#define BW_SATA_P0PHYCR_CR_WRITE(v)   (HW_SATA_P0PHYCR_WR((HW_SATA_P0PHYCR_RD() & ~BM_SATA_P0PHYCR_CR_WRITE) | BF_SATA_P0PHYCR_CR_WRITE(v)))
#endif

/* --- Register HW_SATA_P0PHYCR, field CR_READ[19] (RW)
 *
 * CR Read. Reads from the referenced Address register.
 */

#define BP_SATA_P0PHYCR_CR_READ      (19)      //!< Bit position for SATA_P0PHYCR_CR_READ.
#define BM_SATA_P0PHYCR_CR_READ      (0x00080000)  //!< Bit mask for SATA_P0PHYCR_CR_READ.

//! @brief Get value of SATA_P0PHYCR_CR_READ from a register value.
#define BG_SATA_P0PHYCR_CR_READ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0PHYCR_CR_READ) >> BP_SATA_P0PHYCR_CR_READ)

//! @brief Format value for bitfield SATA_P0PHYCR_CR_READ.
#define BF_SATA_P0PHYCR_CR_READ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0PHYCR_CR_READ) & BM_SATA_P0PHYCR_CR_READ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the CR_READ field to a new value.
#define BW_SATA_P0PHYCR_CR_READ(v)   (HW_SATA_P0PHYCR_WR((HW_SATA_P0PHYCR_RD() & ~BM_SATA_P0PHYCR_CR_READ) | BF_SATA_P0PHYCR_CR_READ(v)))
#endif

/* --- Register HW_SATA_P0PHYCR, field TEST_PDDQ[20] (RW)
 *
 * Test IDDQ
 */

#define BP_SATA_P0PHYCR_TEST_PDDQ      (20)      //!< Bit position for SATA_P0PHYCR_TEST_PDDQ.
#define BM_SATA_P0PHYCR_TEST_PDDQ      (0x00100000)  //!< Bit mask for SATA_P0PHYCR_TEST_PDDQ.

//! @brief Get value of SATA_P0PHYCR_TEST_PDDQ from a register value.
#define BG_SATA_P0PHYCR_TEST_PDDQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0PHYCR_TEST_PDDQ) >> BP_SATA_P0PHYCR_TEST_PDDQ)

//! @brief Format value for bitfield SATA_P0PHYCR_TEST_PDDQ.
#define BF_SATA_P0PHYCR_TEST_PDDQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_SATA_P0PHYCR_TEST_PDDQ) & BM_SATA_P0PHYCR_TEST_PDDQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TEST_PDDQ field to a new value.
#define BW_SATA_P0PHYCR_TEST_PDDQ(v)   (HW_SATA_P0PHYCR_WR((HW_SATA_P0PHYCR_RD() & ~BM_SATA_P0PHYCR_TEST_PDDQ) | BF_SATA_P0PHYCR_TEST_PDDQ(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_SATA_P0PHYSR - Port0 PHY Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SATA_P0PHYSR - Port0 PHY Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * This register is used to monitor PHY status. This register only exists when PHY_STAT_W parameter
 * is set to a non-zero value, otherwise this location is reserved. The width is set by the
 * PHY_STAT_W parameter (valid range: 0 to 32). When PHY_CTRL_W < 32, the remaining bits are
 * reserved: reads return zeros, writes have no effect.   The bits of this register reflect the
 * state of the corresponding bits of the p #  0 _phy_status input.  Signals connected to the p #  0
 * _phy_status input can be asynchronous to any of the SATA block clocks, however they must not
 * change faster than five hclk periods, otherwise the SATA_P #  0 PHYSR register may never be
 * updated with the intermediate changing values.   Size: 32 bits  Address offset: for # = 0 to 7:
 * P0PHYSR: 0x17C  P1PHYSR: 0x1FC  P2PHYSR: 0x27C  P3PHYSR: 0x2FC  P4PHYSR: 0x37C  P5PHYSR: 0x3FC
 * P6PHYSR: 0x47C  P7PHYSR: 0x4FC    Read/write access: Read-only  Reset: p#_phy_status
 */
typedef union _hw_sata_p0physr
{
    reg32_t U;
    struct _hw_sata_p0physr_bitfields
    {
        unsigned CR_DATA_OUT : 16; //!< [15:0] CR Data Output Bus. Always presents last read data.
        unsigned RESERVED0 : 2; //!< [17:16] 
        unsigned CR_ACK : 1; //!< [18] CR Acknowledgement. Acknowledgement for the phy_cr_cap_addr, phy_cr_cap_data, phy_cr_write, and phy_cr_read control signals.
        unsigned RESERVED1 : 13; //!< [31:19] 
    } B;
} hw_sata_p0physr_t;
#endif

/*
 * constants & macros for entire SATA_P0PHYSR register
 */
#define HW_SATA_P0PHYSR_ADDR      (REGS_SATA_BASE + 0x17c)

#ifndef __LANGUAGE_ASM__
#define HW_SATA_P0PHYSR           (*(volatile hw_sata_p0physr_t *) HW_SATA_P0PHYSR_ADDR)
#define HW_SATA_P0PHYSR_RD()      (HW_SATA_P0PHYSR.U)
#endif

/*
 * constants & macros for individual SATA_P0PHYSR bitfields
 */

/* --- Register HW_SATA_P0PHYSR, field CR_DATA_OUT[15:0] (RO)
 *
 * CR Data Output Bus. Always presents last read data.
 */

#define BP_SATA_P0PHYSR_CR_DATA_OUT      (0)      //!< Bit position for SATA_P0PHYSR_CR_DATA_OUT.
#define BM_SATA_P0PHYSR_CR_DATA_OUT      (0x0000ffff)  //!< Bit mask for SATA_P0PHYSR_CR_DATA_OUT.

//! @brief Get value of SATA_P0PHYSR_CR_DATA_OUT from a register value.
#define BG_SATA_P0PHYSR_CR_DATA_OUT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0PHYSR_CR_DATA_OUT) >> BP_SATA_P0PHYSR_CR_DATA_OUT)

/* --- Register HW_SATA_P0PHYSR, field CR_ACK[18] (RO)
 *
 * CR Acknowledgement. Acknowledgement for the phy_cr_cap_addr, phy_cr_cap_data, phy_cr_write, and
 * phy_cr_read control signals.
 */

#define BP_SATA_P0PHYSR_CR_ACK      (18)      //!< Bit position for SATA_P0PHYSR_CR_ACK.
#define BM_SATA_P0PHYSR_CR_ACK      (0x00040000)  //!< Bit mask for SATA_P0PHYSR_CR_ACK.

//! @brief Get value of SATA_P0PHYSR_CR_ACK from a register value.
#define BG_SATA_P0PHYSR_CR_ACK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_SATA_P0PHYSR_CR_ACK) >> BP_SATA_P0PHYSR_CR_ACK)


/*!
 * @brief All SATA module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_sata
{
    volatile hw_sata_cap_t CAP; //!< HBA Capabilites Register
    volatile hw_sata_ghc_t GHC; //!< Global HBA Control Register
    volatile hw_sata_is_t IS; //!< Interrupt Status Register
    volatile hw_sata_pi_t PI; //!< Ports Implemented Register
    volatile hw_sata_vs_t VS; //!< AHCl Version Register
    volatile hw_sata_ccc_ctl_t CCC_CTL; //!< Command Completion Coalescing Control
    volatile hw_sata_ccc_ports_t CCC_PORTS; //!< Command Completion Coalescing Ports
    reg32_t _reserved0[2];
    volatile hw_sata_cap2_t CAP2; //!< HBA Capabilities Extended Register
    reg32_t _reserved1[30];
    volatile hw_sata_bistafr_t BISTAFR; //!< BIST Activate FIS Register
    volatile hw_sata_bistcr_t BISTCR; //!< BIST Control Register
    volatile hw_sata_bistfctr_t BISTFCTR; //!< BIST FIS Count Register
    volatile hw_sata_bistsr_t BISTSR; //!< BIST Status Register
    reg32_t _reserved2[3];
    volatile hw_sata_oobr_t OOBR; //!< OOB Register
    reg32_t _reserved3[4];
    volatile hw_sata_gpcr_t GPCR; //!< General Purpose Control Register
    volatile hw_sata_gpsr_t GPSR; //!< General Purpose Status Register
    reg32_t _reserved4[2];
    volatile hw_sata_timer1ms_t TIMER1MS; //!< Timer 1-ms Register
    reg32_t _reserved5;
    volatile hw_sata_gparam1r_t GPARAM1R; //!< Global Parameter 1 Register
    volatile hw_sata_gparam2r_t GPARAM2R; //!< Global Parameter 1 Register
    volatile hw_sata_pparamr_t PPARAMR; //!< Port Parameter Register
    volatile hw_sata_testr_t TESTR; //!< Test Register
    volatile hw_sata_versionr_t VERSIONR; //!< Version Register
    reg32_t _reserved6;
    volatile hw_sata_p0clb_t P0CLB; //!< Port0 Command List Base Address Register
    reg32_t _reserved7;
    volatile hw_sata_p0fb_t P0FB; //!< Port0 FIS Base Address Register
    reg32_t _reserved8;
    volatile hw_sata_p0is_t P0IS; //!< Port0 Interrupt Status Register
    volatile hw_sata_p0ie_t P0IE; //!< Port0 Interrupt Enable Register
    volatile hw_sata_p0cmd_t P0CMD; //!< Port0 Command Register
    reg32_t _reserved9;
    volatile hw_sata_p0tfd_t P0TFD; //!< Port0 Task File Data Register
    volatile hw_sata_p0sig_t P0SIG; //!< Port0 Signature Register
    volatile hw_sata_p0ssts_t P0SSTS; //!< Port0 Serial ATA Status Register
    volatile hw_sata_p0sctl_t P0SCTL; //!< Port0 Serial ATA Control {SControl} Register
    volatile hw_sata_p0serr_t P0SERR; //!< Port0 Serial ATA Error Register
    volatile hw_sata_p0sact_t P0SACT; //!< Port0 Serial ATA Active Register
    volatile hw_sata_p0ci_t P0CI; //!< Port0 Command Issue Register
    volatile hw_sata_p0sntf_t P0SNTF; //!< Port0 Serial ATA Notification Register
    reg32_t _reserved10[12];
    volatile hw_sata_p0dmacr_t P0DMACR; //!< Port0 DMA Control Register
    reg32_t _reserved11;
    volatile hw_sata_p0phycr_t P0PHYCR; //!< Port0 PHY Control Register
    volatile hw_sata_p0physr_t P0PHYSR; //!< Port0 PHY Status Register
} hw_sata_t;
#pragma pack()

//! @brief Macro to access all SATA registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_SATA(0)</code>.
#define HW_SATA     (*(volatile hw_sata_t *) REGS_SATA_BASE)

#endif


#endif // __HW_SATA_REGISTERS_H__
