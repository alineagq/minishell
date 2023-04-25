# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 01:37:43 by fsuomins          #+#    #+#              #
#    Updated: 2023/04/24 21:38:08 by fsuomins         ###   ########.fr        #
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

# Rules
all		: $(NAME)

$(NAME)	: $(OBJS)
	@$(CC) $(CFLAGS) -I../ -L../ -lft t_isalnum.c -o isalnum.test 

clean:
	rm -f $(OBJS) $(OBJS_TEST)

fclean: clean
	rm -f $(NAME) $(TEST)
	rm -rf objs

re: fclean all

.PHONY: all clean fclean re
