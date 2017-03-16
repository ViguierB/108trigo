##
## Makefile for math in /home/benji_epitech/Maths/108trigo
## 
## Made by Benjamin Viguier
## Login   <benjamin.viguier@epitech.eu>
## 
## Started on  Wed Mar 15 14:15:00 2017 Benjamin Viguier
## Last update Wed Mar 15 22:44:19 2017 Benjamin Viguier
##

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -g -I./include/

SRC	=	main.c	\
		sdlm.c	\
		matrix.c

OBJ	=	$(SRC:.c=.o)

NAME	=	108trigo

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lm

clean	:
	rm -f $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
