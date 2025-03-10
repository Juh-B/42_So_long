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
	if (game->mlx_ptr && game->mlx_win)
  {
  //   ft_printf("%sGame Finished!\n%sTotal Moves: %d\n%s", GREEN, WHITE, \
  //     		game->moves, DEFAULT);
    mlx_clear_window(game->mlx_ptr, game->mlx_win);
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
    // mlx_destroy_display(game->mlx_ptr);
	  // free(game->mlx_ptr);
  }
	exit(0);
  return (0);
}

// int	end_game(t_game *g)
// {
// 	if (g->map)
// 		ft_free_matrix(&g->map);
// 	if (g->map_bak)
// 		ft_free_matrix(&g->map_bak);
// 	free_sprites(g);
// 	ft_free_playerlist(g);
// 	printf("%sGame Finished!\n%sTotal Moves: %d\n\n%s", GREEN, \
// 		BLUE, g->n_moves, DEFAULT);
// 	mlx_clear_window(g->id, g->w_id);
// 	mlx_destroy_window(g->id, g->w_id);
// 	mlx_destroy_display(g->id);
// 	free(g->id);
// 	exit(0);
// 	return (0);
// }


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

void	load_images(t_game *game)
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
  size_t  col;
  size_t  row;
  void *img;

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
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, img, \
        col * 64, row * 64);
      col++;
		}
    row++;
	}
}

// void	move_player(t_game *game, int dx, int dy)
// {
// 	int new_x;
// 	int new_y;

//   new_x = game->player_col + dx;
// 	new_y = game->player_row + dy;
// 	if (game->map[new_y][new_x] == '1')
// 		return ;
// 	if (game->map[new_y][new_x] == 'E' && game->collectible != 0)
// 		return ;
// 	if (game->map[new_y][new_x] == 'C')
// 		game->collectible--;
// 	if (game->collectible == 0)
// 		game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, \
//       "textures/exit_open.xpm", &game->img_size, &game->img_size);
// 	if (game->map[new_y][new_x] == 'E' && game->collectible == 0)
// 		close_game(game);
//   game->moves++;
//   ft_printf("Total moves: %s%d\n%s", GREEN, game->moves, DEFAULT);
// 	game->map[game->player_row][game->player_col] = '0';
// 	game->map[new_y][new_x] = 'P';
// 	game->player_col = new_x;
// 	game->player_row = new_y;
// 	draw_map(game);
// }

// int	handle_keypress(int keycode, t_game *game)
// {
// 	if (keycode == 65307)
// 		close_game(game);
// 	else if (keycode == 'w' || keycode == 65362)
// 		move_player(game, 0, -1);
// 	else if (keycode == 's' || keycode == 65364)
// 		move_player(game, 0, 1);
// 	else if (keycode == 'a' || keycode == 65361)
// 		move_player(game, -1, 0);
// 	else if (keycode == 'd' || keycode == 65363)
// 		move_player(game, 1, 0);
// 	return (0);
// }
