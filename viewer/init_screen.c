/*
** init_screen.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Jun  1 19:30:11 2008 caner candan
** Last update Sun Jun  1 19:30:18 2008 caner candan
*/

#include <SDL.h>
#include <stdio.h>
#include "lemipc.h"

int	init_screen(void)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      perror("SDL_Init");
      return (-1);
    }
  return (0);
}
