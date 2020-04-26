
SRCS =	./srcs/mytest/main.cpp			\
		./srcs/mytest/vectorTest.cpp	\
		./srcs/mytest/constructor.cpp

OBJS = $(SRCS:.cpp=.o)
INCLUDES = ../includes/vector/
NAME = ft_containers
RM = rm -f
CC = clang++
CFLAGS = -Wall -Wextra -Werror -g -MMD -I$(INCLUDES) -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	mv ft_containers bin/

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re



# CXX       := clang++
# CXX_FLAGS := -Wall -Wextra -Werror -std=c++98 -ggdb

# BIN     := bin
# SRC     := src
# INCLUDE := includes
# LIB     := lib
# LIBRARIES   := 
# EXECUTABLE  := main


# all: $(BIN)/$(EXECUTABLE)

# run: clean all
#     clear
#     @echo "🚀 Executing..."
#     ./$(BIN)/$(EXECUTABLE)

# $(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
#     @echo "🚧 Building..."
#     $(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

# clean:
#     @echo "🧹 Clearing..."
#     -rm $(BIN)/*