#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "hardware/pio.h"
#include "hardware/gpio.h"
#include "hardware/irq.h"
#include "pio_matrix.pio.h"
#include "./includes/led_control.h"
#include "./includes/button_control.h"
#include "./includes/matrix_display.h"

int main()
{
    // Initialize the red LED
    gpio_init(RED_LED);
    gpio_set_dir(RED_LED, GPIO_OUT);

    // Initialize buttons
    button_init(BUTTON_A);
    button_init(BUTTON_B);

    // Set system clock to 128 MHz
    set_sys_clock_khz(128000, false);

    // Initialize serial communication
    stdio_init_all();

    // Initialize PIO and configure the state machine
    PIO pio = pio0;
    uint sm = 0;
    uint offset = pio_add_program(pio, &pio_matrix_program);
    pio_matrix_program_init(pio, sm, offset, MATRIX_PIN);

    // Display the initial number (0)
    display_number(pio, sm, 0);

    // Configure button interrupts
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    // Main loop
    while (true)
    {
        // Blink the red LED
        blink_red_led();
    }

    return 0;
}