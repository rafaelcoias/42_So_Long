/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:06:57 by rade-sar          #+#    #+#             */
/*   Updated: 2022/05/12 14:10:48 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	can_move_2(t_game *game, int key)
{
	if (key == RIGHT && (game->map.map[game->p_i][game->p_j + 1] == '1'
		|| (game->map.map[game->p_i][game->p_j + 1] == 'B'
		&& game->has_coll == 0)))
		return (0);
	else if (key == LEFT && (game->map.map[game->p_i][game->p_j - 1] == '1'
		|| (game->map.map[game->p_i][game->p_j - 1] == 'B'
		&& game->has_coll == 0)))
		return (0);
	else if (key == DOWN && (game->map.map[game->p_i + 1][game->p_j] == '1'
		|| (game->map.map[game->p_i + 1][game->p_j] == 'B'
		&& game->has_coll == 0)))
		return (0);
	else if (key == UP && (game->map.map[game->p_i - 1][game->p_j] == '1'
		|| (game->map.map[game->p_i - 1][game->p_j] == 'B'
		&& game->has_coll == 0)))
		return (0);
	return (1);
}

static int	can_move(t_game *game, int key)
{
	if (key == D && (game->map.map[game->p_i][game->p_j + 1] == '1'
		|| (game->map.map[game->p_i][game->p_j + 1] == 'B'
		&& game->has_coll == 0)))
		return (0);
	else if (key == A && (game->map.map[game->p_i][game->p_j - 1] == '1'
		|| (game->map.map[game->p_i][game->p_j - 1] == 'B'
		&& game->has_coll == 0)))
		return (0);
	else if (key == S && (game->map.map[game->p_i + 1][game->p_j] == '1'
		|| (game->map.map[game->p_i + 1][game->p_j] == 'B'
		&& game->has_coll == 0)))
		return (0);
	else if (key == W && (game->map.map[game->p_i - 1][game->p_j] == '1'
		|| (game->map.map[game->p_i - 1][game->p_j] == 'B'
		&& game->has_coll == 0)))
		return (0);
	return (can_move_2(game, key));
}

static void	check_transport(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (game->map.map[game->p_i][game->p_j] == 'T')
	{
		while (++i < game->map.height)
		{
			j = -1;
			while (++j < game->map.width)
			{
				if (game->map.map[i][j] == 'T' && i != game->p_i
						&& j != game->p_j)
				{
					game->map.map[game->p_i][game->p_j] = 'A';
					game->p_i = i;
					game->p_j = j;
				}
			}
		}
	}
}

void	move_player(t_game *game, int key)
{
	if (!can_move(game, key))
		return ;
	game->map.map[game->p_i][game->p_j] = 'A';
	if (key == D || key == RIGHT)
		game->p_j++;
	else if (key == A || key == LEFT)
		game->p_j--;
	else if (key == S || key == DOWN)
		game->p_i++;
	else if (key == W || key == UP)
		game->p_i--;
	game->count_moves++;
	if (game->map.map[game->p_i][game->p_j] == 'E')
		end_game(game, 1);
	else if (game->map.map[game->p_i][game->p_j] == 'A')
		end_game(game, 0);
	else if (game->map.map[game->p_i][game->p_j] == 'C')
		game->has_coll = 1;
	else if (game->map.map[game->p_i][game->p_j] == 'S')
		game->bonus += 575;
	check_transport(game);
	game->map.map[game->p_i][game->p_j] = 'P';
}
