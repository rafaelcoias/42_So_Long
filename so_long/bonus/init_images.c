/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:16:09 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/28 22:21:46 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_images3(t_game *game)
{
	game->img.nbr = mlx_xpm_file_to_image(game->img.mlx, NBR_PATH,
			&game->img.width, &game->img.width);
	game->img.death1 = mlx_xpm_file_to_image(game->img.mlx, DEATH_1,
			&game->img.width, &game->img.width);
	game->img.death2 = mlx_xpm_file_to_image(game->img.mlx, DEATH_2,
			&game->img.width, &game->img.width);
	game->img.death3 = mlx_xpm_file_to_image(game->img.mlx, DEATH_3,
			&game->img.width, &game->img.width);
	game->img.death4 = mlx_xpm_file_to_image(game->img.mlx, DEATH_4,
			&game->img.width, &game->img.width);
	game->img.death5 = mlx_xpm_file_to_image(game->img.mlx, DEATH_5,
			&game->img.width, &game->img.width);
	game->img.water1 = mlx_xpm_file_to_image(game->img.mlx, WATER_1,
			&game->img.width, &game->img.width);
	game->img.water2 = mlx_xpm_file_to_image(game->img.mlx, WATER_2,
			&game->img.width, &game->img.width);
	game->img.water3 = mlx_xpm_file_to_image(game->img.mlx, WATER_3,
			&game->img.width, &game->img.width);
	game->img.water4 = mlx_xpm_file_to_image(game->img.mlx, WATER_4,
			&game->img.width, &game->img.width);
	game->img.water5 = mlx_xpm_file_to_image(game->img.mlx, WATER_5,
			&game->img.width, &game->img.width);
}

static void	init_images2(t_game *game)
{
	int	t_five;
	int	fivety;

	t_five = 25;
	fivety = 50;
	game->img.mov = mlx_xpm_file_to_image(game->img.mlx, MOV,
			&fivety, &t_five);
	game->img.es = mlx_xpm_file_to_image(game->img.mlx, ES,
			&fivety, &t_five);
	game->img.sco = mlx_xpm_file_to_image(game->img.mlx, SCO,
			&fivety, &t_five);
	game->img.re = mlx_xpm_file_to_image(game->img.mlx, RE,
			&fivety, &t_five);
	game->img.win = mlx_xpm_file_to_image(game->img.mlx, WIN,
			&game->menu.width, &game->menu.width);
	game->img.lose = mlx_xpm_file_to_image(game->img.mlx, LOSE,
			&game->menu.width, &game->menu.width);
	game->img.menu_test = mlx_xpm_file_to_image(game->img.mlx, MENU_TEST,
			&game->menu.width, &game->menu.width);
	game->img.menu_play = mlx_xpm_file_to_image(game->img.mlx, MENU_PLAY,
			&game->menu.width, &game->menu.width);
	game->img.menu_exit = mlx_xpm_file_to_image(game->img.mlx, MENU_EXIT,
			&game->menu.width, &game->menu.width);
	init_images3(game);
}

void	init_images(t_game *game)
{
	game->img.wall = mlx_xpm_file_to_image(game->img.mlx, WALL,
			&game->img.width, &game->img.width);
	game->img.exit = mlx_xpm_file_to_image(game->img.mlx, EXIT,
			&game->img.width, &game->img.width);
	game->img.back_ground = mlx_xpm_file_to_image(game->img.mlx, BACK_GRD,
			&game->img.width, &game->img.width);
	game->img.player = mlx_xpm_file_to_image(game->img.mlx, PLAYER,
			&game->img.width, &game->img.width);
	game->img.collectable = mlx_xpm_file_to_image(game->img.mlx, COLL,
			&game->img.width, &game->img.width);
	game->img.bonus = mlx_xpm_file_to_image(game->img.mlx, BONUS,
			&game->img.width, &game->img.width);
	game->img.player_w_coll = mlx_xpm_file_to_image(game->img.mlx,
			PLAYER_W_COLL, &game->img.width, &game->img.width);
	game->img.block = mlx_xpm_file_to_image(game->img.mlx, BLOCK,
			&game->img.width, &game->img.width);
	game->img.transport = mlx_xpm_file_to_image(game->img.mlx, TRANSPORT,
			&game->img.width, &game->img.width);
	game->img.line = mlx_xpm_file_to_image(game->img.mlx, LINE,
			&game->img.width, &game->img.width);
	init_images2(game);
}

void	delete_images2(t_game game)
{
	mlx_destroy_image(game.img.mlx, game.img.death1);
	mlx_destroy_image(game.img.mlx, game.img.death2);
	mlx_destroy_image(game.img.mlx, game.img.death3);
	mlx_destroy_image(game.img.mlx, game.img.death4);
	mlx_destroy_image(game.img.mlx, game.img.death5);
	mlx_destroy_image(game.img.mlx, game.img.water1);
	mlx_destroy_image(game.img.mlx, game.img.water2);
	mlx_destroy_image(game.img.mlx, game.img.water3);
	mlx_destroy_image(game.img.mlx, game.img.water4);
	mlx_destroy_image(game.img.mlx, game.img.water5);
}

void	delete_images(t_game game)
{
	mlx_destroy_image(game.img.mlx, game.img.wall);
	mlx_destroy_image(game.img.mlx, game.img.exit);
	mlx_destroy_image(game.img.mlx, game.img.back_ground);
	mlx_destroy_image(game.img.mlx, game.img.player);
	mlx_destroy_image(game.img.mlx, game.img.player_w_coll);
	mlx_destroy_image(game.img.mlx, game.img.collectable);
	mlx_destroy_image(game.img.mlx, game.img.bonus);
	mlx_destroy_image(game.img.mlx, game.img.block);
	mlx_destroy_image(game.img.mlx, game.img.transport);
	mlx_destroy_image(game.img.mlx, game.img.water);
	mlx_destroy_image(game.img.mlx, game.img.line);
	mlx_destroy_image(game.img.mlx, game.img.mov);
	mlx_destroy_image(game.img.mlx, game.img.es);
	mlx_destroy_image(game.img.mlx, game.img.win);
	mlx_destroy_image(game.img.mlx, game.img.lose);
	mlx_destroy_image(game.img.mlx, game.img.nbr);
	mlx_destroy_image(game.img.mlx, game.img.menu_test);
	mlx_destroy_image(game.img.mlx, game.img.menu_play);
	mlx_destroy_image(game.img.mlx, game.img.menu_exit);
	mlx_destroy_image(game.img.mlx, game.img.sco);
	mlx_destroy_image(game.img.mlx, game.img.re);
	delete_images2(game);
}
