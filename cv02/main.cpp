/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "LCD_DISCO_F469NI.h"
#include "stm32469i_discovery_lcd.h"

LCD_DISCO_F469NI lcd;
// main() runs in its own thread in the OS
Thread thread1;
Thread thread2;
Thread thread3;

void text1_thread()
{
    while (true) {
      ThisThread::sleep_for(2s);
      lcd.SetTextColor(LCD_COLOR_BLACK);
      BSP_LCD_SetFont(&Font24);
      lcd.DisplayStringAt(0, LINE(2), (uint8_t *)"Jsem vlakno 1", CENTER_MODE);   
    }
}

void text2_thread()
{
    while (true) {
      ThisThread::sleep_for(5s);
      lcd.SetTextColor(LCD_COLOR_BLACK);
      BSP_LCD_SetFont(&Font24);
      lcd.DisplayStringAt(0, LINE(8), (uint8_t *)"Jsem vlakno 2", CENTER_MODE);   
    }
}

void text3_thread()
{
    while (true) {
      ThisThread::sleep_for(9s);
      lcd.SetTextColor(LCD_COLOR_BLACK);
      BSP_LCD_SetFont(&Font24);
      lcd.DisplayStringAt(0, LINE(12), (uint8_t *)"Jsem vlakno 3", CENTER_MODE);   
    }
}

int main()
{
    thread1.start(text1_thread);
    thread2.start(text2_thread);
    thread3.start(text3_thread);  
}