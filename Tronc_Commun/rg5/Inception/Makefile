.PHONY: all build rebuild stop volumes fclean prune

all: volumes build up

build:
		sudo docker-compose -f srcs/docker-compose.yml --env-file srcs/.env build

up:
		sudo docker-compose -f srcs/docker-compose.yml --env-file srcs/.env up -d

stop:
		sudo docker-compose -f srcs/docker-compose.yml --env-file srcs/.env stop

volumes:
		sudo mkdir -p /home/lcompieg/data/wordpress
		sudo mkdir -p /home/lcompieg/data/mariadb

fclean:
		sudo docker-compose -f srcs/docker-compose.yml down -v --rmi all --remove-orphans
		sudo rm -rf /home/lcompieg/data/wordpress
		sudo rm -rf /home/lcompieg/data/mariadb

rebuild:
		sudo docker-compose -f srcs/docker-compose.yml --env-file srcs/.env build --no-cache

prune:	fclean
		sudo docker system prune -a

re: fclean rebuild all