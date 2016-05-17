/*
** my_putnbr.c for  in /home/aurelien/rendu/PSU_2015_my_printf/lib/my
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Mon Nov  9 13:43:43 2015 Aurélien
** Last update Fri Nov 13 11:16:54 2015 Aurélien
*/

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_power_it(int nb, int power);

int	my_putnbr(int nbr)
{
  int   i;
  int   j;

  i = 0;
  if (nbr == 0)
    my_putchar('0');
  if (nbr == -2147483648)
    {
      my_putstr("-2147483648");
      return (0);
    }
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
    my_putchar(nbr / my_power_it(10, i) % 10 + '0');
}
