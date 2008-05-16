/*
** get_random.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 16:37:52 2008 caner candan
** Last update Thu May 15 16:39:11 2008 caner candan
*/

#include <stdlib.h>
#include "lemipc.h"

int		get_random(int max, int diff)
{
  double	val;
  int		res;

  while (42)
    {
      val = (double)max * random();
      if ((res = (int)(val / (RAND_MAX + 1.0)) % (max + 1)) != diff)
	break;
    }
  return (res);
}
