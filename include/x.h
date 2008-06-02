/*
** x.h for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May 15 15:51:58 2008 caner candan
** Last update Thu May 15 15:53:23 2008 caner candan
*/

#ifndef __X_H__
# define __X_H__

/*
** Memory's functions
*/
void	*xmalloc(int size);

/*
** Stream's functions
*/
int	xopen(char *path, int flags);
int	xclose(int fd);

#endif /* !__X_H__ */
