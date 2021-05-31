/*
** EPITECH PROJECT, 2020
** list_creation
** File description:
** create, print & free a list
*/

#include "lib.h"
#include <stdlib.h>
#include "bonus.h"

element_list *free_list(element_list *list)
{
    element_list *tmp = NULL;

    while (list) {
        tmp = list->next;
        free(list);
        list = tmp;
    }
    return (list);
}
