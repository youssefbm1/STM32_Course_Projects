#define STM32L475xx
#include "stm32l4xx.h"
#include "button.h"
#include "led.h"
#include "irq.h"

static void clock_enable(){
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
}

static void pinMode(){
    GPIOC->MODER &= ~GPIO_MODER_MODE13_Msk;
}

static void sourceIRQ(){ 
    SYSCFG->EXTICR[3] &= ~SYSCFG_EXTICR4_EXTI13_Msk;
    SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC;
}

static void hardwareInterruptSelection(){ 
    EXTI->IMR1 |= EXTI_IMR1_IM13_Msk; 

    EXTI->RTSR1 &= ~EXTI_RTSR1_RT13_Msk; 
    EXTI->FTSR1 |= EXTI_FTSR1_FT13_Msk; 

    NVIC_EnableIRQ(40); 
}

void button_init(){
    led_init(); 
    clock_enable(); 
    pinMode(); 
    sourceIRQ(); 
    hardwareInterruptSelection(); 
}

void EXTI15_10_IRQHandler(void){
    EXTI->PR1 |= EXTI_PR1_PIF13_Msk; 
    led_g_toggle(); 
}