NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Cores ANSI
GREEN  = \033[1;32m
RESET  = \033[0m

MLX_PATH = ./minilibx-linux
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11

OBJDIR = objs

SRCS = srcs/so_long.c srcs/verif_map.c srcs/verif_map_struct.c\
		srcs/verif_map_struct_utils.c srcs/init_game.c\
		srcs/error_and_free.c srcs/movimentation.c srcs/initialize.c

SRCS_BONUS = bonus/so_long.c bonus/verif_map.c bonus/verif_map_struct.c\
		bonus/verif_map_struct_utils.c bonus/init_game.c\
		bonus/error_and_free.c bonus/movimentation.c bonus/initialize.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
	OBJS = $(OBJS_BONUS)
endif

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@$(MAKE) -C $(MLX_PATH) --no-print-directory
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -I$(MLX_PATH) -o $(NAME) $(LIBFT)
	@echo "$(GREEN)So Long is Ready!$(RESET)"
# $(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

clean:
	rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all bonus

# NAME = so_long

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror -I$(MLX_PATH)

# LIBFT_DIR = libft
# LIBFT = $(LIBFT_DIR)/libft.a

# MLX_PATH = ./minilibx-linux
# MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11

# SRCS = srcs/so_long.c srcs/map_verify.c srcs/verif_map_struct.c

# OBJS = $(SRCS:.c=.o)

# all: $(NAME)

# $(NAME): $(OBJS)
# 	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
# 	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -I$(MLX_PATH) -o $(NAME) $(LIBFT)
# clean:
# 	rm -rf $(OBJS)
# 	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

# fclean: clean
# 	rm -f $(NAME)
# 	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

# re: fclean all