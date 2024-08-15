/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:25:41 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/15 05:18:47 by mjuicha          ###   ########.fr       */
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

void    up(t_data *data)
{
    if (data->map[data->y - 1][data->x] == '0')
    {
        ft_swap(&data->map[data->y][data->x], &data->map[data->y - 1][data->x]);
        data->y--;
        printf("your position now  is %d\t%d\n", data->x, data->y);
    }
    else if (data->map[data->y - 1][data->x] == '1')
    {
        printf("You can't move to %d\t%d\n", data->x, data->y - 1);
    }
    else if (data->map[data->y - 1][data->x] == 'C')
    {
        data->collectible--;
        data->map[data->y - 1][data->x] = '0';
        ft_swap(&data->map[data->y][data->x], &data->map[data->y - 1][data->x]);
        data->y--;
        printf("your position now  is %d\t%d\n", data->x, data->y);
    }
    else if (data->map[data->y - 1][data->x] == 'E' && data->collectible == 0)
    {
        printf("You win!\n");
        ft_free(data);
    }
}

void    down(t_data *data)
{
    if (data->map[data->y + 1][data->x] == '0')
    {
        ft_swap(&data->map[data->y][data->x], &data->map[data->y + 1][data->x]);
        data->y++;
        printf("your position now  is %d\t%d\n", data->x, data->y);

    }
    else if (data->map[data->y + 1][data->x] == 'C')
    {
        data->collectible--;
        data->map[data->y + 1][data->x] = '0';
        ft_swap(&data->map[data->y][data->x], &data->map[data->y + 1][data->x]);
        data->y++;
        printf("your position now  is %d\t%d\n", data->x, data->y);

    }
    else if (data->map[data->y + 1][data->x] == 'E' && data->collectible == 0)
    {
        printf("You win!\n");
        ft_free(data);
    }  
}

void    right(t_data *data)
{
    if (data->map[data->y][data->x + 1] == '0')
    {
        ft_swap(&data->map[data->y][data->x], &data->map[data->y][data->x + 1]);
        data->x++;
        printf("your position now  is %d\t%d\n", data->x, data->y);

    }
    else if (data->map[data->y][data->x + 1] == 'C')
    {
        data->collectible--;
        data->map[data->y][data->x + 1] = '0';
        ft_swap(&data->map[data->y][data->x], &data->map[data->y][data->x + 1]);
        data->x++;
        printf("your position now  is %d\t%d\n", data->x, data->y);

    }
    else if (data->map[data->y][data->x + 1] == 'E' && data->collectible == 0)
    {
        printf("You win!\n");
        ft_free(data);
    }
}

void    left(t_data *data)
{
    if (data->map[data->y][data->x - 1] == '0')
    {
        ft_swap(&data->map[data->y][data->x], &data->map[data->y][data->x - 1]);
        data->x--;
        printf("your position now  is %d\t%d\n", data->x, data->y);

    }
    else if (data->map[data->y][data->x - 1] == 'C')
    {
        data->collectible--;
        data->map[data->y][data->x - 1] = '0';
        ft_swap(&data->map[data->y][data->x], &data->map[data->y][data->x - 1]);
        data->x--;
        printf("your position now  is %d\t%d\n", data->x, data->y);

    }
    else if (data->map[data->y][data->x - 1] == 'E' && data->collectible == 0)
    {
        printf("You win!\n");
        ft_free(data);
    }
}