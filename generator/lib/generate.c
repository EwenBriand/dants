/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-3-dante-ewen.briand
** File description:
** generate.c
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "structs.h"
#include "gen.h"

void show_links(maze_builder_t *maze)
{
    char *line = malloc(sizeof(char) * (maze->dim_y * 2 + 2));
    int pos_act = 0;
    int curr_first = maze->first_index % 2;
    int curr_second = (maze->first_index + 1) % 2;

    for (int i = 0; i < maze->dim_x; ++i) {
        if (maze->line[curr_second][i] == maze->line[curr_first][i]) {
            line[pos_act] = '*';
            line[pos_act + 1] = 'X';
            pos_act += 2;
        } else {
            line[pos_act] = 'X';
            line[pos_act + 1] = 'X';
            pos_act += 2;
        }
    }
    line[pos_act] = '\0';
    write(1, line, (int) strlen(line) - 1);
    if (maze->fill_dim_x == 1)
        putchar('X');
    putchar('\n');
    free(line);
}

void show_first_line(maze_builder_t *maze)
{
    int curr_first = maze->first_index % 2;
    for (int i = 0; i < maze->dim_x - 1; ++i) {
        putchar('*');
        if (maze->line[curr_first][i + 1]
        != maze->line[curr_first][i])
            putchar('X');
        else
            putchar('*');
    }
    putchar('*');
    if (maze->fill_dim_x == 1)
        putchar('X');
    putchar('\n');
}

int get_curr_group_len(maze_builder_t *maze, int start_index)
{
    int i = start_index;
    int curr_first = maze->first_index % 2;
    int curr_second = (maze->first_index + 1) % 2;

    for (;  i < maze->dim_x
    && maze->line[curr_first][i] == maze->line[curr_first][start_index]; ++i);
    return i;
}

void link_group(int *index, maze_builder_t *maze)
{
    int len = get_curr_group_len(maze, *index);
    int curr_first = maze->first_index % 2;
    int curr_second = (maze->first_index + 1) % 2;
    int link_nbr = 0;
    int rdm = 0;
    struct timeval dtime;

    gettimeofday(&dtime, NULL);
    srandom(dtime.tv_sec + dtime.tv_usec * 10000);
    for (int i = *index; i < len; ++i) {
        rdm = random() % 100;
       //  printf("random: %d\n", rdm);
        if (rdm < LINK_FACTOR) {
            maze->line[curr_second][i] = maze->line[curr_first][i];
            ++link_nbr;
        } else
            maze->line[curr_second][i] = (maze->group_id)++;
    }
    if (link_nbr == 0)
        maze->line[curr_second][len - 1] = maze->line[curr_first][len - 1];
}

void link_lines(maze_builder_t *maze)
{
    for (int i = 0; i < maze->dim_x; ++i) {
        link_group(&i, maze);
    }
}

void iterate_eller(maze_builder_t *maze, int last)
{
    group_rooms(maze);
 //   show_first_line(maze);
    link_lines(maze);
    show_links(maze);
    ++(maze->first_index);
}

void generate_map(maze_builder_t *maze)
{
    for (int i = 0; i < maze->dim_y - 1; ++i) {
        iterate_eller(maze, i);
    }
    for (int i = 0; i < maze->dim_x * 2 - 1; ++i)
        putchar('*');

    if (maze->fill_dim_x == 1)
        putchar('*');
    putchar('\n');
}
