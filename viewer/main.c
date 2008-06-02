/*
** main.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 13:54:51 2008 caner candan
** Last update Sun Jun  1 20:33:32 2008 caner candan
*/

#include <machine/param.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include "lemipc.h"

static int	loop(t_info *info)
{
  struct sembuf	sops;

  if (catch_keys() < 0)
    return (-1);
  sops.sem_num = 0;
  sops.sem_op = 1;
  sops.sem_flg = IPC_NOWAIT;
  if (semop(info->sem, &sops, 1) < 0)
    return (0);
  printf("nb_connected: [%d]\n", info->share->nb_connect);
  draw_gfx(info);
  return (0);
}

int		main(void)
{
  t_info	info;
  t_gfx		gfx;

  if (init_info(&info) < 0)
    destroy_info(&info);
  info.gfx = &gfx;
  init_gfx(&gfx);
  init_signal(&info);
  while (42)
    if (loop(&info) < 0)
      destroy_info(&info);
  return (0);
}
