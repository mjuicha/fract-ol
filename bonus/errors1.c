/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 02:05:22 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/19 12:51:25 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_exit(t_data *data)
{
	ft_printf("Error\nYou add more or less than One Exit!\n");
	error_free_map(data);
}

void	err_coins(t_data *data)
{
	ft_printf("Error\nCollectible not Found!\n");
	error_free_map(data);
}

void	err_rect(t_data *data)
{
	ft_printf("Error\nMap isn't rectangular!\n");
	error_free_map(data);
}

void	err_valid_path(t_data *data)
{
	ft_printf("Error\nInvalid path on the map!\n");
	error_free_map(data);
}

void	ft_error(void)
{
	ft_printf("Error\nUnable to initialize MiniLibX\n");
	exit(1);
}
