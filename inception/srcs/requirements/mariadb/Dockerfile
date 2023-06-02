FROM debian:buster

RUN apt update -y && apt upgrade -y
RUN apt-get install mariadb-server -y

EXPOSE 3306

RUN mkdir -p /var/run/mysqld \
    && chown -R mysql:mysql /var/run/mysqld \
    && chmod 777 /var/run/mysqld

COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/db_config.sh /usr/local/bin/db_config.sh
RUN chmod +x /usr/local/bin/db_config.sh

ENTRYPOINT /usr/local/bin/db_config.sh
