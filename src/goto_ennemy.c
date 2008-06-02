/*
** goto_ennemy.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon Jun  2 02:26:00 2008 caner candan
** Last update Mon Jun  2 07:46:30 2008 caner candan
*/

#include "lemipc.h"

static int	touch(t_info *info, int x, int y)
{
  int	x_tmp;
  int	y_tmp;

  x_tmp = info->x;
  y_tmp = info->y;
  if (info->share->zone[x][y].team_idx < 0 ||
      info->share->zone[x][y].team_idx == info->team_idx)
    return (0);
  if (x - info->x < 0)
    x_tmp--;
  else if (x - info->x > 0)
    x_tmp++;
  if (y - info->y < 0)
    y_tmp--;
  else if (y - info->y > 0)
    y_tmp++;
  if (info->share->zone[x_tmp][y_tmp].team_idx < 0)
    {
      info->share->zone[info->x][info->y].team_idx = -1;
      info->x = x_tmp;
      info->y = y_tmp;
      info->share->zone[info->x][info->y].team_idx = info->team_idx;
      return (1);
    }
  return (0);
}

int	goto_ennemy(t_info *info)
{
  int	x;
  int	y;
/*   int	r; */
/*   int	x_mv; */
/*   int	y_mv; */

  for (x = 0; x < MAP_X; x++)
    for (y = 0; y < MAP_Y; y++)
      {
	if (!touch(info, x, y))
	  {
	    continue;
	  }
	return (0);
      }
return (-1);
}
