NAME	= philo
CC		= gcc -fsanitize=thread
CFLAGS	= -Wall -Werror -Wextra -fsanitize=thread
RM		= rm -f

SRCS	=	$(wildcard *.c)

OBJS	=	$(patsubst %.c, %.o, $(SRCS))

%.o: %.c
			$(CC) $(CFLAGS) -c  $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS) 

fclean:		clean
			$(RM) $(NAME) 

re:			fclean all

.PHONY:		all clean fclean re 
