/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:35:07 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/19 12:53:07 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_data *data)
{
	free_map(data);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

void	new_window(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->col * 32,
			data->row * 32, "so_long");
	if (!data->win)
	{
		ft_printf("Error\nUnable to create MiniLibX window\n");
		ft_close(data);
		exit(1);
	}
	mlx_hook(data->win, 17, 0, ft_close, data);
}
