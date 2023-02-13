.PHONY: all clean fclean re bonus

NAME 		= libft.a

SRCS 		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJS 		= ${SRCS:.c=.o}

SRCS_BONUS 	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS_BONUS 	= ${SRCS_BONUS:.c=.o}

CC 			= gcc
FLAGS 		= -Wall -Wextra -Werror

HEADER 		= libft.h

LIB 		= ar rc

RM 			= rm -f

all:    	${NAME} Makefile

%.o: 		%.c ${HEADER} Makefile 
			${CC} ${FLAGS} -include${HEADER} -c $< -o $@

$(NAME):    $(OBJS) Makefile
			${LIB} ${NAME} ${OBJS}

bonus:		$(OBJS) ${OBJS_BONUS}
			${LIB} ${NAME} ${OBJS} ${OBJS_BONUS}
clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:     clean
			${RM} ${NAME} ${OBJS_BONUS}

re:        fclean all

