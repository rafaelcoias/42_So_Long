/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:35:33 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/28 21:54:45 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Quando dá erro, pode ser por 3 razoes:
//
// 1 - Os loops usam a função handle_keypress mesmo não devendo 
// (quando estão no end_game, verificam os movimentos do jogo).
// SOLUCAO : verificar em que janela do programa estão sempre que entra na 
// funcao handle_keypress.
//
// 2 - Os loops não têm uma janela válida/ativada porque foi destruida
// SOLUCAO : usar sempre a mesma *window e o mesmo *mlx
//
// SOL:  mlx_loop_end(game->mlx)

//ADD : close program when click window red cross 
//ADD : animation in collectable and in water

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (0);
	init_all_stats(&game, argv[1]);
	check_ber(argv[1]);
	check_map(&game);
	init_images(&game);
	do_menu_window(&game);
}
