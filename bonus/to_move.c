/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:38:07 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/20 18:38:33 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	to_move(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == 53)
		ft_free(data);
	else if (key == 13)
		up(data);
	else if (key == 1)
		down(data);
	else if (key == 0)
		left(data);
	else if (key == 2)
		right(data);
	mlx_clear_window(data->mlx, data->win);
	render_image(data);
	return (0);
}
