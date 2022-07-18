/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:17:28 by daparici          #+#    #+#             */
/*   Updated: 2022/07/18 21:02:01 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemap(t_map *map)
{
	int	i;

	while (map->split_map)
	{
		i = -1;
		while (map->split_map[++i])
			free(map->split_map[i]);
		free(map->split_map);
	}
	// if (map->mlx && map->mlx_window)
	// {
	// 	mlx_clear_window(map->mlx, map->mlx_window);
	// 	mlx_destroy_window(map->mlx, map->mlx_window);
	// }
}

int	closewin(t_map *map)
{
	freemap(map);
	printf("Finished\n");
	exit (0);
	return (0);
}

void	start_game(t_map *map)
{
	map->mlx = mlx_init();
	map->mlx_window = mlx_new_window(map->mlx, map->n_col * SIZE, \
		map->n_row * SIZE, "So_long");
	put_imagen_map(map);
	mlx_hook(map->mlx_window, 17, 1L << 17, closewin, &map);
	mlx_key_hook(map->mlx_window, key_select, &map);
	mlx_loop(map->mlx);
}

int	key_select(int keycode, t_map *map)
{
	int	i;

	i = 0;
	if (keycode == 53)
	{
		printf("finished!\n");
//		freemap(map);
		exit(0);
	}
	if (map->split_map)
		return (0);
	return (0);
}

void	put_imagen_map(t_map *map)
{
	int	i;
	int	k;

	i = -1;
	while (map->split_map[++i])
	{
		k = -1;
		while (map->split_map[i][++k])
		{
			if (map->split_map[i][k] == '1')
				put_imagen_xpm(map, "./sprites/pared.xpm", i, k);
			if (map->split_map[i][k] == '0')
				put_imagen_xpm(map, "./sprites/suelo.xpm", i, k);
			if (map->split_map[i][k] == 'C')
			{
				put_imagen_xpm(map, "./sprites/suelo.xpm", i, k);
				put_imagen_xpm(map, "./sprites/comestible.xpm", i, k);
			}
			if (map->split_map[i][k] == 'E')
				put_imagen_xpm(map, "./sprites/capsula.xpm", i, k);
			if (map->split_map[i][k] == 'P')
				put_imagen_xpm(map, "./sprites/goku.xpm", i, k);
		}
	}
}

void	put_imagen_xpm(t_map *map, char *adress_img, int x, int y)
{
	void	*img;
	int		res;

	res = 47;
	map->width = (res * y);
	map->height = (res * x);
	img = mlx_xpm_file_to_image(map->mlx, adress_img,
			&res, &res);
	if (!img)
	{
		printf("ERROR\n");
		exit(1);
	}
	mlx_put_image_to_window(map->mlx, map->mlx_window, img,
		map->width, map->height);
	mlx_destroy_image(map->mlx, img);
}

