/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-3-dante-ewen.briand
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gen.h"
#include "structs.h"

int check(char *name)
{
    char perf[] = "perfect\0";
    if (strlen(name) != strlen(perf))
        return 0;
    for (int i = 0; name[i] != '\0'; ++i)
        if (name[i] != perf[i])
            return 0;
    return 1;
}

int main(int argc, char **argv)
{
    maze_t *my_maze;
    int perfect = 0;

    if (argc < 3)
        return 84;
    my_maze = set_maze_builder(atoi(argv[1]), atoi(argv[2]));
    if (argc == 4 && check(argv[3]) == 1) {
        perfect = 1;
    }
    if (my_maze == NULL)
        return 84;
    srand(time(NULL));
    generate_maze(my_maze, perfect);
    if (my_maze->width % 2 == 0 && my_maze->height % 2 == 0)
        my_maze->maze[my_maze->height - 1][my_maze->width - 2] = '*';

    my_maze->maze[my_maze->height - 1][my_maze->width - 1] = '*';
    display_maze(my_maze);
    destroy_maze(my_maze);
    return 0;
}
