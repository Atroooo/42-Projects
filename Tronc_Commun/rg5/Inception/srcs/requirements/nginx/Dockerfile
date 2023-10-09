FROM debian:buster

RUN apt-get update && apt-get install -y nginx \
    && apt-get install -y vim
    && apt-get install -y openssl

COPY /conf/nginx.conf /etc/nginx/sites-available/default.conf

//Generer les cles SSL puis les colle dans un dossier securise

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]