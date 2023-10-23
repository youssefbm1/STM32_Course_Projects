#include <stdint.h>
#include "led.h"



void led_init() {
    RCC_AHB2ENR |= 0x6;

    GPIOB_MODER &= ~(GPIOB_MODER_PIN14_OUTPUT);
    GPIOC_MODER &= ~(GPIOC_MODER_PIN9_OUTPUT);
}

void led_g_on() {
    GPIOB_BSRR |= GPIO_BSRR_BS14; 
}

void led_g_off() {
    GPIOB_BSRR |= GPIO_BSRR_BR14;  
}

void led(enum STATE s){
    switch(s){
        case LED_YELLOW:
            GPIOC_BSRR |= (1 << 9);  
            break;
        case LED_BLUE:
            GPIOC_MODER |= (1 << 18);
            GPIOC_BSRR |= (1 << 25);  
            break;
        case LED_OFF:
            GPIOC_MODER &= ~(1 << 18);
            break;
    }
}