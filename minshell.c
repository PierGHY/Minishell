/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** ppp
*/

#include "my.h"

char *way(char *file_name, char *f_word)
{
    int i = 0;
    int j = 0;
    char * test = malloc(sizeof(char) * (my_strlen_env(file_name)
    + my_strlen_env(f_word) + 2));
    
    while (f_word[i] != '\0') {
        test[i] = f_word[i];
        i = i + 1;
    } if (test[i] != '/') {
        test[i] = '/';
        i = i + 1;
    }
    while (file_name[j] != '\0') {
        test[i] = file_name[j];
        j = j + 1;
        i = i + 1;
    }
    test[i] = '\0';
    return (test);
}

char * detect_comm(char ** copy, char * summ) 
{
    int i = 0;
    int z = 0;
    char **path;
    char *test;
    int p = 1;
    
    while(my_str_compare_env(copy[i],"PATH") != 1)
        i++;
    path = pars_path(copy[i]);
    while(path[p] != NULL) {
        if (access(way(summ, path[p]), X_OK) == 0)
            break;
        p++;
    }
    if (path[p] != NULL) {
        test = way(summ, path[p + 1]);
        return(test);
    }
    else
        return(summ);
}

int count_path(char *str) 
{
    int i = 0;
    int j = 0;

    while(str[i] != '\0') {
        if (str[i] == ':' || str[i] == '=')
            j++;
        i++;
    }
    return (j);
}

int my_strlenp(char const *str)
{
    int i = 0;

    while (str[i] != ':' && str[i] != '=' && str[i] != '\0')
        i = i + 1;
    return (i);
}

void main(int ac, char ** av, char ** const envp)
{
    minishell(ac, av, envp);
}