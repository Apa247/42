/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:17:28 by daparici          #+#    #+#             */
/*   Updated: 2022/07/27 19:06:11 by daparici         ###   ########.fr       */
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

int	render_next_frame(t_map *map)
{
	if ((map->keycode_c == 13 || map->keycode_c == 1))
		move_goku_y(map);
	if (map->keycode_c == 0 || map->keycode_c == 2)
		move_goku_x(map);
	if (map->n_collect == 0 && map->n_exit != 0)
	{
		printf("hola\n");
		open_exit(map);
	}
	if (map->ki == 1)
		power_ki(map);
//	if (map->ki == 1 && map->n_collect == 0)
	map->frame_exit++;
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



void	move_goku_x(t_map *map)
{
	if (map->keycode_c == 0)
		move_goku_x_left(map);
	if (map->keycode_c == 2)
		move_goku_x_right(map);
}

void	move_goku_x_right(t_map *map)
{
	if (map->n_frames == 100)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/goku_move_right.xpm",
			map->py, map->px);
	}
	if (map->n_frames == 800)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		map->split_map[map->py][map->px] = '0';
		put_goku_map(map);
	}
	if (map->n_frames == 1300)
		put_goku_map(map);
}

void	move_goku_x_left(t_map *map)
{
	if (map->n_frames == 0)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/goku_move_y_left2.xpm",
			map->py, map->px);
	}
	if (map->n_frames == 800)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		map->split_map[map->py][map->px] = '0';
		put_goku_map(map);
	}
	if (map->n_frames == 1300)
		put_goku_map(map);
}

void	move_goku_y(t_map *map)
{
	if (map->n_frames == 0)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		if (map->pl_dir == 0)
			put_imagen_xpm(map, "./sprites/goku_move_y.xpm",
				map->py, map->px);
		else
			put_imagen_xpm(map, "./sprites/goku_move_y_left.xpm", map->py, map->px);
	}
	if (map->n_frames == 400)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		if (map->pl_dir == 0)
			put_imagen_xpm(map, "./sprites/goku_move_y_borroso.xpm",
				map->py, map->px);
		else
			put_imagen_xpm(map, "./sprites/goku_move_y_borroso2.xpm", map->py, map->px);
	}
	if (map->n_frames == 800)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/goku_move_y_bueno.xpm",
			map->py, map->px);
	}
	if (map->n_frames == 1200)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_goku_map(map);
		map->split_map[map->py][map->px] = '0';
	}
}

void	put_goku_map(t_map *map)
{
	if (map->keycode_c == 13)
	{
		map->py--;
		if (map->split_map[map->py][map->px] == 'C')
			map->ki = 1;
		map->split_map[map->py][map->px] = 'P';
		if (map->pl_dir == 0)
		{
			put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
			put_imagen_xpm(map, "./sprites/goku_buena.xpm", map->py, map->px);
		}
		else
		{
			put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
			put_imagen_xpm(map, "./sprites/goku_left.xpm", map->py, map->px);
		}
	}
	if (map->keycode_c == 1)
	{
		map->py++;
		if (map->split_map[map->py][map->px] == 'C')
			map->ki = 1;
		map->split_map[map->py][map->px] = 'P';
		if (map->pl_dir == 0)
		{
			put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
			put_imagen_xpm(map, "./sprites/goku_buena.xpm", map->py, map->px);
		}
		else
		{
			put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
			put_imagen_xpm(map, "./sprites/goku_left.xpm", map->py, map->px);
		}
	}
	if (map->keycode_c == 0 && map->n_frames == 800)
	{
		map->px--;
		put_imagen_xpm(map, "./sprites/goku_move_left3.xpm", map->py, map->px);
	}
	if (map->keycode_c == 0 && map->n_frames == 1300)
	{
		if (map->split_map[map->py][map->px] == 'C')
			map->ki = 1;
		map->split_map[map->py][map->px] = 'P';
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/goku_left.xpm", map->py, map->px);
	}
	if (map->keycode_c == 2 && map->n_frames == 800)
	{
		map->px++;
		put_imagen_xpm(map, "./sprites/goku_move_left.xpm", map->py, map->px);
	}
	if (map->keycode_c == 2 && map->n_frames == 1300)
	{
		if (map->split_map[map->py][map->px] == 'C')
			map->ki = 1;
		map->split_map[map->py][map->px] = 'P';
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/goku_buena.xpm", map->py, map->px);
	}
}

int	put_imagen_map(t_map *map)
{
//	put_imagen_xpm(map, "./sprites/goku_s10.xpm", 0, 0);
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
				put_imagen_xpm(map, "./sprites/coleccionable.xpm", i, k);
			}
			if (map->split_map[i][k] == 'E')
				put_imagen_xpm(map, "./sprites/capsula.xpm", i, k);
			if (map->split_map[i][k] == 'P')
			{
				put_imagen_xpm(map, "./sprites/suelo.xpm", i, k);
				put_imagen_xpm(map, "./sprites/goku_buena.xpm", i, k);
			}
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
	//printf("x: %i, y: %i, width: %i, height: %i\n", x, y, map->width, map->height);
	// map->width = SIZE;
	// map->height = SIZE;
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
	// if (strcmp(adress_img, "./sprites/goku_s10.xpm") == 0)
	// {
	// 	img = mlx_xpm_file_to_image(map->mlx, adress_img,
	// 			&map->width, &map->height);
	// 	if (!img)
	// 	{
	// 		printf("ERROR\n");
	// 		exit(1);
	// 	}
	// 	mlx_put_image_to_window(map->mlx, map->mlx_window, img, x, y);
	// 	mlx_destroy_image(map->mlx, img);
	// }
	// else
	// {
	// 	img = mlx_xpm_file_to_image(map->mlx, adress_img,
	// 			&res, &res);
	// 	if (!img)
	// 	{
	// 		printf("ERROR\n");
	// 		exit(1);
	// 	}
	// 	mlx_put_image_to_window(map->mlx, map->mlx_window, img,
	// 		map->width, map->height);
	// 	mlx_destroy_image(map->mlx, img);
	// }
}
