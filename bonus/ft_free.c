/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:26:24 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/19 19:55:26 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_free_map(t_data *data)
{
	int	i;

	i = 0;
	if (!data || !data->map)
		exit(1);
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	exit(1);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	ft_free(t_data *data)
{
	free_map(data);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	free_maps(char **map, int len)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i] && i < len)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
