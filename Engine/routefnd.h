#ifndef _ROUTEFND_H_HEADER
#define _ROUTEFND_H_HEADER

// forward declarations:
#include "allegro.h"        // for BITMAP
typedef BITMAP *block;      // wgt2allh.h

extern int route_script_link();
extern int find_route(short , short , short , short , block , int , int, int);
extern void print_welcome_text(char*,char*);

#endif