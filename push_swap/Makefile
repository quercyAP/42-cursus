# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glamazer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 09:42:28 by glamazer          #+#    #+#              #
#    Updated: 2023/01/31 17:40:03 by glamazer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= source/push_swap.c source/utils/check_error.c source/utils/free.c \
			source/utils/utils.c source/action/action.c source/three_nbr/three_nbr.c \
			source/action/action1.c source/action/action2.c
			

OBJS		= ${SRCS:.c=.o}

NAME		= push_swap

CC			= gcc

MACLIBS		= lib/mac_libftprintf.a lib/mac_libft.a

WINLIBS		= lib/win_libftprintf.a lib/win_libft.a

CFLAGS		= -Wall -Wextra -Werror -fsanitize=address

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} ${WINLIBS} -o ${NAME}

all:		${NAME}
			
clean:			
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
