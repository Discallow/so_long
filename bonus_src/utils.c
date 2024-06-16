/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:36:35 by discallow         #+#    #+#             */
/*   Updated: 2024/06/16 06:18:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_struct(t_game *game)
{
	game->x = 0;
	game->y = 0;
	game->map = NULL;
	game->copy.collectable = 0;
	game->copy.exit = 0;
	game->collectable.num = 0;
	game->collectable.total = 0;
	game->player.num = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->exit.num = 0;
	game->wall.num = 0;
	game->floor.num = 0;
	game->enemy.x = 0;
	game->enemy.y = 0;
}

// This function is calling strcmp2, to make sure that the extension is .ber
void	check_extension(char *file)
{
	if (ft_strcmp2(file, "ber") == 0)
	{
		write(2, "Wrong extension file\n", 21);
		exit (1);
	}
}
