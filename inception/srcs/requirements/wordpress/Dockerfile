FROM debian:buster

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y wget vim php7.3 php-fpm php-mysql mariadb-client && \
    rm -rf /var/lib/apt/lists/*

RUN wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www

RUN cd /var/www && tar -xzf wordpress-6.0-fr_FR.tar.gz && rm wordpress-6.0-fr_FR.tar.gz

COPY conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY conf/wp_config.php /var/www

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

RUN chown -R www-data:www-data /var/www/wordpress

COPY tools/auto_config.sh /usr/local/bin/auto_config.sh
RUN chmod +x /usr/local/bin/auto_config.sh

RUN mkdir -p /run/php

ENTRYPOINT /usr/local/bin/auto_config.sh

CMD /usr/sbin/php-fpm7.3 -F

