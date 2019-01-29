##
## EPITECH PROJECT, 2019
## make
## File description:
## a
##

SRC     =   minshell.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:    $(NAME)

$(NAME):        $(OBJ)
		gcc -lm -g3 -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re