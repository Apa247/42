/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:17:28 by daparici          #+#    #+#             */
/*   Updated: 2022/07/22 20:47:48 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_exit(t_map *map)
{
	int	i;
	int	k;

	i = -1;
	while (map->split_map[++i] && map->n_frames == 4500 && map->n_exit != 0)
	{
		k = -1;
		while (map->split_map[i][++k])
		{
			if ( map->split_map[i][k] == 'E')
			{
				map->E_x = k;
				map->E_y = i;
				break ;
			}
		}
	}
	if (map->n_frames == 4800 && map->n_exit != 0)
		put_imagen_xpm(map, "./sprites/puff.xpm", map->E_y, map->E_x);
	if (map->n_frames == 5200 && map->n_exit != 0)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->E_y, map->E_x);
		put_imagen_xpm(map, "./sprites/puff2.xpm", map->E_y, map->E_x);
	}
	if (map->n_frames == 5600 && map->n_exit != 0)
	{
		put_imagen_xpm(map, "./sprites/salida.xpm", map->E_y, map->E_x);
		map->split_map[map->E_y][map->E_x] = 'O';
		map->n_exit -= 1;
		if (map->n_exit != 0)
			map->n_frames = 4499;
		if (map->n_exit == 0)
		{
			map->exit_open = 1;
			map->n_frames = 5601;
		}
	}

}
