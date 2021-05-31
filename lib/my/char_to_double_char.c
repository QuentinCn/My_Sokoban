/*
** EPITECH PROJECT, 2021
** char_to_double_char
** File description:
** convert a char * to a char **
*/

#include <stdlib.h>

int find_nb_space(char *str, char c)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i += 1)
        if (str[i] == c)
            counter += 1;
    return (counter + 1);
}

int find_len_word(char *str, char c)
{
    int i = 0;

    for (; str[i] != c && str[i] != '\0' && str[i] != '\n'; i += 1);
    return (i);
}

char **char_to_double_char(char **arg, char *str)
{
    int j = 0;

    if (str[0] == '\0') {
        return (NULL);
    }
    arg = malloc(sizeof(char *) * (find_nb_space(str, '\n') + 1));
    for (int i = 0; str[0] != '\0'; i += 1) {
        arg[i] = malloc(sizeof(char) * (find_len_word(str, '\n') + 1));
        for (j = 0; str[j] != '\n' && str[j] != '\0'; j += 1) {
            arg[i][j] = str[j];
            arg[i][j + 1] = '\0';
        }
        arg[i + 1] = NULL;
        if (str[j] == '\0')
            return (arg);
        str = &str[j + 1];
    }
    return (arg);
}
