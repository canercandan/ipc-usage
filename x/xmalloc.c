/*
** xmalloc.c for lemipc in /home/candan_c/cu/rendu/project/lemipc/x
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 15:50:38 2008 caner candan
** Last update Thu May 15 15:52:51 2008 caner candan
*/

#include <stdlib.h>
#include <stdio.h>
#include "x.h"

void	*xmalloc(int size)
{
  void	*p;

  p = malloc(size);
  if (p == NULL)
    {
      perror("malloc\n");
      exit(-1);
    }
  return (p);
}
