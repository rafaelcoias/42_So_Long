#include "../include/so_long.h"

static void init_menu_stats(t_game *game)
{
    game->menu.exit = 0;
    game->menu.test = 0;
    game->menu.play = 0;
}

static void check_arrows(t_game *game, int key)
{
    if (game->menu.test)
    {
        init_menu_stats(game);
        if (key == TOP)
            game->menu.exit = 1;
        else if (key == DOWN)
            game->menu.play = 1;
    }
    else if (game->menu.play)
    {
        init_menu_stats(game);
        if (key == TOP)
            game->menu.test = 1;
        else if (key == DOWN)
            game->menu.exit = 1;
    }
    else if (game->menu.exit)
    {
        init_menu_stats(game);
        if (key == TOP)
            game->menu.play = 1;
        else if (key == DOWN)
            game->menu.test = 1;
    }
}

static void handle_keypress(int key, t_game *game)
{
    if (key == ENTER && game->menu.exit)
    {
        mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
        exit(0);
    }
    else if (key == ENTER && game->menu.test)
    {
        mlx_destroy_window(game->mlx, game->win);
        init_game(MAP_TEST, game);
	    render_images(game);
	    do_game(game);
    }
    else if (key == ENTER && game->menu.play)
    {
        mlx_destroy_window(game->mlx, game->win);
        init_game(game->map.path, game);
        render_images(game);
	    do_game(game);
    }
    check_arrows(game, key);
}

void    do_menu_window(t_game *game)
{   
    if (game->window)
        mlx_destroy_window(game->mlx, game->win);
    game->width = 550;
    game->height = 550;
    init_window(game);
    mlx_put_image_to_window(game->mlx, game->window, game->img.menu_test,
			0, 0);
    mlx_hook(game.win, KeyPress, KeyPressMask, &handle_keypress, &game);
	mlx_loop(game.mlx);
}