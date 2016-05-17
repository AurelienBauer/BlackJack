/*
** my_strcpy.c for  in /home/aurelien/rendu/Cycle_PSU/PSU_2015_minishell1/lib/srcs
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Thu Feb  4 15:23:16 2016 Aurélien
** Last update Thu Feb  4 15:40:27 2016 Aurélien
*/

#include <stdlib.h>

int	my_strlen(char *str);

char	*my_strcpy(char *str, char *dest)
{
  int	i;

  i = 0;
  if ((dest = malloc(sizeof(char) * my_strlen(str))) == NULL)
    return (0);
  while (str[i])
    {
      dest[i] = str[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
