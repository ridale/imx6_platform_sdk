/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "ips_test.h"

extern int ips_display_test(void);

static ipu_test_t ipu_tests[] = {
    {"IPU DISPLAY TEST", ips_display_test},
};

extern char receive_char(void);

int ipu_test(void)
{
    int retv, idx;
    char sel;

    printf("\n---- Running IPU test, type 'x' to exit.\n");
    ipu_iomux_config();
    display_device_init();

    do {
        printf("Please select ipu test type:\n");
        for (idx = 0; idx < (sizeof(ipu_tests) / sizeof(ipu_test_t)); idx++) {
            printf("\t%d - %s\n", idx, ipu_tests[idx].name);
        }

        do {
            sel = receive_char();
        } while (sel == (char)0xFF);

        if (sel == 'x') {
            printf("\nTest exit.\n");
            break;
        }

        idx = sel - '0';

        if ((idx >= 0) && (idx < (sizeof(ipu_tests) / sizeof(ipu_test_t)))) {
            printf("\n");
            retv = ipu_tests[idx].test();
            if (retv == TRUE) {
                printf("\n%s test PASSED.\n", ipu_tests[idx].name);
            } else {
                printf("\n%s test FAILED.\n", ipu_tests[idx].name);
            }

        }
    } while (1);

    return retv;
}
