NAME = philo_one
CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEADERS = philo_one.h
HEADER_DIR = ./
HEADER = $(addprefix $(HEADER_DIR), $(HEADERS))
INCLUDE = -I $(HEADER_DIR)
LINK = -lpthread

SRCS =	philo_one.c philo_work.c print.c \
		utils.c validation.c
SRC_DIR = ./
SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJ = $(SRC:.c=.o)

.PHONY : all
all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(CFLAGS) $(INCLUDE) $(LINK) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
	gcc $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY : clean
clean :
	rm -rf $(OBJ)

.PHONY : fclean
fclean : clean
	rm -rf $(NAME)

.PHONY : re
re : fclean all
