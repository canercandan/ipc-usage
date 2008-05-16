/*
** ftok.c for ftok in /u/epitech_2010s/candan_c/cu/rendu/test/ipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 10:32:26 2008 caner candan
** Last update Fri May 16 09:13:21 2008 caner candan
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

typedef struct	s_info
{
  int		x;
  int		y;
  char		*test;
}		t_info;

int		main(int ac, char **av)
{
  key_t		key;
  char		path[1024];
  int		shm_id;
  t_info	*info;

  getcwd(path, sizeof(path));
  key = ftok(path, 2);
  printf("key: [%d]\n", key);
  if ((shm_id = shmget(key, 255, SHM_R | SHM_W)) < 0)
    {
      printf("shm not exist\n");
      shm_id = shmget(key, 255, IPC_CREAT | SHM_R | SHM_W);
      info = shmat(shm_id, NULL, 0);
      info->x = 11111;
      info->y = 12222;
      strcpy(info->test, "coucou\n");
      shmdt(info);
    }
  else
    {
      printf("shm removed\n");
      info = shmat(shm_id, NULL, 0);
      printf("x[%d], y[%d], test[%s]\n", info->x, info->y, info->test);
      shmdt(info);
      shmctl(shm_id, IPC_RMID, NULL);
    }
  return (0);
}
