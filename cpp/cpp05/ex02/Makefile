SRCS = src/class/Bureaucrat.cpp \
	 src/class/Form.cpp \
	 src/class/PresidentialPardonForm.cpp \
	 src/class/RobotomyRequestForm.cpp \
	 src/class/ShrubberyCreationForm.cpp \
	 src/main.cpp \
	
OBJS = $(addprefix obj/,$(notdir $(SRCS:.cpp=.o)))
NAME = Bureaucrat
CC = c++
CFLAGS = -Wall -Wextra -Werror -Wno-unknown-pragmas -std=c++98
CPPFLAGS = -I include
LDFLAGS = -lncurses

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

obj/%.o: src/class/%.cpp | dir
	@echo "$(BLUE)Compiling $(notdir $<)...$(RESET)"
	@${CC} ${CPPFLAGS} ${CFLAGS} -c $< -o $@

obj/%.o: src/%.cpp | dir
	@echo "$(BLUE)Compiling $(notdir $<)...$(RESET)"
	@${CC} ${CPPFLAGS} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@echo "$(GREEN)Linking objects into executable ${NAME}...$(RESET)"
	@${CC} ${CFLAGS} ${CPPFLAGS} ${OBJS} -o ${NAME} ${LDFLAGS}

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
	@if [ ! -d "include" ]; then \
		echo "$(RED)Creating directory include...$(RESET)"; \
		mkdir -p include; \
	fi
	@if [ ! -d "include/class" ]; then \
		echo "$(RED)Creating directory include/class...$(RESET)"; \
		mkdir -p include/class; \
	fi
	@if [ ! -d "src" ]; then \
		echo "$(RED)Creating directory src...$(RESET)"; \
		mkdir -p src; \
	fi
	@if [ ! -d "src/class" ]; then \
		echo "$(RED)Creating directory src/class...$(RESET)"; \
		mkdir -p src/class; \
	fi

class:
	@echo "$(RED)Enter the names of your .cpp files (separated by spaces):$(RESET)"
	@read cpp_files; \
	for cpp_file in $$cpp_files; do \
		touch src/class/$$cpp_file.cpp; \
		touch include/class/$$cpp_file.hpp; \
		echo "$(RED)$$cpp_file.hpp, $$cpp_file.cpp created successfully$(RESET)"; \
	done
	
.h:
	@echo "$(RED)Enter the names of your .h files (separated by spaces):$(RESET)"
	@read h_files; \
	for h_file in $$h_files; do \
		touch include/$$h_file.h; \
		echo "$(RED)$$h_file.h created successfully$(RESET)"; \
	done

.cpp:
	@echo "$(RED)Enter the names of your cpp files (separated by spaces):$(RESET)"
	@read cpp_files; \
	for cpp_file in $$cpp_files; do \
		touch src/$$cpp_file.cpp; \
		echo "$(RED)$$cpp_file.cpp created successfully$(RESET)"; \
	done

add:
	@script="tools/update_srcs.sh"; \
	while [ ! -f $$script ] && [ ! $$PWD = "/" ]; do cd ..; done; \
	if [ -f $$script ]; then \
		./$$script "$(CURDIR)"; \
		echo "$(RED)SRCS File added successfully.$(RESET)"; \
	else \
		echo "$(RED)update_srcs.sh not found in parent directories$(RESET)"; \
	fi

fclean: clean
	@echo "$(YELLOW)Removing executable...$(RESET)"
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

