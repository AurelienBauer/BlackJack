/*
** add_elem_inlist.c for  in /home/aurelien/rendu/Cycle_PSU/PSU_2015_minishell1/lib/srcs
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Thu Feb 11 17:06:00 2016 Aurélien
** Last update Mon Mar  7 18:31:09 2016 Aurélien
*/

typedef struct		s_listchar
{
  char			data;
  struct s_listchar	*next;
}			t_listchar;

#include <stdlib.h>

t_listchar	*add_char_inlist(t_listchar *list, char data)
{
  t_listchar	*new_list;
  t_listchar	*tmp_list;

  tmp_list = list;
  if ((new_list = malloc(sizeof(*list))) == NULL)
    return (0);
  new_list->data = data;
  new_list->next = NULL;
  if (list == NULL)
    return (new_list);
  while (tmp_list->next != NULL)
    tmp_list = tmp_list->next;
  tmp_list->next = new_list;
  return (list);
}
