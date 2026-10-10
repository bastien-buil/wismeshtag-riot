/*
 * SPDX-FileCopyrightText: 2026 Bastien BUIL
 * SPDX-License-Identifier: MIT
 */
/**
 * @ingroup     boards_wismeshtag
 * @{
 *
 * @file
 * @brief       Configuration of SAUL battery voltage
 *
 * @author      Bastien BUIL <git@buil.ovh>
 */

#pragma once

#ifdef MODULE_SAUL_BAT_VOLTAGE

#include "saul/bat_voltage.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Convert ADC sample to milliwatt
 *
 * @param[in] adc_sample The ADC Sample.
 *
 * @return Battery Voltage in Milliwatt.
 */
int16_t saul_bat_voltage_convert(int32_t adc_sample);

/**
 * @brief   Battery voltage configuration
 */
static const saul_bat_voltage_params_t saul_bat_voltage_params[] = {
    {
        .name = "BAT",
        .phydat_scale = -3, // mV as 10^-3
        .line = ADC_LINE(5),
        .res = ADC_RES_10BIT,
        .convert = saul_bat_voltage_convert,
    },
};

#ifdef __cplusplus
}
#endif

#endif // MODULE_SAUL_BAT_VOLTAGE

/** @} */
