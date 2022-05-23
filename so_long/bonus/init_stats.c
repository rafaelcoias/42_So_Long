/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:21:44 by rade-sar          #+#    #+#             */
/*   Updated: 2022/05/12 16:22:37 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game_stats(t_game *game)
{
	game->p_i = 0;
	game->p_j = 0;
	game->has_coll = 0;
	game->count_moves = 0;
	game->score = 0;
	game->end_game.win = 0;
	game->end_game.time_death = 0;
	game->time_water = 0;
	game->menu.in_end = 0;
	game->menu.in_menu = 0;
	game->menu.in_game = 1;
	game->end_game.death = 0;
}

void	init_all_stats(t_game *game, char *path)
{
	game->img.mlx = mlx_init();
	game->map.path = path;
	game->p_i = 0;
	game->p_j = 0;
	game->has_coll = 0;
	game->count_moves = 0;
	game->map.count_ground = 0;
	game->score = 0;
	game->menu.width = 550;
	game->menu.test = 1;
	game->menu.play = 0;
	game->menu.exit = 0;
	game->end_game.width = 550;
	game->end_game.win = 0;
	game->end_game.time_death = 0;
	game->time_water = 0;
	game->menu.in_end = 0;
	game->menu.in_menu = 1;
	game->menu.in_game = 0;
}
