/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-3-dante-ewen.briand
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>

#include "structs.h"
#include "gen.h"

int main(int argc, char **argv)
{
    srand(time(NULL));
    maze_builder_t *maze = set_maze_builder(atoi(argv[1]), atoi(argv[2]));
    iterate_eller(maze, atoi(argv[2]));
    destroy_maze_builder(maze);
    return 0;
}
