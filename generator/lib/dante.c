// /*
// ** EPITECH PROJECT, 2021
// ** B-CPE-200-PAR-2-3-dante-ewen.briand
// ** File description:
// ** dante.c
// */

// #include <stdio.h>
// #include <stdlib.h>

// #include "gen.h"
// #include "structs.h"

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
//         // random = 1;
//     else
//         random = rand() % count;
//     if (random == 0)
//         ++random;
//     change_coo(x2, y2, random, res);
// }

// void write_bridge(maze_t *maze, int x, int y)
// {
//     int n_index = rand() % 4;
//     int pos[4][2] = {{-2, 0},
//     {2, 0},
//     {0, -2},
//     {0, 2}};
//     int tmp_x = 0;
//     int tmp_y = 0;

//     for (int i = 0; i < 4; ++i) {
//         tmp_x = x + pos[n_index][X];
//         tmp_y = y + pos[n_index][Y];
//         if (tmp_x < 0 || tmp_x >= maze->width
//         || tmp_y || tmp_y >= maze->height
//         || maze->maze[tmp_y][tmp_x] != 'X')
//         n_index = (n_index + 1 >= 4) ? 0 : n_index + 1;
//         else {
//             // printf("x : %d, y : %d, bridge: %d %d\n", x, y, x + pos[n_index][X] / 2, y + pos[n_index][Y] / 2);
//             maze->maze[y + pos[n_index][Y] / 2][x + pos[n_index][X] / 2] = '*';
//             return;
//         }
//     }
// }

// void add_pos_to_list_if_available(maze_t *maze, int x, int y)
// {
//     if (x < 0 || x >= maze->width || y < 0 || y >= maze->height)
//         return;
//     if (x < 0 || x >= maze->width || y < 0
//     || y >= maze->height) {
//         return;
//         }
//     if (maze->maze[y][x] == 'X') {
//         list_add(&(maze->list), new_node(x, y, NULL), &(maze->node_count));
//     }
// }

// void add_new_available_pathes_to_list(maze_t *maze, int origin_x, int origin_y)
// {
//     for (int x = -2; x <= 2; x += 4) {
//         add_pos_to_list_if_available(maze, origin_x + x, origin_y);
//     }
//     for (int y = -2; y <= 2; y += 4) {
//         add_pos_to_list_if_available(maze, origin_x, origin_y + y);
//     }
// }

// int position_is_used(int *node, maze_t *maze)
// {
//     if (maze->maze[node[Y]][node[X]] == '*') {
//         free_list(node);
//         return 1;
//     }
//     return 0;
// }

// void generate_maze(maze_t *maze)
// {
//     int i;
//     node_t *node_tmp = NULL;
//     node_t *bridge_to_path = NULL;

//     while (maze->node_count > 0) {
//         i = rand() % maze->node_count;

//         node_tmp = pop_at(i, &maze->list, &(maze->node_count));
//         if (node_tmp == NULL) {
//             return;
//         }
//         if (node_tmp->x < 0 || node_tmp->x >= maze->width || node_tmp->y < 0
//             || node_tmp->y >= maze->height || position_is_used(node_tmp, maze))
//             continue;
//         maze->maze[node_tmp->y][node_tmp->x] = '*';
//         // display_maze(maze);
//         bridge_to_path = new_node(node_tmp->x, node_tmp->y, NULL);
//         choose_way(maze, &(bridge_to_path->x), &(bridge_to_path->y));
//         if (bridge_to_path->x < 0 || bridge_to_path->x >= maze->width
//         || bridge_to_path->y < 0
//         || bridge_to_path->y >= maze->height)
//             continue;
//         maze->maze[bridge_to_path->y][bridge_to_path->x] = '*';
//         add_new_available_pathes_to_list(maze, node_tmp->x, node_tmp->y);
//         if (node_tmp != NULL)
//             free_list(node_tmp);
//         if (bridge_to_path != NULL)
//             free_list(bridge_to_path);
//     }
// }

// void print_array(maze_t *maze)
// {
//     printf("\n-------------------\n");
//     for (int i = 0; i < maze->array_len; ++i) {
//         if (maze->array[i] == NULL) {
//             printf("index:  %d  - (nil)\n", i);
//             continue;
//         }
//         printf("index:  %d  - %p\n", i, maze->array[i]);
//     }
//     printf("\n--------------------\n");
// }

// // void generate_maze(maze_t *maze)
// // {
// //     int i;
// //     // node_t *node_tmp = NULL;
// //     // node_t *bridge_to_path = NULL;
// //     int *node_tmp = NULL;
// //     int *bridge_to_path = NULL;

// //     while (maze->node_count > 0) {
// //         i = rand() % maze->max_id_written;
// //         node_tmp = array_pop_at_i(i, maze, &(maze->node_count));
// //         if (node_tmp == NULL) {
// //             return;
// //         }
// //         if (node_tmp[X] < 0 || node_tmp[X] >= maze->width || node_tmp[X] < 0
// //             || node_tmp[X] >= maze->height || position_is_used(node_tmp, maze))
// //             continue;
// //         maze->maze[node_tmp[Y]][node_tmp[X]] = '*';
// //         bridge_to_path = malloc(sizeof(int) * 2);
// //         bridge_to_path[X] = node_tmp[X];
// //         bridge_to_path[Y] = node_tmp[Y];
// //         choose_way(maze, &(bridge_to_path[X]), &(bridge_to_path[Y]));
// //         if (bridge_to_path[X] < 0 || bridge_to_path[X] >= maze->width
// //         || bridge_to_path[Y] < 0
// //         || bridge_to_path[Y] >= maze->height)
// //             continue;
// //         maze->maze[bridge_to_path[Y]][bridge_to_path[X]] = '*';
// //         // write_bridge(maze, node_tmp[X], node_tmp[Y]);
// //         add_new_available_pathes_to_array(maze, node_tmp[X], node_tmp[Y]); //check if place is already taken
// //         if (node_tmp != NULL)
// //             free(node_tmp);
// //         // if (bridge_to_path != NULL)
// //         //     free(bridge_to_path);
// //     }
// // }

// void add_new_available_pathes_to_array(maze_t *maze, int origin_x, int origin_y)
// {
//     for (int x = -2; x <= 2; x += 4) {
//         add_pos_to_array_if_available(maze, origin_x + x, origin_y);
//     }
//     for (int y = -2; y <= 2; y += 4) {
//         add_pos_to_array_if_available(maze, origin_x, origin_y + y);
//     }
// }

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
    for (; random > 0; ++i)
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
        return;
        // random = 1;
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
    if (x < 0 || x >= maze->width || y < 0
    || y >= maze->height) {
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

int position_is_used(node_t *node, maze_t *maze)
{
    if (maze->maze[node->y][node->x] == '*') {
        node->next = NULL;
        free_list(node);
        return 1;
    }
    return 0;
}

void write_bridge(maze_t *maze, int x, int y)
{
    int pos[4][2] = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}};
    int rdm = rand() % 4;
    int tmp_x = 0;
    int tmp_y = 0;

    for (int i = 0; i < 4; ++i) {
        tmp_x = x + pos[rdm][X];
        tmp_y = y + pos[rdm][Y];
        if (tmp_x < 0 || tmp_x >= maze->width
        || tmp_y < 0 || tmp_y >= maze->height)
        rdm = (rdm + 1 < 4) ? rdm + 1 : 0;
        else
            maze->maze[y + pos[rdm][Y] / 2][x + pos[rdm][X] / 2] = '*';
    }
}

void draw_bridge_to_creator(maze_t *maze, node_t *node)
{
    int dx = node->creator_x - node->x;
    int dy = node->creator_y - node->y;
    maze->maze[node->x + dx / 2][node->y + dy / 2] = '*';

}

void generate_maze(maze_t *maze)
{
    int i;
    node_t *node_tmp = NULL;
    node_t *bridge_to_path = NULL;

    while (maze->node_count > 0) {
        i = rand() % maze->node_count;
        node_tmp = pop_at(i, &maze->list, &(maze->node_count));
        if (node_tmp == NULL) {
            return;
        }
        if (node_tmp->x < 0 || node_tmp->x >= maze->width || node_tmp->y < 0
            || node_tmp->y >= maze->height || position_is_used(node_tmp, maze))
            continue;
        maze->maze[node_tmp->y][node_tmp->x] = '*';
        // display_maze(maze);
        // bridge_to_path = new_node(node_tmp->x, node_tmp->y, NULL);
        // choose_way(maze, &(bridge_to_path->x), &(bridge_to_path->y));
        // if (bridge_to_path->x < 0 || bridge_to_path->x >= maze->width
        // || bridge_to_path->y < 0
        // || bridge_to_path->y >= maze->height)
        //     continue;
        // maze->maze[bridge_to_path->y][bridge_to_path->x] = '*';
        // write_bridge(maze, node_tmp->x, node_tmp->y);
        draw_bridge_to_creator(maze, node_tmp);
        add_new_available_pathes_to_list(maze, node_tmp->x, node_tmp->y);
        if (node_tmp != NULL)
            free(node_tmp);
        // if (bridge_to_path != NULL)
        //     free(bridge_to_path);
    }
}
