FROM debian:buster

RUN apt-get update && apt-get install -y nginx \
    && apt-get install -y vim \
    && apt-get install -y openssl \
    && openssl req -x509 -nodes -days 365 -subj \
    "/C=CA/ST=QC/O=Company, Inc./CN=lcompieg.42.fr" \
    -addext "subjectAltName=DNS:lcompieg.42.fr" -newkey rsa:2048 -keyout \
    /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt; 

COPY /conf/default.conf /etc/nginx/sites-available/default.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]