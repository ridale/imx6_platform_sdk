/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "vpu_test.h"

static int fb_index;
static struct frame_buf *fbarray[NUM_FRAME_BUFS];
static struct frame_buf fbpool[NUM_FRAME_BUFS];
vdec_frame_buffer_t gDecFifo[NUM_FRAME_BUFS];
uint32_t gBsBuffer[NUM_FRAME_BUFS];

void framebuf_init(void)
{
    int i;

    for (i = 0; i < NUM_FRAME_BUFS; i++) {
        fbarray[i] = &fbpool[i];
    }

    for (i = 0; i < MAX_NUM_INSTANCE; i++)
        disp_clr_index[i] = -1;
}

struct frame_buf *get_framebuf(void)
{
    struct frame_buf *fb;

    fb = fbarray[fb_index];
    fbarray[fb_index] = 0;

    ++fb_index;
    fb_index &= FB_INDEX_MASK;

    return fb;
}

void put_framebuf(struct frame_buf *fb)
{
    --fb_index;
    fb_index &= FB_INDEX_MASK;

    fbarray[fb_index] = fb;
}

void dec_fifo_init(vdec_frame_buffer_t * fifo, int size)
{
    fifo->size = size;
    fifo->wrptr = 0;
    fifo->rdptr = 0;
    fifo->full = 0;
    fifo->popCnt = 0;
}

int dec_fifo_is_full(vdec_frame_buffer_t * fifo)
{
    return (fifo->full);
}

int dec_fifo_is_empty(vdec_frame_buffer_t * fifo)
{
    return ((fifo->rdptr == fifo->wrptr) && !(fifo->full));
}

/*one frame is in-queued*/
int dec_fifo_push(vdec_frame_buffer_t * fifo, uint32_t frame, uint32_t id)
{
    if (fifo->full)
        return -1;

    fifo->frames[fifo->wrptr] = frame;
    fifo->id[fifo->wrptr] = id;

    if (++fifo->wrptr == fifo->size)
        fifo->wrptr = 0;

    if (fifo->wrptr == fifo->rdptr)
        fifo->full = 1;

    return 0;
}

/*one frame is dequeued*/
int dec_fifo_pop(vdec_frame_buffer_t * fifo, uint32_t * frame, uint32_t * id)
{
    if ((fifo->rdptr == fifo->wrptr) && !(fifo->full))
        return -1;

    *frame = fifo->frames[fifo->rdptr];
    *id = fifo->id[fifo->rdptr];

    if (++fifo->rdptr == fifo->size)
        fifo->rdptr = 0;

    if (fifo->full)
        fifo->full = 0;

    return 0;
}

struct frame_buf *framebuf_alloc(int stdMode, int format, int strideY, int height, int mvCol)
{
    struct frame_buf *fb;
    int err;
    int divX, divY;

    fb = get_framebuf();
    if (fb == NULL)
        return NULL;

    divX = (format == MODE420 || format == MODE422) ? 2 : 1;
    divY = (format == MODE420 || format == MODE224) ? 2 : 1;

    memset(&(fb->desc), 0, sizeof(vpu_mem_desc));
    fb->desc.size = (strideY * height + strideY / divX * height / divY * 2);
    if (mvCol)
        fb->desc.size += strideY / divX * height / divY;

    err = IOGetMem(&fb->desc);
    if (err) {
        printf("Frame buffer allocation failure\n");
        memset(&(fb->desc), 0, sizeof(vpu_mem_desc));
        return NULL;
    }

    fb->addrY = fb->desc.phy_addr;
    fb->addrCb = fb->addrY + strideY * height;
    fb->addrCr = fb->addrCb + strideY / divX * height / divY;
    fb->strideY = strideY;
    fb->strideC = strideY / divX;
    if (mvCol)
        fb->mvColBuf = fb->addrCr + strideY / divX * height / divY;

    /*set the background to black */
    memset((void *)fb->addrY, 0x10, strideY * height);
    memset((void *)fb->addrCr, 0x80, strideY * height >> 2);
    memset((void *)fb->addrCb, 0x80, strideY * height >> 2);
    if (mvCol) {
        fb->desc.virt_uaddr = fb->desc.phy_addr;
        fb->mvColBuf = fb->addrCr + strideY / divX * height / divY;
    }
    return fb;
}

struct frame_buf *tiled_framebuf_alloc(int stdMode, int format, int strideY, int height, int mvCol,
                                       int mapType)
{
    struct frame_buf *fb;
    int err, align;
    int divX, divY;
    uint32_t lum_top_base, lum_bot_base, chr_top_base, chr_bot_base;
    uint32_t lum_top_20bits, lum_bot_20bits, chr_top_20bits, chr_bot_20bits;
    int luma_top_size, luma_bot_size, chroma_top_size, chroma_bot_size;

    fb = get_framebuf();
    if (fb == NULL)
        return NULL;

    divX = (format == MODE420 || format == MODE422) ? 2 : 1;
    divY = (format == MODE420 || format == MODE224) ? 2 : 1;

    memset(&(fb->desc), 0, sizeof(vpu_mem_desc));

/*
	 * The buffers is luma top, chroma top, luma bottom and chroma bottom for
	 * tiled map type, and only 20bits for the address description, so we need
	 * to do 4K page align for each buffer.
	 */
    align = 4 * 1024;
    if (mapType == TILED_FRAME_MB_RASTER_MAP) {
        /* luma_top_size means the Y size of one frame, chroma_top_size
         * means the interleaved UV size of one frame in frame tiled map type*/
        luma_top_size = (strideY * height + align - 1) & ~(align - 1);
        chroma_top_size = (strideY / divX * height / divY * 2 + align - 1) & ~(align - 1);
        luma_bot_size = chroma_bot_size = 0;
    } else {
        /* This is FIELD_FRAME_MB_RASTER_MAP case, there are two fields */
        luma_top_size = (strideY * height / 2 + align - 1) & ~(align - 1);
        luma_bot_size = luma_top_size;
        chroma_top_size = (strideY / divX * height / divY + align - 1) & ~(align - 1);
        chroma_bot_size = chroma_top_size;
    }
    fb->desc.size = luma_top_size + chroma_top_size + luma_bot_size + chroma_bot_size;
    /* There is possible fb->desc.phy_addr in IOGetPhyMem not 4K page align,
     * so add more SZ_4K byte here for alignment */
    fb->desc.size += align - 1;

    if (mvCol)
        fb->desc.size += strideY / divX * height / divY;

    err = IOGetMem(&fb->desc);
    if (err) {
        printf("Frame buffer allocation failure\n");
        memset(&(fb->desc), 0, sizeof(vpu_mem_desc));
        return NULL;
    }

    lum_top_base = (fb->desc.phy_addr + align - 1) & ~(align - 1);
    chr_top_base = lum_top_base + luma_top_size;
    if (mapType == TILED_FRAME_MB_RASTER_MAP) {
        lum_bot_base = 0;
        chr_bot_base = 0;
    } else {
        lum_bot_base = chr_top_base + chroma_top_size;
        chr_bot_base = lum_bot_base + luma_bot_size;
    }

    lum_top_20bits = lum_top_base >> 12;
    lum_bot_20bits = lum_bot_base >> 12;
    chr_top_20bits = chr_top_base >> 12;
    chr_bot_20bits = chr_bot_base >> 12;

    /*
     * In tiled map format the construction of the buffer pointers is as follows:
     * 20bit = addrY [31:12]: lum_top_20bits
     * 20bit = addrY [11: 0], addrCb[31:24]: chr_top_20bits
     * 20bit = addrCb[23: 4]: lum_bot_20bits
     * 20bit = addrCb[ 3: 0], addrCr[31:16]: chr_bot_20bits
     */
    fb->addrY = (lum_top_20bits << 12) + (chr_top_20bits >> 8);
    fb->addrCb = (chr_top_20bits << 24) + (lum_bot_20bits << 4) + (chr_bot_20bits >> 16);
    fb->addrCr = chr_bot_20bits << 16;
    fb->strideY = strideY;
    fb->strideC = strideY / divX;
    if (mvCol)
        fb->mvColBuf = chr_bot_base + chroma_bot_size;
    return fb;
}

void framebuf_free(struct frame_buf *fb)
{
    memset(&(fb->desc), 0, sizeof(vpu_mem_desc));
    put_framebuf(fb);
}