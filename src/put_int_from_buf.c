/*
** put_int_from_buf.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 12:27:10 2008 caner candan
** Last update Thu May 15 15:03:46 2008 caner candan
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lemipc.h"

void	put_int_from_buf(int *elm, char **buf, char *delimit, int pos)
{
  char	*str;
  int	i;

  i = 0;
  while ((str = strsep(buf, delimit)))
    {
      if (!str[0])
	continue;
      if (pos == i)
	{
	  *elm = atoi(str);
	  break;
	}
      i++;
    }
}
