FROM debian:buster

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y curl wget gnupg

RUN apt-get update && apt-get install -y \
    php7.3 \
    php7.3-fpm \
    php7.3-mysql \
    php7.3-curl \
    php7.3-gd \
    php7.3-intl \
    php7.3-mbstring \
    php7.3-soap \
    php7.3-xml \
    php7.3-xmlrpc \
    php7.3-zip \
    mariadb-client \
    curl

RUN mkdir -p /run/php && chown -R www-data:www-data /run/php

RUN rm -f /etc/php/7.3/fpm/pool.d/www.conf
COPY conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

RUN mkdir -p /var/www/html && \
    getent group www-data || groupadd -g 82 www-data && \
    id -u www-data || useradd -u 82 -d /var/www -s /sbin/nologin -g www-data www-data && \
    chmod 777 -R /var/www/html && \
    chown -R www-data:www-data /var/www/html

COPY ./conf/wp-config.php ./
COPY ./tools/wp_script.sh ./
RUN chmod +x ./wp_script.sh
ENTRYPOINT ["./wp_script.sh"]

EXPOSE 9000
