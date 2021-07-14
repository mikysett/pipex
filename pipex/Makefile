# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 11:32:44 by msessa            #+#    #+#              #
#    Updated: 2021/07/13 22:38:51 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS	+=	--quiet

WHT	= \033[0;37m
BLK	= \033[0;30m
RED	= \033[0;31m
YEL	= \033[0;33m
BLU	= \033[0;34m
GRN	= \033[0;32m

NAME	=	pipex

LIBFT	=	libft/libft

HEADERS	=	headers

DIR_S	=	srcs

DIR_O	=	obj

# Using wildcards: $(shell find $(DIR_S) -name *.c)
BASIC_SRCS	:=	srcs/ft_init_pipex.c \
				srcs/ft_pipex_util.c \
				srcs/ft_run_cmd.c \
				srcs/ft_run_pipex.c \
				srcs/main.c

SRCS		:= $(BASIC_SRCS) \
				srcs/no_bonus/ft_init_pipex_util.c
		

BONUS_SRCS	:= $(BASIC_SRCS) \
				srcs/bonus/ft_init_pipex_util.c

OBJS		:= $(SRCS:%.c=$(DIR_O)/%.o)

BONUS_OBJS	:= $(BONUS_SRCS:%.c=$(DIR_O)/%.o)

SUB_DIR_O := $(shell find $(DIR_S) -type d)
SUB_DIR_O := $(SUB_DIR_O:%=$(DIR_O)/%)

# Using wildcards: $(shell find $(HEADERS) -name *.h)
DEPS	=	$(shell find $(HEADERS) -name *.h)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -fsanitize=address
INCLUDES	= -I $(HEADERS) -I $(LIBFT)

LIBS	=	-L./$(LIBFT) -lft

RM		=	rm -f

$(DIR_O)/%.o: %.c
			@mkdir -p $(DIR_O)
			@mkdir -p $(SUB_DIR_O)
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME):	$(DEPS) $(OBJS)
			@make $(FAST)bonus -C $(LIBFT)
			$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS)
			printf "$(WHT)[$(GRN)$(NAME) COMPILED$(WHT)]\n"

all:		$(NAME)

# bonus:		OBJS = $(BONUS_OBJS)
# bonus:		all
# 			printf "$(WHT)[$(GRN)$(NAME) BONUS COMPILED$(WHT)]\n"

bonus:		$(DEPS) $(BONUS_OBJS)
			@make $(FAST)bonus -C $(LIBFT)
			$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(BONUS_OBJS) $(LIBS)
			printf "$(WHT)[$(GRN)$(NAME) BONUS COMPILED$(WHT)]\n"

miniclean:
			$(RM) $(OBJS)
			$(RM) $(BOBJS)
			printf "$(WHT)[$(YEL)$(NAME) OBJS REMOVED$(WHT)]\n"

clean:		miniclean
			@make clean -C $(LIBFT)

fclean:		miniclean
			$(RM) $(NAME)
			@make fclean -C $(LIBFT)
			printf "$(WHT)[$(YEL)$(NAME) BINARIES REMOVED$(WHT)]\n"

re:			fclean all

.PHONY:		all bonus miniclean clean fclean re
