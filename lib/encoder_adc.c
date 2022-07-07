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

#include <avr/interrupt.h>
#include "encoder_adc.h"
#include "lamp_menu.h"

// a function who turns adc samples to encoder pin signals
uint8_t portDecode(void);
// a function, returning a direction of encoder
uint8_t encoderDecode(uint8_t port);

const uint8_t encTable[4] = { (uint8_t)(((uint16_t)VOLT_TO_ADC_5V(33-VOLT_ERROR)) >> 2),
                              (uint8_t)(((uint16_t)VOLT_TO_ADC_5V(25-VOLT_ERROR)) >> 2),
                              (uint8_t)(((uint16_t)VOLT_TO_ADC_5V(20-VOLT_ERROR)) >> 2),
                              (uint8_t)(((uint16_t)VOLT_TO_ADC_5V(10-VOLT_ERROR)) >> 2)};

void encoderInit()
{
    // adc config
    ADMUX  = REFS0_VCC | ADLAR | MUX_ADC2;
    ADCSRA = ADEN | ADIE | ADPS_DIV128;
    // start conversion
    ADCSRA |= ADSC;
}

uint8_t portDecode()
{
    uint8_t adcValue = ADCH;
    if( adcValue > encTable[ENC_NC] ) {
        return ENC_NC;
    } else if( adcValue > encTable[ENC_BOTH] ) {
        return ENC_BOTH;
    } else if( adcValue > encTable[ENC_A] ) {
        return ENC_A;
    } else if( adcValue > encTable[ENC_B] ) {
        return ENC_B;
    }
    return ENC_BREAK;
}

uint8_t encoderDecode(uint8_t port)
{
    static uint8_t prevPort = ENC_BREAK;
    static uint8_t stateCnt = 0;
    static uint8_t fixed = 1;
    // a counter to fix a stable position of encoder
    if( (prevPort == port) && (stateCnt < 255) ) {
        ++stateCnt;
    }
    // fixing stable encoder previous positions only
    if( (prevPort != port) && (stateCnt > STABLE_CNT ) ) {
        prevPort = port;
        stateCnt = 0;
        fixed = 0;
    }
    // fixing states of encoder
    if( (stateCnt > STABLE_CNT) && (fixed == 0) \
     && (prevPort == ENC_A) && (port == ENC_BOTH) ) {
         fixed = 1;
         return ENC_CLOCKWISE;
    }
    if( (stateCnt > STABLE_CNT) && (fixed == 0) \
     && (prevPort == ENC_BOTH) && (port == ENC_B) ) {
         fixed = 1;
         return ENC_ANTICLOCKWISE;
    }
    return ENC_NOTHING;
}

ISR(ADC_vect)
{
    uint8_t encoder = encoderDecode(portDecode());
    if(encoder == ENC_ANTICLOCKWISE) {
        anticlockwiseCallback();
    }
    if(encoder == ENC_CLOCKWISE) {
        clockwiseCallback();
    }
    ADCSRA &= ~ADIF;
    ADCSRA |= ADSC;
}
