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

#include "unity.h"
#include "leds.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

static uint16_t puerto_virtual;

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

void setUp(void){
    LedsInit(&puerto_virtual);
}

//Al iniciar el driver todos los leds deben quedar apagados
void test_todos_los_leds_arrancan_apagados(void){
    uint16_t puerto_virtual = 0xFFFF;
    LedsInit(&puerto_virtual);
    TEST_ASSERT_EQUAL(0, puerto_virtual);
}

//Con todos los leds apagados se prende un led en particular
void test_encender_un_led_apagado(void){
    LedTurnOn(5);
    TEST_ASSERT_BIT_HIGH(4, puerto_virtual);
    TEST_ASSERT_BIT_LOW(~(1<<4), puerto_virtual);
}

//Con todos los leds encendidos se apaga un led en particular
void test_apagar_un_led_encendido(void){
    LedTurnOn(5);
    LedTurnOff(5);
    TEST_ASSERT_EQUAL(0, puerto_virtual);
}

/* === End of documentation ==================================================================== */