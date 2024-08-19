/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:21:35 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/19 19:00:56 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill_c(char **map, size_t y, size_t x)
{
	if (!map || y < 0 || x < 0 || y >= ft_tablen(map) || x >= ft_strlen(map[y]))
		return ;
	if (map[y][x] == '1' || map[y][x] == 'X' || map[y][x] == 'E')
		return ;
	map[y][x] = 'X';
	flood_fill_c(map, y, x - 1);
	flood_fill_c(map, y, x + 1);
	flood_fill_c(map, y - 1, x);
	flood_fill_c(map, y + 1, x);
}

int	check_coins_path(t_data *data)
{
	char	**temp_map;
	int		i;

	if (!data || !data->map)
		return (0);
	if (!(temp_map = malloc(sizeof(char *) * (data->row + 1))))
		return (0);
	copy_map(data->map, temp_map, data->row);
	flood_fill_c(temp_map, data->py, data->px);
	i = 0;
	while (i < data->row)
	{
		if (ft_strchr(temp_map[i], 'C'))
		{
			free_maps(temp_map, data->row);
			return (0);
		}
		i++;
	}
	free_maps(temp_map, data->row);
	return (1);
}

void	check_map(t_data *data)
{
	if (!check_char(data))
		err_char(data);
	if (!check_walls(data))
		err_walls(data);
	check_exist(data);
	if (!check_rect(data))
		err_rect(data);
	if (!check_valid_path(data))
		err_valid_path(data);
}

void	map_check_list(char *av, t_data *data)
{
	if (av == NULL || data == NULL)
    {
        ft_printf("Error\nInvalid input!\n");
        exit(1);
    }
	file_check(av);
	game_map(av, data);
	check_map(data);
	get_collectibles(data);
	get_player_position(data);
	if (!check_coins_path(data))
		err_valid_path(data);
}
