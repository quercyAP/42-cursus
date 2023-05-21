# Variables
DOCKER_COMPOSE_FILE := docker-compose.yml
CONTAINER_ID := $(shell sudo docker-compose -f $(DOCKER_COMPOSE_FILE) ps -q nginx_tor)

# Cibles
build:
	sudo docker-compose -f $(DOCKER_COMPOSE_FILE) build

up:
	sudo docker-compose -f $(DOCKER_COMPOSE_FILE) up -d

shell:
	sudo docker-compose -f $(DOCKER_COMPOSE_FILE) exec mon_conteneur_ssh bash

ssh:
	sudo ssh -i ~/.ssh/id_rsa user@localhost -p 4242

url:
	sudo docker exec -it $(CONTAINER_ID) cat /var/lib/tor/hidden_service/hostname

down:
	sudo docker-compose -f $(DOCKER_COMPOSE_FILE) down

clean:
	sudo docker-compose -f $(DOCKER_COMPOSE_FILE) down --volumes --rmi all

.PHONY: build up shell down clean url

