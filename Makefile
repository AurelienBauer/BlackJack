##
## Makefile for  in /home/aurelien/rendu/PSU_2015_my_ls
## 
## Made by Aur�lien
## Login   <aurelien.bauer@epitech.net>
## 
## Started on  Thu Nov 26 15:34:08 2015 Aur�lien
## Last update Mon Mar  7 18:36:53 2016 Aur�lien
##

RM	= rm -f									\

CC	= gcc -g								\

NAME	= blackjack								\

CFLAGS	= -lmy -L ./lib -I ./include						\

SRCS	= main.c								\
	  init_functions.c							\
	  cal_functions.c							\
	  display.c								\
	  win_functions.c

OBJS	= $(SRCS:.c=.o)								\

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) *~

re: fclean all

.PHONY: all clean re
