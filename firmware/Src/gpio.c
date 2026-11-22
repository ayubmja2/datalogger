/*
 * gpio.c
 *
 *  Created on: Nov 22, 2026
 *      Author: ayuba
 */

#include "gpio.h"

void gpio_clock_enable(GPIO_TypeDef *port)
{
    // Ports are 0x400 apart: A = bit 0, B = bit 1, C = bit 2
    uint32_t bit = ((uint32_t)port - 0x48000000) / 0x400;
    RCC_AHB2ENR |= (1 << bit);
}

void gpio_set_mode(GPIO_TypeDef *port, uint32_t pin, uint32_t mode)
{
    port->MODER &= ~(3 << (pin * 2));     // clear the pin's 2 bits
    port->MODER |=  (mode << (pin * 2));  // set the new mode
}

void gpio_set_pull(GPIO_TypeDef *port, uint32_t pin, uint32_t pull)
{
    port->PUPDR &= ~(3 << (pin * 2));     // clear the pin's 2 bits
    port->PUPDR |=  (pull << (pin * 2));  // set the new pull value
}

void gpio_write(GPIO_TypeDef *port, uint32_t pin, uint32_t value)
{
    if (value) {
        port->ODR |=  (1 << pin);   // pin high
    } else {
        port->ODR &= ~(1 << pin);   // pin low
    }
}

void gpio_toggle(GPIO_TypeDef *port, uint32_t pin)
{
    port->ODR ^= (1 << pin);        // flip the pin's bit
}

uint32_t gpio_read(GPIO_TypeDef *port, uint32_t pin)
{
    if (port->IDR & (1 << pin)) {
        return 1;                   // pin is high
    }
    return 0;                       // pin is low
}
