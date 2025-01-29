# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afontan <afontan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 14:31:49 by afontan           #+#    #+#              #
#    Updated: 2025/01/29 11:01:35 by afontan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		= so_long

SRC_DIR     = srcs
OBJ_DIR     = objs

SRCS		= main.c initialize.c end_prog.c check_map.c check_path.c moves.c \
			move_player.c utils.c utils_two.c floodfill.c

CC			= gcc
RM			= rm -f
FLAGS		= -Wall -Werror -Wextra -I./libft/include -I/usr/include -Imlx_linux -O3 

LIBFT_DR	= libft
LIBFT_A		= $(LIBFT_DR)/libft.a
MINILIBX_DR = mlx
MINILIBX    = $(MINILIBX_DR)/libmlx.a
		
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

GREEN       = \033[0;32m
BOLD        = \033[1m
RESET       = \033[0m

all:		${LIBFT_A} ${NAME} ${MINILIBX}

${LIBFT_A}:	
			${MAKE} -C ${LIBFT_DR}

${NAME}:	${OBJS} ${LIBFT_A}
			@$(CC) $(FLAGS) -o ${NAME} ${OBJS} ${LIBFT_A} -L$(MINILIBX_DR) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
			@echo "$(GREEN)$(BOLD)Success: Compilation of ${NAME} complete!$(RESET)"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(FLAGS) -c $< -o $@
			
%.o: %.c	
			${CC} ${FLAGS} -c $< -o $@
			

clean:	
			@echo "\033[0;33mCleaning in progress...\033[0m"
			@${RM} ${OBJS} 
			@${MAKE} -C ${LIBFT_DR} clean > /dev/null 2>&1 
			@echo "$(GREEN)$(BOLD)Success: Clean of ${NAME} complete!$(RESET)"


fclean:		clean
			@${RM} ${NAME}
			${MAKE} -C ${LIBFT_DR} clean

re:			fclean all

.PHONY:		all clean fclean re