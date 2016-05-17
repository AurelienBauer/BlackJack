/*
** my_str_to_worktab.c for  in /home/aurelien/rendu/Cycle_PSU/PSU_2015_my_sokoban/lib
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Mon Feb  1 19:42:29 2016 Aurélien
** Last update Tue Feb  2 13:45:55 2016 Aurélien
*/

#include <stdio.h>
#include <stdlib.h>

int	my_strlen(char *str);

int	my_strspace(char *str)
{
  int	i;

  i = 0;
  while (str[i] != ' ' && str[i] != '\t' && str[i] !='\0')
    i++;
  return (i);
}

char	*clear_str(char *str)
{
  int	count;
  int	is_space;
  char	*new_str;

  count = 0;
  is_space = 2;
  if ((new_str = malloc(sizeof(char) * (my_strlen(str)) + 1)) == NULL)
       exit(1);
  while (*str)
    {
      if (*str == ' ' || *str == '\t')
	is_space++;
      if (*str != ' ' && *str != '\t')
	is_space = 0;
      if (is_space < 2)
	new_str[count++] = *str;
      str++;
    }
  new_str[count] = '\0';
  if (new_str[my_strlen(new_str) - 1] == ' ' ||
      new_str[my_strlen(new_str) - 1] == '\t')
    new_str[my_strlen(new_str) - 1] = '\0';
  return (new_str);
}

int	wordtab_count_words(char *str)
{
  int	count;

  count = 0;
  while (*str)
    {
      if (*str == ' ' || *str == '\t')
	count++;
      str++;
    }
  return (count + 1);
}

char	**alloc_strtab(char **tab, char *str, int words)
{
  int	i;

  i = -1;
  if ((tab = malloc(sizeof(char*) * (words + 1))) == NULL)
    exit(1);
  while (++i < words)
    {
      if ((tab[i] = malloc(sizeof(char) * (my_strspace(str) + 10))) == NULL)
	exit(1);
    }
  return (tab);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	words;
  int   i;
  int	j;

  str = clear_str(str);
  words = wordtab_count_words(str);
  tab = alloc_strtab(tab, str, words);
  i = -1;
  while (++i < words)
    {
      j = 0;
      while ((*str != ' ' && *str != '\t') && *str != '\0')
	{
	  tab[i][j] = *str;
	  j++;
	  str++;
	}
      tab[i][j] = '\0';
      if (*str)
	str++;
    }
  return (tab);
}
