/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:51:54 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/19 20:29:10 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_data *data)
{
	int	i;
	int	j;

	if (data == NULL || data->map == NULL)
		return (0);
	i = 0;
	data->col = ft_strlen(data->map[0]) - 1;
	while (data->map[i] && i < data->row)
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n' && j < data->col)
		{
			if (i == 0 || i == data->row - 1 || j == 0 || j == data->col - 1)
			{
				if (data->map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

size_t	ft_strlen_n(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	check_rect(t_data *data)
{
	int	i;
	int	len;
	int	ref;

	i = 0;
	if (!data || !data->map)
		return (0);
	ref = ft_strlen_n(data->map[i]);
	while (data->map[i])
	{
		len = ft_strlen_n(data->map[i]);
		if (len != ref)
			return (0);
		i++;
	}
	if (data->map[i - 1][len] == '\n')
		return (0);
	return (1);
}
