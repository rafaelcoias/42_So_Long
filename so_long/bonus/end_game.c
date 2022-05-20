/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:01:04 by rade-sar          #+#    #+#             */
/*   Updated: 2022/05/12 14:06:51 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_nbr(t_game *game, int width, int h, int nbr)
{
	int		i;
	char	*str;
	char	*path;

	i = -1;
	str = malloc(sizeof(char) * 32);
	path = NBR_WIN_PATH;
	while (path[++i])
		str[i] = path[i];
	str[27] = nbr + '0';
	game->img.nbr = mlx_xpm_file_to_image(game->mlx, str,
			&game->img.width, &game->img.width);
	mlx_put_image_to_window(game->end_game.mlx, game->end_game.window,
		game->img.nbr, width, h);
	free(str);
}

static void	write_score(t_game *game, int w, int h, int score)
{
	printf("%i\n", score);
	if (score < 10)
		put_nbr(game, w, h, 0);
	else
	{
		write_score(game, w - 30, h, score / 10);
		write_score(game, w, h, score % 10);
	}
}

static void	write_moves(t_game *game, int w, int h, int nbr)
{
	int	score;

	score = (game->map.count_ground / game->count_moves) * 1333;
	if (nbr < 10)
	{
		put_nbr(game, w, h, 0);
		put_nbr(game, w + 25, h, nbr);
	}
	else if (nbr < 100)
	{
		put_nbr(game, w, h, nbr / 10);
		put_nbr(game, w + 25, h, nbr % 10);
	}
	if (game->end_game.win)
		write_score(game, 295, 390, score);
}

static int	handle_keypress(int key, t_game *game)
{
	if (key == ESCAPE)
	{
		mlx_destroy_window(game->end_game.mlx, game->end_game.window);
		game->menu.in_end = 0;
		game->menu.in_menu = 1;
		game->menu.in_game = 0;
		free(game->mlx);
		if (game->map.map)
			free_map(game->map.map);
		init_menu_window(game);
		mlx_put_image_to_window(game->menu.mlx, game->menu.window,
			game->img.menu_test, 0, 0);
	}
	return (1);
}

void	end_game(t_game *game, int win)
{
	game->end_game.win = win;
	game->menu.in_end = 1;
	game->menu.in_menu = 0;
	game->menu.in_game = 0;
	mlx_destroy_window(game->mlx, game->window);
	init_end_game_window(game);
	if (win)
		mlx_put_image_to_window(game->end_game.mlx, game->end_game.window,
			game->img.win, 0, 0);
	else
		mlx_put_image_to_window(game->end_game.mlx, game->end_game.window,
			game->img.lose, 0, 0);
	write_moves(game, 305, 345, game->count_moves);
	mlx_hook(game->end_game.window, 02, 0, &handle_keypress, game);
	mlx_loop(game->end_game.mlx);
}
