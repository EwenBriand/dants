/*
** EPITECH PROJECT, 2022
** dants
** File description:
** add_neighboors_to_list
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
    int x = 0;
    int y = 0;
    if (mother == NULL)
        return;
    for (int i = 0; i < 4; ++i) {
        x = mother->parents[mother->p_len - 1][X] + pos[i][X];
        y = mother->parents[mother->p_len - 1][Y] + pos[i][Y];
        if (x < 0 || x >= maze->width || y < 0 || y >= maze->height)
            continue;
        if (maze->maze[y][x] == '*') {
            list_add(list,
                new_node(build_parents_from_mother(mother, x, y),
                    mother->p_len + 1, NULL, maze));
            maze->maze[y][x] = 't';
        }
        if (x == maze->height - 1 && y == maze->width - 1)
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
