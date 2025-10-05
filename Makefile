# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: your_login <your_email@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/01 00:00:00 by your_login       #+#    #+#              #
#    Updated: 2024/01/01 00:00:00 by your_login      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -pthread
INCLUDES	= -I./includes

SRC_DIR		= src
OBJ_DIR		= object

SRCS		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/parser.c \
			  $(SRC_DIR)/init.c \
			  $(SRC_DIR)/dinner.c \
			  $(SRC_DIR)/monitor.c \
			  $(SRC_DIR)/utils.c \
			  $(SRC_DIR)/write.c \
			  $(SRC_DIR)/safe_functions.c \
			  $(SRC_DIR)/getters_setters.c \
			  $(SRC_DIR)/synchro_utils.c \
			  $(SRC_DIR)/clean.c

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

RM			= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0;32m✓ Philosophers compiled successfully!\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "\033[0;33mCompiling: $<\033[0m"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "\033[0;31m✓ Object files removed\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31m✓ Executable removed\033[0m"

re: fclean all

.PHONY: all clean fclean re