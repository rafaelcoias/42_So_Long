/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:23:58 by rade-sar          #+#    #+#             */
/*   Updated: 2022/05/20 17:25:13 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	end_game(t_game *game, int win)
{
	if (win)
	{
		ft_printf(GREEN);
		ft_printf("\n<<<<< YOU WON >>>>>\n\n");
		ft_printf(RESET);
		ft_printf("Total of steps : ");
		ft_printf(YELLOW);
	}
	else
	{
		ft_printf(RED);
		ft_printf("\n<<<<< GAME OVER >>>>>\n\n");
		ft_printf(RESET);
		ft_printf("Total of steps : ");
		ft_printf(YELLOW);
	}
	ft_printf("%i\n", game->count_moves);
	ft_printf(RESET);
	delete_images(*game);
	free(game->mlx);
	if (game->map.map)
		free_map(game->map.map);
	exit(0);
}
