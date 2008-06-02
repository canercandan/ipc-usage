/*
** set_backdrop.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Jun  1 19:17:04 2008 caner candan
** Last update Sun Jun  1 21:22:43 2008 caner candan
*/

#include <stdio.h>
#include "lemipc.h"

void	set_backdrop(t_info *info)
{
  int	x;
  int	y;

  for (y = 0; y < (MAP_Y + 2) * FLOOR_Y; y += FLOOR_Y)
    for (x = 0; x < (MAP_X + 2) * FLOOR_X; x += FLOOR_X)
      {
	if (x < FLOOR_X ||
	    y < FLOOR_Y ||
	    x > ((MAP_X + 2) * FLOOR_X) - (FLOOR_X * 2) ||
	    y > ((MAP_Y + 2) * FLOOR_Y) - (FLOOR_Y * 2))
	  set_floor(info->gfx, 0, x, y);
	else
	  set_floor(info->gfx, 5, x, y);
      }
}
