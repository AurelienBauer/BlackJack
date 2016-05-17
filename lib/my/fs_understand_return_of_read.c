/*
** fs_understand_return_of_read.c for  in /home/aurelien/rendu/CPE_2015_BSQ_bootstrap
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Tue Dec  1 11:28:28 2015 Aurélien
** Last update Mon Dec  7 10:11:38 2015 Aurélien
*/

#include <unistd.h>
#include <stdlib.h>

int     fs_open_file(char *filepath);
int	my_printf(const char *str, ...);

void	fs_understand_return_of_read(int fd, char *buffer, int size)
{
  int	ssize;

  ssize = read(fd, buffer, size);
  if (ssize == -1)
    {
      my_printf("read a fail\n");
      exit(1);
    }
  if (ssize == 0)
    my_printf("read n'a plus rien a lire\n");
  if (ssize < size && ssize != -1)
    my_printf("read n'a pas rempli tout le buffer\n");
  if (ssize == size)
    my_printf("read a rempli tout le buffer\n");
}
