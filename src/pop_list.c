/*
** pop_list.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 16:02:54 2008 caner candan
** Last update Thu May 15 16:04:43 2008 caner candan
*/

#include <stdlib.h>
#include "lemipc.h"

void		*pop_list(t_list **t)
{
  t_list	*tmp;
  void		*data;

  if (!(*t))
    return (NULL);
  tmp = (*t)->next;
  data = (*t)->data;
  free(*t);
  *t = tmp;
  return (data);
}
