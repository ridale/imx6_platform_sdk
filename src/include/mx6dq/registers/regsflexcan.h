/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_FLEXCAN_REGISTERS_H__
#define __HW_FLEXCAN_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6DQ FLEXCAN registers defined in this header file.
 *
 * - HW_FLEXCAN_MCR - Module Configuration Register
 * - HW_FLEXCAN_CTRL - Control Register
 * - HW_FLEXCAN_TIMER - Free Running Timer
 * - HW_FLEXCAN_RXGMASK - Rx Global Mask
 * - HW_FLEXCAN_RX14MASK - Rx 14 Mask
 * - HW_FLEXCAN_RX15MASK - Rx 15 Mask
 * - HW_FLEXCAN_ECR - Error Counter Register
 * - HW_FLEXCAN_ESR - Error and Status Register
 * - HW_FLEXCAN_IMASK2 - Interrupt Masks 2 Register
 * - HW_FLEXCAN_IMASK1 - Interrupt Masks 1 Register
 * - HW_FLEXCAN_IFLAG2 - Interrupt Flags 2 Register
 * - HW_FLEXCAN_IFLAG1 - Interrupt Flags 1 Register
 * - HW_FLEXCAN_GFWR - Glitch Filter Width Register
 * - HW_FLEXCAN_RX0IMR - Rx Individual Mask Registers
 * - HW_FLEXCAN_RX63IMR - Rx Individual Mask Registers
 *
 * - hw_flexcan_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_FLEXCAN_BASE
#define HW_FLEXCAN_INSTANCE_COUNT (2) //!< Number of instances of the FLEXCAN module.
#define HW_FLEXCAN1 (1) //!< Instance number for FLEXCAN1.
#define HW_FLEXCAN2 (2) //!< Instance number for FLEXCAN2.

#define REGS_FLEXCAN1_BASE (0x02090000) //!< Base address for FLEXCAN instance number 1.
#define REGS_FLEXCAN2_BASE (0x02094000) //!< Base address for FLEXCAN instance number 2.

//! @brief Get the base address of FLEXCAN by instance number.
//! @param x FLEXCAN instance number, from 1 through 2.
#define REGS_FLEXCAN_BASE(x) ( (x) == HW_FLEXCAN1 ? REGS_FLEXCAN1_BASE : (x) == HW_FLEXCAN2 ? REGS_FLEXCAN2_BASE : 0x00d00000)

//! @brief Get the instance number given a base address.
//! @param b Base address for an instance of FLEXCAN.
#define REGS_FLEXCAN_INSTANCE(b) ( (b) == REGS_FLEXCAN1_BASE ? HW_FLEXCAN1 : (b) == REGS_FLEXCAN2_BASE ? HW_FLEXCAN2 : 0)
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
// HW_FLEXCAN_MCR - Module Configuration Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_MCR - Module Configuration Register (RW)
 *
 * Reset value: 0x5980000f
 *
 * This register defines global system configurations, such as the block operation mode (low power,
 * for example) and maximum message buffer configuration. {statement} Most of the fields in this
 * register can be accessed at any time, except the MAXMB field, which should only be changed while
 * the block is in Freeze Mode {statement} .
 */
typedef union _hw_flexcan_mcr
{
    reg32_t U;
    struct _hw_flexcan_mcr_bitfields
    {
        unsigned MAXMB : 6; //!< [5:0] This 6-bit field defines the maximum number of message buffers that will take part in the matching and arbitration processes {flexcan2_ipi_slv_flex_reg_mcr_maxmb} . The reset value (0x0F) is equivalent to 16 Mbyte configuration {flexcan2_ipi_slv_flex_reg_mcr_maxmb} . This field should be changed only while the block is in Freeze Mode {statement} . Maximum message buffers in use = MAXMB + 1. {flexcan2_ipi_slv_flex_reg_mcr_maxmb} MAXMB has to be programmed with a value smaller or equal to the number of available Message Buffers, otherwise FLEXCAN will not transmit or receive frames {statement} .
        unsigned RESERVED0 : 2; //!< [7:6] Reserved
        unsigned IDAM : 2; //!< [9:8] This 2-bit field identifies the format of the elements of the Rx FIFO filter table, as shown below. Note that all elements of the table are configured at the same time by this field (they are all the same format). See . 00 Format A One full ID (standard or extended) per filter element. 01 Format B Two full standard IDs or two partial 14-bit extended IDs per filter element 10 Format C Four partial 8-bit IDs (standard or extended) per filter element. 11 Format D All frames rejected.
        unsigned RESERVED1 : 2; //!< [11:10] Reserved
        unsigned AEN : 1; //!< [12] This bit is supplied for backwards compatibility reasons. When asserted, it enables the Tx abort feature. This feature guarantees a safe procedure for aborting a pending transmission, so that no frame is sent in the CAN bus without notification.
        unsigned LPRIO_EN : 1; //!< [13] This bit is provided for backwards compatibility reasons. It controls whether the local priority feature is enabled or not. It is used to extend the ID used during the arbitration process. With this extended ID concept, the arbitration process is done based on the full 32-bit word, but the actual transmitted ID still has 11-bit for standard frames and 29-bit for extended frames.
        unsigned RESERVED2 : 2; //!< [15:14] Reserved
        unsigned BCC : 1; //!< [16] This bit is provided to support Backwards Compatibility with previous FLEXCAN versions {statement} . When this bit is negated, the following configuration is applied: For ARM platforms supporting individual Rx ID masking, this feature is disabled {flexcan2_ipi_slv_flex_reg_rxmask} . Instead of individual ID masking per message buffer, FLEXCAN uses its previous masking scheme with RXGMASK, RX14MASK and RX15MASK {flexcan2_ipi_slv_flex_reg_rxmask} . The reception queue feature is disabled {flexcan2_ipi_slv_flex_queue_cs_code_rx} . Upon receiving a message, if the first message buffer with a matching ID that is found is still occupied by a previous unread message, FLEXCAN will not look for another matching message buffer {flexcan2_ipi_slv_flex_queue_cs_code_rx} . It will override this message buffer with the new message and set the CODE field to 0110 (overrun) {flexcan2_ipi_slv_flex_queue_cs_code_rx} . Upon reset this bit is negated, allowing legacy software to work without modification {flexcan2_ipi_slv_flex_reg_access} .
        unsigned SRX_DIS : 1; //!< [17] This bit defines whether FLEXCAN is allowed to receive frames transmitted by itself. If this bit is asserted, frames transmitted by the block will not be stored in any message buffers, regardless if the message buffers is programmed with an ID that matches the transmitted frame, and no interrupt flag or interrupt signal will be generated due to the frame reception.
        unsigned DOZE : 1; //!< [18] This bit defines whether FLEXCAN is allowed to enter low power mode when Doze Mode is requested at ARM platform level by the assertion of the Green-Line signal ipg_doze {flexcan2_ipi_slv_flex_dozemode} . This bit is automatically reset when FLEXCAN wakes up from Doze Mode upon detecting activity on the CAN bus (self wake-up enabled) {flexcan2_ipi_slv_flex_dozemode} . Doze Mode is not supported in i.MX53
        unsigned WAK_SRC : 1; //!< [19] This bit defines whether the integrated low-pass filter is applied to protect the Rx CAN input. {statement}
        unsigned LPM_ACK : 1; //!< [20] This read-only bit indicates that FLEXCAN is either in Disable Mode and Stop Mode {flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_slv_flex_dozemode} . Either of these low power modes can not be entered until all current transmission or reception processes have finished, so the ARM can poll the LPM_ACK bit to know when FLEXCAN has actually entered low power mode {flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_slv_flex_dozemode} {statement} .
        unsigned WRN_EN : 1; //!< [21] When asserted, this bit enables the generation of the TWRN_INT and RWRN_INT flags in the Error and Status Register. If WRN_EN is negated, the TWRN_INT and RWRN_INT flags will always be zero, independent of the values of the error counters, and no warning interrupt will ever be generated.
        unsigned SLF_WAK : 1; //!< [22] This bit enables the Self Wake Up feature when FLEXCAN is in Stop Mode {flexcan2_ipi_slv_flex_reg_mcr_swu} . If this bit had been asserted by the time FLEXCAN entered Stop Mode, then FLEXCAN will look for a recessive to dominant transition on the bus during these modes {flexcan2_ipi_slv_flex_reg_mcr_swu} . If a transition from recessive to dominant is detected during Stop Mode, then FLEXCAN generates, if enabled to do so, a Wake Up interrupt to the ARM so that it can resume the clocks globally. {flexcan2_ipi_slv_flex_reg_mcr_swu} This bit can not be written while the block is in Stop Mode {flexcan2_ipi_slv_flex_reg_mcr_swu} .
        unsigned SUPV : 1; //!< [23] This bit configures some of the FLEXCAN registers to be either in Supervisor or Unrestricted memory space {flexcan2_ipi_slv_flex_reg_access}{flexcan2_ipi_slv_flex_ram_access}{flexcan2_ipi_slv_flex_ram_rximask_access} . The registers affected by this bit are marked as S/U in the Access Type column of the Memory Map. Reset value of this bit is 1, so the affected registers start with Supervisor access restrictions . {flexcan2_ipi_slv_flex_reg_access}
        unsigned FRZ_ACK : 1; //!< [24] This read-only bit indicates that FLEXCAN is in Freeze Mode and its prescaler is stopped {flexcan2_ipi_slv_flex_freezemode} . The Freeze Mode request cannot be granted until current transmission or reception processes have finished {flexcan2_ipi_slv_flex_freezemode} . Therefore the software can poll the FRZ_ACK bit to know when FLEXCAN has actually entered Freeze Mode {flexcan2_ipi_slv_flex_freezemode} . If Freeze Mode request is negated, then this bit is negated once the FLEXCAN prescaler is running again. {flexcan2_ipi_slv_flex_freezemode} If Freeze Mode is requested while FLEXCAN is in any of the low power modes, then the FRZ_ACK bit will only be set when the low power mode is exited {flexcan2_ipi_slv_flex_freezemode} {statement} .
        unsigned SOFT_RST : 1; //!< [25] When this bit is asserted, FLEXCAN resets its internal state machines and some of the memory mapped registers {flexcan2_ipi_slv_flex_softreset} . The following registers are reset: MCR (except the MDIS bit), TIMER, TCR, ECR, ESR, IMASK1, IMASK2, IFLAG1, IFLAG2. {flexcan2_ipi_slv_flex_softreset} Configuration registers that control the interface to the CAN bus are not affected by soft reset {flexcan2_ipi_slv_flex_softreset} . The following registers are unaffected {flexcan2_ipi_slv_flex_softreset} : CTRL {flexcan2_ipi_slv_flex_softreset} RXIMR0‚RXIMR63 {flexcan2_ipi_slv_flex_softreset} RXGMASK, RX14MASK, RX15MASK {flexcan2_ipi_slv_flex_softreset} all Message Buffers {flexcan2_ipi_slv_flex_softreset} The SOFT_RST bit can be asserted directly by the ARM when it writes to the MCR Register. Because soft reset is synchronous and has to follow a request/acknowledge procedure across clock domains, it may take some time to fully propagate its effect {statement} . The SOFT_RST bit remains asserted while reset is pending, and is automatically negated when reset completes {flexcan2_ipi_slv_flex_softreset} . Therefore, software can poll this bit to know when the soft reset has completed. {flexcan2_ipi_slv_flex_softreset} Soft reset cannot be applied while clocks are shut down in any of the low power modes {statement} . The block should be first removed from low power mode, and then soft reset can be applied {statement} .
        unsigned WAK_MSK : 1; //!< [26] This bit enables the Wake Up Interrupt generation. {flexcan2_ipi_slv_flex_reg_esr_int}
        unsigned NOT_RDY : 1; //!< [27] This read-only bit indicates that FLEXCAN is either in Disable Mode, Stop Mode or Freeze Mode {flexcan2_ipi_slv_flex_freezemode}{flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_slv_flex_dozemode} . It is negated once FLEXCAN has exited these modes. {flexcan2_ipi_slv_flex_freezemode}{flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_slv_flex_dozemode}{flexcan2_ipi_slv_flex_reg_mcr_swu}
        unsigned HALT : 1; //!< [28] Assertion of this bit puts the FLEXCAN block into Freeze Mode {flexcan2_ipi_slv_flex_freezemode} . The ARM should clear it after initializing the Message Buffers and Control Register {statement} . No reception or transmission is performed by FLEXCAN before this bit is cleared {flexcan2_ipi_slv_flex_freezemode} . While in Freeze Mode, the ARM has write access to the Error Counter Register, that is otherwise read-only {flexcan2_ipi_slv_flex_freezemode} . Freeze Mode can not be entered while FLEXCAN is in any of the low power modes {flexcan2_ipi_slv_flex_freezemode} {statement} .
        unsigned FEN : 1; //!< [29] This bit controls whether the FIFO feature is enabled or not. When FEN is set, message buffers 0 to 7 cannot be used for normal reception and transmission because the corresponding memory region (0x80-0xFF) is used by the FIFO engine.
        unsigned FRZ : 1; //!< [30] The FRZ bit specifies the FLEXCAN behavior when the HALT bit in the MCR Register is set or when Debug Mode is requested at ARM platform level . When FRZ is asserted, FLEXCAN is enabled to enter Freeze Mode {flexcan2_ipi_slv_flex_freezemode} . Negation of this bit field causes FLEXCAN to exit from Freeze Mode {flexcan2_ipi_slv_flex_freezemode} .
        unsigned MDIS : 1; //!< [31] This bit controls whether FLEXCAN is enabled or not {flexcan2_ipi_slv_flex_disablemode} . When disabled, FLEXCAN shuts down the clocks to the CAN Protocol Interface and Message Buffer Management sub-blocks {flexcan2_ipi_slv_flex_disablemode} . This is the only bit in MCR not affected by soft reset {flexcan2_ipi_slv_flex_softreset} . {statement}
    } B;
} hw_flexcan_mcr_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_MCR register
 */
#define HW_FLEXCAN_MCR_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_MCR(x)           (*(volatile hw_flexcan_mcr_t *) HW_FLEXCAN_MCR_ADDR(x))
#define HW_FLEXCAN_MCR_RD(x)        (HW_FLEXCAN_MCR(x).U)
#define HW_FLEXCAN_MCR_WR(x, v)     (HW_FLEXCAN_MCR(x).U = (v))
#define HW_FLEXCAN_MCR_SET(x, v)    (HW_FLEXCAN_MCR_WR(x, HW_FLEXCAN_MCR_RD(x) |  (v)))
#define HW_FLEXCAN_MCR_CLR(x, v)    (HW_FLEXCAN_MCR_WR(x, HW_FLEXCAN_MCR_RD(x) & ~(v)))
#define HW_FLEXCAN_MCR_TOG(x, v)    (HW_FLEXCAN_MCR_WR(x, HW_FLEXCAN_MCR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_MCR bitfields
 */

/* --- Register HW_FLEXCAN_MCR, field MAXMB[5:0] (RW)
 *
 * This 6-bit field defines the maximum number of message buffers that will take part in the
 * matching and arbitration processes {flexcan2_ipi_slv_flex_reg_mcr_maxmb} . The reset value (0x0F)
 * is equivalent to 16 Mbyte configuration {flexcan2_ipi_slv_flex_reg_mcr_maxmb} . This field should
 * be changed only while the block is in Freeze Mode {statement} . Maximum message buffers in use =
 * MAXMB + 1. {flexcan2_ipi_slv_flex_reg_mcr_maxmb} MAXMB has to be programmed with a value smaller
 * or equal to the number of available Message Buffers, otherwise FLEXCAN will not transmit or
 * receive frames {statement} .
 */

#define BP_FLEXCAN_MCR_MAXMB      (0)      //!< Bit position for FLEXCAN_MCR_MAXMB.
#define BM_FLEXCAN_MCR_MAXMB      (0x0000003f)  //!< Bit mask for FLEXCAN_MCR_MAXMB.

//! @brief Get value of FLEXCAN_MCR_MAXMB from a register value.
#define BG_FLEXCAN_MCR_MAXMB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_MAXMB) >> BP_FLEXCAN_MCR_MAXMB)

//! @brief Format value for bitfield FLEXCAN_MCR_MAXMB.
#define BF_FLEXCAN_MCR_MAXMB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_MCR_MAXMB) & BM_FLEXCAN_MCR_MAXMB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MAXMB field to a new value.
#define BW_FLEXCAN_MCR_MAXMB(x, v)   (HW_FLEXCAN_MCR_WR(x, (HW_FLEXCAN_MCR_RD(x) & ~BM_FLEXCAN_MCR_MAXMB) | BF_FLEXCAN_MCR_MAXMB(v)))
#endif

/* --- Register HW_FLEXCAN_MCR, field IDAM[9:8] (RW)
 *
 * This 2-bit field identifies the format of the elements of the Rx FIFO filter table, as shown
 * below. Note that all elements of the table are configured at the same time by this field (they
 * are all the same format). See . 00 Format A One full ID (standard or extended) per filter
 * element. 01 Format B Two full standard IDs or two partial 14-bit extended IDs per filter element
 * 10 Format C Four partial 8-bit IDs (standard or extended) per filter element. 11 Format D All
 * frames rejected.
 */

#define BP_FLEXCAN_MCR_IDAM      (8)      //!< Bit position for FLEXCAN_MCR_IDAM.
#define BM_FLEXCAN_MCR_IDAM      (0x00000300)  //!< Bit mask for FLEXCAN_MCR_IDAM.

//! @brief Get value of FLEXCAN_MCR_IDAM from a register value.
#define BG_FLEXCAN_MCR_IDAM(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_IDAM) >> BP_FLEXCAN_MCR_IDAM)

//! @brief Format value for bitfield FLEXCAN_MCR_IDAM.
#define BF_FLEXCAN_MCR_IDAM(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_MCR_IDAM) & BM_FLEXCAN_MCR_IDAM)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IDAM field to a new value.
#define BW_FLEXCAN_MCR_IDAM(x, v)   (HW_FLEXCAN_MCR_WR(x, (HW_FLEXCAN_MCR_RD(x) & ~BM_FLEXCAN_MCR_IDAM) | BF_FLEXCAN_MCR_IDAM(v)))
#endif

/* --- Register HW_FLEXCAN_MCR, field AEN[12] (RW)
 *
 * This bit is supplied for backwards compatibility reasons. When asserted, it enables the Tx abort
 * feature. This feature guarantees a safe procedure for aborting a pending transmission, so that no
 * frame is sent in the CAN bus without notification.
 *
 * Values:
 * 0 - Abort disabled
 * 1 - Abort enabled
 */

#define BP_FLEXCAN_MCR_AEN      (12)      //!< Bit position for FLEXCAN_MCR_AEN.
#define BM_FLEXCAN_MCR_AEN      (0x00001000)  //!< Bit mask for FLEXCAN_MCR_AEN.

//! @brief Get value of FLEXCAN_MCR_AEN from a register value.
#define BG_FLEXCAN_MCR_AEN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_AEN) >> BP_FLEXCAN_MCR_AEN)

//! @brief Format value for bitfield FLEXCAN_MCR_AEN.
#define BF_FLEXCAN_MCR_AEN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_MCR_AEN) & BM_FLEXCAN_MCR_AEN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AEN field to a new value.
#define BW_FLEXCAN_MCR_AEN(x, v)   (HW_FLEXCAN_MCR_WR(x, (HW_FLEXCAN_MCR_RD(x) & ~BM_FLEXCAN_MCR_AEN) | BF_FLEXCAN_MCR_AEN(v)))
#endif


/* --- Register HW_FLEXCAN_MCR, field LPRIO_EN[13] (RW)
 *
 * This bit is provided for backwards compatibility reasons. It controls whether the local priority
 * feature is enabled or not. It is used to extend the ID used during the arbitration process. With
 * this extended ID concept, the arbitration process is done based on the full 32-bit word, but the
 * actual transmitted ID still has 11-bit for standard frames and 29-bit for extended frames.
 *
 * Values:
 * 0 - Local Priority disabled
 * 1 - Local Priority enabled
 */

#define BP_FLEXCAN_MCR_LPRIO_EN      (13)      //!< Bit position for FLEXCAN_MCR_LPRIO_EN.
#define BM_FLEXCAN_MCR_LPRIO_EN      (0x00002000)  //!< Bit mask for FLEXCAN_MCR_LPRIO_EN.

//! @brief Get value of FLEXCAN_MCR_LPRIO_EN from a register value.
#define BG_FLEXCAN_MCR_LPRIO_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_LPRIO_EN) >> BP_FLEXCAN_MCR_LPRIO_EN)

//! @brief Format value for bitfield FLEXCAN_MCR_LPRIO_EN.
#define BF_FLEXCAN_MCR_LPRIO_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_MCR_LPRIO_EN) & BM_FLEXCAN_MCR_LPRIO_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LPRIO_EN field to a new value.
#define BW_FLEXCAN_MCR_LPRIO_EN(x, v)   (HW_FLEXCAN_MCR_WR(x, (HW_FLEXCAN_MCR_RD(x) & ~BM_FLEXCAN_MCR_LPRIO_EN) | BF_FLEXCAN_MCR_LPRIO_EN(v)))
#endif


/* --- Register HW_FLEXCAN_MCR, field BCC[16] (RW)
 *
 * This bit is provided to support Backwards Compatibility with previous FLEXCAN versions
 * {statement} . When this bit is negated, the following configuration is applied: For ARM platforms
 * supporting individual Rx ID masking, this feature is disabled {flexcan2_ipi_slv_flex_reg_rxmask}
 * . Instead of individual ID masking per message buffer, FLEXCAN uses its previous masking scheme
 * with RXGMASK, RX14MASK and RX15MASK {flexcan2_ipi_slv_flex_reg_rxmask} . The reception queue
 * feature is disabled {flexcan2_ipi_slv_flex_queue_cs_code_rx} . Upon receiving a message, if the
 * first message buffer with a matching ID that is found is still occupied by a previous unread
 * message, FLEXCAN will not look for another matching message buffer
 * {flexcan2_ipi_slv_flex_queue_cs_code_rx} . It will override this message buffer with the new
 * message and set the CODE field to 0110 (overrun) {flexcan2_ipi_slv_flex_queue_cs_code_rx} . Upon
 * reset this bit is negated, allowing legacy software to work without modification
 * {flexcan2_ipi_slv_flex_reg_access} .
 *
 * Values:
 * 0 - Individual Rx masking and queue feature are disabled {flexcan2_ipi_slv_flex_queue_cs_code_rx} .
 * 1 - Individual Rx masking and queue feature are enabled {flexcan2_ipi_slv_flex_queue_cs_code_rx} .
 */

#define BP_FLEXCAN_MCR_BCC      (16)      //!< Bit position for FLEXCAN_MCR_BCC.
#define BM_FLEXCAN_MCR_BCC      (0x00010000)  //!< Bit mask for FLEXCAN_MCR_BCC.

//! @brief Get value of FLEXCAN_MCR_BCC from a register value.
#define BG_FLEXCAN_MCR_BCC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_BCC) >> BP_FLEXCAN_MCR_BCC)

//! @brief Format value for bitfield FLEXCAN_MCR_BCC.
#define BF_FLEXCAN_MCR_BCC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_MCR_BCC) & BM_FLEXCAN_MCR_BCC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BCC field to a new value.
#define BW_FLEXCAN_MCR_BCC(x, v)   (HW_FLEXCAN_MCR_WR(x, (HW_FLEXCAN_MCR_RD(x) & ~BM_FLEXCAN_MCR_BCC) | BF_FLEXCAN_MCR_BCC(v)))
#endif


/* --- Register HW_FLEXCAN_MCR, field SRX_DIS[17] (RW)
 *
 * This bit defines whether FLEXCAN is allowed to receive frames transmitted by itself. If this bit
 * is asserted, frames transmitted by the block will not be stored in any message buffers,
 * regardless if the message buffers is programmed with an ID that matches the transmitted frame,
 * and no interrupt flag or interrupt signal will be generated due to the frame reception.
 *
 * Values:
 * 0 - Self reception enabled
 * 1 - Self reception disabled
 */

#define BP_FLEXCAN_MCR_SRX_DIS      (17)      //!< Bit position for FLEXCAN_MCR_SRX_DIS.
#define BM_FLEXCAN_MCR_SRX_DIS      (0x00020000)  //!< Bit mask for FLEXCAN_MCR_SRX_DIS.

//! @brief Get value of FLEXCAN_MCR_SRX_DIS from a register value.
#define BG_FLEXCAN_MCR_SRX_DIS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_SRX_DIS) >> BP_FLEXCAN_MCR_SRX_DIS)

//! @brief Format value for bitfield FLEXCAN_MCR_SRX_DIS.
#define BF_FLEXCAN_MCR_SRX_DIS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_MCR_SRX_DIS) & BM_FLEXCAN_MCR_SRX_DIS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SRX_DIS field to a new value.
#define BW_FLEXCAN_MCR_SRX_DIS(x, v)   (HW_FLEXCAN_MCR_WR(x, (HW_FLEXCAN_MCR_RD(x) & ~BM_FLEXCAN_MCR_SRX_DIS) | BF_FLEXCAN_MCR_SRX_DIS(v)))
#endif


/* --- Register HW_FLEXCAN_MCR, field DOZE[18] (RW)
 *
 * This bit defines whether FLEXCAN is allowed to enter low power mode when Doze Mode is requested
 * at ARM platform level by the assertion of the Green-Line signal ipg_doze
 * {flexcan2_ipi_slv_flex_dozemode} . This bit is automatically reset when FLEXCAN wakes up from
 * Doze Mode upon detecting activity on the CAN bus (self wake-up enabled)
 * {flexcan2_ipi_slv_flex_dozemode} . Doze Mode is not supported in i.MX53
 *
 * Values:
 * 0 - FLEXCAN is not enabled to enter low power mode when Doze Mode is requested
 *     {flexcan2_ipi_slv_flex_dozemode}
 * 1 - FLEXCAN is enabled to enter low power mode when Doze Mode is requested
 *     {flexcan2_ipi_slv_flex_dozemode}
 */

#define BP_FLEXCAN_MCR_DOZE      (18)      //!< Bit position for FLEXCAN_MCR_DOZE.
#define BM_FLEXCAN_MCR_DOZE      (0x00040000)  //!< Bit mask for FLEXCAN_MCR_DOZE.

//! @brief Get value of FLEXCAN_MCR_DOZE from a register value.
#define BG_FLEXCAN_MCR_DOZE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_DOZE) >> BP_FLEXCAN_MCR_DOZE)

//! @brief Format value for bitfield FLEXCAN_MCR_DOZE.
#define BF_FLEXCAN_MCR_DOZE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_MCR_DOZE) & BM_FLEXCAN_MCR_DOZE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOZE field to a new value.
#define BW_FLEXCAN_MCR_DOZE(x, v)   (HW_FLEXCAN_MCR_WR(x, (HW_FLEXCAN_MCR_RD(x) & ~BM_FLEXCAN_MCR_DOZE) | BF_FLEXCAN_MCR_DOZE(v)))
#endif


/* --- Register HW_FLEXCAN_MCR, field WAK_SRC[19] (RW)
 *
 * This bit defines whether the integrated low-pass filter is applied to protect the Rx CAN input.
 * {statement}
 *
 * Values:
 * 1 - FLEXCAN us _slv_flex_reg_mcr_swu}
 */

#define BP_FLEXCAN_MCR_WAK_SRC      (19)      //!< Bit position for FLEXCAN_MCR_WAK_SRC.
#define BM_FLEXCAN_MCR_WAK_SRC      (0x00080000)  //!< Bit mask for FLEXCAN_MCR_WAK_SRC.

//! @brief Get value of FLEXCAN_MCR_WAK_SRC from a register value.
#define BG_FLEXCAN_MCR_WAK_SRC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_WAK_SRC) >> BP_FLEXCAN_MCR_WAK_SRC)

//! @brief Format value for bitfield FLEXCAN_MCR_WAK_SRC.
#define BF_FLEXCAN_MCR_WAK_SRC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_MCR_WAK_SRC) & BM_FLEXCAN_MCR_WAK_SRC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WAK_SRC field to a new value.
#define BW_FLEXCAN_MCR_WAK_SRC(x, v)   (HW_FLEXCAN_MCR_WR(x, (HW_FLEXCAN_MCR_RD(x) & ~BM_FLEXCAN_MCR_WAK_SRC) | BF_FLEXCAN_MCR_WAK_SRC(v)))
#endif


/* --- Register HW_FLEXCAN_MCR, field LPM_ACK[20] (RO)
 *
 * This read-only bit indicates that FLEXCAN is either in Disable Mode and Stop Mode {flexcan2_ipi_s
 * lv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_slv_flex_dozemode} . Either of
 * these low power modes can not be entered until all current transmission or reception processes
 * have finished, so the ARM can poll the LPM_ACK bit to know when FLEXCAN has actually entered low
 * power mode {flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_slv_f
 * lex_dozemode} {statement} .
 *
 * Values:
 * 0 - FLEXCAN not in any of the low power modes
 *     {flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_slv_flex_doz
 *     emode}
 * 1 - FLEXCAN is either in Disable Mode, or Stop mode
 *     {flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_slv_flex_doz
 *     emode}
 */

#define BP_FLEXCAN_MCR_LPM_ACK      (20)      //!< Bit position for FLEXCAN_MCR_LPM_ACK.
#define BM_FLEXCAN_MCR_LPM_ACK      (0x00100000)  //!< Bit mask for FLEXCAN_MCR_LPM_ACK.

//! @brief Get value of FLEXCAN_MCR_LPM_ACK from a register value.
#define BG_FLEXCAN_MCR_LPM_ACK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_LPM_ACK) >> BP_FLEXCAN_MCR_LPM_ACK)


/* --- Register HW_FLEXCAN_MCR, field WRN_EN[21] (RW)
 *
 * When asserted, this bit enables the generation of the TWRN_INT and RWRN_INT flags in the Error
 * and Status Register. If WRN_EN is negated, the TWRN_INT and RWRN_INT flags will always be zero,
 * independent of the values of the error counters, and no warning interrupt will ever be generated.
 *
 * Values:
 * 0 - TWRN_INT and RWRN_INT bits are zero, independent of the values in the error counters.
 * 1 - TWRN_INT and RWRN_INT bits are set when the respective error counter transition from <96 to ℜ≥ 96.
 */

#define BP_FLEXCAN_MCR_WRN_EN      (21)      //!< Bit position for FLEXCAN_MCR_WRN_EN.
#define BM_FLEXCAN_MCR_WRN_EN      (0x00200000)  //!< Bit mask for FLEXCAN_MCR_WRN_EN.

//! @brief Get value of FLEXCAN_MCR_WRN_EN from a register value.
#define BG_FLEXCAN_MCR_WRN_EN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_WRN_EN) >> BP_FLEXCAN_MCR_WRN_EN)

//! @brief Format value for bitfield FLEXCAN_MCR_WRN_EN.
#define BF_FLEXCAN_MCR_WRN_EN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_MCR_WRN_EN) & BM_FLEXCAN_MCR_WRN_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WRN_EN field to a new value.
#define BW_FLEXCAN_MCR_WRN_EN(x, v)   (HW_FLEXCAN_MCR_WR(x, (HW_FLEXCAN_MCR_RD(x) & ~BM_FLEXCAN_MCR_WRN_EN) | BF_FLEXCAN_MCR_WRN_EN(v)))
#endif


/* --- Register HW_FLEXCAN_MCR, field SLF_WAK[22] (RW)
 *
 * This bit enables the Self Wake Up feature when FLEXCAN is in Stop Mode
 * {flexcan2_ipi_slv_flex_reg_mcr_swu} . If this bit had been asserted by the time FLEXCAN entered
 * Stop Mode, then FLEXCAN will look for a recessive to dominant transition on the bus during these
 * modes {flexcan2_ipi_slv_flex_reg_mcr_swu} . If a transition from recessive to dominant is
 * detected during Stop Mode, then FLEXCAN generates, if enabled to do so, a Wake Up interrupt to
 * the ARM so that it can resume the clocks globally. {flexcan2_ipi_slv_flex_reg_mcr_swu} This bit
 * can not be written while the block is in Stop Mode {flexcan2_ipi_slv_flex_reg_mcr_swu} .
 *
 * Values:
 * 0 - FLEXCAN Self Wake Up feature is disabled {flexcan2_ipi_slv_flex_reg_mcr_swu}
 * 1 - FLEXCAN Self Wake Up feature is enabled {flexcan2_ipi_slv_flex_reg_mcr_swu}
 */

#define BP_FLEXCAN_MCR_SLF_WAK      (22)      //!< Bit position for FLEXCAN_MCR_SLF_WAK.
#define BM_FLEXCAN_MCR_SLF_WAK      (0x00400000)  //!< Bit mask for FLEXCAN_MCR_SLF_WAK.

//! @brief Get value of FLEXCAN_MCR_SLF_WAK from a register value.
#define BG_FLEXCAN_MCR_SLF_WAK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_SLF_WAK) >> BP_FLEXCAN_MCR_SLF_WAK)

//! @brief Format value for bitfield FLEXCAN_MCR_SLF_WAK.
#define BF_FLEXCAN_MCR_SLF_WAK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_MCR_SLF_WAK) & BM_FLEXCAN_MCR_SLF_WAK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SLF_WAK field to a new value.
#define BW_FLEXCAN_MCR_SLF_WAK(x, v)   (HW_FLEXCAN_MCR_WR(x, (HW_FLEXCAN_MCR_RD(x) & ~BM_FLEXCAN_MCR_SLF_WAK) | BF_FLEXCAN_MCR_SLF_WAK(v)))
#endif


/* --- Register HW_FLEXCAN_MCR, field SUPV[23] (RW)
 *
 * This bit configures some of the FLEXCAN registers to be either in Supervisor or Unrestricted
 * memory space {flexcan2_ipi_slv_flex_reg_access}{flexcan2_ipi_slv_flex_ram_access}{flexcan2_ipi_sl
 * v_flex_ram_rximask_access} . The registers affected by this bit are marked as S/U in the Access
 * Type column of the Memory Map. Reset value of this bit is 1, so the affected registers start with
 * Supervisor access restrictions . {flexcan2_ipi_slv_flex_reg_access}
 *
 * Values:
 * 0 - Affected registers are in Unrestricted memory space  {flexcan2_ipi_slv_flex_reg_access}{flexcan2_ipi
 *     _slv_flex_ram_access}{flexcan2_ipi_slv_flex_ram_rximask_access}
 * 1 - Affected registers are in Supervisor memory space {flexcan2_ipi_slv_flex_reg_access}{flexcan2_ipi_sl
 *     v_flex_ram_access}{flexcan2_ipi_slv_flex_ram_rximask_access} . Any access without supervisor
 *     permission behaves as though the access was done to an unimplemented register location  {flex
 *     can2_ipi_slv_flex_reg_access}{flexcan2_ipi_slv_flex_ram_access}{flexcan2_ipi_slv_flex_ram_rxi
 *     mask_access}
 */

#define BP_FLEXCAN_MCR_SUPV      (23)      //!< Bit position for FLEXCAN_MCR_SUPV.
#define BM_FLEXCAN_MCR_SUPV      (0x00800000)  //!< Bit mask for FLEXCAN_MCR_SUPV.

//! @brief Get value of FLEXCAN_MCR_SUPV from a register value.
#define BG_FLEXCAN_MCR_SUPV(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_SUPV) >> BP_FLEXCAN_MCR_SUPV)

//! @brief Format value for bitfield FLEXCAN_MCR_SUPV.
#define BF_FLEXCAN_MCR_SUPV(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_MCR_SUPV) & BM_FLEXCAN_MCR_SUPV)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SUPV field to a new value.
#define BW_FLEXCAN_MCR_SUPV(x, v)   (HW_FLEXCAN_MCR_WR(x, (HW_FLEXCAN_MCR_RD(x) & ~BM_FLEXCAN_MCR_SUPV) | BF_FLEXCAN_MCR_SUPV(v)))
#endif


/* --- Register HW_FLEXCAN_MCR, field FRZ_ACK[24] (RO)
 *
 * This read-only bit indicates that FLEXCAN is in Freeze Mode and its prescaler is stopped
 * {flexcan2_ipi_slv_flex_freezemode} . The Freeze Mode request cannot be granted until current
 * transmission or reception processes have finished {flexcan2_ipi_slv_flex_freezemode} . Therefore
 * the software can poll the FRZ_ACK bit to know when FLEXCAN has actually entered Freeze Mode
 * {flexcan2_ipi_slv_flex_freezemode} . If Freeze Mode request is negated, then this bit is negated
 * once the FLEXCAN prescaler is running again. {flexcan2_ipi_slv_flex_freezemode} If Freeze Mode is
 * requested while FLEXCAN is in any of the low power modes, then the FRZ_ACK bit will only be set
 * when the low power mode is exited {flexcan2_ipi_slv_flex_freezemode} {statement} .
 *
 * Values:
 * 0 - FLEXCAN not in Freeze Mode, prescaler running {flexcan2_ipi_slv_flex_freezemode}
 * 1 - FLEXCAN in Freeze Mode, prescaler stopped {flexcan2_ipi_slv_flex_freezemode}
 */

#define BP_FLEXCAN_MCR_FRZ_ACK      (24)      //!< Bit position for FLEXCAN_MCR_FRZ_ACK.
#define BM_FLEXCAN_MCR_FRZ_ACK      (0x01000000)  //!< Bit mask for FLEXCAN_MCR_FRZ_ACK.

//! @brief Get value of FLEXCAN_MCR_FRZ_ACK from a register value.
#define BG_FLEXCAN_MCR_FRZ_ACK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_FRZ_ACK) >> BP_FLEXCAN_MCR_FRZ_ACK)


/* --- Register HW_FLEXCAN_MCR, field SOFT_RST[25] (RW)
 *
 * When this bit is asserted, FLEXCAN resets its internal state machines and some of the memory
 * mapped registers {flexcan2_ipi_slv_flex_softreset} . The following registers are reset: MCR
 * (except the MDIS bit), TIMER, TCR, ECR, ESR, IMASK1, IMASK2, IFLAG1, IFLAG2.
 * {flexcan2_ipi_slv_flex_softreset} Configuration registers that control the interface to the CAN
 * bus are not affected by soft reset {flexcan2_ipi_slv_flex_softreset} . The following registers
 * are unaffected {flexcan2_ipi_slv_flex_softreset} : CTRL {flexcan2_ipi_slv_flex_softreset}
 * RXIMR0‚RXIMR63 {flexcan2_ipi_slv_flex_softreset} RXGMASK, RX14MASK, RX15MASK
 * {flexcan2_ipi_slv_flex_softreset} all Message Buffers {flexcan2_ipi_slv_flex_softreset} The
 * SOFT_RST bit can be asserted directly by the ARM when it writes to the MCR Register. Because soft
 * reset is synchronous and has to follow a request/acknowledge procedure across clock domains, it
 * may take some time to fully propagate its effect {statement} . The SOFT_RST bit remains asserted
 * while reset is pending, and is automatically negated when reset completes
 * {flexcan2_ipi_slv_flex_softreset} . Therefore, software can poll this bit to know when the soft
 * reset has completed. {flexcan2_ipi_slv_flex_softreset} Soft reset cannot be applied while clocks
 * are shut down in any of the low power modes {statement} . The block should be first removed from
 * low power mode, and then soft reset can be applied {statement} .
 *
 * Values:
 * 0 - No reset request {flexcan2_ipi_slv_flex_softreset}
 * 1 - Resets the registers marked as affected by soft reset shown in the memory map
 *     {flexcan2_ipi_slv_flex_softreset}
 */

#define BP_FLEXCAN_MCR_SOFT_RST      (25)      //!< Bit position for FLEXCAN_MCR_SOFT_RST.
#define BM_FLEXCAN_MCR_SOFT_RST      (0x02000000)  //!< Bit mask for FLEXCAN_MCR_SOFT_RST.

//! @brief Get value of FLEXCAN_MCR_SOFT_RST from a register value.
#define BG_FLEXCAN_MCR_SOFT_RST(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_SOFT_RST) >> BP_FLEXCAN_MCR_SOFT_RST)

//! @brief Format value for bitfield FLEXCAN_MCR_SOFT_RST.
#define BF_FLEXCAN_MCR_SOFT_RST(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_MCR_SOFT_RST) & BM_FLEXCAN_MCR_SOFT_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SOFT_RST field to a new value.
#define BW_FLEXCAN_MCR_SOFT_RST(x, v)   (HW_FLEXCAN_MCR_WR(x, (HW_FLEXCAN_MCR_RD(x) & ~BM_FLEXCAN_MCR_SOFT_RST) | BF_FLEXCAN_MCR_SOFT_RST(v)))
#endif


/* --- Register HW_FLEXCAN_MCR, field WAK_MSK[26] (RW)
 *
 * This bit enables the Wake Up Interrupt generation. {flexcan2_ipi_slv_flex_reg_esr_int}
 *
 * Values:
 * 0 - Wake Up Interrupt is disabled {flexcan2_ipi_slv_flex_reg_esr_int}
 * 1 - Wake Up Interrupt is enabled {flexcan2_ipi_slv_flex_reg_esr_int}
 */

#define BP_FLEXCAN_MCR_WAK_MSK      (26)      //!< Bit position for FLEXCAN_MCR_WAK_MSK.
#define BM_FLEXCAN_MCR_WAK_MSK      (0x04000000)  //!< Bit mask for FLEXCAN_MCR_WAK_MSK.

//! @brief Get value of FLEXCAN_MCR_WAK_MSK from a register value.
#define BG_FLEXCAN_MCR_WAK_MSK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_WAK_MSK) >> BP_FLEXCAN_MCR_WAK_MSK)

//! @brief Format value for bitfield FLEXCAN_MCR_WAK_MSK.
#define BF_FLEXCAN_MCR_WAK_MSK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_MCR_WAK_MSK) & BM_FLEXCAN_MCR_WAK_MSK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WAK_MSK field to a new value.
#define BW_FLEXCAN_MCR_WAK_MSK(x, v)   (HW_FLEXCAN_MCR_WR(x, (HW_FLEXCAN_MCR_RD(x) & ~BM_FLEXCAN_MCR_WAK_MSK) | BF_FLEXCAN_MCR_WAK_MSK(v)))
#endif


/* --- Register HW_FLEXCAN_MCR, field NOT_RDY[27] (RO)
 *
 * This read-only bit indicates that FLEXCAN is either in Disable Mode, Stop Mode or Freeze Mode {fl
 * excan2_ipi_slv_flex_freezemode}{flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode
 * }{flexcan2_ipi_slv_flex_dozemode} . It is negated once FLEXCAN has exited these modes. {flexcan2_
 * ipi_slv_flex_freezemode}{flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexc
 * an2_ipi_slv_flex_dozemode}{flexcan2_ipi_slv_flex_reg_mcr_swu}
 *
 * Values:
 * 0 - FLEXCAN block is either in Normal Mode, Listen-Only Mode or Loop-Back Mode {flexcan2_ipi_slv_flex_fr
 *     eezemode}{flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_slv
 *     _flex_dozemode}
 * 1 - FLEXCAN block is either in Disable Mode, Stop Mode or Freeze Mode {flexcan2_ipi_slv_flex_freezemode}
 *     {flexcan2_ipi_slv_flex_stopmode}{flexcan2_ipi_slv_flex_disablemode}{flexcan2_ipi_slv_flex_doz
 *     emode}
 */

#define BP_FLEXCAN_MCR_NOT_RDY      (27)      //!< Bit position for FLEXCAN_MCR_NOT_RDY.
#define BM_FLEXCAN_MCR_NOT_RDY      (0x08000000)  //!< Bit mask for FLEXCAN_MCR_NOT_RDY.

//! @brief Get value of FLEXCAN_MCR_NOT_RDY from a register value.
#define BG_FLEXCAN_MCR_NOT_RDY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_NOT_RDY) >> BP_FLEXCAN_MCR_NOT_RDY)


/* --- Register HW_FLEXCAN_MCR, field HALT[28] (RW)
 *
 * Assertion of this bit puts the FLEXCAN block into Freeze Mode {flexcan2_ipi_slv_flex_freezemode}
 * . The ARM should clear it after initializing the Message Buffers and Control Register {statement}
 * . No reception or transmission is performed by FLEXCAN before this bit is cleared
 * {flexcan2_ipi_slv_flex_freezemode} . While in Freeze Mode, the ARM has write access to the Error
 * Counter Register, that is otherwise read-only {flexcan2_ipi_slv_flex_freezemode} . Freeze Mode
 * can not be entered while FLEXCAN is in any of the low power modes
 * {flexcan2_ipi_slv_flex_freezemode} {statement} .
 *
 * Values:
 * 0 - No Freeze Mode request. {flexcan2_ipi_slv_flex_freezemode}
 * 1 - Enters Freeze Mode if the FRZ bit is asserted. {flexcan2_ipi_slv_flex_freezemode}
 */

#define BP_FLEXCAN_MCR_HALT      (28)      //!< Bit position for FLEXCAN_MCR_HALT.
#define BM_FLEXCAN_MCR_HALT      (0x10000000)  //!< Bit mask for FLEXCAN_MCR_HALT.

//! @brief Get value of FLEXCAN_MCR_HALT from a register value.
#define BG_FLEXCAN_MCR_HALT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_HALT) >> BP_FLEXCAN_MCR_HALT)

//! @brief Format value for bitfield FLEXCAN_MCR_HALT.
#define BF_FLEXCAN_MCR_HALT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_MCR_HALT) & BM_FLEXCAN_MCR_HALT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALT field to a new value.
#define BW_FLEXCAN_MCR_HALT(x, v)   (HW_FLEXCAN_MCR_WR(x, (HW_FLEXCAN_MCR_RD(x) & ~BM_FLEXCAN_MCR_HALT) | BF_FLEXCAN_MCR_HALT(v)))
#endif


/* --- Register HW_FLEXCAN_MCR, field FEN[29] (RW)
 *
 * This bit controls whether the FIFO feature is enabled or not. When FEN is set, message buffers 0
 * to 7 cannot be used for normal reception and transmission because the corresponding memory region
 * (0x80-0xFF) is used by the FIFO engine.
 *
 * Values:
 * 0 - FIFO not enabled
 * 1 - FIFO enabled
 */

#define BP_FLEXCAN_MCR_FEN      (29)      //!< Bit position for FLEXCAN_MCR_FEN.
#define BM_FLEXCAN_MCR_FEN      (0x20000000)  //!< Bit mask for FLEXCAN_MCR_FEN.

//! @brief Get value of FLEXCAN_MCR_FEN from a register value.
#define BG_FLEXCAN_MCR_FEN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_FEN) >> BP_FLEXCAN_MCR_FEN)

//! @brief Format value for bitfield FLEXCAN_MCR_FEN.
#define BF_FLEXCAN_MCR_FEN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_MCR_FEN) & BM_FLEXCAN_MCR_FEN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FEN field to a new value.
#define BW_FLEXCAN_MCR_FEN(x, v)   (HW_FLEXCAN_MCR_WR(x, (HW_FLEXCAN_MCR_RD(x) & ~BM_FLEXCAN_MCR_FEN) | BF_FLEXCAN_MCR_FEN(v)))
#endif


/* --- Register HW_FLEXCAN_MCR, field FRZ[30] (RW)
 *
 * The FRZ bit specifies the FLEXCAN behavior when the HALT bit in the MCR Register is set or when
 * Debug Mode is requested at ARM platform level . When FRZ is asserted, FLEXCAN is enabled to enter
 * Freeze Mode {flexcan2_ipi_slv_flex_freezemode} . Negation of this bit field causes FLEXCAN to
 * exit from Freeze Mode {flexcan2_ipi_slv_flex_freezemode} .
 *
 * Values:
 * 0 - Not enabled to enter Freeze Mode {flexcan2_ipi_slv_flex_freezemode}
 * 1 - Enabled to enter Freeze Mode {flexcan2_ipi_slv_flex_freezemode}
 */

#define BP_FLEXCAN_MCR_FRZ      (30)      //!< Bit position for FLEXCAN_MCR_FRZ.
#define BM_FLEXCAN_MCR_FRZ      (0x40000000)  //!< Bit mask for FLEXCAN_MCR_FRZ.

//! @brief Get value of FLEXCAN_MCR_FRZ from a register value.
#define BG_FLEXCAN_MCR_FRZ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_FRZ) >> BP_FLEXCAN_MCR_FRZ)

//! @brief Format value for bitfield FLEXCAN_MCR_FRZ.
#define BF_FLEXCAN_MCR_FRZ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_MCR_FRZ) & BM_FLEXCAN_MCR_FRZ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FRZ field to a new value.
#define BW_FLEXCAN_MCR_FRZ(x, v)   (HW_FLEXCAN_MCR_WR(x, (HW_FLEXCAN_MCR_RD(x) & ~BM_FLEXCAN_MCR_FRZ) | BF_FLEXCAN_MCR_FRZ(v)))
#endif


/* --- Register HW_FLEXCAN_MCR, field MDIS[31] (RW)
 *
 * This bit controls whether FLEXCAN is enabled or not {flexcan2_ipi_slv_flex_disablemode} . When
 * disabled, FLEXCAN shuts down the clocks to the CAN Protocol Interface and Message Buffer
 * Management sub-blocks {flexcan2_ipi_slv_flex_disablemode} . This is the only bit in MCR not
 * affected by soft reset {flexcan2_ipi_slv_flex_softreset} . {statement}
 *
 * Values:
 * 0 - Enable the FLEXCAN block {flexcan2_ipi_slv_flex_disablemode}
 * 1 - Disable the FLEXCAN block {flexcan2_ipi_slv_flex_disablemode}
 */

#define BP_FLEXCAN_MCR_MDIS      (31)      //!< Bit position for FLEXCAN_MCR_MDIS.
#define BM_FLEXCAN_MCR_MDIS      (0x80000000)  //!< Bit mask for FLEXCAN_MCR_MDIS.

//! @brief Get value of FLEXCAN_MCR_MDIS from a register value.
#define BG_FLEXCAN_MCR_MDIS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_MCR_MDIS) >> BP_FLEXCAN_MCR_MDIS)

//! @brief Format value for bitfield FLEXCAN_MCR_MDIS.
#define BF_FLEXCAN_MCR_MDIS(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_MCR_MDIS) & BM_FLEXCAN_MCR_MDIS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MDIS field to a new value.
#define BW_FLEXCAN_MCR_MDIS(x, v)   (HW_FLEXCAN_MCR_WR(x, (HW_FLEXCAN_MCR_RD(x) & ~BM_FLEXCAN_MCR_MDIS) | BF_FLEXCAN_MCR_MDIS(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_FLEXCAN_CTRL - Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_CTRL - Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register is defined for specific FLEXCAN control features related to the CAN bus, such as
 * bit-rate, programmable sampling point within an Rx bit, Loop Back Mode, Listen Only Mode, Bus Off
 * recovery behavior and interrupt enabling (Bus-Off, Error, Warning) {statement} . It also
 * determines the Division Factor for the clock prescaler. {flexcan2_ipi_slv_can_timing_parameters}
 * Most of the fields in this register should only be changed while the block is in Disable Mode or
 * in Freeze Mode {statement} . Exceptions are the BOFF_MSK, ERR_MSK, TWRN_MSK, RWRN_MSK and
 * BOFF_REC bits, that can be accessed at any time {statement} .
 */
typedef union _hw_flexcan_ctrl
{
    reg32_t U;
    struct _hw_flexcan_ctrl_bitfields
    {
        unsigned PROP_SEG : 3; //!< [2:0] This 3-bit field defines the length of the Propagation Segment in the bit time {flexcan2_ipi_slv_can_timing_parameters} . The valid programmable values are 0‚7. {flexcan2_ipi_slv_can_timing_parameters} Propagation Segment Time = (PROPSEG + 1) * Time-Quanta. {flexcan2_ipi_slv_can_timing_parameters} Time-Quantum = one Sclock period. {flexcan2_ipi_slv_can_timing_parameters}
        unsigned LOM : 1; //!< [3] This bit configures FLEXCAN to operate in Listen Only Mode {flexcan2_ipi_slv_flex_lomode} . In this mode, transmission is disabled, all error counters are frozen and the block operates in a CAN Error Passive mode {flexcan2_ipi_slv_flex_lomode} [Ref. 1]. Only messages acknowledged by another CAN station will be received {flexcan2_ipi_slv_flex_lomode} . If FLEXCAN detects a message that has not been acknowledged, it will flag a BIT0 error (without changing the REC), as if it was trying to acknowledge the message {flexcan2_ipi_slv_flex_lomode} .
        unsigned LBUF : 1; //!< [4] This bit defines the ordering mechanism for Message Buffer transmission. When asserted, the LPRIO_EN bit does not affect the priority arbitration. {flexcan2_ipi_slv_flex_reg_ctrl_lbuf}
        unsigned TSYN : 1; //!< [5] This bit enables a mechanism that resets the free-running timer each time a message is received in Message Buffer 0 {flexcan2_ipi_slv_flex_reg_ctrl_tsyn} . This feature provides a means to synchronize multiple FLEXCAN stations with a special SYNC message (for example, global network time). {statement} If the FEN bit in MCR is set (FIFO enabled), MB8 is used for timer synchronization instead of MB0.
        unsigned BOFF_REC : 1; //!< [6] This bit defines how FLEXCAN recovers from Bus Off state. {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} If this bit is negated, automatic recovering from Bus Off state occurs according to the CAN Specification 2.0B {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} . If the bit is asserted, automatic recovering from Bus Off is disabled and the block remains in Bus Off state until the bit is negated by the user {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} . If the negation occurs before 128 sequences of 11 recessive bits are detected on the CAN bus, then Bus Off recovery happens as if the BOFF_REC bit had never been asserted {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} . If the negation occurs after 128 sequences of 11 recessive bits occurred, then FLEXCAN will re-synchronize to the bus by waiting for 11 recessive bits before joining the bus {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} . After negation, the BOFF_REC bit can be re-asserted again during Bus Off, but it will only be effective the next time the block enters Bus Off {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} . If BOFF_REC was negated when the block entered Bus Off, asserting it during Bus Off will not be effective for the current Bus Off recovery {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} .
        unsigned SMP : 1; //!< [7] This bit defines the sampling mode of CAN bits at the Rx input {flexcan2_ipi_slv_flex_reg_ctrl_smp} .
        unsigned RESERVED0 : 2; //!< [9:8] Reserved
        unsigned RWRN_MSK : 1; //!< [10] This bit provides a mask for the Rx Warning Interrupt associated with the RWRN_INT flag in the Error and Status Register. This bit has no effect if the WRN_EN bit in MCR is negated and it is read as zero when WRN_EN is negated.
        unsigned TWRN_MSK : 1; //!< [11] This bit provides a mask for the Tx Warning Interrupt associated with the TWRN_INT flag in the Error and Status Register. This bit has no effect if the WRN_EN bit in MCR is negated and it is read as zero when WRN_EN is negated.
        unsigned LPB : 1; //!< [12] This bit configures FLEXCAN to operate in Loop-Back Mode {flexcan2_ipi_slv_flex_reg_ctrl_lpb} . In this mode, FLEXCAN performs an internal loop back that can be used for self test operation {statement} . The bit stream output of the transmitter is fed back internally to the receiver input {statement} . The Rx CAN input pin is ignored and the Tx CAN output goes to the recessive state (logic 1) {flexcan2_ipi_slv_flex_reg_ctrl_lpb} . FLEXCAN behaves as it normally does when transmitting, and treats its own transmitted message as a message received from a remote node {flexcan2_ipi_slv_flex_reg_ctrl_lpb} . In this mode, FLEXCAN ignores the bit sent during the ACK slot in the CAN frame acknowledge field, generating an internal acknowledge bit to ensure proper reception of its own message {flexcan2_ipi_slv_flex_reg_ctrl_lpb} . Both transmit and receive interrupts are generated. {flexcan2_ipi_slv_flex_reg_ctrl_lpb}
        unsigned RESERVED1 : 1; //!< [13] Reserved CLK_SRC - This bit selects the clock source to the CAN Protocol Interface (CPI) to be either the peripheral clock (driven by the PLL) or the crystal oscillator clock {flexcan2_ipi_slv_flex_reg_ctrl_clksrc} . The selected clock is the one fed to the prescaler to generate the Serial Clock (Sclock) {flexcan2_ipi_slv_flex_reg_ctrl_clksrc} . In order to guarantee reliable operation, this bit should only be changed while the block is in Disable Mode {statement} . See . {statement}
        unsigned ERR_MSK : 1; //!< [14] This bit provides a mask for the Error Interrupt. {flexcan2_ipi_slv_flex_reg_esr_int}
        unsigned BOFF_MSK : 1; //!< [15] This bit provides a mask for the Bus Off Interrupt. {flexcan2_ipi_slv_flex_reg_esr_int}
        unsigned PSEG2 : 3; //!< [18:16] This 3-bit field defines the length of Phase Buffer Segment 2 in the bit time {flexcan2_ipi_slv_can_timing_parameters} . The valid programmable values are 1‚7. {flexcan2_ipi_slv_can_timing_parameters} Phase Buffer Segment 2 = (PSEG2 + 1) x Time-Quanta. {flexcan2_ipi_slv_can_timing_parameters}
        unsigned PSEG1 : 3; //!< [21:19] This 3-bit field defines the length of Phase Buffer Segment 1 in the bit time {flexcan2_ipi_slv_can_timing_parameters} . The valid programmable values are 0‚7. {flexcan2_ipi_slv_can_timing_parameters} Phase Buffer Segment 1 = (PSEG1 + 1) x Time-Quanta. {flexcan2_ipi_slv_can_timing_parameters}
        unsigned RJW : 2; //!< [23:22] This 2-bit field defines the maximum number of time quanta One time quantum is equal to the Sclock period. {statement} that a bit time can be changed by one re-synchronization {flexcan2_ipi_slv_can_timing_resynchronization} . The valid programmable values are 0‚3. {flexcan2_ipi_slv_can_timing_resynchronization} Resync Jump Width = RJW + 1. {flexcan2_ipi_slv_can_timing_resynchronization}
        unsigned PRESDIV : 8; //!< [31:24] This 8-bit field defines the ratio between the CPI clock frequency and the Serial Clock (Sclock) frequency {flexcan2_ipi_slv_can_timing_parameters} . The Sclock period defines the time quantum of the CAN protocol {flexcan2_ipi_slv_can_timing_parameters} . For the reset value, the Sclock frequency is equal to the CPI clock frequency {flexcan2_ipi_slv_can_timing_parameters} . The Maximum value of this register is 0xFF, that gives a minimum Sclock frequency equal to the CPI clock frequency divided by 256. {flexcan2_ipi_slv_can_timing_parameters} For more information refer to . {statement} Sclock frequency = CPI clock frequency / (PRESDIV + 1) {flexcan2_ipi_slv_can_timing_parameters}
    } B;
} hw_flexcan_ctrl_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_CTRL register
 */
#define HW_FLEXCAN_CTRL_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_CTRL(x)           (*(volatile hw_flexcan_ctrl_t *) HW_FLEXCAN_CTRL_ADDR(x))
#define HW_FLEXCAN_CTRL_RD(x)        (HW_FLEXCAN_CTRL(x).U)
#define HW_FLEXCAN_CTRL_WR(x, v)     (HW_FLEXCAN_CTRL(x).U = (v))
#define HW_FLEXCAN_CTRL_SET(x, v)    (HW_FLEXCAN_CTRL_WR(x, HW_FLEXCAN_CTRL_RD(x) |  (v)))
#define HW_FLEXCAN_CTRL_CLR(x, v)    (HW_FLEXCAN_CTRL_WR(x, HW_FLEXCAN_CTRL_RD(x) & ~(v)))
#define HW_FLEXCAN_CTRL_TOG(x, v)    (HW_FLEXCAN_CTRL_WR(x, HW_FLEXCAN_CTRL_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_CTRL bitfields
 */

/* --- Register HW_FLEXCAN_CTRL, field PROP_SEG[2:0] (RW)
 *
 * This 3-bit field defines the length of the Propagation Segment in the bit time
 * {flexcan2_ipi_slv_can_timing_parameters} . The valid programmable values are 0‚7.
 * {flexcan2_ipi_slv_can_timing_parameters} Propagation Segment Time = (PROPSEG + 1) * Time-Quanta.
 * {flexcan2_ipi_slv_can_timing_parameters} Time-Quantum = one Sclock period.
 * {flexcan2_ipi_slv_can_timing_parameters}
 */

#define BP_FLEXCAN_CTRL_PROP_SEG      (0)      //!< Bit position for FLEXCAN_CTRL_PROP_SEG.
#define BM_FLEXCAN_CTRL_PROP_SEG      (0x00000007)  //!< Bit mask for FLEXCAN_CTRL_PROP_SEG.

//! @brief Get value of FLEXCAN_CTRL_PROP_SEG from a register value.
#define BG_FLEXCAN_CTRL_PROP_SEG(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_CTRL_PROP_SEG) >> BP_FLEXCAN_CTRL_PROP_SEG)

//! @brief Format value for bitfield FLEXCAN_CTRL_PROP_SEG.
#define BF_FLEXCAN_CTRL_PROP_SEG(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_CTRL_PROP_SEG) & BM_FLEXCAN_CTRL_PROP_SEG)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PROP_SEG field to a new value.
#define BW_FLEXCAN_CTRL_PROP_SEG(x, v)   (HW_FLEXCAN_CTRL_WR(x, (HW_FLEXCAN_CTRL_RD(x) & ~BM_FLEXCAN_CTRL_PROP_SEG) | BF_FLEXCAN_CTRL_PROP_SEG(v)))
#endif

/* --- Register HW_FLEXCAN_CTRL, field LOM[3] (RW)
 *
 * This bit configures FLEXCAN to operate in Listen Only Mode {flexcan2_ipi_slv_flex_lomode} . In
 * this mode, transmission is disabled, all error counters are frozen and the block operates in a
 * CAN Error Passive mode {flexcan2_ipi_slv_flex_lomode} [Ref. 1]. Only messages acknowledged by
 * another CAN station will be received {flexcan2_ipi_slv_flex_lomode} . If FLEXCAN detects a
 * message that has not been acknowledged, it will flag a BIT0 error (without changing the REC), as
 * if it was trying to acknowledge the message {flexcan2_ipi_slv_flex_lomode} .
 *
 * Values:
 * 0 - Listen Only Mode is deactivated {flexcan2_ipi_slv_flex_lomode}
 * 1 - FLEXCAN block operates in Listen Only Mode {flexcan2_ipi_slv_flex_lomode}
 */

#define BP_FLEXCAN_CTRL_LOM      (3)      //!< Bit position for FLEXCAN_CTRL_LOM.
#define BM_FLEXCAN_CTRL_LOM      (0x00000008)  //!< Bit mask for FLEXCAN_CTRL_LOM.

//! @brief Get value of FLEXCAN_CTRL_LOM from a register value.
#define BG_FLEXCAN_CTRL_LOM(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_CTRL_LOM) >> BP_FLEXCAN_CTRL_LOM)

//! @brief Format value for bitfield FLEXCAN_CTRL_LOM.
#define BF_FLEXCAN_CTRL_LOM(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_CTRL_LOM) & BM_FLEXCAN_CTRL_LOM)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LOM field to a new value.
#define BW_FLEXCAN_CTRL_LOM(x, v)   (HW_FLEXCAN_CTRL_WR(x, (HW_FLEXCAN_CTRL_RD(x) & ~BM_FLEXCAN_CTRL_LOM) | BF_FLEXCAN_CTRL_LOM(v)))
#endif


/* --- Register HW_FLEXCAN_CTRL, field LBUF[4] (RW)
 *
 * This bit defines the ordering mechanism for Message Buffer transmission. When asserted, the
 * LPRIO_EN bit does not affect the priority arbitration. {flexcan2_ipi_slv_flex_reg_ctrl_lbuf}
 *
 * Values:
 * 0 - Buffer with highest priority is transmitted first {flexcan2_ipi_slv_flex_reg_ctrl_lbuf}
 * 1 - Lowest number buffer is transmitted first {flexcan2_ipi_slv_flex_reg_ctrl_lbuf}
 */

#define BP_FLEXCAN_CTRL_LBUF      (4)      //!< Bit position for FLEXCAN_CTRL_LBUF.
#define BM_FLEXCAN_CTRL_LBUF      (0x00000010)  //!< Bit mask for FLEXCAN_CTRL_LBUF.

//! @brief Get value of FLEXCAN_CTRL_LBUF from a register value.
#define BG_FLEXCAN_CTRL_LBUF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_CTRL_LBUF) >> BP_FLEXCAN_CTRL_LBUF)

//! @brief Format value for bitfield FLEXCAN_CTRL_LBUF.
#define BF_FLEXCAN_CTRL_LBUF(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_CTRL_LBUF) & BM_FLEXCAN_CTRL_LBUF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LBUF field to a new value.
#define BW_FLEXCAN_CTRL_LBUF(x, v)   (HW_FLEXCAN_CTRL_WR(x, (HW_FLEXCAN_CTRL_RD(x) & ~BM_FLEXCAN_CTRL_LBUF) | BF_FLEXCAN_CTRL_LBUF(v)))
#endif


/* --- Register HW_FLEXCAN_CTRL, field TSYN[5] (RW)
 *
 * This bit enables a mechanism that resets the free-running timer each time a message is received
 * in Message Buffer 0 {flexcan2_ipi_slv_flex_reg_ctrl_tsyn} . This feature provides a means to
 * synchronize multiple FLEXCAN stations with a special SYNC message (for example, global network
 * time). {statement} If the FEN bit in MCR is set (FIFO enabled), MB8 is used for timer
 * synchronization instead of MB0.
 *
 * Values:
 * 0 - Timer Sync feature disabled {flexcan2_ipi_slv_flex_reg_ctrl_tsyn}
 * 1 - Timer Sync feature enabled {flexcan2_ipi_slv_flex_reg_ctrl_tsyn}
 */

#define BP_FLEXCAN_CTRL_TSYN      (5)      //!< Bit position for FLEXCAN_CTRL_TSYN.
#define BM_FLEXCAN_CTRL_TSYN      (0x00000020)  //!< Bit mask for FLEXCAN_CTRL_TSYN.

//! @brief Get value of FLEXCAN_CTRL_TSYN from a register value.
#define BG_FLEXCAN_CTRL_TSYN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_CTRL_TSYN) >> BP_FLEXCAN_CTRL_TSYN)

//! @brief Format value for bitfield FLEXCAN_CTRL_TSYN.
#define BF_FLEXCAN_CTRL_TSYN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_CTRL_TSYN) & BM_FLEXCAN_CTRL_TSYN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TSYN field to a new value.
#define BW_FLEXCAN_CTRL_TSYN(x, v)   (HW_FLEXCAN_CTRL_WR(x, (HW_FLEXCAN_CTRL_RD(x) & ~BM_FLEXCAN_CTRL_TSYN) | BF_FLEXCAN_CTRL_TSYN(v)))
#endif


/* --- Register HW_FLEXCAN_CTRL, field BOFF_REC[6] (RW)
 *
 * This bit defines how FLEXCAN recovers from Bus Off state.
 * {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} If this bit is negated, automatic recovering from Bus
 * Off state occurs according to the CAN Specification 2.0B {flexcan2_ipi_slv_flex_reg_ctrl_boffrec}
 * . If the bit is asserted, automatic recovering from Bus Off is disabled and the block remains in
 * Bus Off state until the bit is negated by the user {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} . If
 * the negation occurs before 128 sequences of 11 recessive bits are detected on the CAN bus, then
 * Bus Off recovery happens as if the BOFF_REC bit had never been asserted
 * {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} . If the negation occurs after 128 sequences of 11
 * recessive bits occurred, then FLEXCAN will re-synchronize to the bus by waiting for 11 recessive
 * bits before joining the bus {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} . After negation, the
 * BOFF_REC bit can be re-asserted again during Bus Off, but it will only be effective the next time
 * the block enters Bus Off {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} . If BOFF_REC was negated when
 * the block entered Bus Off, asserting it during Bus Off will not be effective for the current Bus
 * Off recovery {flexcan2_ipi_slv_flex_reg_ctrl_boffrec} .
 *
 * Values:
 * 0 - Automatic recovering from Bus Off state enabled, according to CAN Spec 2.0 part B
 *     {flexcan2_ipi_slv_flex_reg_ctrl_boffrec}
 * 1 - Automatic recovering from Bus Off state disabled {flexcan2_ipi_slv_flex_reg_ctrl_boffrec}
 */

#define BP_FLEXCAN_CTRL_BOFF_REC      (6)      //!< Bit position for FLEXCAN_CTRL_BOFF_REC.
#define BM_FLEXCAN_CTRL_BOFF_REC      (0x00000040)  //!< Bit mask for FLEXCAN_CTRL_BOFF_REC.

//! @brief Get value of FLEXCAN_CTRL_BOFF_REC from a register value.
#define BG_FLEXCAN_CTRL_BOFF_REC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_CTRL_BOFF_REC) >> BP_FLEXCAN_CTRL_BOFF_REC)

//! @brief Format value for bitfield FLEXCAN_CTRL_BOFF_REC.
#define BF_FLEXCAN_CTRL_BOFF_REC(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_CTRL_BOFF_REC) & BM_FLEXCAN_CTRL_BOFF_REC)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BOFF_REC field to a new value.
#define BW_FLEXCAN_CTRL_BOFF_REC(x, v)   (HW_FLEXCAN_CTRL_WR(x, (HW_FLEXCAN_CTRL_RD(x) & ~BM_FLEXCAN_CTRL_BOFF_REC) | BF_FLEXCAN_CTRL_BOFF_REC(v)))
#endif


/* --- Register HW_FLEXCAN_CTRL, field SMP[7] (RW)
 *
 * This bit defines the sampling mode of CAN bits at the Rx input
 * {flexcan2_ipi_slv_flex_reg_ctrl_smp} .
 *
 * Values:
 * 0 - Just one sample is used to determine the bit value {flexcan2_ipi_slv_flex_reg_ctrl_smp}
 * 1 - Three samples are used to determine the value of the received bit: the regular one (sample point)
 *     and 2 preceding samples, a majority rule is used {flexcan2_ipi_slv_flex_reg_ctrl_smp}
 */

#define BP_FLEXCAN_CTRL_SMP      (7)      //!< Bit position for FLEXCAN_CTRL_SMP.
#define BM_FLEXCAN_CTRL_SMP      (0x00000080)  //!< Bit mask for FLEXCAN_CTRL_SMP.

//! @brief Get value of FLEXCAN_CTRL_SMP from a register value.
#define BG_FLEXCAN_CTRL_SMP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_CTRL_SMP) >> BP_FLEXCAN_CTRL_SMP)

//! @brief Format value for bitfield FLEXCAN_CTRL_SMP.
#define BF_FLEXCAN_CTRL_SMP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_CTRL_SMP) & BM_FLEXCAN_CTRL_SMP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SMP field to a new value.
#define BW_FLEXCAN_CTRL_SMP(x, v)   (HW_FLEXCAN_CTRL_WR(x, (HW_FLEXCAN_CTRL_RD(x) & ~BM_FLEXCAN_CTRL_SMP) | BF_FLEXCAN_CTRL_SMP(v)))
#endif


/* --- Register HW_FLEXCAN_CTRL, field RWRN_MSK[10] (RW)
 *
 * This bit provides a mask for the Rx Warning Interrupt associated with the RWRN_INT flag in the
 * Error and Status Register. This bit has no effect if the WRN_EN bit in MCR is negated and it is
 * read as zero when WRN_EN is negated.
 *
 * Values:
 * 0 - Rx Warning Interrupt disabled
 * 1 - Rx Warning Interrupt enabled
 */

#define BP_FLEXCAN_CTRL_RWRN_MSK      (10)      //!< Bit position for FLEXCAN_CTRL_RWRN_MSK.
#define BM_FLEXCAN_CTRL_RWRN_MSK      (0x00000400)  //!< Bit mask for FLEXCAN_CTRL_RWRN_MSK.

//! @brief Get value of FLEXCAN_CTRL_RWRN_MSK from a register value.
#define BG_FLEXCAN_CTRL_RWRN_MSK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_CTRL_RWRN_MSK) >> BP_FLEXCAN_CTRL_RWRN_MSK)

//! @brief Format value for bitfield FLEXCAN_CTRL_RWRN_MSK.
#define BF_FLEXCAN_CTRL_RWRN_MSK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_CTRL_RWRN_MSK) & BM_FLEXCAN_CTRL_RWRN_MSK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RWRN_MSK field to a new value.
#define BW_FLEXCAN_CTRL_RWRN_MSK(x, v)   (HW_FLEXCAN_CTRL_WR(x, (HW_FLEXCAN_CTRL_RD(x) & ~BM_FLEXCAN_CTRL_RWRN_MSK) | BF_FLEXCAN_CTRL_RWRN_MSK(v)))
#endif


/* --- Register HW_FLEXCAN_CTRL, field TWRN_MSK[11] (RW)
 *
 * This bit provides a mask for the Tx Warning Interrupt associated with the TWRN_INT flag in the
 * Error and Status Register. This bit has no effect if the WRN_EN bit in MCR is negated and it is
 * read as zero when WRN_EN is negated.
 *
 * Values:
 * 0 - Tx Warning Interrupt disabled
 * 1 - Tx Warning Interrupt enabled
 */

#define BP_FLEXCAN_CTRL_TWRN_MSK      (11)      //!< Bit position for FLEXCAN_CTRL_TWRN_MSK.
#define BM_FLEXCAN_CTRL_TWRN_MSK      (0x00000800)  //!< Bit mask for FLEXCAN_CTRL_TWRN_MSK.

//! @brief Get value of FLEXCAN_CTRL_TWRN_MSK from a register value.
#define BG_FLEXCAN_CTRL_TWRN_MSK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_CTRL_TWRN_MSK) >> BP_FLEXCAN_CTRL_TWRN_MSK)

//! @brief Format value for bitfield FLEXCAN_CTRL_TWRN_MSK.
#define BF_FLEXCAN_CTRL_TWRN_MSK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_CTRL_TWRN_MSK) & BM_FLEXCAN_CTRL_TWRN_MSK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TWRN_MSK field to a new value.
#define BW_FLEXCAN_CTRL_TWRN_MSK(x, v)   (HW_FLEXCAN_CTRL_WR(x, (HW_FLEXCAN_CTRL_RD(x) & ~BM_FLEXCAN_CTRL_TWRN_MSK) | BF_FLEXCAN_CTRL_TWRN_MSK(v)))
#endif


/* --- Register HW_FLEXCAN_CTRL, field LPB[12] (RW)
 *
 * This bit configures FLEXCAN to operate in Loop-Back Mode {flexcan2_ipi_slv_flex_reg_ctrl_lpb} .
 * In this mode, FLEXCAN performs an internal loop back that can be used for self test operation
 * {statement} . The bit stream output of the transmitter is fed back internally to the receiver
 * input {statement} . The Rx CAN input pin is ignored and the Tx CAN output goes to the recessive
 * state (logic 1) {flexcan2_ipi_slv_flex_reg_ctrl_lpb} . FLEXCAN behaves as it normally does when
 * transmitting, and treats its own transmitted message as a message received from a remote node
 * {flexcan2_ipi_slv_flex_reg_ctrl_lpb} . In this mode, FLEXCAN ignores the bit sent during the ACK
 * slot in the CAN frame acknowledge field, generating an internal acknowledge bit to ensure proper
 * reception of its own message {flexcan2_ipi_slv_flex_reg_ctrl_lpb} . Both transmit and receive
 * interrupts are generated. {flexcan2_ipi_slv_flex_reg_ctrl_lpb}
 *
 * Values:
 * 0 - Loop Back disabled {flexcan2_ipi_slv_flex_reg_ctrl_lpb}
 * 1 - Loop Back enabled {flexcan2_ipi_slv_flex_reg_ctrl_lpb}
 */

#define BP_FLEXCAN_CTRL_LPB      (12)      //!< Bit position for FLEXCAN_CTRL_LPB.
#define BM_FLEXCAN_CTRL_LPB      (0x00001000)  //!< Bit mask for FLEXCAN_CTRL_LPB.

//! @brief Get value of FLEXCAN_CTRL_LPB from a register value.
#define BG_FLEXCAN_CTRL_LPB(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_CTRL_LPB) >> BP_FLEXCAN_CTRL_LPB)

//! @brief Format value for bitfield FLEXCAN_CTRL_LPB.
#define BF_FLEXCAN_CTRL_LPB(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_CTRL_LPB) & BM_FLEXCAN_CTRL_LPB)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LPB field to a new value.
#define BW_FLEXCAN_CTRL_LPB(x, v)   (HW_FLEXCAN_CTRL_WR(x, (HW_FLEXCAN_CTRL_RD(x) & ~BM_FLEXCAN_CTRL_LPB) | BF_FLEXCAN_CTRL_LPB(v)))
#endif


/* --- Register HW_FLEXCAN_CTRL, field ERR_MSK[14] (RW)
 *
 * This bit provides a mask for the Error Interrupt. {flexcan2_ipi_slv_flex_reg_esr_int}
 *
 * Values:
 * 0 - Error interrupt disabled {flexcan2_ipi_slv_flex_reg_esr_int}
 * 1 - Error interrupt enabled {flexcan2_ipi_slv_flex_reg_esr_int}
 */

#define BP_FLEXCAN_CTRL_ERR_MSK      (14)      //!< Bit position for FLEXCAN_CTRL_ERR_MSK.
#define BM_FLEXCAN_CTRL_ERR_MSK      (0x00004000)  //!< Bit mask for FLEXCAN_CTRL_ERR_MSK.

//! @brief Get value of FLEXCAN_CTRL_ERR_MSK from a register value.
#define BG_FLEXCAN_CTRL_ERR_MSK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_CTRL_ERR_MSK) >> BP_FLEXCAN_CTRL_ERR_MSK)

//! @brief Format value for bitfield FLEXCAN_CTRL_ERR_MSK.
#define BF_FLEXCAN_CTRL_ERR_MSK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_CTRL_ERR_MSK) & BM_FLEXCAN_CTRL_ERR_MSK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ERR_MSK field to a new value.
#define BW_FLEXCAN_CTRL_ERR_MSK(x, v)   (HW_FLEXCAN_CTRL_WR(x, (HW_FLEXCAN_CTRL_RD(x) & ~BM_FLEXCAN_CTRL_ERR_MSK) | BF_FLEXCAN_CTRL_ERR_MSK(v)))
#endif


/* --- Register HW_FLEXCAN_CTRL, field BOFF_MSK[15] (RW)
 *
 * This bit provides a mask for the Bus Off Interrupt. {flexcan2_ipi_slv_flex_reg_esr_int}
 *
 * Values:
 * 0 - Bus Off interrupt disabled {flexcan2_ipi_slv_flex_reg_esr_int}
 * 1 - Bus Off interrupt enabled {flexcan2_ipi_slv_flex_reg_esr_int}
 */

#define BP_FLEXCAN_CTRL_BOFF_MSK      (15)      //!< Bit position for FLEXCAN_CTRL_BOFF_MSK.
#define BM_FLEXCAN_CTRL_BOFF_MSK      (0x00008000)  //!< Bit mask for FLEXCAN_CTRL_BOFF_MSK.

//! @brief Get value of FLEXCAN_CTRL_BOFF_MSK from a register value.
#define BG_FLEXCAN_CTRL_BOFF_MSK(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_CTRL_BOFF_MSK) >> BP_FLEXCAN_CTRL_BOFF_MSK)

//! @brief Format value for bitfield FLEXCAN_CTRL_BOFF_MSK.
#define BF_FLEXCAN_CTRL_BOFF_MSK(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_CTRL_BOFF_MSK) & BM_FLEXCAN_CTRL_BOFF_MSK)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BOFF_MSK field to a new value.
#define BW_FLEXCAN_CTRL_BOFF_MSK(x, v)   (HW_FLEXCAN_CTRL_WR(x, (HW_FLEXCAN_CTRL_RD(x) & ~BM_FLEXCAN_CTRL_BOFF_MSK) | BF_FLEXCAN_CTRL_BOFF_MSK(v)))
#endif


/* --- Register HW_FLEXCAN_CTRL, field PSEG2[18:16] (RW)
 *
 * This 3-bit field defines the length of Phase Buffer Segment 2 in the bit time
 * {flexcan2_ipi_slv_can_timing_parameters} . The valid programmable values are 1‚7.
 * {flexcan2_ipi_slv_can_timing_parameters} Phase Buffer Segment 2 = (PSEG2 + 1) x Time-Quanta.
 * {flexcan2_ipi_slv_can_timing_parameters}
 */

#define BP_FLEXCAN_CTRL_PSEG2      (16)      //!< Bit position for FLEXCAN_CTRL_PSEG2.
#define BM_FLEXCAN_CTRL_PSEG2      (0x00070000)  //!< Bit mask for FLEXCAN_CTRL_PSEG2.

//! @brief Get value of FLEXCAN_CTRL_PSEG2 from a register value.
#define BG_FLEXCAN_CTRL_PSEG2(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_CTRL_PSEG2) >> BP_FLEXCAN_CTRL_PSEG2)

//! @brief Format value for bitfield FLEXCAN_CTRL_PSEG2.
#define BF_FLEXCAN_CTRL_PSEG2(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_CTRL_PSEG2) & BM_FLEXCAN_CTRL_PSEG2)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PSEG2 field to a new value.
#define BW_FLEXCAN_CTRL_PSEG2(x, v)   (HW_FLEXCAN_CTRL_WR(x, (HW_FLEXCAN_CTRL_RD(x) & ~BM_FLEXCAN_CTRL_PSEG2) | BF_FLEXCAN_CTRL_PSEG2(v)))
#endif

/* --- Register HW_FLEXCAN_CTRL, field PSEG1[21:19] (RW)
 *
 * This 3-bit field defines the length of Phase Buffer Segment 1 in the bit time
 * {flexcan2_ipi_slv_can_timing_parameters} . The valid programmable values are 0‚7.
 * {flexcan2_ipi_slv_can_timing_parameters} Phase Buffer Segment 1 = (PSEG1 + 1) x Time-Quanta.
 * {flexcan2_ipi_slv_can_timing_parameters}
 */

#define BP_FLEXCAN_CTRL_PSEG1      (19)      //!< Bit position for FLEXCAN_CTRL_PSEG1.
#define BM_FLEXCAN_CTRL_PSEG1      (0x00380000)  //!< Bit mask for FLEXCAN_CTRL_PSEG1.

//! @brief Get value of FLEXCAN_CTRL_PSEG1 from a register value.
#define BG_FLEXCAN_CTRL_PSEG1(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_CTRL_PSEG1) >> BP_FLEXCAN_CTRL_PSEG1)

//! @brief Format value for bitfield FLEXCAN_CTRL_PSEG1.
#define BF_FLEXCAN_CTRL_PSEG1(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_CTRL_PSEG1) & BM_FLEXCAN_CTRL_PSEG1)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PSEG1 field to a new value.
#define BW_FLEXCAN_CTRL_PSEG1(x, v)   (HW_FLEXCAN_CTRL_WR(x, (HW_FLEXCAN_CTRL_RD(x) & ~BM_FLEXCAN_CTRL_PSEG1) | BF_FLEXCAN_CTRL_PSEG1(v)))
#endif

/* --- Register HW_FLEXCAN_CTRL, field RJW[23:22] (RW)
 *
 * This 2-bit field defines the maximum number of time quanta One time quantum is equal to the
 * Sclock period. {statement} that a bit time can be changed by one re-synchronization
 * {flexcan2_ipi_slv_can_timing_resynchronization} . The valid programmable values are 0‚3.
 * {flexcan2_ipi_slv_can_timing_resynchronization} Resync Jump Width = RJW + 1.
 * {flexcan2_ipi_slv_can_timing_resynchronization}
 */

#define BP_FLEXCAN_CTRL_RJW      (22)      //!< Bit position for FLEXCAN_CTRL_RJW.
#define BM_FLEXCAN_CTRL_RJW      (0x00c00000)  //!< Bit mask for FLEXCAN_CTRL_RJW.

//! @brief Get value of FLEXCAN_CTRL_RJW from a register value.
#define BG_FLEXCAN_CTRL_RJW(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_CTRL_RJW) >> BP_FLEXCAN_CTRL_RJW)

//! @brief Format value for bitfield FLEXCAN_CTRL_RJW.
#define BF_FLEXCAN_CTRL_RJW(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_CTRL_RJW) & BM_FLEXCAN_CTRL_RJW)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RJW field to a new value.
#define BW_FLEXCAN_CTRL_RJW(x, v)   (HW_FLEXCAN_CTRL_WR(x, (HW_FLEXCAN_CTRL_RD(x) & ~BM_FLEXCAN_CTRL_RJW) | BF_FLEXCAN_CTRL_RJW(v)))
#endif

/* --- Register HW_FLEXCAN_CTRL, field PRESDIV[31:24] (RW)
 *
 * This 8-bit field defines the ratio between the CPI clock frequency and the Serial Clock (Sclock)
 * frequency {flexcan2_ipi_slv_can_timing_parameters} . The Sclock period defines the time quantum
 * of the CAN protocol {flexcan2_ipi_slv_can_timing_parameters} . For the reset value, the Sclock
 * frequency is equal to the CPI clock frequency {flexcan2_ipi_slv_can_timing_parameters} . The
 * Maximum value of this register is 0xFF, that gives a minimum Sclock frequency equal to the CPI
 * clock frequency divided by 256. {flexcan2_ipi_slv_can_timing_parameters} For more information
 * refer to . {statement} Sclock frequency = CPI clock frequency / (PRESDIV + 1)
 * {flexcan2_ipi_slv_can_timing_parameters}
 */

#define BP_FLEXCAN_CTRL_PRESDIV      (24)      //!< Bit position for FLEXCAN_CTRL_PRESDIV.
#define BM_FLEXCAN_CTRL_PRESDIV      (0xff000000)  //!< Bit mask for FLEXCAN_CTRL_PRESDIV.

//! @brief Get value of FLEXCAN_CTRL_PRESDIV from a register value.
#define BG_FLEXCAN_CTRL_PRESDIV(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_CTRL_PRESDIV) >> BP_FLEXCAN_CTRL_PRESDIV)

//! @brief Format value for bitfield FLEXCAN_CTRL_PRESDIV.
#define BF_FLEXCAN_CTRL_PRESDIV(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_CTRL_PRESDIV) & BM_FLEXCAN_CTRL_PRESDIV)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PRESDIV field to a new value.
#define BW_FLEXCAN_CTRL_PRESDIV(x, v)   (HW_FLEXCAN_CTRL_WR(x, (HW_FLEXCAN_CTRL_RD(x) & ~BM_FLEXCAN_CTRL_PRESDIV) | BF_FLEXCAN_CTRL_PRESDIV(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_FLEXCAN_TIMER - Free Running Timer
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_TIMER - Free Running Timer (RW)
 *
 * Reset value: 0x00000000
 *
 * This register represents a 16-bit free running counter that can be read and written by the ARM
 * {flexcan2_ipi_slv_flex_reg_timer} . The timer starts from 0x0000 after Reset, counts linearly to
 * 0xFFFF, and wraps around. {flexcan2_ipi_slv_flex_reg_timer}  The timer is clocked by the FLEXCAN
 * bit-clock (which defines the baud rate on the CAN bus) {flexcan2_ipi_slv_flex_reg_timer} . During
 * a message transmission/reception, it increments by one for each bit that is received or
 * transmitted {flexcan2_ipi_slv_flex_reg_timer} . When there is no message on the bus, it counts
 * using the previously programmed baud rate. {flexcan2_ipi_slv_flex_reg_timer} During Freeze Mode,
 * the timer is not incremented {flexcan2_ipi_slv_flex_reg_timer} .  The timer value is captured at
 * the beginning of the identifier field of any frame on the CAN bus
 * {flexcan2_ipi_slv_flex_reg_timer} . This captured value is written into the Time Stamp entry in a
 * message buffer after a successful reception or transmission of a message.
 * {flexcan2_ipi_slv_flex_reg_timer}  Writing to the timer is an indirect operation {statement} .
 * The data is first written to an auxiliary register and then an internal request/acknowledge
 * procedure across clock domains is executed {statement} . All this is transparent to the user,
 * except for the fact that the data will take some time to be actually written to the register
 * {statement} . If desired, software can poll the register to discover when the data was actually
 * written {flexcan2_ipi_slv_flex_reg_timer} .
 */
typedef union _hw_flexcan_timer
{
    reg32_t U;
    struct _hw_flexcan_timer_bitfields
    {
        unsigned TIMER : 16; //!< [15:0] Timer value Contains the free-running counter value.
        unsigned RESERVED0 : 16; //!< [31:16] This read-only bitfield is reserved and always has the value zero.
    } B;
} hw_flexcan_timer_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_TIMER register
 */
#define HW_FLEXCAN_TIMER_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_TIMER(x)           (*(volatile hw_flexcan_timer_t *) HW_FLEXCAN_TIMER_ADDR(x))
#define HW_FLEXCAN_TIMER_RD(x)        (HW_FLEXCAN_TIMER(x).U)
#define HW_FLEXCAN_TIMER_WR(x, v)     (HW_FLEXCAN_TIMER(x).U = (v))
#define HW_FLEXCAN_TIMER_SET(x, v)    (HW_FLEXCAN_TIMER_WR(x, HW_FLEXCAN_TIMER_RD(x) |  (v)))
#define HW_FLEXCAN_TIMER_CLR(x, v)    (HW_FLEXCAN_TIMER_WR(x, HW_FLEXCAN_TIMER_RD(x) & ~(v)))
#define HW_FLEXCAN_TIMER_TOG(x, v)    (HW_FLEXCAN_TIMER_WR(x, HW_FLEXCAN_TIMER_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_TIMER bitfields
 */

/* --- Register HW_FLEXCAN_TIMER, field TIMER[15:0] (RW)
 *
 * Timer value Contains the free-running counter value.
 */

#define BP_FLEXCAN_TIMER_TIMER      (0)      //!< Bit position for FLEXCAN_TIMER_TIMER.
#define BM_FLEXCAN_TIMER_TIMER      (0x0000ffff)  //!< Bit mask for FLEXCAN_TIMER_TIMER.

//! @brief Get value of FLEXCAN_TIMER_TIMER from a register value.
#define BG_FLEXCAN_TIMER_TIMER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_TIMER_TIMER) >> BP_FLEXCAN_TIMER_TIMER)

//! @brief Format value for bitfield FLEXCAN_TIMER_TIMER.
#define BF_FLEXCAN_TIMER_TIMER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_TIMER_TIMER) & BM_FLEXCAN_TIMER_TIMER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TIMER field to a new value.
#define BW_FLEXCAN_TIMER_TIMER(x, v)   (HW_FLEXCAN_TIMER_WR(x, (HW_FLEXCAN_TIMER_RD(x) & ~BM_FLEXCAN_TIMER_TIMER) | BF_FLEXCAN_TIMER_TIMER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_FLEXCAN_RXGMASK - Rx Global Mask
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_RXGMASK - Rx Global Mask (RW)
 *
 * Reset value: 0xffffffff
 *
 * Supports individual masks per message buffer, setting the BCC bit in MCR causes the RXGMASK
 * Register to have no effect on the block operation {flexcan2_ipi_slv_flex_reg_rxmask} .  RXGMASK
 * is used as acceptance mask for all Rx message buffers, excluding message buffers 14‚ 15, which
 * have individual mask registers {flexcan2_ipi_slv_flex_reg_rxmask} . When the FEN bit in MCR is
 * set (FIFO enabled), the RXGMASK also applies to all elements of the ID filter table, except
 * elements 6-7, which have individual masks. {flexcan2_ipi_slv_flex_reg_rxmask}  The contents of
 * this register must be programmed while the block is in Freeze Mode, and must not be modified when
 * the block is transmitting or receiving frames.
 */
typedef union _hw_flexcan_rxgmask
{
    reg32_t U;
    struct _hw_flexcan_rxgmask_bitfields
    {
        unsigned MI31_MI0 : 32; //!< [31:0] For normal Rx message buffers, the mask bits affect the ID filter programmed on the message buffer. For the Rx FIFO, the mask bits affect all bits programmed in the filter table (ID, IDE, RTR) {flexcan2_ipi_slv_flex_reg_rxmask} .
    } B;
} hw_flexcan_rxgmask_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_RXGMASK register
 */
#define HW_FLEXCAN_RXGMASK_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_RXGMASK(x)           (*(volatile hw_flexcan_rxgmask_t *) HW_FLEXCAN_RXGMASK_ADDR(x))
#define HW_FLEXCAN_RXGMASK_RD(x)        (HW_FLEXCAN_RXGMASK(x).U)
#define HW_FLEXCAN_RXGMASK_WR(x, v)     (HW_FLEXCAN_RXGMASK(x).U = (v))
#define HW_FLEXCAN_RXGMASK_SET(x, v)    (HW_FLEXCAN_RXGMASK_WR(x, HW_FLEXCAN_RXGMASK_RD(x) |  (v)))
#define HW_FLEXCAN_RXGMASK_CLR(x, v)    (HW_FLEXCAN_RXGMASK_WR(x, HW_FLEXCAN_RXGMASK_RD(x) & ~(v)))
#define HW_FLEXCAN_RXGMASK_TOG(x, v)    (HW_FLEXCAN_RXGMASK_WR(x, HW_FLEXCAN_RXGMASK_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_RXGMASK bitfields
 */

/* --- Register HW_FLEXCAN_RXGMASK, field MI31_MI0[31:0] (RW)
 *
 * For normal Rx message buffers, the mask bits affect the ID filter programmed on the message
 * buffer. For the Rx FIFO, the mask bits affect all bits programmed in the filter table (ID, IDE,
 * RTR) {flexcan2_ipi_slv_flex_reg_rxmask} .
 *
 * Values:
 * 0 - the corresponding bit in the filter is dont care
 * 1 - The corresponding bit in the filter is checked against the one received
 */

#define BP_FLEXCAN_RXGMASK_MI31_MI0      (0)      //!< Bit position for FLEXCAN_RXGMASK_MI31_MI0.
#define BM_FLEXCAN_RXGMASK_MI31_MI0      (0xffffffff)  //!< Bit mask for FLEXCAN_RXGMASK_MI31_MI0.

//! @brief Get value of FLEXCAN_RXGMASK_MI31_MI0 from a register value.
#define BG_FLEXCAN_RXGMASK_MI31_MI0(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_RXGMASK_MI31_MI0) >> BP_FLEXCAN_RXGMASK_MI31_MI0)

//! @brief Format value for bitfield FLEXCAN_RXGMASK_MI31_MI0.
#define BF_FLEXCAN_RXGMASK_MI31_MI0(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_RXGMASK_MI31_MI0) & BM_FLEXCAN_RXGMASK_MI31_MI0)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MI31_MI0 field to a new value.
#define BW_FLEXCAN_RXGMASK_MI31_MI0(x, v)   (HW_FLEXCAN_RXGMASK_WR(x, (HW_FLEXCAN_RXGMASK_RD(x) & ~BM_FLEXCAN_RXGMASK_MI31_MI0) | BF_FLEXCAN_RXGMASK_MI31_MI0(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_FLEXCAN_RX14MASK - Rx 14 Mask
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_RX14MASK - Rx 14 Mask (RW)
 *
 * Reset value: 0xffffffff
 *
 * Setting the BCC bit in MCR causes the RX14MASK Register to have no effect on the block operation
 * {flexcan2_ipi_slv_flex_reg_rxmask} .  RX14MASK is used as acceptance mask for the Identifier in
 * Message Buffer 14 {flexcan2_ipi_slv_flex_reg_rxmask} . When the FEN bit in MCR is set (FIFO
 * enabled), the RXG14MASK also applies to element 6 of the ID filter table. This register has the
 * same structure as the Rx Global Mask Register {flexcan2_ipi_slv_flex_reg_rxmask} . It must be
 * programmed while the block is in Freeze Mode, and must not be modified when the block is
 * transmitting or receiving frames.   Address Offset: 0x14 {flexcan2_ipi_slv_flex_reg_rxmask}
 * Reset Value: 0xFFFF_FFFF {flexcan2_ipi_slv_flex_reg_access}
 */
typedef union _hw_flexcan_rx14mask
{
    reg32_t U;
    struct _hw_flexcan_rx14mask_bitfields
    {
        unsigned MI31_MI0 : 32; //!< [31:0] Acceptance mask for the Identifier in Message Buffer 14
    } B;
} hw_flexcan_rx14mask_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_RX14MASK register
 */
#define HW_FLEXCAN_RX14MASK_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_RX14MASK(x)           (*(volatile hw_flexcan_rx14mask_t *) HW_FLEXCAN_RX14MASK_ADDR(x))
#define HW_FLEXCAN_RX14MASK_RD(x)        (HW_FLEXCAN_RX14MASK(x).U)
#define HW_FLEXCAN_RX14MASK_WR(x, v)     (HW_FLEXCAN_RX14MASK(x).U = (v))
#define HW_FLEXCAN_RX14MASK_SET(x, v)    (HW_FLEXCAN_RX14MASK_WR(x, HW_FLEXCAN_RX14MASK_RD(x) |  (v)))
#define HW_FLEXCAN_RX14MASK_CLR(x, v)    (HW_FLEXCAN_RX14MASK_WR(x, HW_FLEXCAN_RX14MASK_RD(x) & ~(v)))
#define HW_FLEXCAN_RX14MASK_TOG(x, v)    (HW_FLEXCAN_RX14MASK_WR(x, HW_FLEXCAN_RX14MASK_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_RX14MASK bitfields
 */

/* --- Register HW_FLEXCAN_RX14MASK, field MI31_MI0[31:0] (RW)
 *
 * Acceptance mask for the Identifier in Message Buffer 14
 */

#define BP_FLEXCAN_RX14MASK_MI31_MI0      (0)      //!< Bit position for FLEXCAN_RX14MASK_MI31_MI0.
#define BM_FLEXCAN_RX14MASK_MI31_MI0      (0xffffffff)  //!< Bit mask for FLEXCAN_RX14MASK_MI31_MI0.

//! @brief Get value of FLEXCAN_RX14MASK_MI31_MI0 from a register value.
#define BG_FLEXCAN_RX14MASK_MI31_MI0(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_RX14MASK_MI31_MI0) >> BP_FLEXCAN_RX14MASK_MI31_MI0)

//! @brief Format value for bitfield FLEXCAN_RX14MASK_MI31_MI0.
#define BF_FLEXCAN_RX14MASK_MI31_MI0(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_RX14MASK_MI31_MI0) & BM_FLEXCAN_RX14MASK_MI31_MI0)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MI31_MI0 field to a new value.
#define BW_FLEXCAN_RX14MASK_MI31_MI0(x, v)   (HW_FLEXCAN_RX14MASK_WR(x, (HW_FLEXCAN_RX14MASK_RD(x) & ~BM_FLEXCAN_RX14MASK_MI31_MI0) | BF_FLEXCAN_RX14MASK_MI31_MI0(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_FLEXCAN_RX15MASK - Rx 15 Mask
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_RX15MASK - Rx 15 Mask (RW)
 *
 * Reset value: 0xffffffff
 *
 * Setting the BCC bit in MCR causes the RX15MASK Register to have no effect on the block operation
 * {flexcan2_ipi_slv_flex_reg_rxmask} .  When the BCC bit is negated, RX15MASK is used as acceptance
 * mask for the Identifier in Message Buffer 15 {flexcan2_ipi_slv_flex_reg_rxmask} . When the FEN
 * bit in MCR is set (FIFO enabled), the RXG14MASK also applies to element 7 of the ID filter table.
 * This register has the same structure as the Rx Global Mask Register
 * {flexcan2_ipi_slv_flex_reg_rxmask} . It must be programmed while the block is in Freeze Mode, and
 * must not be modified when the block is transmitting or receiving frames.   Address Offset: 0x18
 * {flexcan2_ipi_slv_flex_reg_rxmask}   Reset Value: 0xFFFF_FFFF {flexcan2_ipi_slv_flex_reg_access}
 */
typedef union _hw_flexcan_rx15mask
{
    reg32_t U;
    struct _hw_flexcan_rx15mask_bitfields
    {
        unsigned MI31_MI0 : 32; //!< [31:0] Acceptance mask for the Identifier in Message Buffer 15
    } B;
} hw_flexcan_rx15mask_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_RX15MASK register
 */
#define HW_FLEXCAN_RX15MASK_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_RX15MASK(x)           (*(volatile hw_flexcan_rx15mask_t *) HW_FLEXCAN_RX15MASK_ADDR(x))
#define HW_FLEXCAN_RX15MASK_RD(x)        (HW_FLEXCAN_RX15MASK(x).U)
#define HW_FLEXCAN_RX15MASK_WR(x, v)     (HW_FLEXCAN_RX15MASK(x).U = (v))
#define HW_FLEXCAN_RX15MASK_SET(x, v)    (HW_FLEXCAN_RX15MASK_WR(x, HW_FLEXCAN_RX15MASK_RD(x) |  (v)))
#define HW_FLEXCAN_RX15MASK_CLR(x, v)    (HW_FLEXCAN_RX15MASK_WR(x, HW_FLEXCAN_RX15MASK_RD(x) & ~(v)))
#define HW_FLEXCAN_RX15MASK_TOG(x, v)    (HW_FLEXCAN_RX15MASK_WR(x, HW_FLEXCAN_RX15MASK_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_RX15MASK bitfields
 */

/* --- Register HW_FLEXCAN_RX15MASK, field MI31_MI0[31:0] (RW)
 *
 * Acceptance mask for the Identifier in Message Buffer 15
 */

#define BP_FLEXCAN_RX15MASK_MI31_MI0      (0)      //!< Bit position for FLEXCAN_RX15MASK_MI31_MI0.
#define BM_FLEXCAN_RX15MASK_MI31_MI0      (0xffffffff)  //!< Bit mask for FLEXCAN_RX15MASK_MI31_MI0.

//! @brief Get value of FLEXCAN_RX15MASK_MI31_MI0 from a register value.
#define BG_FLEXCAN_RX15MASK_MI31_MI0(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_RX15MASK_MI31_MI0) >> BP_FLEXCAN_RX15MASK_MI31_MI0)

//! @brief Format value for bitfield FLEXCAN_RX15MASK_MI31_MI0.
#define BF_FLEXCAN_RX15MASK_MI31_MI0(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_RX15MASK_MI31_MI0) & BM_FLEXCAN_RX15MASK_MI31_MI0)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MI31_MI0 field to a new value.
#define BW_FLEXCAN_RX15MASK_MI31_MI0(x, v)   (HW_FLEXCAN_RX15MASK_WR(x, (HW_FLEXCAN_RX15MASK_RD(x) & ~BM_FLEXCAN_RX15MASK_MI31_MI0) | BF_FLEXCAN_RX15MASK_MI31_MI0(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_FLEXCAN_ECR - Error Counter Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_ECR - Error Counter Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register has 2 8-bit fields reflecting the value of two FLEXCAN error counters: Transmit
 * Error Counter (Tx_Err_Counter field) and Receive Error Counter (Rx_Err_Counter field)
 * {flexcan2_ipi_slv_can_counters_tx}{flexcan2_ipi_slv_can_counters_rx} . The rules for increasing
 * and decreasing these counters are described in the CAN protocol and are completely implemented in
 * the FLEXCAN block {flexcan2_ipi_slv_can_counters_tx}{flexcan2_ipi_slv_can_counters_rx} . Both
 * counters are read only except in Test Mode or Freeze Mode, where they can be written by the ARM.
 * {flexcan2_ipi_slv_flex_freezemode}{flexcan2_ipi_slv_flex_reg_test}  Writing to the Error Counter
 * Register while in Freeze Mode is an indirect operation {statement} . The data is first written to
 * an auxiliary register and then an internal request/acknowledge procedure across clock domains is
 * executed {statement} . All this is transparent to the user, except for the fact that the data
 * will take some time to be actually written to the register {statement} . If desired, software can
 * poll the register to discover when the data was actually written
 * {flexcan2_ipi_slv_flex_freezemode} .  FLEXCAN responds to any bus state as described in the
 * protocol {statement} that is transmit Error Active or Error Passive flag, delay its transmission
 * start time (Error Passive) and avoid any influence on the bus when in ‚ Bus Off state {statement}
 * . The following are the basic rules for FLEXCAN bus state transitions. {statement}   If the value
 * of Tx_Err_Counter or Rx_Err_Counter increases to be greater than or equal to 128, the FLT_CONF
 * field in the Error and Status Register is updated to reflect Error Passive state
 * {flexcan2_ipi_slv_can_error_multipleerrors}{flexcan2_ipi_slv_flex_reg_esr_fltconf} .  If the
 * FLEXCAN state is Error Passive and either Tx_Err_Counter or Rx_Err_Counter decrements to a value
 * less than or equal to 127. While the other already satisfies this condition, the FLT_CONF field
 * in the Error and Status Register is updated to reflect ErrorError Active state
 * {flexcan2_ipi_slv_can_error_multipleerrors}{flexcan2_ipi_slv_flex_reg_esr_fltconf} .  If the
 * value of Tx_Err_Counter increases to be greater than 255, the FLT_CONF field in the Error and
 * Status Register is updated to reflect Bus Off state and an interrupt may be issued {flexcan2_ipi_
 * slv_flex_reg_esr_fltconf}{flexcan2_ipi_slv_flex_reg_esr_int}{flexcan2_ipi_slv_flex_busoff} . The
 * value of Tx_Err_Counter is then reset to zero. {flexcan2_ipi_slv_flex_busoff}   If FLEXCAN is in
 * Bus Off state then Tx_Err_Counter is cascaded together with another internal counter to count the
 * 128th occurrences of 11 consecutive recessive bits on the bus {flexcan2_ipi_slv_flex_busoff} .
 * Hence, Tx_Err_Counter is reset to zero and counts in a manner where the internal counter counts
 * 11 such bits and then wraps around while incrementing the Tx_Err_Counter
 * {flexcan2_ipi_slv_flex_busoff} . When Tx_Err_Counter reaches the value of 128, the FLT_CONF field
 * in the Error and Status Register is updated to be Error Active and both error counters are reset
 * to zero {flexcan2_ipi_slv_flex_busoff} . At any instance of dominant bit following a stream of
 * less than 11 consecutive recessive bits, the internal counter resets itself to zero without
 * affecting the Tx_Err_Counter value. {flexcan2_ipi_slv_flex_busoff}   If during system start-up
 * only one node is operating, then its Tx_Err_Counter increases in each message it is trying to
 * transmit as a result of acknowledge errors (indicated by the ACK_ERR bit in the Error and Status
 * Register) {flexcan2_ipi_slv_can_error_multipleerrors} . After the transition to Error Passive
 * state, the Tx_Err_Counter does not increment anymore by acknowledge errors
 * {flexcan2_ipi_slv_can_error_multipleerrors} . Therefore the device never goes to the Bus Off
 * state. {flexcan2_ipi_slv_can_error_multipleerrors}   If the Rx_Err_Counter increases to a value
 * greater than 127, it is not incremented further even if more errors are detected while being a
 * receiver {flexcan2_ipi_slv_can_error_multipleerrors} . At the next successful message reception,
 * the counter is set to a value between 119 and 127 to resume to Error Active state.
 * {flexcan2_ipi_slv_can_error_multipleerrors}
 */
typedef union _hw_flexcan_ecr
{
    reg32_t U;
    struct _hw_flexcan_ecr_bitfields
    {
        unsigned TX_ERR_COUNTER : 8; //!< [7:0] Transmit Error Counter
        unsigned RX_ERR_COUNTER : 8; //!< [15:8] Receive Error Counter
        unsigned RESERVED0 : 16; //!< [31:16] This read-only bitfield is reserved and always has the value zero
    } B;
} hw_flexcan_ecr_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_ECR register
 */
#define HW_FLEXCAN_ECR_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_ECR(x)           (*(volatile hw_flexcan_ecr_t *) HW_FLEXCAN_ECR_ADDR(x))
#define HW_FLEXCAN_ECR_RD(x)        (HW_FLEXCAN_ECR(x).U)
#define HW_FLEXCAN_ECR_WR(x, v)     (HW_FLEXCAN_ECR(x).U = (v))
#define HW_FLEXCAN_ECR_SET(x, v)    (HW_FLEXCAN_ECR_WR(x, HW_FLEXCAN_ECR_RD(x) |  (v)))
#define HW_FLEXCAN_ECR_CLR(x, v)    (HW_FLEXCAN_ECR_WR(x, HW_FLEXCAN_ECR_RD(x) & ~(v)))
#define HW_FLEXCAN_ECR_TOG(x, v)    (HW_FLEXCAN_ECR_WR(x, HW_FLEXCAN_ECR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_ECR bitfields
 */

/* --- Register HW_FLEXCAN_ECR, field TX_ERR_COUNTER[7:0] (RW)
 *
 * Transmit Error Counter
 */

#define BP_FLEXCAN_ECR_TX_ERR_COUNTER      (0)      //!< Bit position for FLEXCAN_ECR_TX_ERR_COUNTER.
#define BM_FLEXCAN_ECR_TX_ERR_COUNTER      (0x000000ff)  //!< Bit mask for FLEXCAN_ECR_TX_ERR_COUNTER.

//! @brief Get value of FLEXCAN_ECR_TX_ERR_COUNTER from a register value.
#define BG_FLEXCAN_ECR_TX_ERR_COUNTER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_ECR_TX_ERR_COUNTER) >> BP_FLEXCAN_ECR_TX_ERR_COUNTER)

//! @brief Format value for bitfield FLEXCAN_ECR_TX_ERR_COUNTER.
#define BF_FLEXCAN_ECR_TX_ERR_COUNTER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_ECR_TX_ERR_COUNTER) & BM_FLEXCAN_ECR_TX_ERR_COUNTER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_ERR_COUNTER field to a new value.
#define BW_FLEXCAN_ECR_TX_ERR_COUNTER(x, v)   (HW_FLEXCAN_ECR_WR(x, (HW_FLEXCAN_ECR_RD(x) & ~BM_FLEXCAN_ECR_TX_ERR_COUNTER) | BF_FLEXCAN_ECR_TX_ERR_COUNTER(v)))
#endif

/* --- Register HW_FLEXCAN_ECR, field RX_ERR_COUNTER[15:8] (RW)
 *
 * Receive Error Counter
 */

#define BP_FLEXCAN_ECR_RX_ERR_COUNTER      (8)      //!< Bit position for FLEXCAN_ECR_RX_ERR_COUNTER.
#define BM_FLEXCAN_ECR_RX_ERR_COUNTER      (0x0000ff00)  //!< Bit mask for FLEXCAN_ECR_RX_ERR_COUNTER.

//! @brief Get value of FLEXCAN_ECR_RX_ERR_COUNTER from a register value.
#define BG_FLEXCAN_ECR_RX_ERR_COUNTER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_ECR_RX_ERR_COUNTER) >> BP_FLEXCAN_ECR_RX_ERR_COUNTER)

//! @brief Format value for bitfield FLEXCAN_ECR_RX_ERR_COUNTER.
#define BF_FLEXCAN_ECR_RX_ERR_COUNTER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_ECR_RX_ERR_COUNTER) & BM_FLEXCAN_ECR_RX_ERR_COUNTER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RX_ERR_COUNTER field to a new value.
#define BW_FLEXCAN_ECR_RX_ERR_COUNTER(x, v)   (HW_FLEXCAN_ECR_WR(x, (HW_FLEXCAN_ECR_RD(x) & ~BM_FLEXCAN_ECR_RX_ERR_COUNTER) | BF_FLEXCAN_ECR_RX_ERR_COUNTER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_FLEXCAN_ESR - Error and Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_ESR - Error and Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register reflects various error conditions. Four of these error conditions may be programed
 * to signal an interrupt to the ARM. The reported error conditions (bits 15‚ 10) (bits 16-21) are
 * those that occurred since the last time the ARM read this register
 * {flexcan2_ipi_slv_flex_reg_esr_error} . The ARM read action clears (bits 15‚10)(bits 16-21)
 * {flexcan2_ipi_slv_flex_reg_esr_error} . (Bits 9‚ 4) (bits 22-28) are status bits. {statement}
 * Most bits in this register are read only, except TWRN_INT, RWRN_INT, BOFF_INT, WAK_INT and
 * ERR_INT {flexcan2_ipi_slv_flex_reg_access} , that are interrupt flags that can be cleared by
 * writing 1 to them (writing 0 has no effect) {flexcan2_ipi_slv_flex_reg_esr_int} . See for more
 * details. {statement}
 */
typedef union _hw_flexcan_esr
{
    reg32_t U;
    struct _hw_flexcan_esr_bitfields
    {
        unsigned WAK_INT : 1; //!< [0] When FLEXCAN is Stop Mode and a recessive to dominant transition is detected on the CAN bus and if the WAK_MSK bit in the MCR Register is set, an interrupt is generated to the ARM {flexcan2_ipi_slv_flex_reg_esr_int} . This bit is cleared by writing it to 1 {flexcan2_ipi_slv_flex_reg_esr_int} . Writing 0 has no effect. {flexcan2_ipi_slv_flex_reg_esr_int}
        unsigned ERR_INT : 1; //!< [1] This bit indicates that at least one of the Error Bits (bits 15-10) (bits 16-21) is set {flexcan2_ipi_slv_flex_reg_esr_int} . If the corresponding mask bit in the Control Register (ERR_MSK) is set, an interrupt is generated to the ARM {flexcan2_ipi_slv_flex_reg_esr_int} . This bit is cleared by writing it to 1 {flexcan2_ipi_slv_flex_reg_esr_int} . Writing 0 has no effect. {flexcan2_ipi_slv_flex_reg_esr_int}
        unsigned BOFF_INT : 1; //!< [2] This bit is set when FLEXCAN enters Bus Off state {flexcan2_ipi_slv_flex_reg_esr_int} . If the corresponding mask bit in the Control Register (BOFF_MSK) is set, an interrupt is generated to the ARM {flexcan2_ipi_slv_flex_reg_esr_int} . This bit is cleared by writing it to 1. Writing 0 has no effect. {flexcan2_ipi_slv_flex_reg_esr_int}
        unsigned RESERVED0 : 1; //!< [3] Reserved
        unsigned FLT_CONF : 2; //!< [5:4] This 2-bit field indicates the Confinement State of the FLEXCAN block, as shown in below: {flexcan2_ipi_slv_flex_reg_esr_fltconf} If the LOM bit in the Control Register is asserted, the FLT_CONF field will indicate Error Passive {flexcan2_ipi_slv_flex_lomode} . Because the Control Register is not affected by soft reset, the FLT_CONF field will not be affected by soft reset if the LOM bit is asserted {flexcan2_ipi_slv_flex_softreset}
        unsigned TXRX : 1; //!< [6] This bit indicates if FLEXCAN is transmitting or receiving a message when the CAN bus is not in IDLE state {flexcan2_ipi_slv_flex_reg_esr_idle} . This bit has no meaning when IDLE is asserted. {statement}
        unsigned IDLE : 1; //!< [7] This bit indicates when CAN bus is in IDLE state. {flexcan2_ipi_slv_flex_reg_esr_idle}
        unsigned RX_WRN : 1; //!< [8] This bit indicates when repetitive errors are occurring during message reception. {statement}
        unsigned TX_WRN : 1; //!< [9] This bit indicates when repetitive errors are occurring during message transmission. {statement}
        unsigned STF_ERR : 1; //!< [10] This bit indicates that a Stuffing Error has been detected. {flexcan2_ipi_slv_flex_reg_esr_error}
        unsigned FRM_ERR : 1; //!< [11] This bit indicates that a Form Error has been detected by the receiver node, that is, a fixed-form bit field contains at least one illegal bit. {flexcan2_ipi_slv_flex_reg_esr_error}
        unsigned CRC_ERR : 1; //!< [12] This bit indicates that a CRC Error has been detected by the receiver node, that is, the calculated CRC is different from the received. {flexcan2_ipi_slv_flex_reg_esr_error}
        unsigned ACK_ERR : 1; //!< [13] This bit indicates that an Acknowledge Error has been detected by the transmitter node, that is, a dominant bit has not been detected during the ACK SLOT {flexcan2_ipi_slv_flex_reg_esr_error} .
        unsigned BIT0_ERR : 1; //!< [14] This bit indicates when an inconsistency occurs between the transmitted and the received bit in a message. {flexcan2_ipi_slv_flex_reg_esr_error}
        unsigned BIT1_ERR : 1; //!< [15] This bit indicates when an inconsistency occurs between the transmitted and the received bit in a message {flexcan2_ipi_slv_flex_reg_esr_error} . This bit is not set by a transmitter in case of arbitration field or ACK slot, or in case of a node sending a passive error flag that detects dominant bits. {flexcan2_ipi_slv_flex_reg_esr_error}
        unsigned RWRN_INT : 1; //!< [16] If the WRN_EN bit in MCR is asserted, the RWRN_INT bit is set when the RX_WRN flag transitions from 0 to 1, meaning that the Rx error counters reached 96. If the corresponding mask bit in the Control Register (RWRN_MSK) is set, an interrupt is generated to the ARM. This bit is cleared by writing it to 1. Writing 0 has no effect.
        unsigned TWRN_INT : 1; //!< [17] If the WRN_EN bit in MCR is asserted, the TWRN_INT bit is set when the TX_WRN flag transitions from 0 to 1, meaning that the Tx error counter reached 96. If the corresponding mask bit in the Control Register (TWRN_MSK) is set, an interrupt is generated to the ARM. This bit is cleared by writing it to 1. Writing 0 has no effect.
        unsigned RESERVED1 : 14; //!< [31:18] Reserved
    } B;
} hw_flexcan_esr_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_ESR register
 */
#define HW_FLEXCAN_ESR_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_ESR(x)           (*(volatile hw_flexcan_esr_t *) HW_FLEXCAN_ESR_ADDR(x))
#define HW_FLEXCAN_ESR_RD(x)        (HW_FLEXCAN_ESR(x).U)
#define HW_FLEXCAN_ESR_WR(x, v)     (HW_FLEXCAN_ESR(x).U = (v))
#define HW_FLEXCAN_ESR_SET(x, v)    (HW_FLEXCAN_ESR_WR(x, HW_FLEXCAN_ESR_RD(x) |  (v)))
#define HW_FLEXCAN_ESR_CLR(x, v)    (HW_FLEXCAN_ESR_WR(x, HW_FLEXCAN_ESR_RD(x) & ~(v)))
#define HW_FLEXCAN_ESR_TOG(x, v)    (HW_FLEXCAN_ESR_WR(x, HW_FLEXCAN_ESR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_ESR bitfields
 */

/* --- Register HW_FLEXCAN_ESR, field WAK_INT[0] (RW)
 *
 * When FLEXCAN is Stop Mode and a recessive to dominant transition is detected on the CAN bus and
 * if the WAK_MSK bit in the MCR Register is set, an interrupt is generated to the ARM
 * {flexcan2_ipi_slv_flex_reg_esr_int} . This bit is cleared by writing it to 1
 * {flexcan2_ipi_slv_flex_reg_esr_int} . Writing 0 has no effect.
 * {flexcan2_ipi_slv_flex_reg_esr_int}
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_reg_esr_int}
 * 1 - Indicates a recessive to dominant transition received on the CAN bus when the FLEXCAN is in Stop
 *     Mode {flexcan2_ipi_slv_flex_reg_esr_int}
 */

#define BP_FLEXCAN_ESR_WAK_INT      (0)      //!< Bit position for FLEXCAN_ESR_WAK_INT.
#define BM_FLEXCAN_ESR_WAK_INT      (0x00000001)  //!< Bit mask for FLEXCAN_ESR_WAK_INT.

//! @brief Get value of FLEXCAN_ESR_WAK_INT from a register value.
#define BG_FLEXCAN_ESR_WAK_INT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_ESR_WAK_INT) >> BP_FLEXCAN_ESR_WAK_INT)

//! @brief Format value for bitfield FLEXCAN_ESR_WAK_INT.
#define BF_FLEXCAN_ESR_WAK_INT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_ESR_WAK_INT) & BM_FLEXCAN_ESR_WAK_INT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WAK_INT field to a new value.
#define BW_FLEXCAN_ESR_WAK_INT(x, v)   (HW_FLEXCAN_ESR_WR(x, (HW_FLEXCAN_ESR_RD(x) & ~BM_FLEXCAN_ESR_WAK_INT) | BF_FLEXCAN_ESR_WAK_INT(v)))
#endif


/* --- Register HW_FLEXCAN_ESR, field ERR_INT[1] (RW)
 *
 * This bit indicates that at least one of the Error Bits (bits 15-10) (bits 16-21) is set
 * {flexcan2_ipi_slv_flex_reg_esr_int} . If the corresponding mask bit in the Control Register
 * (ERR_MSK) is set, an interrupt is generated to the ARM {flexcan2_ipi_slv_flex_reg_esr_int} . This
 * bit is cleared by writing it to 1 {flexcan2_ipi_slv_flex_reg_esr_int} . Writing 0 has no effect.
 * {flexcan2_ipi_slv_flex_reg_esr_int}
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_reg_esr_int}
 * 1 - Indicates setting of any Error Bit in the Error and Status Register
 *     {flexcan2_ipi_slv_flex_reg_esr_int}
 */

#define BP_FLEXCAN_ESR_ERR_INT      (1)      //!< Bit position for FLEXCAN_ESR_ERR_INT.
#define BM_FLEXCAN_ESR_ERR_INT      (0x00000002)  //!< Bit mask for FLEXCAN_ESR_ERR_INT.

//! @brief Get value of FLEXCAN_ESR_ERR_INT from a register value.
#define BG_FLEXCAN_ESR_ERR_INT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_ESR_ERR_INT) >> BP_FLEXCAN_ESR_ERR_INT)

//! @brief Format value for bitfield FLEXCAN_ESR_ERR_INT.
#define BF_FLEXCAN_ESR_ERR_INT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_ESR_ERR_INT) & BM_FLEXCAN_ESR_ERR_INT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ERR_INT field to a new value.
#define BW_FLEXCAN_ESR_ERR_INT(x, v)   (HW_FLEXCAN_ESR_WR(x, (HW_FLEXCAN_ESR_RD(x) & ~BM_FLEXCAN_ESR_ERR_INT) | BF_FLEXCAN_ESR_ERR_INT(v)))
#endif


/* --- Register HW_FLEXCAN_ESR, field BOFF_INT[2] (RW)
 *
 * This bit is set when FLEXCAN enters Bus Off state {flexcan2_ipi_slv_flex_reg_esr_int} . If the
 * corresponding mask bit in the Control Register (BOFF_MSK) is set, an interrupt is generated to
 * the ARM {flexcan2_ipi_slv_flex_reg_esr_int} . This bit is cleared by writing it to 1. Writing 0
 * has no effect. {flexcan2_ipi_slv_flex_reg_esr_int}
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_reg_esr_int}
 * 1 - FLEXCAN block entered Bus Off state {flexcan2_ipi_slv_flex_reg_esr_int}
 */

#define BP_FLEXCAN_ESR_BOFF_INT      (2)      //!< Bit position for FLEXCAN_ESR_BOFF_INT.
#define BM_FLEXCAN_ESR_BOFF_INT      (0x00000004)  //!< Bit mask for FLEXCAN_ESR_BOFF_INT.

//! @brief Get value of FLEXCAN_ESR_BOFF_INT from a register value.
#define BG_FLEXCAN_ESR_BOFF_INT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_ESR_BOFF_INT) >> BP_FLEXCAN_ESR_BOFF_INT)

//! @brief Format value for bitfield FLEXCAN_ESR_BOFF_INT.
#define BF_FLEXCAN_ESR_BOFF_INT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_ESR_BOFF_INT) & BM_FLEXCAN_ESR_BOFF_INT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BOFF_INT field to a new value.
#define BW_FLEXCAN_ESR_BOFF_INT(x, v)   (HW_FLEXCAN_ESR_WR(x, (HW_FLEXCAN_ESR_RD(x) & ~BM_FLEXCAN_ESR_BOFF_INT) | BF_FLEXCAN_ESR_BOFF_INT(v)))
#endif


/* --- Register HW_FLEXCAN_ESR, field FLT_CONF[5:4] (RO)
 *
 * This 2-bit field indicates the Confinement State of the FLEXCAN block, as shown in below:
 * {flexcan2_ipi_slv_flex_reg_esr_fltconf} If the LOM bit in the Control Register is asserted, the
 * FLT_CONF field will indicate Error Passive {flexcan2_ipi_slv_flex_lomode} . Because the Control
 * Register is not affected by soft reset, the FLT_CONF field will not be affected by soft reset if
 * the LOM bit is asserted {flexcan2_ipi_slv_flex_softreset}
 *
 * Values:
 * 01 - Error Passive
 * 1x - Bus off
 */

#define BP_FLEXCAN_ESR_FLT_CONF      (4)      //!< Bit position for FLEXCAN_ESR_FLT_CONF.
#define BM_FLEXCAN_ESR_FLT_CONF      (0x00000030)  //!< Bit mask for FLEXCAN_ESR_FLT_CONF.

//! @brief Get value of FLEXCAN_ESR_FLT_CONF from a register value.
#define BG_FLEXCAN_ESR_FLT_CONF(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_ESR_FLT_CONF) >> BP_FLEXCAN_ESR_FLT_CONF)


/* --- Register HW_FLEXCAN_ESR, field TXRX[6] (RO)
 *
 * This bit indicates if FLEXCAN is transmitting or receiving a message when the CAN bus is not in
 * IDLE state {flexcan2_ipi_slv_flex_reg_esr_idle} . This bit has no meaning when IDLE is asserted.
 * {statement}
 *
 * Values:
 * 0 - FLEXCAN is receiving a message (IDLE=0) {flexcan2_ipi_slv_flex_reg_esr_idle}
 * 1 - FLEXCAN is transmitting a message (IDLE=0) {flexcan2_ipi_slv_flex_reg_esr_idle}
 */

#define BP_FLEXCAN_ESR_TXRX      (6)      //!< Bit position for FLEXCAN_ESR_TXRX.
#define BM_FLEXCAN_ESR_TXRX      (0x00000040)  //!< Bit mask for FLEXCAN_ESR_TXRX.

//! @brief Get value of FLEXCAN_ESR_TXRX from a register value.
#define BG_FLEXCAN_ESR_TXRX(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_ESR_TXRX) >> BP_FLEXCAN_ESR_TXRX)


/* --- Register HW_FLEXCAN_ESR, field IDLE[7] (RO)
 *
 * This bit indicates when CAN bus is in IDLE state. {flexcan2_ipi_slv_flex_reg_esr_idle}
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_reg_esr_idle}
 * 1 - CAN bus is now IDLE {flexcan2_ipi_slv_flex_reg_esr_idle}
 */

#define BP_FLEXCAN_ESR_IDLE      (7)      //!< Bit position for FLEXCAN_ESR_IDLE.
#define BM_FLEXCAN_ESR_IDLE      (0x00000080)  //!< Bit mask for FLEXCAN_ESR_IDLE.

//! @brief Get value of FLEXCAN_ESR_IDLE from a register value.
#define BG_FLEXCAN_ESR_IDLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_ESR_IDLE) >> BP_FLEXCAN_ESR_IDLE)


/* --- Register HW_FLEXCAN_ESR, field RX_WRN[8] (RO)
 *
 * This bit indicates when repetitive errors are occurring during message reception. {statement}
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_can_error_multipleerrors}
 * 1 - Rx_Err_Counter ℜ≥ 96 {flexcan2_ipi_slv_can_error_multipleerrors}
 */

#define BP_FLEXCAN_ESR_RX_WRN      (8)      //!< Bit position for FLEXCAN_ESR_RX_WRN.
#define BM_FLEXCAN_ESR_RX_WRN      (0x00000100)  //!< Bit mask for FLEXCAN_ESR_RX_WRN.

//! @brief Get value of FLEXCAN_ESR_RX_WRN from a register value.
#define BG_FLEXCAN_ESR_RX_WRN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_ESR_RX_WRN) >> BP_FLEXCAN_ESR_RX_WRN)


/* --- Register HW_FLEXCAN_ESR, field TX_WRN[9] (RO)
 *
 * This bit indicates when repetitive errors are occurring during message transmission. {statement}
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_can_error_multipleerrors}
 * 1 - TX_Err_Counter ℜ≥ 96 {flexcan2_ipi_slv_can_error_multipleerrors}
 */

#define BP_FLEXCAN_ESR_TX_WRN      (9)      //!< Bit position for FLEXCAN_ESR_TX_WRN.
#define BM_FLEXCAN_ESR_TX_WRN      (0x00000200)  //!< Bit mask for FLEXCAN_ESR_TX_WRN.

//! @brief Get value of FLEXCAN_ESR_TX_WRN from a register value.
#define BG_FLEXCAN_ESR_TX_WRN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_ESR_TX_WRN) >> BP_FLEXCAN_ESR_TX_WRN)


/* --- Register HW_FLEXCAN_ESR, field STF_ERR[10] (RO)
 *
 * This bit indicates that a Stuffing Error has been detected. {flexcan2_ipi_slv_flex_reg_esr_error}
 *
 * Values:
 * 0 - No such occurrence. {flexcan2_ipi_slv_flex_reg_esr_error}
 * 1 - A Stuffing Error occurred since last read of this register. {flexcan2_ipi_slv_flex_reg_esr_error}
 */

#define BP_FLEXCAN_ESR_STF_ERR      (10)      //!< Bit position for FLEXCAN_ESR_STF_ERR.
#define BM_FLEXCAN_ESR_STF_ERR      (0x00000400)  //!< Bit mask for FLEXCAN_ESR_STF_ERR.

//! @brief Get value of FLEXCAN_ESR_STF_ERR from a register value.
#define BG_FLEXCAN_ESR_STF_ERR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_ESR_STF_ERR) >> BP_FLEXCAN_ESR_STF_ERR)


/* --- Register HW_FLEXCAN_ESR, field FRM_ERR[11] (RO)
 *
 * This bit indicates that a Form Error has been detected by the receiver node, that is, a fixed-
 * form bit field contains at least one illegal bit. {flexcan2_ipi_slv_flex_reg_esr_error}
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_reg_esr_error}
 * 1 - A Form Error occurred since last read of this register {flexcan2_ipi_slv_flex_reg_esr_error}
 */

#define BP_FLEXCAN_ESR_FRM_ERR      (11)      //!< Bit position for FLEXCAN_ESR_FRM_ERR.
#define BM_FLEXCAN_ESR_FRM_ERR      (0x00000800)  //!< Bit mask for FLEXCAN_ESR_FRM_ERR.

//! @brief Get value of FLEXCAN_ESR_FRM_ERR from a register value.
#define BG_FLEXCAN_ESR_FRM_ERR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_ESR_FRM_ERR) >> BP_FLEXCAN_ESR_FRM_ERR)


/* --- Register HW_FLEXCAN_ESR, field CRC_ERR[12] (RO)
 *
 * This bit indicates that a CRC Error has been detected by the receiver node, that is, the
 * calculated CRC is different from the received. {flexcan2_ipi_slv_flex_reg_esr_error}
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_reg_esr_error}
 * 1 - A CRC error occurred since last read of this register. {flexcan2_ipi_slv_flex_reg_esr_error}
 */

#define BP_FLEXCAN_ESR_CRC_ERR      (12)      //!< Bit position for FLEXCAN_ESR_CRC_ERR.
#define BM_FLEXCAN_ESR_CRC_ERR      (0x00001000)  //!< Bit mask for FLEXCAN_ESR_CRC_ERR.

//! @brief Get value of FLEXCAN_ESR_CRC_ERR from a register value.
#define BG_FLEXCAN_ESR_CRC_ERR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_ESR_CRC_ERR) >> BP_FLEXCAN_ESR_CRC_ERR)


/* --- Register HW_FLEXCAN_ESR, field ACK_ERR[13] (RO)
 *
 * This bit indicates that an Acknowledge Error has been detected by the transmitter node, that is,
 * a dominant bit has not been detected during the ACK SLOT {flexcan2_ipi_slv_flex_reg_esr_error} .
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_reg_esr_error}
 * 1 - An ACK error occurred since last read of this register {flexcan2_ipi_slv_flex_reg_esr_error}
 */

#define BP_FLEXCAN_ESR_ACK_ERR      (13)      //!< Bit position for FLEXCAN_ESR_ACK_ERR.
#define BM_FLEXCAN_ESR_ACK_ERR      (0x00002000)  //!< Bit mask for FLEXCAN_ESR_ACK_ERR.

//! @brief Get value of FLEXCAN_ESR_ACK_ERR from a register value.
#define BG_FLEXCAN_ESR_ACK_ERR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_ESR_ACK_ERR) >> BP_FLEXCAN_ESR_ACK_ERR)


/* --- Register HW_FLEXCAN_ESR, field BIT0_ERR[14] (RO)
 *
 * This bit indicates when an inconsistency occurs between the transmitted and the received bit in a
 * message. {flexcan2_ipi_slv_flex_reg_esr_error}
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_reg_esr_error}
 * 1 - At least one bit sent as dominant is received as recessive {flexcan2_ipi_slv_flex_reg_esr_error}
 */

#define BP_FLEXCAN_ESR_BIT0_ERR      (14)      //!< Bit position for FLEXCAN_ESR_BIT0_ERR.
#define BM_FLEXCAN_ESR_BIT0_ERR      (0x00004000)  //!< Bit mask for FLEXCAN_ESR_BIT0_ERR.

//! @brief Get value of FLEXCAN_ESR_BIT0_ERR from a register value.
#define BG_FLEXCAN_ESR_BIT0_ERR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_ESR_BIT0_ERR) >> BP_FLEXCAN_ESR_BIT0_ERR)


/* --- Register HW_FLEXCAN_ESR, field BIT1_ERR[15] (RO)
 *
 * This bit indicates when an inconsistency occurs between the transmitted and the received bit in a
 * message {flexcan2_ipi_slv_flex_reg_esr_error} . This bit is not set by a transmitter in case of
 * arbitration field or ACK slot, or in case of a node sending a passive error flag that detects
 * dominant bits. {flexcan2_ipi_slv_flex_reg_esr_error}
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_reg_esr_error}
 * 1 - At least one bit sent as recessive is received as dominant {flexcan2_ipi_slv_flex_reg_esr_error}
 */

#define BP_FLEXCAN_ESR_BIT1_ERR      (15)      //!< Bit position for FLEXCAN_ESR_BIT1_ERR.
#define BM_FLEXCAN_ESR_BIT1_ERR      (0x00008000)  //!< Bit mask for FLEXCAN_ESR_BIT1_ERR.

//! @brief Get value of FLEXCAN_ESR_BIT1_ERR from a register value.
#define BG_FLEXCAN_ESR_BIT1_ERR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_ESR_BIT1_ERR) >> BP_FLEXCAN_ESR_BIT1_ERR)


/* --- Register HW_FLEXCAN_ESR, field RWRN_INT[16] (RW)
 *
 * If the WRN_EN bit in MCR is asserted, the RWRN_INT bit is set when the RX_WRN flag transitions
 * from 0 to 1, meaning that the Rx error counters reached 96. If the corresponding mask bit in the
 * Control Register (RWRN_MSK) is set, an interrupt is generated to the ARM. This bit is cleared by
 * writing it to 1. Writing 0 has no effect.
 *
 * Values:
 * 0 - No such occurrence
 * 1 - The Rx error counter transition from < 96 to ℜ≥ 96
 */

#define BP_FLEXCAN_ESR_RWRN_INT      (16)      //!< Bit position for FLEXCAN_ESR_RWRN_INT.
#define BM_FLEXCAN_ESR_RWRN_INT      (0x00010000)  //!< Bit mask for FLEXCAN_ESR_RWRN_INT.

//! @brief Get value of FLEXCAN_ESR_RWRN_INT from a register value.
#define BG_FLEXCAN_ESR_RWRN_INT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_ESR_RWRN_INT) >> BP_FLEXCAN_ESR_RWRN_INT)

//! @brief Format value for bitfield FLEXCAN_ESR_RWRN_INT.
#define BF_FLEXCAN_ESR_RWRN_INT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_ESR_RWRN_INT) & BM_FLEXCAN_ESR_RWRN_INT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RWRN_INT field to a new value.
#define BW_FLEXCAN_ESR_RWRN_INT(x, v)   (HW_FLEXCAN_ESR_WR(x, (HW_FLEXCAN_ESR_RD(x) & ~BM_FLEXCAN_ESR_RWRN_INT) | BF_FLEXCAN_ESR_RWRN_INT(v)))
#endif


/* --- Register HW_FLEXCAN_ESR, field TWRN_INT[17] (RW)
 *
 * If the WRN_EN bit in MCR is asserted, the TWRN_INT bit is set when the TX_WRN flag transitions
 * from 0 to 1, meaning that the Tx error counter reached 96. If the corresponding mask bit in the
 * Control Register (TWRN_MSK) is set, an interrupt is generated to the ARM. This bit is cleared by
 * writing it to 1. Writing 0 has no effect.
 *
 * Values:
 * 0 - No such occurrence
 * 1 - The Tx error counter transition from < 96 to ℜ≥ 96
 */

#define BP_FLEXCAN_ESR_TWRN_INT      (17)      //!< Bit position for FLEXCAN_ESR_TWRN_INT.
#define BM_FLEXCAN_ESR_TWRN_INT      (0x00020000)  //!< Bit mask for FLEXCAN_ESR_TWRN_INT.

//! @brief Get value of FLEXCAN_ESR_TWRN_INT from a register value.
#define BG_FLEXCAN_ESR_TWRN_INT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_ESR_TWRN_INT) >> BP_FLEXCAN_ESR_TWRN_INT)

//! @brief Format value for bitfield FLEXCAN_ESR_TWRN_INT.
#define BF_FLEXCAN_ESR_TWRN_INT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_ESR_TWRN_INT) & BM_FLEXCAN_ESR_TWRN_INT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TWRN_INT field to a new value.
#define BW_FLEXCAN_ESR_TWRN_INT(x, v)   (HW_FLEXCAN_ESR_WR(x, (HW_FLEXCAN_ESR_RD(x) & ~BM_FLEXCAN_ESR_TWRN_INT) | BF_FLEXCAN_ESR_TWRN_INT(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_FLEXCAN_IMASK2 - Interrupt Masks 2 Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_IMASK2 - Interrupt Masks 2 Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register allows any number of a range of 32 Message Buffer Interrupts to be enabled or
 * disabled {flexcan2_ipi_slv_flex_mbuffer_int} . It contains one interrupt mask bit per buffer
 * enabling the ARM to determine which buffer generates an interrupt after a successful transmission
 * or reception {flexcan2_ipi_slv_flex_mbuffer_int} (that is, when the corresponding IFLAG2 bit is
 * set) {flexcan2_ipi_slv_flex_mbuffer_int} .  Setting or clearing a bit in the IMASK2 Register can
 * assert or negate an interrupt request if the corresponding IFLAG2 bit is set.
 * {flexcan2_ipi_slv_flex_mbuffer_int}
 */
typedef union _hw_flexcan_imask2
{
    reg32_t U;
    struct _hw_flexcan_imask2_bitfields
    {
        unsigned BUF63M : 32; //!< [31:0] Each bit enables or disables the respective FLEXCAN Message Buffer (MB32 to MB63) Interrupt. {flexcan2_ipi_slv_flex_mbuffer_int}
    } B;
} hw_flexcan_imask2_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_IMASK2 register
 */
#define HW_FLEXCAN_IMASK2_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_IMASK2(x)           (*(volatile hw_flexcan_imask2_t *) HW_FLEXCAN_IMASK2_ADDR(x))
#define HW_FLEXCAN_IMASK2_RD(x)        (HW_FLEXCAN_IMASK2(x).U)
#define HW_FLEXCAN_IMASK2_WR(x, v)     (HW_FLEXCAN_IMASK2(x).U = (v))
#define HW_FLEXCAN_IMASK2_SET(x, v)    (HW_FLEXCAN_IMASK2_WR(x, HW_FLEXCAN_IMASK2_RD(x) |  (v)))
#define HW_FLEXCAN_IMASK2_CLR(x, v)    (HW_FLEXCAN_IMASK2_WR(x, HW_FLEXCAN_IMASK2_RD(x) & ~(v)))
#define HW_FLEXCAN_IMASK2_TOG(x, v)    (HW_FLEXCAN_IMASK2_WR(x, HW_FLEXCAN_IMASK2_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_IMASK2 bitfields
 */

/* --- Register HW_FLEXCAN_IMASK2, field BUF63M[31:0] (RW)
 *
 * Each bit enables or disables the respective FLEXCAN Message Buffer (MB32 to MB63) Interrupt.
 * {flexcan2_ipi_slv_flex_mbuffer_int}
 *
 * Values:
 * 0 - The corresponding buffer Interrupt is disabled {flexcan2_ipi_slv_flex_mbuffer_int}
 * 1 - The corresponding buffer Interrupt is enabled {flexcan2_ipi_slv_flex_mbuffer_int}
 */

#define BP_FLEXCAN_IMASK2_BUF63M      (0)      //!< Bit position for FLEXCAN_IMASK2_BUF63M.
#define BM_FLEXCAN_IMASK2_BUF63M      (0xffffffff)  //!< Bit mask for FLEXCAN_IMASK2_BUF63M.

//! @brief Get value of FLEXCAN_IMASK2_BUF63M from a register value.
#define BG_FLEXCAN_IMASK2_BUF63M(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_IMASK2_BUF63M) >> BP_FLEXCAN_IMASK2_BUF63M)

//! @brief Format value for bitfield FLEXCAN_IMASK2_BUF63M.
#define BF_FLEXCAN_IMASK2_BUF63M(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_IMASK2_BUF63M) & BM_FLEXCAN_IMASK2_BUF63M)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BUF63M field to a new value.
#define BW_FLEXCAN_IMASK2_BUF63M(x, v)   (HW_FLEXCAN_IMASK2_WR(x, (HW_FLEXCAN_IMASK2_RD(x) & ~BM_FLEXCAN_IMASK2_BUF63M) | BF_FLEXCAN_IMASK2_BUF63M(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_FLEXCAN_IMASK1 - Interrupt Masks 1 Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_IMASK1 - Interrupt Masks 1 Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register allows the enabling or disabling of any number of a range of 32 Message Buffer
 * Interrupts {flexcan2_ipi_slv_flex_mbuffer_int} . It contains one interrupt mask bit per buffer
 * enabling the ARM to determine which buffer generates an interrupt after a successful transmission
 * or reception {flexcan2_ipi_slv_flex_mbuffer_int} (that is, when the corresponding IFLAG1 bit is
 * set). {flexcan2_ipi_slv_flex_mbuffer_int}  Setting or clearing a bit in the IMASK1 Register can
 * assert or negate an interrupt request if the corresponding IFLAG1 bit is set.
 * {flexcan2_ipi_slv_flex_mbuffer_int}
 */
typedef union _hw_flexcan_imask1
{
    reg32_t U;
    struct _hw_flexcan_imask1_bitfields
    {
        unsigned BUF31M_BUF0M : 32; //!< [31:0] Each bit enables or disables the respective FLEXCAN Message Buffer (MB0 to MB31) Interrupt. {flexcan2_ipi_slv_flex_mbuffer_int}
    } B;
} hw_flexcan_imask1_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_IMASK1 register
 */
#define HW_FLEXCAN_IMASK1_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_IMASK1(x)           (*(volatile hw_flexcan_imask1_t *) HW_FLEXCAN_IMASK1_ADDR(x))
#define HW_FLEXCAN_IMASK1_RD(x)        (HW_FLEXCAN_IMASK1(x).U)
#define HW_FLEXCAN_IMASK1_WR(x, v)     (HW_FLEXCAN_IMASK1(x).U = (v))
#define HW_FLEXCAN_IMASK1_SET(x, v)    (HW_FLEXCAN_IMASK1_WR(x, HW_FLEXCAN_IMASK1_RD(x) |  (v)))
#define HW_FLEXCAN_IMASK1_CLR(x, v)    (HW_FLEXCAN_IMASK1_WR(x, HW_FLEXCAN_IMASK1_RD(x) & ~(v)))
#define HW_FLEXCAN_IMASK1_TOG(x, v)    (HW_FLEXCAN_IMASK1_WR(x, HW_FLEXCAN_IMASK1_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_IMASK1 bitfields
 */

/* --- Register HW_FLEXCAN_IMASK1, field BUF31M_BUF0M[31:0] (RW)
 *
 * Each bit enables or disables the respective FLEXCAN Message Buffer (MB0 to MB31) Interrupt.
 * {flexcan2_ipi_slv_flex_mbuffer_int}
 *
 * Values:
 * 0 - The corresponding buffer Interrupt is disabled {flexcan2_ipi_slv_flex_mbuffer_int}
 * 1 - The corresponding buffer Interrupt is enabled {flexcan2_ipi_slv_flex_mbuffer_int}
 */

#define BP_FLEXCAN_IMASK1_BUF31M_BUF0M      (0)      //!< Bit position for FLEXCAN_IMASK1_BUF31M_BUF0M.
#define BM_FLEXCAN_IMASK1_BUF31M_BUF0M      (0xffffffff)  //!< Bit mask for FLEXCAN_IMASK1_BUF31M_BUF0M.

//! @brief Get value of FLEXCAN_IMASK1_BUF31M_BUF0M from a register value.
#define BG_FLEXCAN_IMASK1_BUF31M_BUF0M(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_IMASK1_BUF31M_BUF0M) >> BP_FLEXCAN_IMASK1_BUF31M_BUF0M)

//! @brief Format value for bitfield FLEXCAN_IMASK1_BUF31M_BUF0M.
#define BF_FLEXCAN_IMASK1_BUF31M_BUF0M(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_IMASK1_BUF31M_BUF0M) & BM_FLEXCAN_IMASK1_BUF31M_BUF0M)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BUF31M_BUF0M field to a new value.
#define BW_FLEXCAN_IMASK1_BUF31M_BUF0M(x, v)   (HW_FLEXCAN_IMASK1_WR(x, (HW_FLEXCAN_IMASK1_RD(x) & ~BM_FLEXCAN_IMASK1_BUF31M_BUF0M) | BF_FLEXCAN_IMASK1_BUF31M_BUF0M(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_FLEXCAN_IFLAG2 - Interrupt Flags 2 Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_IFLAG2 - Interrupt Flags 2 Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register defines the flags for 32 Message Buffer interrupts
 * {flexcan2_ipi_slv_flex_mbuffer_int} . It contains one interrupt flag bit per buffer
 * {flexcan2_ipi_slv_flex_mbuffer_int} . Each successful transmission or reception sets the
 * corresponding IFLAG2 bit {flexcan2_ipi_slv_flex_mbuffer_int} . If the corresponding IMASK2 bit is
 * set, an interrupt will be generated. {flexcan2_ipi_slv_flex_mbuffer_int} The interrupt flag must
 * be cleared by writing it to 1 {flexcan2_ipi_slv_flex_mbuffer_int} . Writing 0 has no effect.
 * {flexcan2_ipi_slv_flex_mbuffer_int}  When the AEN bit in the MCR is set (Abort enabled), while
 * the IFLAG2 bit is set for a message buffer configured as Tx, the writing access done by ARM into
 * the corresponding message buffer will be blocked.
 */
typedef union _hw_flexcan_iflag2
{
    reg32_t U;
    struct _hw_flexcan_iflag2_bitfields
    {
        unsigned BUF63I_BUF32I : 32; //!< [31:0] Each bit flags the respective FLEXCAN Message Buffer (MB32 to MB63) interrupt. {flexcan2_ipi_slv_flex_mbuffer_int}
    } B;
} hw_flexcan_iflag2_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_IFLAG2 register
 */
#define HW_FLEXCAN_IFLAG2_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_IFLAG2(x)           (*(volatile hw_flexcan_iflag2_t *) HW_FLEXCAN_IFLAG2_ADDR(x))
#define HW_FLEXCAN_IFLAG2_RD(x)        (HW_FLEXCAN_IFLAG2(x).U)
#define HW_FLEXCAN_IFLAG2_WR(x, v)     (HW_FLEXCAN_IFLAG2(x).U = (v))
#define HW_FLEXCAN_IFLAG2_SET(x, v)    (HW_FLEXCAN_IFLAG2_WR(x, HW_FLEXCAN_IFLAG2_RD(x) |  (v)))
#define HW_FLEXCAN_IFLAG2_CLR(x, v)    (HW_FLEXCAN_IFLAG2_WR(x, HW_FLEXCAN_IFLAG2_RD(x) & ~(v)))
#define HW_FLEXCAN_IFLAG2_TOG(x, v)    (HW_FLEXCAN_IFLAG2_WR(x, HW_FLEXCAN_IFLAG2_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_IFLAG2 bitfields
 */

/* --- Register HW_FLEXCAN_IFLAG2, field BUF63I_BUF32I[31:0] (RW)
 *
 * Each bit flags the respective FLEXCAN Message Buffer (MB32 to MB63) interrupt.
 * {flexcan2_ipi_slv_flex_mbuffer_int}
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_mbuffer_int}
 * 1 - The corresponding buffer has successfully completed transmission or reception
 *     {flexcan2_ipi_slv_flex_mbuffer_int}
 */

#define BP_FLEXCAN_IFLAG2_BUF63I_BUF32I      (0)      //!< Bit position for FLEXCAN_IFLAG2_BUF63I_BUF32I.
#define BM_FLEXCAN_IFLAG2_BUF63I_BUF32I      (0xffffffff)  //!< Bit mask for FLEXCAN_IFLAG2_BUF63I_BUF32I.

//! @brief Get value of FLEXCAN_IFLAG2_BUF63I_BUF32I from a register value.
#define BG_FLEXCAN_IFLAG2_BUF63I_BUF32I(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_IFLAG2_BUF63I_BUF32I) >> BP_FLEXCAN_IFLAG2_BUF63I_BUF32I)

//! @brief Format value for bitfield FLEXCAN_IFLAG2_BUF63I_BUF32I.
#define BF_FLEXCAN_IFLAG2_BUF63I_BUF32I(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_IFLAG2_BUF63I_BUF32I) & BM_FLEXCAN_IFLAG2_BUF63I_BUF32I)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BUF63I_BUF32I field to a new value.
#define BW_FLEXCAN_IFLAG2_BUF63I_BUF32I(x, v)   (HW_FLEXCAN_IFLAG2_WR(x, (HW_FLEXCAN_IFLAG2_RD(x) & ~BM_FLEXCAN_IFLAG2_BUF63I_BUF32I) | BF_FLEXCAN_IFLAG2_BUF63I_BUF32I(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_FLEXCAN_IFLAG1 - Interrupt Flags 1 Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_IFLAG1 - Interrupt Flags 1 Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register defines the flags for 32 Message Buffer interrupts
 * {flexcan2_ipi_slv_flex_mbuffer_int} and FIFO interrupts. It contains one interrupt flag bit per
 * buffer {flexcan2_ipi_slv_flex_mbuffer_int} . Each successful transmission or reception sets the
 * corresponding IFLAG1 bit {flexcan2_ipi_slv_flex_mbuffer_int} . If the corresponding IMASK1 bit is
 * set, an interrupt will be generated. {flexcan2_ipi_slv_flex_mbuffer_int} The Interrupt flag must
 * be cleared by writing it to 1 {flexcan2_ipi_slv_flex_mbuffer_int} . Writing 0 has no effect.
 * {flexcan2_ipi_slv_flex_mbuffer_int}  When the AEN bit in the MCR is set (Abort enabled), while
 * the IFLAG1 bit is set for a message buffer configured as Tx, the writing access done by ARM into
 * the corresponding message buffer will be blocked.  When the FEN bit in the MCR is set (FIFO
 * enabled), the function of the 8 least significant interrupt flags (BUF7I - BUF0I) is changed to
 * support the FIFO operation. BUF7I, BUF6I and BUF5I indicate operating conditions of the FIFO,
 * while BUF4I to BUF0I are not used.
 */
typedef union _hw_flexcan_iflag1
{
    reg32_t U;
    struct _hw_flexcan_iflag1_bitfields
    {
        unsigned BUF4I_BUF0I : 5; //!< [4:0] If the FIFO is not enabled, these bits flag the interrupts for MB0 to MB4. {flexcan2_ipi_slv_flex_mbuffer_int} If the FIFO is enabled, these flags are not used and must be considered as reserved locations.
        unsigned BUF5I : 1; //!< [5] If the FIFO is not enabled, this bit flags the interrupt for MB5. {flexcan2_ipi_slv_flex_mbuffer_int} If the FIFO is enabled, this flag indicates that at least one frame is available to be read from the FIFO.
        unsigned BUF6I : 1; //!< [6] If the FIFO is not enabled, this bit flags the interrupt for MB6. {flexcan2_ipi_slv_flex_mbuffer_int} If the FIFO is enabled, this flag indicates that 4 out of 6 buffers of the FIFO are already occupied (FIFO almost full).
        unsigned BUF7I : 1; //!< [7] If the FIFO is not enabled, this bit flags the interrupt for MB7. {flexcan2_ipi_slv_flex_mbuffer_int} If the FIFO is enabled, this flag indicates an overflow condition in the FIFO (frame lost because FIFO is full).
        unsigned BUF31I_BUF8I : 24; //!< [31:8] Each bit flags the respective FLEXCAN Message Buffer (MB8 to MB31) interrupt. {flexcan2_ipi_slv_flex_mbuffer_int}
    } B;
} hw_flexcan_iflag1_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_IFLAG1 register
 */
#define HW_FLEXCAN_IFLAG1_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_IFLAG1(x)           (*(volatile hw_flexcan_iflag1_t *) HW_FLEXCAN_IFLAG1_ADDR(x))
#define HW_FLEXCAN_IFLAG1_RD(x)        (HW_FLEXCAN_IFLAG1(x).U)
#define HW_FLEXCAN_IFLAG1_WR(x, v)     (HW_FLEXCAN_IFLAG1(x).U = (v))
#define HW_FLEXCAN_IFLAG1_SET(x, v)    (HW_FLEXCAN_IFLAG1_WR(x, HW_FLEXCAN_IFLAG1_RD(x) |  (v)))
#define HW_FLEXCAN_IFLAG1_CLR(x, v)    (HW_FLEXCAN_IFLAG1_WR(x, HW_FLEXCAN_IFLAG1_RD(x) & ~(v)))
#define HW_FLEXCAN_IFLAG1_TOG(x, v)    (HW_FLEXCAN_IFLAG1_WR(x, HW_FLEXCAN_IFLAG1_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_IFLAG1 bitfields
 */

/* --- Register HW_FLEXCAN_IFLAG1, field BUF4I_BUF0I[4:0] (RW)
 *
 * If the FIFO is not enabled, these bits flag the interrupts for MB0 to MB4.
 * {flexcan2_ipi_slv_flex_mbuffer_int} If the FIFO is enabled, these flags are not used and must be
 * considered as reserved locations.
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_mbuffer_int}
 * 1 - Corresponding message buffer completed transmission/reception
 */

#define BP_FLEXCAN_IFLAG1_BUF4I_BUF0I      (0)      //!< Bit position for FLEXCAN_IFLAG1_BUF4I_BUF0I.
#define BM_FLEXCAN_IFLAG1_BUF4I_BUF0I      (0x0000001f)  //!< Bit mask for FLEXCAN_IFLAG1_BUF4I_BUF0I.

//! @brief Get value of FLEXCAN_IFLAG1_BUF4I_BUF0I from a register value.
#define BG_FLEXCAN_IFLAG1_BUF4I_BUF0I(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_IFLAG1_BUF4I_BUF0I) >> BP_FLEXCAN_IFLAG1_BUF4I_BUF0I)

//! @brief Format value for bitfield FLEXCAN_IFLAG1_BUF4I_BUF0I.
#define BF_FLEXCAN_IFLAG1_BUF4I_BUF0I(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_IFLAG1_BUF4I_BUF0I) & BM_FLEXCAN_IFLAG1_BUF4I_BUF0I)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BUF4I_BUF0I field to a new value.
#define BW_FLEXCAN_IFLAG1_BUF4I_BUF0I(x, v)   (HW_FLEXCAN_IFLAG1_WR(x, (HW_FLEXCAN_IFLAG1_RD(x) & ~BM_FLEXCAN_IFLAG1_BUF4I_BUF0I) | BF_FLEXCAN_IFLAG1_BUF4I_BUF0I(v)))
#endif


/* --- Register HW_FLEXCAN_IFLAG1, field BUF5I[5] (RW)
 *
 * If the FIFO is not enabled, this bit flags the interrupt for MB5.
 * {flexcan2_ipi_slv_flex_mbuffer_int} If the FIFO is enabled, this flag indicates that at least one
 * frame is available to be read from the FIFO.
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_mbuffer_int}
 * 1 - MB5 completed transmission/reception or frames available in the FIFO
 */

#define BP_FLEXCAN_IFLAG1_BUF5I      (5)      //!< Bit position for FLEXCAN_IFLAG1_BUF5I.
#define BM_FLEXCAN_IFLAG1_BUF5I      (0x00000020)  //!< Bit mask for FLEXCAN_IFLAG1_BUF5I.

//! @brief Get value of FLEXCAN_IFLAG1_BUF5I from a register value.
#define BG_FLEXCAN_IFLAG1_BUF5I(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_IFLAG1_BUF5I) >> BP_FLEXCAN_IFLAG1_BUF5I)

//! @brief Format value for bitfield FLEXCAN_IFLAG1_BUF5I.
#define BF_FLEXCAN_IFLAG1_BUF5I(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_IFLAG1_BUF5I) & BM_FLEXCAN_IFLAG1_BUF5I)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BUF5I field to a new value.
#define BW_FLEXCAN_IFLAG1_BUF5I(x, v)   (HW_FLEXCAN_IFLAG1_WR(x, (HW_FLEXCAN_IFLAG1_RD(x) & ~BM_FLEXCAN_IFLAG1_BUF5I) | BF_FLEXCAN_IFLAG1_BUF5I(v)))
#endif


/* --- Register HW_FLEXCAN_IFLAG1, field BUF6I[6] (RW)
 *
 * If the FIFO is not enabled, this bit flags the interrupt for MB6.
 * {flexcan2_ipi_slv_flex_mbuffer_int} If the FIFO is enabled, this flag indicates that 4 out of 6
 * buffers of the FIFO are already occupied (FIFO almost full).
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_mbuffer_int}
 * 1 - MB6 completed transmission/reception or FIFO almost full
 */

#define BP_FLEXCAN_IFLAG1_BUF6I      (6)      //!< Bit position for FLEXCAN_IFLAG1_BUF6I.
#define BM_FLEXCAN_IFLAG1_BUF6I      (0x00000040)  //!< Bit mask for FLEXCAN_IFLAG1_BUF6I.

//! @brief Get value of FLEXCAN_IFLAG1_BUF6I from a register value.
#define BG_FLEXCAN_IFLAG1_BUF6I(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_IFLAG1_BUF6I) >> BP_FLEXCAN_IFLAG1_BUF6I)

//! @brief Format value for bitfield FLEXCAN_IFLAG1_BUF6I.
#define BF_FLEXCAN_IFLAG1_BUF6I(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_IFLAG1_BUF6I) & BM_FLEXCAN_IFLAG1_BUF6I)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BUF6I field to a new value.
#define BW_FLEXCAN_IFLAG1_BUF6I(x, v)   (HW_FLEXCAN_IFLAG1_WR(x, (HW_FLEXCAN_IFLAG1_RD(x) & ~BM_FLEXCAN_IFLAG1_BUF6I) | BF_FLEXCAN_IFLAG1_BUF6I(v)))
#endif


/* --- Register HW_FLEXCAN_IFLAG1, field BUF7I[7] (RW)
 *
 * If the FIFO is not enabled, this bit flags the interrupt for MB7.
 * {flexcan2_ipi_slv_flex_mbuffer_int} If the FIFO is enabled, this flag indicates an overflow
 * condition in the FIFO (frame lost because FIFO is full).
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_mbuffer_int}
 * 1 - MB7 completed transmission/reception or FIFO overflow {flexcan2_ipi_slv_flex_mbuffer_int}
 */

#define BP_FLEXCAN_IFLAG1_BUF7I      (7)      //!< Bit position for FLEXCAN_IFLAG1_BUF7I.
#define BM_FLEXCAN_IFLAG1_BUF7I      (0x00000080)  //!< Bit mask for FLEXCAN_IFLAG1_BUF7I.

//! @brief Get value of FLEXCAN_IFLAG1_BUF7I from a register value.
#define BG_FLEXCAN_IFLAG1_BUF7I(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_IFLAG1_BUF7I) >> BP_FLEXCAN_IFLAG1_BUF7I)

//! @brief Format value for bitfield FLEXCAN_IFLAG1_BUF7I.
#define BF_FLEXCAN_IFLAG1_BUF7I(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_IFLAG1_BUF7I) & BM_FLEXCAN_IFLAG1_BUF7I)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BUF7I field to a new value.
#define BW_FLEXCAN_IFLAG1_BUF7I(x, v)   (HW_FLEXCAN_IFLAG1_WR(x, (HW_FLEXCAN_IFLAG1_RD(x) & ~BM_FLEXCAN_IFLAG1_BUF7I) | BF_FLEXCAN_IFLAG1_BUF7I(v)))
#endif


/* --- Register HW_FLEXCAN_IFLAG1, field BUF31I_BUF8I[31:8] (RW)
 *
 * Each bit flags the respective FLEXCAN Message Buffer (MB8 to MB31) interrupt.
 * {flexcan2_ipi_slv_flex_mbuffer_int}
 *
 * Values:
 * 0 - No such occurrence {flexcan2_ipi_slv_flex_mbuffer_int}
 * 1 - The corresponding message buffer has successfully completed transmission or reception
 *     {flexcan2_ipi_slv_flex_mbuffer_int}
 */

#define BP_FLEXCAN_IFLAG1_BUF31I_BUF8I      (8)      //!< Bit position for FLEXCAN_IFLAG1_BUF31I_BUF8I.
#define BM_FLEXCAN_IFLAG1_BUF31I_BUF8I      (0xffffff00)  //!< Bit mask for FLEXCAN_IFLAG1_BUF31I_BUF8I.

//! @brief Get value of FLEXCAN_IFLAG1_BUF31I_BUF8I from a register value.
#define BG_FLEXCAN_IFLAG1_BUF31I_BUF8I(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_IFLAG1_BUF31I_BUF8I) >> BP_FLEXCAN_IFLAG1_BUF31I_BUF8I)

//! @brief Format value for bitfield FLEXCAN_IFLAG1_BUF31I_BUF8I.
#define BF_FLEXCAN_IFLAG1_BUF31I_BUF8I(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_IFLAG1_BUF31I_BUF8I) & BM_FLEXCAN_IFLAG1_BUF31I_BUF8I)

#ifndef __LANGUAGE_ASM__
//! @brief Set the BUF31I_BUF8I field to a new value.
#define BW_FLEXCAN_IFLAG1_BUF31I_BUF8I(x, v)   (HW_FLEXCAN_IFLAG1_WR(x, (HW_FLEXCAN_IFLAG1_RD(x) & ~BM_FLEXCAN_IFLAG1_BUF31I_BUF8I) | BF_FLEXCAN_IFLAG1_BUF31I_BUF8I(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_FLEXCAN_GFWR - Glitch Filter Width Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_GFWR - Glitch Filter Width Register (RW)
 *
 * Reset value: 0x0000007f
 *
 * The Glitch Filter just takes effects when FLEXCAN enters the STOP mode.
 */
typedef union _hw_flexcan_gfwr
{
    reg32_t U;
    struct _hw_flexcan_gfwr_bitfields
    {
        unsigned GFWR : 8; //!< [7:0] It determines the Glitch Filter Width. The width will be divided from Oscillator clock by GFWR values. By default, it is 5.33us when the oscillator is 24MHz.
        unsigned RESERVED0 : 24; //!< [31:8] Reserved
    } B;
} hw_flexcan_gfwr_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_GFWR register
 */
#define HW_FLEXCAN_GFWR_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_GFWR(x)           (*(volatile hw_flexcan_gfwr_t *) HW_FLEXCAN_GFWR_ADDR(x))
#define HW_FLEXCAN_GFWR_RD(x)        (HW_FLEXCAN_GFWR(x).U)
#define HW_FLEXCAN_GFWR_WR(x, v)     (HW_FLEXCAN_GFWR(x).U = (v))
#define HW_FLEXCAN_GFWR_SET(x, v)    (HW_FLEXCAN_GFWR_WR(x, HW_FLEXCAN_GFWR_RD(x) |  (v)))
#define HW_FLEXCAN_GFWR_CLR(x, v)    (HW_FLEXCAN_GFWR_WR(x, HW_FLEXCAN_GFWR_RD(x) & ~(v)))
#define HW_FLEXCAN_GFWR_TOG(x, v)    (HW_FLEXCAN_GFWR_WR(x, HW_FLEXCAN_GFWR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_GFWR bitfields
 */

/* --- Register HW_FLEXCAN_GFWR, field GFWR[7:0] (RW)
 *
 * It determines the Glitch Filter Width. The width will be divided from Oscillator clock by GFWR
 * values. By default, it is 5.33us when the oscillator is 24MHz.
 */

#define BP_FLEXCAN_GFWR_GFWR      (0)      //!< Bit position for FLEXCAN_GFWR_GFWR.
#define BM_FLEXCAN_GFWR_GFWR      (0x000000ff)  //!< Bit mask for FLEXCAN_GFWR_GFWR.

//! @brief Get value of FLEXCAN_GFWR_GFWR from a register value.
#define BG_FLEXCAN_GFWR_GFWR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_GFWR_GFWR) >> BP_FLEXCAN_GFWR_GFWR)

//! @brief Format value for bitfield FLEXCAN_GFWR_GFWR.
#define BF_FLEXCAN_GFWR_GFWR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_GFWR_GFWR) & BM_FLEXCAN_GFWR_GFWR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the GFWR field to a new value.
#define BW_FLEXCAN_GFWR_GFWR(x, v)   (HW_FLEXCAN_GFWR_WR(x, (HW_FLEXCAN_GFWR_RD(x) & ~BM_FLEXCAN_GFWR_GFWR) | BF_FLEXCAN_GFWR_GFWR(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_FLEXCAN_RX0IMR - Rx Individual Mask Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_RX0IMR - Rx Individual Mask Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * These registers are used as acceptance masks for ID filtering in Rx message buffers
 * {flexcan2_ipi_slv_flex_ram_rximask} and the FIFO. If the FIFO is not enabled, one mask register
 * is provided for each available Message Buffer, providing ID masking capability on a per Message
 * Buffer basis {flexcan2_ipi_slv_flex_ram_rximask} . When the FIFO is enabled (FEN bit in MCR is
 * set), the first 8 Mask Registers apply to the 8 elements of the FIFO filter table (on a one-to-
 * one correspondence) while the rest of the registers apply to the regular message buffers starting
 * from MB8.  The Individual Rx Mask Registers are implemented in RAM so they are not affected by
 * reset and must be explicitly initialized prior to any reception {statement} . Furthermore, they
 * can only be accessed by the ARM while the block is in Freeze Mode
 * {flexcan2_ipi_slv_flex_ram_rximask_access} . Out of Freeze Mode, write accesses are blocked and
 * read accesses will return all zeros {flexcan2_ipi_slv_flex_ram_rximask_access} . Furthermore, if
 * the BCC bit in the MCR Register is negated, any read or write operation to these registers
 * results in access error {flexcan2_ipi_slv_flex_ram_rximask_access} .
 */
typedef union _hw_flexcan_rx0imr
{
    reg32_t U;
    struct _hw_flexcan_rx0imr_bitfields
    {
        unsigned MI31_MI0 : 32; //!< [31:0] For normal Rx message buffers, the mask bits affect the ID filter programmed on the message buffer. For the Rx FIFO, the mask bits affect all bits programmed in the filter table (ID, IDE, RTR) {flexcan2_ipi_slv_flex_reg_rxmask} .
    } B;
} hw_flexcan_rx0imr_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_RX0IMR register
 */
#define HW_FLEXCAN_RX0IMR_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x880)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_RX0IMR(x)           (*(volatile hw_flexcan_rx0imr_t *) HW_FLEXCAN_RX0IMR_ADDR(x))
#define HW_FLEXCAN_RX0IMR_RD(x)        (HW_FLEXCAN_RX0IMR(x).U)
#define HW_FLEXCAN_RX0IMR_WR(x, v)     (HW_FLEXCAN_RX0IMR(x).U = (v))
#define HW_FLEXCAN_RX0IMR_SET(x, v)    (HW_FLEXCAN_RX0IMR_WR(x, HW_FLEXCAN_RX0IMR_RD(x) |  (v)))
#define HW_FLEXCAN_RX0IMR_CLR(x, v)    (HW_FLEXCAN_RX0IMR_WR(x, HW_FLEXCAN_RX0IMR_RD(x) & ~(v)))
#define HW_FLEXCAN_RX0IMR_TOG(x, v)    (HW_FLEXCAN_RX0IMR_WR(x, HW_FLEXCAN_RX0IMR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_RX0IMR bitfields
 */

/* --- Register HW_FLEXCAN_RX0IMR, field MI31_MI0[31:0] (RW)
 *
 * For normal Rx message buffers, the mask bits affect the ID filter programmed on the message
 * buffer. For the Rx FIFO, the mask bits affect all bits programmed in the filter table (ID, IDE,
 * RTR) {flexcan2_ipi_slv_flex_reg_rxmask} .
 *
 * Values:
 * 0 - the corresponding bit in the filter is dont care
 * 1 - The corresponding bit in the filter is checked against the one received
 */

#define BP_FLEXCAN_RX0IMR_MI31_MI0      (0)      //!< Bit position for FLEXCAN_RX0IMR_MI31_MI0.
#define BM_FLEXCAN_RX0IMR_MI31_MI0      (0xffffffff)  //!< Bit mask for FLEXCAN_RX0IMR_MI31_MI0.

//! @brief Get value of FLEXCAN_RX0IMR_MI31_MI0 from a register value.
#define BG_FLEXCAN_RX0IMR_MI31_MI0(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_RX0IMR_MI31_MI0) >> BP_FLEXCAN_RX0IMR_MI31_MI0)

//! @brief Format value for bitfield FLEXCAN_RX0IMR_MI31_MI0.
#define BF_FLEXCAN_RX0IMR_MI31_MI0(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_RX0IMR_MI31_MI0) & BM_FLEXCAN_RX0IMR_MI31_MI0)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MI31_MI0 field to a new value.
#define BW_FLEXCAN_RX0IMR_MI31_MI0(x, v)   (HW_FLEXCAN_RX0IMR_WR(x, (HW_FLEXCAN_RX0IMR_RD(x) & ~BM_FLEXCAN_RX0IMR_MI31_MI0) | BF_FLEXCAN_RX0IMR_MI31_MI0(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_FLEXCAN_RX63IMR - Rx Individual Mask Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FLEXCAN_RX63IMR - Rx Individual Mask Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * These registers are used as acceptance masks for ID filtering in Rx message buffers
 * {flexcan2_ipi_slv_flex_ram_rximask} and the FIFO. If the FIFO is not enabled, one mask register
 * is provided for each available Message Buffer, providing ID masking capability on a per Message
 * Buffer basis {flexcan2_ipi_slv_flex_ram_rximask} . When the FIFO is enabled (FEN bit in MCR is
 * set), the first 8 Mask Registers apply to the 8 elements of the FIFO filter table (on a one-to-
 * one correspondence) while the rest of the registers apply to the regular message buffers starting
 * from MB8.  The Individual Rx Mask Registers are implemented in RAM so they are not affected by
 * reset and must be explicitly initialized prior to any reception {statement} . Furthermore, they
 * can only be accessed by the ARM while the block is in Freeze Mode
 * {flexcan2_ipi_slv_flex_ram_rximask_access} . Out of Freeze Mode, write accesses are blocked and
 * read accesses will return all zeros {flexcan2_ipi_slv_flex_ram_rximask_access} . Furthermore, if
 * the BCC bit in the MCR Register is negated, any read or write operation to these registers
 * results in access error {flexcan2_ipi_slv_flex_ram_rximask_access} .
 */
typedef union _hw_flexcan_rx63imr
{
    reg32_t U;
    struct _hw_flexcan_rx63imr_bitfields
    {
        unsigned MI31_MI0 : 32; //!< [31:0] For normal Rx message buffers, the mask bits affect the ID filter programmed on the message buffer. For the Rx FIFO, the mask bits affect all bits programmed in the filter table (ID, IDE, RTR) {flexcan2_ipi_slv_flex_reg_rxmask} .
    } B;
} hw_flexcan_rx63imr_t;
#endif

/*
 * constants & macros for entire multi-block FLEXCAN_RX63IMR register
 */
#define HW_FLEXCAN_RX63IMR_ADDR(x)      (REGS_FLEXCAN_BASE(x) + 0x97c)

#ifndef __LANGUAGE_ASM__
#define HW_FLEXCAN_RX63IMR(x)           (*(volatile hw_flexcan_rx63imr_t *) HW_FLEXCAN_RX63IMR_ADDR(x))
#define HW_FLEXCAN_RX63IMR_RD(x)        (HW_FLEXCAN_RX63IMR(x).U)
#define HW_FLEXCAN_RX63IMR_WR(x, v)     (HW_FLEXCAN_RX63IMR(x).U = (v))
#define HW_FLEXCAN_RX63IMR_SET(x, v)    (HW_FLEXCAN_RX63IMR_WR(x, HW_FLEXCAN_RX63IMR_RD(x) |  (v)))
#define HW_FLEXCAN_RX63IMR_CLR(x, v)    (HW_FLEXCAN_RX63IMR_WR(x, HW_FLEXCAN_RX63IMR_RD(x) & ~(v)))
#define HW_FLEXCAN_RX63IMR_TOG(x, v)    (HW_FLEXCAN_RX63IMR_WR(x, HW_FLEXCAN_RX63IMR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual FLEXCAN_RX63IMR bitfields
 */

/* --- Register HW_FLEXCAN_RX63IMR, field MI31_MI0[31:0] (RW)
 *
 * For normal Rx message buffers, the mask bits affect the ID filter programmed on the message
 * buffer. For the Rx FIFO, the mask bits affect all bits programmed in the filter table (ID, IDE,
 * RTR) {flexcan2_ipi_slv_flex_reg_rxmask} .
 *
 * Values:
 * 0 - the corresponding bit in the filter is dont care
 * 1 - The corresponding bit in the filter is checked against the one received
 */

#define BP_FLEXCAN_RX63IMR_MI31_MI0      (0)      //!< Bit position for FLEXCAN_RX63IMR_MI31_MI0.
#define BM_FLEXCAN_RX63IMR_MI31_MI0      (0xffffffff)  //!< Bit mask for FLEXCAN_RX63IMR_MI31_MI0.

//! @brief Get value of FLEXCAN_RX63IMR_MI31_MI0 from a register value.
#define BG_FLEXCAN_RX63IMR_MI31_MI0(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_FLEXCAN_RX63IMR_MI31_MI0) >> BP_FLEXCAN_RX63IMR_MI31_MI0)

//! @brief Format value for bitfield FLEXCAN_RX63IMR_MI31_MI0.
#define BF_FLEXCAN_RX63IMR_MI31_MI0(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_FLEXCAN_RX63IMR_MI31_MI0) & BM_FLEXCAN_RX63IMR_MI31_MI0)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MI31_MI0 field to a new value.
#define BW_FLEXCAN_RX63IMR_MI31_MI0(x, v)   (HW_FLEXCAN_RX63IMR_WR(x, (HW_FLEXCAN_RX63IMR_RD(x) & ~BM_FLEXCAN_RX63IMR_MI31_MI0) | BF_FLEXCAN_RX63IMR_MI31_MI0(v)))
#endif



/*!
 * @brief All FLEXCAN module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_flexcan
{
    volatile hw_flexcan_mcr_t MCR; //!< Module Configuration Register
    volatile hw_flexcan_ctrl_t CTRL; //!< Control Register
    volatile hw_flexcan_timer_t TIMER; //!< Free Running Timer
    reg32_t _reserved0;
    volatile hw_flexcan_rxgmask_t RXGMASK; //!< Rx Global Mask
    volatile hw_flexcan_rx14mask_t RX14MASK; //!< Rx 14 Mask
    volatile hw_flexcan_rx15mask_t RX15MASK; //!< Rx 15 Mask
    volatile hw_flexcan_ecr_t ECR; //!< Error Counter Register
    volatile hw_flexcan_esr_t ESR; //!< Error and Status Register
    volatile hw_flexcan_imask2_t IMASK2; //!< Interrupt Masks 2 Register
    volatile hw_flexcan_imask1_t IMASK1; //!< Interrupt Masks 1 Register
    volatile hw_flexcan_iflag2_t IFLAG2; //!< Interrupt Flags 2 Register
    volatile hw_flexcan_iflag1_t IFLAG1; //!< Interrupt Flags 1 Register
    volatile hw_flexcan_gfwr_t GFWR; //!< Glitch Filter Width Register
    reg32_t _reserved1[530];
    volatile hw_flexcan_rx0imr_t RX0IMR; //!< Rx Individual Mask Registers
    reg32_t _reserved2[62];
    volatile hw_flexcan_rx63imr_t RX63IMR; //!< Rx Individual Mask Registers
} hw_flexcan_t;
#pragma pack()

//! @brief Macro to access all FLEXCAN registers.
//! @param x FLEXCAN instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_FLEXCAN(0)</code>.
#define HW_FLEXCAN(x)     (*(volatile hw_flexcan_t *) REGS_FLEXCAN_BASE(x))

#endif


#endif // __HW_FLEXCAN_REGISTERS_H__
