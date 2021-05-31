/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** compare two string
*/

#include <stdbool.h>

int my_strlen(char *str);

bool my_strcmp(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return (false);
    for (int i = 0; str1[i] != '\0'; i += 1)
        if (str1[i] != str2[i])
            return (false);
    return (true);
}
