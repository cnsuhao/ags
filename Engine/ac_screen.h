#ifndef _AC_SCREEN_H_HEADER
#define _AC_SCREEN_H_HEADER

#include "allegro.h"  // for PALETTE

extern void my_fade_out(int spdd);
extern void my_fade_in(PALETTE p, int speed) ;

extern void register_screen_script_functions();

#endif
