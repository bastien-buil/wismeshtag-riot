/*
 * SPDX-FileCopyrightText: 2026 - Bastien BUIL
 * SPDX-License-Identifier: MIT
 */

/**
 * @ingroup     Wismesh example
 * @{
 *
 * @file
 * @brief       wismesh battery application
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



int main(void)
{
    phydat_t bat_volt;
    int success;
    int power_less_check = 0;
    int power_plugged = 0;
    saul_reg_t *bat_sensor = saul_reg_find_name("BAT");
    delay();
    while (1) {
        printf("Battery\n");
        success = saul_reg_read(bat_sensor, &bat_volt);
        printf("success=%d\n", success);
        power_plugged = usb_plugged();
        if(!usb_plugged()){
            power_less_check++;
            LED1_OFF;
        }else {
            LED1_ON;
        }
        printf("power_less_check=%d\n", power_less_check);
        delay();
        printf("power_plugged=%d\n", power_plugged);
        phydat_dump(&bat_volt, 1);
    }

    return 0;
}
