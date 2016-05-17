
/*
** uint_to_char.c for  in /home/aurelien/rendu/PSU_2015_my_ls/lib
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Fri Nov 27 10:06:55 2015 Aurélien
** Last update Sat Dec  5 08:40:18 2015 Aurélien
*/

#include <stdlib.h>

int		my_power_it(int nb, int power);

char		*uint_to_char(unsigned int nbr)
{
  int		i;
  unsigned int	j;
  char		*str;

  i = 0;
  j = nbr;
  while (j > 0)
    {
      j = j / 10;
      ++i;
    }
  if ((str = malloc(sizeof(char) * i)) == NULL)
    return (0);
  if (nbr == 0)
    str = "0\0";
  j = 0;
  while (--i > -1)
    {
      str[j] = (nbr / my_power_it(10, i) % 10 + '0');
      j++;
    }
  return (str);
}
