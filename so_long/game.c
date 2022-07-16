/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:17:28 by daparici          #+#    #+#             */
/*   Updated: 2022/07/15 15:31:52 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_map map)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	game = params_init(game);
	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx, map.n_col * SIZE, \
		map.n_row * SIZE, "So_long");
	put_imagen_map(map, game);
	mlx_loop(game->mlx);
}

void	put_imagen_map(t_map map, t_game *game)
{
	int	i;
	int	k;

	i = -1;
	while (map.split_map[++i])
	{
		k = -1;
		while (map.split_map[i][++k])
		{
			if (map.split_map[i][k] == '1')
				put_imagen_xpm(game, "./sprites/pared.xpm", i, k);
			if (map.split_map[i][k] == '0')
				put_imagen_xpm(game, "./sprites/suelo.xpm", i, k);
			if (map.split_map[i][k] == 'C')
				put_imagen_xpm(game, "./sprites/comestible.xpm", i, k);
			if (map.split_map[i][k] == 'E')
				put_imagen_xpm(game, "./sprites/salida1.xpm", i, k);
			if (map.split_map[i][k] == 'P')
				put_imagen_xpm(game, "./sprites/goku.xpm", i, k);
		}
	}
}

void	put_imagen_xpm(t_game *game, char *adress_img, int x, int y)
{
	void	*img;
	int		res;

	res = 47;
	game->width = (res * y);
	game->height = (res * x);
	img = mlx_xpm_file_to_image(game->mlx, adress_img,
			&res, &res);
	if (!img)
	{
		printf("ERROR\n");
		exit(1);
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window, img,
		game->width, game->height);
	mlx_destroy_image(game->mlx, img);
}

t_game	*params_init(t_game *game)
{
	game->n_frames = 0;
	game->n_moves = 0;
	game->width = 0;
	game->height = 0;
	return (game);
}
