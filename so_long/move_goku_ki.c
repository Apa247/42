/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_goku_ki.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:34:31 by daparici          #+#    #+#             */
/*   Updated: 2022/07/27 18:49:15 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	power_ki_move(unsigned long frame, t_map *map, char *image)
{
	if (map->n_frames == frame)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, image, map->py, map->px);
		if (map->n_frames == 5400)
			map->ki = 0;
	}
}

void	power_ki(t_map *map)
{
	if (map->pl_dir == 0)
	{
		power_ki_move(1400, map, "./sprites/goku_transf1.xpm");
		power_ki_move(2000, map, "./sprites/goku_transf2.xpm");
		power_ki_move(2600, map, "./sprites/goku_transf3.xpm");
		power_ki_move(3200, map, "./sprites/goku_ki1.xpm");
		power_ki_move(3600, map, "./sprites/goku_ki2.xpm");
		power_ki_move(4200, map, "./sprites/goku_ki3.xpm");
		power_ki_move(4600, map, "./sprites/goku_ki3_final.xpm");
		power_ki_move(5400, map, "./sprites/goku_buena.xpm");
	}
	else
	{
		power_ki_move(1400, map, "./sprites/goku_transf1_left.xpm");
		power_ki_move(2000, map, "./sprites/goku_transf2_left.xpm");
		power_ki_move(2600, map, "./sprites/goku_transf3_left.xpm");
		power_ki_move(3200, map, "./sprites/goku_ki1_left.xpm");
		power_ki_move(3600, map, "./sprites/goku_ki2_left.xpm");
		power_ki_move(4200, map, "./sprites/goku_ki3_left.xpm");
		power_ki_move(4600, map, "./sprites/goku_ki3_final_left.xpm");
		power_ki_move(5400, map, "./sprites/goku_left.xpm");
	}
}
// void	power_ki_final(t_map *map)
// {
// 	if (map->pl_dir == 0)
// 	{
// 		power_ki_move(1400, map, "./sprites/goku_transf1.xpm");
// 		power_ki_move(2000, map, "./sprites/goku_transf2.xpm");
// 		power_ki_move(2600, map, "./sprites/goku_transf3.xpm");
// 		power_ki_move(3200, map, "./sprites/goku_ki1.xpm");
// 		power_ki_move(3600, map, "./sprites/goku_ki2.xpm");
// 		power_ki_move(4200, map, "./sprites/goku_ki3.xpm");
// 		power_ki_move(4600, map, "./sprites/goku_ki3_final.xpm");
// 		power_ki_move(5400, map, "./sprites/goku_buena.xpm");
// 	}
// 	else
// 	{
// 		power_ki_move(1400, map, "./sprites/goku_transf1_left.xpm");
// 		power_ki_move(2000, map, "./sprites/goku_transf2_left.xpm");
// 		power_ki_move(2600, map, "./sprites/goku_transf3_left.xpm");
// 		power_ki_move(3200, map, "./sprites/goku_ki1_left.xpm");
// 		power_ki_move(3600, map, "./sprites/goku_ki2_left.xpm");
// 		power_ki_move(4200, map, "./sprites/goku_ki3_left.xpm");
// 		power_ki_move(4600, map, "./sprites/goku_ki3_final_left.xpm");
// 		power_ki_move(5400, map, "./sprites/goku_left.xpm");
// 	}
// }