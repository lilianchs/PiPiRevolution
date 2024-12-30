// run led strip
#include "ledstrip.h"
#include "hstimer.h"
#include "timer.h"
#include "gpio.h"
#include "uart.h"
#include "printf.h"

const gpio_id_t greens = GPIO_PD21;
const gpio_id_t blues = GPIO_PB0;
const gpio_id_t reds = GPIO_PD22;


void main(void) {
    uart_init();
    led_light_init();
    unsigned long start = timer_get_ticks();
    unsigned long now = timer_get_ticks();
    green_light();
    while(1) {
	//green_light();
    }
   
    // printf("done");
}
