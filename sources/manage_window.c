/*
** EPITECH PROJECT, 2021
** manage_window.c
** File description:
** display a string in the middle of the window
*/

#include "lib.h"
#include "my_sokoban.h"
#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

static void display_window(char **buffer, int x, int y, int error)
{
    char **str = NULL;

    str = my_double_dup(str, (char *[]) {"Haha, the window is to little !",
            "      Try to enhance it !", NULL});
    refresh();
    clear();
    if (error == 1) {
        buffer = str;
        check_win_size(&x, &y, str);
    }
    for (int i = 0; buffer[i]; i += 1, y += 1)
        mvprintw(y, x, buffer[i]);
    refresh();
    free(str);
}

int manage_main_part(char ***buffer, char **o_list, int *key)
{
    int x = 0;
    int y = 0;

    if (check_end_game(o_list, buffer) > 0) {
        display_window(*buffer, x, y, 0);
        return (check_end_game(o_list, buffer) == 1 ? true : false);
    }
    if (check_win_size(&x, &y, *buffer)) {
        display_window(*buffer, x, y, 0);
        *key = get_key(buffer);
    } else {
        display_window(*buffer, x, y, 1);
        *key = get_key(buffer);
    }
    return (-1);
}

bool manage_window(char **buffer, char **o_list)
{
    int key = -1;
    char **save_buffer = NULL;

    save_buffer = my_double_dup(save_buffer, buffer);
    noecho();
    curs_set(0);
    keypad(stdscr, 1);
    while (key != 'q') {
        if (manage_main_part(&buffer, o_list, &key) != -1)
            return (manage_main_part(&buffer, o_list, &key));
        if (key == ' ') {
            free(buffer);
            return (manage_window(save_buffer, o_list));
        }
    }
    free(buffer);
    free(save_buffer);
    return (false);
}
