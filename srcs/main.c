#include "../includes/so_long.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

void init_game(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        write(2, "Error: Failed to initialize MiniLibX\n", 37);
        exit(EXIT_FAILURE);
    }
    game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");
    if (!game->win)
    {
        write(2, "Error: Failed to create window\n", 31);
        exit(EXIT_FAILURE);
    }
}

int handle_keypress(int keycode, t_game *game)
{
    if (keycode == 65307) // Tecla ESC no X11 (Linux)
    {
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    }
    return (0);
}

int main(void)
{
    t_game game;

    init_game(&game);

    mlx_key_hook(game.win, handle_keypress, &game);
    mlx_loop(game.mlx);

    return (0);
}

// void	read_map(char *map, t_list *d)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open(map, O_RDONLY);
// 	if (fd < 0)
// 		ft_free(d);
// 	d->linecontrol = 2;
// 	while (d->linecontrol != 1)
// 	{
// 		d->height_l++;
// 		line = get_next_line(fd);
// 		if (!line)
// 			ft_error(d, 9);
// 		if (d->linecontrol == 2)
// 			d->width_l = ft_strlen(line);
// 		check_line_break(line, d);
// 		if (ft_strlen(line) + d->linecontrol != d->width_l)
// 			ft_error(d, 7);
// 		d->big_line = ft_strjoin(d->big_line, line);
// 		if (line)
// 			free(line);
// 	}
// 	close(fd);
// 	check_fst_line(d);
// 	checkline(d);
// }

// int	init_data(t_list *d, char *map)
// {
// 	d->moves = 0;
// 	check_map_extension(map, d);
// 	read_map(map, d);
// 	init_img(d);
// 	d->win = mlx_new_window(d->mlx, d->x, d->y, "so_long");
// 	print_map(d);
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	t_list	*d;

// 	if (argc != 2)
// 	{
// 		write(1, "Wrong number of args.\n", 22);
// 		return (0);
// 	}
// 	d = ft_calloc(1, sizeof(t_list));
// 	if (!d)
// 		return (0);
// 	d->mlx = mlx_init();
// 	init_data(d, argv[1]);
// 	mlx_key_hook(d->win, key_press, d);
// 	mlx_hook(d->win, 17, 0, ft_free, d);
// 	mlx_loop(d->mlx);
// 	ft_free(d);
// 	return (0);
// }
