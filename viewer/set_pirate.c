/*
** set_pirate.c<2> for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Jun  1 19:34:44 2008 caner candan
** Last update Sun Jun  1 20:27:51 2008 caner candan
*/

#include <SDL.h>
#include "lemipc.h"

void		set_pirate(t_gfx *gfx, int nbr, int x, int y)
{
  SDL_Rect	src;
  SDL_Rect	dst;

  src.x = PIRATE_X * GET_POSITION_X(nbr, PIRATE_MAX_PER_LINE);
  src.y = PIRATE_Y * GET_POSITION_Y(nbr, PIRATE_MAX_PER_LINE);
  src.w = PIRATE_X;
  src.h = PIRATE_Y;
  dst.x = (x + 1) * FLOOR_X;
  dst.y = y * FLOOR_Y;
  dst.w = PIRATE_X;
  dst.h = PIRATE_Y;
  SDL_SetColorKey(gfx->pirate, SDL_SRCCOLORKEY,
		  SDL_MapRGB(SDL_SF(gfx->pirate)->format,
			     PIRATE_R, PIRATE_G, PIRATE_B));
  SDL_BlitSurface(gfx->pirate, &src, gfx->video, &dst);
}
