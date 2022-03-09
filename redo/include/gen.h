/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-3-dante-ewen.briand
** File description:
** dante.h
*/

#include "structs.h"

#ifndef CA54378F_16EB_4732_9369_4ACA064B509C
    #define CA54378F_16EB_4732_9369_4ACA064B509C
    #define LINK_FACTOR 70
    #define MERGE_FACTOR 80
    #define VERTICAL_LIMIT 1
    #define HORIZONTAL_LIMIT 2

void iterate_eller(maze_builder_t *maze, int nbr_line);
maze_builder_t *set_maze_builder(int x, int y);
void destroy_maze_builder(maze_builder_t *maze_builder);

#endif
