#include <stdint.h>
#include "uart.h"
#include "led.h"
#include "clocks.h"
#include "matrix.h"


uint32_t sum;

int main()
{
  clocks_init();
  uart_init();
  matrix_init();

  test_pixels();


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

