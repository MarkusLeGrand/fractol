NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -I minilibx-linux -I includes
MLX_FLAGS = -L minilibx-linux -lmlx -lXext -lX11 -lm

SRCS = main.c \
       parsing.c \
       render.c \
       mandelbrot.c \
       julia.c \
       events.c \
       utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
