FROM	debian:buster

RUN		apt-get update -y
RUN		apt-get upgrade -y

RUN		apt-get install -y nginx

RUN		mkdir -p /var/www/html/

COPY	conf/nginx.conf /etc/nginx/nginx.conf

RUN		apt-get install -y openssl
RUN		mkdir -p /etc/nginx/ssl

RUN		openssl req -newkey rsa:4096 -x509 -sha256 -nodes \
            -subj "/C=FR/ST=ALS/L=Mulhouse/O=42/OU=glamazer/CN=localhost" \
            -keyout /etc/nginx/ssl/inception.key -out /etc/nginx/ssl/inception.cert

EXPOSE	443
CMD		["nginx", "-g", "daemon off;"]
