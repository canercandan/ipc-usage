/*
** info_up.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 17:26:49 2008 caner candan
** Last update Thu May 15 19:28:54 2008 caner candan
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "lemipc.h"

t_info		*info_up(int id)
{
  t_info	*info;

  info = shmat(id, NULL, 0);
  return (info);
}
