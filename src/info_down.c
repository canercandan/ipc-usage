/*
** info_down.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 17:28:59 2008 caner candan
** Last update Thu May 15 17:30:39 2008 caner candan
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "lemipc.h"

void	info_down(t_info *info)
{
  shmdt(info);
}
