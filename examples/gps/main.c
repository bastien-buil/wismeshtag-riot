/*
 * SPDX-FileCopyrightText: 2026 - Bastien BUIL
 * SPDX-License-Identifier: MIT
 */

/**
 * @ingroup     Wismesh test
 * @{
 *
 * @file
 * @brief       wismesh test application
 *
 *
 * @}
 */

#include <stdio.h>

#include "board.h"
#include "gps.h"
#include "periph/gpio.h"
#include "periph/uart.h"
#include "ztimer.h"

static void delay(void)
{

    ztimer_sleep(ZTIMER_MSEC, 10000);

}


static void uart1_rx_cb(void *arg, uint8_t data)
{
    (void)arg;
    /* Process each received byte here */
    putchar(data);
}

int main(void)
{

    delay();
    int res = gps_init(uart1_rx_cb);
    if (res != UART_OK) {
        puts("Error initializing UART1 for GPS");
        return 1;
    }
    gps_on();

    puts("UART1 initialized and listening...");
    delay();
    while (1) {
        printf("GPS off\n");
        gps_off();

        delay();
        printf("GPS on\n");
        gps_on();
        delay();
    }

    return 0;
}
