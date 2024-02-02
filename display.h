#ifndef CLRDISPLAY
#define CLRDISPLAY

#include "colourmods.h"

void display24(char str[], colour24 colour);
void display8(char str[], colour8 colour);
void basic_display(char *str, basic_colour colour, enum colour_index control);

#endif
