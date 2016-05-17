/*
** fs_open_file.c for  in /home/aurelien/rendu/CPE_2015_BSQ_bootstrap
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Tue Dec  1 10:35:30 2015 Aurélien
** Last update Mon Dec 28 19:10:42 2015 Aurélien
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int	my_printf(const char *str, ...);

int	fs_open_file(char *filepath)
{
  int	inode;
  if ((inode = open(filepath, O_RDONLY)) == -1)
    {
      my_printf("FAILURE : open file\n");
      exit(1);
    }
  return (inode);
}
