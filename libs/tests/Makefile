# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 01:37:43 by fsuomins          #+#    #+#              #
#    Updated: 2023/06/12 15:32:18 by fsuomins         ###   ########.fr        #
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

color-test:
	$(info $(red)Message$(reset))
	$(info $(green)Message$(reset))
	$(info $(yellow)Message$(reset))
	$(info $(blue)Message$(reset))
	$(info $(purple)Message$(reset))
	$(info $(cyan)Message$(reset))
	$(info $(white)Message$(reset))
	
NAME		= 	run.a
TEST		= 	test.a
CC			= 	cc 
CFLAGS		= 	-Wextra -Werror -Wall -I../ -I. -g3
LIBFTFLAG 	= 	../libft.a
SRCS_T		= 	t_isalnum t_isalpha t_isascii t_isdigit t_isprint t_bzero t_memcpy \
				t_strlcpy t_strchr t_calloc
#t_memset
EXEC = $(addprefix ./outs/, $(SRCS_T))

# Rules
all: libft $(SRCS_T) $(EXEC)
	
$(EXEC):
	$@

libft:
	@cd ../ && $(MAKE)

$(SRCS_T):
	@$(CC) $(CFLAGS) $(addsuffix .c, $@) $(LIBFTFLAG) -o ./outs/$@

clean:
	rm -f $(OBJS) $(OBJS_TEST)
	@cd ../ && $(MAKE) $@

fclean: clean
	rm -f $(NAME) $(TEST)
	rm -rf objs
	@cd ../ && $(MAKE) $@

re: fclean all

.PHONY: all clean fclean re $(EXEC)
