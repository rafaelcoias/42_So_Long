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
        ft_printf("%i", game->count_moves);
        ft_printf(RESET);
    }
    else
    {
        ft_printf(RED);
        ft_printf("\n<<<<< GAME OVER >>>>>\n\n");
        ft_printf(RESET);
        ft_printf("Total of steps : ");
        ft_printf(YELLOW);
        ft_printf("%i", game->count_moves);
        ft_printf(RESET);
    }
    delete_images(game);
	free(game.mlx);
	if (game.map.map)
		free_map(game.map.map);
}