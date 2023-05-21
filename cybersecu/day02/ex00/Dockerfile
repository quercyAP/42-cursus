FROM nginx

RUN apt-get update && apt-get install -y openssh-server tor
# RUN mkdir -p /root/.ssh
# RUN chmod 700 /root/.ssh
# RUN mkdir -p /root/.ssh/authorized_keys
# RUN chmod 600 /root/.ssh/authorized_keys

# COPY ~/.ssh/id_rsa.pub /root/.ssh/authorized_keys/id_rsa.pub

COPY nginx.conf /etc/nginx/nginx.conf
COPY sshd_config /etc/ssh/sshd_config
COPY torrc /etc/tor/torrc

RUN mkdir /var/lib/tor/hidden_service/ && chown -R debian-tor:debian-tor /var/lib/tor/hidden_service/

RUN mkdir -p /usr/share/nginx/html

COPY cybersite /usr/share/nginx/html/

EXPOSE 80 4242

RUN chmod 700 /var/lib/tor/hidden_service/

CMD service ssh start && service tor start && nginx -g 'daemon off;'
