/*
** EPITECH PROJECT, 2021
** manage_list.c
** File description:
** manage the list
*/

#include "bonus.h"
#include <stdlib.h>

element_list *do_switch1(element_list *element, char c)
{
    switch (c) {
    case ('#'):
        element->texture = sfTexture_createFromFile("content/wall.png", NULL);
        return element;
    case (' '):
        element->texture = sfTexture_createFromFile("content/ground.png", NULL);
        return element;
    case ('O'):
        element->texture = sfTexture_createFromFile("content/ground.png", NULL);
        return element;
    case ('P'):
        element->texture = sfTexture_createFromFile("content/ground.png", NULL);
        return element;
    case ('X'):
        element->texture = sfTexture_createFromFile("content/ground.png", NULL);
        return element;
    }
    return (element);
}

element_list *do_switch2(element_list *element, char c)
{
    switch (c) {
    case ('O'):
        element->texture = sfTexture_createFromFile("content/place.png", NULL);
        return element;
    case ('P'):
        element->texture = sfTexture_createFromFile("content/player.png", NULL);
        return element;
    case ('X'):
        element->texture = sfTexture_createFromFile("content/box.png", NULL);
        return element;
    }
    return (element);
}

element_list *create_element(char c, int i, int j, int option)
{
    element_list *element = malloc(sizeof(*element));

    if (option == 1)
        element = do_switch1(element, c);
    else
        element = do_switch2(element, c);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, 1);
    element->pos = (sfVector2f) {i * 50, j * 50};
    element->scale = (sfVector2f) {1.13, 1.13};
    return (element);
}

element_list *create_list(element_list *list, char **buffer)
{
    for (int i = 0; buffer[i]; i += 1) {
        for (int j = 0; buffer[i][j] != '\0'; j += 1) {
            list = add_inlist(list, create_element(buffer[i][j], j, i, 1),
                            len_list(list));
        }
    }
    return (list);
}

element_list *create_object(element_list *list, char **buffer)
{
    for (int i = 0; buffer[i]; i += 1) {
        for (int j = 0; buffer[i][j] != '\0'; j += 1) {
            if (buffer[i][j] == 'O' || buffer[i][j] == 'P' || buffer[i][j] ==
                        'X')
                list = add_inlist(list, create_element(buffer[i][j], j, i, 0),
                            len_list(list));
        }
    }
    return (list);
}
