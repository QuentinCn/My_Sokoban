/*
** EPITECH PROJECT, 2021
** get_key.c
** File description:
** recup the keyboard key
*/

#include "my_sokoban.h"
#include <ncurses.h>

int get_key(char ***buffer)
{
    int key = 0;

    key = getch();
    if (key == KEY_RIGHT)
        (*buffer) = move_right((*buffer));
    if (key == KEY_LEFT)
        (*buffer) = move_left((*buffer));
    if (key == KEY_UP)
        (*buffer) = move_up((*buffer));
    if (key == KEY_DOWN)
        (*buffer) = move_down((*buffer));
    return (key);
}
