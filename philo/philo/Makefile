# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afontan <afontan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 09:19:41 by afontan           #+#    #+#              #
#    Updated: 2025/03/24 13:23:06 by afontan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = philo

SRC_DIR     = srcs
OBJ_DIR     = objs
INCLUDE_DIR = include

SRCS        = $(SRC_DIR)/main.c 		\
			  $(SRC_DIR)/utils.c 		\
			  $(SRC_DIR)/init.c			\
			  $(SRC_DIR)/routine.c		\
			  $(SRC_DIR)/check_death.c	\
			  $(SRC_DIR)/thread.c
			  

CC          = cc
RM          = rm -f
FLAGS       = -Wall -Werror -Wextra -Iinclude
		
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

GREEN       = \033[0;32m
RED         = \033[0;31m
YELLOW      = \033[0;33m
BOLD        = \033[1m
RESET       = \033[0m

all:        $(NAME)

$(NAME):    $(OBJS)
			@$(CC) $(FLAGS) -o $(NAME) $(OBJS)
			@echo "$(GREEN)$(BOLD)Success: Compilation of $(NAME) complete!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(FLAGS) -c $< -o $@

clean:
			@echo "$(YELLOW)Cleaning object files...$(RESET)"
			@$(RM) -rf $(OBJ_DIR)/*
			@echo "$(GREEN)$(BOLD)Cleaned object files!$(RESET)"

fclean:     clean
			@echo "$(RED)Removing executable...$(RESET)"
			@$(RM) $(NAME)
			@echo "$(GREEN)$(BOLD)Executable removed!$(RESET)"

re:         fclean all

.PHONY:     all clean fclean re