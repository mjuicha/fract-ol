/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 08:50:27 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/19 18:38:49 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*empty_str(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	int	x;

	if (!str)
		return (0);
	x = 0;
	while (str[x] != (char)c)
	{
		if (str[x] == '\0')
			return (0);
		x++;
	}
	return ((char *)&str[x]);
}

char	*ft_strjoin(char *str, char *buffer)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str && !buffer)
		return (NULL);
	if (str == NULL)
		str = "";
	if (buffer == NULL)
		buffer = "";
	s = (char *)malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buffer) + 1));
	if (!s)
		return (0);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	while (buffer[j])
		s[i++] = buffer[j++];
	s[i] = '\0';
	free(str);
	return (s);
}
