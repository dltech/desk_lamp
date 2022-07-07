/*
 * PWM driver for desk lamp. Human interface functions.
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

#include "pwm_lamp.h"
#include "random127.h"
#include "regs/timer_regs.h"
#include <avr/interrupt.h>
#include "lamp_menu.h"


static uint8_t lampSetting;
static uint8_t lampColour;
static uint8_t brightness;
extern volatile lampTyp lamp;

void colourSetup(uint8_t colour);
void random(uint8_t seed);
void acidEffect(void);
void fireEffect(void);

void rndInit()
{
    TIMSK0 = TOIE0;
}

void longButtonCallback()
{
    lampSetting = LAMP_WHITE;
    brightness = 0;
    setBrightness(0);
}

void buttonCallback()
{
    switch ( lampSetting ) {
        case LAMP_WHITE:
            lampSetting = LAMP_COLOUR;
            lamp.white = 0x00;
            colourSetup(LAMP_RED);
            break;
        case LAMP_COLOUR:
            lampSetting = LAMP_RND;
            srand127(TCNT0&0x7e);
            acidEffect();
            break;
        case LAMP_RND:
            lampSetting = LAMP_FIRE;
            srand127(TCNT0&0x7e);
            lamp.blue = 0x00;
            fireEffect();
            break;
        case LAMP_FIRE:
            lampSetting = LAMP_WHITE;
            setBrightness(brightness);
            break;
    }
}

void clockwiseCallback()
{
    if( (lampSetting == LAMP_WHITE) && (brightness < 255) ) {
        setBrightness(++brightness);
    }
    // colour settings
    if( (lampSetting == LAMP_COLOUR) && (lampColour < LAMP_ORANGE) ) {
        colourSetup(++lampColour);
    }
}

void anticlockwiseCallback()
{
    if( (lampSetting == LAMP_WHITE) && (brightness > 0) ) {
        setBrightness(--brightness);
    }
    if( (lampSetting == LAMP_COLOUR) && (lampColour > 0) ) {
        colourSetup(--lampColour);
    }
}

void colourSetup(uint8_t colour)
{
    switch ( colour ) {
        case LAMP_RED:
            lamp.red = 0xff;
            lamp.green = 0x00;
            lamp.blue = 0x00;
            break;
        case LAMP_ROSE:
            lamp.red = 0xff;
            lamp.green = 0x00;
            lamp.blue = 0x0f;
            break;
        case LAMP_MAGENTA:
            lamp.red = 0xff;
            lamp.green = 0x00;
            lamp.blue = 0xff;
            break;
        case LAMP_VIOLET:
            lamp.red = 0x0f;
            lamp.green = 0x00;
            lamp.blue = 0xff;
            break;
        case LAMP_BLUE:
            lamp.red = 0x00;
            lamp.green = 0x00;
            lamp.blue = 0xff;
            break;
        case LAMP_AZURE:
            lamp.red = 0x00;
            lamp.green = 0x0f;
            lamp.blue = 0xff;
            break;
        case LAMP_CYAN:
            lamp.red = 0x00;
            lamp.green = 0xff;
            lamp.blue = 0xff;
            break;
        case LAMP_AQUAMARINE:
            lamp.red = 0x00;
            lamp.green = 0xff;
            lamp.blue = 0x0f;
            break;
        case LAMP_GREEN:
            lamp.red = 0x00;
            lamp.green = 0xff;
            lamp.blue = 0x00;
            break;
        case LAMP_CHARTEUSE:
            lamp.red = 0x0f;
            lamp.green = 0xff;
            lamp.blue = 0x00;
            break;
        case LAMP_YELLOW:
            lamp.red = 0xff;
            lamp.green = 0xff;
            lamp.blue = 0x00;
            break;
        case LAMP_ORANGE:
            lamp.red = 0xff;
            lamp.green = 0x0f;
            lamp.blue = 0x00;
            break;
    }
}

void acidEffect()
{
    lamp.red = rand127();
    lamp.green = rand127();
    lamp.blue = rand127();
    if(rand127() > 64) {
        lamp.white = 0xff;
    } else {
        lamp.white = 0x00;
    }
}

void fireEffect()
{
    lamp.red = rand127();
    lamp.green = rand127();
    if(rand127() > 90) {
        lamp.white = 0xff;
    } else {
        lamp.white = 0x00;
    }
}

void rndCallback()
{
    switch (lampSetting) {
        case LAMP_RND:
            acidEffect();
            break;
        case LAMP_FIRE:
            fireEffect();
            break;
    }
}

ISR(TIM0_OVF_vect)
{
    static uint8_t cnt;
    static uint8_t cntt;
    if(++cnt == 255) {
        cnt = 0;
        ++cntt;
    }
    if(cntt == 255) {
        cntt = 0;
        rndCallback();
    }
}
