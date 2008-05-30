/*
** get_infos_from_config.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 12:31:25 2008 caner candan
** Last update Fri May 30 14:16:39 2008 caner candan
*/

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "lemipc.h"

static void	get_infos(t_info *info, char **buf, char *first)
{
  char		*team_name;
  int		i;

  i = 0;
  if (first[0] != COMMENT)
    {
      if (!strncmp(PARAM_X, first, strlen(PARAM_X)) && !info->x)
	put_int_from_buf(&(info->x), buf, DELIMIT_CFG, 0);
      else if (!strncmp(PARAM_Y, first, strlen(PARAM_Y)) && !info->y)
	put_int_from_buf(&(info->y), buf, DELIMIT_CFG, 0);
      else if (!strncmp(PARAM_TEAM, first, strlen(PARAM_TEAM)))
	{
	  put_char_from_buf(&team_name, buf, DELIMIT_CFG, 0);
	  strcpy(info->team[i++].name, team_name);
	  free(team_name);
	}
    }
}

int	get_infos_from_config(t_info *info)
{
  char	buf[1024];
  int	fd;
  int	nbr;
  char	*tmp;
  char	*first;

  if ((fd = open(FILE_CFG, O_RDONLY)) < 0)
    return (-1);
  while ((nbr = read(fd, buf, sizeof(buf))) > 0)
    {
      buf[nbr] = 0;
      tmp = buf;
      while ((first = strsep(&tmp, DELIMIT_CFG)))
	get_infos(info, &tmp, first);
    }
  if (!info->x || !info->y)
    return (-1);
  return (0);
}
