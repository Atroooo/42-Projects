.PHONY: all clean fclean re libft

NAME_SERVER				= server
NAME_CLIENT				= client

BUILD_DIR				= src/build/

SRCS_DIR 				= src/
SRCS_SERVER				= minitalk_server.c
SRCS_CLIENT				= minitalk_client.c

OBJS_SERVER 			= ${SRCS_SERVER:%.c=$(BUILD_DIR)%.o}
OBJS_CLIENT 			= ${SRCS_CLIENT:%.c=$(BUILD_DIR)%.o}

CC 						= gcc
FLAGS 					= -Wall -Wextra -Werror

HEADER 					= header/minitalk.h

RM 						= rm -f

all:    				${NAME_SERVER} ${NAME_CLIENT}

$(BUILD_DIR)%.o: 		${SRCS_DIR}%.c ${HEADER}
						@mkdir -p $(BUILD_DIR)
						${CC} ${FLAGS} -include${HEADER} -c $< -o $@

$(NAME_SERVER):    		$(OBJS_SERVER) ${HEADER}
						make -C libft
						${CC} ${FLAGS} -include${HEADER} $(OBJS_SERVER) libft/libft.a -o server

$(NAME_CLIENT):    		$(OBJS_CLIENT) ${HEADER}
						make -C libft
						${CC} ${FLAGS} -include${HEADER} $(OBJS_CLIENT) libft/libft.a -o client

clean:
						${RM} ${OBJS} libft/Build/*.o libft/libft.a $(BUILD_DIR)*.o

fclean:     			clean
						${RM} ${NAME_SERVER} ${NAME_CLIENT}

re:        				fclean all

libft:
						make -C libft
