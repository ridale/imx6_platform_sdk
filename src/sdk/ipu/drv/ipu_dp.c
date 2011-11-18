/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ipu_dp.c
 * @brief display controller configuration of IPU.
 * @ingroup diag_ipu
 */

#include "ipu_common.h"

/*!
 * config the DP module, mainly to perform blending, CSC and gamma correction
 * @param	ipu_index:	ipu index
 * @param	conf:		ipu configuration data structure
 */
void ipu_dp_config(uint32_t ipu_index, uint32_t csc_type, uint32_t dual_disp, uint32_t fg_xp,
                   uint32_t fg_yp, uint32_t alpha)
{
    ipu_dp_fg_config(ipu_index, dual_disp, fg_xp, fg_yp, alpha);
    ipu_dp_csc_config(ipu_index, 0, csc_type);
}

/*!
* this function is used to config the color space conversion task in the DP
* @param ipu_index: ipu index, 1 or 2
* @param dp_csc_params: csc conversion matrix
*/
void ipu_dp_csc_config(uint32_t ipu_index, uint32_t dp, uint32_t csc_type)
{
    unsigned int ipu_base_addr = 0;
    int32_t(*coef)[3];

    /*  Y = R *  .299 + G *  .587 + B *  .114;
       U = R * -.169 + G * -.332 + B *  .500 + 128.;
       V = R *  .500 + G * -.419 + B * -.0813 + 128.; */
    int rgb2yuv_coef[5][3] = {
        {0x04D, 0x096, 0x01D},
        {0x3D5, 0x3AB, 0x080},
        {0x080, 0x395, 0x3EB},
        {0x0000, 0x0200, 0x0200},
        {0x2, 0x2, 0x2},
    };

    /* R = (1.164 * (Y - 16)) + (1.596 * (Cr - 128));
       G = (1.164 * (Y - 16)) - (0.392 * (Cb - 128)) - (0.813 * (Cr - 128));
       B = (1.164 * (Y - 16)) + (2.017 * (Cb - 128); */
    int yuv2rgb_coef[5][3] = {
        {0x4A, 0x0, 0x66},
        {0x4A, 0x3E7, 0x39C},   //4A 3E7 3CC
        {0x4A, 0x7F, 0x0},      //4A 81 0
        {0x3F21, 0x85, 0x3EEA}, //3F22 85 3EEB // A0, A1, A2
        {0x0, 0x0, 0x0},        /*S0,S1,S2 */
    };

    if (ipu_index == 1)
        ipu_base_addr = IPU1_CTRL_BASE_ADDR;
    else
        ipu_base_addr = IPU2_CTRL_BASE_ADDR;

    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_CSC_YUV_SAT_MODE_SYNC, 0);  //SAT mode is zero
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_CSC_GAMUT_SAT_EN_SYNC, 0);  //GAMUT en (RGB...)

    if (csc_type == NO_CSC)
        ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_CSC_DEF_SYNC, 0);   //disable CSC
    else
        ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_CSC_DEF_SYNC, 2);   //disable CSC

    if (csc_type == RGB_YUV)
        coef = rgb2yuv_coef;
    else if (csc_type == YUV_RGB)
        coef = yuv2rgb_coef;
    else
        coef = NULL;

    if (coef) {
        writel(GET_LSB(10, coef[0][0]) | (GET_LSB(10, coef[0][1]) << 16),
               ipu_base_addr + SRM_DP_CSCA_SYNC_0__ADDR + dp * 4);
        writel(GET_LSB(10, coef[0][2]) | (GET_LSB(10, coef[1][0]) << 16),
               ipu_base_addr + SRM_DP_CSCA_SYNC_1__ADDR + dp * 4);
        writel(GET_LSB(10, coef[1][1]) | (GET_LSB(10, coef[1][2]) << 16),
               ipu_base_addr + SRM_DP_CSCA_SYNC_2__ADDR + dp * 4);
        writel(GET_LSB(10, coef[2][0]) | (GET_LSB(10, coef[2][1]) << 16),
               ipu_base_addr + SRM_DP_CSCA_SYNC_3__ADDR + dp * 4);
        writel(GET_LSB(10, coef[2][2]) | (GET_LSB(14, coef[3][0]) << 16) |
               (coef[4][0] << 30), ipu_base_addr + SRM_DP_CSC_SYNC_0__ADDR + dp * 4);
        writel(GET_LSB(14, coef[3][1]) | (coef[4][1] << 14) |
               (GET_LSB(14, coef[3][2]) << 16) | (coef[4][2] << 30),
               ipu_base_addr + SRM_DP_CSC_SYNC_1__ADDR + dp * 4);
    }

    ipu_write_field(ipu_index, IPU_IPU_SRM_PRI2__DP_S_SRM_MODE, 3);
    ipu_write_field(ipu_index, IPU_IPU_SRM_PRI2__DP_SRM_PRI, 0x0);
}

/*!
* this function is used to config the foreground plane for combination in the DP
* @param ipu_index: ipu index
* @param foreground_params: params for the foreground, including offset and size
*/
void ipu_dp_fg_config(uint32_t ipu_index, uint32_t dual_disp, uint32_t fg_xp, uint32_t fg_yp,
                      uint32_t alpha)
{
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_GAMMA_EN_SYNC, 0);
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_GAMMA_YUV_EN_SYNC, 0);

    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_COC_SYNC, 0);
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_GWCKE_SYNC, 0); //color key
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_GWAM_SYNC, 1);  //1=global alpha,0=local alpha
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_GWSEL_SYNC, 0); //1=graphic is FG,0=graphic is BG

    if (dual_disp) {
        ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_FG_EN_SYNC, 1); //1=FG channel enabled,0=FG channel disabled
        ipu_write_field(ipu_index, SRM_DP_FG_POS_SYNC__DP_FGXP_SYNC, fg_xp);
        ipu_write_field(ipu_index, SRM_DP_FG_POS_SYNC__DP_FGYP_SYNC, fg_yp);
        ipu_write_field(ipu_index, SRM_DP_GRAPH_WIND_CTRL_SYNC__DP_GWAV_SYNC, alpha);   // set the FG opaque
        ipu_write_field(ipu_index, SRM_DP_GRAPH_WIND_CTRL_SYNC__DP_GWCKR_SYNC, 0xFF);
        ipu_write_field(ipu_index, SRM_DP_GRAPH_WIND_CTRL_SYNC__DP_GWCKG_SYNC, 0xFF);
        ipu_write_field(ipu_index, SRM_DP_GRAPH_WIND_CTRL_SYNC__DP_GWCKB_SYNC, 0xFF);
    } else
        ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_FG_EN_SYNC, 0); //1=FG channel enabled,0=FG channel disabled
}