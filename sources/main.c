/*
** EPITECH PROJECT, 2021
** main
** File description:
** minishell's main
*/

#include "my_sokoban.h"
#include "lib.h"
#include <ncurses.h>
#include <stdlib.h>

static void flag_h(void)
{
    my_putstr("USAGE\n./my_sokoban map_name\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("In this game you will have to place the box on their location.");
    my_putstr("\nFor that you will only be able to push the box so be ");
    my_putstr("carefull !\n\n");
    my_putstr("LEGEND\n");
    my_putstr("'X' = box\n'O' = box's locations\n'P' = player\n'#' = wall\n");
    my_putstr("\nUse the arrow to move your personnage, space to retry and a ");
    my_putstr("to quit.\n");
    exit(0);
}

int main(int ac, char **av)
{
    char **buffer = NULL;
    char *str = NULL;
    char **o_list = NULL;
    int return_value = 1;

    handle_error(ac, av, NULL, 1);
    if (my_strcmp(av[1], "-h"))
        flag_h();
    str = open_read(av[1]);
    if (!str)
        return (84);
    buffer = char_to_double_char(buffer, str);
    handle_error(ac, av, buffer, 2);
    o_list = create_o_list(o_list, buffer);
    initscr();
    if (manage_window(buffer, o_list))
        return_value = 0;
    endwin();
    return (return_value);
}
