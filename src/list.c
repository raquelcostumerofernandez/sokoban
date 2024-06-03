/*
** EPITECH PROJECT, 2023
** winning.c
** File description:
** Functions that involve the winning of the game or the losing.
*/

#include "../include/so.h"
#include "../include/my.h"

tile *addlinked(list_t *list, unsigned int y, unsigned int x)
{
    tile *tiles = malloc(sizeof(tiles));

    tiles->x = x;
    tiles->y = y;
    tiles->next = list->first;
    list->first = tiles;
    return (tiles);
}

tile *searcho(table *t, int x, int y)
{
    tile *storage = t->x.first;

    while (storage != NULL) {
        if (storage->x == x && storage->y == y)
            return (storage);
        storage = storage->next;
    }
    return (NULL);
}
