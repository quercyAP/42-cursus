FROM debian:buster

RUN apt update -y && apt upgrade -y
RUN apt-get install mariadb-server -y

COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/db_config.sh /usr/local/bin/db_config.sh
RUN chmod +x /usr/local/bin/db_config.sh

EXPOSE 3306

ENTRYPOINT ["/usr/local/bin/db_config.sh"]
