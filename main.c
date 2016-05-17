/*
** main.c for  in /home/aurelien/rendu/Cycle_CPE/CPE_2015_Blackjack
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Thu Mar  3 12:56:25 2016 Aurélien
** Last update Thu Mar 24 13:29:53 2016 Aurélien
*/

#include "blackjack.h"

t_player	state_2(t_player player)
{
  if (value_cards(player) > 21)
    {
      my_printf("Bursting ! Out with %d points\n", value_cards(player));
      player.state = 2;
    }
  return (player);
}

t_player       	dealer_turn(char *cards, t_player *players)
{
  char		*buffer;

  players[2].is_turn = 1;
  while (players[2].state ==  0)
    {
      if (value_cards(players[2]) < 16)
	{
	  my_printf("(Dealer) Action: hit\nDealer got a new card:");
	  add_cards_to_player(cards, &players[2]);
	  players[2] = state_2(players[2]);
	}
      else
	{
	  my_printf("(Delear) Action: stand\nTurn ended with %d points\n",
		    value_cards(players[2]));
	  players[2].state = 1;
	}
      display_turn(players);
    }
  players[2].is_turn = 0;
  return (players[2]);
}

t_player       	ia_turn(char *cards, t_player *players)
{
 char		*buffer;

  players[1].is_turn = 1;
  while (players[1].state ==  0)
    {
      if ((value_cards(players[1]) < value_cards(players[0]) &&
	  value_cards(players[0]) <= 21) || value_cards(players[0]) < 16)
	{
	  my_printf("(Ben) Action: hit\nBen got a new card:");
	  add_cards_to_player(cards, &players[1]);
	  players[1] = state_2(players[1]);
	}
      else
	{
	  my_printf("(Ben) Action: stand\nTurn ended with %d points\n",
		    value_cards(players[1]));
	  players[1].state = 1;
	}
      display_turn(players);
    }
  players[1].is_turn = 0;
  return (players[1]);
}

t_player       	your_turn(char *cards, t_player *players)
{
  char		*buffer;

  while (players[0].state ==  0)
    {
      my_printf("(You) Action: ");
      if ((buffer = get_next_line(0)) == NULL)
	exit (0);
      if (my_match(buffer, "hit") == 0)
	{
	  my_printf("You got a new card:");
	  add_cards_to_player(cards, &players[0]);
	  players[0] = state_2(players[0]);
	}
      else if (my_match(buffer, "stand") == 0)
	{
	  my_printf("Turn ended with %d points\n", value_cards(players[0]));
	  players[0].state = 1;
	}
      else
	my_printf("Invalid action. Use 'hit' or 'stand'\n");
      display_turn(players);
    }
  players[0].is_turn = 0;
  return (players[0]);
}

int		main()
{
  char		*cards;
  t_player	*players;

  srand(time(NULL));
  if ((cards = init_cards(cards)) == NULL)
    return (0);
  if ((players = init_player(cards, players)) == NULL)
    return (0);
  players[0].is_turn = 1;
  display_turn(players);
  if (players[0].state != 3 && players[1].state != 3 && players[2].state != 3)
    {
      players[0] = your_turn(cards, players);
      players[1] = ia_turn(cards, players);
      players[2] = dealer_turn(cards, players);
    }
  else
    {
      win_by_blackjack(players);
      return (0);
    }
  normal_win(players);
  return (0);
}
