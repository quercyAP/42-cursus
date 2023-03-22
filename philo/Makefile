# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 12:55:21 by glamazer          #+#    #+#              #
#    Updated: 2023/03/22 12:24:12 by glamazer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = philo.c utils.c philo_routine.c supervisor.c check_args.c ft_error.c
OBJS = ${SRCS:.c=.o}
NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

.c.o:
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@echo "$(GREEN)Linking objects into executable ${NAME}...$(RESET)"
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}
			
clean:
	@echo "$(YELLOW)Removing object files...$(RESET)"
	@rm -f ${OBJS}

fclean: clean
	@echo "$(YELLOW)Removing executable...$(RESET)"
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
