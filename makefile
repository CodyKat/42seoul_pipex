CC = cc
NAME = pipex
CFLAGS =# -Wall -Wextra -Werror
SRCS = 	main.c	\
		processing.c	\
		util_1.c		\
		util_2.c		\
		util_3.c
OBJS = ${SRCS:.c=.o}

all : ${NAME}

$(NAME) : ${OBJS}
	${CC} -o ${NAME} ${CFLAGS} ${OBJS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

.PHONY : all clean fclean bonus re

re : fclean all
