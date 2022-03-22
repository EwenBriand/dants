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
    if (list != NULL)
        show_list(list->next);
}

node_t *pop(node_t **list, int *count)
{
    node_t *tmp = *list;

    if (list == NULL)
        return NULL;
    (*list) = (*list)->next;
    tmp->next = NULL;
    --*count;
    return tmp;
}

void list_add(node_t **list, node_t *to_add, int *count)
{
    if (*list == NULL) {
        (*list) = to_add;
        (*list)->next = *list;
        return;
    }
    to_add->next = *list;
    ++*count;
    *list = to_add;
}

node_t *new_node(int x, int y, node_t *next)
{
    node_t *new = malloc(sizeof(node_t));

    if (new == NULL)
        return NULL;
    new->next = next;
    new->x = x;
    new->y = y;
    return new;
}

node_t *pop_at(int i, node_t **list, int *count)
{
    node_t *tmp = NULL;
    node_t *popped = NULL;

    if (list == NULL || (*list) == NULL || i >= *count || i < 0) {
        return NULL;
    }
    if (i == 0) {
        popped = (*list);
        (*list) = (*list)->next;
        --(*count);
        return popped;
    }
    if (i == 1 && (*list)->next != NULL) {
        tmp = (*list)->next->next;
        popped = (*list)->next;
        popped->next = NULL;
        (*list)->next = tmp;
        --(*count);
        return popped;
    }
    return pop_at(i - 1, &((*list)->next), count);
}

int get_node_index_in_list(node_t *list, int x, int y)
{
    int return_val = 0;

    if (list == NULL)
        return 0;
    if (list->x == x && list->y == y)
        return 1;
    return_val = get_node_index_in_list(list->next, x, y);
    if (return_val == 0)
        return 0;
    return 1 + return_val;
}
