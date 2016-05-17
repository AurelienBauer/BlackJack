/*
** my_match.c for  in /home/aurelien/rendu/Cycle_CPE/CPE_2015_Blackjack/lib/my
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Thu Mar  3 13:37:34 2016 Aurélien
** Last update Thu Mar  3 13:38:03 2016 Aurélien
*/

int		my_strlen(char *str);

int             my_match(char *str, char *str2)
{
  int           i;

  i = 0;
  if (my_strlen(str) != my_strlen(str2))
    return (-1);
  while (str[i])
    {
      if (str[i] != str2[i])
	return (-1);
      i++;
    }
  return (0);
}
