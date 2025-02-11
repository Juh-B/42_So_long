/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:56:46 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/02/11 16:53:57 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include "../includes/so_long.h"

// void	create_map(t_list **lst, char *content)
// {
// 	t_list	*new_node;

// 	new_node = ft_lstnew(content);
// 	if (!new_node)
// 		return ;
// 	ft_lstadd_back(lst, new_node);
// }



int	main(int argc, char **argv)
{
	// void	*mlx;
	// void	*mlx_win;
	t_game	game = {0, 0, 0, 0, 0, 0};

	// printf("oi\n");
	// map_compl = NULL;
	if (argc == 2)
	{
		map_verify(argv[1], &game);
		// mlx = mlx_init();
		// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
		// mlx_loop(mlx);
	}
	// printf("blz\n");
	// printf("map. %s\n", game.map[0]);
	// int i = 0;
	// while (game.map[i])
	// {
	// 	printf("str. %s\n", game.map[i]);
	// 	i++;
	// }
	return (0);
}
