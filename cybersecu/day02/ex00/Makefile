# Variables
DOCKER_COMPOSE_FILE := docker-compose.yml
CONTAINER_ID := $(shell docker-compose -f $(DOCKER_COMPOSE_FILE) ps -q nginx_tor)
IP_ADDRESS := $(shell docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' $(CONTAINER_ID))

# Cibles
build:
	docker-compose -f $(DOCKER_COMPOSE_FILE) build

up:
	docker-compose -f $(DOCKER_COMPOSE_FILE) up -d

shell:
	docker-compose -f $(DOCKER_COMPOSE_FILE) exec mon_conteneur_ssh bash

shell:
	docker exec -it $(CONTAINER_ID) bash

ssh:
	ssh -i ~/.ssh/id_rsa sshuser@localhost -p 4242 

url:
	docker exec -it $(CONTAINER_ID) cat /var/lib/tor/hidden_service/hostname

down:
	docker-compose -f $(DOCKER_COMPOSE_FILE) down

clean:
	docker-compose -f $(DOCKER_COMPOSE_FILE) down --volumes --rmi all

.PHONY: build up shell down clean url

