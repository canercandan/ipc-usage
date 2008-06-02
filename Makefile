##
## Makefile for lemipc in /home/candan_c/cu/rendu/project/lemipc
## 
## Made by caner candan
## Login   <candan_c@epitech.net>
## 
## Started on  Wed May 14 16:50:37 2008 caner candan
## Last update Mon Jun  2 03:02:52 2008 caner candan
##

NAME_APP	=	lemipc
NAME_VW		=	viewer
NAME_SRC	=	src
NAME_X		=	x
NAME_BIN	=	bin

PATH_SRC	=	$(NAME_SRC)/
PATH_VW		=	$(NAME_VW)/
PATH_X		=	$(NAME_X)/
PATH_BIN	=	$(NAME_BIN)/

BIN		=	$(PATH_BIN)$(NAME_APP)
VW		=	$(PATH_BIN)$(NAME_VW)

SRCS		=	$(PATH_SRC)main.c			\
			$(PATH_SRC)init_info.c			\
			$(PATH_SRC)init_signal.c		\
			$(PATH_SRC)put_char_from_buf.c		\
			$(PATH_SRC)put_int_from_buf.c		\
			$(PATH_SRC)get_infos_from_config.c	\
			$(PATH_SRC)init_random.c		\
			$(PATH_SRC)get_random.c			\
			$(PATH_SRC)usage.c			\
			$(PATH_SRC)destroy_info.c		\
			$(PATH_SRC)choose_team.c		\
			$(PATH_SRC)goto_ennemy.c		\
			$(PATH_SRC)touched.c

SRCS_VW		=	$(PATH_VW)main.c			\
			$(PATH_VW)init_info.c			\
			$(PATH_VW)destroy_info.c		\
			$(PATH_VW)init_signal.c			\
			$(PATH_VW)init_gfx.c			\
			$(PATH_VW)load_image.c			\
			$(PATH_VW)destroy_surface.c		\
			$(PATH_VW)destroy_gfx.c			\
			$(PATH_VW)destroy_screen.c		\
			$(PATH_VW)draw_gfx.c			\
			$(PATH_VW)init_screen.c			\
			$(PATH_VW)set_backdrop.c		\
			$(PATH_VW)set_floor.c			\
			$(PATH_VW)set_character.c		\
			$(PATH_VW)set_pirate.c			\
			$(PATH_VW)catch_keys.c

SRCS_X		=	$(PATH_X)xclose.c	\
			$(PATH_X)xmalloc.c	\
			$(PATH_X)xopen.c

OBJS_X		=	$(SRCS_X:.c=.o)
OBJS		=	$(SRCS:.c=.o) $(OBJS_X)
OBJS_VW		=	$(SRCS_VW:.c=.o) $(OBJS_X)

INCLUDES_VW	=	`pkg-config --cflags sdl`
LIBRARY_VW	=	`pkg-config --libs sdl`

INCLUDES	=	-I./include
LIBRARY		=	-L.

DEBUG_42	=	-g

PANIC		=	-Wall -W -Werror -pedantic -ansi

CFLAGS		=	$(INCLUDES) $(DEBUG_$(DEBUG)) $(PANIC)
LDFLAGS		=	$(LIBRARY)

CFLAGS_VW	=	$(INCLUDES_VW)
LDFLAGS_VW	=	$(LIBRARY_VW)

CC		=	gcc
RM		=	rm -f
FIND		=	find . -name
FIND_RM		=	-exec rm {} \;
MK		=	make
MKD		=	mkdir -p

RM_O		=	$(FIND) '*.o' $(FIND_RM)
RM_TILD		=	$(FIND) '*~' $(FIND_RM)
RM_CORE		=	$(FIND) '*.core' $(FIND_RM)

KEY_EQUAL	=	42

.SUFFIXES	:	.c.o

all		:
			@$(MKD) $(PATH_BIN)
			@$(MK) $(BIN)
			@if [ "$(SDL)" = "$(KEY_EQUAL)" ]; then	\
				$(MK) $(VW);			\
			fi

$(BIN)		:	$(OBJS)
			@$(MKD) $(PATH_SRC)
			$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(VW)		:	$(OBJS_VW)
			@$(MKD) $(PATH_VW)
			$(CC) $(CFLAGS_VW) -o $@ $(OBJS_VW) $(LDFLAGS)	\
			$(LDFLAGS_VW)

clean		:
			@$(RM_O)
			@$(RM_TILD)
			@$(RM_CORE)

fclean		:	clean
			$(RM) $(BIN)
			$(RM) $(VW)

re		:	fclean all

.PHONY		:	all clean fclean re

.c.o		:
			@if [ "$(SDL)" = "$(KEY_EQUAL)" ]; then		\
				$(CC) $(CFLAGS) $(CFLAGS_VW)		\
				-c $< -o $@;				\
				echo $(CC) $(CFLAGS) $(CFLAGS_VW)	\
					-c $< -o $@;			\
			else						\
				$(CC) $(CFLAGS) -c $< -o $@;		\
				echo $(CC) $(CFLAGS) -c $< -o $@;	\
			fi
