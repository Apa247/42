/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:17:28 by daparici          #+#    #+#             */
/*   Updated: 2022/07/19 21:10:32 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	freemap(t_map *map)
// {
// 	int	i;

// 	while (map->split_map)
// 	{
// 		i = -1;
// 		while (map->split_map[++i])
// 			free(map->split_map[i]);
// 		free(map->split_map);
// 	}
// 	// if (map->mlx && map->mlx_window)
// 	// {
// 	// 	mlx_clear_window(map->mlx, map->mlx_window);
// 	// 	mlx_destroy_window(map->mlx, map->mlx_window);
// 	// }
// }

int	closewin(t_map *map)
{
//	freemap(map);
	printf("Finished\n");
	exit (0);
	if (map)
		return (0);
}

void	start_game(t_map *map)
{
	map->mlx = mlx_init();
	map->mlx_window = mlx_new_window(map->mlx, map->n_col * SIZE, \
		map->n_row * SIZE, "So_long");
	put_imagen_map(map);
	mlx_hook(map->mlx_window, 17, 1L << 17, closewin, map);
	printf("si\n");
	mlx_key_hook(map->mlx_window, key_select, map);
	mlx_loop(map->mlx);
}

int	key_select(int keycode, t_map *map)
{
	int	i;

	i = 0;
	printf("%i\n%i\n", map->px, map->py);
	if (keycode == 53)
	{
		printf("finished!\n");
	//	freemap(map);
		exit(0);
	}
	if (keycode == 13 || keycode == 1)
		move_goku_y(map, keycode);
	return (0);
}

void	move_goku_y(t_map *map, int keycode)
{
	printf("si\n");
	printf("%i\n%i\n%i\n", keycode, map->px, map->py);
	// if (map->split_map[map->py - 1][map->px] == 'E'
	// 		&& map->n_collect == '0' && keycode == '13')
	if (keycode == 13 && map->split_map[map->py - 1][map->px] != '1'
		&& map->split_map[map->py - 1][map->px] != 'E')
	{
		printf("hola\n");
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/goku_move_y.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/goku_move_y2.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
	}
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
	if (!ft_strncmp(adress_img, "./sprites/goku_move_y.xpm", 27))
	{
		printf("si\n");
		printf("%i\n%i\n", x, y);
	}
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
