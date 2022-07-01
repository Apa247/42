/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:27:41 by daparici          #+#    #+#             */
/*   Updated: 2022/06/24 16:54:10 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(char *msg)
{
	printf("Error\n%s\n", msg);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	check_map(argc, argv, &map);
	start_game(map);
	printf("%s\n", "OK");
	return (0);
}
