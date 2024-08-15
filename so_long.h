/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:24:49 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/15 05:19:04 by mjuicha          ###   ########.fr       */
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
    void    *mlx;//
    void    *win;//
    void    *img;
    char    **map;
    int     row;//
    int     col;//
    int    collectible;//
    int    img_size;
    int    exit;
    int    x;//
    int    y;//
}   t_data;


void print_map(char **map);


void    up(t_data *data);
void    down(t_data *data);
void    right(t_data *data);
void    left(t_data *data);


void    map_check_list(char *av, t_data *data);
void    game_map(char *map, t_data *data);
void    file_check(char *av);
void    check_map(t_data *data);
void    err_fd(char *av);
void    err_malloc();
void    err_char(t_data *data);
void    err_walls(t_data *data);
int     check_walls(t_data *data);
void    err_exit(t_data *data);
void    err_player(t_data *data);
void    err_coins(t_data *data);
int     check_rect(t_data *data);
void    err_rect(t_data *data);
int     check_valid_path(t_data *data);
void    err_valid_path(t_data *data);
void    get_player_position(t_data *data);
void    get_collectibles(t_data *data);

char	*ft_strdup(const char *s1);
int	ft_strcmp(const char *s1, const char *s2);
void    ft_error();
void free_map(t_data *data);
void    ft_free(t_data *data);


#endif
