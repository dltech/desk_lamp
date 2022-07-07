#ifndef WDT_REGS
#define WDT_REGS
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

/* MCUSR – MCU Status Register */
// Watchdog Reset Flag
#define WDRF    0x08
// Brown-out Reset Flag
#define BORF    0x04
// External Reset Flag
#define EXTRF   0x02
// Power-on Reset Flag
#define PORF    0x01

/* WDTCR – Watchdog Timer Control Register */
// Watchdog Timer Interrupt Flag
#define WDTIF   0x80
// Watchdog Timer Interrupt Enable
#define WDTIE   0x40
// Watchdog Change Enable
#define WDCE    0x10
// Watchdog System Reset Enable
#define WDE     0x08
// Watchdog Timer Prescaler
#define WDP_2K     0x00
#define WDP_4K     0x01
#define WDP_8K     0x02
#define WDP_16K    0x03
#define WDP_32K    0x04
#define WDP_64K    0x05
#define WDP_128K   0x06
#define WDP_256K   0x07
#define WDP_512K   0x20
#define WDP_1024K  0x21

#endif
