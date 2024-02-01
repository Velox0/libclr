#include "colourmods.h"
#include <stdio.h>
#include <stdlib.h>

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
  return;
}

char getoption(char *opt) {
  if (opt[1] != '-')
    return opt[1];

  char *long_options[] = {"from", "after", "reset-on", "version", "help"};
  char short_options[] = "farvh";
  short_options[0] = 'F';
  int HOWMANYOPTIONS = sizeof(short_options) / sizeof(char) - 1;

  for (int i = 0; i < HOWMANYOPTIONS; i++) {
    for (int j = 2; opt[j]; j++) {
      if (opt[j] != long_options[i][j - 2])
        break;
      if (!opt[j + 1] && !long_options[i][j - 1])
        return short_options[i];
    }
  }
  return '\0';
}

void help(char arg[]) {
  char red[] = "\033[0;31m";
  char green[] = "\033[0;32m";
  char normal[] = "\033[0;0m";
  printf("Usage: %scommand %s|%s %s %s[OPTIONS]%s\n", green, red, green, arg,
         red, normal);
  printf("  -a, --after    <string> <colour>\tafter matching <string> format "
         "text to <colour>\n");
  printf("  -f, --from     <string> <colour>\tfrom matching <string> format "
         "text to <colour>\n");
  printf("  -r, --reset-on <string> <colour>\treset colour to normal after "
         "matching <string>\n");
  printf("  Note: Combining short options is not supported!\n");
  exit(0);
}
