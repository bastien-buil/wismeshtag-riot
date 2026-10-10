/*
 * SPDX-FileCopyrightText: 2026 Bastien BUIL
 * SPDX-License-Identifier: MIT
 */
/**
 * @ingroup     boards_wismeshtag
 * @{
 *
 * @file
 * @brief       Configuration for GPS
 *
 * @author      Bastien BUIL <git@buil.ovh>
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MODULE_PERIPH_UART
#error GPS implementation for wismeshtag require UART peripheral (periph_uart)
#endif

#include "periph/uart.h"
#include "periph/gpio.h"

// GPS PPS 17

static inline int gps_init(uart_rx_cb_t uart_cb) {
    gpio_init(34, GPIO_OUT);
    return uart_init(UART_DEV(1), 9600, uart_cb, NULL);
}

static inline void gps_on(void) {
    return gpio_set(34);
}

static inline void gps_off(void) {
    return gpio_clear(34);
}


#ifdef __cplusplus
}
#endif

/** @} */
