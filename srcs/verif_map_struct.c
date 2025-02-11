/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:55:38 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/02/11 18:12:13 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	verif_map_size(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
	{
		game->length++;
		i++;
	}
	i = 0;
	while (game->map[i])
	{
		game->width++;
		if (ft_strlen(game->map[i]) != game->length)
			return (1);
		i++;
	}
	return (0);
}

int	inicialize_elem(t_game *game, char c)
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

int	verif_map_elem(t_game *game)
{
	int	i;
	int	j;
	// char	c;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (inicialize_elem(game, game->map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	if (game->exit != 1 || game->player != 1 || game->collectible < 1)
		return (1);
	return (0);
}

int	verif_map_wall(t_game *game)
{
	int		x;
	int		y;
	int		x_max;
	int		y_max;
	char	c;

	x_max = (int)game->length - 1;
	y_max = game->width;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			c = game->map[y][x];
			if (x == 0 || x == x_max || y == 0 || y == y_max)
			{
				if (c != '1')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	verif_map_struct(t_game *game)
{
	if (verif_map_size(game))
		return (1);
	if (verif_map_elem(game))
		return (1);
	if (verif_map_wall(game))
		return (1);
	return (0);
}
