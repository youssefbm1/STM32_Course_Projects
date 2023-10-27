#include <stdint.h>

#include "led.c"
#include "clocks.h"

int main() {
    led_init();
    clocks_init();

    while (1) {
        led_g_on();
        for (int i = 0; i < 1000000; i++) {
            asm volatile("nop");
        }

        led_g_off();
        for (int i = 0; i < 1000000; i++) {
            asm volatile("nop");
        }
        
        led(LED_YELLOW);
        for (int i = 0; i < 1000000; i++) {
            asm volatile("nop");
        }

        led(LED_OFF);
        for (int i = 0; i < 1000000; i++) {
            asm volatile("nop");
        }        

        led(LED_BLUE);
        for (int i = 0; i < 1000000; i++) {
            asm volatile("nop");
        }

        led(LED_OFF);
        for (int i = 0; i < 1000000; i++) {
            asm volatile("nop");
        }    
    }

    return 0;
}
