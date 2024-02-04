#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

static tests test1;

int main() {
  test1.total = 2;
  test1.success = 0;
  test1.failure = 0;

  int a = system("cd ./test 2>/dev/null");
  if (a) {
    basic_display("Error:", BLACK * 16 + RED, FULL);
    printf(" Only run tests from root folder of project\n");
    exit(1);
  }

  getbgtest();

  return test1.total != test1.success;
}

// TEST FUNCTIONS

void success(const char *testname) {
  test1.success++;
  printf("\033[32m");
  printf("SUCCESS: %s\t[%d/%d]", testname, test1.success, test1.total);
  printf("\033[0m\n");
}

void failure(const char *testname) {
  test1.failure++;
  printf("\033[31m");
  printf("FAILURE: %s\t[%d/%d]", testname, test1.failure, test1.total);
  printf("\033[0m\n");
}

/*
  ALL TESTS HERE
*/

void getbgtest() {
  /*
    test for 0x71
              should return 47
    test for 0xFF
              should return 107
  */

  basic_colour testbgZ1 = getbg(0x7F);
  if (testbgZ1 == 47) {
    success("getbg");
  } else {
    failure("getbg");
  }
  basic_colour testbg2 = getbg(0xFF);
  if (testbg2 == 107) {
    success("getbg");
  } else {
    failure("getbg");
  }
}
