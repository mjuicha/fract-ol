
// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   check_map.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/08/08 00:30:23 by mjuicha           #+#    #+#             */
// /*   Updated: 2024/08/08 06:09:14 by mjuicha          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "so_long.h"

// // size_t	ft_strlen(const char *str)
// // {
// // 	size_t	i;

// // 	if (!str)
// // 		return (0);
// // 	i = 0;
// // 	while (str[i])
// // 		i++;
// // 	return (i);
// // }

// char	*ft_strdup(const char *s1)
// {
// 	size_t	x;
// 	size_t	i;
// 	char	*dest;

// 	x = 0;
// 	while (s1[x])
// 		x++;
// 	x++;
// 	dest = (char *)malloc(sizeof(char) * x);
// 	if (dest == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		dest[i] = s1[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }
// int	ft_strcmp(const char *s1, const char *s2)
// {
//     size_t i;

//     i = 0;
//     if (!s1 || !s2)
//         return (1);
//     while (s1[i] && s2[i] && s1[i] == s2[i])
//         i++;
//     return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// }

// int check_ext(char *map, char *ext)
// {
//     int len_ext;
//     int len_map;
//     int fd;

//     fd = open(map, O_RDONLY);
//     if (fd == -1)
//         return (1);
//     close(fd);
//     len_ext = ft_strlen(ext);
//     len_map = ft_strlen(map);
//     if (len_map < len_ext)
//         return (1);
//     map = map + len_map - len_ext;
//     return (ft_strcmp(map, ext));
// }

// int valid_char(char c)
// {
//     char *valid;

//     valid = "01CEP";
//     while (*valid)
//     {
//         if (c == *valid)
//             return (1);
//         valid++;
//     }
//     return (0);
// }

// int check_char(t_data data)
// {
//     int i;
//     int j;

//     i = 0;
//     if (!data.map)
//         return (0);
//     while (data.map[i])
//     {
//         j = 0;
//         while (data.map[i][j] && data.map[i][j] != '\n')
//         {
//             if (!valid_char(data.map[i][j]))
//                 return (0);
//             j++;
//         }
//         i++;
//     }
//     return (1);
// }           

// void free_map(t_data *data)
// {
//     int i;

//     i = 0;
    
//     while (data->map[i])
//     {
//         free(data->map[i]);
//         i++;
//     }
//     free(data->map);
// }

// void err_char(t_data *data)
// {
//     write(1, "Errorbs\n", 8);
//     (void)data;
//     // free_map(data);
// }

// int check_player(t_data *data)
// {
//     int i;
//     int j;
//     int p;
    
//     i = 0;
//     p = 0;
//     if (!data->map)
//         return (0);
//     while (data->map[i])
//     {
//         j = 0;
//         while (data->map[i][j] && data->map[i][j] != '\n')
//         {
//             if (data->map[i][j] == 'P')
//                 p++;
//             if (p > 1)
//                 return (0);
//             j++;
//         }
//         i++;
//     }
//     return (p == 1);
// }

// int check_coins(t_data *data)
// {
//     int i;
//     int j;
//     int c;
    
//     i = 0;
//     c = 0;
//     if (!data->map)
//         return (0);
//     while (data->map[i])
//     {
//         j = 0;
//         while (data->map[i][j] && data->map[i][j] != '\n')
//         {
//             if (data->map[i][j] == 'C')
//                 c++;
//             j++;
//         }
//         i++;
//     }
//     return (c);
// }

// int check_exit(t_data *data)
// {
//     int i;
//     int j;
//     int e;
    
//     i = 0;
//     e = 0;
//     if (!data->map)
//         return (0);
//     while (data->map[i])
//     {
//         j = 0;
//         while (data->map[i][j] && data->map[i][j] != '\n')
//         {
//             if (data->map[i][j] == 'E')
//                 e++;
//             if (e > 1)
//                 return (0);
//             j++;
//         }
//         i++;
//     }
//     return (e == 1);
// }

// int check_walls(t_data *data)
// {
//     int i;
//     int j;
//     int col;

//     i = 0;
//     col = ft_strlen(data->map[0]) - 1;
//     while (i < data->row)
//     {
//         j = 0;
//         while (data->map[i][j] && data->map[i][j] != '\n' && j < col)
//         {
//             if (i == 0 || i == data->row - 1 || j == 0 || j == col - 1)
//             {
//                 if (data->map[i][j] != '1')
//                     return (0);
//             }
//             j++;
//         }
//         i++;
//     }
//     return (1);
// }

// size_t ft_strlen_n(const char *str)
// {
//     size_t i;

//     if (!str)
//         return (0);
//     i = 0;
//     while (str[i] && str[i] != '\n')
//         i++;
//     return (i);
// }

// int check_rect(t_data *data)
// {
//     int i;
//     int len;
//     int ref;

//     i = 0;
//     ref = ft_strlen_n(data->map[i]);
//     while (data->map[i])
//     {
//         len = ft_strlen_n(data->map[i]);
//         if (len != ref)
//             return (0);
//         i++;
//     }
//     return (1);
// }

// int get_player_pos(char **map, int len, int *p_row, int *p_col)
// {
//     *p_row = 0;
//     while (*p_row < len && ft_strchr(map[*p_row], 'P') == 0)
//         (*p_row)++;
//     if (*p_row == len)
//         return (0);
//     *p_col = 0;
//     while (map[*p_row][*p_col] != 'P')
//         (*p_col)++;
//     return (1);
// }

// void copy_map(char **map, char **temp_map, int len)
// {
//     int i;

//     i = 0;
//     while (i < len)
//     {
//         temp_map[i] = ft_strdup(map[i]);
//         i++;
//     }
//     temp_map[i] = NULL;
// }

// static void flood_fill(char **map, int y, int x)
// {
//     if (map[y][x] == '1' || map[y][x] == 'X')
//         return ;
//     map[y][x] = 'X';
//     flood_fill(map, y, x - 1);
//     flood_fill(map,y, x + 1);
//     flood_fill(map, y - 1, x);
//     flood_fill(map, y + 1, x);
// }

// void free_maps(char **map, int len)
// {
//     int i;

//     i = 0;
//     while (i < len)
//     {
//         free(map[i]);
//         i++;
//     }
//     free(map);
// }



// int check_valid_path(t_data *data)
// {
//     char **map;
//     char **temp_map;
//     int p_row;
//     int p_col;
//     int i;

//     map = data->map;
//     if (!get_player_pos(map, data->row, &p_row, &p_col))
//         return (0);
//     temp_map = malloc(sizeof(char *) * (data->row + 1));
//     if (!temp_map)
//         return (0);
//     copy_map(map, temp_map, data->row);
//     flood_fill(temp_map, p_row, p_col);
//     i = 0;
//     while (i < data->row)
//     {
//         if (ft_strchr(temp_map[i], 'E') != 0 || ft_strchr(temp_map[i], 'C') != 0)
//         {
//             free_maps(temp_map, data->row);
//             return (0);
//         }
//         i++;
//     }
//     free_maps(temp_map, data->row);
//     return (1);
// }
// // this 
// void get_collectibles(t_data *data)
// {
//     int i;
//     int j;

//     i = 0;
//     data->collectible = 0;
//     while (i < data->row)
//     {
//         j = 0;
//         while (data->map[i][j] && data->map[i][j] != '\n')
//         {
//             if (data->map[i][j] == 'C')
//                 data->collectible++;
//             j++;
//         }
//         i++;
//     }
// }

// void get_player_position(t_data *data)
// {
//     int i;
//     int j;

//     i = 0;
//     while (i < data->row)
//     {
//         j = 0;
//         while (data->map[i][j] && data->map[i][j] != '\n')
//         {
//             if (data->map[i][j] == 'P')
//             {
//                 data->y = i;
//                 data->x = j;
//                 return ;
//             }
//             j++;
//         }
//         i++;
//     }
// }

// void check_map(char *map, t_data *data)
// {
//     if (check_ext(map ,".ber") != 0)
//         exit(1);
//     game_map(map, data);
//     if (!check_char(*data))
//         err_char(data);
//     if (!check_player(data))
//         err_char(data);
//     if (!check_exit(data))
//         err_char(data);
//     if (!check_walls(data))
//         err_char(data);
//     if (!check_coins(data))
//         err_char(data);
//     if (!check_rect(data))
//         err_char(data);
//     if (!check_valid_path(data))
//         err_char(data);
//     get_collectibles(data);
//     get_player_position(data);
// }

