/*
 * gpio.h
 *
 *  Created on: Nov 22, 2026
 *      Author: ayuba
 */

#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

// One port's registers, in memory order (RM0351 page 314)
typedef struct {
    volatile uint32_t MODER;    // 0x00
    volatile uint32_t OTYPER;   // 0x04
    volatile uint32_t OSPEEDR;  // 0x08
    volatile uint32_t PUPDR;    // 0x0C
    volatile uint32_t IDR;      // 0x10
    volatile uint32_t ODR;      // 0x14
} GPIO_TypeDef;

// Port base addresses
#define GPIOA  ((GPIO_TypeDef *) 0x48000000)
#define GPIOB  ((GPIO_TypeDef *) 0x48000400)
#define GPIOC  ((GPIO_TypeDef *) 0x48000800)

// RCC clock enable register
#define RCC_AHB2ENR  (*(volatile uint32_t *) 0x4002104C)

// Mode values (MODER)
#define GPIO_MODE_INPUT   0
#define GPIO_MODE_OUTPUT  1
#define GPIO_MODE_ALT     2
#define GPIO_MODE_ANALOG  3

// Pull values (PUPDR)
#define GPIO_PULL_NONE  0
#define GPIO_PULL_UP    1
#define GPIO_PULL_DOWN  2

// Functions
void gpio_clock_enable(GPIO_TypeDef *port);
void gpio_set_mode(GPIO_TypeDef *port, uint32_t pin, uint32_t mode);
void gpio_set_pull(GPIO_TypeDef *port, uint32_t pin, uint32_t pull);
void gpio_write(GPIO_TypeDef *port, uint32_t pin, uint32_t value);
void gpio_toggle(GPIO_TypeDef *port, uint32_t pin);
uint32_t gpio_read(GPIO_TypeDef *port, uint32_t pin);

#endif
