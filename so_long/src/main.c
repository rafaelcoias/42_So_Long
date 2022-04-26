/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:35:33 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/26 15:35:34 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(void)
{
    void    *mlx_ptr;
    void    *wind_ptr;
    
    mlx_ptr = mlx_init();
    wind_ptr = mlx_new_window(mlx_ptr, 750, 400, "so_long");
    mlx_loop(mlx_ptr);
}