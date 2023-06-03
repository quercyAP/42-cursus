NAME			=	inception

SRCS_DIR		=	srcs

COMPOSE_FILE	=	${SRCS_DIR}/docker-compose.yml
ENV_FILE		=	${SRCS_DIR}/.env

FLAGS			=	-f ${COMPOSE_FILE} \
					-p ${NAME}

RED				=	"\033[1;31m"
GREEN			=	"\033[1;32m"
BLUE			=	"\033[1;36m"
WHITE			=	"\033[1;37m"
END				=	"\033[0;0m"

all: fclean build

build:
	@mkdir -p ~/data/wordpress ~/data/mariadb
	@docker compose ${FLAGS} up -d --build
	@echo ${GREEN}"ready"${WHITE}" - docker services are up"${END}

start:
	@docker compose ${FLAGS} start > /dev/null
	@echo ${GREEN}"ready"${WHITE}" - docker services have been started"${END}

stop:
	@docker compose ${FLAGS} stop > /dev/null
	@echo ${RED}"stopped"${WHITE}" - docker services have been stopped"${END}

status:
	@docker compose ${FLAGS} ps

clean:
	@sudo rm -rf /home/guigui/data/wordpress/* > /dev/null
	@sudo rm -rf /home/guigui/data/mariadb/* > /dev/null
	@echo ${BLUE}"info"${WHITE}" - cleaned docker data"${END}

fclean: clean
	@docker rmi -f nginx > /dev/null
	@docker rmi -f mariadb > /dev/null
	@docker rmi -f wordpress > /dev/null
	@echo ${BLUE}"info"${WHITE}" - cleaned docker images(s)"${END}
	@docker rm -f nginx > /dev/null
	@docker rm -f mariadb > /dev/null
	@docker rm -f wordpress > /dev/null
	@echo ${BLUE}"info"${WHITE}" - cleaned docker container(s)"${END}
	@docker volume rm -f inception_mariadb > /dev/null
	@docker volume rm -f inception_wordpress > /dev/null
	@echo ${BLUE}"info"${WHITE}" - cleaned docker volumes(s)"${END}
	@docker network rm inception > /dev/null
	@echo ${BLUE}"info"${WHITE}" - cleaned docker network(s)"${END}

re: stop fclean all

.PHONY: start stop status fclean clean re all