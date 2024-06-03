/*
** EPITECH PROJECT, 2023
** move.c
** File description:
** Functions that involve the movement of the pleayer and the box.
*/

#include "../include/so.h"
#include <curses.h>

void keepo(table *t)
{
    tile *e = t->o.first;

    while (e != NULL && e->y < t->height) {
        if (t->map2d[e->y][e->x] == ' ')
            t->map2d[e->y][e->x] = 'O';
        e = e->next;
    }
}

static int boxup(table *t, int key)
{
    if (getpos(t, t->p.y -2, t->p.x) == '#' ||
    getpos(t, t->p.y -2, t->p.x) == 'X')
        return (0);
    if (getpos(t, t->p.y -2, t->p.x) != '#' ||
    getpos(t, t->p.y -2, t->p.x) != 'X'){
        t->map2d[t->p.y -2][t->p.x] = 'X';
        t->map2d[t->p.y -1][t->p.x] = 'P';
        t->map2d[t->p.y][t->p.x] = ' ';
        t->p.y = t->p.y - 1;
        t->x.first->y = t->p.y -2;
    }
    keepo(t);
}

static int upmove(table *t, int key)
{
    if (getpos(t, t->p.y, t->p.x) == '#')
        return (0);
    if (getpos(t, t->p.y - 1, t->p.x) == ' ' ||
    getpos(t, t->p.y -1, t->p.x) == 'O') {
        t->map2d[t->p.y - 1][t->p.x] = 'P';
        t->map2d[t->p.y][t->p.x] = ' ';
        t->p.y = t->p.y - 1;
    }
    if (getpos(t, t->p.y -1, t->p.x) == 'X') {
            boxup(t, key);
    }
    keepo(t);
    return (0);
}

static int boxdown(table *t, int key)
{
    if (getpos(t, t->p.y +2, t->p.x) == '#' ||
    getpos(t, t->p.y +2, t->p.x) == 'X')
        return (0);
    if (getpos(t, t->p.y +2, t->p.x) != '#'
    || getpos(t, t->p.y +2, t->p.x) != 'X'){
        t->map2d[t->p.y +2][t->p.x] = 'X';
        t->map2d[t->p.y +1][t->p.x] = 'P';
        t->map2d[t->p.y][t->p.x] = ' ';
        t->p.y = t->p.y + 1;
        t->x.first->y = t->p.y +2;
    }
}

static int downmove(table *t, int key)
{
    if (getpos(t, t->p.y, t->p.x) == '#')
        return (0);
    if (getpos(t, t->p.y + 1, t->p.x) == ' ' ||
    getpos(t, t->p.y + 1, t->p.x) == 'O') {
        t->map2d[t->p.y + 1][t->p.x] = 'P';
        t->map2d[t->p.y][t->p.x] = ' ';
        t->p.y = t->p.y + 1;
    }
    if (getpos(t, t->p.y +1, t->p.x) == 'X')
        boxdown(t, key);
    keepo(t);
    return (0);
}

int boxright(table *t, int key)
{
    if (getpos(t, t->p.y, t->p.x +2) == '#' ||
    getpos(t, t->p.y, t->p.x +2) == 'X')
        return (0);
    if (getpos(t, t->p.y, t->p.x +2) != '#') {
            t->map2d[t->p.y][t->p.x +2] = 'X';
            t->map2d[t->p.y][t->p.x +1] = 'P';
            t->map2d[t->p.y][t->p.x] = ' ';
            t->p.x = t->p.x +1;
            t->x.first->x = t->p.x +2;
    }
}

static int rightmove(table *t, int key)
{
    if (getpos(t, t->p.y, t->p.x) == '#')
        return (0);
    if (getpos(t, t->p.y, t->p.x + 1) == ' ' ||
    getpos(t, t->p.y, t->p.x + 1) == 'O') {
        t->map2d[t->p.y][t->p.x + 1] = 'P';
        t->map2d[t->p.y][t->p.x] = ' ';
        t->p.x = t->p.x + 1;
    }
    if (getpos(t, t->p.y, t->p.x +1) == 'X') {
        boxright(t, key);
    }
    keepo(t);
    return (0);
}

int boxleft(table *t, int key)
{
    if (getpos(t, t->p.y, t->p.x -2) == '#' ||
    getpos(t, t->p.y, t->p.x -2) == 'X')
        return (0);
    if (getpos(t, t->p.y, t->p.x -2) != '#') {
            t->map2d[t->p.y][t->p.x -2] = 'X';
            t->map2d[t->p.y][t->p.x -1] = 'P';
            t->map2d[t->p.y][t->p.x] = ' ';
            t->p.x = t->p.x - 1;
            t->x.first->x = t->p.x -2;
    }
}

static int leftmove(table *t, int key)
{
    if (getpos(t, t->p.y, t->p.x) == '#')
        return (0);
    if (getpos(t, t->p.y, t->p.x - 1) == ' ' ||
    getpos(t, t->p.y, t->p.x - 1) == 'O') {
        t->map2d[t->p.y][t->p.x - 1] = 'P';
        t->map2d[t->p.y][t->p.x] = ' ';
        t->p.x = t->p.x - 1;
        keepo(t);
    }
    if (getpos(t, t->p.y, t->p.x -1) == 'X') {
        boxleft(t, key);
    }
    keepo(t);
    return (0);
}

int movement(table *t, int key)
{
    if (key == KEY_UP)
        upmove(t, key);
    if (key == KEY_DOWN)
        downmove(t, key);
    if (key == KEY_LEFT)
        leftmove(t, key);
    if (key == KEY_RIGHT)
        rightmove(t, key);
    keepo(t);
}
