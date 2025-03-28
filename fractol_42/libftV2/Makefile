NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

INC = inc/
SRC_DIR = src/
OBJ_DIR = obj/

SRCS = $(wildcard $(SRC_DIR)ft_is/*.c) \
       $(wildcard $(SRC_DIR)ft_mem/*.c) \
       $(wildcard $(SRC_DIR)ft_put/*.c) \
       $(wildcard $(SRC_DIR)ft_to/*.c) \
       $(wildcard $(SRC_DIR)ft_str/*.c) \
       $(wildcard $(SRC_DIR)ft_lst/*.c) \
       $(wildcard $(SRC_DIR)printf_42/*.c)

OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
