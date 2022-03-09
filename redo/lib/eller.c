/*
** EPITECH PROJECT, 2021
** redo
** File description:
** eller.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gen.h"
#include "structs.h"

int my_rand(void)
{
    return rand();
}

int do_merge_procedural(maze_builder_t *maze, int i)
{
    int choice = rand() % 100 < MERGE_FACTOR;

    if (choice && maze->horizontal_counters[i] < HORIZONTAL_LIMIT) {
        ++maze->horizontal_counters[i];
        maze->horizontal_counters[i + 1] = maze->horizontal_counters[i];
        return 0;
    }
    if (maze->horizontal_counters[i] < HORIZONTAL_LIMIT && !choice) {
        choice = rand() % 100 < MERGE_FACTOR;
        if (choice && maze->horizontal_counters[i] < HORIZONTAL_LIMIT) {
            ++maze->horizontal_counters[i];
            maze->horizontal_counters[i + 1] = maze->horizontal_counters[i];
            return 0;
        }
    }
    return 1;
}

void reset_horizontal_weights(maze_builder_t *maze)
{
    for (int i = 0; i < maze->dim_x; ++i) {
        maze->horizontal_counters[i] = 1;
    }
}

void extend_curr_group(int *i, maze_builder_t *maze)
{
    int curr_first = maze->first_index % 2;
    char cell[] = " a\0";
    char previous = '\0';

    while (*i < maze->dim_x - 1) {
        if (0 || maze->line[curr_first][*i] == maze->line[curr_first][*i + 1]
            || previous == maze->line[curr_first][*i + 1]) {
            cell[1] = '#';
            ++(*i);
        } else {
            cell[1] = ' ';
            previous = maze->line[curr_first][*i + 1];
            maze->line[curr_first][*i + 1] = maze->line[curr_first][*i];
            ++(*i);
        }
        printf("%s", cell);
    }
    ++(*i);
    if (*i == maze->dim_x) {
        if (!maze->fill_dim_x)
            printf(" ");
    }
    reset_horizontal_weights(maze);
}

void merge_groups(maze_builder_t *maze)
{
    for (int i = 0; i < maze->dim_x - 1; ++i) {
        extend_curr_group(&i, maze);
    }
    printf("\n");
}

int do_link_procedural(maze_builder_t *maze, int i)
{
    int choice = my_rand() % 100 < LINK_FACTOR;

    if (choice)
        ++(maze->vertical_counters[i]);
    else
        --(maze->vertical_counters[i]);
    if (maze->vertical_counters[i] > VERTICAL_LIMIT && choice) {
        maze->vertical_counters[i] -= 2;
        return 0;
    }
    if (maze->vertical_counters[i] < -VERTICAL_LIMIT && !choice) {
        maze->vertical_counters[i] += 2;
        return 1;
    }
    return choice;
}

void link_curr_group(maze_builder_t *maze, int line1, int line2, int *i)
{
    int link_count = 0;
    char *transit_line = malloc(sizeof(char) * (maze->dim_x * 2 + 1));
    int transit_index = 0;
    int previous_group_links = 0;

    while (*i < maze->dim_x - maze->fill_dim_x) {
        if (do_link_procedural(maze, *i)) {
            ++link_count;
            maze->line[line2][*i] = maze->line[line1][*i];
            transit_line[transit_index++] = ' ';
        } else {
            maze->line[line2][*i] = (maze->group_id)++;
            transit_line[transit_index++] = '#';
        }
        transit_line[transit_index++] = '#';
        if (*i > 0 && maze->line[line1][*i - 1] != maze->line[line1][*i]
            || *i + 1 == maze->dim_x) {
            if (previous_group_links == 0) {
                maze->line[line2][*i - 1] = maze->line[line1][*i - 1];
                transit_line[transit_index - 4] = ' ';
            }
            previous_group_links = link_count;
            link_count = 0;
        }
        ++(*i);
    }
    if (!maze->fill_dim_x)
        transit_line[maze->dim_x * 2 - 1] = '\0';
    printf("%s", transit_line);
    printf("\n");
    free(transit_line);
}

void create_random_links(maze_builder_t *maze)
{
    int curr_first = maze->first_index % 2;
    int curr_second = (maze->first_index + 1) % 2;

    for (int i = 0; i < maze->dim_x; ++i) {
        link_curr_group(maze, curr_first, curr_second, &i);
    }
}

void iterate_eller(maze_builder_t *maze, int nbr_lines)
{
    for (int i = 0; i < nbr_lines / 2; i++) {
        merge_groups(maze);
        create_random_links(maze);
        ++(maze->first_index);
    }
    if (!maze->fill_dim_y)
        merge_groups(maze);
}
