# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 09:42:28 by glamazer          #+#    #+#              #
#    Updated: 2023/01/30 09:51:49 by glamazer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= push_swap.c

OBJS		= ${SRCS:.c=.o}

NAME		= push_swap

CC			= gcc

LIBS		= lib/libftprintf.a lib/libft.a

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

all:		${NAME}
			
clean:			
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
