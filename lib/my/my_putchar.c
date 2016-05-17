/*
** my_putchar.c for my_putchar in /home/bauer_b/test2
** 
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
** 
** Started on  Mon Oct  5 09:38:32 2015 Aurélien BAUER
** Last update Fri Nov 13 11:10:45 2015 Aur�lien
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
