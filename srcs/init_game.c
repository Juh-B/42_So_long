/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:32:49 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/02/27 15:09:03 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"
// #include "../minilibx-linux/mlx.h"
#include "../includes/so_long.h"


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
	size_t	l;
	size_t	w;

	l = game->length;
	w = game->width;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("Error\nFailed to initialize MiniLibX");
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, l * 64, w * 64, "So Long");
	if (!game->win)
	{
		perror("Error\nFailed to create window");
		exit(1);
	}
}

void	load_images(t_game *game)
{
	game->img_size = 32;
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &game->img_size, &game->img_size);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &game->img_size, &game->img_size);
	game->img_coin = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm", &game->img_size, &game->img_size);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit_close.xpm", &game->img_size, &game->img_size);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &game->img_size, &game->img_size);
}

void	draw_map(t_game *game)
{
	for (size_t y = 0; y < game->width; y++)
	{
		for (size_t x = 0; x < game->length; x++)
		{
			char tile = game->map[y][x];
			void *img = game->img_floor;
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


void	move_player(t_game *game, int dx, int dy)
{
	int new_x = game->player_col + dx;
	int new_y = game->player_row + dy;

	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'E' && game->coins != 0)
		return ;
	if (game->map[new_y][new_x] == 'C')
		game->coins--;
	if (game->coins == 0)
		game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit_open.xpm", &game->img_size, &game->img_size);
	if (game->map[new_y][new_x] == 'E' && game->coins == 0)
		close_game(game);

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
