#include "../includes/matrix_display.h"
#include "../includes/numbers.h"
#include <stdio.h>

uint32_t get_color(double r, double g, double b)
{
    unsigned char R = r * 255; // Red intensity
    unsigned char G = g * 255; // Green intensity
    unsigned char B = b * 255; // Blue intensity
    return (G << 24) | (R << 16) | (B << 8);
}

void print_matrix(const uint8_t *pattern)
{
    printf("Matrix Display:\n");
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            int index = row * 5 + col;
            printf("%c ", pattern[index] > 0.5 ? 'X' : '.'); // 'X' for ON, '.' for OFF
        }
        printf("\n");
    }
    printf("\n");
}

void put_leds(const uint8_t *pattern, double *red, double *green, double *blue, PIO pio, uint sm)
{
    for (int16_t i = 0; i < NUM_PIXELS; i++)
    {
        if (i == 15 || i == 5)
        {
            int16_t aux = i;
            for (int16_t j = i + 4; j >= aux; j--, i++)
            {
                uint32_t led_value = get_color(red[24 - j], green[24 - j], blue[24 - j]);
                if (pattern[24 - j])
                {
                    pio_sm_put_blocking(pio, sm, led_value);
                }
                else
                {
                    pio_sm_put_blocking(pio, sm, 0);
                }
            }
            i--;
        }
        else
        {
            uint32_t led_value = get_color(red[24 - i], green[24 - i], blue[24 - i]);
            if (pattern[24 - i])
            {
                pio_sm_put_blocking(pio, sm, led_value);
            }
            else
            {
                pio_sm_put_blocking(pio, sm, 0);
            }
        }
    }
}

void display_number(PIO pio, uint sm, uint number)
{
    double red[NUM_PIXELS] = {0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05};
    double green[NUM_PIXELS] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    double blue[NUM_PIXELS] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    print_matrix(numbers[number]);
    put_leds(numbers[number], red, green, blue, pio, sm);
}