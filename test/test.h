#include "../include/colourmods.h"
#include "../include/display.h"

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

void getcolour4_test();

void display4_test();

void setcolour24_test();

void math24_test();

void start24_test();
