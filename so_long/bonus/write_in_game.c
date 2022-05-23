/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_in_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:01:04 by rade-sar          #+#    #+#             */
/*   Updated: 2022/05/23 20:34:38 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_nbr(t_game *game, int w, int nbr)
{
	int		i;
	char	*str;
	char	*path;

	i = -1;
	str = malloc(sizeof(char) * 29);
	path = NBR_PATH;
	while (path[++i])
		str[i] = path[i];
	str[i] = '\0';
	str[23] = nbr + '0';
	game->img.nbr = mlx_xpm_file_to_image(game->mlx, str,
			&game->img.width, &game->img.width);
	free(str);
	mlx_put_image_to_window(game->img.mlx, game->window, game->img.nbr, w, 0);
}

static void	write_move_number(t_game *game, int width, int nbr)
{
	if (nbr < 10)
	{
		put_nbr(game, width, 0);
		put_nbr(game, width + 15, game->count_moves);
	}
	else if (nbr < 100)
	{
		put_nbr(game, width, nbr / 10);
		put_nbr(game, width + 15, nbr % 10);
	}
}

static void	write_score_number(t_game *game, int width, int nbr, int fst)
{
	if (fst && nbr < 1000)
		put_nbr(game, game->width - 100, 0);
	if (fst && nbr == 0)
	{
		put_nbr(game, game->width - 100, 0);
		put_nbr(game, game->width - 85, 0);
		put_nbr(game, game->width - 70, 0);
		put_nbr(game, game->width - 55, 0);
	}
	else if (nbr < 10)
		put_nbr(game, width, nbr);
	else
	{
		write_score_number(game, width - 15, nbr / 10, 0);
		write_score_number(game, width, nbr % 10, 0);
	}
}

void	write_moves(t_game *game)
{
	int	width;

	width = 0;
	while (width < game->width)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.line,
			width, 0);
		width += PIXEL_SIZE;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->img.mov, 50, 0);
	mlx_put_image_to_window(game->mlx, game->window, game->img.es, 100, 0);
	write_move_number(game, 150, game->count_moves);
}

void	write_score(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img.sco,
		game->width - 200, 0);
	mlx_put_image_to_window(game->mlx, game->window, game->img.re,
		game->width - 150, 0);
	write_score_number(game, game->width - 50, game->score, 1);
}
