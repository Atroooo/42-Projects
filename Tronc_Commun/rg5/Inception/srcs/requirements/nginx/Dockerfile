FROM debian:buster

RUN apt-get update && apt-get install -y nginx
RUN apt-get install -y vim
RUN apt-get install -y openssl


CMD ["nginx", "-g", "daemon off;"]