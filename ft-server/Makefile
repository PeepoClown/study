IMAGE = ft_server
NAME = test
USER = wupdegra

build :
	docker build -t $(IMAGE) ./

run :
	docker run -it -p 80:80 -p 443:443 --name $(NAME) $(IMAGE)

all : build run

tag :
	docker tag $(IMAGE) $(USER)/$(IMAGE):latest

stop :
	docker stop $(NAME)

remove : stop
	docker rm $(NAME)

clean : remove
	docker rmi $(IMAGE)

sh-cont :
	docker ps -a

sh-img :
	docker image ls

.PHONY : build run all tag stop remove clean sh-cont sh-img