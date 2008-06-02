/*
** draw_gfx.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Jun  1 19:06:31 2008 caner candan
** Last update Mon Jun  2 02:15:08 2008 caner candan
*/

#include <SDL.h>
#include "lemipc.h"

static void	put_clients(t_info *info)
{
  int		x;
  int		y;

  for (x = 0; x < MAP_X; x++)
    for (y = 0; y < MAP_Y; y++)
      {
	if (info->share->zone[x][y].team_idx < 0)
	  continue;
	if (!(info->share->zone[x][y].team_idx & 1))
	  set_character(info->gfx, 0, x, y);
	else
	  set_pirate(info->gfx, 0, x, y);
      }
}

int	draw_gfx(t_info *info)
{
  set_backdrop(info);
  put_clients(info);
  SDL_Flip(info->gfx->video);
  SDL_Delay(DELAY);
  return (0);
}
