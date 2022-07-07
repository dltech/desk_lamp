#ifndef H_INTERRUPTS_REGS
#define H_INTERRUPTS_REGS
/*
 * PWM driver for desk lamp. My addition to AVR-GCC lib with bits macro
 * for interrupt registers
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

/* MCUCR – MCU Control Register */
// ISC: Interrupt Sense Control 0 Bit 1 and Bit 0
#define ISC_LOW     0x1
#define ISC_ANY     0x1
#define ISC_FALL    0x2
#define ISC_RISE    0x3

/* GIMSK – General Interrupt Mask Register */
// External Interrupt Request 0 Enable
#define INT0    0x40
// Pin Change Interrupt Enable
#define PCIE    0x20

/* GIFR – General Interrupt Flag Register */
// External Interrupt Flag 0
#define INTF0   0x40
// Pin Change Interrupt Flag
#define PCIF    0x20

/* PCMSK – Pin Change Mask Register */
// Pin Change Enable Mask 5:0
#define PCINT5  0x20
#define PCINT4  0x10
#define PCINT3  0x08
#define PCINT2  0x04
#define PCINT1  0x02
#define PCINT0  0x01

#endif
