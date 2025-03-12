NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

GREEN  = \033[1;32m
RESET  = \033[0m

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_PATH = ./minilibx-linux
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11

SRCS = srcs/so_long.c srcs/verif_map.c srcs/verif_map_struct.c\
		srcs/verif_map_struct_utils.c srcs/init_game.c\
		srcs/error_and_free.c srcs/movements.c srcs/initialize.c

SRCS_BONUS = bonus/so_long_bonus.c bonus/verif_map_bonus.c bonus/verif_map_struct_bonus.c\
		bonus/verif_map_struct_utils_bonus.c bonus/init_game_bonus.c\
		bonus/error_and_free_bonus.c bonus/movements_bonus.c bonus/initialize_bonus.c

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

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all bonus
