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
	if (game->end_game.time_death < 1000)
		game->img.death = mlx_xpm_file_to_image(game->img.mlx, DEATH_1,
			&game->img.width, &game->img.width);
	else if (game->end_game.time_death < 2000)
		game->img.death = mlx_xpm_file_to_image(game->img.mlx, DEATH_1,
			&game->img.width, &game->img.width);
	else if (game->end_game.time_death < 3000)
		game->img.death = mlx_xpm_file_to_image(game->img.mlx, DEATH_1,
			&game->img.width, &game->img.width);
	else if (game->end_game.time_death < 4000)
		game->img.death = mlx_xpm_file_to_image(game->img.mlx, DEATH_1,
			&game->img.width, &game->img.width);
	else if (game->end_game.time_death < 5000)
		game->img.death = mlx_xpm_file_to_image(game->img.mlx, DEATH_1,
			&game->img.width, &game->img.width);
}

void	do_water_animation(t_game *game)
{
	if (game->time_water < 1000)
		game->img.water = mlx_xpm_file_to_image(game->img.mlx, WATER_1,
			&game->img.width, &game->img.width);
	else if (game->time_water < 2000)
		game->img.water = mlx_xpm_file_to_image(game->img.mlx, WATER_2,
			&game->img.width, &game->img.width);
	else if (game->time_water < 3000)
		game->img.water = mlx_xpm_file_to_image(game->img.mlx, WATER_3,
			&game->img.width, &game->img.width);
	else if (game->time_water < 4000)
		game->img.water = mlx_xpm_file_to_image(game->img.mlx, WATER_4,
			&game->img.width, &game->img.width);
	else if (game->time_water < 5000)
		game->img.water = mlx_xpm_file_to_image(game->img.mlx, WATER_5,
			&game->img.width, &game->img.width);
	else
		game->time_water = 0;
}
