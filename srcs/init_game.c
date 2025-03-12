/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:32:49 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/03/12 12:04:18 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	clear_image(t_game *game)
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
}

int	close_game(t_game *game)
{
	if (game->map)
		fr_free_game(game);
	clear_image(game);
	if (game->mlx_ptr && game->mlx_win)
	{
		if (game->end_game == 1)
			ft_printf("\n%s--| Game completed! |--\n%sTotal Moves: %s%d\n\n%s", \
				GREEN, WHITE, BOLD_G, game->moves, DEFAULT);
		else if (game->end_game == 2)
			ft_printf("\n%s--| Game interrupted |--\n%sTotal Moves: %s%d\n\n%s", \
				YELLOW, WHITE, BOLD_G, game->moves, DEFAULT);
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(0);
	return (0);
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
		"textures/player.xpm", &game->img_size, &game->img_size);
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
			img = game->img_floor;
			if (game->map[row][col] == '1')
				img = game->img_wall;
			else if (game->map[row][col] == 'C')
				img = game->img_collectible;
			else if (game->map[row][col] == 'E')
				img = game->img_exit;
			else if (game->map[row][col] == 'P')
				img = game->img_player;
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
