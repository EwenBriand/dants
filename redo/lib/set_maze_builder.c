/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-3-dante-ewen.briand
** File description:
** set_maze_builder.c
*/

#include <stdlib.h>
#include "structs.h"

int **init_lines(int y, int x, maze_builder_t *maze)
{
    int **line = malloc(sizeof(int *) * 2);

    if (line == NULL)
        return NULL;
    line[0] = malloc(sizeof(int) * maze->dim_x);
    if (line[0] == NULL) {
        free(line);
        return NULL;
    }
    line[1] = malloc(sizeof(int) * maze->dim_x);
    if (line[1] == NULL) {
        free(line[0]);
        free(line);
        return NULL;
    }
    for (int i = 0; i < maze->dim_x; i++) {
        line[0][i] = (maze->group_id)++;
        line[1][i] = -1;
    }
    return line;
}

void init_counters(maze_builder_t *maze)
{
    maze->vertical_counters = malloc(sizeof(int) * maze->dim_x);
    maze->horizontal_counters = malloc(sizeof(int) * maze->dim_x);
    for (int i = 0; i < maze->dim_x; ++i) {
        maze->vertical_counters[i] = 0;
        maze->horizontal_counters[i] = 0;
    }
}

maze_builder_t *set_maze_builder(int x, int y)
{
    maze_builder_t *new = malloc(sizeof(maze_builder_t));

    if (new == NULL)
        return NULL;
    new->group_id = 0;
    new->dim_x = x / 2 + 1;
    // new->dim_x += ((x % 2) == 0) ? 0 : 1;
    new->dim_y = y / 2;
    new->fill_dim_y = ((x % 2) == 0) ? 1 : 0;
    new->fill_dim_x = ((y % 2) == 0) ? 1 : 0;
    new->curr_x = 0;
    new->curr_y = 0;
    new->line = init_lines(new->dim_x, new->dim_y, new);
    if (new->line == NULL) {
        free(new);
        return NULL;
    }
    init_counters(new);
    new->first_index = 0;
    return new;
}

void destroy_maze_builder(maze_builder_t *maze)
{
    free(maze->line[0]);
    free(maze->line[1]);
    free(maze->line);
    free(maze->vertical_counters);
    free(maze->horizontal_counters);
    free(maze);

}
