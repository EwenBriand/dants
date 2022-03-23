/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-3-dante-ewen.briand
** File description:
** dante.c
*/

#include <stdio.h>
#include <stdlib.h>

#include "gen.h"
#include "structs.h"

void destroy_list(node_t *list);
void add_neighboors_to_list(
    node_t *mother, maze_t *maze, int *out, node_t **list);

void traceback(maze_t *maze, node_t *node)
{
    if (node == NULL)
        return;
    for (int i = 0; i < maze->height; ++i) {
        for (int j = 0; j < maze->width; ++j) {
            if (maze->maze[i][j] == 't')
                maze->maze[i][j] = '*';
        }
    }
    for (int i = 0; i < node->p_len; ++i) {
        maze->maze[node->parents[i][Y]][node->parents[i][X]] = 'o';
    }
    destroy_list(node);
}

int **init_zero_parents(maze_t *maze)
{
    int **zero_parents = malloc(sizeof(int *));
    zero_parents[0] = malloc(sizeof(int) * 2);
    zero_parents[0][0] = 0;
    zero_parents[0][1] = 0;
    maze->maze[0][0] = 't';
    return zero_parents;
}

void free_node(node_t *node)
{
    for (int i = 0; i < node->p_len; ++i) {
        free(node->parents[i]);
    }
    free(node->parents);
}

void free_all_node(node_t *node)
{
    if (node == NULL)
        return;
    if (node->next != NULL)
        free_all_node(node->next);
    free_node(node);
}

int solve_maze(maze_t *maze)
{
    node_t *available_nodes = new_node(init_zero_parents(maze), 1, NULL, maze);
    node_t *tmp = NULL;
    int out = 0;

    while (!out) {
        if (available_nodes == NULL) {
            break;
        }
        tmp = pop(&available_nodes);
        add_neighboors_to_list(tmp, maze, &out, &available_nodes);
        free_node(tmp);
        free(tmp);
    }
    if (available_nodes == NULL) {
        printf("no solution found\n");
        return 1;
    }
    traceback(maze, available_nodes);
    return 0;
}
