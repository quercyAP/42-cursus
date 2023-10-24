NAME			=	inception

SRCS_DIR		=	srcs

COMPOSE_FILE	=	${SRCS_DIR}/docker-compose.yml
ENV_FILE		=	${SRCS_DIR}/.env

FLAGS			=	-f ${COMPOSE_FILE} \
					-p ${NAME}

all: build

build:
	@mkdir -p ~/data/wordpress ~/data/mariadb
	@docker compose ${FLAGS} up -d --build

start:
	@docker compose ${FLAGS} start > /dev/null

stop:
	@docker compose ${FLAGS} stop > /dev/null

status:
	@docker compose ${FLAGS} ps

clean:
	@rm -rf /home/glamazer/data/wordpress/* > /dev/null
	@rm -rf /home/glamazer/data/mariadb/* > /dev/null

fclean: clean
	@docker system prune

re: stop fclean all

.PHONY: start stop status fclean clean re all