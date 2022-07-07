/*
 * PWM driver for desk lamp. Delay functions for optimisation.
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
#include "regs/timer_regs.h"
#include "delay.h"

void delayMs(uint8_t ms)
{
    TIFR0 = 0;
    uint8_t cnt = 38;

    do {
        while((TIFR0 & TOV0) == 0);
        if(--cnt == 0) {
            cnt = 38;
            --ms;
        }
        TIFR0 = 0;
    } while(ms);
}
