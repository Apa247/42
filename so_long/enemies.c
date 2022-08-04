/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:35:57 by daparici          #+#    #+#             */
/*   Updated: 2022/08/04 16:52:16 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy_frame(int frame, t_map *map, char *image)
{
	if (map->frames_enemies == frame)
	{
		printf("%i\n", map->copy_n_enemies);
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->enemy_y, map->enemy_x);
		put_imagen_xpm(map, image, map->enemy_y, map->enemy_x);
	}
}

void	move_enemies(t_map *map)
{
	int	i;
	int	k;

	// if (map->frames_enemies == 100 || map->frames_enemies == 1500
	// 	|| map->frames_enemies == 3000 || map->frames_enemies == 4500
	// 	|| map->frames_enemies == 6000 || map->frames_enemies == 7500)
	// {
	i = -1;
	while (map->split_map[++i])
	{
		k = -1;
		while (map->split_map[i][++k])
			move_enemies_2(map, i, k);
	}
	if (map->frames_enemies == 15000)
		map->frames_enemies = 0;
}

void	move_enemies_2(t_map *map, int i, int k)
{
	if (map->copy_n_enemies == 0)
		map->copy_n_enemies = map->n_enemies;
	if (map->split_map[i][k] == 'T')
	{
		map->enemy_x = k;
		map->enemy_y = i;
		if (map->copy_n_enemies % 2 == 0)
			move_enemy_y(map);
		if (map->copy_n_enemies % 2 != 0)
			move_enemy_x(map);
		map->copy_n_enemies--;
	}
}

void	move_enemy_y(t_map *map)
{
	move_enemy_frame(100, map, "./sprites/bubu_right2.xpm");
	move_enemy_frame(1500, map, "./sprites/bubu_move_y.xpm");
	move_enemy_frame(3000, map, "./sprites/bubu_move_y2.xpm");
	move_enemy_frame(4500, map, "./sprites/bubu_move_y3.xpm");
	move_enemy_frame(6000, map, "./sprites/bubu_move_y4.xpm");
	if ((map->frames_enemies == 7500 && map->enemy_dir_y == 1))
	{
		if (map->split_map[map->enemy_y - 1][map->enemy_x] == 'P' ||
			map->split_map[map->enemy_y][map->enemy_x] == 'P')
			closewin(map);
		if (map->split_map[map->enemy_y - 1][map->enemy_x] != '1' &&
			map->split_map[map->enemy_y - 1][map->enemy_x] != 'C' &&
			map->split_map[map->enemy_y - 1][map->enemy_x] != 'E' &&
			map->split_map[map->enemy_y - 1][map->enemy_x] != 'O')
		{
			put_imagen_xpm(map, "./sprites/suelo.xpm",
				map->enemy_y, map->enemy_x);
			map->split_map[map->enemy_y][map->enemy_x] = '0';
			map->enemy_y--;
			move_enemy_frame(7500, map, "./sprites/bubu_right.xpm");
			map->split_map[map->enemy_y][map->enemy_x] = 'T';
		}
		else
		{
			move_enemy_frame(7500, map, "./sprites/bubu_right.xpm");
			map->enemy_dir_y = 0;
		}
	}
	else if (map->frames_enemies == 7500 && map->enemy_dir_y == 0)
	{
		if (map->split_map[map->enemy_y + 1][map->enemy_x] == 'P' ||
			map->split_map[map->enemy_y][map->enemy_x] == 'P')
			closewin(map);
		if (map->split_map[map->enemy_y + 1][map->enemy_x] != '1' &&
			map->split_map[map->enemy_y + 1][map->enemy_x] != 'C' &&
			map->split_map[map->enemy_y + 1][map->enemy_x] != 'E' &&
			map->split_map[map->enemy_y + 1][map->enemy_x] != 'O')
		{
			put_imagen_xpm(map, "./sprites/suelo.xpm",
				map->enemy_y, map->enemy_x);
			map->split_map[map->enemy_y][map->enemy_x] = '0';
			map->enemy_y++;
			move_enemy_frame(7500, map, "./sprites/bubu_right.xpm");
			map->split_map[map->enemy_y][map->enemy_x] = 'T';
		}
		else
		{
			move_enemy_frame(7500, map, "./sprites/bubu_right.xpm");
			map->enemy_dir_y = 1;
		}
	}
}

void	move_enemy_x(t_map *map)
{
	move_enemy_frame(100, map, "./sprites/bubu_right2.xpm");
	move_enemy_frame(1500, map, "./sprites/bubu_right3.xpm");
	move_enemy_frame(3000, map, "./sprites/bubu_right2.xpm");
	move_enemy_frame(4500, map, "./sprites/bubu_right3.xpm");
	move_enemy_frame(6000, map, "./sprites/bubu_right2.xpm");
	move_enemy_frame(7500, map, "./sprites/bubu_right.xpm");
}
