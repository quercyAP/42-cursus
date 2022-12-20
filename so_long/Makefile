SRCS	= source/check_error_utils.c source/check_error.c source/free.c \
		source/get_next_line.c source/get_next_line_utils.c source/parsing.c \
		source/so_long.c source/utils.c

LIBS	= lib/libft.a lib/libmlx42.a

MAP		= map/test.ber

NAME	= so_long

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -ldl -lglfw -pthread -lm

.c.o:
			${CC} ${SRCS} ${LIBS} ${CFLAGS} -o ${NAME}

${NAME}:	.c.o

run:		
			./${NAME} ${MAP}

all:		${NAME} run

memcheck:		
			valgrind --leak-check=full ./${NAME} ${MAP}

re:			all

clean:		
			rm -rf a.out a.out.dSYM ${NAME}

.PHONY:		all re clean re debug
