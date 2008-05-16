/*
** create_client.c for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 16:32:13 2008 caner candan
** Last update Thu May 15 16:46:46 2008 caner candan
*/

#include "lemipc.h"
#include "x.h"

t_client	*create_client(t_info *info)
{
  t_client	*client;

  client = xmalloc(sizeof(*client));
  client->x = get_random(info->x, CLIENT(info->clients->data)->x);
  client->y = get_random(info->y, CLIENT(info->clients->data)->y);
  return (client);
}
