/*
** my_putstr.c for My_putstr in /home/bauer_b/test2
** 
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
** 
** Started on  Mon Oct  5 09:47:30 2015 Aurélien BAUER
** Last update Fri Nov 13 11:15:19 2015 Aur�lien
*/

void	my_putchar(char c);

void	my_putstr (char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
}
