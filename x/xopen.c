/*
** xopen.c for lemipc in /home/candan_c/cu/rendu/project/lemipc/x
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 15:51:13 2008 caner candan
** Last update Thu May 15 15:51:30 2008 caner candan
*/

#include <fcntl.h>
#include <stdio.h>
#include "x.h"

int	xopen(char *path, int flags)
{
  int	fd;

  if ((fd = open(path, flags)) < 0)
    perror("open");
  return (fd);
}
