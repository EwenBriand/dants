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

int position_is_used(node_t *node, maze_t *maze)
{
    if (maze->maze[node->y][node->x] == '*') {
        node->next = NULL;
        free_list(node);
        return 1;
    }
    return 0;
}

void add_pos_to_list_if_available(maze_t *maze, int x, int y)
{
    if (x < 0 || x >= maze->width || y < 0 || y >= maze->height)
        return;
    if (x < 0 || x >= maze->width || y < 0 || y >= maze->height) {
        return;
    }
    if (maze->maze[y][x] == 'X') {
        list_add(&(maze->list), new_node(x, y, NULL), &(maze->node_count));
        maze->list->creator_x = maze->tmp_cell_x;
        maze->list->creator_y = maze->tmp_cell_y;
    }
}

void add_new_available_pathes_to_list(maze_t *maze, int origin_x, int origin_y)
{
    maze->tmp_cell_x = origin_x;
    maze->tmp_cell_y = origin_y;
    for (int x = -2; x <= 2; x += 4) {
        add_pos_to_list_if_available(maze, origin_x + x, origin_y);
    }
    for (int y = -2; y <= 2; y += 4) {
        add_pos_to_list_if_available(maze, origin_x, origin_y + y);
    }
}
