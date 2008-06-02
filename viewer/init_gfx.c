/*
** init_gfx.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Jun  1 18:53:52 2008 caner candan
** Last update Sun Jun  1 20:37:43 2008 caner candan
*/

#include <SDL.h>
#include <stdio.h>
#include "lemipc.h"

int	create_video(t_gfx *gfx)
{
  gfx->infos = (void*)SDL_GetVideoInfo();
  if (!(gfx->video =
	SDL_SetVideoMode((MAP_X + 2) * FLOOR_X,
			 (MAP_Y + 2) * FLOOR_Y,
			 SDL_VI(gfx->infos)->vfmt->BitsPerPixel,
			 SDL_VI(gfx->infos)->video_mem)))
    {
      perror("SDL_SetVideoMode");
      return (-1);
    }
  SDL_WM_SetCaption(TITLE, NULL);
  return (0);
}

int	init_gfx(t_gfx *gfx)
{
  if (init_screen() < 0 ||
      !(gfx->character = load_image(CHARACTER_FILE)) ||
      !(gfx->status = load_image(STATUS_FILE)) ||
      !(gfx->floor = load_image(FLOOR_FILE)) ||
      !(gfx->pirate = load_image(PIRATE_FILE)))
    return (-1);
  create_video(gfx);
  return (0);
}
