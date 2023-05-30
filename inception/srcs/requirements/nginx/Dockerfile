FROM debian:buster

RUN apt update -y && apt upgrade -y && apt install -y nginx
RUN apt install -y vim
RUN apt install -y curl
RUN apt install -y openssl

RUN mkdir -p /etc/nginx/ssl
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=ALS/L=Mulhouse/O=42/CN=glamazer.42.fr/UID=glamazer"

RUN mkdir -p /var/run/nginx
COPY conf/nginx.conf /etc/nginx/nginx.conf

RUN mkdir -p /usr/share/nginx/html
COPY tools/cybersite /usr/share/nginx/html/

EXPOSE 443

RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

CMD nginx -g 'daemon off;'