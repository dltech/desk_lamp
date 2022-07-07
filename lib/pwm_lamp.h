#ifndef H_PWM_LAMP
#define H_PWM_LAMP
/*
 * PWM driver for desk lamp.
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

// ports of colours
#define PWM_PORT    PORTB
#define PIN_GREEN   0x04
#define PIN_RED     0x02
#define PIN_BLUE    0x01
#define PIN_WHITE   0x20

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t white;
} lampTyp;

// pwm outputs init function
void pwm_init(void);
void setBrightness(uint8_t bright);
// pwm outputs event loop
void pwm_cycle(void);

#endif
