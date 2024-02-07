#include "../include/colourmods.h"
#include <stdlib.h>
/*
  Remeber that basic_colour is just unsigned char
*/
basic_colour getfg(basic_colour colour) {
  basic_colour fg = colour & 0xF;
  fg += fg < 8 ? 30 : 82;
  return fg;
}

basic_colour getbg(basic_colour colour) {
  basic_colour bg = colour >> 4;
  bg += bg < 8 ? 40 : 92;
  return bg;
}

basic_colour getbasic_colour(enum colour_index BG, enum colour_index FG) {
  return 16 * BG + FG;
}

void setfgcolour24(colour24 *colour, unsigned char R, unsigned char G,
                   unsigned char B) {
  *colour[FR] = R;
  *colour[FB] = B;
  *colour[FG] = G;
  *colour[FCID] = 5;
}

void setbgcolour24(colour24 *colour, unsigned char R, unsigned char G,
                   unsigned char B) {
  *colour[BR] = R;
  *colour[BB] = B;
  *colour[BG] = G;
  *colour[BCID] = 5;
}

void setcolour24(colour24 colour, unsigned char _BR, unsigned char _BG,
                 unsigned char _BB, unsigned char _FR, unsigned char _FG,
                 unsigned char _FB) {
  colour[BR] = _BR;
  colour[BB] = _BB;
  colour[BG] = _BG;
  colour[BCID] = 5;
  colour[FR] = _FR;
  colour[FB] = _FB;
  colour[FG] = _FG;
  colour[FCID] = 5;
}
