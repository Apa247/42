/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:17:28 by daparici          #+#    #+#             */
/*   Updated: 2022/07/22 20:47:48 by daparici         ###   ########.fr       */
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

int	render_next_frame(t_map *map)
{
	if (map->keycode_c == 13 || map->keycode_c == 1)
		move_goku_y(map);
	map->n_frames++;
	return (1);
}

void	start_game(t_map *map)
{
	map->mlx = mlx_init();
	map->mlx_window = mlx_new_window(map->mlx, map->n_col * SIZE, \
		map->n_row * SIZE, "So_long");
	put_imagen_map(map);
	mlx_hook(map->mlx_window, 17, 1L << 17, closewin, map);
	mlx_key_hook(map->mlx_window, key_select, map);
	mlx_loop_hook(map->mlx, render_next_frame, map);
	mlx_loop(map->mlx);
}

int	key_select(int keycode, t_map *map)
{
	int	i;

	i = 0;
	if (keycode == 53)
	{
		printf("finished!\n");
	//	freemap(map);
		exit(0);
		return (1);
	}
	if (keycode == 13 && map->split_map[map->py -1][map->px] != '1')
	{
		map->n_frames = 0;
		map->keycode_c = keycode;
		return (1);
	}
	if (keycode == 1 && map->split_map[map->py + 1][map->px] != '1')
	{
		map->n_frames = 0;
		map->keycode_c = keycode;
		return (1);
	}
	return (0);
}

int	move_goku_y(t_map *map)
{
	if (map->n_frames == 1)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/goku_move_y.xpm",
			map->py, map->px);
	}
	if (map->n_frames == 500)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/goku_move_y2.xpm",
			map->py, map->px);
	}
	if (map->n_frames == 900)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_goku_map(map);
		map->split_map[map->py][map->px] = '0';
		return (1);
	}
	else
		return (0);
}

void	put_goku_map(t_map *map)
{
	if (map->keycode_c == 13)
	{
			map->py--;
			map->split_map[map->py][map->px] = 'P';
			put_imagen_xpm(map, "./sprites/goku.xpm", map->py, map->px);
	}
	if (map->keycode_c == 1)
	{
		map->py++;
		map->split_map[map->py][map->px] = 'P';
		put_imagen_xpm(map, "./sprites/goku.xpm", map->py, map->px);
	}
}

int	put_imagen_map(t_map *map)
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
	//printf("%i\n", map->n_frames);
	return (1);
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
