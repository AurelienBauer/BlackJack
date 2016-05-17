/*
** mem_allocat_2d_array.c for  in /home/aurelien/rendu/CPE_2015_BSQ_bootstrap
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Wed Dec  2 09:32:58 2015 Aurélien
** Last update Sat Dec 26 16:20:30 2015 Aurélien
*/

#include <stdlib.h>

char	**mem_allo_2d_array(int nb_rows, int nb_cols)
{
  int	i;
  char	**ret;

  i = -1;
  if ((ret = malloc(sizeof(char*) * nb_cols)) == NULL)
    return (0);
  while (++i < nb_cols)
    {
      if ((ret[i] = malloc(sizeof(char) * nb_rows)) == NULL)
	return (0);
    }
  return (ret);
}
