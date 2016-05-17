/*
** my_getnbr.c for my_getnbr in /home/saubus_a
** 
** Made by alexandre saubusse
** Login   <saubus_a@epitech.net>
** 
** Started on  Fri Oct 23 14:58:41 2015 alexandre saubusse
** Last update Mon Feb  8 12:48:48 2016 Aurélien
*/

int	check_signe(char *str, int i)
{
  if (i > 0)
    {
      if (str[i - 1] == '-')
	return (1);
    }
  else
    {
      if (str[0] == '-')
	return (1);
    }
  return (0);
}

int	my_getnbr(char	*str)
{
  int	nb;
  int	i;
  int	signe;

  i = 0;
  nb = 0;
  signe = 0;
  while ((str[i] < 48 || str[i] > 57) && str[i] != '\0')
    i = i + 1;
  while ((str[i] > 47 && str[i] < 58) && str[i] != '\0')
    {
      nb = (nb * 10) + (str[i] - '0');
      signe = check_signe(str, i);
      i = i + 1;
    }
  if (signe == 1)
    nb = nb * -1;
  return (nb);
}
