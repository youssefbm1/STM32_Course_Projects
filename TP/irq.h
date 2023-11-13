#ifndef IRQ_H
#define IRQ_H

#define STM32L475xx
#include <stdint.h>
#include "stm32l475xx.h"
#include "core_cm4.h"

void Reset_Handler(void);
void irq_init();

#endif