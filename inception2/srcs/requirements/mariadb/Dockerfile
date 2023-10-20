FROM		debian:buster

RUN			apt-get update -y
RUN			apt-get upgrade -y

RUN			apt-get install -y mariadb-server

RUN			rm -f	/etc/mysql/my.cnf \
					/etc/my.cnf \
					~/my.cnf

RUN			mkdir -p /run/mysqld
RUN			mkdir -p /var/lib/mysql

RUN			chown -R mysql:mysql /var/lib/mysql
RUN			chmod 777 /var/lib/mysql

COPY		tools/auto_config.sh auto_config.sh
RUN			chmod +x auto_config.sh
ENTRYPOINT	["./auto_config.sh"]

EXPOSE		3306
