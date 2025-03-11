/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:10:25 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/03/11 16:49:53 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	update_map(t_game *game, int new_x, int new_y)
{
	game->map[game->player_row][game->player_col] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_col = new_x;
	game->player_row = new_y;
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
		move_player(game, 0, -1);
	else if (keycode == 's' || keycode == 65364)
		move_player(game, 0, 1);
	else if (keycode == 'a' || keycode == 65361)
		move_player(game, -1, 0);
	else if (keycode == 'd' || keycode == 65363)
		move_player(game, 1, 0);
	return (0);
}
