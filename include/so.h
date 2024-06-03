/*
** EPITECH PROJECT, 2023
** so.h
** File description:
** implicit declaration for sokoban.
*/
#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct player {
    int x;
    int y;
} player;

typedef struct tile {
    int x;
    int y;
    struct tile *next;
} tile;

typedef struct number {
    int n_x;
    int n_o;
} number;

typedef struct list {
    tile *first;
} list_t;

typedef struct table {
    char *buffer;
    char **map2d;
    int height;
    int maxlen;
    player p;
    list_t o;
    list_t x;
    number n;
} table;

void hfunction(void);
int error_checker(int ac, char **av);
void print_usage(int argc, char **argv);
void games(char *path);
void move_player(char **map_array, int c);
int check_map(char *path);
int needed_map(int fd, int size, char *buffer, char *path);
int get_map_size(char *path);
char getpos(table *t, int y, int x);
tile *addlinked(list_t *list, unsigned int y, unsigned int x);
int movement(table *t, int key);
void keepo(table *t);
tile *searcho(table *t, int x, int y);

    #include <sys/stat.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <curses.h>
    #include <fcntl.h>
    #include <stddef.h>
    #include "../include/my.h"

#endif
