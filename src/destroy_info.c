/*
** destroy_info.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun Jun  1 18:06:36 2008 caner candan
** Last update Sun Jun  1 21:03:48 2008 caner candan
*/

#include <machine/param.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include "lemipc.h"

void	destroy_info(t_info *info)
{
  info->share->nb_connect--;
  info->share->zone[info->x][info->y].team_idx = -1;
  if (info->share->nb_connect <= 0)
    shmctl(info->shm, IPC_RMID, NULL);
  shmdt(info->share);
  exit(-1);
}
