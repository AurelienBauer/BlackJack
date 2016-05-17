/*
** processing.c for  in /home/aurelien/rendu/PSU_2015_my_printf
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Wed Nov 11 17:03:12 2015 Aurélien
** Last update Fri Nov 13 11:29:31 2015 Aurélien
*/

#include <stdlib.h>
void    my_putchar(char c);
void    my_putstr(char *str);
int	my_putnbr(int nbr);
int	my_nbrlen(int nbr);
int	my_strlen(char *str);
void	my_put_unsignednbr(unsigned int nbr);
char	*my_revstr(char *str);

int	make_d_i(int nbr)
{
  int	nbrchar;

  nbrchar = 0;
  my_putnbr(nbr);
  if (nbr < 0)
    {
      nbr = nbr * -1;
      nbrchar++;
    }
  return (my_nbrlen(nbr) + nbrchar);
}

int	make_c(int c)
{
  my_putchar(c);
  return (1);
}

int	make_s(char *str)
{
  my_putstr(str);
  return (my_strlen(str));
}

int	make_u(unsigned int nbr)
{
  my_put_unsignednbr(nbr);
  return (my_nbrlen(nbr));
}

int	make_p(long long nbr)
{
  long long	 quo;
  char          *result;
  int           j;

  my_putstr("0x");
  j = 0;
  result = malloc(my_nbrlen(nbr) * 3 + 2);
  if (result == NULL)
    return (0);
  while (nbr > 0)
    {
      quo = nbr / 16;
      while (nbr >= 16)
	nbr = nbr - 16;
      if (nbr > 9)
	nbr = nbr + 39;
      result[j] = nbr + '0';
      j++;
      nbr = quo;
    }
  result[j] = '\0';
  my_putstr(my_revstr(result));
  return (my_strlen(result) + 2);
}
