#ifndef H_ADC_REGS
#define H_ADC_REGS
/*
 * PWM driver for desk lamp. My addition to AVR-GCC lib with bits macro
 * for ADC registers.
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

/* ADMUX – ADC Multiplexer Selection Register */
// Reference Selection Bit
#define REFS0_VCC   0x00
#define REFS0_REF   0x40
// Reference Selection Bit
#define ADLAR       0x20
// Analog Channel Selection Bits
#define MUX_ADC0    0x00
#define MUX_ADC1    0x01
#define MUX_ADC2    0x02
#define MUX_ADC3    0x03

/* ADCSRA – ADC Control and Status Register A */
// ADC Enable
#define ADEN        0x80
// ADC Start Conversion
#define ADSC        0x40
// ADC Auto Trigger Enable
#define ADATE       0x20
// ADC Interrupt Flag
#define ADIF        0x10
// ADC Interrupt Enable
#define ADIE        0x08
// ADC Prescaler Select Bits
#define ADPS_DIV2   0x01
#define ADPS_DIV4   0x02
#define ADPS_DIV8   0x03
#define ADPS_DIV16  0x04
#define ADPS_DIV32  0x05
#define ADPS_DIV64  0x06
#define ADPS_DIV128 0x07

/* ADCSRB – ADC Control and Status Register B */
// ADC Auto Trigger Source
#define ADTS_FREE       0x0
#define ADTS_COMPARATOR 0x1
#define ADTS_EXTI0      0x2
#define ADTS_CCRA       0x3
#define ADTS_OVERFLOW   0x4
#define ADTS_CCRB       0x5
#define ADTS_PIN_IT     0x6

/* Digital Input Disable Register 0 */
// ADC0 Digital Input Disable
#define ADC0D   0x20
// ADC2 Digital Input Disable
#define ADC2D   0x10
// ADC3 Digital Input Disable
#define ADC3D   0x08
// ADC1 Digital Input Disable
#define ADC1D   0x04

// formula for converting volts to adc value in case of 5V reference
#define VOLT_TO_ADC_5V(volt)    volt*1024/50

#endif
