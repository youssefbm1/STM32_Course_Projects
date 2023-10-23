#ifndef LED_H
#define LED_H
#include <stdint.h>

#define RCC_BASE_ADDR   0x40021000
#define GPIOB_BASE_ADDR 0x48000400
#define GPIOC_BASE_ADDR 0x48000800

#define GPIO_BSRR_OFFSET 0x18
#define GPIO_BSRR_BS14  (0x01 << 14)  
#define GPIO_BSRR_BR14  (0x01 << 30)  

#define RCC_AHB2ENR_OFFSET  0x4c

#define GPIO_MODER_OFFSET  0x00

#define GPIOB_MODER_PIN14_OUTPUT  (1 << 29) 
#define GPIOC_MODER_PIN9_OUTPUT  (1 << 19)  

#define RCC_AHB2ENR (*(volatile uint32_t *) ((uint32_t *)(RCC_BASE_ADDR + RCC_AHB2ENR_OFFSET)))
#define GPIOB_MODER (*(volatile uint32_t *) ((uint32_t *)(GPIOB_BASE_ADDR + GPIO_MODER_OFFSET)))
#define GPIOC_MODER (*(volatile uint32_t *) ((uint32_t *)(GPIOC_BASE_ADDR + GPIO_MODER_OFFSET)))
#define GPIOB_BSRR (*(volatile uint32_t *) ((uint32_t *)(GPIOB_BASE_ADDR + GPIO_BSRR_OFFSET)))
#define GPIOC_BSRR (*(volatile uint32_t *) ((uint32_t *)(GPIOC_BASE_ADDR + GPIO_BSRR_OFFSET)))


enum STATE {LED_OFF, LED_BLUE, LED_YELLOW};

void led_init(void);
void led_g_on(void);
void led_g_off(void);
void led(enum STATE); 

#endif 