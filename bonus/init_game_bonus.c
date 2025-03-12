/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:32:49 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/03/12 12:16:06 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	clear_image(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx_ptr, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx_ptr, game->img_floor);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx_ptr, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx_ptr, game->img_exit);
	if (game->img_player)
		mlx_destroy_image(game->mlx_ptr, game->img_player);
	if (game->img_enemy)
		mlx_destroy_image(game->mlx_ptr, game->img_enemy);
}

static void	load_images(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, \
		"textures/wall.xpm", &game->img_size, &game->img_size);
	game->img_floor = mlx_xpm_file_to_image(game->mlx_ptr, \
		"textures/floor.xpm", &game->img_size, &game->img_size);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx_ptr, \
		"textures/collectible.xpm", &game->img_size, &game->img_size);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, \
		"textures/exit_close.xpm", &game->img_size, &game->img_size);
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr, \
		"textures/bonus/bunny_front.xpm", &game->img_size, &game->img_size);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx_ptr, \
		"textures/bonus/enemy.xpm", &game->img_size, &game->img_size);
}

static void	*put_img(t_game *game, size_t col, size_t row)
{
	void	*img;

	img = game->img_floor;
	if (game->map[row][col] == '1')
		img = game->img_wall;
	else if (game->map[row][col] == 'C')
		img = game->img_collectible;
	else if (game->map[row][col] == 'E')
		img = game->img_exit;
	else if (game->map[row][col] == 'P')
		img = game->img_player;
	else if (game->map[row][col] == 'Y')
		img = game->img_enemy;
	return (img);
}

void	draw_map(t_game *game)
{
	size_t	col;
	size_t	row;
	void	*img;

	row = 0;
	while (row < game->width)
	{
		col = 0;
		while (col < game->length)
		{
			img = put_img(game, col, row);
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
				img, col * 64, row * 64);
			col++;
		}
	row++;
	}
}

void	init_game(t_game *game)
{
	int	len;
	int	wid;

	len = game->length * 64;
	wid = game->width * 64;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		perror("Error\nFailed to initialize MiniLibX.\n");
		exit(1);
	}
	game->mlx_win = mlx_new_window(game->mlx_ptr, len, wid, "So Long");
	if (!game->mlx_win)
	{
		perror("Error\nFailed to create window.\n");
		exit(1);
	}
	load_images(game);
	draw_map(game);
	mlx_key_hook(game->mlx_win, handle_keypress, game);
	mlx_hook(game->mlx_win, 17, 0, close_game, game);
	mlx_loop(game->mlx_ptr);
}
