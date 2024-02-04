#include "../src/colourmods/colourmods.h"
#include "../src/display/display.h"
#include "../src/optionhandler/optionhandler.h"

// TEST VARIABLES

typedef struct {
  int total;
  int success;
  int failure;
} tests;

/*
  ALL TEST DECLARATIONS HERE

  TEST FOR EVERY FUNCTION IS REQUIRED
*/

void test_log(const char *testname, int status);

void getbg_test();

void getfg_test();

void getbasic_colour_test();

void basic_display_test();