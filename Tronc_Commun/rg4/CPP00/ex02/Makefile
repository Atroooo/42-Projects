.PHONY: all fclean clean re

NAME	=	phoneBook

SRCS	=	Account.cpp tests.cpp
HEADERS	=	Account.hpp

CC		=	clang++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

OBJS	=	$(SRCS:.cpp=.o)

%.o:		%.cpp
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all
