/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:16:09 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/28 22:21:46 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_msg(MLX_ERROR);
	game->window = mlx_new_window(game->mlx, game->width, game->height, TITLE);
	if (!game->window)
		free(game->window);
}

static void	init_images2(t_game *game)
{
	game->img.mov = mlx_xpm_file_to_image(game->mlx, MOV,
			&game->img.width, &game->img.height);
	game->img.es = mlx_xpm_file_to_image(game->mlx, ES,
			&game->img.width, &game->img.height);
	game->img.win = mlx_xpm_file_to_image(game->mlx, WIN,
			&game->img.width, &game->img.height);
	game->img.lose = mlx_xpm_file_to_image(game->mlx, LOSE,
			&game->img.width, &game->img.height);
}

void	init_images(t_game *game)
{
	game->img.wall = mlx_xpm_file_to_image(game->mlx, WALL,
			&game->img.width, &game->img.height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, EXIT,
			&game->img.width, &game->img.height);
	game->img.back_ground = mlx_xpm_file_to_image(game->mlx, BACK_GRD,
			&game->img.width, &game->img.height);
	game->img.player = mlx_xpm_file_to_image(game->mlx, PLAYER,
			&game->img.width, &game->img.height);
	game->img.collectable = mlx_xpm_file_to_image(game->mlx, COLL,
			&game->img.width, &game->img.height);
	game->img.player_w_coll = mlx_xpm_file_to_image(game->mlx, PLAYER_W_COLL,
			&game->img.width, &game->img.height);
	game->img.block = mlx_xpm_file_to_image(game->mlx, BLOCK,
			&game->img.width, &game->img.height);
	game->img.transport = mlx_xpm_file_to_image(game->mlx, TRANSPORT,
			&game->img.width, &game->img.height);
	game->img.water = mlx_xpm_file_to_image(game->mlx, WATER,
			&game->img.width, &game->img.height);
	game->img.line = mlx_xpm_file_to_image(game->mlx, LINE,
			&game->img.width, &game->img.height);
	init_images2(game);
}

void	delete_images(t_game game)
{
	mlx_destroy_image(game.mlx, game.img.wall);
	mlx_destroy_image(game.mlx, game.img.exit);
	mlx_destroy_image(game.mlx, game.img.back_ground);
	mlx_destroy_image(game.mlx, game.img.player);
	mlx_destroy_image(game.mlx, game.img.collectable);
}
