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

// void	fr_free_game(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	while (game->map[i])
// 	{
// 		free(game->map[i]);
// 		i++;
// 	}
// 	free(game->map);
// }

int	main(int argc, char **argv)
{
	t_game	game = {0, 0, 0, 0, 0, 0, 0, 0, \
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 64};

  if (argc != 2)
  {
    ft_printf("%sError\n%sExpected: %s./so_long <map>.ber\n%s", \
      RED, DEFAULT, GREEN, DEFAULT);
    return (0);
  }
  if (verif_map(argv[1], &game))
  {
    if (game.map)
      fr_free_game(&game);
    return (1);
  }
  init_game(&game);
  // load_images(&game);
  // draw_map(&game);
  // mlx_key_hook(game.win, handle_keypress, &game);
  // mlx_hook(game.mlx_win, 17, 0, close_game, &game);
  // mlx_loop(game.mlx_ptr);
  return (0);
}
