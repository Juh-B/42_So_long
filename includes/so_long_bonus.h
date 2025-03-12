/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:41:28 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/03/11 15:40:45 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define DEFAULT "\033[0;39m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define WHITE "\033[0;97m"
# define BOLD_G "\033[1;92m"

# define ERROR_P "The map must contain ONLY 1 PLAYER.\nHowever, it includes "
# define ERROR_E "The map must contain ONLY 1 EXIT.\nHowever, it includes "
# define ERROR_ELEM "There is a wrong element in the map.\nExpected only: "

typedef struct s_game {
	size_t	length;
	size_t	width;
	size_t	moves;
	size_t	collectible;
	size_t	exit;
	size_t	player;
	int		player_col;
	int		player_row;
	char	**map;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_floor;
	void	*img_wall;
	void	*img_collectible;
	void	*img_player;
	void	*img_exit;
	int		img_size;
	char	direction;
}	t_game;

typedef struct s_verif_path {
	char	**map;
	size_t	cols;
	size_t	rows;
	int		found_exit;
	int		found_collectibles;
}	t_verif_path;

int		verif_map(char *map_file, t_game *game);
int		verif_map_struct(t_game *game);
int		verif_map_wall(t_game *game);
int		verif_map_path(t_game *game);
int		handle_keypress(int keycode, t_game *game);
int		ft_error_file(int code);
int		close_game(t_game *game);

void	initialize_path(t_verif_path *verif_path);
void	initialize_game(t_game *game);
void	init_game(t_game *game);
void	draw_map(t_game *game);
void	fr_free_game(t_game *game);

#endif
