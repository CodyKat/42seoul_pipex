CC = gcc
NAME = pipex
NAME_LIBFT = libft/libft.a
NAME_GNL = gnl/gnl.a
CFLAGS = -Wall -Wextra -Werror -g
SRCS = main.c \
	   utils.c

OBJS = ${SRCS:.c=.o}

all : ${NAME}

$(NAME) : ${OBJS} $(NAME_LIBFT) $(NAME_GNL)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(NAME_LIBFT) $(NAME_GNL)

$(NAME_LIBFT) :
	make -C libft all

$(NAME_GNL) :
	make -C gnl all

clean :
	rm -f ${OBJS}
	make -C libft clean
	make -C gnl clean

fclean : clean
	rm -f ${NAME}
	make -C libft fclean
	make -C gnl fclean

.PHONY : all clean fclean bonus re

re : fclean all
