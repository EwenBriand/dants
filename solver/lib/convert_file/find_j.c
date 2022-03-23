/*
** EPITECH PROJECT, 2022
** dants
** File description:
** find_j
*/

#include <stdio.h>
#include "my.h"

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
