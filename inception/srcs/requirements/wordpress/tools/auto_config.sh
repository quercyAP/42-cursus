#!/bin/bash

sleep 5

until mysqladmin ping -h"$SQL_HOST" -P"$SQL_PORT" --silent; do
    echo 'waiting for mysqld to be connectable...'
    sleep 2
done

echo "Mysql is conectable..."

if [ ! -f "/var/www/wordpress/wp-config.php" ]; then
    echo "WP Settings start..."
    mkdir -p /var/www/html
    mv /var/www/wp-config.php /var/www/html/
    wp --allow-root config create --dbname=$SQL_DATABASE --dbuser=$SQL_USER --dbpass=$SQL_PASSWORD \
                    --dbhost=mariadb:3306 --path='/var/www/wordpress'
fi
