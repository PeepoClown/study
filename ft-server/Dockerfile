FROM debian:buster
LABEL maintainer="wupdegra@student.21-school.ru"

# Update image
RUN apt-get update && \
	apt-get -y upgrade && \
	apt-get -y autoremove --purge && \
	apt-get clean

# Install packages
RUN apt-get -y install nginx \
					   mariadb-server \
					   php7.3 php-fpm php-mysql \
					   php-common php-cli php-mbstring \
					   openssl

# Configure nginx
RUN mkdir -p /var/www/wupdegra/html && \
	chown -R www-data:www-data /var/www/wupdegra && \
	rm -rf /etc/nginx/sites-enabled/default
COPY srcs/nginx.conf /etc/nginx/sites-available/wupdegra
RUN ln -s /etc/nginx/sites-available/wupdegra /etc/nginx/sites-enabled/
COPY srcs/info.php /var/www/wupdegra/html/

# Generate ssl certificate
RUN openssl req -x509 -nodes -days 30 -newkey rsa:2048 \
	-out /etc/ssl/certs/wupdegra.crt \
	-keyout /etc/ssl/certs/wupdegra.key \
	-subj '/C=RU/ST=Moscow/L=Moscow/O=ecole42/OU=21School/CN=wupdegra' && \
	chmod -R 755 /etc/ssl/certs/wupdegra*

WORKDIR /var/www/wupdegra

# Install phpMyAdmin
ADD https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz phpmyadmin.tar.gz
RUN tar -xzvf phpmyadmin.tar.gz && \
	mv phpMyAdmin-5.0.2-all-languages phpmyadmin && \
	chown -R www-data:www-data phpmyadmin && \
	rm -rf phpmyadmin.tar.gz
COPY srcs/phpmyadmin.php phpmyadmin/config.inc.php

# Install WordPress
COPY srcs/wordpress.tar.gz ./
RUN	tar -xzvf wordpress.tar.gz && \
	chown -R www-data:www-data wordpress && \
	rm -rf wordpress.tar.gz

# Init database
COPY srcs/mysql_init.sql ./
COPY srcs/wordpress.sql ./
RUN service mysql start && \
	mysql < mysql_init.sql && \
	mysql wordpress < wordpress.sql && \
	rm -rf mysql_init.sql && \
	rm -rf wordpress.sql

EXPOSE 80 443

WORKDIR /root
COPY srcs/run-container.sh ./
COPY srcs/autoindex_switch.sh ./
RUN chmod -R 755 run-container.sh && \
	chmod -R 755 autoindex_switch.sh
ENTRYPOINT ["bash", "run-container.sh"]