/*
** push_list.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 15:59:39 2008 caner candan
** Last update Thu May 15 16:01:12 2008 caner candan
*/

#include "lemipc.h"
#include "x.h"

void		push_list(t_list **t, void *data)
{
  t_list	*new;

  new = xmalloc(sizeof(*new));
  new->data = data;
  new->next = *t;
  *t = new;
}
