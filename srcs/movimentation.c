#include "so_long.h"
#include "../minilibx-linux/mlx.h"

static void	move_player(t_game *game, int dx, int dy)
{
	int new_x;
	int new_y;

  new_x = game->player_col + dx;
	new_y = game->player_row + dy;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'E' && game->collectible != 0)
		return ;
	if (game->map[new_y][new_x] == 'C')
		game->collectible--;
	if (game->collectible == 0)
		game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, \
      "textures/exit_open.xpm", &game->img_size, &game->img_size);
	if (game->map[new_y][new_x] == 'E' && game->collectible == 0)
		close_game(game);
  game->moves++;
  ft_printf("Total moves: %s%d\n%s", GREEN, game->moves, DEFAULT);
	game->map[game->player_row][game->player_col] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_col = new_x;
	game->player_row = new_y;
	draw_map(game);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 'w' || keycode == 65362)
		move_player(game, 0, -1);
	else if (keycode == 's' || keycode == 65364)
		move_player(game, 0, 1);
	else if (keycode == 'a' || keycode == 65361)
		move_player(game, -1, 0);
	else if (keycode == 'd' || keycode == 65363)
		move_player(game, 1, 0);
	return (0);
}
