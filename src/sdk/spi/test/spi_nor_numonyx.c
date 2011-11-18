/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"
#include "spi_nor_numonyx.h"
#include "../inc/ecspi_ifc.h"

extern dev_ecspi_e dev_spi_nor;

static uint8_t spi_nor_tx_buf[SPI_NOR_XFER_SZ];
static uint8_t spi_nor_rx_buf[SPI_NOR_XFER_SZ];

/*-------------------------------------------- Static Function -----------------------------------------*/

static int spi_nor_status_numonyx(uint8_t * status)
{
    spi_nor_tx_buf[1] = RDSR;

    /* Send command */
    if (ecspi_xfer(dev_spi_nor, spi_nor_tx_buf, spi_nor_rx_buf, 2 * 8) == FALSE) {
        printf("Numonyx Error - get status.\n");
        return FAIL;
    }

    *status = spi_nor_rx_buf[0];

    return SUCCESS;
}

static int spi_nor_wren_numonyx(void)
{
    spi_nor_tx_buf[0] = WREN;

    /* Send command */
    if (ecspi_xfer(dev_spi_nor, spi_nor_tx_buf, spi_nor_rx_buf, 1 * 8) == FALSE) {
        printf("Numonyx Error - write enable.\n");
        return FAIL;
    }

    return SUCCESS;
}

static int numonyx_erase_sector(uint32_t d_addr)
{
    uint8_t status;

    /* Enable write */
    if (spi_nor_wren_numonyx() == FAIL) {
        return FAIL;
    }

    /* Setup command */
    spi_nor_tx_buf[0] = d_addr;
    spi_nor_tx_buf[1] = d_addr >> 8;
    spi_nor_tx_buf[2] = d_addr >> 16;
    spi_nor_tx_buf[3] = SE;

    /* Send command */
    if (ecspi_xfer(dev_spi_nor, spi_nor_tx_buf, spi_nor_rx_buf, 4 * 8) == FALSE) {
        printf("Numonyx Error - erase sector.\n");
        return FAIL;
    }

    /* Busy wait */
    do {
        hal_delay_us(100);

        if (spi_nor_status_numonyx(&status) == FAIL) {
            return FAIL;
        }
    } while (status & RDSR_BUSY);

    return SUCCESS;
}

static int numonyx_erase_chip(void)
{
    uint8_t status;

    /* Enable write */
    if (spi_nor_wren_numonyx() == FAIL) {
        return FAIL;
    }

    spi_nor_tx_buf[0] = BE;

    /* Send command */
    if (ecspi_xfer(dev_spi_nor, spi_nor_tx_buf, spi_nor_rx_buf, 1 * 8) == FALSE) {
        printf("Numonyx Error - erase chip.\n");
        return FAIL;
    }

    /* Busy wait */
    do {
        hal_delay_us(100);
        if (spi_nor_status_numonyx(&status) == FAIL) {
            return FAIL;
        }
    } while (status & RDSR_BUSY);

    return SUCCESS;
}

/*-------------------------------------------- Global Function -----------------------------------------*/

/*!
 * Query the Numonyx flash ID
 * Parameter:
 *     data: buffer to store the ID queried
 * Return:
 *     SUCCESS on success, otherwise FAIL
 */
int spi_nor_query_numonyx(uint8_t * data)
{
    spi_nor_tx_buf[3] = RDID;

    /* Read ID get 20 bytes response */
    if (ecspi_xfer(dev_spi_nor, spi_nor_tx_buf, spi_nor_rx_buf, 20 * 8) == FALSE) {
        return FAIL;
    }

    /* Big-endian */
    data[0] = spi_nor_rx_buf[0];
    data[1] = spi_nor_rx_buf[1];
    data[2] = spi_nor_rx_buf[2];
    data[3] = spi_nor_rx_buf[3];

    return SUCCESS;
}

/*!
 * Erase the Numonyx flash start at 'addr' for size of 'length'
 * Parameter:
 *     addr:   offset/start address of the flash
 *     length: length of the data to erase
 * Return:
 *     SUCCESS on success, otherwise FAIL
 */
int spi_nor_erase_numonyx(uint32_t addr, uint32_t length)
{
    int retv;

    /* Erase chip if length >= chip size */
    if (length > (SZ_CHIP - SZ_SECTOR)) {
        retv = numonyx_erase_chip();
    } else {
        /* Erase sector by sector */
        while (length > 0) {
            retv = numonyx_erase_sector(addr);
            if (retv == FAIL) {
                break;
            }

            addr += SZ_SECTOR;
            length -= SZ_SECTOR;
        }
    }

    return retv;
}

/*!
 * Read 'length' data from Numonyx flash start at 'address' to 'dst'
 * Parameter:
 *     address: offset/start address of the flash
 *     dst: buffer to store the data read
 *     length: data size in bytes
 * Return:
 *     SUCCESS on success, otherwise FAIL
 */
int spi_nor_read_numonyx(uint32_t address, uint8_t * dst, int length)
{
    int idx, left, translen;

    /* Check length */
    if (length <= 0) {
        printf("Numonyx read - Invalid length.\n");
        return FAIL;
    }

    memset(spi_nor_tx_buf, 0, NUMONYX_MAX_RX);

    /* Setup command */
    spi_nor_tx_buf[3] = READ;

    while (length > 0) {
        /* Setup source address */
        spi_nor_tx_buf[0] = (uint32_t) address & 0xFF;
        spi_nor_tx_buf[1] = ((uint32_t) address >> 8) & 0xFF;
        spi_nor_tx_buf[2] = ((uint32_t) address >> 16) & 0xFF;

        /* Setup transfer length */
        translen =
            (length < NUMONYX_MAX_RX - NUMONYX_CMD_SZ) ? length : NUMONYX_MAX_RX - NUMONYX_CMD_SZ;

        /* Read data */
        if (ecspi_xfer(dev_spi_nor, spi_nor_tx_buf, spi_nor_rx_buf, (translen + 4) * 8) == FALSE) {
            printf("Numonyx read - xfer %d\n", length);
            return FAIL;
        }

        /* Move data to destination buffer */
        for (idx = 4, left = translen; left > 0; left -= 4, idx += 4) {
            switch (left) {
            default:
                *dst++ = spi_nor_rx_buf[idx + 3];
            case 3:
                *dst++ = spi_nor_rx_buf[idx + 2];
            case 2:
                *dst++ = spi_nor_rx_buf[idx + 1];
            case 1:
                *dst++ = spi_nor_rx_buf[idx];
                break;
            }
        }

        /* Update address and length */
        address += translen, length -= translen;
    }

    return SUCCESS;
}

/*!
 * Write 'length' data from 'src' to Numonyx flash start at 'address'
 * Parameter:
 *     address: offset/start address of the flash
 *     src: buffer that store data to write
 *     length: data size in bytes
 * Return:
 *     SUCCESS on success, otherwise FAIL
 */
int spi_nor_write_numonyx(uint32_t address, uint8_t * src, int length)
{
    uint8_t status;
    int templ, translen, left;
    uint32_t idx, tmpaddr, bytes;

    /* Check length */
    if (length <= 0) {
        printf("Numonyx write - Invalid length.\n");
        return FAIL;
    }

    /* Handle word aligned data */
    templ = length & 0xFFFFFFFC;

    while (templ > 0) {
        /* Set length for transfer */
        translen = SZ_PAGE - (address & SZ_OFFSET);

        /* Handle last word aligned write */
        if (translen > templ) {
            translen = templ;
        }

        /* Transfer data */
        spi_nor_tx_buf[3] = PP, left = translen, tmpaddr = address;

        while (left > 0) {
            if (spi_nor_wren_numonyx() == FAIL) {
                return FAIL;
            }

            /* Setup flash address */
            spi_nor_tx_buf[0] = tmpaddr & 0xFF;
            spi_nor_tx_buf[1] = (tmpaddr >> 8) & 0xFF;
            spi_nor_tx_buf[2] = (tmpaddr >> 16) & 0xFF;

            /* Setup data */
            bytes =
                (left < NUMONYX_MAX_TX - NUMONYX_CMD_SZ) ? left : NUMONYX_MAX_TX - NUMONYX_CMD_SZ;
            for (idx = 4; idx < bytes + 4; idx += 4) {
                spi_nor_tx_buf[idx + 3] = *src++;
                spi_nor_tx_buf[idx + 2] = *src++;
                spi_nor_tx_buf[idx + 1] = *src++;
                spi_nor_tx_buf[idx] = *src++;
            }

            /* Transfer data */
            if (ecspi_xfer(dev_spi_nor, spi_nor_tx_buf, spi_nor_rx_buf, (bytes + 4) * 8) == FALSE) {
                printf("Numonyx write: xfer %d\n", bytes);
                return FAIL;
            }

            /* Busy wait */
            do {
                hal_delay_us(100);

                if (spi_nor_status_numonyx(&status) == FAIL) {
                    return FAIL;
                }
            } while (status & RDSR_BUSY);

            /* Update address & length */
            left -= bytes, tmpaddr += bytes;
        }

        /* Update address and length left */
        address += translen, templ -= translen;
    }

    /* Handle non-word-aligned bytes */
    templ = length & 0x3;

    if (templ > 0) {
        /* Enable Numonyx write */
        if (spi_nor_wren_numonyx() == FAIL) {
            return FAIL;
        }

        /* Setup data */
        for (idx = 0; idx < templ; idx++) {
            spi_nor_tx_buf[templ - 1 - idx] = *src++;
        }

        /* Setup address */
        spi_nor_tx_buf[idx++] = address & 0xFF;
        spi_nor_tx_buf[idx++] = (address >> 8) & 0xFF;
        spi_nor_tx_buf[idx++] = (address >> 16) & 0xFF;

        /* Setup command */
        spi_nor_tx_buf[idx++] = PP;

        /* Transfer data */
        if (ecspi_xfer(dev_spi_nor, spi_nor_tx_buf, spi_nor_rx_buf, idx * 8) == FALSE) {
            printf("Numonyx write: remaining xfer %d\n", templ);
            return FAIL;
        }

        /* Busy wait */
        do {
            hal_delay_us(100);

            if (spi_nor_status_numonyx(&status) == FAIL) {
                return FAIL;
            }
        } while (status & RDSR_BUSY);
    }

    return SUCCESS;
}