#include "../include/colourmods.h"
#include <stdio.h>

void display24(const char *str, colour24 colour) {
  char normal[] = "\033[0m";
  // "Activate" formatting by printing escape code
  printf("\033[38;%d;%d;%d;%d;48;%d;%d;%d;%dm", colour[FCID], colour[FR],
         colour[FG], colour[FB], colour[BCID], colour[BR], colour[BG],
         colour[BB]);
  // Print string
  printf("%s", str);
  // Reset formatting
  printf("%s", normal);
}

void display8(const char *str, colour8 colour) {
  char normal[] = "\033[0m";
  // "Activate" formatting by printing escape code
  printf("\033[38;%d;%d;48;%d;%dm", colour[FCID8], colour[FN], colour[BCID8],
         colour[BN]);
  // Print string
  printf("%s", str);
  // Reset formatting
  printf("%s", normal);
}

void start4(colour4 colour, enum CSID control);

void display4(const char *str, colour4 colour, enum CSID control) {
  char normal[] = "\033[0m";
  start4(colour, control);
  printf("%s", str);
  printf("%s", normal);
}

void start4(colour4 colour, enum CSID control) {
  switch (control) {
  case NOFG:
    printf("\033[%dm", getbg(colour));
    break;
  case FULL:
    printf("\033[%d;%dm", getfg(colour), getbg(colour));
    break;
  default:
    printf("\033[%dm", getfg(colour));
  }
}

void start24(colour24 colour) {
  // The foreground
  printf("\033[38;%d;%d;%d;%dm", colour[FCID], colour[FR], colour[FG],
         colour[FB]);

  // The background
  printf("\033[48;%d;%d;%d;%dm", colour[BCID], colour[BR], colour[BG],
         colour[BB]);
}
