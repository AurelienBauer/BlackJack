 /*
** display.c for  in /home/aurelien/rendu/Cycle_CPE/CPE_2015_Blackjack
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Thu Mar  3 10:46:09 2016 Aurélien
** Last update Mon Mar  7 18:08:01 2016 Aurélien
*/

#include "blackjack.h"

void		display_value_cards(int value)
{
  if (value == 11)
    my_printf(" J");
  else if (value  == 12)
    my_printf(" Q");
  else if (value == 13)
    my_printf(" K");
  else
    my_printf(" %d", value);
}

void		display_turn_cards(t_player players)
{
  char		value;
  int		value_card;

  value_card = value_cards(players);
  while (players.cards != NULL)
    {
      value = players.cards->data;
      display_value_cards(value);
      players.cards = players.cards->next;
    }
  if (players.state == 1)
    my_printf(" - %d", value_card);
  if (players.state == 2)
    my_printf(" - OUT");
  if (players.state == 3)
    my_printf(" - BLACKJACK");
  my_printf("\n");
}

void		display_turn(t_player *players)
{
  int		i;

  i = -1;
  my_printf("*************\n");
  while (++i <= NBR_PLAYERS)
    {
      if (players[i].is_turn == 1)
	my_printf(">");
      my_printf("%s:", players[i].name);
      display_turn_cards(players[i]);
    }
  my_printf("*************\n\n");
}
