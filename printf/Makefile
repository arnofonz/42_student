# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afontan <afontan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 16:14:39 by afontan           #+#    #+#              #
#    Updated: 2024/11/15 16:20:44 by afontan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		= libftprintf.a

SRCS		= ft_printf.c ft_toolspf ft_putnbr_dif

CC			= gcc -c

RM			= rm -f

FLAGS		= -Wall -Werror -Wextra

		
OBJS		= ${SRCS:.c=.o}

all:		${NAME}

${NAME} :	${OBJS}
			ar rcs ${NAME} ${OBJS}
			
%.o: %.c	
			${CC} ${FLAGS} -c $< -o $@
			
clean:	
			${RM} ${OBJS} ${OBJ_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus