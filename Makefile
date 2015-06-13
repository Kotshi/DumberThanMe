## Makefile for rt in /home/leboeu_q/sem2/igraph/MUL_2014_rtracer
##
## Made by Quentin Leboeuf
## Login   <leboeu_q@epitech.net>
##
## Started on  Wed May  6 11:18:30 2015 Quentin Leboeuf
## Last update Sat Jun 13 17:46:33 2015 Picou Gildas
##

CC	= gcc

RM	= rm -rf

SRC	= display.c \
	  fill_image.c \
	  main.c \
	  my_pixel_put_to_image.c

OBJ	= $(SRC:.c=.o)

NAME	= DumberThanMe

CFLAGS	=  -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lmlx -lXext -lX11 -lm

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	clean fclean all

.PHONY:	all clean fclean all
