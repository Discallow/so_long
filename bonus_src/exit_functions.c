/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:31:31 by discallow         #+#    #+#             */
/*   Updated: 2024/06/15 01:00:36 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	invalid_map(t_game *game)
{
	write(2, "Error: Invalid map\n", 20);
	free_map(game->map);
	free_map(game->copy.map);
	exit(1);
}

void	game_over(t_game *game)
{
	count_movements(game);
	write(1, "Try again! You lost!\n", 21);
	destroy_map(game);
	mlx_destroy_window(game->connection, game->window);
	mlx_destroy_display(game->connection);
	free(game->connection);
	free_map(game->map);
	exit(0);
}

void	end_game(t_game *game)
{
	if (game->collectable.num != 0)
		return ;
	count_movements(game);
	write(1, "Congratulations! You won!\n", 26);
	destroy_map(game);
	mlx_destroy_window(game->connection, game->window);
	mlx_destroy_display(game->connection);
	free(game->connection);
	free_map(game->map);
	exit(0);
}

void	destroy_map(t_game *game)
{
	mlx_destroy_image(game->connection, game->floor.img);
	mlx_destroy_image(game->connection, game->wall.img);
	mlx_destroy_image(game->connection, game->collectable.img);
	mlx_destroy_image(game->connection, game->player.img);
	mlx_destroy_image(game->connection, game->exit.img);
}
