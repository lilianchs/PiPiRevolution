#ifndef _DRAW_GRAPHICS_H
#define _DRAW_GRAPHICS_H
#include "fb.h"
#include "uart.h"
#include "draw_graphics.h"
#include "printf.h"
#include "malloc.h"
#include "strings.h"
#include "gl.h"
#include "console.h"
#include "fb.h"
#include "timer.h"
#include "gpio.h"
#include "gpio_extra.h"
#include "uart.h"
#include "ringbuffer2d.h"
#include "hstimer.h"

/*
This function draws a filled triangle pointing left, with the top and bottom points being vertically aligned. Furthermore, the left coordinate should have slope +- 1 from the other points.

This function has no checks on bounds, so ensure that the left point is in bounds, and the length is too
 */

typedef struct arrow_state arrow_state;

enum{
  LEFT_ARROW = 0,
  RIGHT_ARROW,
  UP_ARROW,
  DOWN_ARROW
};

// draws a directional triangle and displays it on screen
void draw_triangle(int arrow_type, int tri_x, int tri_y, int length, color_t c, arrow_state* arrow);

void ppr_init();

// create a new arrow instance
arrow_state* gl_make_new_arrow(int arrow_type, color_t c);

void draw_start_screen();

// draws a left pointing arrow and displays it on screen. This is for scrolling
void gl_draw_arrow(arrow_state* arrow);

// draws in the header of the screen, containing the score
void make_header();

// this function scrolls the screen up once
void scroll_screen(arrow_state* arrow_list[]);

void draw_end_screen();


#endif
