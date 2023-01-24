# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 15:37:47 by glamazer          #+#    #+#              #
#    Updated: 2023/01/24 13:59:15 by glamazer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= source/check/check_error_utils.c source/check/check_error.c source/utils/free.c \
		source/utils/init.c source/utils/draw.c source/utils/count_elem.c \
		source/utils/load_sprite.c source/utils/set_anim.c source/utils/get_next_line.c \
		source/utils/get_next_line_utils.c source/utils/parsing.c source/utils/init_utils.c\
		source/player/player_movement.c source/player/player_collision.c source/player/player_hook.c \
		source/player/player_anim1.c source/player/player_draw.c source/player/player_anim.c \
		source/player/player_shoot.c \
		source/item/item_hook.c source/item/item_anim.c \
		source/gate/gate_anim.c source/gate/gate_hook.c \
		source/mob/mob_hook.c source/mob/mob_anim.c \
		source/so_long.c \
		
OBJS	= ${SRCS:.c=.o}

WINLIBS	= lib/win_libft.a lib/win_libmlx42.a

MACLIBS	= lib/mac_libft.a lib/mac_libmlx42.a -lglfw -L /Users/glamazer/goinfre/.brew/opt/glfw/lib/

HEADER	= -I includes -I /Users/glamazer/goinfre/MLX42/include -I /Users/goinfre/glamazer/.brew/Cellar/glfw/3.3.8/include/GLFW

MAP		= map/test.ber

NAME	= so_long

CC		= gcc

WINCFLAGS	= -Wall -Wextra -Werror -ldl -lglfw -pthread -lm

MACCFLAGS	= -g3 -Wall -Wextra -Werror
# Windows set
# .c.o:
# 			${CC} ${WINCFLAGS} -c $< -o ${<:.c=.o}

# ${NAME}:	${OBJS}
# 			${CC} ${OBJS} ${WINLIBS} ${WINCFLAGS} -o ${NAME}

# MAC set
.c.o:
			${CC} ${MACCFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${MACCFLAGS} ${OBJS} ${MACLIBS} -o ${NAME}

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
