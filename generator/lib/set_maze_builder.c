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
    node_t *first = new_node(0, 2, NULL);
    list_add(&first, new_node(2, 0, first), &(maze->node_count));
    return first;
}

maze_t *set_maze_builder(int x, int y)
{
    maze_t *new = malloc(sizeof(maze_t));
    new->width = x;
    new->height = y;
    new->maze = set_my_maze(x, y);
    new->node_count = 2;
    new->list = set_chained_list(new);
    return new;
}

void free_list(node_t *list)
{
    while (list->next != NULL) {
        free_list(list->next);
        list->next = NULL;
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
