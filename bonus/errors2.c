/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:24:29 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/19 12:52:45 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_malloc(void)
{
	ft_printf("Malloc failed to allocate enough memory.");
	exit(1);
}

void	err_fd(char *av)
{
	ft_printf("Error\nFailed to open file '%s'\n", av);
	exit(1);
}

void	err_char(t_data *data)
{
	ft_printf("Error\nInvalid character found!\n");
	error_free_map(data);
}

void	err_walls(t_data *data)
{
	ft_printf("Error\nInvalid walls!\n");
	error_free_map(data);
}

void	err_player(t_data *data)
{
	ft_printf("Error\nYou add more or less than One Player!\n");
	error_free_map(data);
}
