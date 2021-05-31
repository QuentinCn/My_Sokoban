/*
** EPITECH PROJECT, 2021
** o_list.c
** File description:
** manage the o_list
*/

#include <stdlib.h>
#include "lib.h"

char **create_o_list(char **o_list, char **buffer)
{
    int occ = 0;
    int k = 0;

    for (int i = 0; buffer[i]; i += 1)
        for (int j = 0; buffer[i][j] != '\0'; j += 1)
            if (buffer[i][j] == 'O')
                occ += 1;
    o_list = malloc(sizeof(char *) * (occ * 2 + 1));
    for (int i = 0; buffer[i]; i += 1)
        for (int j = 0; buffer[i][j] != '\0'; j += 1)
            if (buffer[i][j] == 'O') {
                o_list[k++] = my_itoc(i);
                o_list[k++] = my_itoc(j);
            }
    o_list[k] = NULL;
    return (o_list);
}
