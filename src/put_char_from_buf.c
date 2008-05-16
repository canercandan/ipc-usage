/*
** put_char_from_buf.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 12:22:44 2008 caner candan
** Last update Thu May 15 15:03:51 2008 caner candan
*/

#include <string.h>
#include "lemipc.h"

void	put_char_from_buf(char **elm, char **buf, char *delimit, int pos)
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
	  *elm = strdup(str);
	  break;
	}
      i++;
    }
}
