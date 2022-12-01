SRCS		= get_next_line.c get_next_line_utils.c

OBJS		= ${SRCS:.c=.o}

RL			= ranlib

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c ${SRCS}

${NAME}:	${OBJS}
			ar -rc ${NAME} ${OBJS}
			${RL} ${NAME}

all:		${NAME}
			
clean:			
			rm -f ${OBJS}	

fclean:		clean
			rm -f ${NAME} 

re:			fclean all

.PHONY:		all clean fclean re 
