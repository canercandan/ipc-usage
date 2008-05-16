/*
** dump_teams.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 16:11:41 2008 caner candan
** Last update Thu May 15 16:23:34 2008 caner candan
*/

#include <stdio.h>
#include "lemipc.h"

void	dump_teams(t_list *teams)
{
  while (teams)
    {
      printf("Create [%s]\n", (char*)teams->data);
      teams = teams->next;
    }
}
