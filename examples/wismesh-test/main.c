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
#include "periph/pwm.h"
#include "ztimer.h"

char button_pressed = 0;
#define BUZZER_RES      1000
#define BUZZER_CHANNEL      0

static void delay(void)
{
    uint32_t loops = coreclk() / 20 ;
    for (volatile uint32_t i = 0; i < loops; i++) {
        if (!gpio_read(BTN0_PIN)) { // If (on)
            LED1_ON;
            if(button_pressed == 0) {
                LED1_ON;
                pwm_set(PWM_DEV(0), BUZZER_CHANNEL, BUZZER_RES/2);

                ztimer_sleep(ZTIMER_USEC, 100000);
                pwm_set(PWM_DEV(0), BUZZER_CHANNEL, 0);
            }
            button_pressed = 1;
        }
        else {
            button_pressed = 0;
            LED1_OFF;
        }
    }

}

int main(void)
{
    delay();
    uint32_t result = pwm_init(PWM_DEV(0), PWM_LEFT, 4000, BUZZER_RES);
    if(result == 0) {
        puts("PWM initialization failed");
        return -1;
    }
    printf("Buzzer PWM frequency: %lu Hz\n", (unsigned long)result);
    while (1) {

        LED0_OFF;
        delay();
        LED0_ON;
        puts("Blink! ");
        delay();
    }

    return 0;
}
