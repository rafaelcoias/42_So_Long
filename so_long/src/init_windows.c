/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:22:15 by rade-sar          #+#    #+#             */
/*   Updated: 2022/05/12 16:24:46 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_msg(MLX_ERROR);
	game->window = mlx_new_window(game->mlx, game->width,
			game->height, "THIN ICE");
	if (game->window)
		return ;
	free(game->window);
	error_msg(WIN_ERROR);
}
