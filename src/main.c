/*
** main.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed May 14 16:55:48 2008 caner candan
** Last update Mon Jun  2 03:03:47 2008 caner candan
*/

#include <machine/param.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>
#include "lemipc.h"

static int	loop(t_info *info)
{
  struct sembuf	sops;

  usleep(TIMEOUT);
  sops.sem_num = 0;
  sops.sem_op = 1;
  sops.sem_flg = IPC_NOWAIT;
  if (semop(info->sem, &sops, 1) < 0)
    return (0);
  goto_ennemy(info);
  if (touched(info))
    destroy_info(info);
  printf("nb_connected: [%d], x[%d], y[%d]\n",
	 info->share->nb_connect, info->x, info->y);
  return (0);
}

static void	dump(t_info *info)
{
  printf("Team idx: [%d]\nTeam name: [%s]\nX: [%d]\nY: [%d]\n",
	 info->team_idx, info->team[info->team_idx].name,
	 info->x, info->y);
}

static int	secure(t_info *info)
{
  if (MAP_X * MAP_Y > info->share->nb_connect)
    return (0);
  printf("too much clients!");
  return (-1);
}

int		main(int ac, char **av)
{
  t_info	info;

  if (ac < 2)
    {
      usage();
      return (-1);
    }
  init_random();
  if (get_infos_from_config(&info) < 0)
    return (-1);
  if (choose_team(av[1], &info) < 0)
    return (-1);
  if (init_info(&info) < 0)
    destroy_info(&info);
  if (secure(&info) < 0)
    destroy_info(&info);
  init_signal(&info);
  dump(&info);
  while (42)
    if (loop(&info) < 0)
      destroy_info(&info);
  return (0);
}
