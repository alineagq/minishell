# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 00:31:29 by fsuomins          #+#    #+#              #
#    Updated: 2023/04/24 16:07:37 by fsuomins         ###   ########.fr        #
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

INCLUDES	= ./includes/libft.h
PATH_SRC	= ./srcs

# Files

# FILES		= ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c // i think we don't need that. 
OBJS		= $(patsubst %.c, objs/%.o, $(PATH_SRCS))
# The patsubst command is a pattern substitution function in Makefile. 
# It is used to transform a list of words into another list, replacing
# specified patterns in each word by the user.
# WE CAN USE wildcard WITH THIS SIMILAR OBJECTIVE.

# Rules

all		: $(NAME)

$(NAME)	: $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	
$(OBJS)	:
	@mkdir -p objs
	@cc $(CFLAGS) -c ./srcs/$(FILES) -I $(INCLUDES) -g3 

tests : all
	@$(MAKE) -C tests --silent

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
