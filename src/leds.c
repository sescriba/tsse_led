/************************************************************************************************
Copyright (c) 2023, Santiago Escribá <escribasan@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** @file
 ** @brief Definición de la función principal del programa
 **/

/* === Headers files inclusions =============================================================== */

#include "leds.h"

/* === Macros definitions ====================================================================== */

#define LED_OFFSET 1
#define LED_STATE_ON 1
#define ALL_LEDS_OFF 0

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

static uint16_t *direccion_puerto;

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

static uint16_t LedToMask(unsigned int led){
    return LED_STATE_ON << (led-LED_OFFSET);
}

/* === Public function implementation ========================================================== */

void LedsInit(uint16_t *puerto){
    direccion_puerto = puerto;
    *puerto = ALL_LEDS_OFF;
}

void LedTurnOn(unsigned int led){
    *direccion_puerto |= LedToMask(led);
}

void LedTurnOff(unsigned int led){
    *direccion_puerto &= ~(LedToMask(led));
}

/* === End of documentation ==================================================================== */