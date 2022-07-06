/*
 * PWM driver for desk lamp. Fully 8-bits random implementation ANSI-C like.
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

static uint8_t next = 10;

uint8_t doRand(void);

uint8_t doRand(uint8_t *next) {
    const int8_t a = 6;
    const int8_t m = 127;
    const int8_t q = m/a;
    const int8_t r = m%a;
    int8_t lo, hi, test;
    hi = *next / q;
    lo = *next % q;
    test = a*lo - r*hi;
    if(test > 0) {
        *next = test;
    } else {
        *next = test + m;
    }
    return *next;
}

uint8_t rand127(void)
{
    return doRand(&next);
}

uint8_t srand127(uint8_t seed)
{
 	next = seed;
}
