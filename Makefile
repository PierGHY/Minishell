##
## EPITECH PROJECT, 2019
## make
## File description:
## a
##

SRC     =   minshell.c \
			lib.c \
			parthstr.c \
			principal_fct.c \
			env.c \
			other.c \
			libe.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS = -g3

all:    $(NAME)

$(NAME):        $(OBJ)
		gcc -lm $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re