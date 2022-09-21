/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:21:05 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/21 19:59:05 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	do_death_animation(t_game *game)
{
	if (!game->end_game.death)
		return ;
	else
		end_game(game, 0);
	game->end_game.time_death++;
}

void	do_water_animation(t_game *game, int xyij[4])
{	
	int i;

	i = 0;
	while (i != 5)
		mlx_put_image_to_window(game->mlx, game->window, game->img.water[i],
			xyij[0], xyij[1]);
}
