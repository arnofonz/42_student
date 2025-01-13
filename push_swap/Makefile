# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afontan <afontan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 14:31:49 by afontan           #+#    #+#              #
#    Updated: 2025/01/13 12:23:00 by afontan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		= push_swap
BONUS_NAME	= checker

SRC_DIR     = srcs
SRC_BONUS	= srcs
OBJ_DIR     = objs
INCLUDE_DIR = include



SRCS		= main.c op_swap.c op_push.c op_rotate.c op_rrotate.c sort_2_3.c \
			check.c sort_more.c utils_pushswap.c sort_a_to_b.c sort_b_to_a.c \
			initialize.c utils_lst.c utils.c

SRC_BONUS	= op_swap.c op_push.c op_rotate.c op_rrotate.c sort_2_3.c \
			check.c sort_more.c utils_pushswap.c sort_a_to_b.c sort_b_to_a.c \
			initialize.c utils_lst.c utils.c checker_bonus.c utils_bonus.c \
			utils_bonus_two.c

CC			= gcc
RM			= rm -f
FLAGS		= -Wall -Werror -Wextra -I./libft/include -I$(INCLUDE_DIR)

LIBFT_DR	= libft
LIBFT_A		= $(LIBFT_DR)/libft.a
		
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJ_BONUS   = $(addprefix $(OBJ_DIR)/, $(SRC_BONUS:.c=.o))

GREEN       = \033[0;32m
BOLD        = \033[1m
RESET       = \033[0m

all:		${LIBFT_A} ${NAME}

${LIBFT_A}:	
			@echo "$(GREEN)Building libft...$(RESET)"
			${MAKE} -C ${LIBFT_DR}

${NAME}:	${OBJS} ${LIBFT_A}
			$(CC) $(FLAGS) -o ${NAME} ${OBJS} ${LIBFT_A}
			@echo "$(GREEN)$(BOLD)Success: Compilation of ${NAME} complete!$(RESET)"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
			@mkdir -p $(OBJ_DIR)
			$(CC) $(FLAGS) -c $< -o $@

bonus:		${LIBFT_A} ${OBJ_BONUS} ${NAME}
			$(CC) $(FLAGS) -o ${BONUS_NAME} ${OBJ_BONUS} ${LIBFT_A}
			@echo "$(GREEN)$(BOLD)Success: Compilation of BONUS complete!$(RESET)"

%.o: %.c	
			${CC} ${FLAGS} -c $< -o $@
			

clean:
			${RM} -rf ${OBJ_DIR}/*
			${MAKE} -C ${LIBFT_DR} clean

fclean:		clean
			${RM} ${NAME} ${BONUS_NAME}
			${MAKE} -C ${LIBFT_DR} fclean

re:			fclean all


testrepeat:
			@read -p "Enter the number of random integers: " nb && \
			for i in $$(seq 1 100); do \
				seq -300 300 | shuf -n $$nb | tr '\n' ' ' > random_numbers.txt && \
				echo "Test $$i:" && \
				count=$$(./$(NAME) $$(cat random_numbers.txt) | wc -l) && \
				printf "\033[1;38;5;208m$$count\033[0m\n" && \
				echo "Tested with: $$(cat random_numbers.txt)" && \
				rm random_numbers.txt; \
			done

testrepeatlight:
			@read -p "Enter the number of random integers: " nb && \
			total=0 && \
			for i in $$(seq 1 20); do \
				seq -300 300 | shuf -n $$nb | tr '\n' ' ' > random_numbers.txt && \
				echo "Test $$i:" && \
				count=$$(./$(NAME) $$(cat random_numbers.txt) | wc -l) && \
				printf "\033[1;38;5;208m$$count\033[0m\n" && \
				total=$$((total + count)) && \
				rm random_numbers.txt; \
			done && \
			average=$$((total / 20)) && \
			printf "\033[1;36mAverage count over 100 runs: %s\033[0m\n" "$$average"

.PHONY:		all clean fclean re bonus