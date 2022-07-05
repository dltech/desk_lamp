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

// encoder port
#define ENC_DDR     DDRB
#define ENC_PORT    PORTB
#define ENC_LEFT    0x08
#define ENC_RIGHT   0x10

// timings
#define BUTTON_PUSH_MS  50

typedef struct {
    uint8_t leftCnt;
    uint8_t rightCnt;
    uint8_t bothCnt;
}

// encoder init
void encoder_init(void);
// encoder check event loop
void encoder_loop(void);

#endif
