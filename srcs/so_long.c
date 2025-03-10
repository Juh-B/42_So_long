/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:56:46 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/03/10 16:05:36 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
// #include <mlx.h>
// #include "../minilibx-linux/mlx.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_error_file(1);
		return (0);
	}
	initialize_game(&game);
	if (verif_map(argv[1], &game))
	{
		if (game.map)
			fr_free_game(&game);
		return (1);
	}
	init_game(&game);
	return (0);
}
