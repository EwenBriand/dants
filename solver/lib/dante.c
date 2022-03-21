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

// void change_coo(int *x, int *y, int random, char *res)
// {
//     int i = 0;
//     for (; random > 0; ++i)
//         if (res[i] == '1')
//             --random;
//     --i;
//     if (i == 0)
//         *y -= 1;
//     if (i == 1)
//         *y += 1;
//     if (i == 2)
//         *x -= 1;
//     if (i == 3)
//         *x += 1;
// }

// void choose_way(maze_t *maze, int *x2, int *y2)
// {
//     char res[] = "0000";
//     int count = 0;
//     int random = 0;
//     int i = 0;

//     for (int y = *y2 - 2; y <= *y2 + 2; y += 4) {
//         if (*x2 < 0 || *x2 >= maze->width || y < 0 || y >= maze->height) {
//             ++i;
//             continue;
//         } else if (maze->maze[y][*x2] == '*') {
//             res[i] = '1';
//             ++count;
//         }
//         ++i;
//     }
//     for (int x = *x2 - 2; x <= *x2 + 2; x += 4) {
//         if (x < 0 || x >= maze->width || *y2 < 0 || *y2 >= maze->height) {
//             ++i;
//             continue;
//         } else if (maze->maze[*y2][x] == '*') {
//             res[i] = '1';
//             ++count;
//         }
//         ++i;
//     }
//     if (count == 0)
//         return;
//     // random = 1;
//     else
//         random = rand() % count;
//     if (random == 0)
//         ++random;
//     change_coo(x2, y2, random, res);
// }

// void add_pos_to_list_if_available(maze_t *maze, int x, int y)
// {
//     if (x < 0 || x >= maze->width || y < 0 || y >= maze->height)
//         return;
//     if (x < 0 || x >= maze->width || y < 0 || y >= maze->height) {
//         return;
//     }
//     if (maze->maze[y][x] == 'X') {
//         list_add(&(maze->list), new_node(x, y, NULL), &(maze->node_count));
//         maze->list->creator_x = maze->tmp_cell_x;
//         maze->list->creator_y = maze->tmp_cell_y;
//     }
// }

// void add_new_available_pathes_to_list(maze_t *maze, int origin_x, int
// origin_y)
// {
//     maze->tmp_cell_x = origin_x;
//     maze->tmp_cell_y = origin_y;
//     for (int x = -2; x <= 2; x += 4) {
//         add_pos_to_list_if_available(maze, origin_x + x, origin_y);
//     }
//     for (int y = -2; y <= 2; y += 4) {
//         add_pos_to_list_if_available(maze, origin_x, origin_y + y);
//     }
// }

// int position_is_used(node_t *node, maze_t *maze)
// {
//     if (maze->maze[node->y][node->x] == '*') {
//         node->next = NULL;
//         free_list(node);
//         return 1;
//     }
//     return 0;
// }

// void write_bridge(maze_t *maze, int x, int y)
// {
//     int pos[4][2] = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}};
//     int rdm = rand() % 4;
//     int tmp_x = 0;
//     int tmp_y = 0;

//     for (int i = 0; i < 4; ++i) {
//         tmp_x = x + pos[rdm][X];
//         tmp_y = y + pos[rdm][Y];
//         if (tmp_x < 0 || tmp_x >= maze->width || tmp_y < 0
//             || tmp_y >= maze->height)
//             rdm = (rdm + 1 < 4) ? rdm + 1 : 0;
//         else
//             maze->maze[y + pos[rdm][Y] / 2][x + pos[rdm][X] / 2] = '*';
//     }
// }

// void draw_bridge_to_creator(maze_t *maze, node_t *node)
// {
//     int dx = node->creator_x - node->x;
//     int dy = node->creator_y - node->y;
//     maze->maze[node->x + dx / 2][node->y + dy / 2] = '*';
// }

// void carve_passage_around(maze_t *maze, int *coord)
// {
//     int tmp_x = 0;
//     int tmp_y = 0;
//     int pos[4][2] = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}};
//     int rdm = rand() % 4;

//     for (int i = 0; i < 4; ++i) {
//         tmp_x = coord[X] + pos[rdm][X] / 2;
//         tmp_y = coord[Y] + pos[rdm][Y] / 2;
//         if (tmp_x < 0 || tmp_x >= maze->width || tmp_y < 0
//             || tmp_y >= maze->height || maze->maze[tmp_y][tmp_x] == '*')
//             rdm = (rdm + 1 < 4) ? rdm + 1 : 0;
//         else
//             maze->maze[tmp_y][tmp_x] = '*';
//     }
// }

// void ruin_everything(maze_t *maze)
// {
//     int passage_nbr = maze->height * maze->width;
//     int denum = 100;
//     int rdm[2];

//     if (maze->height - 1 <= 0 || maze->width - 1 <= 0)
//         return;
//     do {
//         passage_nbr = maze->height * maze->width / denum--;
//     } while (denum > 0 && passage_nbr == 0);
//     printf("removing %d walls\n", passage_nbr);
//     for (int i = 0; i < passage_nbr; ++i) {
//         rdm[Y] = rand() % (maze->height - 1);
//         rdm[X] = rand() % (maze->width - 1);
//         printf("rdm: %d, %d\n", rdm[Y], rdm[X]);
//         if (maze->maze[rdm[Y]][rdm[X]] == 'X') {
//             maze->maze[rdm[Y]][rdm[X]] = '*';
//             continue;
//         } else
//             carve_passage_around(maze, rdm);
//     }
// }

// void generate_maze(maze_t *maze, int perfect)
// {
//     int rdm = 0;
//     node_t *node_tmp = NULL;
//     node_t *bridge_to_path = NULL;
//     int min = 1;

//     while (maze->node_count > 0) {
//         min = (maze->node_count < 10) ? maze->node_count : 10;
//         rdm = rand() % min;
//         node_tmp = pop_at(rdm, &maze->list, &(maze->node_count));
//         if (node_tmp == NULL)
//             return;
//         if (node_tmp->x < 0 || node_tmp->x >= maze->width || node_tmp->y < 0
//             || node_tmp->y >= maze->height || position_is_used(node_tmp,
//             maze)) continue;
//         maze->maze[node_tmp->y][node_tmp->x] = '*';
//         draw_bridge_to_creator(maze, node_tmp);
//         add_new_available_pathes_to_list(maze, node_tmp->x, node_tmp->y);
//         if (node_tmp != NULL) {
//             free(node_tmp);
//             node_tmp = NULL;
//         }
//     }
//     if (!perfect)
//         ruin_everything(maze);
// }

int **build_parents_from_mother(node_t *mother, int child_x, int child_y)
{
    int **parents = malloc(sizeof(int *) * (mother->p_len + 1));

    for (int i = 0; i < mother->p_len; ++i) {
        parents[i] = malloc(sizeof(int) * 2);
        parents[i][Y] = mother->parents[i][Y];
        parents[i][X] = mother->parents[i][X];
    }
    parents[mother->p_len] = malloc(sizeof(int) * 2);
    parents[mother->p_len][Y] = child_y;
    printf("build_parents_from_mother\n");
    parents[mother->p_len][X] = child_x;
    return parents;
}

void add_neighboors_to_list(
    node_t *mother, maze_t *maze, int *out, node_t **list)
{
    int pos[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int tmp_x = 0;
    int tmp_y = 0;

    if (mother == NULL)
        return;
    printf("maze dims are %d %d\n", maze->height, maze->width);
    for (int i = 0; i < 4; ++i) {
        tmp_x = mother->parents[mother->p_len - 1][X] + pos[i][X];
        tmp_y = mother->parents[mother->p_len - 1][Y] + pos[i][Y];
        printf("tmpy %d tmpx %d\n", tmp_y, tmp_x);
        if (tmp_x < 0 || tmp_x >= maze->width || tmp_y < 0
            || tmp_y >= maze->height)
            continue;
        printf("did not continue\n");
        if (maze->maze[tmp_y][tmp_x] == '*') {
            list_add(list,
                new_node(build_parents_from_mother(mother, tmp_x, tmp_y),
                    mother->p_len + 1, NULL, maze));
            printf("added a node\n");
        }
        if (tmp_x == 0 && tmp_y == 0)
            *out = 1;
    }
}

void destroy_list(node_t *list)
{
    if (list == NULL)
        return;
    for (int i = 0; i < list->p_len; ++i) {
        free(list->parents[i]);
    }
    free(list->parents);
    destroy_list(list->next);
    free(list);
}

void traceback(maze_t *maze, node_t *node)
{
    if (node == NULL)
        return;
    for (int i = 0; i < node->p_len; ++i) {
        printf("y :%i\nx :%i\n\n", node->parents[i][Y], node->parents[i][X]);
        maze->maze[node->parents[i][Y]][node->parents[i][X]] = 'o';
    }
    destroy_list(node);
}

int **init_zero_parents(void)
{
    int **zero_parents = malloc(sizeof(int *));
    zero_parents[0] = malloc(sizeof(int) * 2);
    zero_parents[0][0] = 0;
    zero_parents[0][1] = 0;
    return zero_parents;
}

int solve_maze(maze_t *maze)
{
    node_t *available_nodes = new_node(init_zero_parents(), 1, NULL, maze);
    node_t *tmp = NULL;
    int out = 0;

    while (!out) {
        if (available_nodes == NULL)
            break;
        tmp = pop(&available_nodes);
        printf("we are at %d %d\n", tmp->parents[tmp->p_len - 1][0],
            tmp->parents[tmp->p_len - 1][1]);
        add_neighboors_to_list(tmp, maze, &out, &available_nodes);
    }
    if (available_nodes == NULL) {
        printf("no solution found\n");
        return 0;
    }
    traceback(maze, available_nodes);
    return 0;
}
