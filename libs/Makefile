# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 00:31:29 by fsuomins          #+#    #+#              #
#    Updated: 2023/06/04 20:10:34 by fsuomins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEFAULT_GOAL: all

## COLORS DEFINITIONS

red:=$(shell tput setaf 1)
green:=$(shell tput setaf 2)
yellow:=$(shell tput setaf 3)
blue:=$(shell tput setaf 4)
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

NAME = libft.a

PATH_SRC = ./srcs
PATH_INCLUDE =./
GCCFLAGS = -Wall -Wextra -Werror

FILES = ft_isalpha ft_isalnum ft_isascii ft_isdigit ft_isprint ft_strlen ft_memset ft_bzero
SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

FILES		= ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c
OBJS		= $(patsubst %.c, objs/%.o, $(FILES))

# Rules

all			: $(NAME)

$(NAME)		: $(OBJS)
	$(info $(blue)Compiling libft.a$(reset))
	@ar rcs $(NAME) $(OBJS)
	$(info $(green)Done.✔$(reset))
	
objs/%.o	: srcs/%.c
	@mkdir -p objs
	@$(CC) $(CFLAGS) -c $< -o $@

tests 		: all
	@$(MAKE) -C tests --silent
	
clean:
	$(info $(purple)Removing objects.$(reset))
	@rm -rf objs
	$(info $(green)Done.$(reset))
	
fclean: clean
	$(info $(purple)Removing libft.a.$(reset))
	@rm -f $(NAME)
	$(info $(green)Done.$(reset))


re: fclean all

.PHONY: all clean fclean re