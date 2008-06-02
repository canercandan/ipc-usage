/*
** init_info.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Jun  1 18:40:17 2008 caner candan
** Last update Sun Jun  1 19:41:00 2008 caner candan
*/

#include <unistd.h>
#include <machine/param.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdio.h>
#include "lemipc.h"

static void	init_map(t_info *info)
{
  int		x;
  int		y;

  for (x = 0; x < MAP_X; x++)
    for (y = 0; y < MAP_Y; y++)
      info->share->zone[x][y].team_idx = -1;
}

static int	check_shm(key_t key, t_info *info)
{
  if ((info->shm = shmget(key, SHM_SIZE, SHM_R | SHM_W)) < 0)
    {
      info->shm = shmget(key, SHM_SIZE, IPC_CREAT | SHM_R | SHM_W);
      info->share = (t_share*)shmat(info->shm, NULL, 0);
      info->share->nb_connect = 0;
      init_map(info);
      shmdt(info->share);
    }
  return (0);
}

static int	check_sem(key_t key, t_info *info)
{
  if ((info->sem = semget(key, 1, IPC_R | IPC_W)) < 0)
    {
      info->sem = semget(key, 1, IPC_CREAT | IPC_R | IPC_W);
      semctl(info->sem, 0, SETVAL, 1);
    }
  return (0);
}

int	init_info(t_info *info)
{
  key_t	key;
  char	path[1024];

  getcwd(path, sizeof(path));
  key = ftok(path, 0);
  info->nb_team = 0;
  if (check_shm(key, info) < 0)
    return (-1);
  if (check_sem(key, info) < 0)
    return (-1);
  info->share = (t_share*)shmat(info->shm, NULL, 0);
  info->share->nb_connect++;
  return (0);
}
