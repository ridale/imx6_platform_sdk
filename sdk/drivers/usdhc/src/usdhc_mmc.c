/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 * usdhc_mmc.c
 *
 * MMC card specific driver
 *
 */

#include "usdhc.h"
#include "hardware.h"
#include "usdhc_host.h"
#include "usdhc_mmc.h"
#include "usdhc/inc/usdhc_ifc.h"

static struct csd_struct csd_reg;
static uint32_t ext_csd_data[BLK_LEN / FOUR];
static uint32_t mmc_version = MMC_CARD_INV;

/********************************************* Static Function ******************************************/
static int mmc_set_rca(int base_address)
{
    command_t cmd;
    int port, card_state, status = FAIL;
    command_response_t response;

    /* Check uSDHC Port */
    port = card_get_port(base_address);
    if (port == USDHC_NUMBER_PORTS) {
        printf("Base address: 0x%x not in address table.\n", base_address);
        return status;
    }

    /* Set RCA to ONE */
    usdhc_device[port].rca = ONE;

    /* Configure CMD3 */
    card_cmd_config(&cmd, CMD3, (usdhc_device[port].rca << RCA_SHIFT), READ, RESPONSE_48,
                    DATA_PRESENT_NONE, TRUE, TRUE);

    usdhc_printf("Send CMD3.\n");

    /* Send CMD3 */
    if (host_send_cmd(base_address, &cmd) == SUCCESS) {
        response.format = RESPONSE_48;
        host_read_response(base_address, &response);

        /* Check the IDENT card state */
        card_state = CURR_CARD_STATE(response.cmd_rsp0);

        if (card_state == IDENT) {
            status = SUCCESS;
        }
    }

    return status;
}

static int mmc_switch(int base_address, uint32_t arg)
{
    command_t cmd;
    int status = FAIL;

    /* Configure MMC Switch Command */
    card_cmd_config(&cmd, CMD6, arg, READ, RESPONSE_48, DATA_PRESENT_NONE, TRUE, TRUE);

    usdhc_printf("Send CMD6.\n");

    /* Send CMD6 */
    if (SUCCESS == host_send_cmd(base_address, &cmd)) {
        status = card_trans_status(base_address);
    }

    return status;
}

static int mmc_set_bus_width(int base_address, int bus_width)
{
    return mmc_switch(base_address, MMC_SWITCH_SETBW_ARG(bus_width));
}

static int mmc_read_csd(int base_address)
{
    command_t cmd;
    command_response_t response;

    int status = SUCCESS;

    /* Configure read CSD command */
    card_cmd_config(&cmd, CMD9, ONE << RCA_SHIFT, READ,
                    RESPONSE_136, DATA_PRESENT_NONE, TRUE, FALSE);

    usdhc_printf("Send CMD9.\n");

    /* Send CMD9 */
    if (host_send_cmd(base_address, &cmd) == FAIL) {
        status = FAIL;
    } else {

        /* Read response */
        response.format = RESPONSE_136;
        host_read_response(base_address, &response);

        csd_reg.response[0] = response.cmd_rsp0;
        csd_reg.response[1] = response.cmd_rsp1;
        csd_reg.response[2] = response.cmd_rsp2;
        csd_reg.response[3] = response.cmd_rsp3;

        csd_reg.csds = (csd_reg.response[3] & 0x00C00000) >> 22;
        csd_reg.ssv = (csd_reg.response[3] & 0x003C0000) >> 18;
    }

    return status;
}

static int mmc_read_esd(int base_address)
{
    command_t cmd;

    /* Set block length */
    card_cmd_config(&cmd, CMD16, BLK_LEN, READ, RESPONSE_48, DATA_PRESENT_NONE, TRUE, TRUE);

    usdhc_printf("Send CMD16.\n");

    /* Send CMD16 */
    if (SUCCESS == host_send_cmd(base_address, &cmd)) {
        /* Configure block attribute */
        host_cfg_block(base_address, BLK_LEN, ONE, ESDHC_BLKATTR_WML_BLOCK);

        /* Read extended CSD */
        card_cmd_config(&cmd, CMD8, NO_ARG, READ, RESPONSE_48, DATA_PRESENT, TRUE, TRUE);

        usdhc_printf("Send CMD8.\n");

        /* Send CMD8 */
        if (SUCCESS == host_send_cmd(base_address, &cmd)) {
            return host_data_read(base_address, (int *)ext_csd_data, BLK_LEN,
                                  ESDHC_BLKATTR_WML_BLOCK);
        }
    }

    return FAIL;
}

static uint32_t mmc_get_spec_ver(int base_address)
{
    int retv = 0;

    /* Read CSD */
    if (SUCCESS == mmc_read_csd(base_address)) {
        retv = csd_reg.ssv | (csd_reg.csds << 8);
    }

    /* Enter transfer mode */
    if (SUCCESS == card_enter_trans(base_address)) {
        /* Set bus width */
        if (mmc_set_bus_width(base_address, ONE) == SUCCESS) {
            host_set_bus_width(base_address, ONE);
        }

        /* Read Extended CSD */
        if (SUCCESS == mmc_read_esd(base_address)) {
            retv |= (ext_csd_data[48] & 0x00FF0000) | ((ext_csd_data[57] & 0xFF) << 24);
        }
    }

    return retv;
}

/********************************************* Global Function ******************************************/
int mmc_init(int base_address, int bus_width)
{
    int status = FAIL;

    usdhc_printf("Get CID.\n");

    /* Get CID */
    if (card_get_cid(base_address) == SUCCESS) {
        usdhc_printf("Set RCA.\n");

        /* Set RCA */
        if (mmc_set_rca(base_address) == SUCCESS) {
            /* Check Card Type here */
            usdhc_printf("Set operating frequency.\n");

            /* Switch to Operating Frequency */
            host_cfg_clock(base_address, OPERATING_FREQ);

            usdhc_printf("Enter transfer state.\n");

            /* Enter Transfer State */
            if (card_enter_trans(base_address) == SUCCESS) {
                usdhc_printf("Set bus width.\n");

                /* Set Card Bus Width */
                if (mmc_set_bus_width(base_address, bus_width) == SUCCESS) {
                    /* Set Host Bus Width */
                    host_set_bus_width(base_address, bus_width);

                    /* Set High Speed Here */
                    {
                        status = SUCCESS;
                    }
                }
            }
        }
    }

    return status;
}

int emmc_init(int base_address)
{
    uint8_t byte;
    uint32_t retv;
    int status = FAIL;

    /* Init MMC version */
    mmc_version = MMC_CARD_INV;

    /* Get CID */
    if (card_get_cid(base_address) == SUCCESS) {

        /* Set RCA */
        if (mmc_set_rca(base_address) == SUCCESS) {

            /* Switch to Operating Frequency */
            host_cfg_clock(base_address, OPERATING_FREQ);

            status = SUCCESS;

            retv = mmc_get_spec_ver(base_address);

            /* Obtain CSD structure */
            byte = (retv >> 8) & 0xFF;

            if (byte == 3) {
                /* Obtain system spec version in CSD */
                byte = (retv >> 16) & 0xFF;
            }

            if (byte == 2) {
                /* If support DDR mode */
                byte = retv >> 24;
                if (byte & 0x2) {
                    mmc_version = MMC_CARD_4_4;
                    printf("\teMMC 4.4 card.\n");
                } else {
                    mmc_version = MMC_CARD_4_X;
                    printf("\teMMC 4.X (X<4) card.\n");
                }
            } else {
                mmc_version = MMC_CARD_3_X;
                printf("\tMMC 3.X or older cards.\n");
            }
        }
    }

    return status;
}

void emmc_print_cfg_info(int base_address)
{
    uint8_t byte, *ptr;

    /* Check if card initialized OK */
    if (mmc_version == MMC_CARD_INV) {
        printf("Invalid or uninitialized card.\n");
        return;
    }

    /* Read extended CSD rigister */
    if (FAIL == mmc_read_esd(base_address)) {
        printf("Read extended CSD failed.\n");
        return;
    }

    /* Specify pointer */
    ptr = (uint8_t *) ext_csd_data;

    /* Display boot partition */
    byte = ptr[MMC_ESD_OFF_PRT_CFG] & BP_MASK;

    printf("\t%s enabled for boot.\n", (byte == BP_USER) ? "User Partition" :
           (byte == BP_BT1) ? "Boot partition #1" :
           (byte == BP_BT2) ? "Boot Partition #2" : "No partition");

    /* Display boot acknowledge */
    if (mmc_version == MMC_CARD_4_4) {
        byte = ptr[MMC_ESD_OFF_PRT_CFG] & BT_ACK;

        printf("\tFast boot acknowledgement %s\n", (byte == 0) ? "disabled" : "enabled");
    }

    /* Display fast boot bus width */
    byte = ptr[MMC_ESD_OFF_BT_BW] & BBW_BUS_MASK;
    printf("\tFast boot bus width: %s\n", (byte == BBW_1BIT) ? "1 bit" :
           (byte == BBW_4BIT) ? "4 bit" : (byte == BBW_8BIT) ? "8 bit" : "unknown");

    /* Display DDR mode setting */
    byte = ptr[MMC_ESD_OFF_BT_BW] & BBW_DDR_MASK;
    printf("\tDDR boot mode %s\n", (byte == BBW_DDR) ? "enabled" : "disabled");

    /* Display boot save setting */
    byte = ptr[MMC_ESD_OFF_BT_BW] & BBW_SAVE;
    printf("\t%s boot bus width settings.\n\n", (byte == 0) ? "Discard" : "Retain");
}

int mmc_set_boot_bus_width(int base_address, emmc_bus_width_e width)
{
    int bus_width;

    if (mmc_version == MMC_CARD_INV) {
        printf("Invalid or uninitialized card.\n");
        return FAIL;
    }

    bus_width = (width == EMMC_BOOT_SDR1) ? (BBW_1BIT | BBW_SAVE) :
        (width == EMMC_BOOT_SDR4) ? (BBW_4BIT | BBW_SAVE) :
        (width == EMMC_BOOT_SDR8) ? (BBW_8BIT | BBW_SAVE) :
        (width ==
         EMMC_BOOT_DDR4) ? (BBW_4BIT | BBW_SAVE | BBW_DDR) : (BBW_8BIT | BBW_SAVE | BBW_DDR);

    return mmc_switch(base_address,
                      MMC_SWITCH_SET_BOOT_BUS_WIDTH | (bus_width << MMC_SWITCH_SET_PARAM_SHIFT));
}

int mmc_set_boot_partition(int base_address, emmc_part_e part)
{
    int boot_part;
    uint8_t byte, *ptr;

    if (mmc_version == MMC_CARD_INV) {
        printf("Invalid or uninitialized card.\n");
        return FAIL;
    }

    /* Read extended CSD rigister */
    if (FAIL == mmc_read_esd(base_address)) {
        printf("Read extended CSD failed.\n");
        return FAIL;
    }

    ptr = (uint8_t *) ext_csd_data;

    boot_part = (part == EMMC_PART_USER) ? BP_USER : (part == EMMC_PART_BOOT1) ? BP_BT1 : BP_BT2;

    byte = (ptr[MMC_ESD_OFF_PRT_CFG] & (~BP_MASK)) | boot_part;

    return mmc_switch(base_address,
                      MMC_SWITCH_SET_BOOT_PARTITION | (byte << MMC_SWITCH_SET_PARAM_SHIFT));
}

int mmc_set_boot_ack(int base_address, int enable)
{
    uint32_t data;

    /* Check emmc version */
    if (mmc_version != MMC_CARD_4_4) {
        printf("Fast boot acknowledge only supported for emmc4.4.\n");
        return FAIL;
    }

    if (enable) {
        data = MMC_SWITCH_SET_BOOT_ACK;
    } else {
        data = MMC_SWITCH_CLR_BOOT_ACK;
    }

    return mmc_switch(base_address, data);
}

int mmc_voltage_validation(int base_address)
{
    command_t cmd;
    command_response_t response;
    int port, count = ZERO, status = FAIL;
    unsigned int ocr_val = MMC_HV_HC_OCR_VALUE;

    /* Check uSDHC Port from Base Address */
    port = card_get_port(base_address);
    if (port == USDHC_NUMBER_PORTS) {
        printf("Base address: 0x%x not in address table.\n", base_address);
        return status;
    }

    while ((count < MMC_VOLT_VALID_COUNT) && (status == FAIL)) {
        /* Configure CMD1 */
        card_cmd_config(&cmd, CMD1, ocr_val, READ, RESPONSE_48, DATA_PRESENT_NONE, FALSE, FALSE);

        /* Send CMD1 */
        if (host_send_cmd(base_address, &cmd) == FAIL) {
            printf("Send CMD1 failed.\n");
            break;
        } else {
            /* Check Response */
            response.format = RESPONSE_48;
            host_read_response(base_address, &response);

            /* Check Busy Bit Cleared or NOT */
            if (response.cmd_rsp0 & CARD_BUSY_BIT) {
                /* Check Address Mode */
                if ((response.cmd_rsp0 & MMC_OCR_HC_BIT_MASK) == MMC_OCR_HC_RESP_VAL) {
                    usdhc_device[port].addr_mode = SECT_MODE;
                } else {
                    usdhc_device[port].addr_mode = BYTE_MODE;
                }

                status = SUCCESS;
            } else {
                count++;
                hal_delay_us(MMC_VOLT_VALID_DELAY);
            }
        }
    }

    return status;
}
