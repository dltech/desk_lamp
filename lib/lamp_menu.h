#ifndef H_LAMP_MENU
#define H_LAMP_MENU
/*
 * PWM driver for desk lamp. Human interface.
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

enum{
    LAMP_WHITE,
    LAMP_COLOUR,
    LAMP_RND,
    LAMP_FIRE
} lampEnum;

enum{
    LAMP_RED,
    LAMP_ROSE,
    LAMP_MAGENTA,
    LAMP_VIOLET,
    LAMP_BLUE,
    LAMP_AZURE,
    LAMP_CYAN,
    LAMP_AQUAMARINE,
    LAMP_GREEN,
    LAMP_CHARTEUSE,
    LAMP_YELLOW,
    LAMP_ORANGE
} coloursEnum;

void rndInit(void);

// callbacks for encoder decoder
void clockwiseCallback(void);
void anticlockwiseCallback(void);

//callbacks for button interrupt event
void longButtonCallback(void);
void buttonCallback(void);



#endif
