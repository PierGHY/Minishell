/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** ppp
*/

#include "my.h"

void detect_PWD(){

}

void detect_OLPWD(){

}

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

int minishell(int ac, char ** av, char ** const envp)
{
    char ** copy = copy_env(envp);
    int status;
    int test = 0;
    size_t s;
    char *summ = NULL;
    char *go;

    my_putstr("$>");
    getline(&summ, &s, stdin);
    char ** str = my_str_to_word_array(summ);
    go = detect_comm(copy, str[0]);
    if (exit_t(str, summ) == 0)
        return(0);
    if (my_str_compare(str[0], "env") == 1)
        env(copy);
    else if(my_str_compare(str[0], "cd") == 1)
        to_cd(str, copy);
    else 
        fct_fork(go, str, envp, status);
    free(str);
    free(summ);
    minishell(ac, av, envp);
}

void to_cd(char ** str, char ** copy)
{
    int i = 0;
    char ** pwd;

    chdir(str[1]);
    while(my_str_compare_env(copy[i],"PWD=") != 1)
        i++;
    pwd = pars_path(copy[i]);
    //printf("test => %s\n", pwd[1]);
    //getcwd()
}

void fct_fork(char *go, char ** str, char **envp, int status) 
{
    int id;
    if (str[0][0] != '/' && str[0][0] != '.')
        str[0] = go;
    id = fork();
    if (id == 0 ) {
        if (execve(str[0], str, envp) == -1) {
            my_putstr(str[0]);
            my_putstr(": Command not found.\n");
        }
        exit(0);
    }
    else {
        wait(&status);
    }
}

int exit_t(char **str, char *summ) 
{
    if (my_str_compare(str[0], "exit") == 1) {
        free(str);
        free(summ);
        my_putstr("exit\n");
        return(0);
    }
    else
        return(1);
}

void main(int ac, char ** av, char ** const envp)
{
    minishell(ac, av, envp);
}