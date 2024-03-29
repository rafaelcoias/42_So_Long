/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_menu_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:59:02 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/22 17:52:38 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_menu_stats(t_game *game)
{
	game->menu.exit = 0;
	game->menu.test = 0;
	game->menu.play = 0;
}

static void	check_arrows(t_game *game, int key)
{
	if (game->menu.test)
	{
		init_menu_stats(game);
		if (key == UP)
			game->menu.exit = 1;
		else if (key == DOWN)
			game->menu.play = 1;
	}
	else if (game->menu.play)
	{
		init_menu_stats(game);
		if (key == UP)
			game->menu.test = 1;
		else if (key == DOWN)
			game->menu.exit = 1;
	}
	else if (game->menu.exit)
	{
		init_menu_stats(game);
		if (key == UP)
			game->menu.play = 1;
		else if (key == DOWN)
			game->menu.test = 1;
	}
}

static void	handle_keypress2(int key, t_game *game)
{
	if (key == ESCAPE || (key == ENTER && game->menu.exit))
	{
		mlx_destroy_display(game->menu.mlx);
		mlx_destroy_window(game->menu.mlx, game->menu.window);	
		free(game->menu.mlx);
		exit_game(game);
	}
	check_arrows(game, key);
	if (game->menu.test)
		mlx_put_image_to_window(game->menu.mlx, game->menu.window,
			game->img.menu_test, 0, 0);
	if (game->menu.play)
		mlx_put_image_to_window(game->menu.mlx, game->menu.window,
			game->img.menu_play, 0, 0);
	if (game->menu.exit)
		mlx_put_image_to_window(game->menu.mlx, game->menu.window,
			game->img.menu_exit, 0, 0);
}

static int	handle_keypress(int key, t_game *game)
{
	if (!game->menu.mlx || !game->menu.in_menu
		|| (key != ENTER && key != ESCAPE && key != UP
		&& key != DOWN))
		return (0);
	if (key == ENTER && game->menu.test)
	{
		mlx_destroy_display(game->menu.mlx);
		mlx_destroy_window(game->menu.mlx, game->menu.window);
		free(game->menu.mlx);
		init_game(MAP_TEST, game);
		init_game_window(game);
		write_line(game);
		render_images(game);
		do_game(game);
	}
	else if (key == ENTER && game->menu.play)
	{
		mlx_destroy_display(game->menu.mlx);
		mlx_destroy_window(game->menu.mlx, game->menu.window);
		free(game->menu.mlx);
		init_game(game->map.path, game);
		init_game_window(game);
		write_line(game);
		render_images(game);
		do_game(game);
	}
	handle_keypress2(key, game);
	return (1);
}

void	do_menu_window(t_game *game)
{
	if (game->menu.in_end)
	{
		init_menu_stats(game);
		game->menu.test = 1;
		mlx_destroy_display(game->end_game.mlx);
		mlx_destroy_window(game->end_game.mlx, game->end_game.window);
		game->menu.in_end = 0;
		game->menu.in_menu = 1;
		game->menu.in_game = 0;
		if (game->map.map)
			free_map(game->map.map);
		init_menu_window(game);
	}
	else
		init_menu_window(game);
	mlx_put_image_to_window(game->menu.mlx, game->menu.window,
		game->img.menu_test, 0, 0);
	mlx_hook(game->menu.window, 02, (1L << 0), &handle_keypress, game);
	mlx_hook(game->menu.window, 17, 0, click_to_exit_menu, game);
	mlx_loop(game->menu.mlx);
}
