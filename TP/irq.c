#define STM32L475xx

#include "stm32l475xx.h"
#include "stm32l4xx.h"
#include "core_cm4.h"
#include "irq.h"

#define MAKE_DEFAULT_HANDLER(handlerName) \
void handlerName (void) __attribute__((weak)); \
void handlerName (void){ \
    __disable_irq();  \
    while (1); \
}

#define __stack_start ((void *)0x10008000)

MAKE_DEFAULT_HANDLER(NonMaskableInt_Handler)
MAKE_DEFAULT_HANDLER(HardFault_Handler)
MAKE_DEFAULT_HANDLER(MemoryManagement_Handler)
MAKE_DEFAULT_HANDLER(BusFault_Handler)
MAKE_DEFAULT_HANDLER(UsageFault_Handler)
MAKE_DEFAULT_HANDLER(SVCall_Handler)
MAKE_DEFAULT_HANDLER(DebugMonitor_Handler)
MAKE_DEFAULT_HANDLER(PendSV_Handler)
MAKE_DEFAULT_HANDLER(SysTick_Handler)
MAKE_DEFAULT_HANDLER(WWDG_Handler)
MAKE_DEFAULT_HANDLER(PVD_PVM_Handler)
MAKE_DEFAULT_HANDLER(TAMP_STAMP_Handler)
MAKE_DEFAULT_HANDLER(RTC_WKUP_Handler)
MAKE_DEFAULT_HANDLER(FLASH_Handler)
MAKE_DEFAULT_HANDLER(RCC_Handler)
MAKE_DEFAULT_HANDLER(EXTI0_Handler)
MAKE_DEFAULT_HANDLER(EXTI1_Handler)
MAKE_DEFAULT_HANDLER(EXTI2_Handler)
MAKE_DEFAULT_HANDLER(EXTI3_Handler)
MAKE_DEFAULT_HANDLER(EXTI4_Handler)
MAKE_DEFAULT_HANDLER(DMA1_Channel1_Handler)
MAKE_DEFAULT_HANDLER(DMA1_Channel2_Handler)
MAKE_DEFAULT_HANDLER(DMA1_Channel3_Handler)
MAKE_DEFAULT_HANDLER(DMA1_Channel4_Handler)
MAKE_DEFAULT_HANDLER(DMA1_Channel5_Handler)
MAKE_DEFAULT_HANDLER(DMA1_Channel6_Handler)
MAKE_DEFAULT_HANDLER(DMA1_Channel7_Handler)
MAKE_DEFAULT_HANDLER(ADC1_2_Handler)
MAKE_DEFAULT_HANDLER(CAN1_TX_Handler)
MAKE_DEFAULT_HANDLER(CAN1_RX0_Handler)
MAKE_DEFAULT_HANDLER(CAN1_RX1_Handler)
MAKE_DEFAULT_HANDLER(CAN1_SCE_Handler)
MAKE_DEFAULT_HANDLER(EXTI9_5_Handler)
MAKE_DEFAULT_HANDLER(TIM1_BRK_TIM15_Handler)
MAKE_DEFAULT_HANDLER(TIM1_UP_TIM16_Handler)
MAKE_DEFAULT_HANDLER(TIM1_TRG_COM_TIM17_Handler)
MAKE_DEFAULT_HANDLER(TIM1_CC_Handler)
MAKE_DEFAULT_HANDLER(TIM2_Handler)
MAKE_DEFAULT_HANDLER(TIM3_Handler)
MAKE_DEFAULT_HANDLER(TIM4_Handler)
MAKE_DEFAULT_HANDLER(I2C1_EV_Handler)
MAKE_DEFAULT_HANDLER(I2C1_ER_Handler)
MAKE_DEFAULT_HANDLER(I2C2_EV_Handler)
MAKE_DEFAULT_HANDLER(I2C2_ER_Handler)
MAKE_DEFAULT_HANDLER(SPI1_Handler)
MAKE_DEFAULT_HANDLER(SPI2_Handler)
MAKE_DEFAULT_HANDLER(USART1_Handler)
MAKE_DEFAULT_HANDLER(USART2_Handler)
MAKE_DEFAULT_HANDLER(USART3_Handler)
MAKE_DEFAULT_HANDLER(EXTI15_10_Handler)
MAKE_DEFAULT_HANDLER(RTC_Alarm_Handler)
MAKE_DEFAULT_HANDLER(DFSDM1_FLT3_Handler)
MAKE_DEFAULT_HANDLER(TIM8_BRK_Handler)
MAKE_DEFAULT_HANDLER(TIM8_UP_Handler)
MAKE_DEFAULT_HANDLER(TIM8_TRG_COM_Handler)
MAKE_DEFAULT_HANDLER(TIM8_CC_Handler)
MAKE_DEFAULT_HANDLER(ADC3_Handler)
MAKE_DEFAULT_HANDLER(FMC_Handler)
MAKE_DEFAULT_HANDLER(SDMMC1_Handler)
MAKE_DEFAULT_HANDLER(TIM5_Handler)
MAKE_DEFAULT_HANDLER(SPI3_Handler)
MAKE_DEFAULT_HANDLER(UART4_Handler)
MAKE_DEFAULT_HANDLER(UART5_Handler)
MAKE_DEFAULT_HANDLER(TIM6_DAC_Handler)
MAKE_DEFAULT_HANDLER(TIM7_Handler)
MAKE_DEFAULT_HANDLER(DMA2_Channel1_Handler)
MAKE_DEFAULT_HANDLER(DMA2_Channel2_Handler)
MAKE_DEFAULT_HANDLER(DMA2_Channel3_Handler)
MAKE_DEFAULT_HANDLER(DMA2_Channel4_Handler)
MAKE_DEFAULT_HANDLER(DMA2_Channel5_Handler)
MAKE_DEFAULT_HANDLER(DFSDM1_FLT0_Handler)
MAKE_DEFAULT_HANDLER(DFSDM1_FLT1_Handler)
MAKE_DEFAULT_HANDLER(DFSDM1_FLT2_Handler)
MAKE_DEFAULT_HANDLER(COMP_Handler)
MAKE_DEFAULT_HANDLER(LPTIM1_Handler)
MAKE_DEFAULT_HANDLER(LPTIM2_Handler)
MAKE_DEFAULT_HANDLER(OTG_FS_Handler)
MAKE_DEFAULT_HANDLER(DMA2_Channel6_Handler)
MAKE_DEFAULT_HANDLER(DMA2_Channel7_Handler)
MAKE_DEFAULT_HANDLER(LPUART1_Handler)
MAKE_DEFAULT_HANDLER(QUADSPI_Handler)
MAKE_DEFAULT_HANDLER(I2C3_EV_Handler)
MAKE_DEFAULT_HANDLER(I2C3_ER_Handler)
MAKE_DEFAULT_HANDLER(SAI1_Handler)
MAKE_DEFAULT_HANDLER(SAI2_Handler)
MAKE_DEFAULT_HANDLER(SWPMI1_Handler)
MAKE_DEFAULT_HANDLER(TSC_Handler)
MAKE_DEFAULT_HANDLER(RNG_Handler)
MAKE_DEFAULT_HANDLER(FPU_Handler)





void * const vector_table[] __attribute__((section(".isr_vector")))= {
  __stack_start,            
  Reset_Handler,
  NonMaskableInt_Handler ,
  HardFault_Handler ,  
  MemoryManagement_Handler ,  
  BusFault_Handler ,  
  UsageFault_Handler,
  0,
  0,
  0,
  0,  
  SVCall_Handler,  
  DebugMonitor_Handler,  
  0,  
  PendSV_Handler,    
  SysTick_Handler,    
  WWDG_Handler ,    
  PVD_PVM_Handler ,    
  TAMP_STAMP_Handler ,    
  RTC_WKUP_Handler ,    
  FLASH_Handler ,    
  RCC_Handler ,    
  EXTI0_Handler ,    
  EXTI1_Handler ,    
  EXTI2_Handler ,    
  EXTI3_Handler ,    
  EXTI4_Handler,
  DMA1_Channel1_Handler,
  DMA1_Channel2_Handler,    
  DMA1_Channel3_Handler,    
  DMA1_Channel4_Handler,    
  DMA1_Channel5_Handler,    
  DMA1_Channel6_Handler,    
  DMA1_Channel7_Handler,    
  ADC1_2_Handler,    
  CAN1_TX_Handler,    
  CAN1_RX0_Handler,    
  CAN1_RX1_Handler,    
  CAN1_SCE_Handler,    
  EXTI9_5_Handler,    
  TIM1_BRK_TIM15_Handler,    
  TIM1_UP_TIM16_Handler,    
  TIM1_TRG_COM_TIM17_Handler,    
  TIM1_CC_Handler,    
  TIM2_Handler,    
  TIM3_Handler,    
  TIM4_Handler,    
  I2C1_EV_Handler,    
  I2C1_ER_Handler,    
  I2C2_EV_Handler,    
  I2C2_ER_Handler,    
  SPI1_Handler,    
  SPI2_Handler,    
  USART1_Handler,    
  USART2_Handler,    
  USART3_Handler,    
  EXTI15_10_Handler,    
  RTC_Alarm_Handler,    
  DFSDM1_FLT3_Handler,    
  TIM8_BRK_Handler,    
  TIM8_UP_Handler,    
  TIM8_TRG_COM_Handler,    
  TIM8_CC_Handler,    
  ADC3_Handler,    
  FMC_Handler,    
  SDMMC1_Handler,    
  TIM5_Handler,    
  SPI3_Handler,    
  UART4_Handler,    
  UART5_Handler,    
  TIM6_DAC_Handler,    
  TIM7_Handler,    
  DMA2_Channel1_Handler,    
  DMA2_Channel2_Handler,    
  DMA2_Channel3_Handler,    
  DMA2_Channel4_Handler,    
  DMA2_Channel5_Handler,    
  DFSDM1_FLT0_Handler,    
  DFSDM1_FLT1_Handler,    
  DFSDM1_FLT2_Handler,    
  COMP_Handler,    
  LPTIM1_Handler,    
  LPTIM2_Handler,    
  OTG_FS_Handler,    
  DMA2_Channel6_Handler,    
  DMA2_Channel7_Handler,    
  LPUART1_Handler,    
  QUADSPI_Handler,    
  I2C3_EV_Handler,    
  I2C3_ER_Handler,    
  SAI1_Handler,    
  SAI2_Handler,    
  SWPMI1_Handler,    
  TSC_Handler,
  RNG_Handler,
  FPU_Handler
};




void irq_init()
{
    SCB->VTOR = (uint32_t)&vector_table;
}

void Reset_Handler(void)
{
}
