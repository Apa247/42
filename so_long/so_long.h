/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:16:01 by daparici          #+#    #+#             */
/*   Updated: 2022/06/23 14:20:01 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <xlocale.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
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

int		error_msg(char *msg);
void	check_map(int argc, char **argv, t_map *map);
void	check_map_name(char **argv);
void	check_map_params(int fd, t_map *map);
void	ft_read_map(int fd, t_map *map, char **map_str);
void	ft_add_map_params(char *line, t_map	*map);
int		ft_count_params(char *line, char c);
int		check_map_error(t_map *map);
t_map	ft_initmap(void);

#endif
