#include "../includes/button_control.h"
#include "../includes/matrix_display.h"
#include "hardware/gpio.h"
#include "hardware/irq.h"
#include "hardware/clocks.h"
static volatile int counter = 0;

void button_init(uint gpio)
{
    gpio_init(gpio);
    gpio_set_dir(gpio, GPIO_IN);
    gpio_pull_up(gpio);
}

void gpio_irq_handler(uint gpio, uint32_t events)
{
    static volatile uint32_t last_time = 0;
    uint32_t current_time = to_us_since_boot(get_absolute_time());

    // Debouncing: Ignore rapid successive presses
    if (current_time - last_time > 200000)
    {
        last_time = current_time;

        // Increment or decrement the counter
        if (gpio == BUTTON_A && counter < 9)
        {
            counter++;
        }
        else if (gpio == BUTTON_B && counter > 0)
        {
            counter--;
        }

        // Update the display with the new number
        display_number(pio0, 0, counter);
    }
}