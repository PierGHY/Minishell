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
    getline(&summ, &s, stdin);
    summ = clean_str(summ);
    char ** str = my_str_to_word_array(summ);
    go = detect_comm(copy, str[0]);
    if (exit_t(str, summ) == 0)
        return(0);
    if (my_str_compare(str[0], "env") == 1)
        env(copy);
    else if(my_str_compare(str[0], "cd") == 1)
        to_cd(str, copy);
    else if(my_str_compare(str[0], "setenv") == 1)
        exit(0);
    else if(my_str_compare(str[0], "unsetenv") == 1)
        exit(0);
    else 
        fct_fork(go, str, envp, status);
    free(str);
    free(summ);
    minishell(ac, av, envp);
}

int my_strlenzs(char *str, int k)
{
    int i = k;
    int j = 0;

    while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0'){
        i = i + 1;
        j++;
    }
    printf("%i\n", j);
    return (j);
}

char * clean_str(char * summ)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int z = 0;
    char *dest = malloc(sizeof(char) * (my_strlen_env(summ)));

    while(summ[i] != '\0') {
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
    return(dest);
}

void to_cd(char ** str, char ** copy)
{
    int i = 0;
    char ** pwd;
    char *path;
    size_t t;

    chdir(str[1]);
    while(my_str_compare_env(copy[i],"PWD=") != 1)
        i++;
    pwd = pars_path(copy[i]);
    pwd[1] = getcwd(path, t);
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