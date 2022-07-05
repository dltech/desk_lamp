/*
 * PWM driver for desk lamp. Functions for encoder control.
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
#include <avr/interrupt.h>
#include "lib/regs/timer_regs.h"
#include "encoder_button.h"

void encoder_init()
{
    s
    // timer interrupt init
    TIMSK0 |= TOIE0;
}

void encoder_loop()
{
    if( (ENC_PORT & (ENC_LEFT | ENC_RIGHT)) == 0 ) {
        ++encoder.bothCnt;
    } else {
        encoder.bothCnt = 0;
    }
    if(encoder.bothCnt == 200)
    {

    }
}

INT(TIM0_OVF_vect)
{
    encoder_loop();
}
