/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:48:35 by discallow         #+#    #+#             */
/*   Updated: 2024/06/12 18:31:09 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	init_struct(&game);
	get_path(&game);
	check_map(&game, argv[1]);
	init_connection(&game);
	build_map(&game);
	mlx_hook(game.window, KeyPress, KeyPressMask, &key_pressed, &game);
	mlx_hook(game.window, DestroyNotify, NoEventMask, &window_closed, &game);
	mlx_loop(game.connection);
	return (0);
}
