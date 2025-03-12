/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:10:25 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/03/11 16:50:38 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	update_map(t_game *game, int new_x, int new_y)
{
	char	*player_file;

	player_file = "textures/bonus/bunny_front.xpm";
	game->map[game->player_row][game->player_col] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_col = new_x;
	game->player_row = new_y;
	mlx_destroy_image(game->mlx_ptr, game->img_player);
	if (game->direction == 'W')
		player_file = "textures/bonus/bunny_back.xpm";
	else if (game->direction == 'S')
		player_file = "textures/bonus/bunny_front.xpm";
	else if (game->direction == 'A')
		player_file = "textures/bonus/bunny_left.xpm";
	else if (game->direction == 'D')
		player_file = "textures/bonus/bunny_rigth.xpm";
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr, \
		player_file, &game->img_size, &game->img_size);
	draw_map(game);
}

static void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_col + dx;
	new_y = game->player_row + dy;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'E' && game->collectible != 0)
		return ;
	if (game->map[new_y][new_x] == 'C')
		game->collectible--;
	if (game->collectible == 0)
	{
		mlx_destroy_image(game->mlx_ptr, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, \
			"textures/exit_open.xpm", &game->img_size, &game->img_size);
	}
	if (game->map[new_y][new_x] == 'E' && game->collectible == 0)
		close_game(game);
	game->moves++;
	ft_printf("Moves: %s%d\n%s", GREEN, game->moves, DEFAULT);
	update_map(game, new_x, new_y);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 'w' || keycode == 65362)
	{
		game->direction = 'W';
		move_player(game, 0, -1);
	}
	else if (keycode == 's' || keycode == 65364)
	{
		game->direction = 'S';
		move_player(game, 0, 1);
	}
	else if (keycode == 'a' || keycode == 65361)
	{
		game->direction = 'A';
		move_player(game, -1, 0);
	}
	else if (keycode == 'd' || keycode == 65363)
	{
		game->direction = 'D';
		move_player(game, 1, 0);
	}
	return (0);
}
