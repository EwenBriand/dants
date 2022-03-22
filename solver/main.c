/*
** EPITECH PROJECT, 2022
** my project
** File description:
** main
*/

#include <stdio.h>
#include "./include/gen.h"
#include "./include/my.h"

maze_t *build_maze_from_file(char *filepath)
{
    maze_t *maze = malloc(sizeof(maze_t));
    int error = 0;

    maze->height = 0;
    maze->width = 0;
    maze->maze = load_2d_arr_from_file(
        filepath, &(maze->height), &(maze->width), &error);
    if (maze->maze == NULL) {
        free(maze);
        return NULL;
    }
    return maze;
}

int main(int argc, char **argv)
{
    maze_t *maze = build_maze_from_file(argv[1]);
    if (maze == NULL) {
        printf("Error");
        return 84;
    }
    printf("%i %i\n", maze->height, maze->width);

    if (solve_maze(maze)) {
        for (int i = 0; i < maze->height - 1; ++i) {
            free(maze->maze[i]);
        }
        free(maze->maze[maze->height - 1]);
        free(maze->maze);
        free(maze);
        return 0;
    }

    for (int i = 0; i < maze->height - 1; ++i) {
        printf("%s", maze->maze[i]);
        free(maze->maze[i]);
    }
    printf("%s", maze->maze[maze->height - 1]);
    free(maze->maze[maze->height - 1]);
    free(maze->maze);
    free(maze);
    return 0;
}
