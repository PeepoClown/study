NAME = libft.a
FLAGS = -Wall -Werror -Wextra
INCLUDE = ./

SRCS = ft_isdigit.c ft_putchar.c ft_strlen.c \
	   ft_putnstr.c ft_strdup.c ft_itoa.c \
	   ft_uitoa.c ft_hextoa.c ft_hexlltoa.c
SRC_DIR = ./
SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJS = $(SRC:.c=.o)
OBJ_DIR = ./
OBJ = $(addprefix $(OBJ_DIR), $(OBJS))

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(INCLUDE)libft.h
	@gcc $(FLAGS) -I $(INCLUDE) -c $< -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
