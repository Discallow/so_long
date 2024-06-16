/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:23:57 by discallow         #+#    #+#             */
/*   Updated: 2024/06/15 00:51:42 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	count_movements(void)
{
	static int	count = 0;

	count++;
	write(1, "Movements: ", 11);
	ft_putnbr_fd(count, 1);
	ft_putchar_fd('\n', 1);
}

void	move_down(t_game *game)
{
	game->player.path = "textures/ash_down.xpm";
	if (game->map[game->player.x + 1][game->player.y] == '0')
	{
		game->map[game->player.x][game->player.y] = '0';
		game->player.x = game->player.x + 1;
		game->map[game->player.x][game->player.y] = 'P';
		redraw_map(game);
	}
	else if (game->map[game->player.x + 1][game->player.y] == 'C')
	{
		game->map[game->player.x][game->player.y] = '0';
		game->player.x = game->player.x + 1;
		game->map[game->player.x][game->player.y] = 'P';
		game->collectable.num--;
		redraw_map(game);
	}
	else if (game->map[game->player.x + 1][game->player.y] == 'E')
	{
		if (game->collectable.num == 0)
			end_game(game);
		game->map[game->player.x][game->player.y] = '0';
		game->player.x = game->player.x + 1;
		game->map[game->player.x][game->player.y] = 'P';
		redraw_map(game);
	}
}

void	move_left(t_game *game)
{
	game->player.path = "textures/ash_left.xpm";
	if (game->map[game->player.x][game->player.y - 1] == '0')
	{
		game->map[game->player.x][game->player.y] = '0';
		game->player.y = game->player.y - 1;
		game->map[game->player.x][game->player.y] = 'P';
		redraw_map(game);
	}
	else if (game->map[game->player.x][game->player.y - 1] == 'C')
	{
		game->map[game->player.x][game->player.y] = '0';
		game->player.y = game->player.y - 1;
		game->map[game->player.x][game->player.y] = 'P';
		game->collectable.num--;
		redraw_map(game);
	}
	else if (game->map[game->player.x][game->player.y - 1] == 'E')
	{
		if (game->collectable.num == 0)
			end_game(game);
		game->map[game->player.x][game->player.y] = '0';
		game->player.y = game->player.y - 1;
		game->map[game->player.x][game->player.y] = 'P';
		redraw_map(game);
	}
}

void	move_right(t_game *game)
{
	game->player.path = "textures/ash_right.xpm";
	if (game->map[game->player.x][game->player.y + 1] == '0')
	{
		game->map[game->player.x][game->player.y] = '0';
		game->player.y = game->player.y + 1;
		game->map[game->player.x][game->player.y] = 'P';
		redraw_map(game);
	}
	else if (game->map[game->player.x][game->player.y + 1] == 'C')
	{
		game->map[game->player.x][game->player.y] = '0';
		game->player.y = game->player.y + 1;
		game->map[game->player.x][game->player.y] = 'P';
		game->collectable.num--;
		redraw_map(game);
	}
	else if (game->map[game->player.x][game->player.y + 1] == 'E')
	{
		if (game->collectable.num == 0)
			end_game(game);
		game->map[game->player.x][game->player.y] = '0';
		game->player.y = game->player.y + 1;
		game->map[game->player.x][game->player.y] = 'P';
	}
}

void	move_up(t_game *game)
{
	game->player.path = "textures/ash_up.xpm";
	if (game->map[game->player.x - 1][game->player.y] == '0')
	{
		game->map[game->player.x][game->player.y] = '0';
		game->player.x = game->player.x - 1;
		game->map[game->player.x][game->player.y] = 'P';
		redraw_map(game);
	}
	else if (game->map[game->player.x - 1][game->player.y] == 'C')
	{
		game->map[game->player.x][game->player.y] = '0';
		game->player.x = game->player.x - 1;
		game->map[game->player.x][game->player.y] = 'P';
		game->collectable.num--;
		redraw_map(game);
	}
	else if (game->map[game->player.x - 1][game->player.y] == 'E')
	{
		if (game->collectable.num == 0)
			end_game(game);
		game->map[game->player.x][game->player.y] = '0';
		game->player.x = game->player.x - 1;
		game->map[game->player.x][game->player.y] = 'P';
		redraw_map(game);
	}
}
