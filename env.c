/*
** EPITECH PROJECT, 2019
** env
** File description:
** a
*/

#include "my.h"

int counter_env(char ** envp) {
    int i = 0;

    while (envp[i] != NULL)
        i++;
    return(i);
}

char ** copy_env(char ** const envp)
{
    char **str = malloc(sizeof(char *) * ((counter_env(envp) + 1)));
    int i = 0;
    int z = 0;
    int j = 0;

    while (i < counter_env(envp)) {
        str[i] = malloc(sizeof(char) * (my_strlen_env(envp[i])));
        i = i + 1;
    }
    i = 0;
    while (i < counter_env(envp)) {
        while (j < my_strlen_env(envp[i])) {
            str[i][j] = envp[i][j];
            j = j + 1;
        } 
        i ++;
        j = 0;
    }
    str[i] = NULL;
    return (str);
}

int my_str_compare_env(char * str, char *other)
{
    int i = 0;
    int j = 0;

    while(i != 3 && i != 3) {
        i ++;
        if (str[i] == other[i])
            j++;
    }
    if (j == i)
        return(1);
    else
        return(0);
}

int my_strlenzp(char *str, int k)
{
    int i = k;
    int j = 0;

    while (str[i] != '=' && str[i] != ':' && str[i] != '\0'){
        i = i + 1;
        j++;
    }
    return (j);
}

char ** pars_path(char * path)
{
    char **str = malloc(sizeof(char *) * ((count_path(path) + 1)));
    int i = 0;
    int z = 0;
    int j = 0;
    int k = 0;

    for(int i= 0; i <= count_path(path) + 1; i++)
        str[i] = malloc(sizeof(char) * (my_strlenp(path)));
    while (i < count_path(path) + 1) {
        z = my_strlenzp(path, k);
        while (j <= z) {
            str[i][j] = (path[k] == ':') ? '\0' : path[k];
            j = j + 1;
            k = k + 1;
        }
        i ++;
        j = 0;
    }
    str[i] = NULL;
    return (str);
}