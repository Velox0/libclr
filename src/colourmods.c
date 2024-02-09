#include "../include/colourmods.h"
#include "../include/display.h"
#include <stdio.h>
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

void newcolour24(colour24 colour) {
  for (int i = 0; i < 8; i++) {
    if (i != BCID && i != FCID)
      colour[i] = 0;
    else
      colour[i] = 5;
  }
}

void setfgcolour24(colour24 colour, unsigned char R, unsigned char G,
                   unsigned char B) {
  colour[FR] = R;
  colour[FB] = B;
  colour[FG] = G;
  colour[FCID] = 5;
}

void setbgcolour24(colour24 colour, unsigned char R, unsigned char G,
                   unsigned char B) {
  colour[BR] = R;
  colour[BB] = B;
  colour[BG] = G;
  colour[BCID] = 5;
}

void setcolour24(colour24 colour, unsigned char _BR, unsigned char _BG,
                 unsigned char _BB, unsigned char _FR, unsigned char _FG,
                 unsigned char _FB) {
  colour[BR] = _BR;
  colour[BB] = _BB;
  colour[BG] = _BG;
  colour[BCID] = 2;
  colour[FR] = _FR;
  colour[FB] = _FB;
  colour[FG] = _FG;
  colour[FCID] = 2;
}

void math24(colour24 colour, colour24 colour1, colour24 colour2,
            enum colour_math operation, float blend) {

  if (operation < 0 || operation > LAST_OPERATION) {
    start_basic(RED, NOBG);
    printf("colourmods: Illegal operation\n");
    resetcolour();
    return;
  }

  if (blend == 0.0f) {
    for (int i = 0; i < 8; i++) {
      if (i == FCID || i == BCID) {
        continue;
      }
      colour[i] = colour1[i];
    }
    return;
  }

  for (int i = 0; i < 8; i++) {
    if (i == FCID || i == BCID) {
      continue;
    }

    switch (operation) {
    case ADD:
      colour[i] = (int)colour1[i] + colour2[i] * blend;
      // Clip to 255
      if (colour[i] < colour1[i] || colour[i] < colour2[i])
        colour[i] = 255;
      break;
    case SUBTRACT:
      if (colour2[i] >= colour1[i]) {
        colour[i] = 0;
        continue;
      }
      colour[i] = colour1[i] - colour2[i] * blend;
      break;
    case MULTIPLY:
      colour[i] = colour1[i] / 255.0f * colour2[i];
      // Blend (same as MIX)
      colour[i] = colour1[i] * (1 - blend) + colour[i] * blend;
      break;
    case DIVIDE:
      if (colour2[i] == 0) {
        colour[i] = 255;
        continue;
      }
      // Normal division
      colour[i] = (float)colour1[i] / colour2[i];
      // Same as MIX operation
      colour[i] = colour1[i] * (1 - blend) + colour[i] * blend;
      break;
    case MIX:
      colour[i] = colour1[i] * (1 - blend) + colour2[i] * blend;
      break;
    case LIGHTEN:
      colour[i] = colour1[i] > colour2[i] ? colour1[i] : colour2[i];
      colour[i] = colour1[i] * (1 - blend) + colour[i] * blend;
      break;
    case DARKEN:
      colour[i] = colour1[i] < colour2[i] ? colour1[i] : colour2[i];
      colour[i] = colour1[i] * (1 - blend) + colour[i] * blend;
    }
  }
}

int difference24(colour24 colour1, colour24 colour2) {
  int diff = 0;
  for (int i = 0; i < 8; i++) {
    if (i == BCID || i == FCID)
      continue;
    if (colour1[i] > colour2[i])
      diff += (int)colour1[i] - colour2[i];
    else
      diff += (int)colour2[i] - colour1[i];
  }
  return diff;
}

float value24(colour24 colour) {
  return (colour[FR] + colour[FG] + colour[FB]) / (255.0f * 3);
}
