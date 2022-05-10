#include "../include/so_long.h"

void    put_nbr(t_game *game, int width, int nbr)
{
    int     i;
    int     j;
    char    before[26];
    char    after[4];
    char    path[31];

    before = "../include/images/numbers/";
    after = ".xpm";
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

void    write_move_number(t_game *game, int width, int nbr)
{
    if (nbr < 10)
    {
        put_nbr(game, width, 0);
        put_nbr(game, width + 15, game->count_moves);
    }
    else if (nbr < 100)
    {
        put_nbr(game, width, nbr / 10);
        put_nbr(game, width + 15, nbr % 10);
    }
}

void    write_moves(t_game *game)
{
    int width;
    int i;

    mlx_put_image_to_window(game->mlx, game->window, game->img.line, 0, 0);
    mlx_put_image_to_window(game->mlx, game->window, game->img.mov, 50, 0);
    mlx_put_image_to_window(game->mlx, game->window, game->img.es, 100, 0);
    write_move_number(game, 150, game->count_moves);
    game->img.semi_line = mlx_xpm_file_to_image(game->mlx, SEMI_LINE,
	    &game->img.width, &game->img.height);
    mlx_put_image_to_window(game->mlx, game->window, game->img.semi_line,
		xy[0], xy[1]);
    width = 200;
    i = 3;
    while (game->map.map[++i])
    {
        mlx_put_image_to_window(game->mlx, game->window, game->img.line,
			width, 0);
        width += PIXEL_SIZE;
    }
}

static void put_image(t_game *game, int xy[2], int i, int j)
{
    if (game->map.map[i][j] == '1')
        mlx_put_image_to_window(game->mlx, game->window, game->img.wall,
			xy[0], xy[1]);
    else if (game->map.map[i][j] == '0')
        mlx_put_image_to_window(game->mlx, game->window, game->img.back_ground,
			xy[0], xy[1]);
    else if (game->map.map[i][j] == 'C')
        mlx_put_image_to_window(game->mlx, game->window, game->img.collectable,
			xy[0], xy[1]);
    else if (game->map.map[i][j] == 'P' && game->has_coll == 0)
        mlx_put_image_to_window(game->mlx, game->window, game->img.player,
			xy[0], xy[1]);
    else if (game->map.map[i][j] == 'P' && game->has_coll == 1)
        mlx_put_image_to_window(game->mlx, game->window, game->img.player_w_coll,
			xy[0], xy[1]);
    else if (game->map.map[i][j] == 'B')
        mlx_put_image_to_window(game->mlx, game->window, game->img.block,
			xy[0], xy[1]);
    else if (game->map.map[i][j] == 'A')
        mlx_put_image_to_window(game->mlx, game->window, game->img.water,
			xy[0], xy[1]);
    else if (game->map.map[i][j] == 'T')
        mlx_put_image_to_window(game->mlx, game->window, game->img.transport,
			xy[0], xy[1]);
}

void    render_images(t_game *game)
{
    int     i;
    int     j;
    int     width;
    int     height;
    int     xy[2];

    i = -1;
    j = -1;
    width = 0;
    height = 25;
    if (!game->window)
        error_msg(WIN_ERROR);
    write_moves(game);
    while (game->map.map[++i]) {
        j = -1;
        width = 0;
        while (game->map.map[i][++j]) {
            xy[0] = width;
            xy[1] = height;
            put_image(game, xy, i, j);
            width += PIXEL_SIZE;
        }
        height += PIXEL_SIZE;
    }
}