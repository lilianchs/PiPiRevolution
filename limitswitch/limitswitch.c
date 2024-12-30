/*gpio_interrupt_clear(LARROW_SWITCH);gpio_interrupt_clear(LARROW_SWITCH);gpio_interrupt_clear(LARROW_SWITCH);gpio_interrupt_clear(LARROW_SWITCH); File: limitswitch.c
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

const gpio_id_t SWITCH_STATE = GPIO_PB12;

// Prints out state of limit switch on uart
void read_switch_state(void) {

// QUESTION: why do we set gpio to input, then pulldown in lab7
    gpio_set_input(SWITCH_STATE);
    //gpio_set_pulldown(SWITCH_STATE);

    while(1) {
      //uart_putchar('l');
      printf("%d \n", gpio_read(SWITCH_STATE));
      //        uart_putchar(gpio_read(SWITCH_STATE));
    }
}

void switch_interrupt_handler(uintptr_t pc, void *aux_data) {
    printf("Limit Switch Pressed! Interrupts disabled \n");
    gpio_interrupt_clear(SWITCH_STATE);
    gpio_interrupt_disable(SWITCH_STATE);
    interrupts_global_disable();
}

void switch_interrupt_setup(void) {
    interrupts_init();
    gpio_interrupt_init();
    gpio_interrupt_config(SWITCH_STATE, GPIO_INTERRUPT_POSITIVE_EDGE, true);
    gpio_interrupt_register_handler(SWITCH_STATE, switch_interrupt_handler, (void*)"");
    gpio_interrupt_enable(SWITCH_STATE);

    interrupts_global_enable();
}
