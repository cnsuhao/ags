/*         ______   ___    ___
 *        /\  _  \ /\_ \  /\_ \
 *        \ \ \L\ \\//\ \ \//\ \      __     __   _ __   ___
 *         \ \  __ \ \ \ \  \ \ \   /'__`\ /'_ `\/\`'__\/ __`\
 *          \ \ \/\ \ \_\ \_ \_\ \_/\  __//\ \L\ \ \ \//\ \L\ \
 *           \ \_\ \_\/\____\/\____\ \____\ \____ \ \_\\ \____/
 *            \/_/\/_/\/____/\/____/\/____/\/___L\ \/_/ \/___/
 *                                           /\____/
 *                                           \_/__/
 *
 *      24 bit color sprite drawing functions.
 *
 *      By Michael Bukin.
 *
 *      See readme.txt for copyright information.
 */


#include "sdlwrap/allegro.h"
typedef  ALW_BITMAP BITMAP;
typedef ALW_COLOR_MAP COLOR_MAP;
#define AL_CONST const
#include <assert.h>
#define ASSERT assert

#ifdef ALLEGRO_COLOR24

//#include "allegro/internal/aintern.h"
#include "cdefs24.h"
#include "cspr.h"

#endif
