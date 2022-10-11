#include "mbed.h"
#include "LCD_DISCO_F469NI.h"
#define MAINLINE (7)
LCD_DISCO_F469NI lcd;

DigitalOut led1(LED1);

int main()
{    
    led1 = 1;
  
    lcd.DisplayStringAt(0, LINE(1), (uint8_t *)"MBED EXAMPLE", CENTER_MODE);
    wait(1);
  
    while(1)
    {
      lcd.Clear(LCD_COLOR_BLUE);
      lcd.SetBackColor(LCD_COLOR_BLUE);
      lcd.SetTextColor(LCD_COLOR_WHITE);
      wait(0.5);
      BSP_LCD_SetFont(&Font20);
      lcd.DisplayStringAt(0, LINE(MAINLINE), (uint8_t *)"Dominik Jires", CENTER_MODE);
      wait(1);

      lcd.Clear(LCD_COLOR_WHITE);
      lcd.SetBackColor(LCD_COLOR_WHITE);
      lcd.SetTextColor(LCD_COLOR_BLACK);
      wait(0.5);
      BSP_LCD_SetFont(&Font20);
      lcd.DisplayStringAt(0, LINE(MAINLINE), (uint8_t *)"Matej Paclt", CENTER_MODE);
      wait(1);
    }
}
