#ifndef H_BUTTON
#define H_BUTTON
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
#include <avr/io.h>

#define F_CPU 9600000

#define SW_PORT PORTB
#define SW_PIN  PINB
#define SW_GPIO 0x08

void buttonsInit(void);

#endif
