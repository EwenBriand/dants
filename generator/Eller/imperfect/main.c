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
    maze_builder_t *my_maze = set_maze_builder(atoi(argv[1]), atoi(argv[2]));
    generate_map(my_maze);
    destroy_maze_builder(my_maze);
    return 0;
}
