#ifndef COLOURMODS
#define COLOURMODS

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
typedef union {
  unsigned char format[8];
} colour;

/*
  instead of accessing colour.format[] elements with
  numbers, use enum rgbindex for better maintainability
*/
enum rgbindex {
  FR,     // foreground red
  FG,     // foreground green
  FB,     // foreground blue
  FSTYLE, // foreground colour space id
  BR,     // background red
  BG,     // background green
  BB,     // background blue
  BSTYLE  // background colour space id
};

enum colour_index {
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
  BACKGROUND_BLACK,
  BACKGROUND_RED,
  BACKGROUND_GREEN,
  BACKGROUND_YELLOW,
  BACKGROUND_BLUE,
  BACKGROUND_MAGENTA,
  BACKGROUND_CYAN,
  BACKGROUND_WHITE
};

#endif
