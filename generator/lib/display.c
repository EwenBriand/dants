/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** prim.c
*/

#include <stdio.h>

#include "gen.h"
#include "structs.h"

void display_maze(maze_t *maze)
{
    printf("in dispaying\n");
    printf("maze height: %d\n", maze->height);
    printf("maze->height is ok\n");

    for (int i = 0; i < maze->height; ++i) {
        printf("%s\n", maze->maze[i]);
    }
}
