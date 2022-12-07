NAME	= philo
CC		= gcc -fsanitize=thread
CFLAGS	= -Wall -Werror -Wextra -fsanitize=thread
RM		= rm -f

SRCS	=	$(wildcard *.c)

OBJS	=	$(patsubst %.c, %.o, $(SRCS))

%.o: %.c
			$(CC) $(CFLAGS) -c  $< -o $@

all:		lib $(NAME)

lib:
	cd libft && make

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) libft/*.o

clean:
			$(RM) $(OBJS) libft/*.o

fclean:		clean
			$(RM) $(NAME) libft/libft.a

re:			fclean all

.PHONY:		all clean fclean re lib
