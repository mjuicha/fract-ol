/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 03:49:53 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/18 20:38:37 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_collectibles(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->collectible = 0;
	while (i < data->row)
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			if (data->map[i][j] == 'C')
				data->collectible++;
			j++;
		}
		i++;
	}
}

void	get_player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			if (data->map[i][j] == 'P')
			{
				data->py = i;
				data->px = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
