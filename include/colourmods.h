#ifndef COLOURMODS
#define COLOURMODS

#include <stdio.h>

/*
  The colour union stores colour/formatting information
  required for ANSI escape codes.

  24-bit ANSI uses the following format of escape sequence

  \033[38 (FOREGROUND); [COLOUR SPACE ID...]; [R]; [G]; [B];
       48 (BACKGROUND); [COLOUR SPACE ID...]; [R]; [G]; [B] m

  For more info check out:
  https://en.wikipedia.org/wiki/ANSI_escape_code#24-bit

  format[0-3] store foreground style + RGB values
  format[4-7] store foreground style + RGB values
*/
typedef unsigned char colour24[8];

/*
  Similar to 24-bit colours, 8-bit follow the following pattern

  \033[38 (FOREGROUND); [CSID] (0/5); [N] (0-255);
       48 (BACKGROUND); [CSID] (0/5); [N] (0-255);
*/
typedef unsigned char colour8[4];

/*
  Most terminals at-least support 3-4bit colours. The following
  is the required format:

  \033[ [FOREGROUND COLOUR / BACKGROUND COLOUR] m
  there are 16 available colours for foreground and background

  Therefore all colour combinations can be stored in 2 hexadecimal
  digits. The right hexadecimal is foreground and left is background
  [FG][BG]

  https://en.wikipedia.org/wiki/ANSI_escape_code#3-bit_and_4-bit

  To set to a colour use the following method
  basic_colour colour = 0x<BG><FG>

  for example: basic_colour YELLOW_RED = 0x31
  where left digit is background yellow and right digit is red

  To find out what number gives what colour refer to the enum colour_index
  where 0-16 all colours are on their respective indexes

  you can also set colours as follows:
  basic_colour example = RED (This will set the foreground colour red)
               example += YELLOW * 16 (This will set background colour yellow)
*/

typedef unsigned char basic_colour;

/*
  instead of accessing colour24.format[] elements with
  numbers, use enum rgb_index for better maintainability
*/
enum rgb_index {
  FR,   // foreground red
  FG,   // foreground green
  FB,   // foreground blue
  FCID, // foreground colour space id
  BR,   // background red
  BG,   // background green
  BB,   // background blue
  BCID  // background colour space id
};

enum eight_bit_index {
  FN,    // foreground colour
  FCID8, // foreground cid
  BN,    // background colour
  BCID8  // background cid
};

enum colour_index {
  // Colour index
  BLACK,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  MAGENTA,
  CYAN,
  WHITE,
  BRIGHT_BLACK,
  BRIGHT_RED,
  BRIGHT_GREEN,
  BRIGHT_YELLOW,
  BRIGHT_BLUE,
  BRIGHT_MAGENTA,
  BRIGHT_CYAN,
  BRIGHT_WHITE,
  NOBG,
  NOFG,
  FULL
};
/*
  Remeber that basic_colour is just unsigned char
*/
/*
  basic colour to ANSI colour code translator
  Accepts a basic_colour and return the background ANSI colour value
  for the basic_colour
*/
basic_colour getbg(basic_colour colour);

/*
  basic colour to ANSI colour code translator
  Accepts a basic_colour and return the foreground ANSI colour value
  for the basic_colour
*/
basic_colour getfg(basic_colour colour);

/*
  Give it a background and foreground colour and it gives a basic_colour
  for the specified formatting

  Pass it throung getbg and getfg to get the ANSI code
*/
basic_colour getbasic_colour(enum colour_index BG, enum colour_index FG);

/*
  Function to ease the process of manually changing each element of
  colour24.format[n]. Accepts pointer to the colour24 struct and sets
  the foreground elements appropriate value
*/
void setcolour24(colour24 colour, unsigned char _BR, unsigned char _BG,
                 unsigned char _BB, unsigned char _FR, unsigned char _FG,
                 unsigned char _FB);

/*
  Function to ease the process of manually changing each element of
  colour24.format[n]. Accepts pointer to the colour24 struct and sets
  the background elements appropriate value
*/
void setbgcolour24(colour24 *colour, unsigned char R, unsigned char G,
                   unsigned char B);

/*
  Function to ease the process of manually changing each element of
  colour24.format[n]. Accepts pointer to the colour24 struct and sets
  the foreground and background elements appropriate value
*/
void setcolour24(colour24 colour, unsigned char BR, unsigned char BG,
                 unsigned char BB, unsigned char FR, unsigned char FG,
                 unsigned char FB);

/*
  Sets FCID to 0
*/
inline void resetfg24(colour24 *colour) { *colour[FCID] = 0; }

/*
  Sets BCID to 0
*/
inline void resetbg24(colour24 *colour) { *colour[BCID] = 0; }

void interpolate24(colour24 colour, colour24 colour1, colour24 colour2,
                   float factor);

#endif