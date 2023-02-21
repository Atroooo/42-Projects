.PHONY: all clean fclean re libft sanitize

NAME 		= 			pipex

HEADER_DIR 	= 			header/

SRCS_DIR	= 			src/
GNL_DIR		=			${SRCS_DIR}get_next_line/
BUILD_DIR	= 			${SRCS_DIR}build/

SRCS 		= 			pipex.c pipex_utils.c pipex_exec.c

SRCS_GNL	= 			get_next_line.c get_next_line_utils.c
				 
HEADER		=			${HEADER_DIR}pipex.h ${HEADER_DIR}get_next_line.h

OBJS 		= 			${SRCS:%.c=$(BUILD_DIR)%.o}
OBJS_GNL	=			${SRCS_GNL:%.c=$(BUILD_DIR)%.o}

CC 			= 			gcc
FLAGS 		= 			-Wall -Wextra -Werror -g

RM 			= 			rm -f

all:    				libft ${NAME} 

$(BUILD_DIR)%.o: 		${SRCS_DIR}%.c ${HEADER}
						@mkdir -p src/build
						${CC} ${FLAGS} -I${HEADER_DIR} -c $< -o $@

$(BUILD_DIR)%.o:		${GNL_DIR}%.c ${HEADER}
						${CC} ${FLAGS} -I${HEADER_DIR} -c $< -o $@

${NAME}:    			$(OBJS) $(OBJS_GNL) ${HEADER}
						${CC} ${FLAGS} -I${HEADER_DIR} $(OBJS) $(OBJS_GNL) libft/libft.a -o ${NAME}


sanitize:				libft $(OBJS) $(OBJS_GNL) ${HEADER}
						${CC} ${FLAGS} -fsanitize=address -I${HEADER_DIR} $(OBJS) $(OBJS_GNL) libft/libft.a -o ${NAME}

clean:
						${RM} libft/libft.a libft/build/*.o \
						$(BUILD_DIR)/*.o

fclean:     			clean
						${RM} ${NAME}

re:        				fclean all

libft:
						make -C libft
