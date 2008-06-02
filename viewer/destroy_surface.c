/*
** destroy_surface.c<2> for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Jun  1 19:02:48 2008 caner candan
** Last update Sun Jun  1 19:02:55 2008 caner candan
*/

#include <SDL.h>
#include "lemipc.h"

void	destroy_surface(void *surface)
{
  SDL_FreeSurface(surface);
}
