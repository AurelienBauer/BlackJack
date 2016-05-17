/*
** my_nbrlen_array.c for  in /home/aurelien/rendu/CPE_year_Pushswap
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Mon Nov 16 12:34:05 2015 Aurélien
** Last update Mon Nov 16 12:37:48 2015 Aurélien
*/

int	my_nbrlen_array(int *array)
{
  int	i;

  i = 0;
  while (array[i] != '\0')
    i++;
  return (i);
}
