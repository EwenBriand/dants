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
    }
}

void add_new_available_pathes_to_list(maze_t *maze, int origin_x, int origin_y)
{
    for (int x = -2; x <= 2; x += 4) {
        add_pos_to_list_if_available(maze, origin_x + x, origin_y);
    }
    for (int y = -2; y <= 2; y += 4) {
        add_pos_to_list_if_available(maze, origin_x, origin_y + y);
    }
}

int position_is_used(int *node, maze_t *maze)
{
    if (maze->maze[node[Y]][node[X]] == '*') {
        // free_list(node);
        free(node);
        return 1;
    }
    return 0;
}

// void generate_maze(maze_t *maze)
// {
//     int i;
//     // node_t *node_tmp = NULL;
//     // node_t *bridge_to_path = NULL;
//     int node_tmp[2] = NULL;
//     int bridge_to_path[2] = NULL;

//     while (maze->node_count > 0) {
//         i = rand() % maze->arr_len;

//         // node_tmp = pop_at(i, &maze->list, &(maze->node_count));
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
//             free(node_tmp);
//         if (bridge_to_path != NULL)
//             free(bridge_to_path);
//     }
// }

void print_array(maze_t *maze)
{
    printf("\n-------------------\n");
    for (int i = 0; i < maze->array_len; ++i) {
        if (maze->array[i] == NULL) {
            printf("index:  %d  - (nil)\n", i);
            continue;
        }
        printf("index:  %d  - %p\n", i, maze->array[i]);
    }
    printf("\n--------------------\n");
}

void generate_maze(maze_t *maze)
{
    int i;
    // node_t *node_tmp = NULL;
    // node_t *bridge_to_path = NULL;
    int *node_tmp = NULL;
    int *bridge_to_path = NULL;

    while (maze->node_count > 0) {
        i = rand() % maze->array_len;
        node_tmp = array_pop_at_i(i, maze, &(maze->node_count));
        if (node_tmp == NULL) {
            return;
        }
        if (node_tmp[X] < 0 || node_tmp[X] >= maze->width || node_tmp[X] < 0
            || node_tmp[X] >= maze->height || position_is_used(node_tmp, maze))
            continue;
        maze->maze[node_tmp[Y]][node_tmp[X]] = '*';
        // display_maze(maze);
        // bridge_to_path = new_node(node_tmp[X], node_tmp[Y], NULL);
        bridge_to_path = malloc(sizeof(int) * 2);
        bridge_to_path[X] = node_tmp[X];
        bridge_to_path[Y] = node_tmp[Y];
        choose_way(maze, &(bridge_to_path[X]), &(bridge_to_path[Y]));
        if (bridge_to_path[X] < 0 || bridge_to_path[X] >= maze->width
        || bridge_to_path[Y] < 0
        || bridge_to_path[Y] >= maze->height)
            continue;
        maze->maze[bridge_to_path[Y]][bridge_to_path[X]] = '*';
        // add_new_available_pathes_to_list(maze, node_tmp->x, node_tmp->y);
        add_new_available_pathes_to_array(maze, node_tmp[X], node_tmp[Y]);
        if (node_tmp != NULL)
            free(node_tmp);
        if (bridge_to_path != NULL)
            free(bridge_to_path);
    }
}

void add_new_available_pathes_to_array(maze_t *maze, int origin_x, int origin_y)
{
    for (int x = -2; x <= 2; x += 4) {
        add_pos_to_array_if_available(maze, origin_x + x, origin_y);
    }
    for (int y = -2; y <= 2; y += 4) {
        add_pos_to_array_if_available(maze, origin_x, origin_y + y);
    }
}
