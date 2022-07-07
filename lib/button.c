/*
 * PWM driver for desk lamp. Interrupt button handle.
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
#include <avr/interrupt.h>
#include <avr/io.h>
#include "regs/interrupts_regs.h"
#include "lamp_menu.h"
//#include "delay.h"
#include "util/delay.h"
#include "button.h"

void buttonsInit()
{
    // pull up on button
    SW_PORT |= SW_GPIO;
    // interrupt on button push
    MCUCR = ISC_FALL;
    GIMSK = INT0;
    GIFR  = INTF0;
    PCMSK = PCINT3;
}

ISR(INT0_vect)
{
    _delay_ms(20);
    if( (SW_PIN & SW_GPIO) > 0) {
        buttonCallback();
    }
    uint8_t duration = 0;
    while( ((SW_PIN & SW_GPIO) > 0) && (++duration <= 20) ) {
        _delay_ms(100);
    }
    if(duration == 20) {
        longButtonCallback();
    }
}
