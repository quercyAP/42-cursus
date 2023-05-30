# Variables
DOCKER_COMPOSE_FILE := srcs/docker-compose.yml

# Cibles
build:
	docker-compose -f $(DOCKER_COMPOSE_FILE) build

up:
	docker-compose -f $(DOCKER_COMPOSE_FILE) up -d

clean:
	docker-compose -f $(DOCKER_COMPOSE_FILE) down --volumes --rmi all

.PHONY: build up clean

