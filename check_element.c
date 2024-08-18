/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 02:34:20 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/18 22:40:30 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->col = ft_strlen(data->map[0]) - 1;
	while (i < data->row)
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
	ref = ft_strlen_n(data->map[i]);
	while (data->map[i])
	{
		len = ft_strlen_n(data->map[i]);
		if (len != ref)
			return (0);
		i++;
	}
	return (1);
}

int	get_player_pos(char **map, t_data *data, int *p_row, int *p_col)
{
	*p_row = 0;
	while (*p_row < data->row && ft_strchr(map[*p_row], 'P') == 0)
		(*p_row)++;
	if (*p_row == data->row)
		return (0);
	*p_col = 0;
	while (*p_col < data->col && map[*p_row][*p_col] != 'P')
		(*p_col)++;
	if (*p_col == data->col)
		return (0);
	return (1);
}

void	copy_map(char **map, char **temp_map, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		temp_map[i] = ft_strdup(map[i]);
		i++;
	}
	temp_map[i] = NULL;
}

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(map, y, x - 1);
	flood_fill(map, y, x + 1);
	flood_fill(map, y - 1, x);
	flood_fill(map, y + 1, x);
}

void	free_maps(char **map, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	check_valid_path(t_data *data)
{
	char	**map;
	char	**temp_map;
	int		p_row;
	int		p_col;
	int		i;

	map = data->map;
	if (!get_player_pos(map, data, &p_row, &p_col))
		return (0);
	temp_map = malloc(sizeof(char *) * (data->row + 1));
	if (!temp_map)
		return (0);
	copy_map(map, temp_map, data->row);
	flood_fill(temp_map, p_row, p_col);
	i = 0;
	while (i < data->row)
	{
		if (ft_strchr(temp_map[i], 'E') != 0
			||ft_strchr(temp_map[i], 'C') != 0)
		{
			free_maps(temp_map, data->row);
			return (0);
		}
		i++;
	}
	free_maps(temp_map, data->row);
	return (1);
}
