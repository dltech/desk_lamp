#ifndef H_ENCODER_ADC
#define H_ENCODER_ADC
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
#include <inttypes.h>
#include "regs/adc_regs.h"

// voltages of resistor aray
#define VOLT_ERROR  2
#define ENC_NC_VOLT     (((uint16_t)VOLT_TO_ADC_5V(33-VOLT_ERROR)) >> 2)
#define ENC_BOTH_VOLT   (((uint16_t)VOLT_TO_ADC_5V(25-VOLT_ERROR)) >> 2)
#define ENC_A_VOLT      (((uint16_t)VOLT_TO_ADC_5V(20-VOLT_ERROR)) >> 2)
#define ENC_B_VOLT      (((uint16_t)VOLT_TO_ADC_5V(10-VOLT_ERROR)) >> 2)

enum{
    ENC_NC = 0,
    ENC_BOTH,
    ENC_A,
    ENC_B,
    ENC_BREAK
} encoderStateMachine;

#define STABLE_CNT    50
enum {
    ENC_NOTHING = 0,
    ENC_CLOCKWISE,
    ENC_ANTICLOCKWISE
};

// encoder init
void encoderInit(void);

#endif
