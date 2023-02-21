.PHONY: all clean fclean re libft

NAME 		= libftprintf.a

SRCS 		= ft_printf.c ft_printf_nb.c ft_printf_str.c
OBJS 		= ${SRCS:.c=.o}

CC 			= gcc
FLAGS 		= -Wall -Wextra -Werror

HEADER 		= ft_printf.h

LIB 		= ar rcs

RM 			= rm -f

all:    	libft ${NAME}

%.o: 		%.c ${HEADER}  
			${CC} ${FLAGS} -include${HEADER} -c $< -o $@

$(NAME):    $(OBJS) 
			cp libft/libft.a ./libftprintf.a
			${LIB} ${NAME} ${OBJS}

clean:
			${RM} ${OBJS} libft/*.o libft/libft.a

fclean:     clean
			${RM} ${NAME} libft/*.o libft/libft.a

re:        fclean all

libft:
			make -C libft