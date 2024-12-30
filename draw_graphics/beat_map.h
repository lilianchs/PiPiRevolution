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


enum{
  LEFT = 0,
  DOWN,
  UP,
  RIGHT
};

void scroll(arrow_state** arrow_list, int num);
void babydoll_map(void);
void promiscuous_map(void);
