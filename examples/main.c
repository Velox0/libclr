/*
 * This is an example program to show how to use libclr
 */

#include <libclr/colourmods.h>
#include <libclr/libclr.h>
#include <stdio.h>

int main() {
  colour24 turquoise;

  newcolour24(turquoise); // Initialise  the colour
  resetbg24(turquoise);   // Make bg (background) transparent
  hexto24(turquoise, NULL, "6CDAE7");

  start24(turquoise); // The following text will be turquoise colour
                      // in colour
  printf("turquoise");
  resetcolour(); // Reset terminal colour to normal
                 // literally just abstraction for `printf("\033[0m")`

  printf("\n");

  return 0;
}
