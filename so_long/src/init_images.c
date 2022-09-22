/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:16:09 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/22 10:11:05 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_images3(t_game *game)
{
	int	i;
	char *str;
	
	i = -1;
	str = ft_strdup(NBR_PATH);
	while (++i != 10)
	{		
		game->img.nbrs[i] = mlx_xpm_file_to_image(game->img.mlx, str,
			&game->img.width, &game->img.width);		
		str[23]	= '0' + i;	
	}
	free(str);
	i = -1;
	str = ft_strdup(NBR_WIN_PATH);
	while (++i != 10)
	{		
		game->img.win_nbrs[i] = mlx_xpm_file_to_image(game->img.mlx, str,
			&game->img.width, &game->img.width);		
		str[23]	= '0' + i;	
	}
	free(str);
	i = 0;
	game->img.player[i] = mlx_xpm_file_to_image(game->img.mlx, PLAYER,
		&game->img.width, &game->img.width);
	str = ft_strdup(DEATH_1);
	while (++i != 6)
	{
		game->img.player[i] = mlx_xpm_file_to_image(game->img.mlx, str,
			&game->img.width, &game->img.width);
		str[32] = '0' + i;
	}
	free(str);
	i = -1;
	str = ft_strdup(WATER_1);
	while (++i != 5)
	{
		game->img.water[i] = mlx_xpm_file_to_image(game->img.mlx, str,
			&game->img.width, &game->img.width);
		str[32] = '0' + (i + 1);
	}
	free(str);
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

static void delete_images2(t_game game)
{
	int i;

	i = -1;
	while (++i != 10)
		mlx_destroy_image(game.img.mlx, game.img.nbrs[i]);
	i = -1;
	while (++i != 10)
		mlx_destroy_image(game.img.mlx, game.img.win_nbrs[i]);
	i = -1;
	while (++i != 6)
		mlx_destroy_image(game.img.mlx, game.img.player[i]);
	i = -1;
	while (++i != 5)
		mlx_destroy_image(game.img.mlx, game.img.water[i]);
}

void	delete_images(t_game game)
{
	mlx_destroy_image(game.img.mlx, game.img.wall);
	mlx_destroy_image(game.img.mlx, game.img.exit);
	mlx_destroy_image(game.img.mlx, game.img.back_ground);
	mlx_destroy_image(game.img.mlx, game.img.player_w_coll);
	mlx_destroy_image(game.img.mlx, game.img.collectable);
	mlx_destroy_image(game.img.mlx, game.img.bonus);
	mlx_destroy_image(game.img.mlx, game.img.block);
	mlx_destroy_image(game.img.mlx, game.img.transport);
	mlx_destroy_image(game.img.mlx, game.img.line);
	mlx_destroy_image(game.img.mlx, game.img.mov);
	mlx_destroy_image(game.img.mlx, game.img.es);
	mlx_destroy_image(game.img.mlx, game.img.win);
	mlx_destroy_image(game.img.mlx, game.img.lose);
	mlx_destroy_image(game.img.mlx, game.img.menu_test);
	mlx_destroy_image(game.img.mlx, game.img.menu_play);
	mlx_destroy_image(game.img.mlx, game.img.menu_exit);
	mlx_destroy_image(game.img.mlx, game.img.sco);
	mlx_destroy_image(game.img.mlx, game.img.re);
	delete_images2(game);
}
