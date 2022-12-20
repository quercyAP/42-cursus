SRCS	= source/check_error_utils.c source/check_error.c source/free.c \
		source/get_next_line.c source/get_next_line_utils.c source/parsing.c \
		source/so_long.c source/utils.c

WINLIBS	= lib/win_libft.a lib/win_libmlx42.a

MACLIBS	= lib/mac_libft.a lib/mac_libmlx42.a -lglfw -L "/Users/glamazer/.brew/opt/glfw/lib/"

MAP		= map/test.ber

NAME	= so_long

CC		= gcc

WINCFLAGS	= -Wall -Wextra -Werror -ldl -lglfw -pthread -lm

MACCFLAGS	= -Wall -Wextra -Werror

# .c.o:
# 			${CC} ${SRCS} ${WINLIBS} ${WINCFLAGS} -o ${NAME}

.c.o:
			${CC} ${MACCFLAGS} ${SRCS} ${MACLIBS} -o ${NAME}

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
