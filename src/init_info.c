/*
** init_info.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 14:10:40 2008 caner candan
** Last update Fri May 30 14:30:41 2008 caner candan
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include "lemipc.h"

static int	put_info(int id)
{
  t_info	*info;
  int		x;
  int		y;

  info = info_up(id);
  for (x = 0; x < MAP_X; x++)
    for (y = 0; y < MAP_Y; y++)
      info->zone[x][y].team_idx = -1;
  for (x = 0; x < MAX_TEAM; x++)
    info->team[x].name[0] = 0;
  printf("OK\n");
  if (get_infos_from_config(info) < 0)
    return (-1);
  info_down(info);
  return (0);
}

int		init_info(void)
{
  key_t		key;
  char		path[1024];
  int		id;

  getcwd(path, sizeof(path));
  key = ftok(path, 0);
  printf("key[%d]\n", (int)key);
  if ((id = shmget(key, SHM_SIZE, SHM_R | SHM_W)) < 0)
    {
      id = shmget(key, SHM_SIZE, IPC_CREAT | SHM_R | SHM_W);
      if (put_info(id))
	return (-1);
    }
  else
    shmctl(id, IPC_RMID, NULL);
  return (id);
}
