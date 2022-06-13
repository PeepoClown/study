NAME = libft.a
FLAGS = -Wall -Werror -Wextra
INCLUDE = ./

MEMORY_SRCS = ft_memccpy.c ft_memcpy.c ft_memset.c \
			  ft_memcmp.c ft_memchr.c ft_memmove.c
MEMORY_SRC_DIR = memory/
MEMORY_SRC = $(addprefix $(MEMORY_SRC_DIR), $(MEMORY_SRCS))
MEMORY_OBJS = $(MEMORY_SRC:.c=.o)
MEMORY_OBJDIR = ./
MEMORY_OBJ = $(addprefix $(MEMORY_OBJDIR), $(MEMORY_OBJS))

STRING_SRCS = ft_isprint.c ft_isalpha.c ft_isascii.c \
			  ft_isdigit.c ft_isalnum.c ft_strchr.c \
			  ft_strlen.c ft_strncmp.c ft_tolower.c \
			  ft_toupper.c ft_strrchr.c ft_strdup.c \
			  ft_strnstr.c ft_strlcat.c ft_strlcpy.c \
			  ft_substr.c ft_strjoin.c ft_strtrim.c \
			  ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
			  ft_putendl_fd.c ft_putnbr_fd.c ft_split.c \
			  ft_strcapitalize.c ft_strcat.c ft_strcmp.c \
			  ft_strcpy.c ft_str_is_lowercase.c ft_str_is_uppercase.c \
			  ft_strlowcase.c ft_strupcase.c ft_strncpy.c \
			  ft_strncat.c ft_strstr.c ft_islowcase.c \
			  ft_isupcase.c ft_strrev.c ft_strclr.c
STRING_SRC_DIR = string/
STRING_SRC = $(addprefix $(STRING_SRC_DIR), $(STRING_SRCS))
STRING_OBJS = $(STRING_SRC:.c=.o)
STRING_OBJDIR = ./
STRING_OBJ = $(addprefix $(STRING_OBJDIR), $(STRING_OBJS))

STD_SRCS = ft_atoi.c ft_bzero.c ft_itoa.c \
		   ft_calloc.c ft_max_int.c ft_min_int.c \
		   ft_swap_int.c
STD_SRC_DIR = std/
STD_SRC = $(addprefix $(STD_SRC_DIR), $(STD_SRCS))
STD_OBJS = $(STD_SRC:.c=.o)
STD_OBJDIR = ./
STD_OBJ = $(addprefix $(STD_OBJDIR), $(STD_OBJS))

GNL_SRCS = get_next_line_bonus.c
GNL_SRC_DIR = gnl/
GNL_SRC = $(addprefix $(GNL_SRC_DIR), $(GNL_SRCS))
GNL_OBJS = $(GNL_SRC:.c=.o)
GNL_OBJDIR = ./
GNL_OBJ = $(addprefix $(GNL_OBJDIR), $(GNL_OBJS))

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			 ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			 ft_lstclear.c ft_lstiter.c ft_lstmap.c \
			 ft_lstempty.c ft_lstat.c ft_lstremove.c
BONUS_SRC_DIR = list/
BONUS_SRC = $(addprefix $(BONUS_SRC_DIR), $(BONUS_SRCS))
BONUS_OBJS = $(BONUS_SRC:.c=.o)
BONUS_OBJ_DIR = ./
BONUS_OBJ = $(addprefix $(BONUS_OBJ_DIR), $(BONUS_OBJS))

all : $(NAME)

$(NAME) : bonus

bonus : $(MEMORY_OBJ) $(STRING_OBJ) $(STD_OBJ) $(GNL_OBJ) $(BONUS_OBJ)
	@$(MAKE) all -C ft_printf
	@cp ft_printf/libftprintf.a ./$(NAME)
	@ar rcs $(NAME) $(MEMORY_OBJ) $(STRING_OBJ) $(STD_OBJ) $(GNL_OBJ) $(BONUS_OBJ)

$(MEMORY_OBJDIR)%.o : $(MEMORY_SRCDIR)%.c $(INCLUDE)libft.h
	@gcc $(FLAGS) -I $(INCLUDE) -c $< -o $@

$(STRING_OBJDIR)%.o : $(STRING_SRCDIR)%.c $(INCLUDE)libft.h
	@gcc $(FLAGS) -I $(INCLUDE) -c $< -o $@

$(STD_OBJDIR)%.o : $(STD_SRCDIR)%.c $(INCLUDE)libft.h
	@gcc $(FLAGS) -I $(INCLUDE) -c $< -o $@

$(GNL_OBJDIR)%.o : $(GNL_SRCDIR)%.c $(INCLUDE)libft.h
	@gcc $(FLAGS) -I $(INCLUDE) -c $< -o $@

$(BONUS_OBJ_DIR)%.o : $(BONUS_SRC_DIR)%.c $(INCLUDE)libft.h
	@gcc $(FLAGS) -I $(INCLUDE) -c $< -o $@

clean :
	@$(MAKE) clean -C ft_printf
	@rm -rf $(MEMORY_OBJ) $(STRING_OBJ) $(STD_OBJ) $(BONUS_OBJ) $(GNL_OBJ)

fclean : clean
	@$(MAKE) fclean -C ft_printf
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
