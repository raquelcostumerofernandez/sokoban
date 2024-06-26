/*
** EPITECH PROJECT, 2023
** simple_operations.c
** File description:
** Simple operations to the list
*/

#include "../../include/linked_lists_utils.h"

size_t list_len(l_list *l)
{
    l_elem *e = l->first;
    size_t i = 0;

    while (e != NULL)
        e = e->next;
    return (i);
}

l_elem *list_get_last(l_list *l)
{
    l_elem *e = l->first;

    if (e == NULL)
        return (NULL);
    while (e->next != NULL)
        e = e->next;
    return (e);
}

void list_pop_first(l_list *l)
{
    l_elem *e = l->first;

    l->first = e->next;
    destroy_elem(e, l->del);
    l->len --;
}
