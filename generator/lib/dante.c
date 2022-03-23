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

int position_is_used(node_t *node, maze_t *maze);
void add_pos_to_list_if_available(maze_t *maze, int x, int y);
void add_new_available_pathes_to_list(
    maze_t *maze, int origin_x, int origin_y);

void draw_bridge_to_creator(maze_t *maze, node_t *node)
{
    int dx = node->creator_x - node->x;
    int dy = node->creator_y - node->y;
    maze->maze[node->x + dx / 2][node->y + dy / 2] = '*';
}

void carve_passage_around(maze_t *maze, int *coord)
{
    int tmp_x = 0;
    int tmp_y = 0;
    int pos[4][2] = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}};
    int rdm = rand() % 4;

    for (int i = 0; i < 4; ++i) {
        tmp_x = coord[X] + pos[rdm][X] / 2;
        tmp_y = coord[Y] + pos[rdm][Y] / 2;
        if (tmp_x < 0 || tmp_x >= maze->width || tmp_y < 0
            || tmp_y >= maze->height || maze->maze[tmp_y][tmp_x] == '*')
            rdm = (rdm + 1 < 4) ? rdm + 1 : 0;
        else
            maze->maze[tmp_y][tmp_x] = '*';
    }
}

void ruin_everything(maze_t *maze)
{
    int passage_nbr = maze->height * maze->width;
    int denum = 50;
    int rdm[2];

    if (maze->height - 1 <= 0 || maze->width - 1 <= 0)
        return;
    do {
        passage_nbr = maze->height * maze->width / denum--;
    } while (denum > 0 && passage_nbr == 0);
    for (int i = 0; i < passage_nbr; ++i) {
        rdm[Y] = rand() % (maze->height - 1);
        rdm[X] = rand() % (maze->width - 1);
        if (maze->maze[rdm[Y]][rdm[X]] == 'X') {
            maze->maze[rdm[Y]][rdm[X]] = '*';
            continue;
        } else
            carve_passage_around(maze, rdm);
    }
}

void sec_part(maze_t *maze, node_t *node_tmp)
{
    maze->maze[node_tmp->y][node_tmp->x] = '*';
    draw_bridge_to_creator(maze, node_tmp);
    add_new_available_pathes_to_list(maze, node_tmp->x, node_tmp->y);
    if (node_tmp != NULL) {
        free(node_tmp);
        node_tmp = NULL;
    }
}

void generate_maze(maze_t *maze, int perfect)
{
    int rdm = 0;
    node_t *node_tmp = NULL;
    node_t *bridge_to_path = NULL;
    int min = 1;

    while (maze->node_count > 0) {
        min = (maze->node_count < 10) ? maze->node_count : 10;
        rdm = rand() % min;
        node_tmp = pop_at(rdm, &maze->list, &(maze->node_count));
        if (node_tmp == NULL)
            return;
        if (node_tmp->x < 0 || node_tmp->x >= maze->width || node_tmp->y < 0
            || node_tmp->y >= maze->height || position_is_used(node_tmp, maze))
            continue;
        sec_part(maze, node_tmp);
    }
    if (perfect != 1)
        ruin_everything(maze);
}
