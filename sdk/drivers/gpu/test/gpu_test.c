/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "sdk.h"
#include "soc_memory_map.h"
#include "hardware.h"
#include "gpu/inc/sdk_ldb_common.h"
#include "gpu/inc/sdk_ipu_common.h"
#include "gpu/inc/gpu_test_common.h"
#include "gpu/inc/sdk_gpu_utilities.h"
#include "gpu/inc/texture.h"
#include "iomux_config.h"
#include "registers/regsipu.h"

#define GPU_DEMO_WIDTH  	1024
#define GPU_DEMO_HEIGHT 	768

extern hw_module_t g_debug_uart;
extern uint8_t uart_getchar(struct hw_module *port);

extern void lvds_power_on(void);
extern void gpu_clock_config(void);

int width = GPU_DEMO_WIDTH;
int height = GPU_DEMO_HEIGHT;
int pixel_format = 4;           //2 - 16 bit; 4 - 32 bit
int depth_format = 4;           //2 - 16 bit; 4 - 32 bit 2 not work now 4 is fixed
int lcd_pixel_format = 4;       //2 - 16 bit; 4 - 32 bit

floatint new_width;
floatint new_height;
floatint new_half_width;
floatint new_half_height;
floatint neg_new_half_height;

int SAVE_BMP, ENABLEZC = 1, HZ;
int USE_FAST_CLEAR = 1;

volatile int gpu_new_frame;

int gpu_test(void)
{
    volatile uint8_t ch;
    uint32_t val;

    printf
        ("\nRunning GPU test, please connect the panel to the LVDS0, type 'y' or 'Y' to comfirm.\n");
    do {
        ch = getchar();
    } while (ch == (uint8_t) 0xFF);

    if (('Y' != ch) && ('y' != ch)) {
        return -1;
    }

    printf("GPU test running, press any key to exit.\n");

    new_width.f = (float)width;
    new_height.f = (float)height;
    new_half_width.f = ((float)width) / 2.0f;
    new_half_height.f = ((float)height) / 2.0f;
    neg_new_half_height.f = -new_half_height.f;

    ipu1_iomux_config();

    // enable GPU to access MMDC
    val = reg32_read(CSU_BASE_ADDR + 0x64);
    val |= 0xff;
    reg32_write(CSU_BASE_ADDR + 0x64, val);

    //IPU2 QoS
    reg32_write(IOMUXC_GPR7, 0xffffffff);

    //Lower GPU frequency
    val = reg32_read(GPU_3D_BASE_ADDR + 0x0);
    val &= 0xfffffc03;
    val |= 0x280;
    reg32_write(GPU_3D_BASE_ADDR + 0x0, val);
    val &= 0xfffffdff;
    reg32_write(GPU_3D_BASE_ADDR + 0x0, val);

    lvds_power_on();

    gpu_clock_config();

    ipu_setup_xga(0x24000000, 1, width, height, 0x18000000, 0x18800000, 0, 0, 1);

    val = LDB_CH0_MODE(0x1);
    val |= LDB_CH1_MODE(0x3);
    val |= 0x8000;
    val |= LDB_DI1_VS_POL(1);
    reg32_write(IOMUXC_GPR2, val);

    runTexture(CMD_BUFFER_ADDR, 0);
    while (1) {
        ch = uart_getchar(&g_debug_uart);
        if (ch != (uint8_t) 0xFF) {
            printf("GPU test exits.\n");
            break;
        }
        rotateTexture(CMD_BUFFER_ADDR);
    }

    return 0;
}