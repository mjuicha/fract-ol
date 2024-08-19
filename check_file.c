/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:47:56 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/19 17:50:53 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_dir(char *av)
{
	int	fd;

	fd = open(av, O_DIRECTORY);
	if (fd != -1)
	{
		ft_printf("Error\n'%s' is a directory!\n", av);
		close(fd);
		exit(1);
	}
}

void	check_ext(char *av)
{
	int		len;
	int		ind;
	char	*s;

	if (av == NULL)
	{
		ft_printf("Error\nNo file name provided.\n");
		exit(1);
	}
	ind = 0;
	s = av;
	len = ft_strlen(av);
	if (len < 4)
		ind = 1;
	else
		av = av + len - 4;
	ind = ft_strcmp(av, ".ber");
	if (ind)
	{
		ft_printf("Error\n'%s' Invalid file extention.\n", s);
		exit(1);
	}
}

void	check_fd(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		err_fd(av);
	close(fd);
}

void	file_check(char *av)
{
	if (av == NULL)
	{
		ft_printf("Error\nNo map file provided.\n");
		exit(1);
	}
	check_dir(av);
	check_ext(av);
	check_fd(av);
}
