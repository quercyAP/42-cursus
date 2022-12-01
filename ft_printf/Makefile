SRCS		= ft_printf.c ft_printchar.c ft_printnbr.c ft_printnbr_base.c ft_printstr.c ft_strlen.c ft_printaddr.c ft_printunbr.c

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
