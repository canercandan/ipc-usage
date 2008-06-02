/*
** catch_keys.c<2> for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Jun  1 19:36:04 2008 caner candan
** Last update Sun Jun  1 19:36:14 2008 caner candan
*/

#include <SDL.h>
#include "lemipc.h"

int		catch_keys(void)
{
  SDL_Event	event;

  event.type = 0;
  SDL_PollEvent(&event);
  if (event.type == SDL_KEYDOWN)
    if (event.key.keysym.sym == SDLK_ESCAPE)
      return (-1);
  if (event.type == SDL_QUIT)
    return (-1);
  return (0);
}
