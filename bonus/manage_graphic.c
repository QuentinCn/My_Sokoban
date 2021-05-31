/*
** EPITECH PROJECT, 2021
** manage_garphic.c
** File description:
** display a string in the middle of the window
*/

#include "bonus.h"
#include "lib.h"
#include "my_sokoban.h"
#include <stdlib.h>
#include <unistd.h>

#define SPACE (32)

sfRenderWindow *draw_in_win(sfRenderWindow *game, element_list *list)
{
    while (list) {
        sfSprite_setScale(list->sprite, list->scale);
        sfSprite_setPosition(list->sprite, list->pos);
        sfRenderWindow_drawSprite(game, list->sprite, NULL);
        list = list->next;
    }
    return (game);
}

sfRenderWindow *draw_and_move(sfRenderWindow *game, char ***buffer,
            element_list **list, element_list **list2)
{
    (*list2) = NULL;
    (*buffer) = move_player(*buffer);
    (*list2) = create_object((*list2), *buffer);
    game = draw_in_win(game, (*list));
    game = draw_in_win(game, (*list2));
    return (game);
}

static void display_window(sfRenderWindow *game, element_list *list, char
                **buffer, char **o_list)
{
    sfEvent event;
    element_list *list2 = malloc(sizeof(*list2));

    while (sfRenderWindow_isOpen(game)) {
        sfRenderWindow_clear(game, sfBlack);
        if (sfKeyboard_isKeyPressed(sfKeyQ))
            break;
        while (sfRenderWindow_pollEvent(game, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(game);
        }
        game = draw_and_move(game, &buffer, &list, &list2);
        sfRenderWindow_display(game);
        if (check_end_game(o_list, &buffer) > 0) {
            list = free_list(list);
            break;
        }
    }
    sfRenderWindow_destroy(game);
}

sfTexture *create_texture(int left, int top, int width, int height)
{
    sfIntRect area = {left, top, width, height};
    sfTexture *text = sfTexture_createFromFile("content/images_sokoban.png",
                    &area);

    return (text);
}

bool manage_graphic(char **buffer, char **o_list)
{
    element_list *list = malloc(sizeof(*list));
    sfVideoMode video = {800, 800, 32};
    sfRenderWindow *game = sfRenderWindow_create(video, "my_sokoban",
        sfClose, NULL);

    list = NULL;
    list = create_list(list, buffer);
    display_window(game, list, buffer, o_list);
    return (true);
}
