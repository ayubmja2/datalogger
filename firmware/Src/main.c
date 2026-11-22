#include <stdint.h>
#include "gpio.h"

int main(void)
{
    gpio_clock_enable(GPIOA);

    gpio_set_mode(GPIOA, 0, GPIO_MODE_INPUT);   // PA0: button
    gpio_set_pull(GPIOA, 0, GPIO_PULL_UP);
    gpio_set_mode(GPIOA, 1, GPIO_MODE_OUTPUT);  // PA1: LED

    while (1) {
        if (gpio_read(GPIOA, 0) == 0) {   // pressed (active low)
            gpio_write(GPIOA, 1, 1);      // LED on
        } else {
            gpio_write(GPIOA, 1, 0);      // LED off
        }
    }
}
