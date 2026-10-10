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


//#define BUZZER_FREQ     300
//#define BUZZER_RES      1700
#define BUZZER_FREQ     800
#define BUZZER_RES      1700
#define BUZZER_CHANNEL  0

int main(void)
{
    phydat_t accel;
    ztimer_sleep(ZTIMER_MSEC, 3000);

    uint32_t result = pwm_init(PWM_DEV(0), PWM_LEFT, 300, BUZZER_RES);
    if(result == 0) {
        puts("PWM initialization failed");
        return -1;
    }
    saul_reg_t *accelerometer = saul_reg_find_type_and_name(SAUL_SENSE_ACCEL, "lis2dh12");
    if(accelerometer == NULL) {
        printf("Accelerometer not found\n");
    }

    while (1) {
        ztimer_sleep(ZTIMER_MSEC, 200);
        printf("accelerometer\n");
        saul_reg_read(accelerometer, &accel);
        int32_t score = ((accel.val[0] * accel.val[0] + accel.val[1] * accel.val[1] + accel.val[2] * accel.val[2]) / 1000000) - 2;
        printf("score %ld\n", score);
        if (score < 0) {
            score = 0;
        }
        pwm_set(PWM_DEV(0), BUZZER_CHANNEL, score);

        phydat_dump(&accel, 3);
    }

    return 0;
}
