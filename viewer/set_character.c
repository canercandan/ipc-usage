/*
** set_character.c<2> for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Jun  1 19:32:40 2008 caner candan
** Last update Sun Jun  1 20:27:40 2008 caner candan
*/

#include <SDL.h>
#include "lemipc.h"

void		set_character(t_gfx *gfx, int nbr, int x, int y)
{
  SDL_Rect	src;
  SDL_Rect	dst;

  src.x = CHARACTER_X * GET_POSITION_X(nbr, CHARACTER_MAX_PER_LINE);
  src.y = CHARACTER_Y * GET_POSITION_Y(nbr, CHARACTER_MAX_PER_LINE);
  src.w = CHARACTER_X;
  src.h = CHARACTER_Y;
  dst.x = (x + 1) * FLOOR_X;
  dst.y = y * FLOOR_Y;
  dst.w = CHARACTER_X;
  dst.h = CHARACTER_Y;
  SDL_SetColorKey(gfx->character, SDL_SRCCOLORKEY,
		  SDL_MapRGB(SDL_SF(gfx->character)->format,
			     CHARACTER_R, CHARACTER_G, CHARACTER_B));
  SDL_BlitSurface(gfx->character, &src, gfx->video, &dst);
}
