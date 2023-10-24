#!/bin/sh

mkdir -p /home/glamazer/data/mariadb
mkdir -p /home/glamazer/data/wordpress

mysql_install_db --user=root --datadir=/var/lib/mysql
mysqld --user=root --datadir=/var/lib/mysql & sleep 5


mysql -u root -p$MARIADB_ROOT_PASSWORD -e "CREATE DATABASE IF NOT EXISTS \`${MARIADB_NAME}\`;"
mysql -u root -p$MARIADB_ROOT_PASSWORD -e "CREATE USER IF NOT EXISTS \`${MARIADB_USER}\`@'%' IDENTIFIED BY '${MARIADB_PASSWORD}';"
mysql -u root -p$MARIADB_ROOT_PASSWORD -e "GRANT ALL PRIVILEGES ON \`${MARIADB_NAME}\`.* TO \`${MARIADB_USER}\`@'%' IDENTIFIED BY '${MARIADB_PASSWORD}';"
mysql -u root -p$MARIADB_ROOT_PASSWORD -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PASSWORD}';"
mysql -u root -p$MARIADB_ROOT_PASSWORD -e "FLUSH PRIVILEGES;"

mysqladmin -u root -p$MARIADB_ROOT_PASSWORD shutdown
mysqld --user=root --datadir=/var/lib/mysql

