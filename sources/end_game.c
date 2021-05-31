/*
** EPITECH PROJECT, 2021
** end_game.c
** File description:
** manage end of game
*/

#include <stdbool.h>
#include "lib.h"
#include <stdlib.h>

static int check_around(char **buffer, int i, int j, char **o_list)
{
    int loose = 0;

    for (int x = 0; o_list[x]; x += 2)
        if (i == my_getnbr(o_list[x]) && j == my_getnbr(o_list[x + 1]))
            return (loose);
    if (buffer[i][j] == 'X' && buffer[i][j + 1] == '#')
        loose += 1;
    if (buffer[i][j] == 'X' && buffer[i][j - 1] == '#')
        loose += 10;
    if (buffer[i][j] == 'X' && buffer[i - 1][j] == '#')
        loose += 100;
    if (buffer[i][j] == 'X' && buffer[i + 1][j] == '#')
        loose += 1000;
    return (loose);
}

bool check_for_loose(char **buffer, char **o_list)
{
    int loose = 0;

    for (int i = 0; buffer[i]; i += 1) {
        for (int j = 0; buffer[i][j] != '\0'; j += 1) {
            loose = check_around(buffer, i, j, o_list);
            if (!(loose > 100 && loose != 1000 && loose != 1100) && buffer[i][j]
        == 'X')
                return (false);
        }
    }
    return (true);
}

int check_end_game(char **o_list, char ***buffer)
{
    for (int i = 0; o_list[i]; i += 2)
        if ((*buffer)[my_getnbr(o_list[i])][my_getnbr(o_list[i + 1])] != 'X' &&
            (*buffer)[my_getnbr(o_list[i])][my_getnbr(o_list[i + 1])] != 'P')
            (*buffer)[my_getnbr(o_list[i])][my_getnbr(o_list[i + 1])] = 'O';
    if (check_for_loose((*buffer), o_list))
        return (2);
    for (int i = 0; o_list[i]; i += 2)
        if ((*buffer)[my_getnbr(o_list[i])][my_getnbr(o_list[i + 1])] != 'X')
            return (0);
    return (1);
}
