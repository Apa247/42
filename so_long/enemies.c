/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:35:57 by daparici          #+#    #+#             */
/*   Updated: 2022/07/27 17:36:31 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy_frame(int frame, t_map *map, char *image, int y, int x)
{
	if (map->frames_enemies == frame)
	{
        printf("hola\n");
		put_imagen_xpm(map, "./sprites/suelo.xpm", y, x);
		put_imagen_xpm(map, image, y, x);
	}
}

void    move_enemies(t_map *map)
{
    int	i;
	int	k;

	if (map->frames_enemies == 100 || map->frames_enemies == 1000 ||
		map->frames_enemies == 2000 || map->frames_enemies == 3000)
	{
		i = -1;
		while (map->split_map[++i])
		{
			k = -1;
			while (map->split_map[i][++k])
			{
				if (map->split_map[i][k] == 'T')
				{
                	move_enemy_frame(100, map, "./sprites/bubu_right.xpm", i, k);
            		move_enemy_frame(1000, map, "./sprites/bubu_right2.xpm", i, k);
                	move_enemy_frame(2000, map, "./sprites/bubu_right3.xpm", i, k);
                	move_enemy_frame(3000, map, "./sprites/bubu_right2.xpm", i, k);
				}
			}
		}
	}
    if (map->frames_enemies == 6000)
        map->frames_enemies = 0;
}