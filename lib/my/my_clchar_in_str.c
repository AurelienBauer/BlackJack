/*
** my_clchar_in_str.c for my_cl_char_in_str in /home/bauer_b/rendu/Piscine_C_infinadd/lib/my
** 
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
** 
** Started on  Fri Oct 23 14:23:27 2015 Aurélien BAUER
** Last update Thu Nov 26 13:09:34 2015 Aur�lien
*/

#include <stdlib.h>

int	my_strlen(char *str);

char	*my_clchar_in_str(char *str, char car)
{
  char  *new_str;
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[j] != '\0')
    {
      if (str[j] == car)
	i++;
      j++;
    }
  new_str = malloc(my_strlen(str) - i);
  if (new_str == NULL)
    return (0);
  j = 0;
  i = 0;
  while (str[j] != '\0')
    {
      if (str[j] != car)
	{
	  new_str[i] = str[j];
	  i++;
	}
      j++;
    }
  return (new_str);
}
