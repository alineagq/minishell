# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 09:18:52 by aqueiroz          #+#    #+#              #
#    Updated: 2023/08/20 00:26:49 by fsuomins         ###   ########.fr        #
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

FILES  = 	minishell
			
FILES += 	init/init \
			init/srcs/signals \
			init/srcs/create_env 
			
FILES += 	utils/data \
			utils/free \
			utils/envs \
			utils/vars \
			utils/spaces \
			utils/tokens \
			utils/types \
			utils/cd \
			utils/cd2 \
			utils/heredoc \
			utils/redirect \
			utils/tok
			
FILES += 	prompt/prompt
			
FILES += 	parse/parse \
			parse/srcs/expand_exit \
			parse/srcs/expand_var \
			parse/srcs/quotes \
			parse/srcs/spaces \
			parse/srcs/split_string \
			parse/srcs/tokens
			
FILES += 	execute/srcs/args \
			execute/srcs/clear_exec \
			execute/srcs/com \
			execute/srcs/command \
			execute/srcs/env \
			execute/srcs/get_info \
			execute/srcs/input \
			execute/srcs/multi_cmd \
			execute/srcs/one_cmd \
			execute/srcs/output \
			execute/execute \
			execute/srcs/redirects/heredoc \
			execute/srcs/redirects/redirects \
			execute/srcs/redirects/expansions \
			execute/srcs/env/envs \
			execute/srcs/builtin/cd \
			execute/srcs/builtin/echo \
			execute/srcs/builtin/env \
			execute/srcs/builtin/exit \
			execute/srcs/builtin/export \
			execute/srcs/builtin/pwd \
			execute/srcs/builtin/unset
			
			
FILES += exit/exit

SRCS = $(addprefix $(SRC_PATH)/, $(addsuffix .c, $(FILES)))
OBJS = $(SRCS:.c=.o)

# FLAGS

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
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