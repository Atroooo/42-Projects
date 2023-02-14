.PHONY: all clean fclean re libft minilibx sanitize

NAME 		= 			philo

HEADER_DIR 	= 			header/

SRCS_DIR	= 			src/
BUILD_DIR	= 			${SRCS_DIR}build/

SRCS 		= 			philo.c philo_atoi.c philo_parsing.c \
						philo_create_thread.c
				 
HEADER		=			${HEADER_DIR}philo.h

OBJS 		= 			${SRCS:%.c=$(BUILD_DIR)%.o}

CC 			= 			gcc
FLAGS 		= 			-Wall -Wextra -Werror -g -pthread

RM 			= 			rm -f

all:    				${NAME}

$(BUILD_DIR)%.o: 		${SRCS_DIR}%.c ${HEADER}
						@mkdir -p src/build
						${CC} ${FLAGS} -I${HEADER_DIR} -c $< -o $@


$(NAME):    			$(OBJS) ${HEADER}
						${CC} ${FLAGS} -I${HEADER_DIR} $(OBJS) -o philo


sanitize:				$(OBJS) ${HEADER}
						${CC} ${FLAGS} -fsanitize=address -I${HEADER_DIR} $(OBJS) -o philo

clean:
						${RM} $(BUILD_DIR)/*.o

fclean:     			clean
						${RM} ${NAME} philo

re:        				fclean all
