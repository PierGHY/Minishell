/*
** EPITECH PROJECT, 2019
** test
** File description:
** a
*/

#include "my.h"

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
        i++;
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
    char **str = malloc(sizeof(char *) * ((counter(summ) + 1)));
    int i = 0;
    int z = 0;
    int j = 0;
    int k = 0;

    for(int i= 0; i <= counter(summ) + 1; i++)
        str[i] = malloc(sizeof(char) * (my_strlen(summ)));
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