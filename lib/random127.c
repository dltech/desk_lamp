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
#include "random127.h"

static uint8_t next = 10;

#define RAND_A  6
#define RAND_M  127
#define RAND_Q  RAND_M/RAND_A
#define RAND_R  RAND_M%RAND_A

uint8_t rand127(void)
{
    int8_t lo, hi, test;
    hi = next / RAND_Q;
    lo = next % RAND_Q;
    test = RAND_A*lo - RAND_R*hi;
    if(test > 0) {
        next = test;
    } else {
        next = test + RAND_M;
    }
    return next;
}

void srand127(uint8_t seed)
{
 	next = seed;
}
