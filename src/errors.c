/*
** EPITECH PROJECT, 2023
** errors.c
** File description:
** -
*/
#include "../include/my.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int get_map_size(char *path)
{
    struct stat file;

    if (stat(path, &file) < 0){
        return (1);
    }
    return (file.st_size);
}

int needed_map(char *path, char *buffer)
{
    int box = my_strchr_count(buffer, 88);
    int localitation = my_strchr_count(buffer, 79);

    if (box < localitation){
        write(2, "Not enough boxes\n", 18);
        return (1);
    }
    return (0);
}

int check_map(char *path)
{
    int fd = open(path, O_RDONLY);
    int size = get_map_size(path);
    char *buffer = malloc(sizeof(char) * size);

    if (fd == -1 || size == 1){
        write(2, "Invalid file", 13);
        return (1);
    }
    read(fd, buffer, size);
    for (int f = 0; buffer[f] != '\0'; f++){
        if (buffer[f] != '#' && buffer[f] != 32 && buffer[f] != '\n' &&
        buffer[f] != 'X' && buffer[f] != 'O' && buffer[f] != 'P'){
            write(2, "Characters fail", 16);
            return (1);
        }
    }
    needed_map(path, buffer);
}

int error_checker(int ac, char **av)
{
    if (ac != 2) {
        write(2, "Invalid number of arguments\n", 29);
        return (1);
    }
    if (check_map(av[1]) == 1)
        return (1);
    else
        return (0);
}
