#include <stdint.h>
#include "led.h"
#define STM32L475xx
#include "stm32l4xx.h"
//#include "stm32l475xx.h"



void led_init() {
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN | RCC_AHB2ENR_GPIOCEN;

    GPIOB->MODER &= ~(GPIO_MODER_MODE14_1 | GPIO_MODER_MODE14_0); 
    GPIOB->MODER |= GPIO_MODER_MODE14_0;  

    GPIOC->MODER &= ~(GPIO_MODER_MODE9_1 | GPIO_MODER_MODE9_0);  
    GPIOC->MODER |= GPIO_MODER_MODE9_0;  
}

void led_g_on() {
    GPIOB->BSRR |= GPIO_BSRR_BS14; 
}

void led_g_off() {
    GPIOB->BRR |= GPIO_BRR_BR14;  
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