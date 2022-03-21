/*
** EPITECH PROJECT, 2022
** my project
** File description:
** main
*/

#include "./include/my.h"
#include "./include/gen.h"

maze_t *build_maze_from_file(char *filepath)
{
    maze_t *maze = malloc(sizeof(maze_t));
    int error = 0;

    maze->height = 0;
    maze->width = 0;
    maze->maze = load_2d_arr_from_file(filepath, &(maze->height),
    &(maze->width), &error);
    if (maze->maze == NULL) {
        free(maze);
        return NULL;
    }
}

int main(int argc, char **argv)
{
    maze_t *maze = build_maze_from_file(argv[1]);

    if (maze == NULL)
        return 84;
    solve_maze(maze);
}
