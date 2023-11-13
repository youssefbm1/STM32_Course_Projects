#define STM32L475xx
#include <stdint.h>
#include "led.h"
#include "stm32l4xx.h"




void led_init() {
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN | RCC_AHB2ENR_GPIOCEN;

    GPIOB->MODER &= ~(GPIO_MODER_MODE14_1 | GPIO_MODER_MODE14_0); 
    GPIOB->MODER |= GPIO_MODER_MODE14_0;  

    GPIOC->MODER &= ~(GPIO_MODER_MODE9_1 | GPIO_MODER_MODE9_0);  
    GPIOC->MODER |= GPIO_MODER_MODE9_0;  
}

static uint8_t led_etat = 0;

void led_g_on() {
    GPIOB->BSRR |= GPIO_BSRR_BS14; 
    led_etat = 1;
}

void led_g_off() {
    GPIOB->BRR |= GPIO_BRR_BR14;  
    led_etat = 0;
}

void led_g_toggle(){
    if(led_etat)
        led_g_off();
    else led_g_on ();
}

void led(enum STATE s){
    switch(s){
        case LED_YELLOW:
            GPIOC->MODER |= GPIO_MODER_MODE9_0;
            GPIOC->MODER &= ~GPIO_MODER_MODE9_1;
            GPIOC->BSRR |= GPIO_BSRR_BS9;
            break;
        case LED_BLUE:
            GPIOC->MODER |= GPIO_MODER_MODE9_0;
            GPIOC->MODER &= ~GPIO_MODER_MODE9_1;
            GPIOC->BSRR |= GPIO_BSRR_BR9;  
            break;
        case LED_OFF:
            GPIOC->MODER &= ~(GPIO_MODER_MODE9_1 | GPIO_MODER_MODE9_0);
            break;
    }
}