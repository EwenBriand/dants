/*
** EPITECH PROJECT, 2021
** generator
** File description:
** cell_array.c
*/

#include "gen.h"
#include "structs.h"
#include <stdlib.h>
#include <stdio.h>

int *pop_nearest(int i, maze_t *maze, int *count)
{
    int *tmp = malloc(sizeof(int) * 2);

    for (int j = 1; j < maze->array_len; ++j) {
        if (maze->array[(i + j) % maze->array_len] != NULL) {
            tmp = malloc(sizeof(int) * 2);
            tmp[Y] = maze->array[(i + j) % maze->array_len][Y];
            tmp[X] = maze->array[(i + j) % maze->array_len][X];
            maze->array[(i + j) % maze->array_len] = NULL;
            return tmp;
        }
    }
    return NULL;
}

int *array_pop_at_i(int i, maze_t *maze, int *count)
{
    int *tmp = NULL;

    if (maze == NULL || maze->array == NULL)
        return NULL;
    if (i > maze->array_len)
        i %= maze->array_len;
    if (maze->array[i] == NULL)
        return pop_nearest(i, maze, count);
    tmp = malloc(sizeof(int) * 2);
    tmp[Y] = maze->array[i][Y];
    tmp[X] = maze->array[i][X];
    maze->array[i] = NULL;
    --*count;
    return tmp;
}

void add_in_array(maze_t *maze, int x, int y)
{
    for (int i = 0; i < maze->array_len; ++i) {
        if (maze->array[i] == NULL) {
            maze->array[i] = malloc(sizeof(int) * 2);
            maze->array[i][Y] = y;
            maze->array[i][X] = x;
            ++(maze->node_count);
            return;
        }
    }
    maze->array_len *= 2;
    maze->array = (int **) realloc(maze->array,
    sizeof(int) * 2 * maze->array_len);
    if (maze->array == NULL) {
        perror("Ran out of memory, realloc not possible\n");
        exit(84);
    }
    maze->array[maze->array_len / 2 + 1] = malloc(sizeof(int) * 2);
    maze->array[maze->array_len / 2 + 1][Y] = y;
    maze->array[maze->array_len / 2 + 1][X] = x;
    ++(maze->node_count);
}

void add_pos_to_array_if_available(maze_t *maze, int x, int y)
{
    if (x < 0 || x >= maze->width || y < 0 || y >= maze->height)
        return;
    if (x < 0 || x >= maze->width || y < 0
    || y >= maze->height) {
        return;
        }
    if (maze->maze[y][x] == 'X') {
        add_in_array(maze, x, y);
    }
}
