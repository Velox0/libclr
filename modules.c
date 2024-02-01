#include "colourmods.h"
#include <stdio.h>
#include <stdlib.h>

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

void display(char *str, colour colour) {
  char normal[] = "\033[0;0m";
  printf("\033[38;%d;%d;%d;%d;48;%d;%d;%d;%dm", colour.format[FSTYLE],
         colour.format[FR], colour.format[FG], colour.format[FB],
         colour.format[BSTYLE], colour.format[BR], colour.format[BG],
         colour.format[BB]);
  printf("%s", str);
  printf("%s", normal);
  return;
}

char getoption(char *opt) {
  if (opt[1] != '-')
    return opt[1];
  char *long_options[] = {"from", "after", "reset-on", "version", "help"};

  char short_options[] = "farvh";

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
