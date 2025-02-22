/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:55:38 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/02/12 17:58:33 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	verif_map_size(t_game *game)
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

int	inicialize_elem(t_game *game, char c)
{
	if (c != '0' && c != '1' && c != 'E' && c != 'P' && c != 'C')
		return (1);
	if (c == 'E')
		game->exit++;
	if (c == 'P')
		game->player++;
	if (c == 'C')
		game->coins++;
	return (0);
}

int	verif_map_elem(t_game *game)
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
	if (game->exit != 1 || game->player != 1 || game->coins < 1)
		return (1);
	return (0);
}

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

void  valid_path(char **map, int col, int row, t_verif_path *verif_path)
{
  if (col < 0 || col >= (int)verif_path->cols)
    return ;
  if (row < 0 || row >= (int)verif_path->rows)
    return ;
  if (map[row][col] == '1' || map[row][col] == 'V')
    return ;
  if (map[row][col] == 'E')
  {
    verif_path->found_exit = 1;
    printf("Found Exit\n");
  }
  if (map[row][col] == 'C')
  {
    printf("Found COINS\n");
    verif_path->found_coins--;
  }
  map[row][col] = 'V';
  valid_path(map, (col + 1), row, verif_path);
  valid_path(map, (col - 1), row, verif_path);
  valid_path(map, col, (row + 1), verif_path);
  valid_path(map, col, (row - 1), verif_path);
}

int	verif_map_path(t_game *game, t_verif_path *verif_path)
{
  verif_path->cols = game->length - 1;
  verif_path->rows = game->width - 1;
  verif_path->found_coins = game->coins;
  valid_path(verif_path->map, game->player_col, game->player_row, verif_path);
  if (verif_path->found_exit && verif_path->found_coins == 0)
    return (0);
  else
    return (1);
}

static int	ft_error_struct(int code)
{
  ft_printf("Error\n");
  if (code == 1)
    ft_printf("Wrong map's size.\n");
  else if (code == 2)
    ft_printf("The map must contain only 1 Player, 1 Exit and at least 1 Coin.\n");
  else if (code == 3)
    ft_printf("The map must be closed/surrounded by walls.\n");
  else if (code == 4)
    ft_printf("There isn't a valid path in the map.\n");
  return (1);
}

int	verif_map_struct(t_game *game, t_verif_path *verif_path)
{
	if (verif_map_size(game))
		return (ft_error_struct(1));
	if (verif_map_elem(game))
		return (ft_error_struct(2));
	if (verif_map_wall(game))
    return (ft_error_struct(3));
  if (verif_map_path(game, verif_path))
    return (ft_error_struct(4));
	return (0);
}
