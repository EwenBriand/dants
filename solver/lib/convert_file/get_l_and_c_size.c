/*
** EPITECH PROJECT, 2021
** Dant's
** File description:
** give the size of the board
*/

#include <string.h>
#include "my.h"

int get_l_size(char *buffer)
{
    char *nb = malloc(sizeof(char) * (strlen(buffer)));

    for (int i = 0; buffer[i] != '\n'; ++i) {
        nb[i] = buffer[i];
    }
    return atoi(nb);
}

int get_c_size(char *buffer)
{
    int i = 0;
    int count = 0;

    while (buffer[i] != '\n') {
        ++i;
    }
    for (; buffer[i + 1] != '\n'; ++i) {
        ++count;
    }
    return count;
}
