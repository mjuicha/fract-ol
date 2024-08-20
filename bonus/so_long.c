/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:24:38 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/20 21:36:37 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	l(void)
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (1);
	map_check_list(av[1], &data);
	data.mlx = mlx_init();
	if (!data.mlx)
		ft_error();
	new_window(&data);
	mlx_loop_hook(data.mlx, render_image, &data);
	mlx_hook(data.win, 2, 0, *to_move, &data);
	mlx_loop(data.mlx);
	return (0);
}
