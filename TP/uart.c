#define STM32L475xx
#include "stm32l4xx.h"
#include <stddef.h>
#include "uart.h"


void uart_init() {
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;

    GPIOB->MODER = (GPIOB->MODER & ~(0x5 << GPIO_MODER_MODE6_Pos)) | (0xA << GPIO_MODER_MODE6_Pos);
    GPIOB->AFR[0] = (GPIOB->AFR[0] & ~(0x88 << GPIO_AFRL_AFSEL6_Pos)) | (0x77 << GPIO_AFRL_AFSEL6_Pos);

    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;

    RCC->CCIPR &= ~RCC_CCIPR_USART1SEL_Msk;

    RCC->APB2RSTR |= RCC_APB2RSTR_USART1RST;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_USART1RST;

    USART1->BRR = 0x2B6;

 
    USART1->CR1 &= (~USART_CR1_M0 & ~USART_CR1_M1 & ~USART_CR1_OVER8 & ~USART_CR1_PCE);
    USART1->CR2 &= ~USART_CR2_STOP_Msk;

    USART1->CR1 |=  (USART_CR1_TE | USART_CR1_RE | USART_CR1_UE);
}

void uart_putchar(uint8_t c) {
    while (!(USART1->ISR & USART_ISR_TXE)); 
    USART1->TDR = c;
}

uint8_t uart_getchar() {
    while (!(USART1->ISR & USART_ISR_RXNE)); 
    return (uint8_t)(USART1->RDR & 0xFF); 
}

void uart_puts(const char *s) {
    while (*s) {
        uart_putchar(*s++);
    }
}

void uart_gets(char *s, size_t size) {
    char c;
    size_t i = 0;
    while (i < size - 1) { 
        c = uart_getchar();
        if (c == '\r' || c == '\n') break; 
        s[i++] = c;
    }
    s[i] = '\0'; 
}

uint32_t checksum(size_t size) {
    uint32_t sum = 0;
    char s[1002];
    uart_gets(s,size+1);
    size_t i = 0;
    while(i<size+1) {
        sum += (uint8_t)s[i];
        i++;
    }
    return sum;
}
