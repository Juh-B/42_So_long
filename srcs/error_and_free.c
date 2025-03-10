#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"

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

int	ft_error_file(void)
{
	ft_printf("%sError\n%s", RED, DEFAULT);
	return (1);
}
