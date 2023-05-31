#!/bin/bash

set

sleep 10

echo "SQL_DATABASE: ${SQL_DATABASE}"
echo "SQL_USER: ${SQL_USER}"
echo "SQL_PASSWORD: ${SQL_PASSWORD}"

if [ ! -f "/var/www/wordpress/wp-config.php" ]; then
    wp config create --allow-root --dbname=$SQL_DATABASE --dbuser=$SQL_USER --dbpass=$SQL_PASSWORD \
                    --dbhost=mariadb:3306 --path='/var/www/wordpress'
fi