/*
** load_image.c<2> for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Jun  1 18:57:30 2008 caner candan
** Last update Sun Jun  1 18:57:51 2008 caner candan
*/

#include <SDL.h>
#include <stdio.h>
#include "lemipc.h"

void	*load_image(char *path)
{
  void	*image;

  if (!(image = (void*)SDL_LoadBMP(path)))
    {
      perror("SDL_LoadBMP");
      return (NULL);
    }
  return (image);
}
