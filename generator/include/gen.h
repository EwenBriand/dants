/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-3-dante-ewen.briand
** File description:
** dante.h
*/

#include "structs.h"

#ifndef CA54378F_16EB_4732_9369_4ACA064B509C
    #define CA54378F_16EB_4732_9369_4ACA064B509C
    #define LINK_FACTOR 50

int **init_lines(int y);
maze_builder_t *set_maze_builder(int x, int y);
void destroy_maze_builder(maze_builder_t *maze_builder);
void generate_map(maze_builder_t *maze);
void group_rooms(maze_builder_t *my_maze);

#endif
