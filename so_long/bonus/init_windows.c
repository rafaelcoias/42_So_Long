/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:22:15 by rade-sar          #+#    #+#             */
/*   Updated: 2022/05/12 16:24:46 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_menu_window(t_game *game)
{
	game->menu.mlx = mlx_init();
	if (!game->menu.mlx)
		error_msg(MLX_ERROR);
	game->menu.window = mlx_new_window(game->menu.mlx, game->menu.width,
			game->menu.width, "MENU");
	if (game->menu.window)
		return ;
	free(game->menu.window);
	error_msg(WIN_ERROR);
}

void	init_game_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_msg(MLX_ERROR);
	game->window = mlx_new_window(game->mlx, game->width,
			game->height, "THIN ICE");
	if (game->window)
		return ;
	free(game->window);
	error_msg(WIN_ERROR);
}

void	init_end_game_window(t_game *game)
{
	game->end_game.mlx = mlx_init();
	if (!game->end_game.mlx)
		error_msg(MLX_ERROR);
	if (game->end_game.win)
		game->end_game.window = mlx_new_window(game->end_game.mlx,
				game->end_game.width, game->end_game.width, "WINNER");
	else
		game->end_game.window = mlx_new_window(game->end_game.mlx,
				game->end_game.width, game->end_game.width, "GAME OVER");
	if (game->end_game.window)
		return ;
	free(game->end_game.window);
	error_msg(WIN_ERROR);
}

int	click_to_exit_game(t_game *game)
{
	delete_images(*game);
	if (game->mlx)
	{
		mlx_destroy_window(game->mlx, game->window);
		free(game->mlx);
	}
	else
	{
		mlx_destroy_window(game->end_game.mlx, game->end_game.window);
		free(game->mlx);
	}
	free(game->img.mlx);
	if (game->map.map)
		free_map(game->map.map);
	exit(0);
}

int	click_to_exit_menu(t_game *game)
{
	mlx_destroy_window(game->menu.mlx, game->menu.window);
	delete_images(*game);
	free(game->menu.mlx);
	free(game->img.mlx);
	exit(0);
}
