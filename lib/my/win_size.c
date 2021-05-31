/*
** EPITECH PROJECT, 2021
** win_size.c
** File description:
** manage window size
*/

#include <stdbool.h>
#include <ncurses.h>

int my_strlen(char *str);

int my_double_strlen(char **buffer);

bool check_win_size(int *x, int *y, char **buffer)
{
    getmaxyx(stdscr, *y, *x);
    *x = *x / 2 - my_strlen(buffer[0]) / 2;
    *y = *y / 2 - my_double_strlen(buffer) / 2;
    if (*x < 0 || *y < 0)
        return (false);
    return (true);
}

void display_error_size(void)
{
    int x = 0;
    int y = 0;
    char str[] = "Haha the window is too little you can't play like that !";

    getmaxyx(stdscr, y, x);
    x = x / 2 - my_strlen(str) / 2;
    y = y / 2;
    clear();
    mvprintw(y, x, str);
}
