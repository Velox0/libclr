#ifndef COLOURMODS
#define COLOURMODS

/*
  The colour union stores colour/formattiing information
  required for ANSI escape codes.

  ANSI escape code for 8 bit foreground and background
  formatting looks as follows

  \033[38 (FOREGROUND); [ITALICS/BOLD...]; [R]; [G]; [B];
          (BACKGROUND); [ITALICS/BOLD...]; [R]; [G]; [B] m

  format[0-5] store RGB values that range from
  0 to 255 (0xFF).
  the style[ITALICS/BOLD...] information is stored in format[6]
*/
typedef union {
  unsigned char format[8];
} colour;

enum ColourIndex {
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

enum rgbindex {
  FR,     // foreground red
  FG,     // foreground green
  FB,     // foreground blue
  FSTYLE, // foreground style [BOLD/ITALICS]
  BR,     // background red
  BG,     // background green
  BB,     // background blue
  BSTYLE  // background style [BOLD/ITALICS]
};

#endif
