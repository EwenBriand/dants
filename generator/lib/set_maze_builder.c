/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-3-dante-ewen.briand
** File description:
** set_maze_builder.c
*/

#include <stdlib.h>
#include "gen.h"
#include "structs.h"

char **set_my_maze(int x, int y)
{
    char **maze = malloc(sizeof(char *) * y);
    for (int i = 0; i < y; ++i) {
        maze[i] = malloc(sizeof(char) * (x + 1));
        for (int j = 0; j < x; ++j)
            maze[i][j] = 'X';
        maze[i][x] = '\0';
    }
    maze[0][0] = '*';
    return maze;
}

node_t *set_chained_list(maze_t *maze)
{
    node_t *first = new_node(0, 2, new_node(2, 0, NULL));
    return first;
}

void set_array(maze_t *new)
{
    new->array[0] = malloc(sizeof(int) * 2);
    new->array[0][Y] = 0;
    new->array[0][X] = 2;
    new->array[1] = malloc(sizeof(int) * 2);
    new->array[1][Y] = 2;
    new->array[1][X] = 0;
    new->array[2] = NULL;
    new->array[3] = NULL;
    new->array[4] = NULL;
}

maze_t *set_maze_builder(int x, int y)
{
    maze_t *new = malloc(sizeof(maze_t));
    new->width = x;
    new->height = y;
    new->maze = set_my_maze(x, y);
    new->node_count = 2;
    new->list = set_chained_list(new);
    new->array = malloc(sizeof(int *) * 5);
    set_array(new);
    new->array_len = 5;
    new->max_id_written = 2;
    return new;
}

void free_list(node_t *list)
{
    if (list == NULL)
        return;
    if (list->next != NULL) {
        free_list(list->next);
    }
    free(list);
}

void destroy_maze(maze_t *maze)
{
    free_list(maze->list);
    for (int i = 0; i < maze->height; ++i) {
        free(maze->maze[i]);
    }
    free(maze->maze);
    free(maze);
}
