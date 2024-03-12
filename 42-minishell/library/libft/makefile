# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 15:18:00 by Tdechand          #+#    #+#              #
#    Updated: 2023/03/15 10:29:36 by tdechand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
				ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_putchar_pf.c ft_putstr_pf.c ft_putnbr_pf.c ft_putunbr_pf.c ft_putullnbrb_pf.c \
				ft_putnbrb_pf.c ft_putnbrbcap_pf.c get_next_line.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c ft_lstiter_rev.c ft_lstmap.c ft_strtab_dup.c ft_strtab_len.c ft_lstclear_nc.c ft_lstrewind.c

OBJS		=	${SRCS:.c=.o}

COMP		=	gcc
FLAGS		=	-Wall -Wextra -Werror

.c.o		:	
				@${COMP} ${FLAGS} -I. -c $< -o ${<:.c=.o}
				@echo "\033[0;96m* $(notdir $<) -> $(notdir $@) * \033[0m: \033[0;92mOK\033[0m"

${NAME}		: 	${OBJS}
				@ar rc ${NAME} ${OBJS}
				@echo "\033[0;92m\n* ${NAME} library was created *\033[0m"

all			:	${NAME}

clean		:	
				@rm -f ${OBJS}
				@echo "\033[0;91m* ${NAME} object files were deleted *\033[0m"

fclean		:	clean
				@rm -f ${NAME}
				@echo "\033[0;91m* ${NAME} was deleted *\033[0m"

re			:	fclean all
			
.PHONY		:	all clean fclean re
