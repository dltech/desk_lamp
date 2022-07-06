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

#include "lamp_menu.h"
#include "pwm_lamp.h"

volatile uint8_t lampSetting;
volatile uint8_t lampColour;
extern volatile colourTyp colour;

void colourSetup(uint8_t colour);
void random(uint8_t seed);
void acidEffect(void);
void fireEfect(void);

void longButtonCallback()
{
    lampSetting = LAMP_WHITE;
    colour.white = 0;
    colour.red = 0;
    colour.green = 0;
    colour.blue = 0;
}

void buttonCallback()
{
    switch ( lampSetting ) {
        case LAMP_WHITE:
            lampSetting = LAMP_COLOUR;
            colourSetup(LAMP_RED);
            break;
        case LAMP_COLOUR:
            lampSetting = LAMP_RND;
            rndCallback();
        case LAMP_RND:
            lampSetting = LAMP_FIRE;
            fireCallback();
        case LAMP_FIRE:
            lampSetting = LAMP_
    }
    if(lampSetting  LAMP_FIRE) {
        ++lampSetting;
    }
}

void clockwiseCallback()
{
    if( (lampSetting == LAMP_WHITE) && (colour.white < 255) ) {
        ++colour.white;
        ++colour.red;
        ++colour.green;
        ++colour.blue;
    }
    // colour settings
    if( (lampSetting == LAMP_COLOUR) && (lampColour < LAMP_ORANGE) ) {
        colourSetup(++lampColour);
    }
}

void anticlockwiseCallback()
{
    if( (lampSetting == LAMP_WHITE) && (colour.white > 0) ) {
        --colour.white;
        --colour.red;
        --colour.green;
        --colour.blue;
    }
    if( (lampSetting == LAMP_COLOUR) && (lampColour > 0) ) {
        colourSetup(--lampColour);
    }
}

void colourSetup(uint8_t colour)
{
    switch ( colour ) {
        case LAMP_RED:
            colour.red = 0xff;
            colour.green = 0x00;
            colour.blue = 0x00;
            break;
        case LAMP_ROSE:
            colour.red = 0xff;
            colour.green = 0x00;
            colour.blue = 0x0f;
            break;
        case LAMP_MAGENTA:
            colour.red = 0xff;
            colour.green = 0x00;
            colour.blue = 0xff;
            break;
        case LAMP_VIOLET:
            colour.red = 0x0f;
            colour.green = 0x00;
            colour.blue = 0xff;
            break;
        case LAMP_BLUE:
            colour.red = 0x00;
            colour.green = 0x00;
            colour.blue = 0xff;
            break;
        case LAMP_AZURE:
            colour.red = 0x00;
            colour.green = 0x0f;
            colour.blue = 0xff;
            break;
        case LAMP_CYAN:
            colour.red = 0x00;
            colour.green = 0xff;
            colour.blue = 0xff;
            break;
        case LAMP_AQUAMARINE:
            colour.red = 0x00;
            colour.green = 0xff;
            colour.blue = 0x0f;
            break;
        case LAMP_GREEN:
            colour.red = 0x00;
            colour.green = 0xff;
            colour.blue = 0x00;
            break;
        case LAMP_CHARTEUSE:
            colour.red = 0x0f;
            colour.green = 0xff;
            colour.blue = 0x00;
            break;
        case LAMP_YELLOW:
            colour.red = 0xff;
            colour.green = 0xff;
            colour.blue = 0x00;
            break;
        case LAMP_ORANGE:
            colour.red = 0xff;
            colour.green = 0x0f;
            colour.blue = 0x00;
            break;
    }
}

void random(uint8_t seed)
{

}

void acidEffect()
{

}

void fireEfect()
{

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
