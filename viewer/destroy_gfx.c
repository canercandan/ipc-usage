/*
** destroy_gfx.c<2> for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Jun  1 19:02:14 2008 caner candan
** Last update Sun Jun  1 19:02:22 2008 caner candan
*/

#include "lemipc.h"

void	destroy_gfx(t_gfx *gfx)
{
  destroy_surface(gfx->floor);
  destroy_surface(gfx->status);
  destroy_surface(gfx->character);
  destroy_surface(gfx->video);
  destroy_screen();
}
