/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:21:05 by rade-sar          #+#    #+#             */
/*   Updated: 2022/05/20 23:24:03 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	do_death_animation(t_game *game)
{
	if (!game->end_game.death)
		return ;
	if (game->end_game.time_death < 10)
		game->img.player = mlx_xpm_file_to_image(game->img.mlx, DEATH_1,
				&game->img.width, &game->img.width);
	else if (game->end_game.time_death < 20)
		game->img.player = mlx_xpm_file_to_image(game->img.mlx, DEATH_2,
				&game->img.width, &game->img.width);
	else if (game->end_game.time_death < 30)
		game->img.player = mlx_xpm_file_to_image(game->img.mlx, DEATH_3,
				&game->img.width, &game->img.width);
	else if (game->end_game.time_death < 40)
		game->img.player = mlx_xpm_file_to_image(game->img.mlx, DEATH_4,
				&game->img.width, &game->img.width);
	else if (game->end_game.time_death < 50)
		game->img.player = mlx_xpm_file_to_image(game->img.mlx, DEATH_5,
				&game->img.width, &game->img.width);
	else
		end_game(game, 0);
	game->end_game.time_death++;
}

void	do_water_animation(t_game *game)
{
	if (game->time_water < 10)
		game->img.water = mlx_xpm_file_to_image(game->img.mlx, WATER_1,
				&game->img.width, &game->img.width);
	else if (game->time_water < 20)
		game->img.water = mlx_xpm_file_to_image(game->img.mlx, WATER_2,
				&game->img.width, &game->img.width);
	else if (game->time_water < 30)
		game->img.water = mlx_xpm_file_to_image(game->img.mlx, WATER_3,
				&game->img.width, &game->img.width);
	else if (game->time_water < 40)
		game->img.water = mlx_xpm_file_to_image(game->img.mlx, WATER_4,
				&game->img.width, &game->img.width);
	else if (game->time_water < 50)
		game->img.water = mlx_xpm_file_to_image(game->img.mlx, WATER_5,
				&game->img.width, &game->img.width);
	else
		game->time_water = 0;
	game->time_water++;
}
