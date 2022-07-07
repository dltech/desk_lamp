#ifndef H_TIMER_REGS
#define H_TIMER_REGS
/*
 * PWM driver for desk lamp. My addition to AVR-GCC lib with bits macro
 * for timer registers
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

/* TCCR0A – Timer/Counter Control Register A */
// Compare Match Output A Mode
#define COM0A_NORMAL                0x00
#define COM0A_TOGGLE_ON_A_COMPARE   0x40
#define COM0A_CLEAR_ON_A_COMPARE    0x80
#define COM0A_SET_ON_A_COMPARE      0xc0
// Compare Match Output B Mode
#define COM0B_NORMAL                0x00
#define COM0B_TOGGLE_ON_B_COMPARE   0x10
#define COM0B_CLEAR_ON_B_COMPARE    0x20
#define COM0B_SET_ON_B_COMPARE      0x30
// Waveform Generation Mode
#define WGM01_NORMAL    0x0
#define WGM01_PWM       0x1
#define WGM01_CTC       0x2
#define WGM01_FAST_PWM  0x3

/* TCCR0B – Timer/Counter Control Register B */
// Force Output Compare A
#define FOC0A   0x80
// Force Output Compare B
#define FOC0B   0x40
// Waveform Generation Mode
#define WGM02   0x08
// Clock Select
#define CS0_NO_SOURCE       0x0
#define CS0_NO_PRESCALE     0x1
#define CS0_CLK_DIV_8       0x2
#define CS0_CLK_DIV_64      0x3
#define CS0_CLK_DIV_256     0x4
#define CS0_CLK_DIV_1024    0x5
#define CS0_T0_FALLING_EDGE 0x6
#define CS0_T0_RISING_EDGE  0x7

/* TIMSK0 – Timer/Counter Interrupt Mask Register */
// Timer/Counter Output Compare Match B Interrupt Enable
#define OCIE0B  0x8
// Timer/Counter0 Output Compare Match A Interrupt Enable
#define OCIE0A  0x4
// Timer/Counter0 Overflow Interrupt Enable
#define TOIE0   0x2

/* TIFR0 - Timer/Counter 0 Interrupt Flag Register */
// Output Compare Flag 0 B
#define OCF0B   0x8
// Output Compare Flag 0 A
#define OCF0A   0x4
// Timer/Counter0 Overflow Flag
#define TOV0    0x2

#endif
