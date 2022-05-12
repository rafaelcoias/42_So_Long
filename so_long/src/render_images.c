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
/*
static void	put_nbr(t_game *game, int width, int nbr)
{
	int		i;
	char	*str;
	char	*path;

	i = -1;
	str = malloc(sizeof(char) * 30);
	path = NBR_PATH;
	while (path[++i])
		str[i] = path[i];
	str[23] = nbr + '0';
	game->img.nbr = mlx_xpm_file_to_image(game->mlx, str,
			&game->img.width, &game->img.height);
	mlx_put_image_to_window(game->mlx, game->window, game->img.nbr, width, 0);
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
}*/

static void	write_moves(t_game *game)
{
	int	width;

	mlx_put_image_to_window(game->mlx, game->window, game->img.line, 0, 0);
	mlx_put_image_to_window(game->mlx, game->window, game->img.mov, 50, 0);
	mlx_put_image_to_window(game->mlx, game->window, game->img.es, 100, 0);
	//write_move_number(game, 150, game->count_moves);
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
	int	i;
	int	j;
	int	width;
	int	height;
	int	xy[2];

	i = -1;
	j = -1;
	width = 0;
	height = check_window(game);
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
	return (1);
}
