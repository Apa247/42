/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:17:28 by daparici          #+#    #+#             */
/*   Updated: 2022/06/24 17:56:49 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_map map)
{
	t_game	game;

	game.mlx = mlx_init();
	game.mlx_window = mlx_new_window(game.mlx, map.n_col * SIZE, \
		map.n_row * SIZE, "So_long");
	mlx_loop(game.mlx);
}
