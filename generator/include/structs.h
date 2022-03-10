/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-3-dante-ewen.briand
** File description:
** structs.h
*/

#ifndef DB99BF0C_BD3F_47C9_A833_0564EC8DF4EB
#define DB99BF0C_BD3F_47C9_A833_0564EC8DF4EB

typedef struct node_s node_t;
struct node_s {
    node_t *next;
    int x;
    int y;
    int creator_x;
    int creator_y;
};

typedef struct maze_builder_s {
    node_t *list;
    int node_count;
    char **maze;
    int height;
    int width;
    int tmp_cell_x;
    int tmp_cell_y;
} maze_t;

#endif
