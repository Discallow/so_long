/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:23:57 by discallow         #+#    #+#             */
/*   Updated: 2024/06/15 01:15:47 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	count_movements(t_game *game)
{
	char		*str;
	char		*str2;
	static int	count = 0;

	count++;
	str = ft_itoa(count);
	str2 = ft_itoa(count - 1);
	mlx_string_put(game->connection, game->window, 80, 10, 0x000000, str2);
	mlx_string_put(game->connection, game->window, 80, 10, 0xffffff, str);
	free(str);
	free(str2);
	str = ft_itoa(game->collectable.total - game->collectable.num);
	str2 = ft_itoa(game->collectable.total - game->collectable.num - 1);
	mlx_string_put(game->connection, game->window, 90, 30, 0x000000, str2);
	mlx_string_put(game->connection, game->window, 90, 30, 0xffffff, str);
	free(str);
	free(str2);
}

void	move_down(t_game *game)
{
	game->player.path = "textures/ash_down.xpm";
	if (game->map[game->player.x + 1][game->player.y] == '0')
	{
		game->map[game->player.x][game->player.y] = '0';
		game->player.x = game->player.x + 1;
		game->map[game->player.x][game->player.y] = 'P';
		redraw_map(game, 1);
	}
	else if (game->map[game->player.x + 1][game->player.y] == 'C')
	{
		game->map[game->player.x][game->player.y] = '0';
		game->player.x = game->player.x + 1;
		game->map[game->player.x][game->player.y] = 'P';
		redraw_map(game, 0);
	}
	else if (game->map[game->player.x + 1][game->player.y] == 'E')
	{
		end_game(game);
		game->map[game->player.x][game->player.y] = '0';
		game->player.x = game->player.x + 1;
		game->map[game->player.x][game->player.y] = 'P';
		redraw_map(game, 1);
	}
	else if (game->map[game->player.x + 1][game->player.y] == 'M')
		game_over(game);
}

void	move_left(t_game *game)
{
	game->player.path = "textures/ash_left.xpm";
	if (game->map[game->player.x][game->player.y - 1] == '0')
	{
		game->map[game->player.x][game->player.y] = '0';
		game->player.y = game->player.y - 1;
		game->map[game->player.x][game->player.y] = 'P';
		redraw_map(game, 1);
	}
	else if (game->map[game->player.x][game->player.y - 1] == 'C')
	{
		game->map[game->player.x][game->player.y] = '0';
		game->player.y = game->player.y - 1;
		game->map[game->player.x][game->player.y] = 'P';
		redraw_map(game, 0);
	}
	else if (game->map[game->player.x][game->player.y - 1] == 'E')
	{
		end_game(game);
		game->map[game->player.x][game->player.y] = '0';
		game->player.y = game->player.y - 1;
		game->map[game->player.x][game->player.y] = 'P';
		redraw_map(game, 1);
	}
	else if (game->map[game->player.x][game->player.y - 1] == 'M')
		game_over(game);
}

void	move_right(t_game *game)
{
	game->player.path = "textures/ash_right.xpm";
	if (game->map[game->player.x][game->player.y + 1] == '0')
	{
		game->map[game->player.x][game->player.y] = '0';
		game->player.y = game->player.y + 1;
		game->map[game->player.x][game->player.y] = 'P';
		redraw_map(game, 1);
	}
	else if (game->map[game->player.x][game->player.y + 1] == 'C')
	{
		game->map[game->player.x][game->player.y] = '0';
		game->player.y = game->player.y + 1;
		game->map[game->player.x][game->player.y] = 'P';
		redraw_map(game, 0);
	}
	else if (game->map[game->player.x][game->player.y + 1] == 'E')
	{
		end_game(game);
		game->map[game->player.x][game->player.y] = '0';
		game->player.y = game->player.y + 1;
		game->map[game->player.x][game->player.y] = 'P';
		redraw_map(game, 1);
	}
	else if (game->map[game->player.x][game->player.y + 1] == 'M')
		game_over(game);
}

void	move_up(t_game *game)
{
	game->player.path = "textures/ash_up.xpm";
	if (game->map[game->player.x - 1][game->player.y] == '0')
	{
		game->map[game->player.x][game->player.y] = '0';
		game->player.x = game->player.x - 1;
		game->map[game->player.x][game->player.y] = 'P';
		redraw_map(game, 1);
	}
	else if (game->map[game->player.x - 1][game->player.y] == 'C')
	{
		game->map[game->player.x][game->player.y] = '0';
		game->player.x = game->player.x - 1;
		game->map[game->player.x][game->player.y] = 'P';
		redraw_map(game, 0);
	}
	else if (game->map[game->player.x - 1][game->player.y] == 'E')
	{
		end_game(game);
		game->map[game->player.x][game->player.y] = '0';
		game->player.x = game->player.x - 1;
		game->map[game->player.x][game->player.y] = 'P';
		redraw_map(game, 1);
	}
	else if (game->map[game->player.x - 1][game->player.y] == 'M')
		game_over(game);
}
