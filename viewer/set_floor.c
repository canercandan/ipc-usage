/*
** set_floor.c<2> for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Jun  1 19:17:50 2008 caner candan
** Last update Sun Jun  1 20:27:26 2008 caner candan
*/

#include <SDL.h>
#include "lemipc.h"

void		set_floor(t_gfx *gfx, int nbr, int x, int y)
{
  SDL_Rect	src;
  SDL_Rect	dst;

  src.x = FLOOR_X * GET_POSITION_X(nbr, FLOOR_MAX_PER_LINE);
  src.y = FLOOR_Y * GET_POSITION_Y(nbr, FLOOR_MAX_PER_LINE);
  src.w = FLOOR_X;
  src.h = FLOOR_Y;
  dst.x = x;
  dst.y = y;
  dst.w = FLOOR_X;
  dst.h = FLOOR_Y;
  SDL_BlitSurface(gfx->floor, &src, gfx->video, &dst);
}
