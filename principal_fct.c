/*
** EPITECH PROJECT, 2019
** principal
** File description:
** a
*/

#include "my.h"

int minishell(int ac, char ** av, char ** const envp)
{
    char ** copy = copy_env(envp);
    int status;
    int test = 0;
    size_t s;
    char *summ = NULL;
    char *go;

    my_putstr("$>");
    if (getline(&summ, &s, stdin) == -1)
        exit(0);
    summ = clean_str(summ);
    char ** str = my_str_to_word_array(summ);
    go = detect_comm(copy, str[0]);
    if (exit_t(str, summ) == 0)
        return (0);
    else if (ife(str, summ, copy, envp) != 0)
        fct_fork(go, str, envp, status);
    free(str);
    free(summ);
    minishell(ac, av, envp);
}

int ife(char **str, char * summ, char ** copy, char ** envp)
{
    if (my_str_compare(str[0], "env") == 1) {
        env(copy);
        return (0);
    }
    if (my_str_compare(str[0], "cd") == 1) {
        to_cd(str, copy);
        return (0);
    }
    if (my_str_compare(str[0], "setenv") == 1)
        exit(0);
    if (my_str_compare(str[0], "unsetenv") == 1)
        exit(0);
    return (1);
}

void to_cd(char ** str, char ** copy)
{
    int i = 0;
    char ** pwd;
    char *path;
    size_t t;

    if (chdir(str[1]) == -1)
        exit(0);
    while (my_str_compare_env(copy[i], "PWD=") != 1)
        i++;
    pwd = pars_path(copy[i]);
    pwd[1] = getcwd(path, t);
}

void fct_fork(char *go, char ** str, char **envp, int status)
{
    int id;
    if (str[0][0] != '/' || str[0][0] != '.')
        str[0] = go;
    id = fork();
    if (id == 0 ) {
        if (execve(str[0], str, envp) == -1) {
            my_pute(str[0]);
            write(2, ": Command not found.\n", 22);
            exit (1);
        }
        exit(0);
    }
    else {
        wait(&status);
    }
    if (status == 139 || status == 11) {
        write(2, "Segmentation fault\n", 34);
        exit (139);
    }
}

int exit_t(char **str, char *summ)
{
    if (my_str_compare(str[0], "exit") == 1) {
        free(str);
        free(summ);
        my_putstr("exit\n");
        return (0);
    }
    else
        return (1);
}