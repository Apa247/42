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

int	render_next_frame(t_map *map)
{
	if ((map->keycode_c == 13 || map->keycode_c == 1))
		move_goku_y(map);
	if (map->keycode_c == 0 || map->keycode_c == 2)
		move_goku_x(map);
	if (map->n_collect == 0 && map->exit_open == 0)
		open_exit(map);
	if (map->ki == 1)
		power_ki(map);

	//printf("lu\n", map->n_frames);
	map->n_frames++;
	return (1);
}

void	power_ki(t_map *map)
{
	if (map->n_frames == 1400)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/goku_transf1.xpm", map->py, map->px);
	}
	if (map->n_frames == 1800)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/goku_transf2.xpm", map->py, map->px);
	}
	if (map->n_frames == 2200)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/goku_transf3.xpm", map->py, map->px);
	}
	if (map->n_frames == 2600)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/goku_ki1.xpm", map->py, map->px);
	}
	if (map->n_frames == 3000)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/goku_ki2.xpm", map->py, map->px);
	}
	if (map->n_frames == 3400)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/goku_ki3.xpm", map->py, map->px);
	}
	if (map->n_frames == 4000)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/goku_ki3_final.xpm", map->py, map->px);
		map->ki = 0;
	}
	if (map->n_frames == 4400)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/goku_buena.xpm", map->py, map->px);
		map->ki = 0;
	}
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
	if ( (map->n_frames > 1200 && map->ki == 0) || map->n_frames > 5601)
	{
		key_y(keycode, map, &i);
		key_x(keycode, map, &i);
	}

	return (i);
}

void	key_x(int keycode, t_map *map, int *i)
{
	if (keycode == 0 && map->split_map[map->py][map->px - 1] != '1' &&
		map->split_map[map->py][map->px - 1] != 'E')
	{
		if (map->split_map[map->py][map->px - 1] == 'O')
			closewin(map);
		if (map->pl_dir == 0)
		{
			put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
			put_imagen_xpm(map, "./sprites/goku_left.xpm",
			map->py, map->px);
			map->pl_dir = 1;
		}
		if (map->split_map[map->py][map->px - 1] == 'C')
			map->n_collect -= 1;
		map->n_frames = 0;
		map->keycode_c = keycode;
		*i = 1;
	}
	if (keycode == 2 && map->split_map[map->py][map->px + 1] != '1' &&
		map->split_map[map->py][map->px + 1] != 'E')
	{
		if (map->split_map[map->py][map->px + 1] == 'O')
			closewin(map);
		if (map->pl_dir == 1)
		{
			put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
			put_imagen_xpm(map, "./sprites/goku_buena.xpm",
			map->py, map->px);
			map->pl_dir = 0;
		}
		if (map->split_map[map->py][map->px + 1] == 'C')
			map->n_collect -= 1;
		map->n_frames = 0;
		map->keycode_c = keycode;
		*i = 1;
	}
}

void	key_y(int keycode,t_map *map, int *i)
{
	if (keycode == 13 && map->split_map[map->py - 1][map->px] != '1' &&
		map->split_map[map->py -1][map->px] != 'E')
	{
		if (map->split_map[map->py - 1][map->px] == 'O')
			closewin(map);
		if (map->split_map[map->py -1][map->px] == 'C')
			map->n_collect -= 1;
		map->n_frames = 0;
		map->keycode_c = keycode;
		*i = 1;
	}
	if (keycode == 1 && map->split_map[map->py + 1][map->px] != '1' &&
		map->split_map[map->py + 1][map->px] != 'E')
	{
		if (map->split_map[map->py + 1][map->px] == 'O')
			closewin(map);
		if (map->split_map[map->py + 1][map->px] == 'C')
			map->n_collect -= 1;
		map->n_frames = 0;
		map->keycode_c = keycode;
		*i = 1;
	}
}

void move_goku_x(t_map *map)
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
	if (map->n_frames == 1000)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_goku_map(map);
		map->split_map[map->py][map->px] = '0';
	}
	if (map->n_frames == 2000)
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
	if (map->n_frames == 1000)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_goku_map(map);
		map->split_map[map->py][map->px] = '0';
	}
	if (map->n_frames == 2000)
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
	if (map->keycode_c == 0 && map->n_frames == 1000)
	{
		map->px--;
		map->split_map[map->py][map->px] = 'P';
		put_imagen_xpm(map, "./sprites/goku_move_left3.xpm", map->py, map->px);
	}
	if (map->keycode_c == 0 && map->n_frames == 2000)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, "./sprites/goku_left.xpm", map->py, map->px);
	}
	if (map->keycode_c == 2 && map->n_frames == 1000)
	{
		map->px++;
		map->split_map[map->py][map->px] = 'P';
		put_imagen_xpm(map, "./sprites/goku_move_left.xpm", map->py, map->px);
	}
	if (map->keycode_c == 2 && map->n_frames == 2000)
	{
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
	// map->width = SIZE;
	// map->height = SIZE;
	if (strcmp(adress_img, "./sprites/goku_s10.xpm") == 0)
	{
		img = mlx_xpm_file_to_image(map->mlx, adress_img,
			&map->width, &map->height);
		if (!img)
		{
			printf("ERROR\n");
			exit(1);
		}
		mlx_put_image_to_window(map->mlx, map->mlx_window, img, x, y);
		mlx_destroy_image(map->mlx, img);
	}
	else
	{
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
}
