/*
** dump_infos.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 16:24:19 2008 caner candan
** Last update Fri May 30 14:18:11 2008 caner candan
*/

#include <stdio.h>
#include "lemipc.h"

void		dump_infos(int id)
{
  t_info	*info;

  info = info_up(id);
/*   printf("x[%d], y[%d]\n", info->x, info->y); */
  dump_teams(id);
  info_down(info);
}
