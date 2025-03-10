/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_struct_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:55:38 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/03/10 16:04:22 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	verif_map_wall(t_game *game)
{
	int		col;
	int		row;
	int		col_max;
	int		row_max;
	char	c;

	col_max = game->length - 1;
	row_max = game->width - 1;
	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			c = game->map[row][col];
			if (col == 0 || col == col_max || row == 0 || row == row_max)
			{
				if (c != '1')
					return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}

static void	valid_path(char **map, int col, int row, t_verif_path *verif_path)
{
	if (col < 0 || col >= (int)verif_path->cols)
		return ;
	if (row < 0 || row >= (int)verif_path->rows)
		return ;
	if (map[row][col] == '1' || map[row][col] == 'V')
		return ;
	if (map[row][col] == 'E')
		verif_path->found_exit = 1;
	if (map[row][col] == 'C')
		verif_path->found_collectibles--;
	map[row][col] = 'V';
	valid_path(map, (col + 1), row, verif_path);
	valid_path(map, (col - 1), row, verif_path);
	valid_path(map, col, (row + 1), verif_path);
	valid_path(map, col, (row - 1), verif_path);
}

void	ft_free_path(t_verif_path *path)
{
	int	i;

	i = 0;
	while (path->map[i])
	{
		free(path->map[i]);
		i++;
	}
	free(path->map);
}

int	map_path(t_game *game, t_verif_path *verif_path)
{
	int	row;
	int	row_len;

	row_len = game->width + 1;
	verif_path->map = malloc(row_len * sizeof(char *));
	if (!verif_path->map)
		return (1);
	row = 0;
	while (game->map[row])
	{
		verif_path->map[row] = ft_strdup(game->map[row]);
		if (!verif_path->map[row])
		{
			ft_free_path(verif_path);
			return (1);
		}
		row++;
	}
	verif_path->map[row] = NULL;
	return (0);
}

int	verif_map_path(t_game *game)
{
	t_verif_path	verif_path;
	
	initialize_path(&verif_path);
	if (map_path(game, &verif_path))
		return (1);
	verif_path.cols = game->length - 1;
	verif_path.rows = game->width - 1;
	verif_path.found_collectibles = game->collectible;
	valid_path(verif_path.map, game->player_col, game->player_row, &verif_path);
	ft_free_path(&verif_path);
	if (verif_path.found_exit && verif_path.found_collectibles == 0)
		return (0);
	else
		return (1);
}
