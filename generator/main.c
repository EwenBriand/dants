/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-3-dante-ewen.briand
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gen.h"
#include "structs.h"

int main(int argc, char **argv)
{
    maze_t *my_maze = set_maze_builder(atoi(argv[1]), atoi(argv[2]));

    if (my_maze == NULL)
        return 84;
    srand(time(NULL));
    generate_maze(my_maze);
    display_maze(my_maze);
    destroy_maze(my_maze);
    return 0;
}
