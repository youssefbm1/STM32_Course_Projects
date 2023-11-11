#ifndef UART_H
#define UART_H

#include <stdint.h> 
#include <stddef.h>

void uart_init(void);
void uart_putchar(uint8_t c);
uint8_t uart_getchar();
void uart_puts(const char *s);
void uart_gets(char *s, size_t size);
uint32_t checksum(size_t size);

#endif 