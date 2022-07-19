/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:16:01 by daparici          #+#    #+#             */
/*   Updated: 2022/07/19 20:54:34 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SIZE 47

# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <xlocale.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include "./Libft/libft.h"
# include "./GetNextLine/get_next_line.h"

typedef struct s_map
{
	void	*mlx;
	void	*mlx_window;
	char	**split_map;
	int		n_row;
	int		n_col;
	int		n_exit;
	int		n_pl;
	int		px;
	int		py;
	int		n_collect;
	int		n_moves;
	int		n_frames;
	int		width;
	int		height;
}				t_map;

int		error_msg(char *msg);
void	check_map(int argc, char **argv, t_map *map);
void	check_map_name(char **argv);
void	check_map_params(int fd, t_map *map);
void	ft_read_map(int fd, t_map *map, char **map_str);
void	ft_count_params(t_map *map, int i, int k);
int		check_map_error(t_map *map);
t_map	ft_initmap(void);
void	start_game(t_map *map);
void	put_imagen_map(t_map *map);
void	get_type_params(t_map map, int i, int k);
void	put_imagen_xpm(t_map *map, char *adress_img, int x, int y);
t_map	*params_init(t_map *map);
//void	freemap(t_map *map);
int		closewin(t_map *map);
int		key_select(int keycode, t_map *map);
void	move_goku_y(t_map *map, int keycode);

#endif
