#ifndef SO_LONG_H
#define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include<fcntl.h>  // Para open()
# include<unistd.h> // Para read() e close()
# include<stdlib.h> // Para malloc()


typedef struct s_game {
    void *mlx;  // Ponteiro para MLX
    void *win;  // Ponteiro para a janela
} t_game;

void init_game(t_game *game);  // Protótipo da função para iniciar o jogo

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
