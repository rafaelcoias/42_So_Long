/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:24:24 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/28 21:55:07 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	error_msg(char *str)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd(str, 2);
	exit(1);
}
