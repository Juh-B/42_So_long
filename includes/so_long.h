/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:41:28 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/02/26 18:35:06 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# include <fcntl.h>  // Para open()
# include <unistd.h> // Para read() e close()
# include <stdlib.h> // Para malloc()
# include <stdio.h>

// typedef struct s_player {
//     size_t col;
//     size_t row;
// } t_player;

// typedef struct s_coins{
//     size_t col;
//     size_t row;
//     // size_t coin_id;
//     struct s_coins	*next;
// } t_coins;

// typedef struct s_exit {
//     size_t  col;
//     size_t  row;
//     char    *open;
// } t_exit;

/* Color codes for ft_printf  */
# define DEFAULT "\033[0;39m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define WHITE "\033[0;97m"

# define BLUE "\033[0;94m"
# define GRAY "\033[0;90m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"

typedef struct s_game {
    size_t length;
    size_t width;
    size_t moves;
    size_t collectible;
    size_t exit;
    size_t player;
    int    player_col;
    int    player_row;
    char **map;
    void *mlx_ptr;
    void *mlx_win;
    void  *img_floor;
    void  *img_wall;
    void  *img_collectible;
    void  *img_player;
    void  *img_exit;
    int img_size;
  } t_game;

  typedef struct s_verif_path {
    char   **map;
    size_t cols;
    size_t rows;
    int    found_exit;
    int    found_collectibles;
  } t_verif_path;

  int	verif_map(char *map_file, t_game *game);
  int	verif_map_struct(t_game *game, t_verif_path *verif_path);
  int	verif_map_wall(t_game *game);
  int	verif_map_path(t_game *game, t_verif_path *verif_path);
  void	ft_free_map(t_verif_path *path);
  void	fr_free_game(t_game *game);

  void	init_game(t_game *game);
  int	close_game(t_game *game);
  int	handle_keypress(int keycode, t_game *game);
  void	load_images(t_game *game);
  void	draw_map(t_game *game);

  int	ft_error_file(void);
  void	fr_free_game(t_game *game);

#endif


// #ifndef SO_LONG_H
// # define SO_LONG_H

// # include<unistd.h>
// # include<stdlib.h>
// # include<limits.h>
// # include<stdio.h>
// # include<fcntl.h>
// # include "../minilibx-linux/mlx.h"

// typedef struct s_list
// {
// 	void	*mlx;
// 	void	*win;
// 	void	*bush;
// 	void	*fond;
// 	void	*poke;
// 	void	*npc;
// 	void	*npcstart;
// 	void	*npcmv;
// 	void	*npcleft;
// 	void	*npclmv;
// 	void	*npcright;
// 	void	*npcrmv;
// 	void	*npcback;
// 	void	*npcbmv;
// 	void	*imgexit;
// 	int		errors;
// 	int		moves;
// 	int		npccontrol;
// 	int		linecontrol;
// 	int		x;
// 	int		y;
// 	int		consum;
// 	int		ex;
// 	int		back;
// 	int		wall;
// 	int		player;
// 	int		enemy;
// 	int		height_l;
// 	int		width_l;
// 	char	*big_line;
// }	t_list;

// int		main(int argc, char **argv);
// int		init_data(t_list *d, char *map);

// #endif
