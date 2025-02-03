#ifndef BUTTON_CONTROL_H
#define BUTTON_CONTROL_H

#include "pico/stdlib.h"

#define BUTTON_A 5
#define BUTTON_B 6

void button_init(uint gpio);
void gpio_irq_handler(uint gpio, uint32_t events);

#endif // BUTTON_CONTROL_H