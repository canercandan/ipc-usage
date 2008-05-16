/*
** init_random.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 16:36:07 2008 caner candan
** Last update Thu May 15 16:36:59 2008 caner candan
*/

#include <stdlib.h>
#include <sys/time.h>
#include "lemipc.h"

void	init_random(void)
{
  srandom(time(NULL));
}
