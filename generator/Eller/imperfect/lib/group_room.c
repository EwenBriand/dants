/*
** EPITECH PROJECT, 2022
** dants
** File description:
** set_line_link
*/

#include <stdlib.h>
#include <time.h>

#include "gen.h"
#include "structs.h"

void group_rooms(maze_builder_t *maze)
{
    int curr_first = maze->first_index % 2;
    // srand(time(NULL));

    for (int i = 0; i < maze->dim_x - 1; ++i) {
        if (maze->line[curr_first][i + 1] == maze->line[curr_first][i])
            continue;
        else if (rand() % 2 == 0)
            maze->line[curr_first][i + 1] = maze->line[curr_first][i];
        else
            maze->line[curr_first][i + 1] = ++(maze->group_id);
    }
}
