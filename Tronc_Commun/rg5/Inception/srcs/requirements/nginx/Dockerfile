FROM debian:buster

RUN apt-get update && apt-get install -y \
    nginx \
    openssl


RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/localhost.key \
    -out /etc/ssl/certs/localhost.crt \
    -subj "/C=FR/ST=RHONE/L=LYON/O=42 lyon/OU=42/CN=lcompieg.42.fr/UID=lcompieg"

COPY ./conf/nginx.conf /etc/nginx/sites-available/default

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]