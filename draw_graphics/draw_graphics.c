#include "draw_graphics.h"
#include "printf.h"
#include "de.h"
#include "hdmi.h"
#include "malloc.h"
#include "strings.h"
#include "gl.h"
#include "fb.h"
#include "gpio.h"
#include "gpio_extra.h"
#include "uart.h"
#include "console.h"
#include "ringbuffer2d.h"
#include "malloc.h"
#include <stdbool.h>
#include "timer.h"
#include "hstimer.h"
#include "gpio_interrupt.h"
#include "interrupts.h"

#define BG_COLOR GL_BLACK

const gpio_id_t LARROW_SWITCH = GPIO_PB6;
const gpio_id_t RARROW_SWITCH = GPIO_PB10;
const gpio_id_t UARROW_SWITCH = GPIO_PB11;
const gpio_id_t DARROW_SWITCH = GPIO_PB12;

/*
  This file contains the graphics functions used for Pi Pi Revolution.  
 */

// this struct contains the information for the arrow state
struct arrow_state{
  int arrow_type;
  bool should_show;
  // left, right, up, and down triangles can be defined with these fields
  int triangle_startx;
  int triangle_starty;
  int triangle_length;
  
  int rect_startx;
  int rect_starty;
  int rect_width;
  int rect_height;

  color_t color;
}; // eventually make this an array of 4 structs

int arrow_count = 0;
int null_count = 0;
int score = 0;

// this function creates a new instance of the arrow struct
arrow_state* arrow_new(int arrow_type, bool should_show, int tri_startx, int tri_starty, int tri_length, int rect_startx, int rect_starty, int rect_width, int rect_height, color_t color){
  // malloc this
  arrow_state* arrow = malloc(sizeof(*arrow));
  
  // fill in the struct
  arrow -> arrow_type = arrow_type;
  arrow -> should_show = true;
  arrow -> triangle_startx = tri_startx;
  arrow -> triangle_starty = tri_starty;
  arrow -> triangle_length = tri_length;
  arrow -> rect_startx = rect_startx;
  arrow -> rect_starty = rect_starty;
  arrow -> rect_width = rect_width;
  arrow -> rect_height = rect_height;
  arrow -> color = color;

  return arrow;
}

// draw any triangle based on fields
void draw_triangle(int arrow_type, int tri_x, int tri_y, int length, color_t c, arrow_state* arrow){
  // get the draw buffer
  color_t (*fb)[gl_get_width()] = fb_get_draw_buffer();
  // draw left triangle
  if (arrow_type == LEFT_ARROW){
    // bounds of the triangle
    int x_bound = tri_x + length;
    int y_bound_top = tri_y - length;
    int y_bound_bottom = tri_y + length;
    
    // fill in the triangle
    for (int right = x_bound; right > tri_x - 1; right--){   
      for (int down = y_bound_top; down < y_bound_bottom; down++){
	fb[down][right] = c;
      }
      // narrow in for the next round
      y_bound_top += 1;
      y_bound_bottom -= 1; 
    } 
  }

  // draw right triangle
  else if (arrow_type == RIGHT_ARROW){
    // bounds of the triangle
    int x_bound = tri_x - length;
    int y_bound_top = tri_y - length;
    int y_bound_bottom = tri_y + length;
    
    // fill in the triangle
    for (int right = x_bound; right < tri_x; right++){
      for (int down = y_bound_top; down < y_bound_bottom; down++){
	fb[down][right] = c;
      }
      // narrow in for the next round
      y_bound_top += 1;
      y_bound_bottom -= 1;
    }
  }

  // draw up triangle
  else if (arrow_type == UP_ARROW){
    // bounds of the triangle
    int y_bound = tri_y + length;
    int x_bound_left = tri_x - length;
    int x_bound_right = tri_x + length;
    
    // fill in the triangle
    for (int down = y_bound; down > tri_y-1; down--){
      for (int left = x_bound_left; left < x_bound_right; left++){
	fb[down][left] = c;
      }
      // narrow in for the next round
      x_bound_left += 1;
      x_bound_right -= 1;
    }
  }

  // draw down triangle
  else if (arrow_type == DOWN_ARROW){
    // bounds of the triangle
    int y_bound = tri_y - length;
    int x_bound_left = tri_x - length;
    int x_bound_right = tri_x + length;
    
    // fill in the triangle
    for (int down = y_bound; down < tri_y + 1; down++){
      for (int left = x_bound_left; left < x_bound_right; left++){
	fb[down][left] = c;
      }
      // narrow in for the next round
      x_bound_left += 1;
      x_bound_right -= 1;
    }
  }
  
}
  
// this is when we want to create a new arrow struct. Just a way to decrease the number of parameters
arrow_state* gl_make_new_arrow(int arrow_type, color_t c){
  int tri_length = 25;
  int tri_startx = 100;
  int tri_starty = 100;
  bool should_show = true;
  
  if(arrow_type == LEFT_ARROW){
    tri_startx = 100;
    tri_starty = 450;
  }
  else if (arrow_type == RIGHT_ARROW){
    tri_startx = 550;
    tri_starty = 450;
  }
  else if (arrow_type == UP_ARROW){
    tri_startx = 400;
    tri_starty = 410;
  }
  else if (arrow_type == DOWN_ARROW){
    tri_startx = 250;
    tri_starty = 500;
  }
  
  //printf("%d", tri_startx);

  // variables we will set
  int rect_startx = 234;
  int rect_starty = 100;
  int rect_width = 100;
  int rect_height = 100;
  
  // arrow cases
  if (arrow_type == LEFT_ARROW){
    rect_startx = tri_startx + tri_length;
    rect_starty = tri_starty - (tri_length / 2);
    rect_width = tri_length*2;
    rect_height = tri_length;
  }
  else if (arrow_type == RIGHT_ARROW){
    rect_startx = tri_startx - 3 * tri_length;
    rect_starty = tri_starty - (tri_length / 2);
    rect_width = tri_length*2;
    rect_height = tri_length;
  }
  else if (arrow_type == UP_ARROW){
    rect_startx = tri_startx - (tri_length / 2);
    rect_starty = tri_starty + tri_length;
    rect_width = tri_length;
    rect_height = tri_length*2;
  }
  else if (arrow_type == DOWN_ARROW){
    rect_startx = tri_startx - (tri_length / 2);
    rect_starty = tri_starty - tri_length * 3;
    rect_width = tri_length;
    rect_height = tri_length*2;
  }
  arrow_count++;
  arrow_state* new_arrow = arrow_new(arrow_type, should_show, tri_startx, tri_starty, tri_length, rect_startx, rect_starty, rect_width, rect_height, c);

  // I need to free this at some point
  return new_arrow;
}

static arrow_state* ghost_arrow(int arrow_type){
  color_t c = GL_WHITE;
  int tri_length = 25;
  int tri_startx = 100;
  int tri_starty = 100;
  bool should_show = true;
  
  if(arrow_type == LEFT_ARROW){
    tri_startx = 100;
    tri_starty = 115;
  }
  else if (arrow_type == RIGHT_ARROW){
    tri_startx = 550;
    tri_starty = 115;
  }
  else if (arrow_type == UP_ARROW){
    tri_startx = 400;
    tri_starty = 70;
  }
  else if (arrow_type == DOWN_ARROW){
    tri_startx = 250;
    tri_starty = 150;
  }
  

  // variables we will set
  int rect_startx = 234;
  int rect_starty = 100;
  int rect_width = 100;
  int rect_height = 100;
  
  // arrow cases
  if (arrow_type == LEFT_ARROW){
    rect_startx = tri_startx + tri_length;
    rect_starty = tri_starty - (tri_length / 2);
    rect_width = tri_length*2;
    rect_height = tri_length;
  }
  else if (arrow_type == RIGHT_ARROW){
    rect_startx = tri_startx - 3 * tri_length;
    rect_starty = tri_starty - (tri_length / 2);
    rect_width = tri_length*2;
    rect_height = tri_length;
  }
  else if (arrow_type == UP_ARROW){
    rect_startx = tri_startx - (tri_length / 2);
    rect_starty = tri_starty + tri_length;
    rect_width = tri_length;
    rect_height = tri_length*2;
  }
  else if (arrow_type == DOWN_ARROW){
    rect_startx = tri_startx - (tri_length / 2);
    rect_starty = tri_starty - tri_length * 3;
    rect_width = tri_length;
    rect_height = tri_length*2;
  }
  arrow_state* new_arrow = arrow_new(arrow_type, should_show, tri_startx, tri_starty, tri_length, rect_startx, rect_starty, rect_width, rect_height, c);

  // I need to free this at some point
  return new_arrow;
}

// this function is for redrawing scrolled arrows
void gl_draw_arrow(arrow_state* arrow){
  
  // arrow is made up of a triangle and a rectangle
  draw_triangle(arrow->arrow_type, arrow->triangle_startx, arrow->triangle_starty, arrow->triangle_length, arrow->color, arrow);
  gl_draw_rect(arrow->rect_startx, arrow->rect_starty, arrow->rect_width, arrow->rect_height, arrow->color);
}

void make_header(){
  console_printf("start           Pi Pi Revolution       Score: %d     _____________________________________________", score); // use printf %d to update score
  arrow_state* left_ghost = ghost_arrow(LEFT_ARROW);
  arrow_state* right_ghost = ghost_arrow(RIGHT_ARROW);
  arrow_state* up_ghost = ghost_arrow(UP_ARROW);
  arrow_state* down_ghost = ghost_arrow(DOWN_ARROW);

  // need to draw to both buffers
  gl_draw_arrow(left_ghost);
  gl_draw_arrow(right_ghost);
  gl_draw_arrow(up_ghost);
  gl_draw_arrow(down_ghost);
  gl_swap_buffer();

  gl_draw_arrow(left_ghost);
  gl_draw_arrow(right_ghost);
  gl_draw_arrow(up_ghost);
  gl_draw_arrow(down_ghost);
  gl_swap_buffer();
  
}

static void update_score(){
   console_printf("\fstart           Pi Pi Revolution       Score: %d     _____________________________________________\n", score);
   console_printf("\fstart           Pi Pi Revolution       Score: %d     _____________________________________________\n", score);
}

void draw_start_screen(){
  console_init(25,50,GL_YELLOW, GL_BLACK);
  console_printf("\n\n\n\n\n\n           WELCOME TO PI PI REVOLUTION           \n\n          Produced by Lil Chen and J Qin             \n\n             To Start, Select Song!  \n       LEFT TILE: PROMISCUOUS MAP (medium)   \n          RIGHT TILE: BABYDOLL MAP (hard) "); // use printf %d to update score
  //int ch = uart_getchar();
}

void draw_end_screen(){
  console_init(25,50,GL_YELLOW, GL_BLACK);
  char* message = NULL;

  if (score > 3000){
    message = (char*)"Spectacular Job! Now go touch some grass";
  }
  else if (score > 2000){
    message = (char*)"Amazing Job! You got some serious moves B)";
  }

  else if (score > 1500){
    message = (char*)"Good stuff broski";
  }
  
  else{
    message = (char*)"Even Lilian could've done better :(";
  }
  
  console_printf("\n\n\n\n\nGAME OVER!\n\n\nScore: %d\n%s",score, message);

}

// INTERRUPTS INTERRUPTS INTERRUPTS
// INTERUUPTS INTERUPTS INTERRUTPPTTS
// * *  * * * * * * * * * **  ** ** * * **
// * *  * * * * * * * * * **  ** ** * * **     

void handle_left_click(uintptr_t pc, void *aux_data) {
    gpio_interrupt_disable(LARROW_SWITCH);
    gpio_interrupt_clear(LARROW_SWITCH);
    score += 50;
    update_score();
}
void handle_right_click(uintptr_t pc, void *aux_data) {
    gpio_interrupt_disable(RARROW_SWITCH);
    gpio_interrupt_clear(RARROW_SWITCH);
    score += 50;
    update_score();
}
void handle_up_click(uintptr_t pc, void *aux_data) {
    gpio_interrupt_disable(UARROW_SWITCH);
    gpio_interrupt_clear(UARROW_SWITCH);
    score += 50;
    update_score();
}

void handle_down_click(uintptr_t pc, void *aux_data) {
    gpio_interrupt_disable(DARROW_SWITCH);
    gpio_interrupt_clear(DARROW_SWITCH);
    score += 50;
    update_score();
}


 void ppr_init(){
   score = 0;
   arrow_count = 0;
   null_count = 0;
   update_score();
   gpio_set_input(LARROW_SWITCH);
   gpio_set_input(RARROW_SWITCH);   
   gpio_set_input(DARROW_SWITCH);
   gpio_set_input(UARROW_SWITCH);
   
   gpio_interrupt_config(LARROW_SWITCH, GPIO_INTERRUPT_POSITIVE_EDGE, true);
   gpio_interrupt_register_handler(LARROW_SWITCH, handle_left_click, NULL);

   gpio_interrupt_config(RARROW_SWITCH, GPIO_INTERRUPT_POSITIVE_EDGE, true);
   gpio_interrupt_register_handler(RARROW_SWITCH, handle_right_click, NULL);

   gpio_interrupt_config(UARROW_SWITCH, GPIO_INTERRUPT_POSITIVE_EDGE, true);
   gpio_interrupt_register_handler(UARROW_SWITCH, handle_up_click, NULL);

   gpio_interrupt_config(DARROW_SWITCH, GPIO_INTERRUPT_POSITIVE_EDGE, true);
   gpio_interrupt_register_handler(DARROW_SWITCH, handle_down_click, NULL);

   interrupts_global_enable();
 }


// * *  * * * * * * * * * **  ** ** * * **  
// * *  * * * * * * * * * **  ** ** * * **     
// * *  * * * * * * * * * **  ** ** * * **     
//* *  * * * * * * * * * **  ** ** * * **      
// * *  * * * * * * * * * **  ** ** * * **     
// * *  * * * * * * * * * **  ** ** * * **     

// this function scrolls arrow structs up once
void scroll_screen(arrow_state* arrow_list[]){
  // Number of reserved rows at the top of the screen
  int reserved_rows = 3;
  
  // Line spacing between rows
  int line_spacing = 6;

  int start = null_count; 
  int end = arrow_count;
  start = null_count % 6; // 4 [4:] 
  // null = 7, arrow = 11 -> start = 1 , end = 5 // do 
  //start = 4 and end = 1, do 4,5,0;
  end = arrow_count  % 6; // [:1]
  int counter = 0;
  int index_array[6] = {0, 0, 0, 0, 0, 0};
  if(end > start) { // null count goes up, arrow count , null to arrow -> null = 1 , arrow = 4 -> 1, 2, 3, 4
      counter = end-start;
      int arrow_counter = 0;
      for(int i = 0; i < end - start; i++) {
        index_array[i] = start + arrow_counter;
        arrow_counter++;
      }
  } else if (end < start){
      for(int i = start; i < 6; i++) {
        index_array[counter] = i;
        counter++;
      }
      for(int i = 0; i < end; i++) {
        index_array[counter] = i;
        counter++;
      }
  } else if (end == start){
      index_array[0] = end; 
  }
  // loop through each arrow in the array
  for(int index = 0; index < counter; index++) {
    arrow_state* arrow = arrow_list[index_array[index]];
    int endpt_checker = 0;
    
    // little snippet to get the coord where we cut arrows off (they scolled too high)
    if(arrow->arrow_type == LEFT_ARROW || arrow->arrow_type == RIGHT_ARROW) {
         endpt_checker = arrow->rect_starty;
    } else if (arrow->arrow_type == UP_ARROW) {
         endpt_checker = arrow->rect_starty;
    } else {
         endpt_checker = arrow->rect_starty+ (arrow->triangle_length);
    }

    // little snippet to get the impact point of a specific arrow
    int impact_checker = 0;
    if(arrow->arrow_type == LEFT_ARROW || arrow->arrow_type == RIGHT_ARROW){
      impact_checker = arrow->triangle_starty - arrow->triangle_length;
    } else if (arrow->arrow_type == UP_ARROW) {
      impact_checker = arrow->triangle_starty;
    } else {
      impact_checker = arrow->rect_starty;
    }   

    // don't update if we hit the reserved area
    if (endpt_checker < ((gl_get_char_height() + line_spacing) * reserved_rows)) {
        null_count++;
        arrow->should_show = false;
        arrow->color = BG_COLOR;
    } else {// Check for impact zone. Depending on the arrow, enable the specific gpio_interrupt if we're in the impact zone
      
      // I took the y coord values from ghost_arrow
      if(arrow->arrow_type == LEFT_ARROW && impact_checker <= 115 + (arrow->triangle_length)/2){
        if(impact_checker == 90 || impact_checker == 91) {
          gpio_interrupt_disable(LARROW_SWITCH);
	} else if (impact_checker == 127 || impact_checker == 128) { // enable interrupts for corresponding pin, since we are in the impact interval
          gpio_interrupt_clear(LARROW_SWITCH);
          gpio_interrupt_enable(LARROW_SWITCH);
        }
      }

      else if(arrow->arrow_type == RIGHT_ARROW &&  impact_checker <= 115 + (arrow->triangle_length)/2){
	//if (impact_checker <= 105 - arrow->triangle_length){ // if we go too high
        if(impact_checker == 90 || impact_checker == 91) {
          gpio_interrupt_disable(RARROW_SWITCH);
	} else if (impact_checker == 127 || impact_checker == 128) { // enable interrupts for corresponding pin, since we are in the impact interval
          gpio_interrupt_clear(RARROW_SWITCH);
          gpio_interrupt_enable(RARROW_SWITCH);
	}
      }

      else if(arrow->arrow_type == UP_ARROW &&  impact_checker <= 120 + 2*(arrow->triangle_length)){
	//if (impact_checker <= 120 - (arrow->triangle_length)*2){ // if we go too high
	if(impact_checker == 45 || impact_checker == 46) { 
          gpio_interrupt_disable(UARROW_SWITCH);
	} else { // enable interrupts for corresponding pin, since we are in the impact interval
	  if (impact_checker == 125 || impact_checker == 126) {
	    gpio_interrupt_clear(UARROW_SWITCH);
            gpio_interrupt_enable(UARROW_SWITCH);
	  }
	}
      }
      else if(arrow->arrow_type == DOWN_ARROW &&  impact_checker <= 150 - (arrow->triangle_length)){        	
	//if (impact_checker <= 150 -4*(arrow->triangle_length) + 10){ // if we go too high
        if(impact_checker == 40 || impact_checker == 41) { 
          gpio_interrupt_disable(DARROW_SWITCH);
	} else { // enable interrupts for corresponding pin, since we are in the impact interval
	  if (impact_checker == 165 - 2* (arrow->triangle_length) || impact_checker == 1+165 - 2* (arrow->triangle_length)) {
	    gpio_interrupt_clear(DARROW_SWITCH);
	    gpio_interrupt_enable(DARROW_SWITCH);
	  }
	}
      }
      
      
      // This moves the arrow location up by 1 (change this value to change scroll speed), regardless of impact zone
      arrow->triangle_starty -= 2;
      arrow->rect_starty -= 2;
    }
    
    // clear whatever was there before with the background color. Each arrow needs a case
    if (arrow->arrow_type == LEFT_ARROW) {
      gl_draw_rect(arrow->triangle_startx, arrow->triangle_starty - (arrow->triangle_length /2), 3* arrow->triangle_length, arrow->triangle_length * 2, BG_COLOR);
    }
    
    if (arrow->arrow_type == RIGHT_ARROW) {
      gl_draw_rect(arrow->triangle_startx - 3*arrow->triangle_length, arrow->triangle_starty - (arrow->triangle_length /2), 3* arrow->triangle_length, arrow->triangle_length * 2, BG_COLOR);
    }
    else if (arrow->arrow_type == UP_ARROW) {
      gl_draw_rect(arrow->triangle_startx - (arrow->triangle_length), arrow->triangle_starty, 2* arrow->triangle_length, arrow->triangle_length * 3 + 5, BG_COLOR);
    }
    else if (arrow->arrow_type == DOWN_ARROW) {
      gl_draw_rect(arrow->triangle_startx - (arrow->triangle_length), arrow->triangle_starty - 3*arrow->triangle_length,2* arrow->triangle_length, arrow->triangle_length * 3 + 5, BG_COLOR);
    }  
    
    gl_draw_arrow(arrow);
    if(arrow->should_show == false) {
        gl_swap_buffer();
	gl_draw_arrow(arrow);
        gl_swap_buffer();
    }
  }
  // must redraw all ghost arrows upon each scroll call
  arrow_state* left_ghost = ghost_arrow(LEFT_ARROW);
  arrow_state* right_ghost = ghost_arrow(RIGHT_ARROW);
  arrow_state* up_ghost = ghost_arrow(UP_ARROW);
  arrow_state* down_ghost = ghost_arrow(DOWN_ARROW);
  gl_draw_arrow(left_ghost);
  gl_draw_arrow(right_ghost);
  gl_draw_arrow(up_ghost);
  gl_draw_arrow(down_ghost);
  free(left_ghost);
  free(right_ghost);
  free(up_ghost);
  free(down_ghost);
  
  gl_swap_buffer();
}
