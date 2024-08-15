/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:21:35 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/15 04:08:32 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    map_check_list(char *av, t_data *data)
{
    file_check(av);
    game_map(av, data);
    check_map(data);
    get_collectibles(data);
    get_player_position(data);
}