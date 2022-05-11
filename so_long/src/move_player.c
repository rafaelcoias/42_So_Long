#include "../include/so_long.h"

static int can_move(t_game *game, char move)
{
    if (move == 'd' && (game->map.map[game->p_i][game->p_j + 1] == '1'
        || (game->map.map[game->p_i][game->p_j + 1] == 'B'
            && game->has_coll == 0)))
		return (0);
	else if (move == 'a' && (game->map.map[game->p_i][game->p_j - 1] == '1'
        || (game->map.map[game->p_i][game->p_j - 1] == 'B'
            && game->has_coll == 0)))
		return (0);
	else if (move == 's' && (game->map.map[game->p_i + 1][game->p_j] == '1'
        || (game->map.map[game->p_i + 1][game->p_j] == 'B'
            && game->has_coll == 0)))
		return (0);
	else if (move == 'w' && (game->map.map[game->p_i - 1][game->p_j] == '1'
        || (game->map.map[game->p_i - 1][game->p_j] == 'B'
            && game->has_coll == 0)))
		return (0);
    return (1);
}

static void	check_transport(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (game->map.map[game->p_i][game->p_j] == 'T')
	{
		while (game->map.map[++i])
		{
			j = -1;
			while (game->map.map[i][++j])
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

void    move_player(t_game *game, char move)
{
    if (!can_move(game, move))
        return ;
    game->map.map[game->p_i][game->p_j] = 'A';
    if (move == 'd')
		game->p_j++;
	else if (move == 'a')
		game->p_j--;
	else if (move == 's')
		game->p_i++;
	else if (move == 'w')
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