/*
** EPITECH PROJECT, 2021
** error_handling.c
** File description:
** handle errors
*/

#include <stdlib.h>
#include <stdbool.h>

bool my_strcmp(char *str1, char *str2);

static void check_for_forbiden_char(char **buffer)
{
    for (int i = 0; buffer[i]; i += 1)
        for (int j = 0; buffer[i][j] != '\0'; j += 1)
            if (buffer[i][j] != '#' && buffer[i][j] != ' ' && buffer[i][j] !=
                'X' && buffer[i][j] != 'O' && buffer[i][j] != 'P')
                exit(84);
}

void handle_error(int ac, char **av, char **buffer, int step)
{
    if (step == 1) {
        if (ac != 2)
            exit(84);
    } else if (step == 2) {
        if (!buffer)
            exit(84);
        if (!my_strcmp(av[1], "-h"))
            check_for_forbiden_char(buffer);
    }
}
