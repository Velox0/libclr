#include "colourmods.h"
#include <stdio.h>

void display24(char *str, colour24 colour) {
  char normal[] = "\033[0;0m";
  // "Activate" formatting by printing escape code
  printf("\033[38;%d;%d;%d;%d;48;%d;%d;%d;%dm", colour.format[FCID],
         colour.format[FR], colour.format[FG], colour.format[FB],
         colour.format[BCID], colour.format[BR], colour.format[BG],
         colour.format[BB]);
  // Print string
  printf("%s", str);
  // Reset formatting
  printf("%s", normal);
}

void display8(char *str, colour8 colour) {
  char normal[] = "\033[0;0m";
  // "Activate" formatting by printing escape code
  printf("\033[38;%d;%d;48;%d;%dm", colour.format[FCID8], colour.format[FN],
         colour.format[BCID8], colour.format[BN]);
  // Print string
  printf("%s", str);
  // Reset formatting
  printf("%s", normal);
}

void basic_display(char *str, basic_colour colour, enum colour_index control) {
  char normal[] = "\033[0;0m";
  switch (control) {
  case 0:
  case NOBG:
    printf("\033[%dm", getfg(colour));
    break;
  case 1:
  case NOFG:
    printf("\033[%dm", getbg(colour));
    break;
  case FULL:
    printf("\033[%d;%dm", getfg(colour), getbg(colour));
    break;
  default:
    basic_display("Error:", RED, NOBG);
    printf("invalid control bit\n");
    return;
  }
  printf("%s", str);
  printf("%s", normal);
}
