#include "colourmods.h"
#include "modules.h"
#include "version.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  colour24 colour_list[24];

  colour_list[RED].format[FR] = 0xFF;
  colour_list[RED].format[FG] = 0;
  colour_list[RED].format[FB] = 0;
  colour_list[RED].format[BG] = 0;
  colour_list[RED].format[BR] = 0;
  colour_list[RED].format[BB] = 0;
  colour_list[RED].format[FCID] = 2;
  colour_list[RED].format[BCID] = 0;

  colour_list[YELLOW].format[FR] = 225;
  colour_list[YELLOW].format[FG] = 225;
  colour_list[YELLOW].format[FCID] = 2;

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-')
      continue;
    char ch = getoption(argv[i]);
    switch (ch) {
    case 'r':
      break;
    case 'v':
      display24(CLRVERSION "\n", colour_list[YELLOW]);
      return 0;
    case 'h':
    default:
      help(argv[0]);
    }
  }

  return 0;
}
