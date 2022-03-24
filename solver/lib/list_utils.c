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
