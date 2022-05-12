/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:12:24 by rade-sar          #+#    #+#             */
/*   Updated: 2022/05/12 14:28:03 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_nbr(t_game *game, int width, int nbr)
{
	int		i;
	int		j;
	char	before[26];
	char	after[4];
	char	path[31];

	before = "../include/images/numbers/";
	after = ".xpm";
	i = 0;
	j = 0;
	while (before[i])
		path[j++] = before[i++];
	if (nbr > 99)
		nbr = 0;
	path[j] = nbr + '0';
	i = 0;
	while (after[i])
		path[j++] = after[i++];
	game->img.nbr = mlx_xpm_file_to_image(game->mlx, path,
			&game->img.width, &game->img.height);
	mlx_put_image_to_window(game->mlx, game->window, game->img.nbr, width, 0);
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

static void	write_moves(t_game *game)
{
	int	width;
	int	i;

	mlx_put_image_to_window(game->mlx, game->window, game->img.line, 0, 0);
	mlx_put_image_to_window(game->mlx, game->window, game->img.mov, 50, 0);
	mlx_put_image_to_window(game->mlx, game->window, game->img.es, 100, 0);
	write_move_number(game, 150, game->count_moves);
	game->img.semi_line = mlx_xpm_file_to_image(game->mlx, SEMI_LINE,
			&game->img.width, &game->img.height);
	mlx_put_image_to_window(game->mlx, game->window, game->img.semi_line,
		xy[0], xy[1]);
	width = 200;
	i = 3;
	while (game->map.map[++i])
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.line,
			width, 0);
		width += PIXEL_SIZE;
	}
}

static void	check_window(t_game *game)
{
	if (!game->window)
		error_msg(WIN_ERROR);
	write_moves(game);
}

void	render_images(t_game *game)
{
	int	i;
	int	j;
	int	width;
	int	height;
	int	xy[2];

	i = -1;
	j = -1;
	width = 0;
	height = 25;
	check_window(game);
	while (game->map.map[++i])
	{
		j = -1;
		width = 0;
		while (game->map.map[i][++j])
		{
			xy[0] = width;
			xy[1] = height;
			put_image(game, xy, i, j);
			width += PIXEL_SIZE;
		}
		height += PIXEL_SIZE;
	}
}
