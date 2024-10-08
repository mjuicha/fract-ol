/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:25:41 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/20 21:51:40 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	up(t_data *data)
{
	if (data->map[data->py - 1][data->px] == '0')
	{
		ft_swap(&data->map[data->py][data->px],
			&data->map[data->py - 1][data->px]);
		data->py--;
		ft_printf("[MOVED UP]-[COUNT] > %d\n", ++data->mv_count);
	}
	else if (data->map[data->py - 1][data->px] == 'C')
	{
		data->collectible--;
		data->map[data->py - 1][data->px] = '0';
		ft_swap(&data->map[data->py][data->px],
			&data->map[data->py - 1][data->px]);
		data->py--;
		ft_printf("[MOVED UP]-[COUNT] > %d\n", ++data->mv_count);
	}
	else if (data->map[data->py - 1][data->px] == 'E'
		&& data->collectible == 0)
		you_win(data);
	else if (data->map[data->py - 1][data->px] == 'K')
		you_lose(data);
}

void	down(t_data *data)
{
	if (data->map[data->py + 1][data->px] == '0')
	{
		ft_swap(&data->map[data->py][data->px],
			&data->map[data->py + 1][data->px]);
		data->py++;
		ft_printf("[MOVED DOWN]-[COUNT] > %d\n", ++data->mv_count);
	}
	else if (data->map[data->py + 1][data->px] == 'C')
	{
		data->collectible--;
		data->map[data->py + 1][data->px] = '0';
		ft_swap(&data->map[data->py][data->px],
			&data->map[data->py + 1][data->px]);
		data->py++;
		ft_printf("[MOVED UP]-[COUNT] > %d\n", ++data->mv_count);
	}
	else if (data->map[data->py + 1][data->px] == 'E'
		&& data->collectible == 0)
		you_win(data);
	else if (data->map[data->py + 1][data->px] == 'K')
		you_lose(data);
}

void	right(t_data *data)
{
	if (data->map[data->py][data->px + 1] == '0')
	{
		ft_swap(&data->map[data->py][data->px],
			&data->map[data->py][data->px + 1]);
		data->px++;
		ft_printf("[MOVED UP]-[RIGHT] > %d\n", ++data->mv_count);
	}
	else if (data->map[data->py][data->px + 1] == 'C')
	{
		data->collectible--;
		data->map[data->py][data->px + 1] = '0';
		ft_swap(&data->map[data->py][data->px],
			&data->map[data->py][data->px + 1]);
		data->px++;
		ft_printf("[MOVED UP]-[COUNT] > %d\n", ++data->mv_count);
	}
	else if (data->map[data->py][data->px + 1] == 'E'
		&& data->collectible == 0)
		you_win(data);
	else if (data->map[data->py][data->px + 1] == 'K')
		you_lose(data);
}

void	left(t_data *data)
{
	if (data->map[data->py][data->px - 1] == '0')
	{
		ft_swap(&data->map[data->py][data->px],
			&data->map[data->py][data->px - 1]);
		data->px--;
		ft_printf("[MOVED LEFT]-[COUNT] > %d\n", ++data->mv_count);
	}
	else if (data->map[data->py][data->px - 1] == 'C')
	{
		data->collectible--;
		data->map[data->py][data->px - 1] = '0';
		ft_swap(&data->map[data->py][data->px],
			&data->map[data->py][data->px - 1]);
		data->px--;
		ft_printf("[MOVED UP]-[COUNT] > %d\n", ++data->mv_count);
	}
	else if (data->map[data->py][data->px - 1] == 'E'
		&& data->collectible == 0)
		you_win(data);
	else if (data->map[data->py][data->px - 1] == 'K')
		you_lose(data);
}
