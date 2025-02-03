#ifndef MATRIX_DISPLAY_H
#define MATRIX_DISPLAY_H

#include "pico/stdlib.h"
#include "hardware/pio.h"

#define MATRIX_PIN 7
#define NUM_PIXELS 25

void display_number(PIO pio, uint sm, uint number);

#endif 