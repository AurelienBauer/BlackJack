/*
** my_revstr.c for Day06Ex4 in /home/bauer_b/test2
** 
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
** 
** Started on  Mon Oct  5 12:23:04 2015 Aurélien BAUER
** Last update Fri Nov 13 11:17:55 2015 Aur�lien
*/

int	my_strlen(char *str);

void     my_swap(char *a, char *b)
{
  int   c;

  c = *b;
  *b = *a;
  *a = c;
}

char    *my_revstr(char *str)
{
  int   count;
  int	a;

  a = 0;
  count = my_strlen(str) - 1;
  while(count != a && a != (count + 1))
    {
      my_swap(&str[a], &str[count]);
      count = count - 1;
      a = a + 1;
    }
  return (str);
}
