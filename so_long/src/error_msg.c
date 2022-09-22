/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:24:24 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/22 17:52:51 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_game(t_game *game)
{	
	delete_images(*game);
	free(game->img.mlx);
	exit(0);
}

int	error_msg(char *str)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("\nError\n", 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	exit(-1);
}
