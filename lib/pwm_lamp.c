/*
 * PWM driver for desk lamp.
 *
 * Copyright 2022 Mikhail Belkin <dltech174@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <avr/io.h>
#include <stdlib.h>
#include "regs/timer_regs.h"
#include "pwm_lamp.h"

volatile colourTyp colour;

void pwm_init()
{
    // struct init
    colour.red   = 0;
    colour.green = 0;
    colour.blue  = 0;
    colour.white = 0;
    // timer init
    TCNT0  = 0;
    TCCR0A = COM0A_NORMAL | COM0B_NORMAL | WGM01_NORMAL;
    TCCR0B = CS0_NO_PRESCALE;
    // port init
    DDRB = PIN_RED | PIN_GREEN | PIN_BLUE | PIN_WHITE;
}

void pwm_cycle()
{
    if(TCNT0 >= colour.red) {
        PWM_PORT |= PIN_RED;
    } else {
        PWM_PORT &= ~PIN_RED;
    }
    if(TCNT0 >= colour.green) {
        PWM_PORT |= PIN_GREEN;
    } else {
        PWM_PORT &= ~PIN_GREEN;
    }
    if(TCNT0 >= colour.blue) {
        PWM_PORT |= PIN_BLUE;
    } else {
        PWM_PORT &= ~PIN_BLUE;
    }
    if(TCNT0 >= colour.white) {
        PWM_PORT |= PIN_WHITE;
    } else {
        PWM_PORT &= ~PIN_WHITE;
    }
}
