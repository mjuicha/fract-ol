/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:25:41 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/14 14:16:45 by mjuicha          ###   ########.fr       */
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


// we need to swap the player's position with the position above it
void    up(t_data *data)
{
        // write(1, "up\n", 3);
        // printf("before swap %d\t%d\n", data->x, data->y);
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
        exit(0);
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
        exit(0);
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
        exit(0);
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
        exit(0);
    }
}