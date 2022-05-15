/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:10:55 by rade-sar          #+#    #+#             */
/*   Updated: 2022/05/12 14:12:21 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_image2(t_game *game, int xyij[4])
{
	if (game->map.map[xyij[2]][xyij[3]] == 'B')
		mlx_put_image_to_window(game->mlx, game->window, game->img.block,
			xyij[0], xyij[1]);
	else if (game->map.map[xyij[2]][xyij[3]] == 'A')
		mlx_put_image_to_window(game->mlx, game->window, game->img.water,
			xyij[0], xyij[1]);
	else if (game->map.map[xyij[2]][xyij[3]] == 'T')
		mlx_put_image_to_window(game->mlx, game->window, game->img.transport,
			xyij[0], xyij[1]);
	else if (game->map.map[xyij[2]][xyij[3]] == 'S')
		mlx_put_image_to_window(game->mlx, game->window, game->img.bonus,
			xyij[0], xyij[1]);
	else if (game->map.map[xyij[2]][xyij[3]] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->img.exit,
			xyij[0], xyij[1]);
}

void	put_image(t_game *game, int xyij[4])
{
	if (game->map.map[xyij[2]][xyij[3]] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall,
			xyij[0], xyij[1]);
	else if (game->map.map[xyij[2]][xyij[3]] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->img.back_ground,
			xyij[0], xyij[1]);
	else if (game->map.map[xyij[2]][xyij[3]] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->img.collectable,
			xyij[0], xyij[1]);
	else if (game->map.map[xyij[2]][xyij[3]] == 'P' && game->has_coll == 0)
		mlx_put_image_to_window(game->mlx, game->window, game->img.player,
			xyij[0], xyij[1]);
	else if (game->map.map[xyij[2]][xyij[3]] == 'P' && game->has_coll == 1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->img.player_w_coll, xyij[0], xyij[1]);
	put_image2(game, xyij);
}
