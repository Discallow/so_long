/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:30:24 by discallow         #+#    #+#             */
/*   Updated: 2024/06/15 01:15:08 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	key_pressed(int keysim, t_game *game)
{
	if (keysim == XK_w || keysim == XK_Up)
		move_up(game);
	if (keysim == XK_d || keysim == XK_Right)
		move_right(game);
	if (keysim == XK_a || keysim == XK_Left)
		move_left(game);
	if (keysim == XK_s || keysim == XK_Down)
		move_down(game);
	if (keysim == XK_Escape)
	{
		write(1, "Couldn't you get all the pokeballs? Are you afraid?\n", 52);
		destroy_map(game);
		mlx_destroy_window(game->connection, game->window);
		mlx_destroy_display(game->connection);
		free(game->connection);
		free_map(game->map);
		exit (0);
	}
	return (0);
}

int	window_closed(t_game *game)
{
	write(1, "Window closed!\n", 15);
	destroy_map(game);
	mlx_destroy_window(game->connection, game->window);
	mlx_destroy_display(game->connection);
	free(game->connection);
	free_map(game->map);
	exit (0);
}

void	init_connection(t_game *game)
{
	game->connection = mlx_init();
	if (!game->connection)
	{
		write(2, "Error: Couldn't start connection.\n", 34);
		free_map(game->map);
		exit (1);
	}
	game->window = mlx_new_window(game->connection, (game->x + 2) * TILE_SIZE,
			(game->y + 2) * TILE_SIZE, "So_long");
	if (!game->window)
	{
		mlx_destroy_display(game->connection);
		write(2, "Error: Couldn't open window.\n", 29);
		free_map(game->map);
		free(game->connection);
		exit (1);
	}
	mlx_string_put(game->connection, game->window, 1, 10,
		0xffffff, "Movements:");
	mlx_string_put(game->connection, game->window, 80, 10, 0xffffff, "0");
	mlx_string_put(game->connection, game->window, 1, 30,
		0xffffff, "Collectables:");
	mlx_string_put(game->connection, game->window, 90, 30, 0xffffff, "0");
}

void	redraw_map(t_game *game, int flag)
{
	if (flag == 0)
		game->collectable.num--;
	count_movements(game);
	destroy_map(game);
	build_map(game);
}
