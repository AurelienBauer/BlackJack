/*
** my_strcat.c for  in /home/aurelien/rendu/PSU_2015_my_ls/lib
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Thu Nov 26 16:27:07 2015 Aurélien
** Last update Tue Jan  5 15:33:13 2016 Aurélien
*/

#include <stdlib.h>

int	my_strlen(char *str);

char	*my_strcat(char *data, char *add)
{
  int	i;
  char	*dest;

  i = 0;
  if ((dest = malloc(sizeof(char) * (my_strlen(data) +
				     my_strlen(add) + 1))) == NULL)
    return (0);
  while (*data != '\0')
    {
      dest[i] = *data;
      data++;
      i++;
    }
  while (*add != '\0')
    {
      dest[i] = *add;
      add++;
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
