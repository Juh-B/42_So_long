#include "so_long.h"
#include "../minilibx-linux/mlx.h"

int	close_game(t_game *game)
{
	if (game->map)
		fr_free_game(game);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	exit(0);
}


void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("Error\nFailed to initialize MiniLibX");
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, game->length * 64, game->width * 64, "So Long");
	if (!game->win)
	{
		perror("Error\nFailed to create window");
		exit(1);
	}
}

void	load_images(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &game->img_size, &game->img_size);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &game->img_size, &game->img_size);
	game->img_coin = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm", &game->img_size, &game->img_size);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &game->img_size, &game->img_size);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &game->img_size, &game->img_size);
}

void	draw_map(t_game *game)
{
	for (size_t y = 0; y < game->width; y++)
	{
		for (size_t x = 0; x < game->length; x++)
		{
			char tile = game->map[y][x];
			void *img = game->img_floor; // Fundo padrão
			if (tile == '1')
				img = game->img_wall;
			else if (tile == 'C')
				img = game->img_coin;
			else if (tile == 'E')
				img = game->img_exit;
			else if (tile == 'P')
				img = game->img_player;
			mlx_put_image_to_window(game->mlx, game->win, img, x * 64, y * 64);
		}
	}
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307) // Tecla ESC para fechar
		close_game(game);
	else if (keycode == 'w' || keycode == 119) // W ou seta para cima
		move_player(game, 0, -1);
	else if (keycode == 's' || keycode == 115) // S ou seta para baixo
		move_player(game, 0, 1);
	else if (keycode == 'a' || keycode == 97) // A ou seta para esquerda
		move_player(game, -1, 0);
	else if (keycode == 'd' || keycode == 100) // D ou seta para direita
		move_player(game, 1, 0);
	return (0);
}

void	move_player(t_game *game, int dx, int dy)
{
	int new_x = game->player_col + dx;
	int new_y = game->player_row + dy;

	if (game->map[new_y][new_x] == '1') // Paredes bloqueiam
		return;
	if (game->map[new_y][new_x] == 'C') // Coletando moeda
		game->coins--;
	if (game->map[new_y][new_x] == 'E' && game->coins == 0) // Saída liberada
		close_game(game);

	// Atualiza posição
	game->map[game->player_row][game->player_col] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_col = new_x;
	game->player_row = new_y;

	// Renderiza o mapa atualizado
	draw_map(game);
}
