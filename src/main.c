/*
** EPITECH PROJECT, 2023
** example_sokoban.c
** File description:
** -
*/
#include "../include/my.h"
#include "../include/so.h"

void hfunction(void)
{
    my_printf("USAGE\n\t./mysokoban map\nDESCRIPTION\n");
    my_printf("\tmap\tfile representing the werehouse");
    my_printf("map, containing '#' for walls, \n\t\t'P' ");
    my_printf("for the player, 'X' for the boxes and 'O' ");
    my_printf("for storage location.");
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        write(2, "Number of arguments incorrect\n", 31);
        return (84);
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h' && argc == 2)
        hfunction();
    if (error_checker(argc, argv) == 1)
        return (84);
    games(argv[1]);
}
