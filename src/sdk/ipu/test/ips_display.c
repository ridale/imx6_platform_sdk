/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <string.h>
#include <stdio.h>

#include "ips.h"
#include "ipu_common.h"
#include "ips_test.h"

int ips_display_test(void)
{
    ips_device_t *mem, *ipu, *disp;
    ips_ims_t *ims;
    ips_pad_t *srcpad;
    ips_flow_t *flow;
    ips_bin_t *bin;

    // create memory and define video output data
    disp = ips_new_device(IPS_DEV_DISPLAY, "HannStar XGA LVDS");
    mem = ips_new_device(IPS_DEV_MEM, "memory");
    ipu = ips_new_device(IPS_DEV_IPU, "ipu");

    ims = ips_new_ims();
    ips_set_ims(ims, OFFSETOF(ips_ims_t, width), 1024, EOP);
    ips_set_ims(ims, OFFSETOF(ips_ims_t, height), 768, EOP);
    srcpad = ips_device_get_src_pad(mem, "output");
    ips_set_pad_ims(srcpad, ims);

    bin = ips_new_bin("display bin");
    ips_bin_add_device_many(bin, mem, ipu, disp, NULL);
    ips_device_add_sink_pad(ipu, "common");
    ips_link_device_many(mem, "output", "common", ipu, "di0", "interface", disp, NULL);

    flow = ips_new_flow(IPU1_DP_DISP0, "di0 display", bin);
    load_centralized_image(flow);
    stream_on(flow);
    return true;
}
