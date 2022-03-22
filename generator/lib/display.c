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
    for (int i = 0; i < maze->height - 1; ++i) {
        printf("%s\n", maze->maze[i]);
    }
    printf("%s", maze->maze[maze->height - 1]);
    // for (int i = 0; i < maze->height; ++i) {
    //     for (int j = 0; j < maze->width; ++j) {
    //         if (maze->maze[i][j] == 'X')
    //             printf("%c", '#');
    //         else
    //             printf("%c", '.');
    //         printf(" ");
    //     }
    //     printf("\n");
    // }
}
