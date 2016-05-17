/*
** cal_functions.c for  in /home/aurelien/rendu/Cycle_CPE/CPE_2015_Blackjack
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Fri Mar  4 13:48:44 2016 Aurélien
** Last update Thu Mar 24 13:29:11 2016 Aurélien
*/

#include "blackjack.h"

int		nb_char_in_list(t_listchar *list)
{
  int		i;

  i = 0;
  while (list != NULL)
    {
      i++;
      list = list->next;
    }
  return (i);
}

int             value_cards(t_player player)
{
  char          somme;
  char          value;
  int           as;

  somme = 0;
  as = 0;
  while (player.cards != NULL)
    {
      value = player.cards->data;
      if (value > 10)
	value = 10;
      if (value == 1)
	as++;
      somme = somme + value;
      player.cards = player.cards->next;
    }
  if (as != 0)
    {
      if (somme + 10 <= 21)
	somme = somme + 10;
    }
  return (somme);
}

void		add_cards_to_player(char *cards, t_player *player)
{
  char		result;
  int		nb_rand;

  result = -1;
  while (result == -1)
    {
      nb_rand = rand() % NBR_CARDS;
      result = cards[nb_rand];
    }
  cards[nb_rand] = -1;
  if (player->is_turn == 1)
    {
      display_value_cards(result);
      my_printf("\n");
    }
  player->cards = add_char_inlist(player->cards, result);
}
