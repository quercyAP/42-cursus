FROM nginx

RUN apt-get update && apt-get install -y openssh-server tor

RUN groupadd sshgroup && \
	useradd -ms /bin/bash -g sshgroup sshuser && \
	mkdir -p /home/sshuser/.ssh
COPY id_rsa.pub /home/sshuser/.ssh/authorized_keys
RUN chown sshuser:sshgroup /home/sshuser/.ssh/authorized_keys && \
	chmod 600 /home/sshuser/.ssh/authorized_keys
RUN service ssh start


COPY nginx.conf /etc/nginx/nginx.conf
COPY sshd_config /etc/ssh/sshd_config
COPY torrc /etc/tor/torrc

RUN mkdir /var/lib/tor/hidden_service/ && chown -R debian-tor:debian-tor /var/lib/tor/hidden_service/

RUN mkdir -p /usr/share/nginx/html

COPY cybersite /usr/share/nginx/html/

EXPOSE 80 4242

RUN chmod 700 /var/lib/tor/hidden_service/

CMD service ssh start && service tor start && nginx -g 'daemon off;'
