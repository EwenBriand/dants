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
    maze_t *my_maze;
    int perfect = 0;

    if (argc < 3)
        return 84;
    my_maze = set_maze_builder(atoi(argv[1]), atoi(argv[2]));
    if (argc == 4 && argv[3][0] == '1')
        perfect = 1;
    if (my_maze == NULL)
        return 84;
    srand(time(NULL));
    generate_maze(my_maze, perfect);
    display_maze(my_maze);
    destroy_maze(my_maze);
    return 0;
}
