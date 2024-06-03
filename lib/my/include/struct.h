/*
** EPITECH PROJECT, 2023
** struct.h
** File description:
** struct my ls
*/

#ifndef STRUCTS_H_
    #define STRUCTS_H_

    #include <stdbool.h>
    #include <stdlib.h>

typedef struct infos{
    char const *file_name;
    char type;
    int *inode;
    int hard_link;
    int *size;
    int allocated_space;
    unsigned int minor;
    unsigned int mayor;
    int *UID;
    int *GID;
}infos;

#endif
