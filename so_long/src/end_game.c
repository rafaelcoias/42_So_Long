#include "../include/so_long.h"

static void put_nbr(t_game *game, int width, int height, int nbr)
{
    int     i;
    int     j;
    char    before[30];
    char    after[4];
    char    path[35];

    before = ft_strcpy(before, "../include/images/win_numbers/");
    after = ft_strcpy(after, ".xpm");
    i = 0;
    j = 0;
    while (before[i])
        path[j++] = before[i++];
    if (nbr > 99)
        nbr = 0;
    path[j] = nbr + '0';
    i = 0;
    while (after[i])
        path[j++] = after[i++];
    game->img.nbr = mlx_xpm_file_to_image(game->mlx, path,
			&game->img.width, &game->img.height);
    mlx_put_image_to_window(game->mlx, game->window, game->img.nbr, width, 0);
}

static void write_score(t_game *game, int w, int h, int score)
{
    if (score < 10)
        put_nbr(game, w, h, 0);
    else
    {
        write_score(game, w - 30, h, score / 10);
        write_score(game, w, h, score % 10);
    }
}

static void write_moves(t_game *game, int w, int h, int nbr)
{
    if (nbr < 10)
    {
        put_nbr(game, w, h, 0);
        put_nbr(game, w + 30, h, nbr);
    }
    else if (nbr < 100)
    {
        put_nbr(game, w, h, nbr / 10);
        put_nbr(game, w + 30, h, nbr % 10);
    }
}

static void handle_keypress(int key, t_game *game)
{
    if (key == ESCAPE)
    {
        mlx_destroy_window(game->mlx, game->win);
        do_menu_window(game);
    }
}

void    end_game(t_game *game, int win)
{
    mlx_destroy_window(game->mlx, game->window);
	game->window = NULL;
    game->mlx = mlx_init();
	if (!game->mlx)
		error_msg(MLX_ERROR);
    if (win)
	    game->window = mlx_new_window(game->mlx, 550, 
            550, "WINNER");
    else
        game->window = mlx_new_window(game->mlx, 550, 
            550, "GAME OVER");
	if (!game->window)
		free(game->window);
    if (win)
        mlx_put_image_to_window(game->mlx, game->window, game->img.win,
			0, 0);
    else
        mlx_put_image_to_window(game->mlx, game->window, game->img.lose,
			0, 0);
    write_moves(game, 310, 355, game->count_moves);
    write_score(game, 330, 400, (game->map.count_ground / game->count_moves) * 1333);
    mlx_hook(game->win, KeyPress, KeyPressMask, &handle_keypress, game);
    mlx_loop(game->mlx);
}
