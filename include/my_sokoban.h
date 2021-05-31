/*
** EPITECH PROJECT, 2021
** my_sokoban.h
** File description:
** .h
*/

#ifndef SOKOBAN
#define SOKOBAN

#include <stdbool.h>

bool manage_window(char **str, char **o_list);
char **move_right(char **buffer);
char **move_left(char **buffer);
char **move_up(char **buffer);
char **move_down(char **buffer);
char **create_o_list(char **o_list, char **buffer);
int check_end_game(char **o_list, char ***buffer);
int get_key(char ***buffer);

#endif /* !SOKOBAN */
