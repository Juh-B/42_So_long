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

// ---------------
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_linux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 11:06:26 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/27 20:02:06 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/game.h"
// #include <mlx.h>

// int	key_hook(int key, t_game *g)
// {
// 	if ((key == KEY_Q || key == KEY_ESC) && !g->pac_dying)
// 	{
// 		printf("\n%sYou quit the game early!%s\n\n", RED, DEFAULT);
// 		end_game(g);
// 	}
// 	if (key == KEY_R && !g->pac_dying)
// 		ft_reset(g);
// 	if ((key == KEY_UP || key == KEY_W) && g->next_dir != N && \
// 		!g->pac_dying)
// 		ft_newdirection(g, N);
// 	if ((key == KEY_DOWN || key == KEY_S) && g->next_dir != S && \
// 		!g->pac_dying)
// 		ft_newdirection(g, S);
// 	if ((key == KEY_RIGHT || key == KEY_D) && g->next_dir != E && \
// 		!g->pac_dying)
// 		ft_newdirection(g, E);
// 	if ((key == KEY_LEFT || key == KEY_A) && g->next_dir != W && \
// 		!g->pac_dying)
// 		ft_newdirection(g, W);
// 	return (0);
// }

// int	end_game(t_game *g)
// {
// 	if (g->map)
// 		ft_free_matrix(&g->map);
// 	if (g->map_bak)
// 		ft_free_matrix(&g->map_bak);
// 	free_sprites(g);
// 	ft_free_playerlist(g);
// 	printf("%sGame Finished!\n%sTotal Moves: %d\n\n%s", GREEN, \
// 		BLUE, g->n_moves, DEFAULT);
// 	mlx_clear_window(g->id, g->w_id);
// 	mlx_destroy_window(g->id, g->w_id);
// 	mlx_destroy_display(g->id);
// 	free(g->id);
// 	exit(0);
// 	return (0);
// }

// void	init_game(char **map, t_lay lay)
// {
// 	t_game	g;

// 	g.lay_bak = lay;
// 	g.n_collect_bak = lay.n_collect;
// 	g.map_bak = ft_dup_matrix(map);
// 	g.id = mlx_init();
// 	g.w_id = mlx_new_window(g.id, lay.n_col * SIZE, \
// 		lay.n_row * SIZE + 80, "Pac-Man");
// 	ft_newgame(&g, map, &lay);
// }

// void	ft_newgame(t_game *g, char **m, t_lay *lay)
// {
// 	g->n_frames = 1;
// 	g->n_moves = 0;
// 	g->width = lay->n_col * SIZE;
// 	g->height = lay->n_row * SIZE + 80;
// 	g->lay = lay;
// 	g->map = m;
// 	g->sprites = ft_initsprites(g);
// 	g->pl = NULL;
// 	g->gh = NULL;
// 	ft_playerlist(m, g);
// 	g->next_dir = 0;
// 	ft_load_ghosts(g);
// 	ft_load_pacmans(g);
// 	g->pac_dying = 0;
// 	g->panic_mode = 0;
// 	g->g_rate = GAME_RATE;
// 	g->redraw = 1;
// 	mlx_loop_hook(g->id, ft_update, (void *)g);
// 	mlx_hook(g->w_id, 17, 0, end_game, (void *)g);
// 	mlx_key_hook(g->w_id, key_hook, (void *)g);
// 	mlx_loop(g->id);
// }

// void	ft_check_game(t_game *g)
// {
// 	if (g->lay_bak.n_collect / 4 + 1 >= g->lay->n_collect && g->lay->n_gh)
// 	{
// 		if (!g->panic_mode)
// 			g->g_rate -= g->g_rate / 3;
// 		g->panic_mode = 1;
// 	}
// 	if (!(g->n_frames % (g->g_rate + (g->g_rate / 13))))
// 		ft_redraw_gh(g);
// 	if (!(g->n_frames % g->g_rate) && !g->pac_dying)
// 		ft_redraw_pac(g);
// 	if (g->pl->dir != ST && !g->pac_dying)
// 		ft_update_ghosts(g);
// 	if (g->next_dir)
// 		ft_next_dir(g);
// 	if (g->pac_dying && !(g->n_frames % (10 * g->g_rate)))
// 		ft_anim_pacdeath(g);
// 	if (!g->lay->n_collect && !g->lay->n_pl && !g->pac_dying)
// 	{
// 		printf("%sCONGRATULATIONS, YOU WIN!%s\n\n", GREEN, DEFAULT);
// 		end_game(g);
// 	}
// }
