# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 17:54:24 by dvargas           #+#    #+#              #
#    Updated: 2022/08/24 20:06:44 by dvargas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	pipex.c \
			utils.c
OBJS		= ${SRCS:%.c=%.o}
NAME		= pipex
NAMEBONUS	= pipex
LIB			= libft/libft.a
CC			= cc
CCFLAGS		= -Wall -Wextra -Werror -I libft/
LIBFT_PATH  = libft/

all:		${NAME}

$(NAME):	${OBJS}
			@ echo 'Creating the monster'
			make all -C $(LIBFT_PATH)
			${CC} ${CCFLAGS} ${OBJS} ${LIB} -o ${NAME}
			@ echo 'ITS ALIVE!!!!!!!!!'
			@ echo ' '

%.o: %.c
			${CC} ${CCFLAGS} -c $< -o $@
			@ echo ' '

clean:
			@ echo 'clean rule'
			rm -f ${OBJS} bonus.o
			make clean -C $(LIBFT_PATH)
			@ echo ' '

fclean:		clean
			@ echo 'Removing pipex and pipex bonus'
			rm -f ${NAMEBONUS}
			rm -f ${NAME}
			make fclean -C $(LIBFT_PATH)
			@ echo ' '

re:			fclean all
			@ echo 're rule. . . .$<'
			@ echo ' '

bonus:		fclean	
			make all -C $(LIBFT_PATH)
			${CC} ${CCFLAGS} utils_bonus.c pipex_bonus.c ${LIB} -o ${NAMEBONUS}

.PHONY:		all clean fclean re
