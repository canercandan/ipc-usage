/*
** xclose.c for lemipc in /home/candan_c/cu/rendu/project/lemipc/x
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 15:50:31 2008 caner candan
** Last update Thu May 15 15:52:43 2008 caner candan
*/

#include <unistd.h>
#include <stdio.h>
#include "x.h"

int	xclose(int fd)
{
  int	rc;

  if ((rc = close(fd)) < 0)
    perror("close");
  return (rc);
}
