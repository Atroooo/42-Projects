SRCS	= error.c ft_atoi.c ft_file.c ft_find_nb.c ft_print.c ft_split.c main.c ft_corr_dictio.c print_nb.c

OBJS 	= ${SRCS:.c=.o}

NAME	= rush-02

HEADER	= ft.h

CC		= cc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror -g

.c.o:	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:	${NAME} ${LIB}

clean:
		${RM} ${NAME}
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

		all clean fclean re
