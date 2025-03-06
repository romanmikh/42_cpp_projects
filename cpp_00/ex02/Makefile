# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rocky <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/25 18:53:30 by rocky             #+#    #+#              #
#    Updated: 2024/08/25 18:53:32 by rocky            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# c++ -Wall -Wextra -Werror ./src/*.cpp

# Program file name
NAME	= output

# Compiler and compilation flags
CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

# Build files and directories
SRC_PATH 	= ./src/
OBJ_PATH	= ./obj/
INC_PATH	= ./inc/
SRC			= $(wildcard $(SRC_PATH)/*.cpp) $(wildcard $(SRC_PATH)/*/*.cpp)
SRCS		= $(SRC)
OBJ			= $(patsubst $(SRC_PATH)%, %, $(SRCS:.cpp=.o))
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))
INC			= -I $(INC_PATH)

# Main rule
all: $(OBJ_PATH) $(NAME)

# Objects directory rule
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

# Objects rule
$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# Project file rule
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)

# Clean up build files rule
clean:
	rm -rf $(OBJ_PATH)

# Remove program executable
fclean: clean
	rm -f $(NAME)

# Clean + remove executable
re: fclean all

.PHONY: all re clean fclean