/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:24:49 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/14 11:32:44 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include <fcntl.h>
#include "get_next_line.h"

typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    *img;
    char    **map;
    int     len_line;
    int    collectible;
    int    img_size;
    int    exit;
    int    x;
    int    y;
}   t_data;

void check_map(char *map, t_data *data);
void game_map(char *map, t_data *data);
void print_map(char **map);


void    up(t_data *data);
void    down(t_data *data);
void    right(t_data *data);
void    left(t_data *data);



#endif
