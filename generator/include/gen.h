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
    #define Y 0
    #define X 1

node_t *pop(node_t **list);
node_t *new_node(int x, int y, node_t *next);
void list_add(node_t **list, node_t *to_add, int *count);
void free_list(node_t *list);
int get_node_index_in_list(node_t *list, int x, int y);
void destroy_maze(maze_t *maze);
void generate_maze(maze_t *maze, int perfect);
void display_maze(maze_t *maze);
node_t *pop_at(int i, node_t **list, int *count);
maze_t *set_maze_builder(int x, int y);
void show_list(node_t *list);
int *pop_nearest(int i, maze_t *maze, int *count);
int *array_pop_at_i(int i, maze_t *maze, int *count);
void add_new_available_pathes_to_array(maze_t *maze, int x, int y);
void add_pos_to_array_if_available(maze_t *maze, int x, int y);

#endif
