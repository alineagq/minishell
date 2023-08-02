# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 22:30:34 by aqueiroz          #+#    #+#              #
#    Updated: 2023/07/21 23:00:29 by aqueiroz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

## COLORS DEFINITIONS

red:=$(shell tput setaf 1)
green:=$(shell tput setaf 2)
yellow:=$(shell tput setaf 3)
blue:=$(shell tput setaf 4)
purple:=$(shell tput setaf 5)
cyan:=$(shell tput setaf 6)
white:=$(shell tput setaf 7)
reset:=$(shell tput sgr0)

color:
	@make -s _color-test

_color-test:
	$(info $(red)Message$(reset))
	$(info $(green)Message$(reset))
	$(info $(yellow)Message$(reset))
	$(info $(blue)Message$(reset))
	$(info $(purple)Message$(reset))
	$(info $(cyan)Message$(reset))
	$(info $(white)Message$(reset))

# PATHS

# FILES

NAME = test
		
SRCS = $(wildcard */*.c)
OBJS := ${SRCS:.c=.o}

# FLAGS

CC = cc
CFLAGS = -Wall -Wextra -Werror

# TARGETS

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -I files $(OBJS) -L ../ -lft -o $@
	@./test

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

valgrind: re
	@valgrind --track-origins=yes --error-exitcode=42 --leak-check=full --show-leak-kinds=all --quiet ./$(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test