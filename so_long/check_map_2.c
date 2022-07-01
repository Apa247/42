/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:31:21 by daparici          #+#    #+#             */
/*   Updated: 2022/06/24 14:44:51 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(int fd, t_map *map, char **map_str)
{
	char	*line;
	char	*last_line;

	line = NULL;
	last_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (map->n_row < 3 && map->n_col < 3)
				error_msg("Map is empty!");
			else
				ft_add_map_params(last_line, map);
			free(last_line);
			break ;
		}
		free(last_line);
		ft_add_map_params(line, map);
		last_line = ft_substr(line, 0, ft_strlen(line));
		free(line);
		*map_str = ft_strjoin(*map_str, last_line);
		map->n_row++;
	}
}

void	ft_add_map_params(char *line, t_map	*map)
{
	if (!map->n_col)
		map->n_col = ft_strlen(line) - 1;
	map->n_exit += ft_count_params(line, 'E');
	map->n_pl += ft_count_params(line, 'P');
	map->n_collect += ft_count_params(line, 'C');
}

int	ft_count_params(char *line, char c)
{
	int	count;

	count = 0;
	if (!line)
		return (0);
	while (*line)
	{
		if (*line == c)
			count++;
		line++;
	}
	return (count);
}

int	check_map_error(t_map *map)
{
	int	i;
	int	k;

	i = 0;
	while (map->split_map[i])
	{
		k = 0;
		if (ft_strlen(map->split_map[0]) != ft_strlen(map->split_map[i]))
			error_msg("Map must be rectangular!");
		while (map->split_map[i][k])
		{
			if (map->split_map[0][k] != '1' ||
				map->split_map[map->n_row - 1][k] != '1'
				|| map->split_map[i][0] != '1' ||
				map->split_map[i][map->n_col - 1] != '1')
				error_msg("Map must be surrounded by walls!");
			if (map->split_map[i][k] != '0' && map->split_map[i][k] != '1' &&
					map->split_map[i][k] != 'P' && map->split_map[i][k] != 'C'
					&& map->split_map[i][k] != 'E')
				error_msg("Invalid map, check parameters");
			k++;
		}
		i++;
	}
	return (0);
}
