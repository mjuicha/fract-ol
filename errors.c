/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 02:05:22 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/15 04:57:27 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void free_map(t_data *data)
{
    int i;

    i = 0;
    
    while (data->map[i])
    {
        free(data->map[i]);
        i++;
    }
    free(data->map);
    exit(1);
}

void    err_malloc()
{
    printf("Malloc failed to allocate enough memory.");
    exit(1);
}
void    err_fd(char *av)
{
    printf("Error: Failed to open file '%s'", av);
    exit(1);
}

void    err_char(t_data *data)
{
    printf("Invalid character found!\n");
    free_map(data);
}

void    err_walls(t_data *data)
{
    printf("Invalid walls!\n");
    free_map(data);
}

void    err_player(t_data *data)
{
    printf("Only one player is allowed!\n");
    free_map(data);
}

void    err_exit(t_data *data)
{
    printf("Only one exit is allowed!\n");
    free_map(data);
}

void    err_coins(t_data *data)
{
    printf("Collectible not Found!\n");
    free_map(data);
}

void    err_rect(t_data *data)
{
    printf("Map isn't rectangular!\n");
    free_map(data);
}

void    err_valid_path(t_data *data)
{
    printf("Invalid path on the map!\n");
    free_map(data);
}

void    ft_error()
{
    printf("Error: Unable to initialize MiniLibX\n");
    exit(1);
}