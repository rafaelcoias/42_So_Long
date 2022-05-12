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

static void	put_image2(t_game *game, int xy[2], int i, int j)
{
	if (game->map.map[i][j] == 'B')
		mlx_put_image_to_window(game->mlx, game->window, game->img.block,
			xy[0], xy[1]);
	else if (game->map.map[i][j] == 'A')
		mlx_put_image_to_window(game->mlx, game->window, game->img.water,
			xy[0], xy[1]);
	else if (game->map.map[i][j] == 'T')
		mlx_put_image_to_window(game->mlx, game->window, game->img.transport,
			xy[0], xy[1]);
	else if (game->map.map[i][j] == 'S')
		mlx_put_image_to_window(game->mlx, game->window, game->img.bonus,
			xy[0], xy[1]);
	else if (game->map.map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->img.exit,
			xy[0], xy[1]);
}

void	put_image(t_game *game, int xy[2], int i, int j)
{
	if (game->map.map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall,
			xy[0], xy[1]);
	else if (game->map.map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->img.back_ground,
			xy[0], xy[1]);
	else if (game->map.map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->img.collectable,
			xy[0], xy[1]);
	else if (game->map.map[i][j] == 'P' && game->has_coll == 0)
		mlx_put_image_to_window(game->mlx, game->window, game->img.player,
			xy[0], xy[1]);
	else if (game->map.map[i][j] == 'P' && game->has_coll == 1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->img.player_w_coll, xy[0], xy[1]);
	put_image2(game, xy, i, j);
}
