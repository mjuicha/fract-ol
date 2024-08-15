/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:47:56 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/15 02:08:31 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_dir(char *av)
{
    int fd;
    
    fd = open(av, O_DIRECTORY);
    if (fd != -1)
    {
        printf("Error: '%s' is a directory!\n", av);
        exit(1);
    }
    close(fd);
}

void    check_ext(char *av)
{
    int len;
    int ind;

    ind = 0;
    len = ft_strlen(av);
    if (len < 4)
        ind = 1;
    av = av + len - 4;
    ind = ft_strcmp(av, ".ber");
    if (ind)
    {
        printf("Error: '%s' Invalid file extention.", av);
        exit(1);
    }
}

void    check_fd(char *av)
{
    int fd;

    fd = open(av, O_RDONLY);
    if (fd == -1)
    err_fd(av);
    close(fd);
}

void    file_check(char *av)
{
    check_dir(av);
    check_ext(av);
    check_fd(av);
}