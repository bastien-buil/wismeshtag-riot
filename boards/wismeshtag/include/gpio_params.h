/*
 * SPDX-FileCopyrightText: 2026 Bastien BUIL
 * SPDX-License-Identifier: MIT
 */
/**
 * @ingroup     boards_wismeshtag
 * @{
 *
 * @file
 * @brief       Configuration of SAUL GPIO pins for WisMeshTag
 *
 * @author      Bastien BUIL <git@buil.ovh>
 */

#pragma once


#ifdef __cplusplus
extern "C" {
#endif


#if MODULE_SAUL_GPIO || DOXYGEN
#include "board.h"
#include "saul/periph.h"

/**
 * @brief Saul GPIO configuration
 */
static const saul_gpio_params_t saul_gpio_params[] = {
    {
        .name = "Main Button",
        .pin = BTN0_PIN,
        .mode = BTN0_MODE,
        .flags = SAUL_GPIO_INVERTED,
    },
    {
        .name = "Green LED",
        .pin = LED0_PIN,
        .mode = GPIO_OUT,
        .flags = SAUL_GPIO_INIT_CLEAR,
    },
    {
        .name = "Blue LED",
        .pin = LED1_PIN,
        .mode = GPIO_OUT,
        .flags = SAUL_GPIO_INIT_CLEAR,
    },
};

#endif // MODULE_SAUL_GPIO || DOXYGEN

#ifdef __cplusplus
}
#endif

/** @} */
