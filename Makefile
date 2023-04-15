NAME = minishell
SRCS =  
		
INCLUDE = 
OBJS = 
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS) 

$(OBJS) : $(SRCS) libft.h
	@cc $(CFLAGS) -c $(SRCS) -I $(INCLUDE) 

clean : 
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all