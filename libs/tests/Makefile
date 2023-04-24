# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 01:37:43 by fsuomins          #+#    #+#              #
#    Updated: 2023/04/24 18:46:04 by fsuomins         ###   ########.fr        #
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
	
NAME	= run.a
TEST	= test.a
CC		= cc 
CFLAGS	= -Wextra -Werror -Wall -g3 

# Files
SRCS	= $(wildcard *.c)
# The wildcard function in a Makefile allows you
# to search for files that match a particular pattern. 
# It is used to create lists of files that can be used in compilation rules.
OBJS	= $(SRCS:.c=.o)
SRCS_TEST	= $(wildcard *_test.c)
OBJS_TEST	= $(SRCS_TEST:.c=.o)

# Rules
all		: $(NAME) $(TEST)

$(NAME)	: $(OBJS)
	@mkdir -p objs
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(TEST)	: $(OBJS_TEST) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS_TEST) $(OBJS) -o $(TEST)

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_TEST)

fclean: clean
	rm -f $(NAME) $(TEST)
	rm -rf objs

re: fclean all

.PHONY: all clean fclean re
