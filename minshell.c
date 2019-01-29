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

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    int pow = 1;
    int nbcpy = nb;
    int lon = 0;

    while (nbcpy > 9) {
        pow = pow * 10;
        nbcpy = nbcpy / 10;
        lon = lon + 1;
        }
    while (lon > 0) {
        my_putchar((nb/pow) + 48);
        nb = nb % pow;
        pow = pow / 10;
        lon = lon - 1;
    }
    my_putchar(nb + '0');
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != ' ' && str[i] != '\n')
        i = i + 1;
    return (i);
}

int counter(char const *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ') {
            j++;      
        }
        i++;
    }

    return (j);
}

int my_str_compare(char *str, char *other)
{
    int i = 0;
    int j = 0;

    while(str[i] != '\0' && other[i] != '\0') {
        i ++;
        if (str[i] == other[i])
            j++;
    }
    if(j == i)
        return(1);
    else
        return(0);
}

int my_strlenz(char *str, int k)
{
    int i = k;
    int j = 0;

    while (str[i] != ' ' && str[i] != '\0'){
        i = i + 1;
        j++;
    }
    return (j);
}

char ** my_str_to_word_array( char * summ)
{
    char **str = malloc(sizeof(char *) * ((counter(summ + 1))));
    int i = 0;
    int z = 0;

    while (i <= counter(summ) + 1) {
        str[i] = malloc(sizeof(char) * (my_strlen(summ)));
        i = i + 1;
    }
    i = 0;
    int j = 0;
    int k = 0;

    while (i < counter(summ) + 1) {
        z = my_strlenz(summ, k);
        while (j <= z) {
            str[i][j] = (summ[k] == ' ' || summ[k] == '\n') ? '\0' : summ[k];
            j = j + 1;
            k = k + 1;
        }
        i ++;
        j = 0;
    }
    str[i] = NULL;
    return (str);
}

void env(char** copy) 
{
    int i = 0;
    
    while(copy[i] != NULL){
        my_putstr(copy[i]);
        my_putchar('\n');
        i++;
    }
}

void detect_PWD(){

}

void detect_OLPWD(){

}

int minishell(int ac, char ** av, char ** const envp)
{
    char **copy = envp;
    int id ;
    int status;
    pid_t process_id;
    int test = 0;
    pid_t return_pid = waitpid(process_id, &status, WNOHANG);
    size_t s;
    char *summ = NULL;

    my_putstr("$>");
    getline(&summ, &s, stdin);
    char ** str = my_str_to_word_array(summ);
    /*
    my_putstr("Program name:");
    my_putstr(str[0]);
    my_putstr("\n");
    my_putstr("Nb args:  ");
    my_put_nbr(counter(summ));
    my_putstr("\n");
    */
    if (my_str_compare(str[0], "env") == 1) {
        env(copy);
    }
    else {
        id = fork();
        if (id == 0 ) {
            /*
            my_putstr("Child PID:  ");
            my_put_nbr(getpid());
            my_putstr("\n");
            */
            execve(str[0], str, envp);
            exit(0);
        }
        else {
            wait(&status);
            /*
            my_putstr("Programme terminated.\n");
            my_putstr("status :  ");
            my_put_nbr(status);
            my_putstr("\n");
            */
        }
    }
    if (my_str_compare(str[0], "exit") == 1) {
        free(str);
        free(summ);
        //free(copy);
        return(0);
    }
    else {
        free(str);
        free(summ);
        //free(copy);
        minishell(ac, av, envp);
    }
}

void main(int ac, char ** av, char ** const envp)
{
    minishell(ac, av, envp);
}