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
		|| (game->map.map[game->p_i][game->p_j + 1] == 'E'
		&& game->has_coll != game->map.count_col)))
		return (0);
	else if (key == LEFT && (game->map.map[game->p_i][game->p_j - 1] == '1'
		|| (game->map.map[game->p_i][game->p_j - 1] == 'E'
		&& game->has_coll != game->map.count_col)))
		return (0);
	else if (key == DOWN && (game->map.map[game->p_i + 1][game->p_j] == '1'
		|| (game->map.map[game->p_i + 1][game->p_j] == 'E'
		&& game->has_coll != game->map.count_col)))
		return (0);
	else if (key == UP && (game->map.map[game->p_i - 1][game->p_j] == '1'
		|| (game->map.map[game->p_i - 1][game->p_j] == 'E'
		&& game->has_coll != game->map.count_col)))
		return (0);
	return (1);
}

static int	can_move(t_game *game, int key)
{
	if (key == D && (game->map.map[game->p_i][game->p_j + 1] == '1'
		|| (game->map.map[game->p_i][game->p_j + 1] == 'E'
		&& game->has_coll != game->map.count_col)))
		return (0);
	else if (key == A && (game->map.map[game->p_i][game->p_j - 1] == '1'
		|| (game->map.map[game->p_i][game->p_j - 1] == 'E'
		&& game->has_coll != game->map.count_col)))
		return (0);
	else if (key == S && (game->map.map[game->p_i + 1][game->p_j] == '1'
		|| (game->map.map[game->p_i + 1][game->p_j] == 'E'
		&& game->has_coll != game->map.count_col)))
		return (0);
	else if (key == W && (game->map.map[game->p_i - 1][game->p_j] == '1'
		|| (game->map.map[game->p_i - 1][game->p_j] == 'E'
		&& game->has_coll != game->map.count_col)))
		return (0);
	return (can_move_2(game, key));
}

static void	write_moves(int nbr)
{
	ft_printf("Number of steps: ");
	ft_printf(YELLOW);
	ft_printf("%i\n", nbr);
	ft_printf(RESET);
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
	write_moves(game->count_moves);
	if (game->map.map[game->p_i][game->p_j] == 'E')
		end_game(game, 1);
	else if (game->map.map[game->p_i][game->p_j] == 'A')
		end_game(game, 0);
	else if (game->map.map[game->p_i][game->p_j] == 'C')
		game->has_coll++;
	game->map.map[game->p_i][game->p_j] = 'P';
}
