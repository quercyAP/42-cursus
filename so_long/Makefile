# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glamazer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 15:37:47 by glamazer          #+#    #+#              #
#    Updated: 2023/01/11 07:24:48 by glamazer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= source/check/check_error_utils.c source/check/check_error.c source/utils/free.c \
		source/utils/get_next_line.c source/utils/get_next_line_utils.c source/utils/parsing.c \
		source/so_long.c source/utils/init.c source/draw_map.c source/utils/count_elem.c \
		source/utils/load_sprite.c source/player.c source/collision.c

OBJS	= ${SRCS:.c=.o}

WINLIBS	= lib/win_libft.a lib/win_libmlx42.a

MACLIBS	= lib/mac_libft.a lib/mac_libmlx42.a lib/libglfw3.a -framework Cocoa -framework OpenGL -framework IOKit

HEADER	= -I includes -I /Users/glamazer/goinfre/MLX42/include -I /Users/glamazer/.brew/Cellar/glfw/3.3.8/include/GLFW

MAP		= map/test.ber

NAME	= so_long

CC		= gcc

WINCFLAGS	= -Wall -Wextra -Werror -ldl -lglfw -pthread -lm

MACCFLAGS	= -Wall -Wextra -Werror
# Windows set
.c.o:
			${CC} ${WINCFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${OBJS} ${WINLIBS} ${WINCFLAGS} -o ${NAME}

# MAC set
# .c.o:
# 			${CC} ${MACCFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

# ${NAME}:	${OBJS}
# 			${CC} ${MACCFLAGS} ${OBJS} ${MACLIBS} -o ${NAME}

run:		
			./${NAME} ${MAP}

all:		${NAME} run clean

memcheck:	re
			valgrind --leak-check=full ./${NAME} ${MAP}

re:			all

clean:		
			rm -rf a.out so_long.dSYM ${OBJS}

fclean:		clean
			rm -rf so_long

.PHONY:		all re clean re
