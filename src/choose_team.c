/*
** choose_team.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Jun  1 18:15:04 2008 caner candan
** Last update Sun Jun  1 18:22:04 2008 caner candan
*/

#include <strings.h>
#include <stdio.h>
#include "lemipc.h"

int	choose_team(char *team, t_info *info)
{
  int	i;

  for (i = 0; i < info->nb_team; i++)
    if (!strcasecmp(team, info->team[i].name))
      {
	info->team_idx = i;
	return (0);
      }
  printf("Team not found!\n");
  return (-1);
}
