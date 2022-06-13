NAME = libasm.a
CFLAGS = -Wall -Wextra -Werror -g -O2 -no-pie -I ./src
NASMFLAGS = -f elf64

SRCS_LINUX = ft_write.s ft_read.s ft_strlen.s \
			 ft_strcpy.s ft_strcmp.s ft_strdup.s
SRC_DIR_LINUX = src/linux/
SRC_LINUX = $(addprefix $(SRC_DIR_LINUX), $(SRCS_LINUX))
OBJS_LINUX = $(SRC_LINUX:.s=.o)
OBJ_DIR_LINUX = ./
OBJ_LINUX = $(addprefix $(OBJ_DIR_LINUX), $(OBJS_LINUX))

SRCS_LINUX_BONUS = ft_list_push_front_bonus.s ft_list_sort_bonus.s \
				   ft_list_size.s ft_list_remove_if_bonus.s ft_atoi_base_bonus.s
SRC_DIR_LINUX_BONUS = src/linux/
SRC_LINUX_BONUS = $(addprefix $(SRC_DIR_LINUX_BONUS), $(SRCS_LINUX_BONUS))
OBJS_LINUX_BONUS = $(SRC_LINUX_BONUS:.s=.o)
OBJ_DIR_LINUX_BONUS = ./
OBJ_LINUX_BONUS = $(addprefix $(OBJ_DIR_LINUX_BONUS), $(OBJS_LINUX_BONUS))

all : $(NAME)

$(NAME) : $(OBJ_LINUX)
	@ar rc $(NAME) $(OBJ_LINUX)
	@ranlib $(NAME)

bonus : $(OBJ_LINUX) $(OBJ_LINUX_BONUS)
	@ar rc $(NAME) $(OBJ_LINUX) $(OBJ_LINUX_BONUS)
	@ranlib $(NAME)

%.o : %.s
	@nasm $(NASMFLAGS) $< -o $@

clean :
	@rm -rf $(OBJ_LINUX) $(OBJ_LINUX_BONUS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

test :
	@gcc $(CFLAGS) src/main.c -L. -lasm -o ./test
	@./test
	@rm -rf ./test

.PHONY : all clean fclean re test
