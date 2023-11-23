#!/bin/bash

# Start the MariaDB service inside the Docker container
mysqld_safe &

sleep 10

# Create the WordPress database
mysql -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;"

# Create the MySQL user for WordPress
mysql -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'localhost' IDENTIFIED BY '${SQL_PASSWORD}';"

# Grant privileges to the WordPress user on the WordPress database
mysql -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"

mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"

# Flush privilegess
mysql -e "FLUSH PRIVILEGES;"

# Stop the MariaDB server gracefully
mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown

# Start the MariaDB service inside the Docker container
mysqld_safe