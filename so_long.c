/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:24:38 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/18 21:01:24 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	l(void)
{
	system("leaks so_long");
}

char	*get_image(char c, int exit)
{
	char	*out;

	(void)exit;
	out = NULL;
	if (c == '1')
		out = "textures/newwall.xpm";
	else if (c == 'P')
		out = "textures/player.xpm";
	else if (c == 'C')
		out = "textures/money.xpm";
	else if (c == 'E')
	{
		if (exit == 1)
			out = "textures/exit_open.xpm";
		else
			out = "textures/exit_closed.xpm";
	}
	return (out);
}

void	render_img(t_data data, int x, int y)
{
	char	*image;

	if (data.collectible == 0)
		data.exit = 1;
	image = get_image(data.map[y][x], data.exit);
	if (image)
	{
		data.img = mlx_xpm_file_to_image(data.mlx, image,
				&data.img_size, &data.img_size);
		if (data.img)
		{
			mlx_put_image_to_window(data.mlx, data.win,
				data.img, x * 32, y * 32);
			mlx_destroy_image(data.mlx, data.img);
		}
		else
		{
			ft_printf("Error: Image is Invalid\n");
			exit(1);
		}
	}
}

void	render_image(t_data data)
{
	int	x;
	int	y;

	y = 0;
	data.img_size = 32;
	while (data.map[y])
	{
		x = 0;
		while (data.map[y][x] && data.map[y][x] != '\n')
		{
			render_img(data, x, y);
			x++;
		}
		y++;
	}
}

void 	free_map(t_data *data)
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

int	ftff(int key, void *param)
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
	render_image(*data);
	return (0);
}

int	ft_close(t_data *data)
{
	free_map(data);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

void	ft_new_window(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->col * 32,
			data->row * 32, "so_long");
	if (!data->win)
	{
		ft_printf("Error: Unable to create MiniLibX window\n");
		ft_close(data);
		exit(1);
	}
	mlx_hook(data->win, 17, 0, ft_close, data);
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
	ft_new_window(&data);
	render_image(data);
	mlx_hook(data.win, 2, 0, *ftff, &data);
	mlx_loop(data.mlx);
	return (0);
}
