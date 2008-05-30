/*
** main.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
4** 
** Started on  Wed May 14 16:55:48 2008 caner candan
** Last update Fri May 30 13:59:03 2008 caner candan
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "lemipc.h"

int	main(void)
{
  int	id;

  if ((id = init_info()) < 0)
    return (-1);
  dump_infos(id);
  return (0);
}
