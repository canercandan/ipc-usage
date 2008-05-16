/*
** init_info.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 14:10:40 2008 caner candan
** Last update Thu May 15 19:50:00 2008 caner candan
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include "lemipc.h"

int		init_info(void)
{
  void		*info;
  key_t		key;
  char		path[1024];
  int		id;

  getcwd(path, sizeof(path));
  key = ftok(path, 0);
  printf("key[%d]\n", (int)key);
  if ((id = shmget(key, SHM_SIZE, SHM_R | SHM_W)) < 0)
    {
      id = shmget(key, SHM_SIZE, IPC_CREAT | SHM_R | SHM_W);
/*       info = info_up(id); */
      info = shmat(id, NULL, 0);
      strcpy((char*)info, "CouCou\n");
/*       INFO(info)->x = 0; */
/*       INFO(info)->y = 0; */
/*       INFO(info)->teams = NULL; */
/*       INFO(info)->clients = NULL; */
      printf("OK\n");
      if (get_infos_from_config(info) < 0)
	return (-1);
      info_down(info);
    }
  else
    {
      shmctl(id, IPC_RMID, NULL);
    }
  return (id);
}
