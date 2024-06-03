/*
** EPITECH PROJECT, 2023
** game.c
** File description:
** game functions
*/

#include "../include/so.h"

void printmap(table *t, int y, int x)
{
    getmaxyx(stdscr, y, x);
    for (int i = 0; t->map2d[i] != NULL; i++)
        mvprintw(((y - t->height) / 2) + i, ((x - t->maxlen) / 2),
        "%s", t->map2d[i]);
}

char getpos(table *t, int y, int x)
{
    if (x < 0 || y < 0)
        return ('#');
    if (y >= t->height)
        return ('#');
    if (t->p.x >= my_strlen(t->map2d[y]))
        return ('#');
    return (t->map2d[y][x]);
}

void findobjects(table *t, int i)
{
    number *n;

    for (int j = 0; t->map2d[i][j] != 0; j++) {
        if (t->map2d[i][j] == 'P') {
            t->p.y = i;
            t->p.x = j;
        }
        if (t->map2d[i][j] == 'X') {
            t->x.first = addlinked(&t->x, i, j);
        }
        if (t->map2d[i][j] == 'O') {
            t->x.first = addlinked(&t->o, i, j);
        }
    }
}

static int max_lenght(table *t)
{
    int max = 0;
    int i = 0;
    int len;

    while (i < t->height) {
        len = my_strlen(t->map2d[i]);
        if (len > max)
            max = len;
        i ++;
    }
    return (max);
}

static void get_2d_array(table *t)
{
    int i = 0;
    char *next = t->buffer;

    t->map2d = malloc(sizeof(char *) *(t->height + 1));
    if (t->map2d == NULL)
        return;
    while (i < t->height){
        t->map2d[i] = malloc(my_strlen(t->buffer));
        if (t->map2d[i] == NULL)
            return;
        t->map2d[i] = next;
        next = my_strchr(next, '\n') + 1;
        if (i != t->height - 1)
            next[-1] = 0;
        i++;
    }
    for (int i = 0; i < t->height; i++) {
        findobjects(t, i);
    }
}

static int get_size(char *path)
{
    struct stat file;

    if (stat(path, &file) < 0)
        return (-1);
    return (file.st_size);
}

static char *getbuffer(char *path)
{
    int fd = open(path, O_RDONLY);
    int size = get_size(path);
    char *buffer = malloc(sizeof(char) * (size + 1));

    read(fd, buffer, size);
    buffer[size] = 0;
    return (buffer);
}

void screen(int key, table *t)
{
    int x;
    int y;

    initscr();
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, y, x);
    printmap(t, y, x);
    while (key != 'q'){
        refresh();
        key = getch();
        movement(t, key);
        printmap(t, y, x);
    }
    refresh();
    endwin();
    for (int i = 0; t->map2d[i] != NULL; i++) {
        my_putstr(t->map2d[i]);
        my_putchar('\n');
    }
}

void games(char *path)
{
    int key;
    table t;

    t.buffer = getbuffer(path);
    t.height = my_strchr_count(t.buffer, '\n') +1;
    get_2d_array(&t);
    t.maxlen = max_lenght(&t);
    screen(key, &t);
    free(t.buffer);
    free(t.map2d);
}
