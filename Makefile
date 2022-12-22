NAME	= philo
CC		= gcc #-fsanitize=thread
CFLAGS	= -Wall -Werror -Wextra -fsanitize=address -g
RM		= rm -f

SRCS	=	$(wildcard *.c)

OBJS	=	$(patsubst %.c, %.o, $(SRCS))

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS) 

fclean:		clean
			$(RM) $(NAME) 

re:			fclean all

.PHONY:		all clean fclean re 
