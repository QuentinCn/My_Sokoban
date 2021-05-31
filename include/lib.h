/*
** EPITECH PROJECT, 2021
** lib my_sokoban
** File description:
** .h
*/

#ifndef LIB
#define LIB

#include <stdbool.h>

int my_strlen(char const *str);
void handle_error(int ac, char **av, char **buffer, int step);
char *open_read(char *filepath);
char **char_to_double_char(char **arg, char *str);
int my_double_strlen(char **str);
bool check_right(char ***buffer, int i, int j);
bool check_left(char ***buffer, int i, int j);
bool check_up(char ***buffer, int i, int j);
bool check_down(char ***buffer, int i, int j);
int my_getnbr(char *nbr);
char *my_itoc(int nb);
char **my_double_dup(char **dest, char **src);
bool check_win_size(int *x, int *y, char **buffer);
bool my_strcmp(char *str1, char *str2);
int my_putstr(char *str);
void display_error_size(void);
char *my_strdup(char *dest, char *src);

#endif /* !LIB */
