/*
** add_elem_inlist.c for  in /home/aurelien/rendu/Cycle_PSU/PSU_2015_minishell1/lib/srcs
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Thu Feb 11 17:06:00 2016 Aurélien
** Last update Thu Feb 11 17:37:19 2016 Aurélien
*/

typedef struct  s_list
{
  void          *data;
  struct s_list *next;
}               t_list;

#include <stdlib.h>

t_list          *add_elem_inlist(t_list *list, void *data)
{
  t_list        *new_list;
  t_list        *tmp_list;

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
