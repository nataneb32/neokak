#pragma once

#include <sys/ioctl.h>
#include <stdio.h>

void term_get_size(int* width, int* height) {
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);
  *width = w.ws_col;
  *height = w.ws_row;
}
