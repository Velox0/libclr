#ifndef CLRDISPLAY
#define CLRDISPLAY

#include "colourmods.h"

/*
  prints the given string in appropriate colour
  refer to ../colourmods/colourmods.h for more documentation
*/
void display24(char *str, colour24 colour);

/*
  prints the given string in appropriate colour
*/
void display8(char *str, colour8 colour);

/*
  same. BUT...
  requires a third argument "control"
  if control is set to
      NOBG (enum) or 0      only foreground colour will be affected
      NOFG (enum) or 1      only background colour will be affected
      FULL                  both foregrounf and background will be affected

  example:
    display4("Error:", RED, NOBG);
*/
void display4(char *str, colour4 colour, CSID control);

void resetcolour();

void start4(colour4 colour, CSID control);

void start24(colour24 colour);

#endif
