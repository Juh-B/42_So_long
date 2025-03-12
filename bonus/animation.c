#include "../includes/so_long_bonus.h"

void move_player(t_game *game)
{
    int new_x = game->player_col;
    int new_y = game->player_row;

    if (game->direction == 'W')
        new_y--;
    else if (game->direction == 'S')
        new_y++;
    else if (game->direction == 'A')
        new_x--;
    else if (game->direction == 'D')
        new_x++;

    if (game->map[new_y][new_x] != '1')
    {
        game->player_col = new_x;
        game->player_row = new_y;
        game->moves++;
    }
}

int update_game(t_game *game)
{
    game->current_frame = (game->current_frame + 1) % 4; // Alterna frames
    game->current_coin_frame = (game->current_coin_frame + 1) % 2;

    move_player(game); // Movimenta o personagem continuamente
    render_game(game);
    return (0);
}

int handle_keypress(int keycode, t_game *game)
{
    if (keycode == 119)
        game->direction = 'W';
    else if (keycode == 115)
        game->direction = 'S';
    else if (keycode == 97)
        game->direction = 'A';
    else if (keycode == 100)
        game->direction = 'D';
    else if (keycode == 65307)
        close_game(game);

    return (0);
}

void start_game(t_game *game)
{
    mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
    mlx_loop_hook(game->mlx, update_game, game);
    mlx_loop(game->mlx);
}
