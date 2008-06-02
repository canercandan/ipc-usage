/*
** lemipc.h for lemipc in /home/candan_c/cu/rendu/project/lemipc
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed May 14 16:56:27 2008 caner candan
** Last update Mon Jun  2 03:03:06 2008 caner candan
*/

#ifndef __LEMIPC_H__
# define __LEMIPC_H__

/*
** Config's define
*/
# define FILE_CFG	"bin/lemipc.cfg"
# define DELIMIT_CFG	" \t=\n"
# define PARAM_X	"X"
# define PARAM_Y	"Y"
# define PARAM_TEAM	"TEAM"
# define COMMENT	';'

/*
** Map's info
*/
# define MAP_X	10
# define MAP_Y	10
# define TIMEOUT	500000

/*
** Team's infos
*/
# define MAX_TEAM	5

/*
** SHM's informations
*/
# define SHM_SIZE	255

/*
** SDL's defines
*/
# define SCREEN_X	640
# define SCREEN_Y	480
# define DELAY		50
# define DELAY_ANIM	20
# define UNIT_X		5.0
# define UNIT_Y		5.0
# define TITLE		"LeMiPc"

/*
** Character's infos
*/
# define CHARACTER_FILE		"images/bibi.bmp"
# define CHARACTER_MAX_PER_LINE	4
# define CHARACTER_X		32
# define CHARACTER_Y		48
# define CHARACTER_R		255
# define CHARACTER_G		255
# define CHARACTER_B		255

/*
** Status' infos
*/
# define STATUS_FILE		"images/status.bmp"
# define STATUS_MAX_PER_LINE	5
# define STATUS_X		17
# define STATUS_Y		17
# define STATUS_R		192
# define STATUS_G		192
# define STATUS_B		192

/*
** Floor's infos
*/
# define FLOOR_FILE		"images/floor.bmp"
# define FLOOR_MAX_PER_LINE	4
# define FLOOR_X		32
# define FLOOR_Y		32

/*
** Pirate's infos
*/
# define PIRATE_FILE		"images/pirate.bmp"
# define PIRATE_MAX_PER_LINE	4
# define PIRATE_X		40
# define PIRATE_Y		56
# define PIRATE_R		102
# define PIRATE_G		78
# define PIRATE_B		79

/*
** Null's define
*/
# ifndef NULL
#  define NULL	((void*)0)
# endif /* !NULL */

/*
** SDL's macros
*/
# define SDL_SF(data)	((SDL_Surface *) (data))
# define SDL_VI(data)	((SDL_VideoInfo *) (data))

/*
** Position's macros
*/
# define GET_POSITION_X(nbr, max)	((nbr) % (max))
# define GET_POSITION_Y(nbr, max)	((nbr) / (max))

/*
** Struct
*/
typedef struct	s_team
{
  char		name[30];
}		t_team;

typedef struct	s_zone
{
  int		team_idx;
}		t_zone;

typedef struct	s_share
{
  int		nb_connect;
  t_zone	zone[MAP_X][MAP_Y];
}		t_share;

/*
** GFX's structure
*/
typedef struct	s_gfx
{
  void		*video;
  void		*infos;
  void		*character;
  void		*status;
  void		*floor;
  void		*pirate;
}		t_gfx;

typedef struct	s_info
{
  int		shm;
  int		sem;
  t_share	*share;
  t_team	team[MAX_TEAM];
  int		nb_team;
  int		team_idx;
  int		x;
  int		y;
  t_gfx		*gfx;
}		t_info;

/*
** Infos's functions
*/
int	init_info(t_info *info);
void	init_signal(t_info *i);
void	destroy_info(t_info *info);
int	choose_team(char *team, t_info *info);
int	goto_ennemy(t_info *info);
int	touched(t_info *info);

/*
** Parsing's functions
*/
void	put_char_from_buf(char **elm, char **buf, char *delimit, int pos);
void	put_int_from_buf(int *elm, char **buf, char *delimit, int pos);
int	get_infos_from_config(t_info *info);

/*
** Random's functions
*/
void	init_random(void);
int	get_random(int max, int diff);

/*
** Useful's functions
*/
void	usage(void);

/*
** GFX's functions
*/
int	init_gfx(t_gfx *gfx);
void	destroy_gfx(t_gfx *gfx);
int	init_screen(void);
void	*load_image(char *path);
int	loop_env(t_info *info);
void	destroy_surface(void *surface);
void	destroy_screen(void);
int	catch_keys(void);
void	set_backdrop(t_info *info);
void	set_character(t_gfx *gfx, int nbr, int x, int y);
void	set_status(t_gfx *gfx, int nbr, int x, int y);
void	set_floor(t_gfx *gfx, int nbr, int x, int y);
void	set_pirate(t_gfx *gfx, int nbr, int x, int y);
int	draw_gfx(t_info *info);

#endif /* !__LEMIPC_H__ */
