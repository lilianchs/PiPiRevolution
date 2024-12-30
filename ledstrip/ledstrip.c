// functions for ledstrip.c
#include "gpio.h"

const gpio_id_t red = GPIO_PB1;
const gpio_id_t green = GPIO_PB0;
const gpio_id_t blue = GPIO_PB5;

void led_light_init(void) {
    gpio_init();
    gpio_set_output(red);
    gpio_set_output(blue);
    gpio_set_output(green);
}

void red_light(void) {
    gpio_write(red, 255);
    gpio_write(blue,0);
    gpio_write(green,0);
}

void blue_light(void) {
    gpio_write(red, 0);
    gpio_write(blue, 255);
    gpio_write(green,0);
}

void green_light(void) {
    gpio_write(red, 0);
    gpio_write(blue, 0);
    gpio_write(green, 255);
}

void pink_light(void) {
    gpio_write(red, 255);
    gpio_write(blue, 182);
    gpio_write(green, 193);
}

void nothing(void) {
    gpio_write(red,0);
    gpio_write(blue,0);
    gpio_write(green,0);
}
