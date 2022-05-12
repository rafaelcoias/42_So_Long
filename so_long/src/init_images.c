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

static void	init_images2(t_game *game)
{
	int	twenty;
	int	t_five;
	int	fivety;

	twenty = 20;
	t_five = 25;
	fivety = 50;
	game->img.semi_line = mlx_xpm_file_to_image(game->mlx, SEMI_LINE,
			&twenty, &t_five);
	game->img.mov = mlx_xpm_file_to_image(game->mlx, MOV,
			&fivety, &t_five);
	game->img.es = mlx_xpm_file_to_image(game->mlx, ES,
			&fivety, &t_five);
	game->img.win = mlx_xpm_file_to_image(game->mlx, WIN,
			&game->menu.width, &game->menu.width);
	game->img.lose = mlx_xpm_file_to_image(game->mlx, LOSE,
			&game->menu.width, &game->menu.width);
	game->img.menu_test = mlx_xpm_file_to_image(game->mlx, MENU_TEST,
			&game->menu.width, &game->menu.width);
	game->img.menu_play = mlx_xpm_file_to_image(game->mlx, MENU_PLAY,
			&game->menu.width, &game->menu.width);
	game->img.menu_exit = mlx_xpm_file_to_image(game->mlx, MENU_EXIT,
			&game->menu.width, &game->menu.width);
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
	game->img.bonus = mlx_xpm_file_to_image(game->mlx, BONUS,
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
	mlx_destroy_image(game.mlx, game.img.player_w_coll);
	mlx_destroy_image(game.mlx, game.img.collectable);
	mlx_destroy_image(game.mlx, game.img.bonus);
	mlx_destroy_image(game.mlx, game.img.block);
	mlx_destroy_image(game.mlx, game.img.transport);
	mlx_destroy_image(game.mlx, game.img.water);
	mlx_destroy_image(game.mlx, game.img.line);
	mlx_destroy_image(game.mlx, game.img.semi_line);
	mlx_destroy_image(game.mlx, game.img.mov);
	mlx_destroy_image(game.mlx, game.img.es);
	mlx_destroy_image(game.mlx, game.img.win);
	mlx_destroy_image(game.mlx, game.img.lose);
	mlx_destroy_image(game.mlx, game.img.nbr);
	mlx_destroy_image(game.mlx, game.img.menu_test);
	mlx_destroy_image(game.mlx, game.img.menu_play);
	mlx_destroy_image(game.mlx, game.img.menu_exit);
}
