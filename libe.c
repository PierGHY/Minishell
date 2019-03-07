/*
** EPITECH PROJECT, 2019
** libe
** File description:
** a
*/

#include "my.h"

void my_putchare(char c)
{
    write(2, &c, 1);
}

void my_pute(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchare(str[i]);
        i = i + 1;
    }
}