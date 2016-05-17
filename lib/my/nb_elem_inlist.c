/*
** nb_elem_inlist.c for  in /home/aurelien/rendu/Cycle_CPE/CPE_2015_Blackjack/lib/my
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Mon Mar  7 18:42:55 2016 Aurélien
** Last update Mon Mar  7 18:48:32 2016 Aurélien
*/

#include <stdio.h>

typedef struct		s_list
{
  void			*data;
  struct s_list		*next;
}			t_list;

int		nb_elem_inlist(t_list *list)
{
  int		i;

  i = 0;
  while (list != NULL)
    {
      ++i;
      list = list->next;
    }
  return (i);
}
