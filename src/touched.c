/*
** touched.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon Jun  2 03:01:09 2008 caner candan
** Last update Mon Jun  2 07:40:15 2008 caner candan
*/

#include "lemipc.h"

static int	around[MAX_TEAM];

static void	one(t_info *info)
{
  int	team;

  team = info->share->zone[info->x][info->y + 1].team_idx;
  if (team >= 0 && team != info->team_idx)
    around[team]++;
  team = info->share->zone[info->x + 1][info->y + 1].team_idx;
  if (team >= 0 && team != info->team_idx)
    around[team]++;
  team = info->share->zone[info->x + 1][info->y].team_idx;
  if (team >= 0 && team != info->team_idx)
    around[team]++;
  team = info->share->zone[info->x + 1][info->y - 1].team_idx;
  if (team >= 0 && team != info->team_idx)
    around[team]++;
}

static void	two(t_info *info)
{
  int	team;

  team = info->share->zone[info->x][info->y - 1].team_idx;
  if (team >= 0 && team != info->team_idx)
    around[team]++;
  team = info->share->zone[info->x - 1][info->y - 1].team_idx;
  if (team >= 0 && team != info->team_idx)
    around[team]++;
  team = info->share->zone[info->x - 1][info->y].team_idx;
  if (team >= 0 && team != info->team_idx)
    around[team]++;
  team = info->share->zone[info->x - 1][info->y + 1].team_idx;
  if (team >= 0 && team != info->team_idx)
    around[team]++;
}

int	touched(t_info *info)
{
  int	i;

  for (i = 0; i < MAX_TEAM; i++)
    around[i] = 0;
  one(info);
  two(info);
  for (i = 0; i < MAX_TEAM; i++)
    if (around[i] >= 2 && i != info->team_idx)
      return (1);
  return (0);
}
