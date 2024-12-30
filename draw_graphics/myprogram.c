#include "uart.h"
#include "draw_graphics.h"
#include "printf.h"
#include "malloc.h"
#include "strings.h"
#include "gl.h"
#include "console.h"
#include "fb.h"
#include "strings.h"
#include "timer.h"
#include "gpio.h"
#include "uart.h"
#include "console.h"
#include "ringbuffer2d.h"
#include "hstimer.h"
#include "interrupts.h"
#include "gpio_interrupt.h"
#include "beat_map.h"

static gpio_id_t LARROW_SWITCH = GPIO_PB6;
static gpio_id_t RARROW_SWITCH = GPIO_PB10;

static void pause(const char *message) {
    if (message) printf("\n%s\n", message);
    printf("[PAUSED] type any key in minicom/terminal to continue: ");
    int ch = uart_getchar();
    uart_putchar(ch);
    uart_putchar('\n');
}

static int choice = -1;

void handle_left_choice(uintptr_t pc, void *aux_data) {
    gpio_interrupt_disable(LARROW_SWITCH);
    gpio_interrupt_clear(LARROW_SWITCH);
    interrupts_global_disable();
    choice = 1;
}

void handle_right_choice(uintptr_t pc, void *aux_data) {
    gpio_interrupt_disable(RARROW_SWITCH);
    gpio_interrupt_clear(RARROW_SWITCH);
    interrupts_global_disable();
    choice = 2;
}


static void choice_init() {
     gpio_set_input(LARROW_SWITCH);
     gpio_set_input(RARROW_SWITCH);
     gpio_interrupt_config(LARROW_SWITCH, GPIO_INTERRUPT_POSITIVE_EDGE, true);
     gpio_interrupt_register_handler(LARROW_SWITCH, handle_left_choice, NULL);
     gpio_interrupt_config(RARROW_SWITCH, GPIO_INTERRUPT_POSITIVE_EDGE, true);
     gpio_interrupt_register_handler(RARROW_SWITCH, handle_right_choice, NULL);
     gpio_interrupt_clear(LARROW_SWITCH);
     gpio_interrupt_clear(RARROW_SWITCH);
     gpio_interrupt_enable(LARROW_SWITCH);
     gpio_interrupt_enable(RARROW_SWITCH);
     interrupts_global_enable();
}

static void begin() {
    // this initializes a graphic layer of size 50*21 by 75 * 14
    // glyph height is 16(without line spacing of 5), glyph width is 14
    console_init(25, 50, GL_YELLOW, GL_BLACK);
    // make the upper header with score
    make_header();
    console_printf(" ");
}

static void countdown() {
    timer_delay(4);
    console_printf("\n3...");
    timer_delay(1);
    console_printf("2...");
    timer_delay(1);
    console_printf("1...");
    timer_delay(1);
    console_printf("start!");
    timer_delay(1);
    console_printf("\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b");
    console_printf(" ");
}

void main(void) {
    uart_init();
    gpio_init();
    interrupts_init();
    gpio_interrupt_init();
    while(1) {
        draw_start_screen();
        timer_delay(4);
        choice = -1;
        choice_init();
        while(choice != 1 && choice != 2) {}
        if(choice == 1) {
            begin();
	    ppr_init();
            countdown();
            promiscuous_map();
        } else if (choice == 2) {
            begin();
	    ppr_init();
            countdown();
            babydoll_map();
        }
        draw_end_screen();
        timer_delay(11);
    }
}

