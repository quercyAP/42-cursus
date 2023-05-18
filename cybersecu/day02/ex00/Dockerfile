FROM nginx

# Mise à jour des paquets et installation de openssh-server et tor
RUN apt-get update && apt-get install -y openssh-server tor

# Copie des fichiers de configuration
COPY nginx.conf /etc/nginx/nginx.conf
COPY sshd_config /etc/ssh/sshd_config
COPY torrc /etc/tor/torrc

# Création du répertoire pour le service caché Tor
RUN mkdir /var/lib/tor/hidden_service/ && chown -R debian-tor:debian-tor /var/lib/tor/hidden_service/

# Création du répertoire de travail pour nginx
RUN mkdir -p /usr/share/nginx/html

# Copie de la page d'accueil
COPY index.html /usr/share/nginx/html/index.html

# Ouverture du port 80 pour le serveur web et du port 4242 pour SSH
EXPOSE 80 4242

# Démarrage des services
CMD service ssh start && service tor start && nginx -g 'daemon off;'
