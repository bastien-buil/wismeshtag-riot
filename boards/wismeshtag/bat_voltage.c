/*
 * SPDX-FileCopyrightText: 2026 Bastien BUIL
 * SPDX-License-Identifier: MIT
 */
/**
 * @ingroup     boards_wismeshtag
 * @{
 *
 * @file
 * @brief       Implementation of battery voltage convert function
 *
 * @author      Bastien BUIL <git@buil.ovh>
 */

#ifdef MODULE_SAUL_BAT_VOLTAGE
#  include "saul/bat_voltage.h"

int16_t saul_bat_voltage_convert(int32_t adc_sample)
{
    /* Return millivolts
     * https://github.com/meshcore-dev/MeshCore/blob/main/variants/rak_wismesh_tag/RAKWismeshTagBoard.h
     *
     * Not working !!!!
     */
    const int32_t ADC_RESOLUTION = 10;
    return (int16_t)(( (3L * 1.73L * 1.187L * 1000L)*adc_sample) / ((1 << ADC_RESOLUTION) - 1));
}

#endif // MODULE_SAUL_BAT_VOLTAGE

/** @} */
