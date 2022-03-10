/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-3-dante-ewen.briand
** File description:
** set_maze_builder.c
*/

#include <stdlib.h>
#include "structs.h"

int **init_lines(int y, int x)
{
    int **line = malloc(sizeof(int *) * 2);

    if (line == NULL)
        return NULL;
    line[0] = malloc(sizeof(int) * y);
    if (line[0] == NULL) {
        free(line);
        return NULL;
    }
    line[1] = malloc(sizeof(int) * y);
    if (line[1] == NULL) {
        free(line[0]);
        free(line);
        return NULL;
    }
    for (int i = 0; i < x; i++) {
        line[0][i] = i;
        line[1][i] = -1;
    }
    return line;
}

maze_builder_t *set_maze_builder(int x, int y)
{
    maze_builder_t *new = malloc(sizeof(maze_builder_t));

    if (new == NULL)
        return NULL;
    new->dim_x = (x + 1) / 2;
    new->dim_y = (y + 1) / 2;
    new->fill_dim_y = ((x % 2) == 0) ? 1 : 0;
    new->fill_dim_x = ((y % 2) == 0) ? 1 : 0;
    new->curr_x = 0;
    new->curr_y = 0;
    new->line = init_lines(new->dim_x, new->dim_y);
    if (new->line == NULL) {
        free(new);
        return NULL;
    }
    new->array = malloc(sizeof(int *) * (x * y / 2 + 1));
    new->array_len = (x * y / 2 + 1);
    new->first_index = 0;
    new->group_id = 0;
    return new;
}

void destroy_maze_builder(maze_builder_t *maze_builder)
{
    free(maze_builder->line[0]);
    free(maze_builder->line[1]);
    free(maze_builder->line);
    free(maze_builder);
}
