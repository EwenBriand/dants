/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-3-dante-ewen.briand
** File description:
** dante.c
*/

#include <stdio.h>
#include <stdlib.h>

#include "gen.h"
#include "structs.h"

void change_coo(int *x, int *y, int random, char *res)
{
    int i = 0;
    for (i = 0; random > 0; ++i)
        if (res[i] == '1')
            --random;
    --i;
    if (i == 0)
        *y -= 1;
    if (i == 1)
        *y += 1;
    if (i == 2)
        *x -= 1;
    if (i == 3)
        *x += 1;
}

void choose_way(maze_t *maze, int *x2, int *y2)
{
    char res[] = "0000";
    int count = 0;
    int random = 0;
    int i = 0;

    for (int y = *y2 - 2; y <= *y2 + 2; y += 4) {
        if (*x2 < 0 || *x2 >= maze->width || y < 0 || y >= maze->height) {
            ++i;
            continue;
        } else if (maze->maze[y][*x2] == '*') {
            res[i] = '1';
            ++count;
        }
        ++i;
    }
    for (int x = *x2 - 2; x <= *x2 + 2; x += 4) {
        if (x < 0 || x >= maze->width || *y2 < 0 || *y2 >= maze->height) {
            ++i;
            continue;
        } else if (maze->maze[*y2][x] == '*') {
            res[i] = '1';
            ++count;
        }
        ++i;
    }
    if (count == 0)
        random = 1;
    else
        random = rand() % count;
    if (random == 0)
        ++random;
    change_coo(x2, y2, random, res);
}

void add_pos_to_list_if_available(maze_t *maze, int x, int y)
{
    if (x < 0 || x >= maze->width || y < 0 || y >= maze->height)
        return;
    if (x - 1 < 0 || x + 1 >= maze->width || y - 1 < 0
        || y + 1 >= maze->height)
        return;
    if (maze->maze[y][x] == 'X' && maze->maze[y - 1][x] == 'X'
        && maze->maze[y + 1][x] == 'X' && maze->maze[y][x - 1] == 'X'
        && maze->maze[y][x + 1] == 'X')
        list_add(&(maze->list), new_node(x, y, NULL), &(maze->node_count));
}

void add_new_available_pathes_to_list(maze_t *maze, int origin_x, int origin_y)
{
    for (int y = -1; y <= 1; y += 2) {
        for (int x = -1; x <= 1; x += 2) {
            add_pos_to_list_if_available(maze, origin_x + x, origin_y + y);
        }
    }
}

void generate_maze(maze_t *maze)
{
    int i;
    node_t *node_tmp = NULL;

    while (maze->node_count > 0) {
        i = rand() % maze->node_count;
        node_tmp = pop_at(i, &maze->list, &(maze->node_count));

        if (node_tmp == NULL) {
            printf("NOPNOPNOPNOP\n");
            return;
        }
        if (node_tmp->x < 0 || node_tmp->x >= maze->width || node_tmp->y < 0
            || node_tmp->y >= maze->height)
            continue;
        maze->maze[node_tmp->y][node_tmp->x] = '*';
        display_maze(maze);
        choose_way(maze, &(node_tmp->x), &(node_tmp->y));
        if (node_tmp->x < 0 || node_tmp->x >= maze->width || node_tmp->y < 0
            || node_tmp->y >= maze->height)
            continue;
        maze->maze[node_tmp->y][node_tmp->x] = '*';
        add_new_available_pathes_to_list(maze, node_tmp->x, node_tmp->y);
        if (node_tmp != NULL)
            free(node_tmp);
    }
}
