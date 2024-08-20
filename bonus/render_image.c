/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:32:42 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/20 21:47:43 by mjuicha          ###   ########.fr       */
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
	if (c == 'P')
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

static char	*ft_get_enemy_sprite(void)
{
    static int	i = 0;
    char		*output;

    // Alternate between two enemy sprites based on the value of 'i'
    if (i % 2 == 0)
        output = "textures/enemy-1.xpm";
    else
        output = "textures/enemy-2.xpm";
    
    // Increment 'i' to switch sprites on the next call
    i++;

    return (output);
}

void animate_enemy(t_data *data, int x, int y)
{
    static int frame_count = 0;
    static void *current_img = NULL;  // Hold the current image pointer
    char *img_path = NULL;

    // Every 20 frames, update the enemy sprite
    if (frame_count % 10==5 == 0)
    {
        img_path = ft_get_enemy_sprite();  // Get the next sprite path
        if (img_path)
        {
            // Destroy the previous image only when changing the sprite
            if (current_img)
                mlx_destroy_image(data->mlx, current_img);

            // Load the new sprite image and store it
            current_img = mlx_xpm_file_to_image(data->mlx, img_path,
                                                &data->img_size, &data->img_size);
        }
    }

    // Always redraw the enemy sprite
    if (current_img)
    {
        mlx_put_image_to_window(data->mlx, data->win, current_img,
                                x * 32, y * 32);
    }

    frame_count++;
}

void	render_img(t_data data, int x, int y)
{
    char *image;

    if (data.collectible == 0)
        data.exit = 1;
    
    if (data.map[y][x] == 'K')
    {
        animate_enemy(&data, x, y);  // Animate enemy
    }
    else
    {
        image = get_image(data.map[y][x], data.exit);
        if (image)
        {
            data.img = mlx_xpm_file_to_image(data.mlx, image,
                    &data.img_size, &data.img_size);
            if (data.img)
            {
                mlx_put_image_to_window(data.mlx, data.win, data.img,
                    x * 32, y * 32);
                mlx_destroy_image(data.mlx, data.img);
            }
            else
            {
                ft_printf("Error\nimage path is invalid!\n");
                exit(1);
            }
        }
    }
}

void show_moves(t_data *data)
{
    char *num;

    num = ft_itoa(data->mv_count);
	mlx_string_put(data->mlx, data->win, (data->col * 32) / 2 - 10, data->row * 32, 0x00FF0000, "MOVES: ");
    mlx_string_put(data->mlx, data->win, (data->col * 32) / 2 + 50, data->row * 32, 0x00FF0000, num);
    free(num);
}

int	render_image(void *param)
{
	t_data	*data;
	int	x;
	int	y;

	data = (t_data *)param;
	y = 0;
	data->img_size = 32;
	mlx_clear_window(data->mlx, data->win);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] && data->map[y][x] != '\n')
		{
			render_img(*data, x, y);
			x++;
		}
		y++;
	}
	show_moves(data);
	return (0);
}
