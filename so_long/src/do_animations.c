/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:21:05 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/22 11:51:12 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	do_death_animation(t_game *game)
{
	if (!game->end_game.death)
		return ;
	if (game->end_game.time_death < 50)
		game->end_game.player = 1;
	else if (game->end_game.time_death < 100)
		game->end_game.player = 2;
	else if (game->end_game.time_death < 150)
		game->end_game.player = 3;
	else if (game->end_game.time_death < 200)
		game->end_game.player = 4;
	else if (game->end_game.time_death < 250)
		game->end_game.player = 5;
	else
		end_game(game, 0);
	game->end_game.time_death++;
}

void	do_water_animation(t_game *game)
{
	if (game->time_water < 75)
		game->water = 0;
	else if (game->time_water < 150)
		game->water = 1;
	else if (game->time_water < 225)
		game->water = 2;
	else if (game->time_water < 300)
		game->water = 3;
	else if (game->time_water < 375)
		game->water = 4;
	else
	{
		game->water = 0;
		game->time_water = 0;
	}
	game->time_water++;
}
