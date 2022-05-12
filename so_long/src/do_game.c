/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:58:09 by rade-sar          #+#    #+#             */
/*   Updated: 2022/05/12 13:58:43 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_arrows(int key)
{
	if (key == TOP || key == DOWN || key == RIGHT || key == LEFT)
		return (1);
	return (0);
}

static int	handle_keypress(int key, t_game *game)
{
	if (key == ESCAPE)
	{
		mlx_destroy_window(game->mlx, game->window);
		exit(0);
	}
	else if (strchr("wasd", key) || check_arrows(key))
		move_player(game, key);
	return (1);
}

void	do_game(t_game *game)
{
	mlx_loop_hook(game->mlx, &render_images, &game);
	mlx_hook(game->window, 02, 0, &handle_keypress, game);
	mlx_loop(game->mlx);
}
