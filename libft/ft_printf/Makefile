NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
HEADER = include/
LIBFT_DIR = libft/

SRCS = ft_printf.c parse.c specifiers.c \
	   display_percent.c display_char.c display_str.c \
	   display_uint.c display_int.c display_hex.c \
	   display_ptr.c display_other.c
SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJS = $(SRCS:.c=.o)
OBJ_DIR = ./
OBJ = $(addprefix $(OBJ_DIR), $(OBJS))

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADER)ft_printf.h
	@gcc $(FLAGS) -I $(HEADER) -c $< -o $@

clean :
	@rm -rf $(OBJ)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean : clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY : all clean fclean re
