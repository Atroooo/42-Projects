FROM debian:buster

RUN apt-get update && apt-get install -y nginx
RUN apt-get install -y vim
RUN apt-get install -y openssl

COPY /etc/ssl/certs/server.crt /etc/ssl/cert/server.key /tmp/certs/

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]