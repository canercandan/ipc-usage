/*
** init_signal.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Jun  1 18:44:32 2008 caner candan
** Last update Sun Jun  1 20:38:56 2008 caner candan
*/

#include <signal.h>
#include <stdio.h>
#include "lemipc.h"

static t_info	*info = NULL;

static void	power_off(int signal)
{
  (void)signal;
  printf("\nit's off!\n");
  destroy_gfx(info->gfx);
  destroy_info(info);
}

void	init_signal(t_info *i)
{
  info = i;
  signal(SIGINT, power_off);
}
