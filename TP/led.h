#ifndef LED_H
#define LED_H
#include <stdint.h>

enum STATE {LED_OFF, LED_BLUE, LED_YELLOW};

void led_init(void);
void led_g_on(void);
void led_g_off(void);
void led_g_toggle(void);
void led(enum STATE); 

#endif 