/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:19:51 by discallow         #+#    #+#             */
/*   Updated: 2024/06/16 06:18:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*I chose an iterative flood fill instead of a recursive one.
I found this aproach better since in a large map, I would get a stack overflow because of the recursive call.
This can also be a bit slow, I found that the best approach would be a queue.*/

#include "../so_long.h"

void	change_map_value(t_game *game, int x, int y)
{
	if (game->copy.map[x][y] == 'C')
	{
		game->copy.map[x][y] = 'V';
		game->copy.collectable++;
	}
	else if (game->copy.map[x][y] == 'E')
	{
		game->copy.map[x][y] = 'V';
		game->copy.exit++;
	}
	else
		game->copy.map[x][y] = 'V';
}

void	check_directions(t_game *game, int x, int y)
{
	if (game->copy.map[x][y - 1] != '1')
		change_map_value(game, x, y - 1);
	if (game->copy.map[x][y + 1] != '1')
		change_map_value(game, x, y + 1);
	if (game->copy.map[x - 1][y] != '1')
		change_map_value(game, x - 1, y);
	if (game->copy.map[x + 1][y] != '1')
		change_map_value(game, x + 1, y);
}

int	check_map_fill(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (game->copy.map[i])
	{
		j = 1;
		while (game->copy.map[i][j])
		{
			if (game->copy.map[i][j] == 'V')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	change_map(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (game->copy.map[i])
	{
		j = 1;
		while (game->copy.map[i][j])
		{
			if (game->copy.map[i][j] == 'V')
			{
				game->copy.map[i][j] = '1';
				check_directions(game, i, j);
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_game *game)
{
	game->copy.map[game->player.x][game->player.y] = 'V';
	while (check_map_fill(game))
		change_map(game);
	if (game->copy.collectable != game->collectable.num || game->copy.exit != 1)
		invalid_map(game);
	free_map(game->copy.map);
}
