/*
** win_functions.c for  in /home/aurelien/rendu/Cycle_CPE/CPE_2015_Blackjack
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Mon Mar  7 18:11:38 2016 Aurélien
** Last update Fri Mar 11 12:27:01 2016 Aurélien
*/

#include "blackjack.h"

void		win_by_blackjack(t_player *player)
{
  int		i;
  t_list	*winner;

  i = -1;
  winner = NULL;
  while (++i <= NBR_PLAYERS)
    {
      if (player[i].state == 3)
        winner = add_elem_inlist(winner, (void *)player[i].name);
    }
  i = nb_elem_inlist(winner) - 1;
  while (winner != NULL)
    {
      my_printf("%s", (char *)winner->data);
      if (i > 0)
	{
	  my_printf(" and ");
	  i--;
	}
      winner = winner->next;
    }
  my_printf(" win !\n");
}

int		find_score_max(t_player *player)
{
  int		i;
  int		max;

  i = -1;
  max = 0;
  while (++i <= NBR_PLAYERS)
    {
      if (max < value_cards(player[i]) && value_cards(player[i]) <= 21)
	max = value_cards(player[i]);
    }
  return (max);
}

void		normal_win(t_player *player)
{
  int		i;
  t_list	*winner;
  int		score_max;

  i = -1;
  score_max = find_score_max(player);
  winner = NULL;
  while (++i <= NBR_PLAYERS)
    {
      if (value_cards(player[i]) == score_max)
        winner = add_elem_inlist(winner, (void *)player[i].name);
    }
  i = nb_elem_inlist(winner) - 1;
  while (winner != NULL)
    {
      my_printf("%s", (char *)winner->data);
      if (i > 0)
	{
	  my_printf(" and ");
	  i--;
	}
      winner = winner->next;
    }
  my_printf(" win !\n");
}
