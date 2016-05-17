/*
** my_putnbr.c for my_putnbr in /home/bauer_b/test2
** 
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
** 
** Started on  Thu Oct 15 17:59:38 2015 Aurélien BAUER
** Last update Fri Nov 13 11:28:36 2015 Aur�lien
*/

void    my_putchar(char c);
void    my_putstr(char *str);
int     my_power_it(int nb, int power);

void		my_put_unsignednbr(unsigned int nbr)
{
  int		i;
  unsigned int	j;

  i = 0;
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = nbr * -1;
    }
  j = nbr;
  while (j > 0)
    {
      j = j / 10;
      ++i;
    }
  while (--i > -1)
    {
      my_putchar(nbr / my_power_it(10, i) % 10 + '0');
    }
}
