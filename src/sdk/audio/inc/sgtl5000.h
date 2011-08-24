/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#ifndef __SGTL5000_H
#define __SGTL5000_H

#include "../inc/audio.h"

#define DAC_VOL_UP 1
#define DAC_VOL_DOWN 0
#define DAC_I2S_CONFIG 2
#define DAC_INIT 3

#define SGTL5000_I2C_ADDR	0x14
#define SGTL5000_ID  (SGTL5000_I2C_ADDR>>1)

#define PLL_OUTPUT_FREQ_180633600HZ    180633600
#define PLL_OUTPUT_FREQ_196608000HZ    196608000

typedef struct DAPPara {
    unsigned char bass_enhance;
    unsigned char eq;
    unsigned char peq;          /* parametic eq */
} DAPPara_t;

/*int SGTL5000CodecConfig(void *);
int SGTL5000CodecInit(void *);
int SGTL5000CodecI2SConfig(void *, AUDIO_PARAS_t * paras);*/

#endif //__SGTL5000_H
