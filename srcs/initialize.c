/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:00:41 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/03/12 12:05:30 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_game(t_game *game)
{
	game->length = 0;
	game->width = 0;
	game->moves = 0;
	game->collectible = 0;
	game->exit = 0;
	game->player = 0;
	game->player_col = 0;
	game->player_row = 0;
	game->map = NULL;
	game->mlx_ptr = NULL;
	game->mlx_win = NULL;
	game->img_floor = NULL;
	game->img_wall = NULL;
	game->img_collectible = NULL;
	game->img_player = NULL;
	game->img_exit = NULL;
	game->img_size = 64;
	game->end_game = 2;
}

void	initialize_path(t_verif_path *verif_path)
{
	verif_path->map = NULL;
	verif_path->cols = 0;
	verif_path->rows = 0;
	verif_path->found_exit = 0;
	verif_path->found_collectibles = 0;
}
