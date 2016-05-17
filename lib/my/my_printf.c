/*
** my_printf.c for  in /home/bauer_b/rendu/PSU_2015_my_printf
** 
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
** 
** Started on  Wed Nov  4 14:21:44 2015 Aurélien BAUER
** Last update Mon Dec  7 10:09:39 2015 Aur�lien
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void    my_putchar(char c);
void    my_putstr(char *str);
int	my_nbrlen(int nbr);
int	my_strlen(char *str);
char	*my_revstr(char *str);
int	make_d_i(int nbr);
int	make_c(int c);
int	make_s(char *str);
int	make_u(unsigned int nbr);
int	make_p(long long nbr);


int		put_convert_to_nbase(unsigned int nbr, int base, char b)
{
  unsigned int	quo;
  char		*result;
  int		j;

  j = 0;
  result = malloc(my_nbrlen(nbr) * 3 + 2);
  if (result == NULL)
    return (0);
  while (nbr > 0)
    {
      quo = nbr / base;
      while (nbr >= base)
	nbr = nbr - base;
      if (nbr > 9 && b == 0)
	nbr = nbr + 7;
      if (nbr > 9 && b == 1)
	nbr = nbr + 39;
      result[j] = nbr + '0';
      j++;
      nbr = quo;
    }
  result[j] = '\0';
  my_putstr(my_revstr(result));
  return (my_strlen(result));
}

int		put_convert_to_oct(char rest)
{
  int		j;
  int		quo;
  char		stnb[3] = "000";

  j = 2;
  while ((quo = rest / 8) > 0 || j == 2 || j != 0)
    {
      while (rest > 8)
	rest = rest - 8;
      stnb[j] = rest + '0';
      j--;
      rest = quo;
    }
  my_putchar(stnb[0]);
  my_putchar(stnb[1]);
  my_putchar(stnb[2]);
}

int		maj_S(const char *str)
{
  int		i;
  int		nbrchar;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  my_putchar('\\');
	  put_convert_to_oct(str[i]);
	  nbrchar = nbrchar + 4;
	}
      else
	{
	  my_putchar(str[i]);
	  nbrchar++;
	}
      i++;
    }
  return (nbrchar);
}

int		processing(int nbchar, const char *str, va_list ap)
{
  str++;
  if (*str == 'd' || *str == 'i')
    nbchar = nbchar + make_d_i(va_arg(ap, int));
  else if (*str == 'c')
    nbchar = nbchar + make_c(va_arg(ap, int));
  else if (*str == 's')
    nbchar = nbchar + make_s(va_arg(ap, char*));
  else if (*str == '%')
    my_putchar('%');
  else if (*str == 'u')
    nbchar = nbchar + make_u(va_arg(ap, unsigned int));
  else if (*str == 'S')
    nbchar = nbchar + maj_S(va_arg(ap, char*));
  else if (*str == 'o')
    nbchar = nbchar + put_convert_to_nbase(va_arg(ap, unsigned int), 8, 0);
  else if (*str == 'b')
    nbchar = nbchar +put_convert_to_nbase(va_arg(ap, unsigned int), 2, 0);
  else if (*str == 'x')
    nbchar = nbchar + put_convert_to_nbase(va_arg(ap, unsigned int), 16, 1);
  else if (*str == 'X')
    nbchar = nbchar + put_convert_to_nbase(va_arg(ap, unsigned int), 16, 0);
  else if (*str == 'p')
    nbchar = nbchar + make_p(va_arg(ap, long long));
  return (nbchar);
}

int		my_printf(const char *str, ...)
{
  va_list	ap;
  int		nbrchar;

  nbrchar = 0;
  va_start(ap, str);
  while (*str != '\0')
    {
      if (*str == '%')
	{
	 nbrchar = nbrchar +  processing(nbrchar, str, ap);
	  str++;
	}
      else
	{
	  nbrchar++;
	  my_putchar(*str);
	}
      str++;
    }
  va_end(ap);
  return (nbrchar);
}
