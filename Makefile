NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(MLX_PATH)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_PATH = ./minilibx-linux
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11

SRCS = srcs/so_long.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -I$(MLX_PATH) -o $(NAME) $(LIBFT)
clean:
	rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all