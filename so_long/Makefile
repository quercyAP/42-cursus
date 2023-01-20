# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glamazer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 15:37:47 by glamazer          #+#    #+#              #
#    Updated: 2023/01/19 08:33:20 by glamazer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= source/check/check_error_utils.c source/check/check_error.c source/utils/free.c \
		source/utils/init.c source/utils/draw.c source/utils/count_elem.c \
		source/utils/load_sprite.c source/utils/set_anim.c source/utils/get_next_line.c \
		source/utils/get_next_line_utils.c source/utils/parsing.c \
		source/player/player_movement.c source/player/player_collision.c source/player/player_hook.c \
		source/player/player_anim1.c source/player/player_draw.c source/player/player_anim.c \
		source/player/player_shoot.c \
		source/item/item_hook.c source/item/item_anim.c \
		source/gate/gate_anim.c source/gate/gate_hook.c \
		source/so_long.c \
		
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
