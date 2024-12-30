/* File: program_limit.c
 * --------------
 * Lilianch@stanford.edu : reads interrupts from limit switch
 */

#include "uart.h"
#include "printf.h"
#include "malloc.h"
#include "gl.h"
#include "console.h"
#include "fb.h"
#include "strings.h"
#include "timer.h"
#include "gpio_interrupt.h"
#include "interrupts.h"
#include "timer.h"
#include "gpio.h"
#include "gpio_extra.h"
#include "limitswitch.h"

volatile static int count = 0;

void main(void) {
    gpio_init();
    uart_init();
    printf("lol");
    //gpio_set_input(SWITCH_STATE);
    //gpio_set_pulldown(SWITCH_STATE); 
    switch_interrupt_setup();
    while(1) {
        read_switch_state(); 
    }
}
