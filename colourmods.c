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