##
## Makefile for sudoki in /home/enzo/rendu/prog/sudoki-bi
## 
## Made by Enzo
## Login   <enzo@epitech.net>
## 
## Started on  Fri Feb 26 22:28:29 2016 Enzo
## Last update Sun Feb 28 22:44:56 2016 Khoualdia Sabri
##

CC	= gcc

RM	= rm -f

LDFLAGS = -W -Wall -Werror

NAME	= sudoki-bi

SRCS	= get_next_line.c \
	  su_load.c \
	  error.c \
	  sudoku.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
