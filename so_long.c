/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:24:38 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/14 22:49:46 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void l()
{
    system("leaks a.out");
}

char *get_image(char c, int exit)
{
    char *out;

    (void)exit;
    out = NULL;
    if (c == '1')
        out = "textures/newwall.xpm";
    else if (c == 'P')
        out = "textures/player.xpm";
    else if (c == 'C')
        out = "textures/colle.xpm";
    else if (c == 'E')
    {
        if (exit == 1)
            out = "textures/exit_open.xpm";
        else
            out = "textures/exit_closed.xpm";
    }
    return (out);
}
void print_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        printf("%s", map[i]);
        i++;
    }
    printf("\n");
}
void    render_img(t_data data, int x, int y)
{
    char *image;
    if (data.collectible == 0)
        data.exit = 1;
    if (data.map[y] == NULL)
    {
        if (data.map[y] == NULL)
            printf("Map[y] error\n%d\t%d\n", x, y);
        exit(1);
    }
    image = get_image(data.map[y][x], data.exit);
    if (image)
    {
        data.img = mlx_xpm_file_to_image(data.mlx, image, &data.img_size, &data.img_size);
        if (data.img)
        {
            mlx_put_image_to_window(data.mlx, data.win, data.img, x * 32, y * 32);
            mlx_destroy_image(data.mlx, data.img);
        }
        else
        {
            printf("Image not found\n");
            exit(1);
        }
    }       
}

void render_image(t_data data)
{
    // void *img;
    int x;
    int y;

    y = 0;
    
    data.img_size = 32;
    if (data.map == NULL)
    {
        printf("Map error\n");
        exit(1);
    }
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

int ftff(int key, void *param)
{
    t_data *data;

    data = (t_data *)param;
    if (key == 53)
        exit(0);
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

int ft_close(t_data *data)
{
    (void)data;
    printf("by\n");
    exit(0);
    return 0;
}
int main(int ac, char **av)
{
    t_data data;

    if (ac != 2)
        return (1);
    check_map(av[1], &data);
    data.mlx = mlx_init();
    if(!data.mlx)
        exit(1);
    data.win = mlx_new_window(data.mlx, 1920,1080, "so_long");
    if (!data.win)
        exit(1);
    render_image(data);
    mlx_hook(data.win, 2, 0, *ftff, &data);
    mlx_hook(data.win, 17, 0, ft_close, &data);
    mlx_loop(data.mlx);
    return (0);
}