/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:36:35 by discallow         #+#    #+#             */
/*   Updated: 2024/06/11 18:36:59 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_struct(t_game *game)
{
	game->x = 0;
	game->y = 0;
	game->map = NULL;
	game->copy.collectable = 0;
	game->copy.exit = 0;
	game->collectable.num = 0;
	game->collectable.x = 0;
	game->collectable.y = 0;
	game->player.num = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->exit.num = 0;
	game->exit.x = 0;
	game->exit.y = 0;
	game->wall.num = 0;
	game->wall.x = 0;
	game->wall.y = 0;
	game->floor.num = 0;
	game->floor.x = 0;
	game->floor.y = 0;
}

void	check_extension(char *file)
{
	if (ft_strcmp2(file, "ber") == 0)
	{
		write(2, "Wrong extension file\n", 21);
		exit (1);
	}
}
