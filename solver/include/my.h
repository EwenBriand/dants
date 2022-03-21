/*
** EPITECH PROJECT, 2022
** dants
** File description:
** my
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef D07DA196_02D1_4834_975F_0BB14A91A233
#define D07DA196_02D1_4834_975F_0BB14A91A233

char ** load_2d_arr_from_file(char const *filepath,
int *nb_rows, int *nb_cols, int *error);

#endif
