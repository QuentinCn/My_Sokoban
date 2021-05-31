/*
** EPITECH PROJECT, 2021
** check_move.c
** File description:
** check moves
*/

#include <stdlib.h>
#include <stdbool.h>

bool move_box(char ***buffer, int i, int j, int direction)
{
    if (direction == 0 && ((*buffer)[i][j + 1] == ' ' || (*buffer)[i][j + 1] ==
                        'O')) {
        (*buffer)[i][j + 1] = 'X';
        return (true);
    } else if (direction == 1 && ((*buffer)[i][j - 1] == ' ' || (*buffer)[i][j -
    1] == 'O')) {
        (*buffer)[i][j - 1] = 'X';
        return (true);
    } else if (direction == 2 && ((*buffer)[i - 1][j] == ' ' || (*buffer)[i -
    1][j] == 'O')) {
        (*buffer)[i - 1][j] = 'X';
        return (true);
    } else if (direction == 3 && ((*buffer)[i + 1][j] == ' ' || (*buffer)[i +
    1][j] == 'O')) {
        (*buffer)[i + 1][j] = 'X';
        return (true);
    }
    return (false);
}

bool check_right(char ***buffer, int i, int j)
{
    if ((*buffer)[i][j] == 'P' && (*buffer)[i][j + 1] != '#' &&
            (*buffer)[i][j + 1] != '\0') {
        if ((*buffer)[i][j + 1] == 'X')
            if (!move_box(buffer, i, j + 1, 0))
                return (false);
        (*buffer)[i][j] = ' ';
        (*buffer)[i][j + 1] = 'P';
        return (true);
    }
    return (false);
}

bool check_left(char ***buffer, int i, int j)
{
    if ((*buffer)[i][j] == 'P' && j > 1 && (*buffer)[i][j - 1] != '#') {
        if ((*buffer)[i][j - 1] == 'X')
            if (!move_box(buffer, i, j - 1, 1))
                return (false);
        (*buffer)[i][j] = ' ';
        (*buffer)[i][j - 1] = 'P';
        return (true);
    }
    return (false);
}

bool check_up(char ***buffer, int i, int j)
{
    if ((*buffer)[i][j] == 'P' && i > 1 && (*buffer)[i - 1][j] != '#') {
        if ((*buffer)[i - 1][j] == 'X')
            if (!move_box(buffer, i - 1, j, 2))
                return (false);
        (*buffer)[i][j] = ' ';
        (*buffer)[i - 1][j] = 'P';
        return (true);
    }
    return (false);
}

bool check_down(char ***buffer, int i, int j)
{
    if ((*buffer)[i][j] == 'P' && (*buffer)[i + 1] != NULL) {
        if ((*buffer)[i + 1][j] != '#') {
            if ((*buffer)[i + 1][j] == 'X' && !move_box(buffer, i + 1, j, 3))
                return (false);
            (*buffer)[i][j] = ' ';
            (*buffer)[i + 1][j] = 'P';
            return (true);
        }
    }
    return (false);
}