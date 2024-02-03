#include "../src/colourmods/colourmods.h"
#include "../src/display/display.h"
#include "../src/optionhandler/optionhandler.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  system("pwd");
  int a = system("cd ./test 2>/dev/null");
  if (a) {
    basic_display("Error:", BLACK * 16 + RED, FULL);
    printf(" Only run tests from root folder of project\n");
    exit(1);
  }
}