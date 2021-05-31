/*
** EPITECH PROJECT, 2021
** move_player.c
** File description:
** move the player
*/

#include "bonus.h"
#include "my_sokoban.h"
#include <unistd.h>

char **move_player(char **buffer)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        buffer = move_right(buffer);
        usleep(150000);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        buffer = move_left(buffer);
        usleep(150000);
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        buffer = move_up(buffer);
        usleep(150000);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        buffer = move_down(buffer);
        usleep(150000);
    }
    return (buffer);
}
