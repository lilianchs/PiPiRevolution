/* File: limitswitch.h
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


// Prints out state of limit switch on uart
void read_switch_state(void);

void switch_interrupt_handler(uintptr_t pc, void *aux_data);

void switch_interrupt_setup(void);
