# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 09:54:16 by glamazer          #+#    #+#              #
#    Updated: 2023/01/26 15:30:34 by glamazer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

LIBS		= lib/libftprintf.a lib/libft.a

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

client:		client.o
			${CC} ${CFLAGS} client.o ${LIBS} -o client

server:		server.o
			${CC} ${CFLAGS} server.o ${LIBS} -o server

all:		client server
			
clean:			
			rm -f client.o server.o

fclean:		clean
			rm -f client server

re:			fclean all

.PHONY:		all clean fclean re
