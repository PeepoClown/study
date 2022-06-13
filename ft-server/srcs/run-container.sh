#!/bin/bash

service php7.3-fpm start
service mysql restart
service nginx start

while true
do
	sleep 1000;
done