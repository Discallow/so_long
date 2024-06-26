/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:30:02 by discallow         #+#    #+#             */
/*   Updated: 2024/06/16 06:18:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_enemy_on_window(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	game->enemy.img = check_image(game, game->enemy.img, game->enemy.path);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'M')
			{
				mlx_put_image_to_window(game->connection, game->window,
					game->enemy.img, (j + 1) * 32, (i + 1) * 32);
			}
			j++;
		}
		i++;
	}
	mlx_destroy_image(game->connection, game->enemy.img);
}
// This is going to constantly change image and put that different image in the window.
void	get_enemy_sprite(t_game *game, int i)
{
	if (i == 0)
		game->enemy.path = "textures/magikarp_00.xpm";
	else if (i == 1)
		game->enemy.path = "textures/magikarp_01.xpm";
	else
		game->enemy.path = "textures/magikarp_02.xpm";
}
// This function is constantly called by mlx_loop_hook and time value will constantly update to change the image
int	enemy_sprite(t_game *game)
{
	static float	time = 0;

	time += 0.05;
	if (time > 3)
		time = 0;
	get_enemy_sprite(game, (int)time);
	put_enemy_on_window(game);
	return (0);
}
