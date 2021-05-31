/*
** EPITECH PROJECT, 2021
** test_sokoban.c
** File description:
** test different function of the sokoban project
*/

#include <criterion/criterion.h>
#include "lib.h"
#include "my_sokoban.h"

#include <stdio.h>

static int len_array(char *array[])
{
    int i = 0;

    while (array[i])
        i += 1;
    return i;
}

static char **create_double_char(char *array[])
{
    char **new = malloc(sizeof(char *) * (len_array(array) + 1));

    for (int i = 0; array[i]; i += 1) {
        new[i] = strdup(array[i]);
        new[i + 1] = NULL;
    }
    return new;
}

Test(move_right, simple_move_right)
{
    char **actual = create_double_char((char *[]){"#####", "#  O#", "#P X#",
            "#   #", "#####", NULL});
    char **expected = create_double_char((char *[]){"#####", "#  O#", "# PX#",
            "#   #", "#####", NULL});

    actual = move_right(actual);
    for (int i = 0; expected[i] && actual[i]; i += 1)
        cr_assert_str_eq(actual[i], expected[i]);
}

Test(move_right, intermediate_move_right)
{
    char **actual = create_double_char((char *[]){"#####", "#  O#", "# PX#",
            "#   #", "#####", NULL});
    char **expected = create_double_char((char *[]){"#####", "#  O#", "# PX#",
            "#   #", "#####", NULL});

    actual = move_right(actual);
    for (int i = 0; expected[i] && actual[i]; i += 1)
        cr_assert_str_eq(actual[i], expected[i]);
}

Test(move_left, simple_move_left)
{
    char **expected = create_double_char((char *[]){"#####", "#  O#", "#P X#",
            "#   #", "#####", NULL});
    char **actual = create_double_char((char *[]){"#####", "#  O#", "# PX#",
            "#   #", "#####", NULL});

    actual = move_left(actual);
    for (int i = 0; expected[i] && actual[i]; i += 1)
        cr_assert_str_eq(actual[i], expected[i]);
}

Test(move_left, intermediate_move_left)
{
    char **expected = create_double_char((char *[]){"#####", "#  O#", "#P X#",
            "#   #", "#####", NULL});
    char **actual = create_double_char((char *[]){"#####", "#  O#", "#P X#",
            "#   #", "#####", NULL});

    actual = move_left(actual);
    for (int i = 0; expected[i] && actual[i]; i += 1)
        cr_assert_str_eq(actual[i], expected[i]);
}

Test(move_up, simple_move_up)
{
    char **actual = create_double_char((char *[]){"#####", "#  O#", "#P X#",
            "#   #", "#####", NULL});
    char **expected = create_double_char((char *[]){"#####", "#P O#", "#  X#",
            "#   #", "#####", NULL});

    actual = move_up(actual);
    for (int i = 0; expected[i] && actual[i]; i += 1)
        cr_assert_str_eq(actual[i], expected[i]);
}

Test(move_up, intermediate_move_up)
{
    char **actual = create_double_char((char *[]){"#####", "#P O#", "#  X#",
            "#   #", "#####", NULL});
    char **expected = create_double_char((char *[]){"#####", "#P O#", "#  X#",
            "#   #", "#####", NULL});

    actual = move_up(actual);
    for (int i = 0; expected[i] && actual[i]; i += 1)
        cr_assert_str_eq(actual[i], expected[i]);
}

Test(move_down, simple_move_down)
{
    char **actual = create_double_char((char *[]){"#####", "#  O#", "#P X#",
            "#   #", "#####", NULL});
    char **expected = create_double_char((char *[]){"#####", "#  O#", "#  X#",
            "#P  #", "#####", NULL});

    actual = move_down(actual);
    for (int i = 0; expected[i] && actual[i]; i += 1)
        cr_assert_str_eq(actual[i], expected[i]);
}

Test(move_down, intermediate_move_down)
{
    char **actual = create_double_char((char *[]){"#####", "#  O#", "#  X#",
            "#P  #", "#####", NULL});
    char **expected = create_double_char((char *[]){"#####", "#  O#", "#  X#",
            "#P  #", "#####", NULL});

    actual = move_down(actual);
    for (int i = 0; expected[i] && actual[i]; i += 1)
        cr_assert_str_eq(actual[i], expected[i]);
}

Test(create_o_list, with_one_O)
{
    char **actual = NULL;
    char **map = create_double_char((char *[]){"#####", "#  O#", "#  X#",
            "#P  #", "#####", NULL});
    char **expected = create_double_char((char *[]){"1", "3", NULL});

    actual = create_o_list(actual, map);
    for (int i = 0; expected[i] && actual[i]; i += 1)
        cr_assert_str_eq(actual[i], expected[i]);
}

Test(end_game, game_not_over)
{
    char **map = create_double_char((char *[]){"#####", "#  O#", "#  X#",
            "#P  #", "#####", NULL});
    char **o_list = create_double_char((char *[]){"1", "3", NULL});

    cr_assert_eq(check_end_game(o_list, &map), 0);
}

Test(end_game, game_win)
{
    char **map = create_double_char((char *[]){"#####", "#  X#", "#   #",
            "#P  #", "#####", NULL});
    char **o_list = create_double_char((char *[]){"1", "3", NULL});

    cr_assert_eq(check_end_game(o_list, &map), 1);
}

Test(end_game, game_loose_case1)
{
    char **map = create_double_char((char *[]){"#####", "#  O#", "#   #",
            "#P X#", "#####", NULL});
    char **o_list = create_double_char((char *[]){"1", "3", NULL});

    cr_assert_eq(check_end_game(o_list, &map), 2);
}

Test(end_game, game_loose_case2)
{
    char **map = create_double_char((char *[]){"#####", "#X O#", "#   #",
            "#P  #", "#####", NULL});
    char **o_list = create_double_char((char *[]){"1", "3", NULL});

    cr_assert_eq(check_end_game(o_list, &map), 2);
}

Test(end_game, game_loose_case3)
{
    char **map = create_double_char((char *[]){"#####", "#  O#", "#   #",
            "#XP #", "#####", NULL});
    char **o_list = create_double_char((char *[]){"1", "3", NULL});

    cr_assert_eq(check_end_game(o_list, &map), 2);
}
