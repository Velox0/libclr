#include "modules.h"
#include "version.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int colour[3] = {0xFF, 0x44, 0x88};

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
    display(argv[i], colour);
    printf("\n");
  }

  return 0;
}
