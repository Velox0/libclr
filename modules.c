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

void display(char *str, int colour[]) {
  char normal[] = "\033[0;0m";
  printf("\033[38;2;%d;%d;%dm%s%s", colour[0], colour[1], colour[2], str,
         normal);
  return;
}

char getoption(char *ch) {
  if (ch[1] != '-')
    return ch[1];
  char *options[] = {"from", "after", "reset-on", "version", "help"};

  char shortoptions[] = "farvh";

  int HOWMANYOPTIONS = sizeof(shortoptions) / sizeof(char) - 1;

  for (int i = 0; i < HOWMANYOPTIONS; i++) {
    for (int j = 2; ch[j]; j++) {
      if (ch[j] != options[i][j - 2])
        break;
      if (!ch[j + 1] && !options[i][j - 1])
        return shortoptions[i];
    }
  }
  return '\0';
}