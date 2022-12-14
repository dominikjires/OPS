#include "LCD_DISCO_F469NI.h"
#include "mbed.h"
#include <stack>

LCD_DISCO_F469NI lcd;
int width;
int height;

Thread car1;
Thread car2;
Thread car3;
Thread car4;
Thread car5;

Mutex stdio_mutex;
Mutex freeplaces;
Semaphore semaphore(4);
stack<int> places;

void displayColor(int n, int color) {    
    lcd.SetTextColor(color);
    lcd.FillRect(width/4 * n, 0, width/4, height);
}

typedef struct {
    char* color;
    int time;
    } Car;


void parkinglot(Car *car)
{
    int n = 0;
    while (true) {
        semaphore.acquire();

        freeplaces.lock();
        n = places.top();
        freeplaces.unlock();
        
        stdio_mutex.lock();
        displayColor(n, car->color);
        stdio_mutex.unlock();

        ThisThread::sleep_for(car->time);

        freeplaces.lock();
        places.push(n);
        freeplaces.unlock();

        stdio_mutex.lock();
        displayColor(n, LCD_COLOR_BLACK);
        stdio_mutex.unlock();

        semaphore.release();

        ThisThread::sleep_for(car->time);
    }
}

int main(void)
{
    width = lcd.GetXSize();
    height = lcd.GetYSize();
    lcd.SetTextColor(LCD_COLOR_BLACK);
    lcd.FillRect(0, 0, width, height);

    for (int i = 0; i < 4; i++) {
        places.push(i);
    }

    struct Car c1;
        color = LCD_COLOR_BLUE;
        time = 1000;
    struct Car c2;
        color = LCD_COLOR_RED;
        time = 2000;
    struct Car c3;
        color = LCD_COLOR_YELLOW;
        time = 3000;
    struct Car c4;
        color = LCD_COLOR_ORANGE;
        time = 1500;
    struct Car c5;
        color = LCD_COLOR_GREEN;
        time = 2500;

    car1.start(callback(parkinglot,&c1));
    car2.start(callback(parkinglot,&c2));
    car3.start(callback(parkinglot,&c3));
    car4.start(callback(parkinglot,&c4));
    car5.start(callback(parkinglot,&c5));
}
