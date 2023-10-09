FROM debian:buster

RUN apt-get update && apt-get install -y nginx \
    && apt-get install -y vim \
    && apt-get install -y openssl

COPY /conf/nginx.conf /etc/nginx/sites-available/default.conf

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/private/nginx-selfsigned.key -out /etc/nginx/ssl/certs/nginx-selfsigned.crt

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]