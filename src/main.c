#include "unistd.h"
#include <ncurses.h>
#include <stddef.h>
#include <stdint.h>

#define COLOR_PRIMARY 1

int main() {
  char *view;
  fprintf(stderr, "%s\n", view);

  int row, col; /* to store the number of rows and *
                 * the number of colums of the screen */
  initscr();    /* start the curses mode */
  keypad(stdscr, TRUE);
  raw();
  noecho();
  start_color();
  getmaxyx(stdscr, row, col); /* get the number of rows and columns */

  init_color(COLOR_PRIMARY, 150, 150, 150);

  init_pair(1, COLOR_WHITE, COLOR_PRIMARY);

  attron(COLOR_PAIR(1));
  move(row - 2, 0);
  hline(' ', col);
  mvprintw(row - 2, 1, "Insert");
  refresh();

  int cursor_index = 0;

  int cursor_row = 0;
  int cursor_col = 0;

  while (true) {

    attroff(COLOR_PAIR(1));

    int cur_row = 0;
    int cur_col = 0;

    for (int i = 0; view[i] != '\0'; i++) {
      if (i == cursor_index) {
        cursor_row = cur_row;
        cursor_col = cur_col;
      }

      if (view[i] == '\n') {
        cur_row++;
        cur_col = 0;
        continue;
      }

      mvaddch(cur_row, cur_col, view[i]);
      cur_col++;
    }

    move(cursor_row, cursor_col);

    refresh();

    uint32_t c = getch();

    switch (c) {
    case 'q':
      endwin();
      return 0;
    case KEY_LEFT:
      cursor_index--;
      break;
    case KEY_RIGHT:
      cursor_index++;
      break;
    case KEY_BACKSPACE:
      cursor_index--;
      break;
    default:
      break;
    }
  }

  /*
  __auto_type win = newwin(20, 20, 3, 3);


  wprintw(win, "test");
  wrefresh(win);
  */
  echo();
  noraw();
  endwin(); /* End curses mode		  */
  return 0;
}
