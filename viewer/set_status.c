/*
** set_status.c<2> for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Jun  1 19:35:25 2008 caner candan
** Last update Sun Jun  1 20:28:01 2008 caner candan
*/

#include <SDL.h>
#include "lemipc.h"

void		set_status(t_gfx *gfx, int nbr, int x, int y)
{
  SDL_Rect	src;
  SDL_Rect	dst;

  src.x = STATUS_X * GET_POSITION_X(nbr, STATUS_MAX_PER_LINE);
  src.y = STATUS_Y * GET_POSITION_Y(nbr, STATUS_MAX_PER_LINE);
  src.w = STATUS_X;
  src.h = STATUS_Y;
  dst.x = (x * FLOOR_X) - 5;
  dst.y = (y * FLOOR_Y) - 10;
  dst.w = STATUS_X;
  dst.h = STATUS_Y;
  SDL_SetColorKey(gfx->status, SDL_SRCCOLORKEY,
		  SDL_MapRGB(SDL_SF(gfx->status)->format,
			     STATUS_R, STATUS_G, STATUS_B));
  SDL_BlitSurface(gfx->status, &src, gfx->video, &dst);
}
