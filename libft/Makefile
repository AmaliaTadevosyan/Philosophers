SRCS = $(shell find "." -name "*.c" ! -name "ft_lst*.c")
 	 
OBJS = $(SRCS:.c=.o)

BONUS = $(shell find "." -name "ft_lst*.c")

BONUS_OBJS = $(BONUS:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I.

NAME = libft.a

all: $(NAME)

$(NAME):
	$(CC) -c $(SRCS)
	ar rc ${NAME} $(OBJS)
	ranlib ${NAME}

bonus: $(BONUS_OBJS)
	ar rc ${NAME} $(BONUS_OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus .c.o