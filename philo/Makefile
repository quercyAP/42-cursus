# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 12:55:21 by glamazer          #+#    #+#              #
#    Updated: 2023/03/20 14:28:33 by glamazer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= philo.c utils.c philo_routine.c supervisor.c

OBJS		= ${SRCS:.c=.o}

NAME		= philo

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}
			
clean:			
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re