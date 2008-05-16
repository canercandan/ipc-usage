/*
** main.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed May 14 16:55:48 2008 caner candan
** Last update Thu May 15 17:41:39 2008 caner candan
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
