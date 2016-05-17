/*
** my_power_it.c for Day05Ex3 in /home/bauer_b/test
** 
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
** 
** Started on  Fri Oct  2 17:25:12 2015 Aurélien BAUER
** Last update Fri Nov  6 18:45:49 2015 Aur�lien
*/

int     my_power_it(int nb, int power)
{
  int   result;
  int   c;
  int   resultprov;

  result = 0;
  c = 0;
  resultprov = 1;
  if (power == 0)
    result = 1;
  else
    {
      while (c != power)
        {
          result = resultprov * nb;
          c = c + 1;
          resultprov = result;
        }
    }
  return (result);
}
