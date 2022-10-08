#include "mbed.h"

DigitalOut led_green(LED1);
DigitalOut led_orange(LED2);
DigitalOut led_red(LED3);
DigitalOut led_blue(LED4);

double SHORT = 0.5;
double LONG = 1.0;
double SHORTP = 0.2;
double LONGP = 0.4;
double END = 5.0;
void start() {
        led_blue = 1;
        led_red = 1;
        led_orange = 1;
        led_green = 1;
}
void m() {
    led_blue = 0;
        wait(LONG); // 1 sec
        led_blue = 1;
        wait(SHORTP);
        led_blue = 0;
        wait(LONG);
        led_blue = 1;
        wait(LONGP);
}

void a() {
    led_blue = 0;
        wait(SHORT); // 1 sec
        led_blue = 1;
        wait(SHORTP);
        led_blue = 0;
        wait(LONG);
        led_blue = 1;
        wait(LONGP);
}

void t() {
    
        led_blue = 0;
        wait(LONG);
        led_blue = 1;
        wait(LONGP);
}

void e() {
    led_blue = 0;
        wait(SHORT);
        led_blue = 1;
        wait(LONGP);
}

void j() {
     led_blue = 0;
        wait(SHORT); // 1 sec
        led_blue = 1;
        wait(SHORTP);
        led_blue = 0;
        wait(LONG);
        led_blue = 1;
        wait(SHORTP);
        led_blue = 0;
        wait(LONG);
        led_blue = 1;
        wait(SHORTP);
          led_blue = 0;
        wait(LONG);
        led_blue = 1;
        wait(LONGP);
}



int main() {
   
    while(1) {
        start();
        m();
        a();
        t();
        e();
        j();

        led_blue = 1;
        wait(END);

    }

}