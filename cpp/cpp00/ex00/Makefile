SRCS = src/megaphone.cpp
OBJS = $(addprefix obj/,$(notdir $(SRCS:.cpp=.o)))
NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

obj/%.o: ${SRCS} | dir
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@echo "$(GREEN)Linking objects into executable ${NAME}...$(RESET)"
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

sanitize: ${NAME}
	@echo "$(GREEN)Linking objects into executable with sflags ${NAME}...$(RESET)"
	@${CC} ${SFLAGS} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	@echo "$(YELLOW)Removing object files...$(RESET)"
	@rm -f ${OBJS}

dir:
	@if [ ! -d "obj" ]; then \
		echo "$(RED)Creating directory obj...$(RESET)"; \
		mkdir -p obj; \
	fi
	@if [ ! -d "src" ]; then \
		echo "$(RED)Creating directory src...$(RESET)"; \
		mkdir -p src; \
	fi
	@if [ ! -d "src/class" ]; then \
		echo "$(RED)Creating directory src/class...$(RESET)"; \
		mkdir -p src/class; \
	fi

file:
	@echo "$(RED)Enter the names of your .cpp files (separated by spaces):$(RESET)"
	@read cpp_files; \
	for cpp_file in $$cpp_files; do \
		touch src/$$cpp_file.cpp; \
	done
	@echo "$(RED)Enter the names of your .hpp files (separated by spaces):$(RESET)"
	@read hpp_files; \
	for hpp_file in $$hpp_files; do \
		touch src/class/$$hpp_file.hpp; \
	done

fclean: clean
	@echo "$(YELLOW)Removing executable...$(RESET)"
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
