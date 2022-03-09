/*
** EPITECH PROJECT, 2022
** dants
** File description:
** set_line_link
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "gen.h"
#include "structs.h"

void group_rooms(maze_builder_t *maze)
{
    struct timeval dtime;
    int act_pos = 0;
    char *display = malloc(sizeof(char) * (maze->dim_y * 2 + 2));
    int curr_first = maze->first_index % 2;
    int curr_second = (maze->first_index + 1) % 2;

    gettimeofday(&dtime, NULL);
    srandom(dtime.tv_sec + dtime.tv_usec * 1000);
    for (int i = 0; i < maze->dim_x - 1; ++i) {
        if (maze->line[curr_first][i + 1] == maze->line[curr_first][i]) {
            display[act_pos++] = '\'';
            display[act_pos++] = 'X';
        } else if (rand() % 2 == 0) {
            maze->line[curr_first][i + 1] = maze->line[curr_first][i];
            display[act_pos++] = 'o';
            display[act_pos++] = 'o';
        } else {
            maze->line[curr_first][i + 1] = ++(maze->group_id);
            display[act_pos++] = '.';
            display[act_pos++] = 'X';
        }
    // printf("act pos is %d and dimx is %d\n", act_pos, maze->dim_x);
    }
    // if (maze->curr_y != 0)
    //     display[act_pos++] = (maze->line[curr_first][maze->dim_x * 2] == maze->line[curr_second][maze->dim_x * 2]) ? '*' : 'X';
    // else
    //     display[act_pos++] = '*';
    display[act_pos++] = '*';
    display[act_pos] = '\0';
    printf("%s", display);
    if (maze->fill_dim_x == 1) {
        printf("%c", 'X');
    }
    putchar('\n');
}
