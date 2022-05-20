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

static void	put_nbr(t_game *game, int w, int nbr)
{
	int		i;
	char	*str;
	char	*path;

	i = -1;
	str = malloc(sizeof(char) * 28);
	path = NBR_PATH;
	while (path[++i])
		str[i] = path[i];
	str[23] = nbr + '0';
	game->img.nbr = mlx_xpm_file_to_image(game->mlx, str,
			&game->img.width, &game->img.width);
	mlx_put_image_to_window(game->img.mlx, game->window, game->img.nbr, w, 0);
	free(str);
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

	mlx_put_image_to_window(game->mlx, game->window, game->img.line, 0, 0);
	mlx_put_image_to_window(game->mlx, game->window, game->img.mov, 50, 0);
	mlx_put_image_to_window(game->mlx, game->window, game->img.es, 100, 0);
	write_move_number(game, 150, game->count_moves);
	mlx_put_image_to_window(game->mlx, game->window, game->img.semi_line,
		180, 0);
	width = 200;
	while (width < game->width)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.line,
			width, 0);
		width += PIXEL_SIZE;
	}
}

static int	check_window(t_game *game)
{
	if (!game->window)
		error_msg(WIN_ERROR);
	write_moves(game);
	return (25);
}

int	render_images(t_game *game)
{
	int	xyij[4];

	if (!game->mlx || !game->menu.in_game)
		return (0);
	xyij[0] = 0;
	xyij[1] = check_window(game);
	xyij[2] = -1;
	while (++xyij[2] < game->map.height)
	{
		xyij[3] = -1;
		xyij[0] = 0;
		while (++xyij[3] < game->map.width)
		{
			put_image(game, xyij);
			xyij[0] += PIXEL_SIZE;
		}
		xyij[1] += PIXEL_SIZE;
	}
	return (1);
}
