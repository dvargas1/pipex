# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 17:54:24 by dvargas           #+#    #+#              #
#    Updated: 2022/08/23 15:15:03 by dvargas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	pipex.c \
			utils.c
OBJS		= ${SRCS:%.c=%.o}
NAME		= pipex
NAMEBONUS	= pipex_bonus
LIB			= libft/libft.a
CC			= cc
CCFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

$(NAME):	${OBJS}
			@ echo 'Creating the monster'
			${CC} ${CCFLAGS} ${OBJS} ${LIB} -o ${NAME}
			@ echo 'ITS ALIVE!!!!!!!!!'
			@ echo ' '

%.o: %.c pipex.h 
			${CC} ${CCFLAGS} -c $< -o $@
			@ echo ' '

clean:
			@ echo 'clean rule'
			rm -f ${OBJS} bonus.o
			@ echo ' '

fclean:		clean
			@ echo 'Removing pipex'
			rm -f ${NAME}
			@ echo ' '

re:			fclean all
			@ echo 're rule. . . .$<'
			@ echo ' '

bonus:		
			${CC} ${CCFLAGS} utils.c bonus.c ${LIB} -o ${NAMEBONUS}

.PHONY:		all clean fclean re
