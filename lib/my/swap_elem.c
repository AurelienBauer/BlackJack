/*
** swap_elem.c for  in /home/aurelien/rendu/Bootstrap_Pushswap/etape_0
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Fri Nov  6 09:37:27 2015 Aurélien
** Last update Sun Nov 29 15:54:37 2015 Aurélien
*/

void	swap_elem(char *array, int index1, int index2)
{
  int	tmp;

  tmp = array[index1];
  array[index1] = array[index2];
  array[index2] = tmp;
}
