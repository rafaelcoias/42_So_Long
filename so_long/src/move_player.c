/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:06:57 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/22 16:13:17 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	can_move(t_game *game, int key)
{
	if ((key == RIGHT || key == D)
		&& (game->map.map[game->p_i][game->p_j + 1] == '1'
		|| (ft_strchr("BE", game->map.map[game->p_i][game->p_j + 1])
		&& game->has_coll != game->map.count_col)))
		return (0);
	else if ((key == LEFT || key == A)
		&& (game->map.map[game->p_i][game->p_j - 1] == '1'
		|| (ft_strchr("BE", game->map.map[game->p_i][game->p_j - 1])
		&& game->has_coll != game->map.count_col)))
		return (0);
	else if ((key == DOWN || key == S)
		&& (game->map.map[game->p_i + 1][game->p_j] == '1'
		|| (ft_strchr("BE", game->map.map[game->p_i + 1][game->p_j])
		&& game->has_coll != game->map.count_col)))
		return (0);
	else if ((key == UP || key == W)
		&& (game->map.map[game->p_i - 1][game->p_j] == '1'
		|| (ft_strchr("BE", game->map.map[game->p_i - 1][game->p_j])
		&& game->has_coll != game->map.count_col)))
		return (0);
	return (1);
}

static void	move(t_game *game, int key)
{
	if (key == D || key == RIGHT)
		game->p_j++;
	else if (key == A || key == LEFT)
		game->p_j--;
	else if (key == S || key == DOWN)
		game->p_i++;
	else if (key == W || key == UP)
		game->p_i--;
}

static void	check_transport(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (game->map.map[game->p_i][game->p_j] != 'T')
		return ;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (game->map.map[i][j] == 'T' && (i != game->p_i
					|| j != game->p_j))
			{
				game->map.map[game->p_i][game->p_j] = 'A';
				game->p_i = i;
				game->p_j = j;
				return ;
			}
		}
	}
}

static int	check_death(t_game *game)
{
	if ((game->map.map[game->p_i][game->p_j + 1] == 'A'
		|| game->map.map[game->p_i][game->p_j + 1] == '1'
		|| !can_move(game, RIGHT))
		&& (game->map.map[game->p_i][game->p_j - 1] == 'A'
		|| game->map.map[game->p_i][game->p_j - 1] == '1'
		|| !can_move(game, LEFT))
		&& (game->map.map[game->p_i + 1][game->p_j] == 'A'
		|| game->map.map[game->p_i + 1][game->p_j] == '1'
		|| !can_move(game, DOWN))
		&& (game->map.map[game->p_i - 1][game->p_j] == 'A'
		|| game->map.map[game->p_i - 1][game->p_j] == '1'
		|| !can_move(game, UP)))
		return (1);
	return (0);
}

void	move_player(t_game *game, int key)
{
	if (!can_move(game, key) || game->end_game.death)
		return ;
	game->map.map[game->p_i][game->p_j] = 'A';
	move(game, key);
	game->count_moves++;
	game->score += 100;
	if (game->map.map[game->p_i][game->p_j] == 'E')
		end_game(game, 1);
	else if (game->map.map[game->p_i][game->p_j] == 'A')
		game->end_game.death = 1;
	else if (game->map.map[game->p_i][game->p_j] == 'C')
	{
		game->has_coll++;
		game->score += 50;
	}
	else if (game->map.map[game->p_i][game->p_j] == 'S')
		game->score += 575;
	check_transport(game);
	game->map.map[game->p_i][game->p_j] = 'P';
	if (check_death(game))
		game->end_game.death = 1;
	write_moves(game);
	write_score(game);
}
