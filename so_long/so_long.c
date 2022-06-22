/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:27:41 by daparici          #+#    #+#             */
/*   Updated: 2022/06/22 21:25:39 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(char *msg, char **map_str)
{
	if (map_str)
		free(*map_str);
	printf("Error\n%s\n", msg);
	exit(0);
	return (0);
}

int	main(int argc, int argv[])
{
	t_map	map;

	check_map(argc, argv, &map);
}

void	check_map(int argc, char **argv, t_map *map)
{
	int	fd;

	if (argc != 2)
		error_msg("Invalid number of arguments", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_msg("File not found", NULL);
	check_map_name(argv);
	check_map_params(fd, map);
}

void	check_map_name(char **argv)
{
	char	*name_map;

	name_map = strchr(argv[1], ".");
	if (strcmp(name_map, ".ber"))
		error_msg("Invalid type file, please use .ber", NULL);
}

void	chech_map_parms(int fd, t_map *map)
{
	char	*map_str;

	map_str = NULL;
	*map = ft_initmap();
	ft_read_map(fd, map, &map_str);
}

char	*ft_read_map(int fd, t_map map, char **map_str)
{
	char	*line;
	char	*last_line;

	line = NULL;
	last_line = NULL;
}

t_map ft_initmap(void)
{
	t_map	map;

	map.n_row = 0;
	map.n_col = 0;
	map.n_exit = 0;
	map.n_pl = 0;
	map.n_gh = 0;
	map.n_collect = 0;
	**map.split_map = NULL;
}