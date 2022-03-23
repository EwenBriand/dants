/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** list_utils.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <structs.h>
#include <unistd.h>

void show_list(node_t *list)
{
    if (list != NULL) {
        printf("---(%d, %d)---%p---\n", list->x, list->y, list);
        show_list(list->next);
    }
}

node_t *pop(node_t **list)
{
    node_t *tmp = *list;

    if (list == NULL)
        return NULL;
    (*list) = (*list)->next;
    tmp->next = NULL;
    return tmp;
}

int args_are_null(node_t **list, node_t *to_add)
{
    if (to_add == NULL)
        return 1;
    if (list == NULL)
        return 1;
    if (*list == NULL) {
        *list = to_add;
        return 1;
    }
    return 0;
}

void list_add(node_t **list, node_t *to_add)
{
    if (args_are_null(list, to_add))
        return;
    if ((*list)->distance > to_add->distance) {
        to_add->next = *list;
        *list = to_add;
        return;
    }
    if ((*list)->next == NULL) {
        (*list)->next = to_add;
        return;
    }
    if ((*list)->next->distance > to_add->distance) {
        to_add->next = (*list)->next;
        (*list)->next = to_add;
        return;
    }
    list_add(&((*list)->next), to_add);
}

int get_manhattan_distance(maze_t *maze, int **parents, int p_len)
{
    return maze->height - parents[p_len - 1][0] + maze->width
        - parents[p_len - 1][1];
}

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
