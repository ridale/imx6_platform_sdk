/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __IMX_I2C_H__
#define __IMX_I2C_H__

#include "sdk.h"

//! @addtogroup diag_i2c

//! @{

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! @brief Read/write address bits
//!
//! Bit 0 of the i2c device address cycle to indicate r/w. 0 is for write, 1 is for read.
enum _i2c_rq {
    I2C_WRITE = 0,
    I2C_READ = 1
};

//! @brief I2C Error Codes
enum _i2c_err {
    ERR_TX = -1,
    ERR_RX = -2,
    ERR_ARB_LOST = -3,
    ERR_NO_ACK = -4,
    ERR_XFER = -5,
    ERR_RX_ACK = -6,
    ERR_NO_ACK_ON_START = -7,
    ERR_INVALID_REQUEST = -8
};

//! Default slave address used for the MX6.
enum _i2c_slave_id {
    IMX6_DEFAULT_SLAVE_ID = 0x60
};

/*!
 * @brief An I2C transfer descriptor.
 *
 * To perform an I2C transfer, the caller first fills in an instance of this struct. Then
 * i2c_xfer() is called, passing a pointer to the #imx_i2c_request_t struct.
 */
typedef struct imx_i2c_request {
    uint32_t ctl_addr;          //!< The I2C controller base address.
    uint32_t dev_addr;          //!< The I2C device address.
    uint32_t reg_addr;          //!< The register address within the target device.
    uint32_t reg_addr_sz;       //!< Number of bytes for the address of I2C device register.
    uint8_t *buffer;            //!< Buffer to hold the data.
    uint32_t buffer_sz;         //!< The number of bytes for read/write.
    int32_t (*slave_receive) (const struct imx_i2c_request *rq);  //!< Function for slave to receive data from master.
    int32_t (*slave_transmit) (const struct imx_i2c_request *rq); //!< Function for slave to transmit data to master.
} imx_i2c_request_t;

////////////////////////////////////////////////////////////////////////////////
// API
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * Initialize the I2C module -- mainly enable the I2C clock, module
 * itself and the I2C clock prescaler.
 *
 * @param   base        base address of I2C module (also assigned for I2Cx_CLK)
 * @param   baud        the desired data rate in bps
 *
 * @return  0 if successful; non-zero otherwise
 */
int i2c_init(uint32_t base, uint32_t baud);

/*!
 * This is a rather simple function that can be used for most I2C devices.
 * Common steps for both READ and WRITE:
 *     - step 1: issue start signal
 *     - step 2: put I2C device addr on the bus (always 1 byte write. the dir always I2C_WRITE)
 *     - step 3: offset of the I2C device write (offset within the device. can be 1-4 bytes)
 * For READ:
 *     - step 4: do repeat-start
 *     - step 5: send slave address again, but indicate a READ operation by setting LSB bit
 *     - Step 6: change to receive mode
 *     - Step 7: dummy read
 *     - Step 8: reading
 * For WRITE:
 *     - Step 4: do data write
 *     - Step 5: generate STOP by clearing MSTA bit
 *
 * @param   rq        Pointer to #imx_i2c_request_t.
 * @param   dir       #I2C_READ or #I2C_WRITE
 *
 * @return  0 on success; non-zero otherwise
 */
int i2c_xfer(const imx_i2c_request_t *rq, int dir);

/*!
 * @brief Perform I2C read transfer.
 *
 * @param rq Pointer to #imx_i2c_request_t.
 */
int i2c_read(const imx_i2c_request_t *rq);

/*!
 * @brief Perform I2C write transfer.
 *
 * @param rq Pointer to #imx_i2c_request_t.
 */
int i2c_write(const imx_i2c_request_t *rq);

/*!
 * @brief I2C handler for the slave mode.
 *
 * The function is based on the flow chart for typical I2C polling routine described in the
 * I2C controller chapter of the reference manual.
 *
 * @param   rq Pointer to #imx_i2c_request_t.
 */
void i2c_slave_handler(const imx_i2c_request_t *rq);

/*!
 * @brief Handle the I2C transfers in slave mode.
 *
 * The slave mode behaves like any device with g_addr_cycle of address + g_data_cycle of data.
 * Master read =
 * START - SLAVE_ID/W - ACK - MEM_ADDR - ACK - START - SLAVE_ID/R - ACK - DATAx - NACK - STOP
 * 
 * Example for a 16-bit address access:
 * - 1st IRQ - receive the slave address and Write flag from master.
 * - 2nd IRQ - receive the lower byte of the requested 16-bit address.
 * - 3rd IRQ - receive the higher byte of the requested 16-bit address.
 * - 4th IRQ - receive the slave address and Read flag from master.
 * - 5th and next IRQ - transmit the data as long as NACK and STOP is not asserted.
 *
 * Master write =
 * START - SLAVE_ID/W - ACK - MEM_ADDR - ACK - DATAx - NACK - STOP
 *
 * - 1st IRQ - receive the slave address and Write flag from master.
 * - 2nd IRQ - receive the lower byte of the requested 16-bit address.
 * - 3rd IRQ - receive the higher byte of the requested 16-bit address.
 * - 4th and next IRQ - receive the data as long STOP is not asserted.
 *
 * @param   port Pointer to the I2C module structure.
 * @param   rq Pointer to #imx_i2c_request_t.
 */
void i2c_slave_xfer(hw_module_t *port, imx_i2c_request_t *rq);

#if defined(__cplusplus)
}
#endif

//! @}

#endif /* __IMX_I2C_H__ */
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
