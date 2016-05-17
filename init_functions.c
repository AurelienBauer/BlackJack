/*
** init_functions.c for  in /home/aurelien/rendu/Cycle_CPE/CPE_2015_Blackjack
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Thu Mar  3 14:49:40 2016 Aurélien
** Last update Thu Mar 24 13:29:50 2016 Aurélien
*/

#include "blackjack.h"

char		*init_cards(char *cards)
{
  int		i;
  int		j;

  if ((cards = malloc(sizeof(char) * (NBR_CARDS))) == NULL)
    return (NULL);
  i = -1;
  while (++i < 13)
    {
      j = -1;
      while (++j < 4)
	cards[i * 4 + j] = i + 1;
    }
  return (cards);
}

t_player	*init_player(char *cards, t_player *player)
{
  int		i;

  i = -1;
  if ((player = malloc(sizeof(t_player) * 3)) == NULL)
    return (NULL);
  player[0].name = "You";
  player[1].name = "Ben";
  player[2].name = "Dealer";
  while (++i <= NBR_PLAYERS)
    {
      player[i].cards = NULL;
      player[i].is_turn = 0;
      add_cards_to_player(cards, &player[i]);
      if (i != 2)
	add_cards_to_player(cards, &player[i]);
      player[i].is_turn = 0;
      if (value_cards(player[i]) == 21)
	player[i].state = 3;
      else
	player[i].state = 0;
    }
  return (player);
}
