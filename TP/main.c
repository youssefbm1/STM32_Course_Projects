#include <stdint.h>

#include "led.c"
#include "clocks.h"

int main() {
    led_init();
    clocks_init();

    while (1) {
        led_g_on();     // Turn on the green LED
        led(LED_YELLOW); // Turn on the yellow LED
        for (volatile int i = 0; i < 100000; ++i) {
            asm volatile("nop"); // Delay
        }

        led_g_off();    // Turn off the green LED
        led(LED_BLUE);  // Turn on the blue LED
        for (volatile int i = 0; i < 100000; ++i) {
            asm volatile("nop"); // Delay
        }

        led(LED_OFF);   // Turn off all LEDs
        for (volatile int i = 0; i < 100000; ++i) {
            asm volatile("nop"); // Delay
        }
    }
    return 0;
}
