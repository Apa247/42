/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:17:28 by daparici          #+#    #+#             */
/*   Updated: 2022/07/29 17:06:02 by daparici         ###   ########.fr       */
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
	move_enemies(map);
	if ((map->keycode_c == 13 || map->keycode_c == 1))
	{
		if (map->supergoku == 0)
			move_goku_y(map);
		else
			move_supergoku_y(map);
	}
	if (map->keycode_c == 0 || map->keycode_c == 2)
		move_goku_x(map);
	if (map->n_collect == 0 && map->n_exit != 0)
		open_exit(map);
	if (map->ki == 1)
		power_ki(map);
	if (map->ki == 1 && map->n_collect == 0)
		super_power_ki(map);
	map->frame_exit++;
	map->n_frames++;
	map->frames_enemies++;
	printf("%i\n", map->frames_enemies);
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
	printf("%i\n", keycode);
	if (keycode == 53)
	{
		printf("finished!\n");
	//	freemap(map);
		exit(0);
		return (1);
	}
	if (map->n_frames > 1400 && map->ki == 0)
	{
		key_y(keycode, map, &i);
		key_x(keycode, map, &i);
	}
	return (i);
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
			if (map->split_map[i][k] == 'T')
			{
				put_imagen_xpm(map, "./sprites/suelo.xpm", i, k);
				put_imagen_xpm(map, "./sprites/bubu_right.xpm", i, k);
			}
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
