#include "led.c"

int main() {
    led_init();

    while (1) {
        led_g_on();

        for (int i = 0; i < 1000000; i++) {
            asm volatile("nop");
        }

        led_g_off();

        for (int i = 0; i < 1000000; i++) {
            asm volatile("nop");
        }

        
    }

    return 0;
}
