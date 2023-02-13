.PHONY: all clean fclean re ft_printf sanitize

NAME 		= push_swap

SRCS 		= push_swap.c  push_swap_errors.c push_swap_setup.c push_swap_utils.c push_swap_atoi.c \
				push_swap_fdsort.c push_swap_sort.c push_swap_fsort.c push_swap_to_binary.c \
				push_swap_hardsort.c push_swap_hardsort_utils.c push_swap_max.c
				 
OBJS 		= ${SRCS:.c=.o}

CC 			= gcc
FLAGS 		= -Wall -Wextra -Werror

HEADER 		= push_swap.h

RM 			= rm -f

all:    	${NAME}

%.o: 		%.c ${HEADER}  
			${CC} ${FLAGS} -include${HEADER} -c $< -o $@

$(NAME):    ft_printf $(OBJS) 
			${CC} ${FLAGS} -include${HEADER} $(OBJS) ft_printf/libftprintf.a -o push_swap

sanitize:	ft_printf $(OBJS) 
			${CC} ${FLAGS} -g -fsanitize=address -include${HEADER} $(OBJS) ft_printf/libftprintf.a -o push_swap

clean:
			${RM} ${OBJS} ft_printf/libft/*.o ft_printf/libft/libft.a \
							ft_printf/*.o ft_printf/libftprintf.a

fclean:     clean
			${RM} ${NAME} ft_printf/libft/*.o ft_printf/libft/libft.a \
							ft_printf/*.o ft_printf/libftprintf.a push_swap

re:        fclean all

ft_printf:
			make -C ft_printf