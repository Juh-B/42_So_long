/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:09:13 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/03/10 17:01:16 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

int	ft_error_file(int code)
{
	if (code == 1)
		ft_printf("%sError\n%sExpected: %s./so_long <map>.ber\n%s", \
			RED, DEFAULT, YELLOW, DEFAULT);
	else
		ft_printf("%sError\n%s", RED, DEFAULT);
	return (1);
}
