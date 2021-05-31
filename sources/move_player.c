/*
** EPITECH PROJECT, 2021
** move_player
** File description:
** manage to move the player
*/

#include "lib.h"

char **move_right(char **buffer)
{
    for (int i = 0; buffer[i]; i += 1)
        for (int j = 0; buffer[i][j] != '\0'; j += 1) {
            if (check_right(&buffer, i, j))
                return (buffer);
        }
    return (buffer);
}

char **move_left(char **buffer)
{
    for (int i = 0; buffer[i]; i += 1)
        for (int j = 0; buffer[i][j] != '\0'; j += 1) {
            if (check_left(&buffer, i, j))
                return (buffer);
        }
    return (buffer);
}

char **move_up(char **buffer)
{
    for (int i = 0; buffer[i]; i += 1)
        for (int j = 0; buffer[i][j] != '\0'; j += 1) {
            if (check_up(&buffer, i, j))
                return (buffer);
        }
    return (buffer);
}

char **move_down(char **buffer)
{
    for (int i = 0; buffer[i]; i += 1)
        for (int j = 0; buffer[i][j] != '\0'; j += 1) {
            if (check_down(&buffer, i, j))
                return (buffer);
        }
    return (buffer);
}
