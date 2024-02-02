#include "colourmods.h"
#include "modules.h"
#include "version.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  colour24 colour_list[24];

  basic_display("TEST\n", RED, FULL);

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
