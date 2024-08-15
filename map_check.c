/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 02:11:37 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/15 03:53:30 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int valid_char(char c)
{
    char *valid;

    valid = "01CEP";
    while (*valid)
    {
        if (c == *valid)
            return (1);
        valid++;
    }
    return (0);
}

int check_char(t_data *data)
{
    int i;
    int j;

    i = 0;
    if (!data->map)
        return (0);
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j] && data->map[i][j] != '\n')
        {
            if (!valid_char(data->map[i][j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}  

int exist(t_data *data, char r)
{
    int i;
    int j;
    int f;
    
    i = 0;
    f = 0;
    if (!data->map)
        return (0);
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j] && data->map[i][j] != '\n')
        {
            if (data->map[i][j] == r)
                f++;
            if (f > 1)
                return (0);
            j++;
        }
        i++;
    }
    return (f == 1);
}
int exist_coins(t_data *data)
{
    int i;
    int j;
    int c;
    
    i = 0;
    c = 0;
    if (!data->map)
        return (0);
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j] && data->map[i][j] != '\n')
        {
            if (data->map[i][j] == 'C')
                c++;
            j++;
        }
        i++;
    }
    return (c);
}

void    check_exist(t_data *data)
{
    if (!exist(data, 'P'))
        err_player(data);
    if (!exist(data, 'E'))
        err_exit(data);
    if (!exist_coins(data))
        err_coins(data);
}

void    check_map(t_data *data)
{
    if (!check_char(data))
        err_char(data);
    if (!check_walls(data))
        err_walls(data);
    check_exist(data);
    if (!check_rect(data))
        err_rect(data);
    if (!check_valid_path(data))
        err_valid_path(data);
}