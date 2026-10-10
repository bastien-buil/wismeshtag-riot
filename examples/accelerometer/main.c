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

#include "clk.h"
#include "board.h"
#include "gpio_params.h"
#include "periph/pwm.h"
#include "saul_reg.h"
#include "ztimer.h"

static void delay(void)
{

    ztimer_sleep(ZTIMER_MSEC, 5000);

}

/*
 *
 * Temperature need to be calibrated (the temperature is only an offset, not an absolute temperature)
 * Accelerometer is impacted a gravity (giving orientation, in addition to the impact of movement)
 *
 */

int main(void)
{
    phydat_t accel;
    phydat_t temp;
    int success;
    delay();
    saul_reg_t *thermometer = saul_reg_find_type_and_name(SAUL_SENSE_TEMP, "lis2dh12");
    saul_reg_t *accelerometer = saul_reg_find_type_and_name(SAUL_SENSE_ACCEL, "lis2dh12");
    if(accelerometer == NULL) {
        printf("Accelerometer not found\n");
    }
    if(thermometer == NULL) {
        printf("Thermometer not found\n");
    }
    delay();
    while (1) {
        printf("accelerometer\n");
        success = saul_reg_read(accelerometer, &accel);
        printf("success=%d\n", success);
        phydat_dump(&accel, 3);
        printf("Temp\n");
        success = saul_reg_read(thermometer, &temp);
        printf("success=%d\n", success);
        phydat_dump(&temp, 1);
        delay();
    }

    return 0;
}
