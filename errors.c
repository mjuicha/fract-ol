/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 02:05:22 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/15 23:28:51 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	exit(1);
}

void	err_malloc(void)
{
	ft_printf("Malloc failed to allocate enough memory.");
	exit(1);
}

void	err_fd(char *av)
{
	ft_printf("Error: Failed to open file '%s'", av);
	exit(1);
}

void	err_char(t_data *data)
{
	ft_printf("Invalid character found!\n");
	error_free_map(data);
}

void	err_walls(t_data *data)
{
	ft_printf("Invalid walls!\n");
	error_free_map(data);
}

void	err_player(t_data *data)
{
	ft_printf("You add more or less than One Player!\n");
	error_free_map(data);
}

void	err_exit(t_data *data)
{
	ft_printf("You add more or less than One Exit!\n");
	error_free_map(data);
}

void	err_coins(t_data *data)
{
	ft_printf("Collectible not Found!\n");
	error_free_map(data);
}

void	err_rect(t_data *data)
{
	ft_printf("Map isn't rectangular!\n");
	error_free_map(data);
}

void	err_valid_path(t_data *data)
{
	ft_printf("Invalid path on the map!\n");
	error_free_map(data);
}

void	ft_error(void)
{
	ft_printf("Error: Unable to initialize MiniLibX\n");
	exit(1);
}
