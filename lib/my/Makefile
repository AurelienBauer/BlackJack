## load_2d_arr_from_file.c		\
##
## Makefile for my_MakeFile in /home/bauer_b/rendu/Piscine_C_infinadd/lib/my
## 
## Made by Aurélien BAUER
## Login   <bauer_b@epitech.net>
## 
## Started on  Mon Oct 19 10:25:08 2015 Aurélien BAUER
## Last update Mon Mar  7 18:47:17 2016 Aur�lien
##

CC	= gcc

RM	= rm -f *~

NAME	= ../libmy.a

SRCS	= my_putchar.c				\
	  my_putstr.c				\
	  my_putnbr.c				\
	  my_strlen.c				\
	  my_power_it.c				\
	  my_revstr.c				\
	  my_nbrlen.c				\
	  my_put_unsignednbr.c			\
	  my_printf.c				\
	  processing.c				\
	  my_getnbr.c				\
	  my_nbrlen_array.c			\
	  my_clchar_in_str.c			\
	  my_strcat.c				\
	  uint_to_char.c			\
	  swap_elem.c				\
	  fs_open_file.c			\
	  fs_understand_return_of_read.c	\
	  mem_allo_2d_array.c			\
	  get_next_line.c			\
	  my_str_to_wordtab.c			\
	  my_strcpy.c				\
	  my_match.c				\
	  add_char_inlist.c			\
	  add_elem_inlist.c			\
	  nb_elem_inlist.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)	\
	&& ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
