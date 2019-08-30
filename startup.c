// top of the stack
extern void _estack(void);
void main();

void Reset_Handler() {
  main();
  asm("bkpt #1");
  for(;;);
}

void default_irq_handler() {
  for(;;) {
    asm("bkpt #1");
  }
}

__attribute__((weak, alias("default_irq_handler"))) void NMI_Handler();
__attribute__((weak, alias("default_irq_handler"))) void HardFault_Handler();
__attribute__((weak, alias("default_irq_handler"))) void MemManage_Handler();
__attribute__((weak, alias("default_irq_handler"))) void BusFault_Handler();
__attribute__((weak, alias("default_irq_handler"))) void UsageFault_Handler();
__attribute__((weak, alias("default_irq_handler"))) void SVC_Handler();
__attribute__((weak, alias("default_irq_handler"))) void DebugMon_Handler();
__attribute__((weak, alias("default_irq_handler"))) void PendSV_Handler();
__attribute__((weak, alias("default_irq_handler"))) void SysTick_Handler();
__attribute__((weak, alias("default_irq_handler"))) void WWDG_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void PVD_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void TAMPER_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void RTC_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void FLASH_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void RCC_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void EXTI0_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void EXTI1_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void EXTI2_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void EXTI3_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void EXTI4_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void DMA1_Channel1_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void DMA1_Channel2_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void DMA1_Channel3_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void DMA1_Channel4_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void DMA1_Channel5_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void DMA1_Channel6_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void DMA1_Channel7_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void ADC1_2_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void USB_HP_CAN1_TX_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void USB_LP_CAN1_RX0_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void CAN1_RX1_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void CAN1_SCE_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void EXTI9_5_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void TIM1_BRK_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void TIM1_UP_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void TIM1_TRG_COM_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void TIM1_CC_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void TIM2_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void TIM3_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void I2C1_EV_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void I2C1_ER_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void SPI1_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void USART1_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void USART2_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void EXTI15_10_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void RTC_Alarm_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void USBWakeUp_IRQHandler();
__attribute__((weak, alias("default_irq_handler"))) void BootRAM();

__attribute__ ((used, section(".isr_vector"))) void (*vectors[])(void) = {
  &_estack,
  Reset_Handler,
  NMI_Handler,
  HardFault_Handler,
  MemManage_Handler,
  BusFault_Handler,
  UsageFault_Handler,
  0,
  0,
  0,
  0,
  SVC_Handler,
  DebugMon_Handler,
  0,
  PendSV_Handler,
  SysTick_Handler,
  WWDG_IRQHandler,
  PVD_IRQHandler,
  TAMPER_IRQHandler,
  RTC_IRQHandler,
  FLASH_IRQHandler,
  RCC_IRQHandler,
  EXTI0_IRQHandler,
  EXTI1_IRQHandler,
  EXTI2_IRQHandler,
  EXTI3_IRQHandler,
  EXTI4_IRQHandler,
  DMA1_Channel1_IRQHandler,
  DMA1_Channel2_IRQHandler,
  DMA1_Channel3_IRQHandler,
  DMA1_Channel4_IRQHandler,
  DMA1_Channel5_IRQHandler,
  DMA1_Channel6_IRQHandler,
  DMA1_Channel7_IRQHandler,
  ADC1_2_IRQHandler,
  USB_HP_CAN1_TX_IRQHandler,
  USB_LP_CAN1_RX0_IRQHandler,
  CAN1_RX1_IRQHandler,
  CAN1_SCE_IRQHandler,
  EXTI9_5_IRQHandler,
  TIM1_BRK_IRQHandler,
  TIM1_UP_IRQHandler,
  TIM1_TRG_COM_IRQHandler,
  TIM1_CC_IRQHandler,
  TIM2_IRQHandler,
  TIM3_IRQHandler,
  0,
  I2C1_EV_IRQHandler,
  I2C1_ER_IRQHandler,
  0,
  0,
  SPI1_IRQHandler,
  0,
  USART1_IRQHandler,
  USART2_IRQHandler,
  0,
  EXTI15_10_IRQHandler,
  RTC_Alarm_IRQHandler,
  USBWakeUp_IRQHandler,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  BootRAM,
};
