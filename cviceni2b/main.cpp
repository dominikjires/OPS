#include "mbed.h"
#include "LCD_DISCO_F469NI.h"
#include "stm32469i_discovery_lcd.h"

LCD_DISCO_F469NI lcd;
Thread thread1;
Thread thread2;
Thread thread3;
Mutex stdio_mutex;

void notify(const char * number, int line)
{
    stdio_mutex.lock();
    lcd.SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_SetFont(&Font24);
    lcd.DisplayStringAt(0, LINE(line), (uint8_t *)number, CENTER_MODE);
    stdio_mutex.unlock();
}

void text_thread(void const * number)
{
    while (true) {
      notify((const char *)number,8);
      ThisThread::sleep_for(1000);
      stdio_mutex.lock();
      lcd.ClearStringLine(8);
      stdio_mutex.unlock();
      ThisThread::sleep_for(1000);
    }       
}


int main()
{
    thread1.start(callback(text_thread,(void *)"1"));
    thread2.start(callback(text_thread,(void *)"2"));
    thread1.start(callback(text_thread,(void *)"3"));

}