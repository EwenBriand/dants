/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-3-dante-ewen.briand
** File description:
** structs.h
*/

#ifndef DB99BF0C_BD3F_47C9_A833_0564EC8DF4EB
#define DB99BF0C_BD3F_47C9_A833_0564EC8DF4EB

typedef struct maze_builder_s {
    int dim_y;
    int dim_x;
    int curr_x;
    int curr_y;
    int fill_dim_y;
    int fill_dim_x;
    int **line;
    int first_index;
    int group_id;
} maze_builder_t;

#endif
