#include "../includes/led_control.h"

void blink_red_led()
{
    static uint32_t last_toggle_time = 0;
    uint32_t current_time = to_us_since_boot(get_absolute_time());

    // Blink every 200ms (5 times per second)
    if (current_time - last_toggle_time > 200000)
    {
        last_toggle_time = current_time;

        // Toggle the LED state
        static bool led_on = false;
        led_on = !led_on;
        gpio_put(RED_LED, led_on ? 1 : 0);
    }
}