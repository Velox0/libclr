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
void display4(char *str, colour4 colour, enum CSID control);

inline void resetcolour() { printf("\033[0m"); }

/*
  print colour in gradient with specified specified "step"
*/

void step_gradient(colour24 colour, colour24 step);

void start4(colour4 colour, enum CSID control);

void start24(colour24 colour);

#endif
