/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:10:25 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/03/12 12:19:14 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
		else if (game->end_game == 3)
			ft_printf("\n%s--| Game over |--\n%sTotal Moves: %s%d\n\n%s", \
				RED, WHITE, BOLD_G, game->moves, DEFAULT);
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(0);
	return (0);
}

static void	ending_game(t_game *game, char c)
{
	if (c == 'E' && game->collectible == 0)
		game->end_game = 1;
	if (c == 'Y')
		game->end_game = 3;
	close_game(game);
}

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
	int		new_x;
	int		new_y;
	char	c;

	new_x = game->player_col + dx;
	new_y = game->player_row + dy;
	c = game->map[new_y][new_x];
	if (c == '1')
		return ;
	if (c == 'E' && game->collectible != 0)
		return ;
	if (c == 'C')
		game->collectible--;
	if (game->collectible == 0)
	{
		mlx_destroy_image(game->mlx_ptr, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, \
			"textures/exit_open.xpm", &game->img_size, &game->img_size);
	}
	game->moves++;
	if (c == 'Y' || (c == 'E' && game->collectible == 0))
		ending_game(game, c);
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
