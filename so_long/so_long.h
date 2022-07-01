/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:16:01 by daparici          #+#    #+#             */
/*   Updated: 2022/07/01 15:40:14 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SIZE 49

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
	int		n_row;
	int		n_col;
	int		n_exit;
	int		n_pl;
	int		n_collect;
	char	**split_map;
}				t_map;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_window;
	int		n_moves;
	int		n_frames;
}				t_game;

int		error_msg(char *msg);
void	check_map(int argc, char **argv, t_map *map);
void	check_map_name(char **argv);
void	check_map_params(int fd, t_map *map);
void	ft_read_map(int fd, t_map *map, char **map_str);
void	ft_add_map_params(char *line, t_map	*map);
int		ft_count_params(char *line, char c);
int		check_map_error(t_map *map);
t_map	ft_initmap(void);
void	start_game(t_map map);

#endif
