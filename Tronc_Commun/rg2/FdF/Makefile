.PHONY: all clean fclean re libft minilibx sanitize

NAME 		= 			fdf

HEADER_DIR 	= 			header/
MINILIB_DIR	= 			minilibx_linux/

SRCS_DIR	= 			src/
GNL_DIR		=			${SRCS_DIR}get_next_line/
BUILD_DIR	= 			${SRCS_DIR}build/

SRCS 		= 			fdf.c fdf_parsing.c fdf_parsing_utils.c fdf_atoi_base.c fdf_errors.c fdf_setup.c fdf_setup_var.c fdf_mlx.c \
						fdf_mlx_draw.c fdf_draw_lines.c fdf_reset_draw.c fdf_mlx_update.c \
						fdf_mlx_move.c fdf_rotate.c fdf_translate.c fdf_proj_persp.c fdf_proj_iso.c

SRCS_GNL	= 			get_next_line.c get_next_line_utils.c
				 
HEADER		=			${HEADER_DIR}fdf.h ${HEADER_DIR}get_next_line.h ${HEADER_DIR}fdf_keys.h

OBJS 		= 			${SRCS:%.c=$(BUILD_DIR)%.o}
OBJS_GNL	=			${SRCS_GNL:%.c=$(BUILD_DIR)%.o}

CC 			= 			gcc
FLAGS 		= 			-Wall -Wextra -Werror -g

RM 			= 			rm -f

MINILIB		= 			libmlx.a

LINUX		= 			-Lminilibx_linux -L/usr/lib -Iminilibx_linux -lXext -lX11 -lm -lz

all:    				minilibx libft ${NAME} 

$(BUILD_DIR)%.o: 		${SRCS_DIR}%.c ${HEADER}
						@mkdir -p src/build
						${CC} ${FLAGS} -I${HEADER_DIR} -c $< -o $@

$(BUILD_DIR)%.o:		${GNL_DIR}%.c ${HEADER}
						${CC} ${FLAGS} -I${HEADER_DIR} -c $< -o $@

${NAME}:    			$(OBJS) $(OBJS_GNL) ${HEADER}
						${CC} ${FLAGS} -I${HEADER_DIR} $(OBJS) $(OBJS_GNL) $(MINILIB_DIR)$(MINILIB) libft/libft.a ${LINUX} -o fdf


sanitize:				minilibx libft $(OBJS) $(OBJS_GNL) ${HEADER}
						${CC} ${FLAGS} -g -fsanitize=address -I${HEADER_DIR} $(OBJS) $(OBJS_GNL) $(MINILIB_DIR)$(MINILIB) libft/libft.a ${LINUX} -o fdf

clean:
						${RM} libft/libft.a libft/build/*.o \
						$(BUILD_DIR)/*.o $(MINILIB_DIR)/*.o $(MINILIB_DIR)$(MINILIB)

fclean:     			clean
						${RM} ${NAME} fdf

re:        				fclean all

libft:
						make -C libft

minilibx:	
						@make -C $(MINILIB_DIR)