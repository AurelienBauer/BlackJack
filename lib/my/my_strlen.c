/*
** my_strlen.c for my_strlen in /home/bauer_b/test2
** 
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
** 
** Started on  Tue Oct  6 12:52:43 2015 Aurélien BAUER
** Last update Fri Nov 13 11:17:37 2015 Aur�lien
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i +1;
  return (i);
}
