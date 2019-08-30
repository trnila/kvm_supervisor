#include "stm32f103xb.h"

#define BTN_PORT GPIOB
#define BTN_PIN 6

#define DETECT_PORT GPIOB
#define DETECT_PIN 11

#define FEEDBACK_PORT GPIOA
#define FEEDBACK_PIN 12

#define CPU_FREQ 8000000
#define SYSTICK_PRESCALER 8

#define BTN_INTERVAL_MS 280
#define BTN_ACTIVE_MS 15

void gpio_set_mode(GPIO_TypeDef *gpio, int pin, int cnf, int mode) {
  volatile uint32_t *reg = &gpio->CRL;

  if(pin > 7) {
    pin -= 8;
    reg = &gpio->CRH;
  }
  uint32_t offset = 4 * pin;

  *reg &= ~(0xF << offset);
  *reg |= ((cnf << 2) | mode) << offset;
}

int get_gpio_index(GPIO_TypeDef *gpio) {
  GPIO_TypeDef *gpios[] = {GPIOA, GPIOB, GPIOC, GPIOD};
  for(int i = 0; i < sizeof(gpios) / sizeof(*gpios); i++) {
    if(gpios[i] == gpio) {
      return i;
    }
  }
  return -1;
}

void delay_ms(int delay) {
  SysTick->VAL = 0;
  SysTick->LOAD = CPU_FREQ / 1000 / SYSTICK_PRESCALER * delay - 1;
  SysTick->CTRL = SysTick_CTRL_ENABLE_Msk;

  while(!(SysTick->CTRL & (1 << 16)));
  SysTick->CTRL = 0;
}

int main(void) {
  // enable clocks
  RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN;
  RCC->APB1ENR |= RCC_APB1ENR_PWREN;

  // setup btn gpio
  BTN_PORT->ODR |= 1 << BTN_PIN;
  gpio_set_mode(BTN_PORT, BTN_PIN, 0b01 /* output open-drain */, 0b10 /* max speed 2 mhz*/);

  // setup feedback gpio
  gpio_set_mode(FEEDBACK_PORT, FEEDBACK_PIN, 0b10 /* input */, 0b00);
  // enable pull-down resistor
  FEEDBACK_PORT->BSRR = (1 << FEEDBACK_PIN) << 16U;

  // setup detect gpio
  gpio_set_mode(DETECT_PORT, DETECT_PIN, 0b10 /* input */, 0b00);
  // enable pull-down resistor
  DETECT_PORT->BSRR = (1 << DETECT_PIN) << 16U;

  // enable interrupt request from pin on port
  AFIO->EXTICR[DETECT_PIN / 4] &= ~(0xF << (4 * (DETECT_PIN & 0x3)));
  AFIO->EXTICR[DETECT_PIN / 4] |= get_gpio_index(DETECT_PORT) << (4 * (DETECT_PIN & 0x3));

  // enable event requests on gpio line - used with WFE instruction
  EXTI->EMR |= 1 << DETECT_PIN;
  // falling edge
  EXTI->FTSR |= 1 << DETECT_PIN;
  // rising edge
  EXTI->RTSR |= 1 << DETECT_PIN;

  // wait for controller power up
  delay_ms(50);

  for(;;) {
    uint32_t feedback = (FEEDBACK_PORT->IDR & (1 << FEEDBACK_PIN)) > 0;
    uint32_t detect = (DETECT_PORT->IDR & (1 << DETECT_PIN)) > 0;

    if(detect != feedback) {
      BTN_PORT->ODR &= ~(1 << BTN_PIN);
      delay_ms(BTN_ACTIVE_MS);
      BTN_PORT->ODR |= 1 << BTN_PIN;
      delay_ms(BTN_INTERVAL_MS - BTN_ACTIVE_MS);
    } else {
      // sleep until rising/falling edge on detect pin
      // debug is not clocked, so you have to pull BOOT0 high, reset and connect
      asm("wfe");
    }
  }
}
