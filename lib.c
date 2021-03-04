/*
** EPITECH PROJECT, 2019
** lib
** File description:
** a
*/

#include "my.h"

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

int my_strlen_env(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
