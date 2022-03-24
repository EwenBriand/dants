/*
** EPITECH PROJECT, 2021
** solver
** File description:
** node_utils.c
*/

#include "structs.h"
#include "gen.h"
#include <stdlib.h>

node_t *new_node(int **parents, int p_len, node_t *next, maze_t *maze)
{
    node_t *new = malloc(sizeof(node_t));

    if (new == NULL)
        return NULL;
    new->next = next;
    new->parents = parents;
    new->distance = get_manhattan_distance(maze, parents, p_len);
    new->p_len = p_len;
    new->y = new->parents[p_len - 1][0];
    new->x = new->parents[p_len - 1][1];
    return new;
}

node_t *pop_at(int i, node_t **list)
{
    node_t *tmp = NULL;
    node_t *popped = NULL;

    if (list == NULL || (*list) == NULL || i < 0) {
        return NULL;
    }
    if (i == 0) {
        popped = (*list);
        (*list) = (*list)->next;
        return popped;
    }
    if (i == 1 && (*list)->next != NULL) {
        tmp = (*list)->next->next;
        popped = (*list)->next;
        popped->next = NULL;
        (*list)->next = tmp;
        return popped;
    }
    return pop_at(i - 1, &((*list)->next));
}
