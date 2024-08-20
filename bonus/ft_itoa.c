/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:46:23 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/20 21:46:40 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_size(long int n)
{
	long int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			s;
	int			i;
	long int	num;

	i = count_size(n);
	num = n;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	s = i - 1;
	if (num == 0)
		str[s] = '0';
	while (s >= 0 && num != 0)
	{
		str[s--] = (num % 10) + '0';
		num = num / 10;
	}
	str[i] = '\0';
	return (str);
}