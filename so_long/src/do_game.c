/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:58:09 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/22 16:34:34 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_arrows(int key)
{
	if (key == UP || key == DOWN || key == RIGHT || key == LEFT
		|| key == W || key == S || key == D || key == A)
		return (1);
	return (0);
}

static int	handle_keypress(int key, t_game *game)
{
	if (!game->mlx || !game->menu.in_game)
		return (0);
	if (key == ESCAPE)
	{
		mlx_destroy_window(game->mlx, game->window);
		delete_images(*game);
		free(game->mlx);
		free(game->img.mlx);
		if (game->map.map)
			free_map(game->map.map);
		exit(0);
	}
	if (check_arrows(key))
		move_player(game, key);
	return (1);
}

void	do_game(t_game *game)
{
	mlx_loop_hook(game->mlx, &render_images, game);
	mlx_hook(game->window, 02, (1L << 0), &handle_keypress, game);
	mlx_hook(game->window, 17, 0, click_to_exit_game, game);
	mlx_loop(game->mlx);
}
