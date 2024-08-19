/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:24:49 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/19 12:31:50 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	int		row;
	int		col;
	int		collectible;
	int		img_size;
	int		mv_count;
	int		exit;
	int		px;
	int		py;
}	t_data;

void	print_map(char **map);
int		check_coins_path(t_data *data);
void	free_maps(char **map, int len);
void	ft_free(t_data *data);
void	free_map(t_data *data);
void	up(t_data *data);
void	copy_map(char **map, char **temp_map, int len);
void	down(t_data *data);
void	right(t_data *data);
void	left(t_data *data);
void	map_check_list(char *av, t_data *data);
void	game_map(char *map, t_data *data);
void	file_check(char *av);
void	check_map(t_data *data);
void	err_fd(char *av);
void	err_malloc(void);
void	err_char(t_data *data);
void	err_walls(t_data *data);
int		check_walls(t_data *data);
void	err_exit(t_data *data);
void	err_player(t_data *data);
void	err_coins(t_data *data);
int		check_rect(t_data *data);
void	err_rect(t_data *data);
int		check_valid_path(t_data *data);
void	err_valid_path(t_data *data);
void	get_player_position(t_data *data);
char	*ft_strchr(const char *str, int c);
char	*get_next_line(int fd);
char	*empty_str(void);
char	*ft_strjoin(char *str, char *buffer);
void	get_exit_position(t_data *data);
void	get_collectibles(t_data *data);
char	*ft_strdup(const char *s1);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_error(void);
void	error_free_map(t_data *data);
void	ft_free(t_data *data);
void	render_image(t_data data);
void	render_img(t_data data, int x, int y);
char	*get_image(char c, int exit);
void	new_window(t_data *data);
int		to_move(int key, void *param);
int		check_char(t_data *data);
void	check_exist(t_data *data);
size_t	ft_strlen(char *s);

#endif
