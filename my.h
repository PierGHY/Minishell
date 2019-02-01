/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** a
*/

#ifndef MY_H_

#define MY_H_

#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

int my_strlen_env(char const *str);
int count_path(char * path);
int my_strlenp(char const *str);
void my_putstr(char const *str);
char ** my_str_to_word_array(char * summ);
int exit_t(char ** str, char *summ);
int my_str_compare(char * str, char * other);
void env(char **copy);
void fct_fork(char *go, char ** str, char ** envp, int status);
int my_strlen(char const * str);
void my_putchar(char c);
void to_cd(char ** str, char ** copy);
int my_str_compare_env(char * str, char *other);
char ** pars_path(char * str);
int minishell(int ac, char **av , char ** const envp);
char ** copy_env(char ** envp);
char * detect_comm(char ** copy, char * summ);
char * clean_str(char * summ);
int ife(char **str, char* summ, char ** copy, char ** envp);

#endif