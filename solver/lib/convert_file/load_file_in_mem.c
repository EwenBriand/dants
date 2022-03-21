/*
** EPITECH PROJECT, 2021
** Project Name
** File description:
** step 1 task 4
*/

#include "my.h"

char *load_file_in_mem(char const *filepath)
{
    char *buffer;
    int fd = open(filepath, O_RDONLY, S_IRUSR | S_IRGRP | S_IROTH);
    struct stat buf;
    stat(filepath, &buf);

    buffer = malloc(sizeof(char) * (buf.st_size + 1));
    if (fd != -1) {
        read(fd, buffer, buf.st_size);
    }
    return buffer;
}


int find_j(char *buffer)
{
    int j = 0;

    if (buffer[0] == '*' || buffer[0] == 'X') {
        return j;
    } else {
        while (buffer[j] != '\n') {
            ++j;
        }
        return j + 1;
    }
}

char ** mem_alloc_2d_array(int nb_rows , int nb_cols)
{
    char **tab = malloc(sizeof(char *) * (nb_rows + 1));

    if (tab == NULL) {
        return NULL;
    }
    for (int i = 0; i < nb_rows; ++i) {
        tab[i] = malloc(sizeof(char) * (nb_cols + 1));
        if (tab[i] == NULL) {
            return NULL;
        }
    }
    tab[nb_rows] = NULL;
    return tab;
}

void get_lines_and_rows(char *buffer, int *rows, int *cols, int *error)
{
    int i = 0;
    int curr_line_len = -1;

    while (buffer[i]) {
        if (curr_line_len == -1 && buffer[i] == '\n') {
            *cols = i;
            ++*rows;
            curr_line_len = 0;
        } else if (buffer[i] == '\n') {
            ++*rows;
            *error = (curr_line_len == *cols) ? 0 : 1;
            curr_line_len = 0;
        }
        if (*error)
            break;
        ++i;
    }
}

char ** load_2d_arr_from_file(char const *filepath, int *nb_rows, int *nb_cols,
int *error)
{
    char *buffer = load_file_in_mem(filepath);
    int pos_x = 0;
    int pos_y = 0;
    int j = find_j(buffer);
    char **board;

    get_lines_and_rows(buffer, &nb_rows, &nb_cols);
    if (*error) {
        free(buffer);
        return NULL;
    }
    board = mem_alloc_2d_array(nb_rows, nb_cols, error);
    for (; buffer[j] != '\0' && pos_y != nb_rows; ++j) {
        board[pos_y][pos_x] = buffer[j];
        ++pos_x;
        if (buffer[j] == '\n') {
            ++pos_y;
            pos_x = 0;
        }
    }
    return board;
}
