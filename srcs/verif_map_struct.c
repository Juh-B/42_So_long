/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:55:38 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/03/10 15:57:33 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	verif_map_size(t_game *game)
{
	int	col;
	int	row;

	col = 0;
	while (game->map[0][col])
	{
		game->length++;
		col++;
	}
	row = 0;
	while (game->map[row])
	{
		game->width++;
		if (ft_strlen(game->map[row]) != game->length)
			return (1);
	row++;
	}
	return (0);
}

static int	inicialize_elem(t_game *game, char c)
{
	if (c != '0' && c != '1' && c != 'E' && c != 'P' && c != 'C')
		return (1);
	if (c == 'E')
		game->exit++;
	if (c == 'P')
		game->player++;
	if (c == 'C')
		game->collectible++;
	return (0);
}

static int	verif_map_elem(t_game *game)
{
	int	col;
	int	row;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (inicialize_elem(game, game->map[row][col]))
				return (1);
			if (game->map[row][col] == 'P')
			{
				game->player_col = col;
				game->player_row = row;
			}
				col++;
		}
		row++;
	}
	if (game->exit != 1 || game->player != 1 || game->collectible < 1)
		return (1);
	return (0);
}

static int	ft_error_struct(t_game *game, int code)
{
	ft_printf("%sError\n%s", RED, DEFAULT);
	if (code == 1)
		ft_printf("Wrong map's size.\n");
	else if (code == 2)
	{
		if (game->player != 1)
			ft_printf("%s%s%d.%s\n", ERROR_P, YELLOW, game->player, DEFAULT);
		else if (game->exit != 1)
			ft_printf("%s%s%d.%s\n", ERROR_E, YELLOW, game->exit, DEFAULT);
		else if (game->collectible < 1)
			ft_printf("The map must contain AT LEAST 1 COLLECTIBLE.\n");
	}
	else if (code == 3)
		ft_printf("The map must be surrounded by walls.\n");
	else if (code == 4)
		ft_printf("There isn't a valid path in the map.\n");
	return (1);
}

int	verif_map_struct(t_game *game)
{
	if (verif_map_size(game))
		return (ft_error_struct(game, 1));
	if (verif_map_elem(game))
		return (ft_error_struct(game, 2));
	if (verif_map_wall(game))
		return (ft_error_struct(game, 3));
	if (verif_map_path(game))
		return (ft_error_struct(game, 4));
	return (0);
}
