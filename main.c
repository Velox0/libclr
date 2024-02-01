#include "colourmods.h"
#include "modules.h"
#include "version.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  enum ColourIndex colour_index = BLACK;
  colour def[24];

  def[BRIGHT_WHITE].format[FR] = 0xFF;
  def[BRIGHT_WHITE].format[FG] = 0;
  def[BRIGHT_WHITE].format[FB] = 0;
  def[BRIGHT_WHITE].format[BG] = 0;
  def[BRIGHT_WHITE].format[BR] = 0;
  def[BRIGHT_WHITE].format[BB] = 0;
  def[BRIGHT_WHITE].format[FSTYLE] = 2;
  def[BRIGHT_WHITE].format[BSTYLE] = 0;

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-')
      continue;
    char ch = getoption(argv[i]);
    switch (ch) {
    case 'r':
      break;
    case 'v':
      printf(CLRVERSION "\n");
      return 0;
    case 'h':
    default:
      help(argv[0]);
    }
  }

  for (int i = 1; i < argc; i++) {
    display(argv[i], def[BRIGHT_WHITE]);
    printf("\n");
  }

  return 0;
}
