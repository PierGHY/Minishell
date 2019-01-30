/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** ppp
*/

#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

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

int detect_comm(char ** copy) 
{
    int i = 0;
    int z = 0;
    
    while(my_str_compare_env(copy[i],"PATH") != 1)
        i++;
    copy[i];
    /*    
    while(my_str_compare_env(copy[z], "PWD=") != 1)
        z++;
    */
}

int minishell(int ac, char ** av, char ** const envp)
{
    char ** copy = copy_env(envp);
    int id;
    int status;
    int test = 0;
    size_t s;
    char *summ = NULL;

    my_putstr("$>");
    getline(&summ, &s, stdin);
    detect_comm(copy);
    char ** str = my_str_to_word_array(summ);
    if (exit_t(str, summ) == 0)
        return(0);
    if (my_str_compare(str[0], "env") == 1)
        env(copy);
    else 
        fct_fork( id, str, envp, status);
    free(str);
    free(summ);
    minishell(ac, av, envp);
}

void fct_fork(int id, char ** str, char **envp, int status) 
{
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

int exit_t(char **str, char *summ) {
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