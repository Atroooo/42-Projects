### FLAGS ###
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror 

#### LIBFT HEADER COMPILED ####
LIBFT_COMPILED = libft/libft.a

### FINAL COMPILATION FILE ###
NAME = compiled
CLIENT = ./client
SERVER = ./server

### SERVER FILES ###
SRCS_SERVER = src/minitalk_server.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

### CLIENT FILES ###
SRCS_CLIENT = src/minitalk_client.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
DEPENDS := $(SRCS_CLIENT:.c=.d) $(SRCS_SERVER:.c=.d)

#### RULES ####
all:		libft_comp $(SERVER) $(CLIENT) Makefile

%.o:%.c 	Makefile $(LIBFT_COMPILED)
			$(CC) $(CFLAGS) -c $< -MD -o $@ -g3

clean:
			@$(MAKE) clean -C libft
			$(RM) $(OBJS_CLIENT)
			$(RM) $(OBJS_SERVER)
			$(RM) $(DEPENDS)
			$(RM) $(LIBFT_COMPILED)

fclean:     clean
			$(RM) $(SERVER)
			$(RM) $(CLIENT)

libft_comp:
			@$(MAKE) all -C libft

$(CLIENT):  $(OBJS_CLIENT) $(LIBFT_COMPILED)
			$(CC) $(OBJS_CLIENT) $(LIBFT_COMPILED) $(CFLAGS) -o $(CLIENT)

$(SERVER):  $(OBJS_SERVER) $(LIBFT_COMPILED)
			$(CC) $(OBJS_SERVER) $(LIBFT_COMPILED) $(CFLAGS) -o $(SERVER)

re:    fclean all

-include $(DEPENDS)

#### SYSTEM ####

.PHONY:  all clean fclean re libft_comp
