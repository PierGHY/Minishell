/*
** EPITECH PROJECT, 2019
** other
** File description:
** a
*/

#include "my.h"

char * clean_str(char * summ)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int z = 0;
    char *dest = malloc(sizeof(char) * (my_strlen_env(summ)));

    while (summ[i] != '\0') {
        if (summ[i] != ' ' && summ[i] != '\t') {
            dest[j] = summ[i];
            z = 1;
            j++;
        }
        else if (summ[i + 1] != ' ' && summ[i + 1] != '\t' && z == 1){
            dest[j++] = ' ';
        }
        i++;
    }
    dest[i] = '\0';
    return (dest);
}