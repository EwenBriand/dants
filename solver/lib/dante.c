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

int **build_parents_from_mother(node_t *mother, int child_x, int child_y)
{
    int **parents = malloc(sizeof(int *) * (mother->p_len + 1));

    for (int i = 0; i < mother->p_len; ++i) {
        parents[i] = malloc(sizeof(int) * 2);
        parents[i][Y] = mother->parents[i][Y];
        parents[i][X] = mother->parents[i][X];
    }
    parents[mother->p_len] = malloc(sizeof(int) * 2);
    parents[mother->p_len][Y] = child_y;
    parents[mother->p_len][X] = child_x;
    return parents;
}

void add_neighboors_to_list(
    node_t *mother, maze_t *maze, int *out, node_t **list)
{
    int pos[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int tmp_x = 0;
    int tmp_y = 0;

    if (mother == NULL)
        return;
    for (int i = 0; i < 4; ++i) {
        tmp_x = mother->parents[mother->p_len - 1][X] + pos[i][X];
        tmp_y = mother->parents[mother->p_len - 1][Y] + pos[i][Y];
        if (tmp_x < 0 || tmp_x >= maze->width || tmp_y < 0
            || tmp_y >= maze->height)
            continue;
        if (maze->maze[tmp_y][tmp_x] == '*') {
            list_add(list,
                new_node(build_parents_from_mother(mother, tmp_x, tmp_y),
                    mother->p_len + 1, NULL, maze));
            maze->maze[tmp_y][tmp_x] = 't';
        }
        if (tmp_x == maze->height - 1 && tmp_y == maze->width - 1)
            *out = 1;
    }
}

void destroy_list(node_t *list)
{
    if (list == NULL)
        return;
    for (int i = 0; i < list->p_len; ++i) {
        free(list->parents[i]);
    }
    free(list->parents);
    destroy_list(list->next);
    free(list);
}

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
