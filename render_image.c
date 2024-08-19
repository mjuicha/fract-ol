/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:32:42 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/19 12:53:15 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			ft_printf("Error\nImage is Invalid\n");
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
