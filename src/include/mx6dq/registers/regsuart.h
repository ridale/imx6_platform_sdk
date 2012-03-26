/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_UART_REGISTERS_H__
#define __HW_UART_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6DQ UART registers defined in this header file.
 *
 * - HW_UART_URXD - UART Receiver Register
 * - HW_UART_UTXD - UART Transmitter Register
 * - HW_UART_UCR1 - UART Control Register 1
 * - HW_UART_UCR2 - UART Control Register 2
 * - HW_UART_UCR3 - UART Control Register 3
 * - HW_UART_UCR4 - UART Control Register 4
 * - HW_UART_UFCR - UART FIFO Control Register
 * - HW_UART_USR1 - UART Status Register 1
 * - HW_UART_USR2 - UART Status Register 2
 * - HW_UART_UESC - UART Escape Character Register
 * - HW_UART_UTIM - UART Escape Timer Register
 * - HW_UART_UBIR - UART BRM Incremental Register
 * - HW_UART_UBMR - UART BRM Modulator Register
 * - HW_UART_UBRC - UART Baud Rate Count Register
 * - HW_UART_ONEMS - UART One Millisecond Register
 * - HW_UART_UTS - UART Test Register
 * - HW_UART_UMCR - UART RS-485 Mode Control Register
 *
 * - hw_uart_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_UART_BASE
#define HW_UART_INSTANCE_COUNT (5) //!< Number of instances of the UART module.
#define HW_UART1 (1) //!< Instance number for UART1.
#define HW_UART2 (2) //!< Instance number for UART2.
#define HW_UART3 (3) //!< Instance number for UART3.
#define HW_UART4 (4) //!< Instance number for UART4.
#define HW_UART5 (5) //!< Instance number for UART5.

#define REGS_UART1_BASE (0x02020000) //!< Base address for UART instance number 1.
#define REGS_UART2_BASE (0x021e8000) //!< Base address for UART instance number 2.
#define REGS_UART3_BASE (0x021ec000) //!< Base address for UART instance number 3.
#define REGS_UART4_BASE (0x021f0000) //!< Base address for UART instance number 4.
#define REGS_UART5_BASE (0x021f4000) //!< Base address for UART instance number 5.

//! @brief Get the base address of UART by instance number.
//! @param x UART instance number, from 1 through 5.
#define REGS_UART_BASE(x) ( (x) == HW_UART1 ? REGS_UART1_BASE : (x) == HW_UART2 ? REGS_UART2_BASE : (x) == HW_UART3 ? REGS_UART3_BASE : (x) == HW_UART4 ? REGS_UART4_BASE : (x) == HW_UART5 ? REGS_UART5_BASE : 0x00d00000)

//! @brief Get the instance number given a base address.
//! @param b Base address for an instance of UART.
#define REGS_UART_INSTANCE(b) ( (b) == REGS_UART1_BASE ? HW_UART1 : (b) == REGS_UART2_BASE ? HW_UART2 : (b) == REGS_UART3_BASE ? HW_UART3 : (b) == REGS_UART4_BASE ? HW_UART4 : (b) == REGS_UART5_BASE ? HW_UART5 : 0)
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UART_URXD - UART Receiver Register (RO)
 *
 * Reset value: 0x00000000
 *
 * The UART will yield a transfer error on the peripheral bus when core is reading URXD register
 * with receive interface disabled (RXEN=0 or UARTEN=0).
 */
typedef union _hw_uart_urxd
{
    reg32_t U;
    struct _hw_uart_urxd_bitfields
    {
        unsigned RX_DATA : 8; //!< [7:0] Received Data . Holds the received character. In 7-bit mode, the most significant bit (MSB) is forced to 0. In 8-bit mode, all bits are active.
        unsigned RESERVED0 : 2; //!< [9:8] Reserved
        unsigned PRERR : 1; //!< [10] In RS-485 mode, it holds the ninth data bit (bit [8]) of received 9-bit RS-485 data In RS232/IrDA mode, it is the Parity Error flag . Indicates whether the current character was detected with a parity error and is possibly corrupted. PRERR is updated for each character read from the RxFIFO. When parity is disabled, PRERR always reads as 0.
        unsigned BRK : 1; //!< [11] BREAK Detect. Indicates whether the current character was detected as a BREAK character. The data bits and the stop bit are all 0. The FRMERR bit is set when BRK is set. When odd parity is selected, PRERR is also set when BRK is set. BRK is valid for each character read from the RxFIFO.
        unsigned FRMERR : 1; //!< [12] Frame Error. Indicates whether the current character had a framing error (a missing stop bit) and is possibly corrupted. FRMERR is updated for each character read from the RxFIFO.
        unsigned OVRRUN : 1; //!< [13] Receiver Overrun. This read-only bit, when HIGH, indicates that the corresponding character was stored in the last position (32nd) of the Rx FIFO. Even if a 33rd character has not been detected, this bit will be set to '1' for the 32nd character.
        unsigned ERR : 1; //!< [14] Error Detect. Indicates whether the character present in the RX_DATA field has an error (OVRRUN, FRMERR, BRK or PRERR) status. The ERR bit is updated and valid for each received character.
        unsigned CHARRDY : 1; //!< [15] Character Ready. This read-only bit indicates an invalid read when the FIFO becomes empty and software tries to read the same old data. This bit should not be used for polling for data written to the RX FIFO.
        unsigned RESERVED1 : 16; //!< [31:16] Reserved
    } B;
} hw_uart_urxd_t;
#endif

/*
 * constants & macros for entire multi-block UART_URXD register
 */
#define HW_UART_URXD_ADDR(x)      (REGS_UART_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_UART_URXD(x)           (*(volatile hw_uart_urxd_t *) HW_UART_URXD_ADDR(x))
#define HW_UART_URXD_RD(x)        (HW_UART_URXD(x).U)
#endif

/*
 * constants & macros for individual UART_URXD bitfields
 */

/* --- Register HW_UART_URXD, field RX_DATA[7:0] (RO)
 *
 * Received Data . Holds the received character. In 7-bit mode, the most significant bit (MSB) is
 * forced to 0. In 8-bit mode, all bits are active.
 */

#define BP_UART_URXD_RX_DATA      (0)      //!< Bit position for UART_URXD_RX_DATA.
#define BM_UART_URXD_RX_DATA      (0x000000ff)  //!< Bit mask for UART_URXD_RX_DATA.

//! @brief Get value of UART_URXD_RX_DATA from a register value.
#define BG_UART_URXD_RX_DATA(r)   (((r) & BM_UART_URXD_RX_DATA) >> BP_UART_URXD_RX_DATA)

/* --- Register HW_UART_URXD, field PRERR[10] (RO)
 *
 * In RS-485 mode, it holds the ninth data bit (bit [8]) of received 9-bit RS-485 data In RS232/IrDA
 * mode, it is the Parity Error flag . Indicates whether the current character was detected with a
 * parity error and is possibly corrupted. PRERR is updated for each character read from the RxFIFO.
 * When parity is disabled, PRERR always reads as 0.
 *
 * Values:
 * 0 - = No parity error was detected for data in the RX_DATA field
 * 1 - = A parity error was detected for data in the RX_DATA field
 */

#define BP_UART_URXD_PRERR      (10)      //!< Bit position for UART_URXD_PRERR.
#define BM_UART_URXD_PRERR      (0x00000400)  //!< Bit mask for UART_URXD_PRERR.

//! @brief Get value of UART_URXD_PRERR from a register value.
#define BG_UART_URXD_PRERR(r)   (((r) & BM_UART_URXD_PRERR) >> BP_UART_URXD_PRERR)


/* --- Register HW_UART_URXD, field BRK[11] (RO)
 *
 * BREAK Detect. Indicates whether the current character was detected as a BREAK character. The data
 * bits and the stop bit are all 0. The FRMERR bit is set when BRK is set. When odd parity is
 * selected, PRERR is also set when BRK is set. BRK is valid for each character read from the
 * RxFIFO.
 *
 * Values:
 * 0 - The current character is not a BREAK character
 * 1 - The current character is a BREAK character
 */

#define BP_UART_URXD_BRK      (11)      //!< Bit position for UART_URXD_BRK.
#define BM_UART_URXD_BRK      (0x00000800)  //!< Bit mask for UART_URXD_BRK.

//! @brief Get value of UART_URXD_BRK from a register value.
#define BG_UART_URXD_BRK(r)   (((r) & BM_UART_URXD_BRK) >> BP_UART_URXD_BRK)


/* --- Register HW_UART_URXD, field FRMERR[12] (RO)
 *
 * Frame Error. Indicates whether the current character had a framing error (a missing stop bit) and
 * is possibly corrupted. FRMERR is updated for each character read from the RxFIFO.
 *
 * Values:
 * 0 - The current character has no framing error
 * 1 - The current character has a framing error
 */

#define BP_UART_URXD_FRMERR      (12)      //!< Bit position for UART_URXD_FRMERR.
#define BM_UART_URXD_FRMERR      (0x00001000)  //!< Bit mask for UART_URXD_FRMERR.

//! @brief Get value of UART_URXD_FRMERR from a register value.
#define BG_UART_URXD_FRMERR(r)   (((r) & BM_UART_URXD_FRMERR) >> BP_UART_URXD_FRMERR)


/* --- Register HW_UART_URXD, field OVRRUN[13] (RO)
 *
 * Receiver Overrun. This read-only bit, when HIGH, indicates that the corresponding character was
 * stored in the last position (32nd) of the Rx FIFO. Even if a 33rd character has not been
 * detected, this bit will be set to '1' for the 32nd character.
 *
 * Values:
 * 0 - No RxFIFO overrun was detected
 * 1 - A RxFIFO overrun was detected
 */

#define BP_UART_URXD_OVRRUN      (13)      //!< Bit position for UART_URXD_OVRRUN.
#define BM_UART_URXD_OVRRUN      (0x00002000)  //!< Bit mask for UART_URXD_OVRRUN.

//! @brief Get value of UART_URXD_OVRRUN from a register value.
#define BG_UART_URXD_OVRRUN(r)   (((r) & BM_UART_URXD_OVRRUN) >> BP_UART_URXD_OVRRUN)


/* --- Register HW_UART_URXD, field ERR[14] (RO)
 *
 * Error Detect. Indicates whether the character present in the RX_DATA field has an error (OVRRUN,
 * FRMERR, BRK or PRERR) status. The ERR bit is updated and valid for each received character.
 *
 * Values:
 * 0 - No error status was detected
 * 1 - An error status was detected
 */

#define BP_UART_URXD_ERR      (14)      //!< Bit position for UART_URXD_ERR.
#define BM_UART_URXD_ERR      (0x00004000)  //!< Bit mask for UART_URXD_ERR.

//! @brief Get value of UART_URXD_ERR from a register value.
#define BG_UART_URXD_ERR(r)   (((r) & BM_UART_URXD_ERR) >> BP_UART_URXD_ERR)


/* --- Register HW_UART_URXD, field CHARRDY[15] (RO)
 *
 * Character Ready. This read-only bit indicates an invalid read when the FIFO becomes empty and
 * software tries to read the same old data. This bit should not be used for polling for data
 * written to the RX FIFO.
 *
 * Values:
 * 0 - Character in RX_DATA field and associated flags are invalid.
 * 1 - Character in RX_DATA field and associated flags valid and ready for reading.
 */

#define BP_UART_URXD_CHARRDY      (15)      //!< Bit position for UART_URXD_CHARRDY.
#define BM_UART_URXD_CHARRDY      (0x00008000)  //!< Bit mask for UART_URXD_CHARRDY.

//! @brief Get value of UART_URXD_CHARRDY from a register value.
#define BG_UART_URXD_CHARRDY(r)   (((r) & BM_UART_URXD_CHARRDY) >> BP_UART_URXD_CHARRDY)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UART_UTXD - UART Transmitter Register (WO)
 *
 * Reset value: 0x00000000
 *
 * The UART will yield a transfer error on the peripheral bus when core is writing into UART_URXD
 * register with transmit interface disabled (TXEN=0 or UARTEN=0). Memory space between UART_URXD
 * and UART_UTXD registers is reserved. Any read or write access to this space will be considered as
 * an invalid access and yield a transfer error .
 */
typedef union _hw_uart_utxd
{
    reg32_t U;
    struct _hw_uart_utxd_bitfields
    {
        unsigned TX_DATA : 8; //!< [7:0] Transmit Data . Holds the parallel transmit data inputs. In 7-bit mode, D7 is ignored. In 8-bit mode, all bits are used. Data is transmitted least significant bit (LSB) first. A new character is transmitted when the TX_DATA field is written. The TX_DATA field must be written only when the TRDY bit is high to ensure that corrupted data is not sent.
        unsigned RESERVED0 : 24; //!< [31:8] Reserved.
    } B;
} hw_uart_utxd_t;
#endif

/*
 * constants & macros for entire multi-block UART_UTXD register
 */
#define HW_UART_UTXD_ADDR(x)      (REGS_UART_BASE(x) + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_UART_UTXD(x)           (*(volatile hw_uart_utxd_t *) HW_UART_UTXD_ADDR(x))
#define HW_UART_UTXD_WR(x, v)     (HW_UART_UTXD(x).U = (v))
#endif

/*
 * constants & macros for individual UART_UTXD bitfields
 */

/* --- Register HW_UART_UTXD, field TX_DATA[7:0] (WO)
 *
 * Transmit Data . Holds the parallel transmit data inputs. In 7-bit mode, D7 is ignored. In 8-bit
 * mode, all bits are used. Data is transmitted least significant bit (LSB) first. A new character
 * is transmitted when the TX_DATA field is written. The TX_DATA field must be written only when the
 * TRDY bit is high to ensure that corrupted data is not sent.
 */

#define BP_UART_UTXD_TX_DATA      (0)      //!< Bit position for UART_UTXD_TX_DATA.
#define BM_UART_UTXD_TX_DATA      (0x000000ff)  //!< Bit mask for UART_UTXD_TX_DATA.

//! @brief Get value of UART_UTXD_TX_DATA from a register value.
#define BG_UART_UTXD_TX_DATA(r)   (((r) & BM_UART_UTXD_TX_DATA) >> BP_UART_UTXD_TX_DATA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UTXD_TX_DATA.
#define BF_UART_UTXD_TX_DATA(v)   ((((reg32_t) v) << BP_UART_UTXD_TX_DATA) & BM_UART_UTXD_TX_DATA)
#else
//! @brief Format value for bitfield UART_UTXD_TX_DATA.
#define BF_UART_UTXD_TX_DATA(v)   (((v) << BP_UART_UTXD_TX_DATA) & BM_UART_UTXD_TX_DATA)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UART_UCR1 - UART Control Register 1 (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_uart_ucr1
{
    reg32_t U;
    struct _hw_uart_ucr1_bitfields
    {
        unsigned UARTEN : 1; //!< [0] UART Enable . Enables/Disables the UART. If UARTEN is negated in the middle of a transmission, the transmitter stops and pulls the TXD line to a logic 1. UARTEN must be set to 1 before any access to UTXD and URXD registers, otherwise a transfer error is returned. Output ipg_uart_clk_en is internally connected to UARTEN and can be used for software controlled clock gating purpose. This bit can be set to 1 along with other bits in this register. There is no restriction to the sequence of programing this bit and other control registers.
        unsigned DOZE : 1; //!< [1] DOZE . Determines the UART enable condition in the DOZE state. When doze_req input pin is at '1', (the ARM Platform executes a doze instruction and the system is placed in the Doze State), the DOZE bit affects operation of the UART. While in the Doze State, if this bit is asserted, the UART is disabled. See the description in .
        unsigned ATDMAEN : 1; //!< [2] Aging DMA Timer Enable . Enables/Disables the receive DMA request dma_req_rx for the aging timer interrupt (triggered with AGTIM flag in USR1[8]).
        unsigned TXDMAEN : 1; //!< [3] Transmitter Ready DMA Enable . Enables/Disables the transmit DMA request dma_req_tx when the transmitter has one or more slots available in the TxFIFO. The fill level in the TxFIFO that generates the dma_req_tx is controlled by the TXTL bits. A DMA request will be issued as long as TXDMAEN and TRDY are high even if the transmitter is not enabled. In general, user should enable the transmitter before enabling the transmit DMA request.
        unsigned SNDBRK : 1; //!< [4] Send BREAK . Forces the transmitter to send a BREAK character. The transmitter finishes sending the character in progress (if any) and sends BREAK characters until SNDBRK is reset. Because the transmitter samples SNDBRK after every bit is transmitted, it is important that SNDBRK is asserted high for a sufficient period of time to generate a valid BREAK. After the BREAK transmission completes, the UART transmits 2 mark bits. The user can continue to fill the TxFIFO and any characters remaining are transmitted when the BREAK is terminated.
        unsigned RTSDEN : 1; //!< [5] RTS Delta Interrupt Enable . Enables/Disables the RTSD interrupt. The current status of the RTS pin is read in the RTSS bit.
        unsigned TXMPTYEN : 1; //!< [6] Transmitter Empty Interrupt Enable . Enables/Disables the transmitter FIFO empty (TXFE) interrupt. interrupt_tx interrupt_uart . When negated, the TXFE interrupt is disabled. An interrupt will be issued as long as TXMPTYEN and TXFE are high even if the transmitter is not enabled. In general, user should enable the transmitter before enabling the TXFE interrupt.
        unsigned IREN : 1; //!< [7] Infrared Interface Enable . Enables/Disables the IR interface. See the IR interface description in , for more information. Note: MDEN(UMCR[0]) must be cleared to 0 when using IrDA interface. See
        unsigned RXDMAEN : 1; //!< [8] Receive Ready DMA Enable . Enables/Disables the receive DMA request dma_req_rx when the receiver has data in the RxFIFO. The fill level in the RxFIFO at which a DMA request is generated is controlled by the RXTL bits. When negated, the receive DMA request is disabled.
        unsigned RRDYEN : 1; //!< [9] Receiver Ready Interrupt Enable . Enables/Disables the RRDY interrupt when the RxFIFO contains data. The fill level in the RxFIFO at which an interrupt is generated is controlled by the RXTL bits. When RRDYEN is negated, the receiver ready interrupt is disabled.
        unsigned ICD : 2; //!< [11:10] Idle Condition Detect . Controls the number of frames RXD is allowed to be idle before an idle condition is reported.
        unsigned IDEN : 1; //!< [12] Idle Condition Detected Interrupt Enable . Enables/Disables the IDLE bit to generate an interrupt ( interrupt_rx interrupt_uart = 0).
        unsigned TRDYEN : 1; //!< [13] Transmitter Ready Interrupt Enable . Enables/Disables the transmitter Ready Interrupt (TRDY) when the transmitter has one or more slots available in the TxFIFO. The fill level in the TXFIFO at which an interrupt is generated is controlled by TxTL bits. When TRDYEN is negated, the transmitter ready interrupt is disabled. An interrupt will be issued as long as TRDYEN and TRDY are high even if the transmitter is not enabled. In general, user should enable the transmitter before enabling the TRDY interrupt.
        unsigned ADBR : 1; //!< [14] Automatic Detection of Baud Rate . Enables/Disables automatic baud rate detection. When the ADBR bit is set and the ADET bit is cleared, the receiver detects the incoming baud rate automatically. The ADET flag is set when the receiver verifies that the incoming baud rate is detected properly by detecting an ASCII character "A" or "a" (0x61 or 0x41).
        unsigned ADEN : 1; //!< [15] Automatic Baud Rate Detection Interrupt Enable . Enables/Disables the automatic baud rate detect complete (ADET) bit to generate an interrupt ( interrupt_mint interrupt_uart = 0).
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
    } B;
} hw_uart_ucr1_t;
#endif

/*
 * constants & macros for entire multi-block UART_UCR1 register
 */
#define HW_UART_UCR1_ADDR(x)      (REGS_UART_BASE(x) + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_UART_UCR1(x)           (*(volatile hw_uart_ucr1_t *) HW_UART_UCR1_ADDR(x))
#define HW_UART_UCR1_RD(x)        (HW_UART_UCR1(x).U)
#define HW_UART_UCR1_WR(x, v)     (HW_UART_UCR1(x).U = (v))
#define HW_UART_UCR1_SET(x, v)    (HW_UART_UCR1_WR(x, HW_UART_UCR1_RD(x) |  (v)))
#define HW_UART_UCR1_CLR(x, v)    (HW_UART_UCR1_WR(x, HW_UART_UCR1_RD(x) & ~(v)))
#define HW_UART_UCR1_TOG(x, v)    (HW_UART_UCR1_WR(x, HW_UART_UCR1_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UART_UCR1 bitfields
 */

/* --- Register HW_UART_UCR1, field UARTEN[0] (RW)
 *
 * UART Enable . Enables/Disables the UART. If UARTEN is negated in the middle of a transmission,
 * the transmitter stops and pulls the TXD line to a logic 1. UARTEN must be set to 1 before any
 * access to UTXD and URXD registers, otherwise a transfer error is returned. Output ipg_uart_clk_en
 * is internally connected to UARTEN and can be used for software controlled clock gating purpose.
 * This bit can be set to 1 along with other bits in this register. There is no restriction to the
 * sequence of programing this bit and other control registers.
 *
 * Values:
 * 0 - Disable the UART
 * 1 - Enable the UART
 */

#define BP_UART_UCR1_UARTEN      (0)      //!< Bit position for UART_UCR1_UARTEN.
#define BM_UART_UCR1_UARTEN      (0x00000001)  //!< Bit mask for UART_UCR1_UARTEN.

//! @brief Get value of UART_UCR1_UARTEN from a register value.
#define BG_UART_UCR1_UARTEN(r)   (((r) & BM_UART_UCR1_UARTEN) >> BP_UART_UCR1_UARTEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR1_UARTEN.
#define BF_UART_UCR1_UARTEN(v)   ((((reg32_t) v) << BP_UART_UCR1_UARTEN) & BM_UART_UCR1_UARTEN)
#else
//! @brief Format value for bitfield UART_UCR1_UARTEN.
#define BF_UART_UCR1_UARTEN(v)   (((v) << BP_UART_UCR1_UARTEN) & BM_UART_UCR1_UARTEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the UARTEN field to a new value.
#define BW_UART_UCR1_UARTEN(x, v)   (HW_UART_UCR1_WR(x, (HW_UART_UCR1_RD(x) & ~BM_UART_UCR1_UARTEN) | BF_UART_UCR1_UARTEN(v)))
#endif


/* --- Register HW_UART_UCR1, field DOZE[1] (RW)
 *
 * DOZE . Determines the UART enable condition in the DOZE state. When doze_req input pin is at '1',
 * (the ARM Platform executes a doze instruction and the system is placed in the Doze State), the
 * DOZE bit affects operation of the UART. While in the Doze State, if this bit is asserted, the
 * UART is disabled. See the description in .
 *
 * Values:
 * 0 - The UART is enabled when in DOZE state
 * 1 - The UART is disabled when in DOZE state
 */

#define BP_UART_UCR1_DOZE      (1)      //!< Bit position for UART_UCR1_DOZE.
#define BM_UART_UCR1_DOZE      (0x00000002)  //!< Bit mask for UART_UCR1_DOZE.

//! @brief Get value of UART_UCR1_DOZE from a register value.
#define BG_UART_UCR1_DOZE(r)   (((r) & BM_UART_UCR1_DOZE) >> BP_UART_UCR1_DOZE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR1_DOZE.
#define BF_UART_UCR1_DOZE(v)   ((((reg32_t) v) << BP_UART_UCR1_DOZE) & BM_UART_UCR1_DOZE)
#else
//! @brief Format value for bitfield UART_UCR1_DOZE.
#define BF_UART_UCR1_DOZE(v)   (((v) << BP_UART_UCR1_DOZE) & BM_UART_UCR1_DOZE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOZE field to a new value.
#define BW_UART_UCR1_DOZE(x, v)   (HW_UART_UCR1_WR(x, (HW_UART_UCR1_RD(x) & ~BM_UART_UCR1_DOZE) | BF_UART_UCR1_DOZE(v)))
#endif


/* --- Register HW_UART_UCR1, field ATDMAEN[2] (RW)
 *
 * Aging DMA Timer Enable . Enables/Disables the receive DMA request dma_req_rx for the aging timer
 * interrupt (triggered with AGTIM flag in USR1[8]).
 *
 * Values:
 * 0 - Disable AGTIM DMA request
 * 1 - Enable AGTIM DMA request
 */

#define BP_UART_UCR1_ATDMAEN      (2)      //!< Bit position for UART_UCR1_ATDMAEN.
#define BM_UART_UCR1_ATDMAEN      (0x00000004)  //!< Bit mask for UART_UCR1_ATDMAEN.

//! @brief Get value of UART_UCR1_ATDMAEN from a register value.
#define BG_UART_UCR1_ATDMAEN(r)   (((r) & BM_UART_UCR1_ATDMAEN) >> BP_UART_UCR1_ATDMAEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR1_ATDMAEN.
#define BF_UART_UCR1_ATDMAEN(v)   ((((reg32_t) v) << BP_UART_UCR1_ATDMAEN) & BM_UART_UCR1_ATDMAEN)
#else
//! @brief Format value for bitfield UART_UCR1_ATDMAEN.
#define BF_UART_UCR1_ATDMAEN(v)   (((v) << BP_UART_UCR1_ATDMAEN) & BM_UART_UCR1_ATDMAEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATDMAEN field to a new value.
#define BW_UART_UCR1_ATDMAEN(x, v)   (HW_UART_UCR1_WR(x, (HW_UART_UCR1_RD(x) & ~BM_UART_UCR1_ATDMAEN) | BF_UART_UCR1_ATDMAEN(v)))
#endif


/* --- Register HW_UART_UCR1, field TXDMAEN[3] (RW)
 *
 * Transmitter Ready DMA Enable . Enables/Disables the transmit DMA request dma_req_tx when the
 * transmitter has one or more slots available in the TxFIFO. The fill level in the TxFIFO that
 * generates the dma_req_tx is controlled by the TXTL bits. A DMA request will be issued as long as
 * TXDMAEN and TRDY are high even if the transmitter is not enabled. In general, user should enable
 * the transmitter before enabling the transmit DMA request.
 *
 * Values:
 * 0 - Disable transmit DMA request
 * 1 - Enable transmit DMA request
 */

#define BP_UART_UCR1_TXDMAEN      (3)      //!< Bit position for UART_UCR1_TXDMAEN.
#define BM_UART_UCR1_TXDMAEN      (0x00000008)  //!< Bit mask for UART_UCR1_TXDMAEN.

//! @brief Get value of UART_UCR1_TXDMAEN from a register value.
#define BG_UART_UCR1_TXDMAEN(r)   (((r) & BM_UART_UCR1_TXDMAEN) >> BP_UART_UCR1_TXDMAEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR1_TXDMAEN.
#define BF_UART_UCR1_TXDMAEN(v)   ((((reg32_t) v) << BP_UART_UCR1_TXDMAEN) & BM_UART_UCR1_TXDMAEN)
#else
//! @brief Format value for bitfield UART_UCR1_TXDMAEN.
#define BF_UART_UCR1_TXDMAEN(v)   (((v) << BP_UART_UCR1_TXDMAEN) & BM_UART_UCR1_TXDMAEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXDMAEN field to a new value.
#define BW_UART_UCR1_TXDMAEN(x, v)   (HW_UART_UCR1_WR(x, (HW_UART_UCR1_RD(x) & ~BM_UART_UCR1_TXDMAEN) | BF_UART_UCR1_TXDMAEN(v)))
#endif


/* --- Register HW_UART_UCR1, field SNDBRK[4] (RW)
 *
 * Send BREAK . Forces the transmitter to send a BREAK character. The transmitter finishes sending
 * the character in progress (if any) and sends BREAK characters until SNDBRK is reset. Because the
 * transmitter samples SNDBRK after every bit is transmitted, it is important that SNDBRK is
 * asserted high for a sufficient period of time to generate a valid BREAK. After the BREAK
 * transmission completes, the UART transmits 2 mark bits. The user can continue to fill the TxFIFO
 * and any characters remaining are transmitted when the BREAK is terminated.
 *
 * Values:
 * 0 - Do not send a BREAK character
 * 1 - Send a BREAK character (continuous 0s)
 */

#define BP_UART_UCR1_SNDBRK      (4)      //!< Bit position for UART_UCR1_SNDBRK.
#define BM_UART_UCR1_SNDBRK      (0x00000010)  //!< Bit mask for UART_UCR1_SNDBRK.

//! @brief Get value of UART_UCR1_SNDBRK from a register value.
#define BG_UART_UCR1_SNDBRK(r)   (((r) & BM_UART_UCR1_SNDBRK) >> BP_UART_UCR1_SNDBRK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR1_SNDBRK.
#define BF_UART_UCR1_SNDBRK(v)   ((((reg32_t) v) << BP_UART_UCR1_SNDBRK) & BM_UART_UCR1_SNDBRK)
#else
//! @brief Format value for bitfield UART_UCR1_SNDBRK.
#define BF_UART_UCR1_SNDBRK(v)   (((v) << BP_UART_UCR1_SNDBRK) & BM_UART_UCR1_SNDBRK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SNDBRK field to a new value.
#define BW_UART_UCR1_SNDBRK(x, v)   (HW_UART_UCR1_WR(x, (HW_UART_UCR1_RD(x) & ~BM_UART_UCR1_SNDBRK) | BF_UART_UCR1_SNDBRK(v)))
#endif


/* --- Register HW_UART_UCR1, field RTSDEN[5] (RW)
 *
 * RTS Delta Interrupt Enable . Enables/Disables the RTSD interrupt. The current status of the RTS
 * pin is read in the RTSS bit.
 *
 * Values:
 * 0 - Disable RTSD interrupt
 * 1 - Enable RTSD interrupt
 */

#define BP_UART_UCR1_RTSDEN      (5)      //!< Bit position for UART_UCR1_RTSDEN.
#define BM_UART_UCR1_RTSDEN      (0x00000020)  //!< Bit mask for UART_UCR1_RTSDEN.

//! @brief Get value of UART_UCR1_RTSDEN from a register value.
#define BG_UART_UCR1_RTSDEN(r)   (((r) & BM_UART_UCR1_RTSDEN) >> BP_UART_UCR1_RTSDEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR1_RTSDEN.
#define BF_UART_UCR1_RTSDEN(v)   ((((reg32_t) v) << BP_UART_UCR1_RTSDEN) & BM_UART_UCR1_RTSDEN)
#else
//! @brief Format value for bitfield UART_UCR1_RTSDEN.
#define BF_UART_UCR1_RTSDEN(v)   (((v) << BP_UART_UCR1_RTSDEN) & BM_UART_UCR1_RTSDEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RTSDEN field to a new value.
#define BW_UART_UCR1_RTSDEN(x, v)   (HW_UART_UCR1_WR(x, (HW_UART_UCR1_RD(x) & ~BM_UART_UCR1_RTSDEN) | BF_UART_UCR1_RTSDEN(v)))
#endif


/* --- Register HW_UART_UCR1, field TXMPTYEN[6] (RW)
 *
 * Transmitter Empty Interrupt Enable . Enables/Disables the transmitter FIFO empty (TXFE)
 * interrupt. interrupt_tx interrupt_uart . When negated, the TXFE interrupt is disabled. An
 * interrupt will be issued as long as TXMPTYEN and TXFE are high even if the transmitter is not
 * enabled. In general, user should enable the transmitter before enabling the TXFE interrupt.
 *
 * Values:
 * 0 - Disable the transmitter FIFO empty interrupt
 * 1 - Enable the transmitter FIFO empty interrupt
 */

#define BP_UART_UCR1_TXMPTYEN      (6)      //!< Bit position for UART_UCR1_TXMPTYEN.
#define BM_UART_UCR1_TXMPTYEN      (0x00000040)  //!< Bit mask for UART_UCR1_TXMPTYEN.

//! @brief Get value of UART_UCR1_TXMPTYEN from a register value.
#define BG_UART_UCR1_TXMPTYEN(r)   (((r) & BM_UART_UCR1_TXMPTYEN) >> BP_UART_UCR1_TXMPTYEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR1_TXMPTYEN.
#define BF_UART_UCR1_TXMPTYEN(v)   ((((reg32_t) v) << BP_UART_UCR1_TXMPTYEN) & BM_UART_UCR1_TXMPTYEN)
#else
//! @brief Format value for bitfield UART_UCR1_TXMPTYEN.
#define BF_UART_UCR1_TXMPTYEN(v)   (((v) << BP_UART_UCR1_TXMPTYEN) & BM_UART_UCR1_TXMPTYEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXMPTYEN field to a new value.
#define BW_UART_UCR1_TXMPTYEN(x, v)   (HW_UART_UCR1_WR(x, (HW_UART_UCR1_RD(x) & ~BM_UART_UCR1_TXMPTYEN) | BF_UART_UCR1_TXMPTYEN(v)))
#endif


/* --- Register HW_UART_UCR1, field IREN[7] (RW)
 *
 * Infrared Interface Enable . Enables/Disables the IR interface. See the IR interface description
 * in , for more information. Note: MDEN(UMCR[0]) must be cleared to 0 when using IrDA interface.
 * See
 *
 * Values:
 * 0 - Disable the IR interface
 * 1 - Enable the IR interface
 */

#define BP_UART_UCR1_IREN      (7)      //!< Bit position for UART_UCR1_IREN.
#define BM_UART_UCR1_IREN      (0x00000080)  //!< Bit mask for UART_UCR1_IREN.

//! @brief Get value of UART_UCR1_IREN from a register value.
#define BG_UART_UCR1_IREN(r)   (((r) & BM_UART_UCR1_IREN) >> BP_UART_UCR1_IREN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR1_IREN.
#define BF_UART_UCR1_IREN(v)   ((((reg32_t) v) << BP_UART_UCR1_IREN) & BM_UART_UCR1_IREN)
#else
//! @brief Format value for bitfield UART_UCR1_IREN.
#define BF_UART_UCR1_IREN(v)   (((v) << BP_UART_UCR1_IREN) & BM_UART_UCR1_IREN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IREN field to a new value.
#define BW_UART_UCR1_IREN(x, v)   (HW_UART_UCR1_WR(x, (HW_UART_UCR1_RD(x) & ~BM_UART_UCR1_IREN) | BF_UART_UCR1_IREN(v)))
#endif


/* --- Register HW_UART_UCR1, field RXDMAEN[8] (RW)
 *
 * Receive Ready DMA Enable . Enables/Disables the receive DMA request dma_req_rx when the receiver
 * has data in the RxFIFO. The fill level in the RxFIFO at which a DMA request is generated is
 * controlled by the RXTL bits. When negated, the receive DMA request is disabled.
 *
 * Values:
 * 0 - Disable DMA request
 * 1 - Enable DMA request
 */

#define BP_UART_UCR1_RXDMAEN      (8)      //!< Bit position for UART_UCR1_RXDMAEN.
#define BM_UART_UCR1_RXDMAEN      (0x00000100)  //!< Bit mask for UART_UCR1_RXDMAEN.

//! @brief Get value of UART_UCR1_RXDMAEN from a register value.
#define BG_UART_UCR1_RXDMAEN(r)   (((r) & BM_UART_UCR1_RXDMAEN) >> BP_UART_UCR1_RXDMAEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR1_RXDMAEN.
#define BF_UART_UCR1_RXDMAEN(v)   ((((reg32_t) v) << BP_UART_UCR1_RXDMAEN) & BM_UART_UCR1_RXDMAEN)
#else
//! @brief Format value for bitfield UART_UCR1_RXDMAEN.
#define BF_UART_UCR1_RXDMAEN(v)   (((v) << BP_UART_UCR1_RXDMAEN) & BM_UART_UCR1_RXDMAEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDMAEN field to a new value.
#define BW_UART_UCR1_RXDMAEN(x, v)   (HW_UART_UCR1_WR(x, (HW_UART_UCR1_RD(x) & ~BM_UART_UCR1_RXDMAEN) | BF_UART_UCR1_RXDMAEN(v)))
#endif


/* --- Register HW_UART_UCR1, field RRDYEN[9] (RW)
 *
 * Receiver Ready Interrupt Enable . Enables/Disables the RRDY interrupt when the RxFIFO contains
 * data. The fill level in the RxFIFO at which an interrupt is generated is controlled by the RXTL
 * bits. When RRDYEN is negated, the receiver ready interrupt is disabled.
 *
 * Values:
 * 0 - Disables the RRDY interrupt
 * 1 - Enables the RRDY interrupt
 */

#define BP_UART_UCR1_RRDYEN      (9)      //!< Bit position for UART_UCR1_RRDYEN.
#define BM_UART_UCR1_RRDYEN      (0x00000200)  //!< Bit mask for UART_UCR1_RRDYEN.

//! @brief Get value of UART_UCR1_RRDYEN from a register value.
#define BG_UART_UCR1_RRDYEN(r)   (((r) & BM_UART_UCR1_RRDYEN) >> BP_UART_UCR1_RRDYEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR1_RRDYEN.
#define BF_UART_UCR1_RRDYEN(v)   ((((reg32_t) v) << BP_UART_UCR1_RRDYEN) & BM_UART_UCR1_RRDYEN)
#else
//! @brief Format value for bitfield UART_UCR1_RRDYEN.
#define BF_UART_UCR1_RRDYEN(v)   (((v) << BP_UART_UCR1_RRDYEN) & BM_UART_UCR1_RRDYEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RRDYEN field to a new value.
#define BW_UART_UCR1_RRDYEN(x, v)   (HW_UART_UCR1_WR(x, (HW_UART_UCR1_RD(x) & ~BM_UART_UCR1_RRDYEN) | BF_UART_UCR1_RRDYEN(v)))
#endif


/* --- Register HW_UART_UCR1, field ICD[11:10] (RW)
 *
 * Idle Condition Detect . Controls the number of frames RXD is allowed to be idle before an idle
 * condition is reported.
 *
 * Values:
 * 00 - Idle for more than 4 frames
 * 01 - Idle for more than 8 frames
 * 10 - Idle for more than 16 frames
 * 11 - Idle for more than 32 frames
 */

#define BP_UART_UCR1_ICD      (10)      //!< Bit position for UART_UCR1_ICD.
#define BM_UART_UCR1_ICD      (0x00000c00)  //!< Bit mask for UART_UCR1_ICD.

//! @brief Get value of UART_UCR1_ICD from a register value.
#define BG_UART_UCR1_ICD(r)   (((r) & BM_UART_UCR1_ICD) >> BP_UART_UCR1_ICD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR1_ICD.
#define BF_UART_UCR1_ICD(v)   ((((reg32_t) v) << BP_UART_UCR1_ICD) & BM_UART_UCR1_ICD)
#else
//! @brief Format value for bitfield UART_UCR1_ICD.
#define BF_UART_UCR1_ICD(v)   (((v) << BP_UART_UCR1_ICD) & BM_UART_UCR1_ICD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ICD field to a new value.
#define BW_UART_UCR1_ICD(x, v)   (HW_UART_UCR1_WR(x, (HW_UART_UCR1_RD(x) & ~BM_UART_UCR1_ICD) | BF_UART_UCR1_ICD(v)))
#endif


/* --- Register HW_UART_UCR1, field IDEN[12] (RW)
 *
 * Idle Condition Detected Interrupt Enable . Enables/Disables the IDLE bit to generate an interrupt
 * ( interrupt_rx interrupt_uart = 0).
 *
 * Values:
 * 0 - Disable the IDLE interrupt
 * 1 - Enable the IDLE interrupt
 */

#define BP_UART_UCR1_IDEN      (12)      //!< Bit position for UART_UCR1_IDEN.
#define BM_UART_UCR1_IDEN      (0x00001000)  //!< Bit mask for UART_UCR1_IDEN.

//! @brief Get value of UART_UCR1_IDEN from a register value.
#define BG_UART_UCR1_IDEN(r)   (((r) & BM_UART_UCR1_IDEN) >> BP_UART_UCR1_IDEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR1_IDEN.
#define BF_UART_UCR1_IDEN(v)   ((((reg32_t) v) << BP_UART_UCR1_IDEN) & BM_UART_UCR1_IDEN)
#else
//! @brief Format value for bitfield UART_UCR1_IDEN.
#define BF_UART_UCR1_IDEN(v)   (((v) << BP_UART_UCR1_IDEN) & BM_UART_UCR1_IDEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IDEN field to a new value.
#define BW_UART_UCR1_IDEN(x, v)   (HW_UART_UCR1_WR(x, (HW_UART_UCR1_RD(x) & ~BM_UART_UCR1_IDEN) | BF_UART_UCR1_IDEN(v)))
#endif


/* --- Register HW_UART_UCR1, field TRDYEN[13] (RW)
 *
 * Transmitter Ready Interrupt Enable . Enables/Disables the transmitter Ready Interrupt (TRDY) when
 * the transmitter has one or more slots available in the TxFIFO. The fill level in the TXFIFO at
 * which an interrupt is generated is controlled by TxTL bits. When TRDYEN is negated, the
 * transmitter ready interrupt is disabled. An interrupt will be issued as long as TRDYEN and TRDY
 * are high even if the transmitter is not enabled. In general, user should enable the transmitter
 * before enabling the TRDY interrupt.
 *
 * Values:
 * 0 - Disable the transmitter ready interrupt
 * 1 - Enable the transmitter ready interrupt
 */

#define BP_UART_UCR1_TRDYEN      (13)      //!< Bit position for UART_UCR1_TRDYEN.
#define BM_UART_UCR1_TRDYEN      (0x00002000)  //!< Bit mask for UART_UCR1_TRDYEN.

//! @brief Get value of UART_UCR1_TRDYEN from a register value.
#define BG_UART_UCR1_TRDYEN(r)   (((r) & BM_UART_UCR1_TRDYEN) >> BP_UART_UCR1_TRDYEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR1_TRDYEN.
#define BF_UART_UCR1_TRDYEN(v)   ((((reg32_t) v) << BP_UART_UCR1_TRDYEN) & BM_UART_UCR1_TRDYEN)
#else
//! @brief Format value for bitfield UART_UCR1_TRDYEN.
#define BF_UART_UCR1_TRDYEN(v)   (((v) << BP_UART_UCR1_TRDYEN) & BM_UART_UCR1_TRDYEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TRDYEN field to a new value.
#define BW_UART_UCR1_TRDYEN(x, v)   (HW_UART_UCR1_WR(x, (HW_UART_UCR1_RD(x) & ~BM_UART_UCR1_TRDYEN) | BF_UART_UCR1_TRDYEN(v)))
#endif


/* --- Register HW_UART_UCR1, field ADBR[14] (RW)
 *
 * Automatic Detection of Baud Rate . Enables/Disables automatic baud rate detection. When the ADBR
 * bit is set and the ADET bit is cleared, the receiver detects the incoming baud rate
 * automatically. The ADET flag is set when the receiver verifies that the incoming baud rate is
 * detected properly by detecting an ASCII character "A" or "a" (0x61 or 0x41).
 *
 * Values:
 * 0 - Disable automatic detection of baud rate
 * 1 - Enable automatic detection of baud rate
 */

#define BP_UART_UCR1_ADBR      (14)      //!< Bit position for UART_UCR1_ADBR.
#define BM_UART_UCR1_ADBR      (0x00004000)  //!< Bit mask for UART_UCR1_ADBR.

//! @brief Get value of UART_UCR1_ADBR from a register value.
#define BG_UART_UCR1_ADBR(r)   (((r) & BM_UART_UCR1_ADBR) >> BP_UART_UCR1_ADBR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR1_ADBR.
#define BF_UART_UCR1_ADBR(v)   ((((reg32_t) v) << BP_UART_UCR1_ADBR) & BM_UART_UCR1_ADBR)
#else
//! @brief Format value for bitfield UART_UCR1_ADBR.
#define BF_UART_UCR1_ADBR(v)   (((v) << BP_UART_UCR1_ADBR) & BM_UART_UCR1_ADBR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADBR field to a new value.
#define BW_UART_UCR1_ADBR(x, v)   (HW_UART_UCR1_WR(x, (HW_UART_UCR1_RD(x) & ~BM_UART_UCR1_ADBR) | BF_UART_UCR1_ADBR(v)))
#endif


/* --- Register HW_UART_UCR1, field ADEN[15] (RW)
 *
 * Automatic Baud Rate Detection Interrupt Enable . Enables/Disables the automatic baud rate detect
 * complete (ADET) bit to generate an interrupt ( interrupt_mint interrupt_uart = 0).
 *
 * Values:
 * 0 - Disable the automatic baud rate detection interrupt
 * 1 - Enable the automatic baud rate detection interrupt
 */

#define BP_UART_UCR1_ADEN      (15)      //!< Bit position for UART_UCR1_ADEN.
#define BM_UART_UCR1_ADEN      (0x00008000)  //!< Bit mask for UART_UCR1_ADEN.

//! @brief Get value of UART_UCR1_ADEN from a register value.
#define BG_UART_UCR1_ADEN(r)   (((r) & BM_UART_UCR1_ADEN) >> BP_UART_UCR1_ADEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR1_ADEN.
#define BF_UART_UCR1_ADEN(v)   ((((reg32_t) v) << BP_UART_UCR1_ADEN) & BM_UART_UCR1_ADEN)
#else
//! @brief Format value for bitfield UART_UCR1_ADEN.
#define BF_UART_UCR1_ADEN(v)   (((v) << BP_UART_UCR1_ADEN) & BM_UART_UCR1_ADEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADEN field to a new value.
#define BW_UART_UCR1_ADEN(x, v)   (HW_UART_UCR1_WR(x, (HW_UART_UCR1_RD(x) & ~BM_UART_UCR1_ADEN) | BF_UART_UCR1_ADEN(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UART_UCR2 - UART Control Register 2 (RW)
 *
 * Reset value: 0x00000001
 *

 */
typedef union _hw_uart_ucr2
{
    reg32_t U;
    struct _hw_uart_ucr2_bitfields
    {
        unsigned SRST : 1; //!< [0] Software Reset . Once the software writes 0 to SRST , the software reset remains active for 4 module_clock (ipg_perclk) cycles before the hardware deasserts SRST . The software can only write 0 to SRST . Writing 1 to SRST is ignored.
        unsigned RXEN : 1; //!< [1] Receiver Enable . Enables/Disables the receiver. When the receiver is enabled, if the RXD input is already low, the receiver does not recognize BREAK characters, because it requires a valid 1-to-0 transition before it can accept any character.
        unsigned TXEN : 1; //!< [2] Transmitter Enable . Enables/Disables the transmitter. When TXEN is negated the transmitter is disabled and idle. When the UARTEN and TXEN bits are set the transmitter is enabled. If TXEN is negated in the middle of a transmission, the UART disables the transmitter immediately, and starts marking 1s. The transmitter FIFO cannot be written when this bit is cleared.
        unsigned ATEN : 1; //!< [3] Aging Timer Enable . This bit is used to enable the aging timer interrupt (triggered with AGTIM)
        unsigned RTSEN : 1; //!< [4] Request to Send Interrupt Enable. Controls the RTS edge sensitive interrupt. When RTSEN is asserted and the programmed edge is detected on the RTS pin (the RTSF bit is asserted), an interrupt will be generated on the interrupt_mint interrupt_uart pin. (See .)
        unsigned WS : 1; //!< [5] Word Size . Controls the character length. When WS is high, the transmitter and receiver are in 8-bit mode. When WS is low, they are in 7-bit mode. The transmitter ignores bit 7 and the receiver sets bit 7 to 0. WS can be changed in-between transmission (reception) of characters, however not when a transmission (reception) is in progress, in which case the length of the current character being transmitted (received) is unpredictable.
        unsigned STPB : 1; //!< [6] Stop . Controls the number of stop bits after a character. When STPB is low, 1 stop bit is sent. When STPB is high, 2 stop bits are sent. STPB also affects the receiver.
        unsigned PROE : 1; //!< [7] Parity Odd/Even . Controls the sense of the parity generator and checker. When PROE is high, odd parity is generated and expected. When PROE is low, even parity is generated and expected. PROE has no function if PREN is low.
        unsigned PREN : 1; //!< [8] Parity Enable . Enables/Disables the parity generator in the transmitter and parity checker in the receiver. When PREN is asserted, the parity generator and checker are enabled, and disabled when PREN is negated.
        unsigned RTEC : 2; //!< [10:9] Request to Send Edge Control . Selects the edge that triggers the RTS interrupt. This has no effect on the RTS delta interrupt. RTEC has an effect only when RTSEN = 1 (see ).
        unsigned ESCEN : 1; //!< [11] Escape Enable . Enables/Disables the escape sequence detection logic.
        unsigned CTS : 1; //!< [12] Clear to Send . Controls the CTS pin when the CTSC bit is negated. CTS has no function when CTSC is asserted.
        unsigned CTSC : 1; //!< [13] CTS Pin Control . Controls the operation of the CTS output pin. When CTSC is asserted, the CTS output pin is controlled by the receiver. When the RxFIFO is filled to the level of the programmed trigger level and the start bit of the overflowing character (TRIGGER LEVEL + 1) is validated, the CTS output pin is negated to indicate to the far-end transmitter to stop transmitting. When the trigger level is programmed for less than 32, the receiver continues to receive data until the RxFIFO is full. When the CTSC bit is negated, the CTS output pin is controlled by the CTS bit. On reset, because CTSC is cleared to 0, the CTS pin is controlled by the CTS bit, which again is cleared to 0 on reset. This means that on reset the CTS signal is negated.
        unsigned IRTS : 1; //!< [14] Ignore RTS Pin . Forces the RTS input signal presented to the transmitter to always be asserted (set to low), effectively ignoring the external pin. When in this mode, the RTS pin serves as a general purpose input.
        unsigned ESCI : 1; //!< [15] Escape Sequence Interrupt Enable . Enables/Disables the ESCF bit to generate an interrupt.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
    } B;
} hw_uart_ucr2_t;
#endif

/*
 * constants & macros for entire multi-block UART_UCR2 register
 */
#define HW_UART_UCR2_ADDR(x)      (REGS_UART_BASE(x) + 0x84)

#ifndef __LANGUAGE_ASM__
#define HW_UART_UCR2(x)           (*(volatile hw_uart_ucr2_t *) HW_UART_UCR2_ADDR(x))
#define HW_UART_UCR2_RD(x)        (HW_UART_UCR2(x).U)
#define HW_UART_UCR2_WR(x, v)     (HW_UART_UCR2(x).U = (v))
#define HW_UART_UCR2_SET(x, v)    (HW_UART_UCR2_WR(x, HW_UART_UCR2_RD(x) |  (v)))
#define HW_UART_UCR2_CLR(x, v)    (HW_UART_UCR2_WR(x, HW_UART_UCR2_RD(x) & ~(v)))
#define HW_UART_UCR2_TOG(x, v)    (HW_UART_UCR2_WR(x, HW_UART_UCR2_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UART_UCR2 bitfields
 */

/* --- Register HW_UART_UCR2, field SRST[0] (RW)
 *
 * Software Reset . Once the software writes 0 to SRST , the software reset remains active for 4
 * module_clock (ipg_perclk) cycles before the hardware deasserts SRST . The software can only write
 * 0 to SRST . Writing 1 to SRST is ignored.
 *
 * Values:
 * 0 - Reset the transmit and receive state machines, all FIFOs and register USR1, USR2, UBIR, UBMR, UBRC ,
 *     URXD, UTXD and UTS[6-3].
 * 1 - No reset
 */

#define BP_UART_UCR2_SRST      (0)      //!< Bit position for UART_UCR2_SRST.
#define BM_UART_UCR2_SRST      (0x00000001)  //!< Bit mask for UART_UCR2_SRST.

//! @brief Get value of UART_UCR2_SRST from a register value.
#define BG_UART_UCR2_SRST(r)   (((r) & BM_UART_UCR2_SRST) >> BP_UART_UCR2_SRST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR2_SRST.
#define BF_UART_UCR2_SRST(v)   ((((reg32_t) v) << BP_UART_UCR2_SRST) & BM_UART_UCR2_SRST)
#else
//! @brief Format value for bitfield UART_UCR2_SRST.
#define BF_UART_UCR2_SRST(v)   (((v) << BP_UART_UCR2_SRST) & BM_UART_UCR2_SRST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SRST field to a new value.
#define BW_UART_UCR2_SRST(x, v)   (HW_UART_UCR2_WR(x, (HW_UART_UCR2_RD(x) & ~BM_UART_UCR2_SRST) | BF_UART_UCR2_SRST(v)))
#endif


/* --- Register HW_UART_UCR2, field RXEN[1] (RW)
 *
 * Receiver Enable . Enables/Disables the receiver. When the receiver is enabled, if the RXD input
 * is already low, the receiver does not recognize BREAK characters, because it requires a valid
 * 1-to-0 transition before it can accept any character.
 *
 * Values:
 * 0 - Disable the receiver
 * 1 - Enable the receiver
 */

#define BP_UART_UCR2_RXEN      (1)      //!< Bit position for UART_UCR2_RXEN.
#define BM_UART_UCR2_RXEN      (0x00000002)  //!< Bit mask for UART_UCR2_RXEN.

//! @brief Get value of UART_UCR2_RXEN from a register value.
#define BG_UART_UCR2_RXEN(r)   (((r) & BM_UART_UCR2_RXEN) >> BP_UART_UCR2_RXEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR2_RXEN.
#define BF_UART_UCR2_RXEN(v)   ((((reg32_t) v) << BP_UART_UCR2_RXEN) & BM_UART_UCR2_RXEN)
#else
//! @brief Format value for bitfield UART_UCR2_RXEN.
#define BF_UART_UCR2_RXEN(v)   (((v) << BP_UART_UCR2_RXEN) & BM_UART_UCR2_RXEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXEN field to a new value.
#define BW_UART_UCR2_RXEN(x, v)   (HW_UART_UCR2_WR(x, (HW_UART_UCR2_RD(x) & ~BM_UART_UCR2_RXEN) | BF_UART_UCR2_RXEN(v)))
#endif


/* --- Register HW_UART_UCR2, field TXEN[2] (RW)
 *
 * Transmitter Enable . Enables/Disables the transmitter. When TXEN is negated the transmitter is
 * disabled and idle. When the UARTEN and TXEN bits are set the transmitter is enabled. If TXEN is
 * negated in the middle of a transmission, the UART disables the transmitter immediately, and
 * starts marking 1s. The transmitter FIFO cannot be written when this bit is cleared.
 *
 * Values:
 * 0 - Disable the transmitter
 * 1 - Enable the transmitter
 */

#define BP_UART_UCR2_TXEN      (2)      //!< Bit position for UART_UCR2_TXEN.
#define BM_UART_UCR2_TXEN      (0x00000004)  //!< Bit mask for UART_UCR2_TXEN.

//! @brief Get value of UART_UCR2_TXEN from a register value.
#define BG_UART_UCR2_TXEN(r)   (((r) & BM_UART_UCR2_TXEN) >> BP_UART_UCR2_TXEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR2_TXEN.
#define BF_UART_UCR2_TXEN(v)   ((((reg32_t) v) << BP_UART_UCR2_TXEN) & BM_UART_UCR2_TXEN)
#else
//! @brief Format value for bitfield UART_UCR2_TXEN.
#define BF_UART_UCR2_TXEN(v)   (((v) << BP_UART_UCR2_TXEN) & BM_UART_UCR2_TXEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXEN field to a new value.
#define BW_UART_UCR2_TXEN(x, v)   (HW_UART_UCR2_WR(x, (HW_UART_UCR2_RD(x) & ~BM_UART_UCR2_TXEN) | BF_UART_UCR2_TXEN(v)))
#endif


/* --- Register HW_UART_UCR2, field ATEN[3] (RW)
 *
 * Aging Timer Enable . This bit is used to enable the aging timer interrupt (triggered with AGTIM)
 *
 * Values:
 * 0 - AGTIM interrupt disabled
 * 1 - AGTIM interrupt enabled
 */

#define BP_UART_UCR2_ATEN      (3)      //!< Bit position for UART_UCR2_ATEN.
#define BM_UART_UCR2_ATEN      (0x00000008)  //!< Bit mask for UART_UCR2_ATEN.

//! @brief Get value of UART_UCR2_ATEN from a register value.
#define BG_UART_UCR2_ATEN(r)   (((r) & BM_UART_UCR2_ATEN) >> BP_UART_UCR2_ATEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR2_ATEN.
#define BF_UART_UCR2_ATEN(v)   ((((reg32_t) v) << BP_UART_UCR2_ATEN) & BM_UART_UCR2_ATEN)
#else
//! @brief Format value for bitfield UART_UCR2_ATEN.
#define BF_UART_UCR2_ATEN(v)   (((v) << BP_UART_UCR2_ATEN) & BM_UART_UCR2_ATEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATEN field to a new value.
#define BW_UART_UCR2_ATEN(x, v)   (HW_UART_UCR2_WR(x, (HW_UART_UCR2_RD(x) & ~BM_UART_UCR2_ATEN) | BF_UART_UCR2_ATEN(v)))
#endif


/* --- Register HW_UART_UCR2, field RTSEN[4] (RW)
 *
 * Request to Send Interrupt Enable. Controls the RTS edge sensitive interrupt. When RTSEN is
 * asserted and the programmed edge is detected on the RTS pin (the RTSF bit is asserted), an
 * interrupt will be generated on the interrupt_mint interrupt_uart pin. (See .)
 *
 * Values:
 * 0 - Disable request to send interrupt
 * 1 - Enable request to send interrupt
 */

#define BP_UART_UCR2_RTSEN      (4)      //!< Bit position for UART_UCR2_RTSEN.
#define BM_UART_UCR2_RTSEN      (0x00000010)  //!< Bit mask for UART_UCR2_RTSEN.

//! @brief Get value of UART_UCR2_RTSEN from a register value.
#define BG_UART_UCR2_RTSEN(r)   (((r) & BM_UART_UCR2_RTSEN) >> BP_UART_UCR2_RTSEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR2_RTSEN.
#define BF_UART_UCR2_RTSEN(v)   ((((reg32_t) v) << BP_UART_UCR2_RTSEN) & BM_UART_UCR2_RTSEN)
#else
//! @brief Format value for bitfield UART_UCR2_RTSEN.
#define BF_UART_UCR2_RTSEN(v)   (((v) << BP_UART_UCR2_RTSEN) & BM_UART_UCR2_RTSEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RTSEN field to a new value.
#define BW_UART_UCR2_RTSEN(x, v)   (HW_UART_UCR2_WR(x, (HW_UART_UCR2_RD(x) & ~BM_UART_UCR2_RTSEN) | BF_UART_UCR2_RTSEN(v)))
#endif


/* --- Register HW_UART_UCR2, field WS[5] (RW)
 *
 * Word Size . Controls the character length. When WS is high, the transmitter and receiver are in
 * 8-bit mode. When WS is low, they are in 7-bit mode. The transmitter ignores bit 7 and the
 * receiver sets bit 7 to 0. WS can be changed in-between transmission (reception) of characters,
 * however not when a transmission (reception) is in progress, in which case the length of the
 * current character being transmitted (received) is unpredictable.
 *
 * Values:
 * 0 - 7-bit transmit and receive character length (not including START, STOP or PARITY bits)
 * 1 - 8-bit transmit and receive character length (not including START, STOP or PARITY bits)
 */

#define BP_UART_UCR2_WS      (5)      //!< Bit position for UART_UCR2_WS.
#define BM_UART_UCR2_WS      (0x00000020)  //!< Bit mask for UART_UCR2_WS.

//! @brief Get value of UART_UCR2_WS from a register value.
#define BG_UART_UCR2_WS(r)   (((r) & BM_UART_UCR2_WS) >> BP_UART_UCR2_WS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR2_WS.
#define BF_UART_UCR2_WS(v)   ((((reg32_t) v) << BP_UART_UCR2_WS) & BM_UART_UCR2_WS)
#else
//! @brief Format value for bitfield UART_UCR2_WS.
#define BF_UART_UCR2_WS(v)   (((v) << BP_UART_UCR2_WS) & BM_UART_UCR2_WS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WS field to a new value.
#define BW_UART_UCR2_WS(x, v)   (HW_UART_UCR2_WR(x, (HW_UART_UCR2_RD(x) & ~BM_UART_UCR2_WS) | BF_UART_UCR2_WS(v)))
#endif


/* --- Register HW_UART_UCR2, field STPB[6] (RW)
 *
 * Stop . Controls the number of stop bits after a character. When STPB is low, 1 stop bit is sent.
 * When STPB is high, 2 stop bits are sent. STPB also affects the receiver.
 *
 * Values:
 * 0 - The transmitter sends 1 stop bit. The receiver expects 1 or more stop bits.
 * 1 - The transmitter sends 2 stop bits. The receiver expects 2 or more stop bits.
 */

#define BP_UART_UCR2_STPB      (6)      //!< Bit position for UART_UCR2_STPB.
#define BM_UART_UCR2_STPB      (0x00000040)  //!< Bit mask for UART_UCR2_STPB.

//! @brief Get value of UART_UCR2_STPB from a register value.
#define BG_UART_UCR2_STPB(r)   (((r) & BM_UART_UCR2_STPB) >> BP_UART_UCR2_STPB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR2_STPB.
#define BF_UART_UCR2_STPB(v)   ((((reg32_t) v) << BP_UART_UCR2_STPB) & BM_UART_UCR2_STPB)
#else
//! @brief Format value for bitfield UART_UCR2_STPB.
#define BF_UART_UCR2_STPB(v)   (((v) << BP_UART_UCR2_STPB) & BM_UART_UCR2_STPB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the STPB field to a new value.
#define BW_UART_UCR2_STPB(x, v)   (HW_UART_UCR2_WR(x, (HW_UART_UCR2_RD(x) & ~BM_UART_UCR2_STPB) | BF_UART_UCR2_STPB(v)))
#endif


/* --- Register HW_UART_UCR2, field PROE[7] (RW)
 *
 * Parity Odd/Even . Controls the sense of the parity generator and checker. When PROE is high, odd
 * parity is generated and expected. When PROE is low, even parity is generated and expected. PROE
 * has no function if PREN is low.
 *
 * Values:
 * 0 - Even parity
 * 1 - Odd parity
 */

#define BP_UART_UCR2_PROE      (7)      //!< Bit position for UART_UCR2_PROE.
#define BM_UART_UCR2_PROE      (0x00000080)  //!< Bit mask for UART_UCR2_PROE.

//! @brief Get value of UART_UCR2_PROE from a register value.
#define BG_UART_UCR2_PROE(r)   (((r) & BM_UART_UCR2_PROE) >> BP_UART_UCR2_PROE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR2_PROE.
#define BF_UART_UCR2_PROE(v)   ((((reg32_t) v) << BP_UART_UCR2_PROE) & BM_UART_UCR2_PROE)
#else
//! @brief Format value for bitfield UART_UCR2_PROE.
#define BF_UART_UCR2_PROE(v)   (((v) << BP_UART_UCR2_PROE) & BM_UART_UCR2_PROE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PROE field to a new value.
#define BW_UART_UCR2_PROE(x, v)   (HW_UART_UCR2_WR(x, (HW_UART_UCR2_RD(x) & ~BM_UART_UCR2_PROE) | BF_UART_UCR2_PROE(v)))
#endif


/* --- Register HW_UART_UCR2, field PREN[8] (RW)
 *
 * Parity Enable . Enables/Disables the parity generator in the transmitter and parity checker in
 * the receiver. When PREN is asserted, the parity generator and checker are enabled, and disabled
 * when PREN is negated.
 *
 * Values:
 * 0 - Disable parity generator and checker
 * 1 - Enable parity generator and checker
 */

#define BP_UART_UCR2_PREN      (8)      //!< Bit position for UART_UCR2_PREN.
#define BM_UART_UCR2_PREN      (0x00000100)  //!< Bit mask for UART_UCR2_PREN.

//! @brief Get value of UART_UCR2_PREN from a register value.
#define BG_UART_UCR2_PREN(r)   (((r) & BM_UART_UCR2_PREN) >> BP_UART_UCR2_PREN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR2_PREN.
#define BF_UART_UCR2_PREN(v)   ((((reg32_t) v) << BP_UART_UCR2_PREN) & BM_UART_UCR2_PREN)
#else
//! @brief Format value for bitfield UART_UCR2_PREN.
#define BF_UART_UCR2_PREN(v)   (((v) << BP_UART_UCR2_PREN) & BM_UART_UCR2_PREN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PREN field to a new value.
#define BW_UART_UCR2_PREN(x, v)   (HW_UART_UCR2_WR(x, (HW_UART_UCR2_RD(x) & ~BM_UART_UCR2_PREN) | BF_UART_UCR2_PREN(v)))
#endif


/* --- Register HW_UART_UCR2, field RTEC[10:9] (RW)
 *
 * Request to Send Edge Control . Selects the edge that triggers the RTS interrupt. This has no
 * effect on the RTS delta interrupt. RTEC has an effect only when RTSEN = 1 (see ).
 *
 * Values:
 * 00 - Trigger interrupt on a rising edge
 * 01 - Trigger interrupt on a falling edge
 * 1X - Trigger interrupt on any edge
 */

#define BP_UART_UCR2_RTEC      (9)      //!< Bit position for UART_UCR2_RTEC.
#define BM_UART_UCR2_RTEC      (0x00000600)  //!< Bit mask for UART_UCR2_RTEC.

//! @brief Get value of UART_UCR2_RTEC from a register value.
#define BG_UART_UCR2_RTEC(r)   (((r) & BM_UART_UCR2_RTEC) >> BP_UART_UCR2_RTEC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR2_RTEC.
#define BF_UART_UCR2_RTEC(v)   ((((reg32_t) v) << BP_UART_UCR2_RTEC) & BM_UART_UCR2_RTEC)
#else
//! @brief Format value for bitfield UART_UCR2_RTEC.
#define BF_UART_UCR2_RTEC(v)   (((v) << BP_UART_UCR2_RTEC) & BM_UART_UCR2_RTEC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RTEC field to a new value.
#define BW_UART_UCR2_RTEC(x, v)   (HW_UART_UCR2_WR(x, (HW_UART_UCR2_RD(x) & ~BM_UART_UCR2_RTEC) | BF_UART_UCR2_RTEC(v)))
#endif


/* --- Register HW_UART_UCR2, field ESCEN[11] (RW)
 *
 * Escape Enable . Enables/Disables the escape sequence detection logic.
 *
 * Values:
 * 0 - Disable escape sequence detection
 * 1 - Enable escape sequence detection
 */

#define BP_UART_UCR2_ESCEN      (11)      //!< Bit position for UART_UCR2_ESCEN.
#define BM_UART_UCR2_ESCEN      (0x00000800)  //!< Bit mask for UART_UCR2_ESCEN.

//! @brief Get value of UART_UCR2_ESCEN from a register value.
#define BG_UART_UCR2_ESCEN(r)   (((r) & BM_UART_UCR2_ESCEN) >> BP_UART_UCR2_ESCEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR2_ESCEN.
#define BF_UART_UCR2_ESCEN(v)   ((((reg32_t) v) << BP_UART_UCR2_ESCEN) & BM_UART_UCR2_ESCEN)
#else
//! @brief Format value for bitfield UART_UCR2_ESCEN.
#define BF_UART_UCR2_ESCEN(v)   (((v) << BP_UART_UCR2_ESCEN) & BM_UART_UCR2_ESCEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ESCEN field to a new value.
#define BW_UART_UCR2_ESCEN(x, v)   (HW_UART_UCR2_WR(x, (HW_UART_UCR2_RD(x) & ~BM_UART_UCR2_ESCEN) | BF_UART_UCR2_ESCEN(v)))
#endif


/* --- Register HW_UART_UCR2, field CTS[12] (RW)
 *
 * Clear to Send . Controls the CTS pin when the CTSC bit is negated. CTS has no function when CTSC
 * is asserted.
 *
 * Values:
 * 0 - The CTS pin is high (inactive)
 * 1 - The CTS pin is low (active)
 */

#define BP_UART_UCR2_CTS      (12)      //!< Bit position for UART_UCR2_CTS.
#define BM_UART_UCR2_CTS      (0x00001000)  //!< Bit mask for UART_UCR2_CTS.

//! @brief Get value of UART_UCR2_CTS from a register value.
#define BG_UART_UCR2_CTS(r)   (((r) & BM_UART_UCR2_CTS) >> BP_UART_UCR2_CTS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR2_CTS.
#define BF_UART_UCR2_CTS(v)   ((((reg32_t) v) << BP_UART_UCR2_CTS) & BM_UART_UCR2_CTS)
#else
//! @brief Format value for bitfield UART_UCR2_CTS.
#define BF_UART_UCR2_CTS(v)   (((v) << BP_UART_UCR2_CTS) & BM_UART_UCR2_CTS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CTS field to a new value.
#define BW_UART_UCR2_CTS(x, v)   (HW_UART_UCR2_WR(x, (HW_UART_UCR2_RD(x) & ~BM_UART_UCR2_CTS) | BF_UART_UCR2_CTS(v)))
#endif


/* --- Register HW_UART_UCR2, field CTSC[13] (RW)
 *
 * CTS Pin Control . Controls the operation of the CTS output pin. When CTSC is asserted, the CTS
 * output pin is controlled by the receiver. When the RxFIFO is filled to the level of the
 * programmed trigger level and the start bit of the overflowing character (TRIGGER LEVEL + 1) is
 * validated, the CTS output pin is negated to indicate to the far-end transmitter to stop
 * transmitting. When the trigger level is programmed for less than 32, the receiver continues to
 * receive data until the RxFIFO is full. When the CTSC bit is negated, the CTS output pin is
 * controlled by the CTS bit. On reset, because CTSC is cleared to 0, the CTS pin is controlled by
 * the CTS bit, which again is cleared to 0 on reset. This means that on reset the CTS signal is
 * negated.
 *
 * Values:
 * 0 - The CTS pin is controlled by the CTS bit
 * 1 - The CTS pin is controlled by the receiver
 */

#define BP_UART_UCR2_CTSC      (13)      //!< Bit position for UART_UCR2_CTSC.
#define BM_UART_UCR2_CTSC      (0x00002000)  //!< Bit mask for UART_UCR2_CTSC.

//! @brief Get value of UART_UCR2_CTSC from a register value.
#define BG_UART_UCR2_CTSC(r)   (((r) & BM_UART_UCR2_CTSC) >> BP_UART_UCR2_CTSC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR2_CTSC.
#define BF_UART_UCR2_CTSC(v)   ((((reg32_t) v) << BP_UART_UCR2_CTSC) & BM_UART_UCR2_CTSC)
#else
//! @brief Format value for bitfield UART_UCR2_CTSC.
#define BF_UART_UCR2_CTSC(v)   (((v) << BP_UART_UCR2_CTSC) & BM_UART_UCR2_CTSC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CTSC field to a new value.
#define BW_UART_UCR2_CTSC(x, v)   (HW_UART_UCR2_WR(x, (HW_UART_UCR2_RD(x) & ~BM_UART_UCR2_CTSC) | BF_UART_UCR2_CTSC(v)))
#endif


/* --- Register HW_UART_UCR2, field IRTS[14] (RW)
 *
 * Ignore RTS Pin . Forces the RTS input signal presented to the transmitter to always be asserted
 * (set to low), effectively ignoring the external pin. When in this mode, the RTS pin serves as a
 * general purpose input.
 *
 * Values:
 * 0 - Transmit only when the RTS pin is asserted
 * 1 - Ignore the RTS pin
 */

#define BP_UART_UCR2_IRTS      (14)      //!< Bit position for UART_UCR2_IRTS.
#define BM_UART_UCR2_IRTS      (0x00004000)  //!< Bit mask for UART_UCR2_IRTS.

//! @brief Get value of UART_UCR2_IRTS from a register value.
#define BG_UART_UCR2_IRTS(r)   (((r) & BM_UART_UCR2_IRTS) >> BP_UART_UCR2_IRTS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR2_IRTS.
#define BF_UART_UCR2_IRTS(v)   ((((reg32_t) v) << BP_UART_UCR2_IRTS) & BM_UART_UCR2_IRTS)
#else
//! @brief Format value for bitfield UART_UCR2_IRTS.
#define BF_UART_UCR2_IRTS(v)   (((v) << BP_UART_UCR2_IRTS) & BM_UART_UCR2_IRTS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IRTS field to a new value.
#define BW_UART_UCR2_IRTS(x, v)   (HW_UART_UCR2_WR(x, (HW_UART_UCR2_RD(x) & ~BM_UART_UCR2_IRTS) | BF_UART_UCR2_IRTS(v)))
#endif


/* --- Register HW_UART_UCR2, field ESCI[15] (RW)
 *
 * Escape Sequence Interrupt Enable . Enables/Disables the ESCF bit to generate an interrupt.
 *
 * Values:
 * 0 - Disable the escape sequence interrupt
 * 1 - Enable the escape sequence interrupt
 */

#define BP_UART_UCR2_ESCI      (15)      //!< Bit position for UART_UCR2_ESCI.
#define BM_UART_UCR2_ESCI      (0x00008000)  //!< Bit mask for UART_UCR2_ESCI.

//! @brief Get value of UART_UCR2_ESCI from a register value.
#define BG_UART_UCR2_ESCI(r)   (((r) & BM_UART_UCR2_ESCI) >> BP_UART_UCR2_ESCI)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR2_ESCI.
#define BF_UART_UCR2_ESCI(v)   ((((reg32_t) v) << BP_UART_UCR2_ESCI) & BM_UART_UCR2_ESCI)
#else
//! @brief Format value for bitfield UART_UCR2_ESCI.
#define BF_UART_UCR2_ESCI(v)   (((v) << BP_UART_UCR2_ESCI) & BM_UART_UCR2_ESCI)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ESCI field to a new value.
#define BW_UART_UCR2_ESCI(x, v)   (HW_UART_UCR2_WR(x, (HW_UART_UCR2_RD(x) & ~BM_UART_UCR2_ESCI) | BF_UART_UCR2_ESCI(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UART_UCR3 - UART Control Register 3 (RW)
 *
 * Reset value: 0x00000700
 *

 */
typedef union _hw_uart_ucr3
{
    reg32_t U;
    struct _hw_uart_ucr3_bitfields
    {
        unsigned ACIEN : 1; //!< [0] Autobaud Counter Interrupt Enable. This bit is used to enable the autobaud counter stopped interrupt (triggered with ACST (USR2[11]).
        unsigned INVT : 1; //!< [1] Invert TXD output in RS-232/RS-485 mode, set TXD active level in IrDA mode. In RS232/RS-485 mode(UMCR[0] = 1), if this bit is set to 1, the TXD output is inverted before transmitted. In IrDA mode , when INVT is cleared, the infrared logic block transmits a positive IR 3/16 pulse for all 0s and 0s are transmitted for 1s. When INVT is set (INVT = 1), the infrared logic block transmits an active low or negative infrared 3/16 pulse for all 0s and 1s are transmitted for 1s.
        unsigned RXDMUXSEL : 1; //!< [2] RXD Muxed Input Selected. Selects proper input pins for serial and Infrared input signal. In this chip, UARTs are used in MUXED mode, so that this bit should always be set. In this chip, UARTs are used in Non-MUXED mode, so that this bit should always be cleared. 0 Input pin RXD (ipp_uart_rxd_mux) is not used for serial and IR interfaces 1 Input pin RXD (ipp_uart_rxd_mux) is used for serial and IR interfaces 0 Serial input pin is UART_RXD (ipp_uart_rxd) and IrDA input pin is UART_RXD_IR (ipp_uart_rxd_ir) 1 Input pin UART_RXD (ipp_uart_rxd) and UART_RXD_IR (ipp_uart_rxd_ir) are not used
        unsigned DTRDEN : 1; //!< [3] This bit is not used in this chip. Data Terminal Ready Delta Enable . Enables / Disables the asynchronous DTRD interrupt. When DTRDEN is asserted and an edge (rising or falling) is detected on DTR (in DCE mode) or on DSR (in DTE mode), then an interrupt is generated.
        unsigned AWAKEN : 1; //!< [4] Asynchronous WAKE Interrupt Enable. Controls the asynchronous WAKE interrupt. An interrupt is generated when AWAKEN is asserted and a falling edge is detected on the RXD pin.
        unsigned AIRINTEN : 1; //!< [5] Asynchronous IR WAKE Interrupt Enable. Controls the asynchronous IR WAKE interrupt. An interrupt is generated when AIRINTEN is asserted and a pulse is detected on the RXD pin.
        unsigned RXDSEN : 1; //!< [6] Receive Status Interrupt Enable. Controls the receive status interrupt ( interrupt_rx interrupt_uart ). When this bit is enabled and RXDS status bit is set, the interrupt interrupt_rx interrupt_uart will be generated.
        unsigned ADNIMP : 1; //!< [7] Autobaud Detection Not Improved-. Disables new features of autobaud detection (See , for more details).
        unsigned RI : 1; //!< [8] This bit is not used in this chip. Ring Indicator . In DCE mode this bit is used by software to control the RI output pin for the modem interface. In DTE mode, when this bit is set, it will enable the status bit RIDELT (USR2 (10)) to cause an interrupt.
        unsigned DCD : 1; //!< [9] This bit is not used in this chip. Data Carrier Detect . In DCE mode this bit is used by software to control the DCD output pin for the modem interface. In DTE mode, when this bit is set, it will enable the status bit DCDDELT (USR2 (6)) to cause an interrupt.
        unsigned DSR : 1; //!< [10] This bit is not used in this chip. Data Set Ready . This bit is used by software to control the DSR/DTR output pin for the modem interface. In DCE mode it applies to DSR and in DTE mode it applies to DTR .
        unsigned FRAERREN : 1; //!< [11] Frame Error Interrupt Enable. Enables/Disables the interrupt. When asserted, FRAERREN causes the FRAMERR bit to generate an interrupt.
        unsigned PARERREN : 1; //!< [12] Parity Error Interrupt Enable. Enables/Disables the interrupt. When asserted, PARERREN causes the PARITYERR bit to generate an interrupt.
        unsigned DTREN : 1; //!< [13] This bit is not used in this chip. Data Terminal Ready Interrupt Enable . When this bit is set, it will enable the status bit DTRF (USR2 [13]) (DTR/DSR edge sensitive interrupt) to cause an interrupt.
        unsigned DPEC : 2; //!< [15:14] This bit is not used in this chip. DTR/DSR Interrupt Edge Control . These bits control the edge of DTR (DCE) or DSR (DTE) on which an interrupt will be generated. An interrupt will only be generated if the DTREN bit is set.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
    } B;
} hw_uart_ucr3_t;
#endif

/*
 * constants & macros for entire multi-block UART_UCR3 register
 */
#define HW_UART_UCR3_ADDR(x)      (REGS_UART_BASE(x) + 0x88)

#ifndef __LANGUAGE_ASM__
#define HW_UART_UCR3(x)           (*(volatile hw_uart_ucr3_t *) HW_UART_UCR3_ADDR(x))
#define HW_UART_UCR3_RD(x)        (HW_UART_UCR3(x).U)
#define HW_UART_UCR3_WR(x, v)     (HW_UART_UCR3(x).U = (v))
#define HW_UART_UCR3_SET(x, v)    (HW_UART_UCR3_WR(x, HW_UART_UCR3_RD(x) |  (v)))
#define HW_UART_UCR3_CLR(x, v)    (HW_UART_UCR3_WR(x, HW_UART_UCR3_RD(x) & ~(v)))
#define HW_UART_UCR3_TOG(x, v)    (HW_UART_UCR3_WR(x, HW_UART_UCR3_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UART_UCR3 bitfields
 */

/* --- Register HW_UART_UCR3, field ACIEN[0] (RW)
 *
 * Autobaud Counter Interrupt Enable. This bit is used to enable the autobaud counter stopped
 * interrupt (triggered with ACST (USR2[11]).
 *
 * Values:
 * 0 - ACST interrupt disabled
 * 1 - ACST interrupt enabled
 */

#define BP_UART_UCR3_ACIEN      (0)      //!< Bit position for UART_UCR3_ACIEN.
#define BM_UART_UCR3_ACIEN      (0x00000001)  //!< Bit mask for UART_UCR3_ACIEN.

//! @brief Get value of UART_UCR3_ACIEN from a register value.
#define BG_UART_UCR3_ACIEN(r)   (((r) & BM_UART_UCR3_ACIEN) >> BP_UART_UCR3_ACIEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR3_ACIEN.
#define BF_UART_UCR3_ACIEN(v)   ((((reg32_t) v) << BP_UART_UCR3_ACIEN) & BM_UART_UCR3_ACIEN)
#else
//! @brief Format value for bitfield UART_UCR3_ACIEN.
#define BF_UART_UCR3_ACIEN(v)   (((v) << BP_UART_UCR3_ACIEN) & BM_UART_UCR3_ACIEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ACIEN field to a new value.
#define BW_UART_UCR3_ACIEN(x, v)   (HW_UART_UCR3_WR(x, (HW_UART_UCR3_RD(x) & ~BM_UART_UCR3_ACIEN) | BF_UART_UCR3_ACIEN(v)))
#endif


/* --- Register HW_UART_UCR3, field INVT[1] (RW)
 *
 * Invert TXD output in RS-232/RS-485 mode, set TXD active level in IrDA mode. In RS232/RS-485
 * mode(UMCR[0] = 1), if this bit is set to 1, the TXD output is inverted before transmitted. In
 * IrDA mode , when INVT is cleared, the infrared logic block transmits a positive IR 3/16 pulse for
 * all 0s and 0s are transmitted for 1s. When INVT is set (INVT = 1), the infrared logic block
 * transmits an active low or negative infrared 3/16 pulse for all 0s and 1s are transmitted for 1s.
 *
 * Values:
 * 0 -  TXD is not inverted
 * 0 - TXD  Active low transmission
 * 1 -  TXD is inverted
 * 1 - TXD Active high transmission
 */

#define BP_UART_UCR3_INVT      (1)      //!< Bit position for UART_UCR3_INVT.
#define BM_UART_UCR3_INVT      (0x00000002)  //!< Bit mask for UART_UCR3_INVT.

//! @brief Get value of UART_UCR3_INVT from a register value.
#define BG_UART_UCR3_INVT(r)   (((r) & BM_UART_UCR3_INVT) >> BP_UART_UCR3_INVT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR3_INVT.
#define BF_UART_UCR3_INVT(v)   ((((reg32_t) v) << BP_UART_UCR3_INVT) & BM_UART_UCR3_INVT)
#else
//! @brief Format value for bitfield UART_UCR3_INVT.
#define BF_UART_UCR3_INVT(v)   (((v) << BP_UART_UCR3_INVT) & BM_UART_UCR3_INVT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INVT field to a new value.
#define BW_UART_UCR3_INVT(x, v)   (HW_UART_UCR3_WR(x, (HW_UART_UCR3_RD(x) & ~BM_UART_UCR3_INVT) | BF_UART_UCR3_INVT(v)))
#endif


/* --- Register HW_UART_UCR3, field RXDMUXSEL[2] (RW)
 *
 * RXD Muxed Input Selected. Selects proper input pins for serial and Infrared input signal. In this
 * chip, UARTs are used in MUXED mode, so that this bit should always be set. In this chip, UARTs
 * are used in Non-MUXED mode, so that this bit should always be cleared. 0 Input pin RXD
 * (ipp_uart_rxd_mux) is not used for serial and IR interfaces 1 Input pin RXD (ipp_uart_rxd_mux) is
 * used for serial and IR interfaces 0 Serial input pin is UART_RXD (ipp_uart_rxd) and IrDA input
 * pin is UART_RXD_IR (ipp_uart_rxd_ir) 1 Input pin UART_RXD (ipp_uart_rxd) and UART_RXD_IR
 * (ipp_uart_rxd_ir) are not used
 */

#define BP_UART_UCR3_RXDMUXSEL      (2)      //!< Bit position for UART_UCR3_RXDMUXSEL.
#define BM_UART_UCR3_RXDMUXSEL      (0x00000004)  //!< Bit mask for UART_UCR3_RXDMUXSEL.

//! @brief Get value of UART_UCR3_RXDMUXSEL from a register value.
#define BG_UART_UCR3_RXDMUXSEL(r)   (((r) & BM_UART_UCR3_RXDMUXSEL) >> BP_UART_UCR3_RXDMUXSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR3_RXDMUXSEL.
#define BF_UART_UCR3_RXDMUXSEL(v)   ((((reg32_t) v) << BP_UART_UCR3_RXDMUXSEL) & BM_UART_UCR3_RXDMUXSEL)
#else
//! @brief Format value for bitfield UART_UCR3_RXDMUXSEL.
#define BF_UART_UCR3_RXDMUXSEL(v)   (((v) << BP_UART_UCR3_RXDMUXSEL) & BM_UART_UCR3_RXDMUXSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDMUXSEL field to a new value.
#define BW_UART_UCR3_RXDMUXSEL(x, v)   (HW_UART_UCR3_WR(x, (HW_UART_UCR3_RD(x) & ~BM_UART_UCR3_RXDMUXSEL) | BF_UART_UCR3_RXDMUXSEL(v)))
#endif

/* --- Register HW_UART_UCR3, field DTRDEN[3] (RW)
 *
 * This bit is not used in this chip. Data Terminal Ready Delta Enable . Enables / Disables the
 * asynchronous DTRD interrupt. When DTRDEN is asserted and an edge (rising or falling) is detected
 * on DTR (in DCE mode) or on DSR (in DTE mode), then an interrupt is generated.
 *
 * Values:
 * 0 - Disable DTRD interrupt
 * 1 - Enable DTRD interrupt
 */

#define BP_UART_UCR3_DTRDEN      (3)      //!< Bit position for UART_UCR3_DTRDEN.
#define BM_UART_UCR3_DTRDEN      (0x00000008)  //!< Bit mask for UART_UCR3_DTRDEN.

//! @brief Get value of UART_UCR3_DTRDEN from a register value.
#define BG_UART_UCR3_DTRDEN(r)   (((r) & BM_UART_UCR3_DTRDEN) >> BP_UART_UCR3_DTRDEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR3_DTRDEN.
#define BF_UART_UCR3_DTRDEN(v)   ((((reg32_t) v) << BP_UART_UCR3_DTRDEN) & BM_UART_UCR3_DTRDEN)
#else
//! @brief Format value for bitfield UART_UCR3_DTRDEN.
#define BF_UART_UCR3_DTRDEN(v)   (((v) << BP_UART_UCR3_DTRDEN) & BM_UART_UCR3_DTRDEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DTRDEN field to a new value.
#define BW_UART_UCR3_DTRDEN(x, v)   (HW_UART_UCR3_WR(x, (HW_UART_UCR3_RD(x) & ~BM_UART_UCR3_DTRDEN) | BF_UART_UCR3_DTRDEN(v)))
#endif


/* --- Register HW_UART_UCR3, field AWAKEN[4] (RW)
 *
 * Asynchronous WAKE Interrupt Enable. Controls the asynchronous WAKE interrupt. An interrupt is
 * generated when AWAKEN is asserted and a falling edge is detected on the RXD pin.
 *
 * Values:
 * 0 - Disable the AWAKE interrupt
 * 1 - Enable the AWAKE interrupt
 */

#define BP_UART_UCR3_AWAKEN      (4)      //!< Bit position for UART_UCR3_AWAKEN.
#define BM_UART_UCR3_AWAKEN      (0x00000010)  //!< Bit mask for UART_UCR3_AWAKEN.

//! @brief Get value of UART_UCR3_AWAKEN from a register value.
#define BG_UART_UCR3_AWAKEN(r)   (((r) & BM_UART_UCR3_AWAKEN) >> BP_UART_UCR3_AWAKEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR3_AWAKEN.
#define BF_UART_UCR3_AWAKEN(v)   ((((reg32_t) v) << BP_UART_UCR3_AWAKEN) & BM_UART_UCR3_AWAKEN)
#else
//! @brief Format value for bitfield UART_UCR3_AWAKEN.
#define BF_UART_UCR3_AWAKEN(v)   (((v) << BP_UART_UCR3_AWAKEN) & BM_UART_UCR3_AWAKEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the AWAKEN field to a new value.
#define BW_UART_UCR3_AWAKEN(x, v)   (HW_UART_UCR3_WR(x, (HW_UART_UCR3_RD(x) & ~BM_UART_UCR3_AWAKEN) | BF_UART_UCR3_AWAKEN(v)))
#endif


/* --- Register HW_UART_UCR3, field AIRINTEN[5] (RW)
 *
 * Asynchronous IR WAKE Interrupt Enable. Controls the asynchronous IR WAKE interrupt. An interrupt
 * is generated when AIRINTEN is asserted and a pulse is detected on the RXD pin.
 *
 * Values:
 * 0 - Disable the AIRINT interrupt
 * 1 - Enable the AIRINT interrupt
 */

#define BP_UART_UCR3_AIRINTEN      (5)      //!< Bit position for UART_UCR3_AIRINTEN.
#define BM_UART_UCR3_AIRINTEN      (0x00000020)  //!< Bit mask for UART_UCR3_AIRINTEN.

//! @brief Get value of UART_UCR3_AIRINTEN from a register value.
#define BG_UART_UCR3_AIRINTEN(r)   (((r) & BM_UART_UCR3_AIRINTEN) >> BP_UART_UCR3_AIRINTEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR3_AIRINTEN.
#define BF_UART_UCR3_AIRINTEN(v)   ((((reg32_t) v) << BP_UART_UCR3_AIRINTEN) & BM_UART_UCR3_AIRINTEN)
#else
//! @brief Format value for bitfield UART_UCR3_AIRINTEN.
#define BF_UART_UCR3_AIRINTEN(v)   (((v) << BP_UART_UCR3_AIRINTEN) & BM_UART_UCR3_AIRINTEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the AIRINTEN field to a new value.
#define BW_UART_UCR3_AIRINTEN(x, v)   (HW_UART_UCR3_WR(x, (HW_UART_UCR3_RD(x) & ~BM_UART_UCR3_AIRINTEN) | BF_UART_UCR3_AIRINTEN(v)))
#endif


/* --- Register HW_UART_UCR3, field RXDSEN[6] (RW)
 *
 * Receive Status Interrupt Enable. Controls the receive status interrupt ( interrupt_rx
 * interrupt_uart ). When this bit is enabled and RXDS status bit is set, the interrupt interrupt_rx
 * interrupt_uart will be generated.
 *
 * Values:
 * 0 - Disable the RXDS interrupt
 * 1 - Enable the RXDS interrupt
 */

#define BP_UART_UCR3_RXDSEN      (6)      //!< Bit position for UART_UCR3_RXDSEN.
#define BM_UART_UCR3_RXDSEN      (0x00000040)  //!< Bit mask for UART_UCR3_RXDSEN.

//! @brief Get value of UART_UCR3_RXDSEN from a register value.
#define BG_UART_UCR3_RXDSEN(r)   (((r) & BM_UART_UCR3_RXDSEN) >> BP_UART_UCR3_RXDSEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR3_RXDSEN.
#define BF_UART_UCR3_RXDSEN(v)   ((((reg32_t) v) << BP_UART_UCR3_RXDSEN) & BM_UART_UCR3_RXDSEN)
#else
//! @brief Format value for bitfield UART_UCR3_RXDSEN.
#define BF_UART_UCR3_RXDSEN(v)   (((v) << BP_UART_UCR3_RXDSEN) & BM_UART_UCR3_RXDSEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDSEN field to a new value.
#define BW_UART_UCR3_RXDSEN(x, v)   (HW_UART_UCR3_WR(x, (HW_UART_UCR3_RD(x) & ~BM_UART_UCR3_RXDSEN) | BF_UART_UCR3_RXDSEN(v)))
#endif


/* --- Register HW_UART_UCR3, field ADNIMP[7] (RW)
 *
 * Autobaud Detection Not Improved-. Disables new features of autobaud detection (See , for more
 * details).
 *
 * Values:
 * 0 - Autobaud detection new features selected
 * 1 - Keep old autobaud detection mechanism
 */

#define BP_UART_UCR3_ADNIMP      (7)      //!< Bit position for UART_UCR3_ADNIMP.
#define BM_UART_UCR3_ADNIMP      (0x00000080)  //!< Bit mask for UART_UCR3_ADNIMP.

//! @brief Get value of UART_UCR3_ADNIMP from a register value.
#define BG_UART_UCR3_ADNIMP(r)   (((r) & BM_UART_UCR3_ADNIMP) >> BP_UART_UCR3_ADNIMP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR3_ADNIMP.
#define BF_UART_UCR3_ADNIMP(v)   ((((reg32_t) v) << BP_UART_UCR3_ADNIMP) & BM_UART_UCR3_ADNIMP)
#else
//! @brief Format value for bitfield UART_UCR3_ADNIMP.
#define BF_UART_UCR3_ADNIMP(v)   (((v) << BP_UART_UCR3_ADNIMP) & BM_UART_UCR3_ADNIMP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADNIMP field to a new value.
#define BW_UART_UCR3_ADNIMP(x, v)   (HW_UART_UCR3_WR(x, (HW_UART_UCR3_RD(x) & ~BM_UART_UCR3_ADNIMP) | BF_UART_UCR3_ADNIMP(v)))
#endif


/* --- Register HW_UART_UCR3, field RI[8] (RW)
 *
 * This bit is not used in this chip. Ring Indicator . In DCE mode this bit is used by software to
 * control the RI output pin for the modem interface. In DTE mode, when this bit is set, it will
 * enable the status bit RIDELT (USR2 (10)) to cause an interrupt.
 *
 * Values:
 * 0 - RI pin is logic zero (DCE mode)
 * 0 - RIDELT interrupt disabled (DTE mode)
 * 1 - RI pin is logic one (DCE mode)
 * 1 - RIDELT interrupt enabled (DTE mode)
 */

#define BP_UART_UCR3_RI      (8)      //!< Bit position for UART_UCR3_RI.
#define BM_UART_UCR3_RI      (0x00000100)  //!< Bit mask for UART_UCR3_RI.

//! @brief Get value of UART_UCR3_RI from a register value.
#define BG_UART_UCR3_RI(r)   (((r) & BM_UART_UCR3_RI) >> BP_UART_UCR3_RI)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR3_RI.
#define BF_UART_UCR3_RI(v)   ((((reg32_t) v) << BP_UART_UCR3_RI) & BM_UART_UCR3_RI)
#else
//! @brief Format value for bitfield UART_UCR3_RI.
#define BF_UART_UCR3_RI(v)   (((v) << BP_UART_UCR3_RI) & BM_UART_UCR3_RI)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RI field to a new value.
#define BW_UART_UCR3_RI(x, v)   (HW_UART_UCR3_WR(x, (HW_UART_UCR3_RD(x) & ~BM_UART_UCR3_RI) | BF_UART_UCR3_RI(v)))
#endif


/* --- Register HW_UART_UCR3, field DCD[9] (RW)
 *
 * This bit is not used in this chip. Data Carrier Detect . In DCE mode this bit is used by software
 * to control the DCD output pin for the modem interface. In DTE mode, when this bit is set, it will
 * enable the status bit DCDDELT (USR2 (6)) to cause an interrupt.
 *
 * Values:
 * 0 - DCD pin is logic zero (DCE mode)
 * 0 - DCDDELT interrupt disabled (DTE mode)
 * 1 - DCD pin is logic one (DCE mode)
 * 1 - DCDDELT interrupt enabled (DTE mode)
 */

#define BP_UART_UCR3_DCD      (9)      //!< Bit position for UART_UCR3_DCD.
#define BM_UART_UCR3_DCD      (0x00000200)  //!< Bit mask for UART_UCR3_DCD.

//! @brief Get value of UART_UCR3_DCD from a register value.
#define BG_UART_UCR3_DCD(r)   (((r) & BM_UART_UCR3_DCD) >> BP_UART_UCR3_DCD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR3_DCD.
#define BF_UART_UCR3_DCD(v)   ((((reg32_t) v) << BP_UART_UCR3_DCD) & BM_UART_UCR3_DCD)
#else
//! @brief Format value for bitfield UART_UCR3_DCD.
#define BF_UART_UCR3_DCD(v)   (((v) << BP_UART_UCR3_DCD) & BM_UART_UCR3_DCD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DCD field to a new value.
#define BW_UART_UCR3_DCD(x, v)   (HW_UART_UCR3_WR(x, (HW_UART_UCR3_RD(x) & ~BM_UART_UCR3_DCD) | BF_UART_UCR3_DCD(v)))
#endif


/* --- Register HW_UART_UCR3, field DSR[10] (RW)
 *
 * This bit is not used in this chip. Data Set Ready . This bit is used by software to control the
 * DSR/DTR output pin for the modem interface. In DCE mode it applies to DSR and in DTE mode it
 * applies to DTR .
 *
 * Values:
 * 0 - DSR/ DTR pin is logic zero
 * 1 - DSR/ DTR pin is logic one
 */

#define BP_UART_UCR3_DSR      (10)      //!< Bit position for UART_UCR3_DSR.
#define BM_UART_UCR3_DSR      (0x00000400)  //!< Bit mask for UART_UCR3_DSR.

//! @brief Get value of UART_UCR3_DSR from a register value.
#define BG_UART_UCR3_DSR(r)   (((r) & BM_UART_UCR3_DSR) >> BP_UART_UCR3_DSR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR3_DSR.
#define BF_UART_UCR3_DSR(v)   ((((reg32_t) v) << BP_UART_UCR3_DSR) & BM_UART_UCR3_DSR)
#else
//! @brief Format value for bitfield UART_UCR3_DSR.
#define BF_UART_UCR3_DSR(v)   (((v) << BP_UART_UCR3_DSR) & BM_UART_UCR3_DSR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DSR field to a new value.
#define BW_UART_UCR3_DSR(x, v)   (HW_UART_UCR3_WR(x, (HW_UART_UCR3_RD(x) & ~BM_UART_UCR3_DSR) | BF_UART_UCR3_DSR(v)))
#endif


/* --- Register HW_UART_UCR3, field FRAERREN[11] (RW)
 *
 * Frame Error Interrupt Enable. Enables/Disables the interrupt. When asserted, FRAERREN causes the
 * FRAMERR bit to generate an interrupt.
 *
 * Values:
 * 0 - Disable the frame error interrupt
 * 1 - Enable the frame error interrupt
 */

#define BP_UART_UCR3_FRAERREN      (11)      //!< Bit position for UART_UCR3_FRAERREN.
#define BM_UART_UCR3_FRAERREN      (0x00000800)  //!< Bit mask for UART_UCR3_FRAERREN.

//! @brief Get value of UART_UCR3_FRAERREN from a register value.
#define BG_UART_UCR3_FRAERREN(r)   (((r) & BM_UART_UCR3_FRAERREN) >> BP_UART_UCR3_FRAERREN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR3_FRAERREN.
#define BF_UART_UCR3_FRAERREN(v)   ((((reg32_t) v) << BP_UART_UCR3_FRAERREN) & BM_UART_UCR3_FRAERREN)
#else
//! @brief Format value for bitfield UART_UCR3_FRAERREN.
#define BF_UART_UCR3_FRAERREN(v)   (((v) << BP_UART_UCR3_FRAERREN) & BM_UART_UCR3_FRAERREN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FRAERREN field to a new value.
#define BW_UART_UCR3_FRAERREN(x, v)   (HW_UART_UCR3_WR(x, (HW_UART_UCR3_RD(x) & ~BM_UART_UCR3_FRAERREN) | BF_UART_UCR3_FRAERREN(v)))
#endif


/* --- Register HW_UART_UCR3, field PARERREN[12] (RW)
 *
 * Parity Error Interrupt Enable. Enables/Disables the interrupt. When asserted, PARERREN causes the
 * PARITYERR bit to generate an interrupt.
 *
 * Values:
 * 0 - Disable the parity error interrupt
 * 1 - Enable the parity error interrupt
 */

#define BP_UART_UCR3_PARERREN      (12)      //!< Bit position for UART_UCR3_PARERREN.
#define BM_UART_UCR3_PARERREN      (0x00001000)  //!< Bit mask for UART_UCR3_PARERREN.

//! @brief Get value of UART_UCR3_PARERREN from a register value.
#define BG_UART_UCR3_PARERREN(r)   (((r) & BM_UART_UCR3_PARERREN) >> BP_UART_UCR3_PARERREN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR3_PARERREN.
#define BF_UART_UCR3_PARERREN(v)   ((((reg32_t) v) << BP_UART_UCR3_PARERREN) & BM_UART_UCR3_PARERREN)
#else
//! @brief Format value for bitfield UART_UCR3_PARERREN.
#define BF_UART_UCR3_PARERREN(v)   (((v) << BP_UART_UCR3_PARERREN) & BM_UART_UCR3_PARERREN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PARERREN field to a new value.
#define BW_UART_UCR3_PARERREN(x, v)   (HW_UART_UCR3_WR(x, (HW_UART_UCR3_RD(x) & ~BM_UART_UCR3_PARERREN) | BF_UART_UCR3_PARERREN(v)))
#endif


/* --- Register HW_UART_UCR3, field DTREN[13] (RW)
 *
 * This bit is not used in this chip. Data Terminal Ready Interrupt Enable . When this bit is set,
 * it will enable the status bit DTRF (USR2 [13]) (DTR/DSR edge sensitive interrupt) to cause an
 * interrupt.
 *
 * Values:
 * 0 - Data Terminal Ready Interrupt Disabled
 * 1 - Data Terminal Ready Interrupt Enabled
 */

#define BP_UART_UCR3_DTREN      (13)      //!< Bit position for UART_UCR3_DTREN.
#define BM_UART_UCR3_DTREN      (0x00002000)  //!< Bit mask for UART_UCR3_DTREN.

//! @brief Get value of UART_UCR3_DTREN from a register value.
#define BG_UART_UCR3_DTREN(r)   (((r) & BM_UART_UCR3_DTREN) >> BP_UART_UCR3_DTREN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR3_DTREN.
#define BF_UART_UCR3_DTREN(v)   ((((reg32_t) v) << BP_UART_UCR3_DTREN) & BM_UART_UCR3_DTREN)
#else
//! @brief Format value for bitfield UART_UCR3_DTREN.
#define BF_UART_UCR3_DTREN(v)   (((v) << BP_UART_UCR3_DTREN) & BM_UART_UCR3_DTREN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DTREN field to a new value.
#define BW_UART_UCR3_DTREN(x, v)   (HW_UART_UCR3_WR(x, (HW_UART_UCR3_RD(x) & ~BM_UART_UCR3_DTREN) | BF_UART_UCR3_DTREN(v)))
#endif


/* --- Register HW_UART_UCR3, field DPEC[15:14] (RW)
 *
 * This bit is not used in this chip. DTR/DSR Interrupt Edge Control . These bits control the edge
 * of DTR (DCE) or DSR (DTE) on which an interrupt will be generated. An interrupt will only be
 * generated if the DTREN bit is set.
 *
 * Values:
 * 00 - interrupt generated on rising edge
 * 01 - interrupt generated on falling edge
 * 1X - interrupt generated on either edge
 */

#define BP_UART_UCR3_DPEC      (14)      //!< Bit position for UART_UCR3_DPEC.
#define BM_UART_UCR3_DPEC      (0x0000c000)  //!< Bit mask for UART_UCR3_DPEC.

//! @brief Get value of UART_UCR3_DPEC from a register value.
#define BG_UART_UCR3_DPEC(r)   (((r) & BM_UART_UCR3_DPEC) >> BP_UART_UCR3_DPEC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR3_DPEC.
#define BF_UART_UCR3_DPEC(v)   ((((reg32_t) v) << BP_UART_UCR3_DPEC) & BM_UART_UCR3_DPEC)
#else
//! @brief Format value for bitfield UART_UCR3_DPEC.
#define BF_UART_UCR3_DPEC(v)   (((v) << BP_UART_UCR3_DPEC) & BM_UART_UCR3_DPEC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DPEC field to a new value.
#define BW_UART_UCR3_DPEC(x, v)   (HW_UART_UCR3_WR(x, (HW_UART_UCR3_RD(x) & ~BM_UART_UCR3_DPEC) | BF_UART_UCR3_DPEC(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UART_UCR4 - UART Control Register 4 (RW)
 *
 * Reset value: 0x00008000
 *

 */
typedef union _hw_uart_ucr4
{
    reg32_t U;
    struct _hw_uart_ucr4_bitfields
    {
        unsigned DREN : 1; //!< [0] Receive Data Ready Interrupt Enable . Enables/Disables the RDR bit to generate an interrupt.
        unsigned OREN : 1; //!< [1] Receiver Overrun Interrupt Enable . Enables/Disables the ORE bit to generate an interrupt.
        unsigned BKEN : 1; //!< [2] BREAK Condition Detected Interrupt Enable . Enables/Disables the BRCD bit to generate an interrupt.
        unsigned TCEN : 1; //!< [3] Transmit Complete Interrupt Enable . Enables/Disables the TXDC bit to generate an interrupt ( interrupt_tx interrupt_uart = 0) An interrupt will be issued as long as TCEN and TXDC are high even if the transmitter is not enabled. In general, user should enable the transmitter before enabling the TXDC interrupt.
        unsigned LPBYP : 1; //!< [4] Low Power Bypass . Allows to bypass the low power new features in UART. To use during debug phase.
        unsigned IRSC : 1; //!< [5] IR Special Case . Selects the clock for the vote logic. When set, IRSC switches the vote logic clock from the sampling clock to the UART reference clock. The IR pulses are counted a predetermined amount of time depending on the reference frequency. See .
        unsigned IDDMAEN : 1; //!< [6] DMA IDLE Condition Detected Interrupt Enable Enables/Disables the receive DMA request dma_req_rx for the IDLE interrupt (triggered with IDLE flag in USR2[12]).
        unsigned WKEN : 1; //!< [7] WAKE Interrupt Enable . Enables/Disables the WAKE bit to generate an interrupt. The WAKE bit is set at the detection of a start bit by the receiver.
        unsigned ENIRI : 1; //!< [8] Serial Infrared Interrupt Enable . Enables/Disables the serial infrared interrupt.
        unsigned INVR : 1; //!< [9] Invert RXD input in RS-232/RS-485 Mode, d etermine RXD input logic level being sampled in In IrDA mode. In RS232/RS-485 Mode(UMCR[0] = 1), if this bit is set to 1, the RXD input is inverted before sampled. In IrDA mode ,when cleared, the infrared logic block expects an active low or negative IR 3/16 pulse for 0s and 1s are expected for 1s. When INVR is set (INVR 1), the infrared logic block expects an active high or positive IR 3/16 pulse for 0s and 0s are expected for 1s.
        unsigned CTSTL : 6; //!< [15:10] CTS Trigger Level . Controls the threshold at which the CTS pin is deasserted by the RxFIFO. After the trigger level is reached and the CTS pin is deasserted, the RxFIFO continues to receive data until it is full. The CTSTL bits are encoded as shown in the Settings column. Settings 0 to 32 are in use. All other settings are Reserved.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
    } B;
} hw_uart_ucr4_t;
#endif

/*
 * constants & macros for entire multi-block UART_UCR4 register
 */
#define HW_UART_UCR4_ADDR(x)      (REGS_UART_BASE(x) + 0x8c)

#ifndef __LANGUAGE_ASM__
#define HW_UART_UCR4(x)           (*(volatile hw_uart_ucr4_t *) HW_UART_UCR4_ADDR(x))
#define HW_UART_UCR4_RD(x)        (HW_UART_UCR4(x).U)
#define HW_UART_UCR4_WR(x, v)     (HW_UART_UCR4(x).U = (v))
#define HW_UART_UCR4_SET(x, v)    (HW_UART_UCR4_WR(x, HW_UART_UCR4_RD(x) |  (v)))
#define HW_UART_UCR4_CLR(x, v)    (HW_UART_UCR4_WR(x, HW_UART_UCR4_RD(x) & ~(v)))
#define HW_UART_UCR4_TOG(x, v)    (HW_UART_UCR4_WR(x, HW_UART_UCR4_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UART_UCR4 bitfields
 */

/* --- Register HW_UART_UCR4, field DREN[0] (RW)
 *
 * Receive Data Ready Interrupt Enable . Enables/Disables the RDR bit to generate an interrupt.
 *
 * Values:
 * 0 - Disable RDR interrupt
 * 1 - Enable RDR interrupt
 */

#define BP_UART_UCR4_DREN      (0)      //!< Bit position for UART_UCR4_DREN.
#define BM_UART_UCR4_DREN      (0x00000001)  //!< Bit mask for UART_UCR4_DREN.

//! @brief Get value of UART_UCR4_DREN from a register value.
#define BG_UART_UCR4_DREN(r)   (((r) & BM_UART_UCR4_DREN) >> BP_UART_UCR4_DREN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR4_DREN.
#define BF_UART_UCR4_DREN(v)   ((((reg32_t) v) << BP_UART_UCR4_DREN) & BM_UART_UCR4_DREN)
#else
//! @brief Format value for bitfield UART_UCR4_DREN.
#define BF_UART_UCR4_DREN(v)   (((v) << BP_UART_UCR4_DREN) & BM_UART_UCR4_DREN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DREN field to a new value.
#define BW_UART_UCR4_DREN(x, v)   (HW_UART_UCR4_WR(x, (HW_UART_UCR4_RD(x) & ~BM_UART_UCR4_DREN) | BF_UART_UCR4_DREN(v)))
#endif


/* --- Register HW_UART_UCR4, field OREN[1] (RW)
 *
 * Receiver Overrun Interrupt Enable . Enables/Disables the ORE bit to generate an interrupt.
 *
 * Values:
 * 0 - Disable ORE interrupt
 * 1 - Enable ORE interrupt
 */

#define BP_UART_UCR4_OREN      (1)      //!< Bit position for UART_UCR4_OREN.
#define BM_UART_UCR4_OREN      (0x00000002)  //!< Bit mask for UART_UCR4_OREN.

//! @brief Get value of UART_UCR4_OREN from a register value.
#define BG_UART_UCR4_OREN(r)   (((r) & BM_UART_UCR4_OREN) >> BP_UART_UCR4_OREN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR4_OREN.
#define BF_UART_UCR4_OREN(v)   ((((reg32_t) v) << BP_UART_UCR4_OREN) & BM_UART_UCR4_OREN)
#else
//! @brief Format value for bitfield UART_UCR4_OREN.
#define BF_UART_UCR4_OREN(v)   (((v) << BP_UART_UCR4_OREN) & BM_UART_UCR4_OREN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OREN field to a new value.
#define BW_UART_UCR4_OREN(x, v)   (HW_UART_UCR4_WR(x, (HW_UART_UCR4_RD(x) & ~BM_UART_UCR4_OREN) | BF_UART_UCR4_OREN(v)))
#endif


/* --- Register HW_UART_UCR4, field BKEN[2] (RW)
 *
 * BREAK Condition Detected Interrupt Enable . Enables/Disables the BRCD bit to generate an
 * interrupt.
 *
 * Values:
 * 0 - Disable the BRCD interrupt
 * 1 - Enable the BRCD interrupt
 */

#define BP_UART_UCR4_BKEN      (2)      //!< Bit position for UART_UCR4_BKEN.
#define BM_UART_UCR4_BKEN      (0x00000004)  //!< Bit mask for UART_UCR4_BKEN.

//! @brief Get value of UART_UCR4_BKEN from a register value.
#define BG_UART_UCR4_BKEN(r)   (((r) & BM_UART_UCR4_BKEN) >> BP_UART_UCR4_BKEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR4_BKEN.
#define BF_UART_UCR4_BKEN(v)   ((((reg32_t) v) << BP_UART_UCR4_BKEN) & BM_UART_UCR4_BKEN)
#else
//! @brief Format value for bitfield UART_UCR4_BKEN.
#define BF_UART_UCR4_BKEN(v)   (((v) << BP_UART_UCR4_BKEN) & BM_UART_UCR4_BKEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BKEN field to a new value.
#define BW_UART_UCR4_BKEN(x, v)   (HW_UART_UCR4_WR(x, (HW_UART_UCR4_RD(x) & ~BM_UART_UCR4_BKEN) | BF_UART_UCR4_BKEN(v)))
#endif


/* --- Register HW_UART_UCR4, field TCEN[3] (RW)
 *
 * Transmit Complete Interrupt Enable . Enables/Disables the TXDC bit to generate an interrupt (
 * interrupt_tx interrupt_uart = 0) An interrupt will be issued as long as TCEN and TXDC are high
 * even if the transmitter is not enabled. In general, user should enable the transmitter before
 * enabling the TXDC interrupt.
 *
 * Values:
 * 0 - Disable TXDC interrupt
 * 1 - Enable TXDC interrupt
 */

#define BP_UART_UCR4_TCEN      (3)      //!< Bit position for UART_UCR4_TCEN.
#define BM_UART_UCR4_TCEN      (0x00000008)  //!< Bit mask for UART_UCR4_TCEN.

//! @brief Get value of UART_UCR4_TCEN from a register value.
#define BG_UART_UCR4_TCEN(r)   (((r) & BM_UART_UCR4_TCEN) >> BP_UART_UCR4_TCEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR4_TCEN.
#define BF_UART_UCR4_TCEN(v)   ((((reg32_t) v) << BP_UART_UCR4_TCEN) & BM_UART_UCR4_TCEN)
#else
//! @brief Format value for bitfield UART_UCR4_TCEN.
#define BF_UART_UCR4_TCEN(v)   (((v) << BP_UART_UCR4_TCEN) & BM_UART_UCR4_TCEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCEN field to a new value.
#define BW_UART_UCR4_TCEN(x, v)   (HW_UART_UCR4_WR(x, (HW_UART_UCR4_RD(x) & ~BM_UART_UCR4_TCEN) | BF_UART_UCR4_TCEN(v)))
#endif


/* --- Register HW_UART_UCR4, field LPBYP[4] (RW)
 *
 * Low Power Bypass . Allows to bypass the low power new features in UART. To use during debug
 * phase.
 *
 * Values:
 * 0 - Low power features enabled
 * 1 - Low power features disabled
 */

#define BP_UART_UCR4_LPBYP      (4)      //!< Bit position for UART_UCR4_LPBYP.
#define BM_UART_UCR4_LPBYP      (0x00000010)  //!< Bit mask for UART_UCR4_LPBYP.

//! @brief Get value of UART_UCR4_LPBYP from a register value.
#define BG_UART_UCR4_LPBYP(r)   (((r) & BM_UART_UCR4_LPBYP) >> BP_UART_UCR4_LPBYP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR4_LPBYP.
#define BF_UART_UCR4_LPBYP(v)   ((((reg32_t) v) << BP_UART_UCR4_LPBYP) & BM_UART_UCR4_LPBYP)
#else
//! @brief Format value for bitfield UART_UCR4_LPBYP.
#define BF_UART_UCR4_LPBYP(v)   (((v) << BP_UART_UCR4_LPBYP) & BM_UART_UCR4_LPBYP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LPBYP field to a new value.
#define BW_UART_UCR4_LPBYP(x, v)   (HW_UART_UCR4_WR(x, (HW_UART_UCR4_RD(x) & ~BM_UART_UCR4_LPBYP) | BF_UART_UCR4_LPBYP(v)))
#endif


/* --- Register HW_UART_UCR4, field IRSC[5] (RW)
 *
 * IR Special Case . Selects the clock for the vote logic. When set, IRSC switches the vote logic
 * clock from the sampling clock to the UART reference clock. The IR pulses are counted a
 * predetermined amount of time depending on the reference frequency. See .
 *
 * Values:
 * 0 - The vote logic uses the sampling clock (16x baud rate) for normal operation
 * 1 - The vote logic uses the UART reference clock
 */

#define BP_UART_UCR4_IRSC      (5)      //!< Bit position for UART_UCR4_IRSC.
#define BM_UART_UCR4_IRSC      (0x00000020)  //!< Bit mask for UART_UCR4_IRSC.

//! @brief Get value of UART_UCR4_IRSC from a register value.
#define BG_UART_UCR4_IRSC(r)   (((r) & BM_UART_UCR4_IRSC) >> BP_UART_UCR4_IRSC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR4_IRSC.
#define BF_UART_UCR4_IRSC(v)   ((((reg32_t) v) << BP_UART_UCR4_IRSC) & BM_UART_UCR4_IRSC)
#else
//! @brief Format value for bitfield UART_UCR4_IRSC.
#define BF_UART_UCR4_IRSC(v)   (((v) << BP_UART_UCR4_IRSC) & BM_UART_UCR4_IRSC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IRSC field to a new value.
#define BW_UART_UCR4_IRSC(x, v)   (HW_UART_UCR4_WR(x, (HW_UART_UCR4_RD(x) & ~BM_UART_UCR4_IRSC) | BF_UART_UCR4_IRSC(v)))
#endif


/* --- Register HW_UART_UCR4, field IDDMAEN[6] (RW)
 *
 * DMA IDLE Condition Detected Interrupt Enable Enables/Disables the receive DMA request dma_req_rx
 * for the IDLE interrupt (triggered with IDLE flag in USR2[12]).
 *
 * Values:
 * 0 - DMA IDLE interrupt disabled
 * 1 - DMA IDLE interrupt enabled
 */

#define BP_UART_UCR4_IDDMAEN      (6)      //!< Bit position for UART_UCR4_IDDMAEN.
#define BM_UART_UCR4_IDDMAEN      (0x00000040)  //!< Bit mask for UART_UCR4_IDDMAEN.

//! @brief Get value of UART_UCR4_IDDMAEN from a register value.
#define BG_UART_UCR4_IDDMAEN(r)   (((r) & BM_UART_UCR4_IDDMAEN) >> BP_UART_UCR4_IDDMAEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR4_IDDMAEN.
#define BF_UART_UCR4_IDDMAEN(v)   ((((reg32_t) v) << BP_UART_UCR4_IDDMAEN) & BM_UART_UCR4_IDDMAEN)
#else
//! @brief Format value for bitfield UART_UCR4_IDDMAEN.
#define BF_UART_UCR4_IDDMAEN(v)   (((v) << BP_UART_UCR4_IDDMAEN) & BM_UART_UCR4_IDDMAEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IDDMAEN field to a new value.
#define BW_UART_UCR4_IDDMAEN(x, v)   (HW_UART_UCR4_WR(x, (HW_UART_UCR4_RD(x) & ~BM_UART_UCR4_IDDMAEN) | BF_UART_UCR4_IDDMAEN(v)))
#endif


/* --- Register HW_UART_UCR4, field WKEN[7] (RW)
 *
 * WAKE Interrupt Enable . Enables/Disables the WAKE bit to generate an interrupt. The WAKE bit is
 * set at the detection of a start bit by the receiver.
 *
 * Values:
 * 0 - Disable the WAKE interrupt
 * 1 - Enable the WAKE interrupt
 */

#define BP_UART_UCR4_WKEN      (7)      //!< Bit position for UART_UCR4_WKEN.
#define BM_UART_UCR4_WKEN      (0x00000080)  //!< Bit mask for UART_UCR4_WKEN.

//! @brief Get value of UART_UCR4_WKEN from a register value.
#define BG_UART_UCR4_WKEN(r)   (((r) & BM_UART_UCR4_WKEN) >> BP_UART_UCR4_WKEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR4_WKEN.
#define BF_UART_UCR4_WKEN(v)   ((((reg32_t) v) << BP_UART_UCR4_WKEN) & BM_UART_UCR4_WKEN)
#else
//! @brief Format value for bitfield UART_UCR4_WKEN.
#define BF_UART_UCR4_WKEN(v)   (((v) << BP_UART_UCR4_WKEN) & BM_UART_UCR4_WKEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WKEN field to a new value.
#define BW_UART_UCR4_WKEN(x, v)   (HW_UART_UCR4_WR(x, (HW_UART_UCR4_RD(x) & ~BM_UART_UCR4_WKEN) | BF_UART_UCR4_WKEN(v)))
#endif


/* --- Register HW_UART_UCR4, field ENIRI[8] (RW)
 *
 * Serial Infrared Interrupt Enable . Enables/Disables the serial infrared interrupt.
 *
 * Values:
 * 0 - Serial infrared Interrupt disabled
 * 1 - Serial infrared Interrupt enabled
 */

#define BP_UART_UCR4_ENIRI      (8)      //!< Bit position for UART_UCR4_ENIRI.
#define BM_UART_UCR4_ENIRI      (0x00000100)  //!< Bit mask for UART_UCR4_ENIRI.

//! @brief Get value of UART_UCR4_ENIRI from a register value.
#define BG_UART_UCR4_ENIRI(r)   (((r) & BM_UART_UCR4_ENIRI) >> BP_UART_UCR4_ENIRI)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR4_ENIRI.
#define BF_UART_UCR4_ENIRI(v)   ((((reg32_t) v) << BP_UART_UCR4_ENIRI) & BM_UART_UCR4_ENIRI)
#else
//! @brief Format value for bitfield UART_UCR4_ENIRI.
#define BF_UART_UCR4_ENIRI(v)   (((v) << BP_UART_UCR4_ENIRI) & BM_UART_UCR4_ENIRI)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRI field to a new value.
#define BW_UART_UCR4_ENIRI(x, v)   (HW_UART_UCR4_WR(x, (HW_UART_UCR4_RD(x) & ~BM_UART_UCR4_ENIRI) | BF_UART_UCR4_ENIRI(v)))
#endif


/* --- Register HW_UART_UCR4, field INVR[9] (RW)
 *
 * Invert RXD input in RS-232/RS-485 Mode, d etermine RXD input logic level being sampled in In IrDA
 * mode. In RS232/RS-485 Mode(UMCR[0] = 1), if this bit is set to 1, the RXD input is inverted
 * before sampled. In IrDA mode ,when cleared, the infrared logic block expects an active low or
 * negative IR 3/16 pulse for 0s and 1s are expected for 1s. When INVR is set (INVR 1), the infrared
 * logic block expects an active high or positive IR 3/16 pulse for 0s and 0s are expected for 1s.
 *
 * Values:
 * 0 -  RXD input is not inverted
 * 0 - RXD active low detection
 * 1 -  RXD input is inverted
 * 1 - RXD active high detection
 */

#define BP_UART_UCR4_INVR      (9)      //!< Bit position for UART_UCR4_INVR.
#define BM_UART_UCR4_INVR      (0x00000200)  //!< Bit mask for UART_UCR4_INVR.

//! @brief Get value of UART_UCR4_INVR from a register value.
#define BG_UART_UCR4_INVR(r)   (((r) & BM_UART_UCR4_INVR) >> BP_UART_UCR4_INVR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR4_INVR.
#define BF_UART_UCR4_INVR(v)   ((((reg32_t) v) << BP_UART_UCR4_INVR) & BM_UART_UCR4_INVR)
#else
//! @brief Format value for bitfield UART_UCR4_INVR.
#define BF_UART_UCR4_INVR(v)   (((v) << BP_UART_UCR4_INVR) & BM_UART_UCR4_INVR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INVR field to a new value.
#define BW_UART_UCR4_INVR(x, v)   (HW_UART_UCR4_WR(x, (HW_UART_UCR4_RD(x) & ~BM_UART_UCR4_INVR) | BF_UART_UCR4_INVR(v)))
#endif


/* --- Register HW_UART_UCR4, field CTSTL[15:10] (RW)
 *
 * CTS Trigger Level . Controls the threshold at which the CTS pin is deasserted by the RxFIFO.
 * After the trigger level is reached and the CTS pin is deasserted, the RxFIFO continues to receive
 * data until it is full. The CTSTL bits are encoded as shown in the Settings column. Settings 0 to
 * 32 are in use. All other settings are Reserved.
 *
 * Values:
 * 000000 - 0 characters received
 * ... - 
 * ... - 
 * 000001 - 1 characters in the RxFIFO
 * 100000 - 32 characters in the RxFIFO (maximum)
 */

#define BP_UART_UCR4_CTSTL      (10)      //!< Bit position for UART_UCR4_CTSTL.
#define BM_UART_UCR4_CTSTL      (0x0000fc00)  //!< Bit mask for UART_UCR4_CTSTL.

//! @brief Get value of UART_UCR4_CTSTL from a register value.
#define BG_UART_UCR4_CTSTL(r)   (((r) & BM_UART_UCR4_CTSTL) >> BP_UART_UCR4_CTSTL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UCR4_CTSTL.
#define BF_UART_UCR4_CTSTL(v)   ((((reg32_t) v) << BP_UART_UCR4_CTSTL) & BM_UART_UCR4_CTSTL)
#else
//! @brief Format value for bitfield UART_UCR4_CTSTL.
#define BF_UART_UCR4_CTSTL(v)   (((v) << BP_UART_UCR4_CTSTL) & BM_UART_UCR4_CTSTL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CTSTL field to a new value.
#define BW_UART_UCR4_CTSTL(x, v)   (HW_UART_UCR4_WR(x, (HW_UART_UCR4_RD(x) & ~BM_UART_UCR4_CTSTL) | BF_UART_UCR4_CTSTL(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UART_UFCR - UART FIFO Control Register (RW)
 *
 * Reset value: 0x00000801
 *

 */
typedef union _hw_uart_ufcr
{
    reg32_t U;
    struct _hw_uart_ufcr_bitfields
    {
        unsigned RXTL : 6; //!< [5:0] Receiver Trigger Level . Controls the threshold at which a maskable interrupt is generated by the RxFIFO. A maskable interrupt is generated whenever the data level in the RxFIFO reaches the selected threshold. The RXTL bits are encoded as shown in the Settings column. Setting 0 to 32 are in use. All other settings are Reserved.
        unsigned DCEDTE : 1; //!< [6] DCE/DTE mode select . Select UART as data communication equipment (DCE mode) or as data terminal equipment (DTE mode).
        unsigned RFDIV : 3; //!< [9:7] Reference Frequency Divider. Controls the divide ratio for the reference clock. The input clock is module_clock (ipg_perclk) . The output from the divider is ref_clk which is used by BRM to create the 16x baud rate oversampling clock ( brm_clk ).
        unsigned TXTL : 6; //!< [15:10] Transmitter Trigger Level . Controls the threshold at which a maskable interrupt is generated by the TxFIFO. A maskable interrupt is generated whenever the data level in the TxFIFO falls below the selected threshold. The bits are encoded as shown in the Settings column. Settings 0 to 32 are in use. All other settings are Reserved.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
    } B;
} hw_uart_ufcr_t;
#endif

/*
 * constants & macros for entire multi-block UART_UFCR register
 */
#define HW_UART_UFCR_ADDR(x)      (REGS_UART_BASE(x) + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_UART_UFCR(x)           (*(volatile hw_uart_ufcr_t *) HW_UART_UFCR_ADDR(x))
#define HW_UART_UFCR_RD(x)        (HW_UART_UFCR(x).U)
#define HW_UART_UFCR_WR(x, v)     (HW_UART_UFCR(x).U = (v))
#define HW_UART_UFCR_SET(x, v)    (HW_UART_UFCR_WR(x, HW_UART_UFCR_RD(x) |  (v)))
#define HW_UART_UFCR_CLR(x, v)    (HW_UART_UFCR_WR(x, HW_UART_UFCR_RD(x) & ~(v)))
#define HW_UART_UFCR_TOG(x, v)    (HW_UART_UFCR_WR(x, HW_UART_UFCR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UART_UFCR bitfields
 */

/* --- Register HW_UART_UFCR, field RXTL[5:0] (RW)
 *
 * Receiver Trigger Level . Controls the threshold at which a maskable interrupt is generated by the
 * RxFIFO. A maskable interrupt is generated whenever the data level in the RxFIFO reaches the
 * selected threshold. The RXTL bits are encoded as shown in the Settings column. Setting 0 to 32
 * are in use. All other settings are Reserved.
 *
 * Values:
 * 000000 - 0 characters received
 * ... - 
 * ... - 
 * 000001 - RxFIFO has 1 character
 * 011111 - RxFIFO has 31 characters
 * 100000 - RxFIFO has 32 characters (maximum)
 */

#define BP_UART_UFCR_RXTL      (0)      //!< Bit position for UART_UFCR_RXTL.
#define BM_UART_UFCR_RXTL      (0x0000003f)  //!< Bit mask for UART_UFCR_RXTL.

//! @brief Get value of UART_UFCR_RXTL from a register value.
#define BG_UART_UFCR_RXTL(r)   (((r) & BM_UART_UFCR_RXTL) >> BP_UART_UFCR_RXTL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UFCR_RXTL.
#define BF_UART_UFCR_RXTL(v)   ((((reg32_t) v) << BP_UART_UFCR_RXTL) & BM_UART_UFCR_RXTL)
#else
//! @brief Format value for bitfield UART_UFCR_RXTL.
#define BF_UART_UFCR_RXTL(v)   (((v) << BP_UART_UFCR_RXTL) & BM_UART_UFCR_RXTL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXTL field to a new value.
#define BW_UART_UFCR_RXTL(x, v)   (HW_UART_UFCR_WR(x, (HW_UART_UFCR_RD(x) & ~BM_UART_UFCR_RXTL) | BF_UART_UFCR_RXTL(v)))
#endif


/* --- Register HW_UART_UFCR, field DCEDTE[6] (RW)
 *
 * DCE/DTE mode select . Select UART as data communication equipment (DCE mode) or as data terminal
 * equipment (DTE mode).
 *
 * Values:
 * 0 - DCE mode selected
 * 1 - DTE mode selected
 */

#define BP_UART_UFCR_DCEDTE      (6)      //!< Bit position for UART_UFCR_DCEDTE.
#define BM_UART_UFCR_DCEDTE      (0x00000040)  //!< Bit mask for UART_UFCR_DCEDTE.

//! @brief Get value of UART_UFCR_DCEDTE from a register value.
#define BG_UART_UFCR_DCEDTE(r)   (((r) & BM_UART_UFCR_DCEDTE) >> BP_UART_UFCR_DCEDTE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UFCR_DCEDTE.
#define BF_UART_UFCR_DCEDTE(v)   ((((reg32_t) v) << BP_UART_UFCR_DCEDTE) & BM_UART_UFCR_DCEDTE)
#else
//! @brief Format value for bitfield UART_UFCR_DCEDTE.
#define BF_UART_UFCR_DCEDTE(v)   (((v) << BP_UART_UFCR_DCEDTE) & BM_UART_UFCR_DCEDTE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DCEDTE field to a new value.
#define BW_UART_UFCR_DCEDTE(x, v)   (HW_UART_UFCR_WR(x, (HW_UART_UFCR_RD(x) & ~BM_UART_UFCR_DCEDTE) | BF_UART_UFCR_DCEDTE(v)))
#endif


/* --- Register HW_UART_UFCR, field RFDIV[9:7] (RW)
 *
 * Reference Frequency Divider. Controls the divide ratio for the reference clock. The input clock
 * is module_clock (ipg_perclk) . The output from the divider is ref_clk which is used by BRM to
 * create the 16x baud rate oversampling clock ( brm_clk ).
 *
 * Values:
 * 000 - Divide input clock by 6
 * 001 - Divide input clock by 5
 * 010 - Divide input clock by 4
 * 011 - Divide input clock by 3
 * 100 - Divide input clock by 2
 * 101 - Divide input clock by 1
 * 110 - Divide input clock by 7
 * 111 - Reserved
 */

#define BP_UART_UFCR_RFDIV      (7)      //!< Bit position for UART_UFCR_RFDIV.
#define BM_UART_UFCR_RFDIV      (0x00000380)  //!< Bit mask for UART_UFCR_RFDIV.

//! @brief Get value of UART_UFCR_RFDIV from a register value.
#define BG_UART_UFCR_RFDIV(r)   (((r) & BM_UART_UFCR_RFDIV) >> BP_UART_UFCR_RFDIV)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UFCR_RFDIV.
#define BF_UART_UFCR_RFDIV(v)   ((((reg32_t) v) << BP_UART_UFCR_RFDIV) & BM_UART_UFCR_RFDIV)
#else
//! @brief Format value for bitfield UART_UFCR_RFDIV.
#define BF_UART_UFCR_RFDIV(v)   (((v) << BP_UART_UFCR_RFDIV) & BM_UART_UFCR_RFDIV)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFDIV field to a new value.
#define BW_UART_UFCR_RFDIV(x, v)   (HW_UART_UFCR_WR(x, (HW_UART_UFCR_RD(x) & ~BM_UART_UFCR_RFDIV) | BF_UART_UFCR_RFDIV(v)))
#endif


/* --- Register HW_UART_UFCR, field TXTL[15:10] (RW)
 *
 * Transmitter Trigger Level . Controls the threshold at which a maskable interrupt is generated by
 * the TxFIFO. A maskable interrupt is generated whenever the data level in the TxFIFO falls below
 * the selected threshold. The bits are encoded as shown in the Settings column. Settings 0 to 32
 * are in use. All other settings are Reserved.
 *
 * Values:
 * 000000 - Reserved
 * ... - 
 * ... - 
 * 000001 - Reserved
 * 000010 - TxFIFO has 2 or fewer characters
 * 011111 - TxFIFO has 31 or fewer characters
 * 100000 - TxFIFO has 32 characters (maximum)
 */

#define BP_UART_UFCR_TXTL      (10)      //!< Bit position for UART_UFCR_TXTL.
#define BM_UART_UFCR_TXTL      (0x0000fc00)  //!< Bit mask for UART_UFCR_TXTL.

//! @brief Get value of UART_UFCR_TXTL from a register value.
#define BG_UART_UFCR_TXTL(r)   (((r) & BM_UART_UFCR_TXTL) >> BP_UART_UFCR_TXTL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UFCR_TXTL.
#define BF_UART_UFCR_TXTL(v)   ((((reg32_t) v) << BP_UART_UFCR_TXTL) & BM_UART_UFCR_TXTL)
#else
//! @brief Format value for bitfield UART_UFCR_TXTL.
#define BF_UART_UFCR_TXTL(v)   (((v) << BP_UART_UFCR_TXTL) & BM_UART_UFCR_TXTL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXTL field to a new value.
#define BW_UART_UFCR_TXTL(x, v)   (HW_UART_UFCR_WR(x, (HW_UART_UFCR_RD(x) & ~BM_UART_UFCR_TXTL) | BF_UART_UFCR_TXTL(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UART_USR1 - UART Status Register 1 (RW)
 *
 * Reset value: 0x00002040
 *

 */
typedef union _hw_uart_usr1
{
    reg32_t U;
    struct _hw_uart_usr1_bitfields
    {
        unsigned RESERVED0 : 3; //!< [2:0] Reserved
        unsigned SAD : 1; //!< [3] RS-485 Slave Address Detected Interrupt Flag. Indicates if RS-485 Slave Address was detected . SAD was asserted in RS-485 mode when the SADEN bit is set and Slave Address is detected in RxFIFO (in Nomal Address Detect Mode, the 9 th data bit = 1; in Automatic Address Detect Mode, the received charater matches the programmed SLADDR).
        unsigned AWAKE : 1; //!< [4] Asynchronous WAKE Interrupt Flag. Indicates that a falling edge was detected on the UART_RXD_IR RXD pin. Clear AWAKE by writing 1 to it. Writing 0 to AWAKE has no effect. Caution: AWAKE Interrupt flag is affected by external RXD pin whether in loopback mode (UTS[12] = 1'b1) or not (see UART RS-485 Mode Control Register ).
        unsigned AIRINT : 1; //!< [5] Asynchronous IR WAKE Interrupt Flag. Indicates that the IR WAKE pulse was detected on the UART_RXD_IR RXD pin. Clear AIRINT by writing 1 to it. Writing 0 to AIRINT has no effect. Caution: AIRINT Interrupt flag is affected by external RXD pin whether in loopback mode (UTS[12] = 1'b1) or not (see ).
        unsigned RXDS : 1; //!< [6] Receiver IDLE Interrupt Flag. Indicates that the receiver state machine is in an IDLE state, the next state is IDLE, and the receive pin is high. RXDS is automatically cleared when a character is received. RXDS is active only when the receiver is enabled.
        unsigned DTRD : 1; //!< [7] This bit is not used in this chip. DTR Delta. Indicates whether DTR (in DCE mode) or DSR (in DTE mode) pins changed state. DTRD generates a maskable interrupt if DTRDEN (UCR3[3]) is set. Clear DTRD by writing 1 to it. Writing 0 to DTRD has no effect.
        unsigned AGTIM : 1; //!< [8] Ageing Timer Interrupt Flag. Indicates that data in the RxFIFO has been idle for a time of 8 character lengths (where a character length consists of 7 or 8 bits, depending on the setting of the WS bit in UCR2, with the bit time corresponding to the baud rate setting) and FIFO data level is less than RxFIFO threshold level (RXTL in the UFCR). Clear by writing a 1 to it.
        unsigned RRDY : 1; //!< [9] Receiver Ready Interrupt / DMA Flag . Indicates that the RxFIFO data level is above the threshold set by the RXTL bits. (See the RXTL bits description in for setting the interrupt threshold.) When asserted, RRDY generates a maskable interrupt or DMA request. RRDY is automatically cleared when data level in the RxFIFO goes below the set threshold level. At reset, RRDY is set to 0.
        unsigned FRAMERR : 1; //!< [10] Frame Error Interrupt Flag . Indicates that a frame error is detected. The interrupt_mint interrupt_uart interrupt will be generated if a frame error is detected and the interrupt is enabled. Clear FRAMERR by writing 1 to it. Writing 0 to FRAMERR has no effect.
        unsigned ESCF : 1; //!< [11] Escape Sequence Interrupt Flag . Indicates if an escape sequence was detected. ESCF is asserted when the ESCEN bit is set and an escape sequence is detected in the RxFIFO. Clear ESCF by writing 1 to it. Writing 0 to ESCF has no effect.
        unsigned RTSD : 1; //!< [12] RTS Delta. Indicates whether the RTS pin changed state. It (RTSD) generates a maskable interrupt. When in STOP mode, RTS assertion sets RTSD and can be used to wake the processor. The current state of the RTS pin is available on the RTSS bit. Clear RTSD by writing 1 to it. Writing 0 to RTSD has no effect. At reset, RTSD is set to 0.
        unsigned TRDY : 1; //!< [13] Transmitter Ready Interrupt / DMA Flag . Indicates that the TxFIFO emptied below its target threshold and requires data. TRDY is automatically cleared when the data level in the TxFIFO exceeds the threshold set by TXTL bits. At reset, TRDY is set to 1.
        unsigned RTSS : 1; //!< [14] RTS Pin Status . Indicates the current status of the RTS pin. A "snapshot" of the pin is taken immediately before RTSS is presented to the data bus. RTSS cannot be cleared because all writes to RTSS are ignored. At reset, RTSS is set to 0.
        unsigned PARITYERR : 1; //!< [15] Parity Error Interrupt Flag . Indicates a parity error is detected. PARITYERR is cleared by writing 1 to it. Writing 0 to PARITYERR has no effect. When parity is disabled, PARITYERR always reads 0. At reset, PARITYERR is set to 0.
        unsigned RESERVED1 : 16; //!< [31:16] Reserved
    } B;
} hw_uart_usr1_t;
#endif

/*
 * constants & macros for entire multi-block UART_USR1 register
 */
#define HW_UART_USR1_ADDR(x)      (REGS_UART_BASE(x) + 0x94)

#ifndef __LANGUAGE_ASM__
#define HW_UART_USR1(x)           (*(volatile hw_uart_usr1_t *) HW_UART_USR1_ADDR(x))
#define HW_UART_USR1_RD(x)        (HW_UART_USR1(x).U)
#define HW_UART_USR1_WR(x, v)     (HW_UART_USR1(x).U = (v))
#define HW_UART_USR1_SET(x, v)    (HW_UART_USR1_WR(x, HW_UART_USR1_RD(x) |  (v)))
#define HW_UART_USR1_CLR(x, v)    (HW_UART_USR1_WR(x, HW_UART_USR1_RD(x) & ~(v)))
#define HW_UART_USR1_TOG(x, v)    (HW_UART_USR1_WR(x, HW_UART_USR1_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UART_USR1 bitfields
 */

/* --- Register HW_UART_USR1, field SAD[3] (W1C)
 *
 * RS-485 Slave Address Detected Interrupt Flag. Indicates if RS-485 Slave Address was detected .
 * SAD was asserted in RS-485 mode when the SADEN bit is set and Slave Address is detected in RxFIFO
 * (in Nomal Address Detect Mode, the 9 th data bit = 1; in Automatic Address Detect Mode, the
 * received charater matches the programmed SLADDR).
 *
 * Values:
 * 0 - No slave address detected
 * 1 - Slave address detected
 */

#define BP_UART_USR1_SAD      (3)      //!< Bit position for UART_USR1_SAD.
#define BM_UART_USR1_SAD      (0x00000008)  //!< Bit mask for UART_USR1_SAD.

//! @brief Get value of UART_USR1_SAD from a register value.
#define BG_UART_USR1_SAD(r)   (((r) & BM_UART_USR1_SAD) >> BP_UART_USR1_SAD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR1_SAD.
#define BF_UART_USR1_SAD(v)   ((((reg32_t) v) << BP_UART_USR1_SAD) & BM_UART_USR1_SAD)
#else
//! @brief Format value for bitfield UART_USR1_SAD.
#define BF_UART_USR1_SAD(v)   (((v) << BP_UART_USR1_SAD) & BM_UART_USR1_SAD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SAD field to a new value.
#define BW_UART_USR1_SAD(x, v)   (HW_UART_USR1_WR(x, (HW_UART_USR1_RD(x) & ~BM_UART_USR1_SAD) | BF_UART_USR1_SAD(v)))
#endif


/* --- Register HW_UART_USR1, field AWAKE[4] (W1C)
 *
 * Asynchronous WAKE Interrupt Flag. Indicates that a falling edge was detected on the UART_RXD_IR
 * RXD pin. Clear AWAKE by writing 1 to it. Writing 0 to AWAKE has no effect. Caution: AWAKE
 * Interrupt flag is affected by external RXD pin whether in loopback mode (UTS[12] = 1'b1) or not
 * (see UART RS-485 Mode Control Register ).
 *
 * Values:
 * 0 - No falling edge was detected on the RXD Serial pin
 * 1 - A falling edge was detected on the RXD Serial pin
 */

#define BP_UART_USR1_AWAKE      (4)      //!< Bit position for UART_USR1_AWAKE.
#define BM_UART_USR1_AWAKE      (0x00000010)  //!< Bit mask for UART_USR1_AWAKE.

//! @brief Get value of UART_USR1_AWAKE from a register value.
#define BG_UART_USR1_AWAKE(r)   (((r) & BM_UART_USR1_AWAKE) >> BP_UART_USR1_AWAKE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR1_AWAKE.
#define BF_UART_USR1_AWAKE(v)   ((((reg32_t) v) << BP_UART_USR1_AWAKE) & BM_UART_USR1_AWAKE)
#else
//! @brief Format value for bitfield UART_USR1_AWAKE.
#define BF_UART_USR1_AWAKE(v)   (((v) << BP_UART_USR1_AWAKE) & BM_UART_USR1_AWAKE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the AWAKE field to a new value.
#define BW_UART_USR1_AWAKE(x, v)   (HW_UART_USR1_WR(x, (HW_UART_USR1_RD(x) & ~BM_UART_USR1_AWAKE) | BF_UART_USR1_AWAKE(v)))
#endif


/* --- Register HW_UART_USR1, field AIRINT[5] (W1C)
 *
 * Asynchronous IR WAKE Interrupt Flag. Indicates that the IR WAKE pulse was detected on the
 * UART_RXD_IR RXD pin. Clear AIRINT by writing 1 to it. Writing 0 to AIRINT has no effect. Caution:
 * AIRINT Interrupt flag is affected by external RXD pin whether in loopback mode (UTS[12] = 1'b1)
 * or not (see ).
 *
 * Values:
 * 0 - No pulse was detected on the RXD IrDA pin
 * 1 - A pulse was detected on the RXD IrDA pin
 */

#define BP_UART_USR1_AIRINT      (5)      //!< Bit position for UART_USR1_AIRINT.
#define BM_UART_USR1_AIRINT      (0x00000020)  //!< Bit mask for UART_USR1_AIRINT.

//! @brief Get value of UART_USR1_AIRINT from a register value.
#define BG_UART_USR1_AIRINT(r)   (((r) & BM_UART_USR1_AIRINT) >> BP_UART_USR1_AIRINT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR1_AIRINT.
#define BF_UART_USR1_AIRINT(v)   ((((reg32_t) v) << BP_UART_USR1_AIRINT) & BM_UART_USR1_AIRINT)
#else
//! @brief Format value for bitfield UART_USR1_AIRINT.
#define BF_UART_USR1_AIRINT(v)   (((v) << BP_UART_USR1_AIRINT) & BM_UART_USR1_AIRINT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the AIRINT field to a new value.
#define BW_UART_USR1_AIRINT(x, v)   (HW_UART_USR1_WR(x, (HW_UART_USR1_RD(x) & ~BM_UART_USR1_AIRINT) | BF_UART_USR1_AIRINT(v)))
#endif


/* --- Register HW_UART_USR1, field RXDS[6] (RO)
 *
 * Receiver IDLE Interrupt Flag. Indicates that the receiver state machine is in an IDLE state, the
 * next state is IDLE, and the receive pin is high. RXDS is automatically cleared when a character
 * is received. RXDS is active only when the receiver is enabled.
 *
 * Values:
 * 0 - Receive in progress
 * 1 - Receiver is IDLE
 */

#define BP_UART_USR1_RXDS      (6)      //!< Bit position for UART_USR1_RXDS.
#define BM_UART_USR1_RXDS      (0x00000040)  //!< Bit mask for UART_USR1_RXDS.

//! @brief Get value of UART_USR1_RXDS from a register value.
#define BG_UART_USR1_RXDS(r)   (((r) & BM_UART_USR1_RXDS) >> BP_UART_USR1_RXDS)


/* --- Register HW_UART_USR1, field DTRD[7] (W1C)
 *
 * This bit is not used in this chip. DTR Delta. Indicates whether DTR (in DCE mode) or DSR (in DTE
 * mode) pins changed state. DTRD generates a maskable interrupt if DTRDEN (UCR3[3]) is set. Clear
 * DTRD by writing 1 to it. Writing 0 to DTRD has no effect.
 *
 * Values:
 * 0 - DTR (DCE) or DSR (DTE) pin did not change state since last cleared
 * 1 - DTR (DCE) or DSR (DTE) pin changed state (write 1 to clear)
 */

#define BP_UART_USR1_DTRD      (7)      //!< Bit position for UART_USR1_DTRD.
#define BM_UART_USR1_DTRD      (0x00000080)  //!< Bit mask for UART_USR1_DTRD.

//! @brief Get value of UART_USR1_DTRD from a register value.
#define BG_UART_USR1_DTRD(r)   (((r) & BM_UART_USR1_DTRD) >> BP_UART_USR1_DTRD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR1_DTRD.
#define BF_UART_USR1_DTRD(v)   ((((reg32_t) v) << BP_UART_USR1_DTRD) & BM_UART_USR1_DTRD)
#else
//! @brief Format value for bitfield UART_USR1_DTRD.
#define BF_UART_USR1_DTRD(v)   (((v) << BP_UART_USR1_DTRD) & BM_UART_USR1_DTRD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DTRD field to a new value.
#define BW_UART_USR1_DTRD(x, v)   (HW_UART_USR1_WR(x, (HW_UART_USR1_RD(x) & ~BM_UART_USR1_DTRD) | BF_UART_USR1_DTRD(v)))
#endif


/* --- Register HW_UART_USR1, field AGTIM[8] (W1C)
 *
 * Ageing Timer Interrupt Flag. Indicates that data in the RxFIFO has been idle for a time of 8
 * character lengths (where a character length consists of 7 or 8 bits, depending on the setting of
 * the WS bit in UCR2, with the bit time corresponding to the baud rate setting) and FIFO data level
 * is less than RxFIFO threshold level (RXTL in the UFCR). Clear by writing a 1 to it.
 *
 * Values:
 * 0 - AGTIM is not active
 * 1 - AGTIM is active (write 1 to clear)
 */

#define BP_UART_USR1_AGTIM      (8)      //!< Bit position for UART_USR1_AGTIM.
#define BM_UART_USR1_AGTIM      (0x00000100)  //!< Bit mask for UART_USR1_AGTIM.

//! @brief Get value of UART_USR1_AGTIM from a register value.
#define BG_UART_USR1_AGTIM(r)   (((r) & BM_UART_USR1_AGTIM) >> BP_UART_USR1_AGTIM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR1_AGTIM.
#define BF_UART_USR1_AGTIM(v)   ((((reg32_t) v) << BP_UART_USR1_AGTIM) & BM_UART_USR1_AGTIM)
#else
//! @brief Format value for bitfield UART_USR1_AGTIM.
#define BF_UART_USR1_AGTIM(v)   (((v) << BP_UART_USR1_AGTIM) & BM_UART_USR1_AGTIM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the AGTIM field to a new value.
#define BW_UART_USR1_AGTIM(x, v)   (HW_UART_USR1_WR(x, (HW_UART_USR1_RD(x) & ~BM_UART_USR1_AGTIM) | BF_UART_USR1_AGTIM(v)))
#endif


/* --- Register HW_UART_USR1, field RRDY[9] (RO)
 *
 * Receiver Ready Interrupt / DMA Flag . Indicates that the RxFIFO data level is above the threshold
 * set by the RXTL bits. (See the RXTL bits description in for setting the interrupt threshold.)
 * When asserted, RRDY generates a maskable interrupt or DMA request. RRDY is automatically cleared
 * when data level in the RxFIFO goes below the set threshold level. At reset, RRDY is set to 0.
 *
 * Values:
 * 0 - No character ready
 * 1 - Character(s) ready (interrupt posted)
 */

#define BP_UART_USR1_RRDY      (9)      //!< Bit position for UART_USR1_RRDY.
#define BM_UART_USR1_RRDY      (0x00000200)  //!< Bit mask for UART_USR1_RRDY.

//! @brief Get value of UART_USR1_RRDY from a register value.
#define BG_UART_USR1_RRDY(r)   (((r) & BM_UART_USR1_RRDY) >> BP_UART_USR1_RRDY)


/* --- Register HW_UART_USR1, field FRAMERR[10] (W1C)
 *
 * Frame Error Interrupt Flag . Indicates that a frame error is detected. The interrupt_mint
 * interrupt_uart interrupt will be generated if a frame error is detected and the interrupt is
 * enabled. Clear FRAMERR by writing 1 to it. Writing 0 to FRAMERR has no effect.
 *
 * Values:
 * 0 - No frame error detected
 * 1 - Frame error detected (write 1 to clear)
 */

#define BP_UART_USR1_FRAMERR      (10)      //!< Bit position for UART_USR1_FRAMERR.
#define BM_UART_USR1_FRAMERR      (0x00000400)  //!< Bit mask for UART_USR1_FRAMERR.

//! @brief Get value of UART_USR1_FRAMERR from a register value.
#define BG_UART_USR1_FRAMERR(r)   (((r) & BM_UART_USR1_FRAMERR) >> BP_UART_USR1_FRAMERR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR1_FRAMERR.
#define BF_UART_USR1_FRAMERR(v)   ((((reg32_t) v) << BP_UART_USR1_FRAMERR) & BM_UART_USR1_FRAMERR)
#else
//! @brief Format value for bitfield UART_USR1_FRAMERR.
#define BF_UART_USR1_FRAMERR(v)   (((v) << BP_UART_USR1_FRAMERR) & BM_UART_USR1_FRAMERR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FRAMERR field to a new value.
#define BW_UART_USR1_FRAMERR(x, v)   (HW_UART_USR1_WR(x, (HW_UART_USR1_RD(x) & ~BM_UART_USR1_FRAMERR) | BF_UART_USR1_FRAMERR(v)))
#endif


/* --- Register HW_UART_USR1, field ESCF[11] (W1C)
 *
 * Escape Sequence Interrupt Flag . Indicates if an escape sequence was detected. ESCF is asserted
 * when the ESCEN bit is set and an escape sequence is detected in the RxFIFO. Clear ESCF by writing
 * 1 to it. Writing 0 to ESCF has no effect.
 *
 * Values:
 * 0 - No escape sequence detected
 * 1 - Escape sequence detected (write 1 to clear).
 */

#define BP_UART_USR1_ESCF      (11)      //!< Bit position for UART_USR1_ESCF.
#define BM_UART_USR1_ESCF      (0x00000800)  //!< Bit mask for UART_USR1_ESCF.

//! @brief Get value of UART_USR1_ESCF from a register value.
#define BG_UART_USR1_ESCF(r)   (((r) & BM_UART_USR1_ESCF) >> BP_UART_USR1_ESCF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR1_ESCF.
#define BF_UART_USR1_ESCF(v)   ((((reg32_t) v) << BP_UART_USR1_ESCF) & BM_UART_USR1_ESCF)
#else
//! @brief Format value for bitfield UART_USR1_ESCF.
#define BF_UART_USR1_ESCF(v)   (((v) << BP_UART_USR1_ESCF) & BM_UART_USR1_ESCF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ESCF field to a new value.
#define BW_UART_USR1_ESCF(x, v)   (HW_UART_USR1_WR(x, (HW_UART_USR1_RD(x) & ~BM_UART_USR1_ESCF) | BF_UART_USR1_ESCF(v)))
#endif


/* --- Register HW_UART_USR1, field RTSD[12] (W1C)
 *
 * RTS Delta. Indicates whether the RTS pin changed state. It (RTSD) generates a maskable interrupt.
 * When in STOP mode, RTS assertion sets RTSD and can be used to wake the processor. The current
 * state of the RTS pin is available on the RTSS bit. Clear RTSD by writing 1 to it. Writing 0 to
 * RTSD has no effect. At reset, RTSD is set to 0.
 *
 * Values:
 * 0 - RTS pin did not change state since last cleared
 * 1 - RTS pin changed state (write 1 to clear)
 */

#define BP_UART_USR1_RTSD      (12)      //!< Bit position for UART_USR1_RTSD.
#define BM_UART_USR1_RTSD      (0x00001000)  //!< Bit mask for UART_USR1_RTSD.

//! @brief Get value of UART_USR1_RTSD from a register value.
#define BG_UART_USR1_RTSD(r)   (((r) & BM_UART_USR1_RTSD) >> BP_UART_USR1_RTSD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR1_RTSD.
#define BF_UART_USR1_RTSD(v)   ((((reg32_t) v) << BP_UART_USR1_RTSD) & BM_UART_USR1_RTSD)
#else
//! @brief Format value for bitfield UART_USR1_RTSD.
#define BF_UART_USR1_RTSD(v)   (((v) << BP_UART_USR1_RTSD) & BM_UART_USR1_RTSD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RTSD field to a new value.
#define BW_UART_USR1_RTSD(x, v)   (HW_UART_USR1_WR(x, (HW_UART_USR1_RD(x) & ~BM_UART_USR1_RTSD) | BF_UART_USR1_RTSD(v)))
#endif


/* --- Register HW_UART_USR1, field TRDY[13] (RO)
 *
 * Transmitter Ready Interrupt / DMA Flag . Indicates that the TxFIFO emptied below its target
 * threshold and requires data. TRDY is automatically cleared when the data level in the TxFIFO
 * exceeds the threshold set by TXTL bits. At reset, TRDY is set to 1.
 *
 * Values:
 * 0 - The transmitter does not require data
 * 1 - The transmitter requires data (interrupt posted)
 */

#define BP_UART_USR1_TRDY      (13)      //!< Bit position for UART_USR1_TRDY.
#define BM_UART_USR1_TRDY      (0x00002000)  //!< Bit mask for UART_USR1_TRDY.

//! @brief Get value of UART_USR1_TRDY from a register value.
#define BG_UART_USR1_TRDY(r)   (((r) & BM_UART_USR1_TRDY) >> BP_UART_USR1_TRDY)


/* --- Register HW_UART_USR1, field RTSS[14] (RO)
 *
 * RTS Pin Status . Indicates the current status of the RTS pin. A "snapshot" of the pin is taken
 * immediately before RTSS is presented to the data bus. RTSS cannot be cleared because all writes
 * to RTSS are ignored. At reset, RTSS is set to 0.
 *
 * Values:
 * 0 - The RTS pin is high (inactive)
 * 1 - The RTS pin is low (active)
 */

#define BP_UART_USR1_RTSS      (14)      //!< Bit position for UART_USR1_RTSS.
#define BM_UART_USR1_RTSS      (0x00004000)  //!< Bit mask for UART_USR1_RTSS.

//! @brief Get value of UART_USR1_RTSS from a register value.
#define BG_UART_USR1_RTSS(r)   (((r) & BM_UART_USR1_RTSS) >> BP_UART_USR1_RTSS)


/* --- Register HW_UART_USR1, field PARITYERR[15] (W1C)
 *
 * Parity Error Interrupt Flag . Indicates a parity error is detected. PARITYERR is cleared by
 * writing 1 to it. Writing 0 to PARITYERR has no effect. When parity is disabled, PARITYERR always
 * reads 0. At reset, PARITYERR is set to 0.
 *
 * Values:
 * 0 - No parity error detected
 * 1 - Parity error detected (write 1 to clear)
 */

#define BP_UART_USR1_PARITYERR      (15)      //!< Bit position for UART_USR1_PARITYERR.
#define BM_UART_USR1_PARITYERR      (0x00008000)  //!< Bit mask for UART_USR1_PARITYERR.

//! @brief Get value of UART_USR1_PARITYERR from a register value.
#define BG_UART_USR1_PARITYERR(r)   (((r) & BM_UART_USR1_PARITYERR) >> BP_UART_USR1_PARITYERR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR1_PARITYERR.
#define BF_UART_USR1_PARITYERR(v)   ((((reg32_t) v) << BP_UART_USR1_PARITYERR) & BM_UART_USR1_PARITYERR)
#else
//! @brief Format value for bitfield UART_USR1_PARITYERR.
#define BF_UART_USR1_PARITYERR(v)   (((v) << BP_UART_USR1_PARITYERR) & BM_UART_USR1_PARITYERR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PARITYERR field to a new value.
#define BW_UART_USR1_PARITYERR(x, v)   (HW_UART_USR1_WR(x, (HW_UART_USR1_RD(x) & ~BM_UART_USR1_PARITYERR) | BF_UART_USR1_PARITYERR(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UART_USR2 - UART Status Register 2 (RW)
 *
 * Reset value: 0x00004028
 *

 */
typedef union _hw_uart_usr2
{
    reg32_t U;
    struct _hw_uart_usr2_bitfields
    {
        unsigned RDR : 1; //!< [0] Receive Data Ready -Indicates that at least 1 character is received and written to the RxFIFO. If the URXD register is read and there is only 1 character in the RxFIFO, RDR is automatically cleared.
        unsigned ORE : 1; //!< [1] Overrun Error . When set to 1, ORE indicates that the receive buffer (RxFIFO) was full (32 chars inside), and a 33rd character has been fully received. This 33rd character has been discarded. Clear ORE by writing 1 to it. Writing 0 to ORE has no effect.
        unsigned BRCD : 1; //!< [2] BREAK Condition Detected . Indicates that a BREAK condition was detected by the receiver. Clear BRCD by writing 1 to it. Writing 0 to BRCD has no effect.
        unsigned TXDC : 1; //!< [3] Transmitter Complete . Indicates that the transmit buffer (TxFIFO) and Shift Register is empty; therefore the transmission is complete. TXDC is cleared automatically when data is written to the TxFIFO.
        unsigned RTSF : 1; //!< [4] RTS Edge Triggered Interrupt Flag. Indicates if a programmed edge is detected on the RTS pin. The RTEC bits select the edge that generates an interrupt (see ). RTSF can generate an interrupt that can be masked using the RTSEN bit. Clear RTSF by writing 1 to it. Writing 0 to RTSF has no effect.
        unsigned DCDIN : 1; //!< [5] This bit is not used in this chip. Data Carrier Detect Input . This bit is used in DTE mode reflect the status of the Data Carrier Detect input ( DCD ). The Data Carrier Detect input is used to indicate that a carrier signal has been detected. In DCE mode this bit is always zero.
        unsigned DCDDELT : 1; //!< [6] This bit is not used in this chip. Data Carrier Detect Delta . This bit is used in DTE mode to indicate that the Data Carrier Detect input ( DCD ) has changed state. This flag can cause an interrupt if DCD (UCR3[9]) is enabled. When in STOP mode, this bit can be used to wake the processor. In DCE mode this bit is always zero.
        unsigned WAKE : 1; //!< [7] Wake . Indicates the start bit is detected. WAKE can generate an interrupt that can be masked using the WKEN bit. Clear WAKE by writing 1 to it. Writing 0 to WAKE has no effect.
        unsigned IRINT : 1; //!< [8] Serial Infrared Interrupt Flag. When an edge is detected on the RXD pin during SIR Mode, this flag will be asserted. This flag can cause an interrupt which can be masked using the control bit ENIRI: UCR4 [8].
        unsigned RIIN : 1; //!< [9] This bit is not used in this chip. Ring Indicator Input . This bit is used in DTE mode to reflect the status if the Ring Indicator input ( RI ). The Ring Indicator input is used to indicate that a ring has occurred. In DCE mode this bit is always zero.
        unsigned RIDELT : 1; //!< [10] This bit is not used in this chip. Ring Indicator Delta . This bit is used in DTE mode to indicate that the Ring Indicator input ( RI ) has changed state. This flag can generate an interrupt if RI (UCR3[8]) is enabled. RIDELT is cleared by writing 1 to it. Writing 0 to RIDELT has no effect.
        unsigned ACST : 1; //!< [11] Autobaud Counter Stopped . In autobaud detection (ADBR=1), indicates the counter which determines the baud rate was running and is now stopped. This means either START bit is finished (if ADNIMP=1), or Bit 0 is finished (if ADNIMP=0). See , for more details. An interrupt can be flagged on interrupt_mint interrupt_uart if ACIEN=1.
        unsigned IDLE : 1; //!< [12] Idle Condition . Indicates that an idle condition has existed for more than a programmed amount frame (see . An interrupt can be generated by this IDLE bit if IDEN (UCR1[12]) is enabled. IDLE is cleared by writing 1 to it. Writing 0 to IDLE has no effect.
        unsigned DTRF : 1; //!< [13] This bit is not used in this chip. DTR edge triggered interrupt flag . This bit is asserted, when the programmed edge is detected on the DTR pin (DCE mode) or on DSR (DTE mode). This flag can cause an interrupt if DTREN (UCR3[13]) is enabled.
        unsigned TXFE : 1; //!< [14] Transmit Buffer FIFO Empty . Indicates that the transmit buffer (TxFIFO) is empty. TXFE is cleared automatically when data is written to the TxFIFO. Even though TXFE is high, the transmission might still be in progress.
        unsigned ADET : 1; //!< [15] Automatic Baud Rate Detect Complete . Indicates that an "A" or "a" was received and that the receiver detected and verified the incoming baud rate. Clear ADET by writing 1 to it. Writing 0 to ADET has no effect.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
    } B;
} hw_uart_usr2_t;
#endif

/*
 * constants & macros for entire multi-block UART_USR2 register
 */
#define HW_UART_USR2_ADDR(x)      (REGS_UART_BASE(x) + 0x98)

#ifndef __LANGUAGE_ASM__
#define HW_UART_USR2(x)           (*(volatile hw_uart_usr2_t *) HW_UART_USR2_ADDR(x))
#define HW_UART_USR2_RD(x)        (HW_UART_USR2(x).U)
#define HW_UART_USR2_WR(x, v)     (HW_UART_USR2(x).U = (v))
#define HW_UART_USR2_SET(x, v)    (HW_UART_USR2_WR(x, HW_UART_USR2_RD(x) |  (v)))
#define HW_UART_USR2_CLR(x, v)    (HW_UART_USR2_WR(x, HW_UART_USR2_RD(x) & ~(v)))
#define HW_UART_USR2_TOG(x, v)    (HW_UART_USR2_WR(x, HW_UART_USR2_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UART_USR2 bitfields
 */

/* --- Register HW_UART_USR2, field RDR[0] (RO)
 *
 * Receive Data Ready -Indicates that at least 1 character is received and written to the RxFIFO. If
 * the URXD register is read and there is only 1 character in the RxFIFO, RDR is automatically
 * cleared.
 *
 * Values:
 * 0 - No receive data ready
 * 1 - Receive data ready
 */

#define BP_UART_USR2_RDR      (0)      //!< Bit position for UART_USR2_RDR.
#define BM_UART_USR2_RDR      (0x00000001)  //!< Bit mask for UART_USR2_RDR.

//! @brief Get value of UART_USR2_RDR from a register value.
#define BG_UART_USR2_RDR(r)   (((r) & BM_UART_USR2_RDR) >> BP_UART_USR2_RDR)


/* --- Register HW_UART_USR2, field ORE[1] (W1C)
 *
 * Overrun Error . When set to 1, ORE indicates that the receive buffer (RxFIFO) was full (32 chars
 * inside), and a 33rd character has been fully received. This 33rd character has been discarded.
 * Clear ORE by writing 1 to it. Writing 0 to ORE has no effect.
 *
 * Values:
 * 0 - No overrun error
 * 1 - Overrun error (write 1 to clear)
 */

#define BP_UART_USR2_ORE      (1)      //!< Bit position for UART_USR2_ORE.
#define BM_UART_USR2_ORE      (0x00000002)  //!< Bit mask for UART_USR2_ORE.

//! @brief Get value of UART_USR2_ORE from a register value.
#define BG_UART_USR2_ORE(r)   (((r) & BM_UART_USR2_ORE) >> BP_UART_USR2_ORE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR2_ORE.
#define BF_UART_USR2_ORE(v)   ((((reg32_t) v) << BP_UART_USR2_ORE) & BM_UART_USR2_ORE)
#else
//! @brief Format value for bitfield UART_USR2_ORE.
#define BF_UART_USR2_ORE(v)   (((v) << BP_UART_USR2_ORE) & BM_UART_USR2_ORE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ORE field to a new value.
#define BW_UART_USR2_ORE(x, v)   (HW_UART_USR2_WR(x, (HW_UART_USR2_RD(x) & ~BM_UART_USR2_ORE) | BF_UART_USR2_ORE(v)))
#endif


/* --- Register HW_UART_USR2, field BRCD[2] (W1C)
 *
 * BREAK Condition Detected . Indicates that a BREAK condition was detected by the receiver. Clear
 * BRCD by writing 1 to it. Writing 0 to BRCD has no effect.
 *
 * Values:
 * 0 - No BREAK condition was detected
 * 1 - A BREAK condition was detected (write 1 to clear)
 */

#define BP_UART_USR2_BRCD      (2)      //!< Bit position for UART_USR2_BRCD.
#define BM_UART_USR2_BRCD      (0x00000004)  //!< Bit mask for UART_USR2_BRCD.

//! @brief Get value of UART_USR2_BRCD from a register value.
#define BG_UART_USR2_BRCD(r)   (((r) & BM_UART_USR2_BRCD) >> BP_UART_USR2_BRCD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR2_BRCD.
#define BF_UART_USR2_BRCD(v)   ((((reg32_t) v) << BP_UART_USR2_BRCD) & BM_UART_USR2_BRCD)
#else
//! @brief Format value for bitfield UART_USR2_BRCD.
#define BF_UART_USR2_BRCD(v)   (((v) << BP_UART_USR2_BRCD) & BM_UART_USR2_BRCD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BRCD field to a new value.
#define BW_UART_USR2_BRCD(x, v)   (HW_UART_USR2_WR(x, (HW_UART_USR2_RD(x) & ~BM_UART_USR2_BRCD) | BF_UART_USR2_BRCD(v)))
#endif


/* --- Register HW_UART_USR2, field TXDC[3] (RO)
 *
 * Transmitter Complete . Indicates that the transmit buffer (TxFIFO) and Shift Register is empty;
 * therefore the transmission is complete. TXDC is cleared automatically when data is written to the
 * TxFIFO.
 *
 * Values:
 * 0 - Transmit is incomplete
 * 1 - Transmit is complete
 */

#define BP_UART_USR2_TXDC      (3)      //!< Bit position for UART_USR2_TXDC.
#define BM_UART_USR2_TXDC      (0x00000008)  //!< Bit mask for UART_USR2_TXDC.

//! @brief Get value of UART_USR2_TXDC from a register value.
#define BG_UART_USR2_TXDC(r)   (((r) & BM_UART_USR2_TXDC) >> BP_UART_USR2_TXDC)


/* --- Register HW_UART_USR2, field RTSF[4] (W1C)
 *
 * RTS Edge Triggered Interrupt Flag. Indicates if a programmed edge is detected on the RTS pin. The
 * RTEC bits select the edge that generates an interrupt (see ). RTSF can generate an interrupt that
 * can be masked using the RTSEN bit. Clear RTSF by writing 1 to it. Writing 0 to RTSF has no
 * effect.
 *
 * Values:
 * 0 - Programmed edge not detected on RTS
 * 1 - Programmed edge detected on RTS (write 1 to clear)
 */

#define BP_UART_USR2_RTSF      (4)      //!< Bit position for UART_USR2_RTSF.
#define BM_UART_USR2_RTSF      (0x00000010)  //!< Bit mask for UART_USR2_RTSF.

//! @brief Get value of UART_USR2_RTSF from a register value.
#define BG_UART_USR2_RTSF(r)   (((r) & BM_UART_USR2_RTSF) >> BP_UART_USR2_RTSF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR2_RTSF.
#define BF_UART_USR2_RTSF(v)   ((((reg32_t) v) << BP_UART_USR2_RTSF) & BM_UART_USR2_RTSF)
#else
//! @brief Format value for bitfield UART_USR2_RTSF.
#define BF_UART_USR2_RTSF(v)   (((v) << BP_UART_USR2_RTSF) & BM_UART_USR2_RTSF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RTSF field to a new value.
#define BW_UART_USR2_RTSF(x, v)   (HW_UART_USR2_WR(x, (HW_UART_USR2_RD(x) & ~BM_UART_USR2_RTSF) | BF_UART_USR2_RTSF(v)))
#endif


/* --- Register HW_UART_USR2, field DCDIN[5] (RO)
 *
 * This bit is not used in this chip. Data Carrier Detect Input . This bit is used in DTE mode
 * reflect the status of the Data Carrier Detect input ( DCD ). The Data Carrier Detect input is
 * used to indicate that a carrier signal has been detected. In DCE mode this bit is always zero.
 *
 * Values:
 * 0 - Carrier signal Detected
 * 1 - No Carrier signal Detected
 */

#define BP_UART_USR2_DCDIN      (5)      //!< Bit position for UART_USR2_DCDIN.
#define BM_UART_USR2_DCDIN      (0x00000020)  //!< Bit mask for UART_USR2_DCDIN.

//! @brief Get value of UART_USR2_DCDIN from a register value.
#define BG_UART_USR2_DCDIN(r)   (((r) & BM_UART_USR2_DCDIN) >> BP_UART_USR2_DCDIN)


/* --- Register HW_UART_USR2, field DCDDELT[6] (W1C)
 *
 * This bit is not used in this chip. Data Carrier Detect Delta . This bit is used in DTE mode to
 * indicate that the Data Carrier Detect input ( DCD ) has changed state. This flag can cause an
 * interrupt if DCD (UCR3[9]) is enabled. When in STOP mode, this bit can be used to wake the
 * processor. In DCE mode this bit is always zero.
 *
 * Values:
 * 0 - Data Carrier Detect input has not changed state
 * 1 - Data Carrier Detect input has changed state (write 1 to clear)
 */

#define BP_UART_USR2_DCDDELT      (6)      //!< Bit position for UART_USR2_DCDDELT.
#define BM_UART_USR2_DCDDELT      (0x00000040)  //!< Bit mask for UART_USR2_DCDDELT.

//! @brief Get value of UART_USR2_DCDDELT from a register value.
#define BG_UART_USR2_DCDDELT(r)   (((r) & BM_UART_USR2_DCDDELT) >> BP_UART_USR2_DCDDELT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR2_DCDDELT.
#define BF_UART_USR2_DCDDELT(v)   ((((reg32_t) v) << BP_UART_USR2_DCDDELT) & BM_UART_USR2_DCDDELT)
#else
//! @brief Format value for bitfield UART_USR2_DCDDELT.
#define BF_UART_USR2_DCDDELT(v)   (((v) << BP_UART_USR2_DCDDELT) & BM_UART_USR2_DCDDELT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DCDDELT field to a new value.
#define BW_UART_USR2_DCDDELT(x, v)   (HW_UART_USR2_WR(x, (HW_UART_USR2_RD(x) & ~BM_UART_USR2_DCDDELT) | BF_UART_USR2_DCDDELT(v)))
#endif


/* --- Register HW_UART_USR2, field WAKE[7] (W1C)
 *
 * Wake . Indicates the start bit is detected. WAKE can generate an interrupt that can be masked
 * using the WKEN bit. Clear WAKE by writing 1 to it. Writing 0 to WAKE has no effect.
 *
 * Values:
 * 0 - start bit not detected
 * 1 - start bit detected (write 1 to clear)
 */

#define BP_UART_USR2_WAKE      (7)      //!< Bit position for UART_USR2_WAKE.
#define BM_UART_USR2_WAKE      (0x00000080)  //!< Bit mask for UART_USR2_WAKE.

//! @brief Get value of UART_USR2_WAKE from a register value.
#define BG_UART_USR2_WAKE(r)   (((r) & BM_UART_USR2_WAKE) >> BP_UART_USR2_WAKE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR2_WAKE.
#define BF_UART_USR2_WAKE(v)   ((((reg32_t) v) << BP_UART_USR2_WAKE) & BM_UART_USR2_WAKE)
#else
//! @brief Format value for bitfield UART_USR2_WAKE.
#define BF_UART_USR2_WAKE(v)   (((v) << BP_UART_USR2_WAKE) & BM_UART_USR2_WAKE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WAKE field to a new value.
#define BW_UART_USR2_WAKE(x, v)   (HW_UART_USR2_WR(x, (HW_UART_USR2_RD(x) & ~BM_UART_USR2_WAKE) | BF_UART_USR2_WAKE(v)))
#endif


/* --- Register HW_UART_USR2, field IRINT[8] (W1C)
 *
 * Serial Infrared Interrupt Flag. When an edge is detected on the RXD pin during SIR Mode, this
 * flag will be asserted. This flag can cause an interrupt which can be masked using the control bit
 * ENIRI: UCR4 [8].
 *
 * Values:
 * 0 - no edge detected
 * 1 - valid edge detected (write 1 to clear)
 */

#define BP_UART_USR2_IRINT      (8)      //!< Bit position for UART_USR2_IRINT.
#define BM_UART_USR2_IRINT      (0x00000100)  //!< Bit mask for UART_USR2_IRINT.

//! @brief Get value of UART_USR2_IRINT from a register value.
#define BG_UART_USR2_IRINT(r)   (((r) & BM_UART_USR2_IRINT) >> BP_UART_USR2_IRINT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR2_IRINT.
#define BF_UART_USR2_IRINT(v)   ((((reg32_t) v) << BP_UART_USR2_IRINT) & BM_UART_USR2_IRINT)
#else
//! @brief Format value for bitfield UART_USR2_IRINT.
#define BF_UART_USR2_IRINT(v)   (((v) << BP_UART_USR2_IRINT) & BM_UART_USR2_IRINT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IRINT field to a new value.
#define BW_UART_USR2_IRINT(x, v)   (HW_UART_USR2_WR(x, (HW_UART_USR2_RD(x) & ~BM_UART_USR2_IRINT) | BF_UART_USR2_IRINT(v)))
#endif


/* --- Register HW_UART_USR2, field RIIN[9] (RO)
 *
 * This bit is not used in this chip. Ring Indicator Input . This bit is used in DTE mode to reflect
 * the status if the Ring Indicator input ( RI ). The Ring Indicator input is used to indicate that
 * a ring has occurred. In DCE mode this bit is always zero.
 *
 * Values:
 * 0 - Ring Detected
 * 1 - No Ring Detected
 */

#define BP_UART_USR2_RIIN      (9)      //!< Bit position for UART_USR2_RIIN.
#define BM_UART_USR2_RIIN      (0x00000200)  //!< Bit mask for UART_USR2_RIIN.

//! @brief Get value of UART_USR2_RIIN from a register value.
#define BG_UART_USR2_RIIN(r)   (((r) & BM_UART_USR2_RIIN) >> BP_UART_USR2_RIIN)


/* --- Register HW_UART_USR2, field RIDELT[10] (W1C)
 *
 * This bit is not used in this chip. Ring Indicator Delta . This bit is used in DTE mode to
 * indicate that the Ring Indicator input ( RI ) has changed state. This flag can generate an
 * interrupt if RI (UCR3[8]) is enabled. RIDELT is cleared by writing 1 to it. Writing 0 to RIDELT
 * has no effect.
 *
 * Values:
 * 0 - Ring Indicator input has not changed state
 * 1 - Ring Indicator input has changed state (write 1 to clear)
 */

#define BP_UART_USR2_RIDELT      (10)      //!< Bit position for UART_USR2_RIDELT.
#define BM_UART_USR2_RIDELT      (0x00000400)  //!< Bit mask for UART_USR2_RIDELT.

//! @brief Get value of UART_USR2_RIDELT from a register value.
#define BG_UART_USR2_RIDELT(r)   (((r) & BM_UART_USR2_RIDELT) >> BP_UART_USR2_RIDELT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR2_RIDELT.
#define BF_UART_USR2_RIDELT(v)   ((((reg32_t) v) << BP_UART_USR2_RIDELT) & BM_UART_USR2_RIDELT)
#else
//! @brief Format value for bitfield UART_USR2_RIDELT.
#define BF_UART_USR2_RIDELT(v)   (((v) << BP_UART_USR2_RIDELT) & BM_UART_USR2_RIDELT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RIDELT field to a new value.
#define BW_UART_USR2_RIDELT(x, v)   (HW_UART_USR2_WR(x, (HW_UART_USR2_RD(x) & ~BM_UART_USR2_RIDELT) | BF_UART_USR2_RIDELT(v)))
#endif


/* --- Register HW_UART_USR2, field ACST[11] (W1C)
 *
 * Autobaud Counter Stopped . In autobaud detection (ADBR=1), indicates the counter which determines
 * the baud rate was running and is now stopped. This means either START bit is finished (if
 * ADNIMP=1), or Bit 0 is finished (if ADNIMP=0). See , for more details. An interrupt can be
 * flagged on interrupt_mint interrupt_uart if ACIEN=1.
 *
 * Values:
 * 0 - Measurement of bit length not finished (in autobaud)
 * 1 - Measurement of bit length finished (in autobaud). (write 1 to clear)
 */

#define BP_UART_USR2_ACST      (11)      //!< Bit position for UART_USR2_ACST.
#define BM_UART_USR2_ACST      (0x00000800)  //!< Bit mask for UART_USR2_ACST.

//! @brief Get value of UART_USR2_ACST from a register value.
#define BG_UART_USR2_ACST(r)   (((r) & BM_UART_USR2_ACST) >> BP_UART_USR2_ACST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR2_ACST.
#define BF_UART_USR2_ACST(v)   ((((reg32_t) v) << BP_UART_USR2_ACST) & BM_UART_USR2_ACST)
#else
//! @brief Format value for bitfield UART_USR2_ACST.
#define BF_UART_USR2_ACST(v)   (((v) << BP_UART_USR2_ACST) & BM_UART_USR2_ACST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ACST field to a new value.
#define BW_UART_USR2_ACST(x, v)   (HW_UART_USR2_WR(x, (HW_UART_USR2_RD(x) & ~BM_UART_USR2_ACST) | BF_UART_USR2_ACST(v)))
#endif


/* --- Register HW_UART_USR2, field IDLE[12] (W1C)
 *
 * Idle Condition . Indicates that an idle condition has existed for more than a programmed amount
 * frame (see . An interrupt can be generated by this IDLE bit if IDEN (UCR1[12]) is enabled. IDLE
 * is cleared by writing 1 to it. Writing 0 to IDLE has no effect.
 *
 * Values:
 * 0 - No idle condition detected
 * 1 - Idle condition detected (write 1 to clear)
 */

#define BP_UART_USR2_IDLE      (12)      //!< Bit position for UART_USR2_IDLE.
#define BM_UART_USR2_IDLE      (0x00001000)  //!< Bit mask for UART_USR2_IDLE.

//! @brief Get value of UART_USR2_IDLE from a register value.
#define BG_UART_USR2_IDLE(r)   (((r) & BM_UART_USR2_IDLE) >> BP_UART_USR2_IDLE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR2_IDLE.
#define BF_UART_USR2_IDLE(v)   ((((reg32_t) v) << BP_UART_USR2_IDLE) & BM_UART_USR2_IDLE)
#else
//! @brief Format value for bitfield UART_USR2_IDLE.
#define BF_UART_USR2_IDLE(v)   (((v) << BP_UART_USR2_IDLE) & BM_UART_USR2_IDLE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IDLE field to a new value.
#define BW_UART_USR2_IDLE(x, v)   (HW_UART_USR2_WR(x, (HW_UART_USR2_RD(x) & ~BM_UART_USR2_IDLE) | BF_UART_USR2_IDLE(v)))
#endif


/* --- Register HW_UART_USR2, field DTRF[13] (W1C)
 *
 * This bit is not used in this chip. DTR edge triggered interrupt flag . This bit is asserted, when
 * the programmed edge is detected on the DTR pin (DCE mode) or on DSR (DTE mode). This flag can
 * cause an interrupt if DTREN (UCR3[13]) is enabled.
 *
 * Values:
 * 0 - Programmed edge not detected on DTR/DSR
 * 1 - Programmed edge detected on DTR/DSR (write 1 to clear)
 */

#define BP_UART_USR2_DTRF      (13)      //!< Bit position for UART_USR2_DTRF.
#define BM_UART_USR2_DTRF      (0x00002000)  //!< Bit mask for UART_USR2_DTRF.

//! @brief Get value of UART_USR2_DTRF from a register value.
#define BG_UART_USR2_DTRF(r)   (((r) & BM_UART_USR2_DTRF) >> BP_UART_USR2_DTRF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR2_DTRF.
#define BF_UART_USR2_DTRF(v)   ((((reg32_t) v) << BP_UART_USR2_DTRF) & BM_UART_USR2_DTRF)
#else
//! @brief Format value for bitfield UART_USR2_DTRF.
#define BF_UART_USR2_DTRF(v)   (((v) << BP_UART_USR2_DTRF) & BM_UART_USR2_DTRF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DTRF field to a new value.
#define BW_UART_USR2_DTRF(x, v)   (HW_UART_USR2_WR(x, (HW_UART_USR2_RD(x) & ~BM_UART_USR2_DTRF) | BF_UART_USR2_DTRF(v)))
#endif


/* --- Register HW_UART_USR2, field TXFE[14] (RO)
 *
 * Transmit Buffer FIFO Empty . Indicates that the transmit buffer (TxFIFO) is empty. TXFE is
 * cleared automatically when data is written to the TxFIFO. Even though TXFE is high, the
 * transmission might still be in progress.
 *
 * Values:
 * 0 - The transmit buffer (TxFIFO) is not empty
 * 1 - The transmit buffer (TxFIFO) is empty
 */

#define BP_UART_USR2_TXFE      (14)      //!< Bit position for UART_USR2_TXFE.
#define BM_UART_USR2_TXFE      (0x00004000)  //!< Bit mask for UART_USR2_TXFE.

//! @brief Get value of UART_USR2_TXFE from a register value.
#define BG_UART_USR2_TXFE(r)   (((r) & BM_UART_USR2_TXFE) >> BP_UART_USR2_TXFE)


/* --- Register HW_UART_USR2, field ADET[15] (W1C)
 *
 * Automatic Baud Rate Detect Complete . Indicates that an "A" or "a" was received and that the
 * receiver detected and verified the incoming baud rate. Clear ADET by writing 1 to it. Writing 0
 * to ADET has no effect.
 *
 * Values:
 * 0 - ASCII "A" or "a" was not received
 * 1 - ASCII "A" or "a" was received (write 1 to clear)
 */

#define BP_UART_USR2_ADET      (15)      //!< Bit position for UART_USR2_ADET.
#define BM_UART_USR2_ADET      (0x00008000)  //!< Bit mask for UART_USR2_ADET.

//! @brief Get value of UART_USR2_ADET from a register value.
#define BG_UART_USR2_ADET(r)   (((r) & BM_UART_USR2_ADET) >> BP_UART_USR2_ADET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_USR2_ADET.
#define BF_UART_USR2_ADET(v)   ((((reg32_t) v) << BP_UART_USR2_ADET) & BM_UART_USR2_ADET)
#else
//! @brief Format value for bitfield UART_USR2_ADET.
#define BF_UART_USR2_ADET(v)   (((v) << BP_UART_USR2_ADET) & BM_UART_USR2_ADET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADET field to a new value.
#define BW_UART_USR2_ADET(x, v)   (HW_UART_USR2_WR(x, (HW_UART_USR2_RD(x) & ~BM_UART_USR2_ADET) | BF_UART_USR2_ADET(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UART_UESC - UART Escape Character Register (RW)
 *
 * Reset value: 0x0000002b
 *

 */
typedef union _hw_uart_uesc
{
    reg32_t U;
    struct _hw_uart_uesc_bitfields
    {
        unsigned ESC_CHAR : 8; //!< [7:0] UART Escape Character . Holds the selected escape character that all received characters are compared against to detect an escape sequence.
        unsigned RESERVED0 : 24; //!< [31:8] Reserved
    } B;
} hw_uart_uesc_t;
#endif

/*
 * constants & macros for entire multi-block UART_UESC register
 */
#define HW_UART_UESC_ADDR(x)      (REGS_UART_BASE(x) + 0x9c)

#ifndef __LANGUAGE_ASM__
#define HW_UART_UESC(x)           (*(volatile hw_uart_uesc_t *) HW_UART_UESC_ADDR(x))
#define HW_UART_UESC_RD(x)        (HW_UART_UESC(x).U)
#define HW_UART_UESC_WR(x, v)     (HW_UART_UESC(x).U = (v))
#define HW_UART_UESC_SET(x, v)    (HW_UART_UESC_WR(x, HW_UART_UESC_RD(x) |  (v)))
#define HW_UART_UESC_CLR(x, v)    (HW_UART_UESC_WR(x, HW_UART_UESC_RD(x) & ~(v)))
#define HW_UART_UESC_TOG(x, v)    (HW_UART_UESC_WR(x, HW_UART_UESC_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UART_UESC bitfields
 */

/* --- Register HW_UART_UESC, field ESC_CHAR[7:0] (RW)
 *
 * UART Escape Character . Holds the selected escape character that all received characters are
 * compared against to detect an escape sequence.
 */

#define BP_UART_UESC_ESC_CHAR      (0)      //!< Bit position for UART_UESC_ESC_CHAR.
#define BM_UART_UESC_ESC_CHAR      (0x000000ff)  //!< Bit mask for UART_UESC_ESC_CHAR.

//! @brief Get value of UART_UESC_ESC_CHAR from a register value.
#define BG_UART_UESC_ESC_CHAR(r)   (((r) & BM_UART_UESC_ESC_CHAR) >> BP_UART_UESC_ESC_CHAR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UESC_ESC_CHAR.
#define BF_UART_UESC_ESC_CHAR(v)   ((((reg32_t) v) << BP_UART_UESC_ESC_CHAR) & BM_UART_UESC_ESC_CHAR)
#else
//! @brief Format value for bitfield UART_UESC_ESC_CHAR.
#define BF_UART_UESC_ESC_CHAR(v)   (((v) << BP_UART_UESC_ESC_CHAR) & BM_UART_UESC_ESC_CHAR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ESC_CHAR field to a new value.
#define BW_UART_UESC_ESC_CHAR(x, v)   (HW_UART_UESC_WR(x, (HW_UART_UESC_RD(x) & ~BM_UART_UESC_ESC_CHAR) | BF_UART_UESC_ESC_CHAR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UART_UTIM - UART Escape Timer Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_uart_utim
{
    reg32_t U;
    struct _hw_uart_utim_bitfields
    {
        unsigned TIM : 12; //!< [11:0] UART Escape Timer. Holds the maximum time interval (in ms) allowed between escape characters. The escape timer register is programmable in intervals of 2 ms. See and for more information on the UART escape sequence detection. Reset value 0x000 = 2 ms up to 0xFFF = 8.192 s.
        unsigned RESERVED0 : 20; //!< [31:12] Reserved
    } B;
} hw_uart_utim_t;
#endif

/*
 * constants & macros for entire multi-block UART_UTIM register
 */
#define HW_UART_UTIM_ADDR(x)      (REGS_UART_BASE(x) + 0xa0)

#ifndef __LANGUAGE_ASM__
#define HW_UART_UTIM(x)           (*(volatile hw_uart_utim_t *) HW_UART_UTIM_ADDR(x))
#define HW_UART_UTIM_RD(x)        (HW_UART_UTIM(x).U)
#define HW_UART_UTIM_WR(x, v)     (HW_UART_UTIM(x).U = (v))
#define HW_UART_UTIM_SET(x, v)    (HW_UART_UTIM_WR(x, HW_UART_UTIM_RD(x) |  (v)))
#define HW_UART_UTIM_CLR(x, v)    (HW_UART_UTIM_WR(x, HW_UART_UTIM_RD(x) & ~(v)))
#define HW_UART_UTIM_TOG(x, v)    (HW_UART_UTIM_WR(x, HW_UART_UTIM_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UART_UTIM bitfields
 */

/* --- Register HW_UART_UTIM, field TIM[11:0] (RW)
 *
 * UART Escape Timer. Holds the maximum time interval (in ms) allowed between escape characters. The
 * escape timer register is programmable in intervals of 2 ms. See and for more information on the
 * UART escape sequence detection. Reset value 0x000 = 2 ms up to 0xFFF = 8.192 s.
 */

#define BP_UART_UTIM_TIM      (0)      //!< Bit position for UART_UTIM_TIM.
#define BM_UART_UTIM_TIM      (0x00000fff)  //!< Bit mask for UART_UTIM_TIM.

//! @brief Get value of UART_UTIM_TIM from a register value.
#define BG_UART_UTIM_TIM(r)   (((r) & BM_UART_UTIM_TIM) >> BP_UART_UTIM_TIM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UTIM_TIM.
#define BF_UART_UTIM_TIM(v)   ((((reg32_t) v) << BP_UART_UTIM_TIM) & BM_UART_UTIM_TIM)
#else
//! @brief Format value for bitfield UART_UTIM_TIM.
#define BF_UART_UTIM_TIM(v)   (((v) << BP_UART_UTIM_TIM) & BM_UART_UTIM_TIM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TIM field to a new value.
#define BW_UART_UTIM_TIM(x, v)   (HW_UART_UTIM_WR(x, (HW_UART_UTIM_RD(x) & ~BM_UART_UTIM_TIM) | BF_UART_UTIM_TIM(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UART_UBIR - UART BRM Incremental Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register can be written by both software and hardware. When enabling the automatic baud rate
 * detection feature hardware can write 0x000F value into the UBIR after finishing detecting baud
 * rate. Hardware has higher priority when both software and hardware try to write it at the same
 * cycle Note: The write priority in the new design is not same as the original UART. In the orginal
 * design, software has higher priotiry than hardware when writing this register at the same time.
 * .  Please note software reset will reset the register to its reset value.  Writes to the UBIR and
 * UBMR registers will only take effect if the UART Enable bit (UARTEN) in the Uart Control Register
 * 1 (UCR1) is set.
 */
typedef union _hw_uart_ubir
{
    reg32_t U;
    struct _hw_uart_ubir_bitfields
    {
        unsigned INC : 16; //!< [15:0] Incremental Numerator. Holds the numerator value minus one of the BRM ratio (see ). The UBIR register MUST be updated before the UBMR register for the baud rate to be updated correctly. If only one register is written to by software, the BRM will ignore this data until the other register is written to by software. Updating this field using byte accesses is not recommended and is undefined.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
    } B;
} hw_uart_ubir_t;
#endif

/*
 * constants & macros for entire multi-block UART_UBIR register
 */
#define HW_UART_UBIR_ADDR(x)      (REGS_UART_BASE(x) + 0xa4)

#ifndef __LANGUAGE_ASM__
#define HW_UART_UBIR(x)           (*(volatile hw_uart_ubir_t *) HW_UART_UBIR_ADDR(x))
#define HW_UART_UBIR_RD(x)        (HW_UART_UBIR(x).U)
#define HW_UART_UBIR_WR(x, v)     (HW_UART_UBIR(x).U = (v))
#define HW_UART_UBIR_SET(x, v)    (HW_UART_UBIR_WR(x, HW_UART_UBIR_RD(x) |  (v)))
#define HW_UART_UBIR_CLR(x, v)    (HW_UART_UBIR_WR(x, HW_UART_UBIR_RD(x) & ~(v)))
#define HW_UART_UBIR_TOG(x, v)    (HW_UART_UBIR_WR(x, HW_UART_UBIR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UART_UBIR bitfields
 */

/* --- Register HW_UART_UBIR, field INC[15:0] (RW)
 *
 * Incremental Numerator. Holds the numerator value minus one of the BRM ratio (see ). The UBIR
 * register MUST be updated before the UBMR register for the baud rate to be updated correctly. If
 * only one register is written to by software, the BRM will ignore this data until the other
 * register is written to by software. Updating this field using byte accesses is not recommended
 * and is undefined.
 */

#define BP_UART_UBIR_INC      (0)      //!< Bit position for UART_UBIR_INC.
#define BM_UART_UBIR_INC      (0x0000ffff)  //!< Bit mask for UART_UBIR_INC.

//! @brief Get value of UART_UBIR_INC from a register value.
#define BG_UART_UBIR_INC(r)   (((r) & BM_UART_UBIR_INC) >> BP_UART_UBIR_INC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UBIR_INC.
#define BF_UART_UBIR_INC(v)   ((((reg32_t) v) << BP_UART_UBIR_INC) & BM_UART_UBIR_INC)
#else
//! @brief Format value for bitfield UART_UBIR_INC.
#define BF_UART_UBIR_INC(v)   (((v) << BP_UART_UBIR_INC) & BM_UART_UBIR_INC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC field to a new value.
#define BW_UART_UBIR_INC(x, v)   (HW_UART_UBIR_WR(x, (HW_UART_UBIR_RD(x) & ~BM_UART_UBIR_INC) | BF_UART_UBIR_INC(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UART_UBMR - UART BRM Modulator Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register can be written by both software and hardware. When enabling the automatic baud rate
 * detection feature hardware can write a proper value into the UBMR based on detected baud rate.
 * Hardware has higher priority when both software and hardware try to write it at the same cycle
 * Note: The write priority in the new design is not same as the original UART. In the orginal
 * design, software has higher priotiry than hardware when writing this register at the same time.
 * .  Please note software reset will reset the register to its reset value.  Writes to the UBIR and
 * UBMR registers will only take effect if the UART Enable bit (UARTEN) in the Uart Control Register
 * 1 (UCR1) is set.
 */
typedef union _hw_uart_ubmr
{
    reg32_t U;
    struct _hw_uart_ubmr_bitfields
    {
        unsigned MOD : 16; //!< [15:0] Modulator Denominator. Holds the value of the denominator minus one of the BRM ratio (see ). The UBIR register MUST be updated before the UBMR register for the baud rate to be updated correctly. If only one register is written to by software, the BRM will ignore this data until the other register is written to by software. Updating this register using byte accesses is not recommended and undefined.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
    } B;
} hw_uart_ubmr_t;
#endif

/*
 * constants & macros for entire multi-block UART_UBMR register
 */
#define HW_UART_UBMR_ADDR(x)      (REGS_UART_BASE(x) + 0xa8)

#ifndef __LANGUAGE_ASM__
#define HW_UART_UBMR(x)           (*(volatile hw_uart_ubmr_t *) HW_UART_UBMR_ADDR(x))
#define HW_UART_UBMR_RD(x)        (HW_UART_UBMR(x).U)
#define HW_UART_UBMR_WR(x, v)     (HW_UART_UBMR(x).U = (v))
#define HW_UART_UBMR_SET(x, v)    (HW_UART_UBMR_WR(x, HW_UART_UBMR_RD(x) |  (v)))
#define HW_UART_UBMR_CLR(x, v)    (HW_UART_UBMR_WR(x, HW_UART_UBMR_RD(x) & ~(v)))
#define HW_UART_UBMR_TOG(x, v)    (HW_UART_UBMR_WR(x, HW_UART_UBMR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UART_UBMR bitfields
 */

/* --- Register HW_UART_UBMR, field MOD[15:0] (RW)
 *
 * Modulator Denominator. Holds the value of the denominator minus one of the BRM ratio (see ). The
 * UBIR register MUST be updated before the UBMR register for the baud rate to be updated correctly.
 * If only one register is written to by software, the BRM will ignore this data until the other
 * register is written to by software. Updating this register using byte accesses is not recommended
 * and undefined.
 */

#define BP_UART_UBMR_MOD      (0)      //!< Bit position for UART_UBMR_MOD.
#define BM_UART_UBMR_MOD      (0x0000ffff)  //!< Bit mask for UART_UBMR_MOD.

//! @brief Get value of UART_UBMR_MOD from a register value.
#define BG_UART_UBMR_MOD(r)   (((r) & BM_UART_UBMR_MOD) >> BP_UART_UBMR_MOD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UBMR_MOD.
#define BF_UART_UBMR_MOD(v)   ((((reg32_t) v) << BP_UART_UBMR_MOD) & BM_UART_UBMR_MOD)
#else
//! @brief Format value for bitfield UART_UBMR_MOD.
#define BF_UART_UBMR_MOD(v)   (((v) << BP_UART_UBMR_MOD) & BM_UART_UBMR_MOD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MOD field to a new value.
#define BW_UART_UBMR_MOD(x, v)   (HW_UART_UBMR_WR(x, (HW_UART_UBMR_RD(x) & ~BM_UART_UBMR_MOD) | BF_UART_UBMR_MOD(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UART_UBRC - UART Baud Rate Count Register (RO)
 *
 * Reset value: 0x00000004
 *

 */
typedef union _hw_uart_ubrc
{
    reg32_t U;
    struct _hw_uart_ubrc_bitfields
    {
        unsigned BCNT : 16; //!< [15:0] Baud Rate Count Register. This read only register is used to count the start bit of the incoming baud rate (if ADNIMP=1), or start bit + bit0 (if ADNIMP=0). When the measurement is done, the Baud Rate Count Register contains the number of UART internal clock cycles (clock after divider) present in an incoming bit. BCNT retains its value until the next Automatic Baud Rate Detection sequence has been initiated. The 16 bit Baud Rate Count register is reset to 4 and stays at hex FFFF in the case of an overflow.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
    } B;
} hw_uart_ubrc_t;
#endif

/*
 * constants & macros for entire multi-block UART_UBRC register
 */
#define HW_UART_UBRC_ADDR(x)      (REGS_UART_BASE(x) + 0xac)

#ifndef __LANGUAGE_ASM__
#define HW_UART_UBRC(x)           (*(volatile hw_uart_ubrc_t *) HW_UART_UBRC_ADDR(x))
#define HW_UART_UBRC_RD(x)        (HW_UART_UBRC(x).U)
#endif

/*
 * constants & macros for individual UART_UBRC bitfields
 */

/* --- Register HW_UART_UBRC, field BCNT[15:0] (RO)
 *
 * Baud Rate Count Register. This read only register is used to count the start bit of the incoming
 * baud rate (if ADNIMP=1), or start bit + bit0 (if ADNIMP=0). When the measurement is done, the
 * Baud Rate Count Register contains the number of UART internal clock cycles (clock after divider)
 * present in an incoming bit. BCNT retains its value until the next Automatic Baud Rate Detection
 * sequence has been initiated. The 16 bit Baud Rate Count register is reset to 4 and stays at hex
 * FFFF in the case of an overflow.
 */

#define BP_UART_UBRC_BCNT      (0)      //!< Bit position for UART_UBRC_BCNT.
#define BM_UART_UBRC_BCNT      (0x0000ffff)  //!< Bit mask for UART_UBRC_BCNT.

//! @brief Get value of UART_UBRC_BCNT from a register value.
#define BG_UART_UBRC_BCNT(r)   (((r) & BM_UART_UBRC_BCNT) >> BP_UART_UBRC_BCNT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UART_ONEMS - UART One Millisecond Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register has been expanded from 16 bits to 24 bits. In previous versions, the 16-bit ONEMS
 * can only support the maximum 65.535MHz (0xFFFFx1000) ref_clk . To support 4Mbps Bluetooth
 * application with 66.5MHz   module_clock  (ipg_perclk)   , the value 0x103C4 (66.5M/1000) should
 * be written into this register. In this case, the 16 bits are not enough to contain the 0x103C4.
 * So this register was expanded to 24 bits to support high frequency of the ref_clk .
 */
typedef union _hw_uart_onems
{
    reg32_t U;
    struct _hw_uart_onems_bitfields
    {
        unsigned ONEMS : 24; //!< [23:0] One Millisecond Register. This 24-bit register must contain the value of the UART internal frequency ( ref_clk in ) divided by 1000. The internal frequency is obtained after the UART BRM internal divider (F ( ref_clk ) = F( module_clock ) / RFDIV). In fact this register contains the value corresponding to the number of UART BRM internal clock cycles present in one millisecond. The ONEMS (and UTIM) registers value are used in the escape character detection feature ( ) to count the number of clock cycles left between two escape characters. The ONEMS register is also used in infrared special case mode (IRSC = UCR4[5] = 1'b1), see .
        unsigned RESERVED0 : 8; //!< [31:24] Reserved
    } B;
} hw_uart_onems_t;
#endif

/*
 * constants & macros for entire multi-block UART_ONEMS register
 */
#define HW_UART_ONEMS_ADDR(x)      (REGS_UART_BASE(x) + 0xb0)

#ifndef __LANGUAGE_ASM__
#define HW_UART_ONEMS(x)           (*(volatile hw_uart_onems_t *) HW_UART_ONEMS_ADDR(x))
#define HW_UART_ONEMS_RD(x)        (HW_UART_ONEMS(x).U)
#define HW_UART_ONEMS_WR(x, v)     (HW_UART_ONEMS(x).U = (v))
#define HW_UART_ONEMS_SET(x, v)    (HW_UART_ONEMS_WR(x, HW_UART_ONEMS_RD(x) |  (v)))
#define HW_UART_ONEMS_CLR(x, v)    (HW_UART_ONEMS_WR(x, HW_UART_ONEMS_RD(x) & ~(v)))
#define HW_UART_ONEMS_TOG(x, v)    (HW_UART_ONEMS_WR(x, HW_UART_ONEMS_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UART_ONEMS bitfields
 */

/* --- Register HW_UART_ONEMS, field ONEMS[23:0] (RW)
 *
 * One Millisecond Register. This 24-bit register must contain the value of the UART internal
 * frequency ( ref_clk in ) divided by 1000. The internal frequency is obtained after the UART BRM
 * internal divider (F ( ref_clk ) = F( module_clock ) / RFDIV). In fact this register contains the
 * value corresponding to the number of UART BRM internal clock cycles present in one millisecond.
 * The ONEMS (and UTIM) registers value are used in the escape character detection feature ( ) to
 * count the number of clock cycles left between two escape characters. The ONEMS register is also
 * used in infrared special case mode (IRSC = UCR4[5] = 1'b1), see .
 */

#define BP_UART_ONEMS_ONEMS      (0)      //!< Bit position for UART_ONEMS_ONEMS.
#define BM_UART_ONEMS_ONEMS      (0x00ffffff)  //!< Bit mask for UART_ONEMS_ONEMS.

//! @brief Get value of UART_ONEMS_ONEMS from a register value.
#define BG_UART_ONEMS_ONEMS(r)   (((r) & BM_UART_ONEMS_ONEMS) >> BP_UART_ONEMS_ONEMS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_ONEMS_ONEMS.
#define BF_UART_ONEMS_ONEMS(v)   ((((reg32_t) v) << BP_UART_ONEMS_ONEMS) & BM_UART_ONEMS_ONEMS)
#else
//! @brief Format value for bitfield UART_ONEMS_ONEMS.
#define BF_UART_ONEMS_ONEMS(v)   (((v) << BP_UART_ONEMS_ONEMS) & BM_UART_ONEMS_ONEMS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ONEMS field to a new value.
#define BW_UART_ONEMS_ONEMS(x, v)   (HW_UART_ONEMS_WR(x, (HW_UART_ONEMS_RD(x) & ~BM_UART_ONEMS_ONEMS) | BF_UART_ONEMS_ONEMS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UART_UTS - UART Test Register (RW)
 *
 * Reset value: 0x00000060
 *

 */
typedef union _hw_uart_uts
{
    reg32_t U;
    struct _hw_uart_uts_bitfields
    {
        unsigned SOFTRST : 1; //!< [0] Software Reset. Indicates the status of the software reset ( SRST bit of UCR2).
        unsigned RESERVED0 : 2; //!< [2:1] Reserved
        unsigned RXFULL : 1; //!< [3] RxFIFO FULL. Indicates the RxFIFO is full.
        unsigned TXFULL : 1; //!< [4] TxFIFO FULL. Indicates the TxFIFO is full.
        unsigned RXEMPTY : 1; //!< [5] RxFIFO Empty. Indicates the RxFIFO is empty.
        unsigned TXEMPTY : 1; //!< [6] TxFIFO Empty. Indicates that the TxFIFO is empty.
        unsigned RESERVED1 : 2; //!< [8:7] Reserved
        unsigned RXDBG : 1; //!< [9] This bit is not used in this chip. The user should clear this bit for future compatibility. RX_fifo_debug_mode. This bit controls the operation of the RX fifo read counter when in debug mode.
        unsigned LOOPIR : 1; //!< [10] Loop TX and RX for IR Test (LOOPIR) . This bit controls loopback from transmitter to receiver in the InfraRed interface.
        unsigned DBGEN : 1; //!< [11] This bit is not used in this chip. The user should clear this bit for future compatibility. debug_enable . This bit controls whether to respond to the debug_req input signal.
        unsigned LOOP : 1; //!< [12] Loop TX and RX for Test. Controls loopback for test purposes. When LOOP is high, the receiver input is internally connected to the transmitter and ignores the RXD pin. The transmitter is unaffected by LOOP. If RXDMUXSEL (UCR3[2]) is set to 1, the loopback is applied on serial and IrDA signals. If RXDMUXSEL is set to 0, the loopback is only applied on serial signals.
        unsigned FRCPERR : 1; //!< [13] Force Parity Error. Forces the transmitter to generate a parity error if parity is enabled. FRCPERR is provided for system debugging.
        unsigned RESERVED2 : 18; //!< [31:14] Reserved
    } B;
} hw_uart_uts_t;
#endif

/*
 * constants & macros for entire multi-block UART_UTS register
 */
#define HW_UART_UTS_ADDR(x)      (REGS_UART_BASE(x) + 0xb4)

#ifndef __LANGUAGE_ASM__
#define HW_UART_UTS(x)           (*(volatile hw_uart_uts_t *) HW_UART_UTS_ADDR(x))
#define HW_UART_UTS_RD(x)        (HW_UART_UTS(x).U)
#define HW_UART_UTS_WR(x, v)     (HW_UART_UTS(x).U = (v))
#define HW_UART_UTS_SET(x, v)    (HW_UART_UTS_WR(x, HW_UART_UTS_RD(x) |  (v)))
#define HW_UART_UTS_CLR(x, v)    (HW_UART_UTS_WR(x, HW_UART_UTS_RD(x) & ~(v)))
#define HW_UART_UTS_TOG(x, v)    (HW_UART_UTS_WR(x, HW_UART_UTS_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UART_UTS bitfields
 */

/* --- Register HW_UART_UTS, field SOFTRST[0] (RW)
 *
 * Software Reset. Indicates the status of the software reset ( SRST bit of UCR2).
 *
 * Values:
 * 0 - Software reset inactive
 * 1 - Software reset active
 */

#define BP_UART_UTS_SOFTRST      (0)      //!< Bit position for UART_UTS_SOFTRST.
#define BM_UART_UTS_SOFTRST      (0x00000001)  //!< Bit mask for UART_UTS_SOFTRST.

//! @brief Get value of UART_UTS_SOFTRST from a register value.
#define BG_UART_UTS_SOFTRST(r)   (((r) & BM_UART_UTS_SOFTRST) >> BP_UART_UTS_SOFTRST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UTS_SOFTRST.
#define BF_UART_UTS_SOFTRST(v)   ((((reg32_t) v) << BP_UART_UTS_SOFTRST) & BM_UART_UTS_SOFTRST)
#else
//! @brief Format value for bitfield UART_UTS_SOFTRST.
#define BF_UART_UTS_SOFTRST(v)   (((v) << BP_UART_UTS_SOFTRST) & BM_UART_UTS_SOFTRST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SOFTRST field to a new value.
#define BW_UART_UTS_SOFTRST(x, v)   (HW_UART_UTS_WR(x, (HW_UART_UTS_RD(x) & ~BM_UART_UTS_SOFTRST) | BF_UART_UTS_SOFTRST(v)))
#endif


/* --- Register HW_UART_UTS, field RXFULL[3] (RW)
 *
 * RxFIFO FULL. Indicates the RxFIFO is full.
 *
 * Values:
 * 0 - The RxFIFO is not full
 * 1 - The RxFIFO is full
 */

#define BP_UART_UTS_RXFULL      (3)      //!< Bit position for UART_UTS_RXFULL.
#define BM_UART_UTS_RXFULL      (0x00000008)  //!< Bit mask for UART_UTS_RXFULL.

//! @brief Get value of UART_UTS_RXFULL from a register value.
#define BG_UART_UTS_RXFULL(r)   (((r) & BM_UART_UTS_RXFULL) >> BP_UART_UTS_RXFULL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UTS_RXFULL.
#define BF_UART_UTS_RXFULL(v)   ((((reg32_t) v) << BP_UART_UTS_RXFULL) & BM_UART_UTS_RXFULL)
#else
//! @brief Format value for bitfield UART_UTS_RXFULL.
#define BF_UART_UTS_RXFULL(v)   (((v) << BP_UART_UTS_RXFULL) & BM_UART_UTS_RXFULL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXFULL field to a new value.
#define BW_UART_UTS_RXFULL(x, v)   (HW_UART_UTS_WR(x, (HW_UART_UTS_RD(x) & ~BM_UART_UTS_RXFULL) | BF_UART_UTS_RXFULL(v)))
#endif


/* --- Register HW_UART_UTS, field TXFULL[4] (RW)
 *
 * TxFIFO FULL. Indicates the TxFIFO is full.
 *
 * Values:
 * 0 - The TxFIFO is not full
 * 1 - The TxFIFO is full
 */

#define BP_UART_UTS_TXFULL      (4)      //!< Bit position for UART_UTS_TXFULL.
#define BM_UART_UTS_TXFULL      (0x00000010)  //!< Bit mask for UART_UTS_TXFULL.

//! @brief Get value of UART_UTS_TXFULL from a register value.
#define BG_UART_UTS_TXFULL(r)   (((r) & BM_UART_UTS_TXFULL) >> BP_UART_UTS_TXFULL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UTS_TXFULL.
#define BF_UART_UTS_TXFULL(v)   ((((reg32_t) v) << BP_UART_UTS_TXFULL) & BM_UART_UTS_TXFULL)
#else
//! @brief Format value for bitfield UART_UTS_TXFULL.
#define BF_UART_UTS_TXFULL(v)   (((v) << BP_UART_UTS_TXFULL) & BM_UART_UTS_TXFULL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXFULL field to a new value.
#define BW_UART_UTS_TXFULL(x, v)   (HW_UART_UTS_WR(x, (HW_UART_UTS_RD(x) & ~BM_UART_UTS_TXFULL) | BF_UART_UTS_TXFULL(v)))
#endif


/* --- Register HW_UART_UTS, field RXEMPTY[5] (RW)
 *
 * RxFIFO Empty. Indicates the RxFIFO is empty.
 *
 * Values:
 * 0 - The RxFIFO is not empty
 * 1 - The RxFIFO is empty
 */

#define BP_UART_UTS_RXEMPTY      (5)      //!< Bit position for UART_UTS_RXEMPTY.
#define BM_UART_UTS_RXEMPTY      (0x00000020)  //!< Bit mask for UART_UTS_RXEMPTY.

//! @brief Get value of UART_UTS_RXEMPTY from a register value.
#define BG_UART_UTS_RXEMPTY(r)   (((r) & BM_UART_UTS_RXEMPTY) >> BP_UART_UTS_RXEMPTY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UTS_RXEMPTY.
#define BF_UART_UTS_RXEMPTY(v)   ((((reg32_t) v) << BP_UART_UTS_RXEMPTY) & BM_UART_UTS_RXEMPTY)
#else
//! @brief Format value for bitfield UART_UTS_RXEMPTY.
#define BF_UART_UTS_RXEMPTY(v)   (((v) << BP_UART_UTS_RXEMPTY) & BM_UART_UTS_RXEMPTY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXEMPTY field to a new value.
#define BW_UART_UTS_RXEMPTY(x, v)   (HW_UART_UTS_WR(x, (HW_UART_UTS_RD(x) & ~BM_UART_UTS_RXEMPTY) | BF_UART_UTS_RXEMPTY(v)))
#endif


/* --- Register HW_UART_UTS, field TXEMPTY[6] (RW)
 *
 * TxFIFO Empty. Indicates that the TxFIFO is empty.
 *
 * Values:
 * 0 - The TxFIFO is not empty
 * 1 - The TxFIFO is empty
 */

#define BP_UART_UTS_TXEMPTY      (6)      //!< Bit position for UART_UTS_TXEMPTY.
#define BM_UART_UTS_TXEMPTY      (0x00000040)  //!< Bit mask for UART_UTS_TXEMPTY.

//! @brief Get value of UART_UTS_TXEMPTY from a register value.
#define BG_UART_UTS_TXEMPTY(r)   (((r) & BM_UART_UTS_TXEMPTY) >> BP_UART_UTS_TXEMPTY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UTS_TXEMPTY.
#define BF_UART_UTS_TXEMPTY(v)   ((((reg32_t) v) << BP_UART_UTS_TXEMPTY) & BM_UART_UTS_TXEMPTY)
#else
//! @brief Format value for bitfield UART_UTS_TXEMPTY.
#define BF_UART_UTS_TXEMPTY(v)   (((v) << BP_UART_UTS_TXEMPTY) & BM_UART_UTS_TXEMPTY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXEMPTY field to a new value.
#define BW_UART_UTS_TXEMPTY(x, v)   (HW_UART_UTS_WR(x, (HW_UART_UTS_RD(x) & ~BM_UART_UTS_TXEMPTY) | BF_UART_UTS_TXEMPTY(v)))
#endif


/* --- Register HW_UART_UTS, field RXDBG[9] (RW)
 *
 * This bit is not used in this chip. The user should clear this bit for future compatibility.
 * RX_fifo_debug_mode. This bit controls the operation of the RX fifo read counter when in debug
 * mode.
 *
 * Values:
 * 0 - rx fifo read pointer does not increment
 * 1 - rx_fifo read pointer increments as normal
 */

#define BP_UART_UTS_RXDBG      (9)      //!< Bit position for UART_UTS_RXDBG.
#define BM_UART_UTS_RXDBG      (0x00000200)  //!< Bit mask for UART_UTS_RXDBG.

//! @brief Get value of UART_UTS_RXDBG from a register value.
#define BG_UART_UTS_RXDBG(r)   (((r) & BM_UART_UTS_RXDBG) >> BP_UART_UTS_RXDBG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UTS_RXDBG.
#define BF_UART_UTS_RXDBG(v)   ((((reg32_t) v) << BP_UART_UTS_RXDBG) & BM_UART_UTS_RXDBG)
#else
//! @brief Format value for bitfield UART_UTS_RXDBG.
#define BF_UART_UTS_RXDBG(v)   (((v) << BP_UART_UTS_RXDBG) & BM_UART_UTS_RXDBG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDBG field to a new value.
#define BW_UART_UTS_RXDBG(x, v)   (HW_UART_UTS_WR(x, (HW_UART_UTS_RD(x) & ~BM_UART_UTS_RXDBG) | BF_UART_UTS_RXDBG(v)))
#endif


/* --- Register HW_UART_UTS, field LOOPIR[10] (RW)
 *
 * Loop TX and RX for IR Test (LOOPIR) . This bit controls loopback from transmitter to receiver in
 * the InfraRed interface.
 *
 * Values:
 * 0 - No IR loop
 * 1 - Connect IR transmitter to IR receiver
 */

#define BP_UART_UTS_LOOPIR      (10)      //!< Bit position for UART_UTS_LOOPIR.
#define BM_UART_UTS_LOOPIR      (0x00000400)  //!< Bit mask for UART_UTS_LOOPIR.

//! @brief Get value of UART_UTS_LOOPIR from a register value.
#define BG_UART_UTS_LOOPIR(r)   (((r) & BM_UART_UTS_LOOPIR) >> BP_UART_UTS_LOOPIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UTS_LOOPIR.
#define BF_UART_UTS_LOOPIR(v)   ((((reg32_t) v) << BP_UART_UTS_LOOPIR) & BM_UART_UTS_LOOPIR)
#else
//! @brief Format value for bitfield UART_UTS_LOOPIR.
#define BF_UART_UTS_LOOPIR(v)   (((v) << BP_UART_UTS_LOOPIR) & BM_UART_UTS_LOOPIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LOOPIR field to a new value.
#define BW_UART_UTS_LOOPIR(x, v)   (HW_UART_UTS_WR(x, (HW_UART_UTS_RD(x) & ~BM_UART_UTS_LOOPIR) | BF_UART_UTS_LOOPIR(v)))
#endif


/* --- Register HW_UART_UTS, field DBGEN[11] (RW)
 *
 * This bit is not used in this chip. The user should clear this bit for future compatibility.
 * debug_enable . This bit controls whether to respond to the debug_req input signal.
 *
 * Values:
 * 0 - UART will go into debug mode when debug_req is HIGH
 * 1 - UART will not go into debug mode even if debug_req is HIGH
 */

#define BP_UART_UTS_DBGEN      (11)      //!< Bit position for UART_UTS_DBGEN.
#define BM_UART_UTS_DBGEN      (0x00000800)  //!< Bit mask for UART_UTS_DBGEN.

//! @brief Get value of UART_UTS_DBGEN from a register value.
#define BG_UART_UTS_DBGEN(r)   (((r) & BM_UART_UTS_DBGEN) >> BP_UART_UTS_DBGEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UTS_DBGEN.
#define BF_UART_UTS_DBGEN(v)   ((((reg32_t) v) << BP_UART_UTS_DBGEN) & BM_UART_UTS_DBGEN)
#else
//! @brief Format value for bitfield UART_UTS_DBGEN.
#define BF_UART_UTS_DBGEN(v)   (((v) << BP_UART_UTS_DBGEN) & BM_UART_UTS_DBGEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DBGEN field to a new value.
#define BW_UART_UTS_DBGEN(x, v)   (HW_UART_UTS_WR(x, (HW_UART_UTS_RD(x) & ~BM_UART_UTS_DBGEN) | BF_UART_UTS_DBGEN(v)))
#endif


/* --- Register HW_UART_UTS, field LOOP[12] (RW)
 *
 * Loop TX and RX for Test. Controls loopback for test purposes. When LOOP is high, the receiver
 * input is internally connected to the transmitter and ignores the RXD pin. The transmitter is
 * unaffected by LOOP. If RXDMUXSEL (UCR3[2]) is set to 1, the loopback is applied on serial and
 * IrDA signals. If RXDMUXSEL is set to 0, the loopback is only applied on serial signals.
 *
 * Values:
 * 0 - Normal receiver operation
 * 1 - Internally connect the transmitter output to the receiver input
 */

#define BP_UART_UTS_LOOP      (12)      //!< Bit position for UART_UTS_LOOP.
#define BM_UART_UTS_LOOP      (0x00001000)  //!< Bit mask for UART_UTS_LOOP.

//! @brief Get value of UART_UTS_LOOP from a register value.
#define BG_UART_UTS_LOOP(r)   (((r) & BM_UART_UTS_LOOP) >> BP_UART_UTS_LOOP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UTS_LOOP.
#define BF_UART_UTS_LOOP(v)   ((((reg32_t) v) << BP_UART_UTS_LOOP) & BM_UART_UTS_LOOP)
#else
//! @brief Format value for bitfield UART_UTS_LOOP.
#define BF_UART_UTS_LOOP(v)   (((v) << BP_UART_UTS_LOOP) & BM_UART_UTS_LOOP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LOOP field to a new value.
#define BW_UART_UTS_LOOP(x, v)   (HW_UART_UTS_WR(x, (HW_UART_UTS_RD(x) & ~BM_UART_UTS_LOOP) | BF_UART_UTS_LOOP(v)))
#endif


/* --- Register HW_UART_UTS, field FRCPERR[13] (RW)
 *
 * Force Parity Error. Forces the transmitter to generate a parity error if parity is enabled.
 * FRCPERR is provided for system debugging.
 *
 * Values:
 * 0 - Generate normal parity
 * 1 - Generate inverted parity (error)
 */

#define BP_UART_UTS_FRCPERR      (13)      //!< Bit position for UART_UTS_FRCPERR.
#define BM_UART_UTS_FRCPERR      (0x00002000)  //!< Bit mask for UART_UTS_FRCPERR.

//! @brief Get value of UART_UTS_FRCPERR from a register value.
#define BG_UART_UTS_FRCPERR(r)   (((r) & BM_UART_UTS_FRCPERR) >> BP_UART_UTS_FRCPERR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UTS_FRCPERR.
#define BF_UART_UTS_FRCPERR(v)   ((((reg32_t) v) << BP_UART_UTS_FRCPERR) & BM_UART_UTS_FRCPERR)
#else
//! @brief Format value for bitfield UART_UTS_FRCPERR.
#define BF_UART_UTS_FRCPERR(v)   (((v) << BP_UART_UTS_FRCPERR) & BM_UART_UTS_FRCPERR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FRCPERR field to a new value.
#define BW_UART_UTS_FRCPERR(x, v)   (HW_UART_UTS_WR(x, (HW_UART_UTS_RD(x) & ~BM_UART_UTS_FRCPERR) | BF_UART_UTS_FRCPERR(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_UART_UMCR - UART RS-485 Mode Control Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_uart_umcr
{
    reg32_t U;
    struct _hw_uart_umcr_bitfields
    {
        unsigned MDEN : 1; //!< [0] 9-bit data or Multidrop Mode (RS-485) Enable.
        unsigned SLAM : 1; //!< [1] RS-485 Slave Address Detect Mode Selection.
        unsigned TXB8 : 1; //!< [2] Transmit RS-485 bit 8 (the ninth bit or 9 th bit). In RS-485 mode, software writes TXB8 bit as the 9 th data bit to be transmitted.
        unsigned SADEN : 1; //!< [3] RS-485 Slave Address Detected Interrupt Enable.
        unsigned RESERVED0 : 4; //!< [7:4] Reserved
        unsigned SLADDR : 8; //!< [15:8] RS-485 Slave Address Character. Holds the selected slave adress character that the receiver wil try to detect.
        unsigned RESERVED1 : 16; //!< [31:16] Reserved
    } B;
} hw_uart_umcr_t;
#endif

/*
 * constants & macros for entire multi-block UART_UMCR register
 */
#define HW_UART_UMCR_ADDR(x)      (REGS_UART_BASE(x) + 0xb8)

#ifndef __LANGUAGE_ASM__
#define HW_UART_UMCR(x)           (*(volatile hw_uart_umcr_t *) HW_UART_UMCR_ADDR(x))
#define HW_UART_UMCR_RD(x)        (HW_UART_UMCR(x).U)
#define HW_UART_UMCR_WR(x, v)     (HW_UART_UMCR(x).U = (v))
#define HW_UART_UMCR_SET(x, v)    (HW_UART_UMCR_WR(x, HW_UART_UMCR_RD(x) |  (v)))
#define HW_UART_UMCR_CLR(x, v)    (HW_UART_UMCR_WR(x, HW_UART_UMCR_RD(x) & ~(v)))
#define HW_UART_UMCR_TOG(x, v)    (HW_UART_UMCR_WR(x, HW_UART_UMCR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual UART_UMCR bitfields
 */

/* --- Register HW_UART_UMCR, field MDEN[0] (RW)
 *
 * 9-bit data or Multidrop Mode (RS-485) Enable.
 *
 * Values:
 * 0 - Normal RS-232 or IrDA mode, see for detail.
 * 1 - Enable RS-485 mode, see for detail
 */

#define BP_UART_UMCR_MDEN      (0)      //!< Bit position for UART_UMCR_MDEN.
#define BM_UART_UMCR_MDEN      (0x00000001)  //!< Bit mask for UART_UMCR_MDEN.

//! @brief Get value of UART_UMCR_MDEN from a register value.
#define BG_UART_UMCR_MDEN(r)   (((r) & BM_UART_UMCR_MDEN) >> BP_UART_UMCR_MDEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UMCR_MDEN.
#define BF_UART_UMCR_MDEN(v)   ((((reg32_t) v) << BP_UART_UMCR_MDEN) & BM_UART_UMCR_MDEN)
#else
//! @brief Format value for bitfield UART_UMCR_MDEN.
#define BF_UART_UMCR_MDEN(v)   (((v) << BP_UART_UMCR_MDEN) & BM_UART_UMCR_MDEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MDEN field to a new value.
#define BW_UART_UMCR_MDEN(x, v)   (HW_UART_UMCR_WR(x, (HW_UART_UMCR_RD(x) & ~BM_UART_UMCR_MDEN) | BF_UART_UMCR_MDEN(v)))
#endif


/* --- Register HW_UART_UMCR, field SLAM[1] (RW)
 *
 * RS-485 Slave Address Detect Mode Selection.
 *
 * Values:
 * 0 - Select Normal Address Detect mode
 * 1 - Select Automatic Address Detect mode
 */

#define BP_UART_UMCR_SLAM      (1)      //!< Bit position for UART_UMCR_SLAM.
#define BM_UART_UMCR_SLAM      (0x00000002)  //!< Bit mask for UART_UMCR_SLAM.

//! @brief Get value of UART_UMCR_SLAM from a register value.
#define BG_UART_UMCR_SLAM(r)   (((r) & BM_UART_UMCR_SLAM) >> BP_UART_UMCR_SLAM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UMCR_SLAM.
#define BF_UART_UMCR_SLAM(v)   ((((reg32_t) v) << BP_UART_UMCR_SLAM) & BM_UART_UMCR_SLAM)
#else
//! @brief Format value for bitfield UART_UMCR_SLAM.
#define BF_UART_UMCR_SLAM(v)   (((v) << BP_UART_UMCR_SLAM) & BM_UART_UMCR_SLAM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SLAM field to a new value.
#define BW_UART_UMCR_SLAM(x, v)   (HW_UART_UMCR_WR(x, (HW_UART_UMCR_RD(x) & ~BM_UART_UMCR_SLAM) | BF_UART_UMCR_SLAM(v)))
#endif


/* --- Register HW_UART_UMCR, field TXB8[2] (RW)
 *
 * Transmit RS-485 bit 8 (the ninth bit or 9 th bit). In RS-485 mode, software writes TXB8 bit as
 * the 9 th data bit to be transmitted.
 *
 * Values:
 * 0 - 0 will be transmitted as the RS485 9 th data bit
 * 1 - 1 will be transmitted as the RS485 9 th data bit
 */

#define BP_UART_UMCR_TXB8      (2)      //!< Bit position for UART_UMCR_TXB8.
#define BM_UART_UMCR_TXB8      (0x00000004)  //!< Bit mask for UART_UMCR_TXB8.

//! @brief Get value of UART_UMCR_TXB8 from a register value.
#define BG_UART_UMCR_TXB8(r)   (((r) & BM_UART_UMCR_TXB8) >> BP_UART_UMCR_TXB8)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UMCR_TXB8.
#define BF_UART_UMCR_TXB8(v)   ((((reg32_t) v) << BP_UART_UMCR_TXB8) & BM_UART_UMCR_TXB8)
#else
//! @brief Format value for bitfield UART_UMCR_TXB8.
#define BF_UART_UMCR_TXB8(v)   (((v) << BP_UART_UMCR_TXB8) & BM_UART_UMCR_TXB8)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXB8 field to a new value.
#define BW_UART_UMCR_TXB8(x, v)   (HW_UART_UMCR_WR(x, (HW_UART_UMCR_RD(x) & ~BM_UART_UMCR_TXB8) | BF_UART_UMCR_TXB8(v)))
#endif


/* --- Register HW_UART_UMCR, field SADEN[3] (RW)
 *
 * RS-485 Slave Address Detected Interrupt Enable.
 *
 * Values:
 * 0 - Disable RS-485 Slave Address Detected Interrupt
 * 1 - Enable RS-485 Slave Address Detected Interrupt
 */

#define BP_UART_UMCR_SADEN      (3)      //!< Bit position for UART_UMCR_SADEN.
#define BM_UART_UMCR_SADEN      (0x00000008)  //!< Bit mask for UART_UMCR_SADEN.

//! @brief Get value of UART_UMCR_SADEN from a register value.
#define BG_UART_UMCR_SADEN(r)   (((r) & BM_UART_UMCR_SADEN) >> BP_UART_UMCR_SADEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UMCR_SADEN.
#define BF_UART_UMCR_SADEN(v)   ((((reg32_t) v) << BP_UART_UMCR_SADEN) & BM_UART_UMCR_SADEN)
#else
//! @brief Format value for bitfield UART_UMCR_SADEN.
#define BF_UART_UMCR_SADEN(v)   (((v) << BP_UART_UMCR_SADEN) & BM_UART_UMCR_SADEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SADEN field to a new value.
#define BW_UART_UMCR_SADEN(x, v)   (HW_UART_UMCR_WR(x, (HW_UART_UMCR_RD(x) & ~BM_UART_UMCR_SADEN) | BF_UART_UMCR_SADEN(v)))
#endif


/* --- Register HW_UART_UMCR, field SLADDR[15:8] (RW)
 *
 * RS-485 Slave Address Character. Holds the selected slave adress character that the receiver wil
 * try to detect.
 */

#define BP_UART_UMCR_SLADDR      (8)      //!< Bit position for UART_UMCR_SLADDR.
#define BM_UART_UMCR_SLADDR      (0x0000ff00)  //!< Bit mask for UART_UMCR_SLADDR.

//! @brief Get value of UART_UMCR_SLADDR from a register value.
#define BG_UART_UMCR_SLADDR(r)   (((r) & BM_UART_UMCR_SLADDR) >> BP_UART_UMCR_SLADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield UART_UMCR_SLADDR.
#define BF_UART_UMCR_SLADDR(v)   ((((reg32_t) v) << BP_UART_UMCR_SLADDR) & BM_UART_UMCR_SLADDR)
#else
//! @brief Format value for bitfield UART_UMCR_SLADDR.
#define BF_UART_UMCR_SLADDR(v)   (((v) << BP_UART_UMCR_SLADDR) & BM_UART_UMCR_SLADDR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SLADDR field to a new value.
#define BW_UART_UMCR_SLADDR(x, v)   (HW_UART_UMCR_WR(x, (HW_UART_UMCR_RD(x) & ~BM_UART_UMCR_SLADDR) | BF_UART_UMCR_SLADDR(v)))
#endif


/*!
 * @brief All UART module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_uart
{
    volatile hw_uart_urxd_t URXD; //!< UART Receiver Register
    reg32_t _reserved0[15];
    volatile hw_uart_utxd_t UTXD; //!< UART Transmitter Register
    reg32_t _reserved1[15];
    volatile hw_uart_ucr1_t UCR1; //!< UART Control Register 1
    volatile hw_uart_ucr2_t UCR2; //!< UART Control Register 2
    volatile hw_uart_ucr3_t UCR3; //!< UART Control Register 3
    volatile hw_uart_ucr4_t UCR4; //!< UART Control Register 4
    volatile hw_uart_ufcr_t UFCR; //!< UART FIFO Control Register
    volatile hw_uart_usr1_t USR1; //!< UART Status Register 1
    volatile hw_uart_usr2_t USR2; //!< UART Status Register 2
    volatile hw_uart_uesc_t UESC; //!< UART Escape Character Register
    volatile hw_uart_utim_t UTIM; //!< UART Escape Timer Register
    volatile hw_uart_ubir_t UBIR; //!< UART BRM Incremental Register
    volatile hw_uart_ubmr_t UBMR; //!< UART BRM Modulator Register
    volatile hw_uart_ubrc_t UBRC; //!< UART Baud Rate Count Register
    volatile hw_uart_onems_t ONEMS; //!< UART One Millisecond Register
    volatile hw_uart_uts_t UTS; //!< UART Test Register
    volatile hw_uart_umcr_t UMCR; //!< UART RS-485 Mode Control Register
} hw_uart_t;
#pragma pack()

//! @brief Macro to access all UART registers.
//! @param x UART instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_UART(0)</code>.
#define HW_UART(x)     (*(volatile hw_uart_t *) REGS_UART_BASE(x))

#endif


#endif // __HW_UART_REGISTERS_H__
