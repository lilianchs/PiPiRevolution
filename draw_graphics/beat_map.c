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
// This file contains the format for beat maps to be encoded.
void scroll(arrow_state** arrow_list, int num) {
    for(int i = 0; i < num; i++) {
        scroll_screen(arrow_list);
    }
}

// Song 1
void babydoll_map(void) {
    arrow_state** arrow_list = (struct arrow_state**)malloc(6 * sizeof(struct arrow_state*));
    timer_delay(2);
    arrow_state* arrow_1 = (arrow_state*) gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_1;
    scroll(arrow_list, 45);
    arrow_state* arrow_2 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_2;
    scroll(arrow_list, 45);
    arrow_state* arrow_3 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_3;
    scroll(arrow_list, 90);
    arrow_state* arrow_4 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_4;
    scroll(arrow_list, 90);
    arrow_state* arrow_5 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_5;
    scroll(arrow_list, 45);
    arrow_state* arrow_6 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_6;
    scroll(arrow_list, 135);
    free(arrow_1);
    arrow_state* arrow_7 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_7;
    scroll(arrow_list, 90);
    free(arrow_2);
    arrow_state* arrow_8 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_8;
    scroll(arrow_list, 45);
    free(arrow_3);
    arrow_state* arrow_9 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_9;
    scroll(arrow_list, 45);
    free(arrow_4);
    arrow_state* arrow_10 = gl_make_new_arrow(RIGHT_ARROW,GL_BLUE);
    arrow_list[3] = arrow_10;
    scroll(arrow_list, 90);
    free(arrow_5);
    arrow_state* arrow_11 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_11;
    scroll(arrow_list, 80);
    free(arrow_6);
    arrow_state* arrow_12 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_12;
    scroll(arrow_list, 60);
    free(arrow_7);
    arrow_state* arrow_13 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_13;
    scroll(arrow_list, 40);
    free(arrow_8);
    arrow_state* arrow_14 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_14;
    scroll(arrow_list, 40);
    free(arrow_9);
    arrow_state* arrow_15 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_15;
    scroll(arrow_list, 80);
    free(arrow_10);
    arrow_state* arrow_16 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_16;
    scroll(arrow_list, 45);
    free(arrow_11);
    arrow_state* arrow_17 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_17;
    scroll(arrow_list, 90);
    free(arrow_12);
    arrow_state* arrow_18 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_18;
    scroll(arrow_list, 90);
    free(arrow_13);
    arrow_state* arrow_19 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_19;
    scroll(arrow_list, 60);
    free(arrow_14);
    arrow_state* arrow_20 = gl_make_new_arrow(DOWN_ARROW,GL_BLUE);
    arrow_list[1] = arrow_20;
    scroll(arrow_list, 60);
    free(arrow_15);
    arrow_state* arrow_21 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_21;
    scroll(arrow_list, 80);
    free(arrow_16);
    arrow_state* arrow_22 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_22;
    scroll(arrow_list, 45);
    free(arrow_17);
    arrow_state* arrow_23 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_23;
    scroll(arrow_list, 45);
    free(arrow_18);
    arrow_state* arrow_24 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_24;
    scroll(arrow_list, 100);
    free(arrow_19);
    arrow_state* arrow_25 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_25;
    scroll(arrow_list, 30);
    free(arrow_20);
    arrow_state* arrow_26 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_26;
    scroll(arrow_list, 30);
    free(arrow_21);
    arrow_state* arrow_27 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_27;
    scroll(arrow_list, 60);
    free(arrow_22);
    arrow_state* arrow_28 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_28;
    scroll(arrow_list, 120);
    free(arrow_23);
    arrow_state* arrow_29 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_29;
    scroll(arrow_list, 30);
    free(arrow_24);
    arrow_state* arrow_30 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_30;
    scroll(arrow_list, 60);

    free(arrow_25);
    arrow_state* arrow_31 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_31;
    scroll(arrow_list, 45);
    free(arrow_26);
    arrow_state* arrow_32 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_32;
    scroll(arrow_list, 45);
    free(arrow_27);
    arrow_state* arrow_33 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_33;
    scroll(arrow_list, 90);
    free(arrow_28);
    arrow_state* arrow_34 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_34;
    scroll(arrow_list, 90);
    free(arrow_29);
    arrow_state* arrow_35 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_35;
    scroll(arrow_list, 45);
    free(arrow_30);
    arrow_state* arrow_36 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_36;
    scroll(arrow_list, 60);

    free(arrow_31);
    arrow_state* arrow_37 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_37;
    scroll(arrow_list, 90);
    free(arrow_32);
    arrow_state* arrow_38 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_38;
    scroll(arrow_list, 60);
    free(arrow_33);
    arrow_state* arrow_39 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_39;
    scroll(arrow_list, 60);
    free(arrow_34);
    arrow_state* arrow_40 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_40;
    scroll(arrow_list, 45);
    free(arrow_35);
    arrow_state* arrow_41 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_41;
    scroll(arrow_list, 30);
    free(arrow_36);
    arrow_state* arrow_42 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_42;
    scroll(arrow_list, 90);
    free(arrow_37);
    arrow_state* arrow_43 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_43;
    scroll(arrow_list, 80);
    free(arrow_38);
    arrow_state* arrow_44 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_44;
    scroll(arrow_list, 40);
    free(arrow_39);
    arrow_state* arrow_45 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_45;
    scroll(arrow_list, 120);
    free(arrow_40);
    arrow_state* arrow_46 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_46;
    scroll(arrow_list, 45);
    free(arrow_41);
    arrow_state* arrow_47 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_47;
    scroll(arrow_list, 45);
    free(arrow_42);
    arrow_state* arrow_48 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_48;
    scroll(arrow_list, 60);
    free(arrow_43);
    arrow_state* arrow_49 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_49;
    scroll(arrow_list, 60);
    free(arrow_44);
    arrow_state* arrow_50 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_50;
    scroll(arrow_list, 90);
    free(arrow_45);
    arrow_state* arrow_51 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_51;
    scroll(arrow_list, 90);
    free(arrow_46);
    arrow_state* arrow_52 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_52;
    scroll(arrow_list, 120);
    free(arrow_47);
    arrow_state* arrow_53 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_53;
    scroll(arrow_list, 45);
    free(arrow_48);
    arrow_state* arrow_54 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_54;
    scroll(arrow_list, 120);
    free(arrow_49);
    arrow_state* arrow_55 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_55;
    scroll(arrow_list, 60);
    free(arrow_50);

    arrow_state* arrow_56 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_56;
    scroll(arrow_list, 80);
    free(arrow_51);
    arrow_state* arrow_57 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_57;
    scroll(arrow_list, 60);
    free(arrow_52);

    arrow_state* arrow_58 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_58;
    scroll(arrow_list, 120);
    free(arrow_53);

    arrow_state* arrow_59 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_59;
    scroll(arrow_list, 80);
    free(arrow_54);

    arrow_state* arrow_60 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_60;
    scroll(arrow_list, 90);
    free(arrow_55);

    arrow_state* arrow_61 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_61;
    scroll(arrow_list, 90);
    free(arrow_56);

    arrow_state* arrow_62 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_62;
    scroll(arrow_list, 30);
    free(arrow_57);

    arrow_state* arrow_63 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_63;
    scroll(arrow_list, 120);
    free(arrow_58);

    arrow_state* arrow_64 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_64;
    scroll(arrow_list, 60);
    free(arrow_59);

    arrow_state* arrow_65 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_65;
    scroll(arrow_list, 60);
    free(arrow_60);

    arrow_state* arrow_66 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_66;
    scroll(arrow_list, 120);
    free(arrow_61);

    arrow_state* arrow_67 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_67;
    scroll(arrow_list, 30);
    free(arrow_62);

    arrow_state* arrow_68 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_68;
    scroll(arrow_list, 30);
    free(arrow_63);

    arrow_state* arrow_69 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_69;
    scroll(arrow_list, 30);
    free(arrow_64);

    arrow_state* arrow_70 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_70;
    scroll(arrow_list, 60);
    free(arrow_65);

    arrow_state* arrow_71 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_71;
    scroll(arrow_list, 120);
    free(arrow_66);

    arrow_state* arrow_72 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_72;
    scroll(arrow_list, 30);
    free(arrow_67);

    arrow_state* arrow_73 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_73;
    scroll(arrow_list, 60);
    free(arrow_68);

    arrow_state* arrow_74 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_74;
    scroll(arrow_list, 45);
    free(arrow_69);

    arrow_state* arrow_75 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_75;
    scroll(arrow_list, 120);
    free(arrow_70);


    arrow_state* arrow_76 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_76;
    scroll(arrow_list, 60);
    free(arrow_71);

    arrow_state* arrow_77 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_77;
    scroll(arrow_list, 60);
    free(arrow_72);

    arrow_state* arrow_78 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_78;
    scroll(arrow_list, 90);
    free(arrow_73);

    arrow_state* arrow_79 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_79;
    scroll(arrow_list, 40);
    free(arrow_74);

    arrow_state* arrow_80 = gl_make_new_arrow(LEFT_ARROW,GL_BLUE);
    arrow_list[1] = arrow_80;
    scroll(arrow_list, 420);
    free(arrow_75);
    /*
    arrow_state* arrow_81 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_81;
    scroll(arrow_list, 90);
    free(arrow_76);

    arrow_state* arrow_82 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_82;
    scroll(arrow_list, 60);
    free(arrow_77);

    arrow_state* arrow_83 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_83;
    scroll(arrow_list, 60);
    free(arrow_78);

    arrow_state* arrow_84 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_84;
    scroll(arrow_list, 60);
    free(arrow_79);
    */
    for(int i = 0; i < 6; i++) {
        free(arrow_list[i]);
    }
    free(arrow_list);
}

void promiscuous_map() {
    printf("HEYYY");
    arrow_state** arrow_list = (struct arrow_state**)malloc(6 * sizeof(struct arrow_state*));
    timer_delay(2);
    printf("HERE NOW");
    arrow_state* arrow_1 = (arrow_state*) gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA); 
    printf("THEM EHRE");
    arrow_list[0] = arrow_1;
    scroll(arrow_list, 60);
    arrow_state* arrow_2 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_2;
    scroll(arrow_list, 160);
    arrow_state* arrow_3 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_3;
    scroll(arrow_list, 40);
    arrow_state* arrow_4 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_4;
    scroll(arrow_list, 40);
    arrow_state* arrow_5 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_5;
    scroll(arrow_list, 65);
    arrow_state* arrow_6 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_6;
    scroll(arrow_list, 40);
    free(arrow_1);
    arrow_state* arrow_7 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_7;
    scroll(arrow_list, 80);
    free(arrow_2);
    arrow_state* arrow_8 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_8;
    scroll(arrow_list, 120);
    free(arrow_3);
    arrow_state* arrow_9 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_9;
    scroll(arrow_list, 40);
    free(arrow_4);
    arrow_state* arrow_10 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_10;
    scroll(arrow_list, 35);
    free(arrow_5);
    arrow_state* arrow_11 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_11;
    scroll(arrow_list, 100);
    free(arrow_6);
    arrow_state* arrow_12 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_12;
    scroll(arrow_list, 60);
    free(arrow_7);
    arrow_state* arrow_13 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_13;
    scroll(arrow_list, 120);
    free(arrow_8);
    arrow_state* arrow_14 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_14;
    scroll(arrow_list, 120); 
    free(arrow_9);
    arrow_state* arrow_15 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_15;
    scroll(arrow_list, 25);
    free(arrow_10);
    arrow_state* arrow_16 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_16;
    scroll(arrow_list, 75);
    free(arrow_11);
    arrow_state* arrow_17 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_17;
    scroll(arrow_list, 100);
    free(arrow_12);
    arrow_state* arrow_18 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_18;
    scroll(arrow_list, 60);
    free(arrow_13);
    arrow_state* arrow_19 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_19;
    scroll(arrow_list, 30);
    free(arrow_14);
    arrow_state* arrow_20 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_20;
    scroll(arrow_list, 105);
    free(arrow_15);
    arrow_state* arrow_21 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_21;
    scroll(arrow_list, 80);
    free(arrow_16);
    arrow_state* arrow_22 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_22;
    scroll(arrow_list, 60);
    free(arrow_17);
    arrow_state* arrow_23 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_23;
    scroll(arrow_list, 160);
    free(arrow_18);
    arrow_state* arrow_24 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_24;
    scroll(arrow_list, 170); 
    free(arrow_19);
    arrow_state* arrow_25 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_25;
    scroll(arrow_list, 25);
    free(arrow_20);
    arrow_state* arrow_26 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA); 
    arrow_list[1] = arrow_26;
    scroll(arrow_list, 95);
    free(arrow_21);
    arrow_state* arrow_27 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_27;
    scroll(arrow_list, 80);
    free(arrow_22);
    arrow_state* arrow_28 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_28;
    scroll(arrow_list, 60);
    free(arrow_23);
    arrow_state* arrow_29 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_29;
    scroll(arrow_list, 80);
    free(arrow_24);
    arrow_state* arrow_30 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_30;
    scroll(arrow_list, 80);
    
    free(arrow_25);
    arrow_state* arrow_31 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_31;
    scroll(arrow_list, 40);
    free(arrow_26);
    arrow_state* arrow_32 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_32;
    scroll(arrow_list, 80);
    free(arrow_27);
    arrow_state* arrow_33 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_33;
    scroll(arrow_list, 120);
    free(arrow_28);
    arrow_state* arrow_34 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_34;
    scroll(arrow_list, 60);
    free(arrow_29);
    arrow_state* arrow_35 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_35;
    scroll(arrow_list, 80);
    free(arrow_30);
    arrow_state* arrow_36 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_36;
    scroll(arrow_list, 100);
 
    free(arrow_31);
    arrow_state* arrow_37 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_37;
    scroll(arrow_list, 15);
    free(arrow_32);
    arrow_state* arrow_38 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_38;
    scroll(arrow_list, 125);
    free(arrow_33);
    arrow_state* arrow_39 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_39;
    scroll(arrow_list, 50);
    free(arrow_34);
    arrow_state* arrow_40 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_40;
    scroll(arrow_list, 150);
    free(arrow_35);
    arrow_state* arrow_41 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_41;
    scroll(arrow_list, 30);
    free(arrow_36);
    arrow_state* arrow_42 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_42;
    scroll(arrow_list, 100);
    free(arrow_37);
    arrow_state* arrow_43 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_43;
    scroll(arrow_list, 80);
    free(arrow_38);
    arrow_state* arrow_44 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_44;
    scroll(arrow_list, 40);
    free(arrow_39);
    arrow_state* arrow_45 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_45;
    scroll(arrow_list, 100);
    free(arrow_40);
    arrow_state* arrow_46 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_46;
    scroll(arrow_list, 110);
    free(arrow_41);
    arrow_state* arrow_47 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_47;
    scroll(arrow_list, 160);
    free(arrow_42);
    arrow_state* arrow_48 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_48;
    scroll(arrow_list, 130);
    free(arrow_43);
    arrow_state* arrow_49 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_49;
    scroll(arrow_list, 80);
    free(arrow_44);
    arrow_state* arrow_50 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_50;
    scroll(arrow_list, 100);
    free(arrow_45);
    arrow_state* arrow_51 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_51;
    scroll(arrow_list, 90);
    free(arrow_46);
    arrow_state* arrow_52 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_52;
    scroll(arrow_list, 90);
    free(arrow_47);
    arrow_state* arrow_53 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_53;
    scroll(arrow_list, 90);
    free(arrow_48);
    arrow_state* arrow_54 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_54;
    scroll(arrow_list, 100);
    free(arrow_49);
    arrow_state* arrow_55 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_55;
    scroll(arrow_list, 40);
    free(arrow_50);

    arrow_state* arrow_56 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_56;
    scroll(arrow_list, 80);
    free(arrow_51);

    arrow_state* arrow_57 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_57;
    scroll(arrow_list, 60);
    free(arrow_52);

    arrow_state* arrow_58 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_58;
    scroll(arrow_list, 80);
    free(arrow_53);

    arrow_state* arrow_59 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_59;
    scroll(arrow_list, 80);
    free(arrow_54);

    arrow_state* arrow_60 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_60;
    scroll(arrow_list, 50);
    free(arrow_55);

    arrow_state* arrow_61 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_61;
    scroll(arrow_list, 90);
    free(arrow_56);

    arrow_state* arrow_62 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_62;
    scroll(arrow_list, 30);
    free(arrow_57);

    arrow_state* arrow_63 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_63;
    scroll(arrow_list, 100);
    free(arrow_58);

    arrow_state* arrow_64 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_64;
    scroll(arrow_list, 60);
    free(arrow_59);

    arrow_state* arrow_65 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_65;
    scroll(arrow_list, 120);
    free(arrow_60);

    arrow_state* arrow_66 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_66;
    scroll(arrow_list, 50);
    free(arrow_61);

    arrow_state* arrow_67 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_67;
    scroll(arrow_list, 70);
    free(arrow_62);

    arrow_state* arrow_68 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_68;
    scroll(arrow_list, 90);
    free(arrow_63);

    arrow_state* arrow_69 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_69;
    scroll(arrow_list, 80);
    free(arrow_64);

    arrow_state* arrow_70 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_70;
    scroll(arrow_list, 60);
    free(arrow_65);

    arrow_state* arrow_71 = gl_make_new_arrow(UP_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_71;
    scroll(arrow_list, 100);
    free(arrow_66);

    arrow_state* arrow_72 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_72;
    scroll(arrow_list, 60);
    free(arrow_67);

    arrow_state* arrow_73 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_73;
    scroll(arrow_list, 90);
    free(arrow_68);

    arrow_state* arrow_74 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_74;
    scroll(arrow_list, 60);
    free(arrow_69);

    arrow_state* arrow_75 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_75;
    scroll(arrow_list, 90);
    free(arrow_70);


    arrow_state* arrow_76 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_76;
    scroll(arrow_list, 60);
    free(arrow_71);

    arrow_state* arrow_77 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[4] = arrow_77;
    scroll(arrow_list, 50);
    free(arrow_72);

    arrow_state* arrow_78 = gl_make_new_arrow(DOWN_ARROW,GL_MAGENTA);
    arrow_list[5] = arrow_78;
    scroll(arrow_list, 90);
    free(arrow_73);

    arrow_state* arrow_79 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[0] = arrow_79;
    scroll(arrow_list, 70);
    free(arrow_74);

    arrow_state* arrow_80 = gl_make_new_arrow(LEFT_ARROW,GL_MAGENTA);
    arrow_list[1] = arrow_80;
    scroll(arrow_list, 70);
    free(arrow_75);

    arrow_state* arrow_81 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[2] = arrow_81;
    scroll(arrow_list, 70);
    free(arrow_76);

    arrow_state* arrow_82 = gl_make_new_arrow(RIGHT_ARROW,GL_MAGENTA);
    arrow_list[3] = arrow_82;
    scroll(arrow_list, 420);
    free(arrow_77);

    for(int i = 0; i < 6; i++) {
        free(arrow_list[i]);
    }
    free(arrow_list);
}
