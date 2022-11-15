#include "mbed.h"
#include "LCD_DISCO_F469NI.h"
#include "stm32469i_discovery_lcd.h"

LCD_DISCO_F469NI lcd;
Thread thread1;
Thread thread2;

void text1_thread()
{    
      lcd.SetTextColor(LCD_COLOR_BLACK);
      BSP_LCD_SetFont(&Font24);
      lcd.DisplayStringAt(0, LINE(2), (uint8_t *)"Jsem vlakno 1", CENTER_MODE,);
      ThisThread::sleep_for(1s);
}

void text2_thread()
{    
      lcd.SetTextColor(LCD_COLOR_BLACK);
      BSP_LCD_SetFont(&Font24);
      lcd.DisplayStringAt(0, LINE(2), (uint8_t *)"Jsem vlakno 2", CENTER_MODE);
      ThisThread::sleep_for(1s);
}


int main()
{
    thread1.start(text1_thread);
    thread1.join();
    lcd.Clear(LCD_COLOR_WHITE);
    ThisThread::sleep_for(1s);
    thread2.start(text2_thread);
    thread2.join();
    lcd.Clear(LCD_COLOR_WHITE);
    ThisThread::sleep_for(2s);
}
