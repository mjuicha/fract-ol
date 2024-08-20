/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:52:05 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/20 21:54:23 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    you_win(t_data *data)
{
    ft_printf("You win\n");
    ft_free(data);
}

void    you_lose(t_data *data)
{
    ft_printf("You lose\n");
    ft_free(data);
}