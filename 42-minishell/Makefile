# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 07:31:25 by tdechand          #+#    #+#              #
#    Updated: 2023/03/23 09:51:56 by glamazer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	minishell
CC				=	gcc
CCFLAG			=	-Wall -Wextra -Werror

HDR_DIR			=	-I library/libft -I includes -I includes/utils -I includes/built_in -I /Users/$(USER)/goinfre/.brew/opt/readline/include -I /Users/$(USER)/.brew/opt/readline/include
HDR_FILE		=	minishell.h

HEADERS			=	$(addprefix $(HDR_DIR), $(HDR_FILE))


SRC_DIR			=	./src/
SRC_FILE		=	main.c \
					utils/readline.c \
					utils/readline2.c \
					utils/exit_main.c \
					utils/free.c \
					utils/free2.c \
					utils/error.c \
					utils/parser2000.c \
					utils/parser2000_2.c \
					utils/parser2000_3.c \
					utils/parser2000_4.c \
					utils/parser2000_5.c \
					utils/rl_sep_heredoc.c \
					utils/display_utils2.c \
					utils/display_utils.c \
					utils/display_list.c \
					utils/string_cleaner.c \
					utils/string_cleaner_utils.c \
					utils/handle.c \
					utils/exec_other.c \
					utils/parser_check.c\
					utils/parser_check2.c\
					utils/get_env.c \
					utils/display_envutils.c \
					utils/launcher.c \
					utils/ms_split.c \
					utils/ms_split2.c \
					utils/putstr_fd_wq.c \
					utils/create_envlist.c \
					utils/env_parser.c\
					utils/redir.c \
					utils/redir2.c \
					utils/sort_env.c\
					utils/quote_parser.c\
					utils/env_utils2.c\
					utils/heredoc.c\
					utils/cmd_parser.c\
					utils/quote_splitter.c \
					utils/quote_splitter2.c \
					utils/rev.c\
					built_in/ms_exit.c \
					built_in/ms_echo.c \
					built_in/ms_export.c \
					built_in/ms_cd.c \
					built_in/ms_cd2.c \
					built_in/ms_pwd.c\
					built_in/ms_unset.c \
					built_in/ms_env.c\


SOURCES			=	$(addprefix $(SRC_DIR), $(SRC_FILE))


OBJ_DIR			=	./obj/
OBJ_DIR_DEBUG	=	./obj_debug/
OBJ_FILE		=	$(patsubst %.c, %.o, $(SRC_FILE))
OBJECTS			=	$(addprefix $(OBJ_DIR), $(OBJ_FILE))
OBJECTS_DEBUG	=	$(addprefix $(OBJ_DIR_DEBUG), $(OBJ_FILE))



LIB				=	-lft -lreadline
LIB_DIR			=	-L ./library/libft -L /Users/$(USER)/goinfre/.brew/opt/readline/lib -L /Users/$(USER)/.brew/opt/readline/lib

all						:	$(NAME)

$(NAME)					:	obj $(OBJ_DIR) $(OBJECTS) lib
							@$(CC) $(CCFLAG) $(OBJECTS) ${HDR_DIR} ${LIB_DIR} ${LIB} -o $(NAME)
							@echo "\033[0;92m\n* $(NAME) program file was created *\033[0m"

$(OBJ_DIR)%.o 			: 	$(SRC_DIR)%.c
							@$(CC) $(CCFLAGS) ${HDR_DIR} -c $< -o $@
							@echo "\033[0;96m* $(notdir $<) -> $(notdir $@) * \033[0m: \033[0;92mOK\033[0m"

$(OBJ_DIR_DEBUG)%.o		: 	$(SRC_DIR)%.c
							@$(CC) -g $(CCFLAGS) ${HDR_DIR} -c $< -o $@
							@echo "\033[0;96m* $(notdir $<) -> $(notdir $@) * \033[0m: \033[0;93mOK (debug)\033[0m"


clean					:	
							@rm -rf $(OBJ_DIR) && rm -rf $(OBJ_DIR_DEBUG)
							@echo "\033[0;91m* $(NAME) object files were deleted *\033[0m"

fclean					:	clean fcleanlib
							@rm -rf $(NAME)
							@echo "\033[0;91m* $(NAME) was deleted *\033[0m"

re						:	fclean $(NAME)

sanitize				:	$(OBJ_DIR) $(OBJECTS) lib
							@$(CC) -fsanitize=address -g3 $(CCFLAG) $(OBJECTS) ${LIB_DIR} ${LIB} -o $(NAME)
							@echo "\033[0;93m\n* $(NAME) program file was created in sanitize mode*\033[0m"

debug					:	fclean obj_debug $(OBJ_DIR_DEBUG) $(OBJECTS_DEBUG) lib
							@$(CC) -g $(CCFLAG) $(OBJECTS_DEBUG) ${LIB_DIR} ${LIB} -o $(NAME)
							@echo "\033[0;93m\n* $(NAME) program file was created in debug mode*\033[0m"

lib						:	
							@cd ${LIB_DIR} && make
cleanlib				:
							@cd ${LIB_DIR} && make clean
fcleanlib				:
							@cd ${LIB_DIR} && make fclean

obj						:
							@mkdir -p obj && cd obj && mkdir -p utils && mkdir -p built_in
							@echo "\033[0;92m\n* obj/utils created *\033[0m"

obj_debug				:
							@mkdir -p obj_debug && cd obj_debug && mkdir -p utils && mkdir -p built_in
							@echo "\033[0;92m\n* obj_debug/utils created *\033[0m"


.PHONY					:	all clean fclean re
