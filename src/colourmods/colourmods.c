#include "colourmods.h"
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
  colour->format[FR] = R;
  colour->format[FB] = B;
  colour->format[FG] = G;
  colour->format[FCID] = 5;
}

void setbgcolour24(colour24 *colour, unsigned char R, unsigned char G,
                   unsigned char B) {
  colour->format[BR] = R;
  colour->format[BB] = B;
  colour->format[BG] = G;
  colour->format[BCID] = 5;
}

void setcolour24(colour24 *colour, unsigned char BR, unsigned char BG,
                 unsigned char BB, unsigned char FR, unsigned char FG,
                 unsigned char FB) {
  colour->format[BR] = BR;
  colour->format[BB] = BB;
  colour->format[BG] = BG;
  colour->format[BCID] = 5;
  colour->format[FR] = FR;
  colour->format[FB] = FB;
  colour->format[FG] = FG;
  colour->format[FCID] = 5;
}

void resetfg24(colour24 *colour) { colour->format[FCID] = 0; }

void resetbg24(colour24 *colour) { colour->format[BCID] = 0; }