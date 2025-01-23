# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afontan <afontan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 14:31:49 by afontan           #+#    #+#              #
#    Updated: 2025/01/15 12:51:35 by afontan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAMES 		= server
NAMEC		= client
BONUS_NAMES	= server_bonus
BONUS_NAMEC	= client_bonus

SRC_DIR     = srcs
SRC_BONUS	= srcs
OBJ_DIR     = objs
INCLUDE_DIR = include

SRCSC		= client.c
SRCSS		= server.c

SRC_BONUSC	= client_bonus.c
SRC_BONUSS	= server_bonus.c

CC			= gcc
RM			= rm -f
FLAGS		= -Wall -Werror -Wextra -I./libft/include -I$(INCLUDE_DIR)

LIBFT_DR	= libft
LIBFT_A		= $(LIBFT_DR)/libft.a
		
OBJSC		= $(addprefix $(OBJ_DIR)/, $(SRCSC:.c=.o))
OBJSS		= $(addprefix $(OBJ_DIR)/, $(SRCSS:.c=.o))
OBJ_BONUSC   = $(addprefix $(OBJ_DIR)/, $(SRC_BONUSC:.c=.o))
OBJ_BONUSS   = $(addprefix $(OBJ_DIR)/, $(SRC_BONUSS:.c=.o))

GREEN       = \033[0;32m
BOLD        = \033[1m
RESET       = \033[0m

all:		${LIBFT_A} ${NAMES} ${NAMEC}

server:		${NAMES}

client:		${NAMEC}

bonus:		${BONUS_NAMES} ${BONUS_NAMEC}

${LIBFT_A}:	
			@echo "$(GREEN)Building libft...$(RESET)"
			${MAKE} -C ${LIBFT_DR}

${NAMEC}:	${OBJSC} ${LIBFT_A}
			$(CC) $(FLAGS) -o ${NAMEC} ${OBJSC} ${LIBFT_A}
			@echo "$(GREEN)$(BOLD)Success: Compilation of CLIENT complete!$(RESET)"

${NAMES}: 	${OBJSS} ${LIBFT_A}
			$(CC) $(FLAGS) -o ${NAMES} ${OBJSS} ${LIBFT_A}
			@echo "$(GREEN)$(BOLD)Success: Compilation of SERVER complete!$(RESET)"

${BONUS_NAMEC}:	${OBJ_BONUSC} ${LIBFT_A}
			$(CC) $(FLAGS) -o ${BONUS_NAMEC} ${OBJ_BONUSC} ${LIBFT_A}
			@echo "$(GREEN)$(BOLD)Success: Compilation of CLIENT_BONUS complete!$(RESET)"

${BONUS_NAMES}:	${OBJ_BONUSS} ${LIBFT_A}
			$(CC) $(FLAGS) -o ${BONUS_NAMES} ${OBJ_BONUSS} ${LIBFT_A}
			@echo "$(GREEN)$(BOLD)Success: Compilation of SERVER_BONUS complete!$(RESET)"
			
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
			@mkdir -p $(OBJ_DIR)
			$(CC) $(FLAGS) -c $< -o $@

%.o: %.c	
			${CC} ${FLAGS} -c $< -o $@
			

clean:
			${RM} -rf ${OBJ_DIR}/*
			${MAKE} -C ${LIBFT_DR} clean

fclean:		clean
			${RM} ${NAMES} ${NAMEC} ${BONUS_NAMES} ${BONUS_NAMEC}
			${MAKE} -C ${LIBFT_DR} fclean

re:			fclean all

