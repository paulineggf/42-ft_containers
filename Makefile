SRCS =	main.cpp		

OBJS = $(SRCS:.cpp=.o)
NAME = ft_containers
RM = rm -f
CC = clang++
CFLAGS = -Wall -Wextra -Werror -g3 -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

