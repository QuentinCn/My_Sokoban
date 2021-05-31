/*
** EPITECH PROJECT, 2021
** bonus.h
** File description:
** .h of my_sokoban's bonus
*/

#ifndef BONUS
#define BONUS

#include <SFML/Graphics.h>
#include <stdbool.h>

typedef struct list_of_element
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    struct list_of_element *next;
} element_list;

element_list *add_inlist(element_list *list, element_list *element, int pos);
element_list *get_inlist(element_list *list, int pos);
int len_list(element_list *list);
element_list *free_inlist(element_list *list, int pos);
element_list *free_list(element_list *list);
void print_list(element_list *list);
bool manage_graphic(char **buffer, char **o_list);
char **move_player(char **buffer);
element_list *create_list(element_list *list, char **buffer);
element_list *create_object(element_list *list, char **buffer);

#endif /* !LIB */
