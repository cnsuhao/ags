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
 *      Blitting functions.
 *
 *      By Shawn Hargreaves.
 *
 *      Dithering code by James Hyman.
 *
 *      Transparency preserving code by Elias Pschernig.
 *
 *      See readme.txt for copyright information.
 */


#include <string.h>
#include "allegro.h"
//#include "allegro/internal/aintern.h"
#include "alw_to_allegro.h"



int _bestfit_color_for_current_palette(int r, int g, int b) {
  //return bestfit_color(_current_palette, r, g, b);
  return 0;
}

int _tmp_lookup_table[255] = {0};
int *_palette_expansion_table(int color_depth) {
  return _tmp_lookup_table;
}


extern void _linear_blit8(ALW_BITMAP *src, ALW_BITMAP *dst, int sx, int sy, int dx, int dy, int w, int h);
extern void _linear_blit16(ALW_BITMAP *src, ALW_BITMAP *dst, int sx, int sy, int dx, int dy, int w, int h);
extern void _linear_blit24(ALW_BITMAP *src, ALW_BITMAP *dst, int sx, int sy, int dx, int dy, int w, int h);
extern void _linear_blit32(ALW_BITMAP *src, ALW_BITMAP *dst, int sx, int sy, int dx, int dy, int w, int h);

extern void _linear_blit_backward8(ALW_BITMAP *src, ALW_BITMAP *dst, int sx, int sy, int dx, int dy, int w, int h);
extern void _linear_blit_backward16(ALW_BITMAP *src, ALW_BITMAP *dst, int sx, int sy, int dx, int dy, int w, int h);
extern void _linear_blit_backward24(ALW_BITMAP *src, ALW_BITMAP *dst, int sx, int sy, int dx, int dy, int w, int h);
extern void _linear_blit_backward32(ALW_BITMAP *src, ALW_BITMAP *dst, int sx, int sy, int dx, int dy, int w, int h);


// blit other thing to THIS, in this format
static void _vtable_blit_to_self(int for_depth, BITMAP *src, BITMAP *dest, int s_x, int s_y, int d_x, int d_y, int w, int h) {
  switch (for_depth) {
    case 8: _linear_blit8(src, dest, s_x, s_y, d_x, d_y, w, h); break;
    case 15:_linear_blit16(src, dest, s_x, s_y, d_x, d_y, w, h); break;
    case 16:_linear_blit16(src, dest, s_x, s_y, d_x, d_y, w, h); break;
    case 24:_linear_blit24(src, dest, s_x, s_y, d_x, d_y, w, h); break;
    case 32:_linear_blit32(src, dest, s_x, s_y, d_x, d_y, w, h); break;
  }
}


static void _vtable_blit_to_self_forward(int for_depth, BITMAP *src, BITMAP *dest, int s_x, int s_y, int d_x, int d_y, int w, int h) {
  switch (for_depth) {
    case 8: _linear_blit8(src, dest, s_x, s_y, d_x, d_y, w, h); break;
    case 15:_linear_blit16(src, dest, s_x, s_y, d_x, d_y, w, h); break;
    case 16:_linear_blit16(src, dest, s_x, s_y, d_x, d_y, w, h); break;
    case 24:_linear_blit24(src, dest, s_x, s_y, d_x, d_y, w, h); break;
    case 32:_linear_blit32(src, dest, s_x, s_y, d_x, d_y, w, h); break;
  }
}

static void _vtable_blit_to_self_backward(int for_depth, BITMAP *src, BITMAP *dest, int s_x, int s_y, int d_x, int d_y, int w, int h) {
  switch (for_depth) {
    case 8: _linear_blit_backward8(src, dest, s_x, s_y, d_x, d_y, w, h); break;
    case 15:_linear_blit_backward16(src, dest, s_x, s_y, d_x, d_y, w, h); break;
    case 16:_linear_blit_backward16(src, dest, s_x, s_y, d_x, d_y, w, h); break;
    case 24:_linear_blit_backward24(src, dest, s_x, s_y, d_x, d_y, w, h); break;
    case 32:_linear_blit_backward32(src, dest, s_x, s_y, d_x, d_y, w, h); break;
  }
}





/* get_replacement_mask_color:
 *  Helper function to get a replacement color for the bitmap's mask color.
 */
static int get_replacement_mask_color(BITMAP *bmp)
{
  int depth, c, g = 0;
  
  depth = bitmap_color_depth(bmp);
  
  if (depth == 8) {
    //return bestfit_color(_current_palette, 63, 1, 63);
    return _bestfit_color_for_current_palette(63, 1, 63);
  }
  else {
    do
      c = makecol_depth(depth, 255, ++g, 255);
    while (c == bitmap_mask_color(bmp));
    
    return c;
  }
}



/* blit_from_256:
 *  Expands 256 color images onto a truecolor destination.
 */
static void blit_from_256(BITMAP *src, BITMAP *dest, int s_x, int s_y, int d_x, int d_y, int w, int h)
{
#ifdef ALLEGRO_COLOR8
  
  int *dest_palette_color;
  uintptr_t s, d;
  unsigned char *ss;
  int x, y, c, rc;
  
  /* lookup table avoids repeated color format conversions */
  dest_palette_color = _palette_expansion_table(bitmap_color_depth(dest));
  
  /* worker macro */
#define EXPAND_BLIT(bits, dsize)                                          \
{                                                                         \
if (is_memory_bitmap(src)) {                                           \
/* fast version when reading from memory bitmap */                  \
bmp_select(dest);                                                   \
\
for (y=0; y<h; y++) {                                               \
ss = src->line[s_y+y] + s_x;                                     \
d = bmp_write_line(dest, d_y+y) + d_x*dsize;                     \
\
for (x=0; x<w; x++) {                                            \
bmp_write##bits(d, dest_palette_color[*ss]);                  \
ss++;                                                         \
d += dsize;                                                   \
}                                                                \
}                                                                   \
\
bmp_unwrite_line(dest);                                             \
}                                                                      \
else {                                                                 \
/* slower version when reading from the screen */                   \
for (y=0; y<h; y++) {                                               \
s = bmp_read_line(src, s_y+y) + s_x;                             \
d = bmp_write_line(dest, d_y+y) + d_x*dsize;                     \
\
for (x=0; x<w; x++) {                                            \
bmp_select(src);                                              \
c = bmp_read8(s);                                             \
\
bmp_select(dest);                                             \
bmp_write##bits(d, dest_palette_color[c]);                    \
\
s++;                                                          \
d += dsize;                                                   \
}                                                                \
}                                                                   \
\
bmp_unwrite_line(src);                                              \
bmp_unwrite_line(dest);                                             \
}                                                                      \
}
  
  /* expand the above macro for each possible output depth */
  switch (bitmap_color_depth(dest)) {
      
#ifdef ALLEGRO_COLOR16
    case 15:
    case 16:
      EXPAND_BLIT(16, sizeof(int16_t));
      break;
#endif
      
#ifdef ALLEGRO_COLOR24
    case 24:
      EXPAND_BLIT(24, 3);
      break;
#endif
      
#ifdef ALLEGRO_COLOR32
    case 32:
      EXPAND_BLIT(32, sizeof(int32_t));
      break;
#endif
  }
  
#endif
}



/* worker macro for converting between two color formats, possibly with dithering */
#define CONVERT_BLIT_EX(sbits, ssize, dbits, dsize, MAKECOL)                 \
{                                                                            \
{                                                                    \
for (y=0; y<h; y++) {                                                  \
s = bmp_read_line(src, s_y+y) + s_x*ssize;                          \
d = bmp_write_line(dest, d_y+y) + d_x*dsize;                        \
\
for (x=0; x<w; x++) {                                               \
bmp_select(src);                                                 \
c = bmp_read##sbits(s);                                          \
\
r = getr##sbits(c);                                              \
g = getg##sbits(c);                                              \
b = getb##sbits(c);                                              \
\
bmp_select(dest);                                                \
bmp_write##dbits(d, MAKECOL);                                    \
\
s += ssize;                                                      \
d += dsize;                                                      \
}                                                                   \
}                                                                      \
}                                                                         \
\
bmp_unwrite_line(src);                                                    \
bmp_unwrite_line(dest);                                                   \
}

#define CONVERT_BLIT(sbits, ssize, dbits, dsize) \
CONVERT_BLIT_EX(sbits, ssize, dbits, dsize, makecol##dbits(r, g, b))







/* blit_from_15:
 *  Converts 15 bpp images onto some other destination format.
 */
static void blit_from_15(BITMAP *src, BITMAP *dest, int s_x, int s_y, int d_x, int d_y, int w, int h)
{
#ifdef ALLEGRO_COLOR16
  
  int x, y, c, r, g, b;
  uintptr_t s, d;
  
  switch (bitmap_color_depth(dest)) {
      
#ifdef ALLEGRO_COLOR8
    case 8:
        CONVERT_BLIT(15, sizeof(int16_t), 8, 1)
        break;
#endif
      
    case 16:
      CONVERT_BLIT(15, sizeof(int16_t), 16, sizeof(int16_t))
      break;
      
#ifdef ALLEGRO_COLOR24
    case 24:
      CONVERT_BLIT(15, sizeof(int16_t), 24, 3)
      break;
#endif
      
#ifdef ALLEGRO_COLOR32
    case 32:
      CONVERT_BLIT(15, sizeof(int16_t), 32, sizeof(int32_t))
      break;
#endif
  }
  
#endif
}



/* blit_from_16:
 *  Converts 16 bpp images onto some other destination format.
 */
static void blit_from_16(BITMAP *src, BITMAP *dest, int s_x, int s_y, int d_x, int d_y, int w, int h)
{
#ifdef ALLEGRO_COLOR16
  
  int x, y, c, r, g, b;
  uintptr_t s, d;
  
  switch (bitmap_color_depth(dest)) {
      
#ifdef ALLEGRO_COLOR8
    case 8:
        CONVERT_BLIT(16, sizeof(int16_t), 8, 1)
        break;
#endif
      
    case 15:
      CONVERT_BLIT(16, sizeof(int16_t), 15, sizeof(int16_t))
      break;
      
#ifdef ALLEGRO_COLOR24
    case 24:
      CONVERT_BLIT(16, sizeof(int16_t), 24, 3)
      break;
#endif
      
#ifdef ALLEGRO_COLOR32
    case 32:
      CONVERT_BLIT(16, sizeof(int16_t), 32, sizeof(int32_t))
      break;
#endif
  }
  
#endif 
}



/* blit_from_24:
 *  Converts 24 bpp images onto some other destination format.
 */
static void blit_from_24(BITMAP *src, BITMAP *dest, int s_x, int s_y, int d_x, int d_y, int w, int h)
{
#ifdef ALLEGRO_COLOR24
  
  int x, y, c, r, g, b;
  uintptr_t s, d;
  
  switch (bitmap_color_depth(dest)) {
      
#ifdef ALLEGRO_COLOR8
    case 8:
        CONVERT_BLIT(24, 3, 8, 1);
      break;
#endif
      
#ifdef ALLEGRO_COLOR16
    case 15:

          CONVERT_BLIT(24, 3, 15, sizeof(int16_t))
          break;
      
    case 16:

          CONVERT_BLIT(24, 3, 16, sizeof(int16_t))
          break;
#endif
      
#ifdef ALLEGRO_COLOR32
    case 32:
      CONVERT_BLIT(24, 3, 32, sizeof(int32_t))
      break;
#endif
  }
  
#endif 
}



/* blit_from_32:
 *  Converts 32 bpp images onto some other destination format.
 */
static void blit_from_32(BITMAP *src, BITMAP *dest, int s_x, int s_y, int d_x, int d_y, int w, int h)
{
#ifdef ALLEGRO_COLOR32
  
  int x, y, c, r, g, b;
  uintptr_t s, d;
  
  switch (bitmap_color_depth(dest)) {
      
#ifdef ALLEGRO_COLOR8
    case 8:
        CONVERT_BLIT(32, sizeof(int32_t), 8, 1)
        break;
#endif
      
#ifdef ALLEGRO_COLOR16
    case 15:

          CONVERT_BLIT(32, sizeof(int32_t), 15, sizeof(int16_t))
          break;
      
    case 16:

          CONVERT_BLIT(32, sizeof(int32_t), 16, sizeof(int16_t))
          break;
#endif
      
#ifdef ALLEGRO_COLOR24
    case 24:
      CONVERT_BLIT(32, sizeof(int32_t), 24, 3)
      break;
#endif
  }
  
#endif 
}






/* blit_between_formats:
 *  Blits an (already clipped) region between two bitmaps of different
 *  color depths, doing the appopriate format conversions.
 */
void _blit_between_formats(BITMAP *src, BITMAP *dest, int s_x, int s_y, int d_x, int d_y, int w, int h)
{
 {
    switch (bitmap_color_depth(src)) {
        
      case 8:
        blit_from_256(src, dest, s_x, s_y, d_x, d_y, w, h);
        break;
        
      case 15:
        blit_from_15(src, dest, s_x, s_y, d_x, d_y, w, h);
        break;
        
      case 16:
        blit_from_16(src, dest, s_x, s_y, d_x, d_y, w, h);
        break;
        
      case 24:
        blit_from_24(src, dest, s_x, s_y, d_x, d_y, w, h);
        break;
        
      case 32:
        blit_from_32(src, dest, s_x, s_y, d_x, d_y, w, h);
        break;
    }
  }
}



/* blit_to_self:
 *  Blits an (already clipped) region between two areas of the same bitmap,
 *  checking which way around to do the blit.
 */
static void blit_to_self(BITMAP *src, BITMAP *dest, int s_x, int s_y, int d_x, int d_y, int w, int h)
{
  unsigned long sx, sy, dx, dy;
  BITMAP *tmp;
  
  {
    /* check which way round to do the blit */
    sx = s_x + src->x_ofs;
    sy = s_y + src->y_ofs;
    
    dx = d_x + dest->x_ofs;
    dy = d_y + dest->y_ofs;
    
    if ((sx+w <= dx) || (dx+w <= sx) || (sy+h <= dy) || (dy+h <= sy))
      _vtable_blit_to_self(alw_bitmap_color_depth(dest), src, dest, s_x, s_y, d_x, d_y, w, h);
    else if ((sy > dy) || ((sy == dy) && (sx > dx)))
      _vtable_blit_to_self_forward(alw_bitmap_color_depth(dest),src, dest, s_x, s_y, d_x, d_y, w, h);
    else if ((sx != dx) || (sy != dy))
      _vtable_blit_to_self_backward(alw_bitmap_color_depth(dest),src, dest, s_x, s_y, d_x, d_y, w, h);
  }
}



/* helper for clipping a blit rectangle */
#define BLIT_CLIP()                                                          \
/* check for ridiculous cases */                                          \
if ((s_x >= src->w) || (s_y >= src->h) ||                                 \
(d_x >= dest->cr) || (d_y >= dest->cb))                               \
return;                                                                \
\
/* clip src left */                                                       \
if (s_x < 0) {                                                            \
w += s_x;                                                              \
d_x -= s_x;                                                            \
s_x = 0;                                                               \
}                                                                         \
\
/* clip src top */                                                        \
if (s_y < 0) {                                                            \
h += s_y;                                                              \
d_y -= s_y;                                                            \
s_y = 0;                                                               \
}                                                                         \
\
/* clip src right */                                                      \
if (s_x+w > src->w)                                                       \
w = src->w - s_x;                                                      \
\
/* clip src bottom */                                                     \
if (s_y+h > src->h)                                                       \
h = src->h - s_y;                                                      \
\
/* clip dest left */                                                      \
if (d_x < dest->cl) {                                                     \
d_x -= dest->cl;                                                       \
w += d_x;                                                              \
s_x -= d_x;                                                            \
d_x = dest->cl;                                                        \
}                                                                         \
\
/* clip dest top */                                                       \
if (d_y < dest->ct) {                                                     \
d_y -= dest->ct;                                                       \
h += d_y;                                                              \
s_y -= d_y;                                                            \
d_y = dest->ct;                                                        \
}                                                                         \
\
/* clip dest right */                                                     \
if (d_x+w > dest->cr)                                                     \
w = dest->cr - d_x;                                                    \
\
/* clip dest bottom */                                                    \
if (d_y+h > dest->cb)                                                     \
h = dest->cb - d_y;                                                    \
\
/* bottle out if zero size */                                             \
if ((w <= 0) || (h <= 0))                                                 \
return;




/* blit:
 *  Copies an area of the source bitmap to the destination bitmap. s_x and 
 *  s_y give the top left corner of the area of the source bitmap to copy, 
 *  and d_x and d_y give the position in the destination bitmap. w and h 
 *  give the size of the area to blit. This routine respects the clipping 
 *  rectangle of the destination bitmap, and will work correctly even when 
 *  the two memory areas overlap (ie. src and dest are the same). 
 */
void blit(BITMAP *src, BITMAP *dest, int s_x, int s_y, int d_x, int d_y, int w, int h)
{
  ASSERT(src);
  ASSERT(dest);
  BLIT_CLIP();
  
  if (alw_bitmap_color_depth(src) != alw_bitmap_color_depth(dest)) {
    /* need to do a color conversion */
    _blit_between_formats(src, dest, s_x, s_y, d_x, d_y, w, h);
  }
  else if (is_same_bitmap(src, dest)) {
    /* special handling for overlapping regions */
    blit_to_self(src, dest, s_x, s_y, d_x, d_y, w, h);
  }
  else {
    /* drawing onto memory bitmaps */
    _vtable_blit_to_self(alw_bitmap_color_depth(dest), src, dest, s_x, s_y, d_x, d_y, w, h);
  }
}



