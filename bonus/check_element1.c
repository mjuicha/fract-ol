/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 02:34:20 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/20 11:50:32 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_player_pos(char **map, t_data *data, int *p_row, int *p_col)
{
	if (!map || !data)
		return (0);
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

	if (!map || !temp_map)
		return ;
	i = 0;
	while (i < len)
	{
		temp_map[i] = ft_strdup(map[i]);
		i++;
	}
	temp_map[i] = NULL;
}

void	flood_fill(char **map, int y, int x, t_data *data)
{
	if (!map || y < 0 || x < 0 || y >= data->row || x >= data->col)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(map, y, x - 1, data);
	flood_fill(map, y, x + 1, data);
	flood_fill(map, y - 1, x, data);
	flood_fill(map, y + 1, x, data);
}

int	check_valid_path(t_data *data)
{
	char	**map;
	char	**temp_map;
	int		p_row;
	int		p_col;
	int		i;

	if (!data || !data->map)
		return (0);
	map = data->map;
	if (!get_player_pos(map, data, &p_row, &p_col))
		return (0);
	temp_map = malloc(sizeof(char *) * (data->row + 1));
	if (!temp_map)
		return (0);
	copy_map(map, temp_map, data->row);
	flood_fill(temp_map, p_row, p_col, data);
	i = 0;
	while (i < data->row)
	{
		if (ft_strchr(temp_map[i], 'E') || ft_strchr(temp_map[i], 'C'))
			return (free_maps(temp_map, data->row), 0);
		i++;
	}
	return (free_maps(temp_map, data->row), 1);
}
