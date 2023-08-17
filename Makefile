# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 09:18:52 by aqueiroz          #+#    #+#              #
#    Updated: 2023/08/17 15:47:35 by fsuomins         ###   ########.fr        #
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
	@$(MAKE) -s _color-test

_color-test:
	$(info $(red)Message$(reset))
	$(info $(green)Message$(reset))
	$(info $(yellow)Message$(reset))
	$(info $(blue)Message$(reset))
	$(info $(purple)Message$(reset))
	$(info $(cyan)Message$(reset))
	$(info $(white)Message$(reset))

# MANDATORY FILES

NAME = minishell

SRC_PATH = srcs
LIB_PATH = libs
OBJ_PATH = objs
PATH_INC = includes

FILES  = minishell
FILES += init/signals init/init
FILES += prompt/prompt
FILES += parse/parse parse/spaces parse/split_string parse/tokens \
		 parse/utils
FILES += execute/execute
FILES += exit/exit
FILES += utils/utils utils/envs utils/exit utils/prints

SRCS = $(addprefix $(SRC_PATH)/, $(addsuffix .c, $(FILES)))
OBJS = $(SRCS:.c=.o)

# FLAGS

CC = cc
#CFLAGS = -Wall -Wextra -Werror
LIBFLAGS = -L./$(LIB_PATH) -lft -lreadline 

all: $(NAME)

LIBFT:
	@$(MAKE) -s -k -C $(LIB_PATH)

$(NAME): LIBFT $(OBJS)
	@$(CC) $(OBJS) $(INCLUDE) $(LIBFLAGS) -o $@
	$(info $(purple)Project compiled. Run './$(NAME)' to start.$(reset))

valgrind:
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes \
	--suppressions=readline.supp --leak-check=full \
	--show-leak-kinds=all --quiet ./minishell
clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIB_PATH) --silent clean
	$(info $(yellow)All object files were removed.$(reset))

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIB_PATH) --silent fclean
	$(info $(yellow)Executables files were removed.$(reset))

re: fclean all
	
.PHONY: all color clean fclean re valgrind