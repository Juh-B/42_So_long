NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
# -I$(MLX_PATH)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Cores ANSI
GREEN  = \033[1;32m
RESET  = \033[0m

# # MLX_PATH = ./minilibx-linux
# # MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11
# MLX_PATH = ./minilibx-alt
# MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -I$(MLX_PATH)

SRCS = srcs/so_long.c srcs/verif_map.c srcs/verif_map_struct.c\
      srcs/verif_map_struct_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)
	@echo "$(GREEN)So Long is Ready!$(RESET)"
# $(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -I$(MLX_PATH) -o $(NAME) $(LIBFT)

clean:
	rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all
