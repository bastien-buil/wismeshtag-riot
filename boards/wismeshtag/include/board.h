/*
 * SPDX-FileCopyrightText: 2026 Bastien BUIL
 * SPDX-License-Identifier: MIT
 */
/**
 * @ingroup     boards_wismeshtag
 * @{
 *
 * @file
 * @brief       Board configuration for WisMeshTag
 *
 * @author      Bastien BUIL <git@buil.ovh>
 */

#pragma once

#include "cpu.h"  // IWYU pragma: export
#include "periph/gpio.h"  // IWYU pragma: export

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    LED pin configuration
 * @{
 */
#define LED0_PIN    GPIO_PIN(1, 3)
#define LED1_PIN    GPIO_PIN(1, 4)

#define LED0_ON     (gpio_set(LED0_PIN))
#define LED0_OFF    (gpio_clear(LED0_PIN))
#define LED0_TOGGLE (gpio_toggle(LED1_PIN))

#define LED1_ON     (gpio_set(LED1_PIN))
#define LED1_OFF    (gpio_clear(LED1_PIN))
#define LED1_TOGGLE (gpio_toggle(LED1_PIN))
/** @} */

/**
 * @name    Button pin configuration
 * @{
 */
#define BTN0_PIN    GPIO_PIN(0, 9)
#define BTN0_MODE   GPIO_IN_PU
/** @} */

#define BUZZER_PIN  GPIO_PIN(0, 21)

static inline int usb_plugged(void) {
    return !!(NRF_POWER->USBREGSTATUS & POWER_USBREGSTATUS_VBUSDETECT_Msk);
}


#ifdef __cplusplus
}
#endif

/** @} */
