# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 00:31:29 by fsuomins          #+#    #+#              #
#    Updated: 2023/04/28 20:48:40 by fsuomins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

## COLORS DEFINITIONS

red:=$(shell tput setaf 1)
green:=$(shell tput setaf 2)
yellow:=$(shell tput setaf 3)
blue:=$(shell tput setaf 4 setab 3)
purple:=$(shell tput setaf 5)
cyan:=$(shell tput setaf 6)
white:=$(shell tput setaf 7)
reset:=$(shell tput sgr0)

color-test:
	$(info $(red)Message$(reset))
	$(info $(green)Message$(reset))
	$(info $(yellow)Message$(reset))
	$(info $(blue)Message$(reset))
	$(info $(purple)Message$(reset))
	$(info $(cyan)Message$(reset))
	$(info $(white)Message$(reset))

# Variables

NAME	= libft.a
CC		= cc 
CFLAGS	= -Wextra -Werror -Wall -g3 

# Paths

INCLUDES	= ./includes/
PATH_SRC	= ./srcs

# Files

#FILES		= ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c
FILES		= ft_isalpha.c ft_isalnum.c ft_isascii.c
OBJS		= $(patsubst %.c, objs/%.o, $(FILES))

# Rules

all		: $(NAME)

$(NAME)	: $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	
objs/%.o	: srcs/%.c
	@mkdir -p objs
	@$(CC) $(CFLAGS) -c $< -o $@

tests : all
	@$(MAKE) -C tests --silent

clean:
	rm -rf objs
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
