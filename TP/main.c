#include <stdint.h>
#include "uart.h"
#include "led.h"
#include "clocks.h"


uint32_t sum;

int main()
{
  clocks_init();
  uart_init();

  while(1)
  {
    // uart_puts("\r\nType smth!\r\n");
    // uint8_t c = uart_getchar();
    // uart_puts("You typed:");
    // uart_putchar(c);

    sum = checksum(1000);
  }
  return 0;
}

