/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ips_device.c
 * @brief IPU Software library, device management 
 */

/*!
 * create a new ips device.
 * @param  dev: device type
 */
#include "ips.h"
#include "ipu_common.h"

extern ips_image_stream_t *ips_new_ims(int);

ips_device_t *ips_new_device(ips_dev_type_e devtype, char *devname)
{
    ips_device_t *device = (ips_device_t *) malloc(sizeof(ips_device_t));
    device->devtype = devtype;
    switch (devtype) {
    case IPS_DEV_DISPLAY:
        {
            ips_dev_display_t *display = (ips_dev_display_t *) malloc(sizeof(ips_dev_display_t));
            ips_pad_t *pad = NULL;
            ips_dev_panel_t *panel = &disp_dev_list[0];
            int index;
            while (index < MAX_PANEL_NUMBER) {
                if (!strcmp(panel->panel_name, devname)) {
                    break;
                } else {
                    panel++;
                    index++;
                }

            }
            if (index == MAX_PANEL_NUMBER) {
                printf("The display panel %s is not supported!!\n", devname);
                return false;
            }

            display->colorimetry = panel->colorimetry;
            display->active_window_left_offset = 0;
            display->active_window_top_offset = 0;
            display->disp_clk_pol = panel->clk_pol;
            display->disp_clock_freq = panel->pixel_clock;
            display->ext_hsync_en = 0;
            display->ext_vsync_en = panel->extern_vsync;
            display->h_active_start = panel->hsync_start_width;
            display->h_active_end = panel->hsync_end_width;
            display->h_sync_width = panel->hsync_width;
            display->v_active_start = panel->vsync_start_width;
            display->v_active_end = panel->vsync_end_width;
            display->v_sync_width = panel->vsync_start_width;
            display->if_type = panel->panel_id;
            display->total_frame_width = panel->width;
            display->total_frame_height = panel->height;
            display->if_param_ptr = (ips_display_if_t *) malloc(sizeof(ips_display_if_t));
            display->if_param_ptr->data_pol = panel->data_pol;
            display->if_param_ptr->enable_pol = panel->drdy_pol;
            display->if_param_ptr->h_sync_pol = panel->hsync_pol;
            display->if_param_ptr->v_sync_pol = panel->vsync_pol;
            display->if_param_ptr->v_to_h_sync = panel->delay_h2v;

            /*attach the device and attribute */
            device->devname = devname;
            device->devattr = panel;
            device->numsrcpads = 0;

            device->numsinkpads = 1;
            pad = (ips_pad_t *) malloc(sizeof(ips_pad_t) * device->numsinkpads);
            device->sinkpads = pad;
            pad->padname = "interface";
            pad->parent = device;
            pad->prev = pad->next = NULL;
            panel->panel_init(0);   //initialize the panel

            break;
        }
    case IPS_DEV_MEM:
        {
            ips_dev_memory_t *mem = (ips_dev_memory_t *) malloc(sizeof(ips_dev_memory_t));
            ips_pad_t *pad = NULL;

            mem->active_frame_buf = 0;
            mem->number_frame_buf = 1;
            ips_mem_buffer_addr_t *buffer =
                (ips_mem_buffer_addr_t *) malloc(sizeof(ips_mem_buffer_addr_t) *
                                                 mem->number_frame_buf);
            memset((void *)buffer, 0, sizeof(ips_mem_buffer_addr_t) * mem->number_frame_buf);
            buffer->base_addr_0 = 0x70000000;
            buffer->base_addr_1 = 0x72000000;
            mem->buffer = buffer;
            mem->create_ims = &ips_new_ims;

            device->devname = devname;
            device->devattr = mem;

            device->numsrcpads = 1;
            pad = (ips_pad_t *) malloc(sizeof(ips_pad_t) * device->numsrcpads);
            pad->padname = "output";
            pad->parent = device;
            device->srcpads = pad;
            device->numsinkpads = 1;
            pad = (ips_pad_t *) malloc(sizeof(ips_pad_t) * device->numsinkpads);
            pad->padname = "input";
            pad->parent = device;

            device->sinkpads = pad;
        }
        break;
    case IPS_DEV_IPU:
        {
            ips_dev_ipu_t *ipu = (ips_dev_ipu_t *) malloc(sizeof(ips_dev_ipu_t));
            ips_pad_t *pad = NULL;

            /*attach the device and attribute */
            device->devname = devname;
            device->devattr = ipu;
            device->numsrcpads = 0;

            device->numsinkpads = 2;
            pad = (ips_pad_t *) malloc(sizeof(ips_pad_t) * device->numsinkpads);
            device->sinkpads = pad;
            pad->padname = "dcin";
            pad->parent = device;
            pad->prev = pad->next = NULL;
            pad += 1;
            pad->padname = "dpin";
            pad->parent = device;
            pad->prev = pad->next = NULL;

            device->numsrcpads = 2;
            pad = (ips_pad_t *) malloc(sizeof(ips_pad_t) * device->numsrcpads);
            device->srcpads = pad;
            pad->padname = "di0";
            pad->parent = device;
            pad->prev = pad->next = NULL;
            pad += 1;
            pad->padname = "di1";
            pad->parent = device;
            pad->prev = pad->next = NULL;
            break;
        }
    default:
        printf("The device type is not defined!!\n");
        return false;
    }

    return device;
}

void ips_delete_device(ips_device_t * dev)
{
    free(dev->devattr);
    free(dev->srcpads);
    free(dev->sinkpads);
    free(dev);
}

void ips_update_attr_params(void *dev, uint32_t attr_offset, uint32_t val)
{
    mem32_write((char *)(dev + attr_offset), val);
}

int ips_update_ims_attr_params(ips_image_stream_t * ims, uint32_t attr_offset, uint32_t val)
{
    int ipu_index = 1;
    mem32_write((char *)(ims + attr_offset), val);
    switch (attr_offset) {
    case OFFSETOF(ips_image_stream_t, base0):
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_EBA0, val / 8);
        break;
    case OFFSETOF(ips_image_stream_t, base1):
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_EBA1, val / 8);
        break;
    case OFFSETOF(ips_image_stream_t, width):
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_FW, val - 1);
        break;
    case OFFSETOF(ips_image_stream_t, height):
        ipu_cpmem_set_field(ipu_cpmem_addr(ipu_index, ims->channel), NON_INTERLEAVED_FH, val - 1);
        break;
    default:
        printf("unknown image stream field!!\n");
        return false;
    }
    return true;
}

void ips_set_device(void *dev_attr, uint32_t attr, uint32_t val, ...)
{
    va_list attr_list;
    int ret = true;

    va_start(attr_list, val);
    while (attr != EOP) {
        ips_update_attr_params(dev_attr, attr, val);
        attr = va_arg(attr_list, uint32_t);
        val = va_arg(attr_list, uint32_t);
    }
    va_end(attr_list);
}

ips_pad_t *ips_device_get_src_pad(ips_device_t * dev, const char *padname)
{
    ips_pad_t *pad, *padnode;
    int index = 0;

    pad = dev->srcpads;
    for (index = 0; index < dev->numsrcpads; index++) {
        if (!strcmp(pad->padname, padname))
            return pad;
        pad++;
    }
    printf("No source pad named %s can be found!\n", padname);

    return NULL;
}

ips_pad_t *ips_device_get_sink_pad(ips_device_t * dev, const char *padname)
{
    ips_pad_t *pad;
    int index = 0;

    pad = dev->sinkpads;
    for (index = 0; index < dev->numsinkpads; index++) {
        if (!strcmp(pad->padname, padname))
            return pad;
        pad++;
    }
    printf("No sink pad named %s can be found!\n", padname);

    return false;
}

int ips_link_device_pads(ips_device_t * src, const char *srcpadname, ips_device_t * dest,
                         const char *destpadname)
{
    /*pseudo code */
    ips_pad_t *srcpad, *destpad;

    /*step1: check the validity of input, and get the pad attribute.
       first, one device may have several sinks or sources
       second, check the pad parameters match or not */
    srcpad = ips_device_get_src_pad(src, srcpadname);
    if (!srcpad) {
        printf("No pad named %s found in device %s\n", srcpadname, src->devname);
        return false;
    }

    destpad = ips_device_get_sink_pad(dest, destpadname);
    if (!destpad) {
        printf("No pad named %s found in device %s\n", destpadname, dest->devname);
        return false;
    }

    /*step2: set the pad related hardware */
    if (dest->devtype == IPS_DEV_DISPLAY) {
        if (!strcmp(destpadname, "dpin")) ;
    }

    /*step3: link the two pads */
    srcpad->next = destpad;
    destpad->prev = srcpad;

    return true;
}

int ips_link_device(ips_device_t * dev1, char *outpad, char *inpad, ips_device_t * dev2)
{
    /*like the pads of the two devices, dev1.src <==> dev2.sink */
    return ips_link_device_pads(dev1, outpad, dev2, inpad);
}
ips_device_t *ips_link_device_many(ips_device_t * dev1, char *outpad, char *inpad,
                                   ips_device_t * dev2, ...)
{
    ips_device_t *superdev = (ips_flow_t *) malloc(sizeof(ips_device_t));
    va_list dev_list;
    int ret = true;

    superdev->devtype = IPS_DEV_SUPER_DEVICE;
    // the sink pad of super device should be the pad of first device in the chain
    superdev->numsinkpads = dev1->numsinkpads;
    superdev->sinkpads = dev1->sinkpads;

    va_start(dev_list, dev2);
    while ((dev2 != NULL) && (dev1 != NULL)) {
        if (!ips_link_device(dev1, outpad, inpad, dev2)) {
            printf("device link error!!\n");
            ret = false;
            break;
        }
        dev1 = dev2;
        outpad = va_arg(dev_list, char *);
        if (outpad == NULL)
            break;
        inpad = va_arg(dev_list, char *);
        dev2 = va_arg(dev_list, ips_device_t *);
    }

    va_end(dev_list);

    // the source pad of super device should be the pad of last device in the chain
    superdev->numsrcpads = dev2->numsrcpads;
    superdev->srcpads = dev2->srcpads;

    return superdev;
}

inline int is_src_pad(ips_device_t * dev, char *padname)
{
    if (ips_device_get_src_pad(dev, padname) == NULL)
        return true;
    else
        return false;
}

void ips_flow_link_dev(ips_flow_t * flow, char *padname, ips_device_t * dev, char *devpadname)
{
    ips_dev_chain_t *temp;
    ips_pad_t *pad;

    if (is_src_pad(dev, devpadname)) {
        temp = flow->head;
        while (temp->node != NULL) {
            pad = ips_device_get_sink_pad(temp->node, padname);
            if (pad != NULL) {
                ips_link_device(temp->node, pad->padname, devpadname, dev);
                ips_flow_add_device(flow, dev);
                return true;
            } else
                temp = temp->next;
        }

    } else {
        temp = flow->head;
        while (temp->node != NULL) {
            pad = ips_device_get_src_pad(temp->node, padname);
            if (pad != NULL) {
                ips_link_device(dev, devpadname, pad->padname, temp->node);
                ips_flow_add_device(flow, dev);
                return true;
            } else
                temp = temp->next;
        }
    }

    return false;
}
