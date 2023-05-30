FROM debian:buster

RUN apt update -y && apt upgrade -y
RUN apt-get -y install wget
RUN apt install -y vim

RUN apt-get install -y php7.3\
    php-fpm\
    php-mysql\
    mariadb-client

RUN wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www

RUN cd /var/www && tar -xzf wordpress-6.0-fr_FR.tar.gz && rm wordpress-6.0-fr_FR.tar.gz

RUN rm /etc/php/7.3/cli/php.ini
COPY conf/php.ini /etc/php/7.3/cli/php.ini

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

RUN chown -R root:root /var/www/wordpress

COPY tools/auto_config.sh /usr/local/bin/auto_config.sh
RUN chmod +x /usr/local/bin/auto_config.sh

RUN mkdir -p /run/php

ENTRYPOINT ["/usr/local/bin/auto_config.sh"]

CMD ["/usr/sbin/php-fpm7.3 -F"]