/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 01:42:32 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/15 04:53:09 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int len_map(char *map)
{
    int fd;
    int line_len;
    char *line;

    fd = open(map, O_RDONLY);
    if (fd == -1)
        exit(1);
    line_len = 0;
    line = get_next_line(fd);
    while (line)
    {
        line_len++;
        free(line);
        line = get_next_line(fd);
    }
    if (line)
        free(line);
    close(fd);
    return (line_len);
}

char **fill_map(char *map, int len)
{
    int fd;
    int i;
    char **map_tab;

    i = 0;
    fd = open(map, O_RDONLY);
    if (fd == -1)
        exit(1);
    map_tab = malloc(sizeof(char *) * (len + 1));
    if (!map_tab)
        exit(1);
    map_tab[len] = NULL;
    while (i < len)
    {
        map_tab[i] = get_next_line(fd);
        i++;
    }
    close(fd);
    return (map_tab);
}

void game_map(char *map, t_data *data)
{

    data->row = len_map(map);
    if (data->row == 0)
        exit(1);
    data->map = fill_map(map, data->row);
}