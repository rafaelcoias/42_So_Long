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

void	init_all_stats(t_game *game, char *path)
{
	game->img.mlx = mlx_init();
	game->map.path = path;
	game->p_i = 0;
	game->p_j = 0;
	game->has_coll = 0;
	game->count_moves = 0;
}
