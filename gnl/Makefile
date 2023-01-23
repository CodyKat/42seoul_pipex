CC = gcc
NAME = gnl.a
CFLAGS = -Wall -Wextra -Werror
SRCS = get_next_line.c \
	   get_next_line_utils.c

OBJS = ${SRCS:.c=.o}


all : ${NAME}

$(NAME) : ${OBJS}
	ar rs ${NAME} ${OBJS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

.PHONY : all clean fclean bonus re

re : fclean all
