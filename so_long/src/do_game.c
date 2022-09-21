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

static int	click_to_exit(t_game *game)
{
	delete_images(*game);
	mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	free(game->img.mlx);
	if (game->map.map)
		free_map(game->map.map);
	exit(0);
}

static int	check_arrows(int key)
{
	if (key == UP || key == DOWN || key == RIGHT || key == LEFT
		|| key == W || key == S || key == D || key == A)
		return (1);
	return (0);
}

static int	handle_keypress(int key, t_game *game)
{
	printf("%i ", key);
	if (key == ESCAPE)
	{
		mlx_destroy_window(game->mlx, game->window);
		exit(0);
	}
	else if (check_arrows(key))
		move_player(game, key);
	return (1);
}

void	do_game(t_game *game)
{
	mlx_loop_hook(game->mlx, &render_images, game);
	mlx_hook(game->window, 02, (1L << 0), &handle_keypress, game);
	mlx_hook(game->window, 17, 0, click_to_exit, game);
	mlx_loop(game->mlx);
}
