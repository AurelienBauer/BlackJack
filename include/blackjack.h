/*
** blackjack.h for  in /home/thomas/Documents/epitech/CPE_2015_Blackjack
** 
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
** 
** Started on  Thu Mar  3 09:28:12 2016 Thomas HENON
** Last update Fri Mar 11 12:21:59 2016 Aurélien
*/

#ifndef __BLACKJACK_H__
# define __BLACKJACK_H__

# define NBR_CARDS 52
# define NBR_PLAYERS 2

# include <stdlib.h>
# include <stdio.h>
# include <time.h>

typedef struct		s_listchar
{
  char			data;
  struct s_listchar	*next;
}			t_listchar;

typedef struct		s_list
{
  void			*data;
  struct s_list		*next;
}			t_list;

typedef struct	s_player
{
  char		*name;
  t_listchar	*cards;
  char		is_turn;
  char		state;
}		t_player;

/*
display.c
*/
void		display_turn(t_player *players);
void		display_turn_cards(t_player player);
void            display_value_cards(int value);

/*
cal_functions.c
*/
int             value_cards(t_player player);
void	        add_cards_to_player(char *cards, t_player *player);
int             nb_char_in_list(t_listchar *list);

/*
** init_functions.c
*/
char		*init_cards(char *cards);
t_player        *init_player(char *cards, t_player *player);

/*
win_functons.c
*/
void            win_by_blackjack(t_player *player);
int		find_score_max(t_player *player);
void            normal_win(t_player *player);

/*
libmy.a
*/
int             my_power_it(int nb, int power);
void            my_putchar(char c);
char            my_putnbr(int nbr);
int             my_putstr(char *str);
int             my_strlen(char *str);
int             my_nbrlen(int nbr);
char            *my_revstr(char *str);
int             my_put_unsignednbr(unsigned int nbr);
int             my_printf(const char *str, ...);
int             put_convert_to_nbase(unsigned int nbr, int base, char b);
int             put_convert_to_oct(char rest);
int             maj_S(const char *str);
int             make_d_i(int nbr);
int             make_c(int c);
int             make_s(char *str);
int             make_u(unsigned int nbr);
int             make_p(long long nbr);
int             my_getnbr(char  *str);
int             my_nbrlen_array(int *array);
char            *my_clchar_in_str(char *str, char car);
char            *my_strcat(char *data, char *add);
char            *uint_to_char(unsigned int nbr);
int             fs_open_file(char *filepath);
void            fs_understand_return_of_read(int fd, char *buffer, int size);
char            *get_next_line(const int fd);
char            **my_str_to_wordtab(char *str);
char            *my_strcpy(char *str, char *dest);
t_listchar	*add_char_inlist(t_listchar *list, char data);
int             my_match(char *str, char *str2);
t_list		*add_elem_inlist(t_list *list, void *data);
int		nb_elem_inlist(t_list *list);

#endif
