/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:56:46 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/02/27 15:30:57 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <mlx.h>
#include "../includes/so_long.h"
// #include "../minilibx-linux/mlx.h"

// void	create_map(t_list **lst, char *content)
// {
// 	t_list	*new_node;

// 	new_node = ft_lstnew(content);
// 	if (!new_node)
// 		return ;
// 	ft_lstadd_back(lst, new_node);
// }

// void	placeof_P_E(size_t col, size_t row, t_player *player, t_exit *exit, char c)
// {
// 	if (c == 'P')
// 	{
// 		player->col = col;
// 		player->row = row;
// 	}
// 	if (c == 'E')
// 	{
// 		exit->col = col;
// 		exit->row = row;
// 	}
// }


int	placeof_C(size_t col, size_t row, t_coins **coins)
{
  t_coins	*new_node;
  t_coins	*temp;

	new_node = malloc(sizeof(t_coins));
	if (!new_node)
		return (1);
	new_node->col = col;
	new_node->row = row;
	new_node->next = NULL;
	if (!coins)
		return (1);
	if (!*coins)
	{
		*coins = new_node;
		return (0);
	}
	temp = *coins;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
  return (0);
}


// void	create_stack(t_coins **coins, void *content)
// {
// 	t_coins	*new_node;

// 	new_node = malloc(sizeof(t_coins));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->x = x;
// 	new_node->y = y;
// 	new_node->next = NULL;

//   t_coins	*temp;

// 	if (!coins)
// 		return ;
// 	if (!*coins)
// 	{
// 		*coins = new_node;
// 		return ;
// 	}
// 	temp = *coins;
// 	while (temp->next)
// 		temp = temp->next;
// 	temp->next = new_node;
// }


int	elem_inic(t_game *game, t_player *player, t_exit *exit, t_coins **coins)
{
	int	col;
	int	row;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			// if (game->map[row][col] == 'P' || game->map[row][col] == 'E')
			// 	placeof_P_E(col, row, player, exit, game->map[row][col]);
			if (game->map[row][col] == 'C')
			{
				if (placeof_C(col, row, coins))
					return (1);
			}
			col++;
		}
		row++;
	}
	if (game->exit != 1 || game->player != 1 || game->coins < 1)
		return (1);
	return (0);
}

void	ft_free(t_coins *coins)
{
	t_coins	*temp;

	if (coins == NULL)
		return ;
	while (coins)
	{
		temp = coins->next;
		free(coins);
		coins = temp;
	}
}

void	fr_free_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

int	main(int argc, char **argv)
{
	// void	*mlx;
	// void	*mlx_win;

	t_game	game = {0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL, 0, NULL, NULL, NULL, NULL, NULL};
	// t_exit	exit = {0, 0, "false"};
	// t_player	player = {0, 0};
	// t_coins	*coins = NULL;
  // int   n;

	// printf("oi\n");
	// map_compl = NULL;
  // n = 0;
	if (argc == 2)
	{
		if (verif_map(argv[1], &game))
		{
			if (game.map)
				fr_free_game(&game);
			return (1);
		}
		// elem_inic(&game, &player, &exit, &coins);
		// if (elem_inic(&game, &player, &exit, &coins))
		// {
		// 	if (coins)
		// 		ft_free(coins);
		// 	return (1);
    	// }
	init_mlx(&game);
	
	load_images(&game);
	draw_map(&game);
	
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	
	mlx_loop(game.mlx);
	}
  // printf("Player. (%zu, %ld)\n", player.x, player.y);
  // printf("Exit. (%zu, %ld)\n", exit.x, exit.y);
  // while (coins)
  // {
  //   printf("coins. (%zu, %ld)\n", coins->x, coins->y);
  //   coins = coins->next;
  // }


	// // printf("blz\n");
	// printf("map. %s\n", game.map[0]);
	int i = 0;
	while (game.map[i])
	{
		printf("map. %s\n", game.map[i]);
		i++;
	}
	if (coins)
		ft_free(coins);
	if (game.map)
		fr_free_game(&game);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_game	game = {0, 0, 0, 0, 0, 0, 0, '\0'};
// 	if (argc != 2)
// 	{
// 		printf("Error\nUsage: ./so_long <map.ber>\n");
// 		return (1);
// 	}
// 	if (map_verify(argv[1], &game))
// 		return (1);

// 	init_mlx(&game);
// 	load_images(&game);
// 	draw_map(&game);

// 	mlx_key_hook(game.win, handle_keypress, &game);
// 	mlx_hook(game.win, 17, 0, close_game, &game); // Fecha ao clicar no "X"

// 	mlx_loop(game.mlx);
// 	return (0);
// }