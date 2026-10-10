/*
 * SPDX-FileCopyrightText: 2026 Bastien BUIL
 * SPDX-License-Identifier: MIT
 */
/**
 * @ingroup     boards_wismeshtag
 * @{
 *
 * @file
 * @brief       Configuration of peripherals for WisMeshTag
 *
 * @author      Bastien BUIL <git@buil.ovh>
 */

#pragma once

#include "cfg_clock_32_1.h" // IWYU pragma: export
#include "cfg_rtt_default.h" // IWYU pragma: export
#include "cfg_timer_default.h" // IWYU pragma: export
#include "periph_cpu.h" // IWYU pragma: export
#include "periph/gpio.h" // IWYU pragma: export

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    UART configuration
 * @{
 */
static const uart_conf_t uart_config[] = {
    {
        // RAK WISMESHTAG
        .dev = NRF_UARTE0,
        .rx_pin = GPIO_PIN(0, 24),
        .tx_pin = GPIO_PIN(0, 25),
#ifdef MODULE_PERIPH_UART_HW_FC
        .rts_pin = GPIO_UNDEF,
        .cts_pin = GPIO_UNDEF,
#endif
        .irqn = UARTE0_UART0_IRQn,
    },
    {
        // GPS
        .dev        = NRF_UARTE1,
        .rx_pin     = GPIO_PIN(0, 15),
        .tx_pin     = GPIO_PIN(0, 16),
#ifdef MODULE_PERIPH_UART_HW_FC
        .rts_pin    = GPIO_UNDEF,
        .cts_pin    = GPIO_UNDEF,
#endif
        .irqn       = UARTE1_IRQn,
    },
};

#define UART_0_ISR  (isr_uart0)
#define UART_1_ISR  (isr_uarte1)

#define UART_NUMOF ARRAY_SIZE(uart_config)
/** @} */

/**
 * @name    SPI configuration
 * @{
 */
static const spi_conf_t spi_config[] = {
    {
        .dev = NRF_SPIM0,
        .sclk = GPIO_PIN(0, 43),
        .mosi = GPIO_PIN(0, 44),
        .miso = GPIO_PIN(0, 45),
    },
    {
        .dev = NRF_SPIM1,
        .sclk = GPIO_PIN(0, 3),
        .mosi = GPIO_PIN(0, 30),
        .miso = GPIO_PIN(0, 29),
    }
};

#define SPI_NUMOF ARRAY_SIZE(spi_config)
/** @} */

/**
 * @name I2C configuration
 * @{
 */
static const i2c_conf_t i2c_config[] = {
    { .dev = NRF_TWIM1,
      .scl = 24,
      .sda = 25,
      .speed = I2C_SPEED_NORMAL }
};
#define I2C_NUMOF ARRAY_SIZE(i2c_config)
/** @} */

#ifdef __cplusplus
}
#endif

/** @} */

/**
 * @name  PWM configuration
 *
 * PWM_DEV(0): buzzer (P0.21)
 *
 * @note    Unused channels must be set to GPIO_UNDEF.
 * @{
 */
static const pwm_conf_t pwm_config[] = {
    {
        .dev = NRF_PWM0,
        .pin = {
            GPIO_PIN(0, 21),
            GPIO_UNDEF,
            GPIO_UNDEF,
            GPIO_UNDEF,
        },
    },
};

#define PWM_NUMOF ARRAY_SIZE(pwm_config)

/** @} */
