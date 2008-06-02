/*
** dump_teams.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 16:11:41 2008 caner candan
** Last update Fri May 30 14:40:34 2008 caner candan
*/

#include <stdio.h>
#include "lemipc.h"

void		dump_teams(int id)
{
  t_info	*info;
  int		i;

  info = info_up(id);
  for (i = 0; i < MAX_TEAM; i++)
    if (info->team[i].name[0])
      {}
  info_down(info);
}
