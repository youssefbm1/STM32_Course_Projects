// #include <stdint.h>
// #include "uart.h"
// #include "led.h"
// #include "clocks.h"
// #include "matrix.h"
// #include "image.h"


// uint32_t sum;

// int main()
// {
//   clocks_init();
//   uart_init();
//   matrix_init();
//   deactivate_rows();
 
//   while(1) {
//     for(int j = 0;0 < 8; ++j){
//       for(int i = 0;i < 24; i+=3) {
//         send_byte((uint8_t) image_raw[i + 2 + 24 * j], 1); 
//         send_byte ((uint8_t) image_raw[i + 1 + 24 * j], 1); 
//         send_byte ((uint8_t) image_raw[i + 24 * j], 1);
//       }
//       pulse_LAT();
//       deactivate_rows();
//       activate_row(j);
//     }
//   }
//   return 0;
// }


#include "clocks.h"
#include "matrix.h"
#include "uart.h"
#include "led.h"
#include "image.h" 
#include "irq.h"
#include "button.h"


void irq_init(void);
void button_init(void);
void show_static_image(void);

int main()
{
  clocks_init();
  irq_init();
  matrix_init();
  deactivate_rows();
  button_init();
  while(1)
  {
    show_static_image();
  }
 

  return 0;
}

void show_static_image(void)
{
  for(int j = 0;j < 8; ++j)
    {
      for(int i = 0;i < 24; i+=3)
      {     
        send_byte((uint8_t) image_raw[i + 2 + 24 * j], 1);
        send_byte((uint8_t) image_raw[i + 1 + 24 * j], 1);
        send_byte((uint8_t) image_raw[i + 24 * j], 1);
      }
      pulse_LAT();
      deactivate_rows();
      activate_row(j);
    }
}
